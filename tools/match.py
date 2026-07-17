#!/usr/bin/env python3
"""Match a single function: compile candidate C with mwccarm and compare the
result to the function's bytes in the ROM, relocation-aware.

This is the core decomp loop in miniature. Almost every real function pools an
absolute address (a global, a callee), which the compiler emits as a relocation
slot of zeroes plus a reloc entry, while the ROM has the final linked address
there. So a correct match is: every instruction word identical AND every reloc
slot lined up -- not a raw byte-for-byte compare.

API (used by swarm/fdiff/clone/…, same surface as sm64ds-decomp):
  REPO, MW, ARM9, ARM9_BASE, DEFAULT_FLAGS, SWEEP, PINNED, CANONICAL
  compile_c, extract_func, compare, target_bytes

Usage:
  python tools/match.py --c path.c --func name --addr 0x02000800 --size 0x120
  python tools/match.py --c path.c --func name --addr 0x... --size 0x... --sweep
"""
from __future__ import annotations

import argparse
import io
import os
import pathlib
import subprocess
import sys
import tempfile

from capstone import CS_ARCH_ARM, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

REPO = pathlib.Path(__file__).resolve().parent.parent
MW = REPO / "tools" / "mwccarm"
LICENSE = MW / "license.dat"

# Public module map (CLI + simple callers). Prefer tools/modules.py for overlays.
MODULES = {
    "arm9": {"bin": REPO / "arm9" / "arm9.bin", "base": 0x02000000},
    "arm7": {"bin": REPO / "arm7" / "arm7.bin", "base": 0x02380000},
}

# sm64ds swarm/fdiff aliases
ARM9 = MODULES["arm9"]["bin"]
ARM9_BASE = MODULES["arm9"]["base"]

DEFAULT_FLAGS = (
    "-O4,p -enum int -lang c99 -char signed -interworking "
    "-proc arm946e -gccext,on -msgstyle gcc"
)
SWEEP = [
    "1.2/base",
    "1.2/sp2",
    "1.2/sp2p3",
    "1.2/sp3",
    "1.2/sp4",
    "2.0/base",
    "2.0/sp1",
    "2.0/sp1p2",
    "2.0/sp2",
    "2.0/sp2p2",
    "2.0/sp2p3",
]
# CodeWarrior 1.2 trio used as pinned candidates (codegen-identical on SM64DS;
# provisional pin for Electroplankton until probes prove otherwise).
PINNED = ["1.2/base", "1.2/sp2", "1.2/sp2p3"]
CANONICAL = "1.2/sp2p3"

md = Cs(CS_ARCH_ARM, CS_MODE_ARM)


def target_bytes(
    addr: int,
    size: int,
    bin_path: pathlib.Path | None = None,
    base: int | None = None,
) -> bytes:
    """Bytes of [addr, addr+size) from a module binary (defaults: arm9)."""
    path = bin_path if bin_path is not None else ARM9
    base_addr = ARM9_BASE if base is None else base
    data = path.read_bytes()
    off = addr - base_addr
    if off < 0 or off + size > len(data):
        raise SystemExit(
            f"target range out of bounds addr=0x{addr:x} size=0x{size:x} "
            f"bin={path} base=0x{base_addr:x}"
        )
    return data[off : off + size]


def compile_c(cfile: pathlib.Path, version: str, flags: str) -> bytes | None:
    """Compile C -> object with the given mwccarm version. Returns object bytes."""
    exe = MW / version / "mwccarm.exe"
    if not exe.is_file():
        # wibo-wrapped layout also used on macOS
        pe32 = MW / version / "mwccarm.exe.pe32"
        if not pe32.is_file():
            print(f"  ! no compiler at {version}")
            return None
    with tempfile.TemporaryDirectory() as td:
        out_o = pathlib.Path(td) / "out.o"
        env = dict(os.environ)
        if LICENSE.is_file():
            env["LM_LICENSE_FILE"] = str(LICENSE)
        # Prefer native/wibo-wrapped mwccarm.exe path (symlink or wrapper)
        exe = MW / version / "mwccarm.exe"
        if not exe.is_file():
            # fall back to tools/bin/wibo + pe32 if present
            wibo = REPO / "tools" / "bin" / "wibo"
            pe32 = MW / version / "mwccarm.exe.pe32"
            if wibo.is_file() and pe32.is_file():
                cmd = [str(wibo), str(pe32), *flags.split(), "-c", str(cfile), "-o", str(out_o)]
            else:
                print(f"  ! no compiler at {version}")
                return None
        else:
            cmd = [str(exe), *flags.split(), "-c", str(cfile), "-o", str(out_o)]
        try:
            r = subprocess.run(cmd, capture_output=True, text=True, env=env, timeout=90)
        except subprocess.TimeoutExpired:
            print(f"  ! compile timed out ({version})")
            return None
        if r.returncode != 0 or not out_o.is_file():
            err = (r.stderr or r.stdout or "").strip()[:300]
            print(f"  ! compile failed ({version}): {err}")
            return None
        return out_o.read_bytes()


def extract_func(obj: bytes, func: str):
    """Return (code_bytes, set_of_reloc_word_offsets) for `func` in the object."""
    elf = ELFFile(io.BytesIO(obj))
    symtab = elf.get_section_by_name(".symtab")
    if symtab is None:
        return None, None
    sym = next((s for s in symtab.iter_symbols() if s.name == func), None)
    if sym is None:
        return None, None
    sec = elf.get_section(sym["st_shndx"])
    start, size = sym["st_value"], sym["st_size"]
    code = sec.data()[start : start + size]
    relocs: set[int] = set()
    rel = elf.get_section_by_name(".rel" + sec.name) or elf.get_section_by_name(
        ".rela" + sec.name
    )
    if rel is not None:
        for r in rel.iter_relocations():
            o = r["r_offset"] - start
            if 0 <= o < size:
                relocs.add(o & ~3)
    else:
        # broader scan (some toolchains name rel sections differently)
        for section in elf.iter_sections():
            if section.header["sh_type"] not in ("SHT_REL", "SHT_RELA"):
                continue
            if section.header["sh_info"] != sym["st_shndx"]:
                continue
            for r in section.iter_relocations():
                o = r["r_offset"] - start
                if 0 <= o < size:
                    relocs.add(o & ~3)
    return code, relocs


def compare(target: bytes, cand: bytes, relocs: set, verbose: bool = True):
    """Word-by-word compare; reloc slots are wildcards. Returns (ok, n_mismatch)."""
    if len(target) != len(cand):
        if verbose:
            print(f"  size differs: target 0x{len(target):x} vs candidate 0x{len(cand):x}")
        return False, 999
    ok = True
    ndiff = 0
    for i in range(0, len(target), 4):
        tw = target[i : i + 4]
        cw = cand[i : i + 4]
        if i in relocs or any(i <= r < i + 4 for r in relocs):
            tag = "reloc (wildcard)"
            match = True
        else:
            match = tw == cw
            tag = "OK" if match else "<<< MISMATCH"
        if not match:
            ok = False
            ndiff += 1
        if verbose:
            ti = next(md.disasm(tw, 0), None)
            ci = next(md.disasm(cw, 0), None)
            ts = f"{ti.mnemonic} {ti.op_str}" if ti else tw.hex()
            cs = f"{ci.mnemonic} {ci.op_str}" if ci else cw.hex()
            print(f"   +0x{i:02x} | {tw.hex()} {ts:24} | {cw.hex()} {cs:24} | {tag}")
    return ok, ndiff


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--c", required=True, help="Candidate C/C++ file")
    ap.add_argument("--func", required=True)
    ap.add_argument("--addr", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--size", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--module", default="arm9")
    ap.add_argument("--version", default=None, help=f"mwccarm version (default {CANONICAL})")
    ap.add_argument("--versions", default=None, help="comma list to sweep")
    ap.add_argument("--trio", action="store_true", help="sweep the 1.2 base/sp2/sp2p3 trio")
    ap.add_argument("--all", action="store_true", help="sweep every known version")
    ap.add_argument("--sweep", action="store_true", help="alias for --all")
    ap.add_argument("--flags", default=DEFAULT_FLAGS)
    ap.add_argument("--brief", action="store_true")
    ap.add_argument("--bin", default=None, help="override target binary path")
    ap.add_argument("--base", default=None, type=lambda x: int(x, 0),
                    help="load address of --bin")
    ap.add_argument(
        "--strict-relocs",
        dest="strict_relocs",
        action="store_true",
        default=True,
        help="(default) also verify each reloc slot points where config says",
    )
    ap.add_argument(
        "--no-strict-relocs",
        dest="strict_relocs",
        action="store_false",
        help="skip reloc-destination check (loose byte-only compare)",
    )
    args = ap.parse_args()

    # Resolve module binary
    if args.bin:
        bin_path = pathlib.Path(args.bin)
        base = args.base if args.base is not None else ARM9_BASE
    else:
        try:
            import modules as MOD

            found = MOD.by_label(args.module)
            if found is None and args.module in MODULES:
                found = {
                    "bin": MODULES[args.module]["bin"],
                    "base": MODULES[args.module]["base"],
                    "name": args.module,
                }
            if found is None:
                raise SystemExit(
                    f"module {args.module!r} not found (pass --bin/--base)"
                )
            bin_path, base = found["bin"], found["base"]
        except ImportError:
            if args.module not in MODULES:
                raise SystemExit(f"unknown module {args.module}")
            bin_path = MODULES[args.module]["bin"]
            base = MODULES[args.module]["base"]

    if not bin_path.is_file():
        print(f"missing {bin_path} — unpack your ROM first", file=sys.stderr)
        sys.exit(1)
    if not MW.is_dir():
        print("missing tools/mwccarm — see notes/compiler.md / notes/setup-mwccarm.md",
              file=sys.stderr)
        sys.exit(1)

    strict = None
    if args.strict_relocs:
        try:
            import reloc_audit as RA
            import relocs as RL

            strict = (RA, RA.build_name_index(), RA.build_config_relocs(), RL.load_all_syms())
        except Exception as e:
            print(f"  (reloc-destination check unavailable: {e}; byte-only compare)")

    cfile = pathlib.Path(args.c)
    flags = args.flags
    try:
        if cfile.read_text(encoding="utf-8").startswith("//cpp") and "-lang c99" in flags:
            flags = flags.replace("-lang c99", "-lang c++")
    except OSError:
        pass

    tgt = target_bytes(args.addr, args.size, bin_path, base)
    hexstr = tgt.hex()
    shown = hexstr if (not args.brief or len(hexstr) <= 128) else f"{hexstr[:128]}... ({len(tgt)} bytes)"
    print(f"TARGET {args.func} @ 0x{args.addr:08x} size 0x{args.size:x}  bytes: {shown}")

    if args.version:
        versions = [args.version]
    elif args.versions:
        versions = [v.strip() for v in args.versions.split(",") if v.strip()]
    elif args.all or args.sweep:
        versions = SWEEP
    elif args.trio:
        versions = PINNED
    else:
        versions = [CANONICAL]

    matched = []
    closest = None
    for v in versions:
        if not args.brief:
            print(f"\n=== mwccarm {v} ===")
        obj = compile_c(cfile, v, flags)
        if obj is None:
            continue
        code, relocs = extract_func(obj, args.func)
        if code is None:
            print(f"  {v}: symbol {args.func!r} not found in object")
            continue
        relocs = relocs or set()
        ok, ndiff = compare(tgt, code, relocs, verbose=not args.brief)
        if ok and strict is not None:
            RA, name_index, config_relocs, sym_index = strict
            try:
                rows, _missing = RA.check_destinations(
                    obj, args.func, args.addr, args.size,
                    args.module, name_index, config_relocs, sym_index,
                )
                bad = [r for r in (rows or []) if r["verdict"] == "WRONG-DEST"]
            except Exception as e:
                bad = []
                print(f"  {v}: (reloc-destination check skipped: {e})")
            if bad:
                ok = False
                print(
                    f"  {v}: bytes match but {len(bad)} reloc destination(s) WRONG -- "
                    f"not a real match:"
                )
                for r in bad:
                    print(
                        f"      {r['off']:6} cand {r['cand']} ({r['cand_addr']}) "
                        f"!= config {r['cfg']}"
                    )
        if ok:
            matched.append(v)
            if args.brief:
                print(f"  {v}: MATCH")
            else:
                print(f"MATCH with {v}")
        else:
            if args.brief:
                print(f"  {v}: {ndiff} word(s) differ")
            if closest is None or ndiff < closest[0]:
                closest = (ndiff, v, code, relocs)

    if args.brief and not matched and closest is not None:
        print(f"\n--- closest: {closest[1]} ({closest[0]} differ) ---")
        compare(tgt, closest[2], closest[3], verbose=True)

    print("\n" + "=" * 40)
    print("MATCHING VERSIONS:", ", ".join(matched) if matched else "none")
    sys.exit(0 if matched else 1)


if __name__ == "__main__":
    main()

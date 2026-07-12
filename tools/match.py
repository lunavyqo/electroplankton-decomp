#!/usr/bin/env python3
"""Compile candidate C with mwccarm and compare to local ARM9/ARM7 bytes.

Relocation-aware: absolute slots that the linker fills are wildcarded.

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

MODULES = {
    "arm9": {"bin": REPO / "arm9" / "arm9.bin", "base": 0x02000000},
    "arm7": {"bin": REPO / "arm7" / "arm7.bin", "base": 0x02380000},
}

DEFAULT_FLAGS = (
    "-O4,p -enum int -lang c99 -char signed -interworking "
    "-proc arm946e -gccext,on -msgstyle gcc"
)
# Sweep candidates until notes/compiler.md pins one.
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
CANONICAL = "1.2/sp2p3"  # provisional — not yet proven for Electroplankton

md = Cs(CS_ARCH_ARM, CS_MODE_ARM)


def target_bytes(addr: int, size: int, bin_path: pathlib.Path, base: int) -> bytes:
    data = bin_path.read_bytes()
    off = addr - base
    if off < 0 or off + size > len(data):
        raise SystemExit(f"target range out of bounds addr=0x{addr:x} size=0x{size:x}")
    return data[off : off + size]


def compile_c(cfile: pathlib.Path, version: str, flags: str) -> bytes | None:
    exe = MW / version / "mwccarm.exe"
    if not exe.is_file():
        print(f"  ! no compiler at {version}")
        return None
    with tempfile.TemporaryDirectory() as td:
        out_o = pathlib.Path(td) / "out.o"
        env = dict(os.environ)
        if LICENSE.is_file():
            env["LM_LICENSE_FILE"] = str(LICENSE)
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
    reloc_offs: set[int] = set()
    for section in elf.iter_sections():
        if section.header["sh_type"] not in ("SHT_REL", "SHT_RELA"):
            continue
        if section.header["sh_info"] != sym["st_shndx"]:
            continue
        for rel in section.iter_relocations():
            off = rel["r_offset"]
            if start <= off < start + size:
                reloc_offs.add(off - start)
    return code, reloc_offs


def compare(target: bytes, cand: bytes, reloc_offs: set[int]) -> tuple[bool, int, list[str]]:
    lines = []
    if len(cand) != len(target):
        lines.append(f"size mismatch: target={len(target)} cand={len(cand)}")
        return False, max(len(target), len(cand)) // 4, lines
    divergences = 0
    n = len(target)
    for i in range(0, n, 4):
        tw = target[i : i + 4]
        cw = cand[i : i + 4]
        is_reloc = any(r // 4 * 4 == i for r in reloc_offs) or i in reloc_offs
        # also mark if any reloc offset falls in this word
        is_reloc = any(i <= r < i + 4 for r in reloc_offs)
        ok = is_reloc or tw == cw
        if not ok:
            divergences += 1
        t_ins = next(md.disasm(tw, 0), None)
        c_ins = next(md.disasm(cw, 0), None)
        t_s = f"{t_ins.mnemonic} {t_ins.op_str}" if t_ins else tw.hex()
        c_s = f"{c_ins.mnemonic} {c_ins.op_str}" if c_ins else cw.hex()
        mark = "reloc" if is_reloc else ("OK" if ok else "MISMATCH")
        if not ok or is_reloc:
            lines.append(f"  +0x{i:03x}  tgt: {t_s:40s} cand: {c_s:40s} {mark}")
    return divergences == 0 and len(cand) == len(target), divergences, lines


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--c", required=True, help="Candidate C/C++ file")
    ap.add_argument("--func", required=True)
    ap.add_argument("--addr", required=True)
    ap.add_argument("--size", required=True)
    ap.add_argument("--module", default="arm9", choices=sorted(MODULES))
    ap.add_argument("--version", default=None, help=f"mwccarm version (default {CANONICAL})")
    ap.add_argument("--flags", default=DEFAULT_FLAGS)
    ap.add_argument("--sweep", action="store_true", help="Try all known mwccarm versions")
    ap.add_argument("--brief", action="store_true")
    args = ap.parse_args()

    mod = MODULES[args.module]
    if not mod["bin"].is_file():
        print(f"missing {mod['bin']} — unpack your ROM first", file=sys.stderr)
        sys.exit(1)
    if not MW.is_dir():
        print("missing tools/mwccarm — see notes/compiler.md", file=sys.stderr)
        sys.exit(1)

    addr, size = int(args.addr, 0), int(args.size, 0)
    tgt = target_bytes(addr, size, mod["bin"], mod["base"])
    # default: single provisional version; --sweep tries all
    if args.sweep:
        versions = SWEEP
    else:
        versions = [args.version or CANONICAL]

    best = None
    for ver in versions:
        print(f"== {ver} ==")
        obj = compile_c(pathlib.Path(args.c), ver, args.flags)
        if obj is None:
            continue
        code, relocs = extract_func(obj, args.func)
        if code is None:
            print(f"  ! symbol {args.func!r} not in object")
            continue
        relocs = relocs or set()
        ok, div, lines = compare(tgt, code, relocs)
        print(f"  size target={len(tgt)} cand={len(code)} relocs={len(relocs)} div={div} match={ok}")
        if not args.brief:
            for ln in lines[:40]:
                print(ln)
            if len(lines) > 40:
                print(f"  ... ({len(lines) - 40} more lines)")
        if best is None or div < best[0]:
            best = (div, ver, ok)
        if ok:
            print(f"MATCH with {ver}")
            sys.exit(0)

    if best:
        print(f"best: {best[1]} div={best[0]} match={best[2]}")
    sys.exit(1)


if __name__ == "__main__":
    main()

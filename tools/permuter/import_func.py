#!/usr/bin/env python3
"""Set up a decomp-permuter working directory for one unmatched EP function.

Wiring of https://github.com/simonlindholm/decomp-permuter for this repo
(same pattern as sm64ds-decomp tools/permuter/).

Given a function (by name or module+addr) and a seed C file, writes:

    <out>/target.o          raw ROM bytes of the function
    <out>/target.o.relocs   reloc offsets to wildcard
    <out>/compile.sh        -> tools/permuter/mwccarm_compile.sh
    <out>/base.c            seed C (near-miss / draft)
    <out>/settings.toml     mwcc + cap_objdump scorer
    <out>/cc.txt            optional direct mwccarm cmdline (faster on Windows)

Then:
    python vendor/decomp-permuter/permuter.py <out> --stop-on-zero -j 4

Score 0 = permuter thinks it matches; still verify with tools/match.py before bank.

Usage:
    python tools/permuter/import_func.py --name func_02050928 --base seed.c
    python tools/permuter/import_func.py --module arm9 --addr 0x02050928 --base seed.c
    python tools/permuter/import_func.py --name func_02050928 --from-nearmiss
"""
from __future__ import annotations

import argparse
import io
import json
import pathlib
import re
import subprocess
import sys
import tempfile

REPO = pathlib.Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "tools"))

from bank import load_symbol  # noqa: E402
from match import (  # noqa: E402
    CANONICAL,
    DEFAULT_FLAGS,
    MODULES,
    compile_c,
    extract_func,
    target_bytes,
)
from nearmiss_db import load_db, key_of  # noqa: E402

PERM_DIR = REPO / "vendor" / "decomp-permuter"
WRAPPER = REPO / "tools" / "permuter" / "mwccarm_compile.sh"
CAP = REPO / "tools" / "permuter" / "cap_objdump.py"
MWCC = REPO / "tools" / "mwccarm" / "1.2" / "sp2p3" / "mwccarm.exe"
LICENSE = REPO / "tools" / "mwccarm" / "license.dat"
CFLAGS = DEFAULT_FLAGS.split()
ADDR_IN_NAME = re.compile(r"func_([0-9a-fA-F]{6,8})$", re.I)


def to_posix(p: pathlib.Path) -> str:
    s = str(p.resolve())
    if len(s) > 1 and s[1] == ":":
        s = "/" + s[0].lower() + s[2:].replace("\\", "/")
    return s


def to_win(p: pathlib.Path) -> str:
    return str(p.resolve()).replace("\\", "/")


def resolve_func(
    module: str | None, addr: int | None, name: str | None
) -> tuple[str, str, int, int]:
    """Return (module, name, addr, size)."""
    if name:
        info = load_symbol(name)
        if info:
            mod, a, size = info
            return mod, name, a, size
        m = ADDR_IN_NAME.search(name)
        if m and addr is None:
            addr = int(m.group(1), 16)
    if addr is None:
        raise SystemExit("need --name and/or --addr")
    want_mod = module or "arm9"
    config = REPO / "config"
    FUNC_RE = re.compile(
        r"^(\S+)\s+kind:function\((?:arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
    )
    for sym in config.rglob("symbols.txt"):
        rel = sym.parent.relative_to(config).as_posix()
        if rel in ("arm9", "arm7"):
            label = rel
        else:
            om = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
            if not om:
                continue
            label = om.group(1)
        if label != want_mod:
            continue
        for line in sym.read_text(errors="ignore").splitlines():
            m = FUNC_RE.match(line)
            if not m:
                continue
            n, size_h, addr_h = m.group(1), m.group(2), m.group(3)
            a = int(addr_h, 16)
            if a == addr or (name and n == name):
                return label, n, a, int(size_h, 16)
    raise SystemExit(f"function not found module={module} addr={addr} name={name}")


def candidate_reloc_offsets(base_c: pathlib.Path, func: str) -> list[int] | None:
    """Compile seed; return .rel.text offsets for the function (relative to func start)."""
    obj = compile_c(base_c, CANONICAL, DEFAULT_FLAGS)
    if obj is None:
        return None
    code, offs = extract_func(obj, func)
    if code is None:
        # whole .text relocs as absolute file offsets — use raw from ELF
        elf = __import__("elftools.elf.elffile", fromlist=["ELFFile"]).ELFFile(
            io.BytesIO(obj)
        )
        rel = elf.get_section_by_name(".rel.text") or elf.get_section_by_name(
            ".rela.text"
        )
        if rel is None:
            return []
        return sorted(r["r_offset"] for r in rel.iter_relocations())
    return sorted(offs)


def seed_from_nearmiss(module: str, addr: int, name: str) -> str | None:
    db = load_db()
    rec = db.get(key_of(module, addr))
    if rec and (rec.get("c_source") or "").strip():
        return rec["c_source"]
    # try by name
    for r in db.values():
        if r.get("name") == name and (r.get("c_source") or "").strip():
            return r["c_source"]
    return None


def setup_dir(
    module: str,
    name: str,
    addr: int,
    size: int,
    base_src: str,
    out: pathlib.Path | None = None,
) -> tuple[pathlib.Path, int]:
    """Write permuter dir. Returns (out_path, n_relocs)."""
    if module not in MODULES:
        raise SystemExit(f"unknown module {module!r} (need local binary mapping)")
    mod = MODULES[module]
    if not mod["bin"].is_file():
        raise SystemExit(f"missing binary {mod['bin']} — unpack ROM first")
    tgt = target_bytes(addr, size, mod["bin"], mod["base"])

    out = pathlib.Path(out) if out else (PERM_DIR / "work" / name)
    out.mkdir(parents=True, exist_ok=True)

    (out / "compile.sh").write_text(
        f'#!/bin/bash\nexec "{to_posix(WRAPPER)}" "$@"\n'
    )
    (out / "compile.sh").chmod(0o755)
    if MWCC.is_file():
        (out / "cc.txt").write_text(
            json.dumps(
                {
                    "cmd": [to_win(MWCC), *CFLAGS, "-c"],
                    "license": to_win(LICENSE) if LICENSE.is_file() else "",
                }
            )
        )
    (out / "base.c").write_text(base_src)
    (out / "target.o").write_bytes(tgt)

    reloc_offs = candidate_reloc_offsets(out / "base.c", name)
    if reloc_offs is None:
        reloc_offs = []
    (out / "target.o.relocs").write_text(
        "".join(f"0x{o:x}\n" for o in reloc_offs)
    )

    (out / "settings.toml").write_text(
        f'compiler_type = "mwcc"\n'
        f'func_name = "{name}"\n'
        f'objdump_command = "python {to_win(CAP)}"\n'
    )
    return out, len(reloc_offs)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--module", default=None)
    ap.add_argument("--addr", type=lambda x: int(x, 0), default=None)
    ap.add_argument("--name", default=None)
    ap.add_argument("--base", default=None, help="seed C file")
    ap.add_argument(
        "--from-nearmiss",
        action="store_true",
        help="seed from nearmiss/db.jsonl for this function",
    )
    ap.add_argument("--out", default=None, help="output dir (default vendor/.../work/<name>)")
    args = ap.parse_args()
    if args.addr is None and not args.name:
        ap.error("give --name and/or --addr")

    module, name, addr, size = resolve_func(args.module, args.addr, args.name)
    if size <= 0:
        raise SystemExit(f"bad size for {name}")

    base_src = None
    if args.from_nearmiss:
        base_src = seed_from_nearmiss(module, addr, name)
        if not base_src:
            raise SystemExit(f"no nearmiss tip for {module} {name} @ 0x{addr:08x}")
    elif args.base:
        base_src = pathlib.Path(args.base).read_text(encoding="utf-8", errors="ignore")
    else:
        base_src = (
            f"// seed: replace with a draft of {name}\n"
            f"void {name}(void) {{}}\n"
        )

    out, nrel = setup_dir(module, name, addr, size, base_src, args.out)
    print(
        f"imported {module} {name} @ 0x{addr:08x} "
        f"(size 0x{size:x}, {nrel} relocs) -> {out}"
    )
    perm = PERM_DIR / "permuter.py"
    if not perm.is_file():
        print(
            f"NOTE: clone decomp-permuter first:\n"
            f"  git clone https://github.com/simonlindholm/decomp-permuter "
            f"{to_posix(PERM_DIR)}\n"
            f"  python -m pip install toml pcpp pycparser capstone pyelftools",
            file=sys.stderr,
        )
    print(
        f"run: python {to_posix(perm)} {to_posix(out)} --stop-on-zero -j 4"
    )
    print(f"verify: python tools/match.py --c {out}/best.c --func {name} "
          f"--addr 0x{addr:x} --size 0x{size:x} --version 1.2/sp2p3")


if __name__ == "__main__":
    main()

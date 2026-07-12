#!/usr/bin/env python3
"""Disassemble a range of the local ARM9/ARM7 binary (ROM-derived, local only).

Usage:
  python tools/disasm.py --module arm9 --addr 0x02000800 --size 0x120
  python tools/disasm.py arm9/arm9.bin --offset 0x800 --length 0x40 --base 0x02000000
"""
from __future__ import annotations

import argparse
import pathlib
import sys

from capstone import CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB, Cs

REPO = pathlib.Path(__file__).resolve().parent.parent

MODULES = {
    "arm9": {"bin": REPO / "arm9" / "arm9.bin", "base": 0x02000000},
    "arm7": {"bin": REPO / "arm7" / "arm7.bin", "base": 0x02380000},
}


def disassemble(data: bytes, base: int, thumb: bool = False) -> list[str]:
    mode = CS_MODE_THUMB if thumb else CS_MODE_ARM
    md = Cs(CS_ARCH_ARM, mode)
    md.detail = False
    lines = []
    for insn in md.disasm(data, base):
        lines.append(f"  {insn.address:08x}:  {insn.mnemonic:8s} {insn.op_str}")
    return lines


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("binary", nargs="?", help="Path to binary (or use --module)")
    ap.add_argument("--module", choices=sorted(MODULES), help="Known module")
    ap.add_argument("--addr", help="Virtual address (hex)")
    ap.add_argument("--size", help="Byte length (hex or decimal)")
    ap.add_argument("--offset", help="File offset (hex) if not using --addr")
    ap.add_argument("--length", help="Alias for --size")
    ap.add_argument("--base", help="Load address override (hex)")
    ap.add_argument("--thumb", action="store_true")
    args = ap.parse_args()

    if args.module:
        mod = MODULES[args.module]
        path, base = mod["bin"], mod["base"]
    elif args.binary:
        path = pathlib.Path(args.binary)
        base = int(args.base, 0) if args.base else 0
    else:
        ap.error("provide binary path or --module")
        return

    if not path.is_file():
        print(f"missing binary: {path}", file=sys.stderr)
        sys.exit(1)

    blob = path.read_bytes()
    size = int(args.size or args.length or "0x40", 0)
    if args.addr:
        addr = int(args.addr, 0)
        off = addr - base
    else:
        off = int(args.offset or "0", 0)
        addr = base + off

    if off < 0 or off + size > len(blob):
        print(f"range out of bounds: off=0x{off:x} size=0x{size:x} file=0x{len(blob):x}", file=sys.stderr)
        sys.exit(1)

    for line in disassemble(blob[off : off + size], addr, thumb=args.thumb):
        print(line)


if __name__ == "__main__":
    main()

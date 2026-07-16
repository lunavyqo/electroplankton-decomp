#!/usr/bin/env python3
"""Build ghidra_targets.txt from committed config symbols (local-only output).

Writes one address per line (0x…) for every arm/thumb function in config/arm9
(and itcm/dtcm if present). Used as input to the headless Ghidra DecompDump
script. Output is gitignored — never commit it.

Usage:
  python tools/ghidra_targets.py
  python tools/ghidra_targets.py --out ghidra_targets.txt
"""
from __future__ import annotations

import argparse
import pathlib
import re
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
CFG = REPO / "config" / "arm9"

LINE_RE = re.compile(
    r"^(\S+)\s+kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\)\s+addr:0x([0-9a-fA-F]+)"
)


def iter_symbol_files():
    yield CFG / "symbols.txt"
    for sub in ("itcm", "dtcm"):
        p = CFG / sub / "symbols.txt"
        if p.is_file():
            yield p
    ov = CFG / "overlays"
    if ov.is_dir():
        for p in sorted(ov.glob("ov*/symbols.txt")):
            yield p


def collect_addrs() -> list[int]:
    addrs: set[int] = set()
    for path in iter_symbol_files():
        if not path.is_file():
            continue
        for line in path.read_text(errors="ignore").splitlines():
            m = LINE_RE.match(line)
            if m:
                addrs.add(int(m.group(4), 16))
    return sorted(addrs)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument(
        "--out",
        type=pathlib.Path,
        default=REPO / "ghidra_targets.txt",
        help="output path (default: repo-root ghidra_targets.txt, gitignored)",
    )
    args = ap.parse_args()

    addrs = collect_addrs()
    if not addrs:
        print("no function symbols found under config/arm9/", file=sys.stderr)
        sys.exit(1)

    args.out.write_text("".join(f"0x{a:08x}\n" for a in addrs))
    print(f"wrote {len(addrs)} addresses -> {args.out}")


if __name__ == "__main__":
    main()

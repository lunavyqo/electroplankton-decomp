#!/usr/bin/env python3
"""Print decomp progress from committed symbols + src/."""
from __future__ import annotations

import argparse
import pathlib
import re

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"
SRC = REPO / "src"

FUNC_RE = re.compile(
    r"^(\S+)\s+kind:function\((?:arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
)


def module_label(sym_path: pathlib.Path):
    rel = sym_path.parent.relative_to(CONFIG).as_posix()
    if rel in ("arm9", "arm7"):
        return rel
    m = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
    return m.group(1) if m else None


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--bar", action="store_true")
    args = ap.parse_args()

    total_n = matched_n = total_b = matched_b = 0
    for sym in sorted(CONFIG.rglob("symbols.txt")):
        if module_label(sym) is None:
            continue
        for line in sym.read_text(errors="ignore").splitlines():
            m = FUNC_RE.match(line)
            if not m:
                continue
            name, size = m.group(1), int(m.group(2), 16)
            total_n += 1
            total_b += size
            for ext in ("c", "cpp"):
                f = SRC / f"{name}.{ext}"
                if f.is_file() and "NONMATCHING" not in f.read_text(errors="ignore")[:200]:
                    matched_n += 1
                    matched_b += size
                    break

    pf = 100.0 * matched_n / total_n if total_n else 0.0
    pb = 100.0 * matched_b / total_b if total_b else 0.0

    def bar(p: float, width: int = 30) -> str:
        filled = int(width * p / 100)
        return "█" * filled + "░" * (width - filled)

    block = (
        f"Functions  {bar(pf)}  {pf:5.1f}%   {matched_n:,} / {total_n:,}\n"
        f"Code size  {bar(pb)}  {pb:5.1f}%   {matched_b:,} / {total_b:,} bytes"
    )
    if args.bar:
        print(block)
    else:
        print(block)
        print(f"modules from config/: {sum(1 for s in CONFIG.rglob('symbols.txt') if module_label(s))}")


if __name__ == "__main__":
    main()

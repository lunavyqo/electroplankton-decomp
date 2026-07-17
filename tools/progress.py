#!/usr/bin/env python3
"""Print / write decomp progress from committed symbols + src/, or from chaos-db.json.

Same role as sm64ds-decomp tools/progress.py (README bar; progress map is Chaos Viewer):
  python tools/progress.py
  python tools/progress.py --bar
  python tools/progress.py --write-readme --from-db path/to/chaos-db.json
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"
SRC = REPO / "src"
README = REPO / "README.md"

README_START = "<!-- progress:start -->"
README_END = "<!-- progress:end -->"

FUNC_RE = re.compile(
    r"^(\S+)\s+kind:function\((?:arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
)


def module_label(sym_path: pathlib.Path):
    rel = sym_path.parent.relative_to(CONFIG).as_posix()
    if rel in ("arm9", "arm7"):
        return rel
    m = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
    return m.group(1) if m else None


def bar(done: int, tot: int, width: int = 30) -> str:
    """SM64DS-style block bar (same glyph fill as sm64ds-decomp tools/progress.py)."""
    filled = round(done / tot * width) if tot else 0
    if done and filled == 0:
        filled = 1
    return "█" * filled + "░" * (width - filled)


def scan_src() -> tuple[int, int, int, int]:
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
            found = None
            for ext in ("c", "cpp"):
                direct = SRC / f"{name}.{ext}"
                if direct.is_file():
                    found = direct
                    break
                hits = list(SRC.glob(f"**/{name}.{ext}"))
                if hits:
                    found = hits[0]
                    break
            if found is not None and "NONMATCHING" not in found.read_text(errors="ignore")[:200]:
                matched_n += 1
                matched_b += size
    return matched_n, total_n, matched_b, total_b


def from_db(path: pathlib.Path) -> tuple[int, int, int, int]:
    """Read counts from chaos-db.json so README and atlas share one number.

    Skips synthetic atlas-only fixtures (module demo / attempt-history gallery).
    """
    db = json.loads(path.read_text(encoding="utf-8"))
    fns = db["functions"] if isinstance(db, dict) else db
    real = [
        f
        for f in fns
        if f.get("module") != "demo"
        and f.get("id") != "demo:0x0"
        and f.get("name") != "func_attempt_history_gallery"
    ]
    n = len(real)
    done_n = sum(1 for f in real if f.get("matched"))
    tb = sum(int(f.get("size", 0)) for f in real)
    done_b = sum(int(f.get("size", 0)) for f in real if f.get("matched"))
    return int(done_n), n, int(done_b), tb


def bar_block(done_n: int, n: int, done_b: int, tb: int) -> str:
    """Fenced ``` block under README ## Progress — same shape as sm64ds-decomp."""
    lines = [
        "```",
        f"Functions  {bar(done_n, n)}  {100 * done_n / n:4.1f}%   {done_n:,} / {n:,}"
        if n
        else f"Functions  {bar(0, 1)}   0.0%   0 / 0",
        f"Code size  {bar(done_b, tb)}  {100 * done_b / tb:4.1f}%   {done_b:,} / {tb:,} bytes"
        if tb
        else f"Code size  {bar(0, 1)}   0.0%   0 / 0 bytes",
        "```",
    ]
    return "\n".join(lines)


def write_readme(done_n: int, n: int, done_b: int, tb: int) -> bool:
    """Replace the text between the progress markers in README.md in place."""
    text = README.read_text(encoding="utf-8")
    if README_START not in text or README_END not in text:
        print(
            f"WARN: README.md missing {README_START!r} / {README_END!r} markers; skip",
            file=sys.stderr,
        )
        return False
    start = text.index(README_START) + len(README_START)
    end = text.index(README_END)
    new_text = text[:start] + "\n" + bar_block(done_n, n, done_b, tb) + "\n" + text[end:]
    if new_text != text:
        README.write_text(new_text, encoding="utf-8")
        return True
    return False


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--bar", action="store_true", help="Print progress bars only")
    ap.add_argument(
        "--write-readme",
        action="store_true",
        help=f"Rewrite block between {README_START} and {README_END} in README.md",
    )
    ap.add_argument(
        "--from-db",
        type=pathlib.Path,
        default=None,
        help="Use chaos-db.json counts (same numbers as the viewer atlas)",
    )
    args = ap.parse_args()

    if args.from_db is not None:
        if not args.from_db.is_file():
            print(f"ERROR: --from-db not found: {args.from_db}", file=sys.stderr)
            sys.exit(1)
        done_n, n, done_b, tb = from_db(args.from_db)
    else:
        root_db = REPO / "chaos-db.json"
        if root_db.is_file():
            done_n, n, done_b, tb = from_db(root_db)
        else:
            done_n, n, done_b, tb = scan_src()

    if args.write_readme:
        changed = write_readme(done_n, n, done_b, tb)
        print(f"README.md {'updated' if changed else 'already up to date'}")
        return

    block = bar_block(done_n, n, done_b, tb)
    try:
        sys.stdout.reconfigure(encoding="utf-8")  # type: ignore[attr-defined]
    except Exception:
        pass
    if args.bar:
        print(block)
    else:
        print(block)
        print(
            f"modules from config/: "
            f"{sum(1 for s in CONFIG.rglob('symbols.txt') if module_label(s))}"
        )


if __name__ == "__main__":
    main()

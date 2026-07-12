#!/usr/bin/env python3
"""Validate that every src/**/*.c[pp] in a PR (or the whole tree) matches the ROM.

Looks up addr/size from config/**/symbols.txt, compiles with mwccarm via match.py,
and fails if any file does not reproduce the binary.

Usage:
  # all sources under src/
  python tools/pr_validate.py

  # only files changed vs main
  python tools/pr_validate.py --base origin/main

  # explicit list
  python tools/pr_validate.py --files src/arm9/func_02001b44.c

Requires local (gitignored) arm9.bin + tools/mwccarm — same as match.py.
Exit 0 = all match; 1 = at least one failure.
"""
from __future__ import annotations

import argparse
import pathlib
import re
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"
SRC = REPO / "src"
MATCH = REPO / "tools" / "match.py"

FUNC_RE = re.compile(
    r"^(\S+)\s+kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
)
# src/arm9/func_02001b44.c or src/func_02001b44.c
SRC_NAME_RE = re.compile(r"^(?:.*/)?([^/]+)\.(c|cpp)$")


def load_symbols() -> dict[str, tuple[str, int, int, str]]:
    """name -> (module, addr, size, mode)."""
    out: dict[str, tuple[str, int, int, str]] = {}
    for sym in CONFIG.rglob("symbols.txt"):
        rel = sym.parent.relative_to(CONFIG).as_posix()
        if rel in ("arm9", "arm7"):
            module = rel
        else:
            m = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
            if not m:
                continue
            module = m.group(1)
        for line in sym.read_text(errors="ignore").splitlines():
            m = FUNC_RE.match(line)
            if not m:
                continue
            name, mode, size_h, addr_h = m.groups()
            out[name] = (module, int(addr_h, 16), int(size_h, 16), mode)
    return out


def changed_src_files(base: str) -> list[pathlib.Path]:
    r = subprocess.run(
        ["git", "diff", "--name-only", "--diff-filter=AM", f"{base}...HEAD"],
        cwd=REPO,
        capture_output=True,
        text=True,
    )
    if r.returncode != 0:
        # first commit / shallow: fall back to all
        return list(SRC.rglob("*.c")) + list(SRC.rglob("*.cpp"))
    files = []
    for line in r.stdout.splitlines():
        p = pathlib.Path(line)
        if p.suffix in (".c", ".cpp") and (str(p).startswith("src/") or str(p).startswith("src\\")):
            files.append(REPO / p)
    return files


def all_src_files() -> list[pathlib.Path]:
    return sorted(list(SRC.rglob("*.c")) + list(SRC.rglob("*.cpp")))


def is_nonmatching(path: pathlib.Path) -> bool:
    head = path.read_text(errors="ignore")[:400]
    return "NONMATCHING" in head


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--base", help="git base ref; only validate files changed since base")
    ap.add_argument("--files", nargs="*", help="explicit source paths")
    ap.add_argument("--version", default="1.2/sp2p3")
    ap.add_argument("--brief", action="store_true", default=True)
    args = ap.parse_args()

    if not (REPO / "arm9" / "arm9.bin").is_file():
        print("ERROR: arm9/arm9.bin missing — unpack your ROM first", file=sys.stderr)
        sys.exit(2)
    if not (REPO / "tools" / "mwccarm").exists():
        print("ERROR: tools/mwccarm missing — see notes/compiler.md", file=sys.stderr)
        sys.exit(2)

    symbols = load_symbols()
    if args.files:
        paths = [pathlib.Path(f) if pathlib.Path(f).is_absolute() else REPO / f for f in args.files]
    elif args.base:
        paths = changed_src_files(args.base)
    else:
        paths = all_src_files()

    paths = [p for p in paths if p.is_file()]
    if not paths:
        print("No src/*.c files to validate.")
        sys.exit(0)

    print(f"Validating {len(paths)} file(s) with mwccarm {args.version}")
    failed = []
    skipped = []
    passed = []

    for path in paths:
        try:
            rel = path.resolve().relative_to(REPO.resolve()).as_posix()
        except ValueError:
            rel = str(path)
        # stem is the function name (func_0200… or a real symbol name)
        name = path.stem
        if is_nonmatching(path):
            skipped.append((rel, "NONMATCHING"))
            print(f"  SKIP {rel} (NONMATCHING)")
            continue
        if name not in symbols:
            failed.append((rel, "not in symbols.txt"))
            print(f"  FAIL {rel}: symbol {name!r} not in config/**/symbols.txt")
            continue
        module, addr, size, mode = symbols[name]
        if mode == "thumb":
            # match.py currently ARM-mode target compare; still try
            pass
        cmd = [
            sys.executable,
            str(MATCH),
            "--c",
            str(path),
            "--func",
            name,
            "--addr",
            hex(addr),
            "--size",
            hex(size),
            "--module",
            module if module in ("arm9", "arm7") else "arm9",
            "--version",
            args.version,
            "--brief",
        ]
        r = subprocess.run(cmd, cwd=REPO, capture_output=True, text=True, timeout=180)
        ok = r.returncode == 0 and "MATCH" in (r.stdout + r.stderr)
        if ok:
            passed.append(rel)
            print(f"  PASS {rel}  ({module} 0x{addr:08x} size 0x{size:x})")
        else:
            failed.append((rel, "byte mismatch or compile error"))
            print(f"  FAIL {rel}  ({module} 0x{addr:08x} size 0x{size:x})")
            tail = (r.stdout + "\n" + r.stderr).strip().splitlines()[-15:]
            for line in tail:
                print(f"         {line}")

    print()
    print(f"Summary: {len(passed)} passed, {len(failed)} failed, {len(skipped)} skipped")
    if failed:
        print("FAILED:")
        for rel, why in failed:
            print(f"  - {rel}: {why}")
        sys.exit(1)
    print("All changed matching sources reproduce the ROM.")
    sys.exit(0)


if __name__ == "__main__":
    main()

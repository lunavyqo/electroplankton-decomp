#!/usr/bin/env python3
"""Unpack a Nintendo DS ROM into the local extract layout (gitignored binaries).

Requires `dsd` on PATH. Output is written next to this repo's existing dsd extract
layout (arm9/, arm7/, files/, config.yaml, …).

Usage:
  python tools/unpack.py path/to/your-Electroplankton.nds
"""
from __future__ import annotations

import argparse
import pathlib
import shutil
import subprocess
import sys
import tempfile

REPO = pathlib.Path(__file__).resolve().parent.parent


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("rom", type=pathlib.Path, help="Path to your legally dumped .nds")
    ap.add_argument("--out", type=pathlib.Path, default=REPO,
                    help="Extract directory (default: repo root, dsd-style)")
    args = ap.parse_args()

    if not args.rom.is_file():
        print(f"ROM not found: {args.rom}", file=sys.stderr)
        sys.exit(1)
    if shutil.which("dsd") is None:
        print("dsd not found on PATH — install https://github.com/AetiasHax/ds-decomp", file=sys.stderr)
        sys.exit(1)

    # dsd rom extract wants an empty/new directory; extract then copy config pieces.
    with tempfile.TemporaryDirectory() as td:
        td_path = pathlib.Path(td) / "extract"
        td_path.mkdir()
        # Copy ROM in so dsd can read it; extract into td_path
        rom_copy = td_path / args.rom.name
        shutil.copy2(args.rom, rom_copy)
        # dsd rom extract <rom> <out>
        cmd = ["dsd", "rom", "extract", "--rom", str(rom_copy), "--output-path", str(td_path / "out")]
        # try both CLI shapes
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode != 0:
            cmd2 = ["dsd", "rom", "extract", str(rom_copy), str(td_path / "out")]
            r = subprocess.run(cmd2, capture_output=True, text=True)
        if r.returncode != 0:
            print(r.stdout)
            print(r.stderr, file=sys.stderr)
            print(
                "dsd rom extract failed. If your dsd CLI differs, extract manually:\n"
                "  dsd rom extract --help\n"
                "Then place the result so config.yaml, arm9/, arm7/, files/ exist.",
                file=sys.stderr,
            )
            sys.exit(1)
        out = td_path / "out"
        # Merge into repo root / --out
        for item in out.iterdir():
            dest = args.out / item.name
            if dest.exists():
                if dest.is_dir():
                    shutil.rmtree(dest)
                else:
                    dest.unlink()
            shutil.move(str(item), str(dest))
        print(f"Extracted into {args.out}")
        print("Next: dsd init -r config.yaml -o config -b build")
        print("Never commit the .nds, .bin files, or files/ tree.")


if __name__ == "__main__":
    main()

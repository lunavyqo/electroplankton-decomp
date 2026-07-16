#!/usr/bin/env python3
"""Run decomp-permuter on near-miss seeds (EP wiring).

Seeds:
  --seeds FILE.jsonl   lines: {name|module+addr, c_source}  or nearmiss-shaped
  --from-nearmiss      all tips in nearmiss/db.jsonl with c_source + div>0

For each seed: import_func.setup_dir → permuter.py --stop-on-zero → match.py verify.
Does NOT auto-commit. Optional --bank runs tools/bank.py on score-0 wins.

Usage:
  python tools/permuter/batch.py --from-nearmiss --limit 5 --secs 90
  python tools/permuter/batch.py --seeds seeds.jsonl --secs 120 --jobs 4
  python tools/permuter/batch.py --from-nearmiss --max-div 8 --dry-run
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import shutil
import subprocess
import sys
import tempfile
import time

REPO = pathlib.Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "tools"))
sys.path.insert(0, str(REPO / "tools" / "permuter"))

import import_func as IMP  # noqa: E402
from bank import load_symbol  # noqa: E402
from match import CANONICAL, DEFAULT_FLAGS, compile_c, extract_func, target_bytes, MODULES, compare  # noqa: E402
from nearmiss_db import load_db  # noqa: E402

PERM = REPO / "vendor" / "decomp-permuter" / "permuter.py"
ADDR_IN_NAME = re.compile(r"func_([0-9a-fA-F]{6,8})$", re.I)


def resolve_seed(obj: dict) -> tuple[str, str, int, int, str] | None:
    """Return (module, name, addr, size, c_source) or None."""
    src = (obj.get("c_source") or obj.get("cSource") or "").strip()
    if not src:
        return None
    name = obj.get("name")
    module = obj.get("module") or "arm9"
    addr = obj.get("addr")
    if isinstance(addr, str):
        addr = int(addr, 0)
    size = obj.get("size")
    if isinstance(size, str):
        size = int(size, 0)
    if name:
        info = load_symbol(name)
        if info:
            module, addr, size = info[0], info[1], info[2]
        elif addr is None:
            m = ADDR_IN_NAME.search(name)
            if m:
                addr = int(m.group(1), 16)
    if name is None and addr is not None:
        name = f"func_{addr:08x}"
    if addr is None or not name:
        return None
    if not size:
        try:
            module, name, addr, size = IMP.resolve_func(module, addr, name)
        except SystemExit:
            return None
    return module, name, int(addr), int(size), src


def seeds_from_nearmiss(max_div: int | None) -> list[dict]:
    out = []
    for rec in load_db().values():
        div = rec.get("divergences")
        if div is None:
            continue
        try:
            d = int(div)
        except (TypeError, ValueError):
            continue
        if d <= 0:
            continue
        if max_div is not None and d > max_div:
            continue
        if not (rec.get("c_source") or "").strip():
            continue
        out.append(rec)
    out.sort(key=lambda r: int(r.get("divergences") or 9999))
    return out


def run_permuter(work: pathlib.Path, secs: int, jobs: int) -> pathlib.Path | None:
    """Return path to best output C if score-0 found, else None."""
    if not PERM.is_file():
        print(f"ERROR: missing {PERM} — clone decomp-permuter into vendor/", file=sys.stderr)
        return None
    log = work / "permuter.log"
    cmd = [
        sys.executable,
        str(PERM),
        str(work),
        "--stop-on-zero",
        "-j",
        str(jobs),
    ]
    try:
        with open(log, "w", encoding="utf-8") as lf:
            proc = subprocess.Popen(
                cmd, stdout=lf, stderr=subprocess.STDOUT, cwd=str(REPO)
            )
            try:
                proc.wait(timeout=secs)
            except subprocess.TimeoutExpired:
                proc.kill()
                proc.wait()
    except Exception as e:
        print(f"  permuter failed: {e}")
        return None
    # decomp-permuter writes output.c or keeps best in base.c when --stop-on-zero
    for cand in ("output.c", "best.c", "base.c"):
        p = work / cand
        if p.is_file() and p.stat().st_size > 0:
            # Prefer output.c if present and newer than start
            pass
    out = work / "output.c"
    if out.is_file() and out.stat().st_size > 10:
        return out
    # Some versions leave the win in base.c
    base = work / "base.c"
    return base if base.is_file() else None


def oracle_match(c_path: pathlib.Path, name: str, module: str, addr: int, size: int) -> bool:
    if module not in MODULES or not MODULES[module]["bin"].is_file():
        return False
    obj = compile_c(c_path, CANONICAL, DEFAULT_FLAGS)
    if obj is None:
        return False
    code, rel = extract_func(obj, name)
    if code is None:
        return False
    tgt = target_bytes(addr, size, MODULES[module]["bin"], MODULES[module]["base"])
    ok, _div, _ = compare(tgt, code, rel or set())
    return ok


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--seeds", type=pathlib.Path, help="JSONL of near-miss seeds")
    ap.add_argument("--from-nearmiss", action="store_true", help="use nearmiss/db.jsonl")
    ap.add_argument("--max-div", type=int, default=None, help="only tips with div <= N")
    ap.add_argument("--limit", type=int, default=0, help="max functions (0=all)")
    ap.add_argument("--secs", type=int, default=90, help="permuter time budget per func")
    ap.add_argument("--jobs", type=int, default=4, help="permuter -j")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument(
        "--work-root",
        type=pathlib.Path,
        default=REPO / "vendor" / "decomp-permuter" / "work",
    )
    ap.add_argument(
        "--bank",
        action="store_true",
        help="on match, run bank.py --no-verify (still match.py first)",
    )
    args = ap.parse_args()

    seeds: list[dict] = []
    if args.from_nearmiss:
        seeds.extend(seeds_from_nearmiss(args.max_div))
    if args.seeds:
        for line in args.seeds.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            seeds.append(json.loads(line))
    if not seeds:
        ap.error("give --from-nearmiss and/or --seeds")

    resolved = []
    for s in seeds:
        r = resolve_seed(s)
        if r:
            resolved.append(r)
    if args.limit:
        resolved = resolved[: args.limit]

    print(f"{len(resolved)} seed(s) ready (from {len(seeds)} raw)")
    if args.dry_run:
        for module, name, addr, size, _src in resolved:
            print(f"  {module} {name} @ 0x{addr:08x} size=0x{size:x}")
        return

    if not PERM.is_file():
        print(
            "Clone decomp-permuter first:\n"
            "  git clone https://github.com/simonlindholm/decomp-permuter "
            f"{REPO / 'vendor' / 'decomp-permuter'}\n"
            "  python -m pip install toml pcpp pycparser",
            file=sys.stderr,
        )
        sys.exit(1)

    wins = 0
    for module, name, addr, size, src in resolved:
        print(f"\n=== {name} @ 0x{addr:08x} ===")
        work = args.work_root / name
        if work.exists():
            shutil.rmtree(work)
        try:
            out, nrel = IMP.setup_dir(module, name, addr, size, src, work)
        except Exception as e:
            print(f"  import failed: {e}")
            continue
        print(f"  work={out} relocs={nrel} budget={args.secs}s")
        t0 = time.time()
        best = run_permuter(out, args.secs, args.jobs)
        dt = time.time() - t0
        if best is None:
            print(f"  no output after {dt:.0f}s (see {out / 'permuter.log'})")
            continue
        # Copy to a stable path for match
        cand = out / "permuter_win.c"
        cand.write_text(best.read_text(encoding="utf-8", errors="ignore"))
        if not oracle_match(cand, name, module, addr, size):
            print(f"  permuter output failed match.py after {dt:.0f}s")
            continue
        print(f"  MATCH after {dt:.0f}s -> {cand}")
        wins += 1
        if args.bank:
            dest = REPO / "src" / module / f"{name}.c"
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy(cand, dest)
            cmd = [
                sys.executable,
                str(REPO / "tools" / "bank.py"),
                "--src",
                str(dest),
                "--kind",
                "ai",
                "--model",
                "permuter",
                "--reasoning",
                "none",
                "--harness",
                "decomp-permuter",
                "--session-scope",
                "focused",
                "--batch-size",
                "1",
                "--no-verify",
            ]
            print("  banking:", " ".join(cmd))
            subprocess.run(cmd, cwd=str(REPO))
    print(f"\ndone: {wins}/{len(resolved)} oracle matches")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Persistent best-near-miss database (SM64DS-shaped).

Keeps the **closest compiling C** per function — not every try (that stays in
config/match_attempts.jsonl as metadata + optional srcPath).

Store: nearmiss/db.jsonl  (one JSON object per function; rewritten as a tip DB)

Record (compatible with sm64ds-decomp nearmiss/db.jsonl):
  {
    "module": "arm9",
    "addr": "0x020009e0",
    "name": "func_020009e0",
    "size": 120,
    "lang": "c",
    "divergences": 4,
    "c_source": "… full C …",
    "source": "log_attempt|harvest|manual|…",
    "srcPath": "scratch/….c"   # optional breadcrumb
  }

Rules:
  - Key = (module, addr). One tip per function.
  - Ingest only when new divergences < stored divergences (or no prior tip).
  - Do not store MATCH (div=0) as a near-miss; prune when banked/matched in src/.
  - Full C lives HERE. Attempt log does not embed c_source.

Usage:
  python tools/nearmiss_db.py upsert --src path.c --func NAME --module arm9 \\
      --addr 0x… --size 0x… --divergences 4 --label wave-01
  python tools/nearmiss_db.py stats
  python tools/nearmiss_db.py list --max-div 12
  python tools/nearmiss_db.py prune-matched
  python tools/nearmiss_db.py harvest-from-attempts   # backfill from attempt srcPath
"""
from __future__ import annotations

import argparse
import json
import os
import pathlib
import re
import sys
from typing import Any, Optional

_TOOLS = pathlib.Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from match_provenance import configure, make_id, repo as get_repo  # noqa: E402

FUNC_RE = re.compile(
    r"^(\S+)\s+kind:function\((?:arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
)


def db_path(repo: Optional[pathlib.Path] = None) -> pathlib.Path:
    return (repo or get_repo()) / "nearmiss" / "db.jsonl"


def format_addr(addr: int | str) -> str:
    if isinstance(addr, str):
        return f"0x{int(addr, 0):08x}"
    return f"0x{int(addr):08x}"


def key_of(module: str, addr: int | str) -> tuple[str, str]:
    return (str(module), format_addr(addr))


def load_db(path: Optional[pathlib.Path] = None) -> dict[tuple[str, str], dict]:
    path = path or db_path()
    db: dict[tuple[str, str], dict] = {}
    if not path.is_file():
        return db
    for line_no, line in enumerate(path.read_text(encoding="utf-8", errors="ignore").splitlines(), 1):
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        try:
            r = json.loads(line)
        except json.JSONDecodeError as e:
            print(f"WARN: nearmiss/db.jsonl line {line_no}: {e}", file=sys.stderr)
            continue
        if not isinstance(r, dict) or "module" not in r or "addr" not in r:
            continue
        db[key_of(r["module"], r["addr"])] = r
    return db


def save_db(db: dict[tuple[str, str], dict], path: Optional[pathlib.Path] = None) -> None:
    """Atomic rewrite (tip DB, not append-only)."""
    path = path or db_path()
    path.parent.mkdir(parents=True, exist_ok=True)
    items = sorted(
        db.values(),
        key=lambda r: (
            r.get("divergences") if r.get("divergences") is not None else 10**9,
            str(r.get("module", "")),
            str(r.get("addr", "")),
        ),
    )
    tmp = path.with_name(path.name + ".tmp")
    tmp.write_text(
        "".join(json.dumps(r, ensure_ascii=False) + "\n" for r in items),
        encoding="utf-8",
    )
    os.replace(tmp, path)


def lookup_symbol_size(
    repo: pathlib.Path, module: str, addr: int, name: Optional[str] = None
) -> Optional[int]:
    """size from config/**/symbols.txt when known."""
    config = repo / "config"
    if not config.is_dir():
        return None
    want = format_addr(addr)
    for sym in config.rglob("symbols.txt"):
        rel = sym.parent.relative_to(config).as_posix()
        label = None
        if rel in ("arm9", "arm7"):
            label = rel
        else:
            m = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
            if m:
                label = m.group(1)
        if label != module:
            continue
        for line in sym.read_text(errors="ignore").splitlines():
            m = FUNC_RE.match(line)
            if not m:
                continue
            n, size_h, addr_h = m.group(1), m.group(2), m.group(3)
            if format_addr(int(addr_h, 16)) != want:
                continue
            if name and n != name:
                # same addr wins if name mismatch (rename)
                pass
            return int(size_h, 16)
    return None


def upsert(
    *,
    module: str,
    addr: int | str,
    name: str,
    divergences: int,
    c_source: str,
    size: Optional[int] = None,
    lang: Optional[str] = None,
    source: str = "manual",
    src_path: Optional[str] = None,
    path: Optional[pathlib.Path] = None,
    force: bool = False,
) -> tuple[str, Optional[dict]]:
    """Insert or replace tip if closer (or force).

    Returns (action, record) where action is:
      'added' | 'improved' | 'unchanged' | 'skipped'
    skipped = empty source / negative div / true match (div==0 unless force).
    """
    src = (c_source or "").strip()
    if not src:
        return "skipped", None
    try:
        div = int(divergences)
    except (TypeError, ValueError):
        return "skipped", None
    if div < 0:
        return "skipped", None
    if div == 0 and not force:
        # Real matches belong in src/, not the near-miss tip store.
        return "skipped", None

    k = key_of(module, addr)
    addr_s = k[1]
    path = path or db_path()
    db = load_db(path)
    cur = db.get(k)
    curdiv = (
        int(cur["divergences"])
        if cur is not None and cur.get("divergences") is not None
        else 10**9
    )
    if not force and cur is not None and div >= curdiv:
        return "unchanged", cur

    repo = get_repo()
    addr_i = int(addr_s, 0)
    sz = size
    if sz is None:
        sz = lookup_symbol_size(repo, module, addr_i, name)
    if lang is None:
        lang = "cpp" if src.lstrip().startswith("//cpp") else "c"

    rec: dict[str, Any] = {
        "module": module,
        "addr": addr_s,
        "name": name,
        "lang": lang,
        "divergences": div,
        "c_source": src if src.endswith("\n") else src + "\n",
        "source": source,
    }
    if sz is not None:
        rec["size"] = int(sz)
    if src_path:
        rec["srcPath"] = src_path
    # Preserve floor mark only when residual did not improve (force same div).
    if cur and cur.get("floor") and div >= curdiv:
        rec["floor"] = cur["floor"]

    db[k] = rec
    save_db(db, path)
    action = "added" if cur is None else "improved"
    return action, rec


def upsert_from_file(
    *,
    src_file: pathlib.Path,
    module: str,
    addr: int | str,
    name: str,
    divergences: int,
    size: Optional[int] = None,
    source: str = "manual",
    path: Optional[pathlib.Path] = None,
    force: bool = False,
) -> tuple[str, Optional[dict]]:
    repo = get_repo()
    p = src_file if src_file.is_absolute() else repo / src_file
    text = p.read_text(encoding="utf-8", errors="ignore")
    try:
        src_rel = p.resolve().relative_to(repo.resolve()).as_posix()
    except ValueError:
        src_rel = str(src_file)
    return upsert(
        module=module,
        addr=addr,
        name=name,
        divergences=divergences,
        c_source=text,
        size=size,
        source=source,
        src_path=src_rel,
        path=path,
        force=force,
    )


def remove(module: str, addr: int | str, path: Optional[pathlib.Path] = None) -> bool:
    path = path or db_path()
    db = load_db(path)
    k = key_of(module, addr)
    if k not in db:
        return False
    del db[k]
    save_db(db, path)
    return True


def prune_matched(repo: Optional[pathlib.Path] = None, path: Optional[pathlib.Path] = None) -> int:
    """Drop tips whose src/<name>.c exists without NONMATCHING."""
    repo = repo or get_repo()
    path = path or db_path(repo)
    db = load_db(path)
    src_root = repo / "src"
    dropped = 0
    for k, rec in list(db.items()):
        name = rec.get("name")
        if not name:
            continue
        found = None
        for ext in ("c", "cpp"):
            direct = src_root / f"{name}.{ext}"
            if direct.is_file():
                found = direct
                break
            hits = list(src_root.glob(f"**/{name}.{ext}"))
            if hits:
                found = hits[0]
                break
        if found is None:
            continue
        head = found.read_text(errors="ignore")[:400]
        if "NONMATCHING" in head:
            continue
        del db[k]
        dropped += 1
    if dropped:
        save_db(db, path)
    return dropped


def load_best_nearmiss(repo: Optional[pathlib.Path] = None) -> dict[str, dict]:
    """functionId → tip record (includes c_source). Primary atlas/details source."""
    repo = repo or get_repo()
    path = db_path(repo)
    out: dict[str, dict] = {}
    for (module, addr_s), rec in load_db(path).items():
        try:
            fid = make_id(module, int(addr_s, 0))
        except Exception:
            continue
        if rec.get("divergences") is None:
            continue
        out[fid] = rec
    return out


def harvest_from_attempts(
    repo: Optional[pathlib.Path] = None,
    *,
    path: Optional[pathlib.Path] = None,
) -> tuple[int, int, int]:
    """Backfill tips from attempt rows that have near_miss + srcPath still on disk.

    Returns (added, improved, skipped).
    """
    repo = repo or get_repo()
    attempts = repo / "config" / "match_attempts.jsonl"
    if not attempts.is_file():
        return 0, 0, 0
    # Best attempt per function first (lowest div with readable src)
    best: dict[str, dict] = {}
    for line in attempts.read_text(encoding="utf-8", errors="ignore").splitlines():
        if not line.strip():
            continue
        try:
            r = json.loads(line)
        except json.JSONDecodeError:
            continue
        if r.get("status") != "near_miss":
            continue
        div = r.get("divergences")
        sp = r.get("srcPath")
        if div is None or not sp:
            continue
        try:
            div_i = int(div)
        except (TypeError, ValueError):
            continue
        fid = r.get("functionId") or r.get("id")
        if not fid:
            continue
        p = repo / str(sp).lstrip("./")
        if not p.is_file():
            continue
        prev = best.get(fid)
        if prev is None or div_i < int(prev["divergences"]):
            best[fid] = {
                "divergences": div_i,
                "srcPath": str(sp),
                "name": r.get("name") or p.stem,
                "module": r.get("module") or "arm9",
                "addr": r.get("addr"),
            }
    added = improved = skipped = 0
    for fid, meta in best.items():
        addr = meta.get("addr")
        if addr is None:
            # parse from functionId arm9:0x…
            if ":" in fid:
                try:
                    addr = int(fid.split(":", 1)[1], 0)
                except ValueError:
                    skipped += 1
                    continue
            else:
                skipped += 1
                continue
        action, _ = upsert_from_file(
            src_file=pathlib.Path(meta["srcPath"]),
            module=str(meta["module"]),
            addr=addr,
            name=str(meta["name"]),
            divergences=int(meta["divergences"]),
            source="harvest-from-attempts",
            path=path or db_path(repo),
        )
        if action == "added":
            added += 1
        elif action == "improved":
            improved += 1
        else:
            skipped += 1
    return added, improved, skipped


def cmd_stats(_: argparse.Namespace) -> None:
    db = load_db()
    ds = [int(r["divergences"]) for r in db.values() if r.get("divergences") is not None]
    ds.sort()
    with_c = sum(1 for r in db.values() if (r.get("c_source") or "").strip())
    if not ds:
        print(f"DB: {len(db)} entries (none scored); with c_source={with_c}")
        return
    buckets = {
        "1-4": sum(1 <= d <= 4 for d in ds),
        "5-12": sum(5 <= d <= 12 for d in ds),
        "13-30": sum(13 <= d <= 30 for d in ds),
        ">30": sum(d > 30 for d in ds),
    }
    print(
        f"DB: {len(db)} tips, with c_source={with_c}, "
        f"median div={ds[len(ds)//2]}, min={ds[0]}"
    )
    for k, v in buckets.items():
        print(f"  {k:8} {v}")


def cmd_list(args: argparse.Namespace) -> None:
    rows = sorted(
        load_db().values(),
        key=lambda r: (
            r.get("divergences") if r.get("divergences") is not None else 10**9
        ),
    )
    for r in rows:
        div = r.get("divergences")
        if args.max_div is not None and (div is None or int(div) > args.max_div):
            continue
        has_c = "c" if (r.get("c_source") or "").strip() else "-"
        print(
            f"  div={div:<4} {r.get('module','?'):6} "
            f"{str(r.get('name',''))[:46]:46} {has_c} {r.get('source','')}"
        )


def cmd_upsert(args: argparse.Namespace) -> None:
    if args.divergences is None:
        print("ERROR: --divergences required", file=sys.stderr)
        sys.exit(2)
    name = args.func or args.src.stem
    module = args.module or "arm9"
    addr = args.addr
    if addr is None:
        m = re.search(r"([0-9a-fA-F]{6,8})$", name)
        if m:
            addr = int(m.group(1), 16)
    if addr is None:
        print("ERROR: need --addr or address in --func name", file=sys.stderr)
        sys.exit(2)
    size = int(args.size, 0) if args.size else None
    action, rec = upsert_from_file(
        src_file=args.src,
        module=module,
        addr=addr,
        name=name,
        divergences=args.divergences,
        size=size,
        source=args.label or "manual",
        force=args.force,
    )
    if rec is None:
        print(f"nearmiss: {action} (no write)")
        return
    print(
        f"nearmiss: {action} {rec['module']} {rec['addr']} "
        f"div={rec['divergences']} name={rec['name']} "
        f"c_bytes={len(rec.get('c_source') or '')}"
    )


def cmd_prune(_: argparse.Namespace) -> None:
    n = prune_matched()
    print(f"pruned {n} matched tip(s); DB now {len(load_db())} entries")


def cmd_harvest(_: argparse.Namespace) -> None:
    a, i, s = harvest_from_attempts()
    print(f"harvest-from-attempts: +{a} new, {i} improved, {s} skipped; DB={len(load_db())}")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repo", type=pathlib.Path, default=None)
    sub = ap.add_subparsers(dest="cmd", required=True)

    p_stats = sub.add_parser("stats", help="Summarize tip DB")
    p_stats.set_defaults(func=cmd_stats)

    p_list = sub.add_parser("list", help="List tips")
    p_list.add_argument("--max-div", type=int, default=None)
    p_list.set_defaults(func=cmd_list)

    p_up = sub.add_parser("upsert", help="Store C tip if better than current")
    p_up.add_argument("--src", type=pathlib.Path, required=True)
    p_up.add_argument("--func", default=None)
    p_up.add_argument("--module", default=None)
    p_up.add_argument("--addr", type=lambda s: int(s, 0), default=None)
    p_up.add_argument("--size", default=None)
    p_up.add_argument("--divergences", type=int, required=True)
    p_up.add_argument("--label", default="manual", help="source tag")
    p_up.add_argument(
        "--force",
        action="store_true",
        help="Replace even if not closer (or allow div=0)",
    )
    p_up.set_defaults(func=cmd_upsert)

    p_pr = sub.add_parser("prune-matched", help="Drop tips with real matches in src/")
    p_pr.set_defaults(func=cmd_prune)

    p_h = sub.add_parser(
        "harvest-from-attempts",
        help="Backfill tips from match_attempts srcPath files still on disk",
    )
    p_h.set_defaults(func=cmd_harvest)

    args = ap.parse_args()
    configure(args.repo)
    args.func(args)


if __name__ == "__main__":
    main()

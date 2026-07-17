#!/usr/bin/env python3
"""CI-safe Chaos Viewer atlas generator.

Rebuilds chaos-db.json from COMMITTED data only (no ROM required):
  universe     config/**/symbols.txt  (name, addr, size per module)
  matched      src/<name>.c[pp] exists and is not marked // NONMATCHING
  provenance   config/match_provenance.jsonl → matchProvenance (how) on matched
  author       git first-adder of src/ (sm64ds-style who) — never agent names
  near-miss    nearmiss/db.jsonl (tip C + div; sm64ds-shaped). Fallback: best
               near_miss in config/match_attempts.jsonl, then NONMATCHING div=N.
  project      tools/chaosviewer.config.json

Usage:
  python tools/chaos_db_ci.py [--out chaos-db.json] [--repo PATH]
"""
from __future__ import annotations

import argparse
import collections
import json
import pathlib
import re
import sys
import time

_TOOLS_DIR = pathlib.Path(__file__).resolve().parent
if str(_TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(_TOOLS_DIR))

from match_provenance import (  # noqa: E402
    attribution_overrides,
    configure,
    first_matchers,
    is_agent_credit,
    load_ledger,
    make_id,
)
from nearmiss_db import load_best_nearmiss as load_nearmiss_tip_db  # noqa: E402

FUNC_RE = re.compile(
    r"^(\S+)\s+kind:function\((?:arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
)

# // NONMATCHING: … (div=3)  or  // NONMATCHING div=3
DIV_IN_HEAD_RE = re.compile(r"div\s*=\s*(\d+)", re.IGNORECASE)


def module_label(config: pathlib.Path, sym_path: pathlib.Path) -> str | None:
    """config/arm9/symbols.txt -> arm9; config/arm7/symbols.txt -> arm7;
    config/arm9/overlays/ovNNN -> ovNNN. Skip itcm/dtcm (autoload noise)."""
    rel = sym_path.parent.relative_to(config).as_posix()
    if rel in ("arm9", "arm7"):
        return rel
    m = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
    return m.group(1) if m else None


def load_best_nearmiss_from_attempts(repo: pathlib.Path) -> dict[str, dict]:
    """Fallback: best near_miss per functionId from config/match_attempts.jsonl.

    Metadata only (no c_source). Prefer load_best_nearmiss() which reads
    nearmiss/db.jsonl first.
    """
    path = repo / "config" / "match_attempts.jsonl"
    if not path.is_file():
        return {}
    best: dict[str, dict] = {}
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        if not line.strip():
            continue
        try:
            r = json.loads(line)
        except json.JSONDecodeError:
            continue
        if r.get("status") != "near_miss":
            continue
        div = r.get("divergences")
        if div is None:
            continue
        try:
            div_i = int(div)
        except (TypeError, ValueError):
            continue
        fid = r.get("functionId") or r.get("id")
        if not fid:
            mod = r.get("module")
            addr = r.get("addr")
            if mod is None or addr is None:
                continue
            try:
                fid = make_id(str(mod), int(addr, 0) if isinstance(addr, str) else int(addr))
            except Exception:
                continue
        prev = best.get(fid)
        if prev is None or div_i < int(prev["divergences"]):
            best[fid] = {
                "divergences": div_i,
                "srcPath": r.get("srcPath"),
                "name": r.get("name"),
                "module": r.get("module"),
                "addr": r.get("addr"),
            }
    return best


def load_best_nearmiss(repo: pathlib.Path) -> dict[str, dict]:
    """Primary: nearmiss/db.jsonl tips (with c_source). Fill gaps from attempts."""
    tips = load_nearmiss_tip_db(repo)
    attempts = load_best_nearmiss_from_attempts(repo)
    # Tips overwrite attempts on the same functionId (include c_source).
    out = dict(attempts)
    out.update(tips)
    return out




def parse_div_from_src_head(text: str) -> int | None:
    """Parse div=N from the first lines of a NONMATCHING / scratch file."""
    head = "\n".join(text.splitlines()[:12])
    m = DIV_IN_HEAD_RE.search(head)
    if not m:
        return None
    return int(m.group(1))


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="chaos-db.json")
    ap.add_argument("--contrib-out", default=None)
    ap.add_argument(
        "--repo",
        type=pathlib.Path,
        default=None,
        help="Decomp root (or DECOMP_ROOT / MATCH_REPO / cwd discovery)",
    )
    ap.add_argument(
        "--warn-missing-provenance",
        action="store_true",
        default=True,
        help="Warn when matched funcs lack matchProvenance (experimental; default on)",
    )
    ap.add_argument(
        "--no-warn-missing-provenance",
        action="store_false",
        dest="warn_missing_provenance",
    )
    args = ap.parse_args()

    repo = configure(args.repo)
    config = repo / "config"
    src = repo / "src"

    try:
        ledger = load_ledger()
    except Exception as e:
        print(f"ERROR: provenance ledger: {e}", file=sys.stderr)
        sys.exit(1)

    # SM64DS: nearmiss/db.jsonl → div (+ tip C for details). Fallback: attempts.
    nearmiss = load_best_nearmiss(repo)
    nm_from_file = (repo / "nearmiss" / "db.jsonl").is_file()
    # SM64DS: git first-adder → author. Ledger author only if human (not "grok").
    git_authors = first_matchers(repo)
    overrides = attribution_overrides(repo)


    functions = []
    total_b = matched_b = matched_n = 0
    missing_prov: list[str] = []
    with_div = 0
    for sym in sorted(config.rglob("symbols.txt")):
        label = module_label(config, sym)
        if label is None:
            continue
        for line in sym.read_text(errors="ignore").splitlines():
            m = FUNC_RE.match(line)
            if not m:
                continue
            name, size, addr = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
            src_path = None
            for ext in ("c", "cpp"):
                direct = src / f"{name}.{ext}"
                if direct.is_file():
                    src_path = f"src/{name}.{ext}"
                    break
                hits = list(src.glob(f"**/{name}.{ext}"))
                if hits:
                    src_path = hits[0].relative_to(repo).as_posix()
                    break
            matched = False
            head = ""
            if src_path:
                head = (repo / src_path).read_text(errors="ignore")[:400]
                matched = "NONMATCHING" not in head
            total_b += size
            fid = make_id(label, addr)
            rec = {
                "id": fid,
                "module": label,
                "name": name,
                "addr": addr,
                "size": size,
                "matched": matched,
            }
            if src_path:
                rec["srcPath"] = src_path
            if matched:
                matched_b += size
                matched_n += 1
                row = ledger.get(fid)
                if row and row.get("matchProvenance"):
                    rec["matchProvenance"] = row["matchProvenance"]
                else:
                    missing_prov.append(fid)
                # Who = git first-adder (sm64ds), not agent/harness names from ledger.
                who = None
                if src_path:
                    who = overrides.get(src_path) or git_authors.get(src_path)
                if not who and row and row.get("author") and not is_agent_credit(
                    str(row["author"])
                ):
                    who = str(row["author"]).strip()
                if who and not is_agent_credit(who):
                    rec["author"] = who
            else:
                # Near-miss badge for the viewer (same as sm64ds chaos_db_ci).
                nm = nearmiss.get(fid)
                div: int | None = None
                if nm is not None:
                    div = int(nm["divergences"])
                    # Prefer path from the best attempt when we have no src yet.
                    if not src_path and nm.get("srcPath"):
                        sp = str(nm["srcPath"]).lstrip("./")
                        if (repo / sp).is_file():
                            rec["srcPath"] = sp
                            src_path = sp
                            head = (repo / sp).read_text(errors="ignore")[:400]
                if div is None and head:
                    div = parse_div_from_src_head(head)
                if div is not None:
                    rec["div"] = div
                    with_div += 1
            functions.append(rec)

    # Synthetic attempt-history gallery (UI fixture — not a ROM function).
    try:
        from attempt_history_gallery import gallery_function_record  # noqa: E402

        gallery_fn = gallery_function_record()
        if not any(f.get("id") == gallery_fn["id"] for f in functions):
            functions.append(gallery_fn)
            total_b += int(gallery_fn.get("size") or 0)
            if gallery_fn.get("div") is not None:
                with_div += 1
    except Exception as e:
        print(f"WARN: attempt history gallery inject skipped: {e}", file=sys.stderr)

    project = None
    pc = repo / "tools" / "chaosviewer.config.json"
    if pc.is_file():
        project = json.loads(pc.read_text(encoding="utf-8"))

    db = {
        "generatedAt": time.strftime("%Y-%m-%d %H:%M", time.gmtime()) + " UTC",
        "project": project,
        "stats": {
            "totalFunctions": len(functions),
            "matchedFunctions": matched_n,
            "totalBytes": total_b,
            "matchedBytes": matched_b,
            "moduleCount": len({f["module"] for f in functions}),
            "withProvenance": sum(1 for f in functions if f.get("matchProvenance")),
            "withNearMissDiv": with_div,
        },
        "functions": functions,
    }
    out = pathlib.Path(args.out)
    if not out.is_absolute():
        out = repo / out
    out.write_text(json.dumps(db), encoding="utf-8")
    print(
        f"wrote {out} ({out.stat().st_size // 1024} KB): "
        f"{matched_n}/{len(functions)} funcs, {matched_b}/{total_b} bytes, "
        f"{db['stats']['moduleCount']} modules, "
        f"{db['stats']['withProvenance']} with matchProvenance, "
        f"{with_div} with near-miss div "
        f"(from {len(nearmiss)} tips"
        f"{'; nearmiss/db.jsonl' if nm_from_file else '; attempts fallback'})"
    )


    if args.warn_missing_provenance and missing_prov:
        print(
            f"WARN (experimental): {len(missing_prov)} matched function(s) lack "
            f"matchProvenance in config/match_provenance.jsonl. "
            f"Stamp with: python tools/bank.py --src … --kind human|ai …",
            file=sys.stderr,
        )
        show = missing_prov[:8]
        for fid in show:
            print(f"  - {fid}", file=sys.stderr)
        if len(missing_prov) > 8:
            print(f"  … and {len(missing_prov) - 8} more", file=sys.stderr)

    tally = collections.Counter(f.get("author") for f in functions if f.get("author"))
    contrib = {
        "generatedAt": db["generatedAt"],
        "totalMatched": matched_n,
        "contributors": [{"login": who, "matched": n} for who, n in tally.most_common()],
    }
    cpath = (
        pathlib.Path(args.contrib_out)
        if args.contrib_out
        else out.with_name("contributions.json")
    )
    if not cpath.is_absolute():
        cpath = repo / cpath
    cpath.write_text(json.dumps(contrib, indent=1), encoding="utf-8")
    print(f"wrote {cpath}: {len(tally)} contributors")


if __name__ == "__main__":
    main()

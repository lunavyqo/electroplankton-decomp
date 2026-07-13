#!/usr/bin/env python3
"""CI-safe Chaos Viewer atlas generator.

Rebuilds chaos-db.json from COMMITTED data only (no ROM required):
  universe   config/**/symbols.txt  (name, addr, size per module)
  matched    src/<name>.c[pp] exists and is not marked // NONMATCHING
  provenance config/match_provenance.jsonl → matchProvenance on matched funcs
  project    tools/chaosviewer.config.json

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

from match_provenance import configure, load_ledger, make_id  # noqa: E402

FUNC_RE = re.compile(
    r"^(\S+)\s+kind:function\((?:arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
)


def module_label(config: pathlib.Path, sym_path: pathlib.Path) -> str | None:
    """config/arm9/symbols.txt -> arm9; config/arm7/symbols.txt -> arm7;
    config/arm9/overlays/ovNNN -> ovNNN. Skip itcm/dtcm (autoload noise)."""
    rel = sym_path.parent.relative_to(config).as_posix()
    if rel in ("arm9", "arm7"):
        return rel
    m = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
    return m.group(1) if m else None


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

    functions = []
    total_b = matched_b = matched_n = 0
    missing_prov: list[str] = []
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
            if src_path:
                head = (repo / src_path).read_text(errors="ignore")[:200]
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
                # Do not invent defaults for old matches — only copy ledger rows.
                row = ledger.get(fid)
                if row and row.get("matchProvenance"):
                    rec["matchProvenance"] = row["matchProvenance"]
                    # Classic who-credit (separate from how-provenance).
                    if row.get("author"):
                        rec["author"] = row["author"]
                else:
                    missing_prov.append(fid)
            functions.append(rec)

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
        f"{db['stats']['withProvenance']} with matchProvenance"
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

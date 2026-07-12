#!/usr/bin/env python3
"""CI-safe Chaos Viewer atlas generator.

Rebuilds chaos-db.json from COMMITTED data only (no ROM required):
  universe   config/**/symbols.txt  (name, addr, size per module)
  matched    src/<name>.c[pp] exists and is not marked // NONMATCHING
  project    tools/chaosviewer.config.json

Usage:
  python tools/chaos_db_ci.py [--out chaos-db.json]
"""
from __future__ import annotations

import argparse
import collections
import json
import pathlib
import re
import time

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"
SRC = REPO / "src"

FUNC_RE = re.compile(
    r"^(\S+)\s+kind:function\((?:arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
)


def module_label(sym_path: pathlib.Path) -> str | None:
    """config/arm9/symbols.txt -> arm9; config/arm7/symbols.txt -> arm7;
    config/arm9/overlays/ovNNN -> ovNNN. Skip itcm/dtcm (autoload noise)."""
    rel = sym_path.parent.relative_to(CONFIG).as_posix()
    if rel in ("arm9", "arm7"):
        return rel
    m = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
    return m.group(1) if m else None


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="chaos-db.json")
    ap.add_argument("--contrib-out", default=None)
    args = ap.parse_args()

    functions = []
    total_b = matched_b = matched_n = 0
    for sym in sorted(CONFIG.rglob("symbols.txt")):
        label = module_label(sym)
        if label is None:
            continue
        for line in sym.read_text(errors="ignore").splitlines():
            m = FUNC_RE.match(line)
            if not m:
                continue
            name, size, addr = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
            src_path = None
            for ext in ("c", "cpp"):
                f = SRC / f"{name}.{ext}"
                if f.is_file():
                    src_path = f"src/{name}.{ext}"
                    break
            matched = False
            if src_path:
                head = (SRC / src_path.split("/", 1)[1]).read_text(errors="ignore")[:200]
                matched = "NONMATCHING" not in head
            total_b += size
            rec = {
                "id": f"{label}:0x{addr:08x}",
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
            functions.append(rec)

    project = None
    pc = REPO / "tools" / "chaosviewer.config.json"
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
        },
        "functions": functions,
    }
    out = pathlib.Path(args.out)
    out.write_text(json.dumps(db), encoding="utf-8")
    print(
        f"wrote {out} ({out.stat().st_size // 1024} KB): "
        f"{matched_n}/{len(functions)} funcs, {matched_b}/{total_b} bytes, "
        f"{db['stats']['moduleCount']} modules"
    )

    tally = collections.Counter(f.get("author") for f in functions if f.get("author"))
    contrib = {
        "generatedAt": db["generatedAt"],
        "totalMatched": matched_n,
        "contributors": [{"login": who, "matched": n} for who, n in tally.most_common()],
    }
    cpath = pathlib.Path(args.contrib_out) if args.contrib_out else out.with_name("contributions.json")
    cpath.write_text(json.dumps(contrib, indent=1), encoding="utf-8")
    print(f"wrote {cpath}: {len(tally)} contributors")


if __name__ == "__main__":
    main()

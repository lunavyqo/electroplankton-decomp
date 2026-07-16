#!/usr/bin/env python3
"""Build Chaos Viewer details/<module>.json from local binaries + symbols.

Produces annotated disassembly TEXT only (no binary blobs). Requires a local
unpack (arm9/arm9.bin etc.). Output is safe to publish on chaos-data.

Also attaches near-miss draft C when available (same role as sm64ds generate-chaos-db
draft fields): best near_miss from config/match_attempts.jsonl → draft + draftDiv.

Usage:
  python tools/generate_details.py --out-dir /tmp/chaos-details
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import sys

from capstone import CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB, Cs

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"
_TOOLS_DIR = pathlib.Path(__file__).resolve().parent
if str(_TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(_TOOLS_DIR))

from chaos_db_ci import load_best_nearmiss  # noqa: E402
from match_provenance import make_id  # noqa: E402

FUNC_RE = re.compile(
    r"^(\S+)\s+kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\).*?addr:0x([0-9a-fA-F]+)"
)

MODULES = {
    "arm9": {"bin": REPO / "arm9" / "arm9.bin", "base": 0x02000000, "sym": CONFIG / "arm9" / "symbols.txt"},
    "arm7": {"bin": REPO / "arm7" / "arm7.bin", "base": 0x02380000, "sym": CONFIG / "arm7" / "symbols.txt"},
}


def disasm_lines(data: bytes, addr: int, thumb: bool) -> list[str]:
    mode = CS_MODE_THUMB if thumb else CS_MODE_ARM
    md = Cs(CS_ARCH_ARM, mode)
    out = []
    for insn in md.disasm(data, addr):
        out.append(f"  {insn.address:08x}:  {insn.mnemonic:8s} {insn.op_str}")
    return out


def module_label(sym_path: pathlib.Path) -> str | None:
    rel = sym_path.parent.relative_to(CONFIG).as_posix()
    if rel in ("arm9", "arm7"):
        return rel
    m = re.fullmatch(r"arm9/overlays/(ov\d+)", rel)
    return m.group(1) if m else None


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out-dir", required=True)
    ap.add_argument("--max-size", type=lambda s: int(s, 0), default=0x800,
                    help="Skip functions larger than this (default 0x800) to keep JSON lean")
    args = ap.parse_args()
    out_dir = pathlib.Path(args.out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    # Best near-miss drafts (functionId → divergences + srcPath)
    nearmiss = load_best_nearmiss(REPO)

    # group functions by module label
    by_mod: dict[str, list[tuple[str, str, int, int]]] = {}
    for sym in sorted(CONFIG.rglob("symbols.txt")):
        label = module_label(sym)
        if label is None:
            continue
        for line in sym.read_text(errors="ignore").splitlines():
            m = FUNC_RE.match(line)
            if not m:
                continue
            name, mode, size_h, addr_h = m.groups()
            by_mod.setdefault(label, []).append((name, mode, int(addr_h, 16), int(size_h, 16)))

    for label, funcs in by_mod.items():
        # resolve binary: arm9 / arm7 only for now
        if label not in MODULES:
            print(f"skip {label}: no binary mapping")
            continue
        info = MODULES[label]
        if not info["bin"].is_file():
            print(f"skip {label}: missing {info['bin']}", file=sys.stderr)
            continue
        blob = info["bin"].read_bytes()
        base = info["base"]
        # build addr->name for callee resolution
        addr_to_name = {a: n for n, _m, a, _s in funcs}
        details = {}
        skipped = 0
        for name, mode, addr, size in funcs:
            if size > args.max_size:
                skipped += 1
                continue
            off = addr - base
            if off < 0 or off + size > len(blob):
                continue
            chunk = blob[off : off + size]
            thumb = mode == "thumb"
            lines = disasm_lines(chunk, addr, thumb)
            # crude callees: BL targets in ARM mode
            callees = []
            if not thumb:
                md = Cs(CS_ARCH_ARM, CS_MODE_ARM)
                md.detail = True
                for insn in md.disasm(chunk, addr):
                    if insn.mnemonic == "bl" and insn.operands:
                        # op_str like #0x2001234
                        t = insn.op_str.strip()
                        if t.startswith("#"):
                            try:
                                taddr = int(t[1:], 0)
                                cname = addr_to_name.get(taddr)
                                if cname and cname not in callees:
                                    callees.append(cname)
                            except ValueError:
                                pass
            rec: dict = {
                "callees": callees[:32],
                "calledBy": [],  # filled in second pass
                "disasm": lines,
            }
            # Attach near-miss draft C when we have a best attempt with srcPath.
            fid = make_id(label, addr)
            nm = nearmiss.get(fid)
            if nm and nm.get("srcPath"):
                sp = str(nm["srcPath"]).lstrip("./")
                draft_path = REPO / sp
                if draft_path.is_file():
                    text = draft_path.read_text(errors="ignore").strip()
                    if text:
                        rec["draft"] = text
                        rec["draftDiv"] = int(nm["divergences"])
            details[name] = rec
        # calledBy reverse edges
        for name, rec in details.items():
            for c in rec["callees"]:
                if c in details:
                    if name not in details[c]["calledBy"]:
                        details[c]["calledBy"].append(name)
        for rec in details.values():
            rec["calledBy"] = rec["calledBy"][:32]

        out = out_dir / f"{label}.json"
        out.write_text(json.dumps(details), encoding="utf-8")
        n_draft = sum(1 for r in details.values() if r.get("draft"))
        print(
            f"wrote {out} ({len(details)} funcs, drafts={n_draft}, "
            f"skipped_large={skipped}, {out.stat().st_size // 1024} KB)"
        )


if __name__ == "__main__":
    main()

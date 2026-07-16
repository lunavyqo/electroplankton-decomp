"""Module registry: main ARM9 (+ ITCM/DTCM), and overlays if present.

Each module has its own binary, RAM base address, symbols, and relocs. Overlays
can share a base address (they occupy the same memory slot at different times),
so anything that records matches must key by (module, addr), never addr alone.

Electroplankton layout (dsd extract at repo root, not extracted/):
  arm9/arm9.bin   base 0x02000000
  arm9/itcm.bin   base from config/arm9/itcm/symbols.txt
  arm9/dtcm.bin   base from config/arm9/dtcm/symbols.txt
  overlays/       optional (EP has none today)

Adapted from sm64ds-decomp tools/modules.py.
"""
from __future__ import annotations

import pathlib
import re

REPO = pathlib.Path(__file__).resolve().parent.parent
CFG = REPO / "config" / "arm9"
ARM9_BASE = 0x02000000


def _lowest_symbol_addr(symbols: pathlib.Path) -> int | None:
    """Lowest addr:0x… in a symbols.txt (overlay / ITCM / DTCM base)."""
    if not symbols.is_file():
        return None
    lo = None
    for line in symbols.read_text(errors="ignore").splitlines():
        m = re.search(r"addr:0x([0-9a-fA-F]+)", line)
        if m:
            a = int(m.group(1), 16)
            lo = a if lo is None else min(lo, a)
    return lo


def _bin_candidates(*paths: pathlib.Path) -> pathlib.Path | None:
    for p in paths:
        if p.is_file():
            return p
    return None


def modules():
    """All modules as dicts: {name, syms, relocs, bin, base}.

    Internal name for main ARM9 is ``main`` (sm64ds convention); public labels
    use ``arm9`` via callers (``"arm9" if mod["name"] == "main" else mod["name"]``).
    """
    mods = []

    arm9_bin = _bin_candidates(
        REPO / "arm9" / "arm9.bin",
        REPO / "extracted" / "arm9_dec.bin",
        REPO / "extracted" / "arm9.bin",
    )
    if arm9_bin is not None and (CFG / "symbols.txt").is_file():
        mods.append({
            "name": "main",
            "syms": CFG / "symbols.txt",
            "relocs": CFG / "relocs.txt",
            "bin": arm9_bin,
            "base": ARM9_BASE,
        })

    # ITCM / DTCM live next to arm9 binaries in the dsd layout
    for kind in ("itcm", "dtcm"):
        syms = CFG / kind / "symbols.txt"
        rels = CFG / kind / "relocs.txt"
        b = _bin_candidates(
            REPO / "arm9" / f"{kind}.bin",
            REPO / "extracted" / f"{kind}.bin",
        )
        base = _lowest_symbol_addr(syms)
        if b is not None and syms.is_file() and base is not None:
            mods.append({
                "name": kind,
                "syms": syms,
                "relocs": rels,
                "bin": b,
                "base": base,
            })

    # Overlays (none for EP today; keep sm64ds path shapes for future)
    ov_cfg = CFG / "overlays"
    if ov_cfg.is_dir():
        for d in sorted(ov_cfg.glob("ov*")):
            if not d.is_dir():
                continue
            syms = d / "symbols.txt"
            n = int(d.name[2:])
            b = _bin_candidates(
                REPO / "overlays" / f"overlay_{n:04d}.bin",
                REPO / "extracted" / "overlays" / f"overlay_{n:04d}.bin",
                REPO / "arm9_overlays" / f"overlay_{n:04d}.bin",
            )
            if b is None or not syms.is_file():
                continue
            base = _lowest_symbol_addr(syms)
            if base is None:
                continue
            mods.append({
                "name": d.name,
                "syms": syms,
                "relocs": d / "relocs.txt",
                "bin": b,
                "base": base,
            })

    return mods


def read_bytes(mod, addr, size):
    """Bytes of [addr, addr+size) from a module's binary."""
    off = addr - mod["base"]
    data = mod["bin"].read_bytes()
    if off < 0 or off + size > len(data):
        raise ValueError(
            f"range out of bounds module={mod['name']} addr=0x{addr:x} "
            f"size=0x{size:x} bin_len={len(data)} base=0x{mod['base']:x}"
        )
    return data[off : off + size]


def by_label(label: str):
    """Lookup a module by public label (arm9, itcm, ov002, …)."""
    for mod in modules():
        public = "arm9" if mod["name"] == "main" else mod["name"]
        if public == label or mod["name"] == label:
            return mod
    return None

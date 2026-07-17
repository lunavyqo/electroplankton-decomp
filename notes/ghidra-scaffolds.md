# Local Ghidra scaffolds (never commit)

Decompiler C is a **local comprehension aid**. It is not a match, not source of
truth, and must never land in `src/` or be banked as-is. The oracle is still
`python tools/match.py` against your unpacked ROM.

Adapted from the sm64ds-decomp Ghidra dump flow (`tools/ghidra/DecompDump.java`).

## What you get

| Path | Role |
|------|------|
| `ghidra_projects/` | Ghidra project (gitignored) |
| `ghidra_targets.txt` | Address list from committed symbols (gitignored) |
| `ghidra_out/0x….c` | Per-function decompiler dumps (gitignored) |

## One-time project setup

1. Install [Ghidra](https://ghidra-sre.org/) and put `analyzeHeadless` on `PATH`,
   or set `GHIDRA_HOME`.
2. Import **your** unpacked ARM9 image:
   - Binary: `arm9/arm9.bin`
   - Language: `ARM:LE:32:v5t`
   - Base address: `0x02000000`
3. Save the project under `ghidra_projects/ep-arm9` (gitignored).

## Dump scaffolds

```bash
# Target list from committed config (safe to re-run; output is local-only)
python tools/ghidra_targets.py

# Headless decompile → ghidra_out/
analyzeHeadless \
  ghidra_projects ep-arm9 \
  -process arm9.bin \
  -scriptPath tools/ghidra \
  -postScript DecompDump.java ghidra_targets.txt ghidra_out
```

If your Ghidra project used a different program name than `arm9.bin`, pass that
name to `-process`.

## How to use the dumps

- Read `ghidra_out/0x0200….c` for control flow / callees / rough types.
- **Rewrite** into mwccarm-friendly C (see `notes/matching-style.md`,
  `notes/mwccarm-codegen.md`, `notes/pret-idioms.md`).
- Verify with `tools/match.py` / `tools/fdiff.py`.
- Near-miss tips go to `nearmiss/db.jsonl`, not `src/`.

## Discord paste (optional)

When onboarding someone without a full setup, point them at the public
`chaos-data` disasm first; Ghidra scaffolds are for people who already have a
local unpack and want decompiler C on disk.

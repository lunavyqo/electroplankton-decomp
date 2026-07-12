# Contributing

Thanks for helping. This is a **matching** decompilation: landed functions are
hand-written C that compile to the same bytes as the retail ARM binaries.

## What you need

You bring your own copy of the game. Nothing copyrighted lives in this repo.

1. **Your own Electroplankton cartridge dump (`.nds`).** Verify it matches the
   build documented in the README (game code `ATIE` unless we expand versions).
   The ROM and anything extracted from it are git-ignored and must never be
   committed.
2. **A local unpack** of that ROM (dsd, ndstool, or project `tools/unpack.py`
   once it exists). Binaries go next to the existing `arm9/`, `arm7/`, `files/`
   layout or under `extracted/` — both patterns are ignored for binary/asset
   content.
3. **Python 3** and, when tooling is ready:
   ```
   pip install ndspy capstone pyelftools
   ```
4. **mwccarm** (when matching begins): proprietary CodeWarrior ARM, not
   redistributable here. Place it under `tools/mwccarm/` (gitignored).

## Ground rules

- **Never commit copyrighted material.** No ROM, no `.bin` extracts, no
  `files/` NitroFS tree, no banner art, no SDAT/WAV, no mwccarm. The
  `.gitignore` enforces this — do not override it with `git add -f` unless you
  are 100% sure the file is original work.
- **Import knowledge, write code.** Symbol names and field offsets from
  community RE are fine; all C in `src/` must be written from scratch against
  your own dump.
- **Match to the byte.** A function counts only when compiled output equals the
  ROM for that function (relocation-aware compare once tools exist).
- **Claim before grinding.** Add a row to [CLAIMS.md](CLAIMS.md) for the
  address range or subsystem you are working on.

## First-time local setup

```bash
git clone <this-repo-url>
cd electroplankton-decomp   # or your local folder name

# Put YOUR dump somewhere local, e.g.:
#   cp /path/to/your/Electroplankton.nds ./Electroplankton.nds
# It is gitignored. Never push it.

# Unpack with dsd / project tools once available, then start matching.
```

Before every commit, run:

```bash
git status
```

If you see `Electroplankton.nds`, anything under `files/`, `*.bin`, `*.sdat`,
`*.wav`, or banner PNGs, **do not commit**. Fix ignores first.

## Submitting a PR

- Fork, branch, PR against `main`.
- One function (or a small related cluster) per PR is ideal.
- Note the compiler version/flags and the function address in the PR body.

## Questions

Open a GitHub issue, or coordinate claims in CLAIMS.md so two people do not
grind the same function.

# Legal notes (local contributors)

## What stays off git forever

| Material | Examples | Why |
|----------|----------|-----|
| ROM image | `*.nds`, `baserom*` | Entire copyrighted game |
| Code binaries | `arm9.bin`, `arm7.bin`, ITCM/DTCM, overlays | Compiled game code |
| NitroFS | everything under `files/` | Graphics, sound banks, samples |
| Banner / logo | `banner/*.png`, `header_logo.png` | Nintendo banner art / logo data |
| Audio | `*.wav`, `*.sdat`, wave bins | Copyrighted audio |
| Proprietary compiler | `tools/mwccarm/`, `license.dat` | Not redistributable |

## What is OK to commit

- Hand-written C/C++/asm you authored that matches after compile
- Original Python/shell tooling
- Symbol name lists and docs you write
- Structural rebuild config you maintain (addresses, module layout) — **not** the
  bytes those addresses point at
- This documentation

## Operational checklist before every push

```bash
git status
git check-ignore -v Electroplankton.nds files/arm9/arm9.bin 2>/dev/null || true
# Confirm secrets/assets are still ignored:
git ls-files | rg -i '\.(nds|bin|sdat|wav|ntxf|ntxp)$|files/' && echo 'STOP: bad track' || echo 'ok'
```

If anything from the table above appears in `git ls-files`, remove it from the
index immediately (`git rm --cached …`) and fix `.gitignore` before pushing.

## Disclaimer

This is not legal advice. Decompilation for interoperability/research is treated
differently across jurisdictions. Redistributing game assets is always the line
we do not cross in this repository.

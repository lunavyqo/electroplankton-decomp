# electroplankton-decomp

A from-scratch decompilation (decomp) of **Electroplankton** (Nintendo DS) into
matching C.

This project is structured like other modern DS matching decomps (for example
[sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp)): original tooling and
hand-written source live in git; the ROM and every extracted asset stay on your
machine only.

New here? Start with **[CONTRIBUTING.md](CONTRIBUTING.md)** and coordinate work in
**[CLAIMS.md](CLAIMS.md)**.

## Progress

<!-- progress:start -->
```
Functions  █████████░░░░░░░░░░░░░░░░░░░░░  31.5%   614 / 1,950
Code size  ████░░░░░░░░░░░░░░░░░░░░░░░░░░  12.9%   46,454 / 359,462 bytes
```
<!-- progress:end -->

Refresh the block (committed symbols + `src/`, or a local `chaos-db.json`):

```bash
python tools/progress.py --write-readme
```

### Progress map

Interactive atlas is **Chaos Viewer** (not a static treemap). Data is regenerated
on the `chaos-data` branch by GitHub Actions
(`.github/workflows/update-chaos-data.yml` — same idea as sm64ds-decomp: committed
`src/` + `nearmiss/db.jsonl` → `chaos-db.json`, no ROM on the runner).

Live atlas:

**https://tangosdev.github.io/chaos-viewer/?data=https://raw.githubusercontent.com/lunavyqo/electroplankton-decomp/chaos-data/chaos-db.json**

(Or paste this repo URL into Chaos Viewer.) Terminal atlas:
[chaos-viewer-cli](https://github.com/lunavyqo/chaos-viewer-cli).

Console / MCP matching: open this tree with [tangOS](https://github.com/lunavyqo/tangOS)
using committed [`tangos.json`](tangos.json) (`matchConventions` + tools). See
[notes/adopting-match-conventions.md](notes/adopting-match-conventions.md).

## What "matching" means

The goal is source that, when compiled with the original toolchain, produces a
binary byte-for-byte identical to the retail ROM for the function under test.
Every candidate is checked with a relocation-aware compare against your local
dump (`python tools/match.py …`). **Deliverable is C** that goes through mwccarm —
not pasted assembly. Target disassembly is the oracle.
See [notes/matching-style.md](notes/matching-style.md).

## Legal and scope

**This repo must contain only original work:** scripts, build/config metadata we
author, hand-written C, symbols/notes we produce, and documentation.

It must **not** contain:

- the retail `.nds` ROM
- ARM9 / ARM7 / ITCM / DTCM / overlay binaries
- NitroFS contents (`files/` — graphics, SDAT, WAVs, etc.)
- banner icons, header logo, or other game art
- proprietary compilers (e.g. mwccarm)

Those are read locally from a cartridge dump **you** own. They are listed in
`.gitignore` on purpose. **Do not force-add them. Do not publish them.**

**Exception (documented):** the `chaos-data` branch publishes function metadata and
annotated **disassembly text** for unmatched functions so contributors can work
without a full local setup. That is text, not ROM bytes or assets — the same
practice as decomp projects committing `.s` files. Matched functions drop their
disasm from the published data over time as `src/` grows.

You are responsible for complying with the laws that apply to you. Owning a
dump of a game you purchased is a common decomp setup; redistributing Nintendo
assets is not.

## Target build

| Field    | Value         |
|----------|---------------|
| Title    | ELE PLANKTON  |
| Game code| `ATIE`        |
| Maker    | `01`          |
| Compiler | **mwccarm `1.2/sp2p3`** (pinned in practice) |
| Modules  | arm9 only in atlas for now (no overlays) |

Flags (C):

```
-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc
```

Details: [notes/compiler.md](notes/compiler.md). Confirm your ROM against this
before matching; other regions/revisions will differ.

## Layout

```
src/        # Hand-written, verified matching C (promote only after match)
tools/      # Project scripts (mwccarm/ is gitignored — local symlink/copy)
config/     # dsd analysis + attempt/provenance logs (committed)
nearmiss/   # Best near-miss tip C per function (committed; sm64ds-shaped)
notes/      # Setup, compiler pin notes, legal, matching style
docs/       # Longer documentation
tangos.json # Console / MCP descriptor
files/      # LOCAL ONLY — NitroFS extract (gitignored)
arm7/ arm9/ # LOCAL ONLY — binaries gitignored; small yaml may be tracked
ghidra_out/ # LOCAL ONLY — decompiler scaffolds (gitignored)
```

## Logging (sm64ds-shaped + experimental)

| Store | Keeps |
|-------|--------|
| `nearmiss/db.jsonl` | **Best tip C** + `div` ([notes/nearmiss.md](nearmiss.md)) |
| `config/match_attempts.jsonl` | **Every try** (metadata / attempt tree) |
| `config/match_provenance.jsonl` | Final **how** on bank only |

- Near-miss tip C: `log_attempt.py --status near_miss --src …` (upserts nearmiss DB).
- Every try (including `no_progress`): same tool / MATCH_RESULT → attempt log.
- Bank is **not** a new try. No wall-clock times on attempts.
- Status: `matched` only after verify; `near_miss` only when the tip improves;
  otherwise `no_progress`. Details: [notes/match-attempts.md](notes/match-attempts.md).

```bash
python tools/log_attempt.py --func … --status near_miss --divergences N \
  --src path/to/draft.c --kind ai --model grok-4.5 --reasoning high \
  --harness grok-build --session-scope focused --batch-size 1
```

## Setup (short)

1. Own a legal Electroplankton DS dump (`.nds`).
2. Keep it outside git history (ignored as `*.nds`).
3. Unpack locally (`dsd rom extract` / `python tools/unpack.py` / existing layout).
4. `pip install ndspy capstone pyelftools`
5. Place **mwccarm** under `tools/mwccarm/` and **wibo** under `tools/bin/`
   (gitignored; never commit). See [notes/compiler.md](notes/compiler.md).
6. Analysis already lives in `config/` for this tree; re-run if you change extract:
   ```
   dsd init -r config.yaml -o config -b build
   ```
7. **Optional — local Ghidra scaffolds** (not in git): see
   [notes/ghidra-scaffolds.md](notes/ghidra-scaffolds.md).

## Checking matches locally

```bash
python tools/pr_validate.py --base origin/main
# or one file:
python tools/match.py --c src/arm9/func_….c --func NAME --addr 0x… --size 0x… --version 1.2/sp2p3
# iteration oracle:
python tools/fdiff.py --c … --name … --module arm9 --addr 0x… --size 0x…
```

There is no cloud match CI (ROM + mwccarm stay on your machine). Optional ROM-free
**decomp.dev** report: `.github/workflows/report.yml`.

Tooling follows the [sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp) spine
plus EP experimental attempt/provenance logging. See [CONTRIBUTING.md](CONTRIBUTING.md).

## Ground rules

1. **Never commit copyrighted material.** If `git status` shows a `.nds`, `.bin`,
   `files/`, WAV, SDAT, or banner image, stop and fix the ignore rules.
2. **Import knowledge, write code.** Community symbol names and struct offsets are
   fine to use; paste of another project's source is not.
3. **Match to the byte** before promoting anything into `src/`.

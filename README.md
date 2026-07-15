# electroplankton-decomp

A from-scratch effort to decompile **Electroplankton** (Nintendo DS) into
matching C.

This project is structured like other modern DS matching decomps (for example
[sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp)): original tooling and
hand-written source live in git; the ROM and every extracted asset stay on your
machine only.

## Progress

Atlas is regenerated on the `chaos-data` branch (CI / `tools/chaos_db_ci.py`).
Rough scale: **~1,950** arm9 functions, early matching in progress — see the live
viewer for current numbers.

Live atlas (Chaos Viewer): paste the repo URL, or open with data preloaded:

**https://tangosdev.github.io/chaos-viewer/?data=https://raw.githubusercontent.com/lunavyqo/electroplankton-decomp/chaos-data/chaos-db.json**

Terminal atlas + experimental attempt-tree prompts:
[chaos-viewer-cli](https://github.com/lunavyqo/chaos-viewer-cli) with project
convention **experimental** and this repo as `local_repo`.

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
| Modules  | arm9 only in atlas for now (no overlays) |

Confirm your ROM against this before matching; other regions/revisions will
differ.

## Layout

```
src/        # Hand-written, verified matching C (promote only after match)
tools/      # Project scripts (mwccarm/ is gitignored — local symlink/copy)
config/     # dsd analysis: symbols, relocs, delinks (committed)
notes/      # Setup, compiler pin notes, legal
docs/       # Longer documentation
files/      # LOCAL ONLY — NitroFS extract (gitignored)
arm7/ arm9/ # LOCAL ONLY — binaries gitignored; small yaml may be tracked
```

## What "matching" means

Source that, when compiled with the original toolchain, produces bytes identical
to the retail binary for the function under test. A function counts as matched
only after a relocation-aware byte check against your local dump
(`python tools/match.py …`).

**Deliverable is C** that goes through mwccarm — not pasted assembly. Target
disassembly is the oracle. See [notes/matching-style.md](notes/matching-style.md)
and [CONTRIBUTING.md](CONTRIBUTING.md).

**Experimental logging:** every try (including dead ends) is recorded as an
attempt-tree node in `config/match_attempts.jsonl`
([notes/match-attempts.md](notes/match-attempts.md)).

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

## Compiler status

**Pinned in practice: mwccarm `1.2/sp2p3`** with standard NDS flags (8/8 early
matches). Details: [notes/compiler.md](notes/compiler.md).

## Checking matches locally

Before merging matched C, verify against your own dump:

```bash
python tools/pr_validate.py --base origin/main
# or one file:
python tools/match.py --c src/arm9/func_….c --func NAME --addr 0x… --size 0x… --version 1.2/sp2p3
```

There is no cloud match CI for now (ROM + mwccarm stay on your machine only).


## Ground rules

1. **Never commit copyrighted material.** If `git status` shows a `.nds`, `.bin`,
   `files/`, WAV, SDAT, or banner image, stop and fix the ignore rules.
2. **Import knowledge, write code.** Community symbol names and struct offsets are
   fine to use; paste of another project's source is not.
3. **Match to the byte** before promoting anything into `src/`.
4. **Claim work** in [CLAIMS.md](CLAIMS.md) so people do not double up.

## License

Original work in this repository is under the MIT License; see [LICENSE](LICENSE).
That license does **not** cover Electroplankton or any Nintendo / rightsholder
material, which is not present in this repository.

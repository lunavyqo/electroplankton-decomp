# electroplankton-decomp

A from-scratch effort to decompile **Electroplankton** (Nintendo DS) into
matching C.

This project is structured like other modern DS matching decomps (for example
[sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp)): original tooling and
hand-written source live in git; the ROM and every extracted asset stay on your
machine only.

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

You are responsible for complying with the laws that apply to you. Owning a
dump of a game you purchased is a common decomp setup; redistributing Nintendo
assets is not.

## Target build

Local dump metadata (for your machine only) currently matches:

| Field    | Value         |
|----------|---------------|
| Title    | ELE PLANKTON  |
| Game code| `ATIE`        |
| Maker    | `01`          |

Confirm your ROM against this before matching; other regions/revisions will
differ.

## Layout

```
src/        # Hand-written, verified matching C (promote only after match)
tools/      # Original project scripts (never commit mwccarm here)
symbols/    # Symbol maps / name lists we author
config/     # Project-owned analysis/rebuild config (optional)
notes/      # Setup notes, codegen notes, research
docs/       # Longer documentation / diagrams
files/      # LOCAL ONLY — NitroFS extract (gitignored)
arm7/ arm9/ # LOCAL ONLY — binaries gitignored; yaml configs may be tracked
```

Your unpacked ROM may already sit at the repo root (dsd-style `config.yaml`,
`arm9/`, `files/`, …). That is fine for local work. Git will refuse to track the
copyrighted pieces via `.gitignore`.

## What "matching" means

Source that, when compiled with the original toolchain, produces bytes identical
to the retail binary for the function under test. A function counts as matched
only after a byte-for-byte (relocation-aware) check against your local dump.

## Setup (short)

1. Own a legal Electroplankton DS dump (`.nds`).
2. Keep it outside git history (already ignored as `*.nds`).
3. Unpack locally with your preferred toolkit (e.g. [dsd](https://github.com/AetiasHax/ds-decomp) / ndstool).
4. Install Python deps when tooling lands: `ndspy`, `capstone`, `pyelftools`, etc.
5. Obtain mwccarm only from legitimate community toolchain channels; place it under
   `tools/mwccarm/` (gitignored). Never commit it.

Full contributor workflow will live in [CONTRIBUTING.md](CONTRIBUTING.md) as the
toolchain solidifies.

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

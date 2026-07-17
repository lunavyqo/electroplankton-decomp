# Contributing to electroplankton-decomp

Thanks for helping. This is a from-scratch **matching** decompilation of
**Electroplankton** (Nintendo DS): every function we land is hand-written **C**
that compiles with the original toolchain to bytes **identical** to the retail
ARM9 binary. There are ~1,950 arm9 functions in the atlas — every match is real
progress.

## Standards (read this)

This project is intentionally aligned with:

- **[sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp)** — matching layout,
  `nearmiss/db.jsonl`, local verify, claims, `chaos-data` atlas publish
- **[chaos-viewer](https://github.com/tangosdev/chaos-viewer)** — atlas schema and
  live fetch of published `chaos-db.json` (not a frozen manual copy)

**Plus** experimental logging on top of that spine (attempt tree + match
provenance). Do not invent a second system that replaces SM64DS store roles.

### Workflow (PRs)

- Work on a **branch**, open a **PR**, **squash-merge** to `main`, delete the branch.
- Prefer **Conventional Commit** PR titles (`feat:`, `fix:`, `ci:`, `docs:`, or a
  clear match title like historical match PRs).
- Keep match batches separate from tools/CI/docs when practical.
- **No** GitHub Actions that compile against the ROM (mwccarm stays local).

### Where things go

| You have… | Put it… |
|-----------|---------|
| Byte-exact match | `src/…` after local `match.py` MATCH |
| Best near-miss C + div | `nearmiss/db.jsonl` (commit it) |
| Every try (experimental) | `config/match_attempts.jsonl` — **one session/prompt = one try**; bank is not a try |
| Final how on match | `config/match_provenance.jsonl` via `bank.py` |
| Ghidra scaffolds | local `ghidra_out/` only — never commit |

After merge to `main`, CI updates
`chaos-data/chaos-db.json`. Open the viewer against that atlas (or paste this
repo URL into Chaos Viewer), not a hand-copied dump.

### Permuter (optional, SM64DS-style)

Near-miss tips that compile but miss by coloring/order: run
[decomp-permuter](https://github.com/simonlindholm/decomp-permuter) via our glue:

```bash
git clone https://github.com/simonlindholm/decomp-permuter vendor/decomp-permuter
python tools/permuter/import_func.py --name func_….c --from-nearmiss
python tools/permuter/batch.py --from-nearmiss --max-div 8 --limit 5 --secs 120
```

`vendor/` is gitignored. Always re-check with `match.py` before banking.

## Get in touch / claims

- Coordinate in [CLAIMS.md](CLAIMS.md) so two people do not grind the same range.
- Open a GitHub issue for questions or to claim a subsystem.

## What you need

You bring your own copy of the game. Nothing copyrighted lives in this repo.

1. **Your own Electroplankton cartridge dump (`.nds`).** Symbols/addresses are
   verified against the build documented in the README (game code `ATIE` unless
   we expand versions). The ROM and extracts are git-ignored — never commit them.
2. **A local unpack** (`dsd`, `tools/unpack.py`, or equivalent). Binaries stay
   under ignored paths (`arm9/`, `files/`, `extracted/`, …).
3. **Python 3** plus:
   ```bash
   pip install ndspy capstone pyelftools
   ```
4. **mwccarm** (Metrowerks CodeWarrior ARM) under `tools/mwccarm/` (gitignored)
   and **wibo** under `tools/bin/` when needed. See [notes/compiler.md](notes/compiler.md)
   and [notes/setup-mwccarm.md](notes/setup-mwccarm.md).
5. **Optional local vendors** (gitignored): decomp-permuter + m2c for free codegen
   polish and semantic drafts:
   ```bash
   ./tools/setup_vendor.sh
   # or manually:
   #   git clone https://github.com/simonlindholm/decomp-permuter vendor/decomp-permuter
   #   git clone https://github.com/matt-kempster/m2c vendor/m2c
   pip install toml pcpp pycparser
   ```
   See [tools/permuter/README.md](tools/permuter/README.md) and
   [notes/m2c-setup.md](notes/m2c-setup.md).

## First-time setup

```bash
git clone https://github.com/lunavyqo/electroplankton-decomp
cd electroplankton-decomp
pip install ndspy capstone pyelftools toml pcpp pycparser

# Your dump (gitignored), e.g.:
#   cp /path/to/your/Electroplankton.nds ./Electroplankton.nds
# Unpack with dsd / tools/unpack.py, then:
#   dsd init -r config.yaml -o config -b build   # if re-analysing

# Optional: permuter + m2c engines (local only)
./tools/setup_vendor.sh
```

### Local Ghidra scaffolds (recommended)

Decompiler C is **per machine**, built from **your** unpacked `arm9/arm9.bin`.
Do **not** commit `ghidra_out/`, `ghidra_projects/`, or `ghidra_targets.txt`.

```bash
# 1) One-time Ghidra project: import arm9/arm9.bin
#    Language ARM:LE:32:v5t, base 0x02000000 → ghidra_projects/ep-arm9

# 2) Target list from committed symbols (local file only):
python tools/ghidra_targets.py

# 3) Dump C scaffolds (after analyzeHeadless is on PATH / GHIDRA_HOME set):
analyzeHeadless \
  ghidra_projects ep-arm9 \
  -process arm9.bin \
  -scriptPath tools/ghidra \
  -postScript DecompDump.java ghidra_targets.txt ghidra_out
```

Full notes + Discord blurb: [notes/ghidra-scaffolds.md](notes/ghidra-scaffolds.md).
README setup step 7 has the same command.

Before every commit:

```bash
git status
```

If you see `Electroplankton.nds`, `files/`, `*.bin`, `*.sdat`, `*.wav`, or banner
art — **do not commit**. Fix ignores first.

## The matching loop

Pinned compiler: **mwccarm `1.2/sp2p3`** with flags:

```
-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc
```

Setup details: [notes/setup-mwccarm.md](notes/setup-mwccarm.md),
[notes/compiler.md](notes/compiler.md). Codegen idioms:
[notes/mwccarm-codegen.md](notes/mwccarm-codegen.md),
[notes/pret-idioms.md](notes/pret-idioms.md).

1. **Pick / claim** an unmatched function (CLAIMS.md).
2. **Read** annotated disassembly (local tools or Chaos Viewer details). That
   listing is the **oracle**, not a source file to paste.
   ```bash
   python tools/disasm.py --module arm9 --addr 0x020xxxxx --size 0x..
   ```
3. **Write C** (scratch is fine). Prefer C that will go through mwccarm — never
   treat raw asm as the deliverable. Style notes: [notes/matching-style.md](notes/matching-style.md).
4. **Compile + byte-diff** (relocation-aware):
   ```bash
   python tools/match.py --c yourfile.c --func NAME --addr 0x020xxxxx --size 0x.. \
     --version 1.2/sp2p3
   # Per-instruction oracle while iterating:
   python tools/fdiff.py --c yourfile.c --name NAME --module arm9 --addr 0x.. --size 0x..
   ```
   Iterate until `match.py` reports a **MATCH**.
5. **Reloc destinations** (calls / globals): a byte match wildcards reloc slots.
   For call-heavy functions, also run:
   ```bash
   python tools/linkcheck.py   # see notes/link-verification.md
   ```
6. **Near-miss:** keep the best compiling draft with  
   `// NONMATCHING: … (div=N)`  
   and log the try with `--src` so tip **C** lands in `nearmiss/db.jsonl`
   ([notes/nearmiss.md](notes/nearmiss.md)). **Commit `nearmiss/db.jsonl`** in the
   PR (same as sm64ds-decomp) so CI can put `div` on the public atlas. Do not
   replace a near-miss with an asm dump.
7. **Bank** a true match (experimental provenance required — EP `tools/bank.py`):
   ```bash
   python tools/bank.py --src src/arm9/….c --kind ai|human --author YOUR_GITHUB \
     --model … --reasoning … --harness … \
     --session-scope focused --batch-size 1
   ```
8. **PR** one function or a small related family; note compiler version and
   address in the PR body.

### Free / batch tools (sm64ds spine)

These were ported from [sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp)
and adapted to EP’s `arm9/` layout (base `0x02000000`):

| Tool | Role |
|------|------|
| `tools/swarm.py` / `sweep.py` | Zero-token template tier across modules |
| `tools/clone.py` / `paramclone.py` | Free match from already-matched skeletons |
| `tools/worklist.py` | Pre-resolved context for agent fan-out |
| `tools/triage.py` | Size the unmatched pile before LLM work |
| `tools/nearmiss_db.py` | Best near-miss tip store (`nearmiss/db.jsonl`) |
| `tools/agent_bank.py` | Verify-and-bank agent batch results (not provenance `bank.py`) |
| `tools/m2c_draft.py` | Semantic draft via local `vendor/m2c` ([notes/m2c-setup.md](notes/m2c-setup.md)) |
| `tools/permuter/` | decomp-permuter wrappers ([tools/permuter/README.md](tools/permuter/README.md)) |
| `tools/ghidra/` + `ghidra_targets.py` | Local decompiler scaffolds ([notes/ghidra-scaffolds.md](notes/ghidra-scaffolds.md)) |
| `tools/decomp_report.py` | Optional decomp.dev report (ROM-free) |
| `tools/modules.py` / `names.py` / `relocs.py` | Module + symbol + reloc registry |

`progress/` and `vendor/` stay gitignored (local ledgers, m2c, decomp-permuter).

### Chaos Viewer atlas (after merge to `main`)

There is **no** PR CI that recompiles matches (mwccarm/ROM stay local). After
merge, **`update-chaos-data`** (sm64ds-style) runs on Ubuntu and:

1. Rebuilds `chaos-db.json` from committed `src/` + `config/` + `nearmiss/db.jsonl`
2. Pushes it to the **`chaos-data`** branch (viewer downloads this file)
3. Updates the README progress bar + `contributions.json` on `main`

Open the viewer with:

`?data=https://raw.githubusercontent.com/lunavyqo/electroplankton-decomp/chaos-data/chaos-db.json`

### Easy pickings: near-miss drafts

If you cannot fully match after real effort, a compiling near-miss is still
valuable. Open a PR or leave a draft headed with `// NONMATCHING: …`. Later
sessions should **start from that C**, not re-decompile from asm.

## Experimental logging (attempt tree)

This project uses the **experimental** tracking convention (Chaos Viewer CLI
profile). Every matching iteration — including failures — is recorded:

| Store | Content |
|-------|---------|
| `config/match_attempts.jsonl` | **Every try** as an attempt-tree node |
| `config/match_provenance.jsonl` | Final **how** (+ `author`) when banked |

Identity fields (required on new attempts):

- `functionId` — atlas id (`module:0xaddr`)
- `attemptId` — unique UUID for this try
- `parentAttemptId` — node you built on, or `null`
- `schemaVersion` — `1`

Do **not** log wall-clock times (`loggedAt` / `ts`) on attempts.

See [notes/match-attempts.md](notes/match-attempts.md) and
[notes/match-provenance.md](notes/match-provenance.md).

```bash
python tools/log_attempt.py --func NAME --module arm9 --addr 0x… \
  --status no_progress --kind ai \
  --model grok-4.5 --reasoning high --harness grok-build \
  --session-scope focused --batch-size 1

# bank (who = git; how = model/reasoning/harness)
python tools/bank.py --src src/arm9/NAME.c --kind ai \
  --model grok-4.5 --reasoning high --harness grok-build \
  --session-scope focused --batch-size 1
```

See [notes/match-provenance.md](notes/match-provenance.md) and [notes/nearmiss.md](notes/nearmiss.md) for who vs how and near-miss → atlas `div`.

## Chaos atlas (optional publish)

```bash
python tools/chaos_db_ci.py
# publishes matched + git author + matchProvenance + near-miss div
# + details generation / chaos-data branch push via CI or your usual flow
```

Project text for Chaos Viewer prompts lives in
`tools/chaosviewer.config.json` (compiler, rules, nearMissNote, readFirst, …).

## Ground rules (short)

1. **Never commit copyrighted material.**
2. **Import knowledge, write code** — all C from scratch against your dump.
3. **Match to the byte** before promoting to `src/` as matched.
4. **C through the compiler** — target disasm is the oracle, not the deliverable.
5. **Claim** work in CLAIMS.md.
6. **Log every try** on experimental work (attempt tree).

## Questions

Open a GitHub issue, or leave a note in CLAIMS.md.

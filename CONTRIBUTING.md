# Contributing to electroplankton-decomp

Thanks for helping. This is a from-scratch **matching** decompilation of
**Electroplankton** (Nintendo DS): every function we land is hand-written **C**
that compiles with the original toolchain to bytes **identical** to the retail
ARM9 binary. There are ~1,950 arm9 functions in the atlas — every match is real
progress.

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
   and **wibo** under `tools/bin/` when needed. See [notes/compiler.md](notes/compiler.md).

## First-time setup

```bash
git clone https://github.com/lunavyqo/electroplankton-decomp
cd electroplankton-decomp
pip install ndspy capstone pyelftools

# Your dump (gitignored), e.g.:
#   cp /path/to/your/Electroplankton.nds ./Electroplankton.nds
# Unpack with dsd / tools/unpack.py, then:
#   dsd init -r config.yaml -o config -b build   # if re-analysing
```

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

1. **Pick / claim** an unmatched function (CLAIMS.md).
2. **Read** annotated disassembly (local tools or Chaos Viewer details). That
   listing is the **oracle**, not a source file to paste.
3. **Write C** (scratch is fine). Prefer C that will go through mwccarm — never
   treat raw asm as the deliverable. Style notes: [notes/matching-style.md](notes/matching-style.md).
4. **Compile + byte-diff** (relocation-aware):
   ```bash
   python tools/match.py --c yourfile.c --func NAME --addr 0x020xxxxx --size 0x.. \
     --version 1.2/sp2p3
   ```
   Iterate until the verify command reports a **MATCH**.
5. **Near-miss:** keep the best compiling draft with  
   `// NONMATCHING: … (div=N)`  
   and log the try (below). Do not replace it with an asm dump.
6. **Bank** a true match (experimental provenance required):
   ```bash
   python tools/bank.py --src src/arm9/….c --kind ai|human --author YOUR_GITHUB \
     --model … --reasoning … --harness … \
     --session-scope focused --batch-size 1
   ```
7. **PR** one function or a small related family; note compiler version and
   address in the PR body.

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
- `schemaVersion` / `loggedAt`

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

See [notes/proposal-logging-for-tango.md](notes/proposal-logging-for-tango.md)
for the SM64DS-shaped design (who vs how, near-miss → atlas `div`).

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

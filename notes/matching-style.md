# Matching style (Electroplankton)

How to land functions without falling into the “paste the disasm” trap.
This project is a **matching decomp**: the product is **hand-written C** that
`tools/match.py` reports as **MATCH** against your own dump under **mwccarm
1.2/sp2p3** (see [compiler.md](compiler.md)).

## Deliverable

| Do | Don’t |
|----|--------|
| Write **C** (or C++ with first line `//cpp` if the symbol is mangled `_Z…`) | Check in or “finish” with pure `.s` / raw asm dumps |
| Compile with the **pinned** mwccarm + flags | Invent a different compiler version |
| Iterate until `tools/match.py` says **MATCH** | Treat target disassembly as the source file |
| Promote matching C into `src/` | Promote `// NONMATCHING` drafts as matched |

**Target disassembly** (chaos-data details, `tools/disasm.py`, abrow-style
listings) is the **oracle** — what the ROM already does. You match it by
writing C the compiler turns into those bytes. Pasting the listing into a
`.s` file is not a match and is not how this repo works.

## Matching loop

1. **Claim** the range/subsystem in [CLAIMS.md](../CLAIMS.md).
2. **Read** the annotated disasm for the function (local tools or chaos atlas detail).
3. **Write C** (scratch first is fine):
   ```bash
   # example
   python tools/match.py --c scratch/foo.c --func NAME \
     --addr 0x020xxxxx --size 0x.. --version 1.2/sp2p3
   ```
4. **Iterate** (struct layout, cast patterns, declaration order, u64 masks, …)
   until MATCH. For compiler habits, start from [compiler.md](compiler.md);
   many DS mwccarm patterns are shared with sm64ds-style notes (regalloc via
   declaration order, pool loads, `-O4,p` reordering).
5. **Near-miss?** Keep the best compiling C with:
   ```c
   // NONMATCHING: <short reason> (div=N)
   ```
   Log the try (below). Do not throw the draft away for an asm paste.
6. **Bank** a true match with provenance (experimental):
   ```bash
   python tools/bank.py --src src/arm9/….c --kind ai|human --author YOUR_GH \
     --model … --reasoning … --harness … \
     --session-scope focused --batch-size 1
   ```
7. **PR** one function or a small related family; note compiler + address.

## Experimental: log every try as an attempt tree

Every iteration — including `no_progress`, `compile_error`, and non-improving
near-misses — appends a **node** to `config/match_attempts.jsonl`.

Required identity (see [match-attempts.md](match-attempts.md)):

| Field | Meaning |
|-------|---------|
| `functionId` | Atlas id `module:0xaddr` (stable) |
| `attemptId` | Unique id for **this** try (UUID; never `a1`) |
| `parentAttemptId` | Node you built on, or `null` for a new root |
| `schemaVersion` | `1` (bump only when meanings change) |

Do **not** log wall-clock times (`loggedAt` / `ts`) — privacy.

Tree shape (not a flat diary):

```text
functionId = arm9:0x02001a64
├─ near_miss div=40   parent=null
│  ├─ no_progress     parent=…
│  └─ near_miss div=12 parent=…   improved
│     └─ matched      parent=…
```

```bash
python tools/log_attempt.py --func NAME --module arm9 --addr 0x… \
  --status no_progress --kind ai \
  --model grok-4.5 --reasoning high --harness grok-build \
  --author you --session-scope focused --batch-size 1 \
  --parent-attempt-id <prior-attemptId>
```

Agents using the **chaos-experimental** prompt must emit a `MATCH_RESULT` with
these fields; operators ingest with `log_attempt.py`.

## When stuck

1. Re-read the disasm **and** any near-miss C draft — improve the C, don’t
   replace it with asm.
2. Check struct sizes / call signatures of callees.
3. Try declaration reorder and smaller temps (regalloc wall).
4. Log `no_progress` or `near_miss` with a short `note` (settings / idea), then
   escalate model tier on the **best tip** (`parentAttemptId`), not from scratch.
5. Ask / re-claim if blocked; don’t burn another session without a log node.

## Related

- [compiler.md](compiler.md) — pin + flags + evidence
- [setup-mwccarm.md](setup-mwccarm.md) — where to get mwccarm
- [mwccarm-codegen.md](mwccarm-codegen.md) — deep codegen levers (sm64ds spine)
- [pret-idioms.md](pret-idioms.md) — pret-style matching idioms
- [matching-style-sm64ds.md](matching-style-sm64ds.md) — fuller SM64DS style notes
- [link-verification.md](link-verification.md) — reloc destination checks
- [ghidra-scaffolds.md](ghidra-scaffolds.md) — local decompiler dumps
- [match-provenance.md](match-provenance.md) — who (`author`) vs how (`matchProvenance`)
- [match-attempts.md](match-attempts.md) — full attempt log schema
- [legal.md](legal.md) — ROM / assets never in git

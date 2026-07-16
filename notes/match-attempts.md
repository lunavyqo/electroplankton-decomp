# Match attempts (experimental) — every try as a tree

Append-only history of **every matching iteration**, including:

- no score improvement
- no better near-miss
- compile errors
- failed verify
- successful match

This is separate from:

| Store | Keeps |
|-------|--------|
| `config/match_provenance.jsonl` | Final **how** when banked (+ `author` who) |
| **`nearmiss/db.jsonl`** | Closest **C** tip only (`c_source` + `div`) — [nearmiss.md](nearmiss.md) |
| **`config/match_attempts.jsonl`** | **All tries** (attempt tree metadata; no full C) |

## Attempt tree (not a flat diary)

```text
functionId = arm9:0x02001a64
├─ attemptId=aa…  near_miss div=40   parent=null      base=scratch
│  ├─ bb…  no_progress               parent=aa…       (dead-end sibling)
│  └─ cc…  near_miss div=12          parent=aa…       improvedNearMiss=true
│     └─ dd…  matched                parent=cc…       continued from best tip
```

Rules:

- First try: `parentAttemptId = null`, `base.kind = scratch` (or draft/sibling).
- Later tries: `parentAttemptId` = the node you **actually built on** (usually best near-miss tip).
- `no_progress` still gets a node under that parent.
- After an improved near-miss, continue with `parent` = that new node.
- **Never** key history by display name alone — use **`functionId`**.
- **Never** reuse `attemptId` (use UUIDs; `log_attempt.py` generates them).

## Record shape (schemaVersion 1)

```json
{
  "schemaVersion": 1,
  "functionId": "arm9:0x02001a64",
  "id": "arm9:0x02001a64",
  "attemptId": "a1b2c3d4e5f64789a0b1c2d3e4f50617",
  "parentAttemptId": null,
  "loggedAt": "2026-07-15T12:00:00Z",
  "ts": "2026-07-15T12:00:00Z",
  "module": "arm9",
  "addr": 33561188,
  "name": "func_02001a64",
  "status": "no_progress",
  "kind": "ai",
  "model": "grok-4.5",
  "reasoning": "high",
  "harness": "grok-build",
  "author": "lunavyqo",
  "base": { "kind": "scratch" },
  "divergences": null,
  "prevBestDivergences": 4,
  "improvedNearMiss": false,
  "srcPath": "scratch/try3.c",
  "label": "wave-cheap-01",
  "sessionScope": "focused",
  "batchSize": 1,
  "note": "optional"
}
```

### Identity fields (required)

| Field | Role |
|-------|------|
| `schemaVersion` | `1` — bump only when meanings change |
| `functionId` | Atlas `module:0xaddr` (stable). Legacy key `id` is the same value. |
| `attemptId` | Unique id for **this** node (UUID hex). Never `a1` / `try2`. |
| `parentAttemptId` | Prior `attemptId` you built on, or `null` |
| `loggedAt` | ISO-8601 UTC when the try finished (`ts` mirrors it) |

### base.kind

| Value | Meaning |
|-------|---------|
| `scratch` | Started from empty / re-decompile |
| `previous_attempt` | Edited from a prior attempt node |
| `near_miss_draft` | Started from a stored NONMATCHING C draft |
| `matched_sibling` | Scaffolded from a matched sibling |

### sessionScope (required every run)

| Value | Meaning |
|-------|---------|
| **`focused`** | Session was only for this function (`batchSize` = 1) |
| **`batch`** | One of several functions in the same session (`batchSize` ≥ 2) |

### status

| Value | Meaning |
|-------|---------|
| `matched` | Verify reported MATCH (also written by `bank.py`) |
| `near_miss` | Scored draft exists (set `divergences`) |
| `no_progress` | Tried; no useful score / no improvement |
| `compile_error` | Did not compile |
| `failed` | Other failure |
| `skipped` | Deliberately skipped |

`improvedNearMiss` is true when `divergences < prevBestDivergences` (or set explicitly).

**Do not** put full C sources in the attempt log (size). Use `srcPath` to a
scratch file, and for a scored near-miss pass `--src` so
`log_attempt.py` also upserts tip C into **`nearmiss/db.jsonl`**.

**Do not** log pure asm as a successful path — deliverable is C through mwccarm
([matching-style.md](matching-style.md)).

## CLI

```bash
# Dead end under a parent tip (multi-function batch)
python tools/log_attempt.py \
  --func func_02001a64 --module arm9 --addr 0x02001a64 \
  --status no_progress --kind ai \
  --model grok-4.5 --reasoning high --harness grok-build \
  --author lunavyqo --session-scope batch --batch-size 8 \
  --parent-attempt-id <prior> --note "no change"

# Focused near-miss (pass --src so tip C is stored in nearmiss/db.jsonl)
python tools/log_attempt.py --func func_02001a64 \
  --status near_miss --divergences 6 --prev-best 4 \
  --src scratch/func_02001a64.c \
  --kind ai --model grok-4.5 --reasoning high --harness grok-build \
  --session-scope focused --batch-size 1 --stats

# Bank success also logs status=matched (pass scope)
python tools/bank.py --src src/arm9/func_….c --kind ai --author you \
  --model … --reasoning … --harness … --no-verify \
  --session-scope focused --batch-size 1
```

## Tests

```bash
python tools/test_match_attempts.py
```

## Policy

Log **every** agent/human iteration for experimental work. Prefer over-logging.
Agents using the chaos-experimental prompt should emit a MATCH_RESULT for each
function each session (with functionId + attemptId + parentAttemptId);
operators ingest with `log_attempt.py` (or future auto-parse).

Use `label` for mass-run waves (`wave-cheap-01`, `wave-mid-02`) so later queries
can filter by model tier without re-reading chat history.

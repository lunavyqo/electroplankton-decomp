# Match attempts (experimental) — every try

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
| Near-miss best draft (if any) | Closest candidate only |
| **`config/match_attempts.jsonl`** | **All tries** |

## Record shape

```json
{
  "ts": "2026-07-13T12:00:00Z",
  "id": "arm9:0x02001a64",
  "module": "arm9",
  "addr": 33561188,
  "name": "func_02001a64",
  "status": "no_progress",
  "kind": "ai",
  "model": "grok-4.5",
  "reasoning": "high",
  "harness": "grok-build",
  "author": "lunavyqo",
  "divergences": null,
  "prevBestDivergences": 4,
  "improvedNearMiss": false,
  "srcPath": "scratch/try3.c",
  "label": "session-12",
  "note": "optional"
}
```

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

**Do not** put full C sources in the log (size). Use `srcPath` to a scratch file.

## CLI

```bash
# Every dead-end try still goes here
python tools/log_attempt.py \
  --func func_02001a64 --module arm9 --addr 0x02001a64 \
  --status no_progress --kind ai \
  --model grok-4.5 --reasoning high --harness grok-build \
  --author lunavyqo --note "no change"

# Near-miss that did not beat best
python tools/log_attempt.py --func func_02001a64 \
  --status near_miss --divergences 6 --prev-best 4 \
  --kind ai --model grok-4.5 --reasoning high --harness grok-build \
  --stats

# Bank success also logs status=matched
python tools/bank.py --src src/arm9/func_….c --kind ai --author you \
  --model … --reasoning … --harness … --no-verify
```

## Tests

```bash
python tools/test_match_attempts.py
```

## Policy

Log **every** agent/human iteration for experimental work. Prefer over-logging.
Agents using the chaos-experimental prompt should emit a MATCH_RESULT for each
function each session; operators ingest with `log_attempt.py` (or future auto-parse).

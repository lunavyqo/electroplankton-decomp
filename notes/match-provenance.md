# Match provenance (experimental) — who vs how

## Rules

| Field | Meaning |
|-------|---------|
| **`author`** | **Who** matched it (GitHub login). Classic chaos-viewer credit / colors. |
| **`matchProvenance`** | **How** it was matched only. |

| how kind | Required |
|----------|----------|
| **human** | `kind: human` (optional `note`) |
| **ai** | `kind: ai` + non-empty **model**, **reasoning**, **harness** (slugs) |

Do **not** put the operator inside `matchProvenance` (no `by`). Use `author`.

## Ledger

`config/match_provenance.jsonl` — one JSON object per line; last `id` wins.

```json
{"id":"arm9:0x02001a64","module":"arm9","addr":33561188,"name":"func_02001a64","author":"lunavyqo","srcPath":"src/arm9/func_02001a64.c","matchProvenance":{"kind":"ai","model":"grok-4.5","reasoning":"high","harness":"grok-build"}}
```

**Who is git-based (sm64ds-style):** `bank.py` / `chaos_db_ci.py` set `author`
from the **first git adder** of the surviving `src/` file (renames carry credit).
Agent/harness names (`grok`, `claude-opus-4`, …) are never accepted as credit —
even if a bad CLI pass put them in `matchProvenance.by` or `--author`.

Legacy `matchProvenance.by` is ignored for credit when it looks like an agent name.

## Banking

```bash
# Who = git first-adder of src/ (sm64ds-style). How = flags. No --author needed.
python tools/bank.py --src src/arm9/func_02001a64.c \
  --kind ai \
  --model "Grok 4.5" --reasoning high --harness "Grok Build" \
  --session-scope focused --batch-size 1 \
  --no-verify

# Human how-record (credit still from git unless --author is a real login)
python tools/bank.py --src … --kind human \
  --session-scope focused --batch-size 1 --no-verify
```

Display names are slugified (`Grok 4.5` → `grok-4.5`). Use `--repo` if scripts run from `/tmp`.
Never pass agent names as `--author` (`grok` is rejected).

## Atlas

```bash
python tools/chaos_db_ci.py
```

- Matched: `author` from **git**, `matchProvenance` from ledger (**how**)  
- Unmatched near-misses: `div` from best `near_miss` in `match_attempts.jsonl`  

Attempt-tree schema and operator notes: [match-attempts.md](match-attempts.md).
Near-miss tip store: [nearmiss.md](nearmiss.md).

## Attempt history (every try — attempt tree)

Final bank is not enough. **Every** matching iteration (including no progress)
goes to `config/match_attempts.jsonl` via `tools/log_attempt.py` as an
**attempt-tree node** (`functionId`, unique `attemptId`, `parentAttemptId`,
`base`). Do **not** log wall-clock times. See **notes/match-attempts.md** and
**notes/matching-style.md**.

## Tests

```bash
python tools/test_match_provenance.py
python tools/test_match_attempts.py
```

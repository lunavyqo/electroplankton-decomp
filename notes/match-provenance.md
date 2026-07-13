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

Legacy rows with `matchProvenance.by` still load: `by` is migrated to `author`.

## Banking

```bash
python tools/bank.py --src src/arm9/func_02001a64.c \
  --kind ai --author lunavyqo \
  --model "Grok 4.5" --reasoning high --harness "Grok Build" \
  --no-verify

# --by is an alias for --author
python tools/bank.py --src … --kind human --by lunavyqo --no-verify
```

Display names are slugified (`Grok 4.5` → `grok-4.5`). Use `--repo` if scripts run from `/tmp`.

## Atlas

```bash
python tools/chaos_db_ci.py
```

Sets `author` + `matchProvenance` from the ledger on matched functions.

## Tests

```bash
python tools/test_match_provenance.py
```

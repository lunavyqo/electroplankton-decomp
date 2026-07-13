# Match provenance (experimental)

Every **successful match** must permanently record **how** it was matched, per
function. This is experimental atlas tracking for electroplankton-decomp only.

## Rules

| Case | Required |
|------|----------|
| **Human** | `kind: human` (optional `by`, optional `note`) |
| **AI** | `kind: ai` with **all three** non-empty: `model`, `reasoning`, `harness` |

Missing or incomplete AI provenance is a **bug**. Do not bank without a complete
record.

`author` (git / contributor color) is **not** a substitute for provenance.

### Token form

Banking tools **slugify** display names:

| Input | Stored |
|-------|--------|
| `Grok 4.5` | `grok-4.5` |
| `Grok Build` | `grok-build` |
| `claude-opus-4` | `claude-opus-4` |

Prefer writing slugs directly. Spaces are allowed on the CLI and normalized.

## Durable store

```
config/match_provenance.jsonl
```

One JSON object per line. Last row for a given `id` wins.

## Banking

```bash
# From the repo (or pass --repo always if tools were copied elsewhere)
python tools/bank.py --src src/arm9/func_02001a64.c \
  --kind ai --model "Grok 4.5" --reasoning high --harness "Grok Build" \
  --by lunavyqo --no-verify

# Explicit root (fixes /tmp script copies)
python /tmp/ep-bank-tools/bank.py --repo "$PWD" \
  --src src/arm9/func_02001a64.c --kind human --by lunavyqo --no-verify

# Env alternative
export DECOMP_ROOT=/path/to/electroplankton-decomp
python /tmp/ep-bank-tools/bank.py --src src/arm9/func_….c --kind human --by you
```

| Flag | Meaning |
|------|---------|
| `--repo` | Decomp root (also `DECOMP_ROOT` / `MATCH_REPO`) |
| `--model` | Model id (slugified) |
| `--reasoning` | Effort/level (`high` / `medium` / `low` / `none` / …) |
| `--harness` | Pipeline id (slugified) |
| `--dry-run` | Print resolved REPO + provenance; no write |
| `--no-verify` | Skip `match.py` (operator asserts already matched) |
| `--force` | Append even if id already has a ledger row |

Incomplete AI → exit code **2**, no ledger write.

## Atlas

```bash
python tools/chaos_db_ci.py
```

Copies ledger `matchProvenance` onto matched functions. Warns for matched funcs
missing a ledger row.

## Tests

```bash
python tools/test_match_provenance.py
```

## Non-goals

- Changing chaos-viewer-cli / default convention atlases
- Attempt history for failed runs
- Secrets, API keys, or full chat transcripts in the atlas

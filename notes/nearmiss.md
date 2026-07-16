# Near-miss tip store (`nearmiss/db.jsonl`)

SM64DS-shaped store of the **best** compiling C draft per function (fewest
divergences). This is where **full C** for the tip lives.

| Store | What it keeps |
|-------|----------------|
| **`nearmiss/db.jsonl`** | One tip per function: `divergences` + **`c_source`** (+ meta) |
| `config/match_attempts.jsonl` | **Every try** as metadata (+ optional `srcPath`); no full C |
| `config/match_provenance.jsonl` | Final **how** on bank only |

## Record shape

```json
{
  "module": "arm9",
  "addr": "0x020009e0",
  "name": "func_020009e0",
  "size": 120,
  "lang": "c",
  "divergences": 4,
  "c_source": "/* full C */\n…\n",
  "source": "log_attempt",
  "srcPath": "scratch/try.c"
}
```

Same role as sm64ds-decomp `nearmiss/db.jsonl`. Tips are meant to be **committed**
so the closest draft survives clones (unlike local Ghidra dumps). After merge to
`main`, GitHub Actions (`update-chaos-data`) reads this file and writes `div` into
`chaos-data/chaos-db.json` for the web viewer.

## How tips get written

```bash
# Preferred: log a near_miss with --src so tip C is saved automatically
python tools/log_attempt.py --func func_020009e0 \
  --status near_miss --divergences 4 --src scratch/try.c \
  --kind ai --model grok-4.5 --reasoning high --harness grok-build \
  --session-scope focused --batch-size 1

# Manual upsert / replace only if closer
python tools/nearmiss_db.py upsert --src scratch/try.c --func func_020009e0 \
  --module arm9 --addr 0x020009e0 --divergences 4 --label wave-01

# Backfill from old attempts that still have srcPath files on disk
python tools/nearmiss_db.py harvest-from-attempts

python tools/nearmiss_db.py stats
python tools/nearmiss_db.py list --max-div 12
python tools/nearmiss_db.py prune-matched   # drop tips already matched in src/
```

`bank.py` removes the tip for a function when it is banked as a true match.

## Atlas / details

- `chaos_db_ci.py` reads tip **`div`** from `nearmiss/db.jsonl` (attempts as gap-fill).
- `generate_details.py` puts tip **`c_source`** into details `draft` + `draftDiv`.

## Policy

- Only store **compiling** C you would be willing to refine later.
- Never bank tip C as a match without `match.py` MATCH.
- Do **not** put Ghidra decompiler dumps here unless you have scored them as a real near-miss against mwcc (prefer `ghidra_out/` for raw decompiler scaffolds).

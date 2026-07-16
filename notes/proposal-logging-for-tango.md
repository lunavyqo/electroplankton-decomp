# Proposal: SM64DS-shaped logging + experimental how/attempt data

**Audience:** Tango / sm64ds-decomp maintainers  
**Status:** draft for discussion (local EP implementation; not a demand to merge)  
**Repo that prototypes this:** electroplankton-decomp (`tools/` + `notes/`)

---

## Goal

Keep the **same store roles as sm64ds-decomp** (so chaos-viewer and operators
already understand them), and **add only**:

1. **How** a match was done (`matchProvenance`: human vs ai+model+reasoning+harness)
2. Optional **full attempt tree** (every try, including dead ends) for research

Do **not** invent a second unrelated system. Do **not** put agent names in `author`.

---

## SM64DS spine (unchanged roles)

| Role | SM64DS today | EP prototype |
|------|----------------|--------------|
| Verify | `tools/match.py` | same |
| **Who** on atlas | git first-adder of surviving `src/` | same (`first_matchers`) |
| **Best near-miss** | `nearmiss/db.jsonl` (1 tip / function) | derived: best `near_miss` in `match_attempts.jsonl` → atlas `div` |
| Matched park | `src/` + matched ledger | `src/` + bank |
| NONMATCHING park | marked src + nonmatching ledger | `// NONMATCHING` in src (same idea) |
| Atlas publish | `chaos_db_ci.py` → matched + **div** + author | same inputs/outputs |

Viewer near-miss badges only need atlas **`div`**. That field must come from the
**best near-miss store**, not from hoping attempts exist.

---

## Experimental additions (orthogonal)

| Role | Store | Notes |
|------|--------|--------|
| **How** (final) | `config/match_provenance.jsonl` | On **bank** only. Never stores who. |
| **Who** | `author` on ledger **and** atlas | From **git**, not CLI agent handle |
| **Every try** | `config/match_attempts.jsonl` | Attempt tree; optional for viewer parity |
| Prompt scaffold | MATCH_RESULT block | Agents log tries; same schema as attempts |

### Who vs how (hard rule)

```text
author            = human GitHub login (git first-adder / sm64ds rule)
matchProvenance   = how only: human | ai{model,reasoning,harness}
```

Agent product names (`grok`, `claude-opus-4`, harness ids) are **never** credit.

---

## Data flow (one picture)

```text
match.py  ──►  div / MATCH
                 │
                 ├─ near_miss tip ──► best score ──► chaos-db "div"  ──► viewer
                 │                    (+ draft path → details draft)
                 │
                 └─ MATCH ──► bank.py ──► src/ + match_provenance.jsonl
                                    │         (how)
                                    │         author from git (who)
                                    ▼
                              chaos_db_ci.py ──► chaos-db.json
                                    author + matchProvenance + div

optional parallel:
  every try ──► log_attempt.py ──► match_attempts.jsonl (tree)
```

---

## What we ask Tango to consider

1. **Adopt who/how split** on the published atlas for AI-era matching  
   (`author` unchanged; optional/required `matchProvenance` for projects that want it).

2. **Keep near-miss as best-tip store** (sm64ds `nearmiss/db.jsonl` remains the model).  
   Full attempt trees can stay project-optional (EP uses jsonl attempt log as the
   source from which best tip + div are derived).

3. **Reject agent names as `author`** in any generator or bank path.

4. **Chaos Viewer** can later show “via ai · model=…” when `matchProvenance` is present —
   without breaking default sm64ds projects that omit it.

This is **additive**. Existing sm64ds ledgers keep working; experimental projects
opt into how-records + attempt trees.

---

## EP implementation checklist (prototype)

- [x] `match_provenance` schema + bank require complete AI how-records  
- [x] `author` from git first-adder; block agent credit  
- [x] `match_attempts` attempt tree + `log_attempt.py`  
- [x] `chaos_db_ci` publishes `div` from best near_miss attempts  
- [x] `chaos_db_ci` publishes git `author` + ledger `matchProvenance`  
- [x] details gen can attach draft from best near-miss `srcPath`  
- [ ] Optional: materialize explicit `nearmiss/db.jsonl` for byte-identical sm64ds tool names  
- [ ] Optional: upstream PR to chaos-viewer for provenance badges (after discussion)  
- [ ] Publish regenerated `chaos-data` so hosted viewer shows divs  

---

## Commands (EP)

```bash
# every try
python tools/log_attempt.py --func NAME --module arm9 --addr 0x… \
  --status near_miss --divergences N --kind ai \
  --model grok-4.5 --reasoning high --harness grok-build \
  --session-scope focused --batch-size 1

# bank match (who defaults from git; how from flags)
python tools/bank.py --src src/arm9/NAME.c --kind ai \
  --model grok-4.5 --reasoning high --harness grok-build \
  --session-scope focused --batch-size 1

# atlas
python tools/chaos_db_ci.py
```

---

## Out of scope for this proposal

- Swarm / cascade / overnight automation  
- Changing sm64ds progress ledger file layout  
- Pushing experimental-only web forks to tangosdev without agreement  

# Adopting match conventions (Chaos Viewer + tangOS)

Reference for **other decomps** (especially [sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp))
and for Tango when wiring Console / the progress atlas to the same rules EP uses.

**This decomp (electroplankton)** is the full experimental reference. SM64DS already has
the matching **spine** (symbols, `src/`, `nearmiss/db.jsonl`, `chaos_db_ci`). Attempt-tree
logging is **optional** and additive — do not replace the near-miss tip store.

---

## What is ready today

| Piece | Where | Status |
|-------|--------|--------|
| Progress atlas UI | [lunavyqo/chaos-viewer](https://github.com/lunavyqo/chaos-viewer) | Ready (how in try tree only, no wall-clock times, reasoning `max` > `xhigh`) |
| Console + MCP | [lunavyqo/tangOS](https://github.com/lunavyqo/tangOS) (fork; not yet upstream) | Ready: `matchConventions`, draft toggles, Prior tries, log rules |
| EP end-to-end | this repo `tangos.json` + `tools/log_attempt.py` + notes | Ready |

Agents **must call** `log_attempt` (with model/reasoning/harness) for durable provenance —
chat `MATCH_RESULT` paste alone is not enough.

---

## Layer cake (do not invent a parallel spine)

| Layer | SM64DS gold | EP |
|-------|-------------|-----|
| Matched C | `src/` only if MATCH | same |
| Near-miss tip C | `nearmiss/db.jsonl` | same |
| Every try (optional) | — | `config/match_attempts.jsonl` |
| Final how on bank (optional) | — | `config/match_provenance.jsonl` |
| Atlas | `chaos-data` / `chaos_db_ci` | same idea |

---

## Enable on SM64DS (minimal — near-miss only)

SM64DS already has `nearmiss/db.jsonl` and tools. With **lunavyqo/tangOS**, Console
auto-detects near-miss when those files exist. To make it explicit, add under
`project` in `tangos.json`:

```json
"matchConventions": {
  "attemptTree": false,
  "nearMissDb": "nearmiss/db.jsonl",
  "ghidraDrafts": false,
  "defaultProvenance": {
    "model": "grok-4.5",
    "reasoning": "high",
    "harness": "grok-build"
  }
}
```

- **`attemptTree: false`** — keep SM64DS spine only (no try diary required).
- Operators can still toggle near-miss / Ghidra in Console Settings when the
  Console build supports `matchConventions`.

No new Python tools required for this step.

---

## Enable attempt-tree logging (optional, EP-shaped)

Only if you want every try (including `no_progress`) in a reconstructable tree.

1. **Copy tools** from this repo (adapt imports / paths if needed):

   - `tools/match_attempts.py`
   - `tools/log_attempt.py`
   - `tools/match_provenance.py` + bank path if you want final how-records
   - tests: `tools/test_match_attempts.py`

2. **Create** empty `config/match_attempts.jsonl` (and optionally
   `config/match_provenance.jsonl`).

3. **Set** in `tangos.json`:

   ```json
   "matchConventions": {
     "attemptTree": true,
     "attemptsPath": "config/match_attempts.jsonl",
     "provenancePath": "config/match_provenance.jsonl",
     "nearMissDb": "nearmiss/db.jsonl",
     "ghidraDrafts": false,
     "defaultProvenance": {
       "model": "grok-4.5",
       "reasoning": "high",
       "harness": "grok-build"
     }
   }
   ```

4. **Wire tools** in `tangos.json` `tools[]` with full `args` for `log_attempt` /
   `bank` (see this repo’s `tangos.json` — schema is required so MCP agents pass
   model/reasoning/harness correctly).

5. **Rules agents must follow** (also injected by tangOS `next_batch` when
   `attemptTree` is on):

   - `matched` only after verify MATCH  
   - `near_miss` only when the tip improves  
   - same-or-worse score → `no_progress`  
   - no wall-clock times (`loggedAt` / `ts`)  
   - bank is **not** a new try  
   - one session loop = one attempt row  

6. **Docs:** [match-attempts.md](match-attempts.md), [match-provenance.md](match-provenance.md),
   [nearmiss.md](nearmiss.md).

7. **Atlas / viewer:** publish `match_attempts.jsonl` next to `chaos-db.json` on
   `chaos-data` (or main) so Chaos Viewer attempt history can load it.

---

## Chaos Viewer (any decomp)

1. Build / host [lunavyqo/chaos-viewer](https://github.com/lunavyqo/chaos-viewer)
   (or point a fork at it).
2. Load the project’s live `chaos-db.json` URL (SM64DS:
   `…/tangosdev/sm64ds-decomp/chaos-data/chaos-db.json`).
3. Attempt history appears when `match_attempts.jsonl` is published beside the atlas
   or under `config/` on the repo.

---

## tangOS Console

1. Use a build that includes **match conventions** ([lunavyqo/tangOS](https://github.com/lunavyqo/tangOS)
   until merged upstream).
2. Open the decomp repo (descriptor = `tangos.json`).
3. Matching Settings: near-miss / Ghidra toggles.
4. Atlas: Prior tries (metadata only, no C bodies).
5. Connected agents get MATCH LOGGING + SHARED DEFAULTS on `next_batch` when
   `attemptTree` is true.

---

## Suggested path for Tango (SM64DS)

| Step | Change | Risk |
|------|--------|------|
| 1 | Land **lunavyqo/tangOS** match-convention work upstream (or document fork) | Console only |
| 2 | SM64DS PR: explicit `matchConventions` with `attemptTree: false` + `nearMissDb` | Low — docs/descriptor only |
| 3 | Optional later: port attempt-tree tools + `attemptTree: true` | Medium — new experimental surface |
| 4 | Viewer: keep using live chaos-data; optional attempt log URL when step 3 exists | Low |

**Do not** replace `nearmiss/db.jsonl` with attempts-only storage. Tip C stays in the
near-miss DB; the attempt log is metadata history.

---

## Reference implementation (this repo)

| Path | Role |
|------|------|
| `tangos.json` | Full descriptor + tool args for log/bank |
| `tools/log_attempt.py` | Append try nodes |
| `tools/match_attempts.py` | Schema / normalize (no timestamps) |
| `tools/attempt_history_gallery.py` | UI fixture function |
| `notes/match-attempts.md` | Status rules |
| `tools/chaos_db_ci.py` | Atlas (+ optional gallery inject) |

Questions / divergence from SM64DS spine: discuss before making attempt-tree
logging mandatory on SM64DS.

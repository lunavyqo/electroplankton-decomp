# Adopting match conventions (Chaos Viewer + tangOS)

Reference for **other decomps** (especially [sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp))
when wiring Console / the progress atlas to the same rules EP uses.

**This decomp (electroplankton)** is the full experimental reference. SM64DS already has
the matching **spine** (symbols, `src/`, `nearmiss/db.jsonl`, `chaos_db_ci`). Attempt-tree
logging is **optional** and additive — do not replace the near-miss tip store.

**Do not open unsolicited PRs upstream.** Share links / a private fork only when the
maintainer asks.

---

## What is ready today (lunavyqo forks — not assumed upstream)

| Piece | Where | Status |
|-------|--------|--------|
| Progress atlas UI | [lunavyqo/chaos-viewer](https://github.com/lunavyqo/chaos-viewer) | Ready: how only in try tree; no wall-clock times; no redundant matched/best-div chips; reasoning order **max > xhigh > high > …** |
| Console + MCP | [lunavyqo/tangOS](https://github.com/lunavyqo/tangOS) | Ready: `matchConventions`, near-miss/Ghidra toggles, Prior tries, MATCH LOGGING rules, **must call `log_attempt`** with provenance args |
| EP end-to-end | this repo | Ready: `tangos.json` (full tool schemas for log/bank), `tools/log_attempt.py`, attempt gallery fixture, docs |

Agents get SHARED DEFAULTS on `next_batch` when `attemptTree` is on. Durable
provenance requires a **`log_attempt` tool call** (chat-only `MATCH_RESULT` paste is
not enough). `bank` is not a new try.

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

SM64DS already has `nearmiss/db.jsonl`. With a Console build that understands
`matchConventions`, auto-detect may already find the tip store. To make it
explicit, add under `project` in `tangos.json` (on a **personal fork** unless
asked to PR upstream):

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
- No new Python tools required for this step.

---

## Enable attempt-tree logging (optional, EP-shaped)

Only if you want every try (including `no_progress`) in a reconstructable tree.

**These Python tools are required** — `matchConventions` alone does nothing without them.
Console calls `log_attempt` / stamp via `tangos.json` tool entries.

1. **Copy tools** from this repo (adapt paths if needed):

   - `tools/match_attempts.py`
   - `tools/log_attempt.py` (includes draft-flag CLI; wire tip C into `nearmiss/db.jsonl`)
   - `tools/match_provenance.py`
   - **Do not overwrite SM64DS `tools/bank.py`** (fan-out banker). Ship EP bank as
     `tools/stamp_provenance.py` (final how only).
   - tests: `tools/test_match_attempts.py`, `tools/test_match_provenance.py`

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
   `bank` (see this repo’s `tangos.json` — without schemas, agents invent flags and
   skip model/reasoning/harness).

5. **Rules** (also injected by tangOS when `attemptTree` is on):

   - `matched` only after verify MATCH  
   - `near_miss` only when the tip improves  
   - same-or-worse score → `no_progress`  
   - no wall-clock times (`loggedAt` / `ts`)  
   - bank is **not** a new try  
   - one session loop = one attempt row  
   - **call `log_attempt`** after every try  

6. **Docs:** [match-attempts.md](match-attempts.md), [match-provenance.md](match-provenance.md),
   [nearmiss.md](nearmiss.md).

7. **Atlas / viewer:** publish `match_attempts.jsonl` next to `chaos-db.json` on
   `chaos-data` (or main) so Chaos Viewer attempt history can load it.

---

## Chaos Viewer (any decomp)

1. Use [lunavyqo/chaos-viewer](https://github.com/lunavyqo/chaos-viewer) (or merge its
   match-history / privacy UI into your fork).
2. Load the project’s live `chaos-db.json` URL.
3. Attempt history appears when `match_attempts.jsonl` is available beside the atlas
   or under `config/` on the repo.

---

## tangOS Console

1. Use a build with match conventions ([lunavyqo/tangOS](https://github.com/lunavyqo/tangOS)
   until/unless merged elsewhere).
2. Open the decomp (`tangos.json`).
3. Matching Settings: near-miss / Ghidra toggles.
4. Atlas: Prior tries (metadata only).
5. Connected agents: MATCH LOGGING + SHARED DEFAULTS on `next_batch` when
   `attemptTree` is true.

---

## Suggested path (SM64DS / Tango) — only if asked

| Step | Change | Risk |
|------|--------|------|
| 1 | Console build with match-conventions (fork or merge) | Console only |
| 2 | Optional: SM64DS `matchConventions` with `attemptTree: false` + `nearMissDb` | Descriptor only |
| 3 | Optional later: port attempt-tree tools + `attemptTree: true` | Medium — experimental |
| 4 | Viewer: live chaos-data; attempt log URL when step 3 exists | Low |

**Do not** replace `nearmiss/db.jsonl` with attempts-only storage.

---

## Reference implementation (this repo)

| Path | Role |
|------|------|
| `tangos.json` | Full descriptor + tool args for log/bank |
| `tools/log_attempt.py` | Append try nodes (+ draft flags) |
| `tools/match_attempts.py` | Schema / normalize (no timestamps) |
| `tools/attempt_history_gallery.py` | UI fixture function |
| `notes/match-attempts.md` | Status rules |
| `tools/chaos_db_ci.py` | Atlas (+ optional gallery inject) |
| `tools/progress.py --write-readme` | SM64DS-style fenced README bars |

Questions / divergence from SM64DS spine: discuss with the maintainer before making
attempt-tree logging mandatory on SM64DS.


## Ready-made SM64DS fork branch (lunavyqo only)

Full tool port (not upstream):
https://github.com/lunavyqo/sm64ds-decomp/tree/system/match-logging

Includes `log_attempt`, `stamp_provenance`, empty jsonl stores, `matchConventions.attemptTree=true`.

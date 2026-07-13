#!/usr/bin/env python3
"""Append-only log of every matching *attempt* (experimental).

Unlike match_provenance (final how-record on bank) and nearmiss best-draft,
this log keeps **every try** — including no progress, no near-miss improvement,
compile failures, and failed verifies.

Store: config/match_attempts.jsonl  (one JSON object per line, never rewritten)

Record (minimal):
  {
    "ts": "2026-07-13T12:00:00Z",
    "id": "arm9:0x02001a64",
    "module": "arm9",
    "addr": 33561188,
    "name": "func_02001a64",
    "status": "no_progress",   # see STATUSES
    "kind": "ai",              # ai | human
    "model": "grok-4.5",       # required when kind=ai
    "reasoning": "high",
    "harness": "grok-build",
    "author": "lunavyqo",      # optional operator (classic credit identity)
    "divergences": null,       # int if scored
    "prevBestDivergences": 4,  # optional prior best
    "improvedNearMiss": false,
    "srcPath": "scratch/…",    # optional path to attempt C
    "label": "batch-3",        # optional batch / session label
    "sessionScope": "focused", # focused | batch  (required for new records)
    "batchSize": 1,            # how many functions in this matching session
    "note": "optional short note"
  }

sessionScope:
  focused — this session was only about this function (batchSize should be 1)
  batch   — this function was one of several in the same matching session

Do not embed full c_source here (size). Point srcPath or keep drafts elsewhere.
"""
from __future__ import annotations

import json
import pathlib
from datetime import datetime, timezone
from typing import Any, Optional

from match_provenance import (
    ProvenanceError,
    make_id,
    normalize_provenance,
    repo as get_repo,
)

STATUSES = frozenset(
    {
        "matched",
        "near_miss",
        "no_progress",
        "compile_error",
        "failed",
        "skipped",
    }
)

SESSION_SCOPES = frozenset({"focused", "batch"})


def attempts_path() -> pathlib.Path:
    return get_repo() / "config" / "match_attempts.jsonl"


def utc_now_iso() -> str:
    return datetime.now(timezone.utc).replace(microsecond=0).isoformat().replace(
        "+00:00", "Z"
    )


def validate_attempt(rec: dict) -> Optional[str]:
    """Return None if ok, else error string."""
    if not isinstance(rec, dict):
        return "attempt must be an object"
    for req in ("id", "module", "name", "status", "kind"):
        if req not in rec or rec[req] in (None, ""):
            return f"attempt missing {req!r}"
    if rec["status"] not in STATUSES:
        return f"status must be one of {sorted(STATUSES)}, got {rec['status']!r}"
    kind = str(rec["kind"]).strip().lower()
    if kind not in ("ai", "human"):
        return f'kind must be "ai" or "human", got {kind!r}'
    if kind == "ai":
        # Reuse provenance token rules via normalize.
        try:
            normalize_provenance(
                {
                    "kind": "ai",
                    "model": rec.get("model") or "",
                    "reasoning": rec.get("reasoning") or "",
                    "harness": rec.get("harness") or "",
                }
            )
        except ProvenanceError as e:
            return f"ai attempt method invalid: {e}"
    if "addr" in rec and rec["addr"] is not None:
        try:
            int(rec["addr"])
        except (TypeError, ValueError):
            return "addr must be an integer"
    for key in ("divergences", "prevBestDivergences"):
        if key in rec and rec[key] is not None:
            try:
                int(rec[key])
            except (TypeError, ValueError):
                return f"{key} must be int or null"
    if "improvedNearMiss" in rec and rec["improvedNearMiss"] is not None:
        if not isinstance(rec["improvedNearMiss"], bool):
            return "improvedNearMiss must be bool"
    scope = rec.get("sessionScope")
    if scope is not None and str(scope).strip().lower() not in SESSION_SCOPES:
        return f"sessionScope must be focused|batch, got {scope!r}"
    if rec.get("batchSize") is not None:
        try:
            bs = int(rec["batchSize"])
            if bs < 1:
                return "batchSize must be >= 1"
        except (TypeError, ValueError):
            return "batchSize must be int"
    return None


def normalize_attempt(rec: dict) -> dict:
    """Clean + validate. Raises ProvenanceError."""
    out: dict[str, Any] = {
        "ts": rec.get("ts") or utc_now_iso(),
        "id": str(rec["id"]),
        "module": str(rec["module"]),
        "addr": int(rec["addr"]) if rec.get("addr") is not None else None,
        "name": str(rec["name"]),
        "status": str(rec["status"]),
        "kind": str(rec["kind"]).strip().lower(),
    }
    if out["kind"] == "ai":
        how = normalize_provenance(
            {
                "kind": "ai",
                "model": rec.get("model") or "",
                "reasoning": rec.get("reasoning") or "",
                "harness": rec.get("harness") or "",
            }
        )
        out["model"] = how["model"]
        out["reasoning"] = how["reasoning"]
        out["harness"] = how["harness"]
    if rec.get("author"):
        out["author"] = str(rec["author"]).strip()
    for key in ("divergences", "prevBestDivergences"):
        if rec.get(key) is not None:
            out[key] = int(rec[key])
    if "improvedNearMiss" in rec and rec["improvedNearMiss"] is not None:
        out["improvedNearMiss"] = bool(rec["improvedNearMiss"])
    elif (
        out.get("divergences") is not None
        and out.get("prevBestDivergences") is not None
    ):
        out["improvedNearMiss"] = int(out["divergences"]) < int(
            out["prevBestDivergences"]
        )
    else:
        out["improvedNearMiss"] = False
    if rec.get("srcPath"):
        out["srcPath"] = str(rec["srcPath"])
    if rec.get("label"):
        out["label"] = str(rec["label"]).strip()
    if rec.get("note"):
        out["note"] = str(rec["note"]).strip()

    # Session focus: focused (solo) vs batch (multi-function context).
    # Infer when missing: batchSize==1 → focused, batchSize>1 → batch.
    scope_raw = rec.get("sessionScope")
    batch_size = rec.get("batchSize")
    if batch_size is not None:
        batch_size = int(batch_size)
    if scope_raw is not None and str(scope_raw).strip():
        scope = str(scope_raw).strip().lower()
    elif batch_size is not None:
        scope = "focused" if batch_size <= 1 else "batch"
    else:
        # Legacy rows without the field: leave unset after validate? Prefer require
        # for new writes via append_attempt default.
        scope = None
    if scope is not None:
        if scope not in SESSION_SCOPES:
            raise ProvenanceError(f"sessionScope must be focused|batch, got {scope!r}")
        out["sessionScope"] = scope
        if batch_size is None:
            batch_size = 1 if scope == "focused" else batch_size
        if scope == "focused" and batch_size is None:
            batch_size = 1
        if scope == "focused" and batch_size is not None and batch_size != 1:
            # Focused means solo context; coerce size to 1 with note-friendly consistency.
            batch_size = 1
        if scope == "batch" and (batch_size is None or batch_size < 2):
            raise ProvenanceError(
                "sessionScope=batch requires batchSize >= 2 "
                "(or use sessionScope=focused for a single-function session)"
            )
    if batch_size is not None:
        out["batchSize"] = int(batch_size)

    err = validate_attempt(out)
    if err:
        raise ProvenanceError(err)
    return out


def append_attempt(
    *,
    module: str,
    addr: int,
    name: str,
    status: str,
    kind: str = "ai",
    model: Optional[str] = None,
    reasoning: Optional[str] = None,
    harness: Optional[str] = None,
    author: Optional[str] = None,
    divergences: Optional[int] = None,
    prev_best_divergences: Optional[int] = None,
    improved_near_miss: Optional[bool] = None,
    src_path: Optional[str] = None,
    label: Optional[str] = None,
    note: Optional[str] = None,
    session_scope: Optional[str] = None,
    batch_size: Optional[int] = None,
    ts: Optional[str] = None,
    path: Optional[pathlib.Path] = None,
) -> dict:
    """Append one attempt. Always records — including no_progress. Raises ProvenanceError."""
    rid = make_id(module, addr)
    rec: dict[str, Any] = {
        "ts": ts or utc_now_iso(),
        "id": rid,
        "module": module,
        "addr": int(addr),
        "name": name,
        "status": status,
        "kind": kind,
    }
    if kind == "ai":
        rec["model"] = model or ""
        rec["reasoning"] = reasoning or ""
        rec["harness"] = harness or ""
    if author:
        rec["author"] = author
    if divergences is not None:
        rec["divergences"] = divergences
    if prev_best_divergences is not None:
        rec["prevBestDivergences"] = prev_best_divergences
    if improved_near_miss is not None:
        rec["improvedNearMiss"] = improved_near_miss
    if src_path:
        rec["srcPath"] = src_path
    if label:
        rec["label"] = label
    if note:
        rec["note"] = note
    # Default new writes to focused if unspecified (safer than guessing multi).
    if session_scope is not None:
        rec["sessionScope"] = session_scope
    elif batch_size is not None:
        rec["sessionScope"] = "focused" if int(batch_size) <= 1 else "batch"
    else:
        rec["sessionScope"] = "focused"
        rec["batchSize"] = 1
    if batch_size is not None:
        rec["batchSize"] = batch_size
    elif rec.get("sessionScope") == "focused":
        rec["batchSize"] = 1
    clean = normalize_attempt(rec)
    out = path or attempts_path()
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open("a", encoding="utf-8") as f:
        f.write(json.dumps(clean, separators=(",", ":"), ensure_ascii=False) + "\n")
    return clean


def load_attempts(
    path: Optional[pathlib.Path] = None,
    *,
    function_id: Optional[str] = None,
) -> list[dict]:
    """Load all attempts (optionally filter by function id). Order = file order."""
    path = path or attempts_path()
    if not path.is_file():
        return []
    rows: list[dict] = []
    for line_no, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError as e:
            raise ProvenanceError(f"{path}:{line_no}: invalid JSON: {e}") from e
        if function_id and row.get("id") != function_id:
            continue
        rows.append(row)
    return rows


def attempt_stats(rows: list[dict]) -> dict[str, Any]:
    """Aggregate counts for a list of attempt rows."""
    by_status: dict[str, int] = {}
    by_scope: dict[str, int] = {}
    improved = 0
    matched_focused = 0
    matched_batch = 0
    for r in rows:
        s = r.get("status") or "?"
        by_status[s] = by_status.get(s, 0) + 1
        scope = r.get("sessionScope") or "unknown"
        by_scope[scope] = by_scope.get(scope, 0) + 1
        if r.get("improvedNearMiss"):
            improved += 1
        if r.get("status") == "matched":
            if scope == "focused":
                matched_focused += 1
            elif scope == "batch":
                matched_batch += 1
    return {
        "total": len(rows),
        "byStatus": by_status,
        "bySessionScope": by_scope,
        "improvedNearMiss": improved,
        "matchedFocused": matched_focused,
        "matchedBatch": matched_batch,
    }

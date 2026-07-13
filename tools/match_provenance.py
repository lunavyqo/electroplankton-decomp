#!/usr/bin/env python3
"""Match provenance: validation + durable ledger for experimental atlas tracking.

Canonical per-match record (stored in config/match_provenance.jsonl, re-emitted
as matchProvenance on matched functions in chaos-db.json):

  human:  {"kind":"human", "by"?: str, "note"?: str}
  ai:     {"kind":"ai", "model": str, "reasoning": str, "harness": str, "by"?: str}

AI records require non-empty model, reasoning, and harness. Incomplete AI
provenance is a bug — bank() must refuse to complete.

Token form (after normalize):
  - spaces → hyphens
  - model / reasoning / harness lowercased for stable ids
  - GOOD: grok-4.5, claude-opus-4, grok-build
  - BAD (pre-normalize): "Grok 4.5", "Grok Build"  — accepted, then slugified

Repo root discovery (does not rely only on __file__):
  1. --repo / DECOMP_ROOT / MATCH_REPO
  2. walk up from cwd for markers (tools/match.py + config/)
  3. walk up from this file's directory
"""
from __future__ import annotations

import json
import os
import pathlib
import re
from typing import Any, Optional

# Module-level defaults; call configure(repo) before banking if scripts live outside the tree.
_REPO: Optional[pathlib.Path] = None
_LEDGER: Optional[pathlib.Path] = None

KINDS = frozenset({"human", "ai"})
# Stable short tokens after normalize (no spaces).
HARNESS_RE = re.compile(r"^[a-z0-9][a-z0-9._/-]{0,63}$")
MODEL_RE = re.compile(r"^[a-z0-9][a-z0-9._+/-]{0,127}$")
REASONING_RE = re.compile(r"^[a-z0-9][a-z0-9._+/-]{0,63}$")

TOKEN_HELP = (
    "use slug tokens (no spaces): model=grok-4.5 reasoning=high harness=grok-build "
    "(display names like 'Grok 4.5' are auto-slugified)"
)


class ProvenanceError(ValueError):
    """Invalid or incomplete match provenance."""


def is_repo_root(path: pathlib.Path) -> bool:
    """True if path looks like electroplankton-decomp (or sibling layout)."""
    p = path
    return (p / "tools" / "match.py").is_file() and (p / "config").is_dir()


def resolve_repo(explicit: Optional[pathlib.Path | str] = None) -> pathlib.Path:
    """Find decomp root. Prefer explicit / env / cwd walk / __file__ walk."""
    candidates: list[pathlib.Path] = []
    tried: list[str] = []

    def consider(label: str, p: Optional[pathlib.Path]) -> Optional[pathlib.Path]:
        if p is None:
            return None
        try:
            r = p.expanduser().resolve()
        except OSError:
            tried.append(f"{label}: {p} (unresolvable)")
            return None
        tried.append(f"{label}: {r}")
        if is_repo_root(r):
            return r
        return None

    if explicit is not None:
        hit = consider("--repo/explicit", pathlib.Path(explicit))
        if hit:
            return hit
        raise SystemExit(
            f"ERROR: not a decomp root: {explicit}\n"
            f"Expected tools/match.py and config/ under that path.\n"
            f"Tried:\n  " + "\n  ".join(tried)
        )

    for key in ("DECOMP_ROOT", "MATCH_REPO"):
        env = os.environ.get(key)
        if env:
            hit = consider(f"env {key}", pathlib.Path(env))
            if hit:
                return hit

    cwd = pathlib.Path.cwd()
    for cand in [cwd, *cwd.resolve().parents]:
        hit = consider("cwd-walk", cand)
        if hit:
            return hit

    here = pathlib.Path(__file__).resolve().parent  # …/tools or /tmp/…
    for cand in [here, *here.parents]:
        hit = consider("__file__-walk", cand)
        if hit:
            return hit

    raise SystemExit(
        "ERROR: could not find decomp repository root.\n"
        "Pass --repo /path/to/electroplankton-decomp or set DECOMP_ROOT.\n"
        "Markers: tools/match.py + config/\n"
        "Tried:\n  " + "\n  ".join(tried[-12:])
    )


def configure(repo: Optional[pathlib.Path | str] = None) -> pathlib.Path:
    """Set module-level REPO / LEDGER. Returns resolved repo path."""
    global _REPO, _LEDGER
    root = resolve_repo(repo)
    _REPO = root
    _LEDGER = root / "config" / "match_provenance.jsonl"
    return root


def repo() -> pathlib.Path:
    if _REPO is None:
        configure()
    assert _REPO is not None
    return _REPO


def ledger_path() -> pathlib.Path:
    if _LEDGER is None:
        configure()
    assert _LEDGER is not None
    return _LEDGER


# Back-compat names used by older imports / docs.
def _lazy_repo() -> pathlib.Path:
    return repo()


def _lazy_ledger() -> pathlib.Path:
    return ledger_path()


# Property-like module attributes for `from match_provenance import REPO` won't
# work as Path objects; bank.py should call configure() and use repo().


def make_id(module: str, addr: int) -> str:
    return f"{module}:0x{addr:08x}"


def slugify_token(value: str, *, field: str) -> str:
    """Turn display names into stable tokens.

    'Grok 4.5' → 'grok-4.5', 'Grok Build' → 'grok-build'
    """
    s = value.strip()
    s = re.sub(r"\s+", "-", s)
    s = s.lower()
    # collapse duplicate hyphens
    while "--" in s:
        s = s.replace("--", "-")
    s = s.strip("-._/")
    if not s:
        raise ProvenanceError(f"ai.{field} empty after normalize")
    return s


def suggest_token(value: str) -> str:
    try:
        return slugify_token(value, field="?")
    except ProvenanceError:
        return "<empty>"


def validate_match_provenance(rec: Any) -> Optional[str]:
    """Return None if ok, else a short error string.

    Accepts the inner matchProvenance object (not the full ledger row).
    Does not normalize — call normalize_provenance for that.
    """
    if rec is None:
        return "matchProvenance is null/missing"
    if not isinstance(rec, dict):
        return "matchProvenance must be an object"
    kind = rec.get("kind")
    if kind not in KINDS:
        return f'kind must be "human" or "ai", got {kind!r}'

    if kind == "human":
        for k, v in rec.items():
            if k == "kind":
                continue
            if k not in ("by", "note"):
                return f"human provenance unknown field: {k!r}"
            if v is not None and not isinstance(v, str):
                return f"human.{k} must be a string"
            if isinstance(v, str) and not v.strip() and k == "by":
                return "human.by must be non-empty when present"
        return None

    for req in ("model", "reasoning", "harness"):
        v = rec.get(req)
        if not isinstance(v, str) or not v.strip():
            return f"ai provenance requires non-empty string {req!r} ({TOKEN_HELP})"
    model = rec["model"].strip()
    reasoning = rec["reasoning"].strip()
    harness = rec["harness"].strip()
    if not MODEL_RE.match(model):
        sug = suggest_token(model)
        return (
            f"ai.model invalid token: {model!r} "
            f"(try {sug!r}; {TOKEN_HELP})"
        )
    if not REASONING_RE.match(reasoning):
        sug = suggest_token(reasoning)
        return f"ai.reasoning invalid token: {reasoning!r} (try {sug!r})"
    if not HARNESS_RE.match(harness):
        sug = suggest_token(harness)
        return (
            f"ai.harness invalid token: {harness!r} "
            f"(try {sug!r}; lowercase slug, no spaces)"
        )
    if "by" in rec and rec["by"] is not None:
        if not isinstance(rec["by"], str) or not rec["by"].strip():
            return "ai.by must be a non-empty string when present"
    for k in rec:
        if k not in ("kind", "model", "reasoning", "harness", "by"):
            return f"ai provenance unknown field: {k!r}"
    return None


def normalize_provenance(rec: dict) -> dict:
    """Slugify AI tokens, then validate. Raises ProvenanceError."""
    if not isinstance(rec, dict):
        raise ProvenanceError("matchProvenance must be an object")
    kind = (rec.get("kind") or "").strip().lower()
    if kind == "human":
        out: dict[str, Any] = {"kind": "human"}
        if rec.get("by"):
            out["by"] = str(rec["by"]).strip()
        if rec.get("note"):
            out["note"] = str(rec["note"]).strip()
        err = validate_match_provenance(out)
        if err:
            raise ProvenanceError(err)
        return out
    if kind == "ai":
        try:
            out = {
                "kind": "ai",
                "model": slugify_token(str(rec.get("model") or ""), field="model"),
                "reasoning": slugify_token(
                    str(rec.get("reasoning") or ""), field="reasoning"
                ),
                "harness": slugify_token(str(rec.get("harness") or ""), field="harness"),
            }
        except ProvenanceError:
            raise
        if rec.get("by"):
            out["by"] = str(rec["by"]).strip()
        err = validate_match_provenance(out)
        if err:
            raise ProvenanceError(err)
        return out
    raise ProvenanceError(f'kind must be "human" or "ai", got {rec.get("kind")!r}')


def load_ledger(path: Optional[pathlib.Path] = None) -> dict[str, dict]:
    """Load provenance ledger keyed by id (module:0xaddr). Last write wins."""
    path = path or ledger_path()
    by_id: dict[str, dict] = {}
    if not path.is_file():
        return by_id
    for line_no, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError as e:
            raise ProvenanceError(f"{path}:{line_no}: invalid JSON: {e}") from e
        rid = row.get("id")
        if not rid and "module" in row and "addr" in row:
            addr = row["addr"]
            if isinstance(addr, str):
                addr = int(addr, 0)
            rid = make_id(str(row["module"]), int(addr))
        if not rid:
            raise ProvenanceError(f"{path}:{line_no}: row needs id or module+addr")
        prov = row.get("matchProvenance") or row.get("provenance")
        if prov is None:
            raise ProvenanceError(f"{path}:{line_no}: missing matchProvenance")
        # Normalize so older display-name rows still load if slugifiable.
        try:
            clean = normalize_provenance(prov)
        except ProvenanceError as e:
            raise ProvenanceError(f"{path}:{line_no}: {e}") from e
        by_id[str(rid)] = {
            "id": str(rid),
            "module": row.get("module"),
            "addr": row.get("addr"),
            "name": row.get("name"),
            "srcPath": row.get("srcPath"),
            "matchProvenance": clean,
        }
    return by_id


def lookup_provenance(
    module: str,
    addr: int,
    ledger: Optional[dict[str, dict]] = None,
) -> Optional[dict]:
    """Return matchProvenance dict for (module, addr), or None."""
    if ledger is None:
        ledger = load_ledger()
    row = ledger.get(make_id(module, addr))
    if not row:
        return None
    return row.get("matchProvenance")


def append_ledger_row(
    *,
    module: str,
    addr: int,
    name: str,
    provenance: dict,
    src_path: Optional[str] = None,
    path: Optional[pathlib.Path] = None,
) -> dict:
    """Validate, append one JSONL row, return the row. Raises ProvenanceError."""
    path = path or ledger_path()
    prov = normalize_provenance(provenance)
    rid = make_id(module, addr)
    row = {
        "id": rid,
        "module": module,
        "addr": int(addr),
        "name": name,
        "matchProvenance": prov,
    }
    if src_path:
        row["srcPath"] = src_path
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as f:
        f.write(json.dumps(row, separators=(",", ":"), ensure_ascii=False) + "\n")
    return row


def provenance_from_cli_args(
    *,
    kind: str,
    model: Optional[str] = None,
    reasoning: Optional[str] = None,
    harness: Optional[str] = None,
    by: Optional[str] = None,
    note: Optional[str] = None,
) -> dict:
    """Build a provenance object from CLI-style fields. Raises ProvenanceError."""
    kind = (kind or "").strip().lower()
    if kind == "human":
        rec: dict[str, Any] = {"kind": "human"}
        if by:
            rec["by"] = by
        if note:
            rec["note"] = note
        return normalize_provenance(rec)
    if kind == "ai":
        rec = {
            "kind": "ai",
            "model": model or "",
            "reasoning": reasoning or "",
            "harness": harness or "",
        }
        if by:
            rec["by"] = by
        return normalize_provenance(rec)
    raise ProvenanceError(f'kind must be "human" or "ai", got {kind!r}')

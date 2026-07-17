#!/usr/bin/env python3
"""Synthetic attempt-history gallery for UI / schema coverage.

One fake function (`func_attempt_history_gallery`) with a fixed attempt tree that
hits every status, base.kind, draft flag, and common tree shape the viewer
renders. Not a real ROM function — atlas inject only.

  functionId = demo:0x0
  name       = func_attempt_history_gallery

Usage:
  python tools/attempt_history_gallery.py              # print JSONL to stdout
  python tools/attempt_history_gallery.py --sync       # upsert into config/match_attempts.jsonl
"""
from __future__ import annotations

import argparse
import json
import pathlib
import sys
from typing import Any

_TOOLS = pathlib.Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from match_attempts import normalize_attempt  # noqa: E402
from match_provenance import configure  # noqa: E402

# Stable identity — must match chaos_db_ci inject + attempt log filter.
GALLERY_MODULE = "demo"
GALLERY_ADDR = 0
GALLERY_NAME = "func_attempt_history_gallery"
GALLERY_FUNCTION_ID = "demo:0x0"
GALLERY_SIZE = 64  # fake size for atlas row only

# Fixed 32-char hex attemptIds (stable across regenerations; never a1/try2).
def _aid(n: int) -> str:
    return f"a11e1115ca1e00000000000000{n:04x}"


# ---------------------------------------------------------------------------
# Tree (comments show parent links):
#
#   a001  near_miss div=40   root  base=scratch            [ai focused]
#   ├─ a002  no_progress                                  [dead-end sibling]
#   ├─ a003  compile_error
#   ├─ a004  failed
#   └─ a005  near_miss div=12 improved  usedNearMiss
#      ├─ a006  near_miss div=12  NOT improved             [dead-end tip]
#      └─ a007  near_miss div=4 improved  usedGhidra+nm
#         └─ a008  matched                                [ai batch]
#
#   a009  skipped  root  base=matched_sibling             [human focused]
#   a010  no_progress  root  base=near_miss_draft         [ai batch]
# ---------------------------------------------------------------------------

def gallery_rows() -> list[dict[str, Any]]:
    """Return normalized attempt rows for the gallery function (no wall-clock)."""
    A = _aid

    def base_row(**kw: Any) -> dict[str, Any]:
        rec: dict[str, Any] = {
            "schemaVersion": 1,
            "functionId": GALLERY_FUNCTION_ID,
            "id": GALLERY_FUNCTION_ID,
            "module": GALLERY_MODULE,
            "addr": GALLERY_ADDR,
            "name": GALLERY_NAME,
            "author": "lunavyqo",
            **kw,
        }
        return normalize_attempt(rec)

    rows = [
        # Root: first scratch near-miss
        base_row(
            attemptId=A(1),
            parentAttemptId=None,
            status="near_miss",
            kind="ai",
            model="grok-4.5",
            reasoning="high",
            harness="grok-build",
            sessionScope="focused",
            batchSize=1,
            base={"kind": "scratch"},
            divergences=40,
            prevBestDivergences=None,
            improvedNearMiss=False,
            usedNearMissDraft=False,
            usedGhidraDraft=False,
            srcPath="scratch/gallery/a001.c",
            note="gallery: root scratch near-miss",
            label="gallery-root-scratch",
        ),
        # Dead-end siblings under root
        base_row(
            attemptId=A(2),
            parentAttemptId=A(1),
            status="no_progress",
            kind="ai",
            model="grok-4.5",
            reasoning="high",
            harness="grok-build",
            sessionScope="focused",
            batchSize=1,
            base={"kind": "previous_attempt", "attemptId": A(1)},
            divergences=None,
            prevBestDivergences=40,
            improvedNearMiss=False,
            usedNearMissDraft=False,
            usedGhidraDraft=False,
            note="gallery: no_progress dead-end",
        ),
        base_row(
            attemptId=A(3),
            parentAttemptId=A(1),
            status="compile_error",
            kind="ai",
            model="grok-4.5",
            reasoning="high",
            harness="grok-build",
            sessionScope="focused",
            batchSize=1,
            base={"kind": "previous_attempt", "attemptId": A(1)},
            improvedNearMiss=False,
            usedNearMissDraft=False,
            usedGhidraDraft=False,
            note="gallery: compile_error",
        ),
        base_row(
            attemptId=A(4),
            parentAttemptId=A(1),
            status="failed",
            kind="ai",
            model="claude-sonnet-5",
            reasoning="medium",
            harness="cursor-agent",
            sessionScope="focused",
            batchSize=1,
            base={"kind": "previous_attempt", "attemptId": A(1)},
            improvedNearMiss=False,
            usedNearMissDraft=False,
            usedGhidraDraft=False,
            note="gallery: failed verify",
        ),
        # Improved branch
        base_row(
            attemptId=A(5),
            parentAttemptId=A(1),
            status="near_miss",
            kind="ai",
            model="grok-4.5",
            reasoning="high",
            harness="grok-build",
            sessionScope="focused",
            batchSize=1,
            base={"kind": "previous_attempt", "attemptId": A(1), "divergences": 40},
            divergences=12,
            prevBestDivergences=40,
            improvedNearMiss=True,
            usedNearMissDraft=True,
            usedGhidraDraft=False,
            srcPath="scratch/gallery/a005.c",
            note="gallery: improved near-miss + usedNearMissDraft",
        ),
        # Non-improving tip under improved node
        base_row(
            attemptId=A(6),
            parentAttemptId=A(5),
            status="near_miss",
            kind="ai",
            model="grok-4.5",
            reasoning="xhigh",
            harness="grok-build",
            sessionScope="focused",
            batchSize=1,
            base={"kind": "near_miss_draft", "attemptId": A(5), "divergences": 12},
            divergences=12,
            prevBestDivergences=12,
            improvedNearMiss=False,
            usedNearMissDraft=True,
            usedGhidraDraft=False,
            note="gallery: near_miss no improvement",
        ),
        # Ghidra + near-miss lineage
        base_row(
            attemptId=A(7),
            parentAttemptId=A(5),
            status="near_miss",
            kind="ai",
            model="grok-4.5",
            reasoning="high",
            harness="grok-build",
            sessionScope="focused",
            batchSize=1,
            base={"kind": "near_miss_draft", "attemptId": A(5), "divergences": 12},
            divergences=4,
            prevBestDivergences=12,
            improvedNearMiss=True,
            usedNearMissDraft=True,
            usedGhidraDraft=True,
            srcPath="scratch/gallery/a007.c",
            note="gallery: improved + usedGhidraDraft + usedNearMissDraft",
        ),
        # Match leaf (batch scope example)
        base_row(
            attemptId=A(8),
            parentAttemptId=A(7),
            status="matched",
            kind="ai",
            model="grok-4.5",
            reasoning="high",
            harness="grok-build",
            sessionScope="batch",
            batchSize=8,
            base={"kind": "previous_attempt", "attemptId": A(7)},
            divergences=0,
            prevBestDivergences=4,
            improvedNearMiss=True,
            usedNearMissDraft=True,
            usedGhidraDraft=True,
            srcPath="src/demo/func_attempt_history_gallery.c",
            note="gallery: matched leaf (batch scope)",
        ),
        # Second root: human skipped from matched sibling scaffold
        base_row(
            attemptId=A(9),
            parentAttemptId=None,
            status="skipped",
            kind="human",
            sessionScope="focused",
            batchSize=1,
            base={"kind": "matched_sibling"},
            improvedNearMiss=False,
            usedNearMissDraft=False,
            usedGhidraDraft=False,
            note="gallery: second root — human skipped",
        ),
        # Third root: batch no_progress from near_miss_draft
        base_row(
            attemptId=A(10),
            parentAttemptId=None,
            status="no_progress",
            kind="ai",
            model="composer-2.5",
            reasoning="low",
            harness="manual",
            sessionScope="batch",
            batchSize=4,
            base={"kind": "near_miss_draft"},
            improvedNearMiss=False,
            usedNearMissDraft=True,
            usedGhidraDraft=False,
            note="gallery: third root — batch no_progress",
        ),
    ]
    return rows


def gallery_function_record() -> dict[str, Any]:
    """Synthetic atlas row for chaos_db_ci inject (unmatched, near-miss badge)."""
    return {
        "id": GALLERY_FUNCTION_ID,
        "module": GALLERY_MODULE,
        "name": GALLERY_NAME,
        "addr": GALLERY_ADDR,
        "size": GALLERY_SIZE,
        "matched": False,
        "div": 4,  # tip from gallery tree
        "cat": "fixture",
        "author": "lunavyqo",
    }


def expected_coverage() -> dict[str, set[str]]:
    """Sets the unit test asserts are present in the gallery."""
    return {
        "statuses": {
            "matched",
            "near_miss",
            "no_progress",
            "compile_error",
            "failed",
            "skipped",
        },
        "base_kinds": {
            "scratch",
            "previous_attempt",
            "near_miss_draft",
            "matched_sibling",
        },
        "kinds": {"ai", "human"},
        "session_scopes": {"focused", "batch"},
    }


def sync_into_attempts(path: pathlib.Path) -> tuple[int, int]:
    """Replace any prior gallery rows, append current gallery. Returns (removed, added)."""
    existing: list[dict[str, Any]] = []
    if path.is_file():
        for line in path.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            try:
                r = json.loads(line)
            except json.JSONDecodeError:
                continue
            fid = r.get("functionId") or r.get("id")
            name = r.get("name")
            if fid == GALLERY_FUNCTION_ID or name == GALLERY_NAME:
                continue
            existing.append(r)

    gallery = gallery_rows()
    out_lines = [
        json.dumps(r, separators=(",", ":"), ensure_ascii=False) for r in existing
    ]
    out_lines += [
        json.dumps(r, separators=(",", ":"), ensure_ascii=False) for r in gallery
    ]
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(out_lines) + ("\n" if out_lines else ""), encoding="utf-8")
    removed = 0  # not tracked precisely; caller can diff
    return (removed, len(gallery))


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument(
        "--sync",
        action="store_true",
        help="Upsert gallery rows into config/match_attempts.jsonl",
    )
    ap.add_argument("--repo", type=pathlib.Path, default=None)
    args = ap.parse_args()
    repo = configure(args.repo)
    rows = gallery_rows()
    if args.sync:
        path = repo / "config" / "match_attempts.jsonl"
        # count prior gallery
        prior = 0
        if path.is_file():
            for line in path.read_text(encoding="utf-8").splitlines():
                if not line.strip():
                    continue
                try:
                    r = json.loads(line)
                except json.JSONDecodeError:
                    continue
                if (r.get("functionId") or r.get("id")) == GALLERY_FUNCTION_ID:
                    prior += 1
        sync_into_attempts(path)
        print(
            f"synced {len(rows)} gallery rows into {path} "
            f"(replaced {prior} prior gallery rows)",
            file=sys.stderr,
        )
    else:
        for r in rows:
            print(json.dumps(r, separators=(",", ":"), ensure_ascii=False))


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Tests for match attempt log (every try, including no progress)."""
from __future__ import annotations

import pathlib
import sys
import tempfile
import unittest

TOOLS = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))

from match_attempts import (  # noqa: E402
    append_attempt,
    attempt_stats,
    load_attempts,
    normalize_attempt,
)
from match_provenance import ProvenanceError, configure  # noqa: E402


class AttemptNormalize(unittest.TestCase):
    def test_no_progress_ai(self):
        r = normalize_attempt(
            {
                "id": "arm9:0x02000000",
                "module": "arm9",
                "addr": 0x2000000,
                "name": "func_02000000",
                "status": "no_progress",
                "kind": "ai",
                "model": "Grok 4.5",
                "reasoning": "high",
                "harness": "Grok Build",
                "sessionScope": "focused",
                "batchSize": 1,
            }
        )
        self.assertEqual(r["status"], "no_progress")
        self.assertEqual(r["model"], "grok-4.5")
        self.assertEqual(r["harness"], "grok-build")
        self.assertFalse(r["improvedNearMiss"])
        self.assertEqual(r["sessionScope"], "focused")
        self.assertEqual(r["batchSize"], 1)

    def test_batch_scope(self):
        r = normalize_attempt(
            {
                "id": "arm9:0x1",
                "module": "arm9",
                "addr": 1,
                "name": "f",
                "status": "matched",
                "kind": "human",
                "sessionScope": "batch",
                "batchSize": 8,
            }
        )
        self.assertEqual(r["sessionScope"], "batch")
        self.assertEqual(r["batchSize"], 8)

    def test_batch_requires_size(self):
        with self.assertRaises(ProvenanceError):
            normalize_attempt(
                {
                    "id": "arm9:0x1",
                    "module": "arm9",
                    "addr": 1,
                    "name": "f",
                    "status": "no_progress",
                    "kind": "human",
                    "sessionScope": "batch",
                    "batchSize": 1,
                }
            )

    def test_improved_near_miss_inferred(self):
        r = normalize_attempt(
            {
                "id": "arm9:0x1",
                "module": "arm9",
                "addr": 1,
                "name": "f",
                "status": "near_miss",
                "kind": "human",
                "sessionScope": "focused",
                "batchSize": 1,
                "divergences": 2,
                "prevBestDivergences": 5,
            }
        )
        self.assertTrue(r["improvedNearMiss"])

    def test_not_improved(self):
        r = normalize_attempt(
            {
                "id": "arm9:0x1",
                "module": "arm9",
                "addr": 1,
                "name": "f",
                "status": "near_miss",
                "kind": "ai",
                "model": "x",
                "reasoning": "low",
                "harness": "h",
                "sessionScope": "focused",
                "batchSize": 1,
                "divergences": 8,
                "prevBestDivergences": 3,
            }
        )
        self.assertFalse(r["improvedNearMiss"])

    def test_ai_requires_method(self):
        with self.assertRaises(ProvenanceError):
            normalize_attempt(
                {
                    "id": "arm9:0x1",
                    "module": "arm9",
                    "addr": 1,
                    "name": "f",
                    "status": "failed",
                    "kind": "ai",
                    "model": "x",
                    "sessionScope": "focused",
                    "batchSize": 1,
                    # missing reasoning/harness
                }
            )

    def test_session_scope_required(self):
        with self.assertRaises(ProvenanceError):
            normalize_attempt(
                {
                    "id": "arm9:0x1",
                    "module": "arm9",
                    "addr": 1,
                    "name": "f",
                    "status": "no_progress",
                    "kind": "human",
                    # missing sessionScope
                }
            )


class AttemptLog(unittest.TestCase):
    def test_append_every_try(self):
        with tempfile.TemporaryDirectory() as td:
            path = pathlib.Path(td) / "attempts.jsonl"
            append_attempt(
                module="arm9",
                addr=0x200,
                name="foo",
                status="no_progress",
                kind="ai",
                model="m",
                reasoning="high",
                harness="h",
                session_scope="batch",
                batch_size=4,
                path=path,
            )
            append_attempt(
                module="arm9",
                addr=0x200,
                name="foo",
                status="near_miss",
                kind="ai",
                model="m",
                reasoning="high",
                harness="h",
                divergences=4,
                prev_best_divergences=4,
                session_scope="focused",
                path=path,
            )
            append_attempt(
                module="arm9",
                addr=0x200,
                name="foo",
                status="matched",
                kind="ai",
                model="m",
                reasoning="high",
                harness="h",
                author="alice",
                session_scope="focused",
                path=path,
            )
            rows = load_attempts(path)
            self.assertEqual(len(rows), 3)
            self.assertEqual(rows[0]["status"], "no_progress")
            self.assertEqual(rows[0]["sessionScope"], "batch")
            self.assertEqual(rows[2]["status"], "matched")
            self.assertEqual(rows[2]["sessionScope"], "focused")
            st = attempt_stats(rows)
            self.assertEqual(st["total"], 3)
            self.assertEqual(st["byStatus"]["no_progress"], 1)
            self.assertEqual(st["matchedFocused"], 1)
            self.assertEqual(st["bySessionScope"]["batch"], 1)


if __name__ == "__main__":
    # Ensure configure works when run from repo
    configure(TOOLS.parent)
    unittest.main()

#!/usr/bin/env python3
"""Tests for the synthetic attempt-history gallery fixture."""
from __future__ import annotations

import pathlib
import sys
import unittest

TOOLS = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))

from attempt_history_gallery import (  # noqa: E402
    GALLERY_FUNCTION_ID,
    GALLERY_NAME,
    expected_coverage,
    gallery_function_record,
    gallery_rows,
)
from match_attempts import BASE_KINDS, STATUSES, validate_attempt  # noqa: E402


class AttemptHistoryGallery(unittest.TestCase):
    def test_all_rows_validate(self):
        rows = gallery_rows()
        self.assertGreaterEqual(len(rows), 10)
        for r in rows:
            err = validate_attempt(r)
            self.assertIsNone(err, msg=f"{r.get('attemptId')}: {err}")
            self.assertEqual(r["functionId"], GALLERY_FUNCTION_ID)
            self.assertEqual(r["name"], GALLERY_NAME)
            self.assertNotIn("loggedAt", r)
            self.assertNotIn("ts", r)

    def test_covers_every_status_and_base(self):
        rows = gallery_rows()
        cov = expected_coverage()
        statuses = {r["status"] for r in rows}
        bases = {r.get("base", {}).get("kind") for r in rows}
        kinds = {r["kind"] for r in rows}
        scopes = {r["sessionScope"] for r in rows}

        self.assertEqual(statuses, cov["statuses"])
        self.assertEqual(bases, cov["base_kinds"])
        self.assertEqual(kinds, cov["kinds"])
        self.assertEqual(scopes, cov["session_scopes"])

        # Schema enums still match gallery sets (no drift).
        self.assertTrue(cov["statuses"] <= STATUSES)
        self.assertTrue(cov["base_kinds"] <= BASE_KINDS)

    def test_tree_links(self):
        rows = gallery_rows()
        by_id = {r["attemptId"]: r for r in rows}
        self.assertEqual(len(by_id), len(rows), "attemptIds must be unique")

        roots = [r for r in rows if not r.get("parentAttemptId")]
        self.assertGreaterEqual(len(roots), 2, "need multiple roots for gallery")

        children = [r for r in rows if r.get("parentAttemptId")]
        self.assertTrue(children)
        for r in children:
            parent = r["parentAttemptId"]
            self.assertIn(parent, by_id, f"orphan parent {parent}")

        # Matched leaf has a parent (not only a banked root).
        matched = [r for r in rows if r["status"] == "matched"]
        self.assertEqual(len(matched), 1)
        self.assertIsNotNone(matched[0].get("parentAttemptId"))

        # Improved near-miss appears
        improved = [r for r in rows if r.get("improvedNearMiss")]
        self.assertTrue(improved)

        # Draft flags appear
        self.assertTrue(any(r.get("usedNearMissDraft") for r in rows))
        self.assertTrue(any(r.get("usedGhidraDraft") for r in rows))
        self.assertTrue(any(r.get("kind") == "human" for r in rows))

    def test_atlas_record(self):
        fn = gallery_function_record()
        self.assertEqual(fn["id"], GALLERY_FUNCTION_ID)
        self.assertEqual(fn["name"], GALLERY_NAME)
        self.assertFalse(fn["matched"])
        self.assertIn("div", fn)


if __name__ == "__main__":
    unittest.main()

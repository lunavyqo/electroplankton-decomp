#!/usr/bin/env python3
"""Tests for nearmiss/db.jsonl tip store (full C of best near-miss)."""
from __future__ import annotations

import pathlib
import sys
import tempfile
import unittest

TOOLS = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))

from match_provenance import configure, make_id  # noqa: E402
from nearmiss_db import (  # noqa: E402
    db_path,
    load_best_nearmiss,
    load_db,
    prune_matched,
    remove,
    upsert,
    upsert_from_file,
)


class NearmissDb(unittest.TestCase):
    def setUp(self) -> None:
        self.tmp = tempfile.TemporaryDirectory()
        self.root = pathlib.Path(self.tmp.name)
        (self.root / "config").mkdir()
        (self.root / "src" / "arm9").mkdir(parents=True)
        (self.root / "tools").mkdir()
        (self.root / "tools" / "match.py").write_text("# stub for repo discovery\n")
        configure(self.root)


    def tearDown(self) -> None:
        self.tmp.cleanup()

    def test_upsert_keeps_closer_c(self) -> None:
        a, rec = upsert(
            module="arm9",
            addr=0x020009E0,
            name="func_020009e0",
            divergences=12,
            c_source="int func_020009e0(void) { return 1; }\n",
            size=0x78,
            source="t1",
        )
        self.assertEqual(a, "added")
        self.assertIn("return 1", rec["c_source"])

        a2, rec2 = upsert(
            module="arm9",
            addr=0x020009E0,
            name="func_020009e0",
            divergences=4,
            c_source="int func_020009e0(void) { return 2; }\n",
            size=0x78,
            source="t2",
        )
        self.assertEqual(a2, "improved")
        self.assertIn("return 2", rec2["c_source"])
        self.assertEqual(rec2["divergences"], 4)

        a3, rec3 = upsert(
            module="arm9",
            addr=0x020009E0,
            name="func_020009e0",
            divergences=8,
            c_source="int func_020009e0(void) { return 3; }\n",
            size=0x78,
            source="t3",
        )
        self.assertEqual(a3, "unchanged")
        self.assertIn("return 2", rec3["c_source"])

        tips = load_best_nearmiss(self.root)
        fid = make_id("arm9", 0x020009E0)
        self.assertIn(fid, tips)
        self.assertEqual(tips[fid]["divergences"], 4)
        self.assertIn("return 2", tips[fid]["c_source"])
        self.assertTrue(db_path(self.root).is_file())

    def test_skip_match_div_zero(self) -> None:
        a, rec = upsert(
            module="arm9",
            addr=0x1,
            name="f",
            divergences=0,
            c_source="void f(void) {}\n",
        )
        self.assertEqual(a, "skipped")
        self.assertIsNone(rec)

    def test_upsert_from_file_and_remove(self) -> None:
        p = self.root / "scratch" / "try.c"
        p.parent.mkdir(parents=True)
        p.write_text("void func_02000010(void) { /* tip */ }\n")
        action, rec = upsert_from_file(
            src_file=p,
            module="arm9",
            addr=0x02000010,
            name="func_02000010",
            divergences=3,
            source="test",
        )
        self.assertEqual(action, "added")
        self.assertEqual(rec["srcPath"], "scratch/try.c")
        self.assertTrue(remove("arm9", 0x02000010))
        self.assertEqual(load_db(), {})

    def test_prune_matched(self) -> None:
        upsert(
            module="arm9",
            addr=0x02000100,
            name="func_02000100",
            divergences=2,
            c_source="void func_02000100(void) {}\n",
            source="x",
        )
        (self.root / "src" / "arm9" / "func_02000100.c").write_text(
            "void func_02000100(void) {}\n"
        )
        n = prune_matched(self.root)
        self.assertEqual(n, 1)
        self.assertEqual(load_db(), {})


if __name__ == "__main__":
    unittest.main()

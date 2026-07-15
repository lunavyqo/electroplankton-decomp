#!/usr/bin/env python3
"""Log one matching attempt (always — even no progress / no near-miss improve).

Examples:

  # AI try that didn't help (new root)
  python tools/log_attempt.py --func func_02001a64 --module arm9 --addr 0x02001a64 \\
      --status no_progress --kind ai \\
      --model grok-4.5 --reasoning high --harness grok-build \\
      --author lunavyqo --session-scope focused --batch-size 1 \\
      --note "permuter stuck"

  # Continue from a prior attempt node
  python tools/log_attempt.py --func func_02001a64 \\
      --status near_miss --divergences 6 --prev-best 4 \\
      --kind ai --model grok-4.5 --reasoning high --harness grok-build \\
      --session-scope focused --batch-size 1 \\
      --parent-attempt-id <priorAttemptId>

  # Successful match (also bank with bank.py)
  python tools/log_attempt.py --func … --status matched --kind ai …

Statuses: matched | near_miss | no_progress | compile_error | failed | skipped
"""
from __future__ import annotations

import argparse
import pathlib
import re
import sys

_TOOLS = pathlib.Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from match_attempts import append_attempt, attempt_stats, load_attempts  # noqa: E402
from match_provenance import (  # noqa: E402
    ProvenanceError,
    configure,
    make_id,
)
from bank import load_symbol  # noqa: E402

ADDR_IN_NAME = re.compile(r"func_([0-9a-fA-F]{6,8})$", re.I)


def main() -> None:
    ap = argparse.ArgumentParser(
        description="Append one match attempt to config/match_attempts.jsonl"
    )
    ap.add_argument("--repo", type=pathlib.Path, default=None)
    ap.add_argument("--func", help="Symbol name")
    ap.add_argument("--module", default=None)
    ap.add_argument("--addr", help="Address hex")
    ap.add_argument("--src", type=pathlib.Path, help="Path to attempt C (logged as srcPath)")
    ap.add_argument(
        "--status",
        required=True,
        choices=[
            "matched",
            "near_miss",
            "no_progress",
            "compile_error",
            "failed",
            "skipped",
        ],
    )
    ap.add_argument("--kind", default="ai", choices=("ai", "human"))
    ap.add_argument("--model")
    ap.add_argument("--reasoning")
    ap.add_argument("--harness")
    ap.add_argument("--author", "--by", dest="author")
    ap.add_argument("--divergences", type=int, default=None)
    ap.add_argument("--prev-best", type=int, default=None, dest="prev_best")
    ap.add_argument(
        "--improved",
        action=argparse.BooleanOptionalAction,
        default=None,
        help="Override improvedNearMiss (default: compare divergences vs --prev-best)",
    )
    ap.add_argument("--label", help="Batch / wave / session label (e.g. wave-cheap-01)")
    ap.add_argument(
        "--session-scope",
        choices=("focused", "batch"),
        required=True,
        help="REQUIRED every run: focused = solo session; batch = multi-function session",
    )
    ap.add_argument(
        "--batch-size",
        type=int,
        default=None,
        dest="batch_size",
        help="REQUIRED for batch (≥2); defaults to 1 when --session-scope=focused",
    )
    ap.add_argument(
        "--attempt-id",
        dest="attempt_id",
        help="Optional unique id for this node (UUID hex). Generated if omitted.",
    )
    ap.add_argument(
        "--parent-attempt-id",
        dest="parent_attempt_id",
        default=None,
        help="attemptId of the node you built on (omit/null for new root)",
    )
    ap.add_argument(
        "--base-kind",
        dest="base_kind",
        choices=[
            "scratch",
            "previous_attempt",
            "near_miss_draft",
            "matched_sibling",
        ],
        default=None,
        help="What this try was based on (default: scratch or previous_attempt)",
    )
    ap.add_argument(
        "--base-divergences",
        type=int,
        default=None,
        dest="base_divergences",
        help="Score of the base you started from, if known",
    )
    ap.add_argument("--note")
    ap.add_argument(
        "--stats",
        action="store_true",
        help="After write, print attempt counts for this function",
    )
    args = ap.parse_args()

    root = configure(args.repo)
    print(f"REPO = {root}")

    name = args.func
    if not name and args.src:
        name = args.src.stem
    if not name:
        print("ERROR: need --func or --src", file=sys.stderr)
        sys.exit(2)

    module = args.module
    addr = int(args.addr, 0) if args.addr else None
    info = load_symbol(name)
    if info:
        sym_mod, sym_addr, _ = info
        module = module or sym_mod
        addr = sym_addr if addr is None else addr
    if addr is None:
        m = ADDR_IN_NAME.search(name)
        if m:
            addr = int(m.group(1), 16)
    module = module or "arm9"
    if addr is None:
        print("ERROR: need --addr or resolvable symbol", file=sys.stderr)
        sys.exit(2)

    src_rel = None
    if args.src:
        p = args.src if args.src.is_absolute() else root / args.src
        try:
            src_rel = p.resolve().relative_to(root.resolve()).as_posix()
        except ValueError:
            src_rel = str(args.src)

    try:
        row = append_attempt(
            module=module,
            addr=addr,
            name=name,
            status=args.status,
            kind=args.kind,
            model=args.model,
            reasoning=args.reasoning,
            harness=args.harness,
            author=args.author,
            divergences=args.divergences,
            prev_best_divergences=args.prev_best,
            improved_near_miss=args.improved,
            src_path=src_rel,
            label=args.label,
            note=args.note,
            session_scope=args.session_scope,
            batch_size=args.batch_size,
            attempt_id=args.attempt_id,
            parent_attempt_id=args.parent_attempt_id,
            base_kind=args.base_kind,
            base_divergences=args.base_divergences,
        )
    except ProvenanceError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        sys.exit(2)

    print(
        f"Logged attempt functionId={row['functionId']} attemptId={row['attemptId']} "
        f"parent={row.get('parentAttemptId')} status={row['status']} "
        f"scope={row.get('sessionScope')} batchSize={row.get('batchSize')} "
        f"improved={row.get('improvedNearMiss')} kind={row['kind']}"
    )
    if args.stats:
        all_rows = load_attempts(function_id=make_id(module, addr))
        print(f"stats: {attempt_stats(all_rows)}")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Untimed per-DF allocation/digest observations from the native diagnostic driver."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def jsonlines(path):
    return [json.loads(line) for line in Path(path).read_text().splitlines() if line.strip()]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", required=True, type=Path)
    parser.add_argument("--build", required=True, type=Path)
    parser.add_argument("--census", required=True, type=Path)
    parser.add_argument("--corpus", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=False)
    build = json.loads(args.build.read_text())
    binary_hash = sha(args.binary)
    expected_binary = build["artifacts"][str(args.binary)]
    assert binary_hash == expected_binary
    for path, digest in build["reused_production_objects"].items():
        assert sha(path) == digest, path
    census = jsonlines(args.census)
    counts = next(row for row in census if row.get("kind") == "post_decode_shadow_census")
    complete = next(row for row in census if row.get("phase") == "result")
    digests = {row["df"]: row["digest"] for row in complete["per_df"]}
    commands = []
    rows = []
    before = {
        "kind": "untimed_native_per_df_allocation_and_complete_output_digest",
        "started_utc": datetime.now(timezone.utc).isoformat(),
        "binary": str(args.binary), "binary_sha256": binary_hash,
        "build_manifest": str(args.build), "build_manifest_sha256": sha(args.build),
        "census": str(args.census), "census_sha256": sha(args.census),
        "corpus": str(args.corpus), "corpus_sha256": sha(args.corpus),
        "production_objects_match_build_manifest": True,
        "commands": commands,
    }
    (args.output / "before.json").write_text(json.dumps(before, indent=2) + "\n")
    for count in counts["per_df"]:
        df = count["df"]
        if not count["count"]:
            rows.append({"df": df, "messages": 0, "loop_small_allocations": 0,
                         "status": "empty_corpus_stratum_not_executed"})
            continue
        argv = [str(args.binary), f"df{df}", str(args.corpus)]
        commands.append(argv)
        stdout = args.output / f"df{df}.jsonl"
        stderr = args.output / f"df{df}.stderr"
        with stdout.open("w") as output, stderr.open("w") as errors:
            result = subprocess.run(argv, stdout=output, stderr=errors, check=False)
        if result.returncode != 0:
            raise RuntimeError(f"DF{df} driver failed: {result.returncode}")
        observed = jsonlines(stdout)
        prepared = next(row for row in observed if row.get("phase") == "prepared")
        decoded = next(row for row in observed if row.get("phase") == "decoded")
        final = next(row for row in observed if row.get("phase") == "result")
        assert prepared["selected"] == decoded["retained"] == final["digest"]["count"] == count["count"]
        assert final["digest"] == digests[df], (df, final["digest"], digests[df])
        assert decoded["loop_small_allocations"] == final["loop_small_allocations"]
        assert final["per_df"][df]["digest"] == final["digest"]
        assert all(row["digest"]["count"] == 0 for row in final["per_df"] if row["df"] != df)
        rows.append({"df": df, "messages": count["count"],
                     "loop_small_allocations": final["loop_small_allocations"],
                     "complete_output_digest": final["digest"],
                     "matches_full_corpus_df_digest": True,
                     "stdout": str(stdout), "stdout_sha256": sha(stdout),
                     "stderr": str(stderr), "stderr_sha256": sha(stderr)})
        print(json.dumps(rows[-1]), flush=True)
    assert sum(row["messages"] for row in rows) == 172432
    assert sha(args.binary) == binary_hash
    for path, digest in build["reused_production_objects"].items():
        assert sha(path) == digest, path
    result = {
        **before,
        "completed_utc": datetime.now(timezone.utc).isoformat(),
        "binary_and_production_objects_unchanged": True,
        "per_df": rows,
        "all_nonempty_df_digests_match_complete_corpus": True,
        "complete_corpus_loop_small_allocations": complete["loop_small_allocations"],
        "sum_separate_df_loop_small_allocations": sum(row["loop_small_allocations"] for row in rows),
        "notes": [
            "No elapsed duration or throughput is collected.",
            "IO.getNumHeartbeats observes Lean small allocations during decode plus complete-array append, not bytes or all GMP/libc allocations.",
            "Separate DF runs have separate allocator/context state; the sum need not equal one complete corpus run.",
            "Every output field is consumed afterward through repr; per-DF count, byte count and FNV digest match the complete-corpus run.",
            "FNV is an observability/cross-run checksum, not a cryptographic equivalence proof.",
        ],
    }
    (args.output / "summary.json").write_text(json.dumps(result, indent=2) + "\n")


if __name__ == "__main__":
    main()

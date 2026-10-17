#!/usr/bin/env python3
"""Evaluate the frozen CPR predicates on an independently traced oracle stream.

This review script is not a benchmark, proof, or substitute for the final gate.
It selects cases and reports counts; Lean evaluates the actual predicates.
"""

import argparse
import csv
import gzip
import hashlib
import io
import json
from pathlib import Path
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[1]
COLUMNS = ["kind", "id", "surface", "odd", "pLatBits", "pLonBits", "qLatBits",
           "qLonBits", "pLatCode", "pLonCode", "qLatCode", "qLonCode"]


def as_float(bits):
    return struct.unpack(">d", struct.pack(">Q", bits))[0]


def load_trace(path):
    raw = gzip.decompress(path.read_bytes()) if path.suffix == ".gz" else path.read_bytes()
    return raw, [json.loads(line) for line in raw.splitlines() if line]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("trace", type=Path)
    parser.add_argument("--output", type=Path, default=ROOT / "docs/review-cpr")
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    cache = ROOT / ".cache/review-cpr"
    cache.mkdir(parents=True, exist_ok=True)
    raw, trace = load_trace(args.trace)
    cases = []
    exclusions = {"global_attempts": 0, "current_unresolved": 0,
                  "current_resolved_mate_unresolved": 0, "both_resolved": 0,
                  "resolved_without_previous_reference": 0}

    def append_case(kind, row, p, q, p_codes, q_codes, groups, partner_row, age):
        cases.append({
            "kind": kind, "id": len(cases), "surface": int(row["mode"] == "surface"),
            "odd": int(row["odd"]) if kind == 0 else 0,
            "pLatBits": p["lat_bits"], "pLonBits": p["lon_bits"],
            "qLatBits": q["lat_bits"], "qLonBits": q["lon_bits"],
            "pLatCode": p_codes[0], "pLonCode": p_codes[1],
            "qLatCode": q_codes[0], "qLonCode": q_codes[1],
            "row": row["row"], "partner_row": partner_row, "icao": row["icao"],
            "route": row["route"], "groups": groups, "age_seconds": age,
        })

    for row in trace:
        position = row["position"]
        previous = row["previous_ref"]
        if position is not None and previous is not None:
            age = as_float(row["timestamp_bits"]) - as_float(previous["timestamp_bits"])
            groups = ["local_all_previous_references"]
            eligible = (row["mode"] == "surface" or
                        (not row["negative_time"] and age < 180))
            if eligible:
                groups.append("local_previous_references_within_policy_age")
            if row["route"] in ("local", "surface_local"):
                assert eligible
                groups.extend(["local_actual", "local_actual_" + row["mode"]])
            append_case(0, row, position, previous["position"],
                        (row["lat_cpr"], row["lon_cpr"]), (0, 0), groups,
                        previous["row"], age)
        elif position is not None:
            exclusions["resolved_without_previous_reference"] += 1
            assert row["route"] == "global", "accepted local case lacks its reference"

        if row["global_attempt"]:
            exclusions["global_attempts"] += 1
            mate = row["opposite"]
            assert mate is not None and mate["odd"] != row["odd"]
            if position is None:
                exclusions["current_unresolved"] += 1
                continue
            if mate["position"] is None:
                exclusions["current_resolved_mate_unresolved"] += 1
                continue
            exclusions["both_resolved"] += 1
            current = (position, (row["lat_cpr"], row["lon_cpr"]))
            earlier = (mate["position"], (mate["lat_cpr"], mate["lon_cpr"]))
            even, odd = (earlier, current) if row["odd"] else (current, earlier)
            age = as_float(row["timestamp_bits"]) - as_float(mate["timestamp_bits"])
            assert 0 <= age < 30
            groups = ["global_live_pairs_both_resolved"]
            groups.append("global_pairs_accepted_" + row["route"])
            append_case(1, row, even[0], odd[0], even[1], odd[1], groups, mate["row"], age)

    input_path = cache / "predicate-input.csv"
    output_path = cache / "predicate-output.csv"
    with input_path.open("w", newline="") as f:
        writer = csv.DictWriter(f, COLUMNS, extrasaction="ignore", lineterminator="\n")
        writer.writeheader()
        writer.writerows(cases)
    subprocess.run(["lake", "env", "lean", "--run", "scripts/ReviewCPR.lean",
                    str(input_path), str(output_path)], cwd=ROOT, check=True)
    with output_path.open(newline="") as f:
        evaluations = list(csv.DictReader(f))
    assert len(evaluations) == len(cases)
    results = []
    for case, evaluated in zip(cases, evaluations):
        assert int(evaluated["id"]) == case["id"]
        assert int(evaluated["kind"]) == case["kind"]
        results.append({**case, **{k: int(v) if v else None for k, v in evaluated.items()
                                 if k not in ("kind", "id")}})
    groups = {}
    for name in sorted({g for c in cases for g in c["groups"]}):
        members = [r for r in results if name in r["groups"]]
        passed = sum(r["admissible"] for r in members)
        groups[name] = {
            "satisfied": passed, "total": len(members),
            "aircraft": sorted({r["icao"] for r in members}),
            "fraction": passed / len(members), "percent": 100 * passed / len(members),
            "failed_components": {key: sum(r[key] == 0 for r in members)
                                  for key in ("valid_p", "valid_q", "latitude", "zone", "longitude")},
            "reencoding_failures_p": sum(r["reencodes_p"] == 0 for r in members),
            "reencoding_failures_q": sum(r["reencodes_q"] == 0 for r in members),
            "min_age_seconds": min(r["age_seconds"] for r in members),
            "max_age_seconds": max(r["age_seconds"] for r in members),
        }

    # Retain complete evidence compactly, including exact binary64 bit patterns.
    (out / "oracle-trace.jsonl.gz").write_bytes(gzip.compress(raw, mtime=0))
    buffer = io.StringIO(newline="")
    fieldnames = list(results[0])
    writer = csv.DictWriter(buffer, fieldnames, lineterminator="\n")
    writer.writeheader()
    for result in results:
        writer.writerow({**result, "groups": ";".join(result["groups"])})
    (out / "evaluations.csv.gz").write_bytes(gzip.compress(buffer.getvalue().encode(), mtime=0))
    failures = [r for r in results if not r["admissible"]]
    (out / "failures.json").write_text(json.dumps(failures, indent=2) + "\n")
    summary = {
        "oracle_commit": "685dfaa34c5ab186c691bca3cfe2a22e12517d30",
        "trace_sha256": hashlib.sha256(raw).hexdigest(),
        "corpus_sha256": hashlib.sha256((ROOT / "vendor/rs1090/crates/rs1090/data/long_flight.csv").read_bytes()).hexdigest(),
        "spec_lock_sha256": hashlib.sha256((ROOT / "spec.lock").read_bytes()).hexdigest(),
        "trace_cpr_frames": len(trace), "resolved_positions": sum(r["position"] is not None for r in trace),
        "resolved_aircraft": sorted({r["icao"] for r in trace if r["position"] is not None}),
        "evaluated_cases": len(cases), "exclusions": exclusions, "groups": groups,
        "lean_evaluator_sha256": hashlib.sha256((ROOT / "scripts/ReviewCPR.lean").read_bytes()).hexdigest(),
    }
    (out / "summary.json").write_text(json.dumps(summary, indent=2) + "\n")
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()

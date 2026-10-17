#!/usr/bin/env python3
"""Synthetic worldwide CPR differential stratum; no frozen files are modified.

The Lean adapter generates codes with Spec.CPR.encode, evaluates the exact
decoders/contracts and frozen Float adapters, and the Rust adapter calls the
pinned public decoders. This component is not a whole-message differential run.
"""
import argparse
from collections import Counter
import csv
from fractions import Fraction as Q
import gzip
import hashlib
import json
import math
import os
from pathlib import Path
import random
import re
import struct
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PIN = "685dfaa34c5ab186c691bca3cfe2a22e12517d30"
INPUT_COLUMNS = ["id", "kind", "surface", "odd", "latest", "pn", "pd", "qn", "qd",
                 "rn", "rd", "sn", "sd", "tn", "td", "un", "ud"]
OFFSETS = [Q(-4), Q(-2), Q(-1), Q(-1, 2), Q(0), Q(1, 2), Q(1), Q(2), Q(4)]


def transitions():
    text = (ROOT / "Spec/CPR.lean").read_text()
    table = re.search(r"def transitions : List Nat :=\s*\[([^]]+)\]", text)
    assert table, "cannot locate the frozen transition inventory"
    values = [Q(int(n), 100000000) for n in re.findall(r"\d+", table[1])]
    assert len(values) == 58 and values[-1] == 87
    return values


def normalize(lon):
    return (lon + 180) % 360 - 180


def clamp_lat(lat):
    return max(Q(-90), min(Q(90), lat))


def generate(count, seed):
    rng = random.Random(seed)
    boundaries = transitions()
    cases = []
    cells = set()

    def append(group, p, q, reference, kind=0, surface=0, odd=0, latest=0, **tags):
        assert -90 <= p[0] <= 90 and -180 <= p[1] < 180
        assert -90 <= q[0] <= 90 and -180 <= q[1] < 180
        assert -90 <= reference[0] <= 90 and -180 <= reference[1] < 180
        row = dict(id=len(cases), kind=kind, surface=surface, odd=odd, latest=latest)
        for n, d, value in zip(INPUT_COLUMNS[5::2], INPUT_COLUMNS[6::2], (*p, *q, *reference)):
            value = Q(value)
            row[n], row[d] = value.numerator, value.denominator
        cases.append({**row, "group": group, **tags})

    def local(group, p, surface, odd, reference=None, **tags):
        append(group, p, p, reference or p, surface=surface, odd=odd, **tags)

    def global_pair(group, p, q=None, kind=1, **tags):
        for latest in (0, 1):
            append(group, p, q or p, p, kind=kind, latest=latest, **tags)

    def nl(lat):
        return 2 if abs(lat) == 87 else 59 - sum(t <= abs(lat) for t in boundaries)

    def widths(surface, odd, lat):
        width = 90 if surface else 360
        dlat = Q(width, 60 - odd)
        rounded = Q(math.floor(lat / dlat * 131072 + Q(1, 2))) * dlat / 131072
        return dlat, Q(width, max(nl(rounded) - odd, 1)), rounded

    # Uniform latitude/longitude sampling, with bounded movement and independently
    # randomized local references. This is deliberately not area-uniform sampling.
    for index in range(count):
        p = (Q(rng.randrange(-90_000_000_000, 90_000_000_001), 10**9),
             Q(rng.randrange(-180_000_000_000, 180_000_000_000), 10**9))
        cells.add((min(17, int((p[0] + 90) // 10)), int((p[1] + 180) // 30)))
        for surface in (0, 1):
            for odd in (0, 1):
                dlat, dlon, _ = widths(surface, odd, p[0])
                reference = (clamp_lat(p[0] + dlat * Q(rng.randrange(-1000, 1001), 4000)),
                             normalize(p[1] + dlon * Q(rng.randrange(-1000, 1001), 4000)))
                local("worldwide", p, surface, odd, reference, random_index=index)
        global_pair("worldwide_stationary", p, random_index=index)
        q = (clamp_lat(p[0] + Q(rng.randrange(-1000, 1001), 10**6)),
             normalize(p[1] + Q(rng.randrange(-1000, 1001), 10**6)))
        global_pair("worldwide_moving", p, q, random_index=index)
        if index < min(count, 256):
            global_pair("same_parity_rejection", p, q, kind=2, random_index=index)
            far = (clamp_lat(p[0] + 1), normalize(p[1] + 1))
            global_pair("separated_pair", p, far, random_index=index)

    # Every transition, in both hemispheres and at each medium/parity's own
    # latitude quantization step. Preserve duplicate cases across named strata.
    for index, transition in enumerate(boundaries):
        for sign in (-1, 1):
            boundary = sign * transition
            for surface in (0, 1):
                for odd in (0, 1):
                    step = Q(90 if surface else 360, (60 - odd) * 131072)
                    for offset in OFFSETS:
                        lat = boundary + offset * step
                        p = (lat, Q(123456789, 10**7))
                        tags = dict(transition=index, sign=sign, offset=str(offset),
                                    step=str(step), boundary=str(boundary))
                        assert abs(lat - boundary) <= 4 * step
                        local("nl_transition", p, surface, odd, **tags)
                        if not surface:
                            global_pair("nl_transition", p, **tags, origin_parity=odd)
            step0, step1 = Q(360, 60 * 131072), Q(360, 59 * 131072)
            global_pair("nl_straddling", (boundary - 2 * step0, Q(12)),
                        (boundary + 2 * step1, Q(12)), transition=index, sign=sign)

    # Explicit ±87°, poles and equator (87 also occurs in the transition stratum).
    for boundary in (Q(-90), Q(-87), Q(0), Q(87), Q(90)):
        for surface in (0, 1):
            for odd in (0, 1):
                step = Q(90 if surface else 360, (60 - odd) * 131072)
                for offset in OFFSETS:
                    lat = boundary + offset * step
                    if not -90 <= lat <= 90:
                        continue
                    for lon in (Q(0), Q(-180), Q(899999999, 10**7)):
                        p = (lat, lon)
                        tags = dict(boundary=str(boundary), offset=str(offset), step=str(step))
                        local("special_latitude", p, surface, odd, **tags)
                        if not surface:
                            global_pair("special_latitude", p, **tags, origin_parity=odd)

    # Longitude steps depend on NL and parity. Cover both representations of the
    # seam, with references deliberately crossing it and no output normalization.
    for lat in (Q(-90), Q(-87), Q(-60), Q(-1), Q(0), Q(1), Q(60), Q(87), Q(90)):
        for surface in (0, 1):
            for odd in (0, 1):
                _, dlon, _ = widths(surface, odd, lat)
                step = dlon / 131072
                for offset in OFFSETS:
                    p = (lat, normalize(Q(180) + offset * step))
                    reference = (lat, normalize(p[1] + 2 * step))
                    tags = dict(offset=str(offset), step=str(step), latitude=str(lat))
                    local("antimeridian", p, surface, odd, reference, **tags)
                    if not surface:
                        global_pair("antimeridian", p, **tags, origin_parity=odd)

    # Inside, at and outside both reference half-cell limits. Truth remains a
    # valid physical point, but false hypotheses impose no accuracy assertion.
    for lat in (Q(-89), Q(-87), Q(-45), Q(0), Q(45), Q(87), Q(89)):
        for surface in (0, 1):
            for odd in (0, 1):
                p = (lat, Q(12))
                dlat, dlon, rounded = widths(surface, odd, lat)
                rounded_lon = Q(math.floor(p[1] / dlon * 131072 + Q(1, 2))) * dlon / 131072
                for axis in ("latitude", "longitude"):
                    for sign in (-1, 1):
                        for offset in (-1, 0, 1):
                            if axis == "latitude":
                                reference = (rounded + sign * (dlat / 2 + offset * dlat / 131072), p[1])
                                if not -90 <= reference[0] <= 90:
                                    continue
                            else:
                                reference = (lat, normalize(rounded_lon + sign * (dlon / 2 + offset * dlon / 131072)))
                            local("reference_half_cell", p, surface, odd, reference,
                                  axis=axis, sign=sign, offset=offset)

    transition_coverage = {(c["transition"], c["sign"], c["surface"], c["odd"], c["offset"])
                           for c in cases if c["group"] == "nl_transition" and c["kind"] == 0}
    assert len(transition_coverage) == 58 * 2 * 2 * 2 * len(OFFSETS)
    if count >= 4096:
        assert len(cells) == 216, "random stratum missed a 10°×30° geographic cell"
    return cases, {"nl_transition_local_combinations": len(transition_coverage),
                   "random_geographic_cells": len(cells), "random_geographic_cells_total": 216}


def position(row, prefix=""):
    if not int(row[prefix + "accepted"]):
        return None
    return tuple(struct.unpack(">d", struct.pack(">Q", int(row[prefix + key])))[0]
                 for key in ("lat_bits", "lon_bits"))


def agrees(a, b):
    return a is None and b is None or (a is not None and b is not None and
        all(math.isfinite(x) and math.isfinite(y) and abs(x - y) <= 1e-9 for x, y in zip(a, b)))


def run(command, **kwargs):
    subprocess.run(command, cwd=ROOT, check=True, **kwargs)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    size = parser.add_mutually_exclusive_group()
    size.add_argument("--quick", action="store_true")
    size.add_argument("--full", action="store_true")
    parser.add_argument("--random-positions", type=int)
    parser.add_argument("--seed", type=int, default=10902026)
    parser.add_argument("--output", type=Path, default=ROOT / "tests/evidence/cpr-synthetic")
    args = parser.parse_args()
    count = args.random_positions if args.random_positions is not None else (65536 if args.full else 4096)
    if count < 1:
        parser.error("--random-positions must be positive")
    run(["python3", "scripts/check_lock.py"])
    run(["lake", "build", "cprDifferential"])
    actual_pin = subprocess.check_output(["git", "-C", "vendor/rs1090", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
    assert actual_pin == PIN, f"unexpected oracle pin {actual_pin}"
    run(["git", "-C", "vendor/rs1090", "diff", "--exit-code", "HEAD", "--",
         "crates/rs1090", "Cargo.toml", "Cargo.lock"])
    cases, coverage = generate(count, args.seed)
    (ROOT / ".cache").mkdir(exist_ok=True)
    cache = Path(tempfile.mkdtemp(prefix="cpr-synthetic-", dir=ROOT / ".cache"))
    input_path, lean_path, oracle_path = (cache / f for f in ("input.csv", "lean.csv", "oracle.csv"))
    with input_path.open("w", newline="") as stream:
        writer = csv.DictWriter(stream, INPUT_COLUMNS, extrasaction="ignore", lineterminator="\n")
        writer.writeheader()
        writer.writerows(cases)
    print(f"Generated {len(cases)} CPR decoder calls from {count} random positions and mandatory boundary strata.", flush=True)
    run([str(ROOT / ".lake/build/bin/cprDifferential"), str(input_path), str(lean_path)])
    env = {**os.environ, "CARGO_HOME": str(ROOT / ".cache/cargo"),
           "CARGO_TARGET_DIR": str(ROOT / ".cache/rs1090-target")}
    run(["cargo", "build", "--locked", "--offline", "--manifest-path",
         "differential/cpr-oracle/Cargo.toml", "--profile", "dist"], env=env)
    run([str(ROOT / ".cache/rs1090-target/dist/lean1090-synthetic-cpr-oracle"), str(lean_path), str(oracle_path)])
    with lean_path.open() as stream:
        lean = list(csv.DictReader(stream))
    with oracle_path.open() as stream:
        oracle = list(csv.DictReader(stream))
    assert len(lean) == len(oracle) == len(cases)
    counts = Counter()
    groups = {}
    differences = []
    exact_differences = []
    contract_failures = []
    max_error = 0.0
    for case, actual, expected in zip(cases, lean, oracle):
        assert case["id"] == int(actual["id"]) == int(expected["id"])
        a, b, cf, exact = position(actual), position(expected), position(actual, "counterfactual_"), position(actual, "exact_")
        group = groups.setdefault(case["group"], Counter())
        counts["calls"] += 1
        group["calls"] += 1
        for label, condition in (("oracle_accepted", b is not None), ("oracle_rejected", b is None),
                                 ("reference_accepted", a is not None),
                                 ("admissible", actual["admissible"] == "1" and case["kind"] != 2),
                                 ("exact_matches_oracle", agrees(exact, b)), ("float_matches_oracle", agrees(a, b))):
            if condition:
                counts[label] += 1
                group[label] += 1
        if all(actual[key] == expected[key] for key in ("accepted", "lat_bits", "lon_bits")):
            counts["float_bit_identical"] += 1
        if case["kind"] != 2 and actual["admissible"] == "1" and actual["within_resolution"] != "1":
            contract_failures.append({"case": case, "lean": actual, "oracle": expected})
        if a is not None and b is not None and agrees(a, b):
            max_error = max(max_error, abs(a[0] - b[0]), abs(a[1] - b[1]))
        if not agrees(a, b):
            # D009 requires an actual exact-87 reconstructed latitude AND agreement
            # with the counterfactual changing only that one NL table convention.
            known = actual["boundary87"] == "1" and agrees(cf, b)
            classification = "D009" if known else "unclassified"
            counts[classification] += 1
            group[classification] += 1
            differences.append({"classification": classification, "case": case,
                                "lean": actual, "oracle": expected})
        if not agrees(exact, b):
            if actual["boundary87"] == "1" and agrees(cf, b) and not agrees(a, b):
                category = "D009"
            elif (case["group"] == "reference_half_cell" and case["offset"] == 0 and
                  actual["admissible"] == "0" and agrees(a, b)):
                category = "binary64_half_cell_tie"
            else:
                category = "unclassified_exact_difference"
                counts[category] += 1
            exact_differences.append({"classification": category, "case": case,
                                      "lean": actual, "oracle": expected})
        if case["kind"] == 2:
            if a is not None or b is not None or exact is not None:
                counts["same_parity_acceptance_failures"] += 1
                group["same_parity_acceptance_failures"] += 1
                contract_failures.append({"reason": "same-parity pair was accepted",
                                          "case": case, "lean": actual, "oracle": expected})
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    artifacts = {}
    for name, raw in (("input.csv", input_path.read_bytes()), ("lean.csv", lean_path.read_bytes()),
                      ("oracle.csv", oracle_path.read_bytes()),
                      ("metadata.jsonl", b"".join((json.dumps(c, sort_keys=True) + "\n").encode() for c in cases))):
        (out / (name + ".gz")).write_bytes(gzip.compress(raw, mtime=0))
        artifacts[name] = {"sha256": hashlib.sha256(raw).hexdigest(), "bytes": len(raw)}
    (out / "differences.json").write_text(json.dumps(differences, indent=2, sort_keys=True) + "\n")
    (out / "exact-differences.json").write_text(json.dumps(exact_differences, indent=2, sort_keys=True) + "\n")
    (out / "contract-failures.json").write_text(json.dumps(contract_failures, indent=2, sort_keys=True) + "\n")
    summary = {"oracle_pin": PIN, "seed": args.seed, "random_positions": count, "coverage": coverage,
               "counts": dict(counts), "by_stratum": {k: dict(v) for k, v in sorted(groups.items())},
               "contract_failures": len(contract_failures), "maximum_agreeing_float_error_degrees": max_error,
               "exact_difference_categories": dict(Counter(d["classification"] for d in exact_differences)),
               "position_tolerance_degrees": 1e-9, "artifacts": artifacts,
               "source_sha256": {p: hashlib.sha256((ROOT / p).read_bytes()).hexdigest()
                                  for p in ("spec.lock", "lakefile.toml", "scripts/FuzzCPR.lean",
                                            "scripts/check_cpr_differential.py",
                                            "differential/cpr-oracle/Cargo.toml",
                                            "differential/cpr-oracle/Cargo.lock",
                                            "differential/cpr-oracle/src/main.rs",
                                            "Impl/CPR.lean", "Impl/CPRPolicy.lean",
                                            "Impl/CPRFloat.lean", "Impl/Binary64.lean")},
               "limitation": "Proved CPR runtime component stratum with reference equality checks; this component alone is not the complete whole-message differential suite."}
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    print(json.dumps(summary, indent=2, sort_keys=True))
    if contract_failures or counts["unclassified"] or counts["unclassified_exact_difference"]:
        raise SystemExit("Synthetic CPR differential failed; retained concrete counterexamples require review.")
    print("Synthetic CPR stratum passes, with each D009 case retained and checked by a one-convention counterfactual.")


if __name__ == "__main__":
    main()

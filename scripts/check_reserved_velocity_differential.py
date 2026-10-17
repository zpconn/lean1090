#!/usr/bin/env python3
"""Permanently compare reserved TC19 fields against fresh pinned rs1090.

Every reserved subtype has zero, all ones, every one-bit field, and 4,096
seeded random fields. Full message JSON, actual Spec/Impl refinement results,
independent assignment, raw MSB-first values, and x86_64 compatibility values
are checked. No cached oracle output or mismatch exemption is used.
"""
import argparse
from collections import Counter
import gzip
import hashlib
import json
import os
from pathlib import Path
import platform
import random
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PIN = "685dfaa34c5ab186c691bca3cfe2a22e12517d30"
SUBTYPES = (0, 5, 6, 7)
RANDOM_PER_SUBTYPE = 4096
SEED = 0x1090FC002
CASES_PER_SUBTYPE = 2 + 22 + RANDOM_PER_SUBTYPE
REGRESSION = "9011223398040000000000000000"
RUN_LOG = []


def run(command, **kwargs):
    label = "+ " + " ".join(map(str, command))
    print(label, flush=True)
    result = subprocess.run(command, cwd=ROOT,
                            stdout=kwargs.pop("stdout", subprocess.PIPE),
                            stderr=subprocess.PIPE, **kwargs)
    messages = [label]
    for stream in (result.stdout, result.stderr):
        if stream:
            text = stream.decode()
            print(text, end="" if text.endswith("\n") else "\n", flush=True)
            messages.append(text.rstrip())
    messages.append(f"exit_code={result.returncode}")
    RUN_LOG.append("\n".join(messages))
    result.check_returncode()
    return result


def cases():
    rng = random.Random(SEED)
    result = []
    for subtype in SUBTYPES:
        values = [("zero", 0, 0), ("all_ones", (1 << 22) - 1, 0)]
        values += [("single_bit", 1 << bit, 0) for bit in range(22)]
        # Also vary every surrounding TC19 field in the random cases. The
        # first 13 bits contain TC/subtype, intent/reserved/NACv; the final
        # 21 bits contain the vertical-rate and difference fields.
        values += [("random", rng.getrandbits(22), rng.getrandbits(26))
                   for _ in range(RANDOM_PER_SUBTYPE)]
        for kind, raw, context in values:
            word = ((19 << 51) | (subtype << 48) | ((context >> 21) << 43) |
                    (raw << 21) | (context & ((1 << 21) - 1)))
            frame = (18 << 107) | (0x112233 << 80) | (word << 24)
            result.append({"index": len(result), "subtype": subtype,
                           "kind": kind, "raw": raw, "word": word,
                           "hex": frame.to_bytes(14, "big").hex()})
    if len(result) != 4 * CASES_PER_SUBTYPE:
        raise ValueError("reserved velocity generator cardinality changed")
    for subtype in SUBTYPES:
        selected = [case for case in result if case["subtype"] == subtype]
        counts = Counter(case["kind"] for case in selected)
        if counts != {"zero": 1, "all_ones": 1, "single_bit": 22,
                      "random": RANDOM_PER_SUBTYPE}:
            raise ValueError(f"subtype {subtype} generation coverage changed: {counts}")
        if {c["raw"] for c in selected if c["kind"] == "single_bit"} != {
                1 << bit for bit in range(22)}:
            raise ValueError(f"subtype {subtype} single-bit coverage changed")
    if sum(case["hex"] == REGRESSION for case in result) != 1:
        raise ValueError("the exact D011 regression must occur once")
    return result


def check_results(inputs, lean, oracle):
    if len(lean) != len(inputs) or len(oracle) != len(inputs):
        raise ValueError("missing or additional reserved velocity output rows")
    counts, differences = Counter(), []
    for case, actual, expected in zip(inputs, lean, oracle):
        reasons = []
        if actual.get("word") != case["word"] or actual.get("hex") != case["hex"]:
            reasons.append("Lean input order or frame construction differs")
        for flag in ("spec_matches_impl", "assignment_matches_spec",
                     "full_assignment_matches_spec"):
            if actual.get(flag) is not True:
                reasons.append(flag)
        if actual.get("standard_raw") != case["raw"]:
            reasons.append("standard raw field differs from MSB-first input")
        standard_json = actual.get("standard")
        if (not isinstance(standard_json, dict) or
                standard_json.get("reserved_data") != case["raw"]):
            reasons.append("standard JSON raw field differs from MSB-first input")
        if expected is None:
            reasons.append("oracle rejected a reserved subtype frame")
        else:
            if expected.get("consumed") != 14 or expected.get("remainder") != "":
                reasons.append("oracle did not consume exactly the complete frame")
            expected_value = expected.get("oracle", {}).get("reserved_data")
            if actual.get("oracle_value") != expected_value:
                reasons.append("proof-visible oracle value differs")
            projected = {key: actual.get(key) for key in
                         ("oracle", "crc", "consumed", "remainder")}
            if projected != expected:
                reasons.append("full oracle JSON/CRC/consumption/remainder differs")
            if case["hex"] == REGRESSION and expected_value != 128:
                reasons.append("x86_64 D011 oracle value changed from 128")
        counts[f"subtype_{case['subtype']}_cases"] += 1
        counts[f"subtype_{case['subtype']}_{case['kind']}"] += 1
        if reasons:
            differences.append({"case": case, "reasons": reasons,
                                "lean": actual, "oracle": expected})
    for subtype in SUBTYPES:
        if counts[f"subtype_{subtype}_cases"] != CASES_PER_SUBTYPE:
            raise ValueError(f"subtype {subtype} comparison cardinality changed")
    return counts, differences


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path,
                        default=ROOT / "tests/evidence/reserved-velocity")
    args = parser.parse_args()
    run(["python3", "scripts/check_lock.py"])
    if platform.machine().lower() not in ("x86_64", "amd64"):
        raise SystemExit("D011 oracle semantics are pinned to x86_64; unsupported host")
    actual_pin = subprocess.check_output(
        ["git", "-C", "vendor/rs1090", "rev-parse", "HEAD"],
        cwd=ROOT, text=True).strip()
    if actual_pin != PIN:
        raise SystemExit(f"unexpected rs1090 commit: {actual_pin}")
    run(["git", "-C", "vendor/rs1090", "diff", "--exit-code", "HEAD", "--",
         "crates/rs1090", "Cargo.toml", "Cargo.lock"])
    run(["lake", "build", "Spec.Message", "Impl.JSON"])
    (ROOT / ".cache").mkdir(exist_ok=True)
    cache = Path(tempfile.mkdtemp(prefix="reserved-velocity-", dir=ROOT / ".cache"))
    input_cases = cases()
    case_path, word_path, input_path, lean_path, oracle_path = (
        cache / name for name in
        ("cases.json", "words.txt", "input.hex", "lean.jsonl", "oracle.jsonl"))
    case_path.write_text(json.dumps(input_cases, sort_keys=True) + "\n")
    word_path.write_text("".join(f"{case['word']}\n" for case in input_cases))
    input_path.write_text("".join(f"{case['hex']}\n" for case in input_cases))
    with lean_path.open("w") as output:
        run(["lake", "env", "lean", "--run", "Tests/ReservedVelocityDifferential.lean",
             str(word_path)], stdout=output)
    env = {**os.environ, "CARGO_HOME": str(ROOT / ".cache/cargo"),
           "CARGO_TARGET_DIR": str(ROOT / ".cache/rs1090-target")}
    run(["cargo", "build", "--locked", "--offline", "--manifest-path",
         "differential/message-oracle/Cargo.toml", "--profile", "dist", "--bin",
         "lean1090-message-oracle"], env=env)
    with input_path.open() as source, oracle_path.open("w") as output:
        run([str(ROOT / ".cache/rs1090-target/dist/lean1090-message-oracle")],
            stdin=source, stdout=output)
    lean = [json.loads(line) for line in lean_path.read_text().splitlines()]
    oracle = [json.loads(line) for line in oracle_path.read_text().splitlines()]
    counts, differences = check_results(input_cases, lean, oracle)
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    artifacts = {}
    for path in (case_path, word_path, input_path, lean_path, oracle_path):
        raw = path.read_bytes()
        (out / (path.name + ".gz")).write_bytes(gzip.compress(raw, mtime=0))
        artifacts[path.name] = {"sha256": hashlib.sha256(raw).hexdigest(), "bytes": len(raw)}
    (out / "commands.log").write_text("\n\n".join(RUN_LOG) + "\n")
    (out / "differences.json").write_text(json.dumps(differences, indent=2, sort_keys=True) + "\n")
    sources = ["spec.lock", "lean-toolchain", "lakefile.toml", "lake-manifest.json",
               "Tests/ReservedVelocityDifferential.lean",
               "scripts/check_reserved_velocity_differential.py",
               "scripts/run_differential.sh", "differential/message-oracle/Cargo.toml",
               "differential/message-oracle/Cargo.lock",
               "differential/message-oracle/src/main.rs"]
    sources += [str(p.relative_to(ROOT)) for folder in ("Spec", "Model", "Impl")
                for p in sorted((ROOT / folder).rglob("*.lean"))]
    summary = {
        "status": "FAIL" if differences else "PASS", "oracle_pin": PIN,
        "oracle_architecture": platform.machine(), "seed": SEED,
        "subtypes": list(SUBTYPES), "random_per_subtype": RANDOM_PER_SUBTYPE,
        "counts": dict(counts), "comparisons": len(input_cases),
        "mismatches": len(differences), "artifacts": artifacts,
        "source_sha256": {p: hashlib.sha256((ROOT / p).read_bytes()).hexdigest()
                          for p in sources},
        "scope": "Actual Spec/Impl/independent assignment and full reserved TC19 DF18 message JSON against fresh pinned Message::from_bytes; standard raw MSB-first values are retained.",
    }
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    print(json.dumps({key: value for key, value in summary.items()
                      if key not in ("source_sha256", "artifacts")}, indent=2, sort_keys=True))
    if differences:
        raise SystemExit("Reserved velocity differential failed; all counterexamples retained.")
    print(f"Reserved velocity stratum passed: all {len(input_cases):,} cases.")


if __name__ == "__main__":
    main()

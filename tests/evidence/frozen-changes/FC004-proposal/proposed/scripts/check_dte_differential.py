#!/usr/bin/env python3
"""Exhaust every BDS10 DTE code against fresh pinned x86_64 rs1090.

Checks actual Spec/Impl/assignment values, both JSON projections, complete
Message::from_bytes output, and the direct BDS10 reader for all 65,536 codes.
The standard projection must preserve each raw MSB-first code. No mismatch
exemption, cached oracle output, or proposed-definition substitution is used.
"""
import argparse
from collections import Counter
import gzip
import hashlib
import json
import os
from pathlib import Path
import platform
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PIN = "685dfaa34c5ab186c691bca3cfe2a22e12517d30"
TOTAL = 1 << 16
BASE = 0x10000000000000
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


def cases():
    result = [{"raw": raw, "word": BASE + raw,
               "hex": ((20 << 107) | ((BASE + raw) << 24)).to_bytes(14, "big").hex()}
              for raw in range(TOTAL)]
    if (len(result) != TOTAL or len({case["hex"] for case in result}) != TOTAL or
            Counter(case["raw"] for case in result) != Counter(range(TOTAL))):
        raise ValueError("DTE generator must emit every 16-bit code exactly once")
    return result


def check_results(inputs, lean, oracle, direct_oracle):
    if any(len(rows) != TOTAL for rows in (inputs, lean, oracle, direct_oracle)):
        raise ValueError("DTE input/output cardinality differs from 65,536")
    counts, differences = Counter(), []
    compared_codes, observed_oracle_codes = [], []
    for case, actual, expected, expected_direct in zip(inputs, lean, oracle, direct_oracle):
        reasons = []
        if not isinstance(actual, dict):
            reasons.append("Lean adapter did not emit a complete record")
            actual = {}
        if actual.get("word") != case["word"] or actual.get("hex") != case["hex"]:
            reasons.append("Lean input order or frame construction differs")
        for flag in ("spec_matches_impl", "assignment_matches_spec", "full_assignment_matches_spec",
                     "direct_decoder_refines", "direct_meaning_refines"):
            if actual.get(flag) is not True:
                reasons.append(flag)
        for field in ("standard_raw", "standard_value"):
            if actual.get(field) != case["raw"]:
                reasons.append(f"{field} differs from raw MSB-first code")
        standard = actual.get("standard")
        standard_bds = standard.get("bds10") if isinstance(standard, dict) else None
        direct_standard = actual.get("direct_standard")
        if not isinstance(standard_bds, dict) or standard_bds.get("dte") != case["raw"]:
            reasons.append("whole-message standard DTE differs from raw MSB-first code")
        if not isinstance(direct_standard, dict) or direct_standard.get("dte") != case["raw"]:
            reasons.append("direct standard DTE differs from raw MSB-first code")
        if not isinstance(expected, dict):
            reasons.append("oracle rejected a valid BDS10 DF20 frame")
        else:
            counts["fresh_message_oracle_accepted"] += 1
            if expected.get("consumed") != 14 or expected.get("remainder") != "":
                reasons.append("oracle did not consume exactly the complete frame")
            expected_bds = expected.get("oracle", {}).get("bds10")
            if not isinstance(expected_bds, dict):
                reasons.append("whole-message oracle did not infer BDS10")
            else:
                counts["fresh_message_oracle_inferred_bds10"] += 1
                if actual.get("oracle_value") != expected_bds.get("dte"):
                    reasons.append("proof-visible DTE differs from whole-message oracle")
            projected = {key: actual.get(key) for key in
                         ("oracle", "crc", "consumed", "remainder")}
            if projected != expected:
                reasons.append("full oracle JSON/CRC/consumption/remainder differs")
            else:
                counts["full_message_matches"] += 1
        if not isinstance(expected_direct, dict):
            reasons.append("direct oracle rejected a valid BDS10 payload")
        else:
            counts["fresh_direct_oracle_accepted"] += 1
            observed_oracle_codes.append(expected_direct.get("dte"))
            if actual.get("oracle_value") != expected_direct.get("dte"):
                reasons.append("proof-visible DTE differs from direct oracle")
            if actual.get("direct_oracle") != expected_direct:
                reasons.append("complete direct BDS10 JSON differs")
            else:
                counts["full_direct_matches"] += 1
            if case["raw"] == 1 and expected_direct.get("dte") != 256:
                reasons.append("x86_64 D012 oracle value changed from 256")
        compared_codes.append(case["raw"])
        counts["exhaustive_raw_codes"] += 1
        counts["zero_cases"] += case["raw"] == 0
        counts["all_ones_cases"] += case["raw"] == TOTAL - 1
        counts["single_bit_cases"] += case["raw"] > 0 and case["raw"] & (case["raw"] - 1) == 0
        if reasons:
            differences.append({"case": case, "reasons": reasons, "lean": actual,
                                "oracle": expected, "direct_oracle": expected_direct})
    if Counter(compared_codes) != Counter(range(TOTAL)):
        raise ValueError("comparison failed to visit every DTE code exactly once")
    if (counts["exhaustive_raw_codes"] != TOTAL or counts["zero_cases"] != 1 or
            counts["all_ones_cases"] != 1 or counts["single_bit_cases"] != 16):
        raise ValueError("DTE exhaustive/basis cardinality changed")
    counts["distinct_direct_oracle_codes"] = len(set(observed_oracle_codes))
    if Counter(observed_oracle_codes) != Counter(range(TOTAL)):
        differences.append({"reasons": ["fresh oracle DTE outputs are not a permutation of all 65,536 codes"],
                            "counts": dict(counts)})
    return counts, differences


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, default=ROOT / "tests/evidence/dte-exhaustive")
    args = parser.parse_args()
    run(["python3", "scripts/check_lock.py"])
    if platform.machine().lower() not in ("x86_64", "amd64"):
        raise SystemExit("D012 oracle semantics are pinned to x86_64; unsupported host")
    actual_pin = subprocess.check_output(
        ["git", "-C", "vendor/rs1090", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
    if actual_pin != PIN:
        raise SystemExit(f"unexpected rs1090 commit: {actual_pin}")
    run(["git", "-C", "vendor/rs1090", "diff", "--exit-code", "HEAD", "--",
         "crates/rs1090", "Cargo.toml", "Cargo.lock"])
    run(["lake", "build", "dteDifferential"])
    (ROOT / ".cache").mkdir(exist_ok=True)
    cache = Path(tempfile.mkdtemp(prefix="dte-exhaustive-", dir=ROOT / ".cache"))
    inputs = cases()
    paths = {name: cache / name for name in ("cases.json", "words.txt", "input.hex",
        "direct-input.txt", "lean.jsonl", "oracle.jsonl", "direct-oracle.jsonl")}
    paths["cases.json"].write_text(json.dumps(inputs, sort_keys=True) + "\n")
    paths["words.txt"].write_text("".join(f"{case['word']}\n" for case in inputs))
    paths["input.hex"].write_text("".join(f"{case['hex']}\n" for case in inputs))
    paths["direct-input.txt"].write_text("".join(f"16 {case['word']}\n" for case in inputs))
    env = {**os.environ, "CARGO_HOME": str(ROOT / ".cache/cargo"),
           "CARGO_TARGET_DIR": str(ROOT / ".cache/rs1090-target")}
    run(["cargo", "build", "--locked", "--offline", "--manifest-path",
         "differential/message-oracle/Cargo.toml", "--profile", "dist", "--bin",
         "lean1090-message-oracle", "--bin", "commb-oracle"], env=env)
    jobs = [([str(ROOT / ".lake/build/bin/dteDifferential")], "words.txt", "lean.jsonl"),
            ([str(ROOT / ".cache/rs1090-target/dist/lean1090-message-oracle")],
             "input.hex", "oracle.jsonl"),
            ([str(ROOT / ".cache/rs1090-target/dist/commb-oracle")],
             "direct-input.txt", "direct-oracle.jsonl")]
    for command, input_name, output_name in jobs:
        with paths[input_name].open() as source, paths[output_name].open("w") as output:
            run(command, stdin=source, stdout=output)
    outputs = [[json.loads(line) for line in paths[name].read_text().splitlines()]
               for name in ("lean.jsonl", "oracle.jsonl", "direct-oracle.jsonl")]
    counts, differences = check_results(inputs, *outputs)
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    artifacts = {}
    for path in paths.values():
        raw = path.read_bytes()
        (out / (path.name + ".gz")).write_bytes(gzip.compress(raw, mtime=0))
        artifacts[path.name] = {"sha256": hashlib.sha256(raw).hexdigest(), "bytes": len(raw)}
    (out / "commands.log").write_text("\n\n".join(RUN_LOG) + "\n")
    (out / "differences.json").write_text(json.dumps(differences, indent=2, sort_keys=True) + "\n")
    sources = ["spec.lock", "lean-toolchain", "lakefile.toml", "lake-manifest.json",
               "Tests/DTEDifferential.lean", "scripts/check_dte_differential.py",
               "scripts/run_differential.sh", "differential/message-oracle/Cargo.toml",
               "differential/message-oracle/Cargo.lock",
               "differential/message-oracle/src/main.rs", "differential/message-oracle/src/commb.rs"]
    sources += [str(p.relative_to(ROOT)) for folder in ("Spec", "Model", "Impl")
                for p in sorted((ROOT / folder).rglob("*.lean"))]
    summary = {"status": "FAIL" if differences else "PASS", "oracle_pin": PIN,
        "oracle_architecture": platform.machine(), "comparisons": TOTAL,
        "counts": dict(counts), "mismatches": len(differences), "artifacts": artifacts,
        "source_sha256": {p: hashlib.sha256((ROOT / p).read_bytes()).hexdigest() for p in sources},
        "scope": "All 65,536 DTE codes, actual Spec/Impl/assignment and complete direct/full-message JSON against fresh pinned x86_64 rs1090; standard raw MSB-first values preserved."}
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    print(json.dumps({key: value for key, value in summary.items()
                      if key not in ("source_sha256", "artifacts")}, indent=2, sort_keys=True))
    if differences:
        raise SystemExit("DTE differential failed; all counterexamples retained.")
    print(f"DTE stratum passed: all {TOTAL:,} codes, full and direct oracle comparisons.")


if __name__ == "__main__":
    main()

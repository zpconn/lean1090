#!/usr/bin/env python3
"""Exhaust every AC13/AC12 wire code against pinned Message::from_bytes.

Mandatory in both quick and full differential runs. No sampling, tolerance,
known-difference exemption, review-only implementation, or cached oracle result
is used. Standard negative Gillham values are checked separately and retained.
"""
import argparse
from collections import Counter
import csv
import gzip
import hashlib
import json
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PIN = "685dfaa34c5ab186c691bca3cfe2a22e12517d30"
REGRESSION = "a1000000920805003ffc0005c6e5"
RUN_LOG = []


def run(command, **kwargs):
    label = "+ " + " ".join(map(str, command))
    print(label, flush=True)
    result = subprocess.run(command, cwd=ROOT, stdout=kwargs.pop("stdout", subprocess.PIPE),
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


def wire_inputs():
    # Independent direct placement of the source AC13/AC12 bits. DF18 avoids
    # introducing DF17 PI validation into this exhaustive altitude check.
    return [((4 << 51) | (code << 24)).to_bytes(7, "big").hex()
            for code in range(8192)] + [
        ((18 << 107) | (11 << 75) | (code << 60)).to_bytes(14, "big").hex()
        for code in range(4096)]


def check_results(rows, oracle, inputs):
    if len(rows) != 12288 or len(oracle) != 12289 or len(inputs) != 12288:
        raise ValueError("exhaustive AC13/AC12 input or output cardinality changed")
    counts = Counter()
    differences = []
    for index, (row, expected, wire) in enumerate(zip(rows, oracle, inputs)):
        width, code = (13, index) if index < 8192 else (12, index - 8192)
        if (int(row["width"]), int(row["code"]), row["hex"]) != (width, code, wire):
            raise ValueError(f"missing, duplicate, reordered, or misencoded code at index {index}")
        if row["accepted"] not in ("true", "false"):
            raise ValueError(f"invalid Lean acceptance at index {index}")
        accepted = row["accepted"] == "true"
        height = None if row["height"] == "none" else int(row["height"])
        oracle_accepted = expected is not None
        oracle_height = expected["oracle"]["altitude"] if oracle_accepted else None
        expected_size = 7 if width == 13 else 14
        if oracle_accepted and expected["consumed"] != expected_size:
            raise ValueError(f"oracle did not consume one complete frame at index {index}")
        if oracle_accepted and expected["remainder"] != "":
            raise ValueError(f"oracle left an unexpected suffix at index {index}")
        if accepted != oracle_accepted or height != oracle_height:
            differences.append({"index": index, "width": width, "code": code,
                                "wire": wire, "lean": row, "oracle": expected})
        counts[f"ac{width}_cases"] += 1
        counts[f"ac{width}_{'accepted' if oracle_accepted else 'rejected'}"] += 1
        if row["standard_unit"] == "feet" and int(row["standard_height"]) < 0:
            standard_height = int(row["standard_height"])
            if code & 0x10:
                if not accepted or height != standard_height:
                    raise ValueError(f"negative binary25 altitude lost at AC{width} {code}")
                counts[f"ac{width}_negative_binary25_preserved"] += 1
            else:
                if not accepted or height is not None:
                    raise ValueError(f"negative Gillham compatibility changed at AC{width} {code}")
                counts[f"ac{width}_negative_gillham_standard_only"] += 1
    for width in (13, 12):
        # Every representable negative Gillham value (-1200..-100, step100)
        # and negative binary25 value (-1000..-25, step25) must be exercised.
        if counts[f"ac{width}_negative_gillham_standard_only"] != 12:
            raise ValueError(f"standard negative Gillham domain changed for AC{width}")
        if counts[f"ac{width}_negative_binary25_preserved"] != 40:
            raise ValueError(f"negative binary25 domain changed for AC{width}")
    regression = oracle[-1]
    if (regression is None or regression["consumed"] != 14 or
            regression["remainder"] != "" or
            regression["oracle"].get("bds05", {}).get("altitude", "absent") is not None or
            sorted(k for k in regression["oracle"] if k.startswith("bds")) != ["bds05"]):
        raise ValueError("rs1090 Comm-B missing-height candidate regression changed")
    counts["commb_regression_cases"] = 1
    return counts, differences


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path,
                        default=ROOT / "tests/evidence/altitude-exhaustive")
    args = parser.parse_args()
    run(["python3", "scripts/check_lock.py"])
    actual_pin = subprocess.check_output(
        ["git", "-C", "vendor/rs1090", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
    if actual_pin != PIN:
        raise SystemExit(f"unexpected rs1090 commit: {actual_pin}")
    run(["git", "-C", "vendor/rs1090", "diff", "--exit-code", "HEAD", "--",
         "crates/rs1090", "Cargo.toml", "Cargo.lock"])
    run(["lake", "build", "Spec.Message", "Impl.Message"])
    (ROOT / ".cache").mkdir(exist_ok=True)
    cache = Path(tempfile.mkdtemp(prefix="altitude-exhaustive-", dir=ROOT / ".cache"))
    lean_path, input_path, oracle_path = (cache / name for name in
                                         ("lean.csv", "input.hex", "oracle.jsonl"))
    with lean_path.open("w") as output:
        run(["lake", "env", "lean", "--run", "Tests/AltitudeDifferential.lean"], stdout=output)
    inputs = wire_inputs()
    input_path.write_text("\n".join(inputs + [REGRESSION]) + "\n")
    env = {**os.environ, "CARGO_HOME": str(ROOT / ".cache/cargo"),
           "CARGO_TARGET_DIR": str(ROOT / ".cache/rs1090-target")}
    run(["cargo", "build", "--locked", "--offline", "--manifest-path",
         "differential/message-oracle/Cargo.toml", "--profile", "dist", "--bin",
         "lean1090-message-oracle"], env=env)
    with input_path.open() as source, oracle_path.open("w") as output:
        run([str(ROOT / ".cache/rs1090-target/dist/lean1090-message-oracle")],
            stdin=source, stdout=output)
    with lean_path.open() as source:
        rows = list(csv.DictReader(source))
    oracle = [json.loads(line) for line in oracle_path.read_text().splitlines()]
    counts, differences = check_results(rows, oracle, inputs)
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    artifacts = {}
    for path in (input_path, lean_path, oracle_path):
        raw = path.read_bytes()
        (out / (path.name + ".gz")).write_bytes(gzip.compress(raw, mtime=0))
        artifacts[path.name] = {"sha256": hashlib.sha256(raw).hexdigest(), "bytes": len(raw)}
    (out / "commands.log").write_text("\n\n".join(RUN_LOG) + "\n")
    (out / "differences.json").write_text(json.dumps(differences, indent=2, sort_keys=True) + "\n")
    sources = ["spec.lock", "lean-toolchain", "lakefile.toml", "lake-manifest.json",
               "Tests/AltitudeDifferential.lean", "scripts/check_altitude_differential.py",
               "scripts/run_differential.sh", "differential/message-oracle/Cargo.toml",
               "differential/message-oracle/Cargo.lock", "differential/message-oracle/src/main.rs"]
    sources += [str(p.relative_to(ROOT)) for folder in ("Spec", "Model", "Impl")
                for p in sorted((ROOT / folder).rglob("*.lean"))]
    summary = {"status": "FAIL" if differences else "PASS", "oracle_pin": PIN,
               "counts": dict(counts), "code_comparisons": 12288,
               "additional_commb_regressions": 1, "mismatches": len(differences),
               "artifacts": artifacts,
               "source_sha256": {p: hashlib.sha256((ROOT / p).read_bytes()).hexdigest()
                                 for p in sources},
               "scope": "Actual Spec/Impl/independent-assignment altitude definitions and complete DF4/DF18 decoders against fresh pinned Message::from_bytes calls; not the complete message differential suite."}
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    print(json.dumps({k: v for k, v in summary.items() if k not in ("source_sha256", "artifacts")},
                     indent=2, sort_keys=True))
    if differences:
        raise SystemExit("Exhaustive AC13/AC12 differential failed; counterexamples retained.")
    print("Exhaustive altitude stratum passed: all 12,288 codes and the Comm-B candidate regression.")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""REVIEW ONLY: exhaust the proposed DTE projection without changing the model.

The current full decoder remains unchanged and fails the differential gate.
This script compares a copied candidate function, then substitutes only its
DTE result in current JSON for assessment. This is not an implementation test
or a passing gate, and does not waive any recorded mismatch.
"""
import argparse
from collections import Counter
import copy
import csv
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
PATCH_HASH = "1de67cd6b73644ebd60a9e24f3e8f3e6618dd58ef364a69ef8accea29ef6968a"
LOG = []


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def run(command, **kwargs):
    label = "+ " + " ".join(map(str, command))
    print(label, flush=True)
    result = subprocess.run(command, cwd=ROOT,
                            stdout=kwargs.pop("stdout", subprocess.PIPE),
                            stderr=subprocess.PIPE, **kwargs)
    parts = [label]
    for stream in (result.stdout, result.stderr):
        if stream:
            message = stream.decode()
            print(message, end="" if message.endswith("\n") else "\n", flush=True)
            parts.append(message.rstrip())
    parts.append(f"exit_code={result.returncode}")
    LOG.append("\n".join(parts))
    result.check_returncode()


def load_lines(path):
    opener = gzip.open if path.suffix == ".gz" else open
    with opener(path, "rt") as source:
        return [json.loads(line) for line in source]


def verify_copy():
    current = (ROOT / "Spec/CommB.lean").read_text()
    candidate = (ROOT / "review/DTEByteOrderProposal.lean").read_text()
    start = "def commBValue (register word : Nat) (name : String) : Option Rat := do"
    current = current[current.index(start):].split("\n\n", 1)[0]
    candidate = candidate[candidate.index(start):].split("\n\n", 1)[0]
    arm = '  | 0x10, "dte" => some (payloadBits word 41 8 + 256 * payloadBits word 49 8 : Rat)\n'
    if candidate.count(arm) != 1 or candidate.replace(arm, "") != current:
        raise ValueError("review candidate is not exactly current function plus the proposed arm")
    if digest(ROOT / "docs/DTE-BYTE-ORDER-PROPOSAL.diff") != PATCH_HASH:
        raise ValueError("review patch digest differs")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--campaign", type=Path,
                        default=ROOT / "tests/evidence/message-differential")
    parser.add_argument("--output", type=Path,
                        default=ROOT / "tests/evidence/dte-proposal")
    args = parser.parse_args()
    if platform.machine().lower() not in ("x86_64", "amd64"):
        raise SystemExit("this proposal targets the pinned x86_64 oracle")
    run(["python3", "scripts/check_lock.py"])
    lock_before = digest(ROOT / "spec.lock")
    verify_copy()
    pin = subprocess.check_output(["git", "-C", "vendor/rs1090", "rev-parse", "HEAD"],
                                  cwd=ROOT, text=True).strip()
    if pin != PIN:
        raise ValueError(f"unexpected oracle pin {pin}")
    run(["git", "-C", "vendor/rs1090", "diff", "--exit-code", "HEAD", "--",
         "crates/rs1090", "Cargo.toml", "Cargo.lock"])
    campaign = args.campaign.resolve()
    message_failures = load_lines(campaign / "mismatches.jsonl.gz")
    direct_failures = load_lines(campaign / "direct-mismatches.jsonl.gz")
    base_words = [0x10000000000000 + raw for raw in range(65536)]
    extra_words = {int(item["hex"][8:22], 16) for item in message_failures
                   if item["classification"] != "D001"}
    extra_words.update(int(item["input"]["word"]) for item in direct_failures)
    extra_words.difference_update(base_words)
    words = base_words + sorted(extra_words)
    cache = Path(tempfile.mkdtemp(prefix="dte-proposal-", dir=ROOT / ".cache"))
    paths = {name: cache / name for name in ("words.txt", "candidate.csv", "input.hex",
        "direct-input.txt", "lean.jsonl", "oracle.jsonl", "direct-lean.jsonl", "direct-oracle.jsonl")}
    paths["words.txt"].write_text("".join(f"{word}\n" for word in words))
    paths["input.hex"].write_text("".join(
        ((20 << 107) | (word << 24)).to_bytes(14, "big").hex() + "\n"
        for word in base_words))
    paths["direct-input.txt"].write_text("".join(f"16 {word}\n" for word in base_words))
    run(["lake", "build", "Spec.Semantics", "lean1090", "commbDifferential"])
    with paths["candidate.csv"].open("w") as output:
        run(["lake", "env", "lean", "--run", "review/DTEByteOrderProposal.lean",
             str(paths["words.txt"])], stdout=output)
    env = {**os.environ, "CARGO_HOME": str(ROOT / ".cache/cargo"),
           "CARGO_TARGET_DIR": str(ROOT / ".cache/rs1090-target")}
    run(["cargo", "build", "--locked", "--offline", "--manifest-path",
         "differential/message-oracle/Cargo.toml", "--profile", "dist", "--bin",
         "lean1090-message-oracle", "--bin", "commb-oracle"], env=env)
    jobs = [([str(ROOT / ".lake/build/bin/lean1090"), "--diagnostic"], "input.hex", "lean.jsonl"),
            ([str(ROOT / ".cache/rs1090-target/dist/lean1090-message-oracle")], "input.hex", "oracle.jsonl"),
            ([str(ROOT / ".lake/build/bin/commbDifferential")], "direct-input.txt", "direct-lean.jsonl"),
            ([str(ROOT / ".cache/rs1090-target/dist/commb-oracle")], "direct-input.txt", "direct-oracle.jsonl")]
    for command, input_name, output_name in jobs:
        with paths[input_name].open() as source, paths[output_name].open("w") as output:
            run(command, stdin=source, stdout=output)
    with paths["candidate.csv"].open() as source:
        rows = list(csv.DictReader(source))
    if len(rows) != len(words) or [int(row["word"]) for row in rows] != words:
        raise ValueError("candidate cardinality or order differs")
    candidates = {}
    for word, row in zip(words, rows):
        raw = word & 65535
        if (int(row["raw"]) != raw or int(row["current"]) != raw or
                int(row["standard"]) != raw or row["other_fields_unchanged"] != "true"):
            raise ValueError(f"candidate changes raw/standard/other fields at {word}")
        candidates[word] = int(row["proposed"])
    outputs = {name: load_lines(paths[name]) for name in
               ("lean.jsonl", "oracle.jsonl", "direct-lean.jsonl", "direct-oracle.jsonl")}
    if any(len(values) != 65536 for values in outputs.values()):
        raise ValueError("exhaustive output cardinality differs from 65,536")
    counts, failures = Counter(), []
    counterfactuals = cache / "counterfactuals.jsonl"
    with counterfactuals.open("w") as records:
        for index, word in enumerate(base_words):
            lean, oracle, direct_lean, direct_oracle = (
                outputs[name][index] for name in
                ("lean.jsonl", "oracle.jsonl", "direct-lean.jsonl", "direct-oracle.jsonl"))
            if (lean is None or oracle is None or direct_lean["oracle"] is None or
                    direct_oracle is None or "bds10" not in lean["oracle"] or
                    "bds10" not in oracle["oracle"]):
                raise ValueError(f"DTE exhaustive case rejected at {index}")
            if (not direct_lean["decoder_refines"] or not direct_lean["meaning_refines"] or
                    lean["standard"]["bds10"]["dte"] != index):
                raise ValueError(f"current refinement or standard raw value differs at {index}")
            corrected = copy.deepcopy({key: value for key, value in lean.items() if key != "standard"})
            corrected["oracle"]["bds10"]["dte"] = candidates[word]
            corrected_direct = copy.deepcopy(direct_lean["oracle"])
            corrected_direct["dte"] = candidates[word]
            counts["exhaustive_raw_codes"] += 1
            counts["exhaustive_fresh_message_oracle_calls"] += 1
            counts["exhaustive_fresh_direct_oracle_calls"] += 1
            counts["exhaustive_candidate_message_matches"] += corrected == oracle
            counts["exhaustive_candidate_direct_matches"] += corrected_direct == direct_oracle
            counts["exhaustive_current_message_mismatches"] += lean["oracle"] != oracle["oracle"]
            counts["exhaustive_current_direct_mismatches"] += direct_lean["oracle"] != direct_oracle
            if corrected != oracle or corrected_direct != direct_oracle:
                failures.append({"stratum": "exhaustive", "raw": index,
                                 "candidate_message": corrected, "oracle_message": oracle,
                                 "candidate_direct": corrected_direct, "oracle_direct": direct_oracle})
        for item in message_failures:
            if item["classification"] == "D001":
                counts["retained_D001_unchanged"] += 1
                continue
            if item["paths"] != ["/oracle/bds10/dte"]:
                raise ValueError(f"unexpected retained mismatch paths: {item['paths']}")
            word = int(item["hex"][8:22], 16)
            corrected = copy.deepcopy({key: value for key, value in item["lean"].items()
                                       if key != "standard"})
            corrected["oracle"]["bds10"]["dte"] = candidates[word]
            matches = corrected == item["oracle"]
            counts["retained_message_DTE_cases"] += 1
            counts["retained_message_DTE_resolved"] += matches
            record = {"stratum": "retained_message", "index": item["index"],
                      "hex": item["hex"], "candidate": corrected, "matches": matches}
            records.write(json.dumps(record, separators=(",", ":")) + "\n")
            if not matches:
                failures.append(record)
        for item in direct_failures:
            if item["register"] != "10" or item["paths"] != ["/dte"]:
                raise ValueError("unexpected retained direct mismatch")
            word = int(item["input"]["word"])
            corrected = copy.deepcopy(item["lean"]["oracle"])
            corrected["dte"] = candidates[word]
            matches = corrected == item["oracle"]
            counts["retained_direct_DTE_cases"] += 1
            counts["retained_direct_DTE_resolved"] += matches
            record = {"stratum": "retained_direct", "index": item["index"],
                      "word": word, "candidate": corrected, "matches": matches}
            records.write(json.dumps(record, separators=(",", ":")) + "\n")
            if not matches:
                failures.append(record)
    if counts["exhaustive_raw_codes"] != 65536:
        raise ValueError("exhaustive comparison count differs")
    run(["python3", "scripts/check_lock.py"])
    if digest(ROOT / "spec.lock") != lock_before:
        raise ValueError("frozen lock changed during review")
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    artifacts = {}
    for path in [*paths.values(), counterfactuals]:
        raw = path.read_bytes()
        (out / (path.name + ".gz")).write_bytes(gzip.compress(raw, mtime=0))
        artifacts[path.name] = {"bytes": len(raw), "sha256": hashlib.sha256(raw).hexdigest()}
    sources = [ROOT / path for path in ["spec.lock", "Spec/CommB.lean", "Spec/Semantics.lean",
        "Impl/CommB.lean", "Impl/Semantics.lean", "Impl/JSON.lean", "Tests/CommBDifferential.lean",
        "review/DTEByteOrderProposal.lean", "review/check_dte_proposal.py",
        "docs/DTE-BYTE-ORDER-PROPOSAL.diff", "differential/message-oracle/Cargo.lock",
        "differential/message-oracle/Cargo.toml", "differential/message-oracle/src/commb.rs",
        "differential/message-oracle/src/main.rs"]]
    sources += [campaign / "summary.json", campaign / "mismatches.jsonl.gz",
                campaign / "direct-mismatches.jsonl.gz"]
    summary = {"status": "REVIEW_COUNTERFACTUAL_PASS" if not failures else "FAIL",
               "scope": "Unapplied candidate function and DTE-only JSON substitution; not an implementation change or a passing differential gate. Documented D001 cases are unchanged.",
               "oracle_pin": PIN, "architecture": platform.machine(),
               "counts": dict(counts), "candidate_words": len(words),
               "candidate_other_fields_unchanged": len(words),
               "kernel_checked_basis_cases": 18, "kernel_checked_concrete_cases": 1,
               "failures": len(failures), "artifacts": artifacts,
               "source_sha256": {str(path.relative_to(ROOT)): digest(path) for path in sources}}
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    (out / "failures.json").write_text(json.dumps(failures, indent=2, sort_keys=True) + "\n")
    (out / "commands.log").write_text("\n\n".join(LOG) + "\n")
    print(json.dumps({key: value for key, value in summary.items()
                      if key not in ("artifacts", "source_sha256")}, indent=2, sort_keys=True))
    if failures:
        raise SystemExit("review counterfactual failed; all failures retained")


if __name__ == "__main__":
    main()

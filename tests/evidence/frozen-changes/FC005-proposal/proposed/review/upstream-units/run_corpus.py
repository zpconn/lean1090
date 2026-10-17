#!/usr/bin/env python3
"""Port pinned Python test_full's one assertion through actual Lean entrypoints.

No outputs are inferred from the input count: rejected Impl.decode results are
omitted, matching decode_1090t_vec. The supplied timestamps and reference are
then consumed by actual Impl.decodePositions. Its position counts are observed,
not additional upstream expectations. No executable-target mutation is needed.
"""
import argparse
import gzip
import hashlib
import json
import math
import platform
import struct
import subprocess
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PIN = "685dfaa34c5ab186c691bca3cfe2a22e12517d30"
SOURCES = {
    "vendor/rs1090/python/tests/test_full.py": "b6b9791666f33003764369d9a09f526faa548762bfd232a9657a736015ffae68",
    "vendor/rs1090/crates/rs1090/data/long_flight.csv": "3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505",
    "vendor/rs1090/crates/rs1090/data/airports.json": "978b1f95b88769ca5b3b26d3ccc48362116191bb08740eb2c0e0e2f1d82fc760",
}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def bits(value):
    value = float(value)
    if not math.isfinite(value):
        raise ValueError("nonfinite fixture coordinate/timestamp")
    return struct.unpack(">Q", struct.pack(">d", value))[0]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--output", default="tests/evidence/upstream-unit-tests/corpus")
    args = parser.parse_args()
    out = (ROOT / args.output).resolve()
    out.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command):
        start = time.time()
        result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
        commands.append(dict(command=command, exit=result.returncode,
                             elapsed_seconds=time.time()-start,
                             stdout=result.stdout, stderr=result.stderr))
        (out / "commands.json").write_text(json.dumps(commands, indent=2) + "\n")
        if result.returncode:
            raise RuntimeError(f"failed command {command}; see {out / 'commands.json'}")
        return result.stdout

    if run(["git", "-C", "vendor/rs1090", "rev-parse", "HEAD"]).strip() != PIN:
        raise RuntimeError("oracle checkout differs from pinned revision")
    run(["git", "-C", "vendor/rs1090", "diff", "--exit-code", "HEAD", "--",
         "crates/rs1090", "python/tests/test_full.py", "python/src/lib.rs", "Cargo.toml", "Cargo.lock"])
    for name, expected in SOURCES.items():
        if sha(ROOT / name) != expected:
            raise RuntimeError(f"changed pinned source {name}")
    run(["python3", "scripts/check_lock.py"])
    rows = []
    for line in (ROOT / "vendor/rs1090/crates/rs1090/data/long_flight.csv").read_text().splitlines():
        timestamp, raw = line.split(",")
        payload = raw[18:]
        if len(payload) not in (14, 28):
            raise ValueError("unexpected source frame length")
        bytes.fromhex(payload)
        rows.append(dict(kind="message", timestamp_bits=bits(timestamp), hex=payload))
    if len(rows) != 172432:
        raise RuntimeError("pinned corpus cardinality changed")
    input_path = out / "input.jsonl"
    reference_bits = [bits(43.3), bits(1.35)]
    with input_path.open("w") as handle:
        handle.write(json.dumps(dict(kind="header", count=len(rows), reference=reference_bits)) + "\n")
        for row in rows:
            handle.write(json.dumps(row) + "\n")
    airport_path = out / "airports.jsonl"
    airports = json.loads((ROOT / "vendor/rs1090/crates/rs1090/data/airports.json").read_text())
    with airport_path.open("w") as handle:
        for airport in airports:
            handle.write(json.dumps(dict(icao=airport["icao"], position=[bits(airport["lat"]), bits(airport["lon"])])) + "\n")
    run(["lake", "build", "Impl", "Tests.UpstreamCorpus"])
    output = run(["lake", "env", "lean", "--run", "Tests/UpstreamCorpus.lean", str(input_path), str(airport_path)])
    (out / "lean-result.jsonl").write_text(output)
    values = [json.loads(line) for line in output.splitlines() if line.strip()]
    if len(values) != 1:
        raise RuntimeError("expected exactly one Lean assertion result")
    result = values[0]
    if (result.get("passed") is not True or result.get("source_assertions") != 1
            or result.get("corpus_rows") != 172432 or result.get("decoded_messages") != 172432):
        raise RuntimeError("upstream full-corpus assertion failed")
    files = ["Tests/UpstreamCorpus.lean", "review/upstream-units/run_corpus.py",
             "vendor/rs1090/python/src/lib.rs", "Impl/Message.lean", "Impl/CPRPolicy.lean",
             "Impl/CPRFloat.lean", "spec.lock", "lean-toolchain", "lake-manifest.json"]
    summary = dict(result, pinned_rs1090=PIN, reference=[43.3, 1.35], reference_bits=reference_bits,
                   platform=platform.platform(), source_sha256={**SOURCES, **{f: sha(ROOT / f) for f in files}},
                   generated_fixture_sha256={p.name: sha(p) for p in (input_path, airport_path)},
                   source_assertion="data.shape[0] == len(decoded)",
                   decoder_entrypoint="Impl.decode", tracking_entrypoint="Impl.decodePositions",
                   input_timestamp_parser="Python float decimal-to-binary64, retained as exact bits",
                   limitation="The upstream test asserts output cardinality only; position count is observed, not asserted.")
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    for path in (input_path, airport_path):
        with gzip.GzipFile(str(path) + ".gz", "wb", mtime=0) as handle:
            handle.write(path.read_bytes())
        path.unlink()
    print(json.dumps({k: v for k, v in summary.items() if k not in ("source_sha256", "generated_fixture_sha256")}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

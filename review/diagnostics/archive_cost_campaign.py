#!/usr/bin/env python3
"""Retain completed diagnostic evidence without binaries or overwriting artifacts."""
import argparse
import gzip
import hashlib
import io
import json
from pathlib import Path


def sha(data):
    return hashlib.sha256(data).hexdigest()


def perf_raw_record(path, capture):
    """Associate an explicit raw perf file with its recorded capture, not a generation name."""
    path = Path(path)
    data = path.read_bytes()
    recorded = capture["raw_data"]
    assert sha(data) == recorded["sha256"], "raw perf hash differs from capture"
    assert len(data) == recorded["bytes"], "raw perf size differs from capture"
    return {"sha256": sha(data), "bytes": len(data),
            "capture_recorded_path": recorded["path"],
            "reason": "raw perf measurement binary retained in cache; complete extracted stacks and capture provenance archived"}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cache", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--perf-data", type=Path,
                        help="explicit raw perf file, checked against output/perf/capture.json")
    parser.add_argument("--extra-evidence", action="append", default=[], type=Path,
                        help="existing file/directory relative to output to include in the immutable manifest")
    args = parser.parse_args()
    campaign = json.loads((args.cache / "campaign.json").read_text())
    assert campaign["status"] == "passed" and campaign["protected_inputs_unchanged"]
    output = args.output
    perf_capture_path = output / "perf/capture.json"
    perf_record = None
    if args.perf_data is not None:
        perf_record = perf_raw_record(args.perf_data, json.loads(perf_capture_path.read_text()))
    elif perf_capture_path.exists() and "raw_data" in json.loads(perf_capture_path.read_text()):
        parser.error("capture records raw perf data; provide its exact --perf-data path")
    output.mkdir(parents=True, exist_ok=True)
    manifest = {"kind": "untimed_decoder_instruction_archive", "commit": campaign["commit"],
                "files": {}, "omitted_binaries": {}, "notes": [
                    "Instruction diagnostics only; no benchmark samples are generated.",
                    "Raw Callgrind dumps use deterministic gzip and retain original/stored SHA-256 hashes.",
                    "Explicit callgrind.out.1.gz is the primary dump; termination dumps are tool artifacts.",
                    "Candidate and score probes overlap the full decoder and each other.",
                    "Analysis and the report are generated after archival; independent perf records are included below."]}

    def archive(source, destination, compress=False):
        source, destination = Path(source), Path(destination)
        original = source.read_bytes()
        if compress:
            buffer = io.BytesIO()
            with gzip.GzipFile(filename="", mode="wb", fileobj=buffer, compresslevel=9, mtime=0) as stream:
                stream.write(original)
            stored = buffer.getvalue()
            destination = Path(str(destination) + ".gz")
        else:
            stored = original
        target = output / destination
        if target.exists():
            assert target.read_bytes() == stored, "refusing to overwrite changed archive: " + str(target)
        else:
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(stored)
        if compress:
            assert gzip.decompress(target.read_bytes()) == original
        manifest["files"][str(destination)] = {
            "source": str(source), "source_sha256": sha(original), "source_bytes": len(original),
            "stored_sha256": sha(stored), "stored_bytes": len(stored),
            "encoding": "deterministic-gzip-mtime0-no-filename" if compress else "identity"}

    for name in ["campaign.json", "native-df.stdout", "native-df.stderr"]:
        archive(args.cache / name, name)
    for directory in ["driver", "native", "native-df", "profile-jobs", "callgrind"]:
        for source in sorted((args.cache / directory).rglob("*")):
            if not source.is_file() or source.name.startswith("vgdb-"):
                continue
            if source.name == "decode-costs" or source.name.endswith(".o") or source.name == "driver-symbols.log":
                manifest["omitted_binaries"][str(source)] = {
                    "sha256": sha(source.read_bytes()), "bytes": source.stat().st_size,
                    "reason": "cached binary/object/symbol inventory; no binary in evidence"}
                continue
            archive(source, source.relative_to(args.cache), source.name.startswith("callgrind.out"))
    build = json.loads((args.cache / "driver/driver-build.json").read_text())
    for name, digest in campaign["protected_inputs"].items():
        assert sha(Path(name).read_bytes()) == digest, "protected input changed: " + name
    for name, digest in build["reused_production_objects"].items():
        assert sha(Path(name).read_bytes()) == digest
        cpath = Path(name.removesuffix(".o.export"))
        relative = cpath.relative_to(".lake/build/ir")
        archive(cpath, Path("generated-c") / relative)
        source = Path(str(relative).removesuffix(".c") + ".lean")
        archive(source, Path("production-source") / source)
        for suffix in (".trace",):
            trace = Path(name + suffix)
            if trace.exists():
                archive(trace, Path("build-traces") / trace.relative_to(".lake/build/ir"))
    for name in ["DecodeCosts.lean", "build_decode_costs.py", "profile_decode_costs.py",
                 "run_cost_campaign.py", "run_native_df.py", "analyze_callgrind.py",
                 "write_cost_report.py", "archive_cost_campaign.py", "bind_benchmark_history.py",
                 "run_generation_benchmark.py"]:
        archive(Path("review/diagnostics") / name, Path("tooling") / name)
    archive(Path(".cache/profiling-tools/packages.json"), "profiling-tools/packages.json")
    archive(Path(".cache/profiling-tools/bin/valgrind"), "profiling-tools/valgrind-wrapper")
    for source in sorted((output / "perf").rglob("*")):
        if source.is_file():
            archive(source, source.relative_to(output))
    for name in args.extra_evidence:
        source = output / name
        assert source.resolve().is_relative_to(output.resolve()), "extra evidence escaped archive"
        assert source.exists() and not source.is_symlink(), "missing/symlinked extra evidence"
        members = sorted(source.rglob("*")) if source.is_dir() else [source]
        for member in members:
            assert not member.is_symlink(), "symlinked extra evidence member"
            if member.is_file():
                archive(member, member.relative_to(output))
    if perf_record is not None:
        manifest["omitted_binaries"][str(args.perf_data)] = perf_record
    manifest["file_count"] = len(manifest["files"])
    manifest["stored_bytes"] = sum(row["stored_bytes"] for row in manifest["files"].values())
    manifest["all_protected_inputs_still_match"] = True
    path = output / "archive-manifest.json"
    encoded = json.dumps(manifest, indent=2) + "\n"
    if path.exists():
        assert path.read_text() == encoded, "refusing to replace prior archive manifest"
    else:
        path.write_text(encoded)
    print(json.dumps({"manifest": str(path), "files": manifest["file_count"],
                      "stored_bytes": manifest["stored_bytes"], "status": "passed"}))


if __name__ == "__main__":
    main()

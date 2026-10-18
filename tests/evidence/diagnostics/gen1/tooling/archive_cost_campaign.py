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


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cache", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    campaign = json.loads((args.cache / "campaign.json").read_text())
    assert campaign["status"] == "passed" and campaign["protected_inputs_unchanged"]
    output = args.output
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
                 "write_cost_report.py", "archive_cost_campaign.py"]:
        archive(Path("review/diagnostics") / name, Path("tooling") / name)
    archive(Path(".cache/profiling-tools/packages.json"), "profiling-tools/packages.json")
    archive(Path(".cache/profiling-tools/bin/valgrind"), "profiling-tools/valgrind-wrapper")
    for source in sorted((output / "perf").rglob("*")):
        if source.is_file():
            archive(source, source.relative_to(output))
    perf_binary = args.cache / "perf-gen1/perf.data"
    if perf_binary.exists():
        manifest["omitted_binaries"][str(perf_binary)] = {
            "sha256": sha(perf_binary.read_bytes()), "bytes": perf_binary.stat().st_size,
            "reason": "raw perf measurement binary retained in cache; complete extracted stacks and capture provenance archived"}
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

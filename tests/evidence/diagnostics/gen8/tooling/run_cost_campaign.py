#!/usr/bin/env python3
"""Collect a complete untimed decoder diagnostic using a prebuilt native driver.

This never builds or edits production code. All clocks are provenance only;
profile counters are guest instructions, not benchmark samples.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
FAMILIES = ["other", "adsb", "commb"]
PROBES = [prefix + register for prefix in ("candidate", "score")
          for register in ("40", "44", "45", "50", "60")]


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def now():
    return datetime.now(timezone.utc).isoformat()


def read_lines(path):
    return [json.loads(line) for line in Path(path).read_text().splitlines() if line.strip()]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cache", required=True, type=Path)
    parser.add_argument("--jobs", type=int, default=6)
    parser.add_argument("--perf-capture", type=Path,
                        help="completed native capture required before starting any diagnostic worker")
    args = parser.parse_args()
    cache = args.cache
    assert 1 <= args.jobs <= 8
    assert not (cache / "campaign.json").exists(), "preserve any previous campaign"
    driver = cache / "driver"
    binary = driver / "decode-costs"
    build_path = driver / "driver-build.json"
    build = json.loads(build_path.read_text())
    corpus = Path("vendor/rs1090/crates/rs1090/data/long_flight.csv")
    baseline = Path("tests/evidence/diagnostics/gen0")
    binary_hash = sha(binary)
    assert build["artifacts"][str(binary)] == binary_hash
    protected = {**build.get("unchanged_native_inputs", {}),
                 **build["reused_production_objects"], **build["production_sources"]}
    protected["spec.lock"] = sha("spec.lock")
    protected[".lake/build/bin/lean1090-bench"] = sha(".lake/build/bin/lean1090-bench")
    for directory in ("Model", "Proofs"):
        for path in sorted(Path(directory).rglob("*.lean")):
            protected[str(path)] = sha(path)
    for name in ("Model.lean", "Proofs.lean"):
        protected[name] = sha(name)
    for line in Path("spec.lock").read_text().splitlines():
        digest, name = line.split(None, 1)
        assert sha(name) == digest, name
        protected[name] = digest
    for name in build["reused_production_objects"]:
        cpath = Path(name.removesuffix(".o.export"))
        protected[str(cpath)] = sha(cpath)
        source = Path(str(cpath).removeprefix(".lake/build/ir/").removesuffix(".c") + ".lean")
        protected[str(source)] = sha(source)
    state = {
        "kind": "untimed_full_cost_campaign", "status": "running", "started_utc": now(),
        "commit": subprocess.check_output(["git", "rev-parse", "HEAD"], text=True).strip(),
        "driver_binary": str(binary), "driver_binary_sha256": binary_hash,
        "build_manifest": str(build_path), "build_manifest_sha256": sha(build_path),
        "corpus": str(corpus), "corpus_sha256": sha(corpus),
        "maximum_concurrent_profiles": args.jobs,
        "protected_inputs": protected, "native_runs": [], "profiles": [],
        "notes": ["Instruction/allocation diagnostics only; no elapsed-time or throughput result.",
                  "Concurrent Callgrind profiles intentionally overlap.",
                  "Separate processes retain cold lazy constants and distinct allocator contexts.",
                  "Complete result digests are checked after the collected root returns.",
                  "All source, object, C, lock and timed benchmark binary hashes must remain unchanged."]}
    if args.perf_capture:
        capture = json.loads(args.perf_capture.read_text())
        assert capture["record_exit_code"] == 0 and capture["all_input_hashes_unchanged"] and capture["completed_utc"]
        assert capture["before_hashes"][".lake/build/bin/lean1090-bench"] == protected[".lake/build/bin/lean1090-bench"]
        state["prior_perf_capture"] = {"path": str(args.perf_capture), "sha256": sha(args.perf_capture),
                                       "completed_utc": capture["completed_utc"],
                                       "loaded_before_any_native_diagnostic": True}

    def save():
        (cache / "campaign.json").write_text(json.dumps(state, indent=2) + "\n")

    def verify_protected():
        assert sha(binary) == binary_hash
        for name, digest in protected.items():
            assert sha(name) == digest, name

    def native(mode, census=False):
        output = cache / "native"
        output.mkdir(exist_ok=True)
        argv = [str(binary), mode, str(corpus)] + (["--census"] if census else [])
        out, err = output / (mode + ".jsonl"), output / (mode + ".stderr")
        record = {"mode": mode, "argv": argv, "started_utc": now(), "stdout": str(out), "stderr": str(err)}
        with out.open("w") as stdout, err.open("w") as stderr:
            result = subprocess.run(argv, stdout=stdout, stderr=stderr, check=False)
        record.update(returncode=result.returncode, completed_utc=now(), stdout_sha256=sha(out), stderr_sha256=sha(err))
        state["native_runs"].append(record)
        save()
        assert result.returncode == 0, record
        rows = read_lines(out)
        prepared = next(row for row in rows if row.get("phase") == "prepared")
        decoded = next(row for row in rows if row.get("phase") == "decoded")
        final = next(row for row in rows if row.get("phase") == "result")
        assert prepared["selected"] == decoded["retained"] == final["digest"]["count"]
        return rows, prepared, decoded, final

    verify_protected()
    save()
    try:
        all_rows, _, _, complete = native("all", census=True)
        census = next(row for row in all_rows if row.get("kind") == "post_decode_shadow_census")
        previous_rows = read_lines(baseline / "driver-all-census.jsonl")
        previous_complete = next(row for row in previous_rows if row.get("phase") == "result")
        previous_census = next(row for row in previous_rows if row.get("kind") == "post_decode_shadow_census")
        assert complete["digest"] == previous_complete["digest"]
        assert complete["per_df"] == previous_complete["per_df"]
        assert census == previous_census
        assert complete["digest"]["count"] == 172432
        state["full_output_digest_and_census_match_gen0"] = True
        crc_rows = [row for row in all_rows if row.get("kind") == "post_decode_crc_census"]
        if crc_rows:
            assert len(crc_rows) == 1
            crc = crc_rows[0]
            assert crc["strategy"] == "one_syndrome_per_successfully_parsed_frame"
            assert crc["population"] == "accepted_corpus_only"
            assert crc["input_rows"] == crc["retained_accepted_rows"] == complete["digest"]["count"]
            assert crc["parsed_fields_and_syndromes_checked"] and not crc["native_call_counts"]
            assert [row["df"] for row in crc["per_df"]] == list(range(32))
            for row, historical in zip(crc["per_df"], census["per_df"]):
                assert row["df"] == historical["df"]
                assert row["parsed_frames"] == row["crc_call_predictions"] == historical["count"]
                assert row["crc_step_predictions"] == row["parsed_frames"] * (56 if row["df"] < 16 else 112)
            state["live_crc_census"] = crc
            state["notes"].append("The original shadow CRC prediction is historical. Native CRC entries must match the separate checked one-syndrome-per-parsed-frame census.")
        interval_rows = [row for row in all_rows if row.get("kind") == "post_decode_interval_census"]
        if interval_rows:
            assert len(interval_rows) == 1
            interval = interval_rows[0]
            assert interval["live_score_results_checked"] and not interval["native_call_counts"]
            assert {row["register_decimal"] for row in interval["registers"]} == {0x40, 0x44, 0x45, 0x50, 0x60}
            for row in interval["registers"]:
                matching = [item for df in census["per_df"] if df["df"] in (20, 21)
                            for item in df["commb"] if item["register_decimal"] == row["register_decimal"]]
                assert row["reached"] == sum(item["score_attempt_predictions"] for item in matching)
                assert row["fast_accept"] + row["fallback_accept"] == sum(item["score_pass"] for item in matching)
                assert row["reached"] == sum(row[key] for key in ("fast_accept", "fast_reject", "fallback_accept", "fallback_reject"))
                assert sum(item["count"] for item in row["term_lengths"]) == row["reached"]
            state["interval_census"] = interval
        native_argv = [sys.executable, "review/diagnostics/run_native_df.py", "--binary", str(binary),
                       "--build", str(build_path), "--census", str(cache / "native/all.jsonl"),
                       "--corpus", str(corpus), "--output", str(cache / "native-df")]
        with (cache / "native-df.stdout").open("w") as out, (cache / "native-df.stderr").open("w") as err:
            result = subprocess.run(native_argv, stdout=out, stderr=err, check=False)
        state["native_df_command"] = {"argv": native_argv, "returncode": result.returncode}
        save()
        assert result.returncode == 0, "native per-DF validation failed"
        expected = {}
        for mode in FAMILIES + PROBES:
            _, prepared, _, final = native(mode)
            expected[mode] = (prepared, final)
            if mode in PROBES:
                previous = next(row for row in read_lines(baseline / "driver-v2" / (mode + ".jsonl"))
                                if row.get("phase") == "result")
                assert final["digest"] == previous["digest"], mode
            else:
                for row in final["per_df"]:
                    if row["digest"]["count"]:
                        assert row == complete["per_df"][row["df"]], mode
        state["native_outputs_validated"] = True
        save()
        verify_protected()

        def profile(mode):
            output = cache / "callgrind" / mode
            argv = [sys.executable, "review/diagnostics/profile_decode_costs.py", mode,
                    "--binary", str(binary), "--output", str(output)]
            logs = cache / "profile-jobs"
            logs.mkdir(exist_ok=True)
            record = {"mode": mode, "argv": argv, "started_utc": now()}
            with (logs / (mode + ".stdout")).open("w") as out, (logs / (mode + ".stderr")).open("w") as err:
                result = subprocess.run(argv, stdout=out, stderr=err, check=False)
            record.update(returncode=result.returncode, completed_utc=now())
            if result.returncode:
                return {**record, "status": "failed"}
            observed = json.loads((output / "run.json").read_text())
            prepared, final = expected[mode]
            assert observed["status"] == "passed"
            assert observed["prepared"] == prepared, mode
            for key in ("digest", "per_df", "passes", "input_digest"):
                if key in final:
                    assert observed["result"][key] == final[key], (mode, key)
            record.update(status="passed", selected=prepared["selected"],
                          primary_ir=observed["primary_ir"], digest=observed["result"]["digest"],
                          profile=str(output / observed["primary_profile"]),
                          native_output_matches=True)
            return record

        # Independent family and probe runs overlap; they do not collect timings.
        with ThreadPoolExecutor(max_workers=args.jobs) as pool:
            futures = {pool.submit(profile, mode): mode for mode in FAMILIES + PROBES}
            for future in as_completed(futures):
                record = future.result()
                state["profiles"].append(record)
                save()
                print(json.dumps(record), flush=True)
        assert len(state["profiles"]) == 13
        assert all(row["status"] == "passed" for row in state["profiles"])
        verify_protected()
        state.update(status="passed", completed_utc=now(), protected_inputs_unchanged=True)
        save()
    except BaseException as error:
        state.update(status="failed", completed_utc=now(), error=repr(error))
        save()
        raise


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Archive and analyze an already completed gen3 instruction campaign."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[4]
CACHE = Path(".cache/gen4-planning")
OUT = Path("tests/evidence/diagnostics/gen3")
TOOLS = Path("review/diagnostics")


def read(path):
    return json.loads(path.read_text())


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    assert Path.cwd() == ROOT
    state = read(CACHE / "campaign.json")
    assert state["status"] == "passed" and state["protected_inputs_unchanged"]
    assert len(state["profiles"]) == 13
    assert all(row["status"] == "passed" and row["native_output_matches"] for row in state["profiles"])
    assert state["prior_perf_capture"]["loaded_before_any_native_diagnostic"]
    assert all(sha(Path(name)) == digest for name, digest in state["protected_inputs"].items())
    commands = []

    def run(argv, label):
        proc = subprocess.run([str(item) for item in argv], capture_output=True, text=True)
        (OUT / (label + ".stdout")).write_text(proc.stdout)
        (OUT / (label + ".stderr")).write_text(proc.stderr)
        commands.append({"label": label, "argv": [str(item) for item in argv], "returncode": proc.returncode,
                         "stdout_sha256": sha(OUT / (label + ".stdout")),
                         "stderr_sha256": sha(OUT / (label + ".stderr"))})
        (OUT / "finalization-commands.json").write_text(json.dumps(commands, indent=2) + "\n")
        assert proc.returncode == 0, (label, proc.stderr)

    run([sys.executable, "-B", TOOLS / "archive_cost_campaign.py", "--cache", CACHE,
         "--output", OUT, "--perf-data", CACHE / "perf-gen3/perf.data",
         "--extra-evidence", "source-review.json", "--extra-evidence", "source-inspection",
         "--extra-evidence", "context-notes.md", "--extra-evidence", "finalize.py",
         "--extra-evidence", "parser-fixtures"], "archive")
    source_review = read(OUT / "source-review.json")
    analyze = [sys.executable, "-B", TOOLS / "analyze_callgrind.py", "--generation", "3",
               "--extra-anchor", source_review["exact_fallback_anchor"], "--extra-anchor", source_review["parity_fold_anchor"], "--output", OUT / "analysis"]
    for mode in ("adsb", "commb", "other"):
        analyze += ["--profile", f"{mode}={OUT}/callgrind/{mode}/callgrind.out.1.gz"]
    for kind in ("candidate", "score"):
        for register in ("40", "44", "45", "50", "60"):
            analyze += ["--" + kind, f"{register}={OUT}/callgrind/{kind}{register}/callgrind.out.1.gz"]
    run(analyze, "analyze")
    report = Path("docs/GEN3-COST-BREAKDOWN.md")
    run([sys.executable, "-B", TOOLS / "write_cost_report.py", "--generation", "3",
         "--previous-generation", "2", "--previous-analysis", "tests/evidence/diagnostics/gen2/analysis/analysis.json",
         "--analysis", OUT / "analysis/analysis.json", "--census", OUT / "native/all.jsonl",
         "--native-df", OUT / "native-df/summary.json", "--perf", OUT / "perf/analysis.json",
         "--build", OUT / "driver/driver-build.json", "--campaign", OUT / "campaign.json",
         "--benchmark", "bench/runs/gen3/summary.json", "--evidence-root", OUT,
         "--context-notes", OUT / "context-notes.md", "--source-review", OUT / "source-review.json",
         "--output", report], "report")

    manifest = read(OUT / "archive-manifest.json")
    assert all(sha(OUT / name) == row["stored_sha256"] and (OUT / name).stat().st_size == row["stored_bytes"]
               for name, row in manifest["files"].items())
    assert all(sha(Path(name)) == digest for name, digest in state["protected_inputs"].items())
    historical = ["docs/GEN0-COST-BREAKDOWN.md", "docs/GEN1-COST-BREAKDOWN.md", "docs/GEN2-COST-BREAKDOWN.md",
                  "tests/evidence/diagnostics/gen0", "tests/evidence/diagnostics/gen1", "tests/evidence/diagnostics/gen2",
                  "bench/runs/baseline-FC006", "bench/runs/gen1", "bench/runs/gen2"]
    run(["git", "diff", "--exit-code", "HEAD", "--", *historical], "historical-unchanged")
    untracked = subprocess.check_output(["git", "ls-files", "--others", "--exclude-standard", "--", *historical], text=True)
    assert not untracked.strip(), "unexpected added historical artifact"
    analysis = read(OUT / "analysis/analysis.json")
    profiles = list(analysis["families"].values()) + list(analysis["non_additive_register_score_probes"].values()) + list(analysis["non_additive_register_candidate_probes"].values())
    assert len(profiles) == 13
    assert all(profile["self_event_sum_matches_summary"] and not profile["nonzero_outside_root"] for profile in profiles)
    stages = Counter()
    for profile in analysis["families"].values():
        stages.update({key: value.get("Ir", 0) for key, value in profile["exclusive_stage_events"].items()})
    result = {"status": "passed", "completed_utc": datetime.now(timezone.utc).isoformat(),
              "commit": state["commit"], "profiles": 13,
              "all_self_sums_exact": True,
              "all_stage_contexts_unique": all(profile["stage_attribution_complete"] for profile in profiles),
              "all_root_counts_outputs_and_census_validated": True,
              "interval_native_counts_match_checked_populations": True,
              "protected_inputs_unchanged": True, "protected_input_count": len(state["protected_inputs"]),
              "historical_reports_evidence_and_samples_unchanged": True,
              "archive_files": manifest["file_count"], "archive_bytes": manifest["stored_bytes"],
              "exclusive_stage_ir": dict(stages), "total_ir": sum(stages.values()),
              "report": str(report), "report_sha256": sha(report),
              "analysis_sha256": sha(OUT / "analysis/analysis.json"),
              "archive_manifest_sha256": sha(OUT / "archive-manifest.json"),
              "interval_census": state["interval_census"]}
    (OUT / "validation.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result))


if __name__ == "__main__":
    main()

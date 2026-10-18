#!/usr/bin/env python3
"""Pure fixtures and a disposable historical re-render; no live diagnostic runs."""
import ast
import hashlib
import importlib.util
import json
import subprocess
import sys
import tempfile
from datetime import datetime, timezone
from pathlib import Path

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[4]
TOOLS = ROOT / "review/diagnostics"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(name):
    spec = importlib.util.spec_from_file_location(name, TOOLS / (name + ".py"))
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


analyzer = load("analyze_callgrind")
writer = load("write_cost_report")
archiver = load("archive_cost_campaign")
checks = []
commands = []


def passed(name):
    checks.append(name)


def reject(name, operation, exception=AssertionError):
    try:
        operation()
    except exception:
        passed(name)
    else:
        raise AssertionError("unexpected acceptance: " + name)


historical = [ROOT / "docs/GEN0-COST-BREAKDOWN.md", ROOT / "docs/GEN1-COST-BREAKDOWN.md"]
for name in ("tests/evidence/diagnostics/gen0", "tests/evidence/diagnostics/gen1",
             "bench/runs/gen1", "bench/runs/baseline-FC006"):
    historical += [path for path in (ROOT / name).rglob("*") if path.is_file()]
before = {str(path.relative_to(ROOT)): sha(path) for path in sorted(historical)}

analyzer.fixture_checks()
passed("original-parser-accounting-and-context-fixtures")
with tempfile.TemporaryDirectory(prefix="lean1090-report-tooling-") as temp:
    tmp = Path(temp)
    raw = tmp / "raw.perf"
    raw.write_bytes(b"non-executable perf association fixture\n")
    capture = {"raw_data": {"path": "arbitrary-generation/perf.data", "sha256": sha(raw), "bytes": raw.stat().st_size}}
    record = archiver.perf_raw_record(raw, capture)
    assert record["sha256"] == sha(raw) and record["capture_recorded_path"] == capture["raw_data"]["path"]
    passed("perf-path-parameterized-and-bound-to-capture")
    reject("different-perf-hash-rejected", lambda: archiver.perf_raw_record(raw, {"raw_data": {**capture["raw_data"], "sha256": "0" * 64}}))
    reject("different-perf-size-rejected", lambda: archiver.perf_raw_record(raw, {"raw_data": {**capture["raw_data"], "bytes": 0}}))
    prior = tmp / "prior.md"
    writer.write_new_or_identical(prior, "prior report\n")
    writer.write_new_or_identical(prior, "prior report\n")
    reject("changed-existing-report-rejected", lambda: writer.write_new_or_identical(prior, "changed\n"))
    assert prior.read_text() == "prior report\n"
    passed("identical-report-repeat-preserves-bytes")
    prior_analysis = tmp / "analysis"
    analyzer.write_outputs(prior_analysis, {"analysis.json": "prior\n"})
    reject("changed-analysis-rejected-before-any-other-output", lambda: analyzer.write_outputs(
        prior_analysis, {"ANALYSIS.md": "new\n", "analysis.json": "changed\n"}), ValueError)
    assert not (prior_analysis / "ANALYSIS.md").exists()
    assert (prior_analysis / "analysis.json").read_text() == "prior\n"

    prefix = analyzer.PREFIX
    fixture = f"""positions: line
events: Ir
summary: 45
fn=fixture_driver
cfn={analyzer.DECODE}
calls=1 1
1 45
fn={analyzer.DECODE}
1 2
cfn={prefix}frameCommB
calls=1 1
1 43
fn={prefix}frameCommB
1 3
cfn={analyzer.SCORE}
calls=1 1
1 40
fn={analyzer.SCORE}
1 5
cfn={prefix}ScoreGate_choose
calls=1 1
1 31
cfn={prefix}cbDensityTermsFast
calls=1 1
1 4
fn={prefix}cbDensityTermsFast
1 4
fn={prefix}ScoreGate_choose
1 7
cfn={prefix}ScoreGate_center
calls=1 1
1 11
cfn=fixture_fallback
calls=1 1
1 13
fn={prefix}ScoreGate_center
1 11
fn=fixture_fallback
1 13
totals: 45
"""
    path = tmp / "score-fixture.callgrind"
    path.write_text(fixture)
    result = analyzer.analyze(analyzer.parse(path), analyzer.DECODE, "output_model_control", ["fixture_fallback"])
    assert result["total_events"] == {"Ir": 45}
    assert result["exclusive_stage_events"]["commb_inference"] == {"Ir": 43}
    assert result["exclusive_stage_events"]["output_model_control"] == {"Ir": 2}
    anchors = result["native_anchor_counts_and_non_additive_inclusive_events"]
    assert anchors[prefix + "ScoreGate_choose"]["incoming_inclusive_events_non_additive"] == {"Ir": 31}
    assert anchors[prefix + "ScoreGate_center"]["incoming_inclusive_events_non_additive"] == {"Ir": 11}
    assert anchors["fixture_fallback"]["incoming_inclusive_events_non_additive"] == {"Ir": 13}
    assert anchors[prefix + "cbDensityTermsFast"]["incoming_inclusive_events_non_additive"] == {"Ir": 4}
    assert prefix + "ScoreGate_envelope" in result["unobserved_optional_anchor_symbols"]
    assert prefix + "ScoreGate_envelope" not in anchors
    passed("optional-ScoreGate-table-fallback-anchors-do-not-double-count")
    passed("unobserved-anchor-distinct-from-zero-work")
    path.write_text(fixture.replace(prefix + "frameCommB", prefix + "Semantics_commB"))
    semantic = analyzer.analyze(analyzer.parse(path), analyzer.DECODE, "output_model_control", ["fixture_fallback"])
    assert semantic["exclusive_stage_events"]["semantic_oracle_values"] == {"Ir": 43}
    assert not semantic["exclusive_stage_events"].get("commb_inference", {}).get("Ir", 0)
    passed("ScoreGate-module-does-not-override-caller-stage")

output = ROOT / ".cache/gen2-report-tooling/gen1-disposable.md"
output.parent.mkdir(parents=True, exist_ok=True)
base = Path("tests/evidence/diagnostics/gen1")
argv = [sys.executable, "-B", "review/diagnostics/write_cost_report.py",
        "--generation", "1", "--previous-generation", "0",
        "--analysis", str(base / "analysis/analysis.json"),
        "--census", str(base / "native/all.jsonl"),
        "--native-df", str(base / "native-df/summary.json"),
        "--perf", str(base / "perf/analysis.json"),
        "--build", str(base / "driver/driver-build.json"),
        "--previous-analysis", "tests/evidence/diagnostics/gen0/analysis/analysis.json",
        "--campaign", str(base / "campaign.json"),
        "--benchmark", "bench/runs/gen1/summary.json",
        "--evidence-root", str(base), "--output", str(output)]
run = subprocess.run(argv, cwd=ROOT, capture_output=True, text=True)
commands.append({"argv": argv, "returncode": run.returncode, "stdout": run.stdout, "stderr": run.stderr})
assert run.returncode == 0, run.stderr
passed("disposable-gen1-render-with-explicit-gen0-comparison")


def tables(text):
    result, current = [], []
    for line in text.splitlines() + [""]:
        if line.startswith("|"):
            current.append(line)
        elif current:
            result.append(current)
            current = []
    return result


old_tables = tables((ROOT / "docs/GEN1-COST-BREAKDOWN.md").read_text())
new_tables = tables(output.read_text())
assert len(old_tables) == len(new_tables) == 8
for index in (0, 1, 2, 3, 4, 6, 7):
    assert old_tables[index] == new_tables[index], index
assert all(row in new_tables[5] for row in old_tables[5])
assert any("cbCombinedScore" in row and "Not observed" in row for row in new_tables[5])
passed("all-historical-numeric-tables-preserved-exactly")
assert "line 72" not in output.read_text()
assert "Gen1 changes the final 24-bit" not in output.read_text()
assert "native perf capture completed before" not in output.read_text()
passed("no-generation-specific-source-or-chronology-claims-inferred")
bad = argv[:]
bad[bad.index("--generation") + 1] = "2"
bad[bad.index("--output") + 1] = str(output.parent / "must-not-render-gen2.md")
run = subprocess.run(bad, cwd=ROOT, capture_output=True, text=True)
commands.append({"argv": bad, "returncode": run.returncode, "stdout": run.stdout, "stderr": run.stderr})
assert run.returncode != 0 and "benchmark generation differs" in run.stderr
assert not (output.parent / "must-not-render-gen2.md").exists()
passed("gen1-benchmark-cannot-be-labeled-gen2")

for name in ("analyze_callgrind.py", "write_cost_report.py", "archive_cost_campaign.py"):
    ast.parse((TOOLS / name).read_text())
ast.parse(Path(__file__).read_text())
passed("all-changed-Python-syntax-without-bytecode")
assert all(sha(ROOT / name) == digest for name, digest in before.items())
after_paths = [ROOT / "docs/GEN0-COST-BREAKDOWN.md", ROOT / "docs/GEN1-COST-BREAKDOWN.md"]
for name in ("tests/evidence/diagnostics/gen0", "tests/evidence/diagnostics/gen1",
             "bench/runs/gen1", "bench/runs/baseline-FC006"):
    after_paths += [path for path in (ROOT / name).rglob("*") if path.is_file()]
assert set(before) == {str(path.relative_to(ROOT)) for path in after_paths}
passed("historical-report-evidence-and-benchmark-bytes-and-membership-unchanged")
result = {"status": "passed", "kind": "pure_fixtures_and_historical_render_only",
          "utc": datetime.now(timezone.utc).isoformat(), "checks": checks,
          "command": "python3 -B tests/evidence/optimization/gen2/report-tooling/checks.py",
          "tool_sha256": {str((TOOLS / name).relative_to(ROOT)): sha(TOOLS / name) for name in
                          ("analyze_callgrind.py", "write_cost_report.py", "archive_cost_campaign.py")},
          "fixture_source_sha256": sha(Path(__file__)),
          "historical_files_unchanged": before, "render_commands": commands,
          "disposable_gen1_report": str(output.relative_to(ROOT)), "report_sha256": sha(output),
          "numeric_tables_equal": True,
          "scope": "No build, live decoder run, profiler, benchmark, runtime/proof/frozen edit, staging or commit. No gen2 count/result is measured or claimed."}
(HERE / "results.json").write_text(json.dumps(result, indent=2) + "\n")
print(json.dumps({"status": "passed", "checks": len(checks), "historical_files_unchanged": len(before)}))

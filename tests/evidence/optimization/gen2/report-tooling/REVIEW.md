# Generation-independent diagnostic reporting

Only `review/diagnostics/analyze_callgrind.py`, `write_cost_report.py` and `archive_cost_campaign.py` changed in this maintenance task. There is no gen2 measurement or result here.

The report writer requires `--generation` and pairs `--previous-analysis` with `--previous-generation`. Its default report/evidence paths follow the requested generation. For nonzero generations it checks that the benchmark's recorded generation matches, in addition to the existing binary, commit, corpus, build, profile and source/object associations. Comparison labels use the supplied generations. Hardcoded parity explanations, C line numbers, perf chronology and optimization advice were removed. Optional `--context-notes` accepts separately reviewed Markdown and records its hash; source-specific explanations and initialization/fallback observations must be established from the actual run. Existing reports cannot be overwritten with different content.

The analyzer accepts `--generation`, optional `--title`, and repeatable `--extra-anchor EXACT_NATIVE_SYMBOL`. Its optional built-in anchors name the actual source definitions `cbDensityTermsFast`, `cbDensityTableGet`, `cbDensityTerms` and `ScoreGate.mass/center/envelope/choose`. These retain caller-stage attribution and only add overlapping inclusive observations; they never change the exclusive self-cost partition. A fallback thunk's exact native symbol can be supplied after generated-C/call-path inspection. An unobserved or inlined symbol is listed separately and is not reported as zero work or a zero fallback population. Existing analysis output cannot be replaced with different content.

The archiver accepts an explicit `--perf-data PATH`. It verifies that file's SHA-256 and byte count against `output/perf/capture.json` and records the capture's original path. A capture with raw-data provenance requires this argument. It no longer searches a hardcoded `perf-gen1` path or silently omits a recorded capture.

Validation executed:

```sh
python3 -B tests/evidence/optimization/gen2/report-tooling/checks.py
git diff --check -- review/diagnostics/analyze_callgrind.py review/diagnostics/write_cost_report.py review/diagnostics/archive_cost_campaign.py
```

All 16 checks pass. The original accounting/parser fixtures still pass. New fixtures check ScoreGate/table/fallback overlapping costs, caller-stage inheritance, absence versus zero, perf association failures and refusal to overwrite prior outputs. A disposable generation-1 report with explicit generation-0 comparison reproduces every historical numerical table exactly; an attempted generation-2 label using the generation-1 benchmark is rejected without writing a report. All 979 files in the two historical diagnostic archives/reports and baseline/gen1 benchmark artifacts retain identical bytes and membership. Commands, new tool hashes and retained historical hashes are in `results.json`. No historical report or evidence file changed.

For the next diagnostic, explicitly pass the actual generation, preceding-generation analysis, new evidence/output paths and matching benchmark record. Inspect the final generated C to identify live score roots, any inlined boundary, fallback call path and table initialization placement; add only verified native anchor names. Collect new census, profiles and perf evidence, then provide run-specific notes grounded in those artifacts. The current fixtures establish tooling behavior, not those future observations. No compiler, decoder, profiler, benchmark, runtime/proof/frozen-file edit, staging or commit ran during this task.

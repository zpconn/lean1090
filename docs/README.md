# Documentation

Start with the [project README](../README.md), then follow the evidence that
matters for your use case.

| Topic | Read |
| --- | --- |
| Supported messages, fields and policies | [Scope](../SCOPE.md) |
| Guarantees and their limits | [Theorems](../THEOREMS.md), [trusted computing base](../TRUSTED.md) |
| Standards and published examples | [Sources](SOURCES.md), [example coverage](EXAMPLE-COUNTS.md), [layout anchors](LAYOUT-ANCHORS.md) |
| Compatibility with rs1090 | [Discrepancies](../DISCREPANCIES.md), [numeric presentation](NUMERICAL-PRESENTATION.md) |
| Unit and differential testing | [Upstream unit port](UPSTREAM-UNIT-PORT.md), [fuzzing](FUZZING.md), [CPR tracking](CPR-TRACKING-DIFFERENTIAL.md) |
| Performance | [Benchmark method](../bench/BENCHMARK.md), [generation 10 results](../bench/GEN10.md), [all results](../bench/results.csv) |
| Optimization evidence | [Workflow](OPTIMIZATION.md), [initial costs](GEN0-COST-BREAKDOWN.md), [latest pre-change costs](GEN9-COST-BREAKDOWN.md), [QNH table proof](GEN10-QNH-TABLE.md) |
| Review and project history | [Frozen changes](FROZEN-CHANGES.md), [progress](../PROGRESS.md), [original goal](../GOAL.md) |

The [throughput chart](images/throughput.svg) and [animation](images/throughput.gif)
are generated solely from `bench/results.csv`. Their [data manifest](images/throughput-data.json)
records all plotted rows, calculations, frames and file hashes. Regenerate them
with the existing plotting environment:

```sh
.cache/venv/bin/python review/presentation/render_throughput.py
```

Detailed validation transcripts and retained artifacts are under
[`tests/evidence/`](../tests/evidence/); per-generation raw benchmark samples and
build/environment records are under [`bench/runs/`](../bench/runs/).

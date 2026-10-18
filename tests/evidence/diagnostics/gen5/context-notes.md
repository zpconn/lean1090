Generation 5 replaces repeated software-binary64 Mach conversion with one immutable 1,024-entry exact value table keyed only by `payloadBits word 25 10`. The actual timed-worker source/C/object/trace binding and retained assembly are in [source-review.json](../tests/evidence/diagnostics/gen5/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen5/source-inspection/). The field-indexed table loads in the hard-validity, penalty and slow-density callers are the live implementation.

**The standalone `cbMach64` native boundary is absent because Clang inlines it. This does not mean zero Mach work.** No separate `cbMach64` context is observed in these profiles. Its field extraction, array access and reference handling remain in retained callers. Therefore this report does not subtract its former inclusive cost as a measured saving, or equate absent entry counts with an eliminated computation. The exclusive stage and candidate/score measurements remain the primary comparisons.

The following retained caller-boundary observations compare the same corpus populations. They overlap each other and the exclusive stages; only the self-event partition is additive. Full per-stage observations, including the previously separate Mach boundary, are in [helper-comparison.json](../tests/evidence/diagnostics/gen5/helper-comparison.json).

| Native boundary in Comm-B inference | Gen4 entries | Gen5 entries | Gen4 self Ir | Gen5 self Ir | Gen4 inclusive Ir | Gen5 inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| `cbValid60` | 64,315 | 64,315 | 3,465,240 | 4,012,830 | 2,658,427,652 | 265,251,855 |
| `cbPenalty` | 45,510 | 45,510 | 5,052,286 | 5,305,298 | 3,312,119,289 | 2,092,418,992 |
| `Binary64_round` | 216,787 | 108,963 | 35,369,698 | 18,214,338 | 6,003,977,068 | 3,011,442,290 |
| `payloadBits` | 3,121,720 | 3,121,720 | 187,303,200 | 187,303,200 | 187,303,200 | 187,303,200 |

The Mach value table is constructed with the original software multiplication/division sequence during module initialization and then marked persistent. Its construction and the existing 13 density-table initializations precede `main`, outside decoder-root collection and warmed benchmark loops. Other software arithmetic remains live, including the IAS/Mach penalty division. Scalar lazy constants and allocator state can still differ across these single-pass diagnostic processes; no unmeasured correction is applied.

The CRC fold, payload extraction, exact interval gate and callable boxed full-software fallback retain their existing live paths. The report reconciles observed CRC and interval/fallback native entries with the checked corpus census. A missing small helper symbol is never substituted for a logical decision count.

Native perf capture completed before any native census or Callgrind worker began. Later family/probe jobs intentionally overlapped, with at most six active profiles. Other agents performed read-only review and benchmark-report archival; host-wide isolation is not claimed. Sampling exclusions and unwind limitations are retained in [perf/README.md](../tests/evidence/diagnostics/gen5/perf/README.md). These conditional sample observations are not a whole-decoder timing decomposition.

Grouped helper inclusive values are raw incoming-edge observations. Recursive/re-entrant visits can overlap within a row, and descendants can cross a later stage boundary. They must not be added to stage totals or interpreted as predicted speedups. No production or frozen source was changed during this diagnostic.

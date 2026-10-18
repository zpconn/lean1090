# Generation 0: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `ff450a1faafe5d45076ce1ccc7cb1bef69cea12b` over all 172,432 corpus messages before optimization. The largest attributed instruction category is **Frame / CRC**, with 62,345,119,641 of 130,942,672,972 collected guest instructions (47.61%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The accepted generation-0 benchmark remains decode **0.1663×** and CPR **0.1562×**. This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

The family and supplemental Callgrind jobs overlapped on this machine. They count instrumented guest instructions and make no timing or throughput claim. This deliberately supersedes the earlier tool-options suggestion to use one profiler at a time. The native perf capture happened earlier, before these family/probe jobs. The eventual frozen generation benchmark must stop every build, test, profiler and agent task before timing.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 31,700,655,805 | 629,168.5 | 24.21% |
| commb | 47,714 | 88,431,524,379 | 1,853,366.4 | 67.53% |
| other | 74,333 | 10,810,492,788 | 145,433.3 | 8.26% |
| Total | 172,432 | 130,942,672,972 | 759,387.3 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Frame / CRC | 23,788,096,198 | 27,907,684,178 | 10,649,339,265 | 62,345,119,641 | 47.61% |
| Comm-B candidate inference / raw records | 0 | 49,856,067,626 | 0 | 49,856,067,626 | 38.07% |
| Semantic / oracle value construction | 6,071,659,962 | 10,648,646,490 | 145,560,251 | 16,865,866,703 | 12.88% |
| ADS-B fields / checks | 1,829,052,295 | 477,140 | 743,330 | 1,830,272,765 | 1.40% |
| Output-model construction / residual control | 11,847,350 | 18,648,945 | 14,849,942 | 45,346,237 | 0.03% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached software-binary64 score gate, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 12,313,662,763 | 10,655,164,905 |
| BDS44 | 47,166 | 0 | 0 | 154,393,343 | 0 |
| BDS45 | 47,166 | 0 | 0 | 146,497,929 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 9,603,117,158 | 8,825,831,299 |
| BDS60 | 47,166 | 19,356 | 17,149 | 20,567,665,916 | 18,530,767,712 |

BDS44 and BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.

## Native allocation counts and output checks by DF

`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.

| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |
|---|---:|---:|---:|---|
| 0 | 21,393 | 3,315,770 | 154.99 | Yes |
| 4 | 8,841 | 1,244,026 | 140.71 | Yes |
| 5 | 2,949 | 412,861 | 140.00 | Yes |
| 11 | 38,456 | 2,653,465 | 69.00 | Yes |
| 16 | 2,694 | 1,074,907 | 399.00 | Yes |
| 17 | 31,395 | 16,784,850 | 534.63 | Yes |
| 18 | 18,990 | 4,260,956 | 224.38 | Yes |
| 20 | 29,460 | 32,463,313 | 1101.95 | Yes |
| 21 | 18,254 | 20,128,705 | 1102.70 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 82,338,629 small allocations. The sum of separate DF loops is 82,338,853, a difference of 224. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 5,007,164,523 |
| `frameSyndrome` | 287,418 | 57,240,414,024 |
| `Parity_checksum` | 287,418 | 54,594,772,566 |
| `Parity_step` | 26,320,784 | 28,912,043,568 |
| `cbDensity` | 45,510 | 32,381,099,557 |
| `cbPenalty` | 45,510 | 3,673,748,514 |
| `Semantics_adsb` | 51,212 | 5,874,186,894 |
| `Semantics_commB` | 46,440 | 10,179,893,786 |

CRC-only contexts further separate fixed-width remainder work from extraction of bits from the complete word. The following inclusive costs overlap: for example, `Parity.step` calls `BitVec.ofNat`, which can call `Nat.pow`. They must not be added, subtracted as if disjoint, or extrapolated to predicted speedups. Non-CRC uses of the same helpers are excluded by their observed caller context.

| CRC-only helper | Native entries | Inclusive Ir | Share of frame/CRC Ir (overlapping) |
|---|---:|---:|---:|
| `Parity_step` | 26,320,784 | 28,912,043,568 | 46.37% |
| `l_BitVec_ofNat` | 27,279,319 | 29,068,838,748 | 46.63% |
| `l_Nat_testBit` | 26,320,784 | 21,956,735,844 | 35.22% |
| `lean_nat_pow` | 29,732,848 | 30,511,259,275 | 48.94% |
| `lean_nat_big_shiftr` | 20,450,752 | 11,892,867,248 | 19.08% |

The DF11 calibration separately observed exactly 38,456 decode/frame/CRC entries and 2,153,536 parity steps (56 per message), matching the shadow census. It is not added again to the three-family totals.

The retained generation-0 generated C makes the cost boundaries concrete: [Impl/Parity.c](../tests/evidence/diagnostics/gen0/generated-c/Impl/Parity.c) lines 78 and 88 call generic `l_BitVec_ofNat` with width 24 on every step; lines 121 and 123 call `l_Nat_testBit` and `Parity.step` for each bit. Line 156 uses `lean_obj_once` for the syndrome's zero constant. Source-level repetition is therefore checked against the actual generated program, not inferred only from function names.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the original generation-0 benchmark binary retained 1,166 samples; 590 had a visible live `Impl.decode` ancestor. Within those visible stacks, report parity/address had 205 samples and Comm-B inference/raw fields had 247. This independently points to the same expensive code families, but missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. That capture allowed a possible small concurrent diagnostic-driver compilation; strict isolation is not claimed for it either.

## Consequences for the first optimization

Start with the measured **Frame / CRC** cost, then rerun this diagnostic after the change. The generated C and live source show repeated Nat/GMP operations in parity and exact Rat/software-binary64 arithmetic in Comm-B scoring. Which part is improved must be justified by the measured cost and the unchanged refinement theorem, then evaluated with the frozen benchmark protocol.

For Comm-B, the approved direction remains immutable per-field-code tables of exact density terms, proved integer/rational gate decisions and a full-model fallback within a proved rounding interval around −3. No hardware Float trusted primitive, corpus-keyed table, message cache or frozen change is introduced by this diagnostic.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `ff450a1faafe5d45076ce1ccc7cb1bef69cea12b`; its build manifest records every object/source SHA-256 and compiler/link command. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen0/analysis/analysis.json](../tests/evidence/diagnostics/gen0/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen0/native-df/complete-corpus-census.jsonl](../tests/evidence/diagnostics/gen0/native-df/complete-corpus-census.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen0/native-df/summary.json](../tests/evidence/diagnostics/gen0/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen0/perf/analysis.json](../tests/evidence/diagnostics/gen0/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen0/driver-v3/driver-build.json](../tests/evidence/diagnostics/gen0/driver-v3/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen0/callgrind-v3/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen0/analysis/analysis.json` | `8d11cfbb26c548911f52277b8acec43ca1d6d6064e29bff5d7ee21ab88f0b598` |
| `tests/evidence/diagnostics/gen0/native-df/complete-corpus-census.jsonl` | `18ce145781bbb1519736524639cdef59990c6dc7c10701602463d2e381d12d7c` |
| `tests/evidence/diagnostics/gen0/native-df/summary.json` | `6d408a9983447a93a1167320cc45700ca2457bd6db995dac3175f5e884fb240b` |
| `tests/evidence/diagnostics/gen0/perf/analysis.json` | `ef2069b53ef24335f8b265cfc8b396a98a84f1db510e1a83c32ba3cab734616b` |
| `tests/evidence/diagnostics/gen0/driver-v3/driver-build.json` | `7388711e7094fcad3b0d6d49bb9b094d00e2bac994d6fd2089a6f9b2d14f2309` |

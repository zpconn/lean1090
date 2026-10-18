# Generation 1: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `1cec196fd30565c70573fb28b7d555c4c4b71d32` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 49,856,076,161 of 103,138,318,751 collected guest instructions (48.34%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-1 benchmark is decode **0.20945×** and CPR **0.19426×**; see [bench/runs/gen1/summary.json](../bench/runs/gen1/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

The family and supplemental Callgrind jobs overlapped on this machine. They count instrumented guest instructions and make no timing or throughput claim. The native perf capture completed before these family/probe jobs. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 22,024,838,792 | 437,130.9 | 21.35% |
| commb | 47,714 | 77,140,852,912 | 1,616,734.1 | 74.79% |
| other | 74,333 | 3,972,627,047 | 53,443.7 | 3.85% |
| Total | 172,432 | 103,138,318,751 | 598,139.1 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 0 | 49,856,076,161 | 0 | 49,856,076,161 | 48.34% |
| Frame / CRC | 14,112,285,957 | 16,617,012,946 | 3,811,472,836 | 34,540,771,739 | 33.49% |
| Semantic / oracle value construction | 6,071,656,374 | 10,648,638,306 | 145,559,633 | 16,865,854,313 | 16.35% |
| ADS-B fields / checks | 1,829,052,295 | 477,140 | 743,330 | 1,830,272,765 | 1.77% |
| Output-model construction / residual control | 11,844,166 | 18,648,359 | 14,851,248 | 45,343,773 | 0.04% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Comparison with generation 0

Both diagnostics use the same corpus populations, complete output digests, control-flow census and retained stage boundaries. Gen1 changes the final 24-bit reduction in `Parity.step`; it preserves the live decode/checksum/step and semantic/inference symbols used for attribution. Absolute counts and instruction counts per message are compared below; changing shares alone would hide denominator changes.

| Exclusive stage | Gen0 Ir | Gen1 Ir | Difference (gen1 − gen0) | Gen1/gen0 | Gen0 Ir/message | Gen1 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 49,856,067,626 | 49,856,076,161 | +8,535 | 1.00000 | 289,134.66 | 289,134.71 |
| Frame / CRC | 62,345,119,641 | 34,540,771,739 | -27,804,347,902 | 0.55403 | 361,563.51 | 200,315.32 |
| Semantic / oracle value construction | 16,865,866,703 | 16,865,854,313 | -12,390 | 1.00000 | 97,811.70 | 97,811.63 |
| ADS-B fields / checks | 1,830,272,765 | 1,830,272,765 | +0 | 1.00000 | 10,614.46 | 10,614.46 |
| Output-model construction / residual control | 45,346,237 | 45,343,773 | -2,464 | 0.99995 | 262.98 | 262.97 |
| Total | 130,942,672,972 | 103,138,318,751 | -27,804,354,221 | 0.78766 | 759,387.31 | 598,139.09 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached software-binary64 score gate, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 12,313,662,587 | 10,655,165,733 |
| BDS44 | 47,166 | 0 | 0 | 154,393,343 | 0 |
| BDS45 | 47,166 | 0 | 0 | 146,497,929 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 9,603,110,920 | 8,825,831,299 |
| BDS60 | 47,166 | 19,356 | 17,149 | 20,567,659,678 | 18,530,774,853 |

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
| `decodeFrame` | 172,432 | 5,007,156,401 |
| `frameSyndrome` | 287,418 | 29,436,071,392 |
| `Parity_checksum` | 287,418 | 26,790,434,753 |
| `Parity_step` | 26,320,784 | 1,107,759,784 |
| `cbDensity` | 45,510 | 32,381,103,061 |
| `cbPenalty` | 45,510 | 3,673,748,282 |
| `Semantics_adsb` | 51,212 | 5,874,182,579 |
| `Semantics_commB` | 46,440 | 10,179,887,879 |

CRC-only contexts further separate fixed-width remainder work from extraction of bits from the complete word. The following inclusive costs overlap: a high-level parity helper can call the Nat/GMP helpers below it. They must not be added, subtracted as if disjoint, or extrapolated to predicted speedups. Non-CRC uses of the same helpers are excluded by their observed caller context. A zero native-symbol count does not imply that all semantically related work disappeared.

| CRC-only helper | Native entries | Inclusive Ir | Share of frame/CRC Ir (overlapping) |
|---|---:|---:|---:|
| `Parity_step` | 26,320,784 | 1,107,759,784 | 3.21% |
| `l_BitVec_ofNat` | 958,535 | 1,274,090,844 | 3.69% |
| `l_Nat_testBit` | 26,320,784 | 21,956,741,989 | 63.57% |
| `lean_nat_pow` | 3,412,064 | 3,453,493,323 | 10.00% |
| `lean_nat_big_shiftr` | 20,450,752 | 11,892,867,712 | 34.43% |

The retained generation-1 generated C makes the changed path concrete: [tests/evidence/diagnostics/gen1/generated-c/Impl/Parity.c](../tests/evidence/diagnostics/gen1/generated-c/Impl/Parity.c) line 72 calls `lean_nat_mod` with constant 16,777,216 inside `Parity.step`. Its per-bit generic `BitVec.ofNat` call is gone. `Nat.testBit` remains at line 126; other `BitVec.ofNat` calls remain at lines 153, 220 and 222, and line 161 retains the lazy syndrome constant. The reduction did not remove every CRC use of generic bit-vector/Nat helpers.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-1 benchmark binary retained 969 samples; 470 had a visible live `Impl.decode` ancestor. Within those visible stacks, report parity/address had 105 samples and Comm-B inference/raw fields had 236. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The diagnostic driver compilation finished before this capture, and native driver/Callgrind runs began after it. Other agents performed read-only review; host-wide isolation is not claimed. This is still a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost, then rerun this diagnostic after the change. The generated C and live source show repeated Nat/GMP operations in parity and exact Rat/software-binary64 arithmetic in Comm-B scoring. Which part is improved must be justified by the measured cost and the unchanged refinement theorem, then evaluated with the frozen benchmark protocol.

For Comm-B, the approved direction remains immutable per-field-code tables of exact density terms, proved integer/rational gate decisions and a full-model fallback within a proved rounding interval around −3. No hardware Float trusted primitive, corpus-keyed table, message cache or frozen change is introduced by this diagnostic.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `1cec196fd30565c70573fb28b7d555c4c4b71d32`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen1/analysis/analysis.json](../tests/evidence/diagnostics/gen1/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen1/native/all.jsonl](../tests/evidence/diagnostics/gen1/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen1/native-df/summary.json](../tests/evidence/diagnostics/gen1/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen1/perf/analysis.json](../tests/evidence/diagnostics/gen1/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen1/driver/driver-build.json](../tests/evidence/diagnostics/gen1/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen1/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen1/analysis/analysis.json` | `8041410ed8937d3582a7185f8effa8a6ea771c90f64bc272b24b012cbbdf9c09` |
| `tests/evidence/diagnostics/gen1/native/all.jsonl` | `18ce145781bbb1519736524639cdef59990c6dc7c10701602463d2e381d12d7c` |
| `tests/evidence/diagnostics/gen1/native-df/summary.json` | `83c073740849aee430e0d5a007a897208a5f06d3f314acba51a4d71a0cadb285` |
| `tests/evidence/diagnostics/gen1/perf/analysis.json` | `c9b833696d1fd6948e264e0e4afbbbd2de5d21f5a44011db7cfa34107f901f3b` |
| `tests/evidence/diagnostics/gen1/driver/driver-build.json` | `a09a84f2ecf6be2ebcf40b5e0af97908e9a06a71e8b53714117ebd1592d5063e` |
| `tests/evidence/diagnostics/gen0/analysis/analysis.json` | `8d11cfbb26c548911f52277b8acec43ca1d6d6064e29bff5d7ee21ab88f0b598` |
| `tests/evidence/diagnostics/gen1/campaign.json` | `84c41537f397fe7887336c13ba38e5b9e9921b1842ad3ace3485bea4d9e229a1` |
| `bench/runs/gen1/summary.json` | `00f0fad59773d895e82525f0bcfd4ef81a590031a36f4e211aab7ec1b244632e` |

# Generation 17: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `9d441eb3bdbaa17adbb289c3d82afe20307ad28b` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 3,612,702,286 of 10,744,218,389 collected guest instructions (33.62%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-17 benchmark is decode **1.66937×** and CPR **1.15046×**; see [bench/runs/gen17/summary.json](../bench/runs/gen17/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 2,125,760,444 | 42,190.3 | 19.79% |
| commb | 47,714 | 7,620,499,248 | 159,712.0 | 70.93% |
| other | 74,333 | 997,958,697 | 13,425.5 | 9.29% |
| Total | 172,432 | 10,744,218,389 | 62,309.9 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 3,610,207,926 | 1,486,660 | 3,612,702,286 | 33.62% |
| Frame / CRC | 1,280,047,941 | 1,381,691,321 | 835,274,887 | 3,497,014,149 | 32.55% |
| Semantic / oracle value construction | 622,484,542 | 2,609,698,929 | 145,561,375 | 3,377,744,846 | 31.44% |
| ADS-B fields / checks | 209,397,897 | 477,140 | 743,330 | 210,618,367 | 1.96% |
| Output-model construction / residual control | 12,822,364 | 18,423,932 | 14,892,445 | 46,138,741 | 0.43% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Shared-syndrome census and native entries

The original shadow census is retained exactly for historical comparison; its repeated-CRC prediction is not the current expectation. A separate post-decode census reparses every corpus row, checks its frame and syndrome against the retained decoder result, and predicts one syndrome after successful parsing. This work occurs after collection and does not enter the decoder-root counters.

All 172,432 corpus rows are accepted, as required by the complete retained-output check. This census covers that accepted corpus only. It does not measure malformed frames or frames rejected after parsing; the latter now compute a syndrome before rejection, as documented by the source/native review.

| Family | Historical repeated-call prediction | Live one-per-frame prediction | Observed frameSyndrome / checksum entries | Observed UInt32 loop entries |
|---|---:|---:|---:|---:|
| adsb | 81,780 | 50,385 | 50,385 / 50,385 | 50,385 |
| commb | 95,428 | 47,714 | 47,714 / 47,714 | 47,714 |
| other | 110,210 | 74,333 | 74,333 / 74,333 | 74,333 |

The checked corpus implies 15,300,600 bit updates, but this is a mathematical iteration prediction, not an observed function-entry count. The UInt32 step is inlined into the live loop; no standalone `Parity.step` entries are observed. Source and actual native inspection establish the live update, one loop per syndrome, the retained arbitrary-width fallback and one final result projection. Absence of the old step boundary is not zero CRC computation.

The new acceptance/address helpers keep their predecessor stages when they retain a native boundary. Acceptance control inlined into `decode` remains in that function's residual-control category; its called hard-validity helper retains the ADS-B category. No cost is reassigned by source-level intention. The renamed report helper retains the same report/semantic boundaries. These compiler-boundary changes must be considered when comparing stage deltas.

## Comparison with generation 16

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen16 Ir | Gen17 Ir | Difference (gen17 − gen16) | Gen17/gen16 | Gen16 Ir/message | Gen17 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 3,617,157,311 | 3,612,702,286 | -4,455,025 | 0.99877 | 20,977.30 | 20,951.46 |
| Frame / CRC | 3,496,990,936 | 3,497,014,149 | +23,213 | 1.00001 | 20,280.41 | 20,280.54 |
| Semantic / oracle value construction | 3,377,757,626 | 3,377,744,846 | -12,780 | 1.00000 | 19,588.93 | 19,588.85 |
| ADS-B fields / checks | 210,610,391 | 210,618,367 | +7,976 | 1.00004 | 1,221.41 | 1,221.46 |
| Output-model construction / residual control | 46,159,002 | 46,138,741 | -20,261 | 0.99956 | 267.69 | 267.58 |
| Total | 10,748,675,266 | 10,744,218,389 | -4,456,877 | 0.99959 | 62,335.73 | 62,309.89 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 516,575,831 | 381,794,701 |
| BDS44 | 47,166 | 0 | 0 | 11,836,862 | 0 |
| BDS45 | 47,166 | 0 | 0 | 11,932,998 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 713,784,427 | 506,955,914 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,054,157,327 | 899,495,979 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen17/independent-review/source-review.json](../tests/evidence/diagnostics/gen17/independent-review/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


BDS44, BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.

## Native allocation counts and output checks by DF

`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.

| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |
|---|---:|---:|---:|---|
| 0 | 21,393 | 556,073 | 25.99 | Yes |
| 4 | 8,841 | 165,424 | 18.71 | Yes |
| 5 | 2,949 | 53,083 | 18.00 | Yes |
| 11 | 38,456 | 499,929 | 13.00 | Yes |
| 16 | 2,694 | 102,373 | 38.00 | Yes |
| 17 | 31,395 | 5,148,462 | 163.99 | Yes |
| 18 | 18,990 | 841,975 | 44.34 | Yes |
| 20 | 29,460 | 7,690,847 | 261.06 | Yes |
| 21 | 18,254 | 4,841,234 | 265.21 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 19,899,228 small allocations. The sum of separate DF loops is 19,899,400, a difference of 172. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 1,107,357,927 |
| `frameSyndrome` | 172,432 | 2,299,432,438 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,241,739 |
| `reportWithSyndrome` | 172,432 | 7,303,660,476 |
| `Parity_checksum` | 172,432 | 1,279,410,019 |
| `Parity_syndrome` | 172,432 | 1,119,219,468 |
| `Parity_step` | Not observed in collected call contexts | Not assigned |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 516,914,042 |
| `Semantics_adsb` | 51,212 | 586,824,749 |
| `Semantics_commB` | 46,440 | 2,290,145,991 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `_init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1` | Not observed in collected call contexts | Not assigned |
| `initialize_lean1090_Impl_Binary64` | Not observed in collected call contexts | Not assigned |
| `l_Rat_div` | 52,831 | 241,148,243 |
| `lean_cstr_to_nat` | 50,390 | 38,900,980 |
| `Binary64_div` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwo` | 1,324 | 116,512 |
| `Binary64_powerTwoFormula` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwoTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `Binary64_round` | 662 | 15,433,570 |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,232,767,155 |
| `ScoreGate_commonDenominator` | 45,510 | 43,810,159 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bdsWireValid` | 627,880 | 1,248,059,776 |
| `bytesValue` | 172,432 | 454,140,113 |
| `bytesWord` | Not observed in collected call contexts | Not assigned |
| `bytesWordPrefix` | 100,793 | 41,381,812 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,477,194 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbRatioOutside250800` | 17,394 | 159,012,162 |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid40` | 62,679 | 246,013,259 |
| `cbValid60` | 64,315 | 265,301,212 |
| `cbWindPenalty50` | 10,641 | 3,048,948 |
| `cbWindPenaltyTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `commBPayloadLimit` | Not observed in collected call contexts | Not assigned |
| `field` | 881,619 | 564,514,596 |
| `packFields` | 172,432 | 816,478,744 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadValue` | 1,578,891 | 2,042,160,746 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 641,118,869 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 815,961,448 |
| `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg` | 172,432 | 788,844,560 |

Optional ScoreGate, table and fallback-related anchors are overlapping native-symbol observations, not another cost partition. An absent/inlined symbol does not establish zero logical computations, zero fallback decisions or zero initialization work. A fallback population requires a verified live call boundary or a separately checked census; instruction counts are not converted into decision counts.

### Live integer enclosure boundaries

The fresh compiled-source review verifies exact integer common-denominator decisions in live `choose`. Its denominator and first pair-fold entry counts each equal the observed choose entries below. `scaledNumerator` and the `scaledTotals` wrapper are inlined; their missing standalone boundaries do not mean zero work. The old rational `mass`, `center` and `envelope` remain reference APIs used by the post-collection census, outside the collected root. They are not the live decision arithmetic. These counts are overlapping observations, not extra message populations or timing results.

| Collected population | Choose entries | Common-denominator entries | Integer pair-fold entries |
|---|---:|---:|---:|
| candidate40 | 15,513 | 15,513 | 15,513 |
| score40 | 15,513 | 15,513 | 15,513 |
| candidate44 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 |
| candidate50 | 10,641 | 10,641 | 10,641 |
| score50 | 10,641 | 10,641 | 10,641 |
| candidate60 | 19,356 | 19,356 | 19,356 |
| score60 | 19,356 | 19,356 | 19,356 |
| adsb | 0 | 0 | 0 |
| commb | 45,510 | 45,510 | 45,510 |
| other | 0 | 0 | 0 |

Frame/CRC-stage contexts further separate fixed-width remainder work from extraction of bits from the complete word. This filter follows the combined frame/CRC stage, not a stricter parity-only ancestry test. The following inclusive costs overlap: a high-level parity helper can call the Nat/GMP helpers below it. They must not be added, subtracted as if disjoint, or extrapolated to predicted speedups. Uses attributed to other stages are excluded. A zero native-symbol count does not imply that all semantically related work disappeared.

| Helper in frame/CRC-stage contexts | Native entries | Inclusive Ir | Share of frame/CRC Ir (overlapping) |
|---|---:|---:|---:|
| `Parity_step` | 0 | 0 | 0.00% |
| `l_BitVec_ofNat` | 249,344 | 261,923,352 | 7.49% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 249,344 | 254,941,720 | 7.29% |
| `lean_nat_big_shiftr` | 615,557 | 346,073,904 | 9.90% |
| `lean_uint64_of_big_nat` | 302,379 | 269,235,400 | 7.70% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 3,612,702,286 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 3,459,480,296 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 3,459,289,440 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 2,951,821,465 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 2,499,755,135 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 1,787,635,288 |
| `lp_lean1090_Lean1090_Impl_bdsWireValid` | 627,880 | 18,451,163 | 1,248,059,776 |
| `lp_lean1090_Lean1090_Impl_ScoreGate_choose` | 45,510 | 19,248,889 | 1,232,767,155 |
| `lean::mpz::~mpz()` | 8,544,862 | 34,179,448 | 893,611,140 |
| `__gmpz_clear` | 8,544,862 | 59,411,425 | 859,431,692 |
| `lean::mpz::mpz(unsigned long)` | 1,605,932 | 40,148,300 | 801,262,664 |
| `__gmp_default_free` | 8,410,659 | 16,821,318 | 800,020,267 |
| `free` | 8,410,661 | 328,015,779 | 783,199,135 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,118,869 |
| `lean_nat_pow` | 642,646 | 28,276,424 | 635,289,957 |

The source and generated C retained under `tests/evidence/diagnostics/gen17` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-17 benchmark binary retained 230 samples; 86 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: Comm-B semantic projection: 17; Comm-B inference and raw payload: 16; shared frame syndrome: 16; frame extraction: 15; report other/self/unresolved substage: 9; identity: 6; ADS-B raw payload: 3; ADS-B semantic projection: 3; altitude: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused unchanged native production objects originally built from timed commit `0f7882f3f949118c6871a40bc012bb8a957a6a3d`; their audited source blobs also match diagnostic checkout `9d441eb3bdbaa17adbb289c3d82afe20307ad28b`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen17/analysis/analysis.json](../tests/evidence/diagnostics/gen17/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen17/native/all.jsonl](../tests/evidence/diagnostics/gen17/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen17/native-df/summary.json](../tests/evidence/diagnostics/gen17/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen17/perf/analysis.json](../tests/evidence/diagnostics/gen17/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen17/driver/driver-build.json](../tests/evidence/diagnostics/gen17/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen17/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen17/analysis/analysis.json` | `fe7958f28979a5b5857e27f6acaf491a846b2166707eb8e72821371f1681fe0b` |
| `tests/evidence/diagnostics/gen17/native/all.jsonl` | `0c831430c691f66c8912d9acfddfb669a55e90f0c592c3a0825ff7c620983430` |
| `tests/evidence/diagnostics/gen17/native-df/summary.json` | `cb80e535de1d01a21ae1cf836c27a796cc98cfc4d3723f1e053e4e928963877a` |
| `tests/evidence/diagnostics/gen17/perf/analysis.json` | `9b9bc83e1c6d22b4b5970d5ddad8a21c0dda87aa87111027de0343b9dae457ae` |
| `tests/evidence/diagnostics/gen17/driver/driver-build.json` | `1c577fe62bd53d24c35899f8b00f44c9d7fb8202aa7bde78b240cbac1726a426` |
| `tests/evidence/diagnostics/gen16/analysis/analysis.json` | `22285927812e4f58fd6fbdef9b5a57a492a567ef6c7892a07880afd8775e04fb` |
| `tests/evidence/diagnostics/gen17/campaign.json` | `53f3e5d39da44653bc9f8128c59bc8f2143a1cb368b38df32bc50dcd0a2c3c1c` |
| `bench/runs/gen17/summary.json` | `bb5f7e9b0c3a0bad7f75ec6b78a3e9f97947332817e52c4b9a3c4282c19f4222` |
| `tests/evidence/diagnostics/gen17/context-notes.md` | `6e2bb21844c35d40522432219ded522d4cfc0243227e4f2a07a5bd1dfa1d3b4c` |
| `tests/evidence/diagnostics/gen17/independent-review/source-review.json` | `883182f6ab5236c29b7a6cae452afe70b697312bb0911b0bc2ce9355411d149a` |
| `tests/evidence/diagnostics/gen17/benchmark-source-binding.json` | `335a28a7794dc047a765508d9150b8f8709a5b8834717224f7079a333c4fc57d` |

## Reviewed run-specific observations

Generation 17 changes only Binary64.powerTwo: an immutable 2,098-entry table covers format exponents −1074 through 1023, with the original total formula retained outside that range. Equality is proved for every integer exponent and propagated through decoder and CPR proofs. [Source/native review](../tests/evidence/diagnostics/gen17/independent-review/source-review.json) retains the actual indexed lookup, mutually exclusive formula fallback branches and complete eager initializer. The field-packing implementation is unchanged from generation 16. Instruction observations below compare this live implementation with generation 16; no speedup is inferred from instruction differences.

The current checkout contains the committed generation-17 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 230 samples, 86 have a visible decoder ancestor and 144 are excluded; 226 stacks contain an unknown frame and 7 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen17/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen17/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 516,575,831 |
| candidate44 | 47,166 | 0 | 0 | 0 | 11,836,862 |
| candidate45 | 47,166 | 0 | 0 | 0 | 11,932,998 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 146,823,653 | 713,784,427 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 369,662,237 | 1,054,157,327 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,794,701 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 146,817,293 | 506,955,914 |
| score60 | 19,356 | 19,356 | 2,429,938 | 369,779,713 | 899,495,979 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen17/penalty-probe-costs.json).

The retained live wind lookup and eager table construction are distinguished explicitly:

| Profile | Expected lookup calls | Observed lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Entry construction inside root |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 |
| commb | 10,641 | 10,641 | 678,708 | 3,048,948 | 0 |
| other | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 10,641 | 10,641 | 678,708 | 3,048,948 | 0 |
| candidate60 | 0 | 0 | 0 | 0 | 0 |
| score40 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 678,708 | 3,048,948 | 0 |
| score60 | 0 | 0 | 0 | 0 | 0 |

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen17/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,012,162 | 187,526 |
| other | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate60 | 17,394 | 17,386 | 8 | 4,593,636 | 158,934,858 | 187,607 |
| score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| score50 | 0 | 0 | 0 | 0 | 0 | 0 |
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,475,704 | 187,688 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen17/ratio-native-contexts.json) also records generation 16 and 17 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.

The live Comm-B guard and its direct decimal-parser calls:

| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |
|---|---|---:|---:|---:|---:|---:|
| 16 | adsb | 0 | 0 | 0 | 0 | 0 |
| 16 | commb | 627,880 | 18,451,163 | 1,248,053,404 | 0 | 0 |
| 16 | other | 0 | 0 | 0 | 0 | 0 |
| 16 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 16 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 16 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 16 | candidate50 | 47,166 | 1,273,482 | 198,776,429 | 0 | 0 |
| 16 | candidate60 | 47,166 | 1,367,814 | 145,276,019 | 0 | 0 |
| 16 | score40 | 0 | 0 | 0 | 0 | 0 |
| 16 | score44 | 0 | 0 | 0 | 0 | 0 |
| 16 | score45 | 0 | 0 | 0 | 0 | 0 |
| 16 | score50 | 0 | 0 | 0 | 0 | 0 |
| 16 | score60 | 0 | 0 | 0 | 0 | 0 |
| 17 | adsb | 0 | 0 | 0 | 0 | 0 |
| 17 | commb | 627,880 | 18,451,163 | 1,248,059,776 | 0 | 0 |
| 17 | other | 0 | 0 | 0 | 0 | 0 |
| 17 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 17 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 17 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 17 | candidate50 | 47,166 | 1,273,482 | 198,782,150 | 0 | 0 |
| 17 | candidate60 | 47,166 | 1,367,814 | 145,276,424 | 0 | 0 |
| 17 | score40 | 0 | 0 | 0 | 0 | 0 |
| 17 | score44 | 0 | 0 | 0 | 0 | 0 |
| 17 | score45 | 0 | 0 | 0 | 0 | 0 |
| 17 | score50 | 0 | 0 | 0 | 0 | 0 |
| 17 | score60 | 0 | 0 | 0 | 0 | 0 |

These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen17/constant-native-contexts.json).

The live general packing fold and its observed direct native calls:

| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |
|---|---:|---:|---:|---|---:|---:|
| 16 | 172,432 | 38,791,098 | 815,959,275 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 16 | 172,432 | 38,791,098 | 815,959,275 | `lean_nat_big_add` | 100,793 | 151,720,534 |
| 16 | 172,432 | 38,791,098 | 815,959,275 | `lean_nat_shiftl` | 881,619 | 608,010,454 |
| 17 | 172,432 | 38,791,098 | 815,961,448 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 17 | 172,432 | 38,791,098 | 815,961,448 | `lean_nat_big_add` | 100,793 | 151,727,894 |
| 17 | 172,432 | 38,791,098 | 815,961,448 | `lean_nat_shiftl` | 881,619 | 608,005,267 |

Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The generic power/modulus branch remains in the actual binary for widths at least 64, even if the corpus has no observed calls. [Exact packing contexts](../tests/evidence/diagnostics/gen17/pack-fields-direct-costs.json).

The live power-of-two lookup, formula fallback and startup construction:

| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |
|---|---|---:|---:|---:|---:|---:|---:|
| 16 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 16 | commb | 1,324 | 50,991 | 4,563,043 | 0 | 0 | 0 |
| 16 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 16 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 16 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 16 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 16 | candidate50 | 1,308 | 50,375 | 4,504,531 | 0 | 0 | 0 |
| 16 | candidate60 | 16 | 616 | 55,920 | 0 | 0 | 0 |
| 16 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 16 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 16 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 16 | score50 | 1,308 | 50,375 | 4,510,120 | 0 | 0 | 0 |
| 16 | score60 | 16 | 616 | 56,169 | 0 | 0 | 0 |
| 17 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 17 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 17 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 17 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 17 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 17 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 17 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 17 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 17 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 17 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 17 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 17 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 17 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |

These are actual retained incoming boundaries and direct lookup-to-formula edges. Generation 16 implements the formula inside powerTwo and has no separate formula/table symbols. In generation 17, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen17/power-native-contexts.json).


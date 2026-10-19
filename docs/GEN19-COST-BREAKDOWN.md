# Generation 19: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `3f3478c62a1db4c43b40cd8464bdf1787e10976f` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Frame / CRC**, with 3,496,975,683 of 9,587,482,169 collected guest instructions (36.47%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-19 benchmark is decode **1.79542×** and CPR **1.43283×**; see [bench/runs/gen19/summary.json](../bench/runs/gen19/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 1,995,656,801 | 39,608.2 | 20.82% |
| commb | 47,714 | 6,728,136,696 | 141,009.7 | 70.18% |
| other | 74,333 | 863,688,672 | 11,619.2 | 9.01% |
| Total | 172,432 | 9,587,482,169 | 55,601.5 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Frame / CRC | 1,280,030,700 | 1,381,683,391 | 835,261,592 | 3,496,975,683 | 36.47% |
| Comm-B candidate inference / raw records | 1,007,700 | 3,063,371,310 | 1,486,660 | 3,065,865,670 | 31.98% |
| Semantic / oracle value construction | 513,622,551 | 2,264,175,297 | 11,292,854 | 2,789,090,702 | 29.09% |
| ADS-B fields / checks | 188,160,707 | 477,140 | 743,330 | 189,381,177 | 1.98% |
| Output-model construction / residual control | 12,835,143 | 18,429,558 | 14,904,236 | 46,168,937 | 0.48% |

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

## Comparison with generation 18

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen18 Ir | Gen19 Ir | Difference (gen19 − gen18) | Gen19/gen18 | Gen18 Ir/message | Gen19 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Frame / CRC | 3,496,964,323 | 3,496,975,683 | +11,360 | 1.00000 | 20,280.25 | 20,280.32 |
| Comm-B candidate inference / raw records | 3,612,702,399 | 3,065,865,670 | -546,836,729 | 0.84863 | 20,951.46 | 17,780.14 |
| Semantic / oracle value construction | 3,377,763,623 | 2,789,090,702 | -588,672,921 | 0.82572 | 19,588.96 | 16,175.02 |
| ADS-B fields / checks | 210,610,234 | 189,381,177 | -21,229,057 | 0.89920 | 1,221.41 | 1,098.29 |
| Output-model construction / residual control | 46,158,808 | 46,168,937 | +10,129 | 1.00022 | 267.69 | 267.75 |
| Total | 10,744,199,387 | 9,587,482,169 | -1,156,717,218 | 0.89234 | 62,309.78 | 55,601.53 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 516,578,979 | 381,793,254 |
| BDS44 | 47,166 | 0 | 0 | 11,836,862 | 0 |
| BDS45 | 47,166 | 0 | 0 | 11,932,998 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 705,803,397 | 502,894,732 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,051,894,229 | 899,498,961 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen19/independent-review/source-review.json](../tests/evidence/diagnostics/gen19/independent-review/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| `decodeFrame` | 172,432 | 1,107,323,933 |
| `frameSyndrome` | 172,432 | 2,299,432,084 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,241,855 |
| `reportWithSyndrome` | 172,432 | 6,157,587,096 |
| `Parity_checksum` | 172,432 | 1,279,410,019 |
| `Parity_syndrome` | 172,432 | 1,119,219,468 |
| `Parity_step` | Not observed in collected call contexts | Not assigned |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 512,854,719 |
| `Semantics_adsb` | 51,212 | 504,916,204 |
| `Semantics_commB` | 46,440 | 2,249,499,493 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `_init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1` | Not observed in collected call contexts | Not assigned |
| `initialize_lean1090_Impl_Binary64` | Not observed in collected call contexts | Not assigned |
| `l_Rat_add` | 56,229 | 95,231,980 |
| `l_Rat_div` | 52,831 | 241,148,243 |
| `l_Rat_mul` | 502,756 | 1,667,152,681 |
| `lean_cstr_to_nat` | 50,390 | 38,900,980 |
| `Altitude_bit` | 63,893 | 1,469,539 |
| `Altitude_grayDecode` | 10,668 | 7,994,377 |
| `Binary64_div` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwo` | 1,324 | 116,512 |
| `Binary64_powerTwoFormula` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwoTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `Binary64_round` | 662 | 15,433,570 |
| `CPR_Policy_toFloat` | Not observed in collected call contexts | Not assigned |
| `CPR_Policy_toFloatFallback` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,232,766,693 |
| `ScoreGate_commonDenominator` | 45,510 | 43,809,985 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bdsWireValid` | 627,880 | 998,087,774 |
| `bytesValue` | 172,432 | 454,119,785 |
| `bytesWord` | Not observed in collected call contexts | Not assigned |
| `bytesWordPrefix` | 100,793 | 41,361,719 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,477,194 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbRatioOutside250800` | 17,394 | 159,012,104 |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid18` | 47,171 | 19,856,066 |
| `cbValid19` | 47,166 | 14,192,349 |
| `cbValid40` | 62,679 | 246,013,259 |
| `cbValid44` | 47,166 | 4,195,970 |
| `cbValid45` | 47,166 | 3,773,280 |
| `cbValid50` | 56,979 | 284,208,053 |
| `cbValid60` | 64,315 | 260,865,912 |
| `cbWindPenalty50` | 10,641 | 3,048,948 |
| `cbWindPenaltyTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `commBPayloadLimit` | Not observed in collected call contexts | Not assigned |
| `field` | 881,619 | 564,514,596 |
| `identityCode` | 21,257 | 7,057,324 |
| `identityCode___lam__0` | Not observed in collected call contexts | Not assigned |
| `packFields` | 172,432 | 816,478,682 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadInteger` | 1,639,589 | 418,530,906 |
| `payloadValue` | 1,578,891 | 2,008,223,758 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,766 | 5,262,564 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 641,118,871 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 815,961,386 |
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

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Frame / CRC** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameSyndrome` | 172,432 | 11,871,146 | 2,299,432,084 |
| `lp_lean1090_Lean1090_Impl_Parity_checksum` | 172,432 | 5,849,357 | 1,279,410,019 |
| `lp_lean1090_Lean1090_Impl_Parity_syndrome` | 172,432 | 6,438,292 | 1,119,219,468 |
| `lp_lean1090_Lean1090_Impl_decodeFrame` | 172,432 | 22,561,399 | 1,107,323,933 |
| `lp_lean1090_Lean1090_Impl_packFields` | 172,432 | 517,296 | 816,478,682 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 38,791,098 | 815,961,386 |
| `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg` | 172,432 | 788,844,560 | 788,844,560 |
| `lean::mpz::~mpz()` | 7,305,010 | 29,220,040 | 774,272,064 |
| `__gmpz_clear` | 7,305,010 | 51,133,264 | 745,052,024 |
| `__gmp_default_free` | 7,304,408 | 14,608,816 | 693,918,760 |
| `free` | 7,304,408 | 284,871,912 | 679,309,944 |
| `lean_nat_shiftl` | 982,412 | 38,826,657 | 672,812,262 |
| `lean::mpz::mpz(unsigned long)` | 1,319,081 | 32,977,025 | 656,282,008 |
| `lp_lean1090_Lean1090_Impl_field` | 881,619 | 56,178,834 | 564,514,596 |
| `lp_lean1090_Lean1090_Impl_bytesValue` | 172,432 | 31,171,820 | 454,119,785 |

The source and generated C retained under `tests/evidence/diagnostics/gen19` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-19 benchmark binary retained 231 samples; 81 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: shared frame syndrome: 21; Comm-B semantic projection: 20; Comm-B inference and raw payload: 13; frame extraction: 10; report other/self/unresolved substage: 9; ADS-B semantic projection: 7; ADS-B raw payload: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Frame / CRC** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused unchanged native production objects originally built from timed commit `79cc25b8c6f104da94e2b532439fe6e9b47f72ea`; their audited source blobs also match diagnostic checkout `3f3478c62a1db4c43b40cd8464bdf1787e10976f`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen19/analysis/analysis.json](../tests/evidence/diagnostics/gen19/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen19/native/all.jsonl](../tests/evidence/diagnostics/gen19/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen19/native-df/summary.json](../tests/evidence/diagnostics/gen19/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen19/perf/analysis.json](../tests/evidence/diagnostics/gen19/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen19/driver/driver-build.json](../tests/evidence/diagnostics/gen19/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen19/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen19/analysis/analysis.json` | `2471720ffb545d4b5c3ef25ca68d5b6df07f4c4709ee09521a3895605975f32b` |
| `tests/evidence/diagnostics/gen19/native/all.jsonl` | `0c831430c691f66c8912d9acfddfb669a55e90f0c592c3a0825ff7c620983430` |
| `tests/evidence/diagnostics/gen19/native-df/summary.json` | `47a10428735677c70aa0afd96cc4acdedea55900fbc38d7a1436dc222f1c05ba` |
| `tests/evidence/diagnostics/gen19/perf/analysis.json` | `f7d06374d530a1c1005cea3d043da54bd069fed334e92aaf607c47bda230ddd8` |
| `tests/evidence/diagnostics/gen19/driver/driver-build.json` | `0463f08c248d6876655107c919a0d816610b485f101eed200ef25e7538693ce7` |
| `tests/evidence/diagnostics/gen18/analysis/analysis.json` | `3494f22f8ed97891e9df3233168b2fdf78a125ac829c39d6b81dbf3129df377d` |
| `tests/evidence/diagnostics/gen19/campaign.json` | `12bb11bcf218976193eda9038f9787040562b0be74f9370866ad5a20b4354d51` |
| `bench/runs/gen19/summary.json` | `c261c22b3f5600eb19c8f49b0ddf04909186a0fe02b1c6d0a01cc2746c42e343` |
| `tests/evidence/diagnostics/gen19/context-notes.md` | `c7bc48f3cf00353a4d61ccac836429103d8eb77af23b0eb9bf0322ff1fd88674` |
| `tests/evidence/diagnostics/gen19/independent-review/source-review.json` | `6d51d0c6570306fcc66b7b948bdf6e000d627a36264e94ba7dfd62870773917c` |
| `tests/evidence/diagnostics/gen19/benchmark-source-binding.json` | `e8537300b366554dd772354724d028953dcd4015aa37748667caa49fe5100b52` |

## Reviewed run-specific observations

Generation 19 replaces power-of-two divisions and construction with exact natural shifts and masks in Altitude.bit, Altitude.grayDecode, identityCode and payloadInteger. Unconditional proofs preserve every natural word, index and width, including over-wide values; no input is narrowed to a machine word. [Current source/native review](../tests/evidence/diagnostics/gen19/independent-review/source-review.json) binds the freshly timed worker and all four live optimized paths, including caller inlining. This report collects actual Impl.decode only; the separate CPR diagnostic covers tracking and numeric geography. Comparisons with generation 18 below are instruction observations, not throughput predictions or inferred path hit rates.

The current checkout contains the committed generation-19 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 231 samples, 81 have a visible decoder ancestor and 150 are excluded; 228 stacks contain an unknown frame and 7 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen19/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen19/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 516,578,979 |
| candidate44 | 47,166 | 0 | 0 | 0 | 11,836,862 |
| candidate45 | 47,166 | 0 | 0 | 0 | 11,932,998 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 142,764,389 | 705,803,397 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 369,662,237 | 1,051,894,229 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,793,254 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 142,757,861 | 502,894,732 |
| score60 | 19,356 | 19,356 | 2,429,938 | 369,782,695 | 899,498,961 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen19/penalty-probe-costs.json).

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

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen19/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,012,104 | 187,526 |
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
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,478,686 | 187,688 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen19/ratio-native-contexts.json) also records generation 18 and 19 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.

The live Comm-B guard and its direct decimal-parser calls:

| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |
|---|---|---:|---:|---:|---:|---:|
| 18 | adsb | 0 | 0 | 0 | 0 | 0 |
| 18 | commb | 627,880 | 18,451,163 | 1,248,057,210 | 0 | 0 |
| 18 | other | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 18 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 18 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 18 | candidate50 | 47,166 | 1,273,482 | 198,782,150 | 0 | 0 |
| 18 | candidate60 | 47,166 | 1,367,814 | 145,276,424 | 0 | 0 |
| 18 | score40 | 0 | 0 | 0 | 0 | 0 |
| 18 | score44 | 0 | 0 | 0 | 0 | 0 |
| 18 | score45 | 0 | 0 | 0 | 0 | 0 |
| 18 | score50 | 0 | 0 | 0 | 0 | 0 |
| 18 | score60 | 0 | 0 | 0 | 0 | 0 |
| 19 | adsb | 0 | 0 | 0 | 0 | 0 |
| 19 | commb | 627,880 | 18,451,163 | 998,087,774 | 0 | 0 |
| 19 | other | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 19 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 19 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 19 | candidate50 | 47,166 | 1,273,482 | 194,858,282 | 0 | 0 |
| 19 | candidate60 | 47,166 | 1,367,814 | 143,011,400 | 0 | 0 |
| 19 | score40 | 0 | 0 | 0 | 0 | 0 |
| 19 | score44 | 0 | 0 | 0 | 0 | 0 |
| 19 | score45 | 0 | 0 | 0 | 0 | 0 |
| 19 | score50 | 0 | 0 | 0 | 0 | 0 |
| 19 | score60 | 0 | 0 | 0 | 0 | 0 |

These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen19/constant-native-contexts.json).

The live general packing fold and its observed direct native calls:

| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |
|---|---:|---:|---:|---|---:|---:|
| 18 | 172,432 | 38,791,098 | 815,961,212 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 18 | 172,432 | 38,791,098 | 815,961,212 | `lean_nat_big_add` | 100,793 | 151,727,780 |
| 18 | 172,432 | 38,791,098 | 815,961,212 | `lean_nat_shiftl` | 881,619 | 608,005,145 |
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_nat_big_add` | 100,793 | 151,727,950 |
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_nat_shiftl` | 881,619 | 608,005,149 |

Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The generic power/modulus branch remains in the actual binary for widths at least 64, even if the corpus has no observed calls. [Exact packing contexts](../tests/evidence/diagnostics/gen19/pack-fields-direct-costs.json).

The live power-of-two lookup, formula fallback and startup construction:

| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |
|---|---|---:|---:|---:|---:|---:|---:|
| 18 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 18 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 18 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 18 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 18 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 19 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 19 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 19 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 19 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 19 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |

These are actual retained incoming boundaries and direct lookup-to-formula edges. Both generations retain the same immutable format-exponent table. In the current worker, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen19/power-native-contexts.json).

The four optimized extraction paths, compared at actual retained native boundaries:

| Generation | Stage | Native boundary | Entries | Self Ir | Incoming inclusive Ir | Direct pow calls | Direct pow inclusive Ir |
|---|---|---|---:|---:|---:|---:|---:|
| 18 | adsb_fields | `Altitude_bit` | 20,816 | 645,296 | 21,731,904 | 20,816 | 21,086,608 |
| 18 | commb_inference | `Altitude_bit` | 379,793 | 11,773,583 | 394,519,951 | 379,793 | 382,746,368 |
| 18 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 63,756,013 | 0 | 0 |
| 18 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 118,638,989 | 110,143 | 112,456,003 |
| 18 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 6,261,740 | 146,349,326 | 152,710 | 140,087,586 |
| 18 | semantic_oracle_values | `Altitude_bit` | 283,061 | 8,774,891 | 295,685,356 | 283,061 | 286,910,465 |
| 18 | semantic_oracle_values | `identityCode` | 21,257 | 5,654,362 | 264,628,393 | 0 | 0 |
| 18 | semantic_oracle_values | `identityCode___lam__0` | 255,084 | 7,907,604 | 258,974,031 | 255,084 | 251,066,427 |
| 18 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 349,329,881 | 264,274 | 269,838,674 |
| 18 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 83,780 | 1,891,422 | 1,998 | 1,807,642 |
| 19 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 19 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 19 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 7,994,377 | 0 | 0 |
| 19 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 104,100,113 | 0 | 0 |
| 19 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 19 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 19 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 314,430,793 | 0 | 0 |
| 19 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |

The current compiled identity lambda is inlined into identityCode; its old standalone row is absent while the live extraction remains. Other small arithmetic can inline too. Native entry populations across these changed boundaries are not assumed equal. The current direct-power count is zero only for these selected caller boundaries, consistent with the checked shift/mask implementation; it is not a zero-work claim or a claim about all decoder powers. Incoming inclusive columns overlap stage totals and other helpers. [Exact old/new contexts and direct children](../tests/evidence/diagnostics/gen19/bit-extraction-contexts.json) bind both raw profile sets without copying them or predicting timing.

Selected actual nested helpers for prioritization:

| Stage | Native helper | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| commb_inference | `ScoreGate_choose` | 45,510 | 19,248,889 | 1,232,766,693 |
| commb_inference | `bdsWireValid` | 627,880 | 18,451,163 | 998,087,774 |
| commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,118,871 |
| commb_inference | `l_Rat_mul` | 140,239 | 28,557,789 | 497,099,378 |
| commb_inference | `cbValid50` | 56,979 | 4,940,566 | 284,208,053 |
| commb_inference | `cbValid60` | 64,315 | 4,012,830 | 260,865,912 |
| commb_inference | `cbValid40` | 62,679 | 4,396,089 | 246,013,259 |
| commb_inference | `l_Rat_div` | 48,323 | 386,584 | 226,414,310 |
| commb_inference | `payloadValue` | 58,044 | 6,143,488 | 175,075,933 |
| commb_inference | `cbValid21` | 47,854 | 3,200,897 | 108,985,571 |
| commb_inference | `ScoreGate_commonDenominator` | 45,510 | 5,882,374 | 43,809,985 |
| commb_inference | `cbValid18` | 47,171 | 613,237 | 19,856,066 |
| commb_inference | `cbValid19` | 47,166 | 235,830 | 14,192,349 |
| commb_inference | `cbValid17` | 47,498 | 1,210,360 | 5,759,260 |
| commb_inference | `cbValid44` | 47,166 | 1,051,620 | 4,195,970 |
| commb_inference | `cbValid45` | 47,166 | 943,320 | 3,773,280 |
| frame_crc | `frameSyndrome` | 172,432 | 11,871,146 | 2,299,432,084 |
| frame_crc | `Parity_checksum` | 172,432 | 5,849,357 | 1,279,410,019 |
| frame_crc | `Parity_syndrome` | 172,432 | 6,438,292 | 1,119,219,468 |
| frame_crc | `packFields` | 172,432 | 517,296 | 816,478,682 |
| frame_crc | `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 38,791,098 | 815,961,386 |
| frame_crc | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg` | 172,432 | 788,844,560 | 788,844,560 |
| frame_crc | `field` | 881,619 | 56,178,834 | 564,514,596 |
| frame_crc | `bytesValue` | 172,432 | 31,171,820 | 454,119,785 |
| semantic_oracle_values | `payloadValue` | 1,520,847 | 150,316,030 | 1,833,147,825 |
| semantic_oracle_values | `l_Rat_mul` | 362,517 | 73,897,349 | 1,170,053,303 |
| semantic_oracle_values | `l_Rat_add` | 56,229 | 8,095,837 | 95,231,980 |
| semantic_oracle_values | `l_Rat_div` | 4,508 | 36,064 | 14,733,933 |

These rows aggregate only the three disjoint family profiles. Incoming inclusive observations overlap each other and stage totals, including recursive visits and descendants crossing a stage boundary. Direct native children and exact caller contexts are retained in [priority-helper-contexts.json](../tests/evidence/diagnostics/gen19/priority-helper-contexts.json). Rat multiplication rows do not count every logical affine operation; inline work remains in callers. These observations do not select an optimization or infer throughput.


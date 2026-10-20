# Generation 25: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `240cc329f5334e8557687eddc56a854edd2720bc` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 2,248,598,424 of 5,748,262,724 collected guest instructions (39.12%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-25 benchmark is decode **2.64972×** and CPR **1.94770×**; see [bench/runs/gen25/summary.json](../bench/runs/gen25/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 1,425,903,854 | 28,300.2 | 24.81% |
| commb | 47,714 | 3,946,332,740 | 82,708.1 | 68.65% |
| other | 74,333 | 376,026,130 | 5,058.7 | 6.54% |
| Total | 172,432 | 5,748,262,724 | 33,336.4 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 2,246,104,064 | 1,486,660 | 2,248,598,424 | 39.12% |
| Frame / CRC | 703,887,680 | 721,638,011 | 347,512,140 | 1,773,037,831 | 30.84% |
| Semantic / oracle value construction | 509,355,725 | 951,533,020 | 11,299,694 | 1,472,188,439 | 25.61% |
| ADS-B fields / checks | 190,340,902 | 477,140 | 743,330 | 191,561,372 | 3.33% |
| Output-model construction / residual control | 21,311,847 | 26,580,505 | 14,984,306 | 62,876,658 | 1.09% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Shared-syndrome census and native entries

The original shadow census is retained exactly for historical comparison; its repeated-CRC prediction is not the current expectation. A separate post-decode census reparses every corpus row, checks its frame and syndrome against the retained decoder result, and predicts one syndrome after successful parsing. This work occurs after collection and does not enter the decoder-root counters.

All 172,432 corpus rows are accepted, as required by the complete retained-output check. This census covers that accepted corpus only. It does not measure malformed frames or frames rejected after parsing; the latter now compute a syndrome before rejection, as documented by the source/native review.

| Family | Historical repeated-call prediction | Live one-per-frame prediction | Observed paired parser / syndrome entries | Observed byte-loop entries |
|---|---:|---:|---:|---:|
| adsb | 81,780 | 50,385 | 50,385 / 50,385 | 50,385 |
| commb | 95,428 | 47,714 | 47,714 / 47,714 | 47,714 |
| other | 110,210 | 74,333 | 74,333 / 74,333 | 74,333 |

The live decoder reuses the wire word returned by decodeFrameWithWord. No frameSyndrome, checksum or packFields native entries occur inside these decoder roots. The post-collection census separately rechecks the raw word and compares its syndrome with the standalone frame-syndrome formula; those validation calls are outside collection. Standalone APIs and arbitrary-input proofs remain available. Missing boundaries alone do not establish absence of inlined work: current generated-C/native review establishes the direct raw-word path.

The checked 7/14-byte corpus predicts 1,912,575 byte iterations and 15,300,600 equivalent bit updates. These are mathematical iteration counts, not observed function entries. Each observed byte-loop entry processes one syndrome, with eight inlined UInt32 updates per iteration. The live generic bit-loop fallback has zero entries in this accepted corpus; source/native inspection and all-input proofs retain it for widths above 128 or not divisible by eight. Neither zero fallback entries nor absent standalone `Parity.step` calls means zero CRC work.

The new acceptance/address helpers keep their predecessor stages when they retain a native boundary. Acceptance control inlined into `decode` remains in that function's residual-control category; its called hard-validity helper retains the ADS-B category. No cost is reassigned by source-level intention. The renamed report helper retains the same report/semantic boundaries. These compiler-boundary changes must be considered when comparing stage deltas.

## Comparison with generation 24

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen24 Ir | Gen25 Ir | Difference (gen25 − gen24) | Gen25/gen24 | Gen24 Ir/message | Gen25 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 2,306,269,761 | 2,248,598,424 | -57,671,337 | 0.97499 | 13,374.95 | 13,040.49 |
| Frame / CRC | 1,773,036,032 | 1,773,037,831 | +1,799 | 1.00000 | 10,282.52 | 10,282.53 |
| Semantic / oracle value construction | 1,472,212,016 | 1,472,188,439 | -23,577 | 0.99998 | 8,537.93 | 8,537.79 |
| ADS-B fields / checks | 191,591,430 | 191,561,372 | -30,058 | 0.99984 | 1,111.11 | 1,110.94 |
| Output-model construction / residual control | 62,874,443 | 62,876,658 | +2,215 | 1.00004 | 364.63 | 364.65 |
| Total | 5,805,983,682 | 5,748,262,724 | -57,720,958 | 0.99006 | 33,671.15 | 33,336.40 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 379,488,067 | 353,763,260 |
| BDS44 | 47,166 | 0 | 0 | 11,836,862 | 0 |
| BDS45 | 47,166 | 0 | 0 | 11,932,998 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 487,962,842 | 455,728,506 |
| BDS60 | 47,166 | 19,356 | 17,149 | 884,954,498 | 850,726,232 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen25/independent-review/source-review.json](../tests/evidence/diagnostics/gen25/independent-review/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


BDS44, BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.

## Native allocation counts and output checks by DF

`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.

| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |
|---|---:|---:|---:|---|
| 0 | 21,393 | 192,392 | 8.99 | Yes |
| 4 | 8,841 | 77,014 | 8.71 | Yes |
| 5 | 2,949 | 23,593 | 8.00 | Yes |
| 11 | 38,456 | 307,649 | 8.00 | Yes |
| 16 | 2,694 | 43,105 | 16.00 | Yes |
| 17 | 31,395 | 4,800,655 | 152.91 | Yes |
| 18 | 18,990 | 633,080 | 33.34 | Yes |
| 20 | 29,460 | 5,160,498 | 175.17 | Yes |
| 21 | 18,254 | 3,125,644 | 171.23 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 14,363,460 small allocations. The sum of separate DF loops is 14,363,630, a difference of 170. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | Not observed in collected call contexts | Not assigned |
| `decodeFrameWithWord` | 172,432 | 1,094,492,597 |
| `frameSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,236,589 |
| `reportWithSyndrome` | 172,432 | 4,025,753,757 |
| `Parity_checksum` | Not observed in collected call contexts | Not assigned |
| `Parity_syndrome` | 172,432 | 588,137,357 |
| `Parity_step` | Not observed in collected call contexts | Not assigned |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 447,325,570 |
| `Semantics_adsb` | 51,212 | 500,668,642 |
| `Semantics_commB` | 46,440 | 936,889,209 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `_init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1` | Not observed in collected call contexts | Not assigned |
| `initialize_lean1090_Impl_Binary64` | Not observed in collected call contexts | Not assigned |
| `l_Rat_add` | 40,716 | 68,011,453 |
| `l_Rat_div` | 22,565 | 141,697,442 |
| `l_Rat_mul` | 56,601 | 229,407,970 |
| `l_Rat_normalize` | Not observed in collected call contexts | Not assigned |
| `lean_cstr_to_nat` | 50,390 | 38,900,980 |
| `Altitude_bit` | 63,893 | 1,469,539 |
| `Altitude_grayDecode` | 10,668 | 8,203,649 |
| `Binary64_div` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwo` | 1,324 | 116,512 |
| `Binary64_powerTwoFormula` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwoTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `Binary64_round` | 662 | 15,441,109 |
| `CPR_Policy_toFloat` | Not observed in collected call contexts | Not assigned |
| `CPR_Policy_toFloatFallback` | Not observed in collected call contexts | Not assigned |
| `Parity_syndromeBits` | Not observed in collected call contexts | Not assigned |
| `Parity_syndromeBytes` | 172,432 | 583,826,557 |
| `Presentation_oracleCommBFloats` | 45,613 | 58,008,156 |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,175,667,837 |
| `ScoreGate_commonDenominator` | 45,510 | 43,951,384 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `Semantics_commBStandardFloats` | Not observed in collected call contexts | Not assigned |
| `Semantics_tableValues` | Not observed in collected call contexts | Not assigned |
| `acasParts` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bdsWireValid` | 627,880 | 302,071,309 |
| `bytesValue` | 172,432 | 454,143,706 |
| `bytesWord` | Not observed in collected call contexts | Not assigned |
| `bytesWordPrefix` | 100,793 | 41,352,680 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,547,112 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbMachValid60` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbQNHValid40` | Not observed in collected call contexts | Not assigned |
| `cbRatioOutside250800` | 17,394 | 159,471,198 |
| `cbRollValid50` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbSelectedValid40` | Not observed in collected call contexts | Not assigned |
| `cbValid18` | 47,171 | 19,856,066 |
| `cbValid19` | 47,166 | 14,192,349 |
| `cbValid40` | 62,679 | 27,949,710 |
| `cbValid44` | 47,166 | 4,195,970 |
| `cbValid45` | 47,166 | 3,773,280 |
| `cbValid50` | 56,979 | 30,238,839 |
| `cbValid60` | 64,315 | 35,127,332 |
| `cbVerticalValid60` | Not observed in collected call contexts | Not assigned |
| `cbWindPenalty50` | 10,641 | 3,048,948 |
| `cbWindPenaltyTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `commBPayloadLimit` | Not observed in collected call contexts | Not assigned |
| `commBValue` | 58,044 | 126,596,660 |
| `field` | 881,619 | 564,547,148 |
| `findPayloadField` | Not observed in collected call contexts | Not assigned |
| `frameParts` | Not observed in collected call contexts | Not assigned |
| `identityCode` | 21,257 | 7,057,324 |
| `identityCode___lam__0` | Not observed in collected call contexts | Not assigned |
| `integerScale` | Not observed in collected call contexts | Not assigned |
| `packFields` | Not observed in collected call contexts | Not assigned |
| `payloadBits` | 6,535,815 | 392,148,900 |
| `payloadInteger` | 1,066,165 | 222,087,861 |
| `payloadValue` | 1,052,959 | 828,515,049 |
| `surveillanceParts` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,766 | 5,262,564 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 586,539,438 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBOracleValues_spec__0` | 45,613 | 235,188,050 |
| `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBStandardFloatsFromOracle_spec__0` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0` | 96,825 | 835,664,645 |
| `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 |

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
| `l_BitVec_ofNat` | 249,344 | 261,923,517 | 14.77% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 249,344 | 254,941,885 | 14.38% |
| `lean_nat_big_shiftr` | 615,557 | 346,106,456 | 19.52% |
| `lean_uint64_of_big_nat` | 302,379 | 269,404,817 | 15.19% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 2,248,598,424 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 2,234,259,046 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 2,234,068,190 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 2,037,565,212 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 1,970,387,262 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 1,661,017,260 |
| `lp_lean1090_Lean1090_Impl_ScoreGate_choose` | 45,510 | 19,201,184 | 1,175,667,837 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 8,754,868 | 586,539,438 |
| `lean::mpz::~mpz()` | 4,633,677 | 18,534,708 | 479,025,530 |
| `__gmpz_clear` | 4,633,677 | 32,033,130 | 460,490,822 |
| `lp_lean1090_Lean1090_Impl_cbPenalty` | 45,510 | 4,164,506 | 447,325,570 |
| `__gmp_default_free` | 4,499,474 | 8,998,948 | 428,457,692 |
| `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | 45,510 | 16,154,724 | 423,630,489 |
| `free` | 4,499,476 | 175,479,564 | 419,458,930 |
| `lean::mpz::mpz(lean::mpz const&)` | 3,374,681 | 3,374,681 | 338,284,759 |

The source and generated C retained under `tests/evidence/diagnostics/gen25` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-25 benchmark binary retained 197 samples; 49 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: report other/self/unresolved substage: 12; frame extraction: 9; Comm-B inference and raw payload: 7; Comm-B semantic projection: 6; shared frame syndrome: 6; ADS-B raw payload: 3; ADS-B semantic projection: 3; decode self/other: 3. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused unchanged native production objects originally built from timed commit `eaa7b36225b0d3ae29720a319295b0fac34e995b`; their audited source blobs also match diagnostic checkout `240cc329f5334e8557687eddc56a854edd2720bc`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen25/analysis/analysis.json](../tests/evidence/diagnostics/gen25/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen25/native/all.jsonl](../tests/evidence/diagnostics/gen25/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen25/native-df/summary.json](../tests/evidence/diagnostics/gen25/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen25/perf/analysis.json](../tests/evidence/diagnostics/gen25/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen25/driver/driver-build.json](../tests/evidence/diagnostics/gen25/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen25/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen25/analysis/analysis.json` | `9e696e5368550fcb30df6625810eb31770389e405a009a099bc5349eef6d2ad7` |
| `tests/evidence/diagnostics/gen25/native/all.jsonl` | `f2d706070d7cb2e3589e6fd85fe5714e22f1054942a8bf5401a953e061e8d99c` |
| `tests/evidence/diagnostics/gen25/native-df/summary.json` | `7c463171c37913bf4f45eb511087eaae75dcee13e5c410e28a06fc6432733c60` |
| `tests/evidence/diagnostics/gen25/perf/analysis.json` | `522c03c89f511d891f458da876e31a0937c90de16553994c4908a81a95571010` |
| `tests/evidence/diagnostics/gen25/driver/driver-build.json` | `3a7627769a765d8e77dbf5bc9aaf33217e7eb6e41d51c8c76e7e72441a1a1361` |
| `tests/evidence/diagnostics/gen24/analysis/analysis.json` | `b7c31232fcc1ffdee431d92148f4a339e969246ae4dc6854b3a1028aa9a71c4e` |
| `tests/evidence/diagnostics/gen25/campaign.json` | `08dfb6dbf1ea5f241b1f2e2e8e8e7df2134f8322d550740cb3e2967e5f2b24d8` |
| `bench/runs/gen25/summary.json` | `3a762bd041e3231c18247fd2b281aacb3323c29f5537a826946d93107d8e7e56` |
| `tests/evidence/diagnostics/gen25/context-notes.md` | `4e9b5a526921a3bf6d6c5d3ccede47932ec3cec71beeaf5e5b555729088296c9` |
| `tests/evidence/diagnostics/gen25/independent-review/source-review.json` | `489554ec0946e1d574b5261f17e1797b5d1b03e0e9168a72aec306def643dcf7` |
| `tests/evidence/diagnostics/gen25/benchmark-source-binding.json` | `8566df949a77df85d1d703a81697bd9e44d691f42ea0e9edc1e64e1c6b5f09e6` |

## Reviewed run-specific observations

Generation 25 adds only an exact equal-denominator identity arm to scaledNumerator. The original integer multiplication and natural-division formula remains verbatim for unequal denominators. The all-input theorem covers every natural denominator and rational value. [Current source/native review](../tests/evidence/diagnostics/gen25/independent-review/source-review.json) binds the actual branches inside choose and both scaledTotals folds. The measured benchmark regressed in both modes; these instruction observations assess the branch costs without presuming benefit or explaining elapsed-time causation. This report collects Impl.decode; the separate CPR diagnostic covers tracking and numeric geography. Comparisons with generation 24 are instruction observations, not throughput predictions.

The current checkout contains the committed generation-25 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.

The live UInt32 byte loop and generic bit-loop fallback, syndrome, paired parser, byte-value fold and frame field extractor are retained as explicit nested anchors. Historical checksum/frameSyndrome/packing boundaries are absent in the current timed worker; current source/native evidence establishes direct word use, rather than inferring absent work solely from symbols. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed byte loop has one entry per syndrome in this accepted corpus. Its byte-iteration count is predicted from frame widths, and each byte performs eight inlined updates. The callable bit-loop fallback has no observed entries here; it remains live for other widths. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable validity, density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 197 samples, 49 have a visible decoder ancestor and 148 are excluded; 194 stacks contain an unknown frame and 5 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen25/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

CRC wrapper and loop entries reconcile with the separately checked accepted-corpus census:

| Profile | Predicted CRC calls | Observed byte wrapper / loop | Observed bit wrapper / loop | Predicted byte iterations | Predicted bit updates |
|---|---:|---:|---:|---:|---:|
| adsb | 50,385 | 50,385 / 50,385 | 0 / 0 | 705,390 | 5,643,120 |
| commb | 47,714 | 47,714 / 47,714 | 0 / 0 | 667,996 | 5,343,968 |
| other | 74,333 | 74,333 / 74,333 | 0 / 0 | 539,189 | 4,313,512 |
| candidate40 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate44 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate45 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate50 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate60 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score40 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score44 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score45 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score50 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score60 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |

Observed entries are incoming native calls; iteration predictions are separate mathematical census data. All ten overlapping register probes are checked separately. The generic fallback remains callable and proved for arbitrary inputs; its zero accepted-corpus count does not remove its implementation or cost for unseen widths. Byte extraction and eight updates inline into the actual loop, which still contains natural-index and ownership work. [CRC boundary and direct-child evidence](../tests/evidence/diagnostics/gen25/crc-byte-contexts.json) compares both generations without copying old profiles or inferring elapsed time.

| Generation | CRC boundary | Native entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| 24 | `Parity_syndrome` | 172,432 | 4,310,800 | 588,137,357 |
| 24 | `Parity_syndromeBytes` | 172,432 | 6,295,014 | 583,826,557 |
| 24 | `decodeFrameWithWord` | 172,432 | 22,342,047 | 1,094,490,862 |
| 24 | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |
| 25 | `Parity_syndrome` | 172,432 | 4,310,800 | 588,137,357 |
| 25 | `Parity_syndromeBytes` | 172,432 | 6,295,014 | 583,826,557 |
| 25 | `decodeFrameWithWord` | 172,432 | 22,342,047 | 1,094,492,597 |
| 25 | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |

These nested inclusive rows overlap each other and frame/CRC stage cost. Only the exclusive stage partition can be added.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen25/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 379,488,067 |
| candidate44 | 47,166 | 0 | 0 | 0 | 11,836,862 |
| candidate45 | 47,166 | 0 | 0 | 0 | 11,932,998 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 106,455,314 | 487,962,842 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 339,791,291 | 884,954,498 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 353,763,260 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 106,517,936 | 455,728,506 |
| score60 | 19,356 | 19,356 | 2,429,938 | 339,815,920 | 850,726,232 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen25/penalty-probe-costs.json).

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

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen25/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,471,198 | 187,607 |
| other | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate60 | 17,394 | 17,386 | 8 | 4,593,636 | 158,996,477 | 187,526 |
| score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| score50 | 0 | 0 | 0 | 0 | 0 | 0 |
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 158,996,716 | 187,526 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen25/ratio-native-contexts.json) also records generation 24 and 25 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.

The live Comm-B guard and its direct decimal-parser calls:

| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |
|---|---|---:|---:|---:|---:|---:|
| 24 | adsb | 0 | 0 | 0 | 0 | 0 |
| 24 | commb | 627,880 | 18,451,163 | 302,070,107 | 0 | 0 |
| 24 | other | 0 | 0 | 0 | 0 | 0 |
| 24 | candidate40 | 47,166 | 1,273,482 | 19,450,419 | 0 | 0 |
| 24 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 24 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 24 | candidate50 | 47,166 | 1,273,482 | 24,162,353 | 0 | 0 |
| 24 | candidate60 | 47,166 | 1,367,814 | 24,911,606 | 0 | 0 |
| 24 | score40 | 0 | 0 | 0 | 0 | 0 |
| 24 | score44 | 0 | 0 | 0 | 0 | 0 |
| 24 | score45 | 0 | 0 | 0 | 0 | 0 |
| 24 | score50 | 0 | 0 | 0 | 0 | 0 |
| 24 | score60 | 0 | 0 | 0 | 0 | 0 |
| 25 | adsb | 0 | 0 | 0 | 0 | 0 |
| 25 | commb | 627,880 | 18,451,163 | 302,071,309 | 0 | 0 |
| 25 | other | 0 | 0 | 0 | 0 | 0 |
| 25 | candidate40 | 47,166 | 1,273,482 | 19,450,419 | 0 | 0 |
| 25 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 25 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 25 | candidate50 | 47,166 | 1,273,482 | 24,162,353 | 0 | 0 |
| 25 | candidate60 | 47,166 | 1,367,814 | 24,911,606 | 0 | 0 |
| 25 | score40 | 0 | 0 | 0 | 0 | 0 |
| 25 | score44 | 0 | 0 | 0 | 0 | 0 |
| 25 | score45 | 0 | 0 | 0 | 0 | 0 |
| 25 | score50 | 0 | 0 | 0 | 0 | 0 |
| 25 | score60 | 0 | 0 | 0 | 0 | 0 |

These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen25/constant-native-contexts.json).

The retained generic packing fold has no collected entries in either generation:

| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |
|---|---:|---:|---:|---|---:|---:|

Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The standalone packing source and generated-C definition retain generic power/modulus behavior, while neither compared timed decoder links or calls that fold. The zero current incoming count is checked alongside the explicit raw-word path, not treated as an independent no-work proof. [Exact packing contexts](../tests/evidence/diagnostics/gen25/pack-fields-direct-costs.json).

The live power-of-two lookup, formula fallback and startup construction:

| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |
|---|---|---:|---:|---:|---:|---:|---:|
| 24 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 24 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 24 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 24 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 24 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 24 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 24 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 24 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 24 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 24 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 24 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 24 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 24 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 25 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 25 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 25 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 25 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 25 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 25 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 25 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 25 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 25 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 25 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 25 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 25 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 25 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |

These are actual retained incoming boundaries and direct lookup-to-formula edges. Both generations retain the same immutable format-exponent table. In the current worker, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen25/power-native-contexts.json).

The four optimized extraction paths, compared at actual retained native boundaries:

| Generation | Stage | Native boundary | Entries | Self Ir | Incoming inclusive Ir | Direct pow calls | Direct pow inclusive Ir |
|---|---|---|---:|---:|---:|---:|---:|
| 24 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 24 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 24 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 8,203,568 | 0 | 0 |
| 24 | commb_inference | `payloadInteger` | 56,072 | 2,420,620 | 30,039,508 | 0 | 0 |
| 24 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 24 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 24 | semantic_oracle_values | `payloadInteger` | 1,010,093 | 36,137,759 | 192,048,237 | 0 | 0 |
| 24 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |
| 25 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 25 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 25 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 8,203,649 | 0 | 0 |
| 25 | commb_inference | `payloadInteger` | 56,072 | 2,420,620 | 30,039,508 | 0 | 0 |
| 25 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 25 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 25 | semantic_oracle_values | `payloadInteger` | 1,010,093 | 36,137,759 | 192,048,353 | 0 | 0 |
| 25 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |

Both generations inline the identity lambda into identityCode; missing standalone rows do not erase the live extraction. Other small arithmetic can inline too. Native entry populations across these changed boundaries are not assumed equal. The current direct-power count is zero only for these selected caller boundaries, consistent with the checked shift/mask implementation; it is not a zero-work claim or a claim about all decoder powers. Incoming inclusive columns overlap stage totals and other helpers. [Exact old/new contexts and direct children](../tests/evidence/diagnostics/gen25/bit-extraction-contexts.json) bind both raw profile sets without copying them or predicting timing.

The exact affine helper is compared at surviving native boundaries:

| Generation | Stage | Boundary | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---|---:|---:|---:|
| 24 | commb_inference | `l_Rat_mul` | 18,719 | 3,847,020 | 107,350,609 |
| 24 | commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,054,689 |
| 24 | semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,054,916 |
| 24 | semantic_oracle_values | `payloadValue` | 994,915 | 107,280,314 | 719,470,215 |
| 25 | commb_inference | `l_Rat_mul` | 18,719 | 3,847,020 | 107,352,034 |
| 25 | commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,058,336 |
| 25 | semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,055,936 |
| 25 | semantic_oracle_values | `payloadValue` | 994,915 | 107,280,314 | 719,456,713 |

The payloadValue entry populations are independently recounted by stage in both generations; the existing semantic sharing is unchanged this generation, and equality is reported as an observed boolean rather than assumed. Inline integerScale/affineValue calls have no standalone native entry count. The current source and all-input proof establish normalization and preserved guards; actual direct children below show the observed arithmetic boundaries.

| Generation | Stage | Direct child of payloadValue | Calls | Inclusive Ir |
|---|---|---|---:|---:|
| 24 | commb_inference | `l_Rat_ofInt` | 17,406 | 520,969 |
| 24 | commb_inference | `l_instDecidableEqRat_decEq` | 112,144 | 2,851,898 |
| 24 | commb_inference | `lean_alloc_small_object_core` | 94,738 | 1,942,998 |
| 24 | commb_inference | `lean_nat_gcd` | 38,666 | 57,771,127 |
| 24 | commb_inference | `lean_obj_once_cold` | 2 | 576 |
| 24 | commb_inference | `payloadBits` | 114,116 | 6,846,960 |
| 24 | commb_inference | `payloadInteger` | 56,072 | 30,039,508 |
| 24 | semantic_oracle_values | `l_Rat_add` | 15,513 | 26,732,390 |
| 24 | semantic_oracle_values | `l_Rat_ofInt` | 821,979 | 28,718,719 |
| 24 | semantic_oracle_values | `l_instDecidableEqRat_decEq` | 1,971,060 | 50,421,780 |
| 24 | semantic_oracle_values | `lean_alloc_small_object_core` | 1,149,081 | 27,360,542 |
| 24 | semantic_oracle_values | `lean_dec_ref_cold` | 39,433 | 4,101,032 |
| 24 | semantic_oracle_values | `lean_nat_gcd` | 163,551 | 246,742,860 |
| 24 | semantic_oracle_values | `lean_obj_once_cold` | 2 | 576 |
| 24 | semantic_oracle_values | `payloadBits` | 1,194,515 | 71,670,900 |
| 24 | semantic_oracle_values | `payloadInteger` | 985,530 | 156,441,102 |
| 25 | commb_inference | `l_Rat_ofInt` | 17,406 | 522,556 |
| 25 | commb_inference | `l_instDecidableEqRat_decEq` | 112,144 | 2,851,898 |
| 25 | commb_inference | `lean_alloc_small_object_core` | 94,738 | 1,945,058 |
| 25 | commb_inference | `lean_nat_gcd` | 38,666 | 57,771,127 |
| 25 | commb_inference | `lean_obj_once_cold` | 2 | 576 |
| 25 | commb_inference | `payloadBits` | 114,116 | 6,846,960 |
| 25 | commb_inference | `payloadInteger` | 56,072 | 30,039,508 |
| 25 | semantic_oracle_values | `l_Rat_add` | 15,513 | 26,730,608 |
| 25 | semantic_oracle_values | `l_Rat_ofInt` | 821,979 | 28,699,751 |
| 25 | semantic_oracle_values | `l_instDecidableEqRat_decEq` | 1,971,060 | 50,421,780 |
| 25 | semantic_oracle_values | `lean_alloc_small_object_core` | 1,149,081 | 27,367,674 |
| 25 | semantic_oracle_values | `lean_dec_ref_cold` | 39,433 | 4,101,032 |
| 25 | semantic_oracle_values | `lean_nat_gcd` | 163,551 | 246,742,860 |
| 25 | semantic_oracle_values | `lean_obj_once_cold` | 2 | 576 |
| 25 | semantic_oracle_values | `payloadBits` | 1,194,515 | 71,670,900 |
| 25 | semantic_oracle_values | `payloadInteger` | 985,530 | 156,441,218 |

These are overlapping incoming/direct-edge observations, not exclusive savings. Zero current direct Rat.mul calls concern only the listed payloadValue contexts: normalization still performs a numerator product, gcd and exact divisions, with small-value operations possibly inlined. Child calls do not count every nonunit input or logical operation. [Exact affine contexts](../tests/evidence/diagnostics/gen25/affine-native-contexts.json) retain both profile hashes and group reconciliation.

Semantic construction shares the existing table values and labels, which were already CSE-shared before generation 24. The current oracle scalar map adjusts those values without a second layout lookup or payloadValue decode; public commBValue remains live elsewhere. One pure numeric-expression list feeds both views, preserving register-specific branches. These constructors build exact expressions; they do not introduce Float execution.

| Generation | Direct payloadValue caller | Semantic ancestor | Calls | Incoming inclusive Ir |
|---|---|---|---:|---:|
| 24 | `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0` | Semantics_adsb | 462,367 | 165,835,184 |
| 24 | `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0` | Semantics_commB | 532,548 | 553,635,031 |
| 25 | `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0` | Semantics_adsb | 462,367 | 165,823,275 |
| 25 | `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0` | Semantics_commB | 532,548 | 553,633,438 |

The actual semantic caller comparison and current map direct-child contexts are retained in [semantic-caller-contexts.json](../tests/evidence/diagnostics/gen25/semantic-caller-contexts.json). Costs overlap parents, descendants and stage totals; they are not additive savings or predicted timing. Inlined helpers and identity-list branches have no independent call counter.

The equal-denominator change is compared in actual choose and scaledTotals contexts:

| Generation | Stage | Boundary | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---|---:|---:|---:|
| 24 | commb_inference | `_init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0` | 1 | 2 | 2 |
| 24 | commb_inference | `_init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1` | 1 | 18 | 235 |
| 24 | commb_inference | `ScoreGate_choose` | 45,510 | 19,248,889 | 1,233,320,887 |
| 24 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,477,536 |
| 24 | commb_inference | `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | 45,510 | 13,612,673 | 468,612,198 |
| 25 | commb_inference | `_init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__0` | 1 | 2 | 2 |
| 25 | commb_inference | `_init_lp_lean1090_Lean1090_Impl_ScoreGate_scaledTotals___closed__1` | 1 | 18 | 235 |
| 25 | commb_inference | `ScoreGate_choose` | 45,510 | 19,201,184 | 1,175,667,837 |
| 25 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 8,754,868 | 586,539,438 |
| 25 | commb_inference | `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | 45,510 | 16,154,724 | 423,630,489 |

| Generation | Caller | Direct arithmetic child | Calls | Incoming inclusive Ir |
|---|---|---|---:|---:|
| 24 | `ScoreGate_choose` | `lean_int_big_mul` | 237,749 | 179,007,962 |
| 24 | `ScoreGate_choose` | `lean_nat_big_div` | 1,356 | 1,975,244 |
| 24 | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | `lean_int_big_mul` | 45,510 | 31,611,326 |
| 24 | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | `lean_nat_big_div` | 1,356 | 1,386,314 |
| 24 | `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | `lean_int_big_mul` | 95,802 | 73,754,162 |
| 24 | `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | `lean_nat_big_div` | 2,899 | 3,832,394 |
| 25 | `ScoreGate_choose` | `lean_int_big_mul` | 234,950 | 176,806,181 |
| 25 | `ScoreGate_choose` | `lean_nat_big_div` | 1,356 | 1,975,406 |
| 25 | `ScoreGate_choose` | `lean_nat_big_eq` | 1,356 | 8,136 |
| 25 | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | `lean_int_big_mul` | 34,328 | 22,843,779 |
| 25 | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | `lean_nat_big_div` | 539 | 760,492 |
| 25 | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | `lean_nat_big_eq` | 1,356 | 42,450 |
| 25 | `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | `lean_int_big_mul` | 46,456 | 35,108,591 |
| 25 | `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | `lean_nat_big_div` | 2,360 | 3,423,202 |
| 25 | `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | `lean_nat_big_eq` | 2,899 | 39,535 |

The complete direct-child and caller-context records are in [score-scale-contexts.json](../tests/evidence/diagnostics/gen25/score-scale-contexts.json). These are observed native boundaries; small arithmetic and the equality test may inline. No denominator-equality hit rate follows from helper absence or differences in division/multiplication calls. Choose also contains threshold and penalty arithmetic. Both folds and descendants overlap each other and the exclusive stage; their costs cannot be summed as savings. The existing all-input census separately checks each scored-register population.

Selected actual nested helpers for prioritization:

| Stage | Native helper | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| commb_inference | `ScoreGate_choose` | 45,510 | 19,201,184 | 1,175,667,837 |
| commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 8,754,868 | 586,539,438 |
| commb_inference | `bdsWireValid` | 627,880 | 18,451,163 | 302,071,309 |
| commb_inference | `l_Rat_div` | 18,057 | 144,456 | 126,964,520 |
| commb_inference | `commBValue` | 58,044 | 11,121,649 | 126,596,660 |
| commb_inference | `cbValid21` | 47,854 | 3,200,897 | 110,327,050 |
| commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,058,336 |
| commb_inference | `l_Rat_mul` | 18,719 | 3,847,020 | 107,352,034 |
| commb_inference | `ScoreGate_commonDenominator` | 45,510 | 5,882,374 | 43,951,384 |
| commb_inference | `cbValid60` | 64,315 | 3,647,763 | 35,127,332 |
| commb_inference | `cbValid50` | 56,979 | 3,820,724 | 30,238,839 |
| commb_inference | `cbValid40` | 62,679 | 3,527,349 | 27,949,710 |
| commb_inference | `cbValid18` | 47,171 | 613,237 | 19,856,066 |
| commb_inference | `cbValid19` | 47,166 | 235,830 | 14,192,349 |
| commb_inference | `cbValid17` | 47,498 | 1,210,360 | 5,759,260 |
| commb_inference | `cbValid44` | 47,166 | 1,051,620 | 4,195,970 |
| commb_inference | `cbValid45` | 47,166 | 943,320 | 3,773,280 |
| frame_crc | `decodeFrameWithWord` | 172,432 | 22,342,047 | 1,094,492,597 |
| frame_crc | `Parity_syndrome` | 172,432 | 4,310,800 | 588,137,357 |
| frame_crc | `field` | 881,619 | 56,178,834 | 564,547,148 |
| frame_crc | `bytesValue` | 172,432 | 31,171,820 | 454,143,706 |
| frame_crc | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |
| output_model_control | `reportWithSyndrome` | 172,432 | 15,247,428 | 4,025,753,757 |
| semantic_oracle_values | `Semantics_commB` | 46,440 | 5,246,365 | 936,889,209 |
| semantic_oracle_values | `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0` | 96,825 | 57,316,780 | 835,664,645 |
| semantic_oracle_values | `payloadValue` | 994,915 | 107,280,314 | 719,456,713 |
| semantic_oracle_values | `Semantics_adsb` | 51,212 | 4,166,624 | 500,668,642 |
| semantic_oracle_values | `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commBOracleValues_spec__0` | 45,613 | 62,384,311 | 235,188,050 |
| semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,055,936 |
| semantic_oracle_values | `l_Rat_add` | 40,716 | 5,754,560 | 68,011,453 |
| semantic_oracle_values | `Presentation_oracleCommBFloats` | 45,613 | 4,864,700 | 58,008,156 |
| semantic_oracle_values | `l_Rat_div` | 4,508 | 36,064 | 14,732,922 |

These rows aggregate only the three disjoint family profiles. Incoming inclusive observations overlap each other and stage totals, including recursive visits and descendants crossing a stage boundary. Direct native children and exact caller contexts are retained in [priority-helper-contexts.json](../tests/evidence/diagnostics/gen25/priority-helper-contexts.json). Rat multiplication rows do not count every logical affine operation; inline work remains in callers. These observations do not select an optimization or infer throughput.


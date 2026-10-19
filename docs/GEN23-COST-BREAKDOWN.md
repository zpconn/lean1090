# Generation 23: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `0ead24dfeba4f6cb95926f0a0fb8624f4ed08807` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 2,306,055,650 of 6,562,740,540 collected guest instructions (35.14%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-23 benchmark is decode **2.41023×** and CPR **1.83573×**; see [bench/runs/gen23/summary.json](../bench/runs/gen23/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 1,425,907,717 | 28,300.2 | 21.73% |
| commb | 47,714 | 4,760,806,695 | 99,778.0 | 72.54% |
| other | 74,333 | 376,026,128 | 5,058.7 | 5.73% |
| Total | 172,432 | 6,562,740,540 | 38,059.9 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 2,303,561,290 | 1,486,660 | 2,306,055,650 | 35.14% |
| Semantic / oracle value construction | 509,363,470 | 1,708,404,812 | 11,299,694 | 2,229,067,976 | 33.97% |
| Frame / CRC | 703,876,797 | 721,736,412 | 347,497,528 | 1,773,110,737 | 27.02% |
| ADS-B fields / checks | 190,348,773 | 477,140 | 743,330 | 191,569,243 | 2.92% |
| Output-model construction / residual control | 21,310,977 | 26,627,041 | 14,998,916 | 62,936,934 | 0.96% |

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

## Comparison with generation 22

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen22 Ir | Gen23 Ir | Difference (gen23 − gen22) | Gen23/gen22 | Gen22 Ir/message | Gen23 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 3,003,800,578 | 2,306,055,650 | -697,744,928 | 0.76771 | 17,420.20 | 13,373.71 |
| Semantic / oracle value construction | 2,229,202,616 | 2,229,067,976 | -134,640 | 0.99994 | 12,928.01 | 12,927.23 |
| Frame / CRC | 1,773,033,054 | 1,773,110,737 | +77,683 | 1.00004 | 10,282.51 | 10,282.96 |
| ADS-B fields / checks | 191,586,007 | 191,569,243 | -16,764 | 0.99991 | 1,111.08 | 1,110.98 |
| Output-model construction / residual control | 62,860,932 | 62,936,934 | +76,002 | 1.00121 | 364.55 | 365.00 |
| Total | 7,260,483,187 | 6,562,740,540 | -697,742,647 | 0.90390 | 42,106.36 | 38,059.88 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 407,428,808 | 381,717,489 |
| BDS44 | 47,166 | 0 | 0 | 11,836,862 | 0 |
| BDS45 | 47,166 | 0 | 0 | 11,932,998 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 498,747,111 | 466,520,428 |
| BDS60 | 47,166 | 19,356 | 17,149 | 903,877,697 | 869,642,939 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen23/independent-review/source-review.json](../tests/evidence/diagnostics/gen23/independent-review/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| 20 | 29,460 | 6,756,156 | 229.33 | Yes |
| 21 | 18,254 | 4,214,901 | 230.90 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 17,048,376 small allocations. The sum of separate DF loops is 17,048,545, a difference of 169. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | Not observed in collected call contexts | Not assigned |
| `decodeFrameWithWord` | 172,432 | 1,094,552,225 |
| `frameSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,249,867 |
| `reportWithSyndrome` | 172,432 | 4,840,171,945 |
| `Parity_checksum` | Not observed in collected call contexts | Not assigned |
| `Parity_syndrome` | 172,432 | 588,137,357 |
| `Parity_step` | Not observed in collected call contexts | Not assigned |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 447,298,451 |
| `Semantics_adsb` | 51,212 | 500,662,167 |
| `Semantics_commB` | 46,440 | 1,693,729,102 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `_init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1` | Not observed in collected call contexts | Not assigned |
| `initialize_lean1090_Impl_Binary64` | Not observed in collected call contexts | Not assigned |
| `l_Rat_add` | 56,229 | 95,169,077 |
| `l_Rat_div` | 22,565 | 141,717,792 |
| `l_Rat_mul` | 56,601 | 229,397,013 |
| `l_Rat_normalize` | Not observed in collected call contexts | Not assigned |
| `lean_cstr_to_nat` | 50,390 | 38,900,980 |
| `Altitude_bit` | 63,893 | 1,469,539 |
| `Altitude_grayDecode` | 10,668 | 8,161,682 |
| `Binary64_div` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwo` | 1,324 | 116,512 |
| `Binary64_powerTwoFormula` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwoTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `Binary64_round` | 662 | 15,453,937 |
| `CPR_Policy_toFloat` | Not observed in collected call contexts | Not assigned |
| `CPR_Policy_toFloatFallback` | Not observed in collected call contexts | Not assigned |
| `Parity_syndromeBits` | Not observed in collected call contexts | Not assigned |
| `Parity_syndromeBytes` | 172,432 | 583,826,557 |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,233,180,897 |
| `ScoreGate_commonDenominator` | 45,510 | 43,899,146 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `Semantics_commBStandardFloats` | Not observed in collected call contexts | Not assigned |
| `Semantics_tableValues` | Not observed in collected call contexts | Not assigned |
| `acasParts` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bdsWireValid` | 627,880 | 302,020,676 |
| `bytesValue` | 172,432 | 454,201,646 |
| `bytesWord` | Not observed in collected call contexts | Not assigned |
| `bytesWordPrefix` | 100,793 | 41,415,513 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,491,841 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbMachValid60` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbQNHValid40` | Not observed in collected call contexts | Not assigned |
| `cbRatioOutside250800` | 17,394 | 159,441,573 |
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
| `commBValue` | 583,976 | 986,809,479 |
| `field` | 881,619 | 564,522,886 |
| `findPayloadField` | Not observed in collected call contexts | Not assigned |
| `frameParts` | Not observed in collected call contexts | Not assigned |
| `identityCode` | 21,257 | 7,057,324 |
| `identityCode___lam__0` | Not observed in collected call contexts | Not assigned |
| `integerScale` | Not observed in collected call contexts | Not assigned |
| `oracleCommBFloats` | Not observed in collected call contexts | Not assigned |
| `packFields` | Not observed in collected call contexts | Not assigned |
| `payloadBits` | 7,448,230 | 446,893,800 |
| `payloadInteger` | 1,587,001 | 344,458,319 |
| `payloadValue` | 1,578,891 | 1,380,852,839 |
| `surveillanceParts` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,766 | 5,262,564 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 641,398,916 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | Not observed in collected call contexts | Not assigned |
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
| `lean_nat_big_shiftr` | 615,557 | 346,082,194 | 19.52% |
| `lean_uint64_of_big_nat` | 302,379 | 269,404,817 | 15.19% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 2,306,055,650 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 2,291,674,918 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 2,291,484,062 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 2,094,893,362 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 2,027,855,972 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 1,718,448,042 |
| `lp_lean1090_Lean1090_Impl_ScoreGate_choose` | 45,510 | 19,248,889 | 1,233,180,897 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,398,916 |
| `lean::mpz::~mpz()` | 4,826,370 | 19,305,480 | 499,450,988 |
| `__gmpz_clear` | 4,826,370 | 33,381,981 | 480,145,508 |
| `lp_lean1090_List_foldl___at___00List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0_spec__0` | 45,510 | 13,612,673 | 468,560,899 |
| `lp_lean1090_Lean1090_Impl_cbPenalty` | 45,510 | 4,164,506 | 447,298,451 |
| `__gmp_default_free` | 4,692,167 | 9,384,334 | 446,763,527 |
| `free` | 4,692,169 | 182,994,591 | 437,379,379 |
| `lean::mpz::mpz(lean::mpz const&)` | 3,567,374 | 3,567,374 | 357,365,221 |

The source and generated C retained under `tests/evidence/diagnostics/gen23` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-23 benchmark binary retained 197 samples; 46 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: report other/self/unresolved substage: 11; Comm-B inference and raw payload: 8; shared frame syndrome: 7; ADS-B semantic projection: 6; frame extraction: 6; Comm-B semantic projection: 5; ADS-B raw payload: 3. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused unchanged native production objects originally built from timed commit `9b6868f21fcac0a59044153f01e6691d091dbb5c`; their audited source blobs also match diagnostic checkout `0ead24dfeba4f6cb95926f0a0fb8624f4ed08807`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen23/analysis/analysis.json](../tests/evidence/diagnostics/gen23/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen23/native/all.jsonl](../tests/evidence/diagnostics/gen23/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen23/native-df/summary.json](../tests/evidence/diagnostics/gen23/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen23/perf/analysis.json](../tests/evidence/diagnostics/gen23/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen23/driver/driver-build.json](../tests/evidence/diagnostics/gen23/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen23/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen23/analysis/analysis.json` | `50950fb012678e1e2b64ee9779ce9cd486c4e451b7876f7c04f2499af4d3813e` |
| `tests/evidence/diagnostics/gen23/native/all.jsonl` | `8e4e92f8bb5e54cef9b0f8789535bdffe5feb81c250cd6dcadb5be6e0c0d86a8` |
| `tests/evidence/diagnostics/gen23/native-df/summary.json` | `06d835258465077401dd9da1f63208dca876d6c7c07102ab33c2e94db06e1b99` |
| `tests/evidence/diagnostics/gen23/perf/analysis.json` | `a714ae1bac4582e4fff9208aa8c105f7c000cc721f9db25e96ad79ae4308131e` |
| `tests/evidence/diagnostics/gen23/driver/driver-build.json` | `abd4b9f9c6501106f5ddad589dd5e738a9824676c61c2fd3da0dd9ad504eaf07` |
| `tests/evidence/diagnostics/gen22/analysis/analysis.json` | `4e2fb3640a94b2122eb8e814dc9c47d9af88a0893d076526400c9c59a4eb9b5f` |
| `tests/evidence/diagnostics/gen23/campaign.json` | `223bd0073b48f47afa5f71d47c6c3d19efcef3a6b8b57fa4a060df1eae38af69` |
| `bench/runs/gen23/summary.json` | `211395667a7cd4c2eb7069ab4c260d107d21c811296a981906c9b8ede6b63cc1` |
| `tests/evidence/diagnostics/gen23/context-notes.md` | `aa44aa1aa6b056cfe064882edfdb4a61f6721c66b25c6cd379eb7fe4eaf3a5c2` |
| `tests/evidence/diagnostics/gen23/independent-review/source-review.json` | `8a10741740fa07a7054215cefafbdcbf4257482f764a5d9fdbea7ebbd00fcf46` |
| `tests/evidence/diagnostics/gen23/benchmark-source-binding.json` | `c4628c7b56d6f506d5a2a86759ad5d0c90b709d2b945135ece7d132083baf360` |

## Reviewed run-specific observations

Generation 23 replaces five exact Comm-B field validity calculations with immutable Bool tables covering every field code. Existing status, sentinel and final validity guards remain live, with unconditional proofs preserving every natural input word and complete decoder refinement. [Current source/native review](../tests/evidence/diagnostics/gen23/independent-review/source-review.json) binds current BDS40/50/60 calls, inlined table accesses and initialization as well as the unchanged raw-word CRC and semantic paths. This report collects actual Impl.decode only; the separate CPR diagnostic covers tracking and numeric geography. Comparisons with generation 22 are instruction observations, not throughput predictions or inferred path distributions.

The current checkout contains the committed generation-23 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.

The live UInt32 byte loop and generic bit-loop fallback, syndrome, paired parser, byte-value fold and frame field extractor are retained as explicit nested anchors. Historical checksum/frameSyndrome/packing boundaries are absent in the current timed worker; current source/native evidence establishes direct word use, rather than inferring absent work solely from symbols. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed byte loop has one entry per syndrome in this accepted corpus. Its byte-iteration count is predicted from frame widths, and each byte performs eight inlined updates. The callable bit-loop fallback has no observed entries here; it remains live for other widths. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable validity, density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 197 samples, 46 have a visible decoder ancestor and 151 are excluded; 197 stacks contain an unknown frame and 0 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen23/perf/README.md).

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

Observed entries are incoming native calls; iteration predictions are separate mathematical census data. All ten overlapping register probes are checked separately. The generic fallback remains callable and proved for arbitrary inputs; its zero accepted-corpus count does not remove its implementation or cost for unseen widths. Byte extraction and eight updates inline into the actual loop, which still contains natural-index and ownership work. [CRC boundary and direct-child evidence](../tests/evidence/diagnostics/gen23/crc-byte-contexts.json) compares both generations without copying old profiles or inferring elapsed time.

| Generation | CRC boundary | Native entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| 22 | `Parity_syndrome` | 172,432 | 4,310,800 | 588,137,357 |
| 22 | `Parity_syndromeBytes` | 172,432 | 6,295,014 | 583,826,557 |
| 22 | `decodeFrameWithWord` | 172,432 | 22,342,047 | 1,094,474,480 |
| 22 | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |
| 23 | `Parity_syndrome` | 172,432 | 4,310,800 | 588,137,357 |
| 23 | `Parity_syndromeBytes` | 172,432 | 6,295,014 | 583,826,557 |
| 23 | `decodeFrameWithWord` | 172,432 | 22,342,047 | 1,094,552,225 |
| 23 | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |

These nested inclusive rows overlap each other and frame/CRC stage cost. Only the exclusive stage partition can be added.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen23/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 407,428,808 |
| candidate44 | 47,166 | 0 | 0 | 0 | 11,836,862 |
| candidate45 | 47,166 | 0 | 0 | 0 | 11,932,998 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 106,434,021 | 498,747,111 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 339,837,620 | 903,877,697 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,717,489 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 106,428,411 | 466,520,428 |
| score60 | 19,356 | 19,356 | 2,429,938 | 339,853,072 | 869,642,939 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen23/penalty-probe-costs.json).

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

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen23/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,441,573 | 187,445 |
| other | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,015,891 | 187,931 |
| score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| score50 | 0 | 0 | 0 | 0 | 0 | 0 |
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,005,601 | 187,931 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen23/ratio-native-contexts.json) also records generation 22 and 23 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.

The live Comm-B guard and its direct decimal-parser calls:

| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |
|---|---|---:|---:|---:|---:|---:|
| 22 | adsb | 0 | 0 | 0 | 0 | 0 |
| 22 | commb | 627,880 | 18,451,163 | 999,646,182 | 0 | 0 |
| 22 | other | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate40 | 47,166 | 1,273,482 | 128,357,469 | 0 | 0 |
| 22 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 22 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 22 | candidate50 | 47,166 | 1,273,482 | 194,872,662 | 0 | 0 |
| 22 | candidate60 | 47,166 | 1,367,814 | 143,006,297 | 0 | 0 |
| 22 | score40 | 0 | 0 | 0 | 0 | 0 |
| 22 | score44 | 0 | 0 | 0 | 0 | 0 |
| 22 | score45 | 0 | 0 | 0 | 0 | 0 |
| 22 | score50 | 0 | 0 | 0 | 0 | 0 |
| 22 | score60 | 0 | 0 | 0 | 0 | 0 |
| 23 | adsb | 0 | 0 | 0 | 0 | 0 |
| 23 | commb | 627,880 | 18,451,163 | 302,020,676 | 0 | 0 |
| 23 | other | 0 | 0 | 0 | 0 | 0 |
| 23 | candidate40 | 47,166 | 1,273,482 | 19,450,419 | 0 | 0 |
| 23 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 23 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 23 | candidate50 | 47,166 | 1,273,482 | 24,162,353 | 0 | 0 |
| 23 | candidate60 | 47,166 | 1,367,814 | 24,911,606 | 0 | 0 |
| 23 | score40 | 0 | 0 | 0 | 0 | 0 |
| 23 | score44 | 0 | 0 | 0 | 0 | 0 |
| 23 | score45 | 0 | 0 | 0 | 0 | 0 |
| 23 | score50 | 0 | 0 | 0 | 0 | 0 |
| 23 | score60 | 0 | 0 | 0 | 0 | 0 |

These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen23/constant-native-contexts.json).

The retained generic packing fold has no collected entries in either generation:

| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |
|---|---:|---:|---:|---|---:|---:|

Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The standalone packing source and generated-C definition retain generic power/modulus behavior, while neither compared timed decoder links or calls that fold. The zero current incoming count is checked alongside the explicit raw-word path, not treated as an independent no-work proof. [Exact packing contexts](../tests/evidence/diagnostics/gen23/pack-fields-direct-costs.json).

The live power-of-two lookup, formula fallback and startup construction:

| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |
|---|---|---:|---:|---:|---:|---:|---:|
| 22 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 22 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 22 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 22 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 22 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 23 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 23 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 23 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 23 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 23 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 23 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 23 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 23 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 23 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 23 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 23 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 23 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 23 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |

These are actual retained incoming boundaries and direct lookup-to-formula edges. Both generations retain the same immutable format-exponent table. In the current worker, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen23/power-native-contexts.json).

The four optimized extraction paths, compared at actual retained native boundaries:

| Generation | Stage | Native boundary | Entries | Self Ir | Incoming inclusive Ir | Direct pow calls | Direct pow inclusive Ir |
|---|---|---|---:|---:|---:|---:|---:|
| 22 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 22 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 22 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 8,183,432 | 0 | 0 |
| 22 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 104,100,113 | 0 | 0 |
| 22 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 22 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 22 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 314,418,869 | 0 | 0 |
| 22 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |
| 23 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 23 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 23 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 8,161,682 | 0 | 0 |
| 23 | commb_inference | `payloadInteger` | 56,072 | 2,420,620 | 30,039,508 | 0 | 0 |
| 23 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 23 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 23 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 314,418,811 | 0 | 0 |
| 23 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |

Both generations inline the identity lambda into identityCode; missing standalone rows do not erase the live extraction. Other small arithmetic can inline too. Native entry populations across these changed boundaries are not assumed equal. The current direct-power count is zero only for these selected caller boundaries, consistent with the checked shift/mask implementation; it is not a zero-work claim or a claim about all decoder powers. Incoming inclusive columns overlap stage totals and other helpers. [Exact old/new contexts and direct children](../tests/evidence/diagnostics/gen23/bit-extraction-contexts.json) bind both raw profile sets without copying them or predicting timing.

The exact affine helper is compared at surviving native boundaries:

| Generation | Stage | Boundary | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---|---:|---:|---:|
| 22 | commb_inference | `l_Rat_mul` | 101,573 | 20,661,829 | 373,016,854 |
| 22 | commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,026,783 |
| 22 | semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,078,124 |
| 22 | semantic_oracle_values | `payloadValue` | 1,520,847 | 169,626,425 | 1,271,877,672 |
| 23 | commb_inference | `l_Rat_mul` | 18,719 | 3,847,020 | 107,367,182 |
| 23 | commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,026,427 |
| 23 | semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,029,831 |
| 23 | semantic_oracle_values | `payloadValue` | 1,520,847 | 169,626,425 | 1,271,826,412 |

The payloadValue entry populations are independently checked equal by stage across these two profiles. Inline integerScale/affineValue calls have no standalone native entry count. The current source and all-input proof establish normalization and preserved guards; actual direct children below show the observed arithmetic boundaries.

| Generation | Stage | Direct child of payloadValue | Calls | Inclusive Ir |
|---|---|---|---:|---:|
| 22 | commb_inference | `l_Rat_ofInt` | 17,406 | 511,906 |
| 22 | commb_inference | `l_instDecidableEqRat_decEq` | 112,144 | 2,851,898 |
| 22 | commb_inference | `lean_alloc_small_object_core` | 94,738 | 1,924,155 |
| 22 | commb_inference | `lean_nat_gcd` | 38,666 | 57,771,127 |
| 22 | commb_inference | `lean_obj_once_cold` | 2 | 576 |
| 22 | commb_inference | `payloadBits` | 114,116 | 6,846,960 |
| 22 | commb_inference | `payloadInteger` | 56,072 | 30,039,508 |
| 22 | semantic_oracle_values | `l_Rat_add` | 31,026 | 53,464,902 |
| 22 | semantic_oracle_values | `l_Rat_ofInt` | 1,181,731 | 41,329,909 |
| 22 | semantic_oracle_values | `l_instDecidableEqRat_decEq` | 3,012,732 | 76,694,274 |
| 22 | semantic_oracle_values | `lean_alloc_small_object_core` | 1,831,001 | 44,341,125 |
| 22 | semantic_oracle_values | `lean_dec_ref_cold` | 39,433 | 4,101,032 |
| 22 | semantic_oracle_values | `lean_nat_gcd` | 324,635 | 489,703,895 |
| 22 | semantic_oracle_values | `lean_obj_once_cold` | 2 | 576 |
| 22 | semantic_oracle_values | `payloadBits` | 1,896,730 | 113,803,800 |
| 22 | semantic_oracle_values | `payloadInteger` | 1,506,366 | 278,811,734 |
| 23 | commb_inference | `l_Rat_ofInt` | 17,406 | 505,964 |
| 23 | commb_inference | `l_instDecidableEqRat_decEq` | 112,144 | 2,851,898 |
| 23 | commb_inference | `lean_alloc_small_object_core` | 94,738 | 1,929,741 |
| 23 | commb_inference | `lean_nat_gcd` | 38,666 | 57,771,127 |
| 23 | commb_inference | `lean_obj_once_cold` | 2 | 576 |
| 23 | commb_inference | `payloadBits` | 114,116 | 6,846,960 |
| 23 | commb_inference | `payloadInteger` | 56,072 | 30,039,508 |
| 23 | semantic_oracle_values | `l_Rat_add` | 31,026 | 53,458,108 |
| 23 | semantic_oracle_values | `l_Rat_ofInt` | 1,181,731 | 41,493,018 |
| 23 | semantic_oracle_values | `l_instDecidableEqRat_decEq` | 3,012,732 | 76,694,274 |
| 23 | semantic_oracle_values | `lean_alloc_small_object_core` | 1,831,001 | 44,133,608 |
| 23 | semantic_oracle_values | `lean_dec_ref_cold` | 39,433 | 4,101,032 |
| 23 | semantic_oracle_values | `lean_nat_gcd` | 324,635 | 489,703,895 |
| 23 | semantic_oracle_values | `lean_obj_once_cold` | 2 | 576 |
| 23 | semantic_oracle_values | `payloadBits` | 1,896,730 | 113,803,800 |
| 23 | semantic_oracle_values | `payloadInteger` | 1,506,366 | 278,811,676 |

These are overlapping incoming/direct-edge observations, not exclusive savings. Zero current direct Rat.mul calls concern only the listed payloadValue contexts: normalization still performs a numerator product, gcd and exact divisions, with small-value operations possibly inlined. Child calls do not count every nonunit input or logical operation. [Exact affine contexts](../tests/evidence/diagnostics/gen23/affine-native-contexts.json) retain both profile hashes and group reconciliation.

Semantic construction rows retain standard tableValues, the separate oracle-value commBValue calls and standard/oracle Float constructors where callable. The already shared standard values and labels are not counted as duplicated calls. Direct child contexts preserve who called payloadValue; all such inclusive costs overlap and must not be added as savings. Inlined list maps and field helpers may have no callable boundary.

Selected actual nested helpers for prioritization:

| Stage | Native helper | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| commb_inference | `ScoreGate_choose` | 45,510 | 19,248,889 | 1,233,180,897 |
| commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,398,916 |
| commb_inference | `bdsWireValid` | 627,880 | 18,451,163 | 302,020,676 |
| commb_inference | `l_Rat_div` | 18,057 | 144,456 | 126,984,870 |
| commb_inference | `commBValue` | 58,044 | 11,121,649 | 126,574,218 |
| commb_inference | `cbValid21` | 47,854 | 3,200,897 | 110,365,545 |
| commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,026,427 |
| commb_inference | `l_Rat_mul` | 18,719 | 3,847,020 | 107,367,182 |
| commb_inference | `ScoreGate_commonDenominator` | 45,510 | 5,882,374 | 43,899,146 |
| commb_inference | `cbValid60` | 64,315 | 3,647,763 | 35,127,332 |
| commb_inference | `cbValid50` | 56,979 | 3,820,724 | 30,238,839 |
| commb_inference | `cbValid40` | 62,679 | 3,527,349 | 27,949,710 |
| commb_inference | `cbValid18` | 47,171 | 613,237 | 19,856,066 |
| commb_inference | `cbValid19` | 47,166 | 235,830 | 14,192,349 |
| commb_inference | `cbValid17` | 47,498 | 1,210,360 | 5,759,260 |
| commb_inference | `cbValid44` | 47,166 | 1,051,620 | 4,195,970 |
| commb_inference | `cbValid45` | 47,166 | 943,320 | 3,773,280 |
| frame_crc | `decodeFrameWithWord` | 172,432 | 22,342,047 | 1,094,552,225 |
| frame_crc | `Parity_syndrome` | 172,432 | 4,310,800 | 588,137,357 |
| frame_crc | `field` | 881,619 | 56,178,834 | 564,522,886 |
| frame_crc | `bytesValue` | 172,432 | 31,171,820 | 454,201,646 |
| frame_crc | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |
| output_model_control | `reportWithSyndrome` | 172,432 | 15,247,428 | 4,840,171,945 |
| semantic_oracle_values | `Semantics_commB` | 46,440 | 5,170,793 | 1,693,729,102 |
| semantic_oracle_values | `payloadValue` | 1,520,847 | 169,626,425 | 1,271,826,412 |
| semantic_oracle_values | `commBValue` | 525,932 | 109,896,032 | 860,235,261 |
| semantic_oracle_values | `Semantics_adsb` | 51,212 | 4,166,624 | 500,662,167 |
| semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,029,831 |
| semantic_oracle_values | `l_Rat_add` | 56,229 | 8,095,837 | 95,169,077 |
| semantic_oracle_values | `l_Rat_div` | 4,508 | 36,064 | 14,732,922 |

These rows aggregate only the three disjoint family profiles. Incoming inclusive observations overlap each other and stage totals, including recursive visits and descendants crossing a stage boundary. Direct native children and exact caller contexts are retained in [priority-helper-contexts.json](../tests/evidence/diagnostics/gen23/priority-helper-contexts.json). Rat multiplication rows do not count every logical affine operation; inline work remains in callers. These observations do not select an optimization or infer throughput.


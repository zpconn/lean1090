# Generation 7: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `7c3b44d246149a1c5aa671d119b6ba2be27d856b` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Semantic / oracle value construction**, with 9,668,833,265 of 27,331,126,731 collected guest instructions (35.38%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-7 benchmark is decode **0.74126×** and CPR **0.58118×**; see [bench/runs/gen7/summary.json](../bench/runs/gen7/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 6,675,589,979 | 132,491.6 | 24.42% |
| commb | 47,714 | 18,188,923,671 | 381,207.3 | 66.55% |
| other | 74,333 | 2,466,613,081 | 33,183.3 | 9.02% |
| Total | 172,432 | 27,331,126,731 | 158,503.8 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Semantic / oracle value construction | 2,912,528,207 | 6,610,745,358 | 145,559,700 | 9,668,833,265 | 35.38% |
| Frame / CRC | 3,543,756,644 | 3,809,215,684 | 2,303,947,109 | 9,656,919,437 | 35.33% |
| Comm-B candidate inference / raw records | 1,007,700 | 7,750,329,169 | 1,486,660 | 7,752,823,529 | 28.37% |
| ADS-B fields / checks | 205,730,853 | 477,140 | 743,330 | 206,951,323 | 0.76% |
| Output-model construction / residual control | 12,566,575 | 18,156,320 | 14,876,282 | 45,599,177 | 0.17% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Shared-syndrome census and native entries

The original shadow census is retained exactly for historical comparison; its repeated-CRC prediction is not the current expectation. A separate post-decode census reparses every corpus row, checks its frame and syndrome against the retained decoder result, and predicts one syndrome after successful parsing. This work occurs after collection and does not enter the decoder-root counters.

All 172,432 corpus rows are accepted, as required by the complete retained-output check. This census covers that accepted corpus only. It does not measure malformed frames or frames rejected after parsing; the latter now compute a syndrome before rejection, as documented by the source/native review.

| Family | Historical repeated-call prediction | Live one-per-frame prediction | Observed frameSyndrome / checksum entries | Observed CRC step entries |
|---|---:|---:|---:|---:|
| adsb | 81,780 | 50,385 | 50,385 / 50,385 | 5,643,120 |
| commb | 95,428 | 47,714 | 47,714 / 47,714 | 5,343,968 |
| other | 110,210 | 74,333 | 74,333 / 74,333 | 4,313,512 |

The new acceptance/address helpers keep their predecessor stages when they retain a native boundary. Acceptance control inlined into `decode` remains in that function's residual-control category; its called hard-validity helper retains the ADS-B category. No cost is reassigned by source-level intention. The renamed report helper retains the same report/semantic boundaries. These compiler-boundary changes must be considered when comparing stage deltas.

## Comparison with generation 6

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen6 Ir | Gen7 Ir | Difference (gen7 − gen6) | Gen7/gen6 | Gen6 Ir/message | Gen7 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Semantic / oracle value construction | 9,668,597,888 | 9,668,833,265 | +235,377 | 1.00002 | 56,071.95 | 56,073.31 |
| Frame / CRC | 9,657,231,524 | 9,656,919,437 | -312,087 | 0.99997 | 56,006.03 | 56,004.22 |
| Comm-B candidate inference / raw records | 10,590,559,330 | 7,752,823,529 | -2,837,735,801 | 0.73205 | 61,418.76 | 44,961.63 |
| ADS-B fields / checks | 206,951,381 | 206,951,323 | -58 | 1.00000 | 1,200.19 | 1,200.19 |
| Output-model construction / residual control | 45,474,849 | 45,599,177 | +124,328 | 1.00273 | 263.73 | 264.45 |
| Total | 30,168,814,972 | 27,331,126,731 | -2,837,688,241 | 0.90594 | 174,960.65 | 158,503.80 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 1,595,594,543 | 381,704,698 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 1,737,643,348 | 1,494,312,565 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,680,610,421 | 1,489,295,356 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen7/source-review.json](../tests/evidence/diagnostics/gen7/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


BDS44, BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.

## Native allocation counts and output checks by DF

`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.

| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |
|---|---:|---:|---:|---|
| 0 | 21,393 | 1,754,081 | 81.99 | Yes |
| 4 | 8,841 | 660,520 | 74.71 | Yes |
| 5 | 2,949 | 218,227 | 74.00 | Yes |
| 11 | 38,456 | 2,653,465 | 69.00 | Yes |
| 16 | 2,694 | 449,899 | 167.00 | Yes |
| 17 | 31,395 | 9,846,555 | 313.63 | Yes |
| 18 | 18,990 | 3,330,446 | 175.38 | Yes |
| 20 | 29,460 | 13,390,819 | 454.54 | Yes |
| 21 | 18,254 | 8,897,033 | 487.40 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 41,200,880 small allocations. The sum of separate DF loops is 41,201,045, a difference of 165. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 5,006,887,934 |
| `frameSyndrome` | 172,432 | 4,559,221,019 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,800,209 |
| `reportWithSyndrome` | 172,432 | 17,731,596,634 |
| `Parity_checksum` | 172,432 | 3,079,137,820 |
| `Parity_syndrome` | 172,432 | 2,918,946,698 |
| `Parity_step` | 15,300,600 | 644,128,899 |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 2,091,903,685 |
| `Semantics_adsb` | 51,212 | 2,908,712,255 |
| `Semantics_commB` | 46,440 | 6,291,199,512 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,232,723,933 |
| `ScoreGate_commonDenominator` | 45,510 | 43,371,542 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,485,026 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid60` | 64,315 | 265,282,480 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` | 172,432 | 1,233,893,227 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 640,390,656 |

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
| `Parity_step` | 15,300,600 | 644,128,899 | 6.67% |
| `l_BitVec_ofNat` | 958,534 | 1,274,089,788 | 13.19% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 2,721,772 | 2,765,493,432 | 28.64% |
| `lean_nat_big_shiftr` | 100,793 | 52,210,774 | 0.54% |
| `lean_uint64_of_big_nat` | 100,793 | 89,637,146 | 0.93% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Semantic / oracle value construction** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_payloadValue` | 1,520,847 | 130,322,846 | 8,181,358,354 |
| `lean_nat_gcd` | 4,628,415 | 231,420,750 | 6,867,124,943 |
| `lp_lean1090_Lean1090_Impl_Semantics_commB` | 46,440 | 5,170,793 | 6,291,199,512 |
| `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_tableValues_spec__0` | 96,825 | 57,316,780 | 5,447,224,468 |
| `l_Rat_mul` | 1,544,248 | 312,625,892 | 4,948,886,322 |
| `lean::mpz::mpz(unsigned long)` | 10,109,332 | 252,733,300 | 4,639,268,049 |
| `lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_Semantics_commB_spec__0` | 45,613 | 36,195,317 | 3,214,282,039 |
| `lp_lean1090_Lean1090_Impl_commBValue` | 525,932 | 109,896,032 | 3,151,319,079 |
| `lp_lean1090_Lean1090_Impl_Semantics_adsb` | 51,212 | 4,166,624 | 2,908,712,255 |
| `lean::mpz::~mpz()` | 25,926,156 | 103,704,624 | 2,748,172,536 |
| `l_Rat_add` | 1,531,569 | 228,148,069 | 2,667,688,817 |
| `__gmpz_clear` | 25,926,156 | 181,483,092 | 2,644,467,912 |
| `__gmp_default_free` | 25,926,156 | 51,852,312 | 2,462,984,820 |
| `free` | 25,926,156 | 1,011,120,084 | 2,411,132,508 |
| `__gmpz_add` | 10,109,332 | 733,857,740 | 1,581,340,725 |

The source and generated C retained under `tests/evidence/diagnostics/gen7` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-7 benchmark binary retained 371 samples; 204 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: Comm-B semantic projection: 49; frame extraction: 36; Comm-B inference and raw payload: 35; shared frame syndrome: 29; report other/self/unresolved substage: 27; ADS-B semantic projection: 18; identity: 4; ADS-B raw payload: 3; report parity/address: 2; decode self/other: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Semantic / oracle value construction** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `7c3b44d246149a1c5aa671d119b6ba2be27d856b`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen7/analysis/analysis.json](../tests/evidence/diagnostics/gen7/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen7/native/all.jsonl](../tests/evidence/diagnostics/gen7/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen7/native-df/summary.json](../tests/evidence/diagnostics/gen7/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen7/perf/analysis.json](../tests/evidence/diagnostics/gen7/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen7/driver/driver-build.json](../tests/evidence/diagnostics/gen7/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen7/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen7/analysis/analysis.json` | `96549bc333385eb83e8d9276aa056174878ec99b2699af776c87369fae7f3d41` |
| `tests/evidence/diagnostics/gen7/native/all.jsonl` | `82f15ef163fc98503dab67d86c2d4af96cc79fe1083fd4387fc39a7b40233c45` |
| `tests/evidence/diagnostics/gen7/native-df/summary.json` | `76267a3d2be5f0d42d35d0fe93e801fc2f5a52f7e3a30441806ee69d631b1fb8` |
| `tests/evidence/diagnostics/gen7/perf/analysis.json` | `3b1c8d0277b886ae229ca28a97864404355387290a2909549925709c736bb744` |
| `tests/evidence/diagnostics/gen7/driver/driver-build.json` | `72eaf1402824308d97803ff79e74fcadc02e9e73f85a0bc562bf6182320af77e` |
| `tests/evidence/diagnostics/gen6/analysis/analysis.json` | `5a331ab602ec3c7f15d64e2abd38db14f4861ce61e6cfd7e932943353e180593` |
| `tests/evidence/diagnostics/gen7/campaign.json` | `4970a461c256d92fae918a028b7b4386e91dd958303b7ad18fce1e8c01716bbe` |
| `bench/runs/gen7/summary.json` | `df792bb586f408291e22821911ce2e40c0aeef770ac1ea73be34533cd0d802e5` |
| `tests/evidence/diagnostics/gen7/context-notes.md` | `c2cc2ae5cc95beb62b7ec0b679ba9f3470079447a73131a70c45e99d9e92a70d` |
| `tests/evidence/diagnostics/gen7/source-review.json` | `bb110326c667c48bfe3c46d4edd8e3c005b37672f2706783252310b9ff8b647d` |

## Reviewed run-specific observations

Generation 7 evaluates the unchanged score enclosure with exact integer cross multiplication. The live common denominator uses the maximum when every denominator divides it, otherwise the exact product. Signed and absolute scaled numerators are accumulated in one pair fold. The universal equality covers arbitrary rational lists and penalties, including empty lists and non-dyadic denominators. Retained timed-worker source/C/object/trace and assembly evidence is in [source-review.json](../tests/evidence/diagnostics/gen7/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen7/source-inspection/).

The actual live choose path does not construct normalized rational sums, center or envelope. Those pure mathematical APIs remain in source and in the post-collection shadow census. scaledNumerator and the scaledTotals wrapper are inlined; the commonDenominator and integer pair-fold boundaries are observed directly. Missing reference or inline symbols do not mean zero logical enclosure work. Native choose/common-denominator/pair-fold entries are reconciled for every family and register probe; full-software fallback entries are checked separately.

The full-software-score callback remains lazy and unchanged. The exact interval census executes only after the retained decoder results have been fully consumed and collection has stopped. It checks the rational reference decision against the live choose result and predicts populations; these shadow predictions are distinguished from actual native entry counts. Candidate and score probes overlap each other and the full decoder.

Generation 6 sharing remains live: one syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs; the old repeated-call prediction stays historical. Rejected-input costs are not claimed from this corpus population. Native acceptance can be inlined into residual control, while address and parity helpers retain operational frame/CRC attribution.

All immutable density and Mach tables are initialized before main. Their construction is outside collected decoder roots and warmed benchmark loops. The Mach accessor remains inlined into its callers. Integer-gate scalar lazy constants and zero-pair initialization can occur on early collected calls, and each process has its own allocator state; no unmeasured correction is applied.

The native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews and archived benchmark documentation; no host-wide isolation is claimed. Of 371 samples, 204 have a visible decoder ancestor and 167 are excluded; 366 stacks contain an unknown frame and 23 included leaves are unknown. These conditional observations cannot allocate whole-decoder time reliably. The exact capture conditions and reported zero-lost counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen7/perf/README.md). These are diagnostics, not benchmark timings.

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within one inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.


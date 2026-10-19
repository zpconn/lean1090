# Generation 12: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `0592f80708c92e283a4c802f04b5889d5d69a3aa` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 5,493,654,948 of 13,089,567,899 collected guest instructions (41.97%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-12 benchmark is decode **1.37585×** and CPR **0.89449×**; see [bench/runs/gen12/summary.json](../bench/runs/gen12/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 2,281,605,465 | 45,283.4 | 17.43% |
| commb | 47,714 | 9,662,072,468 | 202,499.7 | 73.82% |
| other | 74,333 | 1,145,889,966 | 15,415.6 | 8.75% |
| Total | 172,432 | 13,089,567,899 | 75,911.5 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 5,491,160,588 | 1,486,660 | 5,493,654,948 | 41.97% |
| Frame / CRC | 1,435,895,708 | 1,542,701,716 | 983,192,193 | 3,961,789,617 | 30.27% |
| Semantic / oracle value construction | 622,482,862 | 2,609,255,084 | 145,561,317 | 3,377,299,263 | 25.80% |
| ADS-B fields / checks | 209,390,099 | 477,140 | 743,330 | 210,610,569 | 1.61% |
| Output-model construction / residual control | 12,829,096 | 18,477,940 | 14,906,466 | 46,213,502 | 0.35% |

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

## Comparison with generation 11

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen11 Ir | Gen12 Ir | Difference (gen12 − gen11) | Gen12/gen11 | Gen11 Ir/message | Gen12 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 5,493,885,201 | 5,493,654,948 | -230,253 | 0.99996 | 31,861.17 | 31,859.83 |
| Frame / CRC | 5,609,294,040 | 3,961,789,617 | -1,647,504,423 | 0.70629 | 32,530.47 | 22,975.95 |
| Semantic / oracle value construction | 3,377,247,913 | 3,377,299,263 | +51,350 | 1.00002 | 19,585.97 | 19,586.27 |
| ADS-B fields / checks | 210,765,676 | 210,610,569 | -155,107 | 0.99926 | 1,222.31 | 1,221.41 |
| Output-model construction / residual control | 46,207,052 | 46,213,502 | +6,450 | 1.00014 | 267.97 | 268.01 |
| Total | 14,737,399,882 | 13,089,567,899 | -1,647,831,983 | 0.88819 | 85,467.89 | 75,911.48 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 553,010,678 | 381,703,169 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 1,670,816,929 | 1,427,606,176 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,565,513,808 | 1,374,241,413 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen12/source-review.json](../tests/evidence/diagnostics/gen12/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| 20 | 29,460 | 8,174,792 | 277.49 | Yes |
| 21 | 18,254 | 5,102,958 | 279.55 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 20,644,898 small allocations. The sum of separate DF loops is 20,645,069, a difference of 171. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 1,107,411,270 |
| `frameSyndrome` | 172,432 | 2,764,161,042 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,239,552 |
| `reportWithSyndrome` | 172,432 | 9,184,208,240 |
| `Parity_checksum` | 172,432 | 1,279,412,998 |
| `Parity_syndrome` | 172,432 | 1,119,218,964 |
| `Parity_step` | Not observed in collected call contexts | Not assigned |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 1,910,485,395 |
| `Semantics_adsb` | 51,212 | 586,823,408 |
| `Semantics_commB` | 46,440 | 2,289,701,216 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,234,086,044 |
| `ScoreGate_commonDenominator` | 45,510 | 43,528,100 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bytesValue` | 172,432 | 454,183,525 |
| `bytesWord` | Not observed in collected call contexts | Not assigned |
| `bytesWordPrefix` | 100,793 | 41,393,648 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,500,064 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid40` | 62,679 | 246,020,478 |
| `cbValid60` | 64,315 | 265,333,287 |
| `field` | 881,619 | 564,509,141 |
| `packFields` | 172,432 | 1,281,162,891 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadValue` | 1,599,153 | 2,112,282,705 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 641,136,501 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | Not observed in collected call contexts | Not assigned |
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
| `l_BitVec_ofNat` | 249,344 | 261,922,848 | 6.61% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 1,130,963 | 1,137,759,667 | 28.72% |
| `lean_nat_big_shiftr` | 615,557 | 346,068,449 | 8.74% |
| `lean_uint64_of_big_nat` | 302,379 | 269,235,400 | 6.80% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 5,493,654,948 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 5,340,423,894 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 5,340,233,038 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 4,796,712,149 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 4,332,686,246 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 3,182,548,569 |
| `lp_lean1090_Lean1090_Impl_cbPenalty` | 45,510 | 5,313,376 | 1,910,485,395 |
| `lp_lean1090_Lean1090_Impl_bdsWireValid` | 627,880 | 19,643,081 | 1,733,999,455 |
| `lean::mpz::~mpz()` | 13,097,127 | 52,388,508 | 1,371,475,624 |
| `lean::mpz::mpz(unsigned long)` | 2,695,478 | 67,386,950 | 1,369,086,305 |
| `l_Rat_mul` | 323,785 | 65,126,656 | 1,338,264,357 |
| `__gmpz_clear` | 13,097,127 | 91,164,996 | 1,319,087,116 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` | 46,911 | 7,913,706 | 1,291,164,816 |
| `lp_lean1090_Lean1090_Impl_ScoreGate_choose` | 45,510 | 19,275,043 | 1,234,086,044 |
| `__gmp_default_free` | 12,925,496 | 25,850,992 | 1,227,922,120 |

The source and generated C retained under `tests/evidence/diagnostics/gen12` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-12 benchmark binary retained 271 samples; 74 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: shared frame syndrome: 17; Comm-B inference and raw payload: 16; report other/self/unresolved substage: 15; Comm-B semantic projection: 9; ADS-B semantic projection: 8; frame extraction: 6; altitude: 2; ADS-B raw payload: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `0592f80708c92e283a4c802f04b5889d5d69a3aa`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen12/analysis/analysis.json](../tests/evidence/diagnostics/gen12/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen12/native/all.jsonl](../tests/evidence/diagnostics/gen12/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen12/native-df/summary.json](../tests/evidence/diagnostics/gen12/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen12/perf/analysis.json](../tests/evidence/diagnostics/gen12/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen12/driver/driver-build.json](../tests/evidence/diagnostics/gen12/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen12/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen12/analysis/analysis.json` | `7415c994279673432184e4aa213d51aa5a085b81e396ef8a6530522df34cf9eb` |
| `tests/evidence/diagnostics/gen12/native/all.jsonl` | `4d879b561f0d6d64dc6426045e5e694ab2d8e6e4d7b7ce59f6a534fea2e7cb72` |
| `tests/evidence/diagnostics/gen12/native-df/summary.json` | `ff787095d69b5cbf4c353d960731cff67b82908b389b3d8e4cdcd3710e4c5e69` |
| `tests/evidence/diagnostics/gen12/perf/analysis.json` | `ad6472d9d3e241a1805fd4e84e4595ff9da70ff0bd6b9cc826069fd7aaa5f91f` |
| `tests/evidence/diagnostics/gen12/driver/driver-build.json` | `3a1d35e66ed46777fcdc1a4e66f73081ff72c8fef63f917cabae176e6e564797` |
| `tests/evidence/diagnostics/gen11/analysis/analysis.json` | `f30e99041a17b9aa0803189dbadf9196e8f652112f30d3b1823cc4c020de3994` |
| `tests/evidence/diagnostics/gen12/campaign.json` | `86e11ec12d8eeab983d1ccc3cf01467e787a817e9a3ffc2b937998ef6488abd1` |
| `bench/runs/gen12/summary.json` | `316fcc90d610febaf9f253bbc20446a363268d76e52e211941a38876f0e6ac5a` |
| `tests/evidence/diagnostics/gen12/context-notes.md` | `c9fb70e5e157a08fdabba58410aef30f895f26b704a5b090a5ab22ec2b412c6c` |
| `tests/evidence/diagnostics/gen12/source-review.json` | `62ec482b415fa017b32e4f6964834a597686042031469fa3d062fc6d0ab97937` |

## Reviewed run-specific observations

Generation 12 converts byte lists of length at most eight with a UInt64 fold. Lengths nine through sixteen use a tail-recursive eight-byte prefix reader, one suffix word fold and one final Nat shift/add; longer lists retain the original arbitrary-precision fold. The public equality is proved for every byte list. Actual word folds inline into bytesValue; the prefix helper remains a native boundary and creates its box/pair only at its endpoint, without a pair per byte. [Source/native review](../tests/evidence/diagnostics/gen12/source-review.json) retains the fresh timed-worker C and assembly. Missing standalone word-fold symbols do not mean zero byte processing.

The Frame and Message Lean sources are unchanged, but Lean changed list ownership conventions after bytesValue began consuming its input. The retained native review accounts for removed borrowing wrappers and moved reference-count decrements. Other production paths, including the UInt32 CRC loop, remain as verified in generation 11. The unchanged stage rule classifies actual call contexts; bookkeeping can move between callers, so small stage deltas must be read with these ownership changes in mind.

The diagnostic checkout and original timed generation-12 commit are both `0592f80708c92e283a4c802f04b5889d5d69a3aa`. The driver reuses all production objects from the exact 22-set fresh benchmark inventory, with unchanged source/C/object/trace and binary hashes. No historical attribution remapping is needed for this generation. The benchmark remains a separate measurement; these counters are not throughput samples.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach and QNH tables remain initialized before main. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 271 samples, 74 have a visible decoder ancestor and 197 are excluded; 264 stacks contain an unknown frame and 0 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen12/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen12/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 553,010,678 |
| candidate44 | 47,166 | 0 | 0 | 0 | 48,343,346 |
| candidate45 | 47,166 | 0 | 0 | 0 | 48,439,482 |
| candidate50 | 47,166 | 10,641 | 2,170,766 | 1,066,037,418 | 1,670,816,929 |
| candidate60 | 47,166 | 19,356 | 2,708,246 | 844,659,720 | 1,565,513,808 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,703,169 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 2,170,766 | 1,066,162,352 | 1,427,606,176 |
| score60 | 19,356 | 19,356 | 2,708,246 | 844,670,323 | 1,374,241,413 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen12/penalty-probe-costs.json).


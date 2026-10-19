# Generation 14: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `cd749c8192a77a79ba683303f0b743f04ff6bc0c` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 4,103,080,791 of 11,699,353,673 collected guest instructions (35.07%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-14 benchmark is decode **1.45918×** and CPR **0.93327×**; see [bench/runs/gen14/summary.json](../bench/runs/gen14/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 2,281,627,090 | 45,283.9 | 19.50% |
| commb | 47,714 | 8,271,836,531 | 173,362.9 | 70.70% |
| other | 74,333 | 1,145,890,052 | 15,415.6 | 9.79% |
| Total | 172,432 | 11,699,353,673 | 67,849.1 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 4,100,586,431 | 1,486,660 | 4,103,080,791 | 35.07% |
| Frame / CRC | 1,435,900,211 | 1,542,634,443 | 983,184,584 | 3,961,719,238 | 33.86% |
| Semantic / oracle value construction | 622,503,433 | 2,609,716,465 | 145,565,295 | 3,377,785,193 | 28.87% |
| ADS-B fields / checks | 209,392,809 | 477,140 | 743,330 | 210,613,279 | 1.80% |
| Output-model construction / residual control | 12,822,937 | 18,422,052 | 14,910,183 | 46,155,172 | 0.39% |

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

## Comparison with generation 13

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen13 Ir | Gen14 Ir | Difference (gen14 − gen13) | Gen14/gen13 | Gen13 Ir/message | Gen14 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 4,577,845,091 | 4,103,080,791 | -474,764,300 | 0.89629 | 26,548.70 | 23,795.36 |
| Frame / CRC | 3,961,771,188 | 3,961,719,238 | -51,950 | 0.99999 | 22,975.85 | 22,975.55 |
| Semantic / oracle value construction | 3,377,623,391 | 3,377,785,193 | +161,802 | 1.00005 | 19,588.15 | 19,589.09 |
| ADS-B fields / checks | 210,622,812 | 210,613,279 | -9,533 | 0.99995 | 1,221.48 | 1,221.43 |
| Output-model construction / residual control | 46,212,936 | 46,155,172 | -57,764 | 0.99875 | 268.01 | 267.67 |
| Total | 12,174,075,418 | 11,699,353,673 | -474,721,745 | 0.96101 | 70,602.18 | 67,849.09 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 553,010,678 | 381,702,319 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 754,738,820 | 511,406,971 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,090,748,966 | 899,586,108 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen14/source-review.json](../tests/evidence/diagnostics/gen14/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| 20 | 29,460 | 7,691,779 | 261.09 | Yes |
| 21 | 18,254 | 4,841,628 | 265.24 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 19,900,552 small allocations. The sum of separate DF loops is 19,900,726, a difference of 174. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 1,107,327,517 |
| `frameSyndrome` | 172,432 | 2,764,172,424 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,241,544 |
| `reportWithSyndrome` | 172,432 | 7,794,088,336 |
| `Parity_checksum` | 172,432 | 1,279,416,693 |
| `Parity_syndrome` | 172,432 | 1,119,218,964 |
| `Parity_step` | Not observed in collected call contexts | Not assigned |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 521,386,907 |
| `Semantics_adsb` | 51,212 | 586,843,524 |
| `Semantics_commB` | 46,440 | 2,290,160,914 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `l_Rat_div` | 53,494 | 243,751,602 |
| `Binary64_div` | Not observed in collected call contexts | Not assigned |
| `Binary64_round` | 662 | 19,907,708 |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,232,766,468 |
| `ScoreGate_commonDenominator` | 45,510 | 43,817,318 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bytesValue` | 172,432 | 454,132,950 |
| `bytesWord` | Not observed in collected call contexts | Not assigned |
| `bytesWordPrefix` | 100,793 | 41,367,624 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,477,632 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbRatioOutside250800` | 17,394 | 159,064,887 |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid40` | 62,679 | 246,006,159 |
| `cbValid60` | 64,315 | 265,301,727 |
| `cbWindPenalty50` | 10,641 | 3,048,948 |
| `cbWindPenaltyTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `field` | 881,619 | 564,514,662 |
| `packFields` | 172,432 | 1,281,217,890 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadValue` | 1,578,891 | 2,042,162,656 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 641,112,656 |
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
| `lean_nat_big_shiftr` | 615,557 | 346,073,970 | 8.74% |
| `lean_uint64_of_big_nat` | 302,379 | 269,235,400 | 6.80% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 4,103,080,791 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 3,949,851,728 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 3,949,660,872 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 3,406,273,073 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 2,942,258,105 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 1,792,107,856 |
| `lp_lean1090_Lean1090_Impl_bdsWireValid` | 627,880 | 19,643,081 | 1,733,967,910 |
| `lp_lean1090_Lean1090_Impl_ScoreGate_choose` | 45,510 | 19,248,889 | 1,232,766,468 |
| `lean::mpz::~mpz()` | 9,185,992 | 36,743,968 | 961,570,920 |
| `__gmpz_clear` | 9,185,992 | 63,899,335 | 924,826,952 |
| `__gmp_default_free` | 9,051,789 | 18,103,578 | 860,927,617 |
| `free` | 9,051,791 | 353,019,849 | 842,824,225 |
| `lean::mpz::mpz(unsigned long)` | 1,610,570 | 40,264,250 | 803,577,540 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,112,656 |
| `lean_nat_pow` | 643,970 | 28,334,680 | 636,580,701 |

The source and generated C retained under `tests/evidence/diagnostics/gen14` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-14 benchmark binary retained 251 samples; 87 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: Comm-B semantic projection: 19; shared frame syndrome: 18; Comm-B inference and raw payload: 16; report other/self/unresolved substage: 13; frame extraction: 10; ADS-B semantic projection: 4; identity: 3; ADS-B raw payload: 2; altitude: 1; report parity/address: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `cd749c8192a77a79ba683303f0b743f04ff6bc0c`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen14/analysis/analysis.json](../tests/evidence/diagnostics/gen14/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen14/native/all.jsonl](../tests/evidence/diagnostics/gen14/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen14/native-df/summary.json](../tests/evidence/diagnostics/gen14/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen14/perf/analysis.json](../tests/evidence/diagnostics/gen14/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen14/driver/driver-build.json](../tests/evidence/diagnostics/gen14/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen14/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen14/analysis/analysis.json` | `92a5309dad7b6e23ce1da7ee7783e12aae903fe4f825d829547da9076aa1b9f2` |
| `tests/evidence/diagnostics/gen14/native/all.jsonl` | `bab1ac8133d6fbc2d06e36e4102285377556a2c046d6dc257c224f9424d58dfa` |
| `tests/evidence/diagnostics/gen14/native-df/summary.json` | `467c8868e298052c7b5be68914d32e5ef315a1c6c26d864e1b3d10a02a2a8718` |
| `tests/evidence/diagnostics/gen14/perf/analysis.json` | `b0f67fcc94398830275df642a4ae6b1460978ec5cf1cb0529653f72298451170` |
| `tests/evidence/diagnostics/gen14/driver/driver-build.json` | `f96c54b8d874b625b0bee2e80e5637af7d5c900d01f3ec3006af2e4ca8175970` |
| `tests/evidence/diagnostics/gen13/analysis/analysis.json` | `5e3854ed3f9d87df92779e2f948a25dc1ab1971e62c35209ffdd892ad9dbf174` |
| `tests/evidence/diagnostics/gen14/campaign.json` | `b1952baec58ee770f8331756cbd0a7b9d301f0ef6d40772e6fe7064c93f2e28c` |
| `bench/runs/gen14/summary.json` | `8c1a25dbb0f658382e8ecdf60098f5384c33a1c50250bdeb0246ed59816b32e5` |
| `tests/evidence/diagnostics/gen14/context-notes.md` | `c768bdf9d7654b5abf4f7788ad2eacf3c6975536f90e31d9a33969e646694511` |
| `tests/evidence/diagnostics/gen14/source-review.json` | `5f21252f6e722ee04cd1ba8bb50493dfc48bf40cd7a091fb2d6df8995739203c` |

## Reviewed run-specific observations

Generation 14 replaces only the BDS60 rounded IAS/Mach threshold decision with a proved exact integer enclosure. The caller forms the exact rational IAS/Mach ratio after the unchanged availability and positive-Mach guards. The helper certifies definitely outside or inclusive-inside results with integer arithmetic; uncertain cases retain the original software-binary64 rounding and strict comparisons. The equality holds for every rational, including exact thresholds and values that round back onto them. [Source/native review](../tests/evidence/diagnostics/gen14/source-review.json) retains the fresh timed-worker C and actual conditional fallback assembly.

The helper uses arbitrary-precision Int operations as needed, not a fixed-width or allocation-free path. Exact normalized Rat division remains in cbPenalty before the helper, and the original software round remains at one conditional native call site. BDS50 wind/turn logic, field-code tables, semantic statuses and every other production path are unchanged from generation 13, as recorded by the source review. No measured instruction delta is treated as a timing explanation for the generation-14 benchmark regression.

The diagnostic checkout and original timed generation-14 commit are both `cd749c8192a77a79ba683303f0b743f04ff6bc0c`. The driver reuses all production objects from the exact 22-set fresh benchmark inventory, with unchanged source/C/object/trace and binary hashes. No historical attribution remapping is needed for this generation. The benchmark remains a separate measurement; these counters are not throughput samples.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach, QNH and wind-penalty tables initialize before main. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 251 samples, 87 have a visible decoder ancestor and 164 are excluded; 249 stacks contain an unknown frame and 5 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen14/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen14/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 553,010,678 |
| candidate44 | 47,166 | 0 | 0 | 0 | 48,343,346 |
| candidate45 | 47,166 | 0 | 0 | 0 | 48,439,482 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 151,247,122 | 754,738,820 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 369,716,953 | 1,090,748,966 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,702,319 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 151,233,609 | 511,406,971 |
| score60 | 19,356 | 19,356 | 2,429,938 | 369,869,842 | 899,586,108 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen14/penalty-probe-costs.json).

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

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen14/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,064,887 | 242,334 |
| other | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate60 | 17,394 | 17,386 | 8 | 4,593,636 | 158,990,130 | 242,415 |
| score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| score50 | 0 | 0 | 0 | 0 | 0 | 0 |
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,565,833 | 242,664 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen14/ratio-native-contexts.json) also records generation 13 and 14 cbPenalty direct edges, including old Binary64.div and new exact Rat.div plus enclosure. The old rounded divide already included exact division and rounding; do not add its descendants twice or infer wall-clock effects.


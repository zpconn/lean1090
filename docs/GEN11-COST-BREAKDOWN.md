# Generation 11: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `fd20b1c3553415b1b727f1dca347d4d43dd0d142` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Frame / CRC**, with 5,609,294,040 of 14,737,399,882 collected guest instructions (38.06%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-11 benchmark is decode **1.26834×** and CPR **0.84718×**; see [bench/runs/gen11/summary.json](../bench/runs/gen11/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 3,106,066,033 | 61,646.6 | 21.08% |
| commb | 47,714 | 10,442,549,331 | 218,857.1 | 70.86% |
| other | 74,333 | 1,188,784,518 | 15,992.7 | 8.07% |
| Total | 172,432 | 14,737,399,882 | 85,467.9 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Frame / CRC | 2,260,238,622 | 2,322,966,282 | 1,026,089,136 | 5,609,294,040 | 38.06% |
| Comm-B candidate inference / raw records | 1,007,700 | 5,491,390,841 | 1,486,660 | 5,493,885,201 | 37.28% |
| Semantic / oracle value construction | 622,474,766 | 2,609,213,554 | 145,559,593 | 3,377,247,913 | 22.92% |
| ADS-B fields / checks | 209,545,206 | 477,140 | 743,330 | 210,765,676 | 1.43% |
| Output-model construction / residual control | 12,799,739 | 18,501,514 | 14,905,799 | 46,207,052 | 0.31% |

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

## Comparison with generation 10

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen10 Ir | Gen11 Ir | Difference (gen11 − gen10) | Gen11/gen10 | Gen10 Ir/message | Gen11 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Frame / CRC | 7,401,732,346 | 5,609,294,040 | -1,792,438,306 | 0.75784 | 42,925.51 | 32,530.47 |
| Comm-B candidate inference / raw records | 5,486,609,584 | 5,493,885,201 | +7,275,617 | 1.00133 | 31,818.98 | 31,861.17 |
| Semantic / oracle value construction | 3,338,643,871 | 3,377,247,913 | +38,604,042 | 1.01156 | 19,362.09 | 19,585.97 |
| ADS-B fields / checks | 206,896,581 | 210,765,676 | +3,869,095 | 1.01870 | 1,199.87 | 1,222.31 |
| Output-model construction / residual control | 45,510,863 | 46,207,052 | +696,189 | 1.01530 | 263.94 | 267.97 |
| Total | 16,479,393,245 | 14,737,399,882 | -1,741,993,363 | 0.89429 | 95,570.39 | 85,467.89 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 553,003,267 | 381,710,898 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 1,670,810,668 | 1,427,485,785 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,565,506,886 | 1,374,116,617 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen11/source-review.json](../tests/evidence/diagnostics/gen11/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


BDS44, BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.

## Native allocation counts and output checks by DF

`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.

| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |
|---|---:|---:|---:|---|
| 0 | 21,393 | 556,073 | 25.99 | Yes |
| 4 | 8,841 | 165,424 | 18.71 | Yes |
| 5 | 2,949 | 53,083 | 18.00 | Yes |
| 11 | 38,456 | 499,929 | 13.00 | Yes |
| 16 | 2,694 | 126,619 | 47.00 | Yes |
| 17 | 31,395 | 5,431,017 | 172.99 | Yes |
| 18 | 18,990 | 1,012,885 | 53.34 | Yes |
| 20 | 29,460 | 8,439,932 | 286.49 | Yes |
| 21 | 18,254 | 5,267,244 | 288.55 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 21,552,035 small allocations. The sum of separate DF loops is 21,552,206, a difference of 171. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 2,754,122,331 |
| `frameSyndrome` | 172,432 | 2,764,402,341 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,790,934 |
| `reportWithSyndrome` | 172,432 | 9,185,112,690 |
| `Parity_checksum` | 172,432 | 1,279,464,838 |
| `Parity_syndrome` | 172,432 | 1,119,218,964 |
| `Parity_step` | Not observed in collected call contexts | Not assigned |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 1,910,558,027 |
| `Semantics_adsb` | 51,212 | 586,818,751 |
| `Semantics_commB` | 46,440 | 2,289,667,705 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,234,142,311 |
| `ScoreGate_commonDenominator` | 45,510 | 43,573,736 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bytesValue` | 172,432 | 2,100,152,579 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,536,629 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid40` | 62,679 | 246,024,561 |
| `cbValid60` | 64,315 | 265,344,531 |
| `field` | 881,619 | 564,531,641 |
| `packFields` | 172,432 | 1,281,198,161 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadValue` | 1,599,153 | 2,112,380,046 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 641,111,915 |
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
| `l_BitVec_ofNat` | 249,344 | 261,922,848 | 4.67% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 1,130,963 | 1,137,759,667 | 20.28% |
| `lean_nat_big_shiftr` | 615,557 | 346,090,949 | 6.17% |
| `lean_uint64_of_big_nat` | 302,379 | 269,235,400 | 4.80% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Frame / CRC** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameSyndrome` | 172,432 | 11,871,146 | 2,764,402,341 |
| `lp_lean1090_Lean1090_Impl_decodeFrame` | 172,432 | 23,239,337 | 2,754,122,331 |
| `lp_lean1090_Lean1090_Impl_bytesValue` | 172,432 | 517,296 | 2,100,152,579 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | 172,432 | 65,541,483 | 2,099,635,283 |
| `lean::mpz::~mpz()` | 13,896,959 | 55,587,836 | 1,473,018,658 |
| `lean::mpz::mpz(unsigned long)` | 3,046,030 | 76,150,750 | 1,448,906,701 |
| `__gmpz_clear` | 13,896,959 | 97,276,907 | 1,417,430,822 |
| `__gmp_default_free` | 13,896,357 | 27,792,714 | 1,320,153,915 |
| `free` | 13,896,357 | 541,957,923 | 1,292,361,201 |
| `lp_lean1090_Lean1090_Impl_packFields` | 172,432 | 517,296 | 1,281,198,161 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 52,319,321 | 1,280,680,865 |
| `lp_lean1090_Lean1090_Impl_Parity_checksum` | 172,432 | 5,849,357 | 1,279,464,838 |
| `lean_nat_pow` | 1,130,963 | 49,762,372 | 1,137,759,667 |
| `lp_lean1090_Lean1090_Impl_Parity_syndrome` | 172,432 | 6,438,292 | 1,119,218,964 |
| `lean_nat_big_add` | 806,344 | 37,091,824 | 1,100,098,697 |

The source and generated C retained under `tests/evidence/diagnostics/gen11` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-11 benchmark binary retained 276 samples; 110 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: frame extraction: 24; shared frame syndrome: 22; Comm-B inference and raw payload: 21; report other/self/unresolved substage: 18; Comm-B semantic projection: 15; ADS-B raw payload: 4; ADS-B semantic projection: 3; identity: 2; altitude: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Frame / CRC** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `fd20b1c3553415b1b727f1dca347d4d43dd0d142`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen11/analysis/analysis.json](../tests/evidence/diagnostics/gen11/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen11/native/all.jsonl](../tests/evidence/diagnostics/gen11/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen11/native-df/summary.json](../tests/evidence/diagnostics/gen11/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen11/perf/analysis.json](../tests/evidence/diagnostics/gen11/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen11/driver/driver-build.json](../tests/evidence/diagnostics/gen11/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen11/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen11/analysis/analysis.json` | `f30e99041a17b9aa0803189dbadf9196e8f652112f30d3b1823cc4c020de3994` |
| `tests/evidence/diagnostics/gen11/native/all.jsonl` | `dd926c38fc6926adfb6d0565e2f2c02f80ae7f2f03a1f169ba3c205b543acfa7` |
| `tests/evidence/diagnostics/gen11/native-df/summary.json` | `07f68b06d422bdee9246383b553e9113c99f5f47efd6628251316190ba593041` |
| `tests/evidence/diagnostics/gen11/perf/analysis.json` | `bba496e0416d138c37f6c910680d13fd8820b02728b223fd0e0aaeb74e81bb9f` |
| `tests/evidence/diagnostics/gen11/driver/driver-build.json` | `1004696eea4d98ea37549465013e20c8e0322d1f7d04d37dc03d5c3b3e54c18c` |
| `tests/evidence/diagnostics/gen10/analysis/analysis.json` | `45faf7f3b6bcb01a026dfe772f55704769f93c1cc7a4edb951f5cfa9497be8aa` |
| `tests/evidence/diagnostics/gen11/campaign.json` | `72eaac835874fb79e33b739edc35a3b64c37ce0d1ddf495081f03b7c22e2e722` |
| `bench/runs/gen11/summary.json` | `0e6c8835703f51322790f74d76f21ae18c3616b9a47cd0caa6c04ae32b51be3a` |
| `tests/evidence/diagnostics/gen11/context-notes.md` | `e778469abb6a3fc3c45670d56ee2376be3e9dc356334f8ede29c34c1284abc13` |
| `tests/evidence/diagnostics/gen11/source-review.json` | `13c122c2e9d625ae1cde3fe8716448adbc63749fe888d545099e21ea67a01963` |

## Reviewed run-specific observations

Generation 11 replaces the CRC range-list fold and per-step BitVec remainder projection with a specialized Nat.fold carrying a UInt32 remainder. The public step API uses the same word update. Its equality to the frozen recurrence is proved for arbitrary UInt32 states, natural widths and natural words. The actual timed-worker loop uses native shift/feedback/mask arithmetic and prepares both cached halves before entry. It retains the arbitrary-precision input-bit fallback for indices beyond 127 and projects the result only after the loop. [Source/native review](../tests/evidence/diagnostics/gen11/source-review.json) retains the actual C and assembly; no build-time or timing improvement is inferred from source alone.

The diagnostic checkout and original timed generation-11 commit are both `fd20b1c3553415b1b727f1dca347d4d43dd0d142`. The driver reuses all production objects from the exact 22-set fresh benchmark inventory, with unchanged source/C/object/trace and binary hashes. No historical attribution remapping is needed for this generation. The benchmark remains a separate measurement; these counters are not throughput samples.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The old list-fold and current natural-fold symbols are kept as separate comparison rows. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach and QNH tables remain initialized before main. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 276 samples, 110 have a visible decoder ancestor and 166 are excluded; 272 stacks contain an unknown frame and 8 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen11/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.


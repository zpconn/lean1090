# Generation 8: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `78286f12feb79f8d8e3cdf2411ebd274161d1c3d` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Frame / CRC**, with 9,656,551,322 of 20,817,634,394 collected guest instructions (46.39%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-8 benchmark is decode **0.92785×** and CPR **0.69768×**; see [bench/runs/gen8/summary.json](../bench/runs/gen8/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 4,371,931,522 | 86,770.5 | 21.00% |
| commb | 47,714 | 13,979,089,781 | 292,976.7 | 67.15% |
| other | 74,333 | 2,466,613,091 | 33,183.3 | 11.85% |
| Total | 172,432 | 20,817,634,394 | 120,729.5 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Frame / CRC | 3,543,742,530 | 3,808,863,371 | 2,303,945,421 | 9,656,551,322 | 46.39% |
| Comm-B candidate inference / raw records | 1,007,700 | 7,568,102,337 | 1,486,660 | 7,570,596,697 | 36.37% |
| Semantic / oracle value construction | 608,967,523 | 2,583,573,714 | 145,559,702 | 3,338,100,939 | 16.03% |
| ADS-B fields / checks | 205,687,462 | 477,140 | 743,330 | 206,907,932 | 0.99% |
| Output-model construction / residual control | 12,526,307 | 18,073,219 | 14,877,978 | 45,477,504 | 0.22% |

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

## Comparison with generation 7

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen7 Ir | Gen8 Ir | Difference (gen8 − gen7) | Gen8/gen7 | Gen7 Ir/message | Gen8 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Frame / CRC | 9,656,919,437 | 9,656,551,322 | -368,115 | 0.99996 | 56,004.22 | 56,002.08 |
| Comm-B candidate inference / raw records | 7,752,823,529 | 7,570,596,697 | -182,226,832 | 0.97650 | 44,961.63 | 43,904.82 |
| Semantic / oracle value construction | 9,668,833,265 | 3,338,100,939 | -6,330,732,326 | 0.34524 | 56,073.31 | 19,358.94 |
| ADS-B fields / checks | 206,951,323 | 206,907,932 | -43,391 | 0.99979 | 1,200.19 | 1,199.94 |
| Output-model construction / residual control | 45,599,177 | 45,477,504 | -121,673 | 0.99733 | 264.45 | 263.74 |
| Total | 27,331,126,731 | 20,817,634,394 | -6,513,492,337 | 0.76168 | 158,503.80 | 120,729.53 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 1,595,601,270 | 381,703,329 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 1,670,809,909 | 1,427,477,772 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,565,507,082 | 1,374,124,536 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen8/source-review.json](../tests/evidence/diagnostics/gen8/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| 17 | 31,395 | 9,010,047 | 286.99 | Yes |
| 18 | 18,990 | 3,177,745 | 167.34 | Yes |
| 20 | 29,460 | 12,320,684 | 418.22 | Yes |
| 21 | 18,254 | 8,131,070 | 445.44 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 38,375,567 small allocations. The sum of separate DF loops is 38,375,738, a difference of 171. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 5,006,786,899 |
| `frameSyndrome` | 172,432 | 4,558,959,822 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,796,323 |
| `reportWithSyndrome` | 172,432 | 11,218,538,198 |
| `Parity_checksum` | 172,432 | 3,078,922,982 |
| `Parity_syndrome` | 172,432 | 2,918,747,555 |
| `Parity_step` | 15,300,600 | 644,128,899 |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 1,909,568,023 |
| `Semantics_adsb` | 51,212 | 573,087,174 |
| `Semantics_commB` | 46,440 | 2,264,027,666 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,232,768,416 |
| `ScoreGate_commonDenominator` | 45,510 | 43,393,168 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,459,069 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid60` | 64,315 | 265,242,231 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadValue` | 1,599,153 | 2,100,554,261 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` | 172,432 | 1,233,893,227 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 640,429,079 |

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
| `lean_nat_pow` | 2,721,772 | 2,765,439,486 | 28.64% |
| `lean_nat_big_shiftr` | 100,793 | 52,210,774 | 0.54% |
| `lean_uint64_of_big_nat` | 100,793 | 89,637,146 | 0.93% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Frame / CRC** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_decodeFrame` | 172,432 | 23,239,337 | 5,006,786,899 |
| `lp_lean1090_Lean1090_Impl_frameSyndrome` | 172,432 | 11,871,146 | 4,558,959,822 |
| `lp_lean1090_Lean1090_Impl_Parity_checksum` | 172,432 | 5,849,357 | 3,078,922,982 |
| `lp_lean1090_Lean1090_Impl_Parity_syndrome` | 172,432 | 10,231,811 | 2,918,747,555 |
| `lp_lean1090_Lean1090_Impl_field` | 881,619 | 54,861,964 | 2,818,893,089 |
| `lean_nat_pow` | 2,721,772 | 121,010,680 | 2,765,439,486 |
| `lean::mpz::mpz(unsigned long)` | 5,040,011 | 126,000,275 | 2,383,229,013 |
| `lp_lean1090_Lean1090_Impl_bytesValue` | 172,432 | 517,296 | 2,098,641,405 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | 172,432 | 65,541,483 | 2,098,124,109 |
| `lean::mpz::~mpz()` | 19,587,322 | 78,349,288 | 2,076,201,840 |
| `__gmpz_clear` | 19,587,322 | 137,109,592 | 1,997,852,552 |
| `__gmp_default_free` | 19,586,768 | 39,173,536 | 1,860,742,960 |
| `free` | 19,586,768 | 763,883,952 | 1,821,569,424 |
| `lean_dec_ref_cold` | 2,573,109 | 733,622,617 | 1,410,207,363 |
| `lp_lean1090_Lean1090_Impl_packFields` | 172,432 | 517,296 | 1,280,643,080 |

The source and generated C retained under `tests/evidence/diagnostics/gen8` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-8 benchmark binary retained 323 samples; 160 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: Comm-B inference and raw payload: 40; shared frame syndrome: 31; frame extraction: 29; report other/self/unresolved substage: 23; Comm-B semantic projection: 18; ADS-B semantic projection: 7; altitude: 5; identity: 4; ADS-B raw payload: 1; decode self/other: 1; report parity/address: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Frame / CRC** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `78286f12feb79f8d8e3cdf2411ebd274161d1c3d`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen8/analysis/analysis.json](../tests/evidence/diagnostics/gen8/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen8/native/all.jsonl](../tests/evidence/diagnostics/gen8/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen8/native-df/summary.json](../tests/evidence/diagnostics/gen8/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen8/perf/analysis.json](../tests/evidence/diagnostics/gen8/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen8/driver/driver-build.json](../tests/evidence/diagnostics/gen8/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen8/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen8/analysis/analysis.json` | `488eab80db4a638ffd0cc0d7cc284d164a9cf5fa4ba25d78c21ddfd9c8a354dd` |
| `tests/evidence/diagnostics/gen8/native/all.jsonl` | `250c5ae83c89f36100519d629fbcd43bf57d150ee4e15c7ef6cc32d150167482` |
| `tests/evidence/diagnostics/gen8/native-df/summary.json` | `b64c1c1276c6def96e1d29ce8f97fb3e027efad9872deed9957462925ef84c45` |
| `tests/evidence/diagnostics/gen8/perf/analysis.json` | `f86b61488fcc9e095bcdbe6acf1e1ed4b28a918af2be4f1e7b640f27c837d819` |
| `tests/evidence/diagnostics/gen8/driver/driver-build.json` | `5a6ad7dd3a5c793247dc51392a22b3f5ad7f3910799c2176e8a9fdccbf16611e` |
| `tests/evidence/diagnostics/gen7/analysis/analysis.json` | `96549bc333385eb83e8d9276aa056174878ec99b2699af776c87369fae7f3d41` |
| `tests/evidence/diagnostics/gen8/campaign.json` | `86a69c7b14c57a8128f90eb5ca2d62a2d370a9a9f44654e38baf8e94a1f66b7a` |
| `bench/runs/gen8/summary.json` | `e026dcc879c78494880255951599ef202386aaecfa443ca027e7c3447dde1cef` |
| `tests/evidence/diagnostics/gen8/context-notes.md` | `a71f3f6bc17ae073ed8a8c4975e78514d62245c7c2eef93951e908ff3803bae4` |
| `tests/evidence/diagnostics/gen8/source-review.json` | `9acec6f1a470687036cbf76d891943b6cd3befbcb7a24388f6d9aca077f2d3d2` |

## Reviewed run-specific observations

Generation 8 skips rational multiplication by one and addition of zero in the live payloadValue present branch. Extraction and status checks are unchanged. The universally proved identity helper is inlined into payloadValue; its absent standalone native boundary does not mean zero affine computation. Retained timed-worker source/C/object/trace and assembly evidence is in [source-review.json](../tests/evidence/diagnostics/gen8/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen8/source-inspection/).

The actual linked payloadValue tests scale equality to one and offset equality to zero, with direct Rat.mul and Rat.add calls only on their nonidentity branches. A separate recount of the retained gen7/gen8 family profiles below reports the actual direct arithmetic edges and unchanged payloadValue entry populations. No branch counts are inferred from an absent inlined symbol.

Generation 7 exact integer score decisions remain live: commonDenominator and the integer pair-fold entry are reconciled with actual choose counts in every family and register probe. Rational center/envelope/mass remain pure reference APIs used by the post-collection shadow census, not the live choose fast path. The unchanged full-software-score callback remains lazy. Candidate and score probes overlap each other and the full decoder.

Generation 6 sharing remains live: one syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs; the old repeated-call prediction stays historical. Rejected-input costs are not claimed from this corpus population. Native acceptance can be inlined into residual control, while address and parity helpers retain operational frame/CRC attribution.

All immutable density and Mach tables are initialized before main. Their construction is outside collected decoder roots and warmed benchmark loops. The Mach accessor remains inlined into its callers. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied.

The native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews and archived benchmark documentation; no host-wide isolation is claimed. Of 323 samples, 160 have a visible decoder ancestor and 163 are excluded; 320 stacks contain an unknown frame and 19 included leaves are unknown. These conditional observations cannot allocate whole-decoder time reliably. The exact capture conditions and reported zero-lost counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen8/perf/README.md). These are diagnostics, not benchmark timings.

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within one inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

### Live affine-value observations

The same native `payloadValue` entry populations are observed in both generations. The direct `Rat.mul` and `Rat.add` edges below are actual collected calls; the inlined affine helper has no separate native boundary. Full caller contexts, self costs and edge records are retained in [affine-caller-contexts.json](../tests/evidence/diagnostics/gen8/affine-caller-contexts.json). Incoming and outgoing inclusive costs overlap and must not be added to one another or to stage totals.

| Generation / family / stage | payloadValue calls | payloadValue inclusive Ir | Direct mul calls | Direct mul inclusive Ir | Direct add calls | Direct add inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| Gen7 / adsb / semantic_oracle_values | 462,367 | 2,470,940,022 | 458,078 | 1,486,912,778 | 458,078 | 823,558,847 |
| Gen7 / commb / semantic_oracle_values | 1,058,480 | 5,710,418,332 | 1,048,288 | 3,340,150,441 | 1,048,288 | 1,802,422,565 |
| Gen7 / commb / commb_inference | 78,306 | 431,668,285 | 75,314 | 242,379,993 | 75,314 | 130,025,797 |
| Gen8 / adsb / semantic_oracle_values | 462,367 | 167,625,084 | 2,467 | 7,999,568 | 0 | 0 |
| Gen8 / commb / semantic_oracle_values | 1,058,480 | 1,683,457,990 | 322,168 | 1,037,767,756 | 31,026 | 53,468,882 |
| Gen8 / commb / commb_inference | 78,306 | 249,471,187 | 57,908 | 186,267,668 | 0 | 0 |

These counts do not separate every scale/offset assignment: missing-status fields also avoid arithmetic. The actual generated C and linked assembly independently establish the guarded identity branches. This is an instruction diagnostic, not a throughput prediction.


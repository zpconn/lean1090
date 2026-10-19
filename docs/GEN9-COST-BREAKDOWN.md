# Generation 9: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `0fb54f0661c4cd589816277b1a8996a9969bdc44` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 7,570,594,302 of 18,563,052,929 collected guest instructions (40.78%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-9 benchmark is decode **1.01369×** and CPR **0.75626×**; see [bench/runs/gen9/summary.json](../bench/runs/gen9/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 3,763,296,583 | 74,690.8 | 20.27% |
| commb | 47,714 | 13,144,304,743 | 275,481.1 | 70.81% |
| other | 74,333 | 1,655,451,603 | 22,270.7 | 8.92% |
| Total | 172,432 | 18,563,052,929 | 107,654.3 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 7,568,099,942 | 1,486,660 | 7,570,594,302 | 40.78% |
| Frame / CRC | 2,935,108,863 | 2,974,083,402 | 1,492,765,333 | 7,401,957,598 | 39.87% |
| Semantic / oracle value construction | 608,970,547 | 2,583,558,560 | 145,559,660 | 3,338,088,767 | 17.98% |
| ADS-B fields / checks | 205,671,450 | 477,140 | 743,330 | 206,891,920 | 1.11% |
| Output-model construction / residual control | 12,538,023 | 18,085,699 | 14,896,620 | 45,520,342 | 0.25% |

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

## Comparison with generation 8

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen8 Ir | Gen9 Ir | Difference (gen9 − gen8) | Gen9/gen8 | Gen8 Ir/message | Gen9 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 7,570,596,697 | 7,570,594,302 | -2,395 | 1.00000 | 43,904.82 | 43,904.81 |
| Frame / CRC | 9,656,551,322 | 7,401,957,598 | -2,254,593,724 | 0.76652 | 56,002.08 | 42,926.82 |
| Semantic / oracle value construction | 3,338,100,939 | 3,338,088,767 | -12,172 | 1.00000 | 19,358.94 | 19,358.87 |
| ADS-B fields / checks | 206,907,932 | 206,891,920 | -16,012 | 0.99992 | 1,199.94 | 1,199.85 |
| Output-model construction / residual control | 45,477,504 | 45,520,342 | +42,838 | 1.00094 | 263.74 | 263.99 |
| Total | 20,817,634,394 | 18,563,052,929 | -2,254,581,465 | 0.89170 | 120,729.53 | 107,654.34 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 1,595,592,175 | 381,703,404 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 1,670,802,111 | 1,427,475,457 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,565,506,671 | 1,374,116,314 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen9/source-review.json](../tests/evidence/diagnostics/gen9/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


BDS44, BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.

## Native allocation counts and output checks by DF

`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.

| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |
|---|---:|---:|---:|---|
| 0 | 21,393 | 1,754,081 | 81.99 | Yes |
| 4 | 8,841 | 660,520 | 74.71 | Yes |
| 5 | 2,949 | 218,227 | 74.00 | Yes |
| 11 | 38,456 | 2,653,465 | 69.00 | Yes |
| 16 | 2,694 | 428,347 | 159.00 | Yes |
| 17 | 31,395 | 8,947,257 | 284.99 | Yes |
| 18 | 18,990 | 3,139,765 | 165.34 | Yes |
| 20 | 29,460 | 12,202,844 | 414.22 | Yes |
| 21 | 18,254 | 8,058,054 | 441.44 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 38,062,389 small allocations. The sum of separate DF loops is 38,062,560, a difference of 171. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 2,752,355,228 |
| `frameSyndrome` | 172,432 | 4,558,797,568 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,796,443 |
| `reportWithSyndrome` | 172,432 | 11,218,546,539 |
| `Parity_checksum` | 172,432 | 3,078,835,237 |
| `Parity_syndrome` | 172,432 | 2,918,654,545 |
| `Parity_step` | 15,300,600 | 644,128,899 |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 1,909,568,607 |
| `Semantics_adsb` | 51,212 | 573,086,682 |
| `Semantics_commB` | 46,440 | 2,264,008,373 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,232,788,059 |
| `ScoreGate_commonDenominator` | 45,510 | 43,394,634 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bytesValue` | 172,432 | 2,098,662,371 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,452,217 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid60` | 64,315 | 265,240,254 |
| `field` | 881,619 | 564,418,778 |
| `packFields` | 172,432 | 1,280,611,244 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadValue` | 1,599,153 | 2,100,555,088 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` | 172,432 | 1,233,893,227 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 640,439,638 |

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
| `Parity_step` | 15,300,600 | 644,128,899 | 8.70% |
| `l_BitVec_ofNat` | 76,915 | 79,837,824 | 1.08% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 958,534 | 960,502,655 | 12.98% |
| `lean_nat_big_shiftr` | 615,557 | 345,978,086 | 4.67% |
| `lean_uint64_of_big_nat` | 302,379 | 269,235,400 | 3.64% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 7,570,594,302 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 7,417,363,258 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 7,417,172,402 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 5,836,212,984 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 5,372,154,905 |
| `lp_lean1090_Lean1090_Impl_bdsWireValid` | 627,880 | 19,643,081 | 3,817,548,098 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 3,180,285,681 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` | 108,963 | 18,214,338 | 3,011,030,521 |
| `l_Rat_mul` | 540,967 | 109,587,200 | 2,517,747,906 |
| `lp_lean1090_Lean1090_Impl_cbValid40` | 62,679 | 4,023,777 | 2,329,741,519 |
| `lean::mpz::mpz(unsigned long)` | 4,091,622 | 102,290,550 | 2,124,602,545 |
| `lp_lean1090_Lean1090_Impl_cbQNH64` | 31,026 | 930,780 | 2,078,532,469 |
| `lean::mpz::~mpz()` | 18,867,157 | 75,468,628 | 1,983,098,804 |
| `lp_lean1090_Lean1090_Impl_cbPenalty` | 45,510 | 5,305,298 | 1,909,568,607 |
| `__gmpz_clear` | 18,867,157 | 131,555,206 | 1,907,630,176 |

The source and generated C retained under `tests/evidence/diagnostics/gen9` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-9 benchmark binary retained 324 samples; 114 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: shared frame syndrome: 29; Comm-B inference and raw payload: 26; report other/self/unresolved substage: 19; frame extraction: 15; Comm-B semantic projection: 11; ADS-B semantic projection: 9; identity: 3; ADS-B raw payload: 2. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `0fb54f0661c4cd589816277b1a8996a9969bdc44`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen9/analysis/analysis.json](../tests/evidence/diagnostics/gen9/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen9/native/all.jsonl](../tests/evidence/diagnostics/gen9/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen9/native-df/summary.json](../tests/evidence/diagnostics/gen9/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen9/perf/analysis.json](../tests/evidence/diagnostics/gen9/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen9/driver/driver-build.json](../tests/evidence/diagnostics/gen9/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen9/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen9/analysis/analysis.json` | `63be1aa257ea0208f5951d771bc6f3bd37dac6b2c8e12c72992be73b7ddb5931` |
| `tests/evidence/diagnostics/gen9/native/all.jsonl` | `ba3e9b89000b0b84df2d891062a07a343d425b1a3b7051c89abeceab2e9bb92a` |
| `tests/evidence/diagnostics/gen9/native-df/summary.json` | `5c4be97d3515f47c6b03bb5f9e63e37578024d4ea30261a55beeb42e99780fe3` |
| `tests/evidence/diagnostics/gen9/perf/analysis.json` | `be1f23a131162225e1898759dcd81b969a2625f9e145a81b8a5ab0879b9b668b` |
| `tests/evidence/diagnostics/gen9/driver/driver-build.json` | `43fbe113e194ad61a2348156a8334067f210b353d864433b6d48bca6452675ad` |
| `tests/evidence/diagnostics/gen8/analysis/analysis.json` | `488eab80db4a638ffd0cc0d7cc284d164a9cf5fa4ba25d78c21ddfd9c8a354dd` |
| `tests/evidence/diagnostics/gen9/campaign.json` | `c10fe089c54f4f3d496175fce1ada977eee952661902e7f87e2f11fee1c5ac62` |
| `bench/runs/gen9/summary.json` | `f1e1ea92a32a8eb62ab011e722a82d4981a51ccf3bf7dead8f7f17cb9332e9b0` |
| `tests/evidence/diagnostics/gen9/context-notes.md` | `7d9328fb70f03c1d6b617dc862b757a0d711b2e09607abb319b133ea0f9ef120` |
| `tests/evidence/diagnostics/gen9/source-review.json` | `da26615b77a4430da93bf50b3b00ef89b367cfeeb34685fe16739a4e8bcd2b7c` |

## Reviewed run-specific observations

Generation 9 changes the live frame field extractor for widths below 64. It performs the exact natural-number shift before conversion to UInt64, then applies the native low mask and returns its proved-bounded value. The original natural power/division/BitVec reduction remains for wider fields. The universal equality covers arbitrary total, start, width and word values, including large shifts and truncating subtraction. Retained timed-worker source/C/object/trace and assembly evidence is in [source-review.json](../tests/evidence/diagnostics/gen9/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen9/source-inspection/).

The actual linked decodeFrame retains 26 static calls to the same live field function; these are call sites, not per-message counts. The timed-worker narrow branch shifts before conversion and masking, while the wide branch retains the original power/division path. The existing mask helper is inlined. A separate recount of gen8/gen9 profiles below preserves actual field caller contexts and direct outgoing helper counts. Missing native edges do not mean zero inlined work or remove arbitrary-input fallback behavior.

The live syndrome fold, checksum, byte fold, field extractor and field-packing helper are retained as explicit nested anchors. Their incoming inclusive costs overlap each other and the exclusive stage totals; they are not additive subdivisions. Complete helper self costs remain the exact partition. Generation 8 affine guards and generation 7 exact integer score decisions remain live and unchanged. Rational center/envelope/mass are pure reference APIs used only by the post-collection census. The unchanged software-score callback remains lazy.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs; the old repeated-call prediction stays historical. Rejected-input costs are not claimed from this accepted corpus. Native acceptance can be inlined into residual control, while address and parity helpers retain operational frame/CRC attribution. Integer choose/common-denominator/pair-fold and fallback native counts remain reconciled with the separately checked register populations.

All immutable density and Mach tables are initialized before main. Their construction is outside collected decoder roots and warmed benchmark loops. The Mach accessor remains inlined into its callers. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied.

The native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews and archived benchmark documentation; no host-wide isolation is claimed. Of 324 samples, 114 have a visible decoder ancestor and 210 are excluded; 317 stacks contain an unknown frame and 0 included leaves are unknown. Most recorded samples lack a usable decoder ancestor, so these conditional observations cannot allocate whole-decoder time reliably. The exact capture conditions and reported zero-lost counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen9/perf/README.md). These are diagnostics, not benchmark timings.

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within one inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

### Live frame-field observations

The native `field` entry populations match between generations. The following totals retain actual caller contexts and direct outgoing helper edges; the machine mask and small-Nat operations can inline into `field`. All raw records and checks are in [field-caller-contexts.json](../tests/evidence/diagnostics/gen9/field-caller-contexts.json). Incoming and outgoing inclusive counts overlap and must not be added to stage totals.

| Generation / family / stage | field calls | field self Ir | field inclusive Ir |
|---|---:|---:|---:|
| Gen8 / adsb / frame_crc | 201,540 | 12,596,250 | 846,393,810 |
| Gen8 / commb / frame_crc | 286,284 | 17,845,036 | 1,115,688,769 |
| Gen8 / other / frame_crc | 393,795 | 24,420,678 | 856,810,510 |
| Gen9 / adsb / frame_crc | 201,540 | 12,999,330 | 237,771,724 |
| Gen9 / commb / frame_crc | 286,284 | 18,035,892 | 281,000,668 |
| Gen9 / other / frame_crc | 393,795 | 25,143,612 | 45,646,386 |

| Generation / family / stage | Direct callee | Calls | Inclusive Ir |
|---|---|---:|---:|
| Gen8 / adsb / frame_crc | `lean_nat_pow` | 201,540 | 211,739,310 |
| Gen8 / adsb / frame_crc | `l_BitVec_ofNat` | 201,540 | 354,307,488 |
| Gen8 / adsb / frame_crc | `lean_nat_big_div` | 201,540 | 232,884,342 |
| Gen8 / adsb / frame_crc | `lean_nat_big_shiftr` | 0 | 0 |
| Gen8 / adsb / frame_crc | `lean_uint64_of_big_nat` | 0 | 0 |
| Gen8 / commb / frame_crc | `lean_nat_pow` | 286,284 | 311,730,967 |
| Gen8 / commb / frame_crc | `l_BitVec_ofNat` | 286,284 | 434,671,968 |
| Gen8 / commb / frame_crc | `lean_nat_big_div` | 286,284 | 301,913,666 |
| Gen8 / commb / frame_crc | `lean_nat_big_shiftr` | 0 | 0 |
| Gen8 / commb / frame_crc | `lean_uint64_of_big_nat` | 0 | 0 |
| Gen8 / other / frame_crc | `lean_nat_pow` | 393,795 | 396,234,889 |
| Gen8 / other / frame_crc | `l_BitVec_ofNat` | 393,795 | 405,272,508 |
| Gen8 / other / frame_crc | `lean_nat_big_div` | 26,940 | 26,221,815 |
| Gen8 / other / frame_crc | `lean_nat_big_shiftr` | 0 | 0 |
| Gen8 / other / frame_crc | `lean_uint64_of_big_nat` | 0 | 0 |
| Gen9 / adsb / frame_crc | `lean_nat_pow` | 0 | 0 |
| Gen9 / adsb / frame_crc | `l_BitVec_ofNat` | 0 | 0 |
| Gen9 / adsb / frame_crc | `lean_nat_big_div` | 0 | 0 |
| Gen9 / adsb / frame_crc | `lean_nat_big_shiftr` | 201,540 | 117,553,132 |
| Gen9 / adsb / frame_crc | `lean_uint64_of_big_nat` | 100,770 | 89,786,052 |
| Gen9 / commb / frame_crc | `lean_nat_pow` | 0 | 0 |
| Gen9 / commb / frame_crc | `l_BitVec_ofNat` | 0 | 0 |
| Gen9 / commb / frame_crc | `lean_nat_big_div` | 0 | 0 |
| Gen9 / commb / frame_crc | `lean_nat_big_shiftr` | 286,284 | 161,444,235 |
| Gen9 / commb / frame_crc | `lean_uint64_of_big_nat` | 95,428 | 85,011,497 |
| Gen9 / other / frame_crc | `lean_nat_pow` | 0 | 0 |
| Gen9 / other / frame_crc | `l_BitVec_ofNat` | 0 | 0 |
| Gen9 / other / frame_crc | `lean_nat_big_div` | 0 | 0 |
| Gen9 / other / frame_crc | `lean_nat_big_shiftr` | 26,940 | 14,769,945 |
| Gen9 / other / frame_crc | `lean_uint64_of_big_nat` | 5,388 | 4,800,705 |

Only collected native edges are reported. The original wide-width formula remains in the live function, as independently verified in the fresh source/native review. An unobserved edge in this corpus does not eliminate arbitrary-width fallback semantics or imply zero inlined work. These are instruction observations, not a throughput prediction.


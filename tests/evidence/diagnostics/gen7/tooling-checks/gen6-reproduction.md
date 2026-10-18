# Generation 6: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `cd4df90b6821ed8d375cb26e0e5baed6f6e9fecf` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 10,590,559,330 of 30,168,814,972 collected guest instructions (35.10%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-6 benchmark is decode **0.67766×** and CPR **0.54783×**; see [bench/runs/gen6/summary.json](../bench/runs/gen6/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 6,675,602,067 | 132,491.9 | 22.13% |
| commb | 47,714 | 21,026,598,957 | 440,679.9 | 69.70% |
| other | 74,333 | 2,466,613,948 | 33,183.3 | 8.18% |
| Total | 172,432 | 30,168,814,972 | 174,960.7 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 10,588,064,970 | 1,486,660 | 10,590,559,330 | 35.10% |
| Semantic / oracle value construction | 2,912,507,424 | 6,610,528,632 | 145,561,832 | 9,668,597,888 | 32.05% |
| Frame / CRC | 3,543,797,985 | 3,809,489,819 | 2,303,943,720 | 9,657,231,524 | 32.01% |
| ADS-B fields / checks | 205,730,911 | 477,140 | 743,330 | 206,951,381 | 0.69% |
| Output-model construction / residual control | 12,558,047 | 18,038,396 | 14,878,406 | 45,474,849 | 0.15% |

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

## Comparison with generation 5

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen5 Ir | Gen6 Ir | Difference (gen6 − gen5) | Gen6/gen5 | Gen5 Ir/message | Gen6 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 10,591,058,005 | 10,590,559,330 | -498,675 | 0.99995 | 61,421.65 | 61,418.76 |
| Semantic / oracle value construction | 9,669,138,879 | 9,668,597,888 | -540,991 | 0.99994 | 56,075.08 | 56,071.95 |
| Frame / CRC | 13,038,590,650 | 9,657,231,524 | -3,381,359,126 | 0.74067 | 75,615.84 | 56,006.03 |
| ADS-B fields / checks | 207,150,184 | 206,951,381 | -198,803 | 0.99904 | 1,201.34 | 1,200.19 |
| Output-model construction / residual control | 43,312,345 | 45,474,849 | +2,162,504 | 1.04993 | 251.19 | 263.73 |
| Total | 33,549,250,063 | 30,168,814,972 | -3,380,435,091 | 0.89924 | 194,565.10 | 174,960.65 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 2,525,443,427 | 1,311,416,517 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 2,481,449,511 | 2,238,081,694 |
| BDS60 | 47,166 | 19,356 | 17,149 | 2,845,866,135 | 2,654,727,594 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen6/source-review.json](../tests/evidence/diagnostics/gen6/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| 20 | 29,460 | 14,246,596 | 483.59 | Yes |
| 21 | 18,254 | 9,449,393 | 517.66 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 42,609,012 small allocations. The sum of separate DF loops is 42,609,182, a difference of 170. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 5,006,943,723 |
| `frameSyndrome` | 172,432 | 4,559,483,190 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,796,333 |
| `reportWithSyndrome` | 172,432 | 20,569,021,481 |
| `Parity_checksum` | 172,432 | 3,079,452,760 |
| `Parity_syndrome` | 172,432 | 2,919,269,480 |
| `Parity_step` | 15,300,600 | 644,128,899 |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 2,091,899,562 |
| `Semantics_adsb` | 51,212 | 2,908,696,330 |
| `Semantics_commB` | 46,440 | 6,290,980,328 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | 45,510 | 1,489,110,630 |
| `ScoreGate_choose` | 45,510 | 4,070,403,745 |
| `ScoreGate_envelope` | 45,510 | 1,919,195,267 |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,448,329 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid60` | 64,315 | 265,235,736 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` | 172,432 | 1,233,893,227 |

Optional ScoreGate, table and fallback-related anchors are overlapping native-symbol observations, not another cost partition. An absent/inlined symbol does not establish zero logical computations, zero fallback decisions or zero initialization work. A fallback population requires a verified live call boundary or a separately checked census; instruction counts are not converted into decision counts.

Frame/CRC-stage contexts further separate fixed-width remainder work from extraction of bits from the complete word. This filter follows the combined frame/CRC stage, not a stricter parity-only ancestry test. The following inclusive costs overlap: a high-level parity helper can call the Nat/GMP helpers below it. They must not be added, subtracted as if disjoint, or extrapolated to predicted speedups. Uses attributed to other stages are excluded. A zero native-symbol count does not imply that all semantically related work disappeared.

| Helper in frame/CRC-stage contexts | Native entries | Inclusive Ir | Share of frame/CRC Ir (overlapping) |
|---|---:|---:|---:|
| `Parity_step` | 15,300,600 | 644,128,899 | 6.67% |
| `l_BitVec_ofNat` | 958,534 | 1,274,089,788 | 13.19% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 2,721,772 | 2,765,482,791 | 28.64% |
| `lean_nat_big_shiftr` | 100,793 | 52,210,774 | 0.54% |
| `lean_uint64_of_big_nat` | 100,793 | 89,637,146 | 0.93% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 10,590,559,330 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 10,437,329,855 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 10,437,138,999 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 8,856,093,464 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 8,392,082,784 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 6,200,230,162 |
| `lp_lean1090_Lean1090_Impl_ScoreGate_choose` | 45,510 | 3,874,409 | 4,070,403,745 |
| `lp_lean1090_Lean1090_Impl_bdsWireValid` | 627,880 | 19,643,081 | 3,817,676,424 |
| `lp_lean1090_List_foldr___at___00List_sum___at___00Lean1090_Impl_ScoreGate_mass_spec__1_spec__1` | 373,644 | 14,914,434 | 3,747,536,221 |
| `lean_nat_gcd` | 2,109,773 | 105,075,645 | 3,349,629,578 |
| `lean::mpz::mpz(unsigned long)` | 6,200,387 | 155,009,675 | 3,285,308,623 |
| `l_Rat_mul` | 649,393 | 130,842,740 | 3,192,083,691 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` | 108,963 | 18,214,338 | 3,011,301,499 |
| `l_Rat_add` | 528,529 | 98,807,970 | 2,969,710,069 |
| `lean::mpz::~mpz()` | 27,780,267 | 111,121,068 | 2,916,771,460 |

The source and generated C retained under `tests/evidence/diagnostics/gen6` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-6 benchmark binary retained 398 samples; 147 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: Comm-B semantic projection: 32; report other/self/unresolved substage: 32; Comm-B inference and raw payload: 26; shared frame syndrome: 25; frame extraction: 18; ADS-B semantic projection: 10; ADS-B raw payload: 2; altitude: 2. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `cd4df90b6821ed8d375cb26e0e5baed6f6e9fecf`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen6/analysis/analysis.json](../tests/evidence/diagnostics/gen6/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen6/native/all.jsonl](../tests/evidence/diagnostics/gen6/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen6/native-df/summary.json](../tests/evidence/diagnostics/gen6/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen6/perf/analysis.json](../tests/evidence/diagnostics/gen6/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen6/driver/driver-build.json](../tests/evidence/diagnostics/gen6/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen6/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen6/analysis/analysis.json` | `5a331ab602ec3c7f15d64e2abd38db14f4861ce61e6cfd7e932943353e180593` |
| `tests/evidence/diagnostics/gen6/native/all.jsonl` | `a182b47ca52bbfc2cb720083a2c70143befbce9d888df0e61daf29704a9cfc7f` |
| `tests/evidence/diagnostics/gen6/native-df/summary.json` | `d13906d0ea9b21089ae2952c562e92e54d18ee0a8323bf222739b16a99397e3d` |
| `tests/evidence/diagnostics/gen6/perf/analysis.json` | `255a100a8b112ce3259e892473f52aec83efbe9803c576172d236b3177f0e6b7` |
| `tests/evidence/diagnostics/gen6/driver/driver-build.json` | `7629f5385f8c0643b3bfc61228c7857d7810b66d7ef44f99977ca47afd846524` |
| `tests/evidence/diagnostics/gen5/analysis/analysis.json` | `2cedc492766612847e69ccdac567604e3f64de44733a7284bfa629e692c9411c` |
| `tests/evidence/diagnostics/gen6/campaign.json` | `05da857f8264bb597c853f409959c4c76ef06a0f68215889a7d1fa9b46f99640` |
| `bench/runs/gen6/summary.json` | `8ddc8edcd755e064e7907d4abee08a74a4728345d390ebe9b0617578e0e3da42` |
| `tests/evidence/diagnostics/gen6/context-notes.md` | `d23b713864af7dd008353c0766dbc70c9364cd78ffed4f0f57a18b60a58ecadf` |
| `tests/evidence/diagnostics/gen6/source-review.json` | `2da1819f0f27759fba182067a8668e246c33a19eb8fe5367274f3a0b911bf9e2` |

## Reviewed run-specific observations

Generation 6 computes one pure syndrome after successful frame parsing and passes it to the live acceptance/report/address helpers. The actual timed-worker source/C/object/trace binding and retained assembly are in [source-review.json](../tests/evidence/diagnostics/gen6/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen6/source-inspection/). This is local immutable sharing within one decode call, with no cross-message state.

The diagnostic performs an additional CRC census only after collection and complete output consumption. It checks every parsed frame and exact syndrome against the retained result. The old shadow census remains byte-identical to generation 0, including its explicitly historical repeated-call prediction. Native syndrome/checksum/fold/step entries must instead match the new census. All corpus rows are accepted; no rejected-input cost is measured by that population.

The native acceptance logic can be inlined into `decode`; such self work remains in residual control under the operational partition. `frameAddressWithSyndrome` retains frame/CRC attribution, and `reportWithSyndrome` retains the existing output/semantic boundaries. A missing old wrapper symbol is not an absent computation. Exact observed caller/helper rows and both generations are retained in [helper-comparison.json](../tests/evidence/diagnostics/gen6/helper-comparison.json).

Standalone public acceptance/address/report wrappers delegate to the same helpers and may compute their own syndrome. The profiled root is the complete live `Impl.decode`, whose shared path is independently inspected. The same syndrome supplies DF11 interrogator interpretation. The new eager order can compute a CRC for a frame rejected later by payload plausibility; malformed parsing still exits first. That general-input difference is not a corpus instruction-count claim.

The existing exact density/Mach tables and interval gate remain live. Table initialization precedes `main`, outside decoder-root collection and warmed benchmark loops. `cbMach64` remains inlined into its callers; missing standalone entry counts do not mean zero Mach work. Scalar lazy constants and allocator state can differ across these single-pass diagnostic processes, and no unmeasured correction is applied.

Native perf capture completed before the native census and Callgrind workers began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only review and benchmark archival; host-wide isolation is not claimed. Perf reports 398 samples, of which 147 have a visible decoder stack; these conditional observations and extensive unknown ancestry do not form a whole-decoder timing breakdown. Full capture and attribution limits are retained in [perf/README.md](../tests/evidence/diagnostics/gen6/perf/README.md).

Grouped helper inclusive values are raw incoming-edge observations. Recursive/re-entrant visits can overlap within a row, and descendants can cross a later stage boundary. They must not be added to stage totals or interpreted as predicted speedups. No production or frozen source changed during this diagnostic.


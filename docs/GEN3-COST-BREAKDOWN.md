# Generation 3: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `3ba567f1d5039eb16ab033dd436d3d4f0f33c98b` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 20,413,385,286 of 52,042,380,076 collected guest instructions (39.22%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-3 benchmark is decode **0.40710×** and CPR **0.35355×**; see [bench/runs/gen3/summary.json](../bench/runs/gen3/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 12,456,710,083 | 247,230.5 | 23.94% |
| commb | 47,714 | 36,381,723,547 | 762,495.8 | 69.91% |
| other | 74,333 | 3,203,946,446 | 43,102.6 | 6.16% |
| Total | 172,432 | 52,042,380,076 | 301,813.9 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 20,410,890,926 | 1,486,660 | 20,413,385,286 | 39.22% |
| Semantic / oracle value construction | 6,071,832,196 | 10,499,737,398 | 145,559,669 | 16,717,129,263 | 32.12% |
| Frame / CRC | 4,543,563,407 | 5,453,001,372 | 3,041,892,496 | 13,038,457,275 | 25.05% |
| ADS-B fields / checks | 1,828,870,090 | 477,140 | 743,330 | 1,830,090,560 | 3.52% |
| Output-model construction / residual control | 11,436,690 | 17,616,711 | 14,264,291 | 43,317,692 | 0.08% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Comparison with generation 2

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen2 Ir | Gen3 Ir | Difference (gen3 − gen2) | Gen3/gen2 | Gen2 Ir/message | Gen3 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 20,413,720,901 | 20,413,385,286 | -335,615 | 0.99998 | 118,387.08 | 118,385.13 |
| Semantic / oracle value construction | 16,716,461,772 | 16,717,129,263 | +667,491 | 1.00004 | 96,945.24 | 96,949.11 |
| Frame / CRC | 34,541,501,451 | 13,038,457,275 | -21,503,044,176 | 0.37747 | 200,319.55 | 75,615.07 |
| ADS-B fields / checks | 1,830,272,680 | 1,830,090,560 | -182,120 | 0.99990 | 10,614.46 | 10,613.40 |
| Output-model construction / residual control | 43,271,684 | 43,317,692 | +46,008 | 1.00106 | 250.95 | 251.22 |
| Total | 73,545,228,488 | 52,042,380,076 | -21,502,848,412 | 0.70762 | 426,517.29 | 301,813.93 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 3,154,857,598 | 1,497,049,545 |
| BDS44 | 47,166 | 0 | 0 | 154,393,343 | 0 |
| BDS45 | 47,166 | 0 | 0 | 146,497,929 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 3,384,169,347 | 2,606,868,735 |
| BDS60 | 47,166 | 19,356 | 17,149 | 6,315,485,540 | 4,276,998,672 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen3/source-review.json](../tests/evidence/diagnostics/gen3/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


BDS44, BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.

## Native allocation counts and output checks by DF

`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.

| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |
|---|---:|---:|---:|---|
| 0 | 21,393 | 3,315,770 | 154.99 | Yes |
| 4 | 8,841 | 1,244,026 | 140.71 | Yes |
| 5 | 2,949 | 412,861 | 140.00 | Yes |
| 11 | 38,456 | 2,653,465 | 69.00 | Yes |
| 16 | 2,694 | 810,895 | 301.00 | Yes |
| 17 | 31,395 | 13,708,140 | 436.63 | Yes |
| 18 | 18,990 | 3,330,446 | 175.38 | Yes |
| 20 | 29,460 | 19,418,272 | 659.14 | Yes |
| 21 | 18,254 | 12,224,129 | 669.67 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 57,117,834 small allocations. The sum of separate DF loops is 57,118,004, a difference of 170. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 5,006,884,067 |
| `frameSyndrome` | 287,418 | 7,934,022,035 |
| `Parity_checksum` | 287,418 | 5,289,239,412 |
| `Parity_syndrome` | 287,418 | 4,999,857,715 |
| `Parity_step` | 26,320,784 | 1,107,759,784 |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 3,675,083,432 |
| `Semantics_adsb` | 51,212 | 5,874,348,368 |
| `Semantics_commB` | 46,440 | 10,180,191,550 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | 45,510 | 1,489,179,168 |
| `ScoreGate_choose` | 45,510 | 4,070,284,783 |
| `ScoreGate_envelope` | 45,510 | 1,919,108,645 |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 627,025,607 |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` | 287,418 | 2,126,405,516 |

Optional ScoreGate, table and fallback-related anchors are overlapping native-symbol observations, not another cost partition. An absent/inlined symbol does not establish zero logical computations, zero fallback decisions or zero initialization work. A fallback population requires a verified live call boundary or a separately checked census; instruction counts are not converted into decision counts.

Frame/CRC-stage contexts further separate fixed-width remainder work from extraction of bits from the complete word. This filter follows the combined frame/CRC stage, not a stricter parity-only ancestry test. The following inclusive costs overlap: a high-level parity helper can call the Nat/GMP helpers below it. They must not be added, subtracted as if disjoint, or extrapolated to predicted speedups. Uses attributed to other stages are excluded. A zero native-symbol count does not imply that all semantically related work disappeared.

| Helper in frame/CRC-stage contexts | Native entries | Inclusive Ir | Share of frame/CRC Ir (overlapping) |
|---|---:|---:|---:|
| `Parity_step` | 26,320,784 | 1,107,759,784 | 8.50% |
| `l_BitVec_ofNat` | 958,535 | 1,274,090,844 | 9.77% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 3,412,064 | 3,453,448,670 | 26.49% |
| `lean_nat_big_shiftr` | 182,596 | 94,584,728 | 0.73% |
| `lean_uint64_of_big_nat` | 182,596 | 162,354,285 | 1.25% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 20,413,385,286 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 20,260,156,484 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 20,259,965,628 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 15,761,472,283 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 15,115,560,588 |
| `lp_lean1090_Lean1090_Impl_bdsWireValid` | 627,880 | 19,643,081 | 10,330,775,680 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 8,375,872,087 |
| `lean::mpz::mpz(unsigned long)` | 15,023,971 | 375,599,275 | 7,545,708,179 |
| `lean_nat_pow` | 7,306,916 | 321,504,304 | 7,205,877,826 |
| `lp_lean1090_Lean1090_Impl_payloadBits` | 3,121,720 | 250,904,926 | 6,396,909,632 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` | 216,787 | 35,369,698 | 6,003,976,894 |
| `lean::mpz::~mpz()` | 56,605,429 | 226,421,716 | 5,972,238,632 |
| `__gmpz_clear` | 56,605,429 | 395,223,247 | 5,745,816,916 |
| `l_Rat_mul` | 1,114,889 | 224,944,307 | 5,600,742,064 |
| `__gmp_default_free` | 56,267,177 | 112,534,354 | 5,350,593,669 |

The source and generated C retained under `tests/evidence/diagnostics/gen3` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-3 benchmark binary retained 573 samples; 393 had a visible live `Impl.decode` ancestor. Within those visible stacks, report parity/address had 57 samples and Comm-B inference/raw fields had 90. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `3ba567f1d5039eb16ab033dd436d3d4f0f33c98b`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen3/analysis/analysis.json](../tests/evidence/diagnostics/gen3/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen3/native/all.jsonl](../tests/evidence/diagnostics/gen3/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen3/native-df/summary.json](../tests/evidence/diagnostics/gen3/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen3/perf/analysis.json](../tests/evidence/diagnostics/gen3/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen3/driver/driver-build.json](../tests/evidence/diagnostics/gen3/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen3/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen3/analysis/analysis.json` | `319f3eecd21cb1912f5142cffd7cc0f0993289d3b64d86946946a3dfde5774a0` |
| `tests/evidence/diagnostics/gen3/native/all.jsonl` | `89c52cbe65b64b3a6832507d56c57d2f2fb54f11662281de195c604d4c2981bf` |
| `tests/evidence/diagnostics/gen3/native-df/summary.json` | `47fa940e722defa9664610dd7df38f8b6ff10dce914887430f0aec9cd9c76eb2` |
| `tests/evidence/diagnostics/gen3/perf/analysis.json` | `6cdf56e5acefa7a92e3ae3b1e6fe16ab60bd31e148c336f7d31961537b3633c4` |
| `tests/evidence/diagnostics/gen3/driver/driver-build.json` | `0fc21d83d9bbb7a84f215fc65d424ece1285083a0dae6aac4d4c2dee896d584b` |
| `tests/evidence/diagnostics/gen2/analysis/analysis.json` | `7149a59c8ae67362cd5ae444969bbed5b2e1fe0bc4a16330a5f6bb818c87baf0` |
| `tests/evidence/diagnostics/gen3/campaign.json` | `adf44544847513532ebd82bbc8e2105c16ba5082982d313babc8d7e575c56809` |
| `bench/runs/gen3/summary.json` | `44e70cb8ba03419f7842a35378d9a84eb774362478b58e68c4942b098642cc16` |
| `tests/evidence/diagnostics/gen3/context-notes.md` | `b22708d8be37306478eb37724d3d43eeaa39ee093b9275a128e06bc4e9b897cb` |
| `tests/evidence/diagnostics/gen3/source-review.json` | `143f2587feb01ad2104b2deaee6919813ff11e190e9817f6f6e318cda9d8e9cf` |

## Reviewed run-specific observations

Generation 3 changes only the parity word-bit extraction path. Corpus family populations, complete decoded-output digests and the original control-flow census are checked against generation 0; the instruction comparison uses generation 2. The collection roots remain live `Impl.decode`, `commBCoreEligible` and `cbScorePasses`.

The diagnostic driver replaces the single benchmark worker object and reuses 21 production/model objects. All 22 original linked source/C/object/trace sets match the freshly timed build inventory [bench/runs/gen3/fresh-native-inputs.json](../bench/runs/gen3/fresh-native-inputs.json), SHA-256 `7d7b00f3e9e2ac0e0588ba9b4db71693de578b7babfd157ba6a5c55badd0bd7e`; every linked Lean source also matches its committed blob. The [driver manifest](../tests/evidence/diagnostics/gen3/driver/driver-build.json) and independent [source review](../tests/evidence/diagnostics/gen3/source-review.json) retain the exact associations and unchanged-input checks. The benchmark binary was not replaced by the driver.

The retained [Parity C](../tests/evidence/diagnostics/gen3/generated-c/Impl/Parity.c) computes the low and high UInt64 halves once in `Parity.syndrome`, before the fold call. Both unboxed halves become fold parameters. The two bounded branches perform direct UInt64 shift/mask extraction; the compiler combines them into a machine `bt`/`setb` sequence in the live fold. The original `Nat.testBit` branch remains for indices at least 128. The independent source review identifies `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` as the retained native fold boundary. Its observed entry count, along with syndrome/checksum entries and per-bit step calls, is checked against the corpus CRC census. The helper wrappers `wordBit` and `cachedBit` inline into the fold and are absent from the final binary; that absence does not mean no extraction work occurred. Assembly and symbol evidence are retained under [source-inspection/](../tests/evidence/diagnostics/gen3/source-inspection/).

`lean_uint64_of_big_nat` and `lean_nat_big_shiftr` can now appear in one-time syndrome setup. The nested helper table filters the combined frame/CRC stage, so it is not a narrower parity-only ancestry measurement. A missing `Nat.testBit` entry in those collected contexts establishes no observed calls there only when paired with the retained live fallback boundary; it does not remove the unrestricted fallback from the implementation. UInt64 extraction instructions inline inside the fold and therefore have no separate function-entry count. Index arithmetic, list traversal, allocation and the parity step remain; their cost is not assumed away.

The exact interval gate and its lazy full-model fallback are unchanged. The retained boxed fallback boundary remains `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`; the report independently reconciles native entries with the checked post-decode interval population census. All 13 density arrays are eagerly initialized by the Comm-B module before `main`, outside decoder-root collection and the benchmark's warmed timed loops. Other lazy scalar constants and allocator state can differ between these diagnostic processes and warmed benchmarks. No unmeasured correction is applied.

Native perf capture completed before any native census or Callgrind worker began, with the completed capture loaded by the campaign before launch. The later family/probe profiles intentionally overlap, with at most six active profiles. They count instructions and provide no elapsed-time or throughput measurement. Other agents performed read-only review and benchmark-artifact archival; host-wide isolation is not claimed. The separate [perf analysis](../tests/evidence/diagnostics/gen3/perf/README.md) retains sampling exclusions and unwind limitations. Its visible-decoder sample counts are conditional observations, not a whole-decoder timing decomposition.

The new largest-stage helper table groups measured native base symbols only within uniquely attributed caller contexts. Inclusive edge observations can overlap between rows, within a recursively re-entered symbol, or across a later stage boundary; only self-event totals form a partition. The parser fixture includes a same-symbol recursive call to check that this overlap remains visible instead of being mistaken for additional exclusive cost. These observations guide source inspection, but the frozen ABAB benchmark remains the performance test.


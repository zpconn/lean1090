# Generation 2: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `f05d8b1bd697269efdb2d73b045fdf50a481f969` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Frame / CRC**, with 34,541,501,451 of 73,545,228,488 collected guest instructions (46.97%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-2 benchmark is decode **0.29456×** and CPR **0.27060×**; see [bench/runs/gen2/summary.json](../bench/runs/gen2/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 22,025,459,190 | 437,143.2 | 29.95% |
| commb | 47,714 | 47,546,252,015 | 996,484.3 | 64.65% |
| other | 74,333 | 3,973,517,283 | 53,455.6 | 5.40% |
| Total | 172,432 | 73,545,228,488 | 426,517.3 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Frame / CRC | 14,112,285,757 | 16,617,744,288 | 3,811,471,406 | 34,541,501,451 | 46.97% |
| Comm-B candidate inference / raw records | 1,007,700 | 20,411,226,541 | 1,486,660 | 20,413,720,901 | 27.76% |
| Semantic / oracle value construction | 6,071,674,767 | 10,499,226,199 | 145,560,806 | 16,716,461,772 | 22.73% |
| ADS-B fields / checks | 1,829,052,210 | 477,140 | 743,330 | 1,830,272,680 | 2.49% |
| Output-model construction / residual control | 11,438,756 | 17,577,847 | 14,255,081 | 43,271,684 | 0.06% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Comparison with generation 1

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen1 Ir | Gen2 Ir | Difference (gen2 − gen1) | Gen2/gen1 | Gen1 Ir/message | Gen2 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Frame / CRC | 34,540,771,739 | 34,541,501,451 | +729,712 | 1.00002 | 200,315.32 | 200,319.55 |
| Comm-B candidate inference / raw records | 49,856,076,161 | 20,413,720,901 | -29,442,355,260 | 0.40945 | 289,134.71 | 118,387.08 |
| Semantic / oracle value construction | 16,865,854,313 | 16,716,461,772 | -149,392,541 | 0.99114 | 97,811.63 | 96,945.24 |
| ADS-B fields / checks | 1,830,272,765 | 1,830,272,680 | -85 | 1.00000 | 10,614.46 | 10,614.46 |
| Output-model construction / residual control | 45,343,773 | 43,271,684 | -2,072,089 | 0.95430 | 262.97 | 250.95 |
| Total | 103,138,318,751 | 73,545,228,488 | -29,593,090,263 | 0.71307 | 598,139.09 | 426,517.29 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 3,154,863,445 | 1,497,049,545 |
| BDS44 | 47,166 | 0 | 0 | 154,393,343 | 0 |
| BDS45 | 47,166 | 0 | 0 | 146,497,929 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 3,384,175,321 | 2,606,871,703 |
| BDS60 | 47,166 | 19,356 | 17,149 | 6,315,491,514 | 4,276,991,621 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen2/source-review.json](../tests/evidence/diagnostics/gen2/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


BDS44, BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.

## Native allocation counts and output checks by DF

`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.

| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |
|---|---:|---:|---:|---|
| 0 | 21,393 | 3,315,770 | 154.99 | Yes |
| 4 | 8,841 | 1,244,026 | 140.71 | Yes |
| 5 | 2,949 | 412,861 | 140.00 | Yes |
| 11 | 38,456 | 2,653,465 | 69.00 | Yes |
| 16 | 2,694 | 1,074,907 | 399.00 | Yes |
| 17 | 31,395 | 16,784,850 | 534.63 | Yes |
| 18 | 18,990 | 4,260,956 | 224.38 | Yes |
| 20 | 29,460 | 22,305,352 | 757.14 | Yes |
| 21 | 18,254 | 14,013,021 | 767.67 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 66,065,038 small allocations. The sum of separate DF loops is 66,065,208, a difference of 170. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 5,007,070,615 |
| `frameSyndrome` | 287,418 | 29,436,892,424 |
| `Parity_checksum` | 287,418 | 26,791,537,907 |
| `Parity_step` | 26,320,784 | 1,107,759,784 |
| `cbDensity` | Not observed as a native symbol | Not assigned |
| `cbPenalty` | 45,510 | 3,675,011,356 |
| `Semantics_adsb` | 51,212 | 5,874,190,733 |
| `Semantics_commB` | 46,440 | 10,179,675,623 |
| `cbCombinedScore` | Not observed as a native symbol | Not assigned |
| `ScoreGate_center` | 45,510 | 1,489,194,183 |
| `ScoreGate_choose` | 45,510 | 4,070,362,675 |
| `ScoreGate_envelope` | 45,510 | 1,919,138,289 |
| `ScoreGate_mass` | Not observed as a native symbol | Not assigned |
| `cbDensityTableGet` | Not observed as a native symbol | Not assigned |
| `cbDensityTerms` | Not observed as a native symbol | Not assigned |
| `cbDensityTermsFast` | 45,510 | 627,037,691 |
| `cbScorePasses___lam__0___boxed` | Not observed as a native symbol | Not assigned |

Optional ScoreGate, table and fallback-related anchors are overlapping native-symbol observations, not another cost partition. An absent/inlined symbol does not establish zero logical computations, zero fallback decisions or zero initialization work. A fallback population requires a verified live call boundary or a separately checked census; instruction counts are not converted into decision counts.

CRC-only contexts further separate fixed-width remainder work from extraction of bits from the complete word. The following inclusive costs overlap: a high-level parity helper can call the Nat/GMP helpers below it. They must not be added, subtracted as if disjoint, or extrapolated to predicted speedups. Non-CRC uses of the same helpers are excluded by their observed caller context. A zero native-symbol count does not imply that all semantically related work disappeared.

| CRC-only helper | Native entries | Inclusive Ir | Share of frame/CRC Ir (overlapping) |
|---|---:|---:|---:|
| `Parity_step` | 26,320,784 | 1,107,759,784 | 3.21% |
| `l_BitVec_ofNat` | 958,535 | 1,274,090,844 | 3.69% |
| `l_Nat_testBit` | 26,320,784 | 21,957,771,021 | 63.57% |
| `lean_nat_pow` | 3,412,064 | 3,453,485,157 | 10.00% |
| `lean_nat_big_shiftr` | 20,450,752 | 11,893,506,312 | 34.43% |

The source and generated C retained under `tests/evidence/diagnostics/gen2` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-2 benchmark binary retained 719 samples; 530 had a visible live `Impl.decode` ancestor. Within those visible stacks, report parity/address had 184 samples and Comm-B inference/raw fields had 79. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Frame / CRC** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `f05d8b1bd697269efdb2d73b045fdf50a481f969`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen2/analysis/analysis.json](../tests/evidence/diagnostics/gen2/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen2/native/all.jsonl](../tests/evidence/diagnostics/gen2/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen2/native-df/summary.json](../tests/evidence/diagnostics/gen2/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen2/perf/analysis.json](../tests/evidence/diagnostics/gen2/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen2/driver/driver-build.json](../tests/evidence/diagnostics/gen2/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen2/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen2/analysis/analysis.json` | `7149a59c8ae67362cd5ae444969bbed5b2e1fe0bc4a16330a5f6bb818c87baf0` |
| `tests/evidence/diagnostics/gen2/native/all.jsonl` | `6c1260c12ab7e7c6647b57b14e0ffc12ad73e79f688b974d1af35b40d11ee87d` |
| `tests/evidence/diagnostics/gen2/native-df/summary.json` | `ee09aefaf409f1d973af0e7da61f0c0b3bbfce32f6af620aeeb028e81de9a8ae` |
| `tests/evidence/diagnostics/gen2/perf/analysis.json` | `49fc43eeb240a7c074fdfae831ee02f83ba3fc1d4d386b512de34a933f99dd97` |
| `tests/evidence/diagnostics/gen2/driver/driver-build.json` | `1eaf287c40df59b36dd6dac05529eac24534498f404a79e99bc5c3ead9228bcd` |
| `tests/evidence/diagnostics/gen1/analysis/analysis.json` | `8041410ed8937d3582a7185f8effa8a6ea771c90f64bc272b24b012cbbdf9c09` |
| `tests/evidence/diagnostics/gen2/campaign.json` | `9b0cfbd70cf471eb4e3e752feee9826e786476e6a018e35bb4fd672e20d4e2b9` |
| `bench/runs/gen2/summary.json` | `5ff08f5295a02e6dc51e4a4ac9339b31a20d75afc4103a4069266eac6a83063a` |
| `tests/evidence/diagnostics/gen2/context-notes.md` | `9f555dfc3df63e854e9f5ca3e835ad60adcfc9a26028a229f372863a527724fe` |
| `tests/evidence/diagnostics/gen2/source-review.json` | `df56bbe78a428e3d1cc0ca9bec6de5104f3cf4dcb46aa3eb677e00d1ea047509` |

## Reviewed run-specific observations

Generation 2 changes the Comm-B density and decision path. The disjoint family populations, complete decoded-output digests and original control-flow census are checked against generation 0; the instruction comparison uses generation 1. The exact live `Impl.decode`, `cbScorePasses` and `commBCoreEligible` roots are retained. The diagnostic driver adds only a post-collection interval-population census; it does not replace or instrument production decoder functions.

The driver reuses 21 production/model objects and replaces the single worker object. All 22 linked project source/C/object/trace sets match the fresh benchmark build inventory, whose SHA-256 is `915d92a8996d8eacaf7cce1f10faefbd3b7ef47cac7c7c52b4992d774553a666`. Every linked Lean source also matches its committed blob. These associations and before/after guards are retained in [driver/driver-build.json](../tests/evidence/diagnostics/gen2/driver/driver-build.json), [driver/fresh-native-inputs.json](../tests/evidence/diagnostics/gen2/driver/fresh-native-inputs.json) and the independent [source review](../tests/evidence/diagnostics/gen2/source-review.json).

In the retained [CommB C](../tests/evidence/diagnostics/gen2/generated-c/Impl/CommB.c), lines 6373–6380 construct the fallback closure, compute `cbDensityTermsFast` and `cbPenalty`, and call `ScoreGate.choose`. The retained [ScoreGate C](../tests/evidence/diagnostics/gen2/generated-c/Impl/ScoreGate.c) calls `lean_apply_1` at line 279 only in the uncertain interval. Native disassembly identifies the callable fallback boundary as `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`; the unboxed thunk and `cbCombinedScore` were inlined. The boxed thunk invokes the software density, penalty and addition path. Thus a missing standalone `cbCombinedScore` symbol does not mean the fallback implementation is absent. Exact assembly and its hashes are retained under [source-inspection/](../tests/evidence/diagnostics/gen2/source-inspection/).

`ScoreGate.choose`, `center`, `envelope` and `cbDensityTermsFast` retain native symbols. `mass` and the standalone `cbDensityTableGet` boundary were inlined. Inclusive observations for these functions overlap and remain separate from the exclusive cost partition. The report checks the native choose/fallback entry counts against the independently replayed, result-checked interval populations. Zero corpus fallback entries establish only zero use in this workload; they do not measure the fallback's cost on uncertain inputs.

All 13 immutable density arrays are eagerly constructed and marked persistent by `initialize_lean1090_Impl_CommB` at CommB C lines 6825–6850, before `main`. Their entry construction is outside both the collected decoder roots and the frozen benchmark's timed warm loops. The full-process perf capture includes startup, but decoder-visible sample counts exclude samples without an `Impl.decode` ancestor. Other lazy scalar constants and allocator state can still differ between these separate diagnostic processes and warmed benchmark runs. No unmeasured correction is applied.

The native perf capture completed before any native diagnostic or Callgrind job began; the campaign records loading that completed capture before launching workers. The Callgrind family/probe jobs subsequently overlapped, with at most six active profiles. They count instructions and do not supply elapsed-time or throughput measurements. Other agents performed read-only review and benchmark-artifact archival; host-wide isolation is not claimed.

The [perf capture and analysis](../tests/evidence/diagnostics/gen2/perf/README.md) retain 719 recorded and parsed samples, of which 530 have a visible live decoder ancestor and 189 are excluded from that subset. Both saved perf reports explicitly report `Total Lost Samples: 0`; missing/truncated stack ancestry remains a separate limitation. Unknown frames occur in 709 total samples and at 54 included leaves. Conditional sample counts and inclusive helper counts must not be converted into a whole-decoder timing decomposition. Source/object/binary hashes are unchanged across capture; the precise commands, exclusions and raw-data hash are retained.


# Generation 4: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `275329a2efd269dc44e549e4b6538d36277aaa3f` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 14,203,778,811 of 37,162,226,042 collected guest instructions (38.22%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-4 benchmark is decode **0.55490×** and CPR **0.46133×**; see [bench/runs/gen4/summary.json](../bench/runs/gen4/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 7,674,716,035 | 152,321.4 | 20.65% |
| commb | 47,714 | 26,283,583,017 | 550,856.8 | 70.73% |
| other | 74,333 | 3,203,926,990 | 43,102.4 | 8.62% |
| Total | 172,432 | 37,162,226,042 | 215,518.2 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 14,201,284,451 | 1,486,660 | 14,203,778,811 | 38.22% |
| Frame / CRC | 4,543,589,980 | 5,452,971,140 | 3,041,870,165 | 13,038,431,285 | 35.09% |
| Semantic / oracle value construction | 2,912,754,117 | 6,611,226,898 | 145,559,493 | 9,669,540,508 | 26.02% |
| ADS-B fields / checks | 205,929,640 | 477,140 | 743,330 | 207,150,110 | 0.56% |
| Output-model construction / residual control | 11,434,598 | 17,623,388 | 14,267,342 | 43,325,328 | 0.12% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Comparison with generation 3

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen3 Ir | Gen4 Ir | Difference (gen4 − gen3) | Gen4/gen3 | Gen3 Ir/message | Gen4 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 20,413,385,286 | 14,203,778,811 | -6,209,606,475 | 0.69581 | 118,385.13 | 82,373.22 |
| Frame / CRC | 13,038,457,275 | 13,038,431,285 | -25,990 | 1.00000 | 75,615.07 | 75,614.92 |
| Semantic / oracle value construction | 16,717,129,263 | 9,669,540,508 | -7,047,588,755 | 0.57842 | 96,949.11 | 56,077.41 |
| ADS-B fields / checks | 1,830,090,560 | 207,150,110 | -1,622,940,450 | 0.11319 | 10,613.40 | 1,201.34 |
| Output-model construction / residual control | 43,317,692 | 43,325,328 | +7,636 | 1.00018 | 251.22 | 251.26 |
| Total | 52,042,380,076 | 37,162,226,042 | -14,880,154,034 | 0.71408 | 301,813.93 | 215,518.15 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 2,525,443,251 | 1,311,414,341 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 2,481,574,513 | 2,238,206,823 |
| BDS60 | 47,166 | 19,356 | 17,149 | 5,341,849,846 | 3,875,735,215 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen4/source-review.json](../tests/evidence/diagnostics/gen4/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| `decodeFrame` | 172,432 | 5,006,891,849 |
| `frameSyndrome` | 287,418 | 7,933,988,025 |
| `Parity_checksum` | 287,418 | 5,289,203,646 |
| `Parity_syndrome` | 287,418 | 4,999,821,949 |
| `Parity_step` | 26,320,784 | 1,107,759,784 |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 3,312,119,289 |
| `Semantics_adsb` | 51,212 | 2,908,933,970 |
| `Semantics_commB` | 46,440 | 6,291,681,050 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | 45,510 | 1,489,179,168 |
| `ScoreGate_choose` | 45,510 | 4,070,284,841 |
| `ScoreGate_envelope` | 45,510 | 1,919,108,645 |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,431,543 |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `payloadBits` | 7,470,552 | 448,233,120 |
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
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 14,203,778,811 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 14,050,551,991 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 14,050,361,135 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 11,350,521,035 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 10,886,452,231 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 7,420,314,280 |
| `lp_lean1090_Lean1090_Impl_bdsWireValid` | 627,880 | 19,643,081 | 6,210,967,565 |
| `lp_lean1090_Lean1090_Impl_Binary64_round` | 216,787 | 35,369,698 | 6,003,977,068 |
| `l_Rat_mul` | 1,114,889 | 224,944,307 | 5,600,742,064 |
| `lean_nat_gcd` | 3,040,765 | 151,625,245 | 4,849,658,101 |
| `lean::mpz::mpz(unsigned long)` | 8,780,531 | 219,513,275 | 4,661,238,899 |
| `lp_lean1090_Lean1090_Impl_ScoreGate_choose` | 45,510 | 3,874,409 | 4,070,284,841 |
| `lean::mpz::~mpz()` | 37,875,109 | 151,500,436 | 3,986,824,712 |
| `l_Rat_div` | 691,635 | 5,533,080 | 3,969,721,850 |
| `__gmpz_clear` | 37,875,109 | 264,111,007 | 3,835,324,276 |

The source and generated C retained under `tests/evidence/diagnostics/gen4` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-4 benchmark binary retained 450 samples; 281 had a visible live `Impl.decode` ancestor. Within those visible stacks, report parity/address had 42 samples and Comm-B inference/raw fields had 56. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `275329a2efd269dc44e549e4b6538d36277aaa3f`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen4/analysis/analysis.json](../tests/evidence/diagnostics/gen4/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen4/native/all.jsonl](../tests/evidence/diagnostics/gen4/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen4/native-df/summary.json](../tests/evidence/diagnostics/gen4/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen4/perf/analysis.json](../tests/evidence/diagnostics/gen4/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen4/driver/driver-build.json](../tests/evidence/diagnostics/gen4/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen4/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen4/analysis/analysis.json` | `bcaa9b77781316b05c816823207ed143d309ee9233b73ed5c8d1c8edc5cbe565` |
| `tests/evidence/diagnostics/gen4/native/all.jsonl` | `89c52cbe65b64b3a6832507d56c57d2f2fb54f11662281de195c604d4c2981bf` |
| `tests/evidence/diagnostics/gen4/native-df/summary.json` | `855c4728371e5f1f7d411044b2966f318001f6b421d08dd30f0de22c5f004b1f` |
| `tests/evidence/diagnostics/gen4/perf/analysis.json` | `0728c442a09838c6304f65adb3790e2d8f89d883a59cb8d44a53e4bc4647aa8e` |
| `tests/evidence/diagnostics/gen4/driver/driver-build.json` | `3a034e25a1b32058857207344f058f4fe8ab520187f59758dd7febfdfea1cfa5` |
| `tests/evidence/diagnostics/gen3/analysis/analysis.json` | `319f3eecd21cb1912f5142cffd7cc0f0993289d3b64d86946946a3dfde5774a0` |
| `tests/evidence/diagnostics/gen4/campaign.json` | `c5daff57499647655d43556146eafd5b50e788245c0e2fecf32e12601b283899` |
| `bench/runs/gen4/summary.json` | `dc0e0830e927205e1095dd8e5cf365e559316e19b4062774ff2885df5df623fd` |
| `tests/evidence/diagnostics/gen4/context-notes.md` | `6ef711e728f64f8fa2c7c8b6671fb2dc672df98e7f21486c8f03e93722034f6b` |
| `tests/evidence/diagnostics/gen4/source-review.json` | `e11da2996d34eced6fefb79b24c53f26133884e0140ec2e1cf0b94a8ae57ed48` |

## Reviewed run-specific observations

Generation 4 changes payload extraction for widths below 64. The freshly bound generated C in `generated-c/Impl/PayloadBits.c` keeps UInt64 conversion, shifts and a mask in that branch; the original natural-power/division/remainder formula remains for arbitrary wider widths. The helper is inlined into the live `payloadBits` symbol. Its absence as a separate linked symbol is not zero extraction work. The source/native binding and assembly are retained in [source-review.json](../tests/evidence/diagnostics/gen4/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen4/source-inspection/).

The three Comm-B source changes are erased bound proofs. Its freshly built native object remains byte-identical to generation 3. No runtime stage boundary changed; instruction deltas below compare the same corpus populations and live entry points.

The following `payloadBits` observations group actual native symbols by their uniquely attributed stage. The inclusive costs overlap other helpers and do not form an additional cost partition or a predicted speedup. Complete observations are in [payload-helper-comparison.json](../tests/evidence/diagnostics/gen4/payload-helper-comparison.json).

| Caller stage | Gen3 entries | Gen4 entries | Gen3 self Ir | Gen4 self Ir | Gen3 inclusive Ir | Gen4 inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb_fields | 806,045 | 806,045 | 64,691,992 | 48,362,700 | 1,671,300,781 | 48,362,700 |
| commb_inference | 3,121,720 | 3,121,720 | 250,904,926 | 187,303,200 | 6,396,909,632 | 187,303,200 |
| semantic_oracle_values | 3,542,787 | 3,542,787 | 284,707,505 | 212,567,220 | 7,260,168,078 | 212,567,220 |

Across all three families, retained `payloadBits` contexts have **0** observed outgoing calls to `lean_nat_pow`; the exact positive-cost outgoing edges are retained in [payload-call-edges.json](../tests/evidence/diagnostics/gen4/payload-call-edges.json). These are native call observations, not guessed field-width counts. The arbitrary-width fallback remains in source and native code even when a workload does not reach it.

The CRC cached halves and original arbitrary-index fallback remain unchanged. The exact interval gate, callable boxed software fallback and 13 eagerly initialized immutable density arrays remain unchanged. Table construction occurs during module initialization before `main`, outside decoder-root collection and warmed benchmark loops. Other lazy scalar constants and separate allocator state may differ; no unmeasured correction is applied.

Native perf capture completed before the native census and Callgrind workers began. Family and probe profiles then intentionally overlapped, with at most six active profiles. Other agents performed read-only evidence review and benchmark archival. No host-wide isolation or timing decomposition is claimed. Sampling exclusions, unknown frames and the explicitly reported lost-sample counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen4/perf/README.md).

The largest-stage helper table retains raw inclusive incoming-edge observations. A recursive or re-entrant visit may overlap within one row, and descendants may cross a later stage boundary. Only self events form the exclusive partition; helper costs must not be added to it.


## Supplemental Mach and penalty observations

This section was requested after the main report was rendered, using only the existing raw profiles and analysis. The earlier report and validation are retained as `report-before-mach-addendum.md` and `validation-before-mach-addendum.json`. No decoder, compiler, profiler or benchmark ran for this extraction.

The live `cbMach64` decodes the ten-bit field at payload bit 25, then preserves the software-binary64 multiplication by the rounded literal 256/125 followed by division by 512. The source is retained at [production-source/Impl/CommB.lean](../tests/evidence/diagnostics/gen4/production-source/Impl/CommB.lean). A proposed immutable 1,024-entry exact table would be keyed only by that field code and must prove equality to this operation sequence for every word. This is an optimization candidate, not an implemented change or a throughput prediction.

| Unique caller stage | Observed cbMach64 entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| Frame / CRC | 0 | 0 | 0 |
| ADS-B fields | 0 | 0 | 0 |
| Comm-B inference | 53,912 | 2,306,952 | 3,606,158,963 |
| Semantic / oracle values | 0 | 0 | 0 |
| Output / control | 0 | 0 | 0 |

All 53,912 observed calls belong uniquely to Comm-B inference. Their 3,606,158,963 inclusive instructions are 25.39% of that stage and 9.70% of the aggregate, with overlapping descendants. Zero entries in another stage means this native boundary was not observed there; it does not rule out a different or inlined computation. These costs overlap the hard-validity and penalty paths below and must not be added to the stage totals.

| Observed whole-decoder caller path | cbMach64 entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| BDS60 score penalty | 17,406 | 748,410 | 1,218,474,582 |
| BDS60 candidate hard-validity check | 19,357 | 826,719 | 1,271,017,770 |
| BDS60 accepted-record validity recheck | 17,149 | 731,823 | 1,116,666,611 |

These three actual caller contexts reproduce the grouped Mach entry and instruction totals exactly. The candidate/score-only probes below are separate executions with distinct allocator and lazy-constant context, so their costs cannot be subtracted to reconstruct a whole-decoder substage.

| Register probe | Root inputs | cbMach64 entries | cbMach64 inclusive Ir | cbPenalty entries | cbPenalty inclusive Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 candidate | 47,166 | 0 | 0 | 15,513 | 434,364 |
| BDS44 candidate | 47,166 | 0 | 0 | 0 | 0 |
| BDS45 candidate | 47,166 | 0 | 0 | 0 | 0 |
| BDS50 candidate | 47,166 | 0 | 0 | 10,641 | 1,133,096,539 |
| BDS60 candidate | 47,166 | 36,763 | 2,491,081,693 | 19,356 | 2,181,242,769 |
| BDS40 score | 15,513 | 0 | 0 | 15,513 | 434,364 |
| BDS44 score | 0 | 0 | 0 | 0 | 0 |
| BDS45 score | 0 | 0 | 0 | 0 | 0 |
| BDS50 score | 10,641 | 0 | 0 | 10,641 | 1,133,194,861 |
| BDS60 score | 19,356 | 17,406 | 1,219,579,705 | 19,356 | 2,180,840,238 |

BDS44/45 have no reached score gates in this corpus, so no observed penalty/Mach calls. The complete extraction retains self costs, raw caller names and outgoing software-multiply/divide observations in [mach-penalty-observations.json](../tests/evidence/diagnostics/gen4/mach-penalty-observations.json); [extract_mach_costs.py](../tests/evidence/diagnostics/gen4/extract_mach_costs.py) reproduces them from the existing evidence.

Supplement input SHA-256: `da73cb7ae59a3f37ff38e7bbaf0fcf64eb39c0077084e8d2a4617966337c90e5`. The primary analysis and raw archive are unchanged.

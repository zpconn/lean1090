# Generation 5: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `eeb58261e6be0c2b87385f3064a88aed00d4d19a` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Frame / CRC**, with 13,038,590,650 of 33,549,250,063 collected guest instructions (38.86%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-5 benchmark is decode **0.61531×** and CPR **0.50316×**; see [bench/runs/gen5/summary.json](../bench/runs/gen5/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 7,674,710,723 | 152,321.3 | 22.88% |
| commb | 47,714 | 22,670,592,590 | 475,135.0 | 67.57% |
| other | 74,333 | 3,203,946,750 | 43,102.6 | 9.55% |
| Total | 172,432 | 33,549,250,063 | 194,565.1 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Frame / CRC | 4,543,605,435 | 5,453,081,440 | 3,041,903,775 | 13,038,590,650 | 38.86% |
| Comm-B candidate inference / raw records | 1,007,700 | 10,588,563,645 | 1,486,660 | 10,591,058,005 | 31.57% |
| Semantic / oracle value construction | 2,912,740,723 | 6,610,838,495 | 145,559,661 | 9,669,138,879 | 28.82% |
| ADS-B fields / checks | 205,929,714 | 477,140 | 743,330 | 207,150,184 | 0.62% |
| Output-model construction / residual control | 11,427,151 | 17,631,870 | 14,253,324 | 43,312,345 | 0.13% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Comparison with generation 4

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen4 Ir | Gen5 Ir | Difference (gen5 − gen4) | Gen5/gen4 | Gen4 Ir/message | Gen5 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Frame / CRC | 13,038,431,285 | 13,038,590,650 | +159,365 | 1.00001 | 75,614.92 | 75,615.84 |
| Comm-B candidate inference / raw records | 14,203,778,811 | 10,591,058,005 | -3,612,720,806 | 0.74565 | 82,373.22 | 61,421.65 |
| Semantic / oracle value construction | 9,669,540,508 | 9,669,138,879 | -401,629 | 0.99996 | 56,077.41 | 56,075.08 |
| ADS-B fields / checks | 207,150,110 | 207,150,184 | +74 | 1.00000 | 1,201.34 | 1,201.34 |
| Output-model construction / residual control | 43,325,328 | 43,312,345 | -12,983 | 0.99970 | 251.26 | 251.19 |
| Total | 37,162,226,042 | 33,549,250,063 | -3,612,975,979 | 0.90278 | 215,518.15 | 194,565.10 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 2,525,443,427 | 1,311,415,363 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 2,481,560,500 | 2,238,198,745 |
| BDS60 | 47,166 | 19,356 | 17,149 | 2,845,999,409 | 2,654,866,177 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen5/source-review.json](../tests/evidence/diagnostics/gen5/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| 20 | 29,460 | 17,988,016 | 610.59 | Yes |
| 21 | 18,254 | 11,767,651 | 644.66 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 55,231,100 small allocations. The sum of separate DF loops is 55,231,270, a difference of 170. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 5,007,002,555 |
| `frameSyndrome` | 287,418 | 7,934,040,404 |
| `Parity_checksum` | 287,418 | 5,289,226,745 |
| `Parity_syndrome` | 287,418 | 4,999,846,344 |
| `Parity_step` | 26,320,784 | 1,107,759,784 |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 2,092,418,992 |
| `Semantics_adsb` | 51,212 | 2,908,925,322 |
| `Semantics_commB` | 46,440 | 6,291,292,551 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | 45,510 | 1,489,226,852 |
| `ScoreGate_choose` | 45,510 | 4,070,455,040 |
| `ScoreGate_envelope` | 45,510 | 1,919,199,174 |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,457,353 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid60` | 64,315 | 265,251,855 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` | 287,418 | 2,126,405,516 |

Optional ScoreGate, table and fallback-related anchors are overlapping native-symbol observations, not another cost partition. An absent/inlined symbol does not establish zero logical computations, zero fallback decisions or zero initialization work. A fallback population requires a verified live call boundary or a separately checked census; instruction counts are not converted into decision counts.

Frame/CRC-stage contexts further separate fixed-width remainder work from extraction of bits from the complete word. This filter follows the combined frame/CRC stage, not a stricter parity-only ancestry test. The following inclusive costs overlap: a high-level parity helper can call the Nat/GMP helpers below it. They must not be added, subtracted as if disjoint, or extrapolated to predicted speedups. Uses attributed to other stages are excluded. A zero native-symbol count does not imply that all semantically related work disappeared.

| Helper in frame/CRC-stage contexts | Native entries | Inclusive Ir | Share of frame/CRC Ir (overlapping) |
|---|---:|---:|---:|
| `Parity_step` | 26,320,784 | 1,107,759,784 | 8.50% |
| `l_BitVec_ofNat` | 958,535 | 1,274,090,844 | 9.77% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 3,412,064 | 3,453,466,358 | 26.49% |
| `lean_nat_big_shiftr` | 182,596 | 94,584,728 | 0.73% |
| `lean_uint64_of_big_nat` | 182,596 | 162,354,285 | 1.25% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Frame / CRC** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameSyndrome` | 287,418 | 19,933,294 | 7,934,040,404 |
| `lp_lean1090_Lean1090_Impl_Parity_checksum` | 287,418 | 9,822,938 | 5,289,226,745 |
| `lp_lean1090_Lean1090_Impl_decodeFrame` | 172,432 | 23,239,337 | 5,007,002,555 |
| `lp_lean1090_Lean1090_Impl_Parity_syndrome` | 287,418 | 17,113,225 | 4,999,846,344 |
| `lean_nat_pow` | 3,412,064 | 151,383,528 | 3,453,466,358 |
| `lean::mpz::mpz(unsigned long)` | 6,057,515 | 151,437,875 | 2,876,561,836 |
| `lp_lean1090_Lean1090_Impl_field` | 881,619 | 54,861,964 | 2,818,955,000 |
| `lean::mpz::~mpz()` | 23,376,061 | 93,504,244 | 2,477,753,882 |
| `lp_lean1090_Lean1090_Impl_frameAddress` | 172,432 | 6,065,191 | 2,387,810,846 |
| `__gmpz_clear` | 23,376,061 | 163,629,103 | 2,384,249,638 |
| `lp_lean1090_Lean1090_Impl_packFields` | 287,418 | 862,254 | 2,288,872,948 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 287,418 | 92,929,490 | 2,288,010,694 |
| `__gmp_default_free` | 23,374,953 | 46,749,906 | 2,220,620,535 |
| `lean_dec_ref_cold` | 3,048,490 | 1,234,518,230 | 2,198,411,742 |
| `free` | 23,374,953 | 911,623,167 | 2,173,870,629 |

The source and generated C retained under `tests/evidence/diagnostics/gen5` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-5 benchmark binary retained 420 samples; 259 had a visible live `Impl.decode` ancestor. Within those visible stacks, report parity/address had 63 samples and Comm-B inference/raw fields had 35. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Frame / CRC** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused the unchanged native production objects from commit `eeb58261e6be0c2b87385f3064a88aed00d4d19a`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen5/analysis/analysis.json](../tests/evidence/diagnostics/gen5/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen5/native/all.jsonl](../tests/evidence/diagnostics/gen5/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen5/native-df/summary.json](../tests/evidence/diagnostics/gen5/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen5/perf/analysis.json](../tests/evidence/diagnostics/gen5/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen5/driver/driver-build.json](../tests/evidence/diagnostics/gen5/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen5/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen5/analysis/analysis.json` | `2cedc492766612847e69ccdac567604e3f64de44733a7284bfa629e692c9411c` |
| `tests/evidence/diagnostics/gen5/native/all.jsonl` | `35500dc6da5079470b2491ec27dad3b531ffbfd8f1babfbf5da1eeab3a3542ab` |
| `tests/evidence/diagnostics/gen5/native-df/summary.json` | `65d4c5604c8dc8f60b7e8037a7509f00d4703a6634777abfdad90a0b956bcc7f` |
| `tests/evidence/diagnostics/gen5/perf/analysis.json` | `eabeda93b815082e80903dcf1630fd5c4a3a81cf39a1ba7df8eb503485b3252e` |
| `tests/evidence/diagnostics/gen5/driver/driver-build.json` | `6fe73f417de18241c067b53b044a011115975fc9a25c19dd75da5e2dce12f74d` |
| `tests/evidence/diagnostics/gen4/analysis/analysis.json` | `bcaa9b77781316b05c816823207ed143d309ee9233b73ed5c8d1c8edc5cbe565` |
| `tests/evidence/diagnostics/gen5/campaign.json` | `fab9dd1e57561046b51848044ef558689874c415581f877e75684fcd71168b42` |
| `bench/runs/gen5/summary.json` | `3ca349967ae5d5ed03bac31dc9493d7f6f6fab2c24ffefba942a622eb624b5f1` |
| `tests/evidence/diagnostics/gen5/context-notes.md` | `fc60d286616dae52e853a29ee59400ae75c4c2ab878cccff9665431fa990ebfe` |
| `tests/evidence/diagnostics/gen5/source-review.json` | `9893949eae950f67a499b9007e23cc276f7fe24f54895df5eb8c4e67fd4b4885` |

## Reviewed run-specific observations

Generation 5 replaces repeated software-binary64 Mach conversion with one immutable 1,024-entry exact value table keyed only by `payloadBits word 25 10`. The actual timed-worker source/C/object/trace binding and retained assembly are in [source-review.json](../tests/evidence/diagnostics/gen5/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen5/source-inspection/). The field-indexed table loads in the hard-validity, penalty and slow-density callers are the live implementation.

**The standalone `cbMach64` native boundary is absent because Clang inlines it. This does not mean zero Mach work.** No separate `cbMach64` context is observed in these profiles. Its field extraction, array access and reference handling remain in retained callers. Therefore this report does not subtract its former inclusive cost as a measured saving, or equate absent entry counts with an eliminated computation. The exclusive stage and candidate/score measurements remain the primary comparisons.

The following retained caller-boundary observations compare the same corpus populations. They overlap each other and the exclusive stages; only the self-event partition is additive. Full per-stage observations, including the previously separate Mach boundary, are in [helper-comparison.json](../tests/evidence/diagnostics/gen5/helper-comparison.json).

| Native boundary in Comm-B inference | Gen4 entries | Gen5 entries | Gen4 self Ir | Gen5 self Ir | Gen4 inclusive Ir | Gen5 inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| `cbValid60` | 64,315 | 64,315 | 3,465,240 | 4,012,830 | 2,658,427,652 | 265,251,855 |
| `cbPenalty` | 45,510 | 45,510 | 5,052,286 | 5,305,298 | 3,312,119,289 | 2,092,418,992 |
| `Binary64_round` | 216,787 | 108,963 | 35,369,698 | 18,214,338 | 6,003,977,068 | 3,011,442,290 |
| `payloadBits` | 3,121,720 | 3,121,720 | 187,303,200 | 187,303,200 | 187,303,200 | 187,303,200 |

The Mach value table is constructed with the original software multiplication/division sequence during module initialization and then marked persistent. Its construction and the existing 13 density-table initializations precede `main`, outside decoder-root collection and warmed benchmark loops. Other software arithmetic remains live, including the IAS/Mach penalty division. Scalar lazy constants and allocator state can still differ across these single-pass diagnostic processes; no unmeasured correction is applied.

The CRC fold, payload extraction, exact interval gate and callable boxed full-software fallback retain their existing live paths. The report reconciles observed CRC and interval/fallback native entries with the checked corpus census. A missing small helper symbol is never substituted for a logical decision count.

Native perf capture completed before any native census or Callgrind worker began. Later family/probe jobs intentionally overlapped, with at most six active profiles. Other agents performed read-only review and benchmark-report archival; host-wide isolation is not claimed. Sampling exclusions and unwind limitations are retained in [perf/README.md](../tests/evidence/diagnostics/gen5/perf/README.md). These conditional sample observations are not a whole-decoder timing decomposition.

Grouped helper inclusive values are raw incoming-edge observations. Recursive/re-entrant visits can overlap within a row, and descendants can cross a later stage boundary. They must not be added to stage totals or interpreted as predicted speedups. No production or frozen source was changed during this diagnostic.


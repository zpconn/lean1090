# Generation 10: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `95bc97d75d83190371768950e56ef7cc0825308d` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Frame / CRC**, with 7,401,732,346 of 16,479,393,245 collected guest instructions (44.92%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-10 benchmark is decode **1.16895×** and CPR **0.79079×**; see [bench/runs/gen10/summary.json](../bench/runs/gen10/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 3,763,304,174 | 74,691.0 | 22.84% |
| commb | 47,714 | 11,060,637,702 | 231,811.2 | 67.12% |
| other | 74,333 | 1,655,451,369 | 22,270.7 | 10.05% |
| Total | 172,432 | 16,479,393,245 | 95,570.4 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Frame / CRC | 2,935,100,556 | 2,973,866,793 | 1,492,764,997 | 7,401,732,346 | 44.92% |
| Comm-B candidate inference / raw records | 1,007,700 | 5,484,115,224 | 1,486,660 | 5,486,609,584 | 33.29% |
| Semantic / oracle value construction | 608,970,781 | 2,584,113,549 | 145,559,541 | 3,338,643,871 | 20.26% |
| ADS-B fields / checks | 205,676,111 | 477,140 | 743,330 | 206,896,581 | 1.26% |
| Output-model construction / residual control | 12,549,026 | 18,064,996 | 14,896,841 | 45,510,863 | 0.28% |

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

## Comparison with generation 9

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen9 Ir | Gen10 Ir | Difference (gen10 − gen9) | Gen10/gen9 | Gen9 Ir/message | Gen10 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Frame / CRC | 7,401,957,598 | 7,401,732,346 | -225,252 | 0.99997 | 42,926.82 | 42,925.51 |
| Comm-B candidate inference / raw records | 7,570,594,302 | 5,486,609,584 | -2,083,984,718 | 0.72473 | 43,904.81 | 31,818.98 |
| Semantic / oracle value construction | 3,338,088,767 | 3,338,643,871 | +555,104 | 1.00017 | 19,358.87 | 19,362.09 |
| ADS-B fields / checks | 206,891,920 | 206,896,581 | +4,661 | 1.00002 | 1,199.85 | 1,199.87 |
| Output-model construction / residual control | 45,520,342 | 45,510,863 | -9,479 | 0.99979 | 263.99 | 263.94 |
| Total | 18,563,052,929 | 16,479,393,245 | -2,083,659,684 | 0.88775 | 107,654.34 | 95,570.39 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 553,001,448 | 381,703,285 |
| BDS44 | 47,166 | 0 | 0 | 48,343,346 | 0 |
| BDS45 | 47,166 | 0 | 0 | 48,439,482 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 1,670,810,668 | 1,427,485,785 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,565,506,671 | 1,374,116,744 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen10/source-review.json](../tests/evidence/diagnostics/gen10/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| 20 | 29,460 | 11,739,452 | 398.49 | Yes |
| 21 | 18,254 | 7,311,692 | 400.55 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 36,852,635 small allocations. The sum of separate DF loops is 36,852,806, a difference of 171. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 2,752,276,069 |
| `frameSyndrome` | 172,432 | 4,558,658,713 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,789,205 |
| `reportWithSyndrome` | 172,432 | 9,135,117,239 |
| `Parity_checksum` | 172,432 | 3,078,755,985 |
| `Parity_syndrome` | 172,432 | 2,918,579,472 |
| `Parity_step` | 15,300,600 | 644,128,899 |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 1,909,546,340 |
| `Semantics_adsb` | 51,212 | 573,088,731 |
| `Semantics_commB` | 46,440 | 2,264,567,592 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,232,841,919 |
| `ScoreGate_commonDenominator` | 45,510 | 43,431,577 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bytesValue` | 172,432 | 2,098,573,459 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,476,638 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid40` | 62,679 | 245,881,662 |
| `cbValid60` | 64,315 | 265,244,046 |
| `field` | 881,619 | 564,431,629 |
| `packFields` | 172,432 | 1,280,612,238 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadValue` | 1,599,153 | 2,100,733,995 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` | 172,432 | 1,233,893,227 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 640,496,583 |

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
| `lean_nat_big_shiftr` | 615,557 | 345,990,937 | 4.67% |
| `lean_uint64_of_big_nat` | 302,379 | 269,235,400 | 3.64% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Frame / CRC** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameSyndrome` | 172,432 | 11,871,146 | 4,558,658,713 |
| `lp_lean1090_Lean1090_Impl_Parity_checksum` | 172,432 | 5,849,357 | 3,078,755,985 |
| `lp_lean1090_Lean1090_Impl_Parity_syndrome` | 172,432 | 10,231,811 | 2,918,579,472 |
| `lp_lean1090_Lean1090_Impl_decodeFrame` | 172,432 | 23,239,337 | 2,752,276,069 |
| `lp_lean1090_Lean1090_Impl_bytesValue` | 172,432 | 517,296 | 2,098,573,459 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | 172,432 | 65,541,483 | 2,098,056,163 |
| `lean::mpz::~mpz()` | 13,379,672 | 53,518,688 | 1,418,186,236 |
| `lean::mpz::mpz(unsigned long)` | 2,873,601 | 71,840,025 | 1,369,244,503 |
| `__gmpz_clear` | 13,379,672 | 93,655,898 | 1,364,667,548 |
| `lean_dec_ref_cold` | 2,259,931 | 726,106,345 | 1,355,999,499 |
| `lp_lean1090_Lean1090_Impl_packFields` | 172,432 | 517,296 | 1,280,612,238 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 52,319,321 | 1,280,094,942 |
| `__gmp_default_free` | 13,379,070 | 26,758,140 | 1,271,011,650 |
| `free` | 13,379,070 | 521,783,730 | 1,244,253,510 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0` | 172,432 | 589,764,328 | 1,233,893,227 |

The source and generated C retained under `tests/evidence/diagnostics/gen10` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-10 benchmark binary retained 301 samples; 93 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: shared frame syndrome: 23; report other/self/unresolved substage: 17; Comm-B inference and raw payload: 14; frame extraction: 14; Comm-B semantic projection: 12; ADS-B raw payload: 5; ADS-B semantic projection: 5; altitude: 2; report parity/address: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Frame / CRC** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused unchanged native production objects originally built from timed commit `d51a3040984beb6f0f96b0f4fcf225ba2622a7e0`; their audited source blobs also match diagnostic checkout `95bc97d75d83190371768950e56ef7cc0825308d`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen10/analysis/analysis.json](../tests/evidence/diagnostics/gen10/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen10/native/all.jsonl](../tests/evidence/diagnostics/gen10/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen10/native-df/summary.json](../tests/evidence/diagnostics/gen10/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen10/perf/analysis.json](../tests/evidence/diagnostics/gen10/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen10/driver/driver-build.json](../tests/evidence/diagnostics/gen10/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen10/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen10/analysis/analysis.json` | `45faf7f3b6bcb01a026dfe772f55704769f93c1cc7a4edb951f5cfa9497be8aa` |
| `tests/evidence/diagnostics/gen10/native/all.jsonl` | `eeb9d2057a03c6afe04390019841facc81007ca33d5ea8254d41e4e7ec83723b` |
| `tests/evidence/diagnostics/gen10/native-df/summary.json` | `352b8ed09e834f62611f39c4ccc008949ebccf9c6dc7a83bee4954dc8c72f877` |
| `tests/evidence/diagnostics/gen10/perf/analysis.json` | `d17449648312f632e9afe71829e154e8e0aaea3122085cf41e42a3f67ec30064` |
| `tests/evidence/diagnostics/gen10/driver/driver-build.json` | `fde33b022e8b7190b0eb7c3697513ec50d8ea3cc09f7ae582236f5274c5f4198` |
| `tests/evidence/diagnostics/gen9/analysis/analysis.json` | `63be1aa257ea0208f5951d771bc6f3bd37dac6b2c8e12c72992be73b7ddb5931` |
| `tests/evidence/diagnostics/gen10/campaign.json` | `9f16a29b8d34ed35773f70119f1ed1a4def45b3d79de44ef857ccaa04d6d94a0` |
| `bench/runs/gen10/summary.json` | `b59da49a5de74d61236965b3f66256ec4738f1760f82d57b412955757f207854` |
| `tests/evidence/diagnostics/gen10/context-notes.md` | `7de20f979098122d55abfaafb8a9d6e86e5046867b43bfa798b69cc468747599` |
| `tests/evidence/diagnostics/gen10/source-review.json` | `4a6157a637d06ebec8a1c20b795c912ebb6c2ca778efb15cc5ae8a063952fcca` |
| `tests/evidence/diagnostics/gen10/benchmark-source-binding.json` | `d28a39ecd51a804c50bd3c42d4cedf624db6efd21c1674f814d851350c01113c` |

## Reviewed run-specific observations

Generation 10 replaces repeated QNH software-binary64 arithmetic with the complete immutable 4,096-entry table keyed solely by the 12-bit QNH field code. The original operation order is proved equal for every payload word. The full table is initialized before main and kept persistent; its construction is outside the collected decoder roots and warmed benchmark loops. The actual linked callers retain live checked table access even when the standalone cbQNH64 wrapper is inlined. Retained timed-worker source/C/object/trace and assembly evidence is in [source-review.json](../tests/evidence/diagnostics/gen10/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen10/source-inspection/).

The diagnostic checkout is `95bc97d75d83190371768950e56ef7cc0825308d`. The original generation-10 timed commit `d51a3040984beb6f0f96b0f4fcf225ba2622a7e0` maps to `0131adfd5fe6f2ba4b18af1b7f8dccdb474354a5` with the same tree after the owner-requested attribution correction. All 117 audited Lean source blobs, all 22 linked native sets and the timed worker are checked against the original recorded hashes. Publication and attribution metadata changed; no measured record is rewritten and this is not a fresh benchmark. [Explicit binding](../tests/evidence/diagnostics/gen10/benchmark-source-binding.json).

The live syndrome fold, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. Incoming inclusive costs overlap each other and the exclusive stage totals; they are not additive subdivisions. Complete helper self costs remain the exact partition. Machine-word frame and payload field extraction, affine guards and exact integer score decisions remain live. Rational center/envelope/mass are pure reference APIs used only by the post-collection census. The unchanged software-score callback remains lazy.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs; the old repeated-call prediction stays historical. Rejected-input costs are not claimed from this accepted corpus. Native acceptance can be inlined into residual control, while address and parity helpers retain operational frame/CRC attribution. Integer choose/common-denominator/pair-fold and fallback native counts are reconciled with the separately checked register populations.

All immutable density, Mach and QNH tables are initialized before main. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. Missing standalone or inlined helper boundaries do not mean zero computation.

The native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews and prepared future benchmark tooling; no host-wide isolation is claimed. Of 301 samples, 93 have a visible decoder ancestor and 208 are excluded; 289 stacks contain an unknown frame and 0 included leaves are unknown. Conditional observations cannot allocate whole-decoder time reliably. Exact capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen10/perf/README.md). These are diagnostics, not benchmark timings.

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within one inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.


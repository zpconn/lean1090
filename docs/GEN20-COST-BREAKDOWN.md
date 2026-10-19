# Generation 20: untimed decoder cost breakdown

**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `ee22eab664b16c28382dc85c81d92195b5182fc5` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **Comm-B candidate inference / raw records**, with 3,065,868,970 of 9,056,220,724 collected guest instructions (33.85%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.

The separately completed generation-20 benchmark is decode **1.85206×** and CPR **1.48565×**; see [bench/runs/gen20/summary.json](../bench/runs/gen20/summary.json). This diagnostic does not revise either benchmark.

## Corpus families and exclusive stages

Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.

Family and supplemental jobs count instrumented guest instructions and make no timing or throughput claim. Their concurrency and the native perf capture's chronology are recorded in the campaign/capture provenance; this report does not infer isolation from instruction counts. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.

The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.

| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |
|---|---:|---:|---:|---:|
| adsb | 50,385 | 1,793,739,582 | 35,600.7 | 19.81% |
| commb | 47,714 | 6,536,947,246 | 137,002.7 | 72.18% |
| other | 74,333 | 725,533,896 | 9,760.6 | 8.01% |
| Total | 172,432 | 9,056,220,724 | 52,520.5 | 100% |

ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.

| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |
|---|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 1,007,700 | 3,063,374,610 | 1,486,660 | 3,065,868,970 | 33.85% |
| Frame / CRC | 1,078,126,229 | 1,190,495,286 | 697,110,158 | 2,965,731,673 | 32.75% |
| Semantic / oracle value construction | 513,615,890 | 2,264,173,390 | 11,293,316 | 2,789,082,596 | 30.80% |
| ADS-B fields / checks | 188,149,214 | 477,140 | 743,330 | 189,369,684 | 2.09% |
| Output-model construction / residual control | 12,840,549 | 18,426,820 | 14,900,432 | 46,167,801 | 0.51% |

All stage contexts resolved uniquely: **True**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.

The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.

## Shared-syndrome census and native entries

The original shadow census is retained exactly for historical comparison; its repeated-CRC prediction is not the current expectation. A separate post-decode census reparses every corpus row, checks its frame and syndrome against the retained decoder result, and predicts one syndrome after successful parsing. This work occurs after collection and does not enter the decoder-root counters.

All 172,432 corpus rows are accepted, as required by the complete retained-output check. This census covers that accepted corpus only. It does not measure malformed frames or frames rejected after parsing; the latter now compute a syndrome before rejection, as documented by the source/native review.

| Family | Historical repeated-call prediction | Live one-per-frame prediction | Observed frameSyndrome / checksum entries | Observed byte-loop entries |
|---|---:|---:|---:|---:|
| adsb | 81,780 | 50,385 | 50,385 / 50,385 | 50,385 |
| commb | 95,428 | 47,714 | 47,714 / 47,714 | 47,714 |
| other | 110,210 | 74,333 | 74,333 / 74,333 | 74,333 |

The checked 7/14-byte corpus predicts 1,912,575 byte iterations and 15,300,600 equivalent bit updates. These are mathematical iteration counts, not observed function entries. Each observed byte-loop entry processes one syndrome, with eight inlined UInt32 updates per iteration. The live generic bit-loop fallback has zero entries in this accepted corpus; source/native inspection and all-input proofs retain it for widths above 128 or not divisible by eight. Neither zero fallback entries nor absent standalone `Parity.step` calls means zero CRC work.

The new acceptance/address helpers keep their predecessor stages when they retain a native boundary. Acceptance control inlined into `decode` remains in that function's residual-control category; its called hard-validity helper retains the ADS-B category. No cost is reassigned by source-level intention. The renamed report helper retains the same report/semantic boundaries. These compiler-boundary changes must be considered when comparing stage deltas.

## Comparison with generation 19

The compared family populations agree. Absolute counts and instruction counts per message are shown below; changing shares alone would hide denominator changes. Interpretation also requires checking complete output digests, control-flow census and live generated-C stage boundaries against both retained runs. Any source-specific change or attribution limit belongs in the reviewed run-specific observations, not an inferred narrative.

| Exclusive stage | Gen19 Ir | Gen20 Ir | Difference (gen20 − gen19) | Gen20/gen19 | Gen19 Ir/message | Gen20 Ir/message |
|---|---:|---:|---:|---:|---:|---:|
| Comm-B candidate inference / raw records | 3,065,865,670 | 3,065,868,970 | +3,300 | 1.00000 | 17,780.14 | 17,780.16 |
| Frame / CRC | 3,496,975,683 | 2,965,731,673 | -531,244,010 | 0.84808 | 20,280.32 | 17,199.43 |
| Semantic / oracle value construction | 2,789,090,702 | 2,789,082,596 | -8,106 | 1.00000 | 16,175.02 | 16,174.97 |
| ADS-B fields / checks | 189,381,177 | 189,369,684 | -11,493 | 0.99994 | 1,098.29 | 1,098.23 |
| Output-model construction / residual control | 46,168,937 | 46,167,801 | -1,136 | 0.99998 | 267.75 | 267.74 |
| Total | 9,587,482,169 | 9,056,220,724 | -531,261,445 | 0.94459 | 55,601.53 | 52,520.53 |

These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.

## Each scored Comm-B register

Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached live score-gate path, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.

These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.

| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |
|---|---:|---:|---:|---:|---:|
| BDS40 | 47,166 | 15,513 | 15,513 | 516,578,715 | 381,820,861 |
| BDS44 | 47,166 | 0 | 0 | 11,836,862 | 0 |
| BDS45 | 47,166 | 0 | 0 | 11,932,998 | 0 |
| BDS50 | 47,166 | 10,641 | 9,813 | 705,832,050 | 502,888,690 |
| BDS60 | 47,166 | 19,356 | 17,149 | 1,051,922,618 | 899,495,627 |

### Interval decisions and retained native call boundaries

The post-decode census replays the live interval predicates and checks each result against live `cbScorePasses`. These are population counts. Separately, native entries at `ScoreGate.choose` and the verified boxed fallback thunk are counted in every whole-decoder and supplemental profile. The two observations must agree; no decision count is inferred from instruction cost.

| Register | Reached | Fast accept | Fast reject | Fallback accept / reject | Native choose (score / candidate) | Native fallback (score / candidate) |
|---|---:|---:|---:|---:|---:|---:|
| BDS40 | 15,513 | 15,513 | 0 | 0 / 0 | 15,513 / 15,513 | 0 / 0 |
| BDS44 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS45 | 0 | 0 | 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| BDS50 | 10,641 | 9,813 | 828 | 0 / 0 | 10,641 / 10,641 | 0 / 0 |
| BDS60 | 19,356 | 17,149 | 2,207 | 0 / 0 | 19,356 / 19,356 | 0 / 0 |

Across the disjoint whole-decoder families: **45,510** native interval entries and **0** entries at `lp_lean1090_Lean1090_Impl_cbScorePasses___lam__0___boxed`. The exact retained fallback boundary and source/C/object association are documented in [tests/evidence/diagnostics/gen20/independent-review/source-review.json](../tests/evidence/diagnostics/gen20/independent-review/source-review.json). Supplemental counts overlap the whole-decoder observations and are not added to them.


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
| 20 | 29,460 | 7,690,847 | 261.06 | Yes |
| 21 | 18,254 | 4,841,234 | 265.21 | Yes |

Absent corpus DFs: 1, 2, 3, 6, 7, 8, 9, 10, 12, 13, 14, 15, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31. These are zero-coverage strata, not failed decodes.

The complete corpus loop records 19,899,228 small allocations. The sum of separate DF loops is 19,899,400, a difference of 172. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.

## Nested live calls (non-additive)

Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.

| Live function | Native entries across families | Inclusive Ir across families |
|---|---:|---:|
| `decodeFrame` | 172,432 | 1,107,314,212 |
| `frameSyndrome` | 172,432 | 1,768,197,273 |
| `frameAcceptedWithSyndrome` | Not observed in collected call contexts | Not assigned |
| `frameAddressWithSyndrome` | 172,432 | 7,242,145 |
| `reportWithSyndrome` | 172,432 | 6,157,560,538 |
| `Parity_checksum` | 172,432 | 748,158,326 |
| `Parity_syndrome` | 172,432 | 587,967,775 |
| `Parity_step` | Not observed in collected call contexts | Not assigned |
| `cbDensity` | Not observed in collected call contexts | Not assigned |
| `cbPenalty` | 45,510 | 512,854,720 |
| `Semantics_adsb` | 51,212 | 504,909,543 |
| `Semantics_commB` | 46,440 | 2,249,495,458 |
| `cbCombinedScore` | Not observed in collected call contexts | Not assigned |
| `_init_lp_lean1090_Lean1090_Impl_Binary64_powerTwoTable___closed__1` | Not observed in collected call contexts | Not assigned |
| `initialize_lean1090_Impl_Binary64` | Not observed in collected call contexts | Not assigned |
| `l_Rat_add` | 56,229 | 95,231,974 |
| `l_Rat_div` | 52,831 | 241,148,243 |
| `l_Rat_mul` | 502,756 | 1,667,150,651 |
| `lean_cstr_to_nat` | 50,390 | 38,900,980 |
| `Altitude_bit` | 63,893 | 1,469,539 |
| `Altitude_grayDecode` | 10,668 | 7,994,377 |
| `Binary64_div` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwo` | 1,324 | 116,512 |
| `Binary64_powerTwoFormula` | Not observed in collected call contexts | Not assigned |
| `Binary64_powerTwoTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `Binary64_round` | 662 | 15,433,570 |
| `CPR_Policy_toFloat` | Not observed in collected call contexts | Not assigned |
| `CPR_Policy_toFloatFallback` | Not observed in collected call contexts | Not assigned |
| `Parity_syndromeBits` | Not observed in collected call contexts | Not assigned |
| `Parity_syndromeBytes` | 172,432 | 583,656,975 |
| `ScoreGate_center` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_choose` | 45,510 | 1,232,766,685 |
| `ScoreGate_commonDenominator` | 45,510 | 43,809,985 |
| `ScoreGate_envelope` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_mass` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledNumerator` | Not observed in collected call contexts | Not assigned |
| `ScoreGate_scaledTotals` | Not observed in collected call contexts | Not assigned |
| `affineValue` | Not observed in collected call contexts | Not assigned |
| `bdsWireValid` | 627,880 | 998,087,775 |
| `bytesValue` | 172,432 | 454,118,972 |
| `bytesWord` | Not observed in collected call contexts | Not assigned |
| `bytesWordPrefix` | 100,793 | 41,361,373 |
| `cbDensityTableGet` | Not observed in collected call contexts | Not assigned |
| `cbDensityTerms` | Not observed in collected call contexts | Not assigned |
| `cbDensityTermsFast` | 45,510 | 34,477,194 |
| `cbMach64` | Not observed in collected call contexts | Not assigned |
| `cbQNH64` | Not observed in collected call contexts | Not assigned |
| `cbRatioOutside250800` | 17,394 | 159,012,104 |
| `cbScorePasses___lam__0___boxed` | Not observed in collected call contexts | Not assigned |
| `cbValid18` | 47,171 | 19,856,066 |
| `cbValid19` | 47,166 | 14,192,349 |
| `cbValid40` | 62,679 | 246,013,259 |
| `cbValid44` | 47,166 | 4,195,970 |
| `cbValid45` | 47,166 | 3,773,280 |
| `cbValid50` | 56,979 | 284,208,053 |
| `cbValid60` | 64,315 | 260,865,912 |
| `cbWindPenalty50` | 10,641 | 3,048,948 |
| `cbWindPenaltyTable___lam__0` | Not observed in collected call contexts | Not assigned |
| `commBPayloadLimit` | Not observed in collected call contexts | Not assigned |
| `field` | 881,619 | 564,514,596 |
| `identityCode` | 21,257 | 7,057,324 |
| `identityCode___lam__0` | Not observed in collected call contexts | Not assigned |
| `packFields` | 172,432 | 816,478,570 |
| `payloadBits` | 7,470,552 | 448,233,120 |
| `payloadInteger` | 1,639,589 | 418,530,906 |
| `payloadValue` | 1,578,891 | 2,008,225,332 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,766 | 5,262,564 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 641,118,869 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 815,961,274 |
| `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBits_spec__0___redArg` | Not observed in collected call contexts | Not assigned |
| `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 |

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
| `l_BitVec_ofNat` | 249,344 | 261,923,352 | 8.83% |
| `l_Nat_testBit` | 0 | 0 | 0.00% |
| `lean_nat_pow` | 249,344 | 254,941,720 | 8.60% |
| `lean_nat_big_shiftr` | 615,557 | 346,073,904 | 11.67% |
| `lean_uint64_of_big_nat` | 302,379 | 269,235,400 | 9.08% |

### Largest-stage nested helpers

These are the 15 largest observed inclusive symbol totals within uniquely attributed **Comm-B candidate inference / raw records** contexts. Caller suffixes are grouped by their actual native base symbol. Inclusive values are raw summed incoming call-edge observations: recursive or re-entrant visits can overlap within one row, and descendants can cross a later stage boundary. They are not deduplicated stage-local subtree costs. Rows also overlap each other and the exclusive stage; do not add them or infer a speedup. Only the grouped self costs form a partition. Inlined work remains in its retained caller. Full per-stage observations, including self costs and all smaller symbols, are in the analysis JSON.

| Observed symbol | Native entries | Self Ir | Inclusive Ir (non-additive) |
|---|---:|---:|---:|
| `lp_lean1090_Lean1090_Impl_frameCommB` | 172,432 | 4,021,208 | 3,065,868,970 |
| `lp_lean1090_Lean1090_Impl_inferCommB` | 47,714 | 190,856 | 3,051,488,280 |
| `lp_lean1090_List_filterMapTR_go___at___00Lean1090_Impl_inferCommB_spec__0` | 47,714 | 36,150,010 | 3,051,297,424 |
| `lp_lean1090_Lean1090_Impl_commBEligible` | 667,996 | 23,781,940 | 2,556,159,464 |
| `lp_lean1090_Lean1090_Impl_commBCoreEligible` | 565,992 | 13,739,166 | 2,489,504,339 |
| `lp_lean1090_Lean1090_Impl_cbScorePasses` | 45,510 | 1,865,910 | 1,783,575,498 |
| `lp_lean1090_Lean1090_Impl_ScoreGate_choose` | 45,510 | 19,248,889 | 1,232,766,685 |
| `lp_lean1090_Lean1090_Impl_bdsWireValid` | 627,880 | 18,451,163 | 998,087,775 |
| `lean::mpz::~mpz()` | 6,947,353 | 27,789,412 | 724,275,186 |
| `__gmpz_clear` | 6,947,353 | 48,228,862 | 696,485,774 |
| `__gmp_default_free` | 6,813,150 | 13,626,300 | 648,256,912 |
| `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,118,869 |
| `free` | 6,813,152 | 265,712,928 | 634,630,798 |
| `lean::mpz::mpz(unsigned long)` | 1,073,429 | 26,835,725 | 555,246,278 |
| `lp_lean1090_Lean1090_Impl_cbPenalty` | 45,510 | 4,164,506 | 512,854,720 |

The source and generated C retained under `tests/evidence/diagnostics/gen20` identify the actual live boundaries for this run. Source-specific explanations, compiler inlining and initialization placement must be checked there; no prior generation's C line numbers are assumed.

## Native sampling cross-check

A separate `perf` software CPU-clock capture of the generation-20 benchmark binary retained 231 samples; 64 had a visible live `Impl.decode` ancestor. Its recorded detail labels within those visible stacks are: Comm-B semantic projection: 15; report other/self/unresolved substage: 14; frame extraction: 12; shared frame syndrome: 11; Comm-B inference and raw payload: 7; ADS-B raw payload: 2; ADS-B semantic projection: 2; identity: 1. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. The capture provenance records the actual concurrency and collection conditions; host-wide isolation is not inferred. This is a diagnostic, not a frozen benchmark.

## Consequences for the next optimization

Start with the measured **Comm-B candidate inference / raw records** cost and inspect its actual source/generated-C path. A proposed improvement must follow the current user authorization and preserve the refinement theorem, then be evaluated with the frozen benchmark protocol. These counters do not establish which optimization will improve throughput.

These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.

## Reproduction and evidence

The diagnostic driver reused unchanged native production objects originally built from timed commit `d3a10f60e7e83a35c53d5e4066a82dce048ad2be`; their audited source blobs also match diagnostic checkout `ee22eab664b16c28382dc85c81d92195b5182fc5`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8`.

- Exclusive cost analysis: [tests/evidence/diagnostics/gen20/analysis/analysis.json](../tests/evidence/diagnostics/gen20/analysis/analysis.json).
- Independently checked control-flow census: [tests/evidence/diagnostics/gen20/native/all.jsonl](../tests/evidence/diagnostics/gen20/native/all.jsonl).
- Per-DF native commands, digests, allocation counts and binary/object checks: [tests/evidence/diagnostics/gen20/native-df/summary.json](../tests/evidence/diagnostics/gen20/native-df/summary.json).
- Original native sampling and its limits: [tests/evidence/diagnostics/gen20/perf/analysis.json](../tests/evidence/diagnostics/gen20/perf/analysis.json).
- Diagnostic build provenance: [tests/evidence/diagnostics/gen20/driver/driver-build.json](../tests/evidence/diagnostics/gen20/driver/driver-build.json).
- Collection outputs, control commands and compressed raw Callgrind event files are retained under `tests/evidence/diagnostics/gen20/callgrind/`.
- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.

Input hashes used to render this document:

| Input | SHA-256 |
|---|---|
| `tests/evidence/diagnostics/gen20/analysis/analysis.json` | `106f3ce6feeffa7094aab2476a5e895b71c52cd6b1860ea736a51f4b631efc47` |
| `tests/evidence/diagnostics/gen20/native/all.jsonl` | `0c831430c691f66c8912d9acfddfb669a55e90f0c592c3a0825ff7c620983430` |
| `tests/evidence/diagnostics/gen20/native-df/summary.json` | `85819bd67865b9be0c8f4643258c716e22b6997f5d503e997335259e84c5ad35` |
| `tests/evidence/diagnostics/gen20/perf/analysis.json` | `3724a455e6eda042a585787381a1f3beba26e54dd25cc981e9941a2fb4968e80` |
| `tests/evidence/diagnostics/gen20/driver/driver-build.json` | `74dd7d6b450ccfb45575c103c065aca7411be428343c3fecdcbac5a5c11662ae` |
| `tests/evidence/diagnostics/gen19/analysis/analysis.json` | `2471720ffb545d4b5c3ef25ca68d5b6df07f4c4709ee09521a3895605975f32b` |
| `tests/evidence/diagnostics/gen20/campaign.json` | `3cf2eb1297082004317c471d07dbdc97acc035786ec391128b45d11731f58606` |
| `bench/runs/gen20/summary.json` | `5e45e572c779d81ce80a7344bf56d4b7ca85c954118f6d223631066376ea0fec` |
| `tests/evidence/diagnostics/gen20/context-notes.md` | `22eedd76969256052301b01f6f6b27952f25d4c39e31a2928afdfbe89f4df305` |
| `tests/evidence/diagnostics/gen20/independent-review/source-review.json` | `f149a41c9841f8547f6d93d40a6b7060286c7f8414729ee58c852c7707464fe4` |
| `tests/evidence/diagnostics/gen20/benchmark-source-binding.json` | `4ec2b810155053e29df4472140bcc3b6da3ace1fc31cf0093d77cd6e07a08a8b` |

## Reviewed run-specific observations

Generation 20 batches eight exact UInt32 CRC updates per byte for widths at most 128 divisible by eight. The original bit loop remains the general fallback; all-input proofs preserve every natural width and word. [Current source/native review](../tests/evidence/diagnostics/gen20/independent-review/source-review.json) binds the fresh timed worker, both callable wrappers and loops, and the eight inlined updates in order. This report collects actual Impl.decode only; the separate CPR diagnostic covers tracking and numeric geography. Comparisons with generation 19 are instruction observations, not throughput predictions or inferred input distributions.

The current checkout contains the committed generation-20 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.

The live UInt32 byte loop and generic bit-loop fallback, syndrome, checksum, byte-value fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed byte loop has one entry per syndrome in this accepted corpus. Its byte-iteration count is predicted from frame widths, and each byte performs eight inlined updates. The callable bit-loop fallback has no observed entries here; it remains live for other widths. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 231 samples, 64 have a visible decoder ancestor and 167 are excluded; 220 stacks contain an unknown frame and 0 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen20/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

CRC wrapper and loop entries reconcile with the separately checked accepted-corpus census:

| Profile | Predicted CRC calls | Observed byte wrapper / loop | Observed bit wrapper / loop | Predicted byte iterations | Predicted bit updates |
|---|---:|---:|---:|---:|---:|
| adsb | 50,385 | 50,385 / 50,385 | 0 / 0 | 705,390 | 5,643,120 |
| commb | 47,714 | 47,714 / 47,714 | 0 / 0 | 667,996 | 5,343,968 |
| other | 74,333 | 74,333 / 74,333 | 0 / 0 | 539,189 | 4,313,512 |
| candidate40 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate44 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate45 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate50 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate60 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score40 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score44 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score45 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score50 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score60 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |

Observed entries are incoming native calls; iteration predictions are separate mathematical census data. All ten overlapping register probes are checked separately. The generic fallback remains callable and proved for arbitrary inputs; its zero accepted-corpus count does not remove its implementation or cost for unseen widths. Byte extraction and eight updates inline into the actual loop, which still contains natural-index and ownership work. [CRC boundary and direct-child evidence](../tests/evidence/diagnostics/gen20/crc-byte-contexts.json) compares both generations without copying old profiles or inferring elapsed time.

| Generation | CRC boundary | Native entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| 19 | `Parity_syndrome` | 172,432 | 6,438,292 | 1,119,219,468 |
| 19 | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg` | 172,432 | 788,844,560 | 788,844,560 |
| 20 | `Parity_syndrome` | 172,432 | 4,310,800 | 587,967,775 |
| 20 | `Parity_syndromeBytes` | 172,432 | 6,295,014 | 583,656,975 |
| 20 | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |

These nested inclusive rows overlap each other and frame/CRC stage cost. Only the exclusive stage partition can be added.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen20/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 516,578,715 |
| candidate44 | 47,166 | 0 | 0 | 0 | 11,836,862 |
| candidate45 | 47,166 | 0 | 0 | 0 | 11,932,998 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 142,764,389 | 705,832,050 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 369,662,237 | 1,051,922,618 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,820,861 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 142,757,861 | 502,888,690 |
| score60 | 19,356 | 19,356 | 2,429,938 | 369,779,361 | 899,495,627 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen20/penalty-probe-costs.json).

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

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen20/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,012,104 | 187,526 |
| other | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate60 | 17,394 | 17,386 | 8 | 4,593,636 | 158,934,858 | 187,607 |
| score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| score50 | 0 | 0 | 0 | 0 | 0 | 0 |
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,475,352 | 187,688 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen20/ratio-native-contexts.json) also records generation 19 and 20 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.

The live Comm-B guard and its direct decimal-parser calls:

| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |
|---|---|---:|---:|---:|---:|---:|
| 19 | adsb | 0 | 0 | 0 | 0 | 0 |
| 19 | commb | 627,880 | 18,451,163 | 998,087,774 | 0 | 0 |
| 19 | other | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 19 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 19 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 19 | candidate50 | 47,166 | 1,273,482 | 194,858,282 | 0 | 0 |
| 19 | candidate60 | 47,166 | 1,367,814 | 143,011,400 | 0 | 0 |
| 19 | score40 | 0 | 0 | 0 | 0 | 0 |
| 19 | score44 | 0 | 0 | 0 | 0 | 0 |
| 19 | score45 | 0 | 0 | 0 | 0 | 0 |
| 19 | score50 | 0 | 0 | 0 | 0 | 0 |
| 19 | score60 | 0 | 0 | 0 | 0 | 0 |
| 20 | adsb | 0 | 0 | 0 | 0 | 0 |
| 20 | commb | 627,880 | 18,451,163 | 998,087,775 | 0 | 0 |
| 20 | other | 0 | 0 | 0 | 0 | 0 |
| 20 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 20 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 20 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 20 | candidate50 | 47,166 | 1,273,482 | 194,858,282 | 0 | 0 |
| 20 | candidate60 | 47,166 | 1,367,814 | 143,011,400 | 0 | 0 |
| 20 | score40 | 0 | 0 | 0 | 0 | 0 |
| 20 | score44 | 0 | 0 | 0 | 0 | 0 |
| 20 | score45 | 0 | 0 | 0 | 0 | 0 |
| 20 | score50 | 0 | 0 | 0 | 0 | 0 |
| 20 | score60 | 0 | 0 | 0 | 0 | 0 |

These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen20/constant-native-contexts.json).

The live general packing fold and its observed direct native calls:

| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |
|---|---:|---:|---:|---|---:|---:|
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_nat_big_add` | 100,793 | 151,727,950 |
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_nat_shiftl` | 881,619 | 608,005,149 |
| 20 | 172,432 | 38,791,098 | 815,961,274 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 20 | 172,432 | 38,791,098 | 815,961,274 | `lean_nat_big_add` | 100,793 | 151,727,780 |
| 20 | 172,432 | 38,791,098 | 815,961,274 | `lean_nat_shiftl` | 881,619 | 608,005,207 |

Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The generic power/modulus branch remains in the actual binary for widths at least 64, even if the corpus has no observed calls. [Exact packing contexts](../tests/evidence/diagnostics/gen20/pack-fields-direct-costs.json).

The live power-of-two lookup, formula fallback and startup construction:

| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |
|---|---|---:|---:|---:|---:|---:|---:|
| 19 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 19 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 19 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 19 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 19 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 20 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 20 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 20 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 20 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 20 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 20 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 20 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 20 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 20 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 20 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 20 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 20 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 20 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |

These are actual retained incoming boundaries and direct lookup-to-formula edges. Both generations retain the same immutable format-exponent table. In the current worker, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen20/power-native-contexts.json).

The four optimized extraction paths, compared at actual retained native boundaries:

| Generation | Stage | Native boundary | Entries | Self Ir | Incoming inclusive Ir | Direct pow calls | Direct pow inclusive Ir |
|---|---|---|---:|---:|---:|---:|---:|
| 19 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 19 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 19 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 7,994,377 | 0 | 0 |
| 19 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 104,100,113 | 0 | 0 |
| 19 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 19 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 19 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 314,430,793 | 0 | 0 |
| 19 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |
| 20 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 20 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 20 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 7,994,377 | 0 | 0 |
| 20 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 104,100,113 | 0 | 0 |
| 20 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 20 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 20 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 314,430,793 | 0 | 0 |
| 20 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |

The current compiled identity lambda is inlined into identityCode; its old standalone row is absent while the live extraction remains. Other small arithmetic can inline too. Native entry populations across these changed boundaries are not assumed equal. The current direct-power count is zero only for these selected caller boundaries, consistent with the checked shift/mask implementation; it is not a zero-work claim or a claim about all decoder powers. Incoming inclusive columns overlap stage totals and other helpers. [Exact old/new contexts and direct children](../tests/evidence/diagnostics/gen20/bit-extraction-contexts.json) bind both raw profile sets without copying them or predicting timing.

Selected actual nested helpers for prioritization:

| Stage | Native helper | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| commb_inference | `ScoreGate_choose` | 45,510 | 19,248,889 | 1,232,766,685 |
| commb_inference | `bdsWireValid` | 627,880 | 18,451,163 | 998,087,775 |
| commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,118,869 |
| commb_inference | `l_Rat_mul` | 140,239 | 28,557,789 | 497,099,378 |
| commb_inference | `cbValid50` | 56,979 | 4,940,566 | 284,208,053 |
| commb_inference | `cbValid60` | 64,315 | 4,012,830 | 260,865,912 |
| commb_inference | `cbValid40` | 62,679 | 4,396,089 | 246,013,259 |
| commb_inference | `l_Rat_div` | 48,323 | 386,584 | 226,414,310 |
| commb_inference | `payloadValue` | 58,044 | 6,143,488 | 175,075,931 |
| commb_inference | `cbValid21` | 47,854 | 3,200,897 | 108,985,572 |
| commb_inference | `ScoreGate_commonDenominator` | 45,510 | 5,882,374 | 43,809,985 |
| commb_inference | `cbValid18` | 47,171 | 613,237 | 19,856,066 |
| commb_inference | `cbValid19` | 47,166 | 235,830 | 14,192,349 |
| commb_inference | `cbValid17` | 47,498 | 1,210,360 | 5,759,260 |
| commb_inference | `cbValid44` | 47,166 | 1,051,620 | 4,195,970 |
| commb_inference | `cbValid45` | 47,166 | 943,320 | 3,773,280 |
| frame_crc | `frameSyndrome` | 172,432 | 11,871,146 | 1,768,197,273 |
| frame_crc | `packFields` | 172,432 | 517,296 | 816,478,570 |
| frame_crc | `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 38,791,098 | 815,961,274 |
| frame_crc | `Parity_checksum` | 172,432 | 5,849,357 | 748,158,326 |
| frame_crc | `Parity_syndrome` | 172,432 | 4,310,800 | 587,967,775 |
| frame_crc | `field` | 881,619 | 56,178,834 | 564,514,596 |
| frame_crc | `bytesValue` | 172,432 | 31,171,820 | 454,118,972 |
| frame_crc | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |
| semantic_oracle_values | `payloadValue` | 1,520,847 | 150,316,030 | 1,833,149,401 |
| semantic_oracle_values | `l_Rat_mul` | 362,517 | 73,897,349 | 1,170,051,273 |
| semantic_oracle_values | `l_Rat_add` | 56,229 | 8,095,837 | 95,231,974 |
| semantic_oracle_values | `l_Rat_div` | 4,508 | 36,064 | 14,733,933 |

These rows aggregate only the three disjoint family profiles. Incoming inclusive observations overlap each other and stage totals, including recursive visits and descendants crossing a stage boundary. Direct native children and exact caller contexts are retained in [priority-helper-contexts.json](../tests/evidence/diagnostics/gen20/priority-helper-contexts.json). Rat multiplication rows do not count every logical affine operation; inline work remains in callers. These observations do not select an optimization or infer throughput.


# Generation 17 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 2,125,760,444 | True |
| commb | 7,620,499,248 | True |
| other | 997,958,697 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,280,047,941 | 60.2160% |
| semantic_oracle_values | 622,484,542 | 29.2829% |
| adsb_fields | 209,397,897 | 9.8505% |
| output_model_control | 12,822,364 | 0.6032% |
| commb_inference | 1,007,700 | 0.0474% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 3,610,207,926 | 47.3750% |
| semantic_oracle_values | 2,609,698,929 | 34.2458% |
| frame_crc | 1,381,691,321 | 18.1312% |
| output_model_control | 18,423,932 | 0.2418% |
| adsb_fields | 477,140 | 0.0063% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 835,274,887 | 83.6983% |
| semantic_oracle_values | 145,561,375 | 14.5859% |
| output_model_control | 14,892,445 | 1.4923% |
| commb_inference | 1,486,660 | 0.1490% |
| adsb_fields | 743,330 | 0.0745% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,794,701 |
| 44 | 0 |
| 45 | 0 |
| 50 | 506,955,914 |
| 60 | 899,495,979 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 516,575,831 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 713,784,427 |
| 60 | 1,054,157,327 |

## Attribution limits

- Ir counts instrumented guest instructions, not elapsed time, cycles, cache misses or throughput.
- Stage attribution includes each stage's allocation and runtime helpers; construction is not a global allocation-only category.
- Output-model/control contains final report/message/list assembly plus residual control; instruction-level allocation/control separation is unavailable.
- Generic register arguments are absent from the call graph. Separate score probes overlap Comm-B inference and must not be added to whole-decoder counts.
- Callgrind context merges, if present, remain explicitly shared/ambiguous.
- Register probes are standalone executions of actual reached score gates; allocator/context state may differ from the whole decoder.
- Native entry counts describe retained symbols; inlining/tail-call elimination can remove entries without removing the computation. Census predictions are reported separately.
- Optional ScoreGate/table/fallback anchors retain caller-stage attribution and overlapping inclusive counts only. An unobserved symbol is not evidence of zero logical work or zero fallback decisions.
- These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the three-warmup benchmark; no unmeasured correction is applied.

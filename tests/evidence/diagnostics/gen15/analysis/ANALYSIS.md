# Generation 15 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 2,281,598,530 | True |
| commb | 7,785,925,870 | True |
| other | 1,145,899,373 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,435,871,105 | 62.9327% |
| semantic_oracle_values | 622,496,064 | 27.2833% |
| adsb_fields | 209,389,514 | 9.1773% |
| output_model_control | 12,834,147 | 0.5625% |
| commb_inference | 1,007,700 | 0.0442% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 3,614,674,835 | 46.4258% |
| semantic_oracle_values | 2,609,695,393 | 33.5181% |
| frame_crc | 1,542,652,490 | 19.8133% |
| output_model_control | 18,426,012 | 0.2367% |
| adsb_fields | 477,140 | 0.0061% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 983,213,995 | 85.8028% |
| semantic_oracle_values | 145,561,607 | 12.7028% |
| output_model_control | 14,893,781 | 1.2997% |
| commb_inference | 1,486,660 | 0.1297% |
| adsb_fields | 743,330 | 0.0649% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,799,438 |
| 44 | 0 |
| 45 | 0 |
| 50 | 511,379,713 |
| 60 | 899,560,160 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 516,583,092 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 718,210,729 |
| 60 | 1,054,220,611 |

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

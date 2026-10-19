# Generation 12 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 2,281,605,465 | True |
| commb | 9,662,072,468 | True |
| other | 1,145,889,966 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,435,895,708 | 62.9336% |
| semantic_oracle_values | 622,482,862 | 27.2827% |
| adsb_fields | 209,390,099 | 9.1773% |
| output_model_control | 12,829,096 | 0.5623% |
| commb_inference | 1,007,700 | 0.0442% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 5,491,160,588 | 56.8321% |
| semantic_oracle_values | 2,609,255,084 | 27.0051% |
| frame_crc | 1,542,701,716 | 15.9666% |
| output_model_control | 18,477,940 | 0.1912% |
| adsb_fields | 477,140 | 0.0049% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 983,192,193 | 85.8016% |
| semantic_oracle_values | 145,561,317 | 12.7029% |
| output_model_control | 14,906,466 | 1.3009% |
| commb_inference | 1,486,660 | 0.1297% |
| adsb_fields | 743,330 | 0.0649% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,703,169 |
| 44 | 0 |
| 45 | 0 |
| 50 | 1,427,606,176 |
| 60 | 1,374,241,413 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 553,010,678 |
| 44 | 48,343,346 |
| 45 | 48,439,482 |
| 50 | 1,670,816,929 |
| 60 | 1,565,513,808 |

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

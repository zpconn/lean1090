# Generation 7 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 6,675,589,979 | True |
| commb | 18,188,923,671 | True |
| other | 2,466,613,081 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 3,543,756,644 | 53.0853% |
| semantic_oracle_values | 2,912,528,207 | 43.6295% |
| adsb_fields | 205,730,853 | 3.0818% |
| output_model_control | 12,566,575 | 0.1882% |
| commb_inference | 1,007,700 | 0.0151% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 7,750,329,169 | 42.6102% |
| semantic_oracle_values | 6,610,745,358 | 36.3449% |
| frame_crc | 3,809,215,684 | 20.9425% |
| output_model_control | 18,156,320 | 0.0998% |
| adsb_fields | 477,140 | 0.0026% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 2,303,947,109 | 93.4053% |
| semantic_oracle_values | 145,559,700 | 5.9012% |
| output_model_control | 14,876,282 | 0.6031% |
| commb_inference | 1,486,660 | 0.0603% |
| adsb_fields | 743,330 | 0.0301% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,704,698 |
| 44 | 0 |
| 45 | 0 |
| 50 | 1,494,312,565 |
| 60 | 1,489,295,356 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 1,595,594,543 |
| 44 | 48,343,346 |
| 45 | 48,439,482 |
| 50 | 1,737,643,348 |
| 60 | 1,680,610,421 |

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

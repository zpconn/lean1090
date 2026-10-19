# Generation 23 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 1,425,907,717 | True |
| commb | 4,760,806,695 | True |
| other | 376,026,128 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 703,876,797 | 49.3634% |
| semantic_oracle_values | 509,363,470 | 35.7221% |
| adsb_fields | 190,348,773 | 13.3493% |
| output_model_control | 21,310,977 | 1.4946% |
| commb_inference | 1,007,700 | 0.0707% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 2,303,561,290 | 48.3859% |
| semantic_oracle_values | 1,708,404,812 | 35.8848% |
| frame_crc | 721,736,412 | 15.1600% |
| output_model_control | 26,627,041 | 0.5593% |
| adsb_fields | 477,140 | 0.0100% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 347,497,528 | 92.4131% |
| output_model_control | 14,998,916 | 3.9888% |
| semantic_oracle_values | 11,299,694 | 3.0050% |
| commb_inference | 1,486,660 | 0.3954% |
| adsb_fields | 743,330 | 0.1977% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,717,489 |
| 44 | 0 |
| 45 | 0 |
| 50 | 466,520,428 |
| 60 | 869,642,939 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 407,428,808 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 498,747,111 |
| 60 | 903,877,697 |

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

# Generation 3 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 12,456,710,083 | True |
| commb | 36,381,723,547 | True |
| other | 3,203,946,446 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| semantic_oracle_values | 6,071,832,196 | 48.7435% |
| frame_crc | 4,543,563,407 | 36.4748% |
| adsb_fields | 1,828,870,090 | 14.6818% |
| output_model_control | 11,436,690 | 0.0918% |
| commb_inference | 1,007,700 | 0.0081% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 20,410,890,926 | 56.1020% |
| semantic_oracle_values | 10,499,737,398 | 28.8599% |
| frame_crc | 5,453,001,372 | 14.9883% |
| output_model_control | 17,616,711 | 0.0484% |
| adsb_fields | 477,140 | 0.0013% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 3,041,892,496 | 94.9421% |
| semantic_oracle_values | 145,559,669 | 4.5431% |
| output_model_control | 14,264,291 | 0.4452% |
| commb_inference | 1,486,660 | 0.0464% |
| adsb_fields | 743,330 | 0.0232% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 1,497,049,545 |
| 44 | 0 |
| 45 | 0 |
| 50 | 2,606,868,735 |
| 60 | 4,276,998,672 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 3,154,857,598 |
| 44 | 154,393,343 |
| 45 | 146,497,929 |
| 50 | 3,384,169,347 |
| 60 | 6,315,485,540 |

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

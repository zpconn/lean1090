# Generation 19 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 1,995,656,801 | True |
| commb | 6,728,136,696 | True |
| other | 863,688,672 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,280,030,700 | 64.1408% |
| semantic_oracle_values | 513,622,551 | 25.7370% |
| adsb_fields | 188,160,707 | 9.4285% |
| output_model_control | 12,835,143 | 0.6432% |
| commb_inference | 1,007,700 | 0.0505% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 3,063,371,310 | 45.5308% |
| semantic_oracle_values | 2,264,175,297 | 33.6523% |
| frame_crc | 1,381,683,391 | 20.5359% |
| output_model_control | 18,429,558 | 0.2739% |
| adsb_fields | 477,140 | 0.0071% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 835,261,592 | 96.7086% |
| output_model_control | 14,904,236 | 1.7256% |
| semantic_oracle_values | 11,292,854 | 1.3075% |
| commb_inference | 1,486,660 | 0.1721% |
| adsb_fields | 743,330 | 0.0861% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,793,254 |
| 44 | 0 |
| 45 | 0 |
| 50 | 502,894,732 |
| 60 | 899,498,961 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 516,578,979 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 705,803,397 |
| 60 | 1,051,894,229 |

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

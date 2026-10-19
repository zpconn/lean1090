# Generation 22 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 1,425,901,760 | True |
| commb | 5,458,555,626 | True |
| other | 376,025,801 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 703,876,859 | 49.3636% |
| semantic_oracle_values | 509,340,689 | 35.7206% |
| adsb_fields | 190,365,537 | 13.3505% |
| output_model_control | 21,310,975 | 1.4946% |
| commb_inference | 1,007,700 | 0.0707% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 3,001,306,218 | 54.9835% |
| semantic_oracle_values | 1,708,562,233 | 31.3006% |
| frame_crc | 721,644,386 | 13.2204% |
| output_model_control | 26,565,649 | 0.4867% |
| adsb_fields | 477,140 | 0.0087% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 347,511,809 | 92.4170% |
| output_model_control | 14,984,308 | 3.9849% |
| semantic_oracle_values | 11,299,694 | 3.0050% |
| commb_inference | 1,486,660 | 0.3954% |
| adsb_fields | 743,330 | 0.1977% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,790,858 |
| 44 | 0 |
| 45 | 0 |
| 50 | 466,550,576 |
| 60 | 869,793,865 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 516,543,584 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 669,457,054 |
| 60 | 1,022,125,226 |

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

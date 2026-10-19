# Generation 11 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 3,106,066,033 | True |
| commb | 10,442,549,331 | True |
| other | 1,188,784,518 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 2,260,238,622 | 72.7685% |
| semantic_oracle_values | 622,474,766 | 20.0406% |
| adsb_fields | 209,545,206 | 6.7463% |
| output_model_control | 12,799,739 | 0.4121% |
| commb_inference | 1,007,700 | 0.0324% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 5,491,390,841 | 52.5867% |
| semantic_oracle_values | 2,609,213,554 | 24.9864% |
| frame_crc | 2,322,966,282 | 22.2452% |
| output_model_control | 18,501,514 | 0.1772% |
| adsb_fields | 477,140 | 0.0046% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,026,089,136 | 86.3141% |
| semantic_oracle_values | 145,559,593 | 12.2444% |
| output_model_control | 14,905,799 | 1.2539% |
| commb_inference | 1,486,660 | 0.1251% |
| adsb_fields | 743,330 | 0.0625% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,710,898 |
| 44 | 0 |
| 45 | 0 |
| 50 | 1,427,485,785 |
| 60 | 1,374,116,617 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 553,003,267 |
| 44 | 48,343,346 |
| 45 | 48,439,482 |
| 50 | 1,670,810,668 |
| 60 | 1,565,506,886 |

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

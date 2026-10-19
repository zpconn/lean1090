# Generation 20 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 1,793,739,582 | True |
| commb | 6,536,947,246 | True |
| other | 725,533,896 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,078,126,229 | 60.1049% |
| semantic_oracle_values | 513,615,890 | 28.6338% |
| adsb_fields | 188,149,214 | 10.4892% |
| output_model_control | 12,840,549 | 0.7159% |
| commb_inference | 1,007,700 | 0.0562% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 3,063,374,610 | 46.8625% |
| semantic_oracle_values | 2,264,173,390 | 34.6366% |
| frame_crc | 1,190,495,286 | 18.2118% |
| output_model_control | 18,426,820 | 0.2819% |
| adsb_fields | 477,140 | 0.0073% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 697,110,158 | 96.0824% |
| output_model_control | 14,900,432 | 2.0537% |
| semantic_oracle_values | 11,293,316 | 1.5566% |
| commb_inference | 1,486,660 | 0.2049% |
| adsb_fields | 743,330 | 0.1025% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,820,861 |
| 44 | 0 |
| 45 | 0 |
| 50 | 502,888,690 |
| 60 | 899,495,627 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 516,578,715 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 705,832,050 |
| 60 | 1,051,922,618 |

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

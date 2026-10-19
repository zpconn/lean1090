# Generation 16 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 2,125,750,430 | True |
| commb | 7,624,966,303 | True |
| other | 997,958,533 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,280,042,270 | 60.2160% |
| semantic_oracle_values | 622,480,624 | 29.2829% |
| adsb_fields | 209,389,921 | 9.8502% |
| output_model_control | 12,829,915 | 0.6035% |
| commb_inference | 1,007,700 | 0.0474% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 3,614,662,951 | 47.4056% |
| semantic_oracle_values | 2,609,715,629 | 34.2259% |
| frame_crc | 1,381,685,129 | 18.1205% |
| output_model_control | 18,425,454 | 0.2416% |
| adsb_fields | 477,140 | 0.0063% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 835,263,537 | 83.6972% |
| semantic_oracle_values | 145,561,373 | 14.5859% |
| output_model_control | 14,903,633 | 1.4934% |
| commb_inference | 1,486,660 | 0.1490% |
| adsb_fields | 743,330 | 0.0745% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,827,703 |
| 44 | 0 |
| 45 | 0 |
| 50 | 511,281,969 |
| 60 | 899,588,650 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 516,613,068 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 718,239,786 |
| 60 | 1,054,249,580 |

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

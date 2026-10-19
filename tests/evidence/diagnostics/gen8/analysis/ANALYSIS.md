# Generation 8 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 4,371,931,522 | True |
| commb | 13,979,089,781 | True |
| other | 2,466,613,091 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 3,543,742,530 | 81.0567% |
| semantic_oracle_values | 608,967,523 | 13.9290% |
| adsb_fields | 205,687,462 | 4.7047% |
| output_model_control | 12,526,307 | 0.2865% |
| commb_inference | 1,007,700 | 0.0230% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 7,568,102,337 | 54.1387% |
| frame_crc | 3,808,863,371 | 27.2469% |
| semantic_oracle_values | 2,583,573,714 | 18.4817% |
| output_model_control | 18,073,219 | 0.1293% |
| adsb_fields | 477,140 | 0.0034% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 2,303,945,421 | 93.4052% |
| semantic_oracle_values | 145,559,702 | 5.9012% |
| output_model_control | 14,877,978 | 0.6032% |
| commb_inference | 1,486,660 | 0.0603% |
| adsb_fields | 743,330 | 0.0301% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,703,329 |
| 44 | 0 |
| 45 | 0 |
| 50 | 1,427,477,772 |
| 60 | 1,374,124,536 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 1,595,601,270 |
| 44 | 48,343,346 |
| 45 | 48,439,482 |
| 50 | 1,670,809,909 |
| 60 | 1,565,507,082 |

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

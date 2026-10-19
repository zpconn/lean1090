# Generation 10 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 3,763,304,174 | True |
| commb | 11,060,637,702 | True |
| other | 1,655,451,369 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 2,935,100,556 | 77.9926% |
| semantic_oracle_values | 608,970,781 | 16.1818% |
| adsb_fields | 205,676,111 | 5.4653% |
| output_model_control | 12,549,026 | 0.3335% |
| commb_inference | 1,007,700 | 0.0268% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 5,484,115,224 | 49.5823% |
| frame_crc | 2,973,866,793 | 26.8869% |
| semantic_oracle_values | 2,584,113,549 | 23.3632% |
| output_model_control | 18,064,996 | 0.1633% |
| adsb_fields | 477,140 | 0.0043% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,492,764,997 | 90.1727% |
| semantic_oracle_values | 145,559,541 | 8.7927% |
| output_model_control | 14,896,841 | 0.8999% |
| commb_inference | 1,486,660 | 0.0898% |
| adsb_fields | 743,330 | 0.0449% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,703,285 |
| 44 | 0 |
| 45 | 0 |
| 50 | 1,427,485,785 |
| 60 | 1,374,116,744 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 553,001,448 |
| 44 | 48,343,346 |
| 45 | 48,439,482 |
| 50 | 1,670,810,668 |
| 60 | 1,565,506,671 |

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

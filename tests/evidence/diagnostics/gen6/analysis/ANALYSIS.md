# Generation 6 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 6,675,602,067 | True |
| commb | 21,026,598,957 | True |
| other | 2,466,613,948 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 3,543,797,985 | 53.0858% |
| semantic_oracle_values | 2,912,507,424 | 43.6291% |
| adsb_fields | 205,730,911 | 3.0818% |
| output_model_control | 12,558,047 | 0.1881% |
| commb_inference | 1,007,700 | 0.0151% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 10,588,064,970 | 50.3556% |
| semantic_oracle_values | 6,610,528,632 | 31.4389% |
| frame_crc | 3,809,489,819 | 18.1175% |
| output_model_control | 18,038,396 | 0.0858% |
| adsb_fields | 477,140 | 0.0023% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 2,303,943,720 | 93.4051% |
| semantic_oracle_values | 145,561,832 | 5.9013% |
| output_model_control | 14,878,406 | 0.6032% |
| commb_inference | 1,486,660 | 0.0603% |
| adsb_fields | 743,330 | 0.0301% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 1,311,416,517 |
| 44 | 0 |
| 45 | 0 |
| 50 | 2,238,081,694 |
| 60 | 2,654,727,594 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 2,525,443,427 |
| 44 | 48,343,346 |
| 45 | 48,439,482 |
| 50 | 2,481,449,511 |
| 60 | 2,845,866,135 |

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

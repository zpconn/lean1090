# Generation 5 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 7,674,710,723 | True |
| commb | 22,670,592,590 | True |
| other | 3,203,946,750 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 4,543,605,435 | 59.2023% |
| semantic_oracle_values | 2,912,740,723 | 37.9524% |
| adsb_fields | 205,929,714 | 2.6832% |
| output_model_control | 11,427,151 | 0.1489% |
| commb_inference | 1,007,700 | 0.0131% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 10,588,563,645 | 46.7062% |
| semantic_oracle_values | 6,610,838,495 | 29.1604% |
| frame_crc | 5,453,081,440 | 24.0535% |
| output_model_control | 17,631,870 | 0.0778% |
| adsb_fields | 477,140 | 0.0021% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 3,041,903,775 | 94.9424% |
| semantic_oracle_values | 145,559,661 | 4.5431% |
| output_model_control | 14,253,324 | 0.4449% |
| commb_inference | 1,486,660 | 0.0464% |
| adsb_fields | 743,330 | 0.0232% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 1,311,415,363 |
| 44 | 0 |
| 45 | 0 |
| 50 | 2,238,198,745 |
| 60 | 2,654,866,177 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 2,525,443,427 |
| 44 | 48,343,346 |
| 45 | 48,439,482 |
| 50 | 2,481,560,500 |
| 60 | 2,845,999,409 |

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

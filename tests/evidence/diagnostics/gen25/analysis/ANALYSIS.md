# Generation 25 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 1,425,903,854 | True |
| commb | 3,946,332,740 | True |
| other | 376,026,130 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 703,887,680 | 49.3643% |
| semantic_oracle_values | 509,355,725 | 35.7216% |
| adsb_fields | 190,340,902 | 13.3488% |
| output_model_control | 21,311,847 | 1.4946% |
| commb_inference | 1,007,700 | 0.0707% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 2,246,104,064 | 56.9162% |
| semantic_oracle_values | 951,533,020 | 24.1118% |
| frame_crc | 721,638,011 | 18.2863% |
| output_model_control | 26,580,505 | 0.6735% |
| adsb_fields | 477,140 | 0.0121% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 347,512,140 | 92.4170% |
| output_model_control | 14,984,306 | 3.9849% |
| semantic_oracle_values | 11,299,694 | 3.0050% |
| commb_inference | 1,486,660 | 0.3954% |
| adsb_fields | 743,330 | 0.1977% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 353,763,260 |
| 44 | 0 |
| 45 | 0 |
| 50 | 455,728,506 |
| 60 | 850,726,232 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 379,488,067 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 487,962,842 |
| 60 | 884,954,498 |

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

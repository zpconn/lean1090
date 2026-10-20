# Generation 24 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 1,425,933,969 | True |
| commb | 4,004,023,914 | True |
| other | 376,025,799 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 703,878,193 | 49.3626% |
| semantic_oracle_values | 509,365,153 | 35.7215% |
| adsb_fields | 190,370,960 | 13.3506% |
| output_model_control | 21,311,963 | 1.4946% |
| commb_inference | 1,007,700 | 0.0707% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 2,303,775,401 | 57.5365% |
| semantic_oracle_values | 951,547,169 | 23.7648% |
| frame_crc | 721,646,032 | 18.0230% |
| output_model_control | 26,578,172 | 0.6638% |
| adsb_fields | 477,140 | 0.0119% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 347,511,807 | 92.4170% |
| output_model_control | 14,984,308 | 3.9849% |
| semantic_oracle_values | 11,299,694 | 3.0050% |
| commb_inference | 1,486,660 | 0.3954% |
| adsb_fields | 743,330 | 0.1977% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,730,005 |
| 44 | 0 |
| 45 | 0 |
| 50 | 466,520,604 |
| 60 | 869,643,027 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 407,428,456 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 498,759,521 |
| 60 | 903,878,137 |

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

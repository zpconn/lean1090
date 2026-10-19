# Generation 21 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 1,789,028,952 | True |
| commb | 5,915,257,511 | True |
| other | 725,526,567 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 1,078,150,420 | 60.2646% |
| semantic_oracle_values | 508,900,042 | 28.4456% |
| adsb_fields | 188,137,687 | 10.5162% |
| output_model_control | 12,833,103 | 0.7173% |
| commb_inference | 1,007,700 | 0.0563% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 2,997,214,829 | 50.6692% |
| semantic_oracle_values | 1,708,757,351 | 28.8873% |
| frame_crc | 1,190,385,305 | 20.1240% |
| output_model_control | 18,422,886 | 0.3114% |
| adsb_fields | 477,140 | 0.0081% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 697,097,970 | 96.0817% |
| output_model_control | 14,905,579 | 2.0544% |
| semantic_oracle_values | 11,293,028 | 1.5565% |
| commb_inference | 1,486,660 | 0.2049% |
| adsb_fields | 743,330 | 0.1025% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 381,771,846 |
| 44 | 0 |
| 45 | 0 |
| 50 | 466,548,426 |
| 60 | 869,767,005 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 516,571,060 |
| 44 | 11,836,862 |
| 45 | 11,932,998 |
| 50 | 669,453,337 |
| 60 | 1,022,120,956 |

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

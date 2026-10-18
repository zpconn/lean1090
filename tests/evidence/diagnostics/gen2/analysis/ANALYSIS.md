# Generation 2 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 22,025,459,190 | True |
| commb | 47,546,252,015 | True |
| other | 3,973,517,283 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 14,112,285,757 | 64.0726% |
| semantic_oracle_values | 6,071,674,767 | 27.5666% |
| adsb_fields | 1,829,052,210 | 8.3043% |
| output_model_control | 11,438,756 | 0.0519% |
| commb_inference | 1,007,700 | 0.0046% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 20,411,226,541 | 42.9292% |
| frame_crc | 16,617,744,288 | 34.9507% |
| semantic_oracle_values | 10,499,226,199 | 22.0821% |
| output_model_control | 17,577,847 | 0.0370% |
| adsb_fields | 477,140 | 0.0010% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 3,811,471,406 | 95.9219% |
| semantic_oracle_values | 145,560,806 | 3.6633% |
| output_model_control | 14,255,081 | 0.3588% |
| commb_inference | 1,486,660 | 0.0374% |
| adsb_fields | 743,330 | 0.0187% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 1,497,049,545 |
| 44 | 0 |
| 45 | 0 |
| 50 | 2,606,871,703 |
| 60 | 4,276,991,621 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 3,154,863,445 |
| 44 | 154,393,343 |
| 45 | 146,497,929 |
| 50 | 3,384,175,321 |
| 60 | 6,315,491,514 |

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

# Generation 0 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 31,700,655,805 | True |
| commb | 88,431,524,379 | True |
| other | 10,810,492,788 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 23,788,096,198 | 75.0398% |
| semantic_oracle_values | 6,071,659,962 | 19.1531% |
| adsb_fields | 1,829,052,295 | 5.7698% |
| output_model_control | 11,847,350 | 0.0374% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 49,856,067,626 | 56.3782% |
| frame_crc | 27,907,684,178 | 31.5585% |
| semantic_oracle_values | 10,648,646,490 | 12.0417% |
| output_model_control | 18,648,945 | 0.0211% |
| adsb_fields | 477,140 | 0.0005% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 10,649,339,265 | 98.5093% |
| semantic_oracle_values | 145,560,251 | 1.3465% |
| output_model_control | 14,849,942 | 0.1374% |
| adsb_fields | 743,330 | 0.0069% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 10,655,164,905 |
| 44 | 0 |
| 45 | 0 |
| 50 | 8,825,831,299 |
| 60 | 18,530,767,712 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 12,313,662,763 |
| 44 | 154,393,343 |
| 45 | 146,497,929 |
| 50 | 9,603,117,158 |
| 60 | 20,567,665,916 |

## Attribution limits

- Ir counts instrumented guest instructions, not elapsed time, cycles, cache misses or throughput.
- Stage attribution includes each stage's allocation and runtime helpers; construction is not a global allocation-only category.
- Output-model/control contains final report/message/list assembly plus residual control; instruction-level allocation/control separation is unavailable.
- Generic register arguments are absent from the call graph. Separate score probes overlap Comm-B inference and must not be added to whole-decoder counts.
- Callgrind context merges, if present, remain explicitly shared/ambiguous.
- Register probes are standalone executions of actual reached score gates; allocator/context state may differ from the whole decoder.
- Native entry counts describe retained symbols; inlining/tail-call elimination can remove entries without removing the computation. Census predictions are reported separately.
- These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the three-warmup benchmark; no unmeasured correction is applied.

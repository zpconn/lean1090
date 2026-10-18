# Generation 1 diagnostic instruction counts

**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.

| Profile | Guest instructions (Ir) | Complete stage attribution |
|---|---:|---|
| adsb | 22,024,838,792 | True |
| commb | 77,140,852,912 | True |
| other | 3,972,627,047 | True |

## adsb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 14,112,285,957 | 64.0744% |
| semantic_oracle_values | 6,071,656,374 | 27.5673% |
| adsb_fields | 1,829,052,295 | 8.3045% |
| output_model_control | 11,844,166 | 0.0538% |

## commb

| Exclusive stage | Ir | Share |
|---|---:|---:|
| commb_inference | 49,856,076,161 | 64.6299% |
| frame_crc | 16,617,012,946 | 21.5411% |
| semantic_oracle_values | 10,648,638,306 | 13.8041% |
| output_model_control | 18,648,359 | 0.0242% |
| adsb_fields | 477,140 | 0.0006% |

## other

| Exclusive stage | Ir | Share |
|---|---:|---:|
| frame_crc | 3,811,472,836 | 95.9434% |
| semantic_oracle_values | 145,559,633 | 3.6641% |
| output_model_control | 14,851,248 | 0.3738% |
| adsb_fields | 743,330 | 0.0187% |

## Supplemental register score probes

These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.

| Register | Live score-gate Ir |
|---|---:|
| 40 | 10,655,165,733 |
| 44 | 0 |
| 45 | 0 |
| 50 | 8,825,831,299 |
| 60 | 18,530,774,853 |

## Supplemental complete candidate-predicate probes

These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.

| Register | Live candidate-predicate Ir |
|---|---:|
| 40 | 12,313,662,587 |
| 44 | 154,393,343 |
| 45 | 146,497,929 |
| 50 | 9,603,110,920 |
| 60 | 20,567,659,678 |

## Attribution limits

- Ir counts instrumented guest instructions, not elapsed time, cycles, cache misses or throughput.
- Stage attribution includes each stage's allocation and runtime helpers; construction is not a global allocation-only category.
- Output-model/control contains final report/message/list assembly plus residual control; instruction-level allocation/control separation is unavailable.
- Generic register arguments are absent from the call graph. Separate score probes overlap Comm-B inference and must not be added to whole-decoder counts.
- Callgrind context merges, if present, remain explicitly shared/ambiguous.
- Register probes are standalone executions of actual reached score gates; allocator/context state may differ from the whole decoder.
- Native entry counts describe retained symbols; inlining/tail-call elimination can remove entries without removing the computation. Census predictions are reported separately.
- These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the three-warmup benchmark; no unmeasured correction is applied.

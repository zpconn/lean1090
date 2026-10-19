Generation 12 converts byte lists of length at most eight with a UInt64 fold. Lengths nine through sixteen use a tail-recursive eight-byte prefix reader, one suffix word fold and one final Nat shift/add; longer lists retain the original arbitrary-precision fold. The public equality is proved for every byte list. Actual word folds inline into bytesValue; the prefix helper remains a native boundary and creates its box/pair only at its endpoint, without a pair per byte. [Source/native review](../tests/evidence/diagnostics/gen12/source-review.json) retains the fresh timed-worker C and assembly. Missing standalone word-fold symbols do not mean zero byte processing.

The Frame and Message Lean sources are unchanged, but Lean changed list ownership conventions after bytesValue began consuming its input. The retained native review accounts for removed borrowing wrappers and moved reference-count decrements. Other production paths, including the UInt32 CRC loop, remain as verified in generation 11. The unchanged stage rule classifies actual call contexts; bookkeeping can move between callers, so small stage deltas must be read with these ownership changes in mind.

The diagnostic checkout and original timed generation-12 commit are both `0592f80708c92e283a4c802f04b5889d5d69a3aa`. The driver reuses all production objects from the exact 22-set fresh benchmark inventory, with unchanged source/C/object/trace and binary hashes. No historical attribution remapping is needed for this generation. The benchmark remains a separate measurement; these counters are not throughput samples.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach and QNH tables remain initialized before main. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 271 samples, 74 have a visible decoder ancestor and 197 are excluded; 264 stacks contain an unknown frame and 0 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen12/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen12/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 553,010,678 |
| candidate44 | 47,166 | 0 | 0 | 0 | 48,343,346 |
| candidate45 | 47,166 | 0 | 0 | 0 | 48,439,482 |
| candidate50 | 47,166 | 10,641 | 2,170,766 | 1,066,037,418 | 1,670,816,929 |
| candidate60 | 47,166 | 19,356 | 2,708,246 | 844,659,720 | 1,565,513,808 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,703,169 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 2,170,766 | 1,066,162,352 | 1,427,606,176 |
| score60 | 19,356 | 19,356 | 2,708,246 | 844,670,323 | 1,374,241,413 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen12/penalty-probe-costs.json).


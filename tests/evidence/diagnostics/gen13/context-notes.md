Generation 13 replaces only the BDS50 wind penalty with an exact immutable 2,047-entry table keyed by the signed difference of two ten-bit field codes. The entry retains the original software binary64 rounding, absolute value, division by 100 and subtraction from zero; both status checks and the separate turn penalty remain. The equality is proved for every Nat word, including missing statuses and words beyond the message width. [Source/native review](../tests/evidence/diagnostics/gen13/source-review.json) retains the fresh timed-worker C and actual lookup/initializer assembly.

The complete table is created and marked persistent during module initialization, before main and before collection. The live cbWindPenalty50 helper checks statuses, extracts the two field codes and reads one table entry; both fast inference and the full software fallback use the same cbPenalty path. The final BDS50 turn subtraction and BDS60 IAS/Mach division remain live software operations. No table is keyed by a message or corpus item. All other production source/C/object/trace sets are unchanged from generation 12, as recorded by the source review.

The diagnostic checkout and original timed generation-13 commit are both `247a28d9a681fd5fac37a630cc4a889e30000490`. The driver reuses all production objects from the exact 22-set fresh benchmark inventory, with unchanged source/C/object/trace and binary hashes. No historical attribution remapping is needed for this generation. The benchmark remains a separate measurement; these counters are not throughput samples.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach, QNH and wind-penalty tables initialize before main. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 267 samples, 61 have a visible decoder ancestor and 206 are excluded; 259 stacks contain an unknown frame and 0 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen13/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen13/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 418,851 | 418,851 | 552,992,926 |
| candidate44 | 47,166 | 0 | 0 | 0 | 48,343,346 |
| candidate45 | 47,166 | 0 | 0 | 0 | 48,439,482 |
| candidate50 | 47,166 | 10,641 | 1,330,500 | 151,277,418 | 754,768,813 |
| candidate60 | 47,166 | 19,356 | 2,705,971 | 844,657,445 | 1,565,606,103 |
| score40 | 15,513 | 15,513 | 418,851 | 418,851 | 381,812,591 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,330,500 | 151,263,905 | 511,431,968 |
| score60 | 19,356 | 19,356 | 2,705,971 | 844,668,048 | 1,374,212,137 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen13/penalty-probe-costs.json).

The new live wind lookup and eager table construction are distinguished explicitly:

| Profile | Expected lookup calls | Observed lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Entry construction inside root |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 |
| commb | 10,641 | 10,641 | 678,708 | 3,048,948 | 0 |
| other | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 10,641 | 10,641 | 678,708 | 3,048,948 | 0 |
| candidate60 | 0 | 0 | 0 | 0 | 0 |
| score40 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 678,708 | 3,048,948 | 0 |
| score60 | 0 | 0 | 0 | 0 | 0 |

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen13/wind-native-counts.json).


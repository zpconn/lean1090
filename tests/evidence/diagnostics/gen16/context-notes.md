Generation 16 changes only the general packFields fold: concatenate using an unbounded Nat shift, mask the low UInt64 word for field widths below 64, and retain the original Nat modulus for wider fields. The all-list proof has no layout, accumulator or value bound. [Source/native review](../tests/evidence/diagnostics/gen16/independent-review/source-review.json) retains the actual narrow/wide branches and unchanged caller path. Instruction observations below compare this live implementation with generation 15; no speedup is inferred from instruction differences.

The current checkout contains the committed generation-16 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach, QNH and wind-penalty tables initialize before main. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 242 samples, 56 have a visible decoder ancestor and 186 are excluded; 227 stacks contain an unknown frame and 0 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen16/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen16/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 516,613,068 |
| candidate44 | 47,166 | 0 | 0 | 0 | 11,836,862 |
| candidate45 | 47,166 | 0 | 0 | 0 | 11,932,998 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 151,247,122 | 718,239,786 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 369,716,953 | 1,054,249,580 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,827,703 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 151,233,609 | 511,281,969 |
| score60 | 19,356 | 19,356 | 2,429,938 | 369,872,384 | 899,588,650 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen16/penalty-probe-costs.json).

The retained live wind lookup and eager table construction are distinguished explicitly:

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

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen16/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,064,887 | 242,334 |
| other | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate60 | 17,394 | 17,386 | 8 | 4,593,636 | 158,990,130 | 242,415 |
| score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| score50 | 0 | 0 | 0 | 0 | 0 | 0 |
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,568,375 | 242,664 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen16/ratio-native-contexts.json) also records generation 15 and 16 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.

The live Comm-B guard and its direct decimal-parser calls:

| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |
|---|---|---:|---:|---:|---:|---:|
| 15 | adsb | 0 | 0 | 0 | 0 | 0 |
| 15 | commb | 627,880 | 18,451,163 | 1,248,051,689 | 0 | 0 |
| 15 | other | 0 | 0 | 0 | 0 | 0 |
| 15 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 15 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 15 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 15 | candidate50 | 47,166 | 1,273,482 | 198,776,429 | 0 | 0 |
| 15 | candidate60 | 47,166 | 1,367,814 | 145,276,019 | 0 | 0 |
| 15 | score40 | 0 | 0 | 0 | 0 | 0 |
| 15 | score44 | 0 | 0 | 0 | 0 | 0 |
| 15 | score45 | 0 | 0 | 0 | 0 | 0 |
| 15 | score50 | 0 | 0 | 0 | 0 | 0 |
| 15 | score60 | 0 | 0 | 0 | 0 | 0 |
| 16 | adsb | 0 | 0 | 0 | 0 | 0 |
| 16 | commb | 627,880 | 18,451,163 | 1,248,053,404 | 0 | 0 |
| 16 | other | 0 | 0 | 0 | 0 | 0 |
| 16 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 16 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 16 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 16 | candidate50 | 47,166 | 1,273,482 | 198,776,429 | 0 | 0 |
| 16 | candidate60 | 47,166 | 1,367,814 | 145,276,019 | 0 | 0 |
| 16 | score40 | 0 | 0 | 0 | 0 | 0 |
| 16 | score44 | 0 | 0 | 0 | 0 | 0 |
| 16 | score45 | 0 | 0 | 0 | 0 | 0 |
| 16 | score50 | 0 | 0 | 0 | 0 | 0 |
| 16 | score60 | 0 | 0 | 0 | 0 | 0 |

These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen16/constant-native-contexts.json).

The live general packing fold and its observed direct native calls:

| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |
|---|---:|---:|---:|---|---:|---:|
| 15 | 172,432 | 52,319,321 | 1,280,682,876 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 15 | 172,432 | 52,319,321 | 1,280,682,876 | `lean_nat_big_add` | 100,793 | 151,720,476 |
| 15 | 172,432 | 52,319,321 | 1,280,682,876 | `lean_nat_overflow_mul` | 100,793 | 176,387,439 |
| 15 | 172,432 | 52,319,321 | 1,280,682,876 | `lean_nat_pow` | 881,619 | 882,818,451 |
| 16 | 172,432 | 38,791,098 | 815,959,275 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 16 | 172,432 | 38,791,098 | 815,959,275 | `lean_nat_big_add` | 100,793 | 151,720,534 |
| 16 | 172,432 | 38,791,098 | 815,959,275 | `lean_nat_shiftl` | 881,619 | 608,010,454 |

Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The generic power/modulus branch remains in the actual binary for widths at least 64, even if the corpus has no observed calls. [Exact packing contexts](../tests/evidence/diagnostics/gen16/pack-fields-direct-costs.json).


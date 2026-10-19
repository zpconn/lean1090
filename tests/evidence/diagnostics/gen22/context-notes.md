Generation 22 reuses the raw word returned by decodeFrameWithWord for CRC, avoiding frame information-bit reconstruction and a second byte-value parse. The public parser remains a projection of the same live helper. Unconditional parser and syndrome equalities preserve arbitrary inputs and the complete decoder refinement. [Current source/native review](../tests/evidence/diagnostics/gen22/independent-review/source-review.json) binds the actual paired-parser call, direct syndrome, retained report/acceptance sharing and unchanged semantic normalization. This report collects actual Impl.decode only; the separate CPR diagnostic covers tracking and numeric geography. Comparisons with generation 21 are instruction observations, not throughput predictions or inferred path distributions.

The current checkout contains the committed generation-22 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.

The live UInt32 byte loop and generic bit-loop fallback, syndrome, paired parser, byte-value fold and frame field extractor are retained as explicit nested anchors. Historical checksum/frameSyndrome/packing boundaries are absent in the current timed worker; current source/native evidence establishes direct word use, rather than inferring absent work solely from symbols. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed byte loop has one entry per syndrome in this accepted corpus. Its byte-iteration count is predicted from frame widths, and each byte performs eight inlined updates. The callable bit-loop fallback has no observed entries here; it remains live for other widths. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 212 samples, 38 have a visible decoder ancestor and 174 are excluded; 207 stacks contain an unknown frame and 0 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen22/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

CRC wrapper and loop entries reconcile with the separately checked accepted-corpus census:

| Profile | Predicted CRC calls | Observed byte wrapper / loop | Observed bit wrapper / loop | Predicted byte iterations | Predicted bit updates |
|---|---:|---:|---:|---:|---:|
| adsb | 50,385 | 50,385 / 50,385 | 0 / 0 | 705,390 | 5,643,120 |
| commb | 47,714 | 47,714 / 47,714 | 0 / 0 | 667,996 | 5,343,968 |
| other | 74,333 | 74,333 / 74,333 | 0 / 0 | 539,189 | 4,313,512 |
| candidate40 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate44 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate45 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate50 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| candidate60 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score40 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score44 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score45 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score50 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |
| score60 | 0 | 0 / 0 | 0 / 0 | 0 | 0 |

Observed entries are incoming native calls; iteration predictions are separate mathematical census data. All ten overlapping register probes are checked separately. The generic fallback remains callable and proved for arbitrary inputs; its zero accepted-corpus count does not remove its implementation or cost for unseen widths. Byte extraction and eight updates inline into the actual loop, which still contains natural-index and ownership work. [CRC boundary and direct-child evidence](../tests/evidence/diagnostics/gen22/crc-byte-contexts.json) compares both generations without copying old profiles or inferring elapsed time.

| Generation | CRC boundary | Native entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| 21 | `Parity_checksum` | 172,432 | 5,849,357 | 748,151,605 |
| 21 | `Parity_syndrome` | 172,432 | 4,310,800 | 587,967,775 |
| 21 | `Parity_syndromeBytes` | 172,432 | 6,295,014 | 583,656,975 |
| 21 | `decodeFrame` | 172,432 | 22,561,399 | 1,107,313,743 |
| 21 | `frameSyndrome` | 172,432 | 11,871,146 | 1,768,092,701 |
| 21 | `packFields` | 172,432 | 517,296 | 816,467,903 |
| 21 | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |
| 22 | `Parity_syndrome` | 172,432 | 4,310,800 | 588,137,357 |
| 22 | `Parity_syndromeBytes` | 172,432 | 6,295,014 | 583,826,557 |
| 22 | `decodeFrameWithWord` | 172,432 | 22,342,047 | 1,094,474,480 |
| 22 | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |

These nested inclusive rows overlap each other and frame/CRC stage cost. Only the exclusive stage partition can be added.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen22/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 516,543,584 |
| candidate44 | 47,166 | 0 | 0 | 0 | 11,836,862 |
| candidate45 | 47,166 | 0 | 0 | 0 | 11,932,998 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 106,495,942 | 669,457,054 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 339,955,197 | 1,022,125,226 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,790,858 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 106,524,982 | 466,550,576 |
| score60 | 19,356 | 19,356 | 2,429,938 | 339,960,538 | 869,793,865 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen22/penalty-probe-costs.json).

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

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen22/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,456,446 | 187,445 |
| other | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate60 | 17,394 | 17,386 | 8 | 4,593,636 | 158,972,950 | 187,607 |
| score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| score50 | 0 | 0 | 0 | 0 | 0 | 0 |
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,353,702 | 187,688 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen22/ratio-native-contexts.json) also records generation 21 and 22 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.

The live Comm-B guard and its direct decimal-parser calls:

| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |
|---|---|---:|---:|---:|---:|---:|
| 21 | adsb | 0 | 0 | 0 | 0 | 0 |
| 21 | commb | 627,880 | 18,451,163 | 998,010,921 | 0 | 0 |
| 21 | other | 0 | 0 | 0 | 0 | 0 |
| 21 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 21 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 21 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 21 | candidate50 | 47,166 | 1,273,482 | 194,881,645 | 0 | 0 |
| 21 | candidate60 | 47,166 | 1,367,814 | 143,006,297 | 0 | 0 |
| 21 | score40 | 0 | 0 | 0 | 0 | 0 |
| 21 | score44 | 0 | 0 | 0 | 0 | 0 |
| 21 | score45 | 0 | 0 | 0 | 0 | 0 |
| 21 | score50 | 0 | 0 | 0 | 0 | 0 |
| 21 | score60 | 0 | 0 | 0 | 0 | 0 |
| 22 | adsb | 0 | 0 | 0 | 0 | 0 |
| 22 | commb | 627,880 | 18,451,163 | 999,646,182 | 0 | 0 |
| 22 | other | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate40 | 47,166 | 1,273,482 | 128,357,469 | 0 | 0 |
| 22 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 22 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 22 | candidate50 | 47,166 | 1,273,482 | 194,872,662 | 0 | 0 |
| 22 | candidate60 | 47,166 | 1,367,814 | 143,006,297 | 0 | 0 |
| 22 | score40 | 0 | 0 | 0 | 0 | 0 |
| 22 | score44 | 0 | 0 | 0 | 0 | 0 |
| 22 | score45 | 0 | 0 | 0 | 0 | 0 |
| 22 | score50 | 0 | 0 | 0 | 0 | 0 |
| 22 | score60 | 0 | 0 | 0 | 0 | 0 |

These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen22/constant-native-contexts.json).

The historical packing fold and current absence of collected entries:

| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |
|---|---:|---:|---:|---|---:|---:|
| 21 | 172,432 | 38,791,098 | 815,950,607 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 21 | 172,432 | 38,791,098 | 815,950,607 | `lean_nat_big_add` | 100,793 | 151,713,942 |
| 21 | 172,432 | 38,791,098 | 815,950,607 | `lean_nat_shiftl` | 881,619 | 608,008,378 |

Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The standalone packing source and generated-C definition retain generic power/modulus behavior, while the current timed decoder does not link or call that fold. The zero current incoming count is checked alongside the explicit raw-word path, not treated as an independent no-work proof. [Exact packing contexts](../tests/evidence/diagnostics/gen22/pack-fields-direct-costs.json).

The live power-of-two lookup, formula fallback and startup construction:

| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |
|---|---|---:|---:|---:|---:|---:|---:|
| 21 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 21 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 21 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 21 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 21 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 21 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 21 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 21 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 21 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 21 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 21 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 21 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 21 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 22 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 22 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 22 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 22 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 22 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |

These are actual retained incoming boundaries and direct lookup-to-formula edges. Both generations retain the same immutable format-exponent table. In the current worker, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen22/power-native-contexts.json).

The four optimized extraction paths, compared at actual retained native boundaries:

| Generation | Stage | Native boundary | Entries | Self Ir | Incoming inclusive Ir | Direct pow calls | Direct pow inclusive Ir |
|---|---|---|---:|---:|---:|---:|---:|
| 21 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 21 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 21 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 7,989,646 | 0 | 0 |
| 21 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 104,100,113 | 0 | 0 |
| 21 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 21 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 21 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 314,431,360 | 0 | 0 |
| 21 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |
| 22 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 22 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 22 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 8,183,432 | 0 | 0 |
| 22 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 104,100,113 | 0 | 0 |
| 22 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 22 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 22 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 314,418,869 | 0 | 0 |
| 22 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |

Both generations inline the identity lambda into identityCode; missing standalone rows do not erase the live extraction. Other small arithmetic can inline too. Native entry populations across these changed boundaries are not assumed equal. The current direct-power count is zero only for these selected caller boundaries, consistent with the checked shift/mask implementation; it is not a zero-work claim or a claim about all decoder powers. Incoming inclusive columns overlap stage totals and other helpers. [Exact old/new contexts and direct children](../tests/evidence/diagnostics/gen22/bit-extraction-contexts.json) bind both raw profile sets without copying them or predicting timing.

The exact affine helper is compared at surviving native boundaries:

| Generation | Stage | Boundary | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---|---:|---:|---:|
| 21 | commb_inference | `l_Rat_mul` | 101,573 | 20,661,829 | 373,000,317 |
| 21 | commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,038,837 |
| 21 | semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,064,881 |
| 21 | semantic_oracle_values | `payloadValue` | 1,520,847 | 169,626,425 | 1,271,361,370 |
| 22 | commb_inference | `l_Rat_mul` | 101,573 | 20,661,829 | 373,016,854 |
| 22 | commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,026,783 |
| 22 | semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,078,124 |
| 22 | semantic_oracle_values | `payloadValue` | 1,520,847 | 169,626,425 | 1,271,877,672 |

The payloadValue entry populations are independently checked equal by stage across these two profiles. Inline integerScale/affineValue calls have no standalone native entry count. The current source and all-input proof establish normalization and preserved guards; actual direct children below show the observed arithmetic boundaries.

| Generation | Stage | Direct child of payloadValue | Calls | Inclusive Ir |
|---|---|---|---:|---:|
| 21 | commb_inference | `l_Rat_ofInt` | 17,406 | 520,046 |
| 21 | commb_inference | `l_instDecidableEqRat_decEq` | 112,144 | 2,851,898 |
| 21 | commb_inference | `lean_alloc_small_object_core` | 94,738 | 1,928,069 |
| 21 | commb_inference | `lean_nat_gcd` | 38,666 | 57,771,127 |
| 21 | commb_inference | `lean_obj_once_cold` | 2 | 576 |
| 21 | commb_inference | `payloadBits` | 114,116 | 6,846,960 |
| 21 | commb_inference | `payloadInteger` | 56,072 | 30,039,508 |
| 21 | semantic_oracle_values | `l_Rat_add` | 31,026 | 53,499,445 |
| 21 | semantic_oracle_values | `l_Rat_ofInt` | 1,181,731 | 40,913,873 |
| 21 | semantic_oracle_values | `l_instDecidableEqRat_decEq` | 3,012,732 | 76,694,274 |
| 21 | semantic_oracle_values | `lean_alloc_small_object_core` | 1,831,001 | 44,193,825 |
| 21 | semantic_oracle_values | `lean_dec_ref_cold` | 39,433 | 4,101,032 |
| 21 | semantic_oracle_values | `lean_nat_gcd` | 324,635 | 489,703,895 |
| 21 | semantic_oracle_values | `lean_obj_once_cold` | 2 | 576 |
| 21 | semantic_oracle_values | `payloadBits` | 1,896,730 | 113,803,800 |
| 21 | semantic_oracle_values | `payloadInteger` | 1,506,366 | 278,824,225 |
| 22 | commb_inference | `l_Rat_ofInt` | 17,406 | 511,906 |
| 22 | commb_inference | `l_instDecidableEqRat_decEq` | 112,144 | 2,851,898 |
| 22 | commb_inference | `lean_alloc_small_object_core` | 94,738 | 1,924,155 |
| 22 | commb_inference | `lean_nat_gcd` | 38,666 | 57,771,127 |
| 22 | commb_inference | `lean_obj_once_cold` | 2 | 576 |
| 22 | commb_inference | `payloadBits` | 114,116 | 6,846,960 |
| 22 | commb_inference | `payloadInteger` | 56,072 | 30,039,508 |
| 22 | semantic_oracle_values | `l_Rat_add` | 31,026 | 53,464,902 |
| 22 | semantic_oracle_values | `l_Rat_ofInt` | 1,181,731 | 41,329,909 |
| 22 | semantic_oracle_values | `l_instDecidableEqRat_decEq` | 3,012,732 | 76,694,274 |
| 22 | semantic_oracle_values | `lean_alloc_small_object_core` | 1,831,001 | 44,341,125 |
| 22 | semantic_oracle_values | `lean_dec_ref_cold` | 39,433 | 4,101,032 |
| 22 | semantic_oracle_values | `lean_nat_gcd` | 324,635 | 489,703,895 |
| 22 | semantic_oracle_values | `lean_obj_once_cold` | 2 | 576 |
| 22 | semantic_oracle_values | `payloadBits` | 1,896,730 | 113,803,800 |
| 22 | semantic_oracle_values | `payloadInteger` | 1,506,366 | 278,811,734 |

These are overlapping incoming/direct-edge observations, not exclusive savings. Zero current direct Rat.mul calls concern only the listed payloadValue contexts: normalization still performs a numerator product, gcd and exact divisions, with small-value operations possibly inlined. Child calls do not count every nonunit input or logical operation. [Exact affine contexts](../tests/evidence/diagnostics/gen22/affine-native-contexts.json) retain both profile hashes and group reconciliation.

Selected actual nested helpers for prioritization:

| Stage | Native helper | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| commb_inference | `ScoreGate_choose` | 45,510 | 19,248,889 | 1,233,185,886 |
| commb_inference | `bdsWireValid` | 627,880 | 18,451,163 | 999,646,182 |
| commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,408,765 |
| commb_inference | `l_Rat_mul` | 101,573 | 20,661,829 | 373,016,854 |
| commb_inference | `cbValid50` | 56,979 | 4,940,566 | 284,172,699 |
| commb_inference | `cbValid60` | 64,315 | 4,012,830 | 260,847,884 |
| commb_inference | `cbValid40` | 62,679 | 4,396,089 | 245,938,829 |
| commb_inference | `l_Rat_div` | 48,323 | 386,584 | 226,435,653 |
| commb_inference | `cbValid21` | 47,854 | 3,200,897 | 110,310,474 |
| commb_inference | `payloadValue` | 58,044 | 9,080,653 | 109,026,783 |
| commb_inference | `ScoreGate_commonDenominator` | 45,510 | 5,882,374 | 43,875,426 |
| commb_inference | `cbValid18` | 47,171 | 613,237 | 19,856,066 |
| commb_inference | `cbValid19` | 47,166 | 235,830 | 14,192,349 |
| commb_inference | `cbValid17` | 47,498 | 1,210,360 | 5,759,260 |
| commb_inference | `cbValid44` | 47,166 | 1,051,620 | 4,195,970 |
| commb_inference | `cbValid45` | 47,166 | 943,320 | 3,773,280 |
| frame_crc | `decodeFrameWithWord` | 172,432 | 22,342,047 | 1,094,474,480 |
| frame_crc | `Parity_syndrome` | 172,432 | 4,310,800 | 588,137,357 |
| frame_crc | `field` | 881,619 | 56,178,834 | 564,513,100 |
| frame_crc | `bytesValue` | 172,432 | 31,171,820 | 454,174,837 |
| frame_crc | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndromeBytes_spec__0___redArg` | 172,432 | 253,425,345 | 253,425,345 |
| output_model_control | `reportWithSyndrome` | 172,432 | 15,247,428 | 5,537,992,337 |
| semantic_oracle_values | `Semantics_commB` | 46,440 | 5,170,793 | 1,693,875,263 |
| semantic_oracle_values | `payloadValue` | 1,520,847 | 169,626,425 | 1,271,877,672 |
| semantic_oracle_values | `Semantics_adsb` | 51,212 | 4,166,624 | 500,643,342 |
| semantic_oracle_values | `l_Rat_mul` | 37,882 | 7,725,171 | 122,078,124 |
| semantic_oracle_values | `l_Rat_add` | 56,229 | 8,095,837 | 95,191,827 |
| semantic_oracle_values | `l_Rat_div` | 4,508 | 36,064 | 14,732,922 |

These rows aggregate only the three disjoint family profiles. Incoming inclusive observations overlap each other and stage totals, including recursive visits and descendants crossing a stage boundary. Direct native children and exact caller contexts are retained in [priority-helper-contexts.json](../tests/evidence/diagnostics/gen22/priority-helper-contexts.json). Rat multiplication rows do not count every logical affine operation; inline work remains in callers. These observations do not select an optimization or infer throughput.


Generation 19 replaces power-of-two divisions and construction with exact natural shifts and masks in Altitude.bit, Altitude.grayDecode, identityCode and payloadInteger. Unconditional proofs preserve every natural word, index and width, including over-wide values; no input is narrowed to a machine word. [Current source/native review](../tests/evidence/diagnostics/gen19/independent-review/source-review.json) binds the freshly timed worker and all four live optimized paths, including caller inlining. This report collects actual Impl.decode only; the separate CPR diagnostic covers tracking and numeric geography. Comparisons with generation 18 below are instruction observations, not throughput predictions or inferred path hit rates.

The current checkout contains the committed generation-19 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.

The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.

One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.

All immutable density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.

Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of 231 samples, 81 have a visible decoder ancestor and 150 are excluded; 228 stacks contain an unknown frame and 7 included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen19/perf/README.md).

The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.

Byte-helper native entries reconcile with the separately checked corpus lengths:

| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |
|---|---:|---:|---:|---:|---:|
| adsb | 0 | 50,385 | 50,385 | 50,385 | 0 |
| commb | 0 | 47,714 | 47,714 | 47,714 | 0 |
| other | 71,639 | 2,694 | 74,333 | 2,694 | 0 |

These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen19/byte-native-counts.json).

The live `cbPenalty` boundary in each supplemental register probe:

| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |
|---|---:|---:|---:|---:|---:|---:|
| candidate40 | 47,166 | 15,513 | 434,364 | 434,364 | 516,578,979 |
| candidate44 | 47,166 | 0 | 0 | 0 | 11,836,862 |
| candidate45 | 47,166 | 0 | 0 | 0 | 11,932,998 |
| candidate50 | 47,166 | 10,641 | 1,300,204 | 142,764,389 | 705,803,397 |
| candidate60 | 47,166 | 19,356 | 2,429,938 | 369,662,237 | 1,051,894,229 |
| score40 | 15,513 | 15,513 | 434,364 | 434,364 | 381,793,254 |
| score44 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 |
| score50 | 10,641 | 10,641 | 1,300,204 | 142,757,861 | 502,894,732 |
| score60 | 19,356 | 19,356 | 2,429,938 | 369,782,695 | 899,498,961 |

Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen19/penalty-probe-costs.json).

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

The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen19/wind-native-counts.json).

The BDS60 ratio enclosure and its observed software-round fallback:

| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |
|---|---:|---:|---:|---:|---:|---:|
| adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| commb | 17,394 | 17,386 | 8 | 4,593,636 | 159,012,104 | 187,526 |
| other | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate50 | 0 | 0 | 0 | 0 | 0 | 0 |
| candidate60 | 17,394 | 17,386 | 8 | 4,593,636 | 158,934,858 | 187,607 |
| score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| score50 | 0 | 0 | 0 | 0 | 0 | 0 |
| score60 | 17,394 | 17,386 | 8 | 4,593,636 | 159,478,686 | 187,688 |

These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen19/ratio-native-contexts.json) also records generation 18 and 19 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.

The live Comm-B guard and its direct decimal-parser calls:

| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |
|---|---|---:|---:|---:|---:|---:|
| 18 | adsb | 0 | 0 | 0 | 0 | 0 |
| 18 | commb | 627,880 | 18,451,163 | 1,248,057,210 | 0 | 0 |
| 18 | other | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 18 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 18 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 18 | candidate50 | 47,166 | 1,273,482 | 198,782,150 | 0 | 0 |
| 18 | candidate60 | 47,166 | 1,367,814 | 145,276,424 | 0 | 0 |
| 18 | score40 | 0 | 0 | 0 | 0 | 0 |
| 18 | score44 | 0 | 0 | 0 | 0 | 0 |
| 18 | score45 | 0 | 0 | 0 | 0 | 0 |
| 18 | score50 | 0 | 0 | 0 | 0 | 0 |
| 18 | score60 | 0 | 0 | 0 | 0 | 0 |
| 19 | adsb | 0 | 0 | 0 | 0 | 0 |
| 19 | commb | 627,880 | 18,451,163 | 998,087,774 | 0 | 0 |
| 19 | other | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate40 | 47,166 | 1,273,482 | 128,357,682 | 0 | 0 |
| 19 | candidate44 | 47,166 | 1,273,482 | 5,469,452 | 0 | 0 |
| 19 | candidate45 | 47,166 | 1,273,482 | 5,046,762 | 0 | 0 |
| 19 | candidate50 | 47,166 | 1,273,482 | 194,858,282 | 0 | 0 |
| 19 | candidate60 | 47,166 | 1,367,814 | 143,011,400 | 0 | 0 |
| 19 | score40 | 0 | 0 | 0 | 0 | 0 |
| 19 | score44 | 0 | 0 | 0 | 0 | 0 |
| 19 | score45 | 0 | 0 | 0 | 0 | 0 |
| 19 | score50 | 0 | 0 | 0 | 0 | 0 |
| 19 | score60 | 0 | 0 | 0 | 0 | 0 |

These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen19/constant-native-contexts.json).

The live general packing fold and its observed direct native calls:

| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |
|---|---:|---:|---:|---|---:|---:|
| 18 | 172,432 | 38,791,098 | 815,961,212 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 18 | 172,432 | 38,791,098 | 815,961,212 | `lean_nat_big_add` | 100,793 | 151,727,780 |
| 18 | 172,432 | 38,791,098 | 815,961,212 | `lean_nat_shiftl` | 881,619 | 608,005,145 |
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_dec_ref_cold` | 100,793 | 17,437,189 |
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_nat_big_add` | 100,793 | 151,727,950 |
| 19 | 172,432 | 38,791,098 | 815,961,386 | `lean_nat_shiftl` | 881,619 | 608,005,149 |

Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The generic power/modulus branch remains in the actual binary for widths at least 64, even if the corpus has no observed calls. [Exact packing contexts](../tests/evidence/diagnostics/gen19/pack-fields-direct-costs.json).

The live power-of-two lookup, formula fallback and startup construction:

| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |
|---|---|---:|---:|---:|---:|---:|---:|
| 18 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 18 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 18 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 18 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 18 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 18 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 19 | adsb | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | commb | 1,324 | 90,032 | 116,512 | 0 | 0 | 0 |
| 19 | other | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | candidate50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 19 | candidate60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |
| 19 | score40 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 19 | score50 | 1,308 | 88,944 | 115,104 | 0 | 0 | 0 |
| 19 | score60 | 16 | 1,088 | 1,408 | 0 | 0 | 0 |

These are actual retained incoming boundaries and direct lookup-to-formula edges. Both generations retain the same immutable format-exponent table. In the current worker, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen19/power-native-contexts.json).

The four optimized extraction paths, compared at actual retained native boundaries:

| Generation | Stage | Native boundary | Entries | Self Ir | Incoming inclusive Ir | Direct pow calls | Direct pow inclusive Ir |
|---|---|---|---:|---:|---:|---:|---:|
| 18 | adsb_fields | `Altitude_bit` | 20,816 | 645,296 | 21,731,904 | 20,816 | 21,086,608 |
| 18 | commb_inference | `Altitude_bit` | 379,793 | 11,773,583 | 394,519,951 | 379,793 | 382,746,368 |
| 18 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 63,756,013 | 0 | 0 |
| 18 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 118,638,989 | 110,143 | 112,456,003 |
| 18 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 6,261,740 | 146,349,326 | 152,710 | 140,087,586 |
| 18 | semantic_oracle_values | `Altitude_bit` | 283,061 | 8,774,891 | 295,685,356 | 283,061 | 286,910,465 |
| 18 | semantic_oracle_values | `identityCode` | 21,257 | 5,654,362 | 264,628,393 | 0 | 0 |
| 18 | semantic_oracle_values | `identityCode___lam__0` | 255,084 | 7,907,604 | 258,974,031 | 255,084 | 251,066,427 |
| 18 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 349,329,881 | 264,274 | 269,838,674 |
| 18 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 83,780 | 1,891,422 | 1,998 | 1,807,642 |
| 19 | adsb_fields | `Altitude_bit` | 20,816 | 478,768 | 478,768 | 0 | 0 |
| 19 | commb_inference | `Altitude_bit` | 43,077 | 990,771 | 990,771 | 0 | 0 |
| 19 | commb_inference | `Altitude_grayDecode` | 10,668 | 266,700 | 7,994,377 | 0 | 0 |
| 19 | commb_inference | `payloadInteger` | 108,660 | 5,639,686 | 104,100,113 | 0 | 0 |
| 19 | commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 38,200 | 5,192,770 | 5,192,770 | 0 | 0 |
| 19 | semantic_oracle_values | `identityCode` | 21,257 | 7,057,324 | 7,057,324 | 0 | 0 |
| 19 | semantic_oracle_values | `payloadInteger` | 1,530,929 | 55,412,540 | 314,430,793 | 0 | 0 |
| 19 | semantic_oracle_values | `lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0` | 566 | 69,794 | 69,794 | 0 | 0 |

The current compiled identity lambda is inlined into identityCode; its old standalone row is absent while the live extraction remains. Other small arithmetic can inline too. Native entry populations across these changed boundaries are not assumed equal. The current direct-power count is zero only for these selected caller boundaries, consistent with the checked shift/mask implementation; it is not a zero-work claim or a claim about all decoder powers. Incoming inclusive columns overlap stage totals and other helpers. [Exact old/new contexts and direct children](../tests/evidence/diagnostics/gen19/bit-extraction-contexts.json) bind both raw profile sets without copying them or predicting timing.

Selected actual nested helpers for prioritization:

| Stage | Native helper | Entries | Self Ir | Incoming inclusive Ir |
|---|---|---:|---:|---:|
| commb_inference | `ScoreGate_choose` | 45,510 | 19,248,889 | 1,232,766,693 |
| commb_inference | `bdsWireValid` | 627,880 | 18,451,163 | 998,087,774 |
| commb_inference | `lp_lean1090_List_foldl___at___00Lean1090_Impl_ScoreGate_scaledTotals_spec__0` | 45,510 | 7,462,049 | 641,118,871 |
| commb_inference | `l_Rat_mul` | 140,239 | 28,557,789 | 497,099,378 |
| commb_inference | `cbValid50` | 56,979 | 4,940,566 | 284,208,053 |
| commb_inference | `cbValid60` | 64,315 | 4,012,830 | 260,865,912 |
| commb_inference | `cbValid40` | 62,679 | 4,396,089 | 246,013,259 |
| commb_inference | `l_Rat_div` | 48,323 | 386,584 | 226,414,310 |
| commb_inference | `payloadValue` | 58,044 | 6,143,488 | 175,075,933 |
| commb_inference | `cbValid21` | 47,854 | 3,200,897 | 108,985,571 |
| commb_inference | `ScoreGate_commonDenominator` | 45,510 | 5,882,374 | 43,809,985 |
| commb_inference | `cbValid18` | 47,171 | 613,237 | 19,856,066 |
| commb_inference | `cbValid19` | 47,166 | 235,830 | 14,192,349 |
| commb_inference | `cbValid17` | 47,498 | 1,210,360 | 5,759,260 |
| commb_inference | `cbValid44` | 47,166 | 1,051,620 | 4,195,970 |
| commb_inference | `cbValid45` | 47,166 | 943,320 | 3,773,280 |
| frame_crc | `frameSyndrome` | 172,432 | 11,871,146 | 2,299,432,084 |
| frame_crc | `Parity_checksum` | 172,432 | 5,849,357 | 1,279,410,019 |
| frame_crc | `Parity_syndrome` | 172,432 | 6,438,292 | 1,119,219,468 |
| frame_crc | `packFields` | 172,432 | 517,296 | 816,478,682 |
| frame_crc | `lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0` | 172,432 | 38,791,098 | 815,961,386 |
| frame_crc | `lp_lean1090___private_Init_Data_Nat_Fold_0__Nat_foldTR_loop___at___00Lean1090_Impl_Parity_syndrome_spec__0___redArg` | 172,432 | 788,844,560 | 788,844,560 |
| frame_crc | `field` | 881,619 | 56,178,834 | 564,514,596 |
| frame_crc | `bytesValue` | 172,432 | 31,171,820 | 454,119,785 |
| semantic_oracle_values | `payloadValue` | 1,520,847 | 150,316,030 | 1,833,147,825 |
| semantic_oracle_values | `l_Rat_mul` | 362,517 | 73,897,349 | 1,170,053,303 |
| semantic_oracle_values | `l_Rat_add` | 56,229 | 8,095,837 | 95,231,980 |
| semantic_oracle_values | `l_Rat_div` | 4,508 | 36,064 | 14,733,933 |

These rows aggregate only the three disjoint family profiles. Incoming inclusive observations overlap each other and stage totals, including recursive visits and descendants crossing a stage boundary. Direct native children and exact caller contexts are retained in [priority-helper-contexts.json](../tests/evidence/diagnostics/gen19/priority-helper-contexts.json). Rat multiplication rows do not count every logical affine operation; inline work remains in callers. These observations do not select an optimization or infer throughput.


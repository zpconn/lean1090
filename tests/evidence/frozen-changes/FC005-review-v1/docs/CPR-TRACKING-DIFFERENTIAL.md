# Stream CPR tracking differential

Executed 2026-10-17 with the pinned rs1090 commit `685dfaa34c5ab186c691bca3cfe2a22e12517d30`. The complete diagnostic run passes with **zero mismatches**; no omission in `Spec/CPRPolicy.lean` was found by these finite tests. No frozen file was changed for this work. Mandatory gate integration and freezing remain a proposed FC change pending user approval.

```sh
python3 scripts/check_tracking.py --diagnostic
```

| Population | Streams | Input messages | Resolved positions | Bit-identical resolved positions | Matching unresolved results |
| --- | ---: | ---: | ---: | ---: | ---: |
| corpus | 1 | 172,432 | 11,347 | 11,347 | 161,085 |
| synthetic | 417 | 5,748 | 5,028 | 5,028 | 720 |

All 178,180 per-message results meet the required absolute latitude/longitude tolerance of `1e-9` degrees. The observed maximum error is `0.0` degrees. All 16,375 resolved pairs are also bit-identical. The checker compares original row identities, routing, final shared reference and every aircraft's public position, altitude, airport and seen-BDS set; every comparison passes. Its complete mismatch JSONL is empty.

## What actually runs

`Tests/Tracking.lean` decodes each DF17/18 frame through the live `Impl.decode`, projects the actual decoded payload and oracle-compatible semantic altitude into `TimedReport`, and calls **`Impl.decodePositions` once on the complete ordered stream**. Its geography is the live `Impl.CPR.Policy.numericalGeography`, containing the actual local/global Float adapters and haversine boundary. The 6,903 airports are imported in original pinned data order, preserving each binary64 coordinate exactly as a rational. No tracking implementation is copied into the Lean adapter. Non-ADS-B or rejected frames remain present as unresolved rows, with routing checked separately.

`differential/tracking-oracle/src/main.rs` freshly builds against the pinned, clean rs1090 source and calls **`rs1090::decode::cpr::decode_positions`** on the complete stream. These batch outputs are the expected per-message results. A separate replay calls actual `decode_position` to collect branch observations and public final state. Every replay result is asserted bit-identical to the batch output before the trace is used. The trace calls the actual public CPR primitives and reproduces the source haversine operation order for policy observations; it does not substitute for the batch oracle.

Timestamps are parsed once to binary64 and transmitted as exact 64-bit encodings to both runners. The corpus contains all 172,432 original rows in original order, with their original timestamps and the 18-hex-character Beast prefix removed. No sorting, interpolation, pair deduplication or filtering of unresolved results occurs.

## Synthetic coverage

The recorded generator seed is `109005`. `scripts/generate_tracking.py` uses an independent exact rational CPR encoder (Sun, second edition, 2021, chapter 5 equations) and the frozen NL transition inventory, then constructs CRC-valid raw frames. It includes 200 worldwide random two-aircraft interleaved tracks plus explicit policy cases. The sample is uniform in latitude and longitude, not surface-area uniform. Deliberately out-of-domain raw latitude reconstructions test rejection paths.

The explicit cases cover: both parities and arrival orders; DF17/18 sharing one address; empty opposite slots; the representable neighbors and exact value of the 30-second pair and 180-second local windows; the strict 1800-second speed boundary; cross-parity early returns versus same-parity out-of-order cache replacement; replacement after rejected positions; non-position messages initializing timestamps and evidence; global rejection with local fallback; local reconstruction rejection; zero-duration motion and excessive-speed/jump rejection; both sides and an attainable exact value of the 1200-km/h decision; first surface reports without a reference, near an airport and away from airports; own-surface-reference success, distance failure and decode failure; own reference winning over a contradictory shared reference; shared fallback with an existing aircraft bypassing the first-surface airport check; stale/backward surface timestamps; and independent interleaved aircraft using a shared receiver reference.

Four concrete callback choices are tested: absent, always true, altitude below 1000 ft, and GNSS source plus time synchronization. Accepted callbacks initialize/update reference; false callbacks, rejected positions and surface messages leave it unchanged. This is not an exhaustive test of every possible caller-supplied callback.

The checker requires **59** branch observations to occur. All do; the table reports all63 observed labels, including the four additional aggregate outcome labels. Counts include corpus and synthetic input; the JSON report retains a separate complete table for each stream.

| Branch observation | Count |
| --- | ---: |
| `accepted_callback_false` | 13,094 |
| `accepted_callback_true` | 2,211 |
| `airborne` | 16,110 |
| `airborne_even` | 8,079 |
| `airborne_odd` | 8,031 |
| `cache_replace_accepted` | 15,305 |
| `cache_replace_failed` | 802 |
| `cache_unchanged_early_return` | 3 |
| `cross_parity_out_of_order` | 3 |
| `decode_rejected` | 2 |
| `df17` | 35,527 |
| `df18` | 20,603 |
| `distance_above_500` | 40 |
| `distance_below_500` | 14,824 |
| `global_rejected` | 246 |
| `global_success` | 15,206 |
| `jump_rejection` | 9 |
| `local_age_exact` | 1 |
| `local_age_inside` | 881 |
| `local_age_outside` | 19 |
| `local_attempt` | 262 |
| `local_no_previous_position` | 619 |
| `local_rejected` | 1 |
| `local_success` | 261 |
| `motion_pass` | 14,702 |
| `non_adsb` | 122,048 |
| `opposite_slot_empty` | 611 |
| `other_adsb` | 37,428 |
| `pair_even_then_odd` | 8,013 |
| `pair_gap_exact` | 11 |
| `pair_gap_inside` | 16,063 |
| `pair_gap_outside` | 33 |
| `pair_odd_then_even` | 7,439 |
| `reference_initialized` | 104 |
| `reference_unchanged` | 53,919 |
| `reference_updated` | 2,107 |
| `resolved` | 16,375 |
| `same_parity_out_of_order_replacement` | 1 |
| `speed_above_threshold` | 153 |
| `speed_below_threshold` | 14,678 |
| `speed_exact_threshold` | 1 |
| `speed_gap_exact` | 8 |
| `speed_gap_inside` | 14,855 |
| `speed_gap_outside` | 1 |
| `speed_rejection` | 153 |
| `speed_zero_dt` | 23 |
| `surface` | 2,592 |
| `surface_even` | 1,314 |
| `surface_existing_bypasses_airport` | 3 |
| `surface_first_far_from_airport` | 5 |
| `surface_first_near_airport` | 10 |
| `surface_has_previous` | 1,063 |
| `surface_no_shared_reference` | 1,516 |
| `surface_odd` | 1,278 |
| `surface_out_of_order` | 4 |
| `surface_own_decode_rejected` | 1 |
| `surface_own_outside_1km` | 5 |
| `surface_own_within_1km` | 1,057 |
| `surface_recent_previous` | 1,055 |
| `surface_shared_attempt` | 19 |
| `surface_shared_decode_rejected` | 1 |
| `surface_stale_previous` | 4 |
| `unresolved` | 39,755 |

## Evidence and freezing inventory

`tests/evidence/tracking-diagnostic/summary.json` records all counts, the complete per-stream branch table, platform, pin, seed, input SHA-256 and source SHA-256 values. `commands.json` records exact build/run commands, exits and tool versions. `input.jsonl.gz`, `airports.jsonl.gz`, `oracle.jsonl.gz` and `lean.jsonl.gz` retain complete inputs and outputs. `mismatches.jsonl` retains every finding instead of stopping at the first mismatch; it is empty for this run. `generation.json` lists every synthetic stream and its cardinality. An earlier successful smoke/full version is retained under `tests/evidence/tracking-diagnostic-initial/`.

The six new source/dependency files to freeze are:

- `Tests/Tracking.lean` — SHA-256 `196f549f758b2e4c78f263c12af1151482465a3670e96b714b5fe8885ffde6cd`
- `scripts/check_tracking.py` — SHA-256 `995a99758552651a0944e8b8143a8babcbf425476398595a0f727a5017891272`
- `scripts/generate_tracking.py` — SHA-256 `f36ea39027a57591c3a23ad6f3675a6eef34626e83607de4129e98d5907812e9`
- `differential/tracking-oracle/Cargo.toml` — SHA-256 `85b25b6c4d10fe461009618231dfd9c117e65613d503182b8da40be1a2638a7f`
- `differential/tracking-oracle/Cargo.lock` — SHA-256 `f308bf25efaaf610a22cf0145837a36b2a478f687099ab043d185503d67f0786`
- `differential/tracking-oracle/src/main.rs` — SHA-256 `c7168934991826f7391d2c4ffc350b7990194acae43c1ea58de8a071498a962b`

The adapter compiles under the existing Tests library (`lake build Tests.Tracking`); no `lakefile.toml` change or new executable target is required. The proposed frozen runner integration must call this checker without `--no-corpus` in both quick and full runs. The checker enforces source freshness, all required branch counts and exact corpus cardinality. Referenced Impl names must remain live code paths under the user’s standing rule.

These finite diagnostic strata do not prove numerical geography or aircraft motion correctness, and do not turn the software Float boundary into a theorem. They close the specific missing stream-level differential comparison; the independent low-level CPR suite and all final capstone obligations remain required.

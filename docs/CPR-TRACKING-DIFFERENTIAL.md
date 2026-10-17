# Stream CPR tracking differential

Executed 2026-10-17 against pinned rs1090 `685dfaa34c5ab186c691bca3cfe2a22e12517d30`. The revised diagnostic run passes **178,297 per-message comparisons with zero mismatches**. No `Spec/CPRPolicy.lean` omission was found by these finite tests. No frozen model was changed; the revised FC005 freeze remains a proposal requiring approval.

```sh
python3 scripts/check_tracking.py --diagnostic
```

| Population | Streams | Input messages | Resolved positions | Bit-identical resolved positions | Matching unresolved results |
| --- | ---: | ---: | ---: | ---: | ---: |
| Corpus | 1 | 172,432 | 11,347 | 11,347 | 161,085 |
| Synthetic | 445 | 5,865 | 5,113 | 5,113 | 752 |

The position pass rule is **absolute error at most `1e-9` degrees on each coordinate**. Observed maximum error is `0.0`; all 16,460 resolved outputs happen to be bit-identical. Bit identity is reported separately and is **not required of Lean**. All 161,837 unresolved results agree. Row identity, routing, final shared reference and every aircraft's public position, altitude, airport and seen-BDS set also agree.

## Actual entrypoints and label integrity

`Tests/Tracking.lean` decodes frames through the live `Impl.decode`, projects actual payload and oracle-compatible altitude into `TimedReport`, then calls **`Impl.decodePositions` on the complete ordered stream**. The live `Impl.CPR.Policy.numericalGeography` supplies the local/global Float adapters and haversine boundary. All 6,903 airports are read in pinned source order with exact binary64 coordinates represented as rationals. No tracking implementation is copied into the Lean adapter.

The freshly rebuilt Rust oracle calls actual **`rs1090::decode::cpr::decode_positions`** for expected outputs. A separate actual `decode_position` replay obtains labels and final public state. Every replay result is asserted bit-identical to the batch result. In addition, every routed row's shadow control flow must predict the real outcome: airborne output equals `motion_pass ? candidate : None`; surface output equals `candidate` unconditionally, including `None`. The oracle also asserts real position state, altitude, airport, seen-BDS evidence and shared reference against their predicted updates. Any disagreement aborts the oracle, preventing unchecked labels from supporting a passing comparison.

The Python checker independently requires successful position/state assertion flags on all 178,297 message rows and verifies the recorded candidate, motion decision, prediction and actual output on all **56,247 routed rows**. It rejects unknown or duplicate labels and requires each mandatory label. This validates the tracing instrumentation; equality among two executions of the same Rust oracle does not replace the Lean/Rust comparison or tighten its `1e-9` tolerance.

Timestamps are parsed once to binary64 and supplied to both runners as exact 64-bit encodings. The corpus includes all 172,432 original rows, their timestamps and arrival order, with only the 18-hex-character Beast prefix removed. Unresolved, rejected and non-ADS-B messages remain in the comparison.

## Requested boundary and transition witnesses

The generator seed is `109005`. Its independent exact rational CPR encoder follows Sun, second edition (2021), chapter 5, reads the frozen NL transition inventory as data, and creates CRC-valid frames. Alongside 200 random worldwide two-aircraft interleaved streams, fixed strata exercise both parities and arrival orders, pairing/local/speed window edges, cache ordering and replacement, local/global selection, reference callbacks, surface fallback, airport proximity and motion rejection. Random latitude/longitude sampling is not surface-area uniform. Four concrete callback choices are exercised; arbitrary callback functions are not exhaustively covered.

The added 1-km strata use adjacent **encoded surface latitude codes**, then check the actual decoded haversine distances. Both shared-reference contexts (absent/present) are mandatory for each row below:

| Surface parity | Just inside 1 km | Just outside 1 km |
| --- | ---: | ---: |
| Even | 0.9989320840756828 km | 1.0002046090235500 km |
| Odd | 0.9990399251729599 km | 1.0003340183402822 km |

All four distances are within one parity-specific latitude quantization step of 1 km (about 1.273 m even and 1.294 m odd). The inside case resolves using its own reference. The outside case fails without a shared reference and resolves through shared fallback when one exists. The generic `just_inside`/`just_outside` labels identify a 2-m band; the named mandatory witnesses satisfy the stronger single-code bound checked separately. Source decision: `cpr.rs:800–805`.

Backward-timestamp airborne witnesses move a nonzero distance while keeping the opposite cache old enough to avoid the cross-parity early return. Their speed uses the actual absolute timestamp difference, as at `cpr.rs:720–721`:

| Parity | Decoded distance | Accepted backward speed | Rejected backward speed |
| --- | ---: | ---: | ---: |
| Even | 1.1096417545401216 km | 1199.999996395236 km/h | 1200.0000036047654 km/h |
| Odd | 1.1129201238973385 km | 1199.999996405853 km/h | 1200.0000035941453 km/h |

The checker requires negative signed duration, positive movement, the expected side within 0.001 km/h of 1200, and the corresponding real accept/reject result. Separate moving local-reference cases use signed ages `−180−1e-8`, `−180`, and `−180+1e-8` seconds, for both parities; all resolve because `cpr.rs:705` compares the **signed** age with 180. Positive-age moving cases also cover just inside, exactly at and just outside +180 seconds; only the first resolves locally. An incorrect absolute-age local rule would reject the negative boundary cases.

The labeled lifecycle starts near EHAM, moves by shared reference near LFBO, and exercises these actual state effects:

| Last lifecycle row | Accepted report | Required altitude after report | Required airport after report | Source |
| ---: | --- | --- | --- | --- |
| 1 | Airborne after EHAM surface | 500 ft | None | `cpr.rs:762–764` |
| 2 | Surface after airborne | None | EHAM | `cpr.rs:842,846–848` |
| 5 | Surface near LFBO while EHAM already stored | None | EHAM | `cpr.rs:846` skips a new lookup |
| 6 | Airborne after surface | 500 ft | None | `cpr.rs:762–764` |
| 7 | Surface with no stored airport | None | LFBO | `cpr.rs:842,846–848` |
| 8 | Further surface with airport already stored | None | LFBO | `cpr.rs:846` skips a new lookup |

Six independent streams end at those exact rows. Their final-state comparisons test **Lean's intermediate state effects** before later messages could hide a missed clear/reset or an incorrect airport refresh. The checker requires each prefix's full ordered message set, terminal marker and expected public airport/altitude state. Overall it requires **25 specific message witnesses plus six terminal prefix-state witnesses**, independently of aggregate labels. The complete actual rows and numeric values are retained in `targeted-witnesses.json`.

## Coverage accounting

There are **45 distinct cataloged real rs1090 decision/result outcomes**, all witnessed. This count deduplicates source-linked outcome IDs: for example, exact and outside time-window labels share the same false outcome, and `speed_above_threshold`/`speed_rejection` describe the same rejection. This is a finite catalog of observed policy decisions and call results, **not a claim of complete Rust control-flow, condition or MC/DC coverage**. Independent low-level CPR tests cover additional formula cases.

The checker knows 80 labels, requires 75, and observes 79. `distance_exact_500` is optional and unobserved; no exact binary64 500-km witness is claimed. The four aggregate labels `airborne`, `surface`, `resolved` and `unresolved` are not mandatory labels. The catalog distinguishes source outcomes, boundary/outcome splits, co-occurring duplicates, state effects and contexts. In particular, `surface_out_of_order`, `surface_stale_previous` and `surface_recent_previous` are **negative controls**: rs1090 has no surface 180-second age rule. They are not three policy branches.

Every label is mapped below to lines in the [pinned `cpr.rs`](https://github.com/xoolive/rs1090/blob/685dfaa34c5ab186c691bca3cfe2a22e12517d30/crates/rs1090/src/decode/cpr.rs). “Outcome ID” is the deduplication key; a dash means the observation adds no distinct real decision/result outcome. Counts include corpus and synthetic inputs. Every stream's separate counts are retained in the JSON evidence.

| Label | Count | Classification | `cpr.rs` lines | Outcome ID | Interpretation |
| --- | ---: | --- | --- | --- | --- |
| `accepted_callback_false` | 13,124 | outcome split | 768-774 | — | Aggregate of callback absent or callback returning false; not one source branch. |
| `accepted_callback_true` | 2,227 | cooccurring duplicate | 768-774 | — | Aggregate alias for callback present and true. |
| `airborne` | 16,186 | real outcome | 671-675 | `payload.airborne` | The ME dispatch selects BDS05. |
| `airborne_backward_motion` | 10 | context | 705,720-721 | — | Nonzero movement with negative signed age witnesses use of absolute duration for motion. |
| `airborne_even` | 8,121 | real outcome | 678-685,778-786 | `parity.even` | Even reads the odd slot and eventually replaces the even slot unless returned early. |
| `airborne_odd` | 8,065 | real outcome | 678-685,778-786 | `parity.odd` | Odd reads the even slot and eventually replaces the odd slot unless returned early. |
| `backward_speed_above_threshold` | 2 | boundary split | 720-735 | `speed_threshold.reject` | Nonzero backward-time movement above 1200 km/h rejects; missing abs would accept. |
| `backward_speed_below_threshold` | 8 | boundary split | 720-735 | `speed_threshold.pass` | Nonzero backward-time movement at or below 1200 km/h passes; targeted fixtures must be strictly below. |
| `cache_replace_accepted` | 15,351 | real outcome | 755-786 | `airborne_result.some` | Accepted candidate updates public state then replaces its parity cache. |
| `cache_replace_failed` | 832 | real outcome | 755-786 | `airborne_result.none` | No accepted candidate; public position is preserved but its parity cache is replaced. |
| `cache_unchanged_early_return` | 3 | cooccurring duplicate | 688-690 | — | Same event as cross_parity_out_of_order; state/cache preservation is checked. |
| `callback_absent` | 12,022 | real outcome | 768-775 | `callback.absent` | No update callback was supplied. |
| `callback_false` | 1,102 | real outcome | 769-774 | `callback.false` | A supplied callback returns false and leaves shared reference unchanged. |
| `callback_true` | 2,227 | real outcome | 769-774 | `callback.true` | A supplied callback returns true and updates shared reference. |
| `cross_parity_out_of_order` | 3 | real outcome | 688-690 | `ordering.return` | Negative time relative to the opposite slot returns before any state update. |
| `decode_rejected` | 2 | real outcome | 885-905 | `routing.missing` | Message::from_bytes failed; the batch skips the missing message. |
| `df17` | 35,644 | real outcome | 887-894 | `routing.df17` | The batch dispatch selects ExtendedSquitterADSB. |
| `df18` | 20,603 | real outcome | 895-902 | `routing.df18` | The batch dispatch selects ExtendedSquitterTisB. |
| `distance_above_500` | 40 | outcome split | 743-748 | — | Distance context only; does not by itself imply jump rejection. |
| `distance_below_500` | 14,846 | outcome split | 743-748 | — | Distance context only; speed rejection or age can prevent the jump condition from evaluating. |
| `distance_exact_500` | 0 | outcome split | 743-748 | — | Exact distance boundary context; not required because no exact binary64 fixture is assumed. |
| `global_rejected` | 246 | real outcome | 697,702-705 | `global_result.none` | airborne_position returns None, so the local-age condition is considered. |
| `global_success` | 15,232 | real outcome | 697,702-705 | `global_result.some` | airborne_position returns Some, so the local fallback is skipped. |
| `jump_rejection` | 9 | real outcome | 743-748 | `jump.reject` | Candidate survives speed but exceeds 500 km with absolute age below 30 seconds. |
| `local_age_exact` | 2 | boundary split | 704-706 | `local_age.outside` | Exactly 180 seconds fails the signed local-age condition. |
| `local_age_inside` | 929 | real outcome | 704-706 | `local_age.inside` | The signed age is strictly less than 180 seconds, including negative ages. |
| `local_age_outside` | 20 | boundary split | 704-706 | `local_age.outside` | Greater than 180 seconds fails the same signed condition. |
| `local_attempt` | 284 | real outcome | 707-713 | `local_reference.some` | A previous accepted position exists for local fallback. |
| `local_no_previous_position` | 645 | real outcome | 707-713 | `local_reference.none` | No previous accepted position exists for local fallback. |
| `local_rejected` | 1 | real outcome | 708-713 | `local_result.none` | The actual airborne_position_with_reference returns None. |
| `local_success` | 283 | real outcome | 708-713 | `local_result.some` | The actual airborne_position_with_reference returns Some. |
| `motion_pass` | 14,722 | real outcome | 743-748 | `jump.pass` | After surviving speed validation, the compound jump-rejection condition is false; its conjuncts are not counted separately. |
| `non_adsb` | 122,048 | real outcome | 903 | `routing.other` | A successfully decoded frame has no tracking dispatch. |
| `opposite_slot_empty` | 648 | real outcome | 696-699 | `pair_slot.empty` | The opposite slot is None, so global reconstruction has no candidate. |
| `other_adsb` | 37,428 | real outcome | 852-866 | `payload.other` | The other-ME arm records supported evidence and produces no position. |
| `pair_even_then_odd` | 8,039 | cooccurring duplicate | 678-699 | — | The odd parity arm with a populated even slot; not another decision. |
| `pair_gap_exact` | 11 | boundary split | 692-700 | `pair_window.outside` | Exactly 30 seconds fails the strict pair window. |
| `pair_gap_inside` | 16,126 | real outcome | 692-700 | `pair_window.inside` | The strict absolute 30-second pair window passes after the ordering check. |
| `pair_gap_outside` | 46 | boundary split | 692-700 | `pair_window.outside` | More than 30 seconds fails the same strict pair-window condition. |
| `pair_odd_then_even` | 7,439 | cooccurring duplicate | 678-699 | — | The even parity arm with a populated odd slot; not another decision. |
| `reference_initialized` | 104 | outcome split | 768-774 | — | A true callback changed None to Some; initialization is not a separate source branch. |
| `reference_unchanged` | 54,020 | outcome split | 688-690,755-775,789-866 | — | Can result from early return, failure, absent/false callback, unchanged coordinates, or non-airborne message. |
| `reference_updated` | 2,123 | outcome split | 768-774 | — | A true callback changed an existing coordinate; source uses the same assignment. |
| `resolved` | 16,460 | outcome split | 755-776,834-850 | — | Aggregate accepted position across airborne and surface paths. |
| `same_parity_out_of_order_replacement` | 1 | negative control | 688-690,778-786 | — | Only the opposite timestamp is checked; replacement of an older same-parity slot is permitted. |
| `signed_local_age_backward_motion` | 10 | negative control | 704-713 | — | A negative age permits local fallback; targeted fixtures at -180 seconds and on both sides test that an absolute-age rule would be wrong. |
| `speed_above_threshold` | 155 | boundary split | 730-735 | `speed_threshold.reject` | Computed speed greater than 1200 km/h rejects. |
| `speed_below_threshold` | 14,698 | boundary split | 730-735 | `speed_threshold.pass` | Computed speed below 1200 km/h does not reject. |
| `speed_exact_threshold` | 1 | boundary split | 730-735 | `speed_threshold.pass` | Computed speed equal to 1200 km/h does not reject. |
| `speed_gap_exact` | 8 | boundary split | 727-737 | `speed_window.outside` | Exactly 1800 seconds bypasses speed validation. |
| `speed_gap_inside` | 14,877 | real outcome | 720-729 | `speed_window.inside` | Absolute age below 1800 seconds enables speed validation. |
| `speed_gap_outside` | 1 | boundary split | 727-737 | `speed_window.outside` | Greater than 1800 seconds bypasses the same condition. |
| `speed_rejection` | 155 | cooccurring duplicate | 733-735 | `speed_threshold.reject` | Same rejected event as speed_above_threshold. |
| `speed_zero_dt` | 23 | real outcome | 728-736 | `speed_duration.zero` | Zero absolute duration bypasses division/speed rejection. |
| `surface` | 2,633 | real outcome | 789-792 | `payload.surface` | The ME dispatch selects BDS06. |
| `surface_airport_lookup_found` | 32 | outcome split | 104-127,847-848 | — | Lookup result is Some; a result split inside surface_airport.lookup, not another tracking branch. |
| `surface_airport_lookup_missing` | 18 | outcome split | 104-127,847-848 | — | Lookup result is None; a result split inside surface_airport.lookup, not another tracking branch. |
| `surface_airport_lookup_none` | 50 | real outcome | 846-849 | `surface_airport.lookup` | No airport was set, so nearest-airport lookup runs. |
| `surface_airport_preserved_despite_new_nearest` | 5 | negative control | 846-849 | — | The existing airport is retained even when a fresh lookup would return another airport; no unconditional refresh exists. |
| `surface_airport_preserved_existing` | 1,059 | real outcome | 846-849 | `surface_airport.preserve` | An existing airport skips lookup and remains unchanged. |
| `surface_even` | 1,349 | context | 580-592,789-792 | — | Surface parity selects the low-level grid; decode_position has no surface parity policy branch. |
| `surface_existing_bypasses_airport` | 10 | real outcome | 818-826 | `surface_first.existing` | Existing position bypasses first-surface airport proximity validation. |
| `surface_first_far_from_airport` | 5 | real outcome | 818-823 | `surface_first_airport.far` | First position is not within strict 10-km airport proximity and rejected. |
| `surface_first_near_airport` | 17 | real outcome | 818-823 | `surface_first_airport.near` | First position is within strict 10-km airport proximity and accepted. |
| `surface_has_previous` | 1,097 | real outcome | 794-806 | `surface_previous.some` | An existing accepted position permits an own-reference attempt. |
| `surface_no_shared_reference` | 1,518 | real outcome | 807-833 | `surface_shared.none` | No own candidate remains and no shared reference exists. |
| `surface_odd` | 1,284 | context | 580-592,789-792 | — | Surface parity selects the low-level grid; decode_position has no surface parity policy branch. |
| `surface_out_of_order` | 4 | negative control | 789-850 | — | No surface timestamp gate exists; a backward timestamp can still update position. |
| `surface_own_1km_just_inside` | 4 | boundary split | 800-805 | `surface_own_distance.inside` | Decoded distance lies in the 2-m band below 1 km; targeted fixtures are additionally required within one latitude code. |
| `surface_own_1km_just_outside` | 4 | boundary split | 800-805 | `surface_own_distance.outside` | Decoded distance lies in the 2-m band at/above 1 km; targeted fixtures are additionally required strictly above and within one latitude code. |
| `surface_own_decode_rejected` | 1 | real outcome | 795-802 | `surface_own_decode.none` | The own-reference decoder returns None; short circuit skips distance. |
| `surface_own_outside_1km` | 14 | real outcome | 800-805 | `surface_own_distance.outside` | Decoded distance is at least 1 km, so own-reference candidate is discarded. |
| `surface_own_within_1km` | 1,082 | real outcome | 800-805 | `surface_own_distance.inside` | Decoded distance is strictly below 1 km and the own-reference candidate is retained. |
| `surface_recent_previous` | 1,083 | negative control | 789-850 | — | Age below 180 seconds is context, not a surface policy branch. |
| `surface_shared_attempt` | 33 | real outcome | 807-813 | `surface_shared.some` | No own candidate remains and a shared reference exists. |
| `surface_shared_decode_rejected` | 1 | real outcome | 817-831 | `surface_shared_decode.none` | Shared-reference decoder returns None. |
| `surface_stale_previous` | 10 | negative control | 789-850 | — | No surface 180-second age gate exists; this tests absence of an airborne-only rule. |
| `transition_airborne_to_surface_altitude_reset` | 33 | state effect | 834-844 | — | Accepted surface position resets a nonempty altitude to None; assignment outcome, not a new conditional arm. |
| `transition_surface_to_airborne_airport_cleared` | 11 | state effect | 755-766 | — | Accepted airborne position clears an existing airport; assignment outcome, not a new conditional arm. |
| `unresolved` | 39,787 | outcome split | 688-690,755-776,834-866 | — | Aggregate missing position across different policy outcomes. |

Counts per distinct outcome are retained as `real_outcome_counts`; duplicate labels contribute at most once per message to a given outcome. The source line map is literal metadata in `scripts/check_tracking.py` and exported to `coverage-catalog.json`, so newly emitted labels fail unless the map is extended. Source pin and SHA-256 are checked and retained.

## Evidence, comparator checks and proposed freeze

`tests/evidence/tracking-diagnostic/summary.json` retains source/input hashes, tool/platform information, population counts, all label/outcome counts and every stream's counts. `commands.json` records fresh build/run commands and exits. Complete inputs and outputs remain in `input.jsonl.gz`, `airports.jsonl.gz`, `oracle.jsonl.gz` and `lean.jsonl.gz`. `mismatches.jsonl` is empty. `generation.json` lists all 446 streams; `targeted-witnesses.json` retains the 31 required witnesses. Original proposal-v1 evidence is archived under `tests/evidence/frozen-changes/FC005-review-v1/`; preliminary run evidence is also preserved.

Nineteen independent comparator injection checks use 170 selected real trace rows covering all mandatory labels and targeted streams. Intact and 5e-10-degree perturbations pass; the latter explicitly loses bit identity. Larger errors, lost positions/rows, wrong routing/identity, missing/unknown/duplicate labels, false integrity flags or predictions, a wrong unresolved-surface candidate, a non-adjacent claimed boundary, a missing lifecycle prefix, wrong intermediate airport state, nonfinite coordinates and malformed coordinate pairs are rejected. The exact executable review script, command log and result are retained under `tests/evidence/frozen-changes/FC005-proposal/tracking-comparator-review.*`.

The six tracking source/dependency hashes for the revised freeze are:

- `Tests/Tracking.lean` — SHA-256 `196f549f758b2e4c78f263c12af1151482465a3670e96b714b5fe8885ffde6cd`
- `scripts/check_tracking.py` — SHA-256 `0ceee8daa0e504dcce12f8e499d699698c11c7f1ae111506f1e443c2e8e7b374`
- `scripts/generate_tracking.py` — SHA-256 `64236d72a99fa448863c655e277f1955e4686abfd1d5bfd6edc170abb1b4a7d5`
- `differential/tracking-oracle/Cargo.toml` — SHA-256 `85b25b6c4d10fe461009618231dfd9c117e65613d503182b8da40be1a2638a7f`
- `differential/tracking-oracle/Cargo.lock` — SHA-256 `f308bf25efaaf610a22cf0145837a36b2a478f687099ab043d185503d67f0786`
- `differential/tracking-oracle/src/main.rs` — SHA-256 `3fbd472310907068e885816810ad1503fbafbede364ea76e5494a7decde24374`

The adapter uses the existing Tests library; no `lakefile.toml` change or executable target is required. The proposed runner calls this checker with the full corpus in quick and full runs. Referenced Impl names must remain live code paths under the standing user rule. These finite diagnostics do not prove numerical geography, physical aircraft motion, airport database accuracy or arbitrary streams. They supplement the low-level CPR differential and the still-required capstone proofs.

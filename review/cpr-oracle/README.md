# Review-only CPR trace

This program observes the pinned rs1090 commit
`685dfaa34c5ab186c691bca3cfe2a22e12517d30`. It is review tooling, outside
`spec.lock`; it neither changes the oracle nor supplies implementation/proof
code. It uses the benchmark's original corpus order, strips the 18-character
Beast prefix, starts with no reference and empty aircraft state, and disables
reference updates. Default rs1090 features remain enabled. No airport or
receiver reference is invented for surface messages.

From the repository root:

```sh
mkdir -p .cache/review-cpr
CARGO_HOME="$PWD/.cache/cargo" CARGO_TARGET_DIR="$PWD/.cache/rs1090-target" \
  cargo build --locked --offline --manifest-path review/cpr-oracle/Cargo.toml --profile dist
.cache/rs1090-target/dist/lean1090-review-cpr-oracle \
  vendor/rs1090/crates/rs1090/data/long_flight.csv \
  .cache/review-cpr/trace.jsonl > .cache/review-cpr/trace-summary.json
```

The cached Cargo dependencies must already be available for `--offline`. The
initial successful build reused the frozen oracle harness's dependency lock,
with only this new package and its explicit `serde_json` dependency added.

The program first runs rs1090's actual `decode_positions` over the full corpus.
It then rereads the same corpus and calls actual `decode_position` one frame at
a time, comparing the resolved coordinate bits against the first pass for
every frame. Each observable aircraft `last_position()` is compared with the
parallel observation state. Route classification calls the public
`airborne_position`, `airborne_position_with_reference`, or
`surface_position_with_reference` in oracle priority order, before the real
state update. Every accepted candidate must match the actual returned bits.
The public functions, rather than copied formulas, perform all decoding.

## JSONL schema

There is one object for every BDS05/BDS06 message, including unresolved frames.
`row` is the one-based corpus line. `icao` is the oracle address string. All
`*_bits` values are **unsigned 64-bit integer IEEE-754 bit patterns**, including
timestamps. Parse JSON integers exactly: conversion through JavaScript Number
would lose bits. A position is `{ "lat_bits": ..., "lon_bits": ... }`.

| Key | Meaning |
| --- | --- |
| `row`, `timestamp_bits`, `icao` | Current input identity and time. |
| `mode`, `odd`, `lat_cpr`, `lon_cpr` | Current medium (`airborne` or `surface`), parity, and original 17-bit coordinate codes. |
| `position` | Actual resolved position at this frame's arrival, or null. |
| `previous_ref` | Aircraft's last accepted position before this frame, or null. Contains `row`, `timestamp_bits`, and `position`; time is last accepted position time. |
| `opposite` | Live opposite-parity airborne cache entry before this frame, or null. Contains `row`, `timestamp_bits`, `odd`, `lat_cpr`, `lon_cpr`, and that frame's own arrival `position` (possibly null). This field also exposes stale entries; use `global_attempt` to apply the real window. |
| `global_attempt` | Airborne cache mate exists, time is nonnegative, and absolute difference is strictly below 30 seconds. This says the global function was attempted, not that it succeeded. |
| `global_candidate` | Public global decoder's result before speed/distance validation, or null. |
| `mate_backfill` | Separate supplemental result from the public global decoder with input order reversed, or null. It is **not** a historical arrival position and is excluded from the primary independently resolved pair population. |
| `local_candidate` | Public local decoder result before final validation, or null. Airborne fallback requires failed global decoding and reference age below 180 seconds. Surface uses the last aircraft position; external reference is absent. |
| `route` | `global`, `local` (airborne fallback), `surface_local`, or `none`. A route names an actual accepted result, not merely an attempted method. |
| `negative_time` | Airborne timestamp precedes the opposite cache timestamp, causing the oracle's early return without cache update. |

An independently observed global pair has `global_attempt = true`, non-null
`position`, and non-null `opposite.position`. This population includes a local
fallback after a failed global attempt; do not select only accepted `global`
routes when checking whether the global hypotheses cover the live pairs. A
mate whose own arrival was unresolved must be counted as an exclusion, not
silently assigned the current position. For a local observation use the
current position and the actual pre-update `previous_ref`, with the current
medium/parity. Report actual local routes separately from all successive
resolved position/reference pairs.

## Executed trace

The initial trace has SHA-256
`657c1b429f77e48d4f0519cbfd1f0af63b4ccaf2ebac4b8c40cf9b5e39e40e48`.
Its corpus SHA-256 is
`3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505`.
All 172,432 coordinate-result comparisons passed, yielding 12,964 CPR trace
rows (10,408 airborne and 2,556 surface) and 11,347 accepted positions:

| Observed outcome | Count |
| --- | ---: |
| Accepted global airborne | 10,290 |
| Of those, mate resolved at its own original arrival | 10,254 |
| Of those, mate unresolved at its own original arrival | 36 |
| Accepted airborne local fallback | 10 |
| Accepted surface local | 1,047 |
| Accepted position with previous aircraft reference | 11,345 |
| Global attempts, including unsuccessful candidates | 10,405 |

These are oracle observation counts, not yet evaluations of Lean admissibility
predicates and not external position accuracy measurements.

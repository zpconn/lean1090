# FC005 tracking revision probes

The deterministic generator run used `--no-corpus --random-tracks 0`; this report supplements the complete tracking campaign, rather than substituting for it. Every oracle stream passed unconditional shadow/actual position and public-state assertions.

Executed commands:

```sh
python3 scripts/generate_tracking.py --no-corpus --random-tracks 0 --output tests/evidence/tracking-revision-probes
.cache/rs1090-target/dist/lean1090-tracking-oracle < tests/evidence/tracking-revision-probes/input.jsonl > tests/evidence/tracking-revision-probes/oracle.jsonl
```

Exact measured values below come from the oracle JSONL, not pre-quantization encoder offsets. Full per-row labels, metrics and before/after public state are in `boundary-and-lifecycle.json`.

| Stream | Decoded distance km | Signed duration s | Speed km/h | Resolved |
|---|---:|---:|---:|---|
| surface_own_1km_inside_parity0_no_shared | 0.9989320840756828 |  |  | True |
| surface_own_1km_inside_parity0_shared | 0.9989320840756828 |  |  | True |
| surface_own_1km_outside_parity0_no_shared | 1.00020460902355 |  |  | False |
| surface_own_1km_outside_parity0_shared | 1.00020460902355 |  |  | True |
| surface_own_1km_inside_parity1_no_shared | 0.9990399251729599 |  |  | True |
| surface_own_1km_inside_parity1_shared | 0.9990399251729599 |  |  | True |
| surface_own_1km_outside_parity1_no_shared | 1.0003340183402822 |  |  | False |
| surface_own_1km_outside_parity1_shared | 1.0003340183402822 |  |  | True |
| backward_speed_1200_below_parity0 | 1.1096417545401216 | -3.3289252736203565 | 1199.999996395236 | True |
| backward_speed_1200_above_parity0 | 1.1096417545401216 | -3.328925253620369 | 1200.0000036047654 | False |
| signed_local_age_motion_outside_abs_parity0 | 1.1096417545401216 | -180.00000001 | 22.192835089569495 | True |
| signed_local_age_motion_exact_abs_parity0 | 1.1096417545401216 | -180.0 | 22.19283509080243 | True |
| signed_local_age_motion_inside_abs_parity0 | 1.1096417545401216 | -179.99999999 | 22.19283509203537 | True |
| backward_speed_1200_below_parity1 | 1.1129201238973385 | -3.338760381692012 | 1199.999996405853 | True |
| backward_speed_1200_above_parity1 | 1.1129201238973385 | -3.3387603616920245 | 1200.0000035941453 | False |
| signed_local_age_motion_outside_abs_parity1 | 1.1129201238973385 | -180.00000001 | 22.25840247671019 | True |
| signed_local_age_motion_exact_abs_parity1 | 1.1129201238973385 | -180.0 | 22.25840247794677 | True |
| signed_local_age_motion_inside_abs_parity1 | 1.1129201238973385 | -179.99999999 | 22.25840247918335 | True |

Every backward-speed and signed-local-age row has `pair_gap_outside`, `local_attempt`, `local_success`, and nonzero motion. The below-1200 backward-speed cases resolve; above-1200 cases retain the previous state and emit no position. Both parities accept all three negative ages around −180 s, including the two cases whose absolute age is at least180 s. The added positive-age motion streams separately exercise the signed +180 s limit.

The lifecycle stream starts with airport EHAM, clears it on accepted airborne row1, resets altitude and finds EHAM on surface row2, preserves EHAM after a surface move near LFBO at row5, clears it on airborne row6, then finds LFBO at surface row7 and preserves it at row8. Every transition is asserted against actual public state.

Three disposable oracle mutants were built under a different binary name and rejected with exit101: ignoring airborne motion rejection, predicting a surface candidate when the real decoder returns None, and retaining the old airport in the shadow expectation. Exact compiler commands and panic evidence are in `label-integrity-mutations.json`; the experiment script is retained as a review snapshot. These are assertions about oracle-label integrity, not a bit-identity requirement on Lean/Rust comparison.

Input source SHA-256:

- `scripts/generate_tracking.py`: `64236d72a99fa448863c655e277f1955e4686abfd1d5bfd6edc170abb1b4a7d5`
- `differential/tracking-oracle/src/main.rs`: `3fbd472310907068e885816810ad1503fbafbede364ea76e5494a7decde24374`

Six independent prefixes end immediately after each critical lifecycle row, so the Lean adapter's final-state comparison observes each intermediate state before a later report can overwrite it.

| Terminal row | Primary altitude | Primary airport |
|---|---|---|
| 1 | 500 | None |
| 2 | None | EHAM |
| 5 | None | EHAM |
| 6 | 500 | None |
| 7 | None | LFBO |
| 8 | None | LFBO |

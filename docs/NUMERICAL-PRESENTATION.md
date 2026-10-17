# Numerical presentation compatibility

`Impl.decode` returns the exact field/semantic model covered by refinement.
`Impl.Numeric.eval` evaluates that model's frozen expression trees at the
explicitly tested Float boundary. It does not implement Comm-B inference.
The latter still uses the proved software binary64 model; no hardware
inference primitive is authorized or added.

The initial adapter used system `hypot`/`atan2`, which differ in low bits from
rs1090's Rust `libm` dependency. `Impl/Libm.lean` now translates the algorithms
in pinned `libm` 0.2.16 `src/math/hypot.rs`, `atan.rs`, and `atan2.rs` into
pure Lean. It preserves operation order and exact coefficient bit patterns.
Lean's existing Float arithmetic/square root are used at this tested boundary.
The generated C is compiled at `-O3 -ffp-contract=off` with no CPU-specific
flags. The library license/notices are in `licenses/rust-libm-0.2.16.txt`.
This is a runtime compatibility test, not a new theorem about Float.

Run the permanent check with:

```sh
python3 scripts/check_numeric.py
```

It builds a fresh Rust oracle using the locked `libm` dependency, then compares
binary64 bits on all 16,752,649 nonnegative integer component pairs from
0 through 4092 for hypot, all 4,182,025 signed oracle velocity pairs from
−1022 through 1022 for track, every selected-heading/pressure/heading code,
and a direct rational-to-binary32 double-rounding regression. Total:
**20,936,723 exact comparisons, zero mismatches**. Source hashes, oracle-output
hash and command log are retained in `tests/evidence/numeric-libm/`.
Both complete quick/full differential invocations require this check.

The corrected initial CLI also matches all 172,432 corpus compatibility
outputs exactly, including CRC, consumed bytes and remaining suffix.
`tests/evidence/message-corpus-corrected/` retains complete compressed inputs
and both views. This corpus result does not establish agreement on generated
messages, classify all standard-view differences, complete the unit port, or
prove the remaining capstones. The earlier failing run and wrong-dependency
experiment remain recorded as historical evidence.

# Approved frozen compatibility correction (FC001)

The initial whole-corpus JSON comparison found a reference compatibility
error. The standard Gillham interpretation correctly represents negative
heights, but the separately named oracle interpretation fails to reproduce
the pinned receiver's rejection of those heights. Because Comm-B inference
must reproduce rs1090's exact policy, this affects its candidate set.

The user approved this correction on 2026-10-16. The approved source patch has
been applied; its validation and lock history are recorded in
[FROZEN-CHANGES.md](FROZEN-CHANGES.md). The reviewed patch is
[ALTITUDE-COMPATIBILITY-PROPOSAL.diff](ALTITUDE-COMPATIBILITY-PROPOSAL.diff).
It edits only four compatibility definitions and their docstrings in
`Spec/Altitude.lean` and `Spec/AssignmentAltitude.lean`.

## Concrete counterexample

Corpus row17040 is `a1000000920805003ffc0005c6e5`. The outer AC13 is zero
(missing). Its MB `920805003ffc00` has TC18 and AC12 `0x080`.

| Quantity | Pre-correction frozen reference | Pinned rs1090 |
| --- | --- | --- |
| MB Gillham height, compatibility view | −1200ft | missing |
| Outer AC13 height | missing | missing |
| BDS05 candidate | absent: heights differ | present: both heights missing |

The Rust behavior comes from `gray2alt` in
`vendor/rs1090/crates/rs1090/src/decode/mod.rs`: it returns an error when
the decoded count is below13, thereby rejecting every negative Gillham
height. Its Q=1 binary25 branch still accepts negative values. The DF20
reader in `decode/commb.rs` accepts a BDS05 candidate exactly when its height
option equals the outer AC13 height option, including `None == None`.
The initial full corpus contains33 such candidate-set mismatches.

## Proposed correction and executed checks

- `Altitude.oracleAC13`: return `none` for a negative height only when Q=0.
- `Altitude.oracleAC12`: return `some none` in that case. This accepts the
  message with a missing height; it does not reject the whole message.
- `Assignment.compatibility13` and `compatibility12`: independently apply
  the same Q=0 filter, preserving their decoder-independent construction.
- Preserve all standard altitude decoders, encoders, representability
  domains and capstone types. The independent receiver predicate remains
  correct and needs no change. The existing exhaustive assignment and
  receiver guards need no weakening or edit.

`review/AltitudeCompatibilityProposal.lean` contains the proposed definitions
under a review-only namespace. The command

```sh
lake env lean --run review/AltitudeCompatibilityProposal.lean
```

passed its kernel checks: all8192 independent AC13 meanings, all4096 AC12
meanings, all4096 receiver-acceptance results, the concrete frozen candidate
failure, and negative Gillham/binary25 regression assertions. It also emits
the proposed results for comparison. These were compared with actual
`Message::from_bytes` calls for all8192 DF4 AC13 inputs and all4096 DF18 AC12
inputs: **12288 cases, zero mismatches**, including acceptance and missing
height. Complete inputs/results and hashes are retained under
`tests/evidence/altitude-proposal/`.

The approved patch is mirrored in the runtime. Permanent exhaustive coverage
is implemented in `scripts/check_altitude_differential.py` and required by the
differential entrypoint. The unchanged guards and affected refinements are
rerun successfully before refreshing only these two entries in `spec.lock`. The standard
view retains negative Gillham heights; see discrepancy D010. The original
review-only source is archived as
`tests/evidence/altitude-proposal/AltitudeCompatibilityProposal.lean.gz`; the
working review file now expects the corrected BDS05 candidate result.

## Separate numerical adapter failure

The initial corpus comparison processed all172432 frames. It found170398
exact oracle-view matches and2034 mismatching messages: the33 inference
differences above,1989 track differences and12 groundspeed differences.
All inputs, both outputs and mismatch records are retained in
`tests/evidence/message-initial/`. This is a **failing** component run, not a
passing whole-message differential suite; standard-view differences remain
to be classified separately.

The numerical differences come from the new output adapter using system
libm while rs1090 calls the Rust `libm`0.2.16 crate. The first exhaustive
numeric check compared20,936,723 values with Rust's system math operations;
it passed but tested the wrong dependency for oracle conformance. The test
harness now calls the pinned crate and fails at `hypot(11,261)`:
Lean bits4643303252822179949 versus oracle bits4643303252822179950.
That adapter needs an ordinary implementation fix. It requires no frozen
spec change, new trusted primitive, or relaxed tolerance. The known failure
is documented in `Impl/Numeric.lean`; no oracle-agreement claim is made.

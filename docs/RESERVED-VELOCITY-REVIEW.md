# Reserved TC19 oracle meaning — approval required

The approved altitude correction FC001 and all three conditions are complete.
Continued generated testing found a separate frozen-model omission. No files
in the proposed patch, or their lock entries, have been changed.

## Counterexample and cause

Input `9011223398040000000000000000` is DF18, TC19, subtype0, with only
the first bit of its22-bit reserved velocity field set:

| Quantity | Current proved record / CLI | Pinned rs1090 |
| --- | --- | --- |
| Raw wire field, MSB-first | 2,097,152 (`0x200000`) | same transmitted bits |
| Reported `reserved_data` | 2,097,152 | 128 (`0x80`) |
| Separate oracle meaning in the semantic record | absent | 128 |

The first generated failure was `94d218c99d77ed76f421dc4965ce`, subtype5:
current output4,156,343; rs1090 output3,649,277. The10,000-message initial
campaign had9,029 exact matches,940 known D001 Comm-D failures, and31 new
mismatches, all in this one field. Complete inputs, outputs and failures are
retained in `tests/evidence/message-generated-initial/`.

The pinned `crates/rs1090/src/decode/bds/bds09.rs::ReservedVelocityData`
annotates its `u32` with22bits but no endian context. Its default `deku`0.20.3
reader uses native endian, which is little-endian on the pinned x86_64/WSL2
host. Deku splits the input into8,8,6bit chunks, padding the last chunk on its
left, and loads the chunks least-significant first. Thus the oracle meaning is

```
first8bits + 256 * next8bits + 65536 * final6bits
```

This applies only to TC19 subtypes0,5,6,7. The reserved field has no standard
physical quantity; its raw wire bits must still be preserved. This is an
explicitly rs1090-derived native-endian policy, not a new standard rule or a
claim that the same rs1090 output is portable to a big-endian target.

## Proposed correction

[RESERVED-VELOCITY-PROPOSAL.diff](RESERVED-VELOCITY-PROPOSAL.diff) changes only:

- `Spec/Semantics.lean`: add the exact oracle interpretation and include it in
  `adsbOracleValues` for the four reserved subtypes.
- `Spec/Assignment.lean`: construct the same oracle meaning independently,
  using the existing encoder-side bit fold rather than decoder helpers.

The wire layout, standard/raw values, encoder, hypotheses, capstone types,
existing example expectations, and all guards remain unchanged. After approval,
mirror the semantic change in Impl, extend its refinement proof, and have the
JSON adapter read this proved oracle value. Computing the byte-order
interpretation only inside JSON would leave that reported meaning outside the
proved `Impl.decode` result and the frozen timed path.

## Executed review evidence

`review/ReservedVelocityProposal.lean` compiles the proposed semantic definitions
in a review-only namespace. Its kernel checks cover the literal counterexamples,
the current semantic omission, and independent bit-fold agreement for zero,
all-one and every single-bit reserved payload in every affected subtype.

The review run compared16,511 cases against fresh pinned `Message::from_bytes`
calls: for each of the four subtypes, zero, all-one,22 single-bit cases and
4,096 seeded random field values, plus all31 initial generated failures.
The proposed semantic list agrees with the independent proposed assignment in
every case. Substituting just the proposed `reserved_data` value into the
captured diagnostic output gives **zero mismatches on the complete oracle
output**. This is a tested proposal, not an applied implementation fix or a
passing full differential suite. Complete traces, hashes and reproduction
instructions are in `tests/evidence/reserved-velocity-proposal/`.

If approved, add FC002 to `docs/FROZEN-CHANGES.md` with date, exact files,
old/new hashes, reason, executed evidence and this new approval **before**
refreshing either hash. Retain permanent subtype/bit-placement regressions.
The current lock continues to describe FC001 and still passes all61 hashes.

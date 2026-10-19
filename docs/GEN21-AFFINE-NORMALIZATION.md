# Generation 21: exact integer scaling with one normalization

Generation 20's fresh, independently reviewed diagnostics precede this change.
The decode census collected 9,056,220,724 instructions. Comm-B inference is the
largest exclusive stage (3,065,868,970), followed by frame/CRC (2,965,731,673)
and semantic value construction (2,789,082,596). Direct calls from
`payloadValue` to rational multiplication account for 1,172,225,030 inclusive
instructions across semantic and Comm-B contexts. These nested observations
overlap the exclusive stages; they are not a prediction of elapsed-time savings.
See [decode accounting](GEN20-COST-BREAKDOWN.md) and
[CPR accounting](GEN20-CPR-COST-BREAKDOWN.md).

The selected change specializes multiplication of an integer field value by
an exact rational scale. Instead of allocating an integer-valued rational and
calling generic rational multiplication, construct
`Rat.normalize (value * scale.num) scale.den scale.den_nz`. The existing unit
scale and zero offset shortcuts remain. No field layout, missing-value rule,
rounding rule or semantic output changes.

The proof obligation is unconditional: for every integer `value` and rational
`scale`, the new operation equals `(value : Rat) * scale`. It follows from
Lean's `Rat.mul_def`, since the integer cast has denominator one. The existing
`affineValue_eq` and `payloadValue_eq` statements then preserve the complete
decoder refinement. Negative values, zero, non-dyadic scales and arbitrarily
large inputs remain in the theorem's domain.

Generic multiplication cross-cancels before multiplying numerators; the new
operation normalizes their product. This can create larger intermediate
integers for arbitrary large inputs, so no universal performance claim follows
from the equality proof. The frozen corpus benchmark will determine whether
this is useful for the decoder.

The change stays in the shared proved decoder. CPR policy, Float callbacks,
the software binary64 model, frozen files and trusted primitives are unchanged.
The independently measured CPR-specific costs remain candidates for later
generations: motion rounding and numeric conversion must also stay inside the
proved boundary.

Before timing: build the proofs and production executables, inspect generated
C, run the full fixed-seed gate and a separately seeded 10M campaign, retain
their complete evidence, then commit. Timing uses a fresh build of that clean
commit, its recorded binary hash, the unchanged interleaver and both modes.
Retain every sample and power-plan capture, and report both signed CPR
overheads. No generation 21 throughput result is claimed yet.

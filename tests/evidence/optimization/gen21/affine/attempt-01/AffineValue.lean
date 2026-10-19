import Proofs.PayloadBits
import Proofs.PayloadIntegerShift

/-! Integer normalization and identity shortcuts preserve exact affine field semantics. -/
namespace Lean1090.Proofs.AffineValue

/-- Direct normalization equals rational multiplication for every integer and
rational, without sign, magnitude, denominator or field-validity hypotheses. -/
theorem integerScale_eq (value : Int) (scale : Rat) :
    Impl.integerScale value scale = (value : Rat) * scale := by
  simpa only [Impl.integerScale, Rat.num_intCast, Rat.den_intCast, Nat.one_mul] using
    (Rat.mul_def (value : Rat) scale).symm

/-- Exact equality for every integer and rational pair, including negative
scales and offsets. No field-validity or finite-word hypothesis is required. -/
theorem affineValue_eq (value : Int) (scale offset : Rat) :
    Impl.affineValue value scale offset = (value : Rat) * scale + offset := by
  by_cases unit : scale = 1 <;> by_cases zero : offset = 0 <;>
    simp [Impl.affineValue, integerScale_eq, unit, zero, Rat.mul_one, Rat.add_zero]

/-- The complete field projection equals its old body, preserving the exact
status predicate, bit extraction, integer interpretation and absent result. -/
theorem payloadValue_eq_old (column : Spec.PayloadColumn) (word : Nat) :
    Impl.payloadValue column word =
      (if column.status != 0 && Impl.payloadBits word column.status 1 == 0 then none
       else some ((Impl.payloadInteger column.coding column.width
         (Impl.payloadBits word column.start column.width) : Rat) * column.scale + column.offset)) := by
  simp only [Impl.payloadValue, affineValue_eq]

/-- Equality with the frozen reference for every column and every natural
word, without assuming a valid layout, status position, or bounded input. -/
theorem payloadValue_eq (column : Spec.PayloadColumn) (word : Nat) :
    Impl.payloadValue column word = Spec.payloadValue column word := by
  rw [payloadValue_eq_old]
  simp only [Spec.payloadValue, PayloadBits.payloadBits_eq,
    PayloadIntegerShift.payloadInteger_eq]

/-- Both identity operations are skipped in the live payload projection. -/
theorem identity_witness :
    Impl.payloadValue { name := "identity", start := 53, width := 4 } 7 = some 7 := by
  decide +kernel

/-- A nonidentity scale with zero offset preserves exact rational scaling. -/
theorem scaled_witness :
    Impl.payloadValue { name := "scaled", start := 53, width := 4, scale := 1/2 } 7 =
      some (7/2) := by
  decide +kernel

/-- Unit scale with a nonzero offset preserves the exact translation. -/
theorem offset_witness :
    Impl.payloadValue { name := "offset", start := 53, width := 4, offset := 3/4 } 7 =
      some (31/4) := by
  decide +kernel

/-- Nonidentity scale and offset retain both original arithmetic operations. -/
theorem both_witness :
    Impl.payloadValue { name := "both", start := 53, width := 4, scale := 3/2, offset := 1/4 } 7 = some (43/4) := by
  decide +kernel

/-- Negative signed input, scale and offset are also within the helper's domain. -/
theorem negative_witness :
    Impl.payloadValue { name := "negative", start := 53, width := 4, coding := .twosComplement, scale := -2/3, offset := -1/6 } 9 = some (9/2) := by
  decide +kernel

/-- Missing status still rejects before returning any affine field value. -/
theorem missing_status_witness :
    Impl.payloadValue { name := "missing", start := 53, width := 4, scale := 3/2, offset := 1/4, status := 1 } 7 = none := by
  decide +kernel

/-- A zero scale remains within the unrestricted rational domain. -/
theorem zero_scale_witness :
    Impl.payloadValue { name := "zero", start := 53, width := 4, scale := 0, offset := -1/6 } 7 =
      some (-1/6) := by
  decide +kernel

/-- A common denominator factor is cancelled with a negative integer input. -/
theorem cancellation_witness :
    Impl.integerScale (-84) (5/14) = -30 := by
  decide +kernel

/-- Arbitrary-precision inputs beyond machine-word bounds retain exact cancellation. -/
theorem large_negative_witness :
    Impl.integerScale (-1267650600228229401496703205376)
      (3/1267650600228229401496703205376) = -3 := by
  decide +kernel

/-- A negative scale with no cross cancellation retains a nonintegral result. -/
theorem negative_fraction_witness :
    Impl.integerScale 17 (-3/11) = -51/11 := by
  decide +kernel

#print axioms integerScale_eq
#print axioms affineValue_eq
#print axioms payloadValue_eq_old
#print axioms payloadValue_eq
#print axioms identity_witness
#print axioms scaled_witness
#print axioms offset_witness
#print axioms both_witness
#print axioms negative_witness
#print axioms missing_status_witness
#print axioms zero_scale_witness
#print axioms cancellation_witness
#print axioms large_negative_witness
#print axioms negative_fraction_witness

end Lean1090.Proofs.AffineValue

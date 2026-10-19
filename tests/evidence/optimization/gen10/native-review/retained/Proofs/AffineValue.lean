import Proofs.PayloadBits

/-! Identity shortcuts preserve exact affine field semantics on every input. -/
namespace Lean1090.Proofs.AffineValue

/-- Exact equality for every integer and rational pair, including negative
scales and offsets. No field-validity or finite-word hypothesis is required. -/
theorem affineValue_eq (value : Int) (scale offset : Rat) :
    Impl.affineValue value scale offset = (value : Rat) * scale + offset := by
  by_cases unit : scale = 1 <;> by_cases zero : offset = 0 <;>
    simp [Impl.affineValue, unit, zero, Rat.mul_one, Rat.add_zero]

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
    Impl.payloadInteger, Spec.payloadInteger]

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

end Lean1090.Proofs.AffineValue

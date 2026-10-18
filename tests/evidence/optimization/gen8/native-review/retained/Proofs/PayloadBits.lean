import Impl.PayloadBits
import Spec.PayloadBits

/-!
Machine-word extraction preserves the reference field formula for every
natural-number input, position, and width. Only the bounded low-word prefix
uses native shifts; the public operation retains the original wide fallback.
-/

namespace Lean1090.Proofs.PayloadBits

/-- A field wholly inside the first 64 bits is unchanged by truncating a
natural number to the low machine word before extracting it. -/
theorem payloadWordBits_eq (word shift width : Nat) (smallShift : shift < 64)
    (smallWidth : width < 64) (fits : shift + width ≤ 64) :
    Impl.payloadWordBits word.toUInt64 shift width = word / 2^shift % 2^width := by
  have sizeBound : shift < UInt64.size := Nat.lt_trans smallShift (by decide)
  have index : shift.toUInt64.toNat = shift := UInt64.toNat_ofNat_of_lt' sizeBound
  unfold Impl.payloadWordBits
  rw [UInt64.toNat_and, Impl.payloadWordMask_toNat width smallWidth,
    UInt64.toNat_shiftRight, index, Nat.mod_eq_of_lt smallShift,
    UInt64.toNat_ofNat', Nat.and_two_pow_sub_one_eq_mod,
    ← Nat.shiftRight_eq_div_pow]
  apply Nat.eq_of_testBit_eq
  intro i
  simp only [Nat.testBit_mod_two_pow, Nat.testBit_shiftRight]
  by_cases small : i < width
  · have inside : shift + i < 64 := by omega
    simp only [small, inside, decide_true, Bool.true_and]
  · simp only [small, decide_false, Bool.false_and]

/-- The optimized extraction equals the frozen formula for all naturals,
without assuming a valid layout, bounded word, or positive field width. -/
theorem payloadBits_eq (word start width : Nat) :
    Impl.payloadBits word start width = Spec.payloadBits word start width := by
  unfold Impl.payloadBits Spec.payloadBits
  split
  · rename_i small
    apply payloadWordBits_eq word _ width _ small
    · omega
    · omega
  · rfl

/-- Zero-width fields preserve the reference zero result even on wide input. -/
theorem zero_width_witness : Impl.payloadBits (2^130 + 7) 0 0 = 0 := by
  decide +kernel

/-- Width 63 extracts the maximal fast-path mask from an over-wide input. -/
theorem last_fast_width_witness :
    Impl.payloadBits (2^130 + 2^63 - 1) 1 63 = 2^63 - 1 := by
  decide +kernel

/-- Width 64 uses the fallback rather than a masked native shift count. -/
theorem first_fallback_width_witness :
    Impl.payloadBits (2^130 + 2^63) 1 64 = 2^63 := by
  decide +kernel

/-- The general helper supports a field ending exactly at bit 64. -/
theorem word_boundary_witness :
    Impl.payloadWordBits (2^63 : Nat).toUInt64 1 63 = 2^62 := by
  decide +kernel

#print axioms payloadWordBits_eq
#print axioms payloadBits_eq
#print axioms Impl.payloadBits_lt
#print axioms zero_width_witness
#print axioms last_fast_width_witness
#print axioms first_fallback_width_witness
#print axioms word_boundary_witness

end Lean1090.Proofs.PayloadBits

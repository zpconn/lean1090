import Impl.Bits
import Spec.Bits
import Proofs.PayloadBits

/-! Native frame-field masks preserve arbitrary-width wire extraction. -/
namespace Lean1090.Proofs.FrameBits

/-- The native path equals the frozen field definition for every natural
total, start, width and word. No valid-layout or bounded-word premise is used. -/
theorem field_eq (total start width word : Nat) :
    Impl.field total start width word = Spec.field total start width word := by
  unfold Impl.field Spec.field
  split
  · rename_i small
    apply BitVec.eq_of_toNat_eq
    simp only [BitVec.toNat_ofNatLT, BitVec.toNat_ofNat]
    rw [PayloadBits.payloadWordBits_eq _ 0 width (by decide) small (by omega)]
    simp only [Nat.pow_zero, Nat.div_one, Nat.shiftRight_eq_div_pow]
  · rfl

/-- An explicit old-body equality for integrations that use the wire formula. -/
theorem field_eq_old (total start width word : Nat) :
    Impl.field total start width word =
      BitVec.ofNat width (word / 2 ^ (total - start - width)) :=
  field_eq total start width word

/-- A zero-width native mask remains zero even for an over-wide input. -/
theorem zero_width_witness :
    (Impl.field 200 17 0 (2^250 + 19)).toNat = 0 := by
  decide +kernel

/-- Width 63 takes the final native-mask case after shifting a wide word. -/
theorem last_fast_width_witness :
    (Impl.field 127 0 63 (2^200 + (2^63 - 1) * 2^64 + 7)).toNat = 2^63 - 1 := by
  decide +kernel

/-- Width 64 retains the original fallback and all 64 result bits. -/
theorem first_fallback_width_witness :
    (Impl.field 128 0 64 (2^200 + 2^127 + 5 * 2^64 + 7)).toNat = 2^63 + 5 := by
  decide +kernel

/-- The fallback preserves widths beyond a machine word, including Comm-D. -/
theorem wide_fallback_witness :
    (Impl.field 112 8 80 (2^200 + 2^103 + 13 * 2^24 + 7)).toNat = 2^79 + 13 := by
  decide +kernel

/-- A field crossing bit 64 is shifted before conversion to a machine word. -/
theorem cross_word_witness :
    (Impl.field 96 20 16 (2^130 + 0xABCD * 2^60 + 7)).toNat = 0xABCD := by
  decide +kernel

/-- Shift counts above 64 remain natural shifts, without native count wrapping. -/
theorem high_shift_witness :
    (Impl.field 256 2 12 (2^300 + 0xABC * 2^242 + 7)).toNat = 0xABC := by
  decide +kernel

/-- An out-of-range starting position retains truncating natural subtraction. -/
theorem start_underflow_witness :
    (Impl.field 7 19 8 (2^130 + 0xA5)).toNat = 0xA5 := by
  decide +kernel

/-- A width exceeding the remaining total also leaves the original zero shift. -/
theorem width_underflow_witness :
    (Impl.field 5 1 13 (2^130 + 0x1234)).toNat = 0x1234 := by
  decide +kernel

#print axioms field_eq
#print axioms field_eq_old
#print axioms zero_width_witness
#print axioms last_fast_width_witness
#print axioms first_fallback_width_witness
#print axioms wide_fallback_witness
#print axioms cross_word_witness
#print axioms high_shift_witness
#print axioms start_underflow_witness
#print axioms width_underflow_witness

end Lean1090.Proofs.FrameBits

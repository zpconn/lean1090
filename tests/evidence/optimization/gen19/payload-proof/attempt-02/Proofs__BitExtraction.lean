import Impl.Altitude
import Impl.Frame
import Spec.Altitude
import Spec.Frame

/-! Exact natural shifts preserve altitude and Mode A bit interpretation. -/

namespace Lean1090.Proofs.BitExtraction

/-- Selecting one bit by shifting and masking equals the original quotient
and remainder for every natural word and index, without a machine-word bound. -/
theorem bit_eq (word place : Nat) :
    Impl.Altitude.bit word place = Spec.Altitude.bit word place := by
  simp only [Impl.Altitude.bit, Spec.Altitude.bit,
    Nat.and_one_is_mod, Nat.shiftRight_eq_div_pow]

/-- The Gray-code fold is unchanged for every width and every natural word.
The word need not fit the supplied width. -/
theorem grayDecode_eq (width word : Nat) :
    Impl.Altitude.grayDecode width word = Spec.Altitude.grayDecode width word := by
  simp only [Impl.Altitude.grayDecode, Spec.Altitude.grayDecode,
    Nat.shiftRight_eq_div_pow]

/-- All 13-bit identity fields preserve their four octal digits, including
the reserved bit that is omitted by both definitions. -/
theorem identityCode_eq (code : BitVec 13) :
    Impl.identityCode code = Spec.identityCode code := by
  simp only [Impl.identityCode, Spec.identityCode,
    Nat.and_one_is_mod, Nat.shiftRight_eq_div_pow]

theorem bit_function_eq : Impl.Altitude.bit = Spec.Altitude.bit := by
  funext word place
  exact bit_eq word place

theorem grayDecode_function_eq : Impl.Altitude.grayDecode = Spec.Altitude.grayDecode := by
  funext width word
  exact grayDecode_eq width word

theorem identityCode_function_eq : Impl.identityCode = Spec.identityCode := by
  funext code
  exact identityCode_eq code

/-- Zero remains zero, even at an index above the native word width. -/
theorem zero_bit_witness : Impl.Altitude.bit 0 200 = 0 := by
  decide +kernel

/-- The low-bit mask does not discard an over-wide input before shifting. -/
theorem high_bit_witness : Impl.Altitude.bit (2^200 + 2^80 + 1) 200 = 1 := by
  decide +kernel

/-- An index beyond every set bit gives zero. -/
theorem above_word_witness : Impl.Altitude.bit (2^200 + 2^80 + 1) 201 = 0 := by
  decide +kernel

/-- Width zero performs no Gray-code updates, even for a multiword input. -/
theorem gray_zero_width_witness : Impl.Altitude.grayDecode 0 (2^200 + 3) = 0 := by
  decide +kernel

/-- A Gray fold wider than UInt64 retains every required shifted bit. -/
theorem gray_wide_witness : Impl.Altitude.grayDecode 80 (2^79) = 2^80 - 1 := by
  decide +kernel

/-- A word larger than its requested Gray width is not implicitly truncated. -/
theorem gray_overwide_word_witness : Impl.Altitude.grayDecode 1 (2^200 + 3) = 2^200 + 3 := by
  decide +kernel

theorem identity_zero_witness : Impl.identityCode (BitVec.ofNat 13 0) = 0 := by
  decide +kernel

theorem identity_all_bits_witness : Impl.identityCode (BitVec.ofNat 13 8191) = 4095 := by
  decide +kernel

theorem identity_reserved_bit_witness : Impl.identityCode (BitVec.ofNat 13 64) = 0 := by
  decide +kernel

#print axioms bit_eq
#print axioms grayDecode_eq
#print axioms identityCode_eq
#print axioms bit_function_eq
#print axioms grayDecode_function_eq
#print axioms identityCode_function_eq
#print axioms zero_bit_witness
#print axioms high_bit_witness
#print axioms above_word_witness
#print axioms gray_zero_width_witness
#print axioms gray_wide_witness
#print axioms gray_overwide_word_witness
#print axioms identity_zero_witness
#print axioms identity_all_bits_witness
#print axioms identity_reserved_bit_witness

end Lean1090.Proofs.BitExtraction

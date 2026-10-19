import Impl.PayloadBits
import Spec.PayloadBits

/-! Exact natural shifts preserve signed and unsigned payload interpretation.
The equality is unrestricted: widths may be zero or larger than machine words,
and a supplied code need not fit its declared field width. -/

namespace Lean1090.Proofs.PayloadIntegerShift

/-- The shifted sign threshold and subtraction modulus equal the original
power-of-two formula for every coding, width and natural code. -/
theorem payloadInteger_eq_old (coding : Spec.PayloadCoding) (width code : Nat) :
    Impl.payloadInteger coding width code =
      (if coding = .twosComplement ∧ code ≥ 2 ^ (width - 1) then
        (code : Int) - (2 ^ width : Nat) else code) := by
  simp only [Impl.payloadInteger, Nat.one_shiftLeft]

/-- Universal refinement, including truncated subtraction at width zero and
over-wide codes; no valid-field or bounded-input hypothesis is imposed. -/
theorem payloadInteger_eq (coding : Spec.PayloadCoding) (width code : Nat) :
    Impl.payloadInteger coding width code = Spec.payloadInteger coding width code := by
  exact payloadInteger_eq_old coding width code

/-- Function equality supports callers that pass the interpretation as a
higher-order function without exposing its optimized implementation. -/
theorem payloadInteger_function_eq : @Impl.payloadInteger = @Spec.payloadInteger := by
  funext coding width code
  exact payloadInteger_eq coding width code

/-- Width zero deliberately keeps the reference's truncated sign threshold. -/
theorem zero_width_witness :
    Impl.payloadInteger .twosComplement 0 0 = 0 ∧
    Impl.payloadInteger .twosComplement 0 1 = 0 ∧
    Impl.payloadInteger .twosComplement 0 2 = 1 := by
  decide +kernel

/-- Unsigned inputs are unchanged even when their codes exceed their widths. -/
theorem unsigned_witness :
    Impl.payloadInteger .unsigned 0 7 = 7 ∧
    Impl.payloadInteger .unsigned 8 (2^80 + 255) = (2^80 + 255 : Int) := by
  decide +kernel

/-- Both sides of the signed transition and the all-one code are checked. -/
theorem sign_boundary_witness :
    Impl.payloadInteger .twosComplement 8 127 = 127 ∧
    Impl.payloadInteger .twosComplement 8 128 = -128 ∧
    Impl.payloadInteger .twosComplement 8 255 = -1 := by
  decide +kernel

/-- A one-bit signed field distinguishes the two representable inputs. -/
theorem signed_one_bit_witness :
    Impl.payloadInteger .twosComplement 1 0 = 0 ∧
    Impl.payloadInteger .twosComplement 1 1 = -1 := by
  decide +kernel

/-- Arbitrary codes retain subtraction of one modulus, without silently
masking the supplied input down to its declared field width. -/
theorem overwide_code_witness :
    Impl.payloadInteger .twosComplement 8 256 = 0 ∧
    Impl.payloadInteger .twosComplement 8 (2^80 + 255) = (2^80 - 1 : Int) := by
  decide +kernel

/-- Widths beyond a machine word keep exact natural shift semantics. -/
theorem wide_width_witness :
    Impl.payloadInteger .twosComplement 80 (2^79 - 1) = (2^79 - 1 : Int) ∧
    Impl.payloadInteger .twosComplement 80 (2^79) = -(2^79 : Int) ∧
    Impl.payloadInteger .twosComplement 80 (2^80 - 1) = -1 := by
  decide +kernel

#print axioms payloadInteger_eq_old
#print axioms payloadInteger_eq
#print axioms payloadInteger_function_eq
#print axioms zero_width_witness
#print axioms unsigned_witness
#print axioms sign_boundary_witness
#print axioms signed_one_bit_witness
#print axioms overwide_code_witness
#print axioms wide_width_witness

end Lean1090.Proofs.PayloadIntegerShift

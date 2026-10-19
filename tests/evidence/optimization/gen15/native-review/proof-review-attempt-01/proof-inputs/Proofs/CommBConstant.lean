import Impl.CommB

/-! Sharing the exact format limit preserves every register check for all inputs. -/
namespace Lean1090.Proofs.CommBConstant

/-- The shared constant has the exact original mathematical value. -/
theorem payload_limit_eq : Impl.commBPayloadLimit = 2^56 := rfl

/-- Every original branch remains definitionally identical, for arbitrary
registers and payloads, including unsupported registers and over-wide words. -/
theorem bdsWireValid_eq_old (register word : Nat) :
    Impl.bdsWireValid register word =
      (word < 2^56 && match register with
      | 0x05 =>
        let tc := Impl.payloadBits word 1 5
        ((tc ≥ 9 && tc ≤ 18) || (tc ≥ 20 && tc ≤ 22)) && Impl.adsbHardValid word
      | 0x65 => Impl.payloadBits word 1 5 == 31 &&
        Impl.payloadBits word 6 3 < 2 && Impl.adsbHardValid word
      | 0x10 => Impl.payloadBits word 1 8 == 0x10 && Impl.payloadBits word 10 5 == 0
      | 0x17 => Impl.cbValid17 word
      | 0x18 => Impl.cbValid18 word
      | 0x19 => Impl.cbValid19 word
      | 0x20 => Impl.payloadBits word 1 8 == 0x20
      | 0x21 => Impl.cbValid21 word
      | 0x30 => Impl.payloadBits word 1 8 == 0x30
      | 0x40 => Impl.cbValid40 word
      | 0x44 => Impl.cbValid44 word
      | 0x45 => Impl.cbValid45 word
      | 0x50 => Impl.cbValid50 word
      | 0x60 => Impl.cbValid60 word
      | _ => false) := rfl

/-- No register can accept a payload at or above the exact 56-bit limit. -/
theorem rejects_out_of_range (register word : Nat) (large : 2^56 ≤ word) :
    Impl.bdsWireValid register word = false := by
  simp [Impl.bdsWireValid, Impl.commBPayloadLimit, Nat.not_lt.mpr large]

/-- Both ends of the 56-bit range lie below the shared exclusive limit. -/
theorem range_witness :
    (0 < Impl.commBPayloadLimit) = True ∧
    (2^56 - 1 < Impl.commBPayloadLimit) = True := by
  decide +kernel

/-- The exact limit and a much wider word remain rejected. -/
theorem rejection_boundary_witness :
    Impl.bdsWireValid 0x20 (2^56) = false ∧
    Impl.bdsWireValid 0x20 (2^130 + 0x20 * 2^48) = false := by
  decide +kernel

/-- A supported header below the bound still accepts, while an unsupported
register does not become valid simply because its payload is in range. -/
theorem accepted_and_unsupported_witness :
    Impl.bdsWireValid 0x20 (0x20 * 2^48) = true ∧
    Impl.bdsWireValid 0x22 (0x20 * 2^48) = false := by
  decide +kernel

#print axioms payload_limit_eq
#print axioms bdsWireValid_eq_old
#print axioms rejects_out_of_range
#print axioms range_witness
#print axioms rejection_boundary_witness
#print axioms accepted_and_unsupported_witness

end Lean1090.Proofs.CommBConstant

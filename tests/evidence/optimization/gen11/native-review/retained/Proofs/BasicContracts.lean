import Capstones

/-! Proofs of the approved rejection and ordering contracts. -/

namespace Lean1090.Proofs
open Spec

/-- Different reconstructed latitude zones force rejection, for every pair,
including malformed raw inputs and either recency ordering. -/
theorem CPRZoneRejection : Capstones.CPRZoneRejection := by
  intro even odd latest different
  unfold CPR.SameDecodedZone at different
  simp [CPR.decodeGlobal, different]

/-- An earlier timestamp returns the original state and receiver reference
without consulting either the numerical geography or reference callback. -/
theorem CPROutOfOrder : Capstones.CPROutOfOrder := by
  intro geo update state reference timestamp code altitude metadata earlier
  simp [CPR.Policy.stepAirborne, earlier]

private theorem eligible_register_mem (df : Nat) (altitude : Option Int)
    (register word : Nat) (eligible : commBEligible df altitude register word = true) :
    register ∈ commBRegisters := by
  by_cases position : register = 0x05
  · simp [commBRegisters, position]
  by_cases operation : register = 0x65
  · simp [commBEligible, operation, commBOperationEligible] at eligible
  have core : commBCoreRegisters.contains register = true := by
    simp only [commBEligible, beq_iff_eq, position, operation, Bool.and_eq_true,
      ite_false, commBCoreEligible] at eligible
    exact eligible.2.1.1
  simp only [List.contains_iff_mem] at core
  simp [commBRegisters, core]

/-- The complete candidate list contains exactly the eligible registers with
their decoded fields, including the DF20/21 and empty-payload policies. -/
theorem CommBInference : Capstones.CommBInference := by
  intro df altitude word register fields
  simp only [inferCommB, List.mem_filterMap]
  constructor
  · rintro ⟨candidate, _, result⟩
    split at result
    · rename_i eligible
      simp only [Option.map_eq_some_iff] at result
      obtain ⟨record, decoded, same⟩ := result
      cases same
      exact ⟨eligible, decoded⟩
    · simp at result
  · rintro ⟨eligible, decoded⟩
    exact ⟨register, eligible_register_mem df altitude register word eligible,
      by simp [eligible, decoded]⟩

end Lean1090.Proofs

#print axioms Lean1090.Proofs.CPRZoneRejection
#print axioms Lean1090.Proofs.CPROutOfOrder
#print axioms Lean1090.Proofs.CommBInference

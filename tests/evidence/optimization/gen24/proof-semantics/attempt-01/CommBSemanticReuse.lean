import Impl.Semantics

/-!
Sharing exact numeric-expression lists preserves the previous Comm-B payload
body for arbitrary inputs. These results concern pure `NumericField` trees;
they introduce no floating-point evaluation or callback assumption.
-/

namespace Lean1090.Proofs.CommBSemanticReuse

open Lean1090.Spec Lean1090.Spec.Semantics Lean1090.Spec.Presentation

/-- The reusable helper equals the old guarded map for every supplied list,
including duplicate keys, absent values and fields not emitted by a layout. -/
theorem commBStandardFloatsFromOracle_eq_old (register word : Nat)
    (fields : List NumericField) :
    Impl.Semantics.commBStandardFloatsFromOracle register word fields =
      (if register == 0x30 then [] else
        fields.map fun field =>
          if register == 0x44 && field.key == "temperature" then
            { field with value := some (.literal .binary64 (Impl.cbSigned word 24 11 / 4)) }
          else field) := by
  by_cases h30 : register = 0x30 <;> by_cases h44 : register = 0x44 <;>
    simp [Impl.Semantics.commBStandardFloatsFromOracle, h30, h44]

/-- The standalone public helper retains its entire previous body. -/
theorem commBStandardFloats_eq_old (register word : Nat) :
    Impl.Semantics.commBStandardFloats register word =
      (if register == 0x30 then [] else
        (Impl.Presentation.oracleCommBFloats register word).map fun field =>
          if register == 0x44 && field.key == "temperature" then
            { field with value := some (.literal .binary64 (Impl.cbSigned word 24 11 / 4)) }
          else field) := by
  by_cases h30 : register = 0x30 <;>
    simp [Impl.Semantics.commBStandardFloats,
      commBStandardFloatsFromOracle_eq_old, h30]

/-- Reusing the already-built oracle list equals the standalone standard
projection even for BDS30, whose standard numeric list is empty. -/
theorem commBStandardFloatsFromOracle_oracle_eq (register word : Nat) :
    Impl.Semantics.commBStandardFloatsFromOracle register word
      (Impl.Presentation.oracleCommBFloats register word) =
      Impl.Semantics.commBStandardFloats register word := by
  rw [commBStandardFloatsFromOracle_eq_old, commBStandardFloats_eq_old]

private def witnessFields : List NumericField :=
  [⟨"temperature", none, .omit⟩,
   ⟨"other", some (.add .binary32 (.literal .binary32 1) (.literal .binary32 2)), .null⟩,
   ⟨"temperature", some (.literal .binary64 17), .null⟩,
   ⟨"Temperature", none, .omit⟩]

/-- BDS30 discards any supplied standard expressions, even over-wide words. -/
theorem bds30_arbitrary_list_witness :
    Impl.Semantics.commBStandardFloatsFromOracle 0x30 (2^130) witnessFields = [] := by
  decide +kernel

/-- BDS44 replaces all exact temperature keys, including an absent value,
while preserving duplicates, order, missing policy and other expression trees. -/
theorem bds44_arbitrary_list_witness :
    Impl.Semantics.commBStandardFloatsFromOracle 0x44 (1024 * 2^22) witnessFields =
      [⟨"temperature", some (.literal .binary64 (-256)), .omit⟩,
       ⟨"other", some (.add .binary32 (.literal .binary32 1) (.literal .binary32 2)), .null⟩,
       ⟨"temperature", some (.literal .binary64 (-256)), .null⟩,
       ⟨"Temperature", none, .omit⟩] := by
  decide +kernel

/-- Identity branches preserve an arbitrary supplied list, including unknown
registers and the two registers delegated to ADS-B by the complete payload. -/
theorem identity_arbitrary_list_witness :
    Impl.Semantics.commBStandardFloatsFromOracle 0x05 (2^130) witnessFields = witnessFields ∧
    Impl.Semantics.commBStandardFloatsFromOracle 0x65 (2^130) witnessFields = witnessFields ∧
    Impl.Semantics.commBStandardFloatsFromOracle 0x50 (2^130) witnessFields = witnessFields ∧
    Impl.Semantics.commBStandardFloatsFromOracle 999 (2^130) witnessFields = witnessFields := by
  decide +kernel

#print axioms commBStandardFloatsFromOracle_eq_old
#print axioms commBStandardFloats_eq_old
#print axioms commBStandardFloatsFromOracle_oracle_eq
#print axioms bds30_arbitrary_list_witness
#print axioms bds44_arbitrary_list_witness
#print axioms identity_arbitrary_list_witness

end Lean1090.Proofs.CommBSemanticReuse

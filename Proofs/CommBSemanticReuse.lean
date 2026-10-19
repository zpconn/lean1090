import Impl.Semantics
import Proofs.CommBValueReuse

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

/-- The complete former payload body is preserved for every register and
natural word. Its scalar map still calls the standalone named-field helper,
and its standard expressions still use the standalone standard projection. -/
theorem commB_eq_old (register word : Nat) :
    Impl.Semantics.commB register word =
      (if register == 0x05 || register == 0x65 then Impl.Semantics.adsb word else
        let layout := (Impl.commBLayout register).getD []
        { tableValues := Impl.Semantics.tableValues layout word
          standardValues := Impl.Semantics.tableValues layout word
          oracleValues := layout.map fun c => (c.name, Impl.commBValue register word c.name)
          standardLabels := Impl.Semantics.commBLabels register word
          oracleLabels := Impl.Semantics.commBLabels register word
          standardFloats := Impl.Semantics.commBStandardFloats register word
          oracleFloats := Impl.Presentation.oracleCommBFloats register word
          standardThreat := if register == 0x30 then Impl.cbStandardThreat word else none
          oracleThreat := if register == 0x30 then some (Impl.cbThreat word) else none }) := by
  simp only [Impl.Semantics.commB, CommBValueReuse.oracleValues_eq,
    commBStandardFloatsFromOracle_oracle_eq]

/-- Both ADS-B register branches bypass all Comm-B construction for every word. -/
theorem commB_adsb_branches (word : Nat) :
    Impl.Semantics.commB 0x05 word = Impl.Semantics.adsb word ∧
    Impl.Semantics.commB 0x65 word = Impl.Semantics.adsb word := by
  simp [Impl.Semantics.commB]

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
#print axioms commB_eq_old
#print axioms commB_adsb_branches
#print axioms bds30_arbitrary_list_witness
#print axioms bds44_arbitrary_list_witness
#print axioms identity_arbitrary_list_witness

end Lean1090.Proofs.CommBSemanticReuse

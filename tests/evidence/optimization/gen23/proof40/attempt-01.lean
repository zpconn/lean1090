import Proofs.CommBQNH

/-!+Exact field-code tables for BDS40 plausibility. The statements cover every
natural payload and every selected-altitude field position. The Boolean QNH
table reuses the original rounded values without changing arithmetic order.
-/

namespace Lean1090.Proofs.CommBValidity40

theorem selected_table_size : Impl.cbSelectedValid40Table.size = 4096 := by
  simp [Impl.cbSelectedValid40Table]

theorem selected_table_get (code : Fin 4096) :
    Impl.cbSelectedValid40Table[code.val]'(by simp [selected_table_size]) =
      decide (Impl.cbSelected code.val ≤ 50000) := by
  simp [Impl.cbSelectedValid40Table]

theorem qnh_table_size : Impl.cbQNHValid40Table.size = 4096 := by
  simp [Impl.cbQNHValid40Table, CommBQNH.table_size]

theorem qnh_table_get (code : Fin 4096) :
    Impl.cbQNHValid40Table[code.val]'(by simp [qnh_table_size]) =
      (decide (Impl.cbQNHValueTable[code.val]'(by simp [CommBQNH.table_size]) ≥ 800) &&
       decide (Impl.cbQNHValueTable[code.val]'(by simp [CommBQNH.table_size]) ≤ 1200)) := by
  simp [Impl.cbQNHValid40Table]

/-- Unrestricted position and payload; the field extractor supplies the bound. -/
theorem cbSelectedValid40_eq_old (word start : Nat) :
    Impl.cbSelectedValid40 word start =
      decide (Impl.cbSelected (Impl.payloadBits word start 12) ≤ 50000) := by
  simp [Impl.cbSelectedValid40, Impl.cbSelectedValid40Table]

/-- The exact two comparisons on the original rounded software value. -/
theorem cbQNHValid40_eq_old (word : Nat) :
    Impl.cbQNHValid40 word =
      (decide (Impl.cbQNH64 word ≥ 800) && decide (Impl.cbQNH64 word ≤ 1200)) := by
  simp [Impl.cbQNHValid40, Impl.cbQNHValid40Table, Impl.cbQNH64]

/-- Every original status, spare bit and numerical condition is retained. -/
theorem cbValid40_eq_old (word : Nat) :
    Impl.cbValid40 word =
      (Impl.cbStatus word 1 2 12 && Impl.cbStatus word 14 15 12 &&
       Impl.cbStatus word 27 28 12 && Impl.payloadBits word 40 8 == 0 &&
       Impl.payloadBits word 52 2 == 0 &&
       Impl.cbSelected (Impl.payloadBits word 2 12) ≤ 50000 &&
       Impl.cbSelected (Impl.payloadBits word 15 12) ≤ 50000 &&
       Impl.cbQNH64 word ≥ 800 && Impl.cbQNH64 word ≤ 1200) := by
  simp only [Impl.cbValid40, cbSelectedValid40_eq_old, cbQNHValid40_eq_old,
    Bool.and_assoc]

theorem selected_boundary_witness :
    Impl.cbSelectedValid40 (3130 * 2^43) 2 = true ∧
    Impl.cbSelectedValid40 (3131 * 2^43) 2 = false ∧
    Impl.cbSelectedValid40 (4095 * 2^30) 15 = false := by
  simp only [cbSelectedValid40_eq_old, PayloadBits.payloadBits_eq]
  decide +kernel

theorem qnh_boundary_witness :
    Impl.cbQNHValid40 0 = true ∧
    Impl.cbQNHValid40 (3999 * 2^17) = true ∧
    Impl.cbQNHValid40 (4000 * 2^17) = true ∧
    Impl.cbQNHValid40 (4001 * 2^17) = false ∧
    Impl.cbQNHValid40 (4095 * 2^17) = false := by
  simp only [cbQNHValid40_eq_old, CommBQNH.cbQNH64_eq]
  decide +kernel

theorem overwide_witness :
    Impl.cbSelectedValid40 (2^130 + 3130 * 2^43) 2 = true ∧
    Impl.cbQNHValid40 (2^130 + 4001 * 2^17) = false := by
  simp only [cbSelectedValid40_eq_old, cbQNHValid40_eq_old,
    CommBQNH.cbQNH64_eq, PayloadBits.payloadBits_eq]
  decide +kernel

theorem zero_and_status_witness :
    Impl.cbValid40 0 = true ∧ Impl.cbValid40 (1 * 2^43) = false := by
  simp only [cbValid40_eq_old, CommBQNH.cbQNH64_eq]
  decide +kernel

#print axioms selected_table_size
#print axioms selected_table_get
#print axioms qnh_table_size
#print axioms qnh_table_get
#print axioms cbSelectedValid40_eq_old
#print axioms cbQNHValid40_eq_old
#print axioms cbValid40_eq_old
#print axioms selected_boundary_witness
#print axioms qnh_boundary_witness
#print axioms overwide_witness
#print axioms zero_and_status_witness

end Lean1090.Proofs.CommBValidity40

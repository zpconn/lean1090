import Proofs.CommBMach
import Proofs.PayloadIntegerShift

/-!
Exact BDS60 validity tables. The lookup equalities hold for every natural
payload, without a wire-width, status, or score hypothesis. The vertical-rate
projection is deliberately at the live fixed position 47; no generalized
claim about truncated field positions is needed.
-/

namespace Lean1090.Proofs.CommBValidity60

set_option maxHeartbeats 2000000
set_option maxRecDepth 4000

/-- Every ten-bit Mach code retains one validity entry. -/
theorem mach_table_size : Impl.cbMachValid60Table.size = 1024 := by
  simp [Impl.cbMachValid60Table, CommBMach.table_size]

/-- Mapping to Boolean validity preserves the exact rounded Mach value. -/
theorem mach_table_get (code : Fin 1024) :
    Impl.cbMachValid60Table[code.val]'(by simpa [mach_table_size] using code.isLt) =
      decide (Impl.cbMachValueTable[code.val]'(by
        simpa [CommBMach.table_size] using code.isLt) ≤ 1) := by
  simp [Impl.cbMachValid60Table]

/-- Every ten-bit vertical-rate code retains one validity entry. -/
theorem vertical_table_size : Impl.cbVerticalValid60Table.size = 1024 := by
  simp [Impl.cbVerticalValid60Table]

/-- Each vertical entry uses the original signed and sentinel-aware formula. -/
theorem vertical_table_get (code : Fin 1024) :
    Impl.cbVerticalValid60Table[code.val]'(by
      simpa [vertical_table_size] using code.isLt) =
      decide ((Impl.cbVertical60 code.val 47).abs ≤ 6000) := by
  simp [Impl.cbVerticalValid60Table]

/-- Keeping the low ten bits preserves the fixed-position vertical quantity,
including both magnitude sentinels and arbitrarily high discarded bits. -/
theorem vertical_projection (word : Nat) :
    Impl.cbVertical60 (Impl.payloadBits word 47 10) 47 =
      Impl.cbVertical60 word 47 := by
  simp [Impl.cbVertical60, Impl.cbSigned, PayloadBits.payloadBits_eq,
    Spec.payloadBits, Nat.mod_mod_of_dvd]

/-- The Mach validity lookup equals the original comparison for every word. -/
theorem cbMachValid60_eq (word : Nat) :
    Impl.cbMachValid60 word = decide (Impl.cbMach64 word ≤ 1) := by
  simp [Impl.cbMachValid60, Impl.cbMachValid60Table, Impl.cbMach64]

/-- The vertical validity lookup equals the original comparison for every word. -/
theorem cbVerticalValid60_eq (word : Nat) :
    Impl.cbVerticalValid60 word = decide ((Impl.cbVertical60 word 47).abs ≤ 6000) := by
  simp [Impl.cbVerticalValid60, Impl.cbVerticalValid60Table, vertical_projection]

/-- The complete prior runtime predicate, including its status and IAS checks,
is preserved without any assumption on the supplied natural-number payload. -/
theorem cbValid60_eq_old (word : Nat) :
    Impl.cbValid60 word =
      (Impl.cbStatus word 1 2 11 && Impl.cbStatus word 13 14 10 &&
       Impl.cbStatus word 24 25 10 && Impl.cbStatus word 35 36 10 &&
       Impl.cbStatus word 46 47 10 && Impl.payloadBits word 14 10 ≤ 500 &&
       Impl.cbMach64 word ≤ 1 && (Impl.cbVertical60 word 47).abs ≤ 6000) := by
  simp only [Impl.cbValid60, cbMachValid60_eq, cbVerticalValid60_eq]

/-- The unchanged vertical quantity equals the reference at every position. -/
theorem cbVertical60_eq (word start : Nat) :
    Impl.cbVertical60 word start = Spec.cbVertical60 word start := by
  simp only [Impl.cbVertical60, Spec.cbVertical60, Impl.cbSigned, Spec.cbSigned,
    PayloadBits.payloadBits_eq, PayloadIntegerShift.payloadInteger_eq]

/-- Unrestricted refinement of the complete live BDS60 validity predicate. -/
theorem cbValid60_eq (word : Nat) : Impl.cbValid60 word = Spec.cbValid60 word := by
  simp only [cbValid60_eq_old, Spec.cbValid60, Impl.cbStatus, Spec.cbStatus,
    PayloadBits.payloadBits_eq, CommBMach.cbMach64_eq, cbVertical60_eq]

/-- Function equality supports higher-order uses of the validity predicate. -/
theorem cbValid60_function_eq : Impl.cbValid60 = Spec.cbValid60 := by
  funext word
  exact cbValid60_eq word

/-- Adjacent rounded Mach values keep both sides of the inclusive bound. -/
theorem mach_boundary_witness :
    Impl.cbMachValid60 (249 * 2^22) = true ∧
    Impl.cbMachValid60 (250 * 2^22) = true ∧
    Impl.cbMachValid60 (251 * 2^22) = false := by
  simp only [cbMachValid60_eq, CommBMach.cbMach64_eq]
  decide +kernel

/-- Positive and negative vertical rates bracket 6000 ft/min symmetrically. -/
theorem vertical_boundary_witness :
    Impl.cbVerticalValid60 187 = true ∧ Impl.cbVerticalValid60 188 = false ∧
    Impl.cbVerticalValid60 837 = true ∧ Impl.cbVerticalValid60 836 = false := by
  simp only [cbVerticalValid60_eq, cbVertical60_eq]
  decide +kernel

/-- Both unavailable magnitudes remain zero under either sign bit. -/
theorem vertical_sentinel_witness :
    Impl.cbVertical60 0 47 = 0 ∧ Impl.cbVertical60 511 47 = 0 ∧
    Impl.cbVertical60 512 47 = 0 ∧ Impl.cbVertical60 1023 47 = 0 ∧
    Impl.cbVerticalValid60 0 = true ∧ Impl.cbVerticalValid60 511 = true ∧
    Impl.cbVerticalValid60 512 = true ∧ Impl.cbVerticalValid60 1023 = true := by
  simp only [cbVerticalValid60_eq, cbVertical60_eq]
  decide +kernel

/-- Values far beyond the wire width retain only the actual field bits. -/
theorem overwide_witness :
    Impl.cbMachValid60 (2^130 + 250 * 2^22) = true ∧
    Impl.cbMachValid60 (2^130 + 251 * 2^22) = false ∧
    Impl.cbVerticalValid60 (2^130 + 837) = true ∧
    Impl.cbVerticalValid60 (2^130 + 836) = false ∧
    Impl.cbVerticalValid60 (2^130 + 512) = true := by
  simp only [cbMachValid60_eq, CommBMach.cbMach64_eq,
    cbVerticalValid60_eq, cbVertical60_eq]
  decide +kernel

/-- The complete predicate keeps status consistency even when a table accepts. -/
theorem complete_status_witness :
    Impl.cbValid60 0 = true ∧ Impl.cbValid60 187 = false ∧
    Impl.cbValid60 (2^10 + 187) = true ∧
    Impl.cbValid60 (2^10 + 188) = false := by
  simp only [cbValid60_eq]
  decide +kernel

#print axioms mach_table_size
#print axioms mach_table_get
#print axioms vertical_table_size
#print axioms vertical_table_get
#print axioms vertical_projection
#print axioms cbMachValid60_eq
#print axioms cbVerticalValid60_eq
#print axioms cbValid60_eq_old
#print axioms cbVertical60_eq
#print axioms cbValid60_eq
#print axioms cbValid60_function_eq
#print axioms mach_boundary_witness
#print axioms vertical_boundary_witness
#print axioms vertical_sentinel_witness
#print axioms overwide_witness
#print axioms complete_status_witness

end Lean1090.Proofs.CommBValidity60

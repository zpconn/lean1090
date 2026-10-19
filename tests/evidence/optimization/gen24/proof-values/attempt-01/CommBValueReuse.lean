import Impl.Semantics

/-!
The shared scalar list preserves the original named lookup and every oracle
correction. Layout names are unique for all supported registers; no wire-width,
validity, status, score, or corpus-membership assumption is required.
-/

namespace Lean1090.Proofs.CommBValueReuse
open Spec

set_option maxHeartbeats 1000000
set_option maxRecDepth 4000

/-- Factoring the correction preserves the full original lookup/status body. -/
theorem commBValue_eq_old (register word : Nat) (name : String) :
    Impl.commBValue register word name = (do
      let layout ← Impl.commBLayout register
      let c ← layout.find? (fun c => c.name == name)
      let value ← Impl.payloadValue c word
      match register, name with
      | 0x10, "dte" => some (Impl.payloadBits word 41 8 + 256 * Impl.payloadBits word 49 8 : Rat)
      | 0x40, "selected_mcp" => some (Impl.cbSelected (Impl.payloadBits word 2 12))
      | 0x40, "selected_fms" => some (Impl.cbSelected (Impl.payloadBits word 15 12))
      | 0x44, "temperature" => some (Impl.cbTemperature44 word)
      | 0x50, "track" => some (Impl.cbWrapAngle value)
      | 0x50, "track_rate" =>
        if Impl.payloadBits word 37 9 == 511 then none else some value
      | 0x60, "heading" => some (Impl.cbWrapAngle value)
      | 0x60, "vrate_barometric" => some (Impl.cbVertical60 word 36)
      | 0x60, "vrate_inertial" => some (Impl.cbVertical60 word 47)
      | _, _ => some value) := by
  rfl

/-- Generic member lookup: unique projected names identify the exact element. -/
theorem find_name_of_mem {α : Type} (name : α → String) (xs : List α) (x : α)
    (unique : (xs.map name).Nodup) (member : x ∈ xs) :
    xs.find? (fun y => name y == name x) = some x := by
  induction xs with
  | nil => simp at member
  | cons y ys ih =>
    simp only [List.map_cons, List.nodup_cons] at unique
    rcases unique with ⟨absent, tail⟩
    rcases List.mem_cons.mp member with equal | member
    · subst x
      simp
    · have different : name y ≠ name x := by
        intro same
        apply absent
        exact List.mem_map.mpr ⟨x, member, same.symm⟩
      simp [List.find?_cons, different, ih tail member]

/-- Every concrete core layout has distinct names; unsupported registers use
an empty layout. This includes every spare/status column, not only quantities. -/
theorem layout_names_nodup (register : Nat) :
    (((Impl.commBLayout register).getD []).map PayloadColumn.name).Nodup := by
  unfold Impl.commBLayout
  split <;> decide +kernel

/-- A member's direct decoded value receives exactly the original correction,
including preservation of `none` before any correction can run. -/
theorem commBValue_of_mem (register word : Nat) (layout : List PayloadColumn)
    (selected : Impl.commBLayout register = some layout)
    (column : PayloadColumn) (member : column ∈ layout) :
    Impl.commBValue register word column.name =
      (Impl.payloadValue column word).bind (Impl.commBAdjustValue register word column.name) := by
  have unique : (layout.map PayloadColumn.name).Nodup := by
    simpa only [selected, Option.getD_some] using layout_names_nodup register
  have found := find_name_of_mem PayloadColumn.name layout column unique member
  simp [Impl.commBValue, selected, found]

/-- Reusing the complete standard value list preserves the ordered oracle
list for every natural register and word, including default and ADS-B codes. -/
theorem oracleValues_eq (register word : Nat) :
    Impl.Semantics.commBOracleValues register word
      (Impl.Semantics.tableValues ((Impl.commBLayout register).getD []) word) =
      ((Impl.commBLayout register).getD []).map
        (fun c => (c.name, Impl.commBValue register word c.name)) := by
  cases selected : Impl.commBLayout register with
  | none => simp [selected, Impl.Semantics.tableValues, Impl.Semantics.commBOracleValues]
  | some layout =>
    simp only [selected, Option.getD_some, Impl.Semantics.tableValues,
      Impl.Semantics.commBOracleValues, List.map_map]
    apply List.map_congr_left
    intro column member
    dsimp only [Function.comp_def]
    rw [commBValue_of_mem register word layout selected column member]

/-- The correction cannot turn an unavailable selected-altitude field present. -/
theorem absent_status_witness :
    Impl.commBValue 0x40 (7 * 2^43) "selected_mcp" = none ∧
    Impl.Semantics.commBOracleValues 0x40 (7 * 2^43)
      [("selected_mcp", none)] = [("selected_mcp", none)] := by
  decide +kernel

/-- DTE byte order and selected-altitude rounding remain exact corrections. -/
theorem dte_selected_witness :
    Impl.commBValue 0x10 258 "dte" = some 513 ∧
    Impl.commBValue 0x40 (2^55 + 7 * 2^43) "selected_mcp" = some 100 ∧
    Impl.commBValue 0x40 (2^42 + 7 * 2^30) "selected_fms" = some 100 := by
  decide +kernel

/-- Temperature wraps below -80, but not at the endpoint. -/
theorem temperature_witness :
    Impl.commBValue 0x44 (1724 * 2^22) "temperature" = some 175 ∧
    Impl.commBValue 0x44 (1728 * 2^22) "temperature" = some (-80) := by
  decide +kernel

/-- Both angle corrections retain the exact negative-code wrap. -/
theorem angle_witness :
    Impl.commBValue 0x50 (2^44 + 2047 * 2^33) "track" = some (360 - 90/512) ∧
    Impl.commBValue 0x60 (2^55 + 2047 * 2^44) "heading" = some (360 - 90/512) := by
  decide +kernel

/-- Both signs of the unavailable rate sentinel stay absent after a true status. -/
theorem track_rate_witness :
    Impl.commBValue 0x50 (2^21 + 511 * 2^11) "track_rate" = none ∧
    Impl.commBValue 0x50 (2^21 + 1023 * 2^11) "track_rate" = none ∧
    Impl.commBValue 0x50 (2^21) "track_rate" = some 0 := by
  decide +kernel

/-- Vertical sentinels and a neighboring negative rate preserve their values. -/
theorem vertical_witness :
    Impl.commBValue 0x60 (2^21 + 1023 * 2^11) "vrate_barometric" = some 0 ∧
    Impl.commBValue 0x60 (2^10 + 512) "vrate_inertial" = some 0 ∧
    Impl.commBValue 0x60 (2^10 + 513) "vrate_inertial" = some (-16352) := by
  decide +kernel

/-- Reused maps preserve order, absent entries and untouched ordinary names. -/
theorem ordered_map_witness :
    Impl.Semantics.commBOracleValues 0x50 (511 * 2^11)
      [("ordinary", some 7), ("track", some (-1)),
       ("track_rate", some 2), ("track", none)] =
      [("ordinary", some 7), ("track", some 359),
       ("track_rate", none), ("track", none)] := by
  decide +kernel

/-- Extra high bits do not narrow the theorem's domain; missing layouts/names
still return none, including the separately handled ADS-B register codes. -/
theorem overwide_default_witness :
    Impl.commBValue 0x10 (2^130 + 258) "dte" = some 513 ∧
    Impl.commBValue 0x99 (2^130 + 258) "dte" = none ∧
    Impl.commBValue 0x10 258 "absent" = none ∧
    Impl.commBValue 0x05 0 "dte" = none ∧
    Impl.commBValue 0x65 0 "dte" = none := by
  decide +kernel

#print axioms commBValue_eq_old
#print axioms find_name_of_mem
#print axioms layout_names_nodup
#print axioms commBValue_of_mem
#print axioms oracleValues_eq
#print axioms absent_status_witness
#print axioms dte_selected_witness
#print axioms temperature_witness
#print axioms angle_witness
#print axioms track_rate_witness
#print axioms vertical_witness
#print axioms ordered_map_witness
#print axioms overwide_default_witness

end Lean1090.Proofs.CommBValueReuse

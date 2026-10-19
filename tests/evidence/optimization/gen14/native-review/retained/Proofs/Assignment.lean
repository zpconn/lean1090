import Proofs.AssignmentAltitude
import Proofs.BitPacking
import Proofs.PayloadRoundTrips
import Proofs.CommBPayloadRoundTrips
import Spec.Message

/-! Equivalence of the independent encoder-side assignment and the source
decoder's report. These are conclusions proved from independently defined
functions, never extra assumptions on valid messages. -/
namespace Lean1090.Proofs.Assignment
open Spec

theorem bit_digit (word index : Nat) :
    (if word.testBit index then 1 else 0) = word / 2^index % 2 := by
  rw [Nat.testBit_eq_decide_div_mod_eq]
  have := Nat.mod_lt (word / 2^index) (by decide : 0 < 2)
  split <;> simp_all

theorem columnCode_eq (word start width : Nat) (positive : 1 ≤ start)
    (bounded : start - 1 + width ≤ 56) :
    Spec.Assignment.columnCode word start width = payloadBits word start width := by
  induction width with
  | zero => simp [Spec.Assignment.columnCode, payloadBits, Nat.mod_one]
  | succ width ih =>
    have previous : start - 1 + width ≤ 56 := by omega
    have index : 56 - (start - 1 + (width+1)) = 56 - start - width := by omega
    have oldIndex : 56 - (start - 1 + width) = (56-start-width)+1 := by omega
    have recurrence : Spec.Assignment.columnCode word start (width+1) =
        2 * Spec.Assignment.columnCode word start width +
          (if word.testBit (56-start-width) then 1 else 0) := by
      simp [Spec.Assignment.columnCode, List.range_succ, List.foldl_append]
    rw [recurrence, ih previous, bit_digit]
    simp only [payloadBits, index, oldIndex, pow_succ]
    rw [← Nat.div_div_eq_div_mul]
    rw [Nat.mul_comm (2^width) 2, Nat.mod_mul]
    omega

theorem payloadBits_lt (word start width : Nat) : payloadBits word start width < 2^width :=
  Nat.mod_lt _ (Nat.two_pow_pos _)

@[simp] theorem altitude13_all (code : Nat) :
    Spec.Assignment.altitude13 code = Altitude.decodeAC13 code := by
  by_cases h : code < 8192
  · exact altitude13_eq code h
  · have h' : 8192 ≤ code := by omega
    simp [Spec.Assignment.altitude13, Altitude.decodeAC13, h']

@[simp] theorem compatibility13_all (code : Nat) :
    Spec.Assignment.compatibility13 code = Altitude.oracleAC13 code := by
  by_cases h : code < 8192
  · exact compatibility13_eq code h
  · have h' : 8192 ≤ code := by omega
    simp [Spec.Assignment.compatibility13, Altitude.oracleAC13, h']

@[simp] theorem altitude12_all (code : Nat) :
    Spec.Assignment.altitude12 code = Altitude.decodeAC12 code := by
  by_cases h : code < 4096
  · exact (altitude12_eq code h).1
  · have h' : 4096 ≤ code := by omega
    simp [Spec.Assignment.altitude12, Altitude.decodeAC12, h, h']

@[simp] theorem compatibility12_all (code : Nat) :
    Spec.Assignment.compatibility12 code = (Altitude.oracleAC12 code).join := by
  by_cases h : code < 4096
  · exact (altitude12_eq code h).2
  · have h' : 4096 ≤ code := by omega
    simp [Spec.Assignment.compatibility12, altitude12_all, Altitude.decodeAC12,
      Altitude.oracleAC12, h, h']

theorem payloadAssignment_eq (kind word : Nat) (layout : List PayloadColumn)
    (bounds : ∀ c ∈ layout, 1 ≤ c.start ∧ c.start - 1 + c.width ≤ 56) :
    Spec.Assignment.payloadAssignment kind word layout =
      ⟨kind, decodePayloadFields layout word⟩ := by
  unfold Spec.Assignment.payloadAssignment decodePayloadFields
  congr 1
  apply List.map_congr_left
  intro c member
  rw [columnCode_eq _ _ _ (bounds c member).1 (bounds c member).2]

theorem adsb_standard_values_eq (word : Nat) :
    Spec.Assignment.adsbStandardValues word = Semantics.adsbStandardValues word := by
  simp only [Spec.Assignment.adsbStandardValues, Semantics.adsbStandardValues, altitude12_all]

theorem adsb_compatibility_values_eq (word : Nat) :
    Spec.Assignment.adsbCompatibilityValues word = Semantics.adsbOracleValues word := by
  simp only [Spec.Assignment.adsbCompatibilityValues, Semantics.adsbOracleValues,
    columnCode_eq word 14 8 (by decide) (by decide),
    columnCode_eq word 22 8 (by decide) (by decide),
    columnCode_eq word 30 6 (by decide) (by decide),
    (altitude12_eq _ (payloadBits_lt word 9 12)).2, adsbAltitude,
    Semantics.oracleReservedVelocityData, adsb_standard_values_eq]
  push_cast
  rfl

theorem adsb_meaning_eq (word : Nat) :
    Spec.Assignment.adsbMeaning word = Semantics.adsb word := by
  simp only [Spec.Assignment.adsbMeaning, Semantics.adsb,
    adsb_standard_values_eq, adsb_compatibility_values_eq]

theorem compatibility_threat_eq (word : Nat) :
    Spec.Assignment.compatibilityThreat word = cbThreat word := by
  simp only [Spec.Assignment.compatibilityThreat, cbThreat,
    columnCode_eq word 29 2 (by decide) (by decide),
    columnCode_eq word 31 24 (by decide) (by decide),
    columnCode_eq word 44 7 (by decide) (by decide),
    columnCode_eq word 51 6 (by decide) (by decide),
    columnCode_eq word 31 13 (by decide) (by decide),
    compatibility13_eq _ (payloadBits_lt word 31 13)]
  rfl

theorem standard_threat_eq (word : Nat) :
    Spec.Assignment.standardThreat word = cbStandardThreat word := by
  simp only [Spec.Assignment.standardThreat, cbStandardThreat,
    columnCode_eq word 29 2 (by decide) (by decide),
    columnCode_eq word 55 2 (by decide) (by decide),
    columnCode_eq word 31 24 (by decide) (by decide),
    columnCode_eq word 31 13 (by decide) (by decide),
    columnCode_eq word 44 7 (by decide) (by decide),
    columnCode_eq word 51 6 (by decide) (by decide),
    gillham_eq _ (payloadBits_lt word 31 13)]
  have h7 : payloadBits word 44 7 % 128 = payloadBits word 44 7 :=
    Nat.mod_eq_of_lt (payloadBits_lt word 44 7)
  have h6 : payloadBits word 51 6 % 64 = payloadBits word 51 6 :=
    Nat.mod_eq_of_lt (payloadBits_lt word 51 6)
  simp only [Fin.ofNat, h7, h6]
  rfl

theorem commB_meaning_eq (register word : Nat) :
    Spec.Assignment.commBMeaning register word = Semantics.commB register word := by
  simp only [Spec.Assignment.commBMeaning, Semantics.commB, adsb_meaning_eq,
    standard_threat_eq, compatibility_threat_eq]

theorem adsb_assignment_eq (word : Nat) :
    Spec.Assignment.adsbAssignment word =
      match decodeADSB word with | .ok r => some r | .error _ => none := by
  by_cases wide : word ≥ 2^56
  · change 72057594037927936 ≤ word at wide
    simp [Spec.Assignment.adsbAssignment, decodeADSB, wide]
  · change ¬72057594037927936 ≤ word at wide
    cases layoutH : adsbLayout word with
    | none => simp [Spec.Assignment.adsbAssignment, decodeADSB, wide, layoutH]
    | some layout =>
      have same := payloadAssignment_eq (adsbKind word) word layout
        (PayloadRoundTrip.adsb_columns_in_bounds _ _ layoutH)
      cases valid : adsbHardValid word <;>
        simp [Spec.Assignment.adsbAssignment, decodeADSB, wide, layoutH, valid, same]

theorem candidate_eq (df : Nat) (outer : Option Int) (register word : Nat) :
    Spec.Assignment.candidate df outer register word = commBEligible df outer register word := by
  simp only [Spec.Assignment.candidate, commBEligible, commBPositionEligible,
    commBOperationEligible, columnCode_eq word 1 5 (by decide) (by decide),
    columnCode_eq word 9 12 (by decide) (by decide), compatibility12_all, adsbAltitude]
  rfl

theorem eligible_wire_valid (df : Nat) (outer : Option Int) (register word : Nat)
    (eligible : commBEligible df outer register word = true) :
    bdsWireValid register word = true := by
  unfold commBEligible at eligible
  simp only [Bool.and_eq_true] at eligible
  have h := eligible.2
  split at h
  · rename_i isPosition
    have reg : register = 5 := by simpa using isPosition
    subst register
    simp only [commBPositionEligible, Bool.and_eq_true] at h
    exact h.1.2
  · split at h
    · simp [commBOperationEligible] at h
    · simp only [commBCoreEligible, Bool.and_eq_true] at h
      exact h.1.2

theorem commB_assignments_eq (df : Nat) (outer : Option Int) (word : Nat) :
    Spec.Assignment.commBAssignments df outer word = inferCommB df outer word := by
  unfold Spec.Assignment.commBAssignments inferCommB
  apply List.filterMap_congr
  intro register member
  rw [candidate_eq]
  by_cases eligible : commBEligible df outer register word = true
  · simp only [eligible, ite_true]
    have valid := eligible_wire_valid df outer register word eligible
    cases selected : bdsLayout register word with
    | none => simp [decodeBDS, selected]
    | some layout =>
      have same := payloadAssignment_eq register word layout
        (PayloadRoundTrip.bds_columns_in_bounds _ _ _ selected)
      simp [decodeBDS, selected, valid, same]
  · simp [eligible]

theorem gnss_payload_eq (word : Nat) :
    Altitude.decodeGNSSMetres (payloadBits word 9 12) = some (payloadBits word 9 12) :=
  if_pos (payloadBits_lt word 9 12)

theorem altitude_eq (f : Frame) : Spec.Assignment.altitude f = frameAltitude f := by
  rcases f with ⟨body, parity⟩
  cases body <;>
    simp [Spec.Assignment.altitude, frameAltitude, columnCode_eq,
      altitude13_all, altitude12_all, gnss_payload_eq]
  all_goals split <;> simp_all

theorem expected_report_eq (f : Frame) : Spec.Assignment.expectedReport f = report f := by
  rcases f with ⟨body, parity⟩
  cases body <;>
    simp only [Spec.Assignment.expectedReport, report, frameSyndrome, frameAddress,
      frameIdentity, frameADSB, frameCommB, altitude_eq, adsb_assignment_eq,
      commB_assignments_eq, Spec.Assignment.outerAltitude, frameOracleAltitude,
      compatibility13_all, adsb_meaning_eq, commB_meaning_eq,
      columnCode_eq _ 1 5 (by decide) (by decide),
      columnCode_eq _ 12 13 (by decide) (by decide)]
  all_goals first | rfl | (cases ‹Bool› <;> rfl)

#print axioms expected_report_eq

end Lean1090.Proofs.Assignment

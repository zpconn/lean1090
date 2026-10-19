import Capstones
import Proofs.BitPacking

/-! Generic inverses for the published contiguous payload schemas. -/
namespace Lean1090.Proofs.PayloadRoundTrip
open Spec
set_option maxHeartbeats 1000000
set_option maxRecDepth 10000
set_option linter.unusedSimpArgs false

/-- The columns cover the indicated low bits without gaps or overlap. -/
def Dense : Nat → List PayloadColumn → Prop
  | remaining, [] => remaining = 0
  | remaining, c :: cs =>
      1 ≤ c.start ∧ c.start - 1 + remaining = 56 ∧
      c.width ≤ remaining ∧ Dense (remaining - c.width) cs

instance (remaining : Nat) (cs : List PayloadColumn) : Decidable (Dense remaining cs) := by
  induction cs generalizing remaining with
  | nil => exact inferInstanceAs (Decidable (remaining = 0))
  | cons c cs ih =>
      exact @instDecidableAnd _ _ inferInstance (@instDecidableAnd _ _ inferInstance
        (@instDecidableAnd _ _ inferInstance (ih _)))

theorem encoded_bound (cs : List PayloadColumn) (fs : List PayloadField) (n : Nat)
    (dense : Dense n cs) (valid : ValidPayloadFields cs fs) :
    encodePayloadFields cs fs < 2 ^ n := by
  induction cs generalizing fs n with
  | nil => cases fs <;> simp_all [ValidPayloadFields, encodePayloadFields, Dense]
  | cons c cs ih =>
    cases fs with
    | nil => simp [ValidPayloadFields] at valid
    | cons f fs =>
      rcases valid with ⟨name, bounded, valid⟩
      rcases dense with ⟨start, position, width, dense⟩
      have trailing := ih fs (n-c.width) dense valid
      have shift : 56 - (c.start - 1 + c.width) = n - c.width := by omega
      have decomposition : n = c.width + (n - c.width) := by omega
      simp only [encodePayloadFields, shift]
      have power : 2^n = 2^c.width * 2^(n-c.width) := by
        conv_lhs => rw [decomposition]
        exact pow_add _ _ _
      rw [power]
      have product := Nat.mul_le_mul_right (2 ^ (n-c.width)) (show f.code + 1 ≤ 2 ^ c.width by omega)
      nlinarith

theorem decode_encode_high (cs : List PayloadColumn) (fs : List PayloadField) (n high : Nat)
    (dense : Dense n cs) (valid : ValidPayloadFields cs fs) :
    decodePayloadFields cs (high * 2 ^ n + encodePayloadFields cs fs) = fs := by
  induction cs generalizing fs n high with
  | nil => cases fs <;> simp_all [ValidPayloadFields, decodePayloadFields]
  | cons c cs ih =>
    cases fs with
    | nil => simp [ValidPayloadFields] at valid
    | cons f fs =>
      rcases valid with ⟨name, bounded, valid⟩
      rcases dense with ⟨start, position, width, dense⟩
      have trailing := encoded_bound cs fs (n-c.width) dense valid
      have shift : 56 - (c.start - 1 + c.width) = n - c.width := by omega
      have decomposition : n = c.width + (n - c.width) := by omega
      have representation : high * 2 ^ n + encodePayloadFields (c::cs) (f::fs) =
          (high * 2 ^ c.width + f.code) * 2 ^ (n-c.width) + encodePayloadFields cs fs := by
        simp only [encodePayloadFields, shift]
        have power : 2^n = 2^c.width * 2^(n-c.width) := by
          conv_lhs => rw [decomposition]
          exact pow_add _ _ _
        rw [power]
        ring
      have head : payloadBits ((high * 2 ^ c.width + f.code) * 2 ^ (n-c.width) +
          encodePayloadFields cs fs) c.start c.width = f.code := by
        unfold payloadBits
        rw [shift, Nat.add_comm _ (encodePayloadFields cs fs),
          Nat.add_mul_div_right _ _ (Nat.two_pow_pos _), Nat.div_eq_of_lt trailing,
          Nat.zero_add, Nat.add_comm, Nat.add_mul_mod_self_right, Nat.mod_eq_of_lt bounded]
      rw [representation]
      change ({name := c.name, code := payloadBits _ c.start c.width} ::
        decodePayloadFields cs _) = f :: fs
      rw [head, ih fs (n-c.width) (high * 2 ^ c.width + f.code) dense valid]
      congr 1
      cases f
      simp only [PayloadField.mk.injEq]
      exact ⟨name.symm, True.intro⟩

theorem decode_encodePayloadFields (cs : List PayloadColumn) (fs : List PayloadField)
    (dense : Dense 56 cs) (valid : ValidPayloadFields cs fs) :
    decodePayloadFields cs (encodePayloadFields cs fs) = fs := by
  simpa using decode_encode_high cs fs 56 0 dense valid

theorem encode_decode_low (cs : List PayloadColumn) (word n : Nat) (dense : Dense n cs) :
    encodePayloadFields cs (decodePayloadFields cs word) = word % 2 ^ n := by
  induction cs generalizing n with
  | nil =>
      have : n = 0 := dense
      subst n
      exact (Nat.mod_one word).symm
  | cons c cs ih =>
    rcases dense with ⟨start, position, width, dense⟩
    have shift : 56 - (c.start - 1 + c.width) = n - c.width := by omega
    have decomposition : n = (n - c.width) + c.width := by omega
    change payloadBits word c.start c.width * 2 ^ (56-(c.start-1+c.width)) +
      encodePayloadFields cs (decodePayloadFields cs word) = _
    rw [ih _ dense, payloadBits, shift]
    conv_rhs => rw [decomposition, pow_add, Nat.mod_mul]
    ring

theorem encode_decodePayloadFields (cs : List PayloadColumn) (word : Nat)
    (dense : Dense 56 cs) (bounded : word < 2^56) :
    encodePayloadFields cs (decodePayloadFields cs word) = word := by
  rw [encode_decode_low cs word 56 dense, Nat.mod_eq_of_lt bounded]

theorem columns_in_bounds (cs : List PayloadColumn) (n : Nat) (dense : Dense n cs) :
    ∀ c ∈ cs, 1 ≤ c.start ∧ c.start - 1 + c.width ≤ 56 := by
  induction cs generalizing n with
  | nil => simp
  | cons c cs ih =>
    rcases dense with ⟨start, position, width, dense⟩
    intro column member
    rcases List.mem_cons.mp member with rfl | member
    · exact ⟨start, by omega⟩
    · exact ih _ dense column member

/-- Named-column geometry ignores scale metadata and is checked independently. -/
def namedPosition (cs : List PayloadColumn) (name : String) : Option (Nat × Nat) :=
  (cs.find? (fun c => c.name == name)).map (fun c => (c.start,c.width))

theorem decoded_lookup (cs : List PayloadColumn) (word kind : Nat) (name : String) :
    payloadField ⟨kind, decodePayloadFields cs word⟩ name =
      (cs.find? (fun c => c.name == name)).map
        (fun c => payloadBits word c.start c.width) := by
  simp [payloadField, decodePayloadFields, List.find?_map, Function.comp_def, Option.map_map]

theorem lookup_position (cs : List PayloadColumn) (word kind start bits : Nat) (name : String)
    (position : namedPosition cs name = some (start,bits)) :
    payloadField ⟨kind, decodePayloadFields cs word⟩ name = some (payloadBits word start bits) := by
  rw [decoded_lookup]
  unfold namedPosition at position
  cases found : cs.find? (fun c => c.name == name) with
  | none => simp [found] at position
  | some c =>
    simp only [found, Option.map_some, Option.some.injEq, Prod.mk.injEq] at position
    simp [position.1, position.2]

/-- Finite schema validation examines table geometry, never message values. -/
def ADSBShape (kind : Nat) (layout : List PayloadColumn) : Prop :=
  Dense 56 layout ∧ namedPosition layout "tc" = some (1,5) ∧
  ((namedPosition layout "subtype").elim True (fun p => p.2 ≤ 3)) ∧
  ((namedPosition layout "version").elim True (fun p => p.2 ≤ 3)) ∧
  (kind / 64 = 29 → namedPosition layout "subtype" = some (6,2)) ∧
  (kind / 64 = 19 ∨ kind / 64 = 28 ∨ kind / 64 = 31 →
    namedPosition layout "subtype" = some (6,3)) ∧
  (kind / 64 = 31 ∧ kind / 8 % 8 < 2 → namedPosition layout "version" = some (41,3)) ∧
  ((9 ≤ kind / 64 ∧ kind / 64 ≤ 18) ∨ (20 ≤ kind / 64 ∧ kind / 64 ≤ 22) →
    namedPosition layout "altitude_code" = some (9,12)) ∧
  (kind / 64 = 31 ∧ kind / 8 % 8 < 2 →
    namedPosition layout "cc_reserved0" = some (9,2) ∧
    namedPosition layout "om_reserved" = some (25,2))

instance (kind : Nat) (layout : List PayloadColumn) : Decidable (ADSBShape kind layout) := by
  unfold ADSBShape
  cases namedPosition layout "subtype" <;> cases namedPosition layout "version" <;>
    simp only [Option.elim] <;> infer_instance

private theorem adsb_shape_finite : ∀ kind : Fin 2048,
    ADSBShape kind ((adsbLayoutOfKind kind).getD []) := by decide +kernel

theorem adsb_shape (kind : Nat) (layout : List PayloadColumn)
    (selected : adsbLayoutOfKind kind = some layout) : ADSBShape kind layout := by
  have bounded : kind < 2048 := by
    unfold adsbLayoutOfKind at selected
    dsimp only at selected
    split at selected
    · contradiction
    · omega
  have checked := adsb_shape_finite ⟨kind,bounded⟩
  simpa only [selected, Option.getD_some] using checked

theorem adsb_columns_in_bounds (kind : Nat) (layout : List PayloadColumn)
    (selected : adsbLayoutOfKind kind = some layout) :
    ∀ c ∈ layout, 1 ≤ c.start ∧ c.start - 1 + c.width ≤ 56 :=
  columns_in_bounds layout 56 (adsb_shape kind layout selected).1

theorem decoded_lookup_bound (cs : List PayloadColumn) (word kind : Nat) (name : String)
    (bounds : (namedPosition cs name).elim True (fun p => p.2 ≤ 3)) :
    (payloadField ⟨kind, decodePayloadFields cs word⟩ name).getD 0 < 8 := by
  rw [decoded_lookup]
  unfold namedPosition at bounds
  cases found : cs.find? (fun c => c.name == name) with
  | none => simp [found]
  | some c =>
    simp only [found, Option.map_some, Option.elim_some] at bounds
    simp only [Option.map_some, Option.getD_some]
    have bound : payloadBits word c.start c.width < 2^c.width :=
      Nat.mod_lt _ (Nat.two_pow_pos _)
    have powbound : 2^c.width ≤ 2^3 := Nat.pow_le_pow_right (by decide) bounds
    omega

theorem adsb_canonical (kind word : Nat) (layout : List PayloadColumn)
    (selected : adsbLayoutOfKind kind = some layout)
    (coherent : kind = adsbAssignmentKind ⟨kind, decodePayloadFields layout word⟩) :
    adsbKind word = kind := by
  rcases adsb_shape kind layout selected with
    ⟨dense, tcPosition, stBound, verBound, st29, stOther, verPosition, altPosition, reserved⟩
  let record : PayloadRecord := ⟨kind, decodePayloadFields layout word⟩
  let tc := (payloadField record "tc").getD 0
  let st := (payloadField record "subtype").getD 0
  let ver := (payloadField record "version").getD 0
  have stLt : st < 8 := decoded_lookup_bound layout word kind "subtype" stBound
  have verLt : ver < 8 := decoded_lookup_bound layout word kind "version" verBound
  have tcEq : payloadBits word 1 5 = tc := by
    dsimp [tc, record]
    rw [lookup_position layout word kind 1 5 "tc" tcPosition]
    rfl
  have equation : kind = tc * 64 + (if tc = 19 ∨ tc = 28 ∨ tc = 29 ∨ tc = 31 then st*8 else 0) +
      (if tc = 31 ∧ st < 2 then ver else 0) := by
    simpa only [adsbAssignmentKind, Bool.or_eq_true, Bool.and_eq_true,
      beq_iff_eq, decide_eq_true_eq, or_assoc] using coherent
  have kindTc : kind / 64 = tc := by split_ifs at equation <;> omega
  have kindSt (special : tc = 19 ∨ tc = 28 ∨ tc = 29 ∨ tc = 31) : kind / 8 % 8 = st := by
    rw [ite_eq_left special] at equation
    split_ifs at equation <;> omega
  have subtypeEq (special : tc = 19 ∨ tc = 28 ∨ tc = 29 ∨ tc = 31) :
      (if tc = 29 then payloadBits word 6 2 else payloadBits word 6 3) = st := by
    dsimp [st, record]
    by_cases h : tc = 29
    · rw [ite_eq_left h, lookup_position layout word kind 6 2 "subtype" (st29 (by omega))]
      rfl
    · rw [ite_eq_right h, lookup_position layout word kind 6 3 "subtype" (stOther (by omega))]
      rfl
  have versionEq (special : tc = 31 ∧ st < 2) : payloadBits word 41 3 = ver := by
    dsimp [ver, record]
    rw [lookup_position layout word kind 41 3 "version" (verPosition ⟨by omega,
      by rw [kindSt (by omega)]; exact special.2⟩)]
    rfl
  unfold adsbKind
  simp only [tcEq, Bool.or_eq_true, Bool.and_eq_true, beq_iff_eq, decide_eq_true_eq, or_assoc]
  by_cases special : tc = 19 ∨ tc = 28 ∨ tc = 29 ∨ tc = 31
  · rw [subtypeEq special]
    by_cases version : tc = 31 ∧ st < 2
    · rw [ite_eq_left version, versionEq version]
      simpa only [ite_eq_left version] using equation.symm
    · rw [ite_eq_right version]
      simpa only [ite_eq_right version] using equation.symm
  · have not31 : tc ≠ 31 := by omega
    rw [ite_eq_right special]
    have noVersion : ¬ (tc = 31 ∧ (if tc = 29 then payloadBits word 6 2 else payloadBits word 6 3) < 2) := by omega
    rw [ite_eq_right noVersion]
    have noAssignedVersion : ¬ (tc = 31 ∧ st < 2) := by omega
    simpa only [ite_eq_right special, ite_eq_right noAssignedVersion] using equation.symm

theorem adsb_fields_forward (f : PayloadRecord) (valid : ValidADSBFields f) :
    decodeADSBFields (encodeADSB f) = .ok f := by
  unfold ValidADSBFields at valid
  cases selected : adsbLayoutOfKind f.kind with
  | none => simp [selected] at valid
  | some layout =>
    simp only [selected, Option.elim_some] at valid
    have dense := (adsb_shape f.kind layout selected).1
    have inverse := decode_encodePayloadFields layout f.fields dense valid.1
    have bounded := encoded_bound layout f.fields 56 dense valid.1
    have canonical := adsb_canonical f.kind (encodePayloadFields layout f.fields) layout selected
      (by simpa only [inverse] using valid.2)
    simp only [encodeADSB, selected, decodeADSBFields, show ¬ encodePayloadFields layout f.fields ≥ 2^56 by omega,
      ite_false, adsbLayout, canonical, inverse]

theorem adsb_fields_reverse (word : Nat) (f : PayloadRecord)
    (decoded : decodeADSBFields word = .ok f) : encodeADSB f = word := by
  unfold decodeADSBFields at decoded
  split at decoded
  · contradiction
  · rename_i bounded
    cases selected : adsbLayout word with
    | none => simp [selected] at decoded
    | some layout =>
      simp only [selected, Except.ok.injEq] at decoded
      subst f
      change adsbLayoutOfKind (adsbKind word) = some layout at selected
      simp only [encodeADSB, selected]
      exact encode_decodePayloadFields layout word (adsb_shape _ _ selected).1 (by omega)

theorem adsb_kind_tc (word : Nat) : adsbKind word / 64 = payloadBits word 1 5 := by
  have st2 : payloadBits word 6 2 < 4 := Nat.mod_lt _ (by decide)
  have st3 : payloadBits word 6 3 < 8 := Nat.mod_lt _ (by decide)
  have ver : payloadBits word 41 3 < 8 := Nat.mod_lt _ (by decide)
  unfold adsbKind
  dsimp only
  split_ifs <;> omega

theorem adsb_kind_st (word : Nat) (tc31 : payloadBits word 1 5 = 31) :
    adsbKind word / 8 % 8 = payloadBits word 6 3 := by
  have st3 : payloadBits word 6 3 < 8 := Nat.mod_lt _ (by decide)
  have ver : payloadBits word 41 3 < 8 := Nat.mod_lt _ (by decide)
  simp [adsbKind, tc31]
  split_ifs <;> omega

theorem adsb_valid_fields (f : PayloadRecord) (valid : ValidADSB f) : ValidADSBFields f := by
  unfold ValidADSB ValidADSBFields at *
  cases selected : adsbLayoutOfKind f.kind with
  | none => simp [selected] at valid
  | some layout =>
    simp only [selected, Option.elim_some] at valid ⊢
    exact ⟨valid.1, valid.2.1⟩

theorem adsb_hard_valid (f : PayloadRecord) (valid : ValidADSB f) :
    adsbHardValid (encodeADSB f) = true := by
  have forward := adsb_fields_forward f (adsb_valid_fields f valid)
  unfold ValidADSB at valid
  cases selected : adsbLayoutOfKind f.kind with
  | none => simp [selected] at valid
  | some layout =>
    simp only [selected, Option.elim_some] at valid
    have dense := (adsb_shape f.kind layout selected).1
    have inverse := decode_encodePayloadFields layout f.fields dense valid.1
    let word := encodePayloadFields layout f.fields
    have canonical : adsbKind word = f.kind := adsb_canonical f.kind word layout selected
      (by simpa only [word, inverse] using valid.2.1)
    have tcEq : payloadBits word 1 5 = f.kind / 64 := by rw [← canonical, adsb_kind_tc]
    have subtypeEq (tc31 : f.kind / 64 = 31) : payloadBits word 6 3 = f.kind / 8 % 8 := by
      rw [← canonical, adsb_kind_st word (by omega)]
    have lookup (name : String) (start bits : Nat) (pos : namedPosition layout name = some (start,bits)) :
        payloadField f name = some (payloadBits word start bits) := by
      have found := lookup_position layout word f.kind start bits name pos
      simpa only [word, inverse] using found
    rcases adsb_shape f.kind layout selected with
      ⟨_, _, _, _, _, _, _, altitude, reserved⟩
    simp only [encodeADSB, selected]
    change adsbHardValid word = true
    unfold adsbHardValid
    simp only [tcEq, Bool.or_eq_true, Bool.and_eq_true, decide_eq_true_eq, beq_iff_eq]
    by_cases alt : (9 ≤ f.kind / 64 ∧ f.kind / 64 ≤ 18) ∨ (20 ≤ f.kind / 64 ∧ f.kind / 64 ≤ 22)
    · rw [ite_eq_left alt]
      have accepts := valid.2.2
      rw [ite_eq_left alt, lookup "altitude_code" 9 12 (altitude alt), Option.getD_some] at accepts
      exact accepts
    · rw [ite_eq_right alt]
      by_cases tc31 : f.kind / 64 = 31
      · rw [subtypeEq tc31]
        by_cases sub : f.kind / 8 % 8 < 2
        · rw [ite_eq_left ⟨tc31,sub⟩]
          have accepts := valid.2.2
          rw [ite_eq_right alt, ite_eq_left ⟨tc31,sub⟩] at accepts
          rcases reserved ⟨tc31,sub⟩ with ⟨cc,om⟩
          rw [lookup "cc_reserved0" 9 2 cc, lookup "om_reserved" 25 2 om] at accepts
          simpa only [Option.some.injEq, Bool.and_eq_true, beq_iff_eq] using accepts
        · simp [sub]
      · simp [tc31]

theorem adsb_forward (f : PayloadRecord) (valid : ValidADSB f) :
    decodeADSB (encodeADSB f) = .ok f := by
  have forward := adsb_fields_forward f (adsb_valid_fields f valid)
  have hard := adsb_hard_valid f valid
  unfold decodeADSBFields at forward
  unfold decodeADSB
  split at forward
  · contradiction
  · rename_i bounded
    rw [ite_eq_right bounded]
    cases selected : adsbLayout (encodeADSB f) with
    | none => simp [selected] at forward
    | some layout => simpa only [selected, hard, ite_true] using forward

theorem adsb_reverse (word : Nat) (f : PayloadRecord) (decoded : decodeADSB word = .ok f) :
    encodeADSB f = word := by
  apply adsb_fields_reverse word f
  unfold decodeADSB at decoded
  unfold decodeADSBFields
  split at decoded
  · contradiction
  · rename_i bounded
    rw [ite_eq_right bounded]
    cases selected : adsbLayout word with
    | none => simp [selected] at decoded
    | some layout =>
      simp only [selected] at decoded ⊢
      split at decoded
      · exact decoded
      · contradiction

end Lean1090.Proofs.PayloadRoundTrip

namespace Lean1090.Proofs

theorem ADSBFieldRoundTrips : Capstones.ADSBFieldRoundTrips :=
  ⟨PayloadRoundTrip.adsb_fields_forward, PayloadRoundTrip.adsb_fields_reverse⟩

theorem ADSBRoundTrips : Capstones.ADSBRoundTrips :=
  ⟨PayloadRoundTrip.adsb_forward, PayloadRoundTrip.adsb_reverse⟩

#print axioms ADSBFieldRoundTrips
#print axioms ADSBRoundTrips
end Lean1090.Proofs

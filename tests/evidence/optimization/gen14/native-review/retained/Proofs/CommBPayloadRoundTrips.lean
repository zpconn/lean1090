import Proofs.PayloadRoundTrips

namespace Lean1090.Proofs.PayloadRoundTrip
open Spec
set_option maxHeartbeats 1000000
set_option maxRecDepth 10000
set_option linter.unusedSimpArgs false

/-- Every direct core register covers all 56 payload bits. -/
theorem commb_shape (register : Nat) (layout : List PayloadColumn)
    (selected : commBLayout register = some layout) :
    Dense 56 layout ∧
      (register = 0x10 ∨ register = 0x20 ∨ register = 0x30 →
        namedPosition layout "bds" = some (1,8)) := by
  unfold commBLayout at selected
  split at selected <;> cases selected <;> decide +kernel

/-- The operational-status prefix always contains the three discriminants. -/
theorem operation_shape (surface : Bool) (version : Nat) :
    let layout := adsbOperationPrefix surface ++ adsbOperationSuffix surface version
    Dense 56 layout ∧ namedPosition layout "tc" = some (1,5) ∧
      namedPosition layout "subtype" = some (6,3) ∧
      namedPosition layout "version" = some (41,3) := by
  dsimp only
  unfold adsbOperationSuffix
  split_ifs <;> cases surface <;> decide +kernel

theorem bds_columns_in_bounds (register word : Nat) (layout : List PayloadColumn)
    (selected : bdsLayout register word = some layout) :
    ∀ c ∈ layout, 1 ≤ c.start ∧ c.start - 1 + c.width ≤ 56 := by
  unfold bdsLayout at selected
  split at selected
  · cases selected
    exact columns_in_bounds _ 56 (by decide +kernel)
  · split at selected
    · exact adsb_columns_in_bounds (adsbKind word) layout selected
    · exact columns_in_bounds _ 56 (commb_shape _ _ selected).1

theorem adsb_operation_layout (word : Nat) (tc31 : payloadBits word 1 5 = 31)
    (stLt : payloadBits word 6 3 < 2) :
    adsbLayout word = some (adsbOperationPrefix (payloadBits word 6 3 == 1) ++
      adsbOperationSuffix (payloadBits word 6 3 == 1) (payloadBits word 41 3)) := by
  have versionLt : payloadBits word 41 3 < 8 := Nat.mod_lt _ (by decide)
  have versionEq : adsbKind word % 8 = payloadBits word 41 3 := by
    simp [adsbKind, tc31, stLt]
    omega
  simp [adsbLayout, adsbLayoutOfKind, adsb_kind_tc, tc31,
    adsb_kind_st word tc31, versionEq, stLt]

theorem bds_assignment_dense (f : PayloadRecord) (layout : List PayloadColumn)
    (selected : bdsAssignmentLayout f = some layout) : Dense 56 layout := by
  unfold bdsAssignmentLayout at selected
  split at selected
  · cases selected
    decide +kernel
  · split at selected
    · dsimp only at selected
      split at selected
      · cases selected
        exact (operation_shape _ _).1
      · contradiction
    · exact (commb_shape _ _ selected).1

theorem bds_encoded_lookup (f : PayloadRecord) (layout : List PayloadColumn)
    (selected : bdsAssignmentLayout f = some layout) (valid : ValidPayloadFields layout f.fields)
    (name : String) (start bits : Nat) (position : namedPosition layout name = some (start,bits)) :
    payloadField f name = some (payloadBits (encodePayloadFields layout f.fields) start bits) := by
  have inverse := decode_encodePayloadFields layout f.fields (bds_assignment_dense f layout selected) valid
  have found := lookup_position layout (encodePayloadFields layout f.fields) f.kind start bits name position
  simpa only [inverse] using found

theorem bds_assignment_decoding_layout (f : PayloadRecord) (layout : List PayloadColumn)
    (selected : bdsAssignmentLayout f = some layout) (valid : ValidPayloadFields layout f.fields)
    (structural : bdsStructuralValid f.kind (encodePayloadFields layout f.fields) = true) :
    bdsLayout f.kind (encodePayloadFields layout f.fields) = some layout := by
  by_cases five : f.kind = 5
  · simpa only [bdsLayout, bdsAssignmentLayout, five, beq_self_eq_true, ite_true] using selected
  by_cases op : f.kind = 101
  · have selectedOriginal := selected
    simp only [bdsAssignmentLayout, op, show (101 == 5) = false by decide,
      Bool.false_eq_true, ite_false, beq_self_eq_true, ite_true] at selected
    split at selected
    · cases selected
      let subtype := (payloadField f "subtype").getD 0
      let version := (payloadField f "version").getD 0
      let word := encodePayloadFields (adsbOperationPrefix (subtype == 1) ++
        adsbOperationSuffix (subtype == 1) version) f.fields
      have shape := operation_shape (subtype == 1) version
      have stEq := bds_encoded_lookup f _ selectedOriginal valid "subtype" 6 3 shape.2.2.1
      have verEq := bds_encoded_lookup f _ selectedOriginal valid "version" 41 3 shape.2.2.2
      have parts : word < 2^56 ∧ payloadBits word 1 5 = 31 ∧ payloadBits word 6 3 < 2 := by
        simpa only [bdsStructuralValid, op, Bool.and_eq_true, decide_eq_true_eq,
          beq_iff_eq] using structural
      have tc31 := parts.2.1
      have stLt := parts.2.2
      simp only [bdsLayout, op, show (101 == 5) = false by decide,
        Bool.false_eq_true, ite_false, beq_self_eq_true, ite_true]
      rw [adsb_operation_layout _ tc31 stLt]
      have stEq' : subtype = payloadBits word 6 3 := by
        dsimp only [subtype]
        rw [stEq]
        rfl
      have verEq' : version = payloadBits word 41 3 := by
        dsimp only [version]
        rw [verEq]
        rfl
      rw [← stEq', ← verEq']
    · contradiction
  · simpa only [bdsLayout, bdsAssignmentLayout, show (f.kind == 5) = false by simp [five],
      show (f.kind == 101) = false by simp [op], Bool.false_eq_true, ite_false] using selected

theorem bds_wire_structural (register word : Nat) (wire : bdsWireValid register word = true) :
    bdsStructuralValid register word = true := by
  unfold bdsWireValid at wire
  simp only [Bool.and_eq_true, decide_eq_true_eq] at wire
  rcases wire with ⟨bounded, wire⟩
  unfold bdsStructuralValid
  simp only [bounded, decide_true, Bool.true_and]
  split at wire <;> simp_all [commBLayout]

theorem bds_fields_structural (f : PayloadRecord) (layout : List PayloadColumn)
    (selected : bdsAssignmentLayout f = some layout) (valid : ValidPayloadFields layout f.fields)
    (discriminants : bdsFieldDiscriminants f = true) :
    bdsStructuralValid f.kind (encodePayloadFields layout f.fields) = true := by
  have bounded := encoded_bound layout f.fields 56 (bds_assignment_dense f layout selected) valid
  unfold bdsStructuralValid
  simp only [bounded, decide_true, Bool.true_and]
  by_cases five : f.kind = 5
  · have selected' := selected
    simp only [bdsAssignmentLayout, five, beq_self_eq_true, ite_true, Option.some.injEq] at selected'
    subst layout
    have tcPosition : namedPosition adsbPositionLayout "tc" = some (1,5) := by decide +kernel
    have tcEq := bds_encoded_lookup f _ selected valid "tc" 1 5 tcPosition
    simpa only [bdsFieldDiscriminants, five, tcEq, Option.getD_some] using discriminants
  by_cases op : f.kind = 101
  · have selected' := selected
    simp only [bdsAssignmentLayout, op, show (101 == 5) = false by decide,
      Bool.false_eq_true, ite_false, beq_self_eq_true, ite_true] at selected'
    split at selected'
    · cases selected'
      have shape := operation_shape ((payloadField f "subtype").getD 0 == 1)
        ((payloadField f "version").getD 0)
      have tcEq := bds_encoded_lookup f _ selected valid "tc" 1 5 shape.2.1
      have stEq := bds_encoded_lookup f _ selected valid "subtype" 6 3 shape.2.2.1
      have parts : payloadField f "tc" = some 31 ∧ (payloadField f "subtype").getD 8 < 2 := by
        simpa only [bdsFieldDiscriminants, op, Bool.and_eq_true, beq_iff_eq, decide_eq_true_eq] using discriminants
      have tcVal := Option.some.inj (tcEq.symm.trans parts.1)
      have stLt := parts.2
      rw [stEq] at stLt
      simpa only [op, Bool.and_eq_true, beq_iff_eq, decide_eq_true_eq, Option.getD_some] using And.intro tcVal stLt
    · contradiction
  · have core : commBLayout f.kind = some layout := by simpa [bdsAssignmentLayout, five, op] using selected
    have header := (commb_shape _ _ core).2
    unfold bdsFieldDiscriminants at discriminants
    split at discriminants
    all_goals first
      | contradiction
      | (rename_i h; have eq := bds_encoded_lookup f _ selected valid "bds" 1 8 (header (by omega));
         simpa only [eq, Option.some.injEq, beq_iff_eq] using discriminants)
      | exact discriminants

theorem bds_decoding_dense (register word : Nat) (layout : List PayloadColumn)
    (selected : bdsLayout register word = some layout) : Dense 56 layout := by
  unfold bdsLayout at selected
  split at selected
  · cases selected
    decide +kernel
  · split at selected
    · exact (adsb_shape (adsbKind word) layout selected).1
    · exact (commb_shape _ _ selected).1

theorem bds_decoded_assignment_layout (register word : Nat) (layout : List PayloadColumn)
    (selected : bdsLayout register word = some layout)
    (structural : bdsStructuralValid register word = true) :
    bdsAssignmentLayout ⟨register,decodePayloadFields layout word⟩ = some layout := by
  by_cases five : register = 5
  · simpa only [bdsLayout, bdsAssignmentLayout, five, beq_self_eq_true, ite_true] using selected
  by_cases op : register = 101
  · have parts : word < 2^56 ∧ payloadBits word 1 5 = 31 ∧ payloadBits word 6 3 < 2 := by
      simpa only [bdsStructuralValid, op, Bool.and_eq_true, decide_eq_true_eq, beq_iff_eq] using structural
    simp only [bdsLayout, op, show (101 == 5) = false by decide,
      Bool.false_eq_true, ite_false, beq_self_eq_true, ite_true] at selected
    rw [adsb_operation_layout word parts.2.1 parts.2.2] at selected
    cases selected
    have shape := operation_shape (payloadBits word 6 3 == 1) (payloadBits word 41 3)
    have stEq := lookup_position _ word register 6 3 "subtype" shape.2.2.1
    have verEq := lookup_position _ word register 41 3 "version" shape.2.2.2
    simp only [op] at stEq verEq
    simp only [bdsAssignmentLayout, op, show (101 == 5) = false by decide,
      Bool.false_eq_true, ite_false, beq_self_eq_true, ite_true, stEq, verEq,
      Option.getD_some, parts.2.2]
  · simpa only [bdsLayout, bdsAssignmentLayout, show (register == 5) = false by simp [five],
      show (register == 101) = false by simp [op], Bool.false_eq_true, ite_false] using selected

theorem commb_fields_forward (f : PayloadRecord) (valid : ValidBDSFields f) :
    decodeBDSFields f.kind (encodeBDS f) = some f := by
  unfold ValidBDSFields at valid
  cases selected : bdsAssignmentLayout f with
  | none => simp [selected] at valid
  | some layout =>
    simp only [selected] at valid
    have dense := bds_assignment_dense f layout selected
    have inverse := decode_encodePayloadFields layout f.fields dense valid.1
    have structural := bds_fields_structural f layout selected valid.1 valid.2
    have wireLayout := bds_assignment_decoding_layout f layout selected valid.1 structural
    simp only [encodeBDS, selected, decodeBDSFields, wireLayout, bind, Option.bind_some,
      structural, ite_true, inverse]

theorem commb_forward (f : PayloadRecord) (valid : ValidBDS f) :
    decodeBDS f.kind (encodeBDS f) = some f := by
  unfold ValidBDS at valid
  cases selected : bdsAssignmentLayout f with
  | none => simp [selected] at valid
  | some layout =>
    simp only [selected] at valid
    have dense := bds_assignment_dense f layout selected
    have inverse := decode_encodePayloadFields layout f.fields dense valid.1
    have structural := bds_wire_structural f.kind _ valid.2
    have wireLayout := bds_assignment_decoding_layout f layout selected valid.1 structural
    simp only [encodeBDS, selected, decodeBDS, wireLayout, bind, Option.bind_some,
      valid.2, ite_true, inverse]

theorem commb_fields_reverse (register word : Nat) (f : PayloadRecord)
    (decoded : decodeBDSFields register word = some f) : encodeBDS f = word := by
  unfold decodeBDSFields at decoded
  obtain ⟨layout, selected, decoded⟩ := Option.bind_eq_some_iff.mp decoded
  split at decoded
  · rename_i structural
    cases decoded
    have dense := bds_decoding_dense register word layout selected
    have assignment := bds_decoded_assignment_layout register word layout selected structural
    have bounded : word < 2^56 := by
      have parts := structural
      unfold bdsStructuralValid at parts
      simp only [Bool.and_eq_true, decide_eq_true_eq] at parts
      exact parts.1
    simp only [encodeBDS, assignment]
    exact encode_decodePayloadFields layout word dense bounded
  · contradiction

theorem commb_reverse (register word : Nat) (f : PayloadRecord)
    (decoded : decodeBDS register word = some f) : encodeBDS f = word := by
  unfold decodeBDS at decoded
  obtain ⟨layout, selected, decoded⟩ := Option.bind_eq_some_iff.mp decoded
  split at decoded
  · rename_i wire
    cases decoded
    have dense := bds_decoding_dense register word layout selected
    have structural := bds_wire_structural register word wire
    have assignment := bds_decoded_assignment_layout register word layout selected structural
    have bounded : word < 2^56 := by
      have parts := structural
      unfold bdsStructuralValid at parts
      simp only [Bool.and_eq_true, decide_eq_true_eq] at parts
      exact parts.1
    simp only [encodeBDS, assignment]
    exact encode_decodePayloadFields layout word dense bounded
  · contradiction

end Lean1090.Proofs.PayloadRoundTrip

namespace Lean1090.Proofs

theorem CommBRoundTrips : Capstones.CommBRoundTrips :=
  ⟨PayloadRoundTrip.commb_forward, PayloadRoundTrip.commb_reverse⟩

theorem CommBFieldRoundTrips : Capstones.CommBFieldRoundTrips :=
  ⟨PayloadRoundTrip.commb_fields_forward, PayloadRoundTrip.commb_fields_reverse⟩

#print axioms CommBRoundTrips
#print axioms CommBFieldRoundTrips
end Lean1090.Proofs

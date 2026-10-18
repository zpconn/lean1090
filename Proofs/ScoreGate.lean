import Impl.ScoreGate
import Proofs.Binary64Error

/-! Correctness and concrete branch witnesses for the lazy exact score gate. -/

namespace Lean1090.Proofs.ScoreGate
open Binary64Error

theorem mass_eq (terms : List Rat) : Impl.ScoreGate.mass terms = mass terms := by
  have abs_eq : Rat.abs = fun x : Rat => |x| := funext Binary64Facts.rat_abs_eq_abs
  simp only [Impl.ScoreGate.mass, mass, abs_eq]

theorem center_eq (terms : List Rat) (penalty : Rat) :
    Impl.ScoreGate.center terms penalty = scoreCenter terms penalty := rfl

theorem envelope_eq (terms : List Rat) (penalty : Rat) :
    Impl.ScoreGate.envelope terms penalty = scoreEnvelope terms penalty := by
  simp only [Impl.ScoreGate.envelope, scoreEnvelope, mass_eq,
    Binary64Facts.rat_abs_eq_abs]

/-- The runtime gate agrees with the inclusive software-binary64 comparison
for every short term list and penalty, given the unchanged model as fallback.
Neither acceptance nor rejection is assumed; the enclosure is proved. -/
theorem choose_eq (terms : List Rat) (penalty : Rat) (fallback : Unit → Bool)
    (short : terms.length ≤ 4)
    (fallback_eq : fallback () = decide (scoreReference terms penalty ≥ -3)) :
    Impl.ScoreGate.choose terms penalty fallback =
      decide (scoreReference terms penalty ≥ -3) := by
  unfold Impl.ScoreGate.choose
  rw [center_eq, envelope_eq]
  dsimp only
  have bounded := score_error terms penalty short
  obtain ⟨lower, upper⟩ := abs_le.mp bounded
  split
  · rename_i accept
    have exactAccept : scoreReference terms penalty ≥ -3 := by linarith
    simp only [exactAccept, decide_true]
  · split
    · rename_i reject
      have exactReject : ¬ scoreReference terms penalty ≥ -3 := by linarith
      simp only [exactReject, decide_false]
    · exact fallback_eq

/-- An exact software score of -3 remains accepted, including the uncertain
interval where evaluating the fallback is necessary. -/
theorem choose_at_threshold (terms : List Rat) (penalty : Rat) (fallback : Unit → Bool)
    (short : terms.length ≤ 4)
    (fallback_eq : fallback () = decide (scoreReference terms penalty ≥ -3))
    (threshold : scoreReference terms penalty = -3) :
    Impl.ScoreGate.choose terms penalty fallback = true := by
  rw [choose_eq terms penalty fallback short fallback_eq, threshold]
  decide

/-- The acceptance branch is inhabited and does not use a false fallback. -/
theorem accept_witness : Impl.ScoreGate.choose [0] 0 (fun _ => false) = true := by
  decide +kernel

/-- The rejection branch is inhabited and does not use a true fallback. -/
theorem reject_witness : Impl.ScoreGate.choose [0] (-4) (fun _ => true) = false := by
  decide +kernel

/-- The uncertainty branch is inhabited at the exact threshold; its result
comes from the thunk. Both possible thunk results are preserved. -/
theorem fallback_witness (value : Bool) :
    Impl.ScoreGate.choose [0] (-3) (fun _ => value) = value := by
  cases value <;> decide +kernel

/-- A concrete short list whose fully rounded reference is exactly -3. -/
theorem reference_threshold_witness : scoreReference [0] (-3) = -3 := by
  decide +kernel

/-- Non-vacuity of the refinement hypotheses at the inclusive boundary. -/
theorem threshold_refinement_witness :
    ([0] : List Rat).length ≤ 4 ∧
    (fun _ : Unit => true) () = decide (scoreReference [0] (-3) ≥ -3) ∧
    Impl.ScoreGate.choose [0] (-3) (fun _ => true) = true := by
  rw [reference_threshold_witness]
  decide +kernel

#print axioms choose_eq
#print axioms choose_at_threshold
#print axioms accept_witness
#print axioms reject_witness
#print axioms fallback_witness
#print axioms reference_threshold_witness
#print axioms threshold_refinement_witness

end Lean1090.Proofs.ScoreGate

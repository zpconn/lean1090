import Proofs.CommBDensityBounds

/-!
# Complete Comm-B arithmetic-domain proof

Every executed divisor is nonzero and every operand, exact intermediate, and
rounded result fits in finite binary64 range, for every register and payload.
Conservative rational bounds establish safety without changing any runtime
score or adding an acceptance hypothesis. The final theorem proves the exact
frozen CommBArithmetic contract.
-/

namespace Lean1090.Proofs.CommBArithmeticFacts
open Spec Binary64Facts
set_option maxHeartbeats 2000000

private theorem constant_divisors_nonzero :
    ∀ d ∈ ([512,100,54/10,10844,10,70/100,120,129,55,21/100,
      1669,990/100,29,290,164/10] : List Rat).map Binary64.literal, d ≠ 0 := by
  decide +kernel

theorem divisors_nonzero (register word : Nat) :
    ∀ d ∈ cbScoreDivisors register word, d ≠ 0 := by
  unfold cbScoreDivisors
  intro d hd
  simp only [List.mem_append] at hd
  rcases hd with (constant | count) | ratio
  · exact constant_divisors_nonzero d constant
  · split at count
    · simp at count
    · rename_i nonemptyTest
      obtain rfl := List.mem_singleton.mp count
      have nonempty : cbDensityTerms register word ≠ [] := by
        intro empty
        simp [empty] at nonemptyTest
      exact_mod_cast List.length_pos_iff.mpr nonempty |>.ne'
  · split at ratio
    · rename_i ratioCondition
      obtain rfl := List.mem_singleton.mp ratio
      have positive : 0 < cbMach64 word := by
        simp only [Bool.and_eq_true, decide_eq_true_eq] at ratioCondition
        exact ratioCondition.2
      exact ne_of_gt positive
    · simp at ratio

#print axioms divisors_nonzero
theorem density_terms_length (register word : Nat) : (cbDensityTerms register word).length ≤ 4 := by
  have scoreLength (value : Option Rat) (score : Rat → Rat) : (cbScoreField value score).length ≤ 1 := by
    cases value <;> simp [cbScoreField]
  unfold cbDensityTerms
  split <;> simp only [List.length_append, List.length_cons, List.length_nil]
  all_goals try omega
  all_goals simp only [cbScoreField]
  all_goals repeat' split <;> simp_all

theorem accumulation_bounds (scores : List Rat) (total bound : Rat) (one : 1 ≤ bound)
    (totalBound : total.abs ≤ bound) (scoresBound : ∀ x ∈ scores, x.abs ≤ bound) :
    (∀ x ∈ cbAccumulationTrace total scores, x.abs ≤ 8^scores.length * bound) ∧
    (scores.foldl Binary64.add total).abs ≤ 8^scores.length * bound := by
  induction scores generalizing total bound with
  | nil => simpa [cbAccumulationTrace] using totalBound
  | cons score scores ih =>
    have boundNonneg : 0 ≤ bound := by linarith
    have scoreBound := scoresBound score (by simp)
    have tailBound : ∀ x ∈ scores, x.abs ≤ 8 * bound := by
      intro x hx
      have hx' := scoresBound x (by simp [hx])
      linarith
    have sumBound := abs_add_bound total score bound bound totalBound scoreBound
    have nextBound : (Binary64.add total score).abs ≤ 8 * bound := by
      have := round_bound_of_abs_le (total+score) (bound+bound) sumBound
      change (Binary64.add total score).abs ≤ _ at this
      linarith
    obtain ⟨traceBound, finalBound⟩ := ih (Binary64.add total score) (8*bound)
      (by linarith) nextBound tailBound
    have onePow : (1 : Rat) ≤ 8 ^ scores.length := one_le_pow₀ (by norm_num)
    have eightBound : 8 * bound ≤ 8^(score :: scores).length * bound := by
      simp only [List.length_cons, pow_succ]
      nlinarith
    constructor
    · intro x hx
      simp only [cbAccumulationTrace, List.mem_append, List.mem_cons,
        List.not_mem_nil, or_false] at hx
      rcases hx with (rfl | rfl | rfl | rfl) | hx
      · exact totalBound.trans (by linarith)
      · exact scoreBound.trans (by linarith)
      · exact sumBound.trans (by linarith)
      · exact nextBound.trans eightBound
      · have := traceBound x hx
        simpa only [List.length_cons, pow_succ, mul_assoc] using this
    · simpa only [List.foldl_cons, List.length_cons, pow_succ, mul_assoc] using finalBound

theorem wind_bounds (tas gs : Rat) (tasBound : tas.abs ≤ 2^70) (gsBound : gs.abs ≤ 2^70) :
    let d := Binary64.sub tas gs
    let p := Binary64.div d.abs 100
    (∀ x ∈ [tas, gs, tas-gs, d, d.abs, d.abs/100, p, -p, Binary64.sub 0 p], x.abs ≤ 2^90) ∧
      (Binary64.sub 0 p).abs ≤ 2^90 := by
  let d := Binary64.sub tas gs
  let p := Binary64.div d.abs 100
  have difference := abs_sub_bound tas gs (2^70) (2^70) tasBound gsBound
  have roundedDifference := round_bound_of_abs_le (tas-gs) (2^70+2^70) difference
  change d.abs ≤ _ at roundedDifference
  have ratio := abs_div_bound d.abs 100 (3*(2^70+2^70)+1) 100
    (by simpa only [rat_abs_eq_abs, abs_abs] using roundedDifference) (by decide) (by decide)
  have roundedRatio := round_bound_of_abs_le (d.abs / 100) ((3*(2^70+2^70)+1)/100) ratio
  change p.abs ≤ _ at roundedRatio
  have negative := abs_sub_bound 0 p 0 (3*((3*(2^70+2^70)+1)/100)+1) (by decide) roundedRatio
  have result := round_bound_of_abs_le (0-p) (0+(3*((3*(2^70+2^70)+1)/100)+1)) negative
  change (Binary64.sub 0 p).abs ≤ _ at result
  constructor
  · intro x hx
    simp only [List.mem_cons, List.not_mem_nil, or_false] at hx
    rcases hx with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals dsimp only [p, d] at *
    all_goals simp only [rat_abs_eq_abs, abs_neg, abs_abs] at *
    all_goals norm_num at *; linarith
  · norm_num at *; linarith

theorem wind_penalty_bound (word : Nat) :
    (match commBValue 0x50 word "TAS", commBValue 0x50 word "groundspeed" with
      | some tas, some gs => Binary64.sub 0 (Binary64.div (Binary64.sub tas gs).abs 100)
      | _, _ => 0).abs ≤ 2^90 := by
  split
  · rename_i tas gs htas hgs
    exact (wind_bounds tas gs (value_bound _ _ _ _ htas) (value_bound _ _ _ _ hgs)).2
  · decide +kernel

theorem penalty_bound (register word : Nat) : (cbPenalty register word).abs ≤ 2^94 := by
  unfold cbPenalty
  split
  all_goals dsimp only
  · have windBound := wind_penalty_bound word
    split
    · split
      · exact (round_bound_of_abs_le _ _
          (abs_sub_bound _ 2 (2^90) 2 windBound (by decide))).trans (by norm_num)
      · exact windBound.trans (by norm_num)
    · exact windBound.trans (by norm_num)
  · split <;> (try split) <;> (try split) <;> decide +kernel
  · decide +kernel

theorem penalty_trace_bound (register word : Nat) :
    ∀ x ∈ cbPenaltyTrace register word, x.abs ≤ 2^94 := by
  unfold cbPenaltyTrace
  split
  · rename_i is50
    have eq50 : register = 80 := by simpa using is50
    subst register
    dsimp only
    have windBound := wind_penalty_bound word
    have windTrace : ∀ x ∈ (match commBValue 80 word "TAS", commBValue 80 word "groundspeed" with
        | some tas, some gs =>
          let d := Binary64.sub tas gs
          let p := Binary64.div d.abs 100
          [tas,gs,tas-gs,d,d.abs,d.abs/100,p,-p,Binary64.sub 0 p]
        | _, _ => [0]), x.abs ≤ 2^94 := by
      split
      · rename_i tas gs htas hgs
        intro x hx
        exact ((wind_bounds tas gs (value_bound _ _ _ _ htas) (value_bound _ _ _ _ hgs)).1 x hx).trans (by norm_num)
      · simp
    intro x hx
    simp only [List.mem_append, List.mem_singleton] at hx
    rcases hx with (wind | turn) | final
    · exact windTrace x wind
    · split at turn
      · split at turn
        · have subBound := abs_sub_bound _ 2 (2^90) 2 windBound (by norm_num [rat_abs_eq_abs])
          have roundedBound := round_bound_of_abs_le _ _ subBound
          simp only [List.mem_cons, List.not_mem_nil, or_false] at turn
          rcases turn with rfl | rfl | rfl
          · exact windBound.trans (by norm_num)
          · exact subBound.trans (by norm_num)
          · exact roundedBound.trans (by norm_num)
        · obtain rfl := List.mem_singleton.mp turn
          exact windBound.trans (by norm_num)
      · obtain rfl := List.mem_singleton.mp turn
        exact windBound.trans (by norm_num)
    · subst x
      exact penalty_bound 80 word
  · split
    · rename_i is60
      have eq60 : register = 96 := by simpa using is60
      subst register
      dsimp only
      split
      · rename_i ias mach hias hmach
        split
        · rename_i positive
          have iasBound := value_bound 96 word "IAS" ias hias
          have machBound := (field_arithmetic_bounds word).2.2
          have machLow := mach_positive_lower_bound word positive
          have exactBound := abs_div_bound ias (cbMach64 word) (2^70) (1/1000)
            iasBound (by rw [Rat.abs_of_nonneg positive.le]; exact machLow) (by norm_num)
          have roundedBound := round_bound_of_abs_le _ _ exactBound
          have penaltyBound := penalty_bound 96 word
          intro x hx
          simp only [List.mem_cons, List.not_mem_nil, or_false] at hx
          rcases hx with rfl | rfl | rfl | rfl | rfl
          · exact iasBound.trans (by norm_num)
          · exact machBound.trans (by norm_num)
          · exact exactBound.trans (by norm_num)
          · exact roundedBound.trans (by norm_num)
          · exact penaltyBound
        · simp
      · simp
    · simp

theorem accumulation_concrete_bounds (register word : Nat) :
    (∀ x ∈ cbAccumulationTrace 0 (cbDensityTerms register word), x.abs ≤ 2^182) ∧
    ((cbDensityTerms register word).foldl Binary64.add 0).abs ≤ 2^182 := by
  have bound := accumulation_bounds (cbDensityTerms register word) 0 (2^170)
    (by norm_num) (by norm_num) (density_bounds register word).2
  have length := density_terms_length register word
  have factor : (8 : Rat) ^ (cbDensityTerms register word).length ≤ 8^4 :=
    pow_le_pow_right₀ (by norm_num) length
  have finalFactor : (8 : Rat) ^ (cbDensityTerms register word).length * 2^170 ≤ 2^182 := by
    have := mul_le_mul_of_nonneg_right factor (show (0 : Rat) ≤ 2^170 by positivity)
    norm_num at *; linarith
  exact ⟨fun x hx => (bound.1 x hx).trans finalFactor, bound.2.trans finalFactor⟩

theorem density_mean_bounds (register word : Nat) :
    (let terms := cbDensityTerms register word
     ∀ x ∈ (if terms.isEmpty then [0] else
       [terms.foldl Binary64.add 0 / (terms.length : Rat), cbDensity register word]),
       x.abs ≤ 2^184) ∧
    (cbDensity register word).abs ≤ 2^184 := by
  let terms := cbDensityTerms register word
  change (∀ x ∈ (if terms.isEmpty then [0] else
    [terms.foldl Binary64.add 0 / (terms.length : Rat), cbDensity register word]),
    x.abs ≤ 2^184) ∧ (cbDensity register word).abs ≤ 2^184
  have totalBound := (accumulation_concrete_bounds register word).2
  by_cases empty : terms.isEmpty = true
  · have densityZero : cbDensity register word = 0 := by
      unfold cbDensity
      simp only [terms, empty, ↓reduceIte]
    simp only [empty, ↓reduceIte, densityZero, List.mem_singleton, forall_eq]
    norm_num
  · have count : (1 : Rat) ≤ terms.length := by
      have nonempty : terms ≠ [] := by intro h; simp [h] at empty
      exact_mod_cast List.length_pos_iff.mpr nonempty
    have exactBound := abs_div_bound (terms.foldl Binary64.add 0) (terms.length : Rat)
      (2^182) 1 totalBound (by rw [Rat.abs_of_nonneg (by positivity)]; exact count) (by decide)
    have roundedBound := round_bound_of_abs_le _ _ exactBound
    have densityEq : cbDensity register word = Binary64.div (terms.foldl Binary64.add 0) (terms.length : Rat) := by
      unfold cbDensity
      exact ite_eq_right empty
    rw [densityEq]
    simp only [empty, Bool.false_eq_true, ↓reduceIte]
    constructor
    · intro x hx
      simp only [List.mem_cons, List.not_mem_nil, or_false] at hx
      rcases hx with rfl | rfl
      · exact exactBound.trans (by norm_num)
      · exact roundedBound.trans (by norm_num)
    · exact roundedBound.trans (by norm_num)


theorem final_score_bounds (register word : Nat) :
    (cbDensity register word + cbPenalty register word).abs ≤ 2^187 ∧
    (cbCombinedScore register word).abs ≤ 2^187 := by
  have exactBound := abs_add_bound _ _ (2^184) (2^94)
    (density_mean_bounds register word).2 (penalty_bound register word)
  have roundedBound := round_bound_of_abs_le _ _ exactBound
  exact ⟨exactBound.trans (by norm_num), roundedBound.trans (by norm_num)⟩

theorem arithmetic_finite (register word : Nat) : CommBScoreArithmeticFinite register word := by
  have maximum : (2^200 : Rat) ≤ Binary64.maxFinite := by decide +kernel
  have field := (field_arithmetic_bounds word).1
  have density := (density_bounds register word).1
  have accumulation := (accumulation_concrete_bounds register word).1
  have mean := (density_mean_bounds register word).1
  have penalty := penalty_trace_bound register word
  have finalScore := final_score_bounds register word
  unfold CommBScoreArithmeticFinite
  dsimp only
  constructor
  · intro x hx
    simp only [List.mem_append] at hx
    rcases hx with ((((fieldMem | densityMem) | accumulationMem) | meanMem) | penaltyMem) | finalMem
    · exact (field x fieldMem).trans ((by norm_num : (2^70 : Rat) ≤ 2^200).trans maximum)
    · exact (density x densityMem).trans ((by norm_num : (2^170 : Rat) ≤ 2^200).trans maximum)
    · exact (accumulation x accumulationMem).trans ((by norm_num : (2^182 : Rat) ≤ 2^200).trans maximum)
    · exact (mean x meanMem).trans ((by norm_num : (2^184 : Rat) ≤ 2^200).trans maximum)
    · exact (penalty x penaltyMem).trans ((by norm_num : (2^94 : Rat) ≤ 2^200).trans maximum)
    · simp only [List.mem_cons, List.not_mem_nil, or_false] at finalMem
      rcases finalMem with rfl | rfl
      · exact finalScore.1.trans ((by norm_num : (2^187 : Rat) ≤ 2^200).trans maximum)
      · exact finalScore.2.trans ((by norm_num : (2^187 : Rat) ≤ 2^200).trans maximum)
  · exact divisors_nonzero register word
end Lean1090.Proofs.CommBArithmeticFacts

namespace Lean1090.Proofs
/-- Every exact and rounded Comm-B scoring intermediate is finite, and every
executed divisor is nonzero. The stronger auxiliary result covers all natural
register/payload inputs, without the capstone's wire-width restriction. -/
theorem CommBArithmetic : Capstones.CommBArithmetic := by
  intro register _ word _
  exact CommBArithmeticFacts.arithmetic_finite register word
#print axioms CommBArithmetic
end Lean1090.Proofs


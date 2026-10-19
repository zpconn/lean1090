import Proofs.CPRGeometry
import Proofs.CPRTableClassification
import Mathlib.Data.List.TakeWhile
import Mathlib.Tactic.IntervalCases

/-! Analytic classification of the CPR NL formula by its certified transitions.
The interval enclosure and finite-grid proofs enter as explicit proved premises. -/
namespace Lean1090.Proofs.CPRNLClassification
open Spec.CPR CPRGeometry

noncomputable def zoneRatio (latitude : ℝ) : ℝ :=
  2 * Real.pi / Real.arccos (1 - (1 - Real.cos (Real.pi / 30)) /
    (Real.cos (Real.pi / 180 * latitude)) ^ 2)

private theorem angle_bounds {latitude : ℝ} (nonnegative : 0 ≤ latitude)
    (below : latitude < 90) :
    0 ≤ Real.pi / 180 * latitude ∧ Real.pi / 180 * latitude < Real.pi / 2 := by
  constructor
  · positivity
  · nlinarith [Real.pi_pos]

private theorem latitude_cos_pos {latitude : ℝ} (nonnegative : 0 ≤ latitude)
    (below : latitude < 90) : 0 < Real.cos (Real.pi / 180 * latitude) := by
  obtain ⟨lo, hi⟩ := angle_bounds nonnegative below
  exact Real.cos_pos_of_mem_Ioo ⟨by linarith [Real.pi_pos], hi⟩

private theorem base_positive : 0 < 1 - Real.cos (Real.pi / 30) := by
  have h := Real.cos_lt_cos_of_nonneg_of_le_pi (x := 0) (y := Real.pi / 30)
    (by norm_num) (by linarith [Real.pi_pos]) (by positivity)
  simpa using sub_pos.mpr h

private theorem denominator_pos {latitude : ℝ} (nonnegative : 0 ≤ latitude)
    (below : latitude < 90) :
    0 < Real.arccos (1 - (1 - Real.cos (Real.pi / 30)) /
      (Real.cos (Real.pi / 180 * latitude)) ^ 2) := by
  apply Real.arccos_pos.mpr
  have := div_pos base_positive (sq_pos_of_pos (latitude_cos_pos nonnegative below))
  linarith

/-- The lower formula value2 also holds when the inverse cosine saturates. -/
theorem ratio_at_least_two {latitude : ℝ} (nonnegative : 0 ≤ latitude)
    (below : latitude < 90) : 2 ≤ zoneRatio latitude := by
  unfold zoneRatio
  rw [le_div_iff₀ (denominator_pos nonnegative below)]
  nlinarith [Real.arccos_le_pi (1 - (1 - Real.cos (Real.pi / 30)) /
      (Real.cos (Real.pi / 180 * latitude)) ^ 2)]

private theorem arccos_above_angle {argument angle : ℝ}
    (angle_lo : 0 < angle) (angle_hi : angle < Real.pi) :
    angle < Real.arccos argument ↔ argument < Real.cos angle := by
  by_cases below : argument < -1
  · rw [Real.arccos_of_le_neg_one below.le]
    constructor
    · intro _; exact below.trans_le (Real.neg_one_le_cos angle)
    · intro _; exact angle_hi
  by_cases above : 1 < argument
  · rw [Real.arccos_of_one_le above.le]
    constructor
    · intro impossible; linarith
    · intro impossible; have := Real.cos_le_one angle; linarith
  have bounds : argument ∈ Set.Icc (-1 : ℝ) 1 := ⟨by linarith, by linarith⟩
  have cosine : Real.cos angle ∈ Set.Icc (-1 : ℝ) 1 :=
    ⟨Real.neg_one_le_cos angle, Real.cos_le_one angle⟩
  simpa only [Real.arccos_cos angle_lo.le angle_hi.le] using
    (Real.strictAntiOn_arccos.lt_iff_gt cosine bounds)

private theorem arccos_below_angle {argument angle : ℝ}
    (angle_lo : 0 < angle) (angle_hi : angle < Real.pi) :
    Real.arccos argument < angle ↔ Real.cos angle < argument := by
  by_cases below : argument < -1
  · rw [Real.arccos_of_le_neg_one below.le]
    constructor
    · intro impossible; linarith
    · intro impossible; have := Real.neg_one_le_cos angle; linarith
  by_cases above : 1 < argument
  · rw [Real.arccos_of_one_le above.le]
    constructor
    · intro _; exact (Real.cos_le_one angle).trans_lt above
    · intro _; exact angle_lo
  have bounds : argument ∈ Set.Icc (-1 : ℝ) 1 := ⟨by linarith, by linarith⟩
  have cosine : Real.cos angle ∈ Set.Icc (-1 : ℝ) 1 :=
    ⟨Real.neg_one_le_cos angle, Real.cos_le_one angle⟩
  simpa only [Real.arccos_cos angle_lo.le angle_hi.le] using
    (Real.strictAntiOn_arccos.lt_iff_gt bounds cosine)


private theorem zone_angle_bounds (zone : Nat) (large : 2 < zone) :
    0 < 2 * Real.pi / (zone : ℝ) ∧ 2 * Real.pi / (zone : ℝ) < Real.pi := by
  have hz : (2 : ℝ) < zone := by exact_mod_cast large
  constructor
  · positivity
  · rw [div_lt_iff₀ (by linarith : (0 : ℝ) < zone)]
    nlinarith [Real.pi_pos]

private theorem transition_identity (zone : Nat) (large : 2 < zone)
    (positive : 0 < transitionFormula zone) :
    (Real.cos (Real.pi / 180 * transitionFormula zone))^2 *
      (1 - Real.cos (2 * Real.pi / (zone : ℝ))) = 1 - Real.cos (Real.pi / 30) := by
  obtain ⟨blo, bhi⟩ := zone_angle_bounds zone large
  have denominator : 0 < 1 - Real.cos (2 * Real.pi / (zone : ℝ)) := by
    have := Real.cos_lt_cos_of_nonneg_of_le_pi (x := 0) (by norm_num) bhi.le blo
    simpa using sub_pos.mpr this
  let ratio := (1 - Real.cos (Real.pi / 30)) /
    (1 - Real.cos (2 * Real.pi / (zone : ℝ)))
  have ratio_pos : 0 < ratio := div_pos base_positive denominator
  have root_lt : Real.sqrt ratio < 1 := by
    apply Real.arccos_pos.mp
    unfold transitionFormula at positive
    change 0 < 180 / Real.pi * Real.arccos (Real.sqrt ratio) at positive
    exact (mul_pos_iff_of_pos_left (by positivity : (0 : ℝ) < 180 / Real.pi)).mp positive
  have angle : Real.pi / 180 * transitionFormula zone = Real.arccos (Real.sqrt ratio) := by
    unfold transitionFormula
    change Real.pi / 180 * (180 / Real.pi * Real.arccos (Real.sqrt ratio)) = _
    field_simp
  rw [angle, Real.cos_arccos (by linarith [Real.sqrt_nonneg ratio]) root_lt.le,
    Real.sq_sqrt ratio_pos.le]
  exact div_mul_cancel₀ _ (ne_of_gt denominator)

private theorem square_cosine_lt {x y : ℝ} (xlo : 0 ≤ x) (xhi : x < 90)
    (ylo : 0 ≤ y) (yhi : y < 90) :
    (Real.cos (Real.pi / 180 * x))^2 < (Real.cos (Real.pi / 180 * y))^2 ↔ y < x := by
  have xp := latitude_cos_pos xlo xhi
  have yp := latitude_cos_pos ylo yhi
  have xa := angle_bounds xlo xhi
  have ya := angle_bounds ylo yhi
  have cosine := Real.strictAntiOn_cos.lt_iff_gt
    (show Real.pi / 180 * x ∈ Set.Icc 0 Real.pi from ⟨xa.1, by linarith [Real.pi_pos]⟩)
    (show Real.pi / 180 * y ∈ Set.Icc 0 Real.pi from ⟨ya.1, by linarith [Real.pi_pos]⟩)
  constructor
  · intro h
    have hcos : Real.cos (Real.pi / 180 * x) < Real.cos (Real.pi / 180 * y) := by nlinarith
    have := cosine.mp hcos
    nlinarith [Real.pi_pos]
  · intro h
    have hcos := cosine.mpr (by nlinarith [Real.pi_pos])
    nlinarith

/-- A real latitude past a transition has a strictly smaller real zone ratio. -/
theorem ratio_lt_zone_iff (zone : Nat) (large : 2 < zone)
    (transition_lo : 0 < transitionFormula zone) (transition_hi : transitionFormula zone < 90)
    {latitude : ℝ} (nonnegative : 0 ≤ latitude) (below : latitude < 90) :
    zoneRatio latitude < (zone : ℝ) ↔ transitionFormula zone < latitude := by
  obtain ⟨blo, bhi⟩ := zone_angle_bounds zone large
  have hz : (0 : ℝ) < zone := by exact_mod_cast (show 0 < zone by omega)
  have denominator := denominator_pos nonnegative below
  have cospos := latitude_cos_pos nonnegative below
  have identity := transition_identity zone large transition_lo
  have bpos : 0 < 1 - Real.cos (2 * Real.pi / (zone : ℝ)) := by
    have := Real.cos_lt_cos_of_nonneg_of_le_pi (x := 0) (by norm_num) bhi.le blo
    simpa using sub_pos.mpr this
  calc
    zoneRatio latitude < (zone : ℝ) ↔
        2 * Real.pi / (zone : ℝ) < Real.arccos (1 - (1 - Real.cos (Real.pi / 30)) /
          (Real.cos (Real.pi / 180 * latitude))^2) := by
      unfold zoneRatio
      rw [div_lt_iff₀ denominator, div_lt_iff₀ hz]
      constructor <;> intro h <;> nlinarith
    _ ↔ 1 - (1 - Real.cos (Real.pi / 30)) /
        (Real.cos (Real.pi / 180 * latitude))^2 < Real.cos (2 * Real.pi / (zone : ℝ)) :=
      arccos_above_angle blo bhi
    _ ↔ (Real.cos (Real.pi / 180 * latitude))^2 <
        (Real.cos (Real.pi / 180 * transitionFormula zone))^2 := by
      have sqpos := sq_pos_of_pos cospos
      constructor
      · intro h
        have hdiv : 1 - Real.cos (2 * Real.pi / (zone : ℝ)) <
            (1 - Real.cos (Real.pi / 30)) / (Real.cos (Real.pi / 180 * latitude))^2 := by linarith
        have := (lt_div_iff₀ sqpos).mp hdiv
        nlinarith
      · intro h
        have hprod : (1 - Real.cos (2 * Real.pi / (zone : ℝ))) *
            (Real.cos (Real.pi / 180 * latitude))^2 < 1 - Real.cos (Real.pi / 30) := by
          nlinarith
        have := (lt_div_iff₀ sqpos).mpr hprod
        linarith
    _ ↔ transitionFormula zone < latitude :=
      square_cosine_lt nonnegative below transition_lo.le transition_hi


/-- Every positive nonpolar latitude has ratio strictly below the equatorial60. -/
theorem ratio_below_sixty {latitude : ℝ} (positive : 0 < latitude)
    (below : latitude < 90) : zoneRatio latitude < 60 := by
  have angle := angle_bounds positive.le below
  have cospos := latitude_cos_pos positive.le below
  have coslt : Real.cos (Real.pi / 180 * latitude) < 1 := by
    have h := Real.cos_lt_cos_of_nonneg_of_le_pi (x := 0)
      (by norm_num) (by linarith [Real.pi_pos] : Real.pi / 180 * latitude ≤ Real.pi)
      (by positivity : 0 < Real.pi / 180 * latitude)
    simpa using h
  have sqpositive := sq_pos_of_pos cospos
  have sqsmall : (Real.cos (Real.pi / 180 * latitude))^2 < 1 := by nlinarith
  have product : (1 - Real.cos (Real.pi / 30)) *
      (Real.cos (Real.pi / 180 * latitude))^2 < 1 - Real.cos (Real.pi / 30) := by
    nlinarith [base_positive]
  have divided := (lt_div_iff₀ sqpositive).mpr product
  have inverse := (arccos_above_angle
    (by positivity : 0 < Real.pi / 30)
    (by linarith [Real.pi_pos] : Real.pi / 30 < Real.pi)).mpr
    (by linarith : 1 - (1 - Real.cos (Real.pi / 30)) /
      (Real.cos (Real.pi / 180 * latitude))^2 < Real.cos (Real.pi / 30))
  unfold zoneRatio
  rw [div_lt_iff₀ (denominator_pos positive.le below)]
  nlinarith

theorem ratio_abs (latitude : ℝ) : zoneRatio |latitude| = zoneRatio latitude := by
  have hc : Real.cos (Real.pi / 180 * |latitude|) = Real.cos (Real.pi / 180 * latitude) := by
    calc
      Real.cos (Real.pi / 180 * |latitude|) = Real.cos |Real.pi / 180 * latitude| := by
        rw [abs_mul, abs_of_pos (by positivity : (0 : ℝ) < Real.pi / 180)]
      _ = _ := Real.cos_abs _
  simp only [zoneRatio, hc]

private theorem absolute_cast (latitude : Rat) : ((absQ latitude : Rat) : ℝ) = |(latitude : ℝ)| := by
  rw [absQ_eq_abs]
  exact Rat.cast_abs latitude

/-- The certificate interval separates the rounded threshold and true threshold
from every permitted reconstructed latitude. -/
theorem threshold_comparison (certificate : NLCertificate) (threshold : Nat)
    (certified : CertifiesTransition certificate)
    (avoids : AvoidsDecodableLatitudes certificate)
    (lower : (certificate.lower12 : Rat) / 1000000000000 ≤ (threshold : Rat) / 100000000)
    (upper : (threshold : Rat) / 100000000 ≤ (certificate.upper12 : Rat) / 1000000000000)
    {latitude : Rat} (decodable : DecodableLatitude latitude) :
    (threshold : Rat) / 100000000 ≤ absQ latitude ↔
      transitionFormula certificate.zone < |(latitude : ℝ)| := by
  have outside := avoids latitude decodable
  have dichotomy : absQ latitude < (certificate.lower12 : Rat) / 1000000000000 ∨
      (certificate.upper12 : Rat) / 1000000000000 < absQ latitude := by
    by_cases h : (certificate.lower12 : Rat) / 1000000000000 ≤ absQ latitude
    · right; by_contra h'; exact outside ⟨h, by linarith⟩
    · left; linarith
  rcases dichotomy with low | high
  · have real_low : |(latitude : ℝ)| < (certificate.lower12 : ℝ) / 1000000000000 := by
      rw [← absolute_cast]
      have h := (Rat.cast_lt (K := ℝ)).mpr low
      push_cast at h
      exact h
    constructor
    · intro h; linarith
    · intro h; linarith [certified.1]
  · have real_high : (certificate.upper12 : ℝ) / 1000000000000 < |(latitude : ℝ)| := by
      rw [← absolute_cast]
      have h := (Rat.cast_lt (K := ℝ)).mpr high
      push_cast at h
      exact h
    constructor
    · intro _; exact certified.2.trans real_high
    · intro _; linarith


private def indexedCertificate (index : Fin 57) : NLCertificate :=
  nlCertificates.getD index.val ⟨0, 0, 0⟩

set_option maxRecDepth 100000 in
set_option synthInstance.maxSize 10000 in
private theorem index_facts (index : Fin 57) :
    indexedCertificate index ∈ nlCertificates ∧
    (indexedCertificate index).zone = 59 - index.val ∧
    0 < (indexedCertificate index).lower12 ∧
    (indexedCertificate index).upper12 < 90000000000000 ∧
    ((indexedCertificate index).lower12 : Rat) / 1000000000000 ≤
      (transitions.getD index.val 0 : Rat) / 100000000 ∧
    (transitions.getD index.val 0 : Rat) / 100000000 ≤
      ((indexedCertificate index).upper12 : Rat) / 1000000000000 := by
  have checked : ∀ index : Fin 57,
    (indexedCertificate index).zone = 59 - index.val ∧
    0 < (indexedCertificate index).lower12 ∧
    (indexedCertificate index).upper12 < 90000000000000 ∧
    ((indexedCertificate index).lower12 : Rat) / 1000000000000 ≤
      (transitions.getD index.val 0 : Rat) / 100000000 ∧
    (transitions.getD index.val 0 : Rat) / 100000000 ≤
      ((indexedCertificate index).upper12 : Rat) / 1000000000000 := by decide +kernel
  constructor
  · have within : index.val < nlCertificates.length := by simp [nlCertificates]
    change nlCertificates.getD index.val _ ∈ nlCertificates
    rw [List.getD_eq_getElem?_getD, List.getElem?_eq_getElem within, Option.getD_some]
    exact List.getElem_mem within
  · exact checked index

/-- Each rounded executable cutoff has exactly its real formula's comparison
on the union of all legal CPR grids. -/
theorem indexed_threshold_comparison
    (certificates : ∀ c ∈ nlCertificates, CertifiesTransition c)
    (avoids : ∀ c ∈ nlCertificates, AvoidsDecodableLatitudes c)
    {latitude : Rat} (decodable : DecodableLatitude latitude)
    (below : |(latitude : ℝ)| < 90) (index : Fin 57) :
    (transitions.getD index.val 0 : Rat) / 100000000 ≤ absQ latitude ↔
      zoneRatio |(latitude : ℝ)| < (59 - index.val : Nat) := by
  let c := indexedCertificate index
  obtain ⟨member, zone, lower, upper, threshold_lower, threshold_upper⟩ := index_facts index
  have certified := certificates c member
  have transition_lo : 0 < transitionFormula c.zone := by
    have lowpositive : (0 : ℝ) < (c.lower12 : ℝ) / 1000000000000 := by
      have h : 0 < c.lower12 := lower
      positivity
    exact lowpositive.trans certified.1
  have transition_hi : transitionFormula c.zone < 90 := by
    have highbound : (c.upper12 : ℝ) / 1000000000000 < 90 := by
      rw [div_lt_iff₀ (by norm_num)]
      norm_num
      exact_mod_cast upper
    exact certified.2.trans highbound
  have large : 2 < c.zone := by dsimp only [c]; rw [zone]; have := index.isLt; omega
  have comparison := threshold_comparison c (transitions.getD index.val 0) certified
    (avoids c member) threshold_lower threshold_upper decodable
  rw [comparison, ← zone]
  exact (ratio_lt_zone_iff c.zone large transition_lo transition_hi (abs_nonneg _) below).symm

private theorem table_beyond {latitude : Rat} (beyond : 87 < absQ latitude) : nlTable latitude = 1 := by
  have thresholds : ∀ t ∈ transitions, (t : Rat) / 100000000 ≤ 87 := by decide +kernel
  have selected : transitions.takeWhile (fun (t : Nat) => (t : Rat) / 100000000 ≤ absQ latitude) = transitions := by
    apply List.takeWhile_eq_self_iff.mpr
    intro t member
    exact decide_eq_true (le_trans (thresholds t member) beyond.le)
  simp only [nlTable, beq_iff_eq, show ¬absQ latitude = 87 by linarith, ite_false, selected]
  decide +kernel


/-- Certified real transitions and their proved grid separation classify the
frozen executable NL table at every reconstructible latitude. -/
theorem classification
    (certificates : ∀ c ∈ nlCertificates, CertifiesTransition c)
    (avoids : ∀ c ∈ nlCertificates, AvoidsDecodableLatitudes c)
    (latitude : Rat) (decodable : DecodableLatitude latitude) :
    nlTable latitude = nlFormula (latitude : ℝ) := by
  by_cases zero : latitude = 0
  · subst latitude
    rw [Rat.cast_zero, nl_formula_zero]
    decide +kernel
  have real_zero : (latitude : ℝ) ≠ 0 := by exact_mod_cast zero
  have eq87 : |(latitude : ℝ)| = 87 ↔ absQ latitude = 87 := by
    rw [← absolute_cast]
    norm_cast
  have gt87 : 87 < |(latitude : ℝ)| ↔ 87 < absQ latitude := by
    rw [← absolute_cast]
    norm_cast
  by_cases exact_pole : absQ latitude = 87
  · have real_pole := eq87.mpr exact_pole
    simp [nlTable, exact_pole, nlFormula, real_zero, real_pole]
  by_cases beyond : 87 < absQ latitude
  · rw [table_beyond beyond]
    simp [nlFormula, real_zero, show ¬|(latitude : ℝ)| = 87 from fun h => exact_pole (eq87.mp h),
      gt87.mpr beyond]
  have abspositive : 0 < absQ latitude := by
    rw [absQ_eq_abs]
    exact abs_pos.mpr zero
  have absbelow : absQ latitude < 87 := lt_of_le_of_ne (le_of_not_gt beyond) exact_pole
  have real_below87 : |(latitude : ℝ)| < 87 := by
    rw [← absolute_cast]
    exact_mod_cast absbelow
  have real_below90 : |(latitude : ℝ)| < 90 := by linarith
  have counted := CPRTableClassification.classify (absQ latitude) abspositive absbelow
    (zoneRatio |(latitude : ℝ)|)
    (ratio_at_least_two (abs_nonneg _) real_below90)
    (ratio_below_sixty (abs_pos.mpr real_zero) real_below90)
    (indexed_threshold_comparison certificates avoids decodable real_below90)
  have table_abs : nlTable (absQ latitude) = nlTable latitude := by
    simp only [nlTable, absQ_eq_abs, abs_abs]
  rw [table_abs] at counted
  rw [counted]
  rw [ratio_abs]
  simp only [nlFormula, real_zero, ite_false,
    show ¬|(latitude : ℝ)| = 87 from fun h => exact_pole (eq87.mp h),
    show ¬87 < |(latitude : ℝ)| from fun h => beyond (gt87.mp h)]
  rfl

#print axioms classification
end Lean1090.Proofs.CPRNLClassification

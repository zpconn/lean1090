import Proofs.CPRCosineBounds
import Spec.CPRFormula

/-! Numerical certificates are checked with rational arithmetic; the transfer
into the real arccos formula uses the proved cosine bounds. -/
namespace Lean1090.Proofs.CPRTransitionCertificates
open CPRCosineBounds Spec.CPR

def CertificateCheck (c : NLCertificate) : Prop :=
  3 ≤ c.zone ∧ c.zone ≤ 59 ∧
  0 < c.lower12 ∧ c.lower12 < c.upper12 ∧ c.upper12 < 90 * 10 ^ 12 ∧
  0 < lowerCos ((c.lower12 : Rat) / (180 * 10 ^ 12)) ∧
  0 < lowerCos ((c.upper12 : Rat) / (180 * 10 ^ 12)) ∧
  upperCos (2 / (c.zone : Rat)) < 1 ∧
  (1 - lowerCos (1 / 30)) <
    lowerCos ((c.lower12 : Rat) / (180 * 10 ^ 12)) ^ 2 *
      (1 - upperCos (2 / (c.zone : Rat))) ∧
  upperCos ((c.upper12 : Rat) / (180 * 10 ^ 12)) ^ 2 *
      (1 - lowerCos (2 / (c.zone : Rat))) < 1 - upperCos (1 / 30)

instance (c : NLCertificate) : Decidable (CertificateCheck c) := by
  unfold CertificateCheck
  infer_instance

set_option maxRecDepth 100000 in
set_option maxHeartbeats 0 in
theorem all_checks : nlCertificates.all (fun c => decide (CertificateCheck c)) = true := by
  decide +kernel

theorem transition_of_bounds (zone : Nat) (lower upper : ℝ)
    (lower0 : 0 ≤ lower) (upper90 : upper < 90) (ordered : lower < upper)
    (denom : 0 < 1 - Real.cos (2 * Real.pi / (zone : ℝ)))
    (left : 1 - Real.cos (Real.pi / 30) <
      Real.cos (Real.pi * (lower / 180)) ^ 2 *
        (1 - Real.cos (2 * Real.pi / (zone : ℝ))))
    (right : Real.cos (Real.pi * (upper / 180)) ^ 2 *
      (1 - Real.cos (2 * Real.pi / (zone : ℝ))) <
        1 - Real.cos (Real.pi / 30)) :
    lower < transitionFormula zone ∧ transitionFormula zone < upper := by
  let numerator := 1 - Real.cos (Real.pi / 30)
  let denominator := 1 - Real.cos (2 * Real.pi / (zone : ℝ))
  have numerator0 : 0 < numerator := by
    have h := Real.cos_lt_cos_of_nonneg_of_le_pi (x := 0) (y := Real.pi / 30)
      (by norm_num) (by linarith [Real.pi_pos]) (by positivity)
    simp only [Real.cos_zero] at h
    exact sub_pos.mpr h
  have ratio0 : 0 ≤ numerator / denominator := le_of_lt (div_pos numerator0 denom)
  have cosL0 : 0 ≤ Real.cos (Real.pi * (lower / 180)) := by
    apply Real.cos_nonneg_of_mem_Icc
    constructor <;> nlinarith [Real.pi_pos]
  have cosU0 : 0 ≤ Real.cos (Real.pi * (upper / 180)) := by
    apply Real.cos_nonneg_of_mem_Icc
    constructor <;> nlinarith [Real.pi_pos]
  have upper0 : 0 ≤ upper := le_trans lower0 ordered.le
  have sqrt0 := Real.sqrt_nonneg (numerator / denominator)
  have square := Real.sq_sqrt ratio0
  have leftSq : numerator / denominator < Real.cos (Real.pi * (lower / 180)) ^ 2 := by
    exact (div_lt_iff₀ denom).mpr left
  have rightSq : Real.cos (Real.pi * (upper / 180)) ^ 2 < numerator / denominator := by
    exact (lt_div_iff₀ denom).mpr right
  have leftCos : Real.sqrt (numerator / denominator) < Real.cos (Real.pi * (lower / 180)) := by
    nlinarith
  have rightCos : Real.cos (Real.pi * (upper / 180)) < Real.sqrt (numerator / denominator) := by
    nlinarith
  have sqrt1 : Real.sqrt (numerator / denominator) ≤ 1 :=
    le_trans leftCos.le (Real.cos_le_one _)
  have lowerAngle := Real.arccos_lt_arccos (by linarith : -1 ≤ Real.sqrt (numerator / denominator))
    leftCos (Real.cos_le_one _)
  have upperAngle := Real.arccos_lt_arccos (by linarith : -1 ≤ Real.cos (Real.pi * (upper / 180)))
    rightCos sqrt1
  rw [Real.arccos_cos (by positivity) (by nlinarith [Real.pi_pos])] at lowerAngle
  rw [Real.arccos_cos (by positivity) (by nlinarith [Real.pi_pos])] at upperAngle
  have cancel (x : ℝ) : 180 / Real.pi * (Real.pi * (x / 180)) = x := by
    field_simp [Real.pi_ne_zero]
  constructor
  · rw [← cancel lower]
    exact mul_lt_mul_of_pos_left lowerAngle (by positivity)
  · rw [← cancel upper]
    exact mul_lt_mul_of_pos_left upperAngle (by positivity)

theorem certify (c : NLCertificate) (check : CertificateCheck c) : CertifiesTransition c := by
  obtain ⟨zone3, zone59, lower0, ordered, upper90, lc0, uc0, d0, left, right⟩ := check
  have zoneR : (3 : Rat) ≤ c.zone := by exact_mod_cast zone3
  have denominator0 : (0 : Rat) < c.zone := by linarith
  have co0 : (0 : Rat) ≤ 2 / (c.zone : Rat) := by positivity
  have co1 : 2 / (c.zone : Rat) ≤ 2 / 3 := by
    exact div_le_div_of_nonneg_left (by norm_num) (by norm_num) zoneR
  have upperR : (c.upper12 : Rat) < 90 * 10 ^ 12 := by exact_mod_cast upper90
  have orderedR : (c.lower12 : Rat) < c.upper12 := by exact_mod_cast ordered
  have lowerR0 : (0 : Rat) ≤ c.lower12 := by positivity
  have upperR0 : (0 : Rat) ≤ c.upper12 := by positivity
  have low1 : (c.lower12 : Rat) / (180 * 10 ^ 12) ≤ 2 / 3 := by linarith
  have up1 : (c.upper12 : Rat) / (180 * 10 ^ 12) ≤ 2 / 3 := by linarith
  have el := enclosure ((c.lower12 : Rat) / (180 * 10 ^ 12)) (by positivity) low1
  have eu := enclosure ((c.upper12 : Rat) / (180 * 10 ^ 12)) (by positivity) up1
  have ed := enclosure (2 / (c.zone : Rat)) co0 co1
  have en := enclosure (1 / 30) (by norm_num) (by norm_num)
  have leftR : (1 : ℝ) - (lowerCos (1 / 30) : ℝ) <
      (lowerCos ((c.lower12 : Rat) / (180 * 10 ^ 12)) : ℝ) ^ 2 *
      (1 - (upperCos (2 / (c.zone : Rat)) : ℝ)) := by exact_mod_cast left
  have rightR : (upperCos ((c.upper12 : Rat) / (180 * 10 ^ 12)) : ℝ) ^ 2 *
      (1 - (lowerCos (2 / (c.zone : Rat)) : ℝ)) < 1 - (upperCos (1 / 30) : ℝ) := by
    exact_mod_cast right
  have lcR0 : (0 : ℝ) < (lowerCos ((c.lower12 : Rat) / (180 * 10 ^ 12)) : ℝ) := by exact_mod_cast lc0
  have ucR0 : (0 : ℝ) < (lowerCos ((c.upper12 : Rat) / (180 * 10 ^ 12)) : ℝ) := by exact_mod_cast uc0
  have dR0 : (upperCos (2 / (c.zone : Rat)) : ℝ) < 1 := by exact_mod_cast d0
  have lowarg : (((c.lower12 : Rat) / (180 * 10 ^ 12) : Rat) : ℝ) =
      ((c.lower12 : ℝ) / 10 ^ 12) / 180 := by push_cast; ring
  have uparg : (((c.upper12 : Rat) / (180 * 10 ^ 12) : Rat) : ℝ) =
      ((c.upper12 : ℝ) / 10 ^ 12) / 180 := by push_cast; ring
  have zarg : Real.pi * ((2 / (c.zone : Rat) : Rat) : ℝ) = 2 * Real.pi / c.zone := by
    push_cast
    ring
  have narg : Real.pi * ((1 / 30 : Rat) : ℝ) = Real.pi / 30 := by norm_num; ring
  rw [lowarg] at el
  rw [uparg] at eu
  rw [zarg] at ed
  rw [narg] at en
  have dlower : 0 < 1 - (upperCos (2 / (c.zone : Rat)) : ℝ) := by linarith
  have dreal : 0 < 1 - Real.cos (2 * Real.pi / c.zone) := by linarith [ed.2]
  have leftSquare := mul_self_le_mul_self lcR0.le el.1
  have rightSquare := mul_self_le_mul_self (le_trans ucR0.le eu.1) eu.2
  have leftProduct := mul_le_mul leftSquare (sub_le_sub_left ed.2 1) dlower.le
    (mul_self_nonneg (Real.cos (Real.pi * ((c.lower12 : ℝ) / 10 ^ 12 / 180))))
  have rightProduct := mul_le_mul rightSquare (sub_le_sub_left ed.1 1) dreal.le
    (mul_self_nonneg (upperCos ((c.upper12 : Rat) / (180 * 10 ^ 12)) : ℝ))
  simp only [← sq] at leftProduct rightProduct
  suffices result : (c.lower12 : ℝ) / 10 ^ 12 < transitionFormula c.zone ∧
      transitionFormula c.zone < (c.upper12 : ℝ) / 10 ^ 12 by
    simpa only [CertifiesTransition, show (10 : ℝ) ^ 12 = 1000000000000 by norm_num] using result
  apply transition_of_bounds c.zone ((c.lower12 : ℝ) / 10 ^ 12) ((c.upper12 : ℝ) / 10 ^ 12)
    (by positivity) (by
      have h : (c.upper12 : ℝ) < 90 * 10 ^ 12 := by exact_mod_cast upper90
      linarith)
    (div_lt_div_of_pos_right (by exact_mod_cast ordered) (by positivity)) dreal
  · linarith [en.1]
  · linarith [en.2]

theorem certificates (c : NLCertificate) (member : c ∈ nlCertificates) : CertifiesTransition c :=
  certify c (of_decide_eq_true ((List.all_eq_true.mp all_checks) c member))

end Lean1090.Proofs.CPRTransitionCertificates

import Mathlib.Analysis.Calculus.Taylor
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Deriv
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Bounds
import Mathlib.Analysis.Real.Pi.Bounds
import Mathlib.Tactic.NormNum
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring
import Mathlib.Tactic.GCongr

/-! Rational enclosures for the real cosine, used only in CPR proofs. -/
namespace Lean1090.Proofs.CPRCosineBounds
open scoped BigOperators
open Set

def coefficient (k : Nat) : Rat := if k % 2 = 0 then (-1) ^ (k / 2) else 0

def approximation (x : Rat) : Rat :=
  ∑ k ∈ Finset.range 33, coefficient k / (k.factorial : Rat) * x ^ k

theorem derivative_zero (k : Nat) :
    iteratedDeriv k Real.cos 0 = (coefficient k : ℝ) := by
  obtain ⟨n, rfl | rfl⟩ := Nat.even_or_odd' k
  · simp [coefficient, Real.iteratedDeriv_even_cos]
  · simp [coefficient]

theorem taylor_approximation (x : Rat) :
    taylorWithinEval Real.cos 32 (Icc (0 : ℝ) 3) 0 (x : ℝ) =
      (approximation x : ℝ) := by
  rw [taylor_within_apply]
  simp only [sub_zero, smul_eq_mul,
    Real.iteratedDerivWithin_cos_Icc _ (by norm_num : (0 : ℝ) < 3)
      (by norm_num : (0 : ℝ) ∈ Icc (0 : ℝ) 3), derivative_zero]
  push_cast [approximation]
  apply Finset.sum_congr rfl
  intro k hk
  ring

theorem approximation_error (x : Rat) (lower : 0 ≤ x) (upper : x ≤ 9 / 4) :
    |Real.cos (x : ℝ) - (approximation x : ℝ)| ≤ 1 / 10 ^ 22 := by
  have lowerR : (0 : ℝ) ≤ x := by exact_mod_cast lower
  have upperR : (x : ℝ) ≤ 9 / 4 := by
    have h : (4 : ℝ) * x ≤ 9 := by exact_mod_cast (show (4 : Rat) * x ≤ 9 by linarith)
    linarith
  have bound := taylor_mean_remainder_bound (f := Real.cos) (n := 32)
    (a := 0) (b := 3) (C := 1) (x := (x : ℝ))
    (by norm_num) Real.contDiff_cos.contDiffOn (by constructor <;> linarith)
    (by
      intro y hy
      rw [Real.iteratedDerivWithin_cos_Icc _ (by norm_num : (0 : ℝ) < 3) hy,
        Real.norm_eq_abs]
      exact Real.abs_iteratedDeriv_cos_le_one _ _)
  rw [taylor_approximation, Real.norm_eq_abs] at bound
  refine bound.trans ?_
  simp only [sub_zero, one_mul]
  have power : (x : ℝ) ^ 33 ≤ (9 / 4 : ℝ) ^ 33 := by gcongr
  calc
    (x : ℝ) ^ 33 / (32).factorial ≤ (9 / 4 : ℝ) ^ 33 / (32).factorial := by gcongr
    _ ≤ 1 / 10 ^ 22 := by norm_num

def piApprox : Rat := 314159265358979323846 / 100000000000000000000

def argumentError (c : Rat) : Rat := c / 10 ^ 20 + 1 / 10 ^ 22

def lowerCos (c : Rat) : Rat := approximation (piApprox * c) - argumentError c

def upperCos (c : Rat) : Rat := approximation (piApprox * c) + argumentError c

theorem enclosure (c : Rat) (lower : 0 ≤ c) (upper : c ≤ 2 / 3) :
    (lowerCos c : ℝ) ≤ Real.cos (Real.pi * (c : ℝ)) ∧
      Real.cos (Real.pi * (c : ℝ)) ≤ (upperCos c : ℝ) := by
  have c0 : (0 : ℝ) ≤ c := by exact_mod_cast lower
  have c1 : (c : ℝ) ≤ 2 / 3 := by
    have h : (3 : ℝ) * c ≤ 2 := by exact_mod_cast (show (3 : Rat) * c ≤ 2 by linarith)
    linarith
  have pi0 : (piApprox : ℝ) < Real.pi := by
    convert Real.pi_gt_d20 using 1; norm_num [piApprox]
  have pi1 : Real.pi < (piApprox : ℝ) + 1 / 10 ^ 20 := by
    convert Real.pi_lt_d20 using 1; norm_num [piApprox]
  have argument : |Real.pi * (c : ℝ) - ((piApprox * c : Rat) : ℝ)| ≤
      (c : ℝ) / 10 ^ 20 := by
    push_cast
    rw [abs_of_nonneg (by nlinarith : 0 ≤ Real.pi * (c : ℝ) - (piApprox : ℝ) * c)]
    nlinarith
  have approximate := approximation_error (piApprox * c)
    (mul_nonneg (by norm_num [piApprox]) lower)
    (by unfold piApprox; nlinarith)
  have distance := (abs_sub_le (Real.cos (Real.pi * (c : ℝ)))
      (Real.cos ((piApprox * c : Rat) : ℝ)) (approximation (piApprox * c) : ℝ)).trans
    (add_le_add ((Real.abs_cos_sub_cos_le _ _).trans argument) approximate)
  have error : (c : ℝ) / 10 ^ 20 + 1 / 10 ^ 22 = (argumentError c : ℝ) := by
    norm_num [argumentError]
  rw [error] at distance
  have bounds := abs_le.mp distance
  change ((approximation (piApprox * c) - argumentError c : Rat) : ℝ) ≤ _ ∧
    _ ≤ ((approximation (piApprox * c) + argumentError c : Rat) : ℝ)
  push_cast
  constructor <;> linarith

end Lean1090.Proofs.CPRCosineBounds

import Proofs.CommBFieldBounds

/-!
# Conditional finite bounds for density traces

For bounded inputs and fitted constants, these theorems bound every exact and
rounded Gaussian/Laplace intermediate by 2^170. These conservative bounds are
used only for arithmetic-domain safety; runtime scores remain exact. The
concrete density_bounds theorem covers every register's actual field terms
and traces, including the optional and compatibility-projected fields.
-/
namespace Lean1090.Proofs.CommBArithmeticFacts
set_option maxHeartbeats 2000000
open Spec Binary64Facts

theorem gaussian_bounds (value mu sigma : Rat) (valueBound : value.abs ≤ 2 ^ 70)
    (muBound : (Binary64.literal mu).abs ≤ 2 ^ 70)
    (sigmaLow : 1/10 ≤ Binary64.literal sigma)
    (sigmaBound : (Binary64.literal sigma).abs ≤ 2 ^ 70) :
    (∀ x ∈ cbGaussianTrace value mu sigma, x.abs ≤ 2 ^ 170) ∧
    (cbGaussian value mu sigma).abs ≤ 2 ^ 170 := by
  let m := Binary64.literal mu
  let s := Binary64.literal sigma
  let d := Binary64.sub value m
  let z := Binary64.div d s
  let h := Binary64.mul (-1/2) z
  have sigmaAbsLow : (1/10 : Rat) ≤ s.abs := by
    rw [Rat.abs_of_nonneg (by dsimp [s]; linarith)]
    exact sigmaLow
  have dExact : (value - m).abs ≤ 2 ^ 71 :=
    le_trans (abs_sub_bound value m (2^70) (2^70) valueBound muBound) (by norm_num)
  have dBound : d.abs ≤ 2 ^ 73 :=
    le_trans (round_bound_of_abs_le (value - m) (2^71) dExact) (by norm_num)
  have zExact : (d/s).abs ≤ 2 ^ 77 :=
    le_trans (abs_div_bound d s (2^73) (1/10) dBound sigmaAbsLow (by decide +kernel)) (by norm_num)
  have zBound : z.abs ≤ 2 ^ 79 :=
    le_trans (round_bound_of_abs_le (d/s) (2^77) zExact) (by norm_num)
  have hExact : ((-1/2)*z).abs ≤ 2 ^ 79 :=
    le_trans (abs_mul_bound (-1/2) z 1 (2^79) (by decide +kernel) zBound) (by norm_num)
  have hBound : h.abs ≤ 2 ^ 81 :=
    le_trans (round_bound_of_abs_le ((-1/2)*z) (2^79) hExact) (by norm_num)
  have resultExact : (h*z).abs ≤ 2 ^ 160 :=
    le_trans (abs_mul_bound h z (2^81) (2^79) hBound zBound) (by norm_num)
  have resultBound : (Binary64.mul h z).abs ≤ 2 ^ 162 :=
    le_trans (round_bound_of_abs_le (h*z) (2^160) resultExact) (by norm_num)
  constructor
  · intro x member
    change x ∈ [value,m,s,value-m,d,d/s,z,(-1/2)*z,h,h*z,Binary64.mul h z] at member
    simp only [List.mem_cons, List.not_mem_nil, or_false] at member
    rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
    all_goals norm_num at *; linarith
  · change (Binary64.mul h z).abs ≤ _
    exact le_trans resultBound (by norm_num)

theorem laplace_bounds (value median scale : Rat) (valueBound : value.abs ≤ 2 ^ 70)
    (medianBound : (Binary64.literal median).abs ≤ 2 ^ 70)
    (scaleLow : 1/10 ≤ Binary64.literal scale)
    (scaleBound : (Binary64.literal scale).abs ≤ 2 ^ 70) :
    (∀ x ∈ cbLaplaceTrace value median scale, x.abs ≤ 2 ^ 170) ∧
    (cbLaplace value median scale).abs ≤ 2 ^ 170 := by
  let m := Binary64.literal median
  let b := Binary64.literal scale
  let d := Binary64.sub value m
  have scaleAbsLow : (1/10 : Rat) ≤ b.abs := by
    rw [Rat.abs_of_nonneg (by dsimp [b]; linarith)]
    exact scaleLow
  have dExact : (value - m).abs ≤ 2 ^ 71 :=
    le_trans (abs_sub_bound value m (2^70) (2^70) valueBound medianBound) (by norm_num)
  have dBound : d.abs ≤ 2 ^ 73 :=
    le_trans (round_bound_of_abs_le (value - m) (2^71) dExact) (by norm_num)
  have negativeBound : (-d.abs).abs ≤ 2 ^ 73 := by
    simpa only [rat_abs_eq_abs, abs_neg, abs_abs] using dBound
  have exactBound : (-d.abs/b).abs ≤ 2 ^ 77 :=
    le_trans (abs_div_bound (-d.abs) b (2^73) (1/10) negativeBound scaleAbsLow (by decide +kernel)) (by norm_num)
  have resultBound : (Binary64.div (-d.abs) b).abs ≤ 2 ^ 79 :=
    le_trans (round_bound_of_abs_le (-d.abs/b) (2^77) exactBound) (by norm_num)
  dsimp only [cbLaplaceTrace, cbLaplace]
  split
  · simp only [List.mem_singleton, forall_eq, Rat.abs_zero]
    constructor <;> norm_num
  · constructor
    · intro x member
      change x ∈ [value,m,b,value-m,d,-d.abs,-d.abs/b,Binary64.div (-d.abs) b] at member
      simp only [List.mem_cons, List.not_mem_nil, or_false] at member
      rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
      all_goals norm_num at *; linarith
    · change (Binary64.div (-d.abs) b).abs ≤ _
      exact le_trans resultBound (by norm_num)

#print axioms gaussian_bounds
#print axioms laplace_bounds
def Bounded (xs : List Rat) (bound : Rat) : Prop := ∀ x ∈ xs, x.abs ≤ bound

@[simp] theorem bounded_nil (bound : Rat) : Bounded [] bound := by simp [Bounded]
@[simp] theorem bounded_append (xs ys : List Rat) (bound : Rat) :
    Bounded (xs ++ ys) bound ↔ Bounded xs bound ∧ Bounded ys bound := by
  simp only [Bounded, List.mem_append]
  aesop
@[simp] theorem bounded_singleton (x bound : Rat) :
    Bounded [x] bound ↔ x.abs ≤ bound := by simp [Bounded]

theorem traceField_bound (value : Option Rat) (trace : Rat → List Rat) (bound : Rat)
    (h : ∀ x, value = some x → Bounded (trace x) bound) :
    Bounded (cbTraceField value trace) bound := by
  cases value with
  | none => simp [cbTraceField]
  | some x => exact h x rfl

theorem scoreField_bound (value : Option Rat) (score : Rat → Rat) (bound : Rat)
    (h : ∀ x, value = some x → (score x).abs ≤ bound) :
    Bounded (cbScoreField value score) bound := by
  cases value with
  | none => simp [cbScoreField]
  | some x => simpa [cbScoreField] using h x rfl

theorem constant_map_bound (opt : Option Rat) (value bound : Rat) (h : value.abs ≤ bound) :
    ∀ x, opt.map (fun _ => value) = some x → x.abs ≤ bound := by
  cases opt <;> simp_all

theorem density_bounds (register word : Nat) :
    Bounded (cbDensityTrace register word) (2^170) ∧
    Bounded (cbDensityTerms register word) (2^170) := by
  have hval := value_bound register word
  have hq := constant_map_bound (commBValue register word "barometric_setting")
    (cbQNH64 word) (2^70) (field_arithmetic_bounds word).2.1
  have hm := constant_map_bound (commBValue register word "Mach")
    (cbMach64 word) (2^70) (field_arithmetic_bounds word).2.2
  have ht : (cbTemperature44 word).abs ≤ 2^70 :=
    (temperature_bound word).trans (by norm_num)
  constructor
  · unfold cbDensityTrace
    split <;> simp only [bounded_append, bounded_nil]
    all_goals repeat' apply And.intro
    all_goals try (with_reducible apply traceField_bound; intro x hx)
    all_goals dsimp only [Bounded]
    all_goals first
      | (with_reducible apply (gaussian_bounds _ _ _ ?_ ?_ ?_ ?_).1)
      | (with_reducible apply (laplace_bounds _ _ _ ?_ ?_ ?_ ?_).1)
    all_goals first | exact hval _ _ hx | exact hq _ hx | exact hm _ hx | exact ht | decide +kernel
  · unfold cbDensityTerms
    split <;> simp only [bounded_append, bounded_singleton, bounded_nil]
    all_goals repeat' apply And.intro
    all_goals try (with_reducible apply scoreField_bound; intro x hx)
    all_goals first
      | (with_reducible apply (gaussian_bounds _ _ _ ?_ ?_ ?_ ?_).2)
      | (with_reducible apply (laplace_bounds _ _ _ ?_ ?_ ?_ ?_).2)
    all_goals first | exact hval _ _ hx | exact hq _ hx | exact hm _ hx | exact ht | decide +kernel

end Lean1090.Proofs.CommBArithmeticFacts

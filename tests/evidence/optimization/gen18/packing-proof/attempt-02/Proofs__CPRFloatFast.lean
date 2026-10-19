import Proofs.Binary64Dyadic
import Proofs.Binary64Runtime
import Spec.CPRFloat
import Impl.CPRFloat

/-!
# Exact small-dyadic bit assembly

The fast path produces exactly the argument to the original `Float.ofBits`.
No theorem assigns real-number semantics to Float arithmetic. Inputs outside
its explicit guard retain the total reference conversion, including rounding
tiny negative values to positive zero.
-/
namespace Lean1090.Proofs.CPRFloatFast

private theorem floor_nat (n : Nat) : (n : Rat).floor.toNat = n := by
  rw [← Rat.intCast_natCast, Rat.floor_intCast]
  rfl

private theorem exponent_abs (value : Rat) :
    Spec.Binary64.exponent value.abs = Spec.Binary64.exponent value := by
  by_cases h : 0 ≤ value
  · rw [Rat.abs_of_nonneg h]
  · rw [Rat.abs_of_nonpos (le_of_not_ge h)]
    simp [Spec.Binary64.exponent]

/-- The fallback is the unchanged total reference Float program. -/
theorem fallback_eq (value : Rat) :
    Impl.CPR.Policy.toFloatFallback value = Spec.CPR.Policy.toFloat value := by
  unfold Impl.CPR.Policy.toFloatFallback Spec.CPR.Policy.toFloat
  simp only [Binary64Runtime.round_eq, Binary64Runtime.exponent_eq,
    Binary64Runtime.powerTwo_eq]

/-- Guarded bit packing agrees before the opaque Float operation, for every
nonzero rational with the stated exact dyadic representation. -/
theorem smallDyadic_eq (value : Rat) (k : Nat) (h0 : value ≠ 0)
    (hden : value.den = 2^k) (hn : value.num.natAbs < 2^53) (hk : k ≤ 1074) :
    Float.ofBits (Impl.CPR.Policy.smallDyadicBits (decide (value.num < 0))
      value.num.natAbs k).toUInt64 = Spec.CPR.Policy.toFloat value := by
  have hnum : value.num.natAbs ≠ 0 := by
    intro hz
    exact h0 (Rat.num_eq_zero.mp (Int.natAbs_eq_zero.mp hz))
  have hhigh : value.num.natAbs.log2 ≤ 52 := by
    have := (Nat.log2_lt hnum).mpr hn
    omega
  have hexponent := (exponent_abs value).trans (Binary64Dyadic.exponent_eq value k h0 hden)
  have habs : value.abs ≠ 0 := ne_of_gt (Rat.abs_pos_iff.mpr h0)
  have hsign : value.num < 0 ↔ value < 0 := by
    simpa only [not_le] using not_congr (Rat.num_nonneg (q := value))
  have noOverflow : ¬(value.num.natAbs.log2 : Int) - k > 1023 := by omega
  have subnormal : (value.abs / Spec.Binary64.powerTwo (-1074)).floor.toNat =
      value.num.natAbs <<< (1074 - k) := by
    rw [Binary64Dyadic.scaled_eq_nat value k (-1074) hden (by omega), floor_nat]
    rw [Nat.shiftLeft_eq]
    congr 2
    omega
  have normal : (value.abs / Spec.Binary64.powerTwo
      ((value.num.natAbs.log2 : Int) - k - 52)).floor.toNat =
      value.num.natAbs <<< (52 - value.num.natAbs.log2) := by
    rw [Binary64Dyadic.scaled_eq_nat value k _ hden (by omega), floor_nat]
    rw [Nat.shiftLeft_eq]
    congr 2
    omega
  unfold Spec.CPR.Policy.toFloat
  rw [Binary64Dyadic.round_eq value k hden hn hk]
  simp only [hexponent, beq_iff_eq, habs, ↓reduceIte, noOverflow]
  unfold Impl.CPR.Policy.smallDyadicBits
  simp only [decide_eq_true_eq, hsign, subnormal, normal]

/-- Unconditional refinement for arbitrary Rat inputs, including all fallback
cases and the positive-zero branch. -/
theorem toFloat_eq (value : Rat) :
    Impl.CPR.Policy.toFloat value = Spec.CPR.Policy.toFloat value := by
  unfold Impl.CPR.Policy.toFloat
  split
  next zero =>
    have hz : value = 0 := Rat.num_eq_zero.mp (by simpa only [beq_iff_eq] using zero)
    subst value
    simp [Spec.CPR.Policy.toFloat, Spec.Binary64.round]
  next nonzero =>
    dsimp only
    split
    next guard =>
      have h0 : value ≠ 0 := by
        intro hz
        subst value
        simp at nonzero
      apply smallDyadic_eq value value.den.log2 h0
      · simpa only [Nat.shiftLeft_eq, one_mul] using guard.2.2
      · exact guard.1
      · exact guard.2.1
    next => exact fallback_eq value

theorem toFloat_function_eq : Impl.CPR.Policy.toFloat = Spec.CPR.Policy.toFloat :=
  funext toFloat_eq

/-- Zero is explicitly positive zero, without evaluating Float arithmetic. -/
theorem zero_witness : Impl.CPR.Policy.toFloat 0 = Float.ofBits 0 := by rfl

theorem min_subnormal_witness :
    Impl.CPR.Policy.smallDyadicBits false 1 1074 = 1 ∧
    Impl.CPR.Policy.smallDyadicBits true 1 1074 = 2^63 + 1 := by decide +kernel

theorem subnormal_normal_boundary_witness :
    Impl.CPR.Policy.smallDyadicBits false (2^52 - 1) 1074 = 2^52 - 1 ∧
    Impl.CPR.Policy.smallDyadicBits true (2^52 - 1) 1074 = 2^63 + (2^52 - 1) ∧
    Impl.CPR.Policy.smallDyadicBits false 1 1022 = 2^52 ∧
    Impl.CPR.Policy.smallDyadicBits true 1 1022 = 2^63 + 2^52 := by decide +kernel

theorem largest_small_numerator_witness :
    Impl.CPR.Policy.smallDyadicBits false (2^53 - 1) 0 = 1076 * 2^52 - 1 ∧
    Impl.CPR.Policy.smallDyadicBits true (2^53 - 1) 0 = 2^63 + 1076 * 2^52 - 1 := by
  decide +kernel

/-- Three distinct excluded domains keep the original conversion available. -/
theorem guard_rejection_witness :
    ¬((2^53 : Rat).num.natAbs < 2^53) ∧
    ¬((1 / (2^1075 : Nat) : Rat).den.log2 ≤ 1074) ∧
    ¬((1 / 3 : Rat).den = 1 <<< (1 / 3 : Rat).den.log2) := by decide +kernel

/-- The model's signed-underflow behavior is retained by the fallback; a tie
rounds to zero, while the adjacent three-quarter quantum rounds away from it. -/
theorem underflow_witness :
    Spec.Binary64.round (1 / (2^1075 : Nat) : Rat) = 0 ∧
    Spec.Binary64.round (-1 / (2^1075 : Nat) : Rat) = 0 ∧
    Spec.Binary64.round (3 / (2^1076 : Nat) : Rat) = 1 / (2^1074 : Nat) ∧
    Spec.Binary64.round (-3 / (2^1076 : Nat) : Rat) = -1 / (2^1074 : Nat) := by
  decide +kernel

#print axioms fallback_eq
#print axioms smallDyadic_eq
#print axioms toFloat_eq
#print axioms toFloat_function_eq
#print axioms zero_witness
#print axioms min_subnormal_witness
#print axioms subnormal_normal_boundary_witness
#print axioms largest_small_numerator_witness
#print axioms guard_rejection_witness
#print axioms underflow_witness

end Lean1090.Proofs.CPRFloatFast

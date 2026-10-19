import Proofs.Binary64Bounds

/-!
# Exact small dyadics in the software binary64 model

All statements concern the frozen rational model, before any Float operation.
The denominator and numerator bounds are explicit input hypotheses, independent
of message fields, coordinates or a particular corpus.
-/
namespace Lean1090.Proofs.Binary64Dyadic
open Spec Binary64Facts

theorem exponent_eq (value : Rat) (k : Nat) (h0 : value ≠ 0)
    (hden : value.den = 2^k) :
    Binary64.exponent value = (value.num.natAbs.log2 : Int) - k := by
  have hn : value.num.natAbs ≠ 0 := by
    intro h
    exact h0 (Rat.num_eq_zero.mp (Int.natAbs_eq_zero.mp h))
  have bound : (2 : Rat)^value.num.natAbs.log2 ≤ (value.num.natAbs : Rat) := by
    exact_mod_cast (Nat.le_log2 hn).mp (Nat.le_refl _)
  have lower : Binary64.powerTwo ((value.num.natAbs.log2 : Int) - k) ≤ value.abs := by
    rw [powerTwo_eq_zpow, zpow_sub₀ (by decide : (2 : Rat) ≠ 0),
      zpow_natCast, zpow_natCast, ← abs_num_den, hden, Nat.cast_pow, Nat.cast_ofNat]
    exact div_le_div_of_nonneg_right bound (by positivity)
  simp only [Binary64.exponent, hden, Nat.log2_two_pow]
  exact if_neg (not_lt.mpr lower)

theorem scaled_eq_nat (value : Rat) (k : Nat) (t : Int)
    (hden : value.den = 2^k) (ht : t ≤ -(k : Int)) :
    value.abs / Binary64.powerTwo t =
      ((value.num.natAbs * 2 ^ (-(k : Int) - t).toNat : Nat) : Rat) := by
  have nonneg : 0 ≤ -(k : Int) - t := by omega
  calc
    _ = (value.num.natAbs : Rat) * (2 : Rat)^(-(k : Int) - t) := by
      rw [← abs_num_den, hden, Nat.cast_pow, Nat.cast_ofNat, powerTwo_eq_zpow,
        ← zpow_natCast, div_div, ← zpow_add₀ (by decide : (2 : Rat) ≠ 0),
        div_eq_mul_inv, ← zpow_neg]
      congr 2
      omega
    _ = _ := by
      rw [Nat.cast_mul, Nat.cast_pow, Nat.cast_ofNat, ← zpow_natCast,
        Int.toNat_of_nonneg nonneg]

theorem nearestEven_nat (n : Nat) :
    Binary64.nearestEven (n : Rat).num.natAbs (n : Rat).den = n := by
  simp [Binary64.nearestEven]

theorem round_eq (value : Rat) (k : Nat) (hden : value.den = 2^k)
    (hn : value.num.natAbs < 2^53) (hk : k ≤ 1074) :
    Binary64.round value = value := by
  by_cases h0 : value = 0
  · simp [h0, Binary64.round]
  have logBound : value.num.natAbs.log2 ≤ 52 := by
    have := Nat.lt_log2_self (n := value.num.natAbs)
    have : value.num.natAbs.log2 < 53 := Nat.log2_lt hn
    omega
  let t : Int := max (-1074) (Binary64.exponent value - 52)
  have ht : t ≤ -(k : Int) := by
    dsimp [t]
    rw [exponent_eq value k h0 hden]
    omega
  let n := value.num.natAbs * 2 ^ (-(k : Int) - t).toNat
  have scaled : value.abs / Binary64.powerTwo t = (n : Rat) :=
    scaled_eq_nat value k t hden ht
  have product : (n : Rat) * Binary64.powerTwo t = value.abs := by
    rw [← scaled]
    exact div_mul_cancel₀ _ (ne_of_gt (powerTwo_pos t))
  unfold Binary64.round
  simp only [beq_iff_eq, h0, ↓reduceIte]
  change (if value < 0 then
    -((Binary64.nearestEven (value.abs / Binary64.powerTwo t).num.natAbs
      (value.abs / Binary64.powerTwo t).den : Rat) * Binary64.powerTwo t)
    else (Binary64.nearestEven (value.abs / Binary64.powerTwo t).num.natAbs
      (value.abs / Binary64.powerTwo t).den : Rat) * Binary64.powerTwo t) = value
  rw [scaled, nearestEven_nat, product]
  split
  · rename_i negative
    rw [Rat.abs_of_nonpos negative.le, neg_neg]
  · rename_i nonnegative
    exact Rat.abs_of_nonneg (le_of_not_gt nonnegative)

#print axioms exponent_eq
#print axioms scaled_eq_nat
#print axioms nearestEven_nat
#print axioms round_eq

end Lean1090.Proofs.Binary64Dyadic

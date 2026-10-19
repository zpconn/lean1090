import Capstones

/-!
# Conservative bounds for the exact software binary64 model

These inequalities establish finite-range safety; they do not approximate the
score gate. The rational reference still performs every original rounding.
The absolute round bound follows from the quotient/remainder rounding rule
and the binade estimate's integer bit-length bounds, for every rational input.
-/
namespace Lean1090.Proofs.Binary64Facts
open Spec

theorem powerTwo_eq_zpow (e : Int) : Binary64.powerTwo e = (2 : Rat) ^ e := by
  cases e with
  | ofNat n => simp [Binary64.powerTwo]
  | negSucc n => simp [Binary64.powerTwo, zpow_negSucc]

theorem powerTwo_pos (e : Int) : 0 < Binary64.powerTwo e := by
  rw [powerTwo_eq_zpow]
  exact zpow_pos (by decide) e

theorem powerTwo_mono {a b : Int} (h : a ≤ b) : Binary64.powerTwo a ≤ Binary64.powerTwo b := by
  simp only [powerTwo_eq_zpow]
  exact zpow_le_zpow_right₀ (by decide) h

theorem rat_abs_eq_abs (value : Rat) : value.abs = |value| := by
  rcases le_total 0 value with h | h
  · rw [Rat.abs_of_nonneg h, abs_of_nonneg h]
  · rw [Rat.abs_of_nonpos h, abs_of_nonpos h]

theorem abs_num_den (value : Rat) :
    (value.num.natAbs : Rat) / (value.den : Rat) = value.abs := by
  rw [rat_abs_eq_abs, Rat.abs_def, Rat.divInt_eq_div]
  simp

theorem candidate_le_twice_abs (value : Rat) (nonzero : value ≠ 0) :
    Binary64.powerTwo ((value.num.natAbs.log2 : Int) - (value.den.log2 : Int)) ≤
      2 * value.abs := by
  have hn : value.num.natAbs ≠ 0 := by
    intro zero
    have : value.num = 0 := Int.natAbs_eq_zero.mp zero
    exact nonzero (Rat.num_eq_zero.mp this)
  have numBound : (2 : Rat) ^ value.num.natAbs.log2 ≤ (value.num.natAbs : Rat) := by
    exact_mod_cast (Nat.le_log2 hn).mp (Nat.le_refl _)
  have denBound : (value.den : Rat) ≤ 2 * (2 : Rat) ^ value.den.log2 := by
    have h := Nat.lt_log2_self (n := value.den)
    rw [Nat.pow_succ] at h
    rw [Nat.mul_comm] at h
    exact_mod_cast Nat.le_of_lt h
  have numNonneg : (0 : Rat) ≤ value.num.natAbs := by positivity
  have denPos : (0 : Rat) < value.den := by exact_mod_cast value.den_pos
  have powDenPos : (0 : Rat) < 2 ^ value.den.log2 := by positivity
  rw [powerTwo_eq_zpow, zpow_sub₀ (by decide), zpow_natCast, zpow_natCast,
    ← abs_num_den, show 2 * ((value.num.natAbs : Rat) / value.den) =
      (2 * value.num.natAbs) / value.den by ring]
  apply (div_le_div_iff₀ powDenPos denPos).mpr
  calc
    _ ≤ (value.num.natAbs : Rat) * value.den :=
      mul_le_mul_of_nonneg_right numBound denPos.le
    _ ≤ value.num.natAbs * (2 * (2 : Rat) ^ value.den.log2) :=
      mul_le_mul_of_nonneg_left denBound numNonneg
    _ = _ := by ring

theorem quantum_bound (value : Rat) (nonzero : value ≠ 0) :
    Binary64.powerTwo (max (-1074) (Binary64.exponent value - 52)) ≤ 2 * value.abs + 1 := by
  have absNonneg : 0 ≤ value.abs := Rat.abs_nonneg
  by_cases h : -1074 ≤ Binary64.exponent value - 52
  · rw [max_eq_right h]
    have exponentBound : Binary64.exponent value - 52 ≤
        (value.num.natAbs.log2 : Int) - (value.den.log2 : Int) := by
      dsimp only [Binary64.exponent]
      split <;> omega
    have := le_trans (powerTwo_mono exponentBound) (candidate_le_twice_abs value nonzero)
    linarith
  · rw [max_eq_left (le_of_not_ge h)]
    have small := powerTwo_mono (show (-1074 : Int) ≤ 0 by decide)
    rw [show Binary64.powerTwo 0 = 1 from rfl] at small
    linarith

theorem round_bound (value : Rat) : (Binary64.round value).abs ≤ 3 * value.abs + 1 := by
  by_cases zero : value = 0
  · simp [zero, Binary64.round]
  · have qPos := powerTwo_pos (max (-1074) (Binary64.exponent value - 52))
    let q := Binary64.powerTwo (max (-1074) (Binary64.exponent value - 52))
    have qPositive : 0 < q := qPos
    let scaled := value.abs / q
    have scaledNonneg : 0 ≤ scaled := div_nonneg (Rat.abs_nonneg) qPositive.le
    have nearestBound : Binary64.nearestEven scaled.num.natAbs scaled.den ≤
        scaled.num.natAbs / scaled.den + 1 := by
      dsimp only [Binary64.nearestEven]
      split <;> omega
    have scaledRep : (scaled.num.natAbs : Rat) / scaled.den = scaled := by
      rw [abs_num_den, Rat.abs_of_nonneg scaledNonneg]
    have roundedBound : (Binary64.nearestEven scaled.num.natAbs scaled.den : Rat) ≤ scaled + 1 := by
      calc
        _ ≤ ((scaled.num.natAbs / scaled.den + 1 : Nat) : Rat) := by exact_mod_cast nearestBound
        _ ≤ (scaled.num.natAbs : Rat) / scaled.den + 1 := by
          simp only [Nat.cast_add, Nat.cast_one]
          have castBound : ((scaled.num.natAbs / scaled.den : Nat) : Rat) ≤
              (scaled.num.natAbs : Rat) / scaled.den := Nat.cast_div_le
          linarith
        _ = _ := by rw [scaledRep]
    have roundedNonneg : 0 ≤ (Binary64.nearestEven scaled.num.natAbs scaled.den : Rat) * q := by positivity
    have absolute : (Binary64.round value).abs =
        (Binary64.nearestEven scaled.num.natAbs scaled.den : Rat) * q := by
      unfold Binary64.round
      simp only [beq_iff_eq, zero, ↓reduceIte]
      change (if value < 0 then -((Binary64.nearestEven scaled.num.natAbs scaled.den : Rat) * q)
        else (Binary64.nearestEven scaled.num.natAbs scaled.den : Rat) * q).abs = _
      split <;> simp [Rat.abs_neg, Rat.abs_of_nonneg roundedNonneg]
    rw [absolute]
    have bound := mul_le_mul_of_nonneg_right roundedBound qPositive.le
    have product : (scaled + 1) * q = value.abs + q := by
      dsimp [scaled]
      field_simp [ne_of_gt qPositive]
    rw [product] at bound
    have quantum := quantum_bound value zero
    change q ≤ 2 * value.abs + 1 at quantum
    linarith

#print axioms round_bound
theorem abs_add_bound (a b A B : Rat) (ha : a.abs ≤ A) (hb : b.abs ≤ B) :
    (a + b).abs ≤ A + B := by
  simp only [rat_abs_eq_abs] at ha hb ⊢
  exact (abs_add_le a b).trans (add_le_add ha hb)

theorem abs_sub_bound (a b A B : Rat) (ha : a.abs ≤ A) (hb : b.abs ≤ B) :
    (a - b).abs ≤ A + B := by
  simpa only [sub_eq_add_neg, Rat.abs_neg] using abs_add_bound a (-b) A B ha (by simpa using hb)

theorem abs_mul_bound (a b A B : Rat) (ha : a.abs ≤ A) (hb : b.abs ≤ B) :
    (a * b).abs ≤ A * B := by
  have nonnegative : 0 ≤ A := le_trans Rat.abs_nonneg ha
  simpa only [rat_abs_eq_abs, abs_mul] using mul_le_mul ha hb Rat.abs_nonneg nonnegative

theorem abs_div_bound (a b A B : Rat) (ha : a.abs ≤ A) (hb : B ≤ b.abs) (positive : 0 < B) :
    (a / b).abs ≤ A / B := by
  have nonnegative : 0 ≤ A := le_trans Rat.abs_nonneg ha
  have divisorPositive : 0 < b.abs := lt_of_lt_of_le positive hb
  simp only [rat_abs_eq_abs] at *
  rw [abs_div]
  apply (div_le_div_iff₀ divisorPositive positive).mpr
  exact le_trans (mul_le_mul_of_nonneg_right ha positive.le)
    (mul_le_mul_of_nonneg_left hb nonnegative)

theorem round_bound_of_abs_le (value bound : Rat) (h : value.abs ≤ bound) :
    (Binary64.round value).abs ≤ 3 * bound + 1 := by
  have := round_bound value
  linarith

end Lean1090.Proofs.Binary64Facts

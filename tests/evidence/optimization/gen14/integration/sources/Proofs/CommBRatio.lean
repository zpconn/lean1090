import Impl.CommB
import Proofs.Binary64Error

/-!
The integer enclosure decides exactly the old rounded ratio predicate.
The theorem applies to every rational, including zero, negative values and
arbitrary magnitudes; callers retain the original finite-arithmetic contracts.
-/

namespace Lean1090.Proofs.CommBRatio

set_option maxHeartbeats 2000000

/-- The live enclosure equals the original rounded comparison for every Rat. -/
theorem cbRatioOutside250800_eq (q : Rat) :
    Impl.cbRatioOutside250800 q =
      (Impl.Binary64.round q < 250 || Impl.Binary64.round q > 800) := by
  let n := q.num
  let d : Int := q.den
  let k : Int := 2251799813685248
  let e : Int := (q.num.natAbs : Int) + d
  let c := k * n
  let lower := 250 * k * d
  let upper := 800 * k * d
  let factor : Rat := (k : Rat) * d
  let error : Rat := (|q| + 1) / (k : Rat)
  let rounded := Impl.Binary64.round q
  have dp : (0 : Rat) < d := by
    dsimp only [d]
    exact_mod_cast q.den_pos
  have kp : (0 : Rat) < k := by norm_num [k]
  have fp : 0 < factor := mul_pos kp dp
  have nc : (n : Rat) = (d : Rat) * q := by
    dsimp only [n, d]
    calc
      (q.num : Rat) = (q.den : Rat) * ((q.num : Rat) / q.den) := by field_simp
      _ = _ := by simp only [Rat.num_div_den, Int.cast_natCast]
  have ac : (q.num.natAbs : Rat) = (d : Rat) * |q| := by
    have h := congrArg abs nc
    simpa only [n, abs_mul, abs_of_pos dp, Nat.cast_natAbs, Int.cast_abs] using h
  have cc : (c : Rat) = factor * q := by
    dsimp only [c, factor]
    rw [Int.cast_mul, nc]
    ring
  have ec : (e : Rat) = factor * error := by
    dsimp only [e, factor, error]
    rw [Int.cast_add, Int.cast_natCast, ac]
    field_simp
  have lc : (lower : Rat) = factor * 250 := by
    dsimp only [lower, factor]
    push_cast
    ring
  have uc : (upper : Rat) = factor * 800 := by
    dsimp only [upper, factor]
    push_cast
    ring
  have bounded : |rounded - q| ≤ error := by
    have h := Binary64Error.round_error_of_bound q (|q| + 1)
      (by have := abs_nonneg q; linarith) (by linarith)
    calc
      |rounded - q| ≤ 2 * (|q| + 1) / (2 : Rat)^52 := h
      _ = error := by norm_num [error, k]; ring
  obtain ⟨blo, bhi⟩ := abs_le.mp bounded
  have rlo : (c : Rat) - e ≤ factor * rounded := by
    rw [cc, ec]
    nlinarith
  have rhi : factor * rounded ≤ (c : Rat) + e := by
    rw [cc, ec]
    nlinarith
  have outside (h : c + e < lower ∨ upper < c - e) :
      (rounded < 250 || rounded > 800) = true := by
    simp only [Bool.or_eq_true, decide_eq_true_eq]
    rcases h with h | h
    · left
      have hc : (c : Rat) + e < lower := by exact_mod_cast h
      rw [lc] at hc
      nlinarith
    · right
      have hc : (upper : Rat) < (c : Rat) - e := by exact_mod_cast h
      rw [uc] at hc
      nlinarith
  have inside (h : lower ≤ c - e ∧ c + e ≤ upper) :
      (rounded < 250 || rounded > 800) = false := by
    have hl : (lower : Rat) ≤ (c : Rat) - e := by exact_mod_cast h.1
    have hu : (c : Rat) + e ≤ upper := by exact_mod_cast h.2
    rw [lc] at hl
    rw [uc] at hu
    have lo : 250 ≤ rounded := by nlinarith
    have hi : rounded ≤ 800 := by nlinarith
    simp [not_lt_of_ge lo, not_lt_of_ge hi]
  change (if c + e < lower || upper < c - e then true
    else if lower ≤ c - e && c + e ≤ upper then false
    else rounded < 250 || rounded > 800) = _
  split
  · rename_i h
    exact (outside (by simpa only [Bool.or_eq_true, decide_eq_true_eq] using h)).symm
  · split
    · rename_i h
      exact (inside (by simpa only [Bool.and_eq_true, decide_eq_true_eq] using h)).symm
    · rfl

/-- Values strictly inside the interval take the definite inside branch. -/
theorem inside_witness : Impl.cbRatioOutside250800 500 = false := by
  decide +kernel

/-- Values on either far side, including negative ratios, are outside. -/
theorem outside_witness :
    Impl.cbRatioOutside250800 0 = true ∧
    Impl.cbRatioOutside250800 (-1) = true ∧
    Impl.cbRatioOutside250800 1000 = true := by
  decide +kernel

/-- Exact thresholds preserve the inclusive interval through the fallback. -/
theorem thresholds_witness :
    Impl.cbRatioOutside250800 250 = false ∧
    Impl.cbRatioOutside250800 800 = false := by
  decide +kernel

/-- Exact rationals just outside either edge round back onto that edge.
Replacing the rounded predicate by a bare rational comparison would be wrong. -/
theorem roundback_witness :
    (250 - 1 / (2 : Rat)^50) < 250 ∧
    800 < (800 + 1 / (2 : Rat)^50) ∧
    Impl.Binary64.round (250 - 1 / (2 : Rat)^50) = 250 ∧
    Impl.Binary64.round (800 + 1 / (2 : Rat)^50) = 800 ∧
    Impl.cbRatioOutside250800 (250 - 1 / (2 : Rat)^50) = false ∧
    Impl.cbRatioOutside250800 (800 + 1 / (2 : Rat)^50) = false := by
  decide +kernel

/-- Larger neighboring offsets remain outside after rounding. -/
theorem outside_neighbors_witness :
    Impl.cbRatioOutside250800 (250 - 1 / (2 : Rat)^40) = true ∧
    Impl.cbRatioOutside250800 (800 + 1 / (2 : Rat)^40) = true := by
  decide +kernel

/-- Both exact boundaries and both round-back examples actually enter the
uncertain branch: neither integer shortcut decides these four inputs. -/
theorem fallback_branches_witness :
    ([250, 800, 250 - 1 / (2 : Rat)^50, 800 + 1 / (2 : Rat)^50] : List Rat).all
      (fun q =>
        let d : Int := q.den
        let k : Int := 2251799813685248
        let e : Int := (q.num.natAbs : Int) + d
        let c := k * q.num
        let lower := 250 * k * d
        let upper := 800 * k * d
        !(c + e < lower || upper < c - e) &&
          !(lower ≤ c - e && c + e ≤ upper)) = true := by
  decide +kernel

#print axioms cbRatioOutside250800_eq
#print axioms inside_witness
#print axioms outside_witness
#print axioms thresholds_witness
#print axioms roundback_witness
#print axioms outside_neighbors_witness
#print axioms fallback_branches_witness

end Lean1090.Proofs.CommBRatio

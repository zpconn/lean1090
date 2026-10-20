import Impl.ScoreGate
import Proofs.Binary64Bounds
import Mathlib.Data.Rat.Lemmas
import Mathlib.Algebra.BigOperators.Group.List.Lemmas

/-! Exact integer cross multiplication for the unchanged rational enclosure.
No density-list length, dyadic-denominator or fallback-result assumption is used.
-/
namespace Lean1090.Proofs.ScoreGateInteger
open Impl.ScoreGate

private theorem fold_max_ge (values : List Nat) (initial : Nat) :
    initial ≤ values.foldl max initial := by
  induction values generalizing initial with
  | nil => simp
  | cons value rest ih =>
    exact le_trans (Nat.le_max_left _ _) (ih (max initial value))

private theorem product_pos (values : List Nat)
    (positive : ∀ value ∈ values, 0 < value) : 0 < values.prod := by
  induction values with
  | nil => simp
  | cons value rest ih =>
    simp only [List.prod_cons]
    exact Nat.mul_pos (positive value (by simp))
      (ih (fun v member => positive v (by simp [member])))

/-- The selected denominator is positive for every rational input list. -/
theorem commonDenominator_pos (terms : List Rat) (penalty : Rat) :
    0 < commonDenominator terms penalty := by
  unfold commonDenominator
  dsimp only
  split
  · exact lt_of_lt_of_le (by decide : 0 < 1) (fold_max_ge _ 1)
  · apply product_pos
    intro value member
    simp only [List.mem_cons, List.mem_map] at member
    rcases member with rfl | ⟨q, _, rfl⟩
    · exact penalty.den_pos
    · exact q.den_pos

/-- Every original denominator divides the selected common denominator,
including the exact product fallback for non-dyadic inputs. -/
theorem denominator_dvd (terms : List Rat) (penalty : Rat) (d : Nat)
    (member : d ∈ penalty.den :: terms.map Rat.den) :
    d ∣ commonDenominator terms penalty := by
  unfold commonDenominator
  dsimp only
  split
  · rename_i common
    have remainder := (List.all_eq_true.mp common) d member
    exact Nat.dvd_of_mod_eq_zero (by simpa using remainder)
  · exact List.dvd_prod member

/-- The identity arm preserves the original formula for every denominator and
rational, including zero and non-divisible denominators. -/
theorem scaledNumerator_eq_old (denominator : Nat) (value : Rat) :
    scaledNumerator denominator value = value.num * (denominator / value.den : Nat) := by
  by_cases same : denominator = value.den
  · subst denominator
    simp [scaledNumerator, Nat.div_self value.den_pos]
  · simp [scaledNumerator, same]

/-- Function equality permits unchanged higher-order uses of numerator scaling. -/
theorem scaledNumerator_function_eq :
    scaledNumerator = fun (denominator : Nat) (value : Rat) =>
      value.num * (denominator / value.den : Nat) := by
  funext denominator value
  exact scaledNumerator_eq_old denominator value

/-- Exact scaling of a numerator at any divisible common denominator. -/
theorem scaledNumerator_cast (denominator : Nat) (value : Rat)
    (divides : value.den ∣ denominator) :
    (scaledNumerator denominator value : Rat) = denominator * value := by
  rw [scaledNumerator_eq_old]
  simp only [Int.cast_mul, Int.cast_natCast]
  rw [Rat.natCast_div _ _ divides]
  calc
    (value.num : Rat) * (denominator / value.den) =
        denominator * ((value.num : Rat) / value.den) := by ring
    _ = denominator * value := by rw [Rat.num_div_den]

private theorem scaled_abs_cast (denominator : Nat) (value : Rat)
    (divides : value.den ∣ denominator) :
    ((scaledNumerator denominator value).natAbs : Rat) =
      denominator * value.abs := by
  rw [Nat.cast_natAbs, Int.cast_abs, scaledNumerator_cast denominator value divides,
    abs_mul, abs_of_nonneg (Nat.cast_nonneg _), Binary64Facts.rat_abs_eq_abs]

private theorem totals_fold (denominator : Nat) (terms : List Rat) (initial : Int × Int) :
    terms.foldl (fun totals value =>
      let numerator := scaledNumerator denominator value
      (totals.1 + numerator, totals.2 + (numerator.natAbs : Int))) initial =
      (initial.1 + (terms.map (scaledNumerator denominator)).sum,
       initial.2 + (terms.map (fun value =>
         ((scaledNumerator denominator value).natAbs : Int))).sum) := by
  induction terms generalizing initial with
  | nil => simp
  | cons value rest ih =>
    simp only [List.foldl_cons, List.map_cons, List.sum_cons, ih]
    simp only [Int.add_assoc]

private theorem sum_scaled_cast (denominator : Nat) (terms : List Rat)
    (divides : ∀ value ∈ terms, value.den ∣ denominator) :
    ((terms.map (scaledNumerator denominator)).sum : Rat) = denominator * terms.sum := by
  induction terms with
  | nil => simp
  | cons value rest ih =>
    simp only [List.map_cons, List.sum_cons, Int.cast_add]
    rw [scaledNumerator_cast denominator value (divides value (by simp)),
      ih (fun v member => divides v (by simp [member]))]
    ring

private theorem mass_scaled_cast (denominator : Nat) (terms : List Rat)
    (divides : ∀ value ∈ terms, value.den ∣ denominator) :
    ((terms.map (fun value => ((scaledNumerator denominator value).natAbs : Int))).sum : Rat) =
      denominator * mass terms := by
  induction terms with
  | nil => simp [mass]
  | cons value rest ih =>
    simp only [List.map_cons, List.sum_cons, Int.cast_add, Int.cast_natCast]
    rw [scaled_abs_cast denominator value (divides value (by simp)),
      ih (fun v member => divides v (by simp [member]))]
    simp only [mass, List.map_cons, List.sum_cons]
    ring

/-- Both integer accumulators represent their original exact rational sums. -/
theorem scaledTotals_cast (denominator : Nat) (terms : List Rat)
    (divides : ∀ value ∈ terms, value.den ∣ denominator) :
    ((scaledTotals denominator terms).1 : Rat) = denominator * terms.sum ∧
    ((scaledTotals denominator terms).2 : Rat) = denominator * mass terms := by
  simp only [scaledTotals, totals_fold, zero_add]
  exact ⟨sum_scaled_cast denominator terms divides, mass_scaled_cast denominator terms divides⟩

private theorem center_clear (terms : List Rat) (penalty : Rat) :
    (max terms.length 1 : Nat) * center terms penalty =
      terms.sum + (max terms.length 1 : Nat) * penalty := by
  cases terms with
  | nil => simp [center]
  | cons value rest =>
    have positive : 0 < rest.length + 1 := by omega
    have nonzero : ((rest.length + 1 : Nat) : Rat) ≠ 0 := by exact_mod_cast (Nat.ne_of_gt positive)
    simp only [List.length_cons, Nat.max_eq_left (by omega : 1 ≤ rest.length + 1),
      center, List.isEmpty_cons, Bool.false_eq_true, ite_false, List.sum_cons]
    field_simp

/-- The integer gate is exactly the original rational enclosure decision for
all lists, penalties and fallback functions. In particular, this equivalence
requires no bound on the list length and no binary64/dyadic input assumption. -/
theorem choose_eq_old (terms : List Rat) (penalty : Rat) (fallback : Unit → Bool) :
    choose terms penalty fallback =
      (if center terms penalty - envelope terms penalty ≥ -3 then true
       else if center terms penalty + envelope terms penalty < -3 then false
       else fallback ()) := by
  let d := commonDenominator terms penalty
  let totals := scaledTotals d terms
  let p := scaledNumerator d penalty
  let n : Int := (max terms.length 1 : Nat)
  let c := totals.1 + n * p
  let e := totals.2 + (p.natAbs : Int) + d
  let k : Int := 1099511627776
  let threshold : Int := -3 * n * d * k
  have dPositive : 0 < d := commonDenominator_pos terms penalty
  have dPositiveRat : (0 : Rat) < d := by exact_mod_cast dPositive
  have nPositive : 0 < n := by
    dsimp only [n]
    exact_mod_cast (lt_of_lt_of_le (by decide : 0 < 1) (Nat.le_max_right terms.length 1))
  have nPositiveRat : (0 : Rat) < n := by exact_mod_cast nPositive
  have kPositiveRat : (0 : Rat) < k := by norm_num [k]
  have factorPositive : (0 : Rat) < (n : Rat) * d * k :=
    mul_pos (mul_pos nPositiveRat dPositiveRat) kPositiveRat
  have divisibility (q : Rat) (member : q ∈ terms) : q.den ∣ d :=
    denominator_dvd terms penalty q.den (List.mem_cons_of_mem _ (List.mem_map.mpr ⟨q, member, rfl⟩))
  have penaltyDivides : penalty.den ∣ d := denominator_dvd terms penalty penalty.den (by simp)
  have sums := scaledTotals_cast d terms divisibility
  have penaltyScaled : (p : Rat) = d * penalty := scaledNumerator_cast d penalty penaltyDivides
  have penaltyMass : (p.natAbs : Rat) = d * penalty.abs := scaled_abs_cast d penalty penaltyDivides
  have cCast : (c : Rat) = (n : Rat) * d * center terms penalty := by
    dsimp only [c]
    rw [Int.cast_add, Int.cast_mul, sums.1, penaltyScaled]
    have cleared := center_clear terms penalty
    change (n : Rat) * center terms penalty = terms.sum + (n : Rat) * penalty at cleared
    calc
      (d : Rat) * terms.sum + n * ((d : Rat) * penalty) =
          (d : Rat) * (terms.sum + n * penalty) := by ring
      _ = (d : Rat) * ((n : Rat) * center terms penalty) := by rw [cleared]
      _ = (n : Rat) * d * center terms penalty := by ring
  have eCast : (e : Rat) = (d : Rat) * k * envelope terms penalty := by
    dsimp only [e]
    rw [Int.cast_add, Int.cast_add, Int.cast_natCast, Int.cast_natCast, sums.2, penaltyMass]
    simp only [envelope]
    norm_num [k]
    ring
  have lowerCast : ((k * c - n * e : Int) : Rat) =
      (n : Rat) * d * k * (center terms penalty - envelope terms penalty) := by
    push_cast
    rw [cCast, eCast]
    ring
  have upperCast : ((k * c + n * e : Int) : Rat) =
      (n : Rat) * d * k * (center terms penalty + envelope terms penalty) := by
    push_cast
    rw [cCast, eCast]
    ring
  have thresholdCast : (threshold : Rat) = (n : Rat) * d * k * (-3) := by
    dsimp only [threshold]
    push_cast
    ring
  have accept : k * c - n * e ≥ threshold ↔ center terms penalty - envelope terms penalty ≥ -3 := by
    change threshold ≤ k * c - n * e ↔ -3 ≤ center terms penalty - envelope terms penalty
    rw [← Int.cast_le (R := Rat), lowerCast, thresholdCast]
    exact mul_le_mul_iff_right₀ factorPositive
  have reject : k * c + n * e < threshold ↔ center terms penalty + envelope terms penalty < -3 := by
    rw [← Int.cast_lt (R := Rat), upperCast, thresholdCast]
    exact mul_lt_mul_iff_right₀ factorPositive
  change (if k * c - n * e ≥ threshold then true
    else if k * c + n * e < threshold then false else fallback ()) = _
  simp only [accept, reject]

/-- Acceptance is inhabited independently of a false fallback. -/
theorem accept_witness : choose [0] 0 (fun _ => false) = true := by decide +kernel

/-- Rejection is inhabited independently of a true fallback. -/
theorem reject_witness : choose [0] (-4) (fun _ => true) = false := by decide +kernel

/-- At the exact -3 boundary either supplied fallback result is preserved. -/
theorem fallback_witness (value : Bool) : choose [0] (-3) (fun _ => value) = value := by
  cases value <;> decide +kernel

/-- Empty input has zero mean, with an arbitrary non-integral penalty. -/
theorem empty_witness : choose [] (1 / 3) (fun _ => false) = true := by decide +kernel

/-- The maximum-denominator branch covers dyadic terms and penalties. -/
theorem dyadic_denominator_witness : commonDenominator [1 / 2, 1 / 4] (1 / 8) = 8 := by
  decide +kernel

/-- Pairwise coprime non-dyadic denominators exercise the exact product fallback. -/
theorem product_denominator_witness : commonDenominator [1 / 3, 1 / 5] (1 / 7) = 105 := by
  decide +kernel

/-- The product-denominator decision also runs through the live gate. -/
theorem product_decision_witness : choose [1 / 3, 1 / 5] (1 / 7) (fun _ => false) = true := by
  decide +kernel

/-- Equal positive dyadic denominator takes the identity arm. -/
theorem equal_denominator_witness : scaledNumerator 8 (13 / 8) = 13 := by
  decide +kernel

/-- Unequal divisible denominator retains the original scaling formula. -/
theorem unequal_denominator_witness : scaledNumerator 24 (13 / 8) = 39 := by
  decide +kernel

/-- Zero denominator remains a valid arbitrary input to the original formula. -/
theorem zero_denominator_witness : scaledNumerator 0 (5 / 7) = 0 := by
  decide +kernel

/-- Negative numerators preserve their sign in both branches. -/
theorem negative_numerator_witness :
    scaledNumerator 8 (-13 / 8) = -13 ∧ scaledNumerator 24 (-13 / 8) = -39 := by
  decide +kernel

/-- Non-dyadic denominators are included in the identity arm without restriction. -/
theorem non_dyadic_equal_witness : scaledNumerator 7 (10 / 7) = 10 := by
  decide +kernel

/-- A non-divisible denominator keeps natural division, including truncation. -/
theorem non_divisible_denominator_witness : scaledNumerator 19 (10 / 7) = 20 := by
  decide +kernel

#print axioms scaledNumerator_eq_old
#print axioms scaledNumerator_function_eq
#print axioms equal_denominator_witness
#print axioms unequal_denominator_witness
#print axioms zero_denominator_witness
#print axioms negative_numerator_witness
#print axioms non_dyadic_equal_witness
#print axioms non_divisible_denominator_witness
#print axioms commonDenominator_pos
#print axioms denominator_dvd
#print axioms scaledNumerator_cast
#print axioms scaledTotals_cast
#print axioms choose_eq_old
#print axioms accept_witness
#print axioms reject_witness
#print axioms fallback_witness
#print axioms empty_witness
#print axioms dyadic_denominator_witness
#print axioms product_denominator_witness
#print axioms product_decision_witness

end Lean1090.Proofs.ScoreGateInteger

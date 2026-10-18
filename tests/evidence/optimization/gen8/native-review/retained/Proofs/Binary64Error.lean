import Proofs.Binary64Bounds

/-! Preparatory, general software-binary64 error bounds. No runtime change. -/
namespace Lean1090.Proofs.Binary64Error
open Spec Binary64Facts

theorem nearestEven_error (n d : Nat) (positive : 0 < d) :
    |(Binary64.nearestEven n d : Rat) - (n : Rat) / d| ≤ 1/2 := by
  have dPositive : (0 : Rat) < d := by exact_mod_cast positive
  have remainder : n % d < d := Nat.mod_lt n positive
  have remainderNonneg : (0 : Rat) ≤ n % d := by positivity
  have decomposition : (n : Rat) = (d : Rat) * (n / d : Nat) + (n % d : Nat) := by
    exact_mod_cast (Nat.div_add_mod n d).symm
  have ratio : (n : Rat) / d = (n / d : Nat) + (n % d : Nat) / (d : Rat) := by
    apply (div_eq_iff (ne_of_gt dPositive)).mpr
    field_simp
    nlinarith [decomposition]
  rw [ratio]
  dsimp only [Binary64.nearestEven]
  split
  · rename_i up
    have half : d ≤ 2 * (n % d) := by
      simp only [Bool.or_eq_true, decide_eq_true_eq, Bool.and_eq_true, beq_iff_eq] at up
      omega
    have halfRat : (d : Rat) ≤ 2 * (n % d : Nat) := by exact_mod_cast half
    have remainderRat : (n % d : Nat) < (d : Rat) := by exact_mod_cast remainder
    have lower : (1/2 : Rat) ≤ (n % d : Nat) / (d : Rat) := by
      apply (le_div_iff₀ dPositive).mpr
      linarith
    have upper : (n % d : Nat) / (d : Rat) ≤ 1 := by
      apply (div_le_iff₀ dPositive).mpr
      linarith
    push_cast
    rw [abs_le]
    constructor <;> linarith
  · rename_i down
    have half : 2 * (n % d) ≤ d := by
      simp only [Bool.or_eq_true, decide_eq_true_eq, Bool.and_eq_true, beq_iff_eq] at down
      omega
    have halfRat : 2 * (n % d : Nat) ≤ (d : Rat) := by exact_mod_cast half
    have upper : (n % d : Nat) / (d : Rat) ≤ (1/2 : Rat) := by
      apply (div_le_iff₀ dPositive).mpr
      linarith
    have lower : (0 : Rat) ≤ (n % d : Nat) / (d : Rat) := div_nonneg remainderNonneg dPositive.le
    rw [abs_le]
    constructor <;> linarith

#print axioms nearestEven_error

theorem round_error_quantum (value : Rat) :
    |Binary64.round value - value| ≤
      Binary64.powerTwo (max (-1074) (Binary64.exponent value - 52)) / 2 := by
  by_cases zero : value = 0
  · have qPositive := powerTwo_pos (max (-1074) (Binary64.exponent value - 52))
    simpa [zero, Binary64.round] using (div_nonneg qPositive.le (by norm_num : (0 : Rat) ≤ 2))
  · let q := Binary64.powerTwo (max (-1074) (Binary64.exponent value - 52))
    have qPositive : 0 < q := powerTwo_pos _
    let scaled := value.abs / q
    have scaledNonneg : 0 ≤ scaled := div_nonneg Rat.abs_nonneg qPositive.le
    let nearest : Rat := Binary64.nearestEven scaled.num.natAbs scaled.den
    let rounded := nearest * q
    have nearestBound := nearestEven_error scaled.num.natAbs scaled.den scaled.den_pos
    rw [abs_num_den, Rat.abs_of_nonneg scaledNonneg] at nearestBound
    change |nearest - scaled| ≤ 1/2 at nearestBound
    have scaledError : |rounded - value.abs| ≤ q/2 := by
      calc
        _ = |(nearest - scaled) * q| := by
          congr 1
          dsimp [rounded, scaled]
          field_simp
        _ = |nearest - scaled| * q := by rw [abs_mul, abs_of_pos qPositive]
        _ ≤ (1/2) * q := mul_le_mul_of_nonneg_right nearestBound qPositive.le
        _ = q/2 := by ring
    unfold Binary64.round
    simp only [beq_iff_eq, zero, ↓reduceIte]
    change |(if value < 0 then -rounded else rounded) - value| ≤ q/2
    by_cases negative : value < 0
    · rw [ite_eq_left negative]
      have same : -rounded - value = -(rounded - value.abs) := by
        rw [Rat.abs_of_nonpos negative.le]
        ring
      rw [same, abs_neg]
      exact scaledError
    · rw [ite_eq_right negative]
      simpa only [Rat.abs_of_nonneg (le_of_not_gt negative)] using scaledError

#print axioms round_error_quantum

theorem powerTwo_sub_nat (e : Int) (n : Nat) :
    Binary64.powerTwo (e - (n : Int)) = Binary64.powerTwo e / (2 : Rat)^n := by
  simp only [powerTwo_eq_zpow, zpow_sub₀ (by decide : (2 : Rat) ≠ 0), zpow_natCast]

theorem quantum_relative_bound (value : Rat) (nonzero : value ≠ 0) :
    Binary64.powerTwo (max (-1074) (Binary64.exponent value - 52)) ≤
      2 * value.abs / (2 : Rat)^52 + Binary64.powerTwo (-1074) := by
  let candidate := (value.num.natAbs.log2 : Int) - (value.den.log2 : Int)
  have exponentBound : Binary64.exponent value ≤ candidate := by
    dsimp only [Binary64.exponent, candidate]
    split <;> omega
  have ordinary : Binary64.powerTwo (Binary64.exponent value - 52) ≤
      2 * value.abs / (2 : Rat)^52 := by
    calc
      _ = Binary64.powerTwo (Binary64.exponent value) / (2 : Rat)^52 := powerTwo_sub_nat _ 52
      _ ≤ Binary64.powerTwo candidate / (2 : Rat)^52 :=
        div_le_div_of_nonneg_right (powerTwo_mono exponentBound) (by positivity)
      _ ≤ 2 * value.abs / (2 : Rat)^52 :=
        div_le_div_of_nonneg_right (candidate_le_twice_abs value nonzero) (by positivity)
  by_cases normal : -1074 ≤ Binary64.exponent value - 52
  · rw [max_eq_right normal]
    have positive := powerTwo_pos (-1074)
    linarith
  · rw [max_eq_left (le_of_not_ge normal)]
    have positive : 0 ≤ 2 * value.abs / (2 : Rat)^52 :=
      div_nonneg (mul_nonneg (by norm_num) Rat.abs_nonneg) (by positivity)
    linarith

theorem round_error_relative (value : Rat) :
    |Binary64.round value - value| ≤
      value.abs / (2 : Rat)^52 + Binary64.powerTwo (-1075) := by
  by_cases zero : value = 0
  · simpa [zero, Binary64.round] using (powerTwo_pos (-1075)).le
  · have bound := quantum_relative_bound value zero
    have half := div_le_div_of_nonneg_right bound (by norm_num : (0 : Rat) ≤ 2)
    have subnormal : Binary64.powerTwo (-1075) = Binary64.powerTwo (-1074) / 2 := by
      simpa only [Int.natCast_one, Int.reduceSub, pow_one] using powerTwo_sub_nat (-1074) 1
    calc
      _ ≤ Binary64.powerTwo (max (-1074) (Binary64.exponent value - 52)) / 2 :=
        round_error_quantum value
      _ ≤ (2 * value.abs / (2 : Rat)^52 + Binary64.powerTwo (-1074)) / 2 := half
      _ = value.abs / (2 : Rat)^52 + Binary64.powerTwo (-1075) := by
        rw [subnormal]
        ring

#print axioms powerTwo_sub_nat
#print axioms quantum_relative_bound
#print axioms round_error_relative

def mass (terms : List Rat) : Rat := (terms.map (fun x => |x|)).sum

theorem mass_nonneg (terms : List Rat) : 0 ≤ mass terms := by
  induction terms with
  | nil => simp [mass]
  | cons term terms ih => simpa [mass] using add_nonneg (abs_nonneg term) ih

theorem abs_sum_le_mass (terms : List Rat) : |terms.sum| ≤ mass terms := by
  induction terms with
  | nil => simp [mass]
  | cons term terms ih =>
    simpa only [List.sum_cons, mass, List.map_cons, List.sum_cons] using
      (abs_add_le term terms.sum).trans (add_le_add (le_refl |term|) ih)

theorem round_error_of_bound (value bound : Rat) (one : 1 ≤ bound)
    (bounded : |value| ≤ bound) :
    |Binary64.round value - value| ≤ 2 * bound / (2 : Rat)^52 := by
  have subnormal : Binary64.powerTwo (-1075) ≤ (1 : Rat) / (2 : Rat)^52 := by
    have h := powerTwo_mono (show (-1075 : Int) ≤ -52 by decide)
    have shifted : Binary64.powerTwo (-52) = (1 : Rat) / 2^52 := by
      rw [powerTwo_eq_zpow]
      norm_num
    simpa only [shifted] using h
  have main := round_error_relative value
  rw [rat_abs_eq_abs] at main
  have a := div_le_div_of_nonneg_right bounded (by positivity : (0 : Rat) ≤ 2^52)
  have b := div_le_div_of_nonneg_right one (by positivity : (0 : Rat) ≤ 2^52)
  linarith

theorem fold_error (terms : List Rat) (initial : Rat) :
    |terms.foldl Binary64.add initial - (initial + terms.sum)| ≤
      ((4 : Rat)^terms.length - 1) * (|initial| + mass terms + 1) / (2 : Rat)^52 := by
  induction terms generalizing initial with
  | nil => simp
  | cons term terms ih =>
    let bound := |initial| + mass (term :: terms) + 1
    let next := Binary64.add initial term
    have massTail := mass_nonneg terms
    have initialNonneg := abs_nonneg initial
    have termNonneg := abs_nonneg term
    have boundExpand : bound = |initial| + |term| + mass terms + 1 := by simp [bound, mass]; ring
    have one : 1 ≤ bound := by rw [boundExpand]; linarith
    have inputBound : |initial + term| ≤ bound := by
      have triangle := abs_add_le initial term
      rw [boundExpand]
      linarith
    have localError : |next - (initial + term)| ≤ 2 * bound / (2 : Rat)^52 :=
      round_error_of_bound (initial + term) bound one inputBound
    have nextBound : |next| ≤ 3 * (|initial| + |term|) + 1 := by
      have rounded := round_bound (initial + term)
      simp only [rat_abs_eq_abs] at rounded
      have triangle := abs_add_le initial term
      change |Binary64.round (initial + term)| ≤ _
      linarith
    have nextMass : |next| + mass terms + 1 ≤ 4 * bound := by
      rw [boundExpand]
      linarith
    have inductionBound := ih next
    have factorNonnegative : 0 ≤ (4 : Rat)^terms.length - 1 := by
      have h := one_le_pow₀ (by norm_num : (1 : Rat) ≤ 4) (n := terms.length)
      linarith
    have enlarged := div_le_div_of_nonneg_right
      (mul_le_mul_of_nonneg_left nextMass factorNonnegative)
      (by positivity : (0 : Rat) ≤ 2^52)
    have combined := add_le_add (inductionBound.trans enlarged) localError
    have triangle := abs_add_le
      (terms.foldl Binary64.add next - (next + terms.sum)) (next - (initial + term))
    have identity : terms.foldl Binary64.add next - (initial + (term + terms.sum)) =
        (terms.foldl Binary64.add next - (next + terms.sum)) + (next - (initial + term)) := by ring
    simp only [List.foldl_cons, List.sum_cons, List.length_cons]
    rw [pow_succ]
    change |terms.foldl Binary64.add next - (initial + (term + terms.sum))| ≤ _
    rw [identity]
    have estimate := triangle.trans combined
    change |terms.foldl Binary64.add next - (next + terms.sum) + (next - (initial + term))| ≤
      ((4 : Rat)^terms.length * 4 - 1) * bound / (2 : Rat)^52
    nlinarith

#print axioms round_error_of_bound
#print axioms fold_error

def densityReference (terms : List Rat) : Rat :=
  if terms.isEmpty then 0
  else Binary64.div (terms.foldl Binary64.add 0) (terms.length : Rat)

def densityCenter (terms : List Rat) : Rat :=
  if terms.isEmpty then 0 else terms.sum / (terms.length : Rat)

theorem density_error_and_bound (terms : List Rat) (bound : Rat)
    (short : terms.length ≤ 4) (large : mass terms + 1 ≤ bound) :
    |densityReference terms - densityCenter terms| ≤ 259 * bound / (2 : Rat)^52 ∧
      |densityReference terms| ≤ 7 * bound := by
  have nonnegative := mass_nonneg terms
  have one : 1 ≤ bound := by linarith
  by_cases empty : terms.isEmpty = true
  · simp only [densityReference, densityCenter, empty, ↓reduceIte, sub_self, abs_zero]
    constructor <;> positivity
  · have count : (1 : Rat) ≤ terms.length := by
      have nonempty : terms ≠ [] := by intro h; simp [h] at empty
      exact_mod_cast List.length_pos_iff.mpr nonempty
    have countPositive : (0 : Rat) < terms.length := by linarith
    let total := terms.foldl Binary64.add 0
    have totalError : |total - terms.sum| ≤ 255 * bound / (2 : Rat)^52 := by
      have basic := fold_error terms 0
      simp only [abs_zero, zero_add] at basic
      have powerBound : (4 : Rat)^terms.length ≤ 256 := by
        have h := pow_le_pow_right₀ (by norm_num : (1 : Rat) ≤ 4) short
        norm_num at h
        exact h
      have powerLow : (1 : Rat) ≤ 4^terms.length := one_le_pow₀ (by norm_num)
      have productBound : ((4 : Rat)^terms.length - 1) * (mass terms + 1) ≤ 255 * bound :=
        mul_le_mul (by linarith) large (by linarith) (by norm_num)
      exact basic.trans (div_le_div_of_nonneg_right productBound (by positivity))
    have totalBound : |total| ≤ 2 * bound := by
      have triangle := abs_add_le (total - terms.sum) terms.sum
      have sumBound := abs_sum_le_mass terms
      have identity : total - terms.sum + terms.sum = total := by ring
      rw [identity] at triangle
      norm_num at totalError
      linarith
    let exactMean := total / (terms.length : Rat)
    have meanBound : |exactMean| ≤ 2 * bound := by
      change |total / (terms.length : Rat)| ≤ _
      rw [abs_div, abs_of_pos countPositive]
      apply (div_le_iff₀ countPositive).mpr
      nlinarith
    have meanError : |exactMean - terms.sum / (terms.length : Rat)| ≤
        255 * bound / (2 : Rat)^52 := by
      have identity : exactMean - terms.sum / (terms.length : Rat) =
          (total - terms.sum) / (terms.length : Rat) := by dsimp [exactMean]; ring
      rw [identity, abs_div, abs_of_pos countPositive]
      apply (div_le_iff₀ countPositive).mpr
      have nonnegativeError : 0 ≤ 255 * bound / (2 : Rat)^52 := by positivity
      nlinarith
    have roundError : |Binary64.round exactMean - exactMean| ≤ 4 * bound / (2 : Rat)^52 := by
      have h := round_error_of_bound exactMean (2 * bound) (by linarith) meanBound
      convert h using 1
      ring
    have densityBound : |Binary64.round exactMean| ≤ 7 * bound := by
      have h := round_bound exactMean
      simp only [rat_abs_eq_abs] at h
      linarith
    simp only [densityReference, densityCenter, empty, Binary64.div]
    change |Binary64.round exactMean - terms.sum / (terms.length : Rat)| ≤ _ ∧
      |Binary64.round exactMean| ≤ _
    refine ⟨?_, densityBound⟩
    have triangle := abs_add_le (Binary64.round exactMean - exactMean)
      (exactMean - terms.sum / (terms.length : Rat))
    have identity : Binary64.round exactMean - exactMean +
        (exactMean - terms.sum / (terms.length : Rat)) =
        Binary64.round exactMean - terms.sum / (terms.length : Rat) := by ring
    rw [identity] at triangle
    linarith

def scoreReference (terms : List Rat) (penalty : Rat) : Rat :=
  Binary64.add (densityReference terms) penalty

def scoreCenter (terms : List Rat) (penalty : Rat) : Rat := densityCenter terms + penalty

def scoreEnvelope (terms : List Rat) (penalty : Rat) : Rat :=
  (mass terms + |penalty| + 1) / (2 : Rat)^40

theorem score_error (terms : List Rat) (penalty : Rat) (short : terms.length ≤ 4) :
    |scoreReference terms penalty - scoreCenter terms penalty| ≤ scoreEnvelope terms penalty := by
  let bound := mass terms + |penalty| + 1
  have massNonnegative := mass_nonneg terms
  have penaltyNonnegative := abs_nonneg penalty
  have one : 1 ≤ bound := by dsimp [bound]; linarith
  have large : mass terms + 1 ≤ bound := by dsimp [bound]; linarith
  have penaltyBound : |penalty| ≤ bound := by dsimp [bound]; linarith
  obtain ⟨densityError, densityBound⟩ := density_error_and_bound terms bound short large
  have inputBound : |densityReference terms + penalty| ≤ 8 * bound :=
    (abs_add_le _ _).trans (by linarith)
  have finalError : |scoreReference terms penalty - (densityReference terms + penalty)| ≤
      16 * bound / (2 : Rat)^52 := by
    have h := round_error_of_bound (densityReference terms + penalty) (8 * bound) (by linarith) inputBound
    change |Binary64.round (densityReference terms + penalty) - _| ≤ _
    convert h using 1
    ring
  have triangle := abs_add_le
    (scoreReference terms penalty - (densityReference terms + penalty))
    (densityReference terms - densityCenter terms)
  have identity : scoreReference terms penalty - (densityReference terms + penalty) +
      (densityReference terms - densityCenter terms) =
      scoreReference terms penalty - scoreCenter terms penalty := by unfold scoreCenter; ring
  rw [identity] at triangle
  change |scoreReference terms penalty - scoreCenter terms penalty| ≤ bound / (2 : Rat)^40
  norm_num at densityError finalError ⊢
  linarith

#print axioms density_error_and_bound
#print axioms score_error

def sandwichGate (reference center error : Rat) : Bool :=
  if center - error ≥ -3 then true
  else if center + error < -3 then false
  else reference ≥ -3

theorem sandwichGate_eq (reference center error : Rat)
    (enclosed : |reference - center| ≤ error) :
    sandwichGate reference center error = decide (reference ≥ -3) := by
  obtain ⟨lower, upper⟩ := abs_le.mp enclosed
  unfold sandwichGate
  split
  · rename_i accept
    have exactAccept : reference ≥ -3 := by linarith
    simp only [exactAccept, decide_true]
  · split
    · rename_i reject
      have exactReject : ¬ reference ≥ -3 := by linarith
      simp only [exactReject, decide_false]
    · rfl

def scoreGate (terms : List Rat) (penalty : Rat) : Bool :=
  let center := scoreCenter terms penalty
  let error := scoreEnvelope terms penalty
  if center - error ≥ -3 then true
  else if center + error < -3 then false
  else scoreReference terms penalty ≥ -3

theorem scoreGate_eq (terms : List Rat) (penalty : Rat) (short : terms.length ≤ 4) :
    scoreGate terms penalty = decide (scoreReference terms penalty ≥ -3) :=
  sandwichGate_eq _ _ _ (score_error terms penalty short)

theorem sandwichGate_at_threshold (center error : Rat)
    (enclosed : |(-3 : Rat) - center| ≤ error) :
    sandwichGate (-3) center error = true := by
  simpa using sandwichGate_eq (-3) center error enclosed

#print axioms sandwichGate_eq
#print axioms scoreGate_eq
#print axioms sandwichGate_at_threshold
end Lean1090.Proofs.Binary64Error

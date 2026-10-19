import Std

/-!
Exact rational enclosure for the software-binary64 Comm-B score decision.
For at most four already-rounded density terms, the proved error envelope
encloses the rounded accumulation, mean and final penalty addition. The
inclusive -3 decision uses that enclosure or the unchanged software model.
No floating-point arithmetic or external primitive is used here.
-/

namespace Lean1090.Impl.ScoreGate

/-- Sum of the absolute values of the already-rounded density terms. -/
def mass (terms : List Rat) : Rat := (terms.map Rat.abs).sum

/-- Exact mean of the density terms, or zero for an empty list, plus the
already-rounded penalty. This is the center of the enclosure, not a replacement
definition of the rounded software-binary64 score. -/
def center (terms : List Rat) (penalty : Rat) : Rat :=
  (if terms.isEmpty then 0 else terms.sum / (terms.length : Rat)) + penalty

/-- Conservative absolute error bound for at most four density terms. The
constant denominator is exactly 2^40. The proof covers arbitrary rationals. -/
def envelope (terms : List Rat) (penalty : Rat) : Rat :=
  (mass terms + penalty.abs + 1) / (2 : Rat)^40

/-- A positive common denominator for every term and the penalty. The maximum
is sufficient when all denominators divide it (including all dyadic inputs).
The product supplies an exact fallback for arbitrary rational inputs. -/
def commonDenominator (terms : List Rat) (penalty : Rat) : Nat :=
  let denominators := penalty.den :: terms.map Rat.den
  let largest := denominators.foldl max 1
  if denominators.all (fun d => largest % d == 0) then largest
  else denominators.prod

/-- Numerator at a known common denominator, without constructing a new Rat. -/
@[inline] def scaledNumerator (denominator : Nat) (value : Rat) : Int :=
  value.num * (denominator / value.den : Nat)

/-- Accumulate signed and absolute numerators together using integer arithmetic.
The denominator's divisibility is established by `commonDenominator`. -/
def scaledTotals (denominator : Nat) (terms : List Rat) : Int × Int :=
  terms.foldl (fun totals value =>
    let numerator := scaledNumerator denominator value
    (totals.1 + numerator, totals.2 + (numerator.natAbs : Int))) (0, 0)

/-- Decide the inclusive -3 threshold from the same exact enclosure using
integer cross multiplication at a positive common denominator. A caller must
pass the complete software score decision as a thunk: only the uncertain
branch invokes it. Keeping this boundary uninlined makes that lazy call
explicit in generated C as well as in the pure definition. -/
@[noinline] def choose (terms : List Rat) (penalty : Rat)
    (fallback : Unit → Bool) : Bool :=
  let denominator := commonDenominator terms penalty
  let totals := scaledTotals denominator terms
  let p := scaledNumerator denominator penalty
  let n : Int := (max terms.length 1 : Nat)
  let c := totals.1 + n * p
  let e := totals.2 + (p.natAbs : Int) + denominator
  let scaledCenter := 1099511627776 * c
  let scaledError := n * e
  let threshold := -3 * n * denominator * 1099511627776
  if scaledCenter - scaledError ≥ threshold then true
  else if scaledCenter + scaledError < threshold then false
  else fallback ()

end Lean1090.Impl.ScoreGate

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

/-- Decide the inclusive -3 threshold from the exact enclosure. A caller must
pass the complete software score decision as a thunk: only the uncertain
branch invokes it. Keeping this boundary uninlined makes that lazy call
explicit in generated C as well as in the pure definition. -/
@[noinline] def choose (terms : List Rat) (penalty : Rat)
    (fallback : Unit → Bool) : Bool :=
  let c := center terms penalty
  let e := envelope terms penalty
  if c - e ≥ -3 then true
  else if c + e < -3 then false
  else fallback ()

end Lean1090.Impl.ScoreGate

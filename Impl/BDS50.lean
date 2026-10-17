import Impl.Binary64
import Model.BDS50

/-! Shipping baseline for the complete BDS50 candidate path. This module imports
only Std through Impl.Binary64. Scores are exact, proof-visible binary64 values;
no opaque Float operation participates in the acceptance decision. The baseline
uses Rat and Nat deliberately; replacing them is a future refinement exercise. -/
namespace Lean1090.Impl.BDS50

@[inline] def bits (word start width : Nat) : Nat :=
  word / 2 ^ (56 - (start - 1 + width)) % 2 ^ width

@[inline] def signed (word start width : Nat) : Rat :=
  ((if bits word start width ≥ 2 ^ (width - 1) then
    (bits word start width : Int) - (2 ^ width : Nat) else bits word start width : Int) : Rat)

@[inline] def status (word flag start width : Nat) : Bool :=
  bits word flag 1 == 1 || bits word start width == 0

@[inline] def value (word flag start width : Nat) (isSigned : Bool) (scale : Rat) : Option Rat :=
  if flag != 0 && bits word flag 1 == 0 then none
  else some ((if isSigned then signed word start width else ((bits word start width : Int) : Rat)) * scale + 0)

def roll (word : Nat) : Option Rat := value word 1 2 10 true (45/256)
def track (word : Nat) : Option Rat := do
  let x ← value word 12 13 11 true (90/512)
  some (if x < 0 then x + 360 else x)
def groundSpeed (word : Nat) : Option Rat := value word 24 25 10 false 2
def rate (word : Nat) : Option Rat := do
  let x ← value word 35 36 10 true (8/256)
  if bits word 37 9 == 511 then none else some x
def trueAirspeed (word : Nat) : Option Rat := value word 46 47 10 false 2

/-- Complete rs1090 hard validity, including status consistency and all physical bounds. -/
def wireValid (word : Nat) : Bool :=
  word < 2^56 &&
  (status word 1 2 10 && status word 12 13 11 && status word 24 25 10 &&
   status word 35 36 10 && status word 46 47 10 &&
   (signed word 2 10 * 45 / 256).abs ≤ 45 &&
   bits word 25 10 * 2 ≤ 700 &&
   (bits word 46 1 == 0 || (bits word 47 10 * 2 ≥ 80 && bits word 47 10 * 2 ≤ 600)))

def gaussian (value mu sigma : Rat) : Rat :=
  let z := Binary64.div (Binary64.sub value (Binary64.literal mu)) (Binary64.literal sigma)
  Binary64.mul (Binary64.mul (-1/2) z) z

def laplace (value median scale : Rat) : Rat :=
  if scale ≤ 0 then 0 else
    Binary64.div (-(Binary64.sub value (Binary64.literal median)).abs) (Binary64.literal scale)

def scoreField (value : Option Rat) (score : Rat → Rat) : List Rat :=
  match value with | none => [] | some value => [score value]

def densityTerms (word : Nat) : List Rat :=
  scoreField (roll word) (fun x => laplace x 0 10) ++
  scoreField (rate word) (fun x => laplace x 0 (70/100)) ++
  scoreField (trueAirspeed word) (fun x => gaussian x 413 120) ++
  scoreField (groundSpeed word) (fun x => gaussian x 418 129)

def density (word : Nat) : Rat :=
  let terms := densityTerms word
  if terms.isEmpty then 0
  else Binary64.div (terms.foldl Binary64.add 0) (terms.length : Rat)

def penalty (word : Nat) : Rat :=
  let p := match trueAirspeed word, groundSpeed word with
    | some tas, some gs => Binary64.sub 0 (Binary64.div (Binary64.sub tas gs).abs 100)
    | _, _ => 0
  match roll word, rate word with
  | some roll, some rate =>
    if roll.abs > 5 && rate.abs > Binary64.literal (3/10) &&
      decide (roll > 0) != decide (rate > 0) then Binary64.sub p 2 else p
  | _, _ => p

def combinedScore (word : Nat) : Rat := Binary64.add (density word) (penalty word)

/-- Extraction into the final record, with no original input word retained. -/
def fields (word : Nat) : List (String × Nat) :=
  [("roll_valid", bits word 1 1), ("roll", bits word 2 10),
   ("track_valid", bits word 12 1), ("track", bits word 13 11),
   ("groundspeed_valid", bits word 24 1), ("groundspeed", bits word 25 10),
   ("track_rate_valid", bits word 35 1), ("track_rate", bits word 36 10),
   ("tas_valid", bits word 46 1), ("TAS", bits word 47 10)]

/-- The complete candidate function to be timed: empty-MB check, hard checks,
full binary64 score, inclusive -3 gate, field and semantic projections. -/
def decode (word : Nat) : Option Model.BDS50.Result :=
  if word == 0 || !wireValid word then none else
    let score := combinedScore word
    if score ≥ -3 then
      some ⟨fields word, roll word, track word, groundSpeed word,
        rate word, trueAirspeed word, score⟩
    else none

end Lean1090.Impl.BDS50

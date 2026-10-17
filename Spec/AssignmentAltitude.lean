import Model.Types

/-!
Independent meanings for encoder-side altitude field assignments. This module
uses a left-to-right bit fold, not the reference decoder's shift/XOR routines.
The source is Sun, The 1090 Megahertz Riddle, 2nd edition (2021), chapter13
“Altitude code” and §5.5.1–2. Compatibility exceptions are identified explicitly.
No declaration in this module calls an altitude decoder or receiver helper.
-/
namespace Lean1090.Spec.Assignment

/-- Sun, 2nd ed. (2021), ch.13 altitude bit permutation: concatenate the assigned
bits in the listed most-significant-first order. -/
def orderedBits (word : Nat) (positions : List Nat) : Nat :=
  positions.foldl (fun value i => 2*value + if word.testBit i then 1 else 0) 0

/-- Sun, 2nd ed. (2021), ch.13 Gray-code altitude equations: each binary bit
is the parity of the Gray prefix. This MSB-first construction is independent
of Altitude.grayDecode's XOR-of-shifted-words recurrence. -/
def grayValue (width gray : Nat) : Nat :=
  ((List.range width).foldl (fun (state : Bool × Nat) i =>
    let next := state.1 != gray.testBit (width-1-i)
    (next, 2*state.2 + if next then 1 else 0)) (false,0)).2

/-- Sun, 2nd ed. (2021), ch.13: assigned D2 D4 A1 A2 A4 B1 B2 B4 and
C1 C2 C4 Gray digits determine 500/100-foot counts. Invalid C patterns and
M/Q bits have no Gillham meaning. -/
def gillhamHeight (word : Nat) : Option Int :=
  let coarse := grayValue 8 (orderedBits word [2,0,11,9,7,5,3,1])
  let fine := grayValue 3 (orderedBits word [12,10,8])
  if word ≥ 8192 || word.testBit 6 || word.testBit 4 ||
      !( [1,2,3,4,7].contains fine ) then none else
    let fine := if fine == 7 then 5 else fine
    let fine := if coarse % 2 == 0 then fine else 6-fine
    some ((coarse : Int)*500 + (fine : Int)*100 - 1300)

/-- Sun, 2nd ed. (2021), ch.13: an assigned AC13 code denotes M=1 unsigned
metres, Q=1 binary25 feet, or Gillham100 feet; all-zero is unavailable. -/
def altitude13 (code : Nat) : Option Altitude.Value :=
  if code == 0 || code ≥ 8192 then none
  else if code.testBit 6 then
    some (.metres (orderedBits code [12,11,10,9,8,7,5,4,3,2,1,0]))
  else if code.testBit 4 then
    some (.feet ((orderedBits code [12,11,10,9,8,7,5,3,2,1,0] : Int)*25 - 1000))
  else (gillhamHeight code).map Altitude.Value.feet

/-- Sun, 2nd ed. (2021), §5.5.1: independently insert the omitted M=0 bit
when assigning an ADS-B barometric altitude code. -/
def altitude12 (code : Nat) : Option Int :=
  if code ≥ 4096 then none else
    let expanded := orderedBits code [11,10,9,8,7,6]*128 +
      orderedBits code [5,4,3,2,1,0]
    match altitude13 expanded with
    | some (.feet height) => some height
    | _ => none

/-- rs1090-derived AC13Field::read, pinned685dfaa: compatibility M conversion
uses overlapping bits and truncates to whole feet. Its M=1,Q=1 rejection is
not an assertion about the standard metric representation. The pinned
negative-Gillham rejection is separate from standard representability. -/
def compatibility13 (code : Nat) : Option Int :=
  if code == 0 || code ≥ 8192 then none else
    if code.testBit 6 then
      if code.testBit 4 then none else
        let metres := (orderedBits code [12,11,10,9,8,7]*32) |||
          orderedBits code [5,4,3,2,1,0]
        some ((metres*328084/100000 : Nat) : Int)
    else match altitude13 code with
      | some (.feet height) =>
          if !code.testBit 4 && height < 0 then none else some height
      | _ => none

/-- rs1090-derived bds05.rs, pinned685dfaa: the report's compatible altitude
is absent for invalid/unavailable codes and for heights above50000ft. Frame
acceptance is a separate predicate, not assumed by this assignment meaning.
Negative Gillham heights are missing; negative binary25 heights remain. -/
def compatibility12 (code : Nat) : Option Int :=
  (altitude12 code).filter (fun height => height ≤ 50000 && (code.testBit 4 || height ≥ 0))

/-- Sun ch.13 published38000ft example has the same literal meaning in the
independent field interpreter, including the distinct Gillham encoding. -/
theorem altitude_assignment_nonvacuous :
    altitude13 6200 = some (.feet 38000) ∧ altitude12 3128 = some 38000 ∧
    gillhamHeight 3203 = some 38000 := by decide +kernel

end Lean1090.Spec.Assignment

import Spec.Message

/-! Historical proposal, approved 2026-10-16 and applied as FC001.
The candidate regression below now expects the corrected reference result;
the pre-approval source is archived with the original proposal evidence.
Permanent gate coverage uses scripts/check_altitude_differential.py. -/

set_option maxRecDepth 100000
set_option maxHeartbeats 0

open Lean1090.Spec

namespace AltitudeCompatibilityProposal
open Altitude


def oracleAC13 (word : Nat) : Option Int :=
  if word ≥ 8192 || word == 0 then none
  else if bit word 6 == 1 then
    if bit word 4 == 1 then none
    else
      let metres := ((word &&& 0x1f80) / 4) ||| (word &&& 0x3f)
      some ((metres * 328084 / 100000 : Nat) : Int)
  else
    match decodeAC13 word with
    | some (.feet height) =>
        if bit word 4 == 0 && height < 0 then none else some height
    | _ => none

def oracleAC12 (word : Nat) : Option (Option Int) :=
  if word ≥ 4096 then none else
    match decodeAC12 word with
    | some height =>
        if bit word 4 == 0 && height < 0 then some none
        else if height > 50000 then none else some (some height)
    | none => some none

open Assignment

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

def compatibility12 (code : Nat) : Option Int :=
  (altitude12 code).filter (fun height => height ≤ 50000 && (code.testBit 4 || height ≥ 0))


example : (List.range 8192).all (fun code =>
    decide (compatibility13 code = oracleAC13 code)) = true := by decide +kernel
example : (List.range 4096).all (fun code =>
    decide (compatibility12 code = (oracleAC12 code).join)) = true := by decide +kernel
example : (List.range 4096).all (fun code =>
    altitudeCodeAdmissible code == (oracleAC12 code).isSome) = true := by decide +kernel
example : decodeGillham 0x100 = some (-1200) ∧
    oracleAC13 0x100 = none ∧ oracleAC12 0x80 = some none ∧
    oracleAC13 0x10 = some (-1000) ∧ oracleAC12 0x10 = some (some (-1000)) := by decide +kernel
example : ((decode [0xa1,0,0,0,0x92,8,5,0,0x3f,0xfc,0,5,0xc6,0xe5]).map
    (fun m => m.decoded.commB.map Prod.fst)) = some [5] := by decide +kernel
end AltitudeCompatibilityProposal

private def height (value : Option Int) : String :=
  match value with | none => "none" | some value => toString value

def main : IO Unit := do
  for code in [:8192] do
    IO.println s!"13,{code},{height (AltitudeCompatibilityProposal.oracleAC13 code)}"
  for code in [:4096] do
    IO.println s!"12,{code},{height ((AltitudeCompatibilityProposal.oracleAC12 code).join)},{(AltitudeCompatibilityProposal.oracleAC12 code).isSome}"

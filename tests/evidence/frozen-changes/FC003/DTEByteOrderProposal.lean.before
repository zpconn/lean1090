import Spec.Semantics

/-! REVIEW ONLY: candidate DTE compatibility projection. Nothing in the
decoder, gate, or frozen model imports this module. The driver verifies that
the complete function below is exactly the current frozen commBValue with
the one proposed match arm inserted. Standard/raw projections are unchanged.
-/

set_option maxRecDepth 100000
set_option maxHeartbeats 0
open Lean1090.Spec

namespace DTEByteOrderProposal

def commBValue (register word : Nat) (name : String) : Option Rat := do
  let layout ← commBLayout register
  let c ← layout.find? (fun c => c.name == name)
  let value ← payloadValue c word
  match register, name with
  | 0x10, "dte" => some (payloadBits word 41 8 + 256 * payloadBits word 49 8 : Rat)
  | 0x40, "selected_mcp" => some (cbSelected (payloadBits word 2 12))
  | 0x40, "selected_fms" => some (cbSelected (payloadBits word 15 12))
  | 0x44, "temperature" => some (cbTemperature44 word)
  | 0x50, "track" => some (cbWrapAngle value)
  | 0x50, "track_rate" =>
    if payloadBits word 37 9 == 511 then none else some value
  | 0x60, "heading" => some (cbWrapAngle value)
  | 0x60, "vrate_barometric" => some (cbVertical60 word 36)
  | 0x60, "vrate_inertial" => some (cbVertical60 word 47)
  | _, _ => some value

def standardValue (word : Nat) : Option Rat :=
  (((Semantics.commB 0x10 word).standardValues.find?
    (fun kv => kv.1 == "dte")).map (·.2)).join

-- Concrete counterexample and all basis patterns are checked by the kernel.
example : standardValue 0x10000000000001 = some 1 ∧
    commBValue 0x10 0x10000000000001 "dte" = some 256 := by decide +kernel

example : (0 :: 65535 :: (List.range 16).map (fun n => (2^n : Nat))).all (fun raw =>
    let word := 0x10000000000000 + raw
    decide (standardValue word = some (raw : Rat) ∧
      commBValue 0x10 word "dte" = some ((raw / 256 + 256 * (raw % 256) : Nat) : Rat))) =
    true := by decide +kernel

private def text (value : Option Rat) : String :=
  match value with
  | none => "none"
  | some q => if q.den == 1 then toString q.num else s!"{q.num}/{q.den}"

private def unchangedOtherFields (word : Nat) : Bool :=
  ((commBLayout 0x10).getD []).all fun column =>
    column.name == "dte" || decide
      (commBValue 0x10 word column.name = Lean1090.Spec.commBValue 0x10 word column.name)

def run (args : List String) : IO Unit := do
  let path ← match args with
    | [path] => pure path
    | _ => throw (IO.userError "usage: DTEByteOrderProposal.lean words.txt")
  let input ← IO.FS.readFile path
  IO.println "word,raw,current,proposed,standard,other_fields_unchanged"
  for line in input.splitOn "\n" do
    unless line.isEmpty do
      let some word := line.toNat? | throw (IO.userError "invalid payload word")
      IO.println s!"{word},{payloadBits word 41 16},{text (Lean1090.Spec.commBValue 0x10 word "dte")},{text (commBValue 0x10 word "dte")},{text (standardValue word)},{unchangedOtherFields word}"

end DTEByteOrderProposal

def main (args : List String) : IO Unit := DTEByteOrderProposal.run args

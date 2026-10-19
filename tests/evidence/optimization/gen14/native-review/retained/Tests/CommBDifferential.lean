import Impl.JSON
import Spec.Semantics
import Lean.Data.Json.Printer

/-! Supplemental named-register differential adapter. The complete message
runner separately checks actual DF20/21 candidate inference in three contexts.
This adapter exercises every direct register decoder, including BDS65, whose
whole-message inference path always rejects in the pinned oracle. -/
open Lean Lean1090

private def check (line : String) : IO Unit := do
  match line.trimAscii.toString.splitOn " " with
  | [register, word] =>
    let register ← match register.toNat? with
      | some n => pure n | none => throw (IO.userError "invalid register")
    let word ← match word.toNat? with
      | some n => pure n | none => throw (IO.userError "invalid payload")
    let actual := Impl.decodeBDS register word
    let reference := Spec.decodeBDS register word
    let meaning := Impl.Semantics.commB register word
    let output := match actual with
      | none => Json.null
      | some record => Json.mkObj (Impl.JSON.commB true register record meaning)
    IO.println (Json.mkObj [
      ("decoder_refines", .bool (actual == reference)),
      ("meaning_refines", .bool (meaning == Spec.Semantics.commB register word)),
      ("oracle", output)]).compress
  | _ => throw (IO.userError "expected decimal register and payload")

def main : IO Unit := do
  let input ← IO.getStdin
  repeat
    let line ← input.getLine
    if line.isEmpty then break
    unless line.trimAscii.toString.isEmpty do check line

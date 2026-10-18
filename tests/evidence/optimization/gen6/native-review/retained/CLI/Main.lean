import Impl.JSON
import Lean.Data.Json.Printer

open Lean Lean1090

private def nibble (c : Char) : Option Nat :=
  if '0' ≤ c && c ≤ '9' then some (c.toNat - '0'.toNat)
  else if 'a' ≤ c && c ≤ 'f' then some (c.toNat - 'a'.toNat + 10)
  else if 'A' ≤ c && c ≤ 'F' then some (c.toNat - 'A'.toNat + 10)
  else none

private def hexBytes : List Char → Option (List UInt8)
  | [] => some []
  | a :: b :: rest => do
    let hi ← nibble a
    let lo ← nibble b
    let tail ← hexBytes rest
    return (hi*16+lo).toUInt8 :: tail
  | _ => none

private def emit (mode : String) (line : String) : IO Unit := do
  let bytes := hexBytes line.trimAscii.toString.toList
  let output := match bytes with
    | none => Json.mkObj [("error", .str "invalid hexadecimal input")]
    | some bytes =>
      if mode == "--diagnostic" then
        match Impl.decodePrefix bytes with
        | none => Json.null
        | some (message, rest) => Json.mkObj [
          ("standard", Impl.JSON.message false message),
          ("oracle", Impl.JSON.message true message),
          ("crc", Impl.JSON.integer message.decoded.crc.toNat),
          ("consumed", Impl.JSON.integer (bytes.length - rest.length)),
          ("remainder", .str (String.join (rest.map (fun (b : UInt8) => Impl.JSON.digits 16 2 b.toNat))))]
      else match Impl.decode bytes with
        | none => Json.null
        | some message => Impl.JSON.message (mode == "--oracle-view") message
  IO.println output.compress

def main (args : List String) : IO UInt32 := do
  let (mode, messages) := match args with
    | mode :: rest => if mode == "--oracle-view" || mode == "--diagnostic"
        then (mode, rest) else ("--standard", args)
    | [] => ("--standard", [])
  if messages.isEmpty then
    let input ← IO.getStdin
    repeat
      let line ← input.getLine
      if line.isEmpty then break
      if !line.trimAscii.toString.isEmpty then emit mode line
  else
    for line in messages do emit mode line
  return 0

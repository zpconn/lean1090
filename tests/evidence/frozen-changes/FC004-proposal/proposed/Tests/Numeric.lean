import Impl.Numeric
import Impl.Presentation

open Lean1090.Impl
open Lean1090.Spec.Presentation

private def expected (bytes : ByteArray) (index : Nat) : UInt64 :=
  (List.range 8).foldl (fun value i =>
    value ||| ((bytes[index * 8 + i]?.getD 0).toUInt64 <<< (8*i).toUInt64)) 0

private def check (bytes : ByteArray) (index : Nat) (value : Float) (caseName : String) : IO Unit := do
  if value.toBits != expected bytes index then
    throw <| IO.userError s!"numeric mismatch at {caseName}, index {index}: {value.toBits} != {expected bytes index}"

def main (args : List String) : IO Unit := do
  let path ← match args with
    | [path] => pure path
    | _ => throw <| IO.userError "usage: numericTests oracle.bin"
  let bytes ← IO.FS.readBinFile path
  let count := 4093*4093 + 2045*2045 + 512*2 + 1024 + 1
  unless bytes.size == count*8 do
    throw <| IO.userError s!"wrong expected-output size: {bytes.size}"
  let mut index := 0
  for x in [:4093] do
    for y in [:4093] do
      check bytes index (Numeric.hypot x.toUInt64.toFloat y.toUInt64.toFloat) s!"hypot({x},{y})"
      index := index + 1
  IO.println "hypot: all 16,752,649 integer pairs, bit-identical"
  for x in [:2045] do
    for y in [:2045] do
      let a : Int := (x : Int) - 1022
      let b : Int := (y : Int) - 1022
      check bytes index (Numeric.eval (Presentation.velocityTrack a b)) s!"track({a},{b})"
      index := index + 1
  IO.println "track: all 4,182,025 oracle component pairs, bit-identical"
  for n in [:512] do
    let pressure : FloatExpr := .add .binary32 (.literal .binary32 800)
      (.mul .binary32 (.literal .binary32 n) (.literal .binary32 (4/5)))
    check bytes index (Numeric.eval pressure) s!"pressure({n})"
    check bytes (index+1) (Numeric.eval (Presentation.scaled .binary32 n 180 256)) s!"selected_heading({n})"
    index := index + 2
  for n in [:1024] do
    check bytes index (Numeric.eval (Presentation.scaled .binary32 n 360 1024)) s!"heading({n})"
    index := index + 1
  let midpoint : Rat := 1 + 1/(2^24 : Nat) + 1/(2^80 : Nat)
  check bytes index (Numeric.toFloat32 midpoint).toFloat "direct binary32 midpoint"
  IO.println s!"presentation numeric tests: {count} exact comparisons passed"

import Spec.Message
import Impl.Message

/-!
Permanent exhaustive altitude differential adapter. It evaluates the actual
reference, independent assignment, and implementation definitions, plus full
DF4/DF18 decoding. The Python driver feeds the identical wire bytes to the
pinned rs1090 Message::from_bytes and checks acceptance and optional altitude.
The standard view remains distinct from the oracle compatibility view.
-/

set_option maxRecDepth 100000
set_option maxHeartbeats 0

namespace Lean1090.Tests.AltitudeDifferential
open Spec

private def ac13Bytes (code : Nat) : List UInt8 :=
  valueBytes 7 (4 * 2^51 + code * 2^24)

private def ac12Bytes (code : Nat) : List UInt8 :=
  valueBytes 14 (18 * 2^107 + 11 * 2^75 + code * 2^60)

private def regression : List UInt8 :=
  [0xa1,0,0,0,0x92,8,5,0,0x3f,0xfc,0,5,0xc6,0xe5]

-- Concrete kernel checks lock in standard negative Gillham values, oracle
-- missing values, preserved negative Q=1 values, and the inference regression.
example : Altitude.decodeAC13 0x100 = some (.feet (-1200)) ∧
    Altitude.decodeAC12 0x80 = some (-1200) ∧
    Altitude.oracleAC13 0x100 = none ∧
    Altitude.oracleAC12 0x80 = some none ∧
    Altitude.oracleAC13 0x10 = some (-1000) ∧
    Altitude.oracleAC12 0x10 = some (some (-1000)) := by decide +kernel

example : ((Spec.decode (ac13Bytes 0x100)).bind (·.decoded.altitude)) =
    some (.feet (-1200)) ∧
    ((Spec.decode (ac12Bytes 0x80)).bind (·.decoded.altitude)) =
    some (.feet (-1200)) := by decide +kernel

-- ICAO Annex10 IV (4th ed., 2007), Appendix to Chapter3, p.3-87:
-- pressure-altitude pulse assignment row -950..-850ft (see D010).
example : Altitude.decodeAC13 0x1400 = some (.feet (-900)) ∧
    Altitude.decodeAC12 0xa00 = some (-900) ∧
    Altitude.oracleAC13 0x1400 = none ∧
    Altitude.oracleAC12 0xa00 = some none := by decide +kernel

example : ((Spec.decode regression).map (fun m => m.decoded.commB.map Prod.fst)) =
    some [5] ∧
    ((Impl.decode regression).map (fun m => m.decoded.commB.map Prod.fst)) =
    some [5] := by decide +kernel

private def checked (condition : Bool) (context : String) : IO Unit :=
  unless condition do throw (IO.userError context)

private def heightText (value : Option Int) : String :=
  match value with | none => "none" | some h => toString h

private def standardText (value : Option Altitude.Value) : String :=
  match value with
  | none => "none,none"
  | some (.feet h) => s!"feet,{h}"
  | some (.metres h) => s!"metres,{h}"

private def hexByte (byte : UInt8) : String :=
  let digits := "0123456789abcdef".toList.toArray
  String.ofList [digits[byte.toNat / 16]?.getD '0', digits[byte.toNat % 16]?.getD '0']

private def checkFrame (bytes : List UInt8) (accepted : Bool) (height : Option Int)
    (standard : Option Altitude.Value) (context : String) : IO Unit := do
  let ref := Spec.decode bytes
  let impl := Impl.decode bytes
  checked (decide (ref = impl)) s!"{context}: full Impl.decode/Spec.decode mismatch"
  checked (ref.isSome == accepted) s!"{context}: full decoder acceptance mismatch"
  checked (decide (ref.bind (fun m => Spec.frameOracleAltitude m.fields) = height))
    s!"{context}: full decoder compatibility altitude mismatch"
  checked (decide (impl.bind (fun m => Impl.frameOracleAltitude m.fields) = height))
    s!"{context}: implementation full decoder compatibility altitude mismatch"
  if accepted then
    checked (decide (ref.bind (·.decoded.altitude) = standard))
      s!"{context}: full decoder standard altitude mismatch"

def run : IO Unit := do
  IO.println "width,code,hex,accepted,height,standard_unit,standard_height"
  for code in [:8192] do
    let bytes := ac13Bytes code
    let height := Altitude.oracleAC13 code
    let standard := Altitude.decodeAC13 code
    let context := s!"AC13 {code}"
    checked (decide (height = Impl.Altitude.oracleAC13 code ∧
      height = Assignment.compatibility13 code ∧
      standard = Impl.Altitude.decodeAC13 code ∧
      standard = Assignment.altitude13 code)) s!"{context}: direct definition mismatch"
    checkFrame bytes true height standard context
    IO.println s!"13,{code},{String.join (bytes.map hexByte)},true,{heightText height},{standardText standard}"
  for code in [:4096] do
    let bytes := ac12Bytes code
    let result := Altitude.oracleAC12 code
    let standard := (Altitude.decodeAC12 code).map Altitude.Value.feet
    let context := s!"AC12 {code}"
    checked (decide (result = Impl.Altitude.oracleAC12 code ∧
      result.join = Assignment.compatibility12 code ∧
      standard = (Impl.Altitude.decodeAC12 code).map Altitude.Value.feet ∧
      standard = (Assignment.altitude12 code).map Altitude.Value.feet))
      s!"{context}: direct definition mismatch"
    checked (result.isSome == altitudeCodeAdmissible code)
      s!"{context}: independent acceptance mismatch"
    checkFrame bytes result.isSome result.join standard context
    IO.println s!"12,{code},{String.join (bytes.map hexByte)},{result.isSome},{heightText result.join},{standardText standard}"
  let ref := Spec.decode regression
  let impl := Impl.decode regression
  checked (decide (ref = impl)) "Comm-B regression: full decoder mismatch"
  checked (decide (ref.map (fun m => m.decoded.commB.map Prod.fst) = some [5]))
    "Comm-B regression: wrong candidate set"

end Lean1090.Tests.AltitudeDifferential

def main : IO Unit := Lean1090.Tests.AltitudeDifferential.run

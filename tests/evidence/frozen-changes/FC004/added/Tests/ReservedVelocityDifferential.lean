import Spec.Message
import Impl.JSON
import Lean.Data.Json.Printer

/-!
Permanent TC19 reserved-subtype differential adapter. The Python driver supplies
the same complete DF18 frames to this adapter and a freshly built pinned Rust
oracle. This adapter evaluates the actual reference, implementation, independent
assignment, and JSON projection. It does not substitute a proposed definition.
-/

set_option maxRecDepth 100000
set_option maxHeartbeats 0

namespace Lean1090.Tests.ReservedVelocityDifferential
open Lean Spec

private def wire (word : Nat) : List UInt8 :=
  valueBytes 14 (18 * 2^107 + 0x112233 * 2^80 + word * 2^24)

private def reservedValue (p : Semantics.Payload) : Option Rat :=
  ((p.oracleValues.find? (fun kv => kv.1 == "reserved_data")).map (·.2)).join

-- The exact reported counterexample, checked by the kernel. The standard
-- view retains the 22-bit MSB-first code; the x86_64 oracle view is distinct.
example : ((Spec.decode (wire 0x98040000000000)).bind (·.decoded.adsb)).map
    (fun record => Impl.JSON.raw record "reserved_data") = some 2097152 := by
  decide +kernel

example : ((Spec.decode (wire 0x98040000000000)).bind
    (·.decoded.semanticADSB)).bind reservedValue = some 128 := by
  decide +kernel

private def emit (word : Nat) : IO Unit := do
  let bytes := wire word
  let ref := Spec.decode bytes
  let impl := Impl.decode bytes
  let fields : List (String × Json) := [
    ("word", Impl.JSON.integer word),
    ("hex", .str (String.join (bytes.map (fun b => Impl.JSON.digits 16 2 b.toNat)))),
    ("spec_matches_impl", .bool (decide (ref = impl))),
    ("assignment_matches_spec", .bool (decide
      (Assignment.adsbMeaning word = Semantics.adsb word))),
    ("full_assignment_matches_spec", .bool (decide
      (ref.map (fun m => assigned m.fields) = ref))),
    ("standard_raw", (ref.bind (·.decoded.adsb)).map
      (fun record => Impl.JSON.integer (Impl.JSON.raw record "reserved_data")) |>.getD .null),
    ("oracle_value", ((ref.bind (·.decoded.semanticADSB)).bind reservedValue).map
      Impl.JSON.rational |>.getD .null),
    ("standard", (ref.map (Impl.JSON.message false)).getD .null),
    ("oracle", (impl.map (Impl.JSON.message true)).getD .null),
    ("crc", (impl.map (fun m => Impl.JSON.integer m.decoded.crc.toNat)).getD .null),
    ("consumed", if impl.isSome then Impl.JSON.integer bytes.length else .null),
    ("remainder", if impl.isSome then .str "" else .null)]
  IO.println (Json.mkObj fields).compress

def run (args : List String) : IO Unit := do
  let path ← match args with
    | [path] => pure path
    | _ => throw (IO.userError "usage: ReservedVelocityDifferential.lean words.txt")
  let input ← IO.FS.readFile path
  for line in input.splitOn "\n" do
    unless line.isEmpty do
      let some word := line.toNat? | throw (IO.userError "invalid decimal payload word")
      emit word

end Lean1090.Tests.ReservedVelocityDifferential

def main (args : List String) : IO Unit :=
  Lean1090.Tests.ReservedVelocityDifferential.run args

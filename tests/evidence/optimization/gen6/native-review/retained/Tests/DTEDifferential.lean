import Spec.Message
import Impl.JSON
import Lean.Data.Json.Printer

/-!
Permanent exhaustive BDS10 DTE differential adapter. The driver supplies every
16-bit DTE code exactly once and sends the same payloads/complete DF20 frames to
fresh pinned rs1090 direct-register and Message::from_bytes oracles. All values
here come from the actual definitions, with no review-only substitution.
-/

set_option maxRecDepth 100000
set_option maxHeartbeats 0

namespace Lean1090.Tests.DTEDifferential
open Lean Spec

private def wire (word : Nat) : List UInt8 :=
  valueBytes 14 (20 * 2^107 + word * 2^24)

private def dte (values : Semantics.Values) : Option Rat :=
  ((values.find? (fun kv => kv.1 == "dte")).map (·.2)).join

-- Kernel checks bind the concrete D012 counterexample to actual definitions.
example : dte (Semantics.commB 0x10 0x10000000000001).standardValues = some 1 ∧
    dte (Semantics.commB 0x10 0x10000000000001).oracleValues = some 256 := by
  decide +kernel

private def emit (word : Nat) : IO Unit := do
  let bytes := wire word
  let ref := Spec.decode bytes
  let impl := Impl.decode bytes
  let reference := Spec.decodeBDS 0x10 word
  let actual := Impl.decodeBDS 0x10 word
  let meaning := Impl.Semantics.commB 0x10 word
  let fields : List (String × Json) := [
    ("word", Impl.JSON.integer word),
    ("hex", .str (String.join (bytes.map (fun b => Impl.JSON.digits 16 2 b.toNat)))),
    ("spec_matches_impl", .bool (decide (ref = impl))),
    ("assignment_matches_spec", .bool (decide
      (Assignment.commBMeaning 0x10 word = Semantics.commB 0x10 word))),
    ("full_assignment_matches_spec", .bool (decide
      (ref.map (fun m => assigned m.fields) = ref))),
    ("direct_decoder_refines", .bool (decide (actual = reference))),
    ("direct_meaning_refines", .bool (decide (meaning = Semantics.commB 0x10 word))),
    ("standard_raw", (reference.map
      (fun record => Impl.JSON.integer (Impl.JSON.raw record "dte"))).getD .null),
    ("standard_value", ((dte meaning.standardValues).map Impl.JSON.rational).getD .null),
    ("oracle_value", ((dte meaning.oracleValues).map Impl.JSON.rational).getD .null),
    ("direct_standard", (actual.map
      (fun record => Json.mkObj (Impl.JSON.commB false 0x10 record meaning))).getD .null),
    ("direct_oracle", (actual.map
      (fun record => Json.mkObj (Impl.JSON.commB true 0x10 record meaning))).getD .null),
    ("standard", (ref.map (Impl.JSON.message false)).getD .null),
    ("oracle", (impl.map (Impl.JSON.message true)).getD .null),
    ("crc", (impl.map (fun m => Impl.JSON.integer m.decoded.crc.toNat)).getD .null),
    ("consumed", if impl.isSome then Impl.JSON.integer bytes.length else .null),
    ("remainder", if impl.isSome then .str "" else .null)]
  IO.println (Json.mkObj fields).compress

def run : IO Unit := do
  let input ← IO.getStdin
  repeat
    let line ← input.getLine
    if line.isEmpty then break
    let line := line.trimAscii.toString
    unless line.isEmpty do
      let some word := line.toNat? | throw (IO.userError "invalid decimal BDS10 payload")
      emit word

end Lean1090.Tests.DTEDifferential

def main : IO Unit := Lean1090.Tests.DTEDifferential.run

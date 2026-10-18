import Impl
import Impl.JSON
import Lean.Data.Json.Parser
import Lean.Data.Json.Printer
import Lean.Data.Json.FromToJson.Basic

/-! Port of pinned python/tests/test_full.py:10–22. Decode the complete
timestamped corpus with reference (43.3, 1.35), then assert that the number
of successfully decoded messages equals the source corpus length. The source
assertion makes no claim about the number or accuracy of resolved positions.
We still execute the live stream decoder and consume all of its outputs.
Input timestamps/reference/airports are exact binary64 bit patterns. -/
set_option maxRecDepth 1000000
set_option maxHeartbeats 0
open Lean Lean1090
open Lean1090.Spec.CPR Lean1090.Spec.CPR.Policy

namespace Lean1090.Tests.UpstreamCorpus

private def rational (bits : Nat) : Except String Rat :=
  if bits ≥ 2^64 then .error "binary64 bits out of range" else
  match Impl.Binary64.fromBits (BitVec.ofNat 64 bits) with
  | some q => .ok q
  | none => .error "nonfinite input"

private def position (j : Json) : Except String Position := do
  let a ← j.getArr?
  if a.size != 2 then throw "coordinate pair expected"
  let some lat := a[0]? | throw "latitude absent"
  let some lon := a[1]? | throw "longitude absent"
  return ⟨← rational (← lat.getNat?), ← rational (← lon.getNat?)⟩

private def nibble (c : Char) : Option Nat :=
  if '0' ≤ c && c ≤ '9' then some (c.toNat - 48)
  else if 'a' ≤ c && c ≤ 'f' then some (c.toNat - 87)
  else if 'A' ≤ c && c ≤ 'F' then some (c.toNat - 55) else none

private def hex : List Char → Option (List UInt8)
  | [] => some []
  | a :: b :: rest => do
    return ((← nibble a) * 16 + (← nibble b)).toUInt8 :: (← hex rest)
  | _ => none

/-- Test glue projects already-decoded DF17/18 fields into the live stream
entrypoint. CPR equations, numerical geography, and tracking remain in Impl. -/
private def report (timestamp : Rat) (m : Spec.Message) : Option TimedReport := do
  match m.fields.body with
  | .extended _ _ _ _ => pure ()
  | _ => none
  let address ← m.decoded.address
  let r ← m.decoded.adsb
  let sem ← m.decoded.semanticADSB
  let raw := Impl.JSON.raw r
  let tc := raw "tc"
  let code : Encoded := ⟨raw "parity" == 1, raw "lat_cpr", raw "lon_cpr"⟩
  let message := if 5 ≤ tc && tc ≤ 8 then Message.surface code
    else if (9 ≤ tc && tc ≤ 18) || (20 ≤ tc && tc ≤ 22) then
      let altitude := (Impl.JSON.value true sem "altitude_feet").map Rat.floor
      let metadata : AirborneMetadata := {
        nucP := if tc < 19 then 18 - tc else if tc == 20 || tc == 21 then 29 - tc else 0
        surveillanceStatus := raw "ss"
        safOrNICb := if tc < 19 then some (raw "saf_or_nicb") else none
        gnssSource := tc ≥ 20
        timeSync := raw "time_sync" == 1 }
      Message.airborne code altitude metadata
    else Message.other (if 1 ≤ tc && tc ≤ 4 then .identification else if tc == 19 then .velocity
      else if tc == 28 then .emergency else if tc == 29 then .targetState
      else if tc == 31 then .operationalStatus else .reserved)
  return ⟨address.toNat, timestamp, message⟩

def run (inputPath airportPath : String) : IO UInt32 := do
  let mut airports : Array Airport := #[]
  for line in ← IO.FS.lines airportPath do
    let j ← IO.ofExcept (Json.parse line)
    let icao ← IO.ofExcept (j.getObjValAs? String "icao")
    let p ← IO.ofExcept ((j.getObjVal? "position") >>= position)
    airports := airports.push ⟨icao, p⟩
  let mut rows := 0
  let mut decoded := 0
  let mut reports : Array TimedReport := #[]
  let mut expectedCount := none
  let mut reference := none
  for line in ← IO.FS.lines inputPath do
    let j ← IO.ofExcept (Json.parse line)
    let kind ← IO.ofExcept (j.getObjValAs? String "kind")
    if kind == "header" then
      if expectedCount.isSome || rows != 0 then throw (IO.userError "duplicate/misplaced header")
      expectedCount := some (← IO.ofExcept (j.getObjValAs? Nat "count"))
      reference := some (← IO.ofExcept ((j.getObjVal? "reference") >>= position))
    else if kind == "message" then
      if expectedCount.isNone then throw (IO.userError "missing initial header")
      let timestamp ← IO.ofExcept ((j.getObjValAs? Nat "timestamp_bits") >>= rational)
      let h ← IO.ofExcept (j.getObjValAs? String "hex")
      let some bytes := hex h.toList | throw (IO.userError "invalid hexadecimal frame")
      rows := rows + 1
      -- Python decode_1090t_vec uses filter_map: rejected messages are omitted.
      match Impl.decode bytes with
      | none => pure ()
      | some m =>
        decoded := decoded + 1
        if let some r := report timestamp m then reports := reports.push r
    else throw (IO.userError "unknown fixture record kind")
  let some expected := expectedCount | throw (IO.userError "header missing")
  let some initialReference := reference | throw (IO.userError "reference missing")
  if rows != expected then throw (IO.userError "fixture count does not match header")
  let (state, positions) := Impl.decodePositions
    (Impl.CPR.Policy.numericalGeography airports.toList) (fun _ => false)
    (some initialReference) reports.toList
  let resolved := positions.foldl (fun n p => n + if p.isSome then 1 else 0) 0
  if positions.length != reports.size then throw (IO.userError "stream result cardinality mismatch")
  let passed := decoded == rows
  IO.println (Json.mkObj [
    ("test", toJson "python/tests/test_full.py::test_full"), ("source_line", toJson (22 : Nat)),
    ("passed", .bool passed), ("source_assertions", toJson (1 : Nat)),
    ("corpus_rows", toJson rows), ("decoded_messages", toJson decoded),
    ("tracking_reports", toJson reports.size), ("tracking_results", toJson positions.length),
    ("resolved_positions_observed", toJson resolved), ("aircraft_states", toJson state.aircraft.length),
    ("airports", toJson airports.size)]).compress
  return if passed then 0 else 1

end Lean1090.Tests.UpstreamCorpus

def main (args : List String) : IO UInt32 :=
  match args with
  | [input, airports] => Lean1090.Tests.UpstreamCorpus.run input airports
  | _ => throw (IO.userError "usage: upstream-corpus INPUT.jsonl AIRPORTS.jsonl")

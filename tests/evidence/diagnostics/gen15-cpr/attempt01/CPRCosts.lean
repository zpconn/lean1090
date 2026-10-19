import Impl
import Impl.JSON
import Lean.Data.Json.Parser
import Lean.Data.Json.FromToJson.Basic

/-! Untimed CPR diagnostic. Input/routing definitions below are copied exactly
from frozen Bench/WholeDecoder.lean. Only the new loop and consumers are diagnostic.
Production objects and streamStep are reused unchanged. -/
namespace Lean1090.Diagnostics.CPRCosts
open Lean
open Spec.CPR Spec.CPR.Policy

private def expectedMessages : Nat := 172432
private def airportPath : String := "vendor/rs1090/crates/rs1090/data/airports.json"

private structure Input where
  timestamp : Rat
  bytes : List UInt8

private structure Output where
  message : Spec.Message
  position : Option Position

private def nibble (c : Char) : Option Nat :=
  if '0' ≤ c && c ≤ '9' then some (c.toNat - 48)
  else if 'a' ≤ c && c ≤ 'f' then some (c.toNat - 87)
  else if 'A' ≤ c && c ≤ 'F' then some (c.toNat - 55) else none

private def hexBytes : List Char → Option (List UInt8)
  | [] => some []
  | a :: b :: rest => do
      return ((← nibble a) * 16 + (← nibble b)).toUInt8 :: (← hexBytes rest)
  | _ => none

/-- Decimal parsing is outside timing. Round once to the exact rational value
of the same finite binary64 quantity Rust receives. No Float inference is used. -/
private def number (json : Json) : Except String Rat := do
  let n ← json.getNum?
  let value := Impl.Binary64.round ((n.mantissa : Rat) / (10 ^ n.exponent : Nat))
  if value.abs > Impl.Binary64.maxFinite then throw "non-finite input number"
  return value

private def loadInputs (path : String) : IO (Array Input) := do
  let text ← IO.FS.readFile path
  let mut inputs := Array.mkEmpty expectedMessages
  let lines := text.splitOn "\n"
  for (line, index) in lines.zipIdx do
    -- text.lines() also ignores the final newline, but not interior blank rows.
    if line.isEmpty && index + 1 == lines.length then continue
    let row := if line.endsWith "\r" then line.dropEnd 1 |>.toString else line
    let [time, beast] := row.splitOn ","
      | throw (IO.userError s!"line {index + 1}: expected timestamp,frame")
    if beast.length < 18 then throw (IO.userError s!"line {index + 1}: missing Beast prefix")
    let hexadecimal := String.ofList (beast.toList.drop 18)
    if hexadecimal.length != 14 && hexadecimal.length != 28 then
      throw (IO.userError s!"line {index + 1}: expected 7 or 14 message bytes")
    let some bytes := hexBytes hexadecimal.toList
      | throw (IO.userError s!"line {index + 1}: invalid hexadecimal digit")
    let timestamp ← IO.ofExcept ((Json.parse time) >>= number)
    inputs := inputs.push ⟨timestamp, bytes⟩
  if inputs.size != expectedMessages then
    throw (IO.userError s!"expected {expectedMessages} messages, found {inputs.size}")
  return inputs

/-- The full pinned 6,903-entry dataset, in source order. The frozen parent
runner checks the pinned oracle commit and clean tracked files before startup. -/
private def loadAirports : IO (List Airport) := do
  let json ← IO.ofExcept (Json.parse (← IO.FS.readFile airportPath))
  let array ← IO.ofExcept json.getArr?
  if array.size != 6903 then throw (IO.userError "expected 6903 pinned airports")
  let mut airports := []
  for entry in array do
    let icao ← IO.ofExcept ((entry.getObjVal? "icao") >>= Json.getStr?)
    let latitude ← IO.ofExcept ((entry.getObjVal? "lat") >>= number)
    let longitude ← IO.ofExcept ((entry.getObjVal? "lon") >>= number)
    airports := ⟨icao, ⟨latitude, longitude⟩⟩ :: airports
  return airports.reverse

/-- Project a freshly decoded DF17/18 into the live stream policy. This runs
inside the CPR interval and never decodes the bytes a second time. -/
private def trackingReport (timestamp : Rat) (message : Spec.Message) : Option TimedReport := do
  match message.fields.body with
  | .extended _ _ _ _ => pure ()
  | _ => none
  let address ← message.decoded.address
  let fields ← message.decoded.adsb
  let semantic ← message.decoded.semanticADSB
  let raw := Impl.JSON.raw fields
  let tc := raw "tc"
  let code : Encoded := ⟨raw "parity" == 1, raw "lat_cpr", raw "lon_cpr"⟩
  let report := if 5 ≤ tc && tc ≤ 8 then Message.surface code
    else if (9 ≤ tc && tc ≤ 18) || (20 ≤ tc && tc ≤ 22) then
      let altitude := (((semantic.oracleValues.find? (·.1 == "altitude_feet")).map (·.2)).join).map Rat.floor
      let metadata : AirborneMetadata := {
        nucP := if tc < 19 then 18-tc else if tc == 20 || tc == 21 then 29-tc else 0
        surveillanceStatus := raw "ss"
        safOrNICb := if tc < 19 then some (raw "saf_or_nicb") else none
        gnssSource := tc ≥ 20
        timeSync := raw "time_sync" == 1 }
      Message.airborne code altitude metadata
    else Message.other (if 1 ≤ tc && tc ≤ 4 then .identification else if tc == 19 then .velocity
      else if tc == 28 then .emergency else if tc == 29 then .targetState
      else if tc == 31 then .operationalStatus else .reserved)
  return ⟨address.toNat, timestamp, report⟩

/-- Shared live routing used by the timed secondary path and its audit. -/
private def advance (geo : Geography) (state : StreamState) (timestamp : Rat)
    (message : Spec.Message) : StreamState × Option Position :=
  match trackingReport timestamp message with
  | none => (state, none)
  | some report => Impl.CPR.Policy.streamStep geo (fun _ => false) state report

private def floatBits (value : Rat) : Nat := (Impl.CPR.Policy.toFloat value).toBits.toNat

private def positionJson (p : Option Position) : Json :=
  match p with
  | none => .null
  | some p => toJson [floatBits p.lat, floatBits p.lon]


private def emit (value : Json) : IO Unit := do
  IO.println value.compress
  (← IO.getStdout).flush

private def command (enabled : Bool) (expected : String) : IO Unit := do
  if enabled then
    repeat
      let line ← (← IO.getStdin).getLine
      let value := line.trimAscii.toString
      if value == "poll" then continue
      if value != expected then throw (IO.userError s!"expected command {expected}")
      break

/-- Identical frozen secondary-loop work without clocks or post-run consumption.
The complete output and final state are returned across the collection boundary. -/
@[noinline] def runCPR (inputs : Array Input) (geo : Geography) : IO (Array Output × StreamState) := do
  let mut output : Array Output := Array.mkEmpty inputs.size
  let mut state : StreamState := ⟨[], none⟩
  for input in inputs do
    let some message := Impl.decode input.bytes
      | throw (IO.userError "decoder rejected a corpus message")
    let next := advance geo state input.timestamp message
    state := next.1
    output := output.push ⟨message, next.2⟩
  return (output, state)

private def hashBytes (hash : UInt64) (bytes : ByteArray) : UInt64 :=
  bytes.data.foldl (fun h b => (h ^^^ b.toUInt64) * 1099511628211) hash

/-- Read every retained message field and every per-message position, after
collection. The FNV digest matches DecodeCosts and is not a cryptographic proof. -/
@[noinline] private def consume (inputs : Array Input) (output : Array Output)
    (state : StreamState) (audit : Option String) : IO Json := do
  if output.size != expectedMessages || inputs.size != output.size then
    throw (IO.userError "incomplete retained output")
  let mut digest : UInt64 := 14695981039346656037
  let mut reprBytes : Nat := 0
  let mut resolved : Nat := 0
  let mut routed : Nat := 0
  let mut airborne : Nat := 0
  let mut surface : Nat := 0
  let mut other : Nat := 0
  let mut lines : Array String := #[]
  for h : index in [:output.size] do
    let entry := output[index]
    let bytes := (reprStr entry.message ++ "\n").toUTF8
    digest := hashBytes digest bytes
    reprBytes := reprBytes + bytes.size
    if entry.position.isSome then resolved := resolved + 1
    let isRouted := match entry.message.fields.body with | .extended _ _ _ _ => true | _ => false
    if isRouted then routed := routed + 1
    let some input := inputs[index]? | throw (IO.userError "missing retained input")
    if let some report := trackingReport input.timestamp entry.message then
      match report.message with
      | .airborne _ _ _ => airborne := airborne + 1
      | .surface _ => surface := surface + 1
      | .other _ => other := other + 1
    if audit.isSome then
      lines := lines.push (Json.mkObj [("id", toJson index), ("position", positionJson entry.position),
        ("routed", toJson isRouted)]).compress
  let aircraft := state.aircraft.mergeSort (fun a b => a.1 ≤ b.1)
  let final := Json.mkObj [("final", .bool true), ("reference", positionJson state.reference),
    ("aircraft", toJson (aircraft.map (fun (address, state) => Json.mkObj [
      ("address", toJson address), ("position", positionJson state.position),
      ("altitude", toJson state.lastAltitude), ("airport", toJson state.airport),
      ("seen", toJson state.seenBDS)])))]
  if let some path := audit then
    lines := lines.push final.compress
    IO.FS.writeFile path (String.intercalate "\n" lines.toList ++ "\n")
  return Json.mkObj [("phase", .str "result"), ("mode", .str "all"),
    ("digest", Json.mkObj [("count", toJson output.size), ("repr_bytes", toJson reprBytes),
      ("fnv1a64_decimal", toJson digest.toNat)]), ("positions", toJson resolved),
    ("routed", toJson routed), ("airborne", toJson airborne), ("surface", toJson surface),
    ("other", toJson other), ("final_state", final)]

private def execute (path : String) (wait : Bool) (audit : Option String)
    (inputAudit : Bool) (airportAudit : Bool) : IO Unit := do
  let inputs ← loadInputs path
  let airports ← loadAirports
  if inputAudit then
    for input in inputs do
      IO.println s!"{floatBits input.timestamp} {String.intercalate " " (input.bytes.map (fun byte => toString byte.toNat))}"
    return
  if airportAudit then
    for airport in airports do
      IO.println s!"{airport.icao} {floatBits airport.position.lat} {floatBits airport.position.lon}"
    return
  let geo := Impl.CPR.Policy.numericalGeography airports
  emit (Json.mkObj [("phase", .str "prepared"), ("mode", .str "all"),
    ("selected", toJson inputs.size), ("airports", toJson airports.length),
    ("reference", .null), ("update_reference", .bool false)])
  command wait "run"
  let (output, state) ← runCPR inputs geo
  emit (Json.mkObj [("phase", .str "decoded"), ("mode", .str "all"),
    ("retained", toJson output.size)])
  command wait "consume"
  emit (← consume inputs output state audit)

end Lean1090.Diagnostics.CPRCosts

def main (args : List String) : IO UInt32 := do
  match args with
  | ["all", path] => Lean1090.Diagnostics.CPRCosts.execute path false none false false; return 0
  | ["all", path, "--wait"] => Lean1090.Diagnostics.CPRCosts.execute path true none false false; return 0
  | ["all", path, "--audit", audit] => Lean1090.Diagnostics.CPRCosts.execute path false (some audit) false false; return 0
  | ["--audit-inputs", path] => Lean1090.Diagnostics.CPRCosts.execute path false none true false; return 0
  | ["--audit-airports", path] => Lean1090.Diagnostics.CPRCosts.execute path false none false true; return 0
  | _ => IO.eprintln "usage: cpr-costs all CORPUS [--wait|--audit FILE] | --audit-inputs|--audit-airports CORPUS"; return 2

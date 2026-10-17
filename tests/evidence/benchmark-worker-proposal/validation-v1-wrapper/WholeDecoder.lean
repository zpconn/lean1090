import Impl
import Impl.JSON
import Lean.Data.Json.Parser
import Lean.Data.Json.FromToJson.Basic

/-! Whole-decoder persistent worker for the frozen benchmark contract.
The only timed decode entrypoint is Impl.decode, including its complete model
projection. Inputs, output capacity, empty state, and airport data precede the
clock; complete messages, positions, and state remain live across its end. -/
namespace Lean1090.Bench.WholeDecoder
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

/-- Observable post-clock consumer. Its noinline boundary accepts the complete
retained container and state, so the generated C keeps both through the timer.
A checksum of stored fields is reported only on stderr, outside the interval. -/
@[noinline] private def consume (output : Array Output) (state : StreamState) : IO Nat := do
  if output.size != expectedMessages then throw (IO.userError "incomplete retained output")
  let mut positions := 0
  let mut checksum : Nat := state.aircraft.length
  for entry in output do
    if entry.position.isSome then positions := positions + 1
    checksum := (checksum + entry.message.fields.parity.toNat +
      entry.message.decoded.commB.length + entry.message.decoded.semanticCommB.length) % 4294967296
  IO.eprintln s!"consumed messages={output.size} aircraft={state.aircraft.length} checksum={checksum}"
  return positions

/-- One requested run, with no internal warmup and no state reused across runs.
The entire decoded message is appended before stop, even if it has no CPR. -/
@[noinline] private def runOnce (inputs : Array Input) (geo : Geography) (cpr : Bool) : IO (Nat × Nat) := do
  let mut output : Array Output := Array.mkEmpty inputs.size
  let mut state : StreamState := ⟨[], none⟩
  let start ← IO.monoNanosNow
  for input in inputs do
    let some message := Impl.decode input.bytes
      | throw (IO.userError "decoder rejected a corpus message")
    let mut position := none
    if cpr then
      let next := advance geo state input.timestamp message
      state := next.1
      position := next.2
    output := output.push ⟨message, position⟩
  let finish ← IO.monoNanosNow
  let positions ← consume output state
  return (finish-start, positions)

private def worker (inputs : Array Input) (geo : Geography) (cpr : Bool) : IO Unit := do
  IO.println s!"ready {inputs.size}"
  (← IO.getStdout).flush
  let stdin ← IO.getStdin
  repeat
    let line ← stdin.getLine
    if line.isEmpty then break
    match line.trimAscii.toString with
    | "quit" => break
    | "run" =>
      let (elapsed, positions) ← runOnce inputs geo cpr
      IO.println s!"{elapsed} {positions}"
      (← IO.getStdout).flush
    | _ => throw (IO.userError "unknown worker command")

private def floatBits (value : Rat) : Nat := (Impl.CPR.Policy.toFloat value).toBits.toNat

private def positionJson (p : Option Position) : Json :=
  match p with
  | none => .null
  | some p => toJson [floatBits p.lat, floatBits p.lon]

/-- Untimed diagnostic route over every prepared input, sharing the same
projection and state transition as the timed CPR worker. -/
private def auditTracking (inputs : Array Input) (geo : Geography) : IO Unit := do
  let mut state : StreamState := ⟨[], none⟩
  for h : index in [:inputs.size] do
    let input := inputs[index]
    let some message := Impl.decode input.bytes
      | throw (IO.userError "decoder rejected a corpus message")
    let next := advance geo state input.timestamp message
    state := next.1
    let routed := match message.fields.body with | .extended _ _ _ _ => true | _ => false
    IO.println (Json.mkObj [("id", toJson index), ("position", positionJson next.2),
      ("routed", toJson routed)]).compress
  let aircraft := state.aircraft.mergeSort (fun a b => a.1 ≤ b.1)
  IO.println (Json.mkObj [("final", .bool true), ("reference", positionJson state.reference),
    ("aircraft", toJson (aircraft.map (fun (address, state) => Json.mkObj [
      ("address", toJson address), ("position", positionJson state.position),
      ("altitude", toJson state.lastAltitude), ("airport", toJson state.airport),
      ("seen", toJson state.seenBDS)])))]).compress

private def execute (mode path : String) : IO Unit := do
  let inputs ← loadInputs path
  let airports ← loadAirports
  let geo := Impl.CPR.Policy.numericalGeography airports
  match mode with
  | "--worker-decode" => worker inputs geo false
  | "--worker-cpr" => worker inputs geo true
  | "--check" =>
    for cpr in [false,true] do
      let (_,positions) ← runOnce inputs geo cpr
      IO.println s!"check mode={if cpr then "cpr" else "decode"} messages={inputs.size} positions={positions} ok"
  | "--audit-tracking" => auditTracking inputs geo
  | "--audit-inputs" =>
    for input in inputs do
      IO.println s!"{floatBits input.timestamp} {String.intercalate " " (input.bytes.map (fun byte => toString byte.toNat))}"
  | "--audit-airports" =>
    for airport in airports do
      IO.println s!"{airport.icao} {floatBits airport.position.lat} {floatBits airport.position.lon}"
  | _ => throw (IO.userError "unknown mode")

end Lean1090.Bench.WholeDecoder

def main (args : List String) : IO UInt32 := do
  match args with
  | [mode,path] =>
    Lean1090.Bench.WholeDecoder.execute mode path
    return 0
  | _ =>
    IO.eprintln "usage: lean1090-bench --worker-decode|--worker-cpr|--check|--audit-inputs|--audit-airports|--audit-tracking CORPUS.csv"
    return 2

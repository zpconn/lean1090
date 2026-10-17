import Impl
import Impl.JSON
import Lean.Data.Json.Parser
import Lean.Data.Json.Printer
import Lean.Data.Json.FromToJson.Basic

/- Stream CPR differential adapter. Actual Impl.decodePositions
is called once per whole stream, with the live numerical geography boundary. -/
set_option maxRecDepth 1000000
set_option maxHeartbeats 0
open Lean Lean1090
open Lean1090.Spec.CPR Lean1090.Spec.CPR.Policy

private def rational (bits : Nat) : Except String Rat :=
  match Impl.Binary64.fromBits (BitVec.ofNat 64 bits) with
  | some q => .ok q
  | none => .error "nonfinite input"
private def nat (j : Json) (key : String) : Except String Nat := j.getObjValAs? Nat key
private def str (j : Json) (key : String) : Except String String := j.getObjValAs? String key
private def pos (j : Json) : Except String (Option Position) := do
  if j == .null then return none
  let a ← j.getArr?
  if a.size != 2 then throw "coordinate pair expected"
  return some ⟨← rational (← a[0]!.getNat?), ← rational (← a[1]!.getNat?)⟩
private def positionJson (p : Option Position) : Json :=
  match p with
  | none => .null
  | some p => toJson [Impl.CPR.Policy.toFloat p.lat |>.toBits.toNat,
      Impl.CPR.Policy.toFloat p.lon |>.toBits.toNat]
private def nibble (c : Char) : Option Nat :=
  if '0' ≤ c && c ≤ '9' then some (c.toNat - 48)
  else if 'a' ≤ c && c ≤ 'f' then some (c.toNat - 87)
  else if 'A' ≤ c && c ≤ 'F' then some (c.toNat - 55) else none
private def hex : List Char → Option (List UInt8)
  | [] => some []
  | a::b::rest => do return ((← nibble a)*16+(← nibble b)).toUInt8 :: (← hex rest)
  | _ => none
private def report (time : Rat) (bytes : List UInt8) : Option TimedReport := do
  let first ← bytes.head?
  if first.toNat / 8 != 17 && first.toNat / 8 != 18 then none else do
  let m ← Impl.decode bytes
  let address ← m.decoded.address
  let r ← m.decoded.adsb
  let sem ← m.decoded.semanticADSB
  let raw := Impl.JSON.raw r
  let tc := raw "tc"
  let code : Encoded := ⟨raw "parity" == 1, raw "lat_cpr", raw "lon_cpr"⟩
  let message := if 5 ≤ tc && tc ≤ 8 then Message.surface code
    else if (9 ≤ tc && tc ≤ 18) || (20 ≤ tc && tc ≤ 22) then
      let altitude := (((sem.oracleValues.find? (·.1 == "altitude_feet")).map (·.2)).join).map Rat.floor
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
  return ⟨address.toNat, time, message⟩
private def update (mode : Nat) : UpdateReference := fun v =>
  mode == 1 || (mode == 2 && v.altitude.any (· < 1000)) ||
    (mode == 3 && v.metadata.timeSync && v.metadata.gnssSource)
private def finish (name : String) (mode : Nat) (reference : Option Position)
    (airports : List Airport) (rows : Array (Nat × Option TimedReport)) : IO Unit := do
  let reports := rows.toList.filterMap Prod.snd
  let (state, positions) := Impl.decodePositions (Impl.CPR.Policy.numericalGeography airports)
    (update mode) reference reports
  let mut remaining := positions
  for (id, r) in rows do
    let p := if r.isSome then remaining.head?.join else none
    if r.isSome then remaining := remaining.drop 1
    IO.println (Json.mkObj [("stream",toJson name),("id",toJson id),("position",positionJson p),
      ("routed",toJson r.isSome)]).compress
  unless remaining.isEmpty do throw (IO.userError "unconsumed positions")
  let aircraft := state.aircraft.mergeSort (fun a b => a.1 ≤ b.1)
  IO.println (Json.mkObj [("stream",toJson name),("final",.bool true),
    ("reference",positionJson state.reference),("aircraft",.arr (aircraft.map (fun (address,s) =>
      Json.mkObj [("address",toJson address),("position",positionJson s.position),
       ("altitude",toJson s.lastAltitude),("airport",toJson s.airport),
       ("seen",toJson s.seenBDS)])).toArray)]).compress

def main (args : List String) : IO Unit := do
  let some airportPath := args.head? | throw (IO.userError "airport JSONL required")
  let mut airports : List Airport := []
  for line in (← IO.FS.readFile airportPath).splitOn "\n" do
    if line.isEmpty then continue
    let j ← IO.ofExcept (Json.parse line)
    let name ← IO.ofExcept (str j "icao")
    let some p ← IO.ofExcept (pos (← IO.ofExcept (j.getObjVal? "position")))
      | throw (IO.userError "airport position absent")
    airports := ⟨name,p⟩ :: airports
  airports := airports.reverse
  let input ← IO.getStdin
  let mut name := ""
  let mut mode := 0
  let mut reference := none
  let mut rows := #[]
  repeat
    let line ← input.getLine
    if line.isEmpty then break
    let j ← IO.ofExcept (Json.parse line)
    let kind ← IO.ofExcept (str j "kind")
    if kind == "header" then
      if !name.isEmpty then finish name mode reference airports rows
      name ← IO.ofExcept (str j "stream")
      mode ← IO.ofExcept (nat j "update")
      reference ← IO.ofExcept (pos (← IO.ofExcept (j.getObjVal? "reference")))
      rows := #[]
    else
      let id ← IO.ofExcept (nat j "id")
      let time ← IO.ofExcept ((nat j "timestamp_bits") >>= rational)
      let data ← IO.ofExcept (str j "hex")
      let some bytes := hex data.toList | throw (IO.userError "invalid hex")
      rows := rows.push (id, report time bytes)
  if !name.isEmpty then finish name mode reference airports rows

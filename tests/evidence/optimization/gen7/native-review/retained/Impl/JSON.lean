import Impl.Message
import Impl.Numeric
import Lean.Data.Json.Basic

/-!
Output projection of the proved message record. Key spelling and omission
policies follow the pinned rs1090 serde implementations recorded in SCOPE.md.
The standard and oracle semantic views remain explicitly separate. This
module reads decoded fields and semantic operands; it never reparses bytes.
JSON and Float presentation are tested boundaries, not new inference rules.
-/

namespace Lean1090.Impl.JSON
open Lean Lean1090.Spec

abbrev Object := List (String × Json)

def integer (value : Int) : Json := .num ⟨value, 0⟩

/-- Exact finite binary64 decimal, avoiding Float.toString display rounding.
The generated decimal parses back to the original binary64. -/
def floating (value : Float) : Json :=
  match Binary64.fromBits value.toBits.toBitVec with
  | none => .null
  | some q =>
      let exponent := q.den.log2
      .num ⟨q.num * (5^exponent : Nat), exponent⟩

def rational (value : Rat) : Json :=
  if value.den == 1 then integer value.num else floating (CPR.Policy.toFloat value)

def digits (base width value : Nat) : String :=
  String.ofList ((List.range width).reverse.map fun i =>
    let digit := value / base^i % base
    Char.ofNat (if digit < 10 then 48+digit else 87+digit))

def raw (record : PayloadRecord) (key : String) : Nat :=
  ((record.fields.find? (fun field => field.name == key)).map (·.code)).getD 0

def value (oracle : Bool) (p : Semantics.Payload) (key : String) : Option Rat :=
  (((if oracle then p.oracleValues else p.standardValues).find? (fun kv => kv.1 == key)).map (·.2)).join

def label (oracle : Bool) (p : Semantics.Payload) (key : String) : Option String :=
  (((if oracle then p.oracleLabels else p.standardLabels).find? (fun kv => kv.1 == key)).map (·.2)).join

def optional (key : String) (entry : Option Json) (omitMissing : Bool := false) : Object :=
  match entry with
  | some entry => [(key, entry)]
  | none => if omitMissing then [] else [(key, .null)]

def numeric (oracle : Bool) (p : Semantics.Payload) : Object :=
  (if oracle then p.oracleFloats else p.standardFloats).flatMap fun field =>
    optional field.key (field.value.map (fun expression => floating (Numeric.eval expression)))
      (field.missing == .omit)

def number (oracle : Bool) (p : Semantics.Payload) (key : String)
    (rename : String := key) (omitMissing : Bool := false) : Object :=
  optional rename ((value oracle p key).map rational) omitMissing

def textField (oracle : Bool) (p : Semantics.Payload) (key : String)
    (rename : String := key) (omitMissing : Bool := false) : Object :=
  optional rename ((label oracle p key).map Json.str) omitMissing

def naturals (record : PayloadRecord) (keys : List String) : Object :=
  keys.map fun key => (key, integer (raw record key))

def booleans (record : PayloadRecord) (keys : List String) : Object :=
  keys.map fun key => (key, .bool (raw record key != 0))

def parity (record : PayloadRecord) : Object :=
  [("parity", .str (if raw record "parity" == 0 then "even" else "odd"))]

def operationStatus (record : PayloadRecord) : Object :=
  let subtype := raw record "subtype"
  let version := raw record "version"
  if subtype ≥ 2 then
    let data := raw record "reserved_status_data"
    [("id", integer subtype), ("status", Json.mkObj [("data", .arr (
      (List.range 5).map (fun i => integer (data / 256^(4-i) % 256))).toArray)])]
  else
    [("version", integer version)] ++
      (if version == 1 || version == 2 then
        naturals record ([if version == 1 then "NICs" else "NICa", "NACp"] ++
          (if subtype == 1 then [] else [if version == 1 then "BAQ" else "GVA"]) ++
          ["SIL", if subtype == 1 then "TAH" else "BAI", "HRD"] ++
          (if version == 2 then ["SILs"] else []))
       else [])

/-- Complete default ADS-B JSON field selection, applied to decoded data. -/
def adsb (oracle : Bool) (record : PayloadRecord) (p : Semantics.Payload) : Object :=
  let tc := raw record "tc"
  let st := raw record "subtype"
  if tc == 0 then [("bds", .str "NoPosition")]
  else if tc ≤ 4 then [("bds", .str "08")] ++
    textField oracle p "callsign" ++ textField oracle p "wake_vortex"
  else if tc ≤ 8 then [("bds", .str "06"), ("tc", integer tc)] ++
    number oracle p "NUCp" ++ numeric oracle p ++ parity record ++
    naturals record ["lat_cpr", "lon_cpr"]
  else if tc ≤ 18 || (20 ≤ tc && tc ≤ 22) then
    [("bds", .str "05"), ("tc", integer tc)] ++ number oracle p "NUCp" ++
    number oracle p "NICb" "NICb" true ++
    number oracle p (if !oracle && tc ≥ 20 then "height_metres" else "altitude_feet") "altitude" ++
    textField oracle p "source" ++ booleans record ["time_sync"] ++ parity record ++
    naturals record ["lat_cpr", "lon_cpr"]
  else if tc == 19 then [("bds", .str "09")] ++
    naturals record ["NACv"] ++
    (if st == 1 || st == 2 then numeric oracle p
     else if st == 3 || st == 4 then numeric oracle p ++
       number oracle p "airspeed" (if raw record "airspeed_type" == 0 then "IAS" else "TAS") true
     else if oracle then number true p "reserved_data"
     else naturals record ["reserved_data"]) ++
    textField oracle p "vrate_src" ++ number oracle p "vertical_rate" "vertical_rate" true ++
    number oracle p "geo_minus_baro"
  else if tc == 28 then [("bds", .str "61")] ++
    textField oracle p "subtype" ++ textField oracle p "emergency_state" ++
    optional "squawk" ((value oracle p "squawk").map (fun q => .str (digits 8 4 q.num.toNat)))
  else if tc == 29 then [("bds", .str "62")] ++ textField oracle p "source" ++
    number oracle p "selected_altitude" "selected_altitude" true ++ numeric oracle p ++
    naturals record ["NACp"] ++ booleans record ["nic_baro", "tcas_operational"] ++
    (if raw record "mode_status" == 0 then [] else
      booleans record ["autopilot", "vnav_mode", "alt_hold", "approach_mode", "lnav_mode"])
  else if tc == 31 then [("bds", .str "65")] ++ operationStatus record
  else if 25 ≤ tc && tc ≤ 27 then
    [("bds", .str "id25_27"), ("_id", integer tc)] ++ naturals record ["unused"]
  else [("bds", .str ("id" ++ toString tc))]

def oracleThreat (p : Semantics.Payload) : Object :=
  match p.oracleThreat with
  | some (.address address) => [("threat_identity", .str (digits 16 6 address))]
  | some (.orientation altitude _ bearing) =>
    optional "threat_altitude" (altitude.map integer) ++ numeric true p ++
    optional "threat_bearing" (bearing.map (fun n => integer n))
  | _ => []

/-- Preserve the standard range bounds/sectors instead of turning saturation
or reserved codes into the oracle's invented exact scalar. -/
def standardThreat (p : Semantics.Payload) : Object :=
  match p.standardThreat with
  | some (.address address) => [("threat_identity", .str (digits 16 6 address))]
  | some (.orientation altitude range bearing) =>
    optional "threat_altitude" (altitude.map integer) ++
    [("threat_range", match range with
      | .unavailable => .null
      | .lessThan upper => Json.mkObj [("less_than", rational upper)]
      | .estimate centre tolerance => Json.mkObj [("estimate", rational centre), ("tolerance", rational tolerance)]
      | .greaterThan lower => Json.mkObj [("greater_than", rational lower)]),
     ("threat_bearing", match bearing with
      | .unavailable => .null
      | .unassigned code => Json.mkObj [("unassigned", integer code)]
      | .sector lower upper => Json.mkObj [("lower", integer lower), ("upper", integer upper)])]
  | _ => []

def commB (oracle : Bool) (register : Nat) (record : PayloadRecord)
    (p : Semantics.Payload) : Object :=
  let tag : Object := [("bds", .str (digits 16 2 register))]
  if register == 0x05 then
    -- The direct BDS05 struct has no enclosing ME discriminant/tag.
    (adsb oracle record p).filter (fun kv => kv.1 != "bds" && kv.1 != "tc")
  else if register == 0x65 then operationStatus record
  else tag ++
    (if register == 0x10 then
      booleans record ["config", "ovc", "acas", "level5", "mode_s", "identification",
        "squitter", "sic", "gicb", "acas_hybrid", "acas_ra"] ++ naturals record ["subnet"] ++
        number oracle p "dte"
     else if register == 0x17 || register == 0x18 || register == 0x19 then
      record.fields.filterMap fun field =>
        if field.name.startsWith "bds" && field.code != 0 then some (field.name, .bool true) else none
     else if register == 0x20 then textField oracle p "callsign"
     else if register == 0x21 then textField oracle p "registration" ++ textField oracle p "airline" "airline" true
     else if register == 0x30 then
      booleans record ["issued_ra", "terminated", "multiple"] ++
      (if raw record "issued_ra" == 0 then [] else
        booleans record ["corrective", "downward_sense", "increased_rate", "sense_reversal",
          "altitude_crossing", "positive", "no_below", "no_above", "no_left", "no_right"]) ++
      (if oracle then oracleThreat p else standardThreat p)
     else if register == 0x40 then
      number oracle p "selected_mcp" "selected_mcp" true ++
      number oracle p "selected_fms" "selected_fms" true ++ numeric oracle p ++
      (if raw record "target_altitude_source" == 0 then [] else
        textField oracle p "target_altitude_source" "target_source")
     else if register == 0x44 then
      textField oracle p "figure_of_merit" ++ textField oracle p "turbulence" ++
      number oracle p "wind_speed" ++ number oracle p "pressure" ++ numeric oracle p
     else if register == 0x45 then
      ["turbulence", "wind_shear", "microburst", "icing", "wake_vortex"].flatMap
        (textField oracle p) ++ number oracle p "static_pressure" ++
        number oracle p "radio_height" ++ numeric oracle p
     else if register == 0x50 then
      numeric oracle p ++ number oracle p "groundspeed" ++ number oracle p "TAS"
     else if register == 0x60 then
      numeric oracle p ++ number oracle p "IAS" "IAS" true ++
      number oracle p "vrate_barometric" "vrate_barometric" true ++
      number oracle p "vrate_inertial" "vrate_inertial" true
     else [])

def altitude (oracle : Bool) (message : Message) : Object :=
  if oracle then optional "altitude" ((frameOracleAltitude message.fields).map integer)
  else optional "altitude" (message.decoded.altitude.map fun a =>
    match a with | .feet n => integer n | .metres n => integer n)

def identity (message : Message) : Object :=
  optional "squawk" (message.decoded.identity.map (fun n => .str (digits 8 4 n)))

def message (oracle : Bool) (m : Message) : Json :=
  let address := optional "icao24" (m.decoded.address.map (fun n => .str (digits 16 6 n.toNat))) true
  let body : Object := match m.fields.body with
    | .shortACAS _ => [("df", .str "0")] ++ altitude oracle m
    | .surveillance isIdentity _ => [("df", .str (if isIdentity then "5" else "4"))] ++
      (if isIdentity then identity m else altitude oracle m)
    | .allCall capability _ => [("df", .str "11"), ("capability", .str (
        ["level1", "AG_RESERVED", "AG_RESERVED", "AG_RESERVED", "ground", "airborne",
          "ground/airborne", "AG_DR0"].getD capability.toNat "AG_RESERVED"))]
    | .longACAS fields _ => [("df", .str "16"), ("vs", integer fields.vs.toNat),
        ("sl", integer fields.sl.toNat), ("ri", integer fields.ri.toNat)] ++ altitude oracle m
    | .extended supplementary control _ _ =>
      [("df", .str (if supplementary then "18" else "17"))] ++
      (if supplementary then [("tisb", .str (["ADSB_ES_NT", "ADSB_ES_NT_ALT", "TISB_FINE",
          "TISB_COARSE", "TISB_MANAGE", "TISB_ADSB_RELAY", "TISB_ADSB", "Reserved"].getD
            control.toNat "Reserved"))] else []) ++
      (match m.decoded.adsb, m.decoded.semanticADSB with
       | some fields, some semantic => adsb oracle fields semantic
       | _, _ => [])
    | .military af _ => [("df", .str "ExtendedSquitterMilitary"), ("af", integer af.toNat)]
    | .commB isIdentity _ _ =>
      [("df", .str (if isIdentity then "21" else "20"))] ++
      (if isIdentity then identity m else altitude oracle m) ++
      m.decoded.commB.filterMap fun (register, fields) =>
        (m.decoded.semanticCommB.find? (fun kv => kv.1 == register)).map fun (_, semantic) =>
          ("bds" ++ digits 16 2 register, Json.mkObj (commB oracle register fields semantic))
    | .commD spare _ nd md => [("df", .str "CommDExtended"), ("spare", integer spare.toNat),
      ("nd", integer nd.toNat), ("md", .arr ((List.range 10).map fun i =>
        integer (md.toNat / 256^(9-i) % 256)).toArray),
      ("parity", .str (digits 16 6 m.fields.parity.toNat))]
  Json.mkObj (address ++ body)

end Lean1090.Impl.JSON

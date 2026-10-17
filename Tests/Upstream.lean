import Impl.JSON
import Impl.CPRPolicy
import Lean.Data.Json.Parser
import Lean.Data.Json.Printer

/-! Upstream assertion runner. Expectations come from source-indexed fixtures,
not the decoder. Decoder assertions use live Impl paths. The M-bit upstream
unit test also contains a local arithmetic closure; its original formula checks
are retained explicitly alongside separate live decoder checks (some closure
inputs set M and Q and are rejected by the actual decoder). -/
open Lean Lean1090
namespace Lean1090.Tests.Upstream

def field (j : Json) (key : String) : Json := (j.getObjVal? key).toOption.getD .null
def string (j : Json) : String := j.getStr?.toOption.getD ""
def number (j : Json) : Float := (j.getNum?.toOption.map (·.toFloat)).getD (0/0)
def array (j : Json) : Array Json := j.getArr?.toOption.getD #[]
def nat (j : Json) : Nat := j.getNat?.toOption.getD 0
def rational (j : Json) : Rat :=
  (Impl.Binary64.fromBits (number j).toBits.toBitVec).getD 0

def nibble (c : Char) : Option Nat :=
  if '0' ≤ c && c ≤ '9' then some (c.toNat - 48)
  else if 'a' ≤ c && c ≤ 'f' then some (c.toNat - 87)
  else if 'A' ≤ c && c ≤ 'F' then some (c.toNat - 55) else none

def hexBytes : List Char → Option (List UInt8)
  | [] => some []
  | a :: b :: rest => do
    let hi ← nibble a; let lo ← nibble b; let tail ← hexBytes rest
    return (16*hi+lo).toUInt8 :: tail
  | _ => none

def bytes (j : Json) : List UInt8 := (hexBytes (string j).toList).getD []
def word (bs : List UInt8) : Nat := bs.foldl (fun n b => n*256+b.toNat) 0

def objectRaw (r : Spec.PayloadRecord) : Json :=
  Json.mkObj (r.fields.map fun f => (f.name, Impl.JSON.integer f.code))
def position (p : Option Spec.CPR.Position) : Json := match p with
  | none => .null
  | some p => Json.mkObj [("latitude",Impl.JSON.rational p.lat),("longitude",Impl.JSON.rational p.lon)]

def code (bs : List UInt8) : Spec.CPR.Encoded :=
  let w := word (bs.drop 4 |>.take 7)
  ⟨(w / 2^34 % 2 == 1), w / 2^17 % 2^17, w % 2^17⟩

def report (item : Json) : Option Spec.CPR.Policy.TimedReport := do
  let bs := bytes (field item "hex")
  let m ← Impl.decode bs
  let r ← m.decoded.adsb
  let a ← m.decoded.address
  let tc := Impl.JSON.raw r "tc"
  let message := if 5 ≤ tc && tc ≤ 8 then Spec.CPR.Policy.Message.surface (code bs)
    else if (9 ≤ tc && tc ≤ 18) || (20 ≤ tc && tc ≤ 22) then
      Spec.CPR.Policy.Message.airborne (code bs)
        ((m.decoded.semanticADSB.bind fun p => Impl.JSON.value true p "altitude_feet").map (·.num)) {}
    else Spec.CPR.Policy.Message.other .reserved
  return ⟨a.toNat, rational (field item "timestamp"), message⟩

def streamObservation (j : Json) : Json := Id.run do
  let reports := (array (field j "messages")).toList.filterMap report
  let split := nat (field j "split")
  let geo := Impl.CPR.Policy.numericalGeography []
  let (state, positions) := Impl.decodePositions geo (fun _ => false) none reports
  let (before, beforePositions) := Impl.decodePositions geo (fun _ => false) none (reports.take split)
  let final := state.aircraft.head?.bind (·.2.position)
  let initial := before.aircraft.head?.bind (·.2.position)
  let delta := do
    let a ← initial; let b ← final
    return Impl.CPR.Policy.haversineFloat a b
  let lonDelta := do
    let a ← initial; let b ← final
    return (Impl.CPR.Policy.toFloat a.lon - Impl.CPR.Policy.toFloat b.lon).abs
  return Json.mkObj [("final",position final),("before",position initial),
    ("distance",delta.map Impl.JSON.floating |>.getD .null),
    ("longitude_change",lonDelta.map Impl.JSON.floating |>.getD .null),
    ("before_count",Impl.JSON.integer (beforePositions.filter Option.isSome).length),
    ("after_count",Impl.JSON.integer ((positions.drop split).filter Option.isSome).length),
    ("decoded_count",Impl.JSON.integer reports.length)]

def observe (j : Json) : Json := Id.run do
  let bs := bytes (field j "hex")
  let op := string (field j "op")
  if op == "stream" then return streamObservation j
  if op == "altitude-details" then
    let c := nat (field j "code")
    let metres := match Impl.Altitude.decodeAC13 c with
      | some (.metres n) => some n | _ => none
    return Json.mkObj [("standard_metres",metres.map (fun n => Impl.JSON.integer n) |>.getD .null),
      ("metres",Impl.JSON.integer (((c &&& 0x1f80) / 4) ||| (c &&& 0x3f))),
      ("formula_feet",Impl.JSON.integer (((((c &&& 0x1f80) / 4) ||| (c &&& 0x3f))*328084/100000 : Nat))),
      ("feet", (Impl.Altitude.oracleAC13 c).map Impl.JSON.integer |>.getD .null),
      ("m_bit",Impl.JSON.integer (Impl.Altitude.bit c 6)),
      ("q_bit",Impl.JSON.integer (Impl.Altitude.bit c 4)),
      ("n",Impl.JSON.integer (c / 32 * 16 + c % 16)),
      ("ac12", (Impl.Altitude.decodeAC12 c).map Impl.JSON.integer |>.getD .null)]
  if op == "density" then
    let terms := (array (field j "terms")).map fun term =>
      let a := rational (field term "value")
      let b := rational (field term "center")
      let c := rational (field term "scale")
      if string (field term "kind") == "gauss" then Impl.cbGaussian a b c else Impl.cbLaplace a b c
    let sum := terms.foldl Impl.Binary64.add 0
    return Impl.JSON.rational (Impl.Binary64.div sum terms.size)
  if op == "penalty" then
    let w := word (if bs.length == 7 then bs else bs.drop 4 |>.take 7)
    return Impl.JSON.rational (Impl.cbPenalty (nat (field j "register")) w)
  if op == "adsb-word" then
    let w := word bs
    return match (Impl.decodeADSB w).toOption with
      | none => .null
      | some r => Json.mkObj (("_raw",objectRaw r) :: Impl.JSON.adsb true r (Impl.Semantics.adsb w))
  if op == "crc" then return Impl.JSON.integer (Impl.Parity.syndrome (bs.length*8) (word bs)).toNat
  if op == "ac12" then return (Impl.Altitude.decodeAC12 (nat (field j "code"))).map Impl.JSON.integer |>.getD .null
  if op == "ac13" then return (Impl.Altitude.oracleAC13 (nat (field j "code"))).map Impl.JSON.integer |>.getD .null
  if op == "register" then
    let reg := nat (field j "register")
    let w := if bs.length == 7 then word bs else word (bs.drop 4 |>.take 7)
    return match Impl.decodeBDS reg w with
      | none => .null
      | some r => Json.mkObj (("_raw",objectRaw r) :: Impl.JSON.commB true reg r (Impl.Semantics.commB reg w))
  if op == "local" then
    let ref := field j "reference"
    let p := Spec.CPR.Position.mk (rational (field ref "latitude")) (rational (field ref "longitude"))
    return position (Impl.CPR.Policy.decodeLocalFloat
      (if field j "surface" == .bool true then .surface else .airborne) (code bs) p)
  if op == "global" then
    let a := code bs; let b := code (bytes (field j "other"))
    return position (if a.odd then Impl.CPR.Policy.decodeGlobalFloat b a b.odd
      else Impl.CPR.Policy.decodeGlobalFloat a b b.odd)
  if op == "frame" then
    return match Impl.decodePrefix bs with
    | none => .null
    | some (m, _) =>
      let base := (Impl.JSON.message true m).getObj?.toOption.map (·.toList) |>.getD []
      let raw := m.decoded.adsb.map objectRaw |>.getD .null
      let commb := Json.mkObj (m.decoded.commB.map fun (r,v) => ("bds"++Impl.JSON.digits 16 2 r,objectRaw v))
      Json.mkObj (("_raw",raw)::("_commb_raw",commb)::("_capability",
        match m.fields.body with | .extended _ c _ _ => Impl.JSON.integer c.toNat | _ => .null)::base)
  return .null

def lookup (observations : Array Json) (arg : Json) : Except String Json := do
  let id ← (← arg.getObjVal? "observation").getNat?
  let some root := observations[id]? | throw "invalid observation index"
  let path ← (← arg.getObjVal? "path").getArr?
  let allowMissing := field arg "allow_missing" == .bool true
  let mut current := root
  for h : i in [:path.size] do
    let key ← path[i].getStr?
    let _ ← current.getObj?
    match current.getObjVal? key with
    | .ok value => current := value
    | .error error =>
      if allowMissing && i+1 == path.size then current := .null else throw error
  return current

def numericValue (j : Json) : Except String Float := do
  let n ← j.getNum?
  let value := n.toFloat
  if value.isNaN || value.isInf then throw "nonfinite fixture numeric value"
  return value

def equal (a b : Json) : Except String Bool := do
  match a,b with
  | .num x, .num y =>
    if x.exponent == 0 && y.exponent == 0 then return x.mantissa == y.mantissa
    return (← numericValue a) == (← numericValue b)
  | _,_ => return a == b

def evaluate : Nat → Array Json → Json → Except String Json
  | 0, _, _ => throw "fixture expression depth limit exceeded"
  | fuel+1, obs, arg => do
    let op ← (← arg.getObjVal? "op").getStr?
    if op == "literal" then return ← arg.getObjVal? "value"
    if op == "get" then return ← lookup obs arg
    let children ← (← arg.getObjVal? "args").getArr?
    let ev := evaluate fuel obs
    if op == "and" || op == "or" then
      if children.isEmpty then throw "empty conjunction/disjunction"
      for child in children do
        let value ← (← ev child).getBool?
        if op == "and" && !value then return .bool false
        if op == "or" && value then return .bool true
      return .bool (op == "and")
    let some child := children[0]? | throw "missing assertion argument"
    let a ← ev child
    if op == "null" then return .bool (a == .null)
    if op == "present" then return .bool (a != .null)
    if op == "neg" then return Impl.JSON.floating (-(← numericValue a))
    if op == "not" then return .bool (!(← a.getBool?))
    let some child := children[1]? | throw "missing second assertion argument"
    let b ← ev child
    if op == "eq" then return .bool (← equal a b)
    if op == "ne" then return .bool (!(← equal a b))
    let x ← numericValue a; let y ← numericValue b
    if op == "lt" then return .bool (x < y)
    if op == "le" then return .bool (x ≤ y)
    if op == "gt" then return .bool (x > y)
    if op == "ge" then return .bool (x ≥ y)
    if op == "approx" then
      let rel ← numericValue (← arg.getObjVal? "relative")
      let absolute ← numericValue (← arg.getObjVal? "absolute")
      if rel < 0 || absolute < 0 then throw "negative tolerance"
      let scale := if field arg "symmetric" == .bool true then max x.abs y.abs else y.abs
      let tolerance := max absolute (rel*scale)
      return .bool (if field arg "strict" == .bool true then (x-y).abs < tolerance else (x-y).abs ≤ tolerance)
    throw ("unknown assertion operation: " ++ op)

def validateObservation (j : Json) : Except String Unit := do
  let op ← (← j.getObjVal? "op").getStr?
  let h ← (← j.getObjVal? "hex").getStr?
  let some _ := hexBytes h.toList | throw "malformed hex input"
  if !["crc","ac12","ac13","altitude-details","register","local","global","frame",
       "stream","density","penalty","adsb-word"].contains op then
    throw ("unknown observation operation: " ++ op)
  if ["ac12","ac13","altitude-details"].contains op then
    let _ ← (← j.getObjVal? "code").getNat?
  if ["register","penalty"].contains op then
    let _ ← (← j.getObjVal? "register").getNat?
  if op == "local" then
    let p ← j.getObjVal? "reference"
    let _ ← numericValue (← p.getObjVal? "latitude")
    let _ ← numericValue (← p.getObjVal? "longitude")
    let _ ← (← j.getObjVal? "surface").getBool?
  if op == "global" then
    let h ← (← j.getObjVal? "other").getStr?
    let some _ := hexBytes h.toList | throw "malformed global partner hex"
  if op == "stream" then
    let _ ← (← j.getObjVal? "split").getNat?
    let ms ← (← j.getObjVal? "messages").getArr?
    for m in ms do
      let h ← (← m.getObjVal? "hex").getStr?
      let some _ := hexBytes h.toList | throw "malformed stream hex"
      let _ ← numericValue (← m.getObjVal? "timestamp")
  if op == "density" then
    let terms ← (← j.getObjVal? "terms").getArr?
    if terms.isEmpty then throw "empty density fixture"
    for t in terms do
      let kind ← (← t.getObjVal? "kind").getStr?
      if kind != "gauss" && kind != "laplace" then throw "unknown density term"
      for key in ["value","center","scale"] do
        let _ ← numericValue (← t.getObjVal? key)
  return ()

-- Invalid fixture shapes abort explicitly; valid fixtures accumulate every assertion failure.
def run (path : String) : IO UInt32 := do
  let input ← IO.FS.lines path
  let mut total := 0; let mut failed := 0
  for line in input do
    let fixture ← match Json.parse line with
      | .ok v => pure v | .error e => throw (IO.userError e)
    let observationsInput ← match (fixture.getObjVal? "observations").bind Json.getArr? with
      | .ok xs => pure xs | .error e => throw (IO.userError e)
    for j in observationsInput do
      match validateObservation j with
      | .ok _ => pure () | .error e => throw (IO.userError e)
    let observations := observationsInput.map observe
    let assertions ← match (fixture.getObjVal? "assertions").bind Json.getArr? with
      | .ok xs => pure xs | .error e => throw (IO.userError e)
    for assertion in assertions do
      total := total+1
      let expression := field assertion "expression"
      let result := evaluate 50 observations expression
      let ok := match result with | .ok j => j == .bool true | .error _ => false
      unless ok do failed := failed+1
      IO.println (Json.mkObj [("test",field fixture "id"),("source_line",field assertion "line"),
        ("passed",.bool ok),("evaluation", match result with | .ok j => j | .error e => .str e),("expression",expression),
        ("observations",.arr observations)]).compress
  IO.eprintln s!"Upstream Lean assertions: {total}, failures: {failed}"
  return if failed == 0 then 0 else 1
end Lean1090.Tests.Upstream

def main (args : List String) : IO UInt32 := match args with
  | [path] => Lean1090.Tests.Upstream.run path
  | _ => throw (IO.userError "usage: upstream-units FIXTURES.jsonl")

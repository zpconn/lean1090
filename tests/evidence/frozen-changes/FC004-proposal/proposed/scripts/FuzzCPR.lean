import Spec.CPRFloat
import Spec.CPRContracts
import Impl.CPRFloat

/-!
Synthetic CPR differential adapter. All codes come from the actual frozen
`Spec.CPR.encode`; tested outputs come from the proved runtime decoders and
must equal the frozen reference on every case before oracle comparison.
Input coordinates are exact rational numerator/denominator pairs. This is test
tooling, not implementation code or a proof of the Float boundary.

The explicitly named counterfactual functions below differ from the frozen
Float adapters only by removing the documented NL(±87)=2 correction. They are
used solely to require an exact, narrow explanation for D009 differences.
-/

open Lean1090.Spec Lean1090.Spec.CPR Lean1090.Spec.CPR.Policy

private def oracleNLFloat (latitude : Float) : Nat :=
  59 - (transitions.takeWhile (fun t =>
    t.toUInt64.toFloat / 100000000 ≤ latitude.abs)).length

private def localCounterfactual (mode : Medium) (code : Encoded)
    (reference : Position) : Option Position :=
  if code.lat ≥ scale || code.lon ≥ scale then none else
  let width : Float := match mode with | .airborne => 360 | .surface => 90
  let y := code.lat.toUInt64.toFloat / 131072
  let x := code.lon.toUInt64.toFloat / 131072
  let dlat := width / (if code.odd then 59 else 60)
  let refLat := toFloat reference.lat
  let refLon := toFloat reference.lon
  let j := (0.5 + refLat / dlat - y).floor
  let lat := dlat * (j + y)
  if !(lat ≥ -90 && lat ≤ 90) || (lat - refLat).abs > dlat / 2 then none else
  let ni := oracleNLFloat lat - parity code.odd
  let dlon := if ni > 0 then width / ni.toUInt64.toFloat else width
  let m := (0.5 + refLon / dlon - x).floor
  let lon := dlon * (m + x)
  if (lon - refLon).abs > dlon / 2 then none else positionFromFloats lat lon

private def globalCounterfactual (even odd : Encoded) (latestOdd : Bool) : Option Position :=
  if even.odd || !odd.odd || even.lat ≥ scale || even.lon ≥ scale ||
      odd.lat ≥ scale || odd.lon ≥ scale then none else
  let y0 := even.lat.toUInt64.toFloat / 131072
  let y1 := odd.lat.toUInt64.toFloat / 131072
  let x0 := even.lon.toUInt64.toFloat / 131072
  let x1 := odd.lon.toUInt64.toFloat / 131072
  let j := (59 * y0 - 60 * y1 + 0.5).floor
  let l0 := (360 / 60 : Float) * (moduloFloat j 60 + y0)
  let l1 := (360 / 59 : Float) * (moduloFloat j 59 + y1)
  let l0 := if l0 ≥ 270 then l0 - 360 else l0
  let l1 := if l1 ≥ 270 then l1 - 360 else l1
  if !(l0 ≥ -90 && l0 ≤ 90 && l1 ≥ -90 && l1 ≤ 90) ||
      oracleNLFloat l0 != oracleNLFloat l1 then none
  else
    let lat := if latestOdd then l1 else l0
    let n := oracleNLFloat lat
    let ni := (max (n - parity latestOdd) 1).toUInt64.toFloat
    let m := (x0 * (n - 1).toUInt64.toFloat - x1 * n.toUInt64.toFloat + 0.5).floor
    let lon := (360 / ni) * (moduloFloat m ni + if latestOdd then x1 else x0)
    let lon := if lon ≥ 180 then lon - 360 else lon
    positionFromFloats lat lon

private def fields (position : Option Position) : List String :=
  match position with
  | none => ["0", "0", "0"]
  | some p => ["1", toString (toFloat p.lat).toBits.toNat,
    toString (toFloat p.lon).toBits.toNat]

private def rational (n d : Int) : Except String Rat :=
  if d ≤ 0 then .error "denominator must be positive" else .ok ((n : Rat) / (d : Rat))

private def evaluates (columns : List Int) : Except String String := do
  match columns with
  | [id, kind, surface, odd, latest, pn, pd, qn, qd, rn, rd, sn, sd, tn, td, un, ud] =>
    if id < 0 || kind < 0 || kind > 2 || surface < 0 || surface > 1 ||
        odd < 0 || odd > 1 || latest < 0 || latest > 1 then throw "invalid selectors"
    let p : Position := ⟨← rational pn pd, ← rational qn qd⟩
    let q : Position := ⟨← rational rn rd, ← rational sn sd⟩
    let reference : Position := ⟨← rational tn td, ← rational un ud⟩
    let mode : Medium := if surface == 1 then .surface else .airborne
    let isOdd := odd == 1
    let latestOdd := latest == 1
    let even := encode mode false p
    let other := encode mode (kind != 2) q
    let code := encode mode isOdd p
    let answer := if kind == 0 then Lean1090.Impl.CPR.Policy.decodeLocalFloat mode code reference
      else Lean1090.Impl.CPR.Policy.decodeGlobalFloat even other latestOdd
    let specAnswer := if kind == 0 then decodeLocalFloat mode code reference
      else decodeGlobalFloat even other latestOdd
    if answer != specAnswer then throw "runtime/reference Float refinement mismatch"
    let counterfactual := if kind == 0 then localCounterfactual mode code reference
      else globalCounterfactual even other latestOdd
    let exact := if kind == 0 then Lean1090.Impl.CPR.decodeLocal mode code reference
      else Lean1090.Impl.CPR.decodeGlobal even other latestOdd
    let specExact := if kind == 0 then decodeLocal mode code reference
      else decodeGlobal even other latestOdd
    if exact != specExact then throw "runtime/reference exact refinement mismatch"
    let admissible := if kind == 0 then decide (LocalAdmissible mode isOdd p reference)
      else decide (GlobalAdmissible p q)
    let within := match exact with
      | none => false
      | some position =>
        if kind == 0 then
          @decide (WithinResolution mode isOdd p position)
            (by unfold WithinResolution; infer_instance)
        else
          @decide (WithinResolution .airborne latestOdd
            (if latestOdd then q else p) position)
            (by unfold WithinResolution; infer_instance)
    let used := if kind == 0 then code else even
    let (l0, l1) := globalLatitudes even other
    let localLat := localLatitude mode code reference
    -- This flag is necessary, never sufficient, for the D009 exception.
    let boundary := if kind == 0 then
        let width : Float := if surface == 1 then 90 else 360
        let dlat := width / (if isOdd then 59 else 60)
        let y := code.lat.toUInt64.toFloat / 131072
        (dlat * ((0.5 + toFloat reference.lat / dlat - y).floor + y)).abs == 87
      else (toFloat l0).abs == 87 || (toFloat l1).abs == 87
    pure (String.intercalate "," ([toString id, toString kind, toString surface,
      toString odd, toString latest, toString used.lat, toString used.lon,
      toString other.lat, toString other.lon,
      toString (toFloat reference.lat).toBits.toNat,
      toString (toFloat reference.lon).toBits.toNat] ++ fields answer ++
      fields counterfactual ++ fields exact ++
      [if admissible then "1" else "0", if boundary then "1" else "0",
       toString (nlTable (if kind == 0 then localLat else l0)), toString (nlTable l1),
       if within then "1" else "0"]))
  | _ => throw "expected 17 columns"

def main (arguments : List String) : IO Unit := do
  let [input, output] := arguments
    | throw (IO.userError "usage: FuzzCPR.lean INPUT.csv OUTPUT.csv")
  let source ← IO.FS.readFile input
  let writer ← IO.FS.Handle.mk output .write
  writer.putStrLn "id,kind,surface,odd,latest,e_lat,e_lon,o_lat,o_lon,ref_lat_bits,ref_lon_bits,accepted,lat_bits,lon_bits,counterfactual_accepted,counterfactual_lat_bits,counterfactual_lon_bits,exact_accepted,exact_lat_bits,exact_lon_bits,admissible,boundary87,nl0,nl1,within_resolution"
  let mut count := 0
  for line in (source.splitOn "\n").drop 1 do
    if line.isEmpty then continue
    let parsed := (line.splitOn ",").mapM fun value =>
      match value.toInt? with
      | some number => Except.ok number
      | none => Except.error s!"invalid integer: {value}"
    match parsed >>= evaluates with
    | .error reason => throw (IO.userError s!"case {count}: {reason}")
    | .ok result => writer.putStrLn result
    count := count + 1
  IO.println s!"Encoded {count} synthetic CPR cases; runtime/reference exact and Float outputs agree."

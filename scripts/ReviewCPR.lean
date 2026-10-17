import Spec.CPRContracts
import Spec.Binary64

/-!
Review-only corpus evaluation of the actual frozen admissibility predicates.
No changes to their definitions, no numerical approximation of their decisions.

Input is an unquoted CSV of naturals with the columns:
kind,id,surface,odd,pLatBits,pLonBits,qLatBits,qLonBits,pLatCode,pLonCode,qLatCode,qLonCode
kind=0: LocalAdmissible p q; q is the prior reference.
kind=1: GlobalAdmissible p q; p is even and q is odd.
IEEE binary64 bits are interpreted exactly by Spec.Binary64.fromBits.
The code columns check whether these surrogate true positions re-encode to
the transmitted fields; q's code columns are unused for local cases.

Run: lake env lean --run scripts/ReviewCPR.lean INPUT.csv OUTPUT.csv
-/

open Lean1090.Spec Lean1090.Spec.CPR

private def finite (bits : Nat) : Except String Rat := do
  if bits ≥ 2^64 then throw "binary64 word exceeds 64 bits"
  match Binary64.fromBits (BitVec.ofNat 64 bits) with
  | some value => pure value
  | none => throw "non-finite binary64 position"

private def flag (condition : Bool) : String := if condition then "1" else "0"

private def evaluates (columns : List Nat) : Except String String := do
  match columns with
  | [kind, id, surface, odd, a, b, c, d, pLat, pLon, qLat, qLon] =>
    if kind > 1 || surface > 1 || odd > 1 then throw "invalid case selector"
    let p : Position := ⟨← finite a, ← finite b⟩
    let q : Position := ⟨← finite c, ← finite d⟩
    let mode : Medium := if surface == 1 then .surface else .airborne
    let parity := odd == 1
    let validP := @decide (ValidPosition p) (by unfold ValidPosition; infer_instance)
    let validQ := @decide (ValidPosition q) (by unfold ValidPosition; infer_instance)
    if kind == 0 then
      let latitude := decide
        (absQ (q.lat - roundedLatitude mode parity p.lat) < dLat mode parity / 2)
      let longitude := decide
        (longitudeDistance q.lon (roundedLongitude mode parity p) <
          dLon mode parity (roundedLatitude mode parity p.lat) / 2)
      let admitted := decide (LocalAdmissible mode parity p q)
      if admitted != (validP && validQ && latitude && longitude) then
        throw "local component diagnostics disagree with predicate"
      let encoded := encode mode parity p
      let reencodes := encoded.lat == pLat && encoded.lon == pLon
      pure (String.intercalate "," [toString kind, toString id, flag admitted,
        flag validP, flag validQ, flag latitude, "", flag longitude, flag reencodes, ""])
    else
      if surface != 0 then throw "global surface case is out of scope"
      let r0 := roundedLatitude .airborne false p.lat
      let r1 := roundedLatitude .airborne true q.lat
      let n := nlTable r0
      let latitude := decide (absQ (r0 - r1) < 3 / 59)
      let sameZone := decide (nlTable r0 = nlTable r1)
      let longitude := decide (n = 1 ∨ longitudeDistance
        (roundedLongitude .airborne false p) (roundedLongitude .airborne true q) <
          180 / ((n * (n - 1) : Nat) : Rat))
      let admitted := decide (GlobalAdmissible p q)
      if admitted != (validP && validQ && latitude && sameZone && longitude) then
        throw "global component diagnostics disagree with predicate"
      let even := encode .airborne false p
      let odd := encode .airborne true q
      pure (String.intercalate "," [toString kind, toString id, flag admitted,
        flag validP, flag validQ, flag latitude, flag sameZone, flag longitude,
        flag (even.lat == pLat && even.lon == pLon),
        flag (odd.lat == qLat && odd.lon == qLon)])
  | _ => throw "expected exactly 12 CSV columns"

def main (arguments : List String) : IO Unit := do
  let [input, output] := arguments
    | throw (IO.userError "usage: ReviewCPR.lean INPUT.csv OUTPUT.csv")
  let source ← IO.FS.readFile input
  let mut results := ["kind,id,admissible,valid_p,valid_q,latitude,zone,longitude,reencodes_p,reencodes_q"]
  let mut count := 0
  for line in (source.splitOn "\n").drop 1 do
    if line.isEmpty then continue
    let parsed := (line.splitOn ",").mapM fun value =>
      match value.toNat? with
      | some number => Except.ok number
      | none => Except.error s!"invalid natural: {value}"
    match parsed >>= evaluates with
    | .error reason => throw (IO.userError s!"case line {count + 2}: {reason}")
    | .ok result =>
      results := result :: results
      count := count + 1
  -- Header was inserted first and the results prepended, so reverse once.
  IO.FS.writeFile output (String.intercalate "\n" results.reverse ++ "\n")
  IO.println s!"Evaluated {count} cases using the frozen Lean CPR predicates."

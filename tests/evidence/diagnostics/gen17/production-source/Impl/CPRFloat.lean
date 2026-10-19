import Impl.CPRPolicy

/-!
# Runtime numerical boundary for CPR policy

This initial implementation preserves the tested frozen numerical algorithms.
Impl imports only Model and other Impl modules.

rs1090-derived formulas from commit685dfaa cpr.rs `haversine`. This file is
explicitly outside the mathematical CPR accuracy proofs. Standard library
Float sin/cos/atan2 and IEEE rounding are checked by differential tests, not
claimed correct by the CPR capstones. Exact bit interpretation stays in
Binary64 and the pure state transition consumes explicit Distance values.
-/

namespace Lean1090.Impl.CPR.Policy
open Lean1090.Spec.CPR Lean1090.Spec.CPR.Policy

/-- Rust f64 finite representation: round an exact rational once, then
construct its binary64 bits. This avoids first rounding numerator/denominator
separately. Overflow is represented by signed infinity. -/
def toFloat (value : Rat) : Float :=
  let rounded := Binary64.round value
  let sign := if rounded < 0 then 2^63 else 0
  let magnitude := rounded.abs
  let exponent := Binary64.exponent magnitude
  let bits := if magnitude == 0 then sign
    else if exponent > 1023 then sign + 2047 * 2^52
    else if exponent < -1022 then
      sign + (magnitude / Binary64.powerTwo (-1074)).floor.toNat
    else sign + (exponent + 1023).toNat * 2^52 +
      (magnitude / Binary64.powerTwo (exponent - 52)).floor.toNat - 2^52
  Float.ofBits bits.toUInt64

/-- rs1090 cpr.rs `haversine`: same f64 operation order, Earth radius6371km,
degree-to-radian conversion, sin/cos, sqrt and atan2. This step is tested only. -/
def haversineFloat (a b : Position) : Float :=
  let lat1 := toFloat a.lat
  let lon1 := toFloat a.lon
  let lat2 := toFloat b.lat
  let lon2 := toFloat b.lon
  let rad : Float := 0.017453292519943295
  let dlat := (lat2 - lat1) * rad
  let dlon := (lon2 - lon1) * rad
  let h := (dlat / 2).sin * (dlat / 2).sin +
    (lat1 * rad).cos * (lat2 * rad).cos * (dlon / 2).sin * (dlon / 2).sin
  let c := 2 * (h.sqrt.atan2 ((1 - h).sqrt))
  6371 * c

/-- rs1090 f64 comparison domain: preserve NaN/∞ instead of inventing a
rational value. Finite distances are represented exactly from their bits. -/
def distanceFromFloat (value : Float) : Distance :=
  let bits := value.toBits.toBitVec
  match Binary64.fromBits bits with
  | some rational => .finite rational
  | none =>
    if bits.toNat % 2^52 != 0 then .nan
    else if bits.toNat / 2^63 == 0 then .positiveInfinity else .negativeInfinity

/-- rs1090 cpr.rs numerical CPR output: finite binary64 coordinates are
kept as exact rational values, without losing intermediate-rounding effects. -/
def positionFromFloats (lat lon : Float) : Option Position := do
  let lat ← Binary64.fromBits lat.toBits.toBitVec
  let lon ← Binary64.fromBits lon.toBits.toBitVec
  return ⟨lat, lon⟩

/-- Sun, 2nd ed. (2021), ch.5 NL, evaluated with the pinned oracle's binary64 threshold
comparisons, except the documented standard correction NL(±87)=2. -/
def nlFloat (latitude : Float) : Nat :=
  let lat := latitude.abs
  if lat == 87 then 2 else
    59 - (transitions.takeWhile (fun threshold =>
      threshold.toUInt64.toFloat / 100000000 ≤ lat)).length

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(e), rs1090 cpr.rs `modulo`: preserve operation order. -/
def moduloFloat (a b : Float) : Float := a - b * (a / b).floor

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.5–6 local equations with rs1090's DO260C algebraic
evaluation order and half-cell validation. The result is the exact rational
value of the computed binary64 coordinates, not the ideal rational answer. -/
def decodeLocalFloat (mode : Medium) (code : Encoded) (reference : Position) : Option Position :=
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
  let ni := nlFloat lat - parity code.odd
  let dlon := if ni > 0 then width / ni.toUInt64.toFloat else width
  let m := (0.5 + refLon / dlon - x).floor
  let lon := dlon * (m + x)
  if (lon - refLon).abs > dlon / 2 then none else positionFromFloats lat lon

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7 global equations, preserving pinned rs1090 binary64
operation order; both parity and latitude-zone rejection remain explicit. -/
def decodeGlobalFloat (even odd : Encoded) (latestOdd : Bool) : Option Position :=
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
  if !(l0 ≥ -90 && l0 ≤ 90 && l1 ≥ -90 && l1 ≤ 90) || nlFloat l0 != nlFloat l1 then
    none
  else
    let lat := if latestOdd then l1 else l0
    let n := nlFloat lat
    let ni := (max (n - parity latestOdd) 1).toUInt64.toFloat
    let m := (x0 * (n - 1).toUInt64.toFloat - x1 * n.toUInt64.toFloat + 0.5).floor
    let lon := (360 / ni) * (moduloFloat m ni + if latestOdd then x1 else x0)
    let lon := if lon ≥ 180 then lon - 360 else lon
    positionFromFloats lat lon

/-- rs1090 cpr.rs complete geography boundary, parameterized only by the
pinned airport data. Numeric outputs remain tested rather than proved. -/
def numericalGeography (airports : List Airport) : Geography :=
  { distanceKm := fun a b => distanceFromFloat (haversineFloat a b)
    airports := airports
    localPosition := decodeLocalFloat
    globalPosition := decodeGlobalFloat }

end Lean1090.Impl.CPR.Policy

import Spec.Altitude
import Spec.CPRFloat

/-!
Executable checkpoint-1 specification validation, not capstone proofs and not
the post-approval rs1090 differential suite. Run:
  lake env lean --run scripts/AltitudeCPRExamples.lean

Altitude construction: ICAO Annex10 IV fourth edition2007 §3.1.2.6.5.4(c,d),
Sun second edition ch.13 “Altitude code”. CPR examples: Sun second edition
ch.5 “Decoding example” (airborne global), ch.6 “Locally unambiguous decoding”.
-/

open Lean1090.Spec

private def ensure (condition : Bool) (description : String) : IO Unit :=
  if condition then pure () else throw (IO.userError description)

private def close (actual expected : Float) : Bool :=
  (actual - expected).abs ≤ 0.000000001

private def positionMatches (position : Option CPR.Position) (lat lon : Float) : Bool :=
  match position with
  | none => false
  | some p => close (CPR.Policy.toFloat p.lat) lat && close (CPR.Policy.toFloat p.lon) lon

def main : IO Unit := do
  ensure ((List.range 8192).all (fun word => match Altitude.decodeGillham word with
    | none => true
    | some height => Altitude.encodeGillham height == some word))
    "Gillham raw-word re-encoding failed"
  ensure ((List.range 1280).all (fun index =>
    let height : Int := (index : Int) * 100 - 1200
    (Altitude.encodeGillham height).bind Altitude.decodeGillham == some height))
    "Gillham representable-height round-trip failed"
  ensure ((List.range 2048).all (fun index =>
    let height : Int := (index : Int) * 25 - 1000
    (Altitude.encode25AC13 height).bind Altitude.decodeAC13 == some (.feet height)))
    "Q=1 representable-height round-trip failed"
  ensure (((List.range 8192).filter (fun word =>
    (Altitude.decodeGillham word).isSome)).length == 1280)
    "Gillham valid-code cardinality differs from1280"
  ensure (positionMatches
    (CPR.Policy.decodeGlobalFloat ⟨false, 93000, 51372⟩ ⟨true, 74158, 50194⟩ false)
    52.2572021484375 3.91937255859375)
    "Sun ch.5 global airborne example failed"
  ensure (positionMatches
    (CPR.Policy.decodeLocalFloat .surface ⟨true, 39195, 110320⟩
      ⟨52320607 / 1000000, 4734735 / 1000000⟩)
    52.32056051997815 4.735735212053571)
    "Sun ch.6 local surface example failed"
  ensure (CPR.Policy.haversineFloat ⟨0, 0⟩ ⟨0, 0⟩ == 0)
    "Coincident-position haversine smoke check failed"
  ensure (close (CPR.Policy.haversineFloat ⟨0, 0⟩ ⟨1, 0⟩) 111.19492664455873)
    "One-degree meridional haversine smoke check failed"
  ensure (CPR.Policy.distanceFromFloat (Float.ofBits 0x7ff8000000000000) == .nan)
    "Distance NaN classification failed"
  ensure (CPR.Policy.distanceFromFloat (Float.ofBits 0x7ff0000000000000) == .positiveInfinity)
    "Distance infinity classification failed"
  IO.println "Altitude exhaustive specification checks and CPR source examples passed."

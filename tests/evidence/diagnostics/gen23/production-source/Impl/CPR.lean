import Model.Types

/-!
# Initial exact runtime compact position reporting

This implementation starts from the frozen reference algorithms. It imports
only shared data types and is connected to the reference through Proofs/.

Primary source: ICAO Annex 10, Vol III, Part I, amendment 77 (28 November
2002), §2.6, pp.5-88–5-94, acquired from
https://lso.fe.uni-lj.si/literatura/Razno/Avionika/modes/CPRencoding.pdf .
Corroboration: Sun, *The 1090 Megahertz Riddle*, second edition, ch.5
“Compact position reporting” and ch.6 “Position”.

The encoder follows §2.6.3: first round latitude, then use the reconstructed
latitude in NL when encoding longitude. This order matters near NL changes.
All calculations below are exact rationals; the Float-facing oracle projection
and tracking policy are separate. Only local surface decoding is in scope.
-/

namespace Lean1090.Impl.CPR
open Lean1090.Spec.CPR

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(a): 17 transmitted bits for each CPR coordinate. -/
def scale : Nat := 131072

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3: odd=1 and even=0 in all CPR formulas. -/
def parity (odd : Bool) : Nat := if odd then 1 else 0

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.5(a), §2.6.6(a): angular ambiguity span. -/
def span : Medium → Rat | .airborne => 360 | .surface => 90

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(d): absolute value for exact rational angles. -/
def absQ (x : Rat) : Rat := if x < 0 then -x else x

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(e): Euclidean modulus, including negative angles. -/
def modQ (x y : Rat) : Rat := x - y * ((x / y).floor : Rat)

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(f): canonical longitude in [-180,180). -/
def normalizeLongitude (lon : Rat) : Rat := modQ (lon + 180) 360 - 180

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(f), note5: transition latitudes rounded to 10⁻⁸ degrees,
in increasing order. Generated independently from its arccos/sqrt formula;
certification against the real formula is a separate capstone, not assumed.
The final 87° equality convention is handled explicitly by `nlTable`. -/
def transitions : List Nat :=
  [1047047130, 1482817437, 1818626357, 2102939493, 2354504487,
   2582924707, 2793898710, 2991135686, 3177209708, 3353993436,
   3522899598, 3685025108, 3841241892, 3992256684, 4138651832,
   4280914012, 4419454951, 4554626723, 4686733252, 4816039128,
   4942776439, 5067150166, 5189342469, 5309516153, 5427817472,
   5544378444, 5659318756, 5772747354, 5884763776, 5995459277,
   6104917774, 6213216659, 6320427479, 6426616523, 6531845310,
   6636171008, 6739646774, 6842322022, 6944242631, 7045451075,
   7145986473, 7245884545, 7345177442, 7443893416, 7542056257,
   7639684391, 7736789461, 7833374083, 7929428225, 8024923213,
   8119801349, 8213956981, 8307199445, 8399173563, 8489166191,
   8575541621, 8653536998, 8700000000]

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(f); Sun, 2nd ed. (2021), ch.5 NL: NL(0)=59, NL(±87)=2,
NL(|lat|>87)=1. Decimal thresholds only claim equivalence on CPR grids. -/
def nlTable (lat : Rat) : Nat :=
  if absQ lat == 87 then 2 else
  59 - (transitions.takeWhile (fun (t : Nat) => (t : Rat) / 100000000 ≤ absQ lat)).length

/-- Explicit oracle policy: rs1090 685dfaa cpr.rs `nl` uses strict `<87`,
so the attainable latitude ±87° yields 1 rather than Sun's 2. -/
def oracleNLTable (lat : Rat) : Nat :=
  59 - (transitions.takeWhile (fun (t : Nat) => (t : Rat) / 100000000 ≤ absQ lat)).length

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.5(a), §2.6.6(a): exact latitude cell width. -/
def dLat (mode : Medium) (odd : Bool) : Rat := span mode / (60 - parity odd : Nat)

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(c), §2.6.5(d), §2.6.6(d): at least one longitude zone. -/
def zones (lat : Rat) (odd : Bool) : Nat := max (nlTable lat - parity odd) 1

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(c), §2.6.5(d), §2.6.6(d): exact longitude cell width. -/
def dLon (mode : Medium) (odd : Bool) (lat : Rat) : Rat :=
  span mode / (zones lat odd : Rat)

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(a,b): unwrapped, rounded latitude used by the encoder's
NL lookup. The +1/2 floor rule rounds ties toward positive infinity. -/
def roundedLatitude (mode : Medium) (odd : Bool) (lat : Rat) : Rat :=
  let d := dLat mode odd
  d / scale * (((lat / d * scale + 1 / 2).floor : Int) : Rat)

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(a,d,e): independent coordinate encoding as rounded
fractional zone position, followed by reduction to 17 transmitted bits. -/
def encodeCoordinate (width coordinate : Rat) : Nat :=
  ((modQ coordinate width / width * scale + 1 / 2).floor % (scale : Int)).toNat

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(a–e): reference encoder; the reconstructed latitude,
not the physical latitude, determines the longitude encoding zone. -/
def encode (mode : Medium) (odd : Bool) (p : Position) : Encoded :=
  let lat := roundedLatitude mode odd p.lat
  ⟨odd, encodeCoordinate (dLat mode odd) p.lat,
    encodeCoordinate (dLon mode odd lat) p.lon⟩

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(e): transmitted-coordinate bounds. -/
def ValidCode (e : Encoded) : Prop := e.lat < scale ∧ e.lon < scale

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3: geographic coordinate convention, poles included. -/
def ValidPosition (p : Position) : Prop :=
  -90 ≤ p.lat ∧ p.lat ≤ 90 ∧ -180 ≤ p.lon ∧ p.lon < 180

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.5(b,e), §2.6.6(b,e): choose nearest zone from reference. -/
def localCoordinate (width reference : Rat) (code : Nat) : Rat :=
  let fraction : Rat := code / (scale : Rat)
  let j := (reference / width).floor +
    (modQ reference width / width - fraction + 1 / 2).floor
  width * ((j : Rat) + fraction)

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.5(b,c), §2.6.6(b,c): latitude before longitude lookup. -/
def localLatitude (mode : Medium) (e : Encoded) (reference : Position) : Rat :=
  localCoordinate (dLat mode e.odd) reference.lat e.lat

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.4–6: local airborne or surface reference decoding.
Out-of-range raw coordinates and reconstructed latitudes are rejected.
Longitude follows the reference's unwrapped branch, as the published local
equations and rs1090 do; only global decoding canonicalizes longitude. -/
def decodeLocal (mode : Medium) (e : Encoded) (reference : Position) : Option Position :=
  let lat := localLatitude mode e reference
  if e.lat < scale ∧ e.lon < scale ∧ -90 ≤ lat ∧ lat ≤ 90 then
    some ⟨lat, localCoordinate (dLon mode e.odd lat) reference.lon e.lon⟩
  else none

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(b,c): both reconstructed airborne latitudes, before the
same-NL test. Argument order is even then odd; parity validation is separate. -/
def globalLatitudes (even odd : Encoded) : Rat × Rat :=
  let a : Rat := even.lat / (scale : Rat)
  let b : Rat := odd.lat / (scale : Rat)
  let j := (59 * a - 60 * b + 1 / 2).floor
  let l0 := dLat .airborne false * ((j % 60 : Int) + a)
  let l1 := dLat .airborne true * ((j % 59 : Int) + b)
  (if l0 ≥ 270 then l0 - 360 else l0,
   if l1 ≥ 270 then l1 - 360 else l1)

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(d): reject pairs whose reconstructed latitudes have
different longitude-zone counts. This is not a test on unknowable true positions. -/
def SameDecodedZone (even odd : Encoded) : Prop :=
  let (l0, l1) := globalLatitudes even odd
  nlTable l0 = nlTable l1

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(a–f): global airborne decoding. `latestOdd` selects
the later report; transport timestamps and oracle's 30s rule belong to policy. -/
def decodeGlobal (even odd : Encoded) (latestOdd : Bool) : Option Position :=
  let (l0, l1) := globalLatitudes even odd
  if !even.odd && odd.odd && even.lat < scale && even.lon < scale &&
      odd.lat < scale && odd.lon < scale &&
      -90 ≤ l0 && l0 ≤ 90 && -90 ≤ l1 && l1 ≤ 90 && nlTable l0 == nlTable l1 then
    let lat := if latestOdd then l1 else l0
    let n := nlTable lat
    let a : Rat := even.lon / (scale : Rat)
    let b : Rat := odd.lon / (scale : Rat)
    let m := (a * (n - 1 : Nat) - b * n + 1 / 2).floor
    let ni := max (n - parity latestOdd) 1
    let lon := (360 : Rat) / ni *
      ((m % (ni : Int) : Int) + if latestOdd then b else a)
    some ⟨lat, normalizeLongitude lon⟩
  else none

end Lean1090.Impl.CPR

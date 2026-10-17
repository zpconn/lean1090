import Spec.CPR

/-! Concrete, decidable domains for the CPR capstones.
These hypotheses specify ambiguity and quantization margins, never the desired
decoder result. Source: ICAO Annex10 III amendment77 §2.6.3–7.
-/

namespace Lean1090.Spec.CPR

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(d): unwrapped quantized longitude, using reconstructed
latitude for the encoding zone. Used only to describe quantization error. -/
def roundedLongitude (mode : Medium) (odd : Bool) (p : Position) : Rat :=
  let d := dLon mode odd (roundedLatitude mode odd p.lat)
  d / scale * (((p.lon / d * scale + 1 / 2).floor : Int) : Rat)

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(f): longitude error is circular at the antimeridian. -/
def longitudeDistance (a b : Rat) : Rat := absQ (normalizeLongitude (a - b))

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.4–6: the reference must select the same nearest latitude
and longitude cells as the encoded quantized position. Strict half-cell
margins exclude ambiguous ties; there is no physical-latitude NL assumption. -/
def LocalAdmissible (mode : Medium) (odd : Bool) (p reference : Position) : Prop :=
  ValidPosition p ∧ ValidPosition reference ∧
  absQ (reference.lat - roundedLatitude mode odd p.lat) < dLat mode odd / 2 ∧
  longitudeDistance reference.lon (roundedLongitude mode odd p) <
    dLon mode odd (roundedLatitude mode odd p.lat) / 2

instance (mode : Medium) (odd : Bool) (p reference : Position) :
    Decidable (LocalAdmissible mode odd p reference) := by
  unfold LocalAdmissible ValidPosition
  infer_instance

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3 rounding: half a transmitted coordinate step, with
circular longitude error. The inequality includes exact tie rounding. -/
def WithinResolution (mode : Medium) (odd : Bool) (original decoded : Position) : Prop :=
  absQ (decoded.lat - original.lat) ≤ dLat mode odd / (2 * scale) ∧
  longitudeDistance decoded.lon original.lon ≤
    dLon mode odd (roundedLatitude mode odd original.lat) / (2 * scale)

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(b,e): separation that keeps the integer zone indices
unambiguous, stated on quantized coordinates. Latitude limit is 3/59°;
longitude limit is 180/(NL·(NL−1))°, with no restriction at NL=1.
The NL compatibility condition is on the encoder-side rounded latitudes.
No decoder or decoder helper is used to define this admissibility domain. -/
def GlobalAdmissible (pEven pOdd : Position) : Prop :=
  let r0 := roundedLatitude .airborne false pEven.lat
  let r1 := roundedLatitude .airborne true pOdd.lat
  let n := nlTable r0
  ValidPosition pEven ∧ ValidPosition pOdd ∧
  absQ (r0 - r1) < 3 / 59 ∧
  nlTable r0 = nlTable r1 ∧
  (n = 1 ∨ longitudeDistance
    (roundedLongitude .airborne false pEven)
    (roundedLongitude .airborne true pOdd) < 180 / ((n * (n - 1) : Nat) : Rat))

instance (pEven pOdd : Position) : Decidable (GlobalAdmissible pEven pOdd) := by
  unfold GlobalAdmissible ValidPosition
  infer_instance

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3: zero degrees is an ordinary valid geographic position. -/
def zeroPosition : Position := ⟨0, 0⟩

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7: a genuinely moved second report, roughly 0.085 NM away
from zero in each coordinate; used to make the movement contract non-vacuous. -/
def movedPosition : Position := ⟨1 / 1000, 1 / 1000⟩

/-- Local capstone hypotheses have a concrete witness for both media and
both parities; kernel reduction, no trusted runtime decision procedure. -/
theorem local_nonvacuous (mode : Medium) (odd : Bool) :
    LocalAdmissible mode odd zeroPosition zeroPosition := by
  cases mode <;> cases odd <;> decide +kernel

/-- Global capstone hypotheses admit movement, not only coincident reports. -/
theorem global_nonvacuous : GlobalAdmissible zeroPosition movedPosition := by decide +kernel

/-- The movement witness is nonstationary in both coordinates. -/
theorem global_witness_moves :
    zeroPosition.lat ≠ movedPosition.lat ∧ zeroPosition.lon ≠ movedPosition.lon := by decide +kernel

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7 note2: a 3 NM latitude displacement (0.05°) plus
the worst two half-step latitude rounding errors is below the exact
unambiguous index bound 3/59°. This explains the quantization margin. -/
theorem three_nm_latitude_margin :
    (1 / 20 : Rat) + dLat .airborne false / (2 * scale) +
      dLat .airborne true / (2 * scale) < 3 / 59 := by decide +kernel

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(d): concrete pair straddling the first NL transition
after reconstruction, generated from latitudes10.47045° and10.4705°. -/
def boundaryEven : Encoded := ⟨false, 97658, 0⟩

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(d): odd member of the rejected boundary witness. -/
def boundaryOdd : Encoded := ⟨true, 93847, 0⟩

/-- The zone-rejection capstone's hypotheses are inhabited by bounded
coordinates with the required even/odd parities, not merely malformed input. -/
theorem zone_rejection_nonvacuous :
    ValidCode boundaryEven ∧ ValidCode boundaryOdd ∧
    boundaryEven.odd = false ∧ boundaryOdd.odd = true ∧
    ¬ SameDecodedZone boundaryEven boundaryOdd := by
  unfold ValidCode SameDecodedZone
  decide +kernel

/-- The concrete source pair is rejected for either recency ordering. -/
theorem zone_rejection_witness (latestOdd : Bool) :
    decodeGlobal boundaryEven boundaryOdd latestOdd = none := by
  cases latestOdd <;> decide +kernel

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3 rounding and §2.6.5 nearest-cell ambiguity: physical
latitude inside3° alone is insufficient at a half-cell tie after rounding.
This concrete point is only a quarter CPR step inside the nominal range. -/
def localTiePosition : Position := ⟨-3 + 3 / 262144, 0⟩

/-- Dropping the quantized-reference margin can select a latitude6° away,
even though the physical latitude separation is strictly less than3°. -/
theorem local_margin_needed :
    absQ localTiePosition.lat < 3 ∧
    decodeLocal .airborne (encode .airborne false localTiePosition) zeroPosition =
      some ⟨3, 0⟩ ∧
    ¬ WithinResolution .airborne false localTiePosition ⟨3, 0⟩ := by
  unfold WithinResolution
  decide +kernel

/-- The half-step safety band is less than0.000024° in airborne latitude
and less than0.000006° on the surface, for either parity. -/
theorem local_latitude_rounding_band (odd : Bool) :
    dLat .airborne odd / (2 * scale) < (24 / 1000000 : Rat) ∧
    dLat .surface odd / (2 * scale) < (6 / 1000000 : Rat) := by
  cases odd <;> decide +kernel

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7 note2: excessive pair movement produces an ambiguous
global latitude even though the reconstructed pair passes the NL check. -/
theorem global_latitude_separation_needed :
    SameDecodedZone (encode .airborne false zeroPosition)
      (encode .airborne true ⟨1 / 10, 0⟩) ∧
    decodeGlobal (encode .airborne false zeroPosition)
      (encode .airborne true ⟨1 / 10, 0⟩) false = some ⟨-6, 0⟩ := by
  unfold SameDecodedZone
  decide +kernel

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(e): latitude agreement cannot replace the independent
longitude separation requirement. A0.1° longitude motion aliases by a zone. -/
theorem global_longitude_separation_needed :
    SameDecodedZone (encode .airborne false zeroPosition)
      (encode .airborne true ⟨0, 1 / 10⟩) ∧
    decodeGlobal (encode .airborne false zeroPosition)
      (encode .airborne true ⟨0, 1 / 10⟩) false = some ⟨0, -360 / 59⟩ := by
  unfold SameDecodedZone
  decide +kernel

end Lean1090.Spec.CPR

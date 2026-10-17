import Spec.Message
import Spec.CPRContracts
import Spec.CPRFormula
import Spec.CPRPolicy
import Spec.CommBArithmetic
import Spec.BDS50

/-!
# Frozen theorem statements for checkpoint 1

These are named propositions, NOT claims of completed proofs. After approval,
Proofs/ must supply a theorem of each proposition (instantiating the refinement
parameters with actual Impl functions). This permits freezing this file without
placeholder proofs or changing theorem statements later. Concrete non-vacuity
lemmas live in Spec/*Witnesses and the cited subject modules. See THEOREMS.md.
-/
namespace Lean1090.Capstones
open Spec

/-- Every byte sequence has the specified success/failure and exact fields.
The final manifest instantiates this with Impl.decode. The headline benchmark
times that exact function, including any projection into this result model. -/
def Refinement (implementation : List UInt8 → Option Message) : Prop :=
  ∀ bytes, implementation bytes = Spec.decode bytes

/-- The complete BDS50 path reproduces all fields and the proof-visible binary64
score gate for every input. The pilot times this same implementation function;
its result contains the exact score as well as the accepted field record. -/
def BDS50Refinement (implementation : Nat → Option Model.BDS50.Result) : Prop :=
  ∀ word, implementation word = Spec.bds50Reference word

/-- Streaming boundary behavior includes the exact unconsumed suffix. -/
def PrefixRefinement
    (implementation : List UInt8 → Option (Message × List UInt8)) : Prop :=
  ∀ bytes, implementation bytes = Spec.decodePrefix bytes

/-- Every independently valid wire-field assignment decodes to that assignment
and its complete semantic report. The report is in the conclusion, never a
hypothesis. Successful decoding reproduces every input bit. -/
def MessageRoundTrips : Prop :=
  (∀ fields, Valid fields →
    Spec.decode (encodeFrame fields) = some (assigned fields)) ∧
  (∀ bytes f, Spec.decode bytes = some f → Spec.encode f = bytes)

/-- Every ADS-B TC/subtype/version assignment round-trips, including raw
unavailable/reserved codes. Exact field codes, not rounded JSON, are the domain. -/
def ADSBRoundTrips : Prop :=
  (∀ f, ValidADSB f → decodeADSB (encodeADSB f) = .ok f) ∧
  (∀ word f, decodeADSB word = .ok f → encodeADSB f = word)

/-- Every structural frame assignment round-trips even when a receiver
policy would reject it. This keeps source field guarantees independent of
oracle acceptance and plausibility heuristics. -/
def FrameRoundTrips : Prop :=
  (∀ f, decodeFrame (encodeFrame f) = some f) ∧
  (∀ bytes f, decodeFrame bytes = some f → encodeFrame f = bytes)

/-- Full representable ADS-B field codes round-trip independently of the
receiver altitude ceiling and operational-status reserved-bit checks. -/
def ADSBFieldRoundTrips : Prop :=
  (∀ f, ValidADSBFields f → decodeADSBFields (encodeADSB f) = .ok f) ∧
  (∀ word f, decodeADSBFields word = .ok f → encodeADSB f = word)

/-- CRC recurrence equals independent polynomial division over GF(2). -/
def CRCPolynomial : Prop :=
  ∀ width word,
    Parity.polynomial 24 (Parity.syndrome width word).toNat =
      Parity.polynomialRemainder width word

/-- XOR linearity holds for every bit width and every pair of words. -/
def CRCLinear : Prop :=
  ∀ width a b,
    Parity.syndrome width (a ^^^ b) =
      Parity.syndrome width a ^^^ Parity.syndrome width b

/-- Every single-bit error has nonzero syndrome and every bit has a distinct
syndrome, separately within the 56-bit and 112-bit frame domains. -/
def CRCSingleBit : Prop :=
  ∀ width, width = 56 ∨ width = 112 →
    (∀ i : Fin width, Parity.syndrome width (2^i.val) ≠ 0) ∧
    (∀ i j : Fin width,
      Parity.syndrome width (2^i.val) = Parity.syndrome width (2^j.val) → i = j)

/-- The receiver recovers exactly the transmitted AP/PI XOR overlay. This
algebraic statement does not authenticate an address on a corrupted message. -/
def ParityOverlay : Prop :=
  ∀ width, width = 32 ∨ width = 88 → ∀ information,
    information < 2^width → ∀ address : BitVec 24,
    Parity.syndrome (width+24)
      (information*2^24 + (Parity.overlay width information address).toNat) = address

/-- All representable 25ft and Gillham100ft heights round-trip through both
AC13 and AC12. The domain is mathematical representability, not the oracle's
50000ft acceptance heuristic. -/
def AltitudeRoundTrips : Prop :=
  (∀ h, Altitude.Representable25 h →
    (∃ w, Altitude.encode25AC13 h = some w ∧
      Altitude.decodeAC13 w = some (.feet h)) ∧
    (∃ w, Altitude.encodeFeetAC12 .binary25 h = some w ∧
      Altitude.decodeAC12 w = some h)) ∧
  (∀ h, Altitude.RepresentableGillham h →
    (∃ w, Altitude.encodeGillham h = some w ∧ Altitude.decodeGillham w = some h) ∧
    (∃ w, Altitude.encodeFeetAC12 .gillham100 h = some w ∧
      Altitude.decodeAC12 w = some h))

/-- Invalid Gray-code patterns are rejected and out-of-domain altitudes cannot
be encoded. There is no premise that a decoding/encoding round-trip succeeds. -/
def AltitudeRejection : Prop :=
  (∀ w, Altitude.validGillham w = false → Altitude.decodeGillham w = none) ∧
  (∀ h, ¬ Altitude.Representable25 h → Altitude.encode25AC13 h = none) ∧
  (∀ h, ¬ Altitude.RepresentableGillham h → Altitude.encodeGillham h = none)

/-- Local airborne/surface CPR: nearest-cell quantized-reference conditions
imply at most half a latitude/longitude quantization step of error. -/
def CPRLocal : Prop :=
  ∀ (mode : CPR.Medium) (odd : Bool) (p reference : CPR.Position),
    CPR.LocalAdmissible mode odd p reference →
    ∃ q, CPR.decodeLocal mode (CPR.encode mode odd p) reference = some q ∧
      CPR.WithinResolution mode odd p q

/-- Global airborne CPR: unambiguous quantized pair separation and equal NL
on the encoder-side rounded latitudes recover the selected report to half-step
resolution. No hypothesis calls the global decoder or its reconstruction. -/
def CPRGlobal : Prop :=
  ∀ (pEven pOdd : CPR.Position) (latestOdd : Bool),
    CPR.GlobalAdmissible pEven pOdd →
    ∃ q, CPR.decodeGlobal (CPR.encode .airborne false pEven)
      (CPR.encode .airborne true pOdd) latestOdd = some q ∧
      CPR.WithinResolution .airborne latestOdd (if latestOdd then pOdd else pEven) q

/-- Pairs crossing a reconstructed latitude zone are rejected. This is not a
claim that different physical zones necessarily remain different after rounding. -/
def CPRZoneRejection : Prop :=
  ∀ even odd latestOdd, ¬ CPR.SameDecodedZone even odd →
    CPR.decodeGlobal even odd latestOdd = none

/-- Certified transcendental transitions plus finite grid separation establish
NL's agreement with Real.arccos at EVERY decodable latitude, including ±87°. -/
def CPRLatitudeZones : Prop :=
  (∀ c ∈ CPR.nlCertificates,
    CPR.CertifiesTransition c ∧ CPR.AvoidsDecodableLatitudes c) ∧
  (∀ lat, CPR.DecodableLatitude lat → CPR.nlTable lat = CPR.nlFormula (lat : ℝ))

/-- Oracle-defined Comm-B inference returns exactly the registers passing
all published-in-source predicates, with the exact register field record. -/
def CommBInference : Prop :=
  ∀ df altitude word register fields,
    (register, fields) ∈ inferCommB df altitude word ↔
      commBEligible df altitude register word = true ∧
      decodeBDS register word = some fields

/-- Direct register field encodings round-trip, including BDS65 even though
the pinned per-message selector currently never reports that register. -/
def CommBRoundTrips : Prop :=
  (∀ f, ValidBDS f → decodeBDS f.kind (encodeBDS f) = some f) ∧
  (∀ register word f, decodeBDS register word = some f → encodeBDS f = word)

/-- All structurally valid register field assignments round-trip, including
codes outside the oracle's physical-envelope and status-consistency heuristics. -/
def CommBFieldRoundTrips : Prop :=
  (∀ f, ValidBDSFields f → decodeBDSFields f.kind (encodeBDS f) = some f) ∧
  (∀ register word f, decodeBDSFields register word = some f → encodeBDS f = word)

/-- The binary64 model's finite/no-zero-divisor domain is guaranteed for every
56-bit payload, not added as an assumption to weaken candidate-set equality. -/
def CommBArithmetic : Prop :=
  ∀ register, register ∈ commBCoreRegisters → ∀ word, word < 2^56 →
    CommBScoreArithmeticFinite register word

/-- Complete stateful CPR policy refinement, including per-aircraft caches,
reference updates, ordering, time windows and tested numerical boundaries. -/
def CPRTrackingRefinement
    (implementation : CPR.Policy.Geography → CPR.Policy.UpdateReference →
      Option CPR.Position → List CPR.Policy.TimedReport →
      CPR.Policy.StreamState × List (Option CPR.Position)) : Prop :=
  ∀ geo update reference reports,
    implementation geo update reference reports =
      CPR.Policy.decodePositions geo update reference reports

/-- An airborne report older than the opposite parity cache cannot resolve a
position or mutate either aircraft state or receiver reference. -/
def CPROutOfOrder : Prop :=
  ∀ geo update (state : CPR.Policy.AircraftState) reference timestamp
      (code : CPR.Encoded) altitude metadata,
    Binary64.sub timestamp
      (if code.odd then state.evenTimestamp else state.oddTimestamp) < 0 →
    CPR.Policy.stepAirborne geo update state reference timestamp code altitude metadata =
      ⟨state, reference, none, true⟩

end Lean1090.Capstones

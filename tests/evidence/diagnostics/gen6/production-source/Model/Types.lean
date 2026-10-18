import Std

/-!
Shared data model for the reference specification and executable implementation.
This module contains only data declarations and type abbreviations. It imports
Std only: no Spec module, decoder, validation predicate, or numerical formula.
Existing qualified names are retained so theorem interfaces do not change;
Impl imports this module directly, while Spec supplies the reference meanings.
Source citations move with the data declarations they describe.
-/

namespace Lean1090.Spec

/-- Wire-code interpretation. Two's complement is used by Sun, ch.17 tables 17.2–17.3. -/
inductive PayloadCoding where
  | unsigned | twosComplement
  deriving DecidableEq, Repr

/-- A table column, including its exact scale and status bit. `status = 0` means
unconditionally present. Source references belong to each concrete layout below. -/
structure PayloadColumn where
  name : String
  start : Nat
  width : Nat
  coding : PayloadCoding := .unsigned
  scale : Rat := 1
  offset : Rat := 0
  status : Nat := 0
  deriving DecidableEq, Repr

/-- A single standard field assignment is its lossless wire code. Keeping the
code distinguishes unavailable values, reserved values, and quantization bins. -/
structure PayloadField where
  name : String
  code : Nat
  deriving DecidableEq, Repr

/-- Source-table field assignments; the kind chooses the independent layout.
No original payload word is retained. -/
structure PayloadRecord where
  kind : Nat
  fields : List PayloadField
  deriving DecidableEq, Repr

/-- Decoder outcomes distinguish a malformed payload from an unimplemented
source table; source gaps must never masquerade as standard rejection. -/
inductive PayloadError where
  | outOfRange | malformed (reason : String) | sourceUnavailable (kind : Nat)
  deriving DecidableEq, Repr

end Lean1090.Spec

namespace Lean1090.Spec.Altitude

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: feet and metres are distinct field meanings. -/
inductive Value where
  | feet (height : Int)
  | metres (height : Nat)
  deriving BEq, DecidableEq, Repr

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: M=0 offers 25-foot binary or 100-foot Gillham. -/
inductive FeetEncoding where
  | binary25
  | gillham100
  deriving BEq, DecidableEq, Repr

end Lean1090.Spec.Altitude

namespace Lean1090.Spec

/-- Annex 10 IV (4th ed.), §3.1.2.8.2/3: common ACAS header fields.
In DF16 `cc` is an unassigned bit, retained only for wire reconstruction. -/
structure ACASFields where
  vs : BitVec 1
  cc : BitVec 1
  spare1 : BitVec 1
  sl : BitVec 3
  spare2 : BitVec 2
  ri : BitVec 4
  spare3 : BitVec 2
  ac : BitVec 13
  deriving DecidableEq, Repr

/-- Annex 10 IV (4th ed.), §§3.1.2.6.5–8: surveillance header.
`code` is AC13 for altitude replies and ID13 for identity replies. -/
structure SurveillanceFields where
  fs : BitVec 3
  dr : BitVec 5
  um : BitVec 6
  code : BitVec 13
  deriving DecidableEq, Repr

/-- Annex 10 IV (4th ed.), layouts in §§3.1.2.5.2.2, 3.1.2.6.5–8,
3.1.2.7.3, 3.1.2.8.2/3/6/7/8. DF24 has a TWO-bit descriptor, not five.
The two booleans choose altitude/identity and ADS-B/supplementary respectively. -/
inductive FrameBody where
  | shortACAS (fields : ACASFields)
  | surveillance (identity : Bool) (fields : SurveillanceFields)
  | allCall (ca : BitVec 3) (aa : BitVec 24)
  | longACAS (fields : ACASFields) (mv : BitVec 56)
  | extended (supplementary : Bool) (control : BitVec 3) (aa : BitVec 24)
      (me : BitVec 56)
  | military (af : BitVec 3) (reserved : BitVec 80)
  | commB (identity : Bool) (fields : SurveillanceFields) (mb : BitVec 56)
  | commD (spare : BitVec 1) (ke : BitVec 1) (nd : BitVec 4) (md : BitVec 80)
  deriving DecidableEq, Repr

/-- Annex 10 IV (4th ed.), §3.1.2.3.2.1: transmitted fields plus the
final 24 bits. For DF19 these are uninterpreted reserved military bits;
for the other constructors they carry the AP or PI field. -/
structure Frame where
  body : FrameBody
  parity : BitVec 24
  deriving DecidableEq, Repr

end Lean1090.Spec

namespace Lean1090.Spec.Presentation

/-- rs1090 bds09.rs/bds62.rs: distinguish binary32 intermediates from binary64. -/
inductive Precision where
  | binary32 | binary64
  deriving DecidableEq, Repr

/-- rs1090 arithmetic expressions. Each operation with a precision parameter
rounds to that format; `literal` converts the exact rational once. `hypot64`
and `atan2_64` denote the pinned libm functions, with their unproved runtime
behavior. `addIfNegative64` compares the evaluated argument with zero before
adding360, matching its track/heading reporting normalization. -/
inductive FloatExpr where
  | literal (precision : Precision) (value : Rat)
  | add (precision : Precision) (a b : FloatExpr)
  | sub (precision : Precision) (a b : FloatExpr)
  | mul (precision : Precision) (a b : FloatExpr)
  | div (precision : Precision) (a b : FloatExpr)
  | abs64 (a : FloatExpr)
  | hypot64 (a b : FloatExpr)
  | atan2_64 (y x : FloatExpr)
  | addIfNegative64 (a : FloatExpr)
  deriving DecidableEq, Repr

/-- rs1090 serde policy: unavailable numeric keys can be omitted or null. -/
inductive Missing where
  | omit | null
  deriving DecidableEq, Repr

/-- rs1090-derived output key and optional floating formula. Presence/absence
is decided from exact field codes, before evaluating any Float expression. -/
structure NumericField where
  key : String
  value : Option FloatExpr
  missing : Missing
  deriving DecidableEq, Repr

end Lean1090.Spec.Presentation

namespace Lean1090.Spec

/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.5–6 threat data; unused raw values
remain in PayloadRecord while these projections expose reported meanings.
Range is exact before the oracle's f32 presentation conversion. -/
inductive CommBThreat where
  | none
  | address (icao24 : Nat)
  | orientation (altitude : Option Int) (rangeNM : Option Rat) (bearingDeg : Option Nat)
  | unassigned
  deriving DecidableEq, Repr

/-- ICAO Annex10 IV (4th ed., amendment85), §4.3.8.4.2.2.1.6.2:
TIDR is a quantized range with separate unavailable and saturation codes,
not an unrestricted numeric point estimate. Units are nautical miles. -/
inductive StandardThreatRange where
  | unavailable
  | lessThan (upper : Rat)
  | estimate (centre tolerance : Rat)
  | greaterThan (lower : Rat)
  deriving DecidableEq, Repr

/-- ICAO Annex10 IV (4th ed., amendment85), §4.3.8.4.2.2.1.6.3:
TIDB gives a six-degree bearing sector, with61–63 unassigned. Sector endpoints
are recorded without inventing an open/closed endpoint convention. -/
inductive StandardThreatBearing where
  | unavailable
  | sector (lower upper : Nat)
  | unassigned (code : Nat)
  deriving DecidableEq, Repr

/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.5–6: standard threat information.
The two padding bits of a TTI1 address must be zero. The TTI2 altitude is
Mode C Gillham, not the oracle's generic AC13 M/Q compatibility conversion. -/
inductive StandardCommBThreat where
  | none
  | address (icao24 : Nat)
  | orientation (altitudeFeet : Option Int)
      (range : StandardThreatRange) (bearing : StandardThreatBearing)
  | unassigned
  deriving DecidableEq, Repr

end Lean1090.Spec

namespace Lean1090.Spec.Semantics
open Presentation

/-- Sun, 2nd ed. (2021), tables5.1–8.3 and16.1–18.2; ICAO Annex10 IV, 4th ed. (2007), tables3-6/3-8/3-10: exact physical/code values before Float.
An absent value is different from zero and from an unlisted field. -/
abbrev Values := List (String × Option Rat)

/-- rs1090-derived enum/string projection, with explicit unavailability. -/
abbrev Labels := List (String × Option String)

/-- Source tables plus the documented oracle exceptions: one complete
proof-visible payload interpretation, without a serialization dependency. -/
structure Payload where
  tableValues : Values
  standardValues : Values
  oracleValues : Values
  standardLabels : Labels
  oracleLabels : Labels
  standardFloats : List NumericField
  oracleFloats : List NumericField
  standardThreat : Option StandardCommBThreat := none
  oracleThreat : Option CommBThreat := none
  deriving DecidableEq, Repr

end Lean1090.Spec.Semantics

namespace Lean1090.Spec

/-- Exact derived report. Sources: Annex10 IV parity/altitude/identity clauses
above and Sun payload tables cited in ADSB/CommB. Floating presentation functions
are specified separately; all of their field codes are retained in `Frame`.
The round-trip conclusion constructs every derived value from frame fields;
the independent validity predicate imposes no report-coherence hypothesis. -/
structure Report where
  crc : BitVec 24
  address : Option (BitVec 24)
  interrogator : Option (BitVec 3 × BitVec 4)
  altitude : Option Altitude.Value
  identity : Option Nat
  adsb : Option PayloadRecord
  commB : List (Nat × PayloadRecord)
  semanticADSB : Option Semantics.Payload
  semanticCommB : List (Nat × Semantics.Payload)
  deriving DecidableEq, Repr

/-- Lossless field assignment and its exact semantic views. Annex10 IV layouts
are represented by `Frame`; the report carries named payload decompositions. -/
structure Message where
  fields : Frame
  decoded : Report
  deriving DecidableEq, Repr

end Lean1090.Spec

namespace Lean1090.Spec.CPR

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.1 note5 and §2.6.6: surface ambiguity span is 90°. -/
inductive Medium where
  | airborne
  | surface
  deriving BEq, DecidableEq, Repr

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3: geographic coordinates measured in exact degrees. -/
structure Position where
  lat : Rat
  lon : Rat
  deriving BEq, DecidableEq, Repr

/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(e): transmitted parity and the two 17-bit residues. -/
structure Encoded where
  odd : Bool
  lat : Nat
  lon : Nat
  deriving BEq, DecidableEq, Repr

end Lean1090.Spec.CPR

namespace Lean1090.Spec.CPR.Policy

/-- rs1090 cpr.rs haversine uses f64: comparisons with NaN are false,
including cases where rounding makes sqrt(1-a) invalid near antipodes. -/
inductive Distance where
  | finite (km : Rat)
  | nan
  | positiveInfinity
  | negativeInfinity
  deriving BEq, DecidableEq, Repr

/-- rs1090 cpr.rs `is_near_airport`: preserve airport coordinates and ICAO
identifier from the pinned airport data, including source iteration order. -/
structure Airport where
  icao : String
  position : Position
  deriving BEq, DecidableEq, Repr

/-- rs1090 cpr.rs numerical boundary: tested f64 haversine result, including
NaN and infinities. This is an explicit input to state semantics,
not an unspecified definition or an assumed theorem about trigonometry. -/
structure Geography where
  distanceKm : Position → Position → Distance
  airports : List Airport
  localPosition : Medium → Encoded → Position → Option Position
  globalPosition : Encoded → Encoded → Bool → Option Position

/-- rs1090 cpr.rs AircraftState: CPR state plus evidence needed by Comm-B.
All timestamps and distances carry finite binary64 values as exact rationals. -/
structure AircraftState where
  timestamp : Rat
  position : Option Position
  lastAltitude : Option Int
  airport : Option String
  seenBDS : List Nat
  supportedBDS : List Nat
  bds17Count : Nat
  oddTimestamp : Rat
  oddMessage : Option Encoded
  evenTimestamp : Rat
  evenMessage : Option Encoded
  deriving BEq, DecidableEq, Repr

/-- rs1090 cpr.rs ME match: only these non-position message types add evidence. -/
inductive OtherMessage where
  | identification | velocity | emergency | targetState | operationalStatus | reserved
  deriving BEq, DecidableEq, Repr

/-- rs1090 bds05.rs AirbornePosition fields visible to `UpdateIf`, beyond
CPR coordinates and altitude. The projected resolved coordinate is supplied
separately in `AirborneView`; the source callback runs only after resolution. -/
structure AirborneMetadata where
  nucP : Nat := 0
  surveillanceStatus : Nat := 0
  safOrNICb : Option Nat := none
  gnssSource : Bool := false
  timeSync : Bool := false
  deriving BEq, DecidableEq, Repr

/-- rs1090 cpr.rs `decode_position`: already-decoded position-bearing payload. -/
inductive Message where
  | airborne (code : Encoded) (altitude : Option Int) (metadata : AirborneMetadata)
  | surface (code : Encoded)
  | other (kind : OtherMessage)
  deriving BEq, DecidableEq, Repr

/-- rs1090 cpr.rs `UpdateIf`: every field of the successfully resolved
AirbornePosition is available, including status, integrity, source and time. -/
structure AirborneView where
  code : Encoded
  altitude : Option Int
  metadata : AirborneMetadata
  position : Position
  deriving BEq, DecidableEq, Repr

/-- rs1090 cpr.rs `UpdateIf`: caller-owned selection on a complete report. -/
abbrev UpdateReference := AirborneView → Bool

/-- rs1090 cpr.rs result: resolved output and the complete subsequent state.
None means the message remains unresolved, not that its raw CPR is discarded. -/
structure StepResult where
  state : AircraftState
  reference : Option Position
  resolved : Option Position
  outOfOrder : Bool
  deriving BEq, DecidableEq, Repr

/-- rs1090 cpr.rs `decode_positions`: an address-tagged already-decoded ADS-B
report, preserving source stream order. DF17 and DF18 route into this form. -/
structure TimedReport where
  address : Nat
  timestamp : Rat
  message : Message
  deriving BEq, DecidableEq, Repr

/-- rs1090 cpr.rs `decode_positions`: deterministic stream state. -/
structure StreamState where
  aircraft : List (Nat × AircraftState)
  reference : Option Position
  deriving BEq, DecidableEq, Repr

end Lean1090.Spec.CPR.Policy

/-!
REVIEW ONLY — NOT FROZEN; no executable declarations in this file.

The source below is copied verbatim from the pinned checkout. Every block names
the fully qualified declaration, original file/definition line, and exact source
span (one-based lines, zero-based columns, exclusive end). Original docstrings
are preserved. These are excerpts in original namespace/file context, enclosed
in comments to avoid redefining or importing the frozen specification.

Requested definitions (17):
  Lean1090.Spec.Valid: Spec/Message.lean:115
  Lean1090.Spec.ValidADSB: Spec/ADSB.lean:220
  Lean1090.Spec.ValidADSBFields: Spec/ADSB.lean:316
  Lean1090.Spec.ValidBDS: Spec/CommB.lean:301
  Lean1090.Spec.ValidBDSFields: Spec/CommB.lean:342
  Lean1090.Spec.CPR.LocalAdmissible: Spec/CPRContracts.lean:22
  Lean1090.Spec.CPR.GlobalAdmissible: Spec/CPRContracts.lean:45
  Lean1090.Spec.CPR.WithinResolution: Spec/CPRContracts.lean:35
  Lean1090.Spec.assigned: Spec/Message.lean:143
  Lean1090.Spec.Parity.polynomial: Spec/Parity.lean:37
  Lean1090.Spec.Parity.polynomialRemainder: Spec/Parity.lean:48
  Lean1090.Spec.CPR.nlFormula: Spec/CPRFormula.lean:13
  Lean1090.Spec.CPR.CertifiesTransition: Spec/CPRFormula.lean:105
  Lean1090.Spec.CPR.AvoidsDecodableLatitudes: Spec/CPRFormula.lean:111
  Lean1090.Spec.Altitude.Representable25: Spec/Altitude.lean:81
  Lean1090.Spec.Altitude.RepresentableGillham: Spec/Altitude.lean:56
  Lean1090.Spec.Altitude.validGillham: Spec/Altitude.lean:39

Completeness method:
  lake env lean scripts/review_dependencies.lean
  python3 scripts/write_review_defs.py
  python3 scripts/write_review_defs.py --check

The exporter follows every constant in elaborated declaration TYPES and BODIES,
including opaque bodies, recursively through all Spec/ and Model/ modules.
It found 365 project-local constants. All are mapped in the appendix to
216 exact authored source commands. Plain field accessors occur
inside their containing structures and need no separate snippet. Generated
constructors, recursors, pattern-match helpers, derived instances and proof
auxiliaries are mapped to the source command that generates them. No semantic
project-local helper is omitted. The raw graph is .cache/review-dependencies.json.

Library boundary: generic Lean/Std/Mathlib declarations are not recursively
expanded into the entire theorem-prover implementation. All 248 encountered/supplemented
library constants are listed by module and source location in the appendix;
12 relevant mathematical primitives (including actual
polynomial division, real inverse trig and rational floor) are copied as well.
Their own library dependencies remain at this explicit library boundary.

This file records current definitions, not a proof that their hypotheses are
realistic, their capstones proved, or their formulas faithful to the standard.
-/

/- REVIEW BLOCK 001 — REQUESTED
Declaration: Lean1090.Spec.Valid
Source: Spec/Message.lean:115
Source span: 111:0–115:54
Original module: Spec.Message
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Frame
import Spec.Parity
import Spec.CommB
import Spec.Semantics
import Spec.Assignment
BEGIN EXACT SOURCE
/-- Independent wire-field validity domain: field widths are enforced by
BitVec and the source/receiver predicates state parity and payload acceptance.
No report coherence or decoder result is a hypothesis. The complete semantic
report occurs in the round-trip conclusion, not inside this predicate. -/
def Valid (f : Frame) : Prop := frameAccepted f = true
END EXACT SOURCE
-/

/- REVIEW BLOCK 002 — REQUESTED
Declaration: Lean1090.Spec.ValidADSB
Source: Spec/ADSB.lean:220
Source span: 217:0–228:16
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Independent assignment-domain condition: fields fit the source table, the
chosen discriminants agree, and oracle acceptance constraints hold on the named
altitude/reserved fields. It never assumes the desired round-trip conclusion. -/
def ValidADSB (record : PayloadRecord) : Prop :=
  (adsbLayoutOfKind record.kind).elim False (fun layout =>
    ValidPayloadFields layout record.fields ∧ record.kind = adsbAssignmentKind record ∧
    (let tc := record.kind / 64
     if (9 ≤ tc ∧ tc ≤ 18) ∨ (20 ≤ tc ∧ tc ≤ 22) then
       altitudeCodeAdmissible ((payloadField record "altitude_code").getD 0) = true
     else if tc = 31 ∧ record.kind / 8 % 8 < 2 then
       payloadField record "cc_reserved0" = some 0 ∧ payloadField record "om_reserved" = some 0
     else True))
END EXACT SOURCE
-/

/- REVIEW BLOCK 003 — REQUESTED
Declaration: Lean1090.Spec.ValidADSBFields
Source: Spec/ADSB.lean:316
Source span: 313:0–318:86
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Source-table assignment domain from the cited ADSB layouts: exact bounds
and discriminants only. No50000ft or capability-reserved-bit oracle filter
narrows the full field-code round-trip guarantee. -/
def ValidADSBFields (record : PayloadRecord) : Prop :=
  (adsbLayoutOfKind record.kind).elim False (fun layout =>
    ValidPayloadFields layout record.fields ∧ record.kind = adsbAssignmentKind record)
END EXACT SOURCE
-/

/- REVIEW BLOCK 004 — REQUESTED
Declaration: Lean1090.Spec.ValidBDS
Source: Spec/CommB.lean:301
Source span: 298:0–305:80
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Field assignment validity is explicit schema bounds plus the independent
field constraints. It never assumes a round-trip conclusion. Discriminants are
retained as separately assigned fields, including subtype/version for BDS65. -/
def ValidBDS (record : PayloadRecord) : Prop :=
  match bdsAssignmentLayout record with
  | none => False
  | some layout => ValidPayloadFields layout record.fields ∧
      bdsWireValid record.kind (encodePayloadFields layout record.fields) = true
END EXACT SOURCE
-/

/- REVIEW BLOCK 005 — REQUESTED
Declaration: Lean1090.Spec.ValidBDSFields
Source: Spec/CommB.lean:342
Source span: 337:0–346:41
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Full representable field-code domain from the cited standard tables,
including speeds/heights outside the receiver's chosen physical envelope.
Only bounds, named-field shape and wire discriminants constrain assignments;
reserved and unavailable codes are retained, giving a domain at least as
broad as the tables' valid assignments. No inverse property is assumed. -/
def ValidBDSFields (record : PayloadRecord) : Prop :=
  match bdsAssignmentLayout record with
  | none => False
  | some layout => ValidPayloadFields layout record.fields ∧
      bdsFieldDiscriminants record = true
END EXACT SOURCE
-/

/- REVIEW BLOCK 006 — REQUESTED
Declaration: Lean1090.Spec.CPR.LocalAdmissible
Source: Spec/CPRContracts.lean:22
Source span: 19:0–26:54
Original module: Spec.CPRContracts
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.4–6: the reference must select the same nearest latitude
and longitude cells as the encoded quantized position. Strict half-cell
margins exclude ambiguous ties; there is no physical-latitude NL assumption. -/
def LocalAdmissible (mode : Medium) (odd : Bool) (p reference : Position) : Prop :=
  ValidPosition p ∧ ValidPosition reference ∧
  absQ (reference.lat - roundedLatitude mode odd p.lat) < dLat mode odd / 2 ∧
  longitudeDistance reference.lon (roundedLongitude mode odd p) <
    dLon mode odd (roundedLatitude mode odd p.lat) / 2
END EXACT SOURCE
-/

/- REVIEW BLOCK 007 — REQUESTED
Declaration: Lean1090.Spec.CPR.GlobalAdmissible
Source: Spec/CPRContracts.lean:45
Source span: 40:0–54:79
Original module: Spec.CPRContracts
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 008 — REQUESTED
Declaration: Lean1090.Spec.CPR.WithinResolution
Source: Spec/CPRContracts.lean:35
Source span: 33:0–38:71
Original module: Spec.CPRContracts
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3 rounding: half a transmitted coordinate step, with
circular longitude error. The inequality includes exact tie rounding. -/
def WithinResolution (mode : Medium) (odd : Bool) (original decoded : Position) : Prop :=
  absQ (decoded.lat - original.lat) ≤ dLat mode odd / (2 * scale) ∧
  longitudeDistance decoded.lon original.lon ≤
    dLon mode odd (roundedLatitude mode odd original.lat) / (2 * scale)
END EXACT SOURCE
-/

/- REVIEW BLOCK 009 — REQUESTED
Declaration: Lean1090.Spec.assigned
Source: Spec/Message.lean:143
Source span: 140:0–143:70
Original module: Spec.Message
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Frame
import Spec.Parity
import Spec.CommB
import Spec.Semantics
import Spec.Assignment
BEGIN EXACT SOURCE
/-- Annex10 IV independent encoder-side assignment. Its expected report is
assembled from source columns and separate altitude bit arithmetic, without
calling any decoder or decoder-only helper. Checked transitively by the gate. -/
def assigned (f : Frame) : Message := ⟨f, Assignment.expectedReport f⟩
END EXACT SOURCE
-/

/- REVIEW BLOCK 010 — REQUESTED
Declaration: Lean1090.Spec.Parity.polynomial
Source: Spec/Parity.lean:37
Source span: 35:0–39:78
Original module: Spec.Parity
Original imports/opens:
namespace Lean1090.Spec.Parity
import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: a wire word as a polynomial
over GF(2); LSB bit i is the coefficient of X^i. -/
noncomputable def polynomial (width word : Nat) : Polynomial (ZMod 2) :=
  (List.range width).foldl
    (fun p i => p + Polynomial.monomial i (if word.testBit i then 1 else 0)) 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 011 — REQUESTED
Declaration: Lean1090.Spec.Parity.polynomialRemainder
Source: Spec/Parity.lean:48
Source span: 47:0–49:56
Original module: Spec.Parity
Original imports/opens:
namespace Lean1090.Spec.Parity
import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: mathematical polynomial division. -/
noncomputable def polynomialRemainder (width word : Nat) : Polynomial (ZMod 2) :=
  (polynomial width word).modByMonic generatorPolynomial
END EXACT SOURCE
-/

/- REVIEW BLOCK 012 — REQUESTED
Declaration: Lean1090.Spec.CPR.nlFormula
Source: Spec/CPRFormula.lean:13
Source span: 11:0–20:46
Original module: Spec.CPRFormula
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Inverse
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(f), Sun, 2nd ed. (2021), ch.5 NL: real transcendental definition with
explicit equator/pole conventions. Equality ±87° uses the standard value2. -/
noncomputable def nlFormula (lat : ℝ) : Nat := by
  classical
  exact if lat = 0 then 59
    else if |lat| = 87 then 2
    else if 87 < |lat| then 1
    else Int.toNat ⌊2 * Real.pi / Real.arccos
      (1 - (1 - Real.cos (Real.pi / 30)) /
        (Real.cos (Real.pi / 180 * lat)) ^ 2)⌋
END EXACT SOURCE
-/

/- REVIEW BLOCK 013 — REQUESTED
Declaration: Lean1090.Spec.CPR.CertifiesTransition
Source: Spec/CPRFormula.lean:105
Source span: 104:0–107:60
Original module: Spec.CPRFormula
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Inverse
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(f) note5: proof obligation for the transcendental bound. -/
def CertifiesTransition (c : NLCertificate) : Prop :=
  (c.lower12 : ℝ) / 1000000000000 < transitionFormula c.zone ∧
  transitionFormula c.zone < (c.upper12 : ℝ) / 1000000000000
END EXACT SOURCE
-/

/- REVIEW BLOCK 014 — REQUESTED
Declaration: Lean1090.Spec.CPR.AvoidsDecodableLatitudes
Source: Spec/CPRFormula.lean:111
Source span: 109:0–114:51
Original module: Spec.CPRFormula
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Inverse
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(b): no reconstructible latitude is close enough to the
transition for table rounding to change its NL value. -/
def AvoidsDecodableLatitudes (c : NLCertificate) : Prop :=
  ∀ lat, DecodableLatitude lat →
    ¬ ((c.lower12 : Rat) / 1000000000000 ≤ absQ lat ∧
      absQ lat ≤ (c.upper12 : Rat) / 1000000000000)
END EXACT SOURCE
-/

/- REVIEW BLOCK 015 — REQUESTED
Declaration: Lean1090.Spec.Altitude.Representable25
Source: Spec/Altitude.lean:81
Source span: 80:0–82:60
Original module: Spec.Altitude
Original imports/opens:
namespace Lean1090.Spec.Altitude
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: N is an unsigned 11-bit integer. -/
def Representable25 (height : Int) : Prop :=
  -1000 ≤ height ∧ height ≤ 50175 ∧ (height + 1000) % 25 = 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 016 — REQUESTED
Declaration: Lean1090.Spec.Altitude.RepresentableGillham
Source: Spec/Altitude.lean:56
Source span: 55:0–57:53
Original module: Spec.Altitude
Original imports/opens:
namespace Lean1090.Spec.Altitude
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: exact domain of its 8+3-bit Gillham construction. -/
def RepresentableGillham (height : Int) : Prop :=
  -1200 ≤ height ∧ height ≤ 126700 ∧ height % 100 = 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 017 — REQUESTED
Declaration: Lean1090.Spec.Altitude.validGillham
Source: Spec/Altitude.lean:39
Source span: 38:0–42:30
Original module: Spec.Altitude
Original imports/opens:
namespace Lean1090.Spec.Altitude
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: decoded C counts 0, 5 and 6 are invalid. -/
def validGillham (word : Nat) : Bool :=
  let c := grayDecode 3 (gray100 word)
  word < 8192 && bit word 6 == 0 && bit word 4 == 0 &&
    c != 0 && c != 5 && c != 6
END EXACT SOURCE
-/

/- REVIEW BLOCK 018 — DEPENDENCY
Declaration: Lean1090.Spec.PayloadCoding
Source: Model/Types.lean:15
Source span: 14:0–17:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- Wire-code interpretation. Two's complement is used by Sun, ch.17 tables 17.2–17.3. -/
inductive PayloadCoding where
  | unsigned | twosComplement
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 019 — DEPENDENCY
Declaration: Lean1090.Spec.PayloadColumn
Source: Model/Types.lean:21
Source span: 19:0–29:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 020 — DEPENDENCY
Declaration: Lean1090.Spec.PayloadField
Source: Model/Types.lean:33
Source span: 31:0–36:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- A single standard field assignment is its lossless wire code. Keeping the
code distinguishes unavailable values, reserved values, and quantization bins. -/
structure PayloadField where
  name : String
  code : Nat
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 021 — DEPENDENCY
Declaration: Lean1090.Spec.PayloadRecord
Source: Model/Types.lean:40
Source span: 38:0–43:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- Source-table field assignments; the kind chooses the independent layout.
No original payload word is retained. -/
structure PayloadRecord where
  kind : Nat
  fields : List PayloadField
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 022 — DEPENDENCY
Declaration: Lean1090.Spec.Altitude.Value
Source: Model/Types.lean:56
Source span: 55:0–59:33
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.Altitude
import Std
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: feet and metres are distinct field meanings. -/
inductive Value where
  | feet (height : Int)
  | metres (height : Nat)
  deriving BEq, DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 023 — DEPENDENCY
Declaration: Lean1090.Spec.ACASFields
Source: Model/Types.lean:73
Source span: 71:0–82:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 024 — DEPENDENCY
Declaration: Lean1090.Spec.SurveillanceFields
Source: Model/Types.lean:86
Source span: 84:0–91:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §§3.1.2.6.5–8: surveillance header.
`code` is AC13 for altitude replies and ID13 for identity replies. -/
structure SurveillanceFields where
  fs : BitVec 3
  dr : BitVec 5
  um : BitVec 6
  code : BitVec 13
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 025 — DEPENDENCY
Declaration: Lean1090.Spec.FrameBody
Source: Model/Types.lean:96
Source span: 93:0–106:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 026 — DEPENDENCY
Declaration: Lean1090.Spec.Frame
Source: Model/Types.lean:111
Source span: 108:0–114:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.2.1: transmitted fields plus the
final 24 bits. For DF19 these are uninterpreted reserved military bits;
for the other constructors they carry the AP or PI field. -/
structure Frame where
  body : FrameBody
  parity : BitVec 24
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 027 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.Precision
Source: Model/Types.lean:121
Source span: 120:0–123:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Std
BEGIN EXACT SOURCE
/-- rs1090 bds09.rs/bds62.rs: distinguish binary32 intermediates from binary64. -/
inductive Precision where
  | binary32 | binary64
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 028 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.FloatExpr
Source: Model/Types.lean:130
Source span: 125:0–140:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Std
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 029 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.Missing
Source: Model/Types.lean:143
Source span: 142:0–145:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Std
BEGIN EXACT SOURCE
/-- rs1090 serde policy: unavailable numeric keys can be omitted or null. -/
inductive Missing where
  | omit | null
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 030 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.NumericField
Source: Model/Types.lean:149
Source span: 147:0–153:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Std
BEGIN EXACT SOURCE
/-- rs1090-derived output key and optional floating formula. Presence/absence
is decided from exact field codes, before evaluating any Float expression. -/
structure NumericField where
  key : String
  value : Option FloatExpr
  missing : Missing
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 031 — DEPENDENCY
Declaration: Lean1090.Spec.CommBThreat
Source: Model/Types.lean:162
Source span: 159:0–167:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.5–6 threat data; unused raw values
remain in PayloadRecord while these projections expose reported meanings.
Range is exact before the oracle's f32 presentation conversion. -/
inductive CommBThreat where
  | none
  | address (icao24 : Nat)
  | orientation (altitude : Option Int) (rangeNM : Option Rat) (bearingDeg : Option Nat)
  | unassigned
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 032 — DEPENDENCY
Declaration: Lean1090.Spec.StandardThreatRange
Source: Model/Types.lean:172
Source span: 169:0–177:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV (4th ed., amendment85), §4.3.8.4.2.2.1.6.2:
TIDR is a quantized range with separate unavailable and saturation codes,
not an unrestricted numeric point estimate. Units are nautical miles. -/
inductive StandardThreatRange where
  | unavailable
  | lessThan (upper : Rat)
  | estimate (centre tolerance : Rat)
  | greaterThan (lower : Rat)
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 033 — DEPENDENCY
Declaration: Lean1090.Spec.StandardThreatBearing
Source: Model/Types.lean:182
Source span: 179:0–186:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV (4th ed., amendment85), §4.3.8.4.2.2.1.6.3:
TIDB gives a six-degree bearing sector, with61–63 unassigned. Sector endpoints
are recorded without inventing an open/closed endpoint convention. -/
inductive StandardThreatBearing where
  | unavailable
  | sector (lower upper : Nat)
  | unassigned (code : Nat)
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 034 — DEPENDENCY
Declaration: Lean1090.Spec.StandardCommBThreat
Source: Model/Types.lean:191
Source span: 188:0–197:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 035 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.Values
Source: Model/Types.lean:206
Source span: 204:0–206:43
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Std
open Presentation
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), tables5.1–8.3 and16.1–18.2; ICAO Annex10 IV, 4th ed. (2007), tables3-6/3-8/3-10: exact physical/code values before Float.
An absent value is different from zero and from an unlisted field. -/
abbrev Values := List (String × Option Rat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 036 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.Labels
Source: Model/Types.lean:209
Source span: 208:0–209:46
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Std
open Presentation
BEGIN EXACT SOURCE
/-- rs1090-derived enum/string projection, with explicit unavailability. -/
abbrev Labels := List (String × Option String)
END EXACT SOURCE
-/

/- REVIEW BLOCK 037 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.Payload
Source: Model/Types.lean:213
Source span: 211:0–223:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Std
open Presentation
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 038 — DEPENDENCY
Declaration: Lean1090.Spec.Report
Source: Model/Types.lean:234
Source span: 229:0–244:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
open Presentation
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 039 — DEPENDENCY
Declaration: Lean1090.Spec.Message
Source: Model/Types.lean:248
Source span: 246:0–251:28
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec
import Std
open Presentation
BEGIN EXACT SOURCE
/-- Lossless field assignment and its exact semantic views. Annex10 IV layouts
are represented by `Frame`; the report carries named payload decompositions. -/
structure Message where
  fields : Frame
  decoded : Report
  deriving DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 040 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.Medium
Source: Model/Types.lean:258
Source span: 257:0–261:33
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.CPR
import Std
open Presentation
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.1 note5 and §2.6.6: surface ambiguity span is 90°. -/
inductive Medium where
  | airborne
  | surface
  deriving BEq, DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 041 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.Position
Source: Model/Types.lean:264
Source span: 263:0–267:33
Original module: Model.Types
Original imports/opens:
namespace Lean1090.Spec.CPR
import Std
open Presentation
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3: geographic coordinates measured in exact degrees. -/
structure Position where
  lat : Rat
  lon : Rat
  deriving BEq, DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 042 — DEPENDENCY
Declaration: Lean1090.Spec.adsbIdentificationLayout
Source: Spec/ADSB.lean:23
Source span: 22:0–25:88
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., ch.4 layout diagram: TC, category and eight six-bit symbols. -/
def adsbIdentificationLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "category", start := 6, width := 3}] ++
  (List.range 8).map fun i => {name := "char" ++ toString i, start := 9+6*i, width := 6}
END EXACT SOURCE
-/

/- REVIEW BLOCK 043 — DEPENDENCY
Declaration: Lean1090.Spec.adsbPositionLayout
Source: Spec/ADSB.lean:28
Source span: 27:0–32:96
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table5.1: airborne position and barometric/GNSS altitude code. -/
def adsbPositionLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "ss", start := 6, width := 2},
   {name := "saf_or_nicb", start := 8, width := 1}, {name := "altitude_code", start := 9, width := 12},
   {name := "time_sync", start := 21, width := 1}, {name := "parity", start := 22, width := 1},
   {name := "lat_cpr", start := 23, width := 17}, {name := "lon_cpr", start := 40, width := 17}]
END EXACT SOURCE
-/

/- REVIEW BLOCK 044 — DEPENDENCY
Declaration: Lean1090.Spec.adsbSurfaceLayout
Source: Spec/ADSB.lean:35
Source span: 34:0–40:96
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table6.1: surface movement, track, time and CPR fields. -/
def adsbSurfaceLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "movement", start := 6, width := 7},
   {name := "track_status", start := 13, width := 1},
   {name := "track", start := 14, width := 7, scale := 360/128, status := 13},
   {name := "time_sync", start := 21, width := 1}, {name := "parity", start := 22, width := 1},
   {name := "lat_cpr", start := 23, width := 17}, {name := "lon_cpr", start := 40, width := 17}]
END EXACT SOURCE
-/

/- REVIEW BLOCK 045 — DEPENDENCY
Declaration: Lean1090.Spec.adsbVelocityLayout
Source: Spec/ADSB.lean:44
Source span: 42:0–58:108
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., tables7.1–7.3: velocity variants. Reserved subtype payload
preservation is rs1090-derived, bds09.rs ReservedVelocityData. -/
def adsbVelocityLayout (subtype : Nat) : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
   {name := "intent_change", start := 9, width := 1}, {name := "ifr_capability", start := 10, width := 1},
   {name := "NACv", start := 11, width := 3}] ++
  (if subtype == 1 || subtype == 2 then
    [{name := "ew_sign", start := 14, width := 1}, {name := "ew_velocity", start := 15, width := 10},
     {name := "ns_sign", start := 25, width := 1}, {name := "ns_velocity", start := 26, width := 10}]
   else if subtype == 3 || subtype == 4 then
    [{name := "heading_status", start := 14, width := 1},
     {name := "heading", start := 15, width := 10, scale := 360/1024, status := 14},
     {name := "airspeed_type", start := 25, width := 1}, {name := "airspeed_code", start := 26, width := 10}]
   else [{name := "reserved_data", start := 14, width := 22}]) ++
  [{name := "vrate_source", start := 36, width := 1}, {name := "vrate_sign", start := 37, width := 1},
   {name := "vertical_rate_code", start := 38, width := 9}, {name := "reserved", start := 47, width := 2},
   {name := "gnss_sign", start := 49, width := 1}, {name := "geo_minus_baro_code", start := 50, width := 7}]
END EXACT SOURCE
-/

/- REVIEW BLOCK 046 — DEPENDENCY
Declaration: Lean1090.Spec.adsbStatusLayout
Source: Spec/ADSB.lean:63
Source span: 60:0–66:48
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived: bds61.rs AircraftStatus reads this same layout for ALL
subtypes, including ACAS-RA; no independently read ICAO table supports that
choice. The unused tail is retained for exact field reconstruction. -/
def adsbStatusLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
   {name := "emergency_state", start := 9, width := 3}, {name := "squawk_code", start := 12, width := 13},
   {name := "unused", start := 25, width := 32}]
END EXACT SOURCE
-/

/- REVIEW BLOCK 047 — DEPENDENCY
Declaration: Lean1090.Spec.adsbTargetLayout
Source: Spec/ADSB.lean:70
Source span: 68:0–84:50
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived: bds62.rs TargetStateAndStatusInformation. TC29's subtype
is TWO bits; its value does not alter the oracle's chosen layout. -/
def adsbTargetLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 2},
   {name := "reserved0", start := 8, width := 1}, {name := "alt_source", start := 9, width := 1},
   {name := "selected_altitude_code", start := 10, width := 11},
   {name := "barometric_setting_code", start := 21, width := 9},
   {name := "heading_status", start := 30, width := 1},
   {name := "selected_heading", start := 31, width := 9, scale := 180/256, status := 30},
   {name := "NACp", start := 40, width := 4}, {name := "nic_baro", start := 44, width := 1},
   {name := "SIL", start := 45, width := 2}, {name := "mode_status", start := 47, width := 1},
   {name := "autopilot", start := 48, width := 1, status := 47},
   {name := "vnav_mode", start := 49, width := 1, status := 47},
   {name := "alt_hold", start := 50, width := 1, status := 47}, {name := "imf", start := 51, width := 1},
   {name := "approach_mode", start := 52, width := 1, status := 47},
   {name := "tcas_operational", start := 53, width := 1}, {name := "lnav_mode", start := 54, width := 1, status := 47},
   {name := "reserved1", start := 55, width := 2}]
END EXACT SOURCE
-/

/- REVIEW BLOCK 048 — DEPENDENCY
Declaration: Lean1090.Spec.adsbOperationPrefix
Source: Spec/ADSB.lean:89
Source span: 86:0–108:48
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., tables8.2/8.3 give enclosing blocks; individual bit names
inside CC/OM are rs1090-derived from bds65.rs CapabilityClass/OperationalMode.
Airborne skips bits33–40; surface calls those GPS antenna offset. -/
def adsbOperationPrefix (surface : Bool) : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
   {name := "cc_reserved0", start := 9, width := 2}] ++
  (if surface then
    [{name := "poe", start := 11, width := 1}, {name := "1090ES", start := 12, width := 1},
     {name := "cc_reserved1", start := 13, width := 2}, {name := "GRND", start := 15, width := 1},
     {name := "UATin", start := 16, width := 1}, {name := "NACv", start := 17, width := 3},
     {name := "NICc", start := 20, width := 1}, {name := "lw_codes", start := 21, width := 4}]
   else
    [{name := "ACAS", start := 11, width := 1}, {name := "CDTI", start := 12, width := 1},
     {name := "cc_reserved1", start := 13, width := 2}, {name := "ARV", start := 15, width := 1},
     {name := "TS", start := 16, width := 1}, {name := "TC", start := 17, width := 2},
     {name := "cc_padding", start := 19, width := 6}]) ++
  [{name := "om_reserved", start := 25, width := 2}, {name := "tcas_ra_active", start := 27, width := 1},
   {name := "ident_switch_active", start := 28, width := 1},
   {name := "reserved_recv_atc_service", start := 29, width := 1},
   {name := "single_antenna_flag", start := 30, width := 1},
   {name := "system_design_assurance", start := 31, width := 2},
   {name := if surface then "gps_antenna_offset" else "om_padding", start := 33, width := 8},
   {name := "version", start := 41, width := 3}]
END EXACT SOURCE
-/

/- REVIEW BLOCK 049 — DEPENDENCY
Declaration: Lean1090.Spec.adsbOperationSuffix
Source: Spec/ADSB.lean:112
Source span: 110:0–124:66
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., tables8.2/8.3: version1/2 trailer. Version0 and3–7
opaque treatment is rs1090-derived from bds65.rs ADSBVersionAirborne/Surface. -/
def adsbOperationSuffix (surface : Bool) (version : Nat) : List PayloadColumn :=
  if version == 1 || version == 2 then
    [{name := if version == 1 then "NICs" else "NICa", start := 44, width := 1},
     {name := "NACp", start := 45, width := 4},
     {name := if surface then "reserved_accuracy" else if version == 1 then "BAQ" else "GVA",
       start := 49, width := 2},
     {name := "SIL", start := 51, width := 2},
     {name := if surface then "TAH" else "BAI", start := 53, width := 1},
     {name := "HRD", start := 54, width := 1}] ++
    (if version == 2 then [{name := "SILs", start := 55, width := 1},
                           {name := "reserved_tail", start := 56, width := 1}]
     else [{name := "reserved_tail", start := 55, width := 2}])
  else [{name := "unused_version_tail", start := 44, width := 13}]
END EXACT SOURCE
-/

/- REVIEW BLOCK 050 — DEPENDENCY
Declaration: Lean1090.Spec.adsbKind
Source: Spec/ADSB.lean:128
Source span: 126:0–132:61
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table3.3 plus explicitly rs1090-derived reserved ME variants:
exact layout selector key tc*64+subtype*8+version; irrelevant components zero. -/
def adsbKind (word : Nat) : Nat :=
  let tc := payloadBits word 1 5
  let st := if tc == 29 then payloadBits word 6 2 else payloadBits word 6 3
  tc * 64 + (if tc == 19 || tc == 28 || tc == 29 || tc == 31 then st * 8 else 0) +
    (if tc == 31 && st < 2 then payloadBits word 41 3 else 0)
END EXACT SOURCE
-/

/- REVIEW BLOCK 051 — DEPENDENCY
Declaration: Lean1090.Spec.adsbLayoutOfKind
Source: Spec/ADSB.lean:136
Source span: 134:0–154:107
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., cited individual layouts; all32 typecodes and every oracle
subtype are represented. Reserved codes remain distinct, not invalidated. -/
def adsbLayoutOfKind (kind : Nat) : Option (List PayloadColumn) :=
  let tc := kind / 64
  let st := kind / 8 % 8
  let version := kind % 8
  if tc > 31 then none else
  if tc >= 1 && tc <= 4 then some adsbIdentificationLayout
  else if tc >= 5 && tc <= 8 then some adsbSurfaceLayout
  else if (tc >= 9 && tc <= 18) || (tc >= 20 && tc <= 22) then some adsbPositionLayout
  else if tc == 19 then some (adsbVelocityLayout st)
  else if tc == 28 then some adsbStatusLayout
  else if tc == 29 then some adsbTargetLayout
  else if tc == 31 then
    if st < 2 then some (adsbOperationPrefix (st == 1) ++ adsbOperationSuffix (st == 1) version)
    else some [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
               {name := "reserved_status_data", start := 9, width := 40}, {name := "ignored_tail", start := 49, width := 8}]
  else if tc >= 25 && tc <= 27 then
    some [{name := "tc", start := 1, width := 5}, {name := "unused", start := 6, width := 8},
          {name := "ignored_tail", start := 14, width := 43}]
  else some [{name := "tc", start := 1, width := 5}, {name := "reserved_payload", start := 6, width := 51}]
END EXACT SOURCE
-/

/- REVIEW BLOCK 052 — DEPENDENCY
Declaration: Lean1090.Spec.adsbLayout
Source: Spec/ADSB.lean:157
Source span: 156:0–157:93
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table3.3 and individual layouts: select from received fields. -/
def adsbLayout (word : Nat) : Option (List PayloadColumn) := adsbLayoutOfKind (adsbKind word)
END EXACT SOURCE
-/

/- REVIEW BLOCK 053 — DEPENDENCY
Declaration: Lean1090.Spec.altitudeCodeAdmissible
Source: Spec/ADSB.lean:169
Source span: 164:0–179:35
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived 50000ft acceptance limit, stated independently on the
altitude code: Q=1's unsigned count is at most2040; a valid Gillham count
must satisfy500*N500+100*N100≤51300. Invalid Gillham is accepted as missing.
This predicate neither calls an altitude decoder nor assumes its result. The
Gray arithmetic and code validity are Sun2nded.(2021), ch.13 Altitude code. -/
def altitudeCodeAdmissible (code : Nat) : Bool :=
  code < 4096 &&
  (if Altitude.bit code 4 == 1 then code / 32 * 16 + code % 16 ≤ 2040
   else
     let word := code / 64 * 128 + code % 64
     if !Altitude.validGillham word then true else
       let n500 := Altitude.grayDecode 8 (Altitude.gray500 word)
       let c := Altitude.grayDecode 3 (Altitude.gray100 word)
       let c := if c == 7 then 5 else c
       let n100 := if n500 % 2 == 1 then 6-c else c
       500*n500 + 100*n100 ≤ 51300)
END EXACT SOURCE
-/

/- REVIEW BLOCK 054 — DEPENDENCY
Declaration: Lean1090.Spec.adsbHardValid
Source: Spec/ADSB.lean:183
Source span: 181:0–189:11
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived bds05.rs altitude ceiling and bds65.rs two reserved-bit
assertions; these are receiver acceptance policies, not standard valid-code claims. -/
def adsbHardValid (word : Nat) : Bool :=
  let tc := payloadBits word 1 5
  if (tc >= 9 && tc <= 18) || (tc >= 20 && tc <= 22) then
    altitudeCodeAdmissible (payloadBits word 9 12)
  else if tc == 31 && payloadBits word 6 3 < 2 then
    payloadBits word 9 2 == 0 && payloadBits word 25 2 == 0
  else true
END EXACT SOURCE
-/

/- REVIEW BLOCK 055 — DEPENDENCY
Declaration: Lean1090.Spec.adsbAssignmentKind
Source: Spec/ADSB.lean:210
Source span: 208:0–215:47
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed. layout discriminants: canonical kind computed from named field
assignments, independently of wire decoding and without invoking the encoder. -/
def adsbAssignmentKind (record : PayloadRecord) : Nat :=
  let tc := (payloadField record "tc").getD 0
  let st := (payloadField record "subtype").getD 0
  let version := (payloadField record "version").getD 0
  tc * 64 + (if tc == 19 || tc == 28 || tc == 29 || tc == 31 then st * 8 else 0) +
    (if tc == 31 && st < 2 then version else 0)
END EXACT SOURCE
-/

/- REVIEW BLOCK 056 — DEPENDENCY
Declaration: Lean1090.Spec.adsbCharacter
Source: Spec/ADSB.lean:232
Source span: 230:0–235:38
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., ch.4 §4.1 character alphabet; undefined six-bit codes map
'#' as rs1090 bds08.rs does. Spaces are dealt with by the presentation policy. -/
def adsbCharacter (code : Nat) : Char :=
  if 1 ≤ code && code ≤ 26 then Char.ofNat (64 + code)
  else if 48 ≤ code && code ≤ 57 then Char.ofNat code
  else if code == 32 then ' ' else '#'
END EXACT SOURCE
-/

/- REVIEW BLOCK 057 — DEPENDENCY
Declaration: Lean1090.Spec.adsbCallsign
Source: Spec/ADSB.lean:239
Source span: 237:0–241:62
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived bds08.rs callsign_read removes ALL space symbols,
including embedded spaces. Raw codes remain available for bit round-trips. -/
def adsbCallsign (word : Nat) : String :=
  String.ofList (((List.range 8).map (fun i => payloadBits word (9+6*i) 6)).filterMap
    fun c => if c == 32 then none else some (adsbCharacter c))
END EXACT SOURCE
-/

/- REVIEW BLOCK 058 — DEPENDENCY
Declaration: Lean1090.Spec.adsbMovement
Source: Spec/ADSB.lean:245
Source span: 243:0–254:15
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table6.2: exact lower endpoints of movement quantization bins.
Code124 denotes at least175kt and is reported as175kt by the oracle. -/
def adsbMovement (code : Nat) : Option Rat :=
  if code == 0 || code >= 125 then none
  else if code == 1 then some 0
  else if code <= 8 then some ((code - 1 : Nat) / 8)
  else if code <= 12 then some (1 + (code - 9 : Nat) / 4)
  else if code <= 38 then some (2 + (code - 13 : Nat) / 2)
  else if code <= 93 then some (15 + (code - 39 : Nat))
  else if code <= 108 then some (70 + 2 * (code - 94 : Nat))
  else if code <= 123 then some (100 + 5 * (code - 109 : Nat))
  else some 175
END EXACT SOURCE
-/

/- REVIEW BLOCK 059 — DEPENDENCY
Declaration: Lean1090.Spec.adsbSigned
Source: Spec/ADSB.lean:257
Source span: 256:0–258:53
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., tables7.1–7.3: sign-magnitude arithmetic before Float output. -/
def adsbSigned (sign magnitude : Nat) : Int :=
  if sign == 0 then magnitude else -(magnitude : Int)
END EXACT SOURCE
-/

/- REVIEW BLOCK 060 — DEPENDENCY
Declaration: Lean1090.Spec.adsbVerticalRate
Source: Spec/ADSB.lean:261
Source span: 260:0–263:85
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table7.1: unavailable vertical rate code0; otherwise64ft/min. -/
def adsbVerticalRate (word : Nat) : Option Int :=
  let code := payloadBits word 38 9
  if code == 0 then none else some (adsbSigned (payloadBits word 37 1) ((code-1)*64))
END EXACT SOURCE
-/

/- REVIEW BLOCK 061 — DEPENDENCY
Declaration: Lean1090.Spec.adsbGeoMinusBaro
Source: Spec/ADSB.lean:267
Source span: 265:0–269:85
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived bds09.rs read_geobaro: codes0 AND1 yield none; code127
is decoded. This differs from the availability prose in Sun §7.2. -/
def adsbGeoMinusBaro (word : Nat) : Option Int :=
  let code := payloadBits word 50 7
  if code <= 1 then none else some (adsbSigned (payloadBits word 49 1) ((code-1)*25))
END EXACT SOURCE
-/

/- REVIEW BLOCK 062 — DEPENDENCY
Declaration: Lean1090.Spec.adsbAirspeed
Source: Spec/ADSB.lean:272
Source span: 271:0–275:66
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table7.3: true/indicated airspeed, with factor4 for subtype4. -/
def adsbAirspeed (word : Nat) : Option Nat :=
  let code := payloadBits word 26 10
  if code == 0 then none else
    some ((code - 1) * if payloadBits word 6 3 == 4 then 4 else 1)
END EXACT SOURCE
-/

/- REVIEW BLOCK 063 — DEPENDENCY
Declaration: Lean1090.Spec.adsbOracleVelocityComponents
Source: Spec/ADSB.lean:280
Source span: 277:0–284:62
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived bds09.rs GroundSpeedDecoding: subtype2 shares subtype1's
unscaled components and zero codes become -1 before sign. The standard
subtype2 factor4 and missing-value rules are separately described in THEOREMS.md. -/
def adsbOracleVelocityComponents (word : Nat) : Int × Int :=
  let component := fun sign code =>
    (if sign == 0 then 1 else -1 : Int) * ((code : Int) - 1)
  (component (payloadBits word 14 1) (payloadBits word 15 10),
   component (payloadBits word 25 1) (payloadBits word 26 10))
END EXACT SOURCE
-/

/- REVIEW BLOCK 064 — DEPENDENCY
Declaration: Lean1090.Spec.adsbSelectedAltitude
Source: Spec/ADSB.lean:288
Source span: 286:0–290:61
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived bds62.rs: selected altitude is rounded by integer arithmetic
`((32*(code-1)+16)/100)*100`; codes0/1 are unavailable. -/
def adsbSelectedAltitude (word : Nat) : Option Nat :=
  let code := payloadBits word 10 11
  if code <= 1 then none else some (((code-1)*32+16)/100*100)
END EXACT SOURCE
-/

/- REVIEW BLOCK 065 — DEPENDENCY
Declaration: Lean1090.Spec.adsbBarometricSetting
Source: Spec/ADSB.lean:294
Source span: 292:0–296:71
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- rs1090-derived bds62.rs: exact input to the separately tested f32 formula
`800.0f32 + (code-1) as f32 * 0.8f32`; zero is unavailable. -/
def adsbBarometricSetting (word : Nat) : Option Rat :=
  let code := payloadBits word 21 9
  if code == 0 then none else some (800 + (code-1 : Nat) * (4/5 : Rat))
END EXACT SOURCE
-/

/- REVIEW BLOCK 066 — DEPENDENCY
Declaration: Lean1090.Spec.adsbNUCp
Source: Spec/ADSB.lean:300
Source span: 298:0–302:79
Original module: Spec.ADSB
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame
BEGIN EXACT SOURCE
/-- Sun 2nd ed., ch.9 table9.3 and rs1090 bds05/06 output convention:
NUCp comes directly from TC, not from the decoded CPR position. -/
def adsbNUCp (tc : Nat) : Nat :=
  if 5 ≤ tc && tc ≤ 8 then 14 - tc
  else if tc < 19 then 18 - tc else if tc == 20 || tc == 21 then 29 - tc else 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 067 — DEPENDENCY
Declaration: Lean1090.Spec.Altitude.bit
Source: Spec/Altitude.lean:20
Source span: 19:0–20:58
Original module: Spec.Altitude
Original imports/opens:
namespace Lean1090.Spec.Altitude
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”, bit permutation: select one LSB-indexed bit. -/
def bit (word place : Nat) : Nat := (word / 2 ^ place) % 2
END EXACT SOURCE
-/

/- REVIEW BLOCK 068 — DEPENDENCY
Declaration: Lean1090.Spec.Altitude.grayDecode
Source: Spec/Altitude.lean:23
Source span: 22:0–25:57
Original module: Spec.Altitude
Original imports/opens:
namespace Lean1090.Spec.Altitude
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”, reflected Gray code: prefix-XOR its bits. -/
def grayDecode (width word : Nat) : Nat :=
  (List.range width).foldl
    (fun binary index => binary ^^^ (word / 2 ^ index)) 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 069 — DEPENDENCY
Declaration: Lean1090.Spec.Altitude.gray500
Source: Spec/Altitude.lean:31
Source span: 30:0–32:79
Original module: Spec.Altitude
Original imports/opens:
namespace Lean1090.Spec.Altitude
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: D2 D4 A1 A2 A4 B1 B2 B4 order. -/
def gray500 (word : Nat) : Nat :=
  [2, 0, 11, 9, 7, 5, 3, 1].foldl (fun acc place => 2 * acc + bit word place) 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 070 — DEPENDENCY
Declaration: Lean1090.Spec.Altitude.gray100
Source: Spec/Altitude.lean:35
Source span: 34:0–36:48
Original module: Spec.Altitude
Original imports/opens:
namespace Lean1090.Spec.Altitude
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: C1 C2 C4 order. -/
def gray100 (word : Nat) : Nat :=
  4 * bit word 12 + 2 * bit word 10 + bit word 8
END EXACT SOURCE
-/

/- REVIEW BLOCK 071 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.columnCode
Source: Spec/Assignment.lean:23
Source span: 20:0–25:59
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV, fourth edition (2007), table3-3: assigned payload bits
are numbered1…56 from the MSB. Build each field one bit at a time instead of
calling the reference decoder's division/modulus field reader. -/
def columnCode (word start width : Nat) : Nat :=
  (List.range width).foldl (fun value i =>
    2*value + if word.testBit (56-start-i) then 1 else 0) 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 072 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.payloadAssignment
Source: Spec/Assignment.lean:30
Source span: 27:0–31:72
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV, fourth edition (2007), table3-3; Sun, second edition
(2021), tables5.1–8.3 and16.1–18.2: construct independent named assignments
in published column order, including reserved/status/unavailable codes. -/
def payloadAssignment (kind word : Nat) (columns : List PayloadColumn) : PayloadRecord :=
  ⟨kind, columns.map fun c => ⟨c.name, columnCode word c.start c.width⟩⟩
END EXACT SOURCE
-/

/- REVIEW BLOCK 073 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.adsbAssignment
Source: Spec/Assignment.lean:36
Source span: 33:0–38:66
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- Sun, second edition (2021), table3.3 and tables5.1–8.3: the chosen TC,
subtype and version determine the source-table assignment. Receiver rejection
is stated by adsbHardValid independently of payload record construction. -/
def adsbAssignment (word : Nat) : Option PayloadRecord :=
  if word ≥ 2^56 || !adsbHardValid word then none else
    (adsbLayout word).map (payloadAssignment (adsbKind word) word)
END EXACT SOURCE
-/

/- REVIEW BLOCK 074 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.candidate
Source: Spec/Assignment.lean:43
Source span: 40:0–49:66
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- rs1090-derived commb.rs at685dfaa: the BDS05 candidate agrees with the
outer AC13 meaning and uses TC9–18/20–21; BDS65 is excluded by the documented
offset/leftover policy. Other candidates use their independent predicates. -/
def candidate (df : Nat) (outer : Option Int) (reg word : Nat) : Bool :=
  (df == 20 || df == 21) && word != 0 &&
  (if reg == 0x05 then
    let tc := columnCode word 1 5
    df == 20 && tc ≥ 9 && tc < 22 && tc != 19 &&
      bdsWireValid 0x05 word && decide (compatibility12 (columnCode word 9 12) = outer)
   else if reg == 0x65 then false else commBCoreEligible reg word)
END EXACT SOURCE
-/

/- REVIEW BLOCK 075 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.commBAssignments
Source: Spec/Assignment.lean:54
Source span: 51:0–58:13
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- Sun, second edition (2021), tables5.1/8.2–8.3/16.1–18.2 plus the explicit
rs1090-derived candidate predicates: enumerate the assignment's qualifying
registers and construct their named fields directly from source columns. -/
def commBAssignments (df : Nat) (outer : Option Int) (word : Nat) : List (Nat × PayloadRecord) :=
  commBRegisters.filterMap fun reg =>
    if candidate df outer reg word then
      (bdsLayout reg word).map fun cols => (reg, payloadAssignment reg word cols)
    else none
END EXACT SOURCE
-/

/- REVIEW BLOCK 076 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.adsbStandardValues
Source: Spec/Assignment.lean:63
Source span: 60:0–87:9
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- Sun, second edition (2021), tables5.1/6.1/7.1–7.3: exact expected meanings
of independently assigned ADS-B codes. Altitude uses the independent bit fold;
other scales and availability formulas are shared source-table constants. -/
def adsbStandardValues (word : Nat) : Semantics.Values :=
  let tc := payloadBits word 1 5
  let b := payloadBits word
  if 5 <= tc && tc <= 8 then
    [("NUCp", some (adsbNUCp tc)), ("groundspeed", adsbMovement (b 6 7))]
  else if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("NUCp", some (adsbNUCp tc)),
     ("NICb", if tc < 19 then some (b 8 1) else none),
     ("altitude_feet", if tc < 19 then (altitude12 (b 9 12)).map (fun n => (n : Rat)) else none),
     ("height_metres", (standardGNSSHeightMetres word).map (fun n => (n : Rat)))]
  else if tc == 19 then
    let components := standardVelocityComponents word
    let subtype := b 6 3
    [("east_velocity", components.map (fun p => (p.1 : Rat))),
     ("north_velocity", components.map (fun p => (p.2 : Rat))),
     ("vertical_rate", (adsbVerticalRate word).map (fun n => (n : Rat))),
     ("geo_minus_baro", (standardGeoMinusBaro word).map (fun n => (n : Rat))),
     ("airspeed", if subtype == 3 || subtype == 4 then
       (adsbAirspeed word).map (fun n => (n : Rat)) else none)]
  else if tc == 28 then
    [("squawk", some (identityCode (BitVec.ofNat 13 (b 12 13))))]
  else if tc == 29 then
    [("selected_altitude", (adsbSelectedAltitude word).map (fun n => (n : Rat))),
     ("barometric_setting", adsbBarometricSetting word)]
  else []
END EXACT SOURCE
-/

/- REVIEW BLOCK 077 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.adsbCompatibilityValues
Source: Spec/Assignment.lean:94
Source span: 89:0–112:30
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- rs1090-derived bds05/bds09 compatibility values, pinned685dfaa: the
independent altitude assignment preserves the documented source discrepancy;
reserved velocity data uses independent native-little-endian byte chunks
from bds09.rs/deku0.20.3 on the pinned target. Other numeric code formulas
remain explicitly shared source constants. -/
def adsbCompatibilityValues (word : Nat) : Semantics.Values :=
  let tc := payloadBits word 1 5
  if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("NUCp", some (adsbNUCp tc)),
     ("NICb", if tc < 19 then some (payloadBits word 8 1) else none),
     ("altitude_feet", (compatibility12 (payloadBits word 9 12)).map (fun n => (n : Rat)))]
  else if tc == 19 then
    let (ew, ns) := adsbOracleVelocityComponents word
    let subtype := payloadBits word 6 3
    ([("east_velocity", if subtype == 1 || subtype == 2 then some ew else none),
     ("north_velocity", if subtype == 1 || subtype == 2 then some ns else none),
     ("vertical_rate", (adsbVerticalRate word).map (fun n => (n : Rat))),
     ("geo_minus_baro", (adsbGeoMinusBaro word).map (fun n => (n : Rat))),
     ("airspeed", if subtype == 3 || subtype == 4 then
       (adsbAirspeed word).map (fun n => (n : Rat)) else none)] : Semantics.Values) ++
      (if subtype == 0 || subtype ≥ 5 then
        [("reserved_data", some (columnCode word 14 8 +
          256 * columnCode word 22 8 + 65536 * columnCode word 30 6 : Rat))] else [])
  else adsbStandardValues word
END EXACT SOURCE
-/

/- REVIEW BLOCK 078 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.adsbMeaning
Source: Spec/Assignment.lean:117
Source span: 114:0–121:72
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- Sun, second edition (2021), chs.4–8 tables: complete assignment meaning.
Labels, affine tables and expression ASTs are shared mathematical projection
constants; the decoder-only semantic constructors are never invoked here. -/
def adsbMeaning (word : Nat) : Semantics.Payload :=
  ⟨Semantics.tableValues ((adsbLayout word).getD []) word,
   adsbStandardValues word, adsbCompatibilityValues word,
   Semantics.adsbLabels false word, Semantics.adsbLabels true word,
   Semantics.adsbStandardFloats word, oracleADSBFloats word, none, none⟩
END EXACT SOURCE
-/

/- REVIEW BLOCK 079 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.compatibilityThreat
Source: Spec/Assignment.lean:126
Source span: 123:0–136:20
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV, fourth edition (2007), §4.3.8.4.2.2.1.6: independent
threat field assignment; the compatibility view applies the explicit rs1090
altitude/range/bearing policy instead of the standard quantized-range meaning. -/
def compatibilityThreat (word : Nat) : CommBThreat :=
  match columnCode word 29 2 with
  | 0 => .none
  | 1 => .address (columnCode word 31 24)
  | 2 =>
    let range := columnCode word 44 7
    let bearing := columnCode word 51 6
    .orientation (compatibility13 (columnCode word 31 13))
      (if range == 0 then none else some ((range - 1 : Nat) / 10 : Rat))
      (if bearing == 0 then none else some (6 * (bearing - 1) + 3))
  | _ => .unassigned
END EXACT SOURCE
-/

/- REVIEW BLOCK 080 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.standardThreat
Source: Spec/Assignment.lean:141
Source span: 138:0–150:27
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV, fourth edition (2007), amendment85, §4.3.8.4.2.2.1.6
printed pages4-21–22: assigned standard threat meanings. Typed range/bearing
constructors use their published total finite-code tables. -/
def standardThreat (word : Nat) : Option StandardCommBThreat :=
  if word ≥ 2^56 then none else
    match columnCode word 29 2 with
    | 0 => some .none
    | 1 => if columnCode word 55 2 == 0 then
        some (.address (columnCode word 31 24)) else none
    | 2 => some (.orientation (gillhamHeight (columnCode word 31 13))
        (standardThreatRange (Fin.ofNat 128 (columnCode word 44 7)))
        (standardThreatBearing (Fin.ofNat 64 (columnCode word 51 6))))
    | _ => some .unassigned
END EXACT SOURCE
-/

/- REVIEW BLOCK 081 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.commBMeaning
Source: Spec/Assignment.lean:155
Source span: 152:0–166:90
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- Sun, second edition (2021), tables16.1–18.2 and ICAO Annex10 IV, fourth
edition (2007), threat tables cited above: complete named candidate meanings,
including source/oracle threat disagreement. No decoded candidate is an input. -/
def commBMeaning (register word : Nat) : Semantics.Payload :=
  if register == 0x05 || register == 0x65 then adsbMeaning word else
    let layout := (commBLayout register).getD []
    { tableValues := Semantics.tableValues layout word
      standardValues := Semantics.tableValues layout word
      oracleValues := layout.map fun c => (c.name, commBValue register word c.name)
      standardLabels := Semantics.commBLabels register word
      oracleLabels := Semantics.commBLabels register word
      standardFloats := Semantics.commBStandardFloats register word
      oracleFloats := oracleCommBFloats register word
      standardThreat := if register == 0x30 then standardThreat word else none
      oracleThreat := if register == 0x30 then some (compatibilityThreat word) else none }
END EXACT SOURCE
-/

/- REVIEW BLOCK 082 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.altitude
Source: Spec/Assignment.lean:170
Source span: 168:0–180:13
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- Sun, second edition (2021), chs.5/13: assigned outer altitude value,
including a distinct unsigned GNSS metre height for TC20–22. -/
def altitude (f : Frame) : Option Altitude.Value :=
  match f.body with
  | .shortACAS h | .longACAS h _ => altitude13 h.ac.toNat
  | .surveillance false h | .commB false h _ => altitude13 h.code.toNat
  | .extended _ _ _ me =>
      let tc := columnCode me.toNat 1 5
      if tc ≥ 9 && tc ≤ 18 then
        (altitude12 (columnCode me.toNat 9 12)).map Altitude.Value.feet
      else if tc ≥ 20 && tc ≤ 22 then some (.metres (columnCode me.toNat 9 12))
      else none
  | _ => none
END EXACT SOURCE
-/

/- REVIEW BLOCK 083 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.outerAltitude
Source: Spec/Assignment.lean:184
Source span: 182:0–187:13
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- rs1090-derived outer AC13 meaning for the DF20 candidate predicate;
DF21 identity replies have no outer altitude. -/
def outerAltitude (f : Frame) : Option Int :=
  match f.body with
  | .commB false h _ => compatibility13 h.code.toNat
  | _ => none
END EXACT SOURCE
-/

/- REVIEW BLOCK 084 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.expectedReport
Source: Spec/Assignment.lean:193
Source span: 189:0–221:17
Original module: Spec.Assignment
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity
open Presentation
BEGIN EXACT SOURCE
/-- Annex10 IV, fourth edition (2007), §§3.1.2.3.3/3.1.2.5.2.2/3.1.2.6.7.1:
construct the complete expected report directly from assigned fields. Parity
polynomials, identity permutations and table meanings are shared mathematical
specifications; no report, payload decoder or inference function is called. -/
def expectedReport (f : Frame) : Report :=
  let syndrome := Parity.checksum f.body.informationBits (packFields f.body.parts) ^^^ f.parity
  let address := match f.body with
    | .allCall _ aa | .extended _ _ aa _ => some aa
    | .military _ _ => none
    | _ => some syndrome
  let interrogator := match f.body with
    | .allCall _ _ => Parity.interrogator syndrome
    | _ => none
  let identity := match f.body with
    | .surveillance true h | .commB true h _ => some (identityCode h.code)
    | .extended _ _ _ me => if columnCode me.toNat 1 5 == 28 then
        some (identityCode (BitVec.ofNat 13 (columnCode me.toNat 12 13))) else none
    | _ => none
  let adsb := match f.body with
    | .extended _ _ _ me => adsbAssignment me.toNat
    | _ => none
  let candidates := match f.body with
    | .commB isIdentity _ mb => commBAssignments (if isIdentity then 21 else 20)
        (outerAltitude f) mb.toNat
    | _ => []
  { crc := syndrome, address, interrogator, altitude := altitude f, identity, adsb,
    commB := candidates
    semanticADSB := match f.body with
      | .extended _ _ _ me => some (adsbMeaning me.toNat)
      | _ => none
    semanticCommB := match f.body with
      | .commB _ _ mb => candidates.map fun (reg, _) => (reg, commBMeaning reg mb.toNat)
      | _ => [] }
END EXACT SOURCE
-/

/- REVIEW BLOCK 085 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.orderedBits
Source: Spec/AssignmentAltitude.lean:14
Source span: 12:0–15:78
Original module: Spec.AssignmentAltitude
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 altitude bit permutation: concatenate the assigned
bits in the listed most-significant-first order. -/
def orderedBits (word : Nat) (positions : List Nat) : Nat :=
  positions.foldl (fun value i => 2*value + if word.testBit i then 1 else 0) 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 086 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.grayValue
Source: Spec/AssignmentAltitude.lean:20
Source span: 17:0–23:59
Original module: Spec.AssignmentAltitude
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13 Gray-code altitude equations: each binary bit
is the parity of the Gray prefix. This MSB-first construction is independent
of Altitude.grayDecode's XOR-of-shifted-words recurrence. -/
def grayValue (width gray : Nat) : Nat :=
  ((List.range width).foldl (fun (state : Bool × Nat) i =>
    let next := state.1 != gray.testBit (width-1-i)
    (next, 2*state.2 + if next then 1 else 0)) (false,0)).2
END EXACT SOURCE
-/

/- REVIEW BLOCK 087 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.gillhamHeight
Source: Spec/AssignmentAltitude.lean:28
Source span: 25:0–35:55
Original module: Spec.AssignmentAltitude
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13: assigned D2 D4 A1 A2 A4 B1 B2 B4 and
C1 C2 C4 Gray digits determine 500/100-foot counts. Invalid C patterns and
M/Q bits have no Gillham meaning. -/
def gillhamHeight (word : Nat) : Option Int :=
  let coarse := grayValue 8 (orderedBits word [2,0,11,9,7,5,3,1])
  let fine := grayValue 3 (orderedBits word [12,10,8])
  if word ≥ 8192 || word.testBit 6 || word.testBit 4 ||
      !( [1,2,3,4,7].contains fine ) then none else
    let fine := if fine == 7 then 5 else fine
    let fine := if coarse % 2 == 0 then fine else 6-fine
    some ((coarse : Int)*500 + (fine : Int)*100 - 1300)
END EXACT SOURCE
-/

/- REVIEW BLOCK 088 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.altitude13
Source: Spec/AssignmentAltitude.lean:39
Source span: 37:0–45:51
Original module: Spec.AssignmentAltitude
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.13: an assigned AC13 code denotes M=1 unsigned
metres, Q=1 binary25 feet, or Gillham100 feet; all-zero is unavailable. -/
def altitude13 (code : Nat) : Option Altitude.Value :=
  if code == 0 || code ≥ 8192 then none
  else if code.testBit 6 then
    some (.metres (orderedBits code [12,11,10,9,8,7,5,4,3,2,1,0]))
  else if code.testBit 4 then
    some (.feet ((orderedBits code [12,11,10,9,8,7,5,3,2,1,0] : Int)*25 - 1000))
  else (gillhamHeight code).map Altitude.Value.feet
END EXACT SOURCE
-/

/- REVIEW BLOCK 089 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.altitude12
Source: Spec/AssignmentAltitude.lean:49
Source span: 47:0–55:15
Original module: Spec.AssignmentAltitude
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), §5.5.1: independently insert the omitted M=0 bit
when assigning an ADS-B barometric altitude code. -/
def altitude12 (code : Nat) : Option Int :=
  if code ≥ 4096 then none else
    let expanded := orderedBits code [11,10,9,8,7,6]*128 +
      orderedBits code [5,4,3,2,1,0]
    match altitude13 expanded with
    | some (.feet height) => some height
    | _ => none
END EXACT SOURCE
-/

/- REVIEW BLOCK 090 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.compatibility13
Source: Spec/AssignmentAltitude.lean:61
Source span: 57:0–71:17
Original module: Spec.AssignmentAltitude
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Model.Types
BEGIN EXACT SOURCE
/-- rs1090-derived AC13Field::read, pinned685dfaa: compatibility M conversion
uses overlapping bits and truncates to whole feet. Its M=1,Q=1 rejection is
not an assertion about the standard metric representation. The pinned
negative-Gillham rejection is separate from standard representability. -/
def compatibility13 (code : Nat) : Option Int :=
  if code == 0 || code ≥ 8192 then none else
    if code.testBit 6 then
      if code.testBit 4 then none else
        let metres := (orderedBits code [12,11,10,9,8,7]*32) |||
          orderedBits code [5,4,3,2,1,0]
        some ((metres*328084/100000 : Nat) : Int)
    else match altitude13 code with
      | some (.feet height) =>
          if !code.testBit 4 && height < 0 then none else some height
      | _ => none
END EXACT SOURCE
-/

/- REVIEW BLOCK 091 — DEPENDENCY
Declaration: Lean1090.Spec.Assignment.compatibility12
Source: Spec/AssignmentAltitude.lean:77
Source span: 73:0–78:91
Original module: Spec.AssignmentAltitude
Original imports/opens:
namespace Lean1090.Spec.Assignment
import Model.Types
BEGIN EXACT SOURCE
/-- rs1090-derived bds05.rs, pinned685dfaa: the report's compatible altitude
is absent for invalid/unavailable codes and for heights above50000ft. Frame
acceptance is a separate predicate, not assumed by this assignment meaning.
Negative Gillham heights are missing; negative binary25 heights remain. -/
def compatibility12 (code : Nat) : Option Int :=
  (altitude12 code).filter (fun height => height ≤ 50000 && (code.testBit 4 || height ≥ 0))
END EXACT SOURCE
-/

/- REVIEW BLOCK 092 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.powerTwo
Source: Spec/Binary64.lean:25
Source span: 24:0–27:33
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64, `MANTISSA_DIGITS`, `MIN_EXP`: exact integer powers of two. -/
def powerTwo (exponent : Int) : Rat :=
  if exponent < 0 then 1 / (2 ^ exponent.natAbs : Nat)
  else (2 ^ exponent.toNat : Nat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 093 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.nearestEven
Source: Spec/Binary64.lean:31
Source span: 29:0–35:8
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64, arithmetic nearest/ties-even: round a nonnegative ratio
to an integer by quotient/remainder, independent of Float. -/
def nearestEven (numerator denominator : Nat) : Nat :=
  let q := numerator / denominator
  let r := numerator % denominator
  if 2 * r > denominator || (2 * r == denominator && q % 2 == 1) then q + 1
  else q
END EXACT SOURCE
-/

/- REVIEW BLOCK 094 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.exponent
Source: Spec/Binary64.lean:39
Source span: 37:0–41:69
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64, `MANTISSA_DIGITS`: binade exponent of a nonzero rational.
The initial numerator/denominator bit-length estimate differs by at most one. -/
def exponent (value : Rat) : Int :=
  let candidate := (value.num.natAbs.log2 : Int) - (value.den.log2 : Int)
  if value.abs < powerTwo candidate then candidate - 1 else candidate
END EXACT SOURCE
-/

/- REVIEW BLOCK 095 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.round
Source: Spec/Binary64.lean:46
Source span: 43:0–51:43
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64 arithmetic: nearest representable finite significand with 53
bits, including the fixed 2^-1074 subnormal quantum. For overflow this remains
a mathematical extension; callers must prove `inRange` for every result. -/
def round (value : Rat) : Rat :=
  if value == 0 then 0 else
    let quantum := powerTwo (max (-1074) (exponent value - 52))
    let scaled := value.abs / quantum
    let rounded := (nearestEven scaled.num.natAbs scaled.den : Rat) * quantum
    if value < 0 then -rounded else rounded
END EXACT SOURCE
-/

/- REVIEW BLOCK 096 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.literal
Source: Spec/Binary64.lean:60
Source span: 59:0–60:46
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64 decimal literals: round their exact rational decimal values once. -/
def literal (value : Rat) : Rat := round value
END EXACT SOURCE
-/

/- REVIEW BLOCK 097 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.add
Source: Spec/Binary64.lean:63
Source span: 62:0–63:42
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64 addition: one rounding after exact addition, no reassociation. -/
def add (a b : Rat) : Rat := round (a + b)
END EXACT SOURCE
-/

/- REVIEW BLOCK 098 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.sub
Source: Spec/Binary64.lean:66
Source span: 65:0–66:42
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64 subtraction: one rounding after exact subtraction. -/
def sub (a b : Rat) : Rat := round (a - b)
END EXACT SOURCE
-/

/- REVIEW BLOCK 099 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.mul
Source: Spec/Binary64.lean:69
Source span: 68:0–69:42
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64 multiplication: one rounding after exact multiplication. -/
def mul (a b : Rat) : Rat := round (a * b)
END EXACT SOURCE
-/

/- REVIEW BLOCK 100 — DEPENDENCY
Declaration: Lean1090.Spec.Binary64.div
Source: Spec/Binary64.lean:73
Source span: 71:0–73:42
Original module: Spec.Binary64
Original imports/opens:
namespace Lean1090.Spec.Binary64
import Std
BEGIN EXACT SOURCE
/-- Rust f64 division: one rounding after division; requires b≠0 for the
IEEE interpretation. Rat's total zero-divisor convention is not IEEE semantics. -/
def div (a b : Rat) : Rat := round (a / b)
END EXACT SOURCE
-/

/- REVIEW BLOCK 101 — DEPENDENCY
Declaration: Lean1090.Spec.packFields
Source: Spec/Bits.lean:28
Source span: 27:0–29:80
Original module: Spec.Bits
Original imports/opens:
namespace Lean1090.Spec
import Std
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: concatenate separately supplied fields. -/
def packFields (fields : List (Nat × Nat)) : Nat :=
  fields.foldl (fun acc (width, value) => acc * 2 ^ width + value % 2 ^ width) 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 102 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.scale
Source: Spec/CPR.lean:21
Source span: 20:0–21:25
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(a): 17 transmitted bits for each CPR coordinate. -/
def scale : Nat := 131072
END EXACT SOURCE
-/

/- REVIEW BLOCK 103 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.parity
Source: Spec/CPR.lean:24
Source span: 23:0–24:53
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3: odd=1 and even=0 in all CPR formulas. -/
def parity (odd : Bool) : Nat := if odd then 1 else 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 104 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.span
Source: Spec/CPR.lean:27
Source span: 26:0–27:59
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.5(a), §2.6.6(a): angular ambiguity span. -/
def span : Medium → Rat | .airborne => 360 | .surface => 90
END EXACT SOURCE
-/

/- REVIEW BLOCK 105 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.absQ
Source: Spec/CPR.lean:30
Source span: 29:0–30:51
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(d): absolute value for exact rational angles. -/
def absQ (x : Rat) : Rat := if x < 0 then -x else x
END EXACT SOURCE
-/

/- REVIEW BLOCK 106 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.modQ
Source: Spec/CPR.lean:33
Source span: 32:0–33:59
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(e): Euclidean modulus, including negative angles. -/
def modQ (x y : Rat) : Rat := x - y * ((x / y).floor : Rat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 107 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.normalizeLongitude
Source: Spec/CPR.lean:36
Source span: 35:0–36:70
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(f): canonical longitude in [-180,180). -/
def normalizeLongitude (lon : Rat) : Rat := modQ (lon + 180) 360 - 180
END EXACT SOURCE
-/

/- REVIEW BLOCK 108 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.transitions
Source: Spec/CPR.lean:42
Source span: 38:0–54:38
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
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
END EXACT SOURCE
-/

/- REVIEW BLOCK 109 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.nlTable
Source: Spec/CPR.lean:58
Source span: 56:0–60:89
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(f); Sun, 2nd ed. (2021), ch.5 NL: NL(0)=59, NL(±87)=2,
NL(|lat|>87)=1. Decimal thresholds only claim equivalence on CPR grids. -/
def nlTable (lat : Rat) : Nat :=
  if absQ lat == 87 then 2 else
  59 - (transitions.takeWhile (fun (t : Nat) => (t : Rat) / 100000000 ≤ absQ lat)).length
END EXACT SOURCE
-/

/- REVIEW BLOCK 110 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.dLat
Source: Spec/CPR.lean:68
Source span: 67:0–68:82
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.5(a), §2.6.6(a): exact latitude cell width. -/
def dLat (mode : Medium) (odd : Bool) : Rat := span mode / (60 - parity odd : Nat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 111 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.zones
Source: Spec/CPR.lean:71
Source span: 70:0–71:76
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(c), §2.6.5(d), §2.6.6(d): at least one longitude zone. -/
def zones (lat : Rat) (odd : Bool) : Nat := max (nlTable lat - parity odd) 1
END EXACT SOURCE
-/

/- REVIEW BLOCK 112 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.dLon
Source: Spec/CPR.lean:74
Source span: 73:0–75:35
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(c), §2.6.5(d), §2.6.6(d): exact longitude cell width. -/
def dLon (mode : Medium) (odd : Bool) (lat : Rat) : Rat :=
  span mode / (zones lat odd : Rat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 113 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.roundedLatitude
Source: Spec/CPR.lean:79
Source span: 77:0–81:61
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(a,b): unwrapped, rounded latitude used by the encoder's
NL lookup. The +1/2 floor rule rounds ties toward positive infinity. -/
def roundedLatitude (mode : Medium) (odd : Bool) (lat : Rat) : Rat :=
  let d := dLat mode odd
  d / scale * (((lat / d * scale + 1 / 2).floor : Int) : Rat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 114 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.ValidPosition
Source: Spec/CPR.lean:99
Source span: 98:0–100:55
Original module: Spec.CPR
Original imports/opens:
namespace Lean1090.Spec.CPR
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3: geographic coordinate convention, poles included. -/
def ValidPosition (p : Position) : Prop :=
  -90 ≤ p.lat ∧ p.lat ≤ 90 ∧ -180 ≤ p.lon ∧ p.lon < 180
END EXACT SOURCE
-/

/- REVIEW BLOCK 115 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.roundedLongitude
Source: Spec/CPRContracts.lean:12
Source span: 10:0–14:63
Original module: Spec.CPRContracts
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(d): unwrapped quantized longitude, using reconstructed
latitude for the encoding zone. Used only to describe quantization error. -/
def roundedLongitude (mode : Medium) (odd : Bool) (p : Position) : Rat :=
  let d := dLon mode odd (roundedLatitude mode odd p.lat)
  d / scale * (((p.lon / d * scale + 1 / 2).floor : Int) : Rat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 116 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.longitudeDistance
Source: Spec/CPRContracts.lean:17
Source span: 16:0–17:76
Original module: Spec.CPRContracts
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.7(f): longitude error is circular at the antimeridian. -/
def longitudeDistance (a b : Rat) : Rat := absQ (normalizeLongitude (a - b))
END EXACT SOURCE
-/

/- REVIEW BLOCK 117 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.transitionFormula
Source: Spec/CPRFormula.lean:23
Source span: 22:0–26:49
Original module: Spec.CPRFormula
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Inverse
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(f) note5: exact real transition for a zone count2…59. -/
noncomputable def transitionFormula (zone : Nat) : ℝ :=
  180 / Real.pi * Real.arccos
    (Real.sqrt ((1 - Real.cos (Real.pi / 30)) /
      (1 - Real.cos (2 * Real.pi / (zone : ℝ)))))
END EXACT SOURCE
-/

/- REVIEW BLOCK 118 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.DecodableLatitude
Source: Spec/CPRFormula.lean:30
Source span: 28:0–32:70
Original module: Spec.CPRFormula
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Inverse
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.3(b), §2.6.5(c), §2.6.6(c), §2.6.7(c): union of
all legal reconstructed latitude grids, including airborne/surface and parity. -/
def DecodableLatitude (lat : Rat) : Prop :=
  ∃ (mode : Medium) (odd : Bool) (index : Int),
    lat = dLat mode odd / scale * (index : Rat) ∧ -90 ≤ lat ∧ lat ≤ 90
END EXACT SOURCE
-/

/- REVIEW BLOCK 119 — DEPENDENCY
Declaration: Lean1090.Spec.CPR.NLCertificate
Source: Spec/CPRFormula.lean:36
Source span: 34:0–40:33
Original module: Spec.CPRFormula
Original imports/opens:
namespace Lean1090.Spec.CPR
import Spec.CPR
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Inverse
BEGIN EXACT SOURCE
/-- ICAO Annex 10 Vol. III Part I, amendment 77 (28 November 2002), §2.6.2(f) note5: candidate enclosure includes both the exact
transition and rounded executable table threshold. Denominator is10¹². -/
structure NLCertificate where
  zone : Nat
  lower12 : Nat
  upper12 : Nat
  deriving BEq, DecidableEq, Repr
END EXACT SOURCE
-/

/- REVIEW BLOCK 120 — DEPENDENCY
Declaration: Lean1090.Spec.cbStatus
Source: Spec/CommB.lean:25
Source span: 23:0–26:69
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun chs.17–18 status fields; rs1090-derived rejection requires zero
payload when status is zero. The width includes the sign where present. -/
def cbStatus (word status start width : Nat) : Bool :=
  payloadBits word status 1 == 1 || payloadBits word start width == 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 121 — DEPENDENCY
Declaration: Lean1090.Spec.cbSigned
Source: Spec/CommB.lean:29
Source span: 28:0–30:77
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.17 two's complement quantities, before unit scaling. -/
def cbSigned (word start width : Nat) : Rat :=
  (payloadInteger .twosComplement width (payloadBits word start width) : Rat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 122 — DEPENDENCY
Declaration: Lean1090.Spec.cbSelected
Source: Spec/CommB.lean:34
Source span: 32:0–34:74
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds40.rs read_selected: exact integer presentation rule
`((raw * 16 + 8) / 100) * 100` feet, including its non-nearest-100 behavior. -/
def cbSelected (code : Nat) : Rat := (((code * 16 + 8) / 100) * 100 : Nat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 123 — DEPENDENCY
Declaration: Lean1090.Spec.cbTemperature44
Source: Spec/CommB.lean:38
Source span: 36:0–40:50
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds44.rs read_temperature: signed quarter-degrees followed
by a +256-degree wrap correction whenever the initial temperature is < -80. -/
def cbTemperature44 (word : Nat) : Rat :=
  let initial := cbSigned word 24 11 / 4
  if initial < -80 then initial + 256 else initial
END EXACT SOURCE
-/

/- REVIEW BLOCK 124 — DEPENDENCY
Declaration: Lean1090.Spec.cbVertical60
Source: Spec/CommB.lean:44
Source span: 42:0–46:79
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds60.rs read_vertical: magnitude code 0 or 511 denotes
zero regardless of sign; all other codes use signed 32 ft/min scaling. -/
def cbVertical60 (word start : Nat) : Rat :=
  let magnitude := payloadBits word (start + 1) 9
  if magnitude == 0 || magnitude == 511 then 0 else cbSigned word start 10 * 32
END EXACT SOURCE
-/

/- REVIEW BLOCK 125 — DEPENDENCY
Declaration: Lean1090.Spec.cbQNH64
Source: Spec/CommB.lean:49
Source span: 48:0–51:36
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds40.rs: binary64 `raw * 0.1 + 800`, preserving two rounds. -/
def cbQNH64 (word : Nat) : Rat :=
  Binary64.add (Binary64.mul (payloadBits word 28 12 : Rat)
    (Binary64.literal (1 / 10))) 800
END EXACT SOURCE
-/

/- REVIEW BLOCK 126 — DEPENDENCY
Declaration: Lean1090.Spec.cbMach64
Source: Spec/CommB.lean:55
Source span: 53:0–57:39
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds60.rs: binary64 `raw * 2.048 / 512`, preserving the
rounded decimal constant and operation order instead of replacing it by /250. -/
def cbMach64 (word : Nat) : Rat :=
  Binary64.div (Binary64.mul (payloadBits word 25 10 : Rat)
    (Binary64.literal (256 / 125))) 512
END EXACT SOURCE
-/

/- REVIEW BLOCK 127 — DEPENDENCY
Declaration: Lean1090.Spec.cbWrapAngle
Source: Spec/CommB.lean:60
Source span: 59:0–60:79
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds50/bds60: wrap negative heading/track to [0,360). -/
def cbWrapAngle (value : Rat) : Rat := if value < 0 then value + 360 else value
END EXACT SOURCE
-/

/- REVIEW BLOCK 128 — DEPENDENCY
Declaration: Lean1090.Spec.commBValue
Source: Spec/CommB.lean:68
Source span: 62:0–83:22
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun chs.16–18 standard unit projections, with named rs1090-derived
presentation exceptions: BDS10 DTE native-endian reporting on the pinned x86_64
target (bds10.rs/deku0.20.3), BDS40 altitude rounding, BDS44 temperature correction,
BDS50 unavailable rate sentinel, BDS60 rate sentinels and wrapped headings.
The QNH/Mach values here are exact pre-Float quantities; score arithmetic uses
`cbQNH64` / `cbMach64` separately. -/
def commBValue (register word : Nat) (name : String) : Option Rat := do
  let layout ← commBLayout register
  let c ← layout.find? (fun c => c.name == name)
  let value ← payloadValue c word
  match register, name with
  | 0x10, "dte" => some (payloadBits word 41 8 + 256 * payloadBits word 49 8 : Rat)
  | 0x40, "selected_mcp" => some (cbSelected (payloadBits word 2 12))
  | 0x40, "selected_fms" => some (cbSelected (payloadBits word 15 12))
  | 0x44, "temperature" => some (cbTemperature44 word)
  | 0x50, "track" => some (cbWrapAngle value)
  | 0x50, "track_rate" =>
    if payloadBits word 37 9 == 511 then none else some value
  | 0x60, "heading" => some (cbWrapAngle value)
  | 0x60, "vrate_barometric" => some (cbVertical60 word 36)
  | 0x60, "vrate_inertial" => some (cbVertical60 word 47)
  | _, _ => some value
END EXACT SOURCE
-/

/- REVIEW BLOCK 129 — DEPENDENCY
Declaration: Lean1090.Spec.cbCharacter
Source: Spec/CommB.lean:87
Source span: 85:0–90:38
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-8: A–Z, digits, space; all unassigned
symbols remain visible as '#', following rs1090's output policy. -/
def cbCharacter (code : Nat) : Char :=
  if 1 ≤ code && code ≤ 26 then Char.ofNat (64 + code)
  else if 48 ≤ code && code ≤ 57 then Char.ofNat code
  else if code == 32 then ' ' else '#'
END EXACT SOURCE
-/

/- REVIEW BLOCK 130 — DEPENDENCY
Declaration: Lean1090.Spec.cbCallsign
Source: Spec/CommB.lean:94
Source span: 92:0–96:43
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds08.rs callsign_read, reused by BDS20: discard every
code 32 (including interior spaces); code zero remains its lookup character. -/
def cbCallsign (word : Nat) : String :=
  String.ofList (((List.range 8).map fun i => payloadBits word (9 + 6*i) 6)
    |>.filter (· != 32) |>.map cbCharacter)
END EXACT SOURCE
-/

/- REVIEW BLOCK 131 — DEPENDENCY
Declaration: Lean1090.Spec.standardThreatRange
Source: Spec/CommB.lean:116
Source span: 113:0–120:49
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.6.2 coding table, actually read on
printed page4-21:0 unavailable;1 below0.05;2–126 (n−1)/10±0.05;
127 above12.55 nautical miles. -/
def standardThreatRange (code : Fin 128) : StandardThreatRange :=
  if code.val == 0 then .unavailable
  else if code.val == 1 then .lessThan (1/20)
  else if code.val == 127 then .greaterThan (251/20)
  else .estimate ((code.val-1 : Nat) / 10) (1/20)
END EXACT SOURCE
-/

/- REVIEW BLOCK 132 — DEPENDENCY
Declaration: Lean1090.Spec.standardThreatBearing
Source: Spec/CommB.lean:124
Source span: 122:0–127:27
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.6.3 coding table, actually read on
printed page4-22:1–60 identify sectors6(n−1)…6n degrees;61–63 unassigned. -/
def standardThreatBearing (code : Fin 64) : StandardThreatBearing :=
  if code.val == 0 then .unavailable
  else if code.val ≤ 60 then .sector (6*(code.val-1)) (6*code.val)
  else .unassigned code.val
END EXACT SOURCE
-/

/- REVIEW BLOCK 133 — DEPENDENCY
Declaration: Lean1090.Spec.cbDashPlaceholder
Source: Spec/CommB.lean:153
Source span: 152:0–153:82
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds21.rs: code 0, 32 and 45 are removed dash placeholders. -/
def cbDashPlaceholder (code : Nat) : Bool := code == 0 || code == 32 || code == 45
END EXACT SOURCE
-/

/- REVIEW BLOCK 134 — DEPENDENCY
Declaration: Lean1090.Spec.cbRegistrationCodes
Source: Spec/CommB.lean:156
Source span: 155:0–158:35
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds21.rs: seven six-bit aircraft-registration characters. -/
def cbRegistrationCodes (word : Nat) : List Nat :=
  ((List.range 7).map fun i => payloadBits word (2 + 6*i) 6).filter
    (fun c => !cbDashPlaceholder c)
END EXACT SOURCE
-/

/- REVIEW BLOCK 135 — DEPENDENCY
Declaration: Lean1090.Spec.cbRegistration
Source: Spec/CommB.lean:162
Source span: 160:0–164:72
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds21.rs: registration is absent for false status,
otherwise the dash-less string (which can be empty). -/
def cbRegistration (word : Nat) : Option String :=
  if payloadBits word 1 1 == 0 then none
  else some (String.ofList ((cbRegistrationCodes word).map cbCharacter))
END EXACT SOURCE
-/

/- REVIEW BLOCK 136 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid17
Source: Spec/CommB.lean:168
Source span: 166:0–170:65
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds17.rs: default-feature must-set/must-clear bits and
27-bit zero suffix; the intervening five reserved bits are *not* rejected. -/
def cbValid17 (word : Nat) : Bool :=
  payloadBits word 7 1 == 1 && payloadBits word 30 27 == 0 &&
  [10,11,12,15,20,21,22].all (fun i => payloadBits word i 1 == 0)
END EXACT SOURCE
-/

/- REVIEW BLOCK 137 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid18
Source: Spec/CommB.lean:174
Source span: 172:0–178:69
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds18.rs: default-feature allowed bitmap and four
mandatory support indications. Index 1 is register 0x38, index56 register01. -/
def cbValid18 (word : Nat) : Bool :=
  let allowed := [0x30,0x21,0x20,0x1f,0x1e,0x1d,0x1c,0x1b,0x1a,
    0x19,0x18,0x17,0x10,0x0f,0x0b,0x0a,0x09,0x08,0x07,0x06,0x05]
  (List.range 56).all (fun i => allowed.contains (56-i) || payloadBits word (i+1) 1 == 0) &&
  [0x20,0x19,0x18,0x17].all (fun r => payloadBits word (57-r) 1 == 1)
END EXACT SOURCE
-/

/- REVIEW BLOCK 138 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid19
Source: Spec/CommB.lean:181
Source span: 180:0–183:90
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds19.rs: only the listed register-support bits may be set. -/
def cbValid19 (word : Nat) : Bool :=
  let allowed := [0x65,0x62,0x61,0x60,0x5f,0x53,0x52,0x51,0x50,0x45,0x44,0x40]
  (List.range 56).all (fun i => allowed.contains (112-i) || payloadBits word (i+1) 1 == 0)
END EXACT SOURCE
-/

/- REVIEW BLOCK 139 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid21
Source: Spec/CommB.lean:188
Source span: 185:0–193:88
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds21.rs: false status allows only stripped placeholders;
airline status must be false and both airline characters placeholders; a
present aircraft registration has at most two '#' unknown symbols. -/
def cbValid21 (word : Nat) : Bool :=
  let codes := cbRegistrationCodes word
  (if payloadBits word 1 1 == 0 then codes.isEmpty
   else (codes.filter (fun c => cbCharacter c == '#')).length ≤ 2) &&
  payloadBits word 44 1 == 0 &&
  cbDashPlaceholder (payloadBits word 45 6) && cbDashPlaceholder (payloadBits word 51 6)
END EXACT SOURCE
-/

/- REVIEW BLOCK 140 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid40
Source: Spec/CommB.lean:198
Source span: 195:0–203:43
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds40.rs: status consistency, both spare regions zero,
rounded selected altitude ≤50000ft, binary64 pressure in [800,1200]hPa.
Mode/status and target-source/status consistency are not enforced by rs1090. -/
def cbValid40 (word : Nat) : Bool :=
  cbStatus word 1 2 12 && cbStatus word 14 15 12 && cbStatus word 27 28 12 &&
  payloadBits word 40 8 == 0 && payloadBits word 52 2 == 0 &&
  cbSelected (payloadBits word 2 12) ≤ 50000 &&
  cbSelected (payloadBits word 15 12) ≤ 50000 &&
  cbQNH64 word ≥ 800 && cbQNH64 word ≤ 1200
END EXACT SOURCE
-/

/- REVIEW BLOCK 141 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid44
Source: Spec/CommB.lean:207
Source span: 205:0–211:55
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds44.rs: FOM1/2 only, wind≤250kt, temperature fallback
followed by [-80,60]C, and both turbulence and humidity absent/zero. -/
def cbValid44 (word : Nat) : Bool :=
  (payloadBits word 1 4 == 1 || payloadBits word 1 4 == 2) &&
  cbStatus word 5 6 18 && payloadBits word 6 9 ≤ 250 &&
  cbTemperature44 word ≥ -80 && cbTemperature44 word ≤ 60 &&
  cbStatus word 35 36 11 && payloadBits word 47 10 == 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 142 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid45
Source: Spec/CommB.lean:216
Source span: 213:0–220:50
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds45.rs: all hazard fields absent, spare bits zero,
status consistency for pressure/height. An unavailable temperature may retain
its sign bit, but its nine magnitude bits must be zero. -/
def cbValid45 (word : Nat) : Bool :=
  payloadBits word 1 15 == 0 && payloadBits word 52 5 == 0 &&
  (if payloadBits word 16 1 == 0 then payloadBits word 18 9 == 0
   else cbSigned word 17 10 / 4 ≥ -80 && cbSigned word 17 10 / 4 ≤ 60) &&
  cbStatus word 27 28 11 && cbStatus word 39 40 12
END EXACT SOURCE
-/

/- REVIEW BLOCK 143 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid50
Source: Spec/CommB.lean:225
Source span: 222:0–231:74
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds50.rs: per-field status consistency, |roll|≤45°,
groundspeed≤700kt and present TAS in [80,600]kt. A track-rate magnitude511
is unavailable, not a malformed payload. -/
def cbValid50 (word : Nat) : Bool :=
  cbStatus word 1 2 10 && cbStatus word 12 13 11 && cbStatus word 24 25 10 &&
  cbStatus word 35 36 10 && cbStatus word 46 47 10 &&
  (cbSigned word 2 10 * 45 / 256).abs ≤ 45 &&
  payloadBits word 25 10 * 2 ≤ 700 &&
  (payloadBits word 46 1 == 0 ||
    (payloadBits word 47 10 * 2 ≥ 80 && payloadBits word 47 10 * 2 ≤ 600))
END EXACT SOURCE
-/

/- REVIEW BLOCK 144 — DEPENDENCY
Declaration: Lean1090.Spec.cbValid60
Source: Spec/CommB.lean:236
Source span: 233:0–240:35
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds60.rs: per-field status consistency, IAS≤500kt,
binary64 Mach≤1, inertial vertical-rate magnitude≤6000ft/min after sentinel
handling. Barometric vertical rate has no plausibility bound. -/
def cbValid60 (word : Nat) : Bool :=
  cbStatus word 1 2 11 && cbStatus word 13 14 10 && cbStatus word 24 25 10 &&
  cbStatus word 35 36 10 && cbStatus word 46 47 10 &&
  payloadBits word 14 10 ≤ 500 && cbMach64 word ≤ 1 &&
  (cbVertical60 word 47).abs ≤ 6000
END EXACT SOURCE
-/

/- REVIEW BLOCK 145 — DEPENDENCY
Declaration: Lean1090.Spec.bdsWireValid
Source: Spec/CommB.lean:245
Source span: 242:0–263:14
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived register decoder predicates before the score gate.
BDS10/20/30 use their byte header; only BDS10 additionally checks spare bits.
BDS30 accepts every TTI variant and retains otherwise ignored bits. -/
def bdsWireValid (register word : Nat) : Bool :=
  word < 2^56 && match register with
  | 0x05 =>
    let tc := payloadBits word 1 5
    ((tc ≥ 9 && tc ≤ 18) || (tc ≥ 20 && tc ≤ 22)) && adsbHardValid word
  | 0x65 => payloadBits word 1 5 == 31 && payloadBits word 6 3 < 2 && adsbHardValid word
  | 0x10 => payloadBits word 1 8 == 0x10 && payloadBits word 10 5 == 0
  | 0x17 => cbValid17 word
  | 0x18 => cbValid18 word
  | 0x19 => cbValid19 word
  | 0x20 => payloadBits word 1 8 == 0x20
  | 0x21 => cbValid21 word
  | 0x30 => payloadBits word 1 8 == 0x30
  | 0x40 => cbValid40 word
  | 0x44 => cbValid44 word
  | 0x45 => cbValid45 word
  | 0x50 => cbValid50 word
  | 0x60 => cbValid60 word
  | _ => false
END EXACT SOURCE
-/

/- REVIEW BLOCK 146 — DEPENDENCY
Declaration: Lean1090.Spec.bdsLayout
Source: Spec/CommB.lean:268
Source span: 265:0–271:27
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), tables5.1,8.2–8.3 and16.1–18.2: select a register layout from
wire discriminants. BDS65's detailed subfields are explicitly rs1090-derived
through ADSB. This direct register decoder is distinct from Comm-B inference. -/
def bdsLayout (register word : Nat) : Option (List PayloadColumn) :=
  if register == 0x05 then some adsbPositionLayout
  else if register == 0x65 then adsbLayout word
  else commBLayout register
END EXACT SOURCE
-/

/- REVIEW BLOCK 147 — DEPENDENCY
Declaration: Lean1090.Spec.bdsAssignmentLayout
Source: Spec/CommB.lean:275
Source span: 273:0–282:30
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), tables5.1,8.2–8.3 and16.1–18.2: choose encoder layout from independently
assigned discriminant fields, without invoking a decoder or building a word. -/
def bdsAssignmentLayout (record : PayloadRecord) : Option (List PayloadColumn) :=
  if record.kind == 0x05 then some adsbPositionLayout
  else if record.kind == 0x65 then
    let subtype := (payloadField record "subtype").getD 0
    let version := (payloadField record "version").getD 0
    if subtype < 2 then some (adsbOperationPrefix (subtype == 1) ++
      adsbOperationSuffix (subtype == 1) version) else none
  else commBLayout record.kind
END EXACT SOURCE
-/

/- REVIEW BLOCK 148 — DEPENDENCY
Declaration: Lean1090.Spec.bdsStructuralValid
Source: Spec/CommB.lean:316
Source span: 311:0–323:38
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV table3-6 and §4.3.8.4.2.2.1; Sun, 2nd ed. (2021), tables5.1,
8.2–8.3 and16.1–18.2: structural register discriminants only. Receiver
plausibility, status-zero consistency, reserved-bit checks, density scores,
and candidate inference do not restrict this lossless field-code domain.
The supplementary18/19/21 layouts retain their explicit rs1090-derived origin. -/
def bdsStructuralValid (register word : Nat) : Bool :=
  word < 2^56 && match register with
  | 0x05 =>
    let tc := payloadBits word 1 5
    (tc ≥ 9 && tc ≤ 18) || (tc ≥ 20 && tc ≤ 22)
  | 0x65 => payloadBits word 1 5 == 31 && payloadBits word 6 3 < 2
  | 0x10 | 0x20 | 0x30 => payloadBits word 1 8 == register
  | _ => (commBLayout register).isSome
END EXACT SOURCE
-/

/- REVIEW BLOCK 149 — DEPENDENCY
Declaration: Lean1090.Spec.bdsFieldDiscriminants
Source: Spec/CommB.lean:327
Source span: 325:0–335:41
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Source layout references on bdsStructuralValid: independent assignment
selector using named fields, without invoking the encoder or decoder. -/
def bdsFieldDiscriminants (record : PayloadRecord) : Bool :=
  match record.kind with
  | 0x05 =>
    let tc := (payloadField record "tc").getD 0
    (tc ≥ 9 && tc ≤ 18) || (tc ≥ 20 && tc ≤ 22)
  | 0x65 => payloadField record "tc" == some 31 &&
      (payloadField record "subtype").getD 8 < 2
  | 0x10 | 0x20 | 0x30 => payloadField record "bds" == some record.kind
  | _ => (commBLayout record.kind).isSome
END EXACT SOURCE
-/

/- REVIEW BLOCK 150 — DEPENDENCY
Declaration: Lean1090.Spec.cbGaussian
Source: Spec/CommB.lean:362
Source span: 360:0–364:40
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived density.rs: Gaussian score in exact binary64 operation
order: z=(value-mu)/sigma; then (-0.5*z)*z. -/
def cbGaussian (value mu sigma : Rat) : Rat :=
  let z := Binary64.div (Binary64.sub value (Binary64.literal mu)) (Binary64.literal sigma)
  Binary64.mul (Binary64.mul (-1/2) z) z
END EXACT SOURCE
-/

/- REVIEW BLOCK 151 — DEPENDENCY
Declaration: Lean1090.Spec.cbLaplace
Source: Spec/CommB.lean:367
Source span: 366:0–369:95
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived density.rs: negative absolute deviation divided by scale. -/
def cbLaplace (value median scale : Rat) : Rat :=
  if scale ≤ 0 then 0 else
    Binary64.div (-(Binary64.sub value (Binary64.literal median)).abs) (Binary64.literal scale)
END EXACT SOURCE
-/

/- REVIEW BLOCK 152 — DEPENDENCY
Declaration: Lean1090.Spec.cbScoreField
Source: Spec/CommB.lean:372
Source span: 371:0–373:61
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived density.rs: skip absent fields, preserving source order. -/
def cbScoreField (value : Option Rat) (score : Rat → Rat) : List Rat :=
  match value with | none => [] | some value => [score value]
END EXACT SOURCE
-/

/- REVIEW BLOCK 153 — DEPENDENCY
Declaration: Lean1090.Spec.cbDensityTerms
Source: Spec/CommB.lean:377
Source span: 375:0–402:11
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived density.rs: each register's complete field-density list,
including the exact field order which affects binary64 rounding. -/
def cbDensityTerms (register word : Nat) : List Rat :=
  let value := commBValue register word
  match register with
  | 0x40 =>
    cbScoreField ((value "barometric_setting").map fun _ => cbQNH64 word)
      (fun x => cbLaplace x (10132/10) (54/10)) ++
    cbScoreField (value "selected_mcp") (fun x => cbGaussian x 24688 10844) ++
    cbScoreField (value "selected_fms") (fun x => cbGaussian x 24688 10844)
  | 0x50 =>
    cbScoreField (value "roll") (fun x => cbLaplace x 0 10) ++
    cbScoreField (value "track_rate") (fun x => cbLaplace x 0 (70/100)) ++
    cbScoreField (value "TAS") (fun x => cbGaussian x 413 120) ++
    cbScoreField (value "groundspeed") (fun x => cbGaussian x 418 129)
  | 0x60 =>
    cbScoreField (value "IAS") (fun x => cbGaussian x 272 55) ++
    cbScoreField ((value "Mach").map fun _ => cbMach64 word)
      (fun x => cbGaussian x (69/100) (21/100)) ++
    cbScoreField (value "vrate_inertial") (fun x => cbGaussian x (-298) 1669)
  | 0x44 =>
    [cbLaplace (cbTemperature44 word) (-21) (990/100)] ++
    cbScoreField (value "wind_speed") (fun x => cbGaussian x 52 29) ++
    cbScoreField (value "pressure") (fun x => cbLaplace x 393 290)
  | 0x45 =>
    cbScoreField (value "static_temperature") (fun x => cbGaussian x (-142/10) (164/10)) ++
    cbScoreField (value "static_pressure") (fun x => cbLaplace x 393 290)
  | _ => []
END EXACT SOURCE
-/

/- REVIEW BLOCK 154 — DEPENDENCY
Declaration: Lean1090.Spec.cbDensity
Source: Spec/CommB.lean:406
Source span: 404:0–409:69
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived density.rs Acc: binary64 sequential sum divided by count;
no scored fields yields zero for the combined gate. -/
def cbDensity (register word : Nat) : Rat :=
  let terms := cbDensityTerms register word
  if terms.isEmpty then 0
  else Binary64.div (terms.foldl Binary64.add 0) (terms.length : Rat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 155 — DEPENDENCY
Declaration: Lean1090.Spec.cbPenalty
Source: Spec/CommB.lean:413
Source span: 411:0–434:10
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived penalty.rs: BDS50 wind and opposite-sign turn penalties,
BDS60 IAS/Mach-ratio penalty; source operation order is preserved. -/
def cbPenalty (register word : Nat) : Rat :=
  let value := commBValue register word
  match register with
  | 0x50 =>
    let p := match value "TAS", value "groundspeed" with
      | some tas, some gs => Binary64.sub 0 (Binary64.div (Binary64.sub tas gs).abs 100)
      | _, _ => 0
    match value "roll", value "track_rate" with
    | some roll, some rate =>
      if roll.abs > 5 && rate.abs > Binary64.literal (3/10) &&
          decide (roll > 0) != decide (rate > 0) then Binary64.sub p 2 else p
    | _, _ => p
  | 0x60 =>
    match value "IAS", value "Mach" with
    | some ias, some _ =>
      let mach := cbMach64 word
      if mach > 0 then
        let ratio := Binary64.div ias mach
        if ratio < 250 || ratio > 800 then -3 else 0
      else 0
    | _, _ => 0
  | _ => 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 156 — DEPENDENCY
Declaration: Lean1090.Spec.cbCombinedScore
Source: Spec/CommB.lean:438
Source span: 436:0–439:66
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds/mod.rs validate_score_gate: the final score, exposing
the exact proof-visible rational that represents the oracle binary64 result. -/
def cbCombinedScore (register word : Nat) : Rat :=
  Binary64.add (cbDensity register word) (cbPenalty register word)
END EXACT SOURCE
-/

/- REVIEW BLOCK 157 — DEPENDENCY
Declaration: Lean1090.Spec.cbScorePasses
Source: Spec/CommB.lean:443
Source span: 441:0–444:36
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds/mod.rs validate_score_gate: accept score≥-3. The raw
Message::from_bytes path applies this only to 40/44/45/50/60, not to 05. -/
def cbScorePasses (register word : Nat) : Bool :=
  cbCombinedScore register word ≥ -3
END EXACT SOURCE
-/

/- REVIEW BLOCK 158 — DEPENDENCY
Declaration: Lean1090.Spec.commBCoreRegisters
Source: Spec/CommB.lean:448
Source span: 446:0–449:63
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived commb.rs: per-message core candidates in decoder order,
excluding ADSB-backed BDS05/65 which are integrated separately. -/
def commBCoreRegisters : List Nat :=
  [0x10,0x17,0x18,0x19,0x20,0x21,0x30,0x40,0x44,0x45,0x50,0x60]
END EXACT SOURCE
-/

/- REVIEW BLOCK 159 — DEPENDENCY
Declaration: Lean1090.Spec.commBCoreEligible
Source: Spec/CommB.lean:453
Source span: 451:0–455:94
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived commb.rs candidate predicate: both wire/field constraints
and the score gate for the five scored candidates. -/
def commBCoreEligible (register word : Nat) : Bool :=
  commBCoreRegisters.contains register && bdsWireValid register word &&
  (if [0x40,0x44,0x45,0x50,0x60].contains register then cbScorePasses register word else true)
END EXACT SOURCE
-/

/- REVIEW BLOCK 160 — DEPENDENCY
Declaration: Lean1090.Spec.commBRegisters
Source: Spec/CommB.lean:491
Source span: 490:0–491:69
Original module: Spec.CommB
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.CommBLayouts
import Spec.Binary64
import Spec.Altitude
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived commb.rs: complete reported-register order for DF20/21. -/
def commBRegisters : List Nat := 0x05 :: commBCoreRegisters ++ [0x65]
END EXACT SOURCE
-/

/- REVIEW BLOCK 161 — DEPENDENCY
Declaration: Lean1090.Spec.cbColumn
Source: Spec/CommBLayouts.lean:6
Source span: 5:0–9:53
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- Field-schema constructor; bit numbering follows ICAO Annex 10 IV (4th ed., 2007) table 3-3. -/
def cbColumn (name : String) (start width : Nat) (scale : Rat := 1)
    (offset : Rat := 0) (status : Nat := 0)
    (coding : PayloadCoding := .unsigned) : PayloadColumn :=
  ⟨name, start, width, coding, scale, offset, status⟩
END EXACT SOURCE
-/

/- REVIEW BLOCK 162 — DEPENDENCY
Declaration: Lean1090.Spec.bds10Layout
Source: Spec/CommBLayouts.lean:12
Source span: 11:0–30:24
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., amendment85), table 3-6; Sun (2nd ed.), ch.16, table 16.1. Config is the continuation flag. -/
def bds10Layout : List PayloadColumn :=
  [cbColumn "bds" 1 8,
   cbColumn "config" 9 1,
   cbColumn "reserved" 10 5,
   cbColumn "ovc" 15 1,
   cbColumn "acas" 16 1,
   cbColumn "subnet" 17 7,
   cbColumn "level5" 24 1,
   cbColumn "mode_s" 25 1,
   cbColumn "uplink" 26 3,
   cbColumn "downlink" 29 4,
   cbColumn "identification" 33 1,
   cbColumn "squitter" 34 1,
   cbColumn "sic" 35 1,
   cbColumn "gicb" 36 1,
   cbColumn "acas_hybrid" 37 1,
   cbColumn "acas_ra" 38 1,
   cbColumn "acas_rtca" 39 2,
   cbColumn "dte" 41 16]
END EXACT SOURCE
-/

/- REVIEW BLOCK 163 — DEPENDENCY
Declaration: Lean1090.Spec.bds17Layout
Source: Spec/CommBLayouts.lean:33
Source span: 32:0–59:30
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- Sun (2nd ed.), ch.16, table 16.2; retained spare bits match rs1090-derived observable parsing. -/
def bds17Layout : List PayloadColumn :=
  [cbColumn "bds05" 1 1,
   cbColumn "bds06" 2 1,
   cbColumn "bds07" 3 1,
   cbColumn "bds08" 4 1,
   cbColumn "bds09" 5 1,
   cbColumn "bds0a" 6 1,
   cbColumn "bds20" 7 1,
   cbColumn "bds21" 8 1,
   cbColumn "bds40" 9 1,
   cbColumn "bds41" 10 1,
   cbColumn "bds42" 11 1,
   cbColumn "bds43" 12 1,
   cbColumn "bds44" 13 1,
   cbColumn "bds45" 14 1,
   cbColumn "bds48" 15 1,
   cbColumn "bds50" 16 1,
   cbColumn "bds51" 17 1,
   cbColumn "bds52" 18 1,
   cbColumn "bds53" 19 1,
   cbColumn "bds54" 20 1,
   cbColumn "bds55" 21 1,
   cbColumn "bds56" 22 1,
   cbColumn "bds5f" 23 1,
   cbColumn "bds60" 24 1,
   cbColumn "reserved" 25 5,
   cbColumn "zero_tail" 30 27]
END EXACT SOURCE
-/

/- REVIEW BLOCK 164 — DEPENDENCY
Declaration: Lean1090.Spec.bds18Layout
Source: Spec/CommBLayouts.lean:62
Source span: 61:0–118:25
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- rs1090-derived: pinned bds18.rs field order. No independently read normative table was available for this bitmap. -/
def bds18Layout : List PayloadColumn :=
  [cbColumn "bds38" 1 1,
   cbColumn "bds37" 2 1,
   cbColumn "bds36" 3 1,
   cbColumn "bds35" 4 1,
   cbColumn "bds34" 5 1,
   cbColumn "bds33" 6 1,
   cbColumn "bds32" 7 1,
   cbColumn "bds31" 8 1,
   cbColumn "bds30" 9 1,
   cbColumn "bds2f" 10 1,
   cbColumn "bds2e" 11 1,
   cbColumn "bds2d" 12 1,
   cbColumn "bds2c" 13 1,
   cbColumn "bds2b" 14 1,
   cbColumn "bds2a" 15 1,
   cbColumn "bds29" 16 1,
   cbColumn "bds28" 17 1,
   cbColumn "bds27" 18 1,
   cbColumn "bds26" 19 1,
   cbColumn "bds25" 20 1,
   cbColumn "bds24" 21 1,
   cbColumn "bds23" 22 1,
   cbColumn "bds22" 23 1,
   cbColumn "bds21" 24 1,
   cbColumn "bds20" 25 1,
   cbColumn "bds1f" 26 1,
   cbColumn "bds1e" 27 1,
   cbColumn "bds1d" 28 1,
   cbColumn "bds1c" 29 1,
   cbColumn "bds1b" 30 1,
   cbColumn "bds1a" 31 1,
   cbColumn "bds19" 32 1,
   cbColumn "bds18" 33 1,
   cbColumn "bds17" 34 1,
   cbColumn "bds16" 35 1,
   cbColumn "bds15" 36 1,
   cbColumn "bds14" 37 1,
   cbColumn "bds13" 38 1,
   cbColumn "bds12" 39 1,
   cbColumn "bds11" 40 1,
   cbColumn "bds10" 41 1,
   cbColumn "bds0f" 42 1,
   cbColumn "bds0e" 43 1,
   cbColumn "bds0d" 44 1,
   cbColumn "bds0c" 45 1,
   cbColumn "bds0b" 46 1,
   cbColumn "bds0a" 47 1,
   cbColumn "bds09" 48 1,
   cbColumn "bds08" 49 1,
   cbColumn "bds07" 50 1,
   cbColumn "bds06" 51 1,
   cbColumn "bds05" 52 1,
   cbColumn "bds04" 53 1,
   cbColumn "bds03" 54 1,
   cbColumn "bds02" 55 1,
   cbColumn "bds01" 56 1]
END EXACT SOURCE
-/

/- REVIEW BLOCK 165 — DEPENDENCY
Declaration: Lean1090.Spec.bds19Layout
Source: Spec/CommBLayouts.lean:121
Source span: 120:0–177:25
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- rs1090-derived: pinned bds19.rs field order. No independently read normative table was available for this bitmap. -/
def bds19Layout : List PayloadColumn :=
  [cbColumn "bds70" 1 1,
   cbColumn "bds6f" 2 1,
   cbColumn "bds6e" 3 1,
   cbColumn "bds6d" 4 1,
   cbColumn "bds6c" 5 1,
   cbColumn "bds6b" 6 1,
   cbColumn "bds6a" 7 1,
   cbColumn "bds69" 8 1,
   cbColumn "bds68" 9 1,
   cbColumn "bds67" 10 1,
   cbColumn "bds66" 11 1,
   cbColumn "bds65" 12 1,
   cbColumn "bds64" 13 1,
   cbColumn "bds63" 14 1,
   cbColumn "bds62" 15 1,
   cbColumn "bds61" 16 1,
   cbColumn "bds60" 17 1,
   cbColumn "bds5f" 18 1,
   cbColumn "bds5e" 19 1,
   cbColumn "bds5d" 20 1,
   cbColumn "bds5c" 21 1,
   cbColumn "bds5b" 22 1,
   cbColumn "bds5a" 23 1,
   cbColumn "bds59" 24 1,
   cbColumn "bds58" 25 1,
   cbColumn "bds57" 26 1,
   cbColumn "bds56" 27 1,
   cbColumn "bds55" 28 1,
   cbColumn "bds54" 29 1,
   cbColumn "bds53" 30 1,
   cbColumn "bds52" 31 1,
   cbColumn "bds51" 32 1,
   cbColumn "bds50" 33 1,
   cbColumn "bds4f" 34 1,
   cbColumn "bds4e" 35 1,
   cbColumn "bds4d" 36 1,
   cbColumn "bds4c" 37 1,
   cbColumn "bds4b" 38 1,
   cbColumn "bds4a" 39 1,
   cbColumn "bds49" 40 1,
   cbColumn "bds48" 41 1,
   cbColumn "bds47" 42 1,
   cbColumn "bds46" 43 1,
   cbColumn "bds45" 44 1,
   cbColumn "bds44" 45 1,
   cbColumn "bds43" 46 1,
   cbColumn "bds42" 47 1,
   cbColumn "bds41" 48 1,
   cbColumn "bds40" 49 1,
   cbColumn "bds3f" 50 1,
   cbColumn "bds3e" 51 1,
   cbColumn "bds3d" 52 1,
   cbColumn "bds3c" 53 1,
   cbColumn "bds3b" 54 1,
   cbColumn "bds3a" 55 1,
   cbColumn "bds39" 56 1]
END EXACT SOURCE
-/

/- REVIEW BLOCK 166 — DEPENDENCY
Declaration: Lean1090.Spec.bds20Layout
Source: Spec/CommBLayouts.lean:180
Source span: 179:0–189:25
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-8 and §3.1.2.9.1.2; Sun (2nd ed.), ch.16 table 16.3. -/
def bds20Layout : List PayloadColumn :=
  [cbColumn "bds" 1 8,
   cbColumn "char1" 9 6,
   cbColumn "char2" 15 6,
   cbColumn "char3" 21 6,
   cbColumn "char4" 27 6,
   cbColumn "char5" 33 6,
   cbColumn "char6" 39 6,
   cbColumn "char7" 45 6,
   cbColumn "char8" 51 6]
END EXACT SOURCE
-/

/- REVIEW BLOCK 167 — DEPENDENCY
Declaration: Lean1090.Spec.bds21Layout
Source: Spec/CommBLayouts.lean:192
Source span: 191:0–203:33
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- rs1090-derived: pinned bds21.rs ac_status, seven six-bit registration characters, al_status, two airline characters. -/
def bds21Layout : List PayloadColumn :=
  [cbColumn "ac_status" 1 1,
   cbColumn "reg_char1" 2 6,
   cbColumn "reg_char2" 8 6,
   cbColumn "reg_char3" 14 6,
   cbColumn "reg_char4" 20 6,
   cbColumn "reg_char5" 26 6,
   cbColumn "reg_char6" 32 6,
   cbColumn "reg_char7" 38 6,
   cbColumn "al_status" 44 1,
   cbColumn "airline_char1" 45 6,
   cbColumn "airline_char2" 51 6]
END EXACT SOURCE
-/

/- REVIEW BLOCK 168 — DEPENDENCY
Declaration: Lean1090.Spec.bds30Layout
Source: Spec/CommBLayouts.lean:206
Source span: 205:0–223:41
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., 2007) §4.3.8.4.2.2.1.1–6; Sun (2nd ed.), ch.16 table 16.4. TID is projected according to TTI separately. -/
def bds30Layout : List PayloadColumn :=
  [cbColumn "bds" 1 8,
   cbColumn "issued_ra" 9 1,
   cbColumn "corrective" 10 1 1 0 9,
   cbColumn "downward_sense" 11 1 1 0 9,
   cbColumn "increased_rate" 12 1 1 0 9,
   cbColumn "sense_reversal" 13 1 1 0 9,
   cbColumn "altitude_crossing" 14 1 1 0 9,
   cbColumn "positive" 15 1 1 0 9,
   cbColumn "reserved" 16 7,
   cbColumn "no_below" 23 1 1 0 9,
   cbColumn "no_above" 24 1 1 0 9,
   cbColumn "no_left" 25 1 1 0 9,
   cbColumn "no_right" 26 1 1 0 9,
   cbColumn "terminated" 27 1,
   cbColumn "multiple" 28 1,
   cbColumn "threat_type" 29 2,
   cbColumn "threat_identity_data" 31 26]
END EXACT SOURCE
-/

/- REVIEW BLOCK 169 — DEPENDENCY
Declaration: Lean1090.Spec.bds40Layout
Source: Spec/CommBLayouts.lean:226
Source span: 225:0–240:42
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-10; Sun (2nd ed.), ch.17 table 17.1. Selected altitudes are feet; barometric setting is hPa. -/
def bds40Layout : List PayloadColumn :=
  [cbColumn "mcp_valid" 1 1,
   cbColumn "selected_mcp" 2 12 16 0 1,
   cbColumn "fms_valid" 14 1,
   cbColumn "selected_fms" 15 12 16 0 14,
   cbColumn "qnh_valid" 27 1,
   cbColumn "barometric_setting" 28 12 (1/10) 800 27,
   cbColumn "reserved" 40 8,
   cbColumn "mcp_status" 48 1,
   cbColumn "vnav_mode" 49 1,
   cbColumn "alt_hold_mode" 50 1,
   cbColumn "approach_mode" 51 1,
   cbColumn "reserved2" 52 2,
   cbColumn "source_status" 54 1,
   cbColumn "target_altitude_source" 55 2]
END EXACT SOURCE
-/

/- REVIEW BLOCK 170 — DEPENDENCY
Declaration: Lean1090.Spec.bds44Layout
Source: Spec/CommBLayouts.lean:243
Source span: 242:0–254:42
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- Sun (2nd ed.), ch.18 table 18.1. Temperature scale follows that table; rs1090 wraparound correction is a separate projection. -/
def bds44Layout : List PayloadColumn :=
  [cbColumn "figure_of_merit" 1 4,
   cbColumn "wind_valid" 5 1,
   cbColumn "wind_speed" 6 9 1 0 5,
   cbColumn "wind_direction" 15 9 (180/256) 0 5,
   cbColumn "temperature" 24 11 (1/4) 0 0 .twosComplement,
   cbColumn "pressure_valid" 35 1,
   cbColumn "pressure" 36 11 1 0 35,
   cbColumn "turbulence_valid" 47 1,
   cbColumn "turbulence" 48 2 1 0 47,
   cbColumn "humidity_valid" 50 1,
   cbColumn "humidity" 51 6 (100/64) 0 50]
END EXACT SOURCE
-/

/- REVIEW BLOCK 171 — DEPENDENCY
Declaration: Lean1090.Spec.bds45Layout
Source: Spec/CommBLayouts.lean:257
Source span: 256:0–274:28
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- Sun (2nd ed.), ch.18 table 18.2. Hazard codes 0/1/2/3 mean nil/light/moderate/severe. -/
def bds45Layout : List PayloadColumn :=
  [cbColumn "turbulence_valid" 1 1,
   cbColumn "turbulence" 2 2 1 0 1,
   cbColumn "wind_shear_valid" 4 1,
   cbColumn "wind_shear" 5 2 1 0 4,
   cbColumn "microburst_valid" 7 1,
   cbColumn "microburst" 8 2 1 0 7,
   cbColumn "icing_valid" 10 1,
   cbColumn "icing" 11 2 1 0 10,
   cbColumn "wake_vortex_valid" 13 1,
   cbColumn "wake_vortex" 14 2 1 0 13,
   cbColumn "temperature_valid" 16 1,
   cbColumn "static_temperature" 17 10 (1/4) 0 16 .twosComplement,
   cbColumn "pressure_valid" 27 1,
   cbColumn "static_pressure" 28 11 1 0 27,
   cbColumn "height_valid" 39 1,
   cbColumn "radio_height" 40 12 16 0 39,
   cbColumn "reserved" 52 5]
END EXACT SOURCE
-/

/- REVIEW BLOCK 172 — DEPENDENCY
Declaration: Lean1090.Spec.bds50Layout
Source: Spec/CommBLayouts.lean:277
Source span: 276:0–287:31
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-10; Sun (2nd ed.), ch.17 table 17.2. Angles are degrees, track rate degrees/second, speeds knots. -/
def bds50Layout : List PayloadColumn :=
  [cbColumn "roll_valid" 1 1,
   cbColumn "roll" 2 10 (45/256) 0 1 .twosComplement,
   cbColumn "track_valid" 12 1,
   cbColumn "track" 13 11 (90/512) 0 12 .twosComplement,
   cbColumn "groundspeed_valid" 24 1,
   cbColumn "groundspeed" 25 10 2 0 24,
   cbColumn "track_rate_valid" 35 1,
   cbColumn "track_rate" 36 10 (8/256) 0 35 .twosComplement,
   cbColumn "tas_valid" 46 1,
   cbColumn "TAS" 47 10 2 0 46]
END EXACT SOURCE
-/

/- REVIEW BLOCK 173 — DEPENDENCY
Declaration: Lean1090.Spec.bds60Layout
Source: Spec/CommBLayouts.lean:290
Source span: 289:0–300:59
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-10; Sun (2nd ed.), ch.17 table 17.3. Heading is degrees, IAS knots, rates feet/minute. -/
def bds60Layout : List PayloadColumn :=
  [cbColumn "heading_valid" 1 1,
   cbColumn "heading" 2 11 (90/512) 0 1 .twosComplement,
   cbColumn "ias_valid" 13 1,
   cbColumn "IAS" 14 10 1 0 13,
   cbColumn "mach_valid" 24 1,
   cbColumn "Mach" 25 10 (1/250) 0 24,
   cbColumn "barometric_rate_valid" 35 1,
   cbColumn "vrate_barometric" 36 10 32 0 35 .twosComplement,
   cbColumn "inertial_rate_valid" 46 1,
   cbColumn "vrate_inertial" 47 10 32 0 46 .twosComplement]
END EXACT SOURCE
-/

/- REVIEW BLOCK 174 — DEPENDENCY
Declaration: Lean1090.Spec.commBLayout
Source: Spec/CommBLayouts.lean:304
Source span: 302:0–318:13
Original module: Spec.CommBLayouts
Original imports/opens:
namespace Lean1090.Spec
import Spec.PayloadBits
BEGIN EXACT SOURCE
/-- Sun chs.16–18 register catalogue; supplementary bitmaps/registration are
explicitly rs1090-derived as recorded above. BDS05/65 use ADSB layouts separately. -/
def commBLayout (register : Nat) : Option (List PayloadColumn) :=
  match register with
  | 0x10 => some bds10Layout
  | 0x17 => some bds17Layout
  | 0x18 => some bds18Layout
  | 0x19 => some bds19Layout
  | 0x20 => some bds20Layout
  | 0x21 => some bds21Layout
  | 0x30 => some bds30Layout
  | 0x40 => some bds40Layout
  | 0x44 => some bds44Layout
  | 0x45 => some bds45Layout
  | 0x50 => some bds50Layout
  | 0x60 => some bds60Layout
  | _ => none
END EXACT SOURCE
-/

/- REVIEW BLOCK 175 — DEPENDENCY
Declaration: Lean1090.Spec.ACASFields.parts
Source: Spec/Frame.lean:58
Source span: 57:0–60:79
Original module: Spec.Frame
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Bits
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §§3.1.2.8.2–3: encoder's ACAS field sequence. -/
def ACASFields.parts (f : ACASFields) : List (Nat × Nat) :=
  [(1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat),
   (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat)]
END EXACT SOURCE
-/

/- REVIEW BLOCK 176 — DEPENDENCY
Declaration: Lean1090.Spec.SurveillanceFields.parts
Source: Spec/Frame.lean:63
Source span: 62:0–64:73
Original module: Spec.Frame
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Bits
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §§3.1.2.6.5–8: encoder's surveillance sequence. -/
def SurveillanceFields.parts (f : SurveillanceFields) : List (Nat × Nat) :=
  [(3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat)]
END EXACT SOURCE
-/

/- REVIEW BLOCK 177 — DEPENDENCY
Declaration: Lean1090.Spec.FrameBody.parts
Source: Spec/Frame.lean:68
Source span: 66:0–78:78
Original module: Spec.Frame
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Bits
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), layouts cited on FrameBody: construct fields
in transmission order, independently of the extraction decoder. -/
def FrameBody.parts : FrameBody → List (Nat × Nat)
  | .shortACAS f => (5, 0) :: f.parts
  | .surveillance id f => (5, if id then 5 else 4) :: f.parts
  | .allCall ca aa => [(5, 11), (3, ca.toNat), (24, aa.toNat)]
  | .longACAS f mv => (5, 16) :: f.parts ++ [(56, mv.toNat)]
  | .extended supp cf aa me =>
      [(5, if supp then 18 else 17), (3, cf.toNat), (24, aa.toNat), (56, me.toNat)]
  | .military af bits => [(5, 19), (3, af.toNat), (80, bits.toNat)]
  | .commB id f mb => (5, if id then 21 else 20) :: f.parts ++ [(56, mb.toNat)]
  | .commD spare ke nd md =>
      [(2, 3), (1, spare.toNat), (1, ke.toNat), (4, nd.toNat), (80, md.toNat)]
END EXACT SOURCE
-/

/- REVIEW BLOCK 178 — DEPENDENCY
Declaration: Lean1090.Spec.FrameBody.informationBits
Source: Spec/Frame.lean:81
Source span: 80:0–83:11
Original module: Spec.Frame
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Bits
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.2: short frames have 32 information bits. -/
def FrameBody.informationBits : FrameBody → Nat
  | .shortACAS _ | .surveillance _ _ | .allCall _ _ => 32
  | _ => 88
END EXACT SOURCE
-/

/- REVIEW BLOCK 179 — DEPENDENCY
Declaration: Lean1090.Spec.identityCode
Source: Spec/Frame.lean:94
Source span: 92:0–100:30
Original module: Spec.Frame
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Bits
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.6.7.1: exact Mode A identity digits.
Returned value is the four-digit octal code as a Nat, not decimal text. -/
def identityCode (code : BitVec 13) : Nat :=
  let bit := fun n => (code.toNat / 2^n) % 2
  let a := bit 11 + 2 * bit 9 + 4 * bit 7
  let b := bit 5 + 2 * bit 3 + 4 * bit 1
  let c := bit 12 + 2 * bit 10 + 4 * bit 8
  let d := bit 4 + 2 * bit 2 + 4 * bit 0
  512 * a + 64 * b + 8 * c + d
END EXACT SOURCE
-/

/- REVIEW BLOCK 180 — DEPENDENCY
Declaration: Lean1090.Spec.frameSyndrome
Source: Spec/Message.lean:25
Source span: 23:0–26:79
Original module: Spec.Message
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Frame
import Spec.Parity
import Spec.CommB
import Spec.Semantics
import Spec.Assignment
BEGIN EXACT SOURCE
/-- Annex10 IV (4th ed., 2007) §3.1.2.3.3: the full frame's exact syndrome, expressed on
field assignments without decoding serialized bytes. -/
def frameSyndrome (f : Frame) : BitVec 24 :=
  Parity.checksum f.body.informationBits (packFields f.body.parts) ^^^ f.parity
END EXACT SOURCE
-/

/- REVIEW BLOCK 181 — DEPENDENCY
Declaration: Lean1090.Spec.frameAccepted
Source: Spec/Message.lean:31
Source span: 28:0–35:13
Original module: Spec.Message
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
import Spec.Frame
import Spec.Parity
import Spec.CommB
import Spec.Semantics
import Spec.Assignment
BEGIN EXACT SOURCE
/-- rs1090-derived decode/mod.rs and bds05/65 acceptance policy: DF17
requires zero PI syndrome; DF18 does not. ADSB altitude/reserved-bit filters
apply to both. Standard Comm-D is accepted despite the D001 oracle over-read. -/
def frameAccepted (f : Frame) : Bool :=
  match f.body with
  | .extended supplementary _ _ me =>
      adsbHardValid me.toNat && (supplementary || frameSyndrome f == 0)
  | _ => true
END EXACT SOURCE
-/

/- REVIEW BLOCK 182 — DEPENDENCY
Declaration: Lean1090.Spec.Parity.generator
Source: Spec/Parity.lean:17
Source span: 16:0–17:32
Original module: Spec.Parity
Original imports/opens:
namespace Lean1090.Spec.Parity
import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: generator including leading x^24. -/
def generator : Nat := 0x1FFF409
END EXACT SOURCE
-/

/- REVIEW BLOCK 183 — DEPENDENCY
Declaration: Lean1090.Spec.Parity.step
Source: Spec/Parity.lean:21
Source span: 19:0–23:85
Original module: Spec.Parity
Original imports/opens:
namespace Lean1090.Spec.Parity
import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: multiply the remainder by x,
append one coefficient, then cancel x^24 when present. -/
def step (remainder : BitVec 24) (bit : Bool) : BitVec 24 :=
  let shifted := 2 * remainder.toNat + if bit then 1 else 0
  BitVec.ofNat 24 (if remainder.toNat ≥ 2^23 then shifted ^^^ generator else shifted)
END EXACT SOURCE
-/

/- REVIEW BLOCK 184 — DEPENDENCY
Declaration: Lean1090.Spec.Parity.syndrome
Source: Spec/Parity.lean:27
Source span: 25:0–29:60
Original module: Spec.Parity
Original imports/opens:
namespace Lean1090.Spec.Parity
import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: receiver remainder of the full
word, with no initial/final complement and no extra trailing zero bits. -/
def syndrome (width word : Nat) : BitVec 24 :=
  (List.range width).foldl
    (fun rem i => step rem (word.testBit (width - 1 - i))) 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 185 — DEPENDENCY
Declaration: Lean1090.Spec.Parity.checksum
Source: Spec/Parity.lean:32
Source span: 31:0–33:55
Original module: Spec.Parity
Original imports/opens:
namespace Lean1090.Spec.Parity
import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: sender appends 24 zero bits. -/
def checksum (informationWidth information : Nat) : BitVec 24 :=
  syndrome (informationWidth + 24) (information * 2^24)
END EXACT SOURCE
-/

/- REVIEW BLOCK 186 — DEPENDENCY
Declaration: Lean1090.Spec.Parity.generatorPolynomial
Source: Spec/Parity.lean:43
Source span: 41:0–45:46
Original module: Spec.Parity
Original imports/opens:
namespace Lean1090.Spec.Parity
import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: independently state G(X)
using its published list of powers, not the recurrence's integer constant. -/
noncomputable def generatorPolynomial : Polynomial (ZMod 2) :=
  [0, 3, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24].foldl
    (fun p i => p + Polynomial.monomial i 1) 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 187 — DEPENDENCY
Declaration: Lean1090.Spec.Parity.interrogator
Source: Spec/Parity.lean:64
Source span: 61:0–67:11
Original module: Spec.Parity
Original imports/opens:
namespace Lean1090.Spec.Parity
import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic
BEGIN EXACT SOURCE
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.2: recover CL/IC only when
the remaining seventeen syndrome bits are zero; this does not establish
which interrogator actually transmitted a possibly corrupted message. -/
def interrogator (s : BitVec 24) : Option (BitVec 3 × BitVec 4) :=
  if s.toNat < 128 then
    some (BitVec.ofNat 3 (s.toNat / 16), BitVec.ofNat 4 s.toNat)
  else none
END EXACT SOURCE
-/

/- REVIEW BLOCK 188 — DEPENDENCY
Declaration: Lean1090.Spec.payloadBits
Source: Spec/PayloadBits.lean:8
Source span: 7:0–9:51
Original module: Spec.PayloadBits
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: extract a field at a one-based payload bit position. -/
def payloadBits (word start width : Nat) : Nat :=
  word / 2 ^ (56 - (start - 1 + width)) % 2 ^ width
END EXACT SOURCE
-/

/- REVIEW BLOCK 189 — DEPENDENCY
Declaration: Lean1090.Spec.ValidPayloadFields
Source: Spec/PayloadBits.lean:13
Source span: 11:0–16:17
Original module: Spec.PayloadBits
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
BEGIN EXACT SOURCE
/-- A schema record contains exactly its declared fields in table order and each
code fits its field width. This condition does not invoke decoding or encoding. -/
def ValidPayloadFields : List PayloadColumn → List PayloadField → Prop
  | [], [] => True
  | c :: cs, f :: fs => f.name = c.name ∧ f.code < 2 ^ c.width ∧ ValidPayloadFields cs fs
  | _, _ => False
END EXACT SOURCE
-/

/- REVIEW BLOCK 190 — DEPENDENCY
Declaration: Lean1090.Spec.encodePayloadFields
Source: Spec/PayloadBits.lean:37
Source span: 35:0–39:13
Original module: Spec.PayloadBits
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
BEGIN EXACT SOURCE
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: independent encoder places each supplied field
at its table position; it does not call a decoder or search for a preimage. -/
def encodePayloadFields : List PayloadColumn → List PayloadField → Nat
  | c :: cs, f :: fs => f.code * 2 ^ (56 - (c.start - 1 + c.width)) + encodePayloadFields cs fs
  | _, _ => 0
END EXACT SOURCE
-/

/- REVIEW BLOCK 191 — DEPENDENCY
Declaration: Lean1090.Spec.payloadInteger
Source: Spec/PayloadBits.lean:42
Source span: 41:0–44:46
Original module: Spec.PayloadBits
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.17, signed EHS fields: integer interpretation before scaling. -/
def payloadInteger (coding : PayloadCoding) (width code : Nat) : Int :=
  if coding = .twosComplement ∧ code ≥ 2 ^ (width - 1) then
    (code : Int) - (2 ^ width : Nat) else code
END EXACT SOURCE
-/

/- REVIEW BLOCK 192 — DEPENDENCY
Declaration: Lean1090.Spec.payloadValue
Source: Spec/PayloadBits.lean:48
Source span: 46:0–51:87
Original module: Spec.PayloadBits
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
BEGIN EXACT SOURCE
/-- Sun chs.6–8,16–18 tables: exact field interpretation, with absent status
represented by `none`; nonlinear fields have dedicated projections. -/
def payloadValue (column : PayloadColumn) (word : Nat) : Option Rat :=
  if column.status != 0 && payloadBits word column.status 1 == 0 then none
  else some ((payloadInteger column.coding column.width
    (payloadBits word column.start column.width) : Rat) * column.scale + column.offset)
END EXACT SOURCE
-/

/- REVIEW BLOCK 193 — DEPENDENCY
Declaration: Lean1090.Spec.payloadField
Source: Spec/PayloadBits.lean:54
Source span: 53:0–55:60
Original module: Spec.PayloadBits
Original imports/opens:
namespace Lean1090.Spec
import Model.Types
BEGIN EXACT SOURCE
/-- Source-table field lookup. Missing fields remain distinguishable from code zero. -/
def payloadField (record : PayloadRecord) (name : String) : Option Nat :=
  (record.fields.find? fun f => f.name == name).map (·.code)
END EXACT SOURCE
-/

/- REVIEW BLOCK 194 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.scaled
Source: Spec/Presentation.lean:27
Source span: 26:0–28:84
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090 angle readers: multiply THEN divide, without algebraic reassociation. -/
def scaled (p : Precision) (value numerator denominator : Rat) : FloatExpr :=
  .div p (.mul p (.literal p value) (.literal p numerator)) (.literal p denominator)
END EXACT SOURCE
-/

/- REVIEW BLOCK 195 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.oraclePi
Source: Spec/Presentation.lean:31
Source span: 30:0–31:55
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090 bds09.rs: Rust's binary64 PI constant, represented exactly as Rat. -/
def oraclePi : Rat := 884279719003555 / 281474976710656
END EXACT SOURCE
-/

/- REVIEW BLOCK 196 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.velocitySpeed
Source: Spec/Presentation.lean:35
Source span: 33:0–36:76
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090 bds09.rs GroundSpeedDecoding: hypot(abs(EW),abs(NS)), with signed
integer components supplied by a separately named standard or oracle view. -/
def velocitySpeed (ew ns : Int) : FloatExpr :=
  .hypot64 (.abs64 (.literal .binary64 ew)) (.abs64 (.literal .binary64 ns))
END EXACT SOURCE
-/

/- REVIEW BLOCK 197 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.velocityTrack
Source: Spec/Presentation.lean:40
Source span: 38:0–44:77
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090 bds09.rs GroundSpeedDecoding: atan2(EW,NS) * (360/(2*PI)),
then add360 iff negative. Parenthesization is part of the tested contract. -/
def velocityTrack (ew ns : Int) : FloatExpr :=
  .addIfNegative64 (.mul .binary64
    (.atan2_64 (.literal .binary64 ew) (.literal .binary64 ns))
    (.div .binary64 (.literal .binary64 360)
      (.mul .binary64 (.literal .binary64 2) (.literal .binary64 oraclePi))))
END EXACT SOURCE
-/

/- REVIEW BLOCK 198 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.standardVelocityComponents
Source: Spec/Presentation.lean:48
Source span: 46:0–56:59
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table7.2 and equations7.6–7.9: component0 is unavailable;
subtype2 has4kt resolution. This is distinct from the pinned oracle defect. -/
def standardVelocityComponents (word : Nat) : Option (Int × Int) := do
  let subtype := payloadBits word 6 3
  if subtype != 1 && subtype != 2 then none else do
    let ew := payloadBits word 15 10
    let ns := payloadBits word 26 10
    if ew == 0 || ns == 0 then none else
      let factor := if subtype == 2 then 4 else 1
      some (adsbSigned (payloadBits word 14 1) ((ew-1)*factor),
        adsbSigned (payloadBits word 25 1) ((ns-1)*factor))
END EXACT SOURCE
-/

/- REVIEW BLOCK 199 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.standardVerticalSource
Source: Spec/Presentation.lean:59
Source span: 58:0–60:61
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun 2nd ed., table7.1 and §7.1:0 denotes GNSS,1 barometric. -/
def standardVerticalSource (word : Nat) : String :=
  if payloadBits word 36 1 == 0 then "GNSS" else "barometric"
END EXACT SOURCE
-/

/- REVIEW BLOCK 200 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.oracleVerticalSource
Source: Spec/Presentation.lean:63
Source span: 62:0–64:61
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds09.rs VerticalRateSource reverses Sun's source labels. -/
def oracleVerticalSource (word : Nat) : String :=
  if payloadBits word 36 1 == 0 then "barometric" else "GNSS"
END EXACT SOURCE
-/

/- REVIEW BLOCK 201 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.standardGeoMinusBaro
Source: Spec/Presentation.lean:68
Source span: 66:0–71:62
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun 2nd ed., §7.2 equation7.4:0 and127 are unavailable; code1 means0ft.
The oracle's different availability is adsbGeoMinusBaro in Spec.ADSB. -/
def standardGeoMinusBaro (word : Nat) : Option Int :=
  let code := payloadBits word 50 7
  if code == 0 || code == 127 then none
  else some (adsbSigned (payloadBits word 49 1) ((code-1)*25))
END EXACT SOURCE
-/

/- REVIEW BLOCK 202 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.standardGNSSHeightMetres
Source: Spec/Presentation.lean:75
Source span: 73:0–77:69
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun 2nd ed., §5.5.2: TC20–22 height is unsigned metres, not Q/Gillham
feet. This exact quantity is distinct from the oracle AC12 compatibility view. -/
def standardGNSSHeightMetres (word : Nat) : Option Nat :=
  let tc := payloadBits word 1 5
  if 20 <= tc && tc <= 22 then some (payloadBits word 9 12) else none
END EXACT SOURCE
-/

/- REVIEW BLOCK 203 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.oracleADSBFloats
Source: Spec/Presentation.lean:82
Source span: 79:0–106:9
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds06.rs,bds09.rs,bds62.rs: all floating payload fields
reported for ADS-B before resolved CPR coordinates. Subtype4's heading is
computed in binary32 then widened exactly by its serde helper. -/
def oracleADSBFloats (word : Nat) : List NumericField :=
  let tc := payloadBits word 1 5
  let bits := payloadBits word
  if 5 <= tc && tc <= 8 then
    [⟨"groundspeed", (adsbMovement (bits 6 7)).map (.literal .binary64), .null⟩,
     ⟨"track", if bits 13 1 == 0 then none else
       some (scaled .binary64 (bits 14 7) 360 128), .null⟩]
  else if tc == 19 then
    let st := bits 6 3
    if st == 1 || st == 2 then
      let (ew, ns) := adsbOracleVelocityComponents word
      [⟨"groundspeed", some (velocitySpeed ew ns), .null⟩,
       ⟨"track", some (velocityTrack ew ns), .null⟩]
    else if st == 3 || st == 4 then
      [⟨"heading", if bits 14 1 == 0 then none else
        some (scaled (if st == 3 then .binary64 else .binary32) (bits 15 10) 360 1024), .omit⟩]
    else []
  else if tc == 29 then
    let pressure := bits 21 9
    [⟨"barometric_setting", if pressure == 0 then none else
       some (.add .binary32 (.literal .binary32 800)
         (.mul .binary32 (.literal .binary32 (pressure-1)) (.literal .binary32 (4/5)))), .omit⟩,
     ⟨"selected_heading", if bits 30 1 == 0 then none else
       some (scaled .binary32 (bits 31 9) 180 256), .omit⟩]
  else []
END EXACT SOURCE
-/

/- REVIEW BLOCK 204 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.statusValue
Source: Spec/Presentation.lean:110
Source span: 108:0–111:61
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived status-gated numeric readers: zero status omits the exact
operand; invalid nonzero unavailable fields are rejected upstream by inference. -/
def statusValue (word status : Nat) (value : FloatExpr) : Option FloatExpr :=
  if payloadBits word status 1 == 0 then none else some value
END EXACT SOURCE
-/

/- REVIEW BLOCK 205 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.signedCode
Source: Spec/Presentation.lean:115
Source span: 113:0–117:77
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), ch.17 signed EHS fields, also used by the oracle: combine sign and
magnitude as two's complement before scaling. -/
def signedCode (word sign start width : Nat) : Int :=
  let raw := payloadBits word start width
  if payloadBits word sign 1 == 0 then raw else (raw : Int) - (2^width : Nat)
END EXACT SOURCE
-/

/- REVIEW BLOCK 206 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.oracleMeteoTemperature
Source: Spec/Presentation.lean:122
Source span: 119:0–125:62
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds44.rs read_temperature: quarter-degree signed value;
legacy avionics compatibility adds256 when below−80. Arithmetic here is exact
because all possible operands and results are dyadic and small. -/
def oracleMeteoTemperature (word : Nat) : Rat :=
  let signed := signedCode word 24 25 10
  let temperature : Rat := (signed : Rat) / 4
  if temperature < -80 then temperature + 256 else temperature
END EXACT SOURCE
-/

/- REVIEW BLOCK 207 — DEPENDENCY
Declaration: Lean1090.Spec.Presentation.oracleCommBFloats
Source: Spec/Presentation.lean:132
Source span: 127:0–164:11
Original module: Spec.Presentation
Original imports/opens:
namespace Lean1090.Spec.Presentation
import Model.Types
import Spec.ADSB
BEGIN EXACT SOURCE
/-- rs1090-derived bds30/40/44/45/50/60: every floating field on a successfully
selected candidate. Integer-valued fields (including rates and rounded selected
altitudes) remain exact in other semantic projections; no Float expression is
introduced for them. Register65 shares ADS-B fields but has no floating payload.
The candidate decoder, not this presentation function, enforces validity. -/
def oracleCommBFloats (bds word : Nat) : List NumericField :=
  let bits := payloadBits word
  match bds with
  | 0x30 =>
      if bits 29 2 != 2 then [] else
        let range := bits 44 7
        [⟨"threat_range", if range == 0 then none else
          some (.div .binary32
            (.sub .binary32 (.literal .binary32 range) (.literal .binary32 1))
            (.literal .binary32 10)), .null⟩]
  | 0x40 =>
      [⟨"barometric_setting", statusValue word 27
        (.add .binary64 (.mul .binary64 (.literal .binary64 (bits 28 12))
          (.literal .binary64 (1/10))) (.literal .binary64 800)), .omit⟩]
  | 0x44 =>
      [⟨"wind_direction", statusValue word 5 (scaled .binary64 (bits 15 9) 180 256), .null⟩,
       ⟨"temperature", some (.literal .binary64 (oracleMeteoTemperature word)), .null⟩,
       ⟨"humidity", statusValue word 50 (scaled .binary64 (bits 51 6) 100 64), .null⟩]
  | 0x45 =>
      [⟨"static_temperature", statusValue word 16
        (scaled .binary64 (signedCode word 17 18 9) 1 4), .null⟩]
  | 0x50 =>
      [⟨"roll", statusValue word 1
        (scaled .binary64 (signedCode word 2 3 9) 45 256), .null⟩,
       ⟨"track", statusValue word 12
        (.addIfNegative64 (scaled .binary64 (signedCode word 13 14 10) 90 512)), .null⟩,
       ⟨"track_rate", if bits 37 9 == 511 then none else statusValue word 35
        (scaled .binary64 (signedCode word 36 37 9) 8 256), .null⟩]
  | 0x60 =>
      [⟨"heading", statusValue word 1
        (.addIfNegative64 (scaled .binary64 (signedCode word 2 3 10) 90 512)), .omit⟩,
       ⟨"Mach", statusValue word 24 (scaled .binary64 (bits 25 10) (256/125) 512), .omit⟩]
  | _ => []
END EXACT SOURCE
-/

/- REVIEW BLOCK 208 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.tableValues
Source: Spec/Semantics.lean:25
Source span: 23:0–26:51
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- Source-table affine projections, including every raw/reserved/status
column so booleans and discriminants remain explicitly proof-visible. -/
def tableValues (layout : List PayloadColumn) (word : Nat) : Values :=
  layout.map fun c => (c.name, payloadValue c word)
END EXACT SOURCE
-/

/- REVIEW BLOCK 209 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.wakeVortex
Source: Spec/Semantics.lean:30
Source span: 28:0–41:17
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), table4.1 category meanings; output spelling is rs1090-derived
from bds08.rs WakeVortex's serde names, including its TC2 category mapping. -/
def wakeVortex (tc category : Nat) : String :=
  if tc == 1 then "Reserved" else if category == 0 then "n/a" else
  if tc == 2 then
    if category == 1 then "Surface emergency vehicle"
    else if category == 3 then "Surface service vehicle" else "Obstruction"
  else if tc == 3 then
    (["n/a", "Glider", "Lighter than air", "Parachutist", "Ultralight",
      "Reserved", "UAV", "Space"].getD category "Reserved")
  else if tc == 4 then
    (["n/a", "<7000kg", "<34,000kg", "<136,000kg", "High vortex",
      "Heavy", "High performance", "Rotorcraft"].getD category "Reserved")
  else "Reserved"
END EXACT SOURCE
-/

/- REVIEW BLOCK 210 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.emergency
Source: Spec/Semantics.lean:44
Source span: 43:0–46:80
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- rs1090-derived bds61.rs EmergencyState serde names for the eight codes. -/
def emergency (code : Nat) : String :=
  ["none", "general", "medical", "minimum_fuel", "no_communication",
    "unlawful_interference", "downed_aircraft", "reserved"].getD code "reserved"
END EXACT SOURCE
-/

/- REVIEW BLOCK 211 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.adsbLabels
Source: Spec/Semantics.lean:109
Source span: 107:0–125:9
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), tables4.1/7.1; rs1090-derived bds61/62 enum labels. Internal source
labels are explicit; serialized aliases are described in SCOPE.md. -/
def adsbLabels (oracle : Bool) (word : Nat) : Labels :=
  let b := payloadBits word
  let tc := b 1 5
  if 1 <= tc && tc <= 4 then
    [("callsign", some (adsbCallsign word)), ("wake_vortex", some (wakeVortex tc (b 6 3)))]
  else if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("source", some (if tc < 19 then "barometric" else "GNSS"))]
  else if tc == 19 then
    [("vrate_src", some (if oracle then oracleVerticalSource word else standardVerticalSource word)),
     ("airspeed_type", if b 6 3 == 3 || b 6 3 == 4 then
        some (if b 25 1 == 0 then "IAS" else "TAS") else none)]
  else if tc == 28 then
    [("subtype", some (["no_information", "emergency_priority", "acas_ra"].getD (b 6 3) "reserved")),
     ("emergency_state", some (emergency (b 9 3)))]
  else if tc == 29 then
    [("source", some (if b 9 1 == 0 then "MCP/FCU" else "FMS"))]
  else []
END EXACT SOURCE
-/

/- REVIEW BLOCK 212 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.adsbStandardFloats
Source: Spec/Semantics.lean:129
Source span: 127:0–136:28
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), table7.2 standard signed components feed the same tested hypot/atan2
formula as the oracle. No Float accuracy is claimed by this expression. -/
def adsbStandardFloats (word : Nat) : List NumericField :=
  let tc := payloadBits word 1 5
  let subtype := payloadBits word 6 3
  if tc == 19 && (subtype == 1 || subtype == 2) then
    let components := standardVelocityComponents word
    [⟨"groundspeed", components.map (fun p => velocitySpeed p.1 p.2), .null⟩,
     ⟨"track", components.map (fun p => velocityTrack p.1 p.2), .null⟩]
  else oracleADSBFloats word
END EXACT SOURCE
-/

/- REVIEW BLOCK 213 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.airline
Source: Spec/Semantics.lean:148
Source span: 146:0–151:56
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- rs1090-derived bds21.rs: optional airline string uses the same placeholder
removal as registration. Valid inference currently requires it unavailable. -/
def airline (word : Nat) : Option String :=
  if payloadBits word 44 1 == 0 then none else
    some (String.ofList (([payloadBits word 45 6, payloadBits word 51 6].filter
      (fun c => !cbDashPlaceholder c)).map cbCharacter))
END EXACT SOURCE
-/

/- REVIEW BLOCK 214 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.hazard
Source: Spec/Semantics.lean:154
Source span: 153:0–156:48
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), table18.2 hazard meanings, with rs1090-derived enum spelling. -/
def hazard (value : Option Rat) : Option String :=
  value.map fun v => if v == 0 then "Nil" else if v == 1 then "Light"
    else if v == 2 then "Moderate" else "Severe"
END EXACT SOURCE
-/

/- REVIEW BLOCK 215 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.commBLabels
Source: Spec/Semantics.lean:160
Source span: 158:0–174:9
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- ICAO Annex10 IV, 4th ed. (2007), table3-8 strings and Sun, 2nd ed. (2021), table18.1/18.2 enums; target-source names
and JSON label spelling are rs1090-derived bds21/40/44/45 policies. -/
def commBLabels (register word : Nat) : Labels :=
  if register == 0x20 then [("callsign", some (cbCallsign word))]
  else if register == 0x21 then
    [("registration", cbRegistration word), ("airline", airline word)]
  else if register == 0x40 then
    [("target_altitude_source", some (["Unknown", "AircraftAltitude",
      "FcpMcuSelectedAltitude", "FmsSelectedAltitude"].getD (payloadBits word 55 2) "Unknown"))]
  else if register == 0x44 then
    [("figure_of_merit", some (["Invalid", "INS", "GNSS", "DMEDME", "VORDME"].getD
      (payloadBits word 1 4) "Reserved")),
     ("turbulence", hazard (commBValue register word "turbulence"))]
  else if register == 0x45 then
    ["turbulence", "wind_shear", "microburst", "icing", "wake_vortex"].map
      fun name => (name, hazard (commBValue register word name))
  else []
END EXACT SOURCE
-/

/- REVIEW BLOCK 216 — DEPENDENCY
Declaration: Lean1090.Spec.Semantics.commBStandardFloats
Source: Spec/Semantics.lean:180
Source span: 176:0–185:16
Original module: Spec.Semantics
Original imports/opens:
namespace Lean1090.Spec.Semantics
import Model.Types
import Spec.CommB
import Spec.Presentation
open Presentation
BEGIN EXACT SOURCE
/-- Sun, 2nd ed. (2021), table18.1 temperature is signed quarter-degrees without the oracle's
legacy wrap. ICAO §4.3.8.4.2.2.1.6 range/bearing are typed estimates/sectors
in standardThreat, so no scalar Float replaces those standard meanings.
Other numeric programs use the exact operands and oracle operation order. -/
def commBStandardFloats (register word : Nat) : List NumericField :=
  if register == 0x30 then [] else
    (oracleCommBFloats register word).map fun field =>
      if register == 0x44 && field.key == "temperature" then
        { field with value := some (.literal .binary64 (cbSigned word 24 11 / 4)) }
      else field
END EXACT SOURCE
-/

/- REVIEW BLOCK 217 — LIBRARY SEMANTICS
Declaration: Polynomial.modByMonic
Source: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Div.lean:138
Source span: 137:0–140:55
Original module: Mathlib.Algebra.Polynomial.Div
Original imports/opens:
namespace Polynomial
public import Mathlib.Algebra.Polynomial.Inductions
public import Mathlib.Algebra.Polynomial.Monic
public import Mathlib.RingTheory.Multiplicity
import Mathlib.Algebra.Field.IsField
import Mathlib.Order.Lattice.Nat
open Polynomial
open Finset
BEGIN EXACT SOURCE
/-- `modByMonic`, denoted as `p %ₘ q`, gives the remainder of `p` by a monic polynomial `q`. -/
def modByMonic (p q : R[X]) : R[X] :=
  letI := Classical.decEq R
  if hq : Monic q then (divModByMonicAux p hq).2 else p
END EXACT SOURCE
-/

/- REVIEW BLOCK 218 — LIBRARY SEMANTICS
Declaration: Polynomial.divModByMonicAux
Source: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Div.lean:121
Source span: 120:0–130:23
Original module: Mathlib.Algebra.Polynomial.Div
Original imports/opens:
namespace Polynomial
public import Mathlib.Algebra.Polynomial.Inductions
public import Mathlib.Algebra.Polynomial.Monic
public import Mathlib.RingTheory.Multiplicity
import Mathlib.Algebra.Field.IsField
import Mathlib.Order.Lattice.Nat
open Polynomial
open Finset
BEGIN EXACT SOURCE
/-- See `divByMonic`. -/
noncomputable def divModByMonicAux : ∀ (_p : R[X]) {q : R[X]}, Monic q → R[X] × R[X]
  | p, q, hq =>
    letI := Classical.decEq R
    if h : degree q ≤ degree p ∧ p ≠ 0 then
      let z := C (leadingCoeff p) * X ^ (natDegree p - natDegree q)
      have _wf := div_wf_lemma h hq
      let dm := divModByMonicAux (p - q * z) hq
      ⟨z + dm.1, dm.2⟩
    else ⟨0, p⟩
  termination_by p => p
END EXACT SOURCE
-/

/- REVIEW BLOCK 219 — LIBRARY SEMANTICS
Declaration: Polynomial.div_wf_lemma
Source: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Div.lean:107
Source span: 107:0–118:83
Original module: Mathlib.Algebra.Polynomial.Div
Original imports/opens:
namespace Polynomial
public import Mathlib.Algebra.Polynomial.Inductions
public import Mathlib.Algebra.Polynomial.Monic
public import Mathlib.RingTheory.Multiplicity
import Mathlib.Algebra.Field.IsField
import Mathlib.Order.Lattice.Nat
open Polynomial
open Finset
BEGIN EXACT SOURCE
theorem div_wf_lemma (h : degree q ≤ degree p ∧ p ≠ 0) (hq : Monic q) :
    degree (p - q * (C (leadingCoeff p) * X ^ (natDegree p - natDegree q))) < degree p :=
  have hp : leadingCoeff p ≠ 0 := mt leadingCoeff_eq_zero.1 h.2
  have hq0 : q ≠ 0 := hq.ne_zero_of_polynomial_ne h.2
  have hlt : natDegree q ≤ natDegree p :=
    (Nat.cast_le (α := WithBot ℕ)).1
      (by rw [← degree_eq_natDegree h.2, ← degree_eq_natDegree hq0]; exact h.1)
  degree_sub_lt_left
    (by
      rw [hq.degree_mul_comm, hq.degree_mul, degree_C_mul_X_pow _ hp, degree_eq_natDegree h.2,
        degree_eq_natDegree hq0, ← Nat.cast_add, tsub_add_cancel_of_le hlt])
    h.2 (by rw [leadingCoeff_monic_mul hq, leadingCoeff_mul_X_pow, leadingCoeff_C])
END EXACT SOURCE
-/

/- REVIEW BLOCK 220 — LIBRARY SEMANTICS
Declaration: Polynomial.monomial
Source: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Basic.lean:375
Source span: 374:0–378:45
Original module: Mathlib.Algebra.Polynomial.Basic
Original imports/opens:
namespace Polynomial
public import Mathlib.Algebra.Group.AddChar
public import Mathlib.Algebra.MonoidAlgebra.Module
public import Mathlib.Algebra.MonoidAlgebra.NoZeroDivisors
public import Mathlib.Algebra.Order.Group.Nat
public import Mathlib.Algebra.Ring.Action.Rat
public import Mathlib.Data.Finset.Sort
open AddMonoidAlgebra Finset Module
open Finsupp hiding single
open Function hiding Commute
BEGIN EXACT SOURCE
/-- `monomial s a` is the monomial `a * X^s` -/
def monomial (n : ℕ) : R →ₗ[R] R[X] where
  toFun t := ⟨.single n t⟩
  map_add' x y := by simp [← ofFinsupp_add]
  map_smul' r x := by simp [← ofFinsupp_smul]
END EXACT SOURCE
-/

/- REVIEW BLOCK 221 — LIBRARY SEMANTICS
Declaration: ZMod
Source: .lake/packages/mathlib/Mathlib/Data/ZMod/Defs.lean:139
Source span: 137:0–141:24
Original module: Mathlib.Data.ZMod.Defs
Original imports/opens:
namespace <root>
public import Mathlib.Algebra.Group.Fin.Basic
public import Mathlib.Algebra.Ring.GrindInstances  -- shake: keep (used in `example` only)
public import Mathlib.Algebra.Ring.Int.Defs
public import Mathlib.Data.Fintype.EquivFin
public import Mathlib.Data.Nat.ModEq
import Mathlib.Algebra.Ring.Nat
open Nat.ModEq Int
open scoped Fin.IntCast Fin.NatCast
BEGIN EXACT SOURCE
/-- The integers modulo `n : ℕ`. -/
@[to_additive_dont_translate]
def ZMod : ℕ → Type
  | 0 => ℤ
  | n + 1 => Fin (n + 1)
END EXACT SOURCE
-/

/- REVIEW BLOCK 222 — LIBRARY SEMANTICS
Declaration: Real.arccos
Source: .lake/packages/mathlib/Mathlib/Analysis/SpecialFunctions/Trigonometric/Inverse.lean:277
Source span: 274:0–278:18
Original module: Mathlib.Analysis.SpecialFunctions.Trigonometric.Inverse
Original imports/opens:
namespace Real
public import Mathlib.Analysis.SpecialFunctions.Trigonometric.Basic
import Mathlib.Topology.Order.ProjIcc
open Filter Set Filter Real
open scoped Topology
BEGIN EXACT SOURCE
/-- Inverse of the `cos` function, returns values in the range `0 ≤ arccos x` and `arccos x ≤ π`.
  It defaults to `π` on `(-∞, -1)` and to `0` to `(1, ∞)`. -/
@[pp_nodot]
noncomputable def arccos (x : ℝ) : ℝ :=
  π / 2 - arcsin x
END EXACT SOURCE
-/

/- REVIEW BLOCK 223 — LIBRARY SEMANTICS
Declaration: Real.arcsin
Source: .lake/packages/mathlib/Mathlib/Analysis/SpecialFunctions/Trigonometric/Inverse.lean:36
Source span: 33:0–37:68
Original module: Mathlib.Analysis.SpecialFunctions.Trigonometric.Inverse
Original imports/opens:
namespace Real
public import Mathlib.Analysis.SpecialFunctions.Trigonometric.Basic
import Mathlib.Topology.Order.ProjIcc
open Filter Set Filter Real
open scoped Topology
BEGIN EXACT SOURCE
/-- Inverse of the `sin` function, returns values in the range `-π / 2 ≤ arcsin x ≤ π / 2`.
It defaults to `-π / 2` on `(-∞, -1)` and to `π / 2` to `(1, ∞)`. -/
@[pp_nodot]
noncomputable def arcsin : ℝ → ℝ :=
  Subtype.val ∘ IccExtend (neg_le_self zero_le_one) sinOrderIso.symm
END EXACT SOURCE
-/

/- REVIEW BLOCK 224 — LIBRARY SEMANTICS
Declaration: Real.pi
Source: .lake/packages/mathlib/Mathlib/Analysis/SpecialFunctions/Trigonometric/Basic.lean:128
Source span: 122:0–129:41
Original module: Mathlib.Analysis.SpecialFunctions.Trigonometric.Basic
Original imports/opens:
namespace Real
public import Mathlib.Algebra.Field.NegOnePow
public import Mathlib.Algebra.Field.Periodic
public import Mathlib.Algebra.Polynomial.Eval.Defs
public import Mathlib.Algebra.QuadraticDiscriminant
public import Mathlib.Analysis.SpecialFunctions.Exp
open Filter Set
open scoped Topology
BEGIN EXACT SOURCE
/-- The number π = 3.14159265... Defined here using choice as twice a zero of cos in [1,2],
from which one can derive all its properties. For explicit bounds on π,
see `Mathlib/Analysis/Real/Pi/Bounds.lean`.

Denoted `π`, once the `Real` namespace is opened. -/
@[wikidata Q167]
protected noncomputable def pi : ℝ :=
  2 * Classical.choose exists_cos_eq_zero
END EXACT SOURCE
-/

/- REVIEW BLOCK 225 — LIBRARY SEMANTICS
Declaration: Real.cos
Source: .lake/packages/mathlib/Mathlib/Analysis/Complex/Trigonometric.lean:77
Source span: 77:0–80:12
Original module: Mathlib.Analysis.Complex.Trigonometric
Original imports/opens:
namespace Real
public import Mathlib.Analysis.Complex.Exponential
open Finset
open scoped ComplexConjugate
open Complex
BEGIN EXACT SOURCE
/-- The real cosine function, defined as the real part of the complex cosine -/
@[pp_nodot]
nonrec def cos (x : ℝ) : ℝ :=
  (cos x).re
END EXACT SOURCE
-/

/- REVIEW BLOCK 226 — LIBRARY SEMANTICS
Declaration: Real.sqrt
Source: .lake/packages/mathlib/Mathlib/Analysis/Real/Sqrt.lean:108
Source span: 108:0–112:31
Original module: Mathlib.Analysis.Real.Sqrt
Original imports/opens:
namespace Real
public import Mathlib.Topology.Instances.NNReal.Lemmas
open Set Filter
open scoped Filter NNReal Topology
BEGIN EXACT SOURCE
/-- The square root of a real number. This returns 0 for negative inputs.

This has notation `√x`. Note that `√x⁻¹` is parsed as `√(x⁻¹)`. -/
@[irreducible] noncomputable def sqrt (x : ℝ) : ℝ :=
  NNReal.sqrt (Real.toNNReal x)
END EXACT SOURCE
-/

/- REVIEW BLOCK 227 — LIBRARY SEMANTICS
Declaration: Rat.floor
Source: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:314
Source span: 313:0–318:17
Original module: Init.Data.Rat.Basic
Original imports/opens:
namespace Rat
public import Init.Data.Nat.Coprime
public import Init.Data.OfScientific.Basic
public import Init.Data.Int.DivMod.Basic
public import Init.Data.String.Defs
public import Init.Data.ToString.Macro
public import Init.Data.ToString.Extra
import Init.Data.Hashable
import Init.Data.Int.DivMod.Bootstrap
import Init.Data.Int.DivMod.Lemmas
import Init.Data.Int.Lemmas
import Init.Data.Int.Order
import Init.Data.Int.Pow
import Init.Data.Nat.Dvd
BEGIN EXACT SOURCE
/-- The floor of a rational number `a` is the largest integer less than or equal to `a`. -/
protected def floor (a : Rat) : Int :=
  if a.den = 1 then
    a.num
  else
    a.num / a.den
END EXACT SOURCE
-/

/- REVIEW BLOCK 228 — LIBRARY SEMANTICS
Declaration: Int.floor
Source: .lake/packages/mathlib/Mathlib/Algebra/Order/Floor/Defs.lean:256
Source span: 255:0–257:17
Original module: Mathlib.Algebra.Order.Floor.Defs
Original imports/opens:
namespace Int
public import Mathlib.Algebra.Order.Ring.Cast
import Mathlib.Order.Int.LeastGreatest
open scoped Classical in
BEGIN EXACT SOURCE
/-- `Int.floor a` is the greatest integer `z` such that `z ≤ a`. It is denoted with `⌊a⌋`. -/
def floor : α → ℤ :=
  FloorRing.floor
END EXACT SOURCE
-/

/- PROJECT DEPENDENCY COVERAGE
Every elaborated project constant, including generated constants, appears here.
Lean1090.Spec.ACASFields -> block 023; Model/Types.lean:71
Lean1090.Spec.ACASFields.ac -> block 023; Model/Types.lean:81 [plain field accessor]
Lean1090.Spec.ACASFields.cc -> block 023; Model/Types.lean:75 [plain field accessor]
Lean1090.Spec.ACASFields.parts -> block 175; Spec/Frame.lean:57
Lean1090.Spec.ACASFields.ri -> block 023; Model/Types.lean:79 [plain field accessor]
Lean1090.Spec.ACASFields.sl -> block 023; Model/Types.lean:77 [plain field accessor]
Lean1090.Spec.ACASFields.spare1 -> block 023; Model/Types.lean:76 [plain field accessor]
Lean1090.Spec.ACASFields.spare2 -> block 023; Model/Types.lean:78 [plain field accessor]
Lean1090.Spec.ACASFields.spare3 -> block 023; Model/Types.lean:80 [plain field accessor]
Lean1090.Spec.ACASFields.vs -> block 023; Model/Types.lean:74 [plain field accessor]
Lean1090.Spec.Altitude.Representable25 -> block 015; Spec/Altitude.lean:80
Lean1090.Spec.Altitude.RepresentableGillham -> block 016; Spec/Altitude.lean:55
Lean1090.Spec.Altitude.Value -> block 022; Model/Types.lean:55
Lean1090.Spec.Altitude.Value.casesOn -> block 022; Model/Types.lean:55
Lean1090.Spec.Altitude.Value.ctorIdx -> block 022; Model/Types.lean:56 [compiler-generated; parent source]
Lean1090.Spec.Altitude.Value.feet -> block 022; Model/Types.lean:57
Lean1090.Spec.Altitude.Value.metres -> block 022; Model/Types.lean:58
Lean1090.Spec.Altitude.Value.rec -> block 022; Model/Types.lean:55
Lean1090.Spec.Altitude.bit -> block 067; Spec/Altitude.lean:19
Lean1090.Spec.Altitude.gray100 -> block 070; Spec/Altitude.lean:34
Lean1090.Spec.Altitude.gray500 -> block 069; Spec/Altitude.lean:30
Lean1090.Spec.Altitude.grayDecode -> block 068; Spec/Altitude.lean:22
Lean1090.Spec.Altitude.validGillham -> block 017; Spec/Altitude.lean:38
Lean1090.Spec.Assignment.adsbAssignment -> block 073; Spec/Assignment.lean:33
Lean1090.Spec.Assignment.adsbCompatibilityValues -> block 077; Spec/Assignment.lean:89
Lean1090.Spec.Assignment.adsbCompatibilityValues.match_1 -> block 077; Spec/Assignment.lean:94 [compiler-generated; parent source]
Lean1090.Spec.Assignment.adsbMeaning -> block 078; Spec/Assignment.lean:114
Lean1090.Spec.Assignment.adsbStandardValues -> block 076; Spec/Assignment.lean:60
Lean1090.Spec.Assignment.altitude -> block 082; Spec/Assignment.lean:168
Lean1090.Spec.Assignment.altitude._sparseCasesOn_1 -> block 082; Spec/Assignment.lean:170 [compiler-generated; parent source]
Lean1090.Spec.Assignment.altitude._sparseCasesOn_2 -> block 082; Spec/Assignment.lean:170 [compiler-generated; parent source]
Lean1090.Spec.Assignment.altitude.match_1 -> block 082; Spec/Assignment.lean:170 [compiler-generated; parent source]
Lean1090.Spec.Assignment.altitude12 -> block 089; Spec/AssignmentAltitude.lean:47
Lean1090.Spec.Assignment.altitude12._sparseCasesOn_1 -> block 089; Spec/AssignmentAltitude.lean:49 [compiler-generated; parent source]
Lean1090.Spec.Assignment.altitude12._sparseCasesOn_2 -> block 089; Spec/AssignmentAltitude.lean:49 [compiler-generated; parent source]
Lean1090.Spec.Assignment.altitude12.match_1 -> block 089; Spec/AssignmentAltitude.lean:49 [compiler-generated; parent source]
Lean1090.Spec.Assignment.altitude13 -> block 088; Spec/AssignmentAltitude.lean:37
Lean1090.Spec.Assignment.candidate -> block 074; Spec/Assignment.lean:40
Lean1090.Spec.Assignment.columnCode -> block 071; Spec/Assignment.lean:20
Lean1090.Spec.Assignment.commBAssignments -> block 075; Spec/Assignment.lean:51
Lean1090.Spec.Assignment.commBMeaning -> block 081; Spec/Assignment.lean:152
Lean1090.Spec.Assignment.compatibility12 -> block 091; Spec/AssignmentAltitude.lean:73
Lean1090.Spec.Assignment.compatibility13 -> block 090; Spec/AssignmentAltitude.lean:57
Lean1090.Spec.Assignment.compatibilityThreat -> block 079; Spec/Assignment.lean:123
Lean1090.Spec.Assignment.compatibilityThreat.match_1 -> block 079; Spec/Assignment.lean:126 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport -> block 084; Spec/Assignment.lean:189
Lean1090.Spec.Assignment.expectedReport._sparseCasesOn_1 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport._sparseCasesOn_11 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport._sparseCasesOn_14 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport._sparseCasesOn_15 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport._sparseCasesOn_8 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport.match_1 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport.match_11 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport.match_14 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport.match_4 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport.match_6 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.expectedReport.match_8 -> block 084; Spec/Assignment.lean:193 [compiler-generated; parent source]
Lean1090.Spec.Assignment.gillhamHeight -> block 087; Spec/AssignmentAltitude.lean:25
Lean1090.Spec.Assignment.grayValue -> block 086; Spec/AssignmentAltitude.lean:17
Lean1090.Spec.Assignment.orderedBits -> block 085; Spec/AssignmentAltitude.lean:12
Lean1090.Spec.Assignment.outerAltitude -> block 083; Spec/Assignment.lean:182
Lean1090.Spec.Assignment.outerAltitude._sparseCasesOn_1 -> block 083; Spec/Assignment.lean:184 [compiler-generated; parent source]
Lean1090.Spec.Assignment.outerAltitude.match_1 -> block 083; Spec/Assignment.lean:184 [compiler-generated; parent source]
Lean1090.Spec.Assignment.payloadAssignment -> block 072; Spec/Assignment.lean:27
Lean1090.Spec.Assignment.standardThreat -> block 080; Spec/Assignment.lean:138
Lean1090.Spec.Assignment.standardThreat._proof_1 -> block 080; Spec/Assignment.lean:141 [compiler-generated; parent source]
Lean1090.Spec.Assignment.standardThreat._proof_2 -> block 080; Spec/Assignment.lean:141 [compiler-generated; parent source]
Lean1090.Spec.Binary64.add -> block 097; Spec/Binary64.lean:62
Lean1090.Spec.Binary64.div -> block 100; Spec/Binary64.lean:71
Lean1090.Spec.Binary64.exponent -> block 094; Spec/Binary64.lean:37
Lean1090.Spec.Binary64.literal -> block 096; Spec/Binary64.lean:59
Lean1090.Spec.Binary64.mul -> block 099; Spec/Binary64.lean:68
Lean1090.Spec.Binary64.nearestEven -> block 093; Spec/Binary64.lean:29
Lean1090.Spec.Binary64.powerTwo -> block 092; Spec/Binary64.lean:24
Lean1090.Spec.Binary64.round -> block 095; Spec/Binary64.lean:43
Lean1090.Spec.Binary64.sub -> block 098; Spec/Binary64.lean:65
Lean1090.Spec.CPR.AvoidsDecodableLatitudes -> block 014; Spec/CPRFormula.lean:109
Lean1090.Spec.CPR.CertifiesTransition -> block 013; Spec/CPRFormula.lean:104
Lean1090.Spec.CPR.CertifiesTransition._proof_1 -> block 013; Spec/CPRFormula.lean:105 [compiler-generated; parent source]
Lean1090.Spec.CPR.DecodableLatitude -> block 118; Spec/CPRFormula.lean:28
Lean1090.Spec.CPR.GlobalAdmissible -> block 007; Spec/CPRContracts.lean:40
Lean1090.Spec.CPR.LocalAdmissible -> block 006; Spec/CPRContracts.lean:19
Lean1090.Spec.CPR.Medium -> block 040; Model/Types.lean:257
Lean1090.Spec.CPR.Medium.airborne -> block 040; Model/Types.lean:259
Lean1090.Spec.CPR.Medium.casesOn -> block 040; Model/Types.lean:257
Lean1090.Spec.CPR.Medium.rec -> block 040; Model/Types.lean:257
Lean1090.Spec.CPR.Medium.surface -> block 040; Model/Types.lean:260
Lean1090.Spec.CPR.NLCertificate -> block 119; Spec/CPRFormula.lean:34
Lean1090.Spec.CPR.NLCertificate.lower12 -> block 119; Spec/CPRFormula.lean:38 [plain field accessor]
Lean1090.Spec.CPR.NLCertificate.upper12 -> block 119; Spec/CPRFormula.lean:39 [plain field accessor]
Lean1090.Spec.CPR.NLCertificate.zone -> block 119; Spec/CPRFormula.lean:37 [plain field accessor]
Lean1090.Spec.CPR.Position -> block 041; Model/Types.lean:263
Lean1090.Spec.CPR.Position.lat -> block 041; Model/Types.lean:265 [plain field accessor]
Lean1090.Spec.CPR.Position.lon -> block 041; Model/Types.lean:266 [plain field accessor]
Lean1090.Spec.CPR.ValidPosition -> block 114; Spec/CPR.lean:98
Lean1090.Spec.CPR.WithinResolution -> block 008; Spec/CPRContracts.lean:33
Lean1090.Spec.CPR.absQ -> block 105; Spec/CPR.lean:29
Lean1090.Spec.CPR.dLat -> block 110; Spec/CPR.lean:67
Lean1090.Spec.CPR.dLon -> block 112; Spec/CPR.lean:73
Lean1090.Spec.CPR.longitudeDistance -> block 116; Spec/CPRContracts.lean:16
Lean1090.Spec.CPR.modQ -> block 106; Spec/CPR.lean:32
Lean1090.Spec.CPR.nlFormula -> block 012; Spec/CPRFormula.lean:11
Lean1090.Spec.CPR.nlFormula._proof_1 -> block 012; Spec/CPRFormula.lean:13 [compiler-generated; parent source]
Lean1090.Spec.CPR.nlFormula._proof_2 -> block 012; Spec/CPRFormula.lean:13 [compiler-generated; parent source]
Lean1090.Spec.CPR.nlFormula._proof_3 -> block 012; Spec/CPRFormula.lean:13 [compiler-generated; parent source]
Lean1090.Spec.CPR.nlFormula._proof_4 -> block 012; Spec/CPRFormula.lean:13 [compiler-generated; parent source]
Lean1090.Spec.CPR.nlTable -> block 109; Spec/CPR.lean:56
Lean1090.Spec.CPR.normalizeLongitude -> block 107; Spec/CPR.lean:35
Lean1090.Spec.CPR.parity -> block 103; Spec/CPR.lean:23
Lean1090.Spec.CPR.roundedLatitude -> block 113; Spec/CPR.lean:77
Lean1090.Spec.CPR.roundedLongitude -> block 115; Spec/CPRContracts.lean:10
Lean1090.Spec.CPR.scale -> block 102; Spec/CPR.lean:20
Lean1090.Spec.CPR.span -> block 104; Spec/CPR.lean:26
Lean1090.Spec.CPR.span.match_1 -> block 104; Spec/CPR.lean:27 [compiler-generated; parent source]
Lean1090.Spec.CPR.transitionFormula -> block 117; Spec/CPRFormula.lean:22
Lean1090.Spec.CPR.transitions -> block 108; Spec/CPR.lean:38
Lean1090.Spec.CPR.zones -> block 111; Spec/CPR.lean:70
Lean1090.Spec.CommBThreat -> block 031; Model/Types.lean:159
Lean1090.Spec.CommBThreat.address -> block 031; Model/Types.lean:164
Lean1090.Spec.CommBThreat.none -> block 031; Model/Types.lean:163
Lean1090.Spec.CommBThreat.orientation -> block 031; Model/Types.lean:165
Lean1090.Spec.CommBThreat.unassigned -> block 031; Model/Types.lean:166
Lean1090.Spec.Frame -> block 026; Model/Types.lean:108
Lean1090.Spec.Frame.body -> block 026; Model/Types.lean:112 [plain field accessor]
Lean1090.Spec.Frame.parity -> block 026; Model/Types.lean:113 [plain field accessor]
Lean1090.Spec.FrameBody -> block 025; Model/Types.lean:93
Lean1090.Spec.FrameBody.allCall -> block 025; Model/Types.lean:99
Lean1090.Spec.FrameBody.casesOn -> block 025; Model/Types.lean:93
Lean1090.Spec.FrameBody.commB -> block 025; Model/Types.lean:104
Lean1090.Spec.FrameBody.commD -> block 025; Model/Types.lean:105
Lean1090.Spec.FrameBody.ctorIdx -> block 025; Model/Types.lean:96 [compiler-generated; parent source]
Lean1090.Spec.FrameBody.extended -> block 025; Model/Types.lean:101
Lean1090.Spec.FrameBody.informationBits -> block 178; Spec/Frame.lean:80
Lean1090.Spec.FrameBody.informationBits._sparseCasesOn_1 -> block 178; Spec/Frame.lean:81 [compiler-generated; parent source]
Lean1090.Spec.FrameBody.informationBits.match_1 -> block 178; Spec/Frame.lean:81 [compiler-generated; parent source]
Lean1090.Spec.FrameBody.longACAS -> block 025; Model/Types.lean:100
Lean1090.Spec.FrameBody.military -> block 025; Model/Types.lean:103
Lean1090.Spec.FrameBody.parts -> block 177; Spec/Frame.lean:66
Lean1090.Spec.FrameBody.parts.match_1 -> block 177; Spec/Frame.lean:68 [compiler-generated; parent source]
Lean1090.Spec.FrameBody.rec -> block 025; Model/Types.lean:93
Lean1090.Spec.FrameBody.shortACAS -> block 025; Model/Types.lean:97
Lean1090.Spec.FrameBody.surveillance -> block 025; Model/Types.lean:98
Lean1090.Spec.Message -> block 039; Model/Types.lean:246
Lean1090.Spec.Message.mk -> block 039; Model/Types.lean:248
Lean1090.Spec.Parity.checksum -> block 185; Spec/Parity.lean:31
Lean1090.Spec.Parity.generator -> block 182; Spec/Parity.lean:16
Lean1090.Spec.Parity.generatorPolynomial -> block 186; Spec/Parity.lean:41
Lean1090.Spec.Parity.interrogator -> block 187; Spec/Parity.lean:61
Lean1090.Spec.Parity.polynomial -> block 010; Spec/Parity.lean:35
Lean1090.Spec.Parity.polynomialRemainder -> block 011; Spec/Parity.lean:47
Lean1090.Spec.Parity.step -> block 183; Spec/Parity.lean:19
Lean1090.Spec.Parity.syndrome -> block 184; Spec/Parity.lean:25
Lean1090.Spec.PayloadCoding -> block 018; Model/Types.lean:14
Lean1090.Spec.PayloadCoding.casesOn -> block 018; Model/Types.lean:14
Lean1090.Spec.PayloadCoding.ctorIdx -> block 018; Model/Types.lean:15 [compiler-generated; parent source]
Lean1090.Spec.PayloadCoding.ofNat -> block 018; Model/Types.lean:15 [compiler-generated; parent source]
Lean1090.Spec.PayloadCoding.ofNat_ctorIdx -> block 018; Model/Types.lean:15 [compiler-generated; parent source]
Lean1090.Spec.PayloadCoding.rec -> block 018; Model/Types.lean:14
Lean1090.Spec.PayloadCoding.twosComplement -> block 018; Model/Types.lean:16
Lean1090.Spec.PayloadCoding.unsigned -> block 018; Model/Types.lean:16
Lean1090.Spec.PayloadColumn -> block 019; Model/Types.lean:19
Lean1090.Spec.PayloadColumn.coding -> block 019; Model/Types.lean:25 [plain field accessor]
Lean1090.Spec.PayloadColumn.mk -> block 019; Model/Types.lean:21
Lean1090.Spec.PayloadColumn.name -> block 019; Model/Types.lean:22 [plain field accessor]
Lean1090.Spec.PayloadColumn.offset -> block 019; Model/Types.lean:27 [plain field accessor]
Lean1090.Spec.PayloadColumn.scale -> block 019; Model/Types.lean:26 [plain field accessor]
Lean1090.Spec.PayloadColumn.start -> block 019; Model/Types.lean:23 [plain field accessor]
Lean1090.Spec.PayloadColumn.status -> block 019; Model/Types.lean:28 [plain field accessor]
Lean1090.Spec.PayloadColumn.width -> block 019; Model/Types.lean:24 [plain field accessor]
Lean1090.Spec.PayloadField -> block 020; Model/Types.lean:31
Lean1090.Spec.PayloadField.code -> block 020; Model/Types.lean:35 [plain field accessor]
Lean1090.Spec.PayloadField.mk -> block 020; Model/Types.lean:33
Lean1090.Spec.PayloadField.name -> block 020; Model/Types.lean:34 [plain field accessor]
Lean1090.Spec.PayloadRecord -> block 021; Model/Types.lean:38
Lean1090.Spec.PayloadRecord.fields -> block 021; Model/Types.lean:42 [plain field accessor]
Lean1090.Spec.PayloadRecord.kind -> block 021; Model/Types.lean:41 [plain field accessor]
Lean1090.Spec.PayloadRecord.mk -> block 021; Model/Types.lean:40
Lean1090.Spec.Presentation.FloatExpr -> block 028; Model/Types.lean:125
Lean1090.Spec.Presentation.FloatExpr.abs64 -> block 028; Model/Types.lean:136
Lean1090.Spec.Presentation.FloatExpr.add -> block 028; Model/Types.lean:132
Lean1090.Spec.Presentation.FloatExpr.addIfNegative64 -> block 028; Model/Types.lean:139
Lean1090.Spec.Presentation.FloatExpr.atan2_64 -> block 028; Model/Types.lean:138
Lean1090.Spec.Presentation.FloatExpr.div -> block 028; Model/Types.lean:135
Lean1090.Spec.Presentation.FloatExpr.hypot64 -> block 028; Model/Types.lean:137
Lean1090.Spec.Presentation.FloatExpr.literal -> block 028; Model/Types.lean:131
Lean1090.Spec.Presentation.FloatExpr.mul -> block 028; Model/Types.lean:134
Lean1090.Spec.Presentation.FloatExpr.sub -> block 028; Model/Types.lean:133
Lean1090.Spec.Presentation.Missing -> block 029; Model/Types.lean:142
Lean1090.Spec.Presentation.Missing.null -> block 029; Model/Types.lean:144
Lean1090.Spec.Presentation.Missing.omit -> block 029; Model/Types.lean:144
Lean1090.Spec.Presentation.NumericField -> block 030; Model/Types.lean:147
Lean1090.Spec.Presentation.NumericField.key -> block 030; Model/Types.lean:150 [plain field accessor]
Lean1090.Spec.Presentation.NumericField.missing -> block 030; Model/Types.lean:152 [plain field accessor]
Lean1090.Spec.Presentation.NumericField.mk -> block 030; Model/Types.lean:149
Lean1090.Spec.Presentation.Precision -> block 027; Model/Types.lean:120
Lean1090.Spec.Presentation.Precision.binary32 -> block 027; Model/Types.lean:122
Lean1090.Spec.Presentation.Precision.binary64 -> block 027; Model/Types.lean:122
Lean1090.Spec.Presentation.oracleADSBFloats -> block 203; Spec/Presentation.lean:79
Lean1090.Spec.Presentation.oracleADSBFloats.match_1 -> block 203; Spec/Presentation.lean:82 [compiler-generated; parent source]
Lean1090.Spec.Presentation.oracleCommBFloats -> block 207; Spec/Presentation.lean:127
Lean1090.Spec.Presentation.oracleCommBFloats.match_1 -> block 207; Spec/Presentation.lean:132 [compiler-generated; parent source]
Lean1090.Spec.Presentation.oracleMeteoTemperature -> block 206; Spec/Presentation.lean:119
Lean1090.Spec.Presentation.oraclePi -> block 195; Spec/Presentation.lean:30
Lean1090.Spec.Presentation.oracleVerticalSource -> block 200; Spec/Presentation.lean:62
Lean1090.Spec.Presentation.scaled -> block 194; Spec/Presentation.lean:26
Lean1090.Spec.Presentation.signedCode -> block 205; Spec/Presentation.lean:113
Lean1090.Spec.Presentation.standardGNSSHeightMetres -> block 202; Spec/Presentation.lean:73
Lean1090.Spec.Presentation.standardGeoMinusBaro -> block 201; Spec/Presentation.lean:66
Lean1090.Spec.Presentation.standardVelocityComponents -> block 198; Spec/Presentation.lean:46
Lean1090.Spec.Presentation.standardVerticalSource -> block 199; Spec/Presentation.lean:58
Lean1090.Spec.Presentation.statusValue -> block 204; Spec/Presentation.lean:108
Lean1090.Spec.Presentation.velocitySpeed -> block 196; Spec/Presentation.lean:33
Lean1090.Spec.Presentation.velocityTrack -> block 197; Spec/Presentation.lean:38
Lean1090.Spec.Report -> block 038; Model/Types.lean:229
Lean1090.Spec.Report.mk -> block 038; Model/Types.lean:234
Lean1090.Spec.Semantics.Labels -> block 036; Model/Types.lean:208
Lean1090.Spec.Semantics.Payload -> block 037; Model/Types.lean:211
Lean1090.Spec.Semantics.Payload.mk -> block 037; Model/Types.lean:213
Lean1090.Spec.Semantics.Values -> block 035; Model/Types.lean:204
Lean1090.Spec.Semantics.adsbLabels -> block 211; Spec/Semantics.lean:107
Lean1090.Spec.Semantics.adsbStandardFloats -> block 212; Spec/Semantics.lean:127
Lean1090.Spec.Semantics.airline -> block 213; Spec/Semantics.lean:146
Lean1090.Spec.Semantics.commBLabels -> block 215; Spec/Semantics.lean:158
Lean1090.Spec.Semantics.commBStandardFloats -> block 216; Spec/Semantics.lean:176
Lean1090.Spec.Semantics.emergency -> block 210; Spec/Semantics.lean:43
Lean1090.Spec.Semantics.hazard -> block 214; Spec/Semantics.lean:153
Lean1090.Spec.Semantics.tableValues -> block 208; Spec/Semantics.lean:23
Lean1090.Spec.Semantics.wakeVortex -> block 209; Spec/Semantics.lean:28
Lean1090.Spec.StandardCommBThreat -> block 034; Model/Types.lean:188
Lean1090.Spec.StandardCommBThreat.address -> block 034; Model/Types.lean:193
Lean1090.Spec.StandardCommBThreat.none -> block 034; Model/Types.lean:192
Lean1090.Spec.StandardCommBThreat.orientation -> block 034; Model/Types.lean:194
Lean1090.Spec.StandardCommBThreat.unassigned -> block 034; Model/Types.lean:196
Lean1090.Spec.StandardThreatBearing -> block 033; Model/Types.lean:179
Lean1090.Spec.StandardThreatBearing.sector -> block 033; Model/Types.lean:184
Lean1090.Spec.StandardThreatBearing.unassigned -> block 033; Model/Types.lean:185
Lean1090.Spec.StandardThreatBearing.unavailable -> block 033; Model/Types.lean:183
Lean1090.Spec.StandardThreatRange -> block 032; Model/Types.lean:169
Lean1090.Spec.StandardThreatRange.estimate -> block 032; Model/Types.lean:175
Lean1090.Spec.StandardThreatRange.greaterThan -> block 032; Model/Types.lean:176
Lean1090.Spec.StandardThreatRange.lessThan -> block 032; Model/Types.lean:174
Lean1090.Spec.StandardThreatRange.unavailable -> block 032; Model/Types.lean:173
Lean1090.Spec.SurveillanceFields -> block 024; Model/Types.lean:84
Lean1090.Spec.SurveillanceFields.code -> block 024; Model/Types.lean:90 [plain field accessor]
Lean1090.Spec.SurveillanceFields.dr -> block 024; Model/Types.lean:88 [plain field accessor]
Lean1090.Spec.SurveillanceFields.fs -> block 024; Model/Types.lean:87 [plain field accessor]
Lean1090.Spec.SurveillanceFields.parts -> block 176; Spec/Frame.lean:62
Lean1090.Spec.SurveillanceFields.um -> block 024; Model/Types.lean:89 [plain field accessor]
Lean1090.Spec.Valid -> block 001; Spec/Message.lean:111
Lean1090.Spec.ValidADSB -> block 002; Spec/ADSB.lean:217
Lean1090.Spec.ValidADSBFields -> block 003; Spec/ADSB.lean:313
Lean1090.Spec.ValidBDS -> block 004; Spec/CommB.lean:298
Lean1090.Spec.ValidBDS.match_1 -> block 004; Spec/CommB.lean:301 [compiler-generated; parent source]
Lean1090.Spec.ValidBDSFields -> block 005; Spec/CommB.lean:337
Lean1090.Spec.ValidPayloadFields -> block 189; Spec/PayloadBits.lean:11
Lean1090.Spec.ValidPayloadFields._f -> block 189; Spec/PayloadBits.lean:13 [compiler-generated; parent source]
Lean1090.Spec.ValidPayloadFields._sparseCasesOn_1 -> block 189; Spec/PayloadBits.lean:13 [compiler-generated; parent source]
Lean1090.Spec.ValidPayloadFields._sparseCasesOn_2 -> block 189; Spec/PayloadBits.lean:13 [compiler-generated; parent source]
Lean1090.Spec.ValidPayloadFields.match_1 -> block 189; Spec/PayloadBits.lean:13 [compiler-generated; parent source]
Lean1090.Spec.adsbAirspeed -> block 062; Spec/ADSB.lean:271
Lean1090.Spec.adsbAssignmentKind -> block 055; Spec/ADSB.lean:208
Lean1090.Spec.adsbBarometricSetting -> block 065; Spec/ADSB.lean:292
Lean1090.Spec.adsbCallsign -> block 057; Spec/ADSB.lean:237
Lean1090.Spec.adsbCharacter -> block 056; Spec/ADSB.lean:230
Lean1090.Spec.adsbGeoMinusBaro -> block 061; Spec/ADSB.lean:265
Lean1090.Spec.adsbHardValid -> block 054; Spec/ADSB.lean:181
Lean1090.Spec.adsbIdentificationLayout -> block 042; Spec/ADSB.lean:22
Lean1090.Spec.adsbKind -> block 050; Spec/ADSB.lean:126
Lean1090.Spec.adsbLayout -> block 052; Spec/ADSB.lean:156
Lean1090.Spec.adsbLayoutOfKind -> block 051; Spec/ADSB.lean:134
Lean1090.Spec.adsbMovement -> block 058; Spec/ADSB.lean:243
Lean1090.Spec.adsbNUCp -> block 066; Spec/ADSB.lean:298
Lean1090.Spec.adsbOperationPrefix -> block 048; Spec/ADSB.lean:86
Lean1090.Spec.adsbOperationSuffix -> block 049; Spec/ADSB.lean:110
Lean1090.Spec.adsbOracleVelocityComponents -> block 063; Spec/ADSB.lean:277
Lean1090.Spec.adsbPositionLayout -> block 043; Spec/ADSB.lean:27
Lean1090.Spec.adsbSelectedAltitude -> block 064; Spec/ADSB.lean:286
Lean1090.Spec.adsbSigned -> block 059; Spec/ADSB.lean:256
Lean1090.Spec.adsbStatusLayout -> block 046; Spec/ADSB.lean:60
Lean1090.Spec.adsbSurfaceLayout -> block 044; Spec/ADSB.lean:34
Lean1090.Spec.adsbTargetLayout -> block 047; Spec/ADSB.lean:68
Lean1090.Spec.adsbVelocityLayout -> block 045; Spec/ADSB.lean:42
Lean1090.Spec.adsbVerticalRate -> block 060; Spec/ADSB.lean:260
Lean1090.Spec.altitudeCodeAdmissible -> block 053; Spec/ADSB.lean:164
Lean1090.Spec.assigned -> block 009; Spec/Message.lean:140
Lean1090.Spec.bds10Layout -> block 162; Spec/CommBLayouts.lean:11
Lean1090.Spec.bds17Layout -> block 163; Spec/CommBLayouts.lean:32
Lean1090.Spec.bds18Layout -> block 164; Spec/CommBLayouts.lean:61
Lean1090.Spec.bds19Layout -> block 165; Spec/CommBLayouts.lean:120
Lean1090.Spec.bds20Layout -> block 166; Spec/CommBLayouts.lean:179
Lean1090.Spec.bds21Layout -> block 167; Spec/CommBLayouts.lean:191
Lean1090.Spec.bds30Layout -> block 168; Spec/CommBLayouts.lean:205
Lean1090.Spec.bds40Layout -> block 169; Spec/CommBLayouts.lean:225
Lean1090.Spec.bds44Layout -> block 170; Spec/CommBLayouts.lean:242
Lean1090.Spec.bds45Layout -> block 171; Spec/CommBLayouts.lean:256
Lean1090.Spec.bds50Layout -> block 172; Spec/CommBLayouts.lean:276
Lean1090.Spec.bds60Layout -> block 173; Spec/CommBLayouts.lean:289
Lean1090.Spec.bdsAssignmentLayout -> block 147; Spec/CommB.lean:273
Lean1090.Spec.bdsFieldDiscriminants -> block 149; Spec/CommB.lean:325
Lean1090.Spec.bdsLayout -> block 146; Spec/CommB.lean:265
Lean1090.Spec.bdsStructuralValid.match_1 -> block 148; Spec/CommB.lean:316 [compiler-generated; parent source]
Lean1090.Spec.bdsWireValid -> block 145; Spec/CommB.lean:242
Lean1090.Spec.bdsWireValid.match_1 -> block 145; Spec/CommB.lean:245 [compiler-generated; parent source]
Lean1090.Spec.cbCallsign -> block 130; Spec/CommB.lean:92
Lean1090.Spec.cbCharacter -> block 129; Spec/CommB.lean:85
Lean1090.Spec.cbColumn -> block 161; Spec/CommBLayouts.lean:5
Lean1090.Spec.cbCombinedScore -> block 156; Spec/CommB.lean:436
Lean1090.Spec.cbDashPlaceholder -> block 133; Spec/CommB.lean:152
Lean1090.Spec.cbDensity -> block 154; Spec/CommB.lean:404
Lean1090.Spec.cbDensityTerms -> block 153; Spec/CommB.lean:375
Lean1090.Spec.cbDensityTerms.match_1 -> block 153; Spec/CommB.lean:377 [compiler-generated; parent source]
Lean1090.Spec.cbGaussian -> block 150; Spec/CommB.lean:360
Lean1090.Spec.cbLaplace -> block 151; Spec/CommB.lean:366
Lean1090.Spec.cbMach64 -> block 126; Spec/CommB.lean:53
Lean1090.Spec.cbPenalty -> block 155; Spec/CommB.lean:411
Lean1090.Spec.cbPenalty._sparseCasesOn_1 -> block 155; Spec/CommB.lean:413 [compiler-generated; parent source]
Lean1090.Spec.cbPenalty.match_1 -> block 155; Spec/CommB.lean:413 [compiler-generated; parent source]
Lean1090.Spec.cbPenalty.match_4 -> block 155; Spec/CommB.lean:413 [compiler-generated; parent source]
Lean1090.Spec.cbQNH64 -> block 125; Spec/CommB.lean:48
Lean1090.Spec.cbRegistration -> block 135; Spec/CommB.lean:160
Lean1090.Spec.cbRegistrationCodes -> block 134; Spec/CommB.lean:155
Lean1090.Spec.cbScoreField -> block 152; Spec/CommB.lean:371
Lean1090.Spec.cbScoreField.match_1 -> block 152; Spec/CommB.lean:372 [compiler-generated; parent source]
Lean1090.Spec.cbScorePasses -> block 157; Spec/CommB.lean:441
Lean1090.Spec.cbSelected -> block 122; Spec/CommB.lean:32
Lean1090.Spec.cbSigned -> block 121; Spec/CommB.lean:28
Lean1090.Spec.cbStatus -> block 120; Spec/CommB.lean:23
Lean1090.Spec.cbTemperature44 -> block 123; Spec/CommB.lean:36
Lean1090.Spec.cbValid17 -> block 136; Spec/CommB.lean:166
Lean1090.Spec.cbValid18 -> block 137; Spec/CommB.lean:172
Lean1090.Spec.cbValid19 -> block 138; Spec/CommB.lean:180
Lean1090.Spec.cbValid21 -> block 139; Spec/CommB.lean:185
Lean1090.Spec.cbValid40 -> block 140; Spec/CommB.lean:195
Lean1090.Spec.cbValid44 -> block 141; Spec/CommB.lean:205
Lean1090.Spec.cbValid45 -> block 142; Spec/CommB.lean:213
Lean1090.Spec.cbValid50 -> block 143; Spec/CommB.lean:222
Lean1090.Spec.cbValid60 -> block 144; Spec/CommB.lean:233
Lean1090.Spec.cbVertical60 -> block 124; Spec/CommB.lean:42
Lean1090.Spec.cbWrapAngle -> block 127; Spec/CommB.lean:59
Lean1090.Spec.commBCoreEligible -> block 159; Spec/CommB.lean:451
Lean1090.Spec.commBCoreRegisters -> block 158; Spec/CommB.lean:446
Lean1090.Spec.commBLayout -> block 174; Spec/CommBLayouts.lean:302
Lean1090.Spec.commBLayout.match_1 -> block 174; Spec/CommBLayouts.lean:304 [compiler-generated; parent source]
Lean1090.Spec.commBRegisters -> block 160; Spec/CommB.lean:490
Lean1090.Spec.commBValue -> block 128; Spec/CommB.lean:62
Lean1090.Spec.commBValue.match_1 -> block 128; Spec/CommB.lean:68 [compiler-generated; parent source]
Lean1090.Spec.encodePayloadFields -> block 190; Spec/PayloadBits.lean:35
Lean1090.Spec.encodePayloadFields._f -> block 190; Spec/PayloadBits.lean:37 [compiler-generated; parent source]
Lean1090.Spec.encodePayloadFields.match_1 -> block 190; Spec/PayloadBits.lean:37 [compiler-generated; parent source]
Lean1090.Spec.frameAccepted -> block 181; Spec/Message.lean:28
Lean1090.Spec.frameAccepted._sparseCasesOn_1 -> block 181; Spec/Message.lean:31 [compiler-generated; parent source]
Lean1090.Spec.frameAccepted.match_1 -> block 181; Spec/Message.lean:31 [compiler-generated; parent source]
Lean1090.Spec.frameSyndrome -> block 180; Spec/Message.lean:23
Lean1090.Spec.identityCode -> block 179; Spec/Frame.lean:92
Lean1090.Spec.instDecidableEqPayloadCoding -> block 018; Model/Types.lean:17
Lean1090.Spec.instDecidableEqPayloadCoding._proof_1 -> block 018; Model/Types.lean:15 [compiler-generated; parent source]
Lean1090.Spec.instDecidableEqPayloadCoding._proof_2 -> block 018; Model/Types.lean:15 [compiler-generated; parent source]
Lean1090.Spec.packFields -> block 101; Spec/Bits.lean:27
Lean1090.Spec.packFields.match_1 -> block 101; Spec/Bits.lean:28 [compiler-generated; parent source]
Lean1090.Spec.payloadBits -> block 188; Spec/PayloadBits.lean:7
Lean1090.Spec.payloadField -> block 193; Spec/PayloadBits.lean:53
Lean1090.Spec.payloadInteger -> block 191; Spec/PayloadBits.lean:41
Lean1090.Spec.payloadValue -> block 192; Spec/PayloadBits.lean:46
Lean1090.Spec.standardThreatBearing -> block 132; Spec/CommB.lean:122
Lean1090.Spec.standardThreatRange -> block 131; Spec/CommB.lean:113
-/

/- LIBRARY BOUNDARY
AddGroupWithOne.toAddMonoidWithOne: .lake/packages/mathlib/Mathlib/Data/Int/Cast/Defs.lean:41 [plain field accessor]
AddMonoidWithOne.toOne: .lake/packages/mathlib/Mathlib/Data/Nat/Cast/Defs.lean:65 [plain field accessor]
And: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:645
Applicative.toPure: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:4015 [plain field accessor]
BEq.beq: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1296 [plain field accessor]
Bind.bind: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3881 [plain field accessor]
BitVec: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2496
BitVec.instOfNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/BitVec/BasicAux.lean:25
BitVec.instXorOp: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/BitVec/Basic.lean:558
BitVec.ofNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2533
BitVec.toNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2540
Bool: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:99
Bool.and: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1061
Bool.ctorIdx: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean (generated declaration)
Bool.false: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:108
Bool.not: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1079
Bool.or: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1043
Bool.rec: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:99
Bool.true: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:110
Char: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2981
Char.ofNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3009
CommRing.toCommSemiring: .lake/packages/mathlib/Mathlib/Algebra/Ring/Defs.lean:417
CommRing.toRing: .lake/packages/mathlib/Mathlib/Algebra/Ring/Defs.lean:413 [plain field accessor]
CommSemiring.toSemiring: .lake/packages/mathlib/Mathlib/Algebra/Ring/Defs.lean:228 [plain field accessor]
DFunLike.coe: .lake/packages/mathlib/Mathlib/Basic/FunLike/Basic.lean:147 [plain field accessor]
Decidable: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1130
Decidable.decide: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1158 [plain field accessor]
Decidable.isFalse: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1167
Decidable.isTrue: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1170
DecidableEq: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1200
DivInvMonoid.toDiv: .lake/packages/mathlib/Mathlib/Algebra/Group/DivInvMonoid.lean:145 [plain field accessor]
Eq: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:46
Eq.mp: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Core.lean:846
Eq.ndrec: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:46
Eq.ndrec_symm: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:46
Eq.refl: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:74
Exists: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Core.lean:313
False: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:274
Fin: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2441
Fin.ofNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Fin/Basic.lean:48
Fin.val: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2456 [plain field accessor]
GE.ge: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1409
GT.gt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1411
HAdd.hAdd: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1481 [plain field accessor]
HAppend.hAppend: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1564 [plain field accessor]
HDiv.hDiv: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1518 [plain field accessor]
HMod.hMod: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1529 [plain field accessor]
HMul.hMul: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1500 [plain field accessor]
HOr.hOr: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1606 [plain field accessor]
HPow.hPow: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1538 [plain field accessor]
HSub.hSub: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1491 [plain field accessor]
HXor.hXor: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1600 [plain field accessor]
Int: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:35
Int.cast: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:457
Int.decLe: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:290
Int.decLt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:303
Int.floor: .lake/packages/mathlib/Mathlib/Algebra/Order/Floor/Defs.lean:255
Int.instAdd: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:170
Int.instDecidableEq: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:267
Int.instLEInt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:230
Int.instLTInt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:240
Int.instMax: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:417
Int.instMod: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/DivMod/Basic.lean:113
Int.instMul: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:193
Int.instNegInt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:133
Int.instSub: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:211
Int.natAbs: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:317
Int.toNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:358
LE.le: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1402 [plain field accessor]
LT.lt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1407 [plain field accessor]
LinearMap: .lake/packages/mathlib/Mathlib/Algebra/Module/LinearMap/Defs.lean:78
LinearMap.instFunLike: .lake/packages/mathlib/Mathlib/Algebra/Module/LinearMap/Defs.lean:187
List: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3096
List.all: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:1907
List.below: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3096
List.brecOn: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3096
List.casesOn: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3096
List.cons: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3111
List.contains: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:798
List.ctorIdx: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean (generated declaration)
List.filter: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:473
List.filterMap: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:493
List.find?: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:1598
List.foldl: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3243
List.getD: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/BasicAux.lean:31
List.instAppend: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:605
List.isEmpty: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:754
List.length: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3182
List.map: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3301
List.nil: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3109
List.range: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:2084
List.rec: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3096
List.takeWhile: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/List/Basic.lean:970
Max.max: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1424 [plain field accessor]
Monad.toApplicative: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:4034 [plain field accessor]
Monad.toBind: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:4034 [plain field accessor]
Monoid.toNPow: .lake/packages/mathlib/Mathlib/Algebra/Group/Monoid.lean:388 [plain field accessor]
MulZeroClass.toZero: .lake/packages/mathlib/Mathlib/Algebra/GroupWithZero/Defs.lean:38 [plain field accessor]
NPow.toPow: .lake/packages/mathlib/Mathlib/Algebra/Group/Monoid.lean:369
Nat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1349
Nat.AtLeastTwo: .lake/packages/mathlib/Mathlib/Data/Nat/Init.lean:407
Nat.ble: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1998
Nat.cast: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Cast.lean:69
Nat.decLe: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2196
Nat.decLt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2214
Nat.hasNotBit: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Bitwise/Basic.lean:151
Nat.instAtLeastTwoHAddOfNat: .lake/packages/mathlib/Mathlib/Data/Nat/Init.lean:423
Nat.instDiv: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2320
Nat.instMax: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Basic.lean:876
Nat.instMod: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2408
Nat.instMonoid: .lake/packages/mathlib/Mathlib/Algebra/Group/Nat/Defs.lean:73
Nat.instNeZeroSucc: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Basic.lean:745
Nat.instOrOp: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Bitwise/Basic.lean:100
Nat.instXorOp: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Bitwise/Basic.lean:101
Nat.land: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Bitwise/Basic.lean:44
Nat.log2: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Log2.lean:27
Nat.ne_of_beq_eq_false: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1953
Nat.shiftRight: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Bitwise/Basic.lean:83
Nat.testBit: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Nat/Bitwise/Basic.lean:144
NeZero: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/NeZero.lean:28
Neg.neg: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1657 [plain field accessor]
Not: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:301
OfNat.ofNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1393 [plain field accessor]
One.toOfNat1: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Zero.lean:27
Option: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3047
Option.casesOn: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3047
Option.ctorIdx: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean (generated declaration)
Option.elim: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Option/Basic.lean:365
Option.filter: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Option/Basic.lean:185
Option.getD: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3067
Option.instBEq: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Option/Basic.lean:52
Option.instDecidableEq: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Option/Basic.lean:18
Option.isSome: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Option/Basic.lean:68
Option.map: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3082
Option.none: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3055
Option.rec: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3047
Option.some: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3057
Or: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:661
PProd: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:622
Polynomial: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Basic.lean:63
Polynomial.divModByMonicAux: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Div.lean:120
Polynomial.div_wf_lemma: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Div.lean:107
Polynomial.instAdd: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Basic.lean:116
Polynomial.instZero: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Basic.lean:110
Polynomial.modByMonic: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Div.lean:137
Polynomial.module: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Basic.lean:282
Polynomial.monomial: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Basic.lean:374
Polynomial.semiring: .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Basic.lean:266
Prod: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:603
Prod.casesOn: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:603
Prod.fst: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:616 [plain field accessor]
Prod.mk: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:614
Prod.snd: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:618 [plain field accessor]
Pure.pure: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3899 [plain field accessor]
Rat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:27
Rat.abs: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:327
Rat.den: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:40 [plain field accessor]
Rat.floor: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:313
Rat.instAdd: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:275
Rat.instDecidableLe: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:160
Rat.instDecidableLt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:155
Rat.instDiv: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:223
Rat.instIntCast: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:115
Rat.instLE: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:158
Rat.instLT: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:153
Rat.instMul: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:185
Rat.instNatCast: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:113
Rat.instNeg: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:282
Rat.instOfNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:117
Rat.instSub: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:311
Rat.num: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:38 [plain field accessor]
Real: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:33
Real.arccos: .lake/packages/mathlib/Mathlib/Analysis/SpecialFunctions/Trigonometric/Inverse.lean:274
Real.arcsin: .lake/packages/mathlib/Mathlib/Analysis/SpecialFunctions/Trigonometric/Inverse.lean:33
Real.cos: .lake/packages/mathlib/Mathlib/Analysis/Complex/Trigonometric.lean:77
Real.decidableEq: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:505
Real.decidableLT: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:501
Real.instAddGroup: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:226
Real.instDivInvMonoid: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:476
Real.instFloorRing: .lake/packages/mathlib/Mathlib/Algebra/Order/Archimedean/Real/Basic.lean:37
Real.instLT: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:265
Real.instMonoid: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:242
Real.instMul: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:105
Real.instNatCast: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:161
Real.instOne: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:93
Real.instRing: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:214
Real.instSub: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:109
Real.instZero: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:89
Real.lattice: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:454
Real.linearOrder: .lake/packages/mathlib/Mathlib/Basic/Real/Basic.lean:471
Real.pi: .lake/packages/mathlib/Mathlib/Analysis/SpecialFunctions/Trigonometric/Basic.lean:122
Real.sqrt: .lake/packages/mathlib/Mathlib/Analysis/Real/Sqrt.lean:108
Ring.toAddGroupWithOne: .lake/packages/mathlib/Mathlib/Algebra/Ring/Defs.lean:146
RingHom.id: .lake/packages/mathlib/Mathlib/Algebra/Ring/Hom/Defs.lean:546
Semiring.toAddCommMonoid: .lake/packages/mathlib/Mathlib/Algebra/Ring/Defs.lean:141 [plain field accessor]
Semiring.toModule: .lake/packages/mathlib/Mathlib/Algebra/Module/Defs.lean:167
Semiring.toNonAssocSemiring: .lake/packages/mathlib/Mathlib/Algebra/Ring/Defs.lean:141
String: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3673
String.ofList: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3692
ToString.toString: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/ToString/Basic.lean:26 [plain field accessor]
True: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:264
Unit: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:214
Unit.unit: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:226
ZMod: .lake/packages/mathlib/Mathlib/Data/ZMod/Defs.lean:137
ZMod.commRing: .lake/packages/mathlib/Mathlib/Data/ZMod/Defs.lean:172
Zero.ofOfNat0: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Zero.lean:20
Zero.toOfNat0: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Zero.lean:17
abs: .lake/packages/mathlib/Mathlib/Algebra/Order/Group/Unbundled/Abs.lean:36
absurd: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:323
bne: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Core.lean:765
cond: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1008
congrArg: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:405
dite: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1304
instAddNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1892
instAppendString: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/String/Defs.lean:98
instBEqOfDecidableEq: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1300
instDecidableAnd: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1239
instDecidableEqBitVec: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2526
instDecidableEqBool: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1280
instDecidableEqChar: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3031
instDecidableEqNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1995
instDecidableEqRat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean:45
instDecidableEqString: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:3718
instDecidableOr: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1247
instHAdd: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1784
instHAppendOfAppend: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1823
instHDiv: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1796
instHMod: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1800
instHMul: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1792
instHOrOfOrOp: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1843
instHPow: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1804
instHSub: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1788
instHXorOfXorOp: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1839
instLENat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2026
instLTNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2037
instMonadOption: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Option/Basic.lean:580
instMulNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1913
instMulZeroClassOfSemiring: .lake/packages/mathlib/Mathlib/Algebra/Ring/Defs.lean:150
instNatCastInt: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:63
instNatPowNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1928
instOfNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Int/Basic.lean:65
instOfNatAtLeastTwo: .lake/packages/mathlib/Mathlib/Data/Nat/Cast/Defs.lean:38
instOfNatNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1395
instPowNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1808
instSubNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:2261
instToStringNat: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/ToString/Basic.lean:63
ite: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:1324
optParam: /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Prelude.lean:724
-/

/- SOURCE FILE SHA-256
58450c1ab0d8bb32bc03dadc047190856f73c66f4f36a7392e9f4a842c75de2f  .lake/packages/mathlib/Mathlib/Algebra/Order/Floor/Defs.lean
621439b9ab1ca8354cc99b4aa7bfd4e3007537413b8e822ee805ac35c0f404ef  .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Basic.lean
1c0ae5b5dea58f0c8bd8425cfa7da2e29ab7826d7b2cce6f2d5acf7ffef1784a  .lake/packages/mathlib/Mathlib/Algebra/Polynomial/Div.lean
f6f2c2bb6da4d7dac960bef8d07dc2e337c474b417726c1fd15e30c6b74caafb  .lake/packages/mathlib/Mathlib/Analysis/Complex/Trigonometric.lean
1f19e1d6722b2f51c2cd676d0b28ede856c7915ac815b597cef4b3919040c204  .lake/packages/mathlib/Mathlib/Analysis/Real/Sqrt.lean
55b385f7abb43dd591acc7d548d1de8c3dba6111f79d60814d47b000d8f3bce7  .lake/packages/mathlib/Mathlib/Analysis/SpecialFunctions/Trigonometric/Basic.lean
e2e90ad73a33251a83aa169340e8994cd279adb4acc9ff4606d558e13d5e59ab  .lake/packages/mathlib/Mathlib/Analysis/SpecialFunctions/Trigonometric/Inverse.lean
02ba13aa9ea76486813487aff34e61f4b02e823026d688c8902a7704a35a1d40  .lake/packages/mathlib/Mathlib/Data/ZMod/Defs.lean
30b77ea0918aa986f6617bef4ad99a8d79cd538a714c9f05134bcb6a5e490cc8  /home/zpconn/.elan/toolchains/leanprover--lean4---v4.35.0/src/lean/Init/Data/Rat/Basic.lean
52b4ecd7e9e4997689a7d3f98246e8d41396b0d8afaac593ac6d3927a5e0c504  Model/Types.lean
a3b1ed8691863bd9cf18cbaa79d2d3dcb7a0964c04bcd135117797c583275330  Spec/ADSB.lean
c505219ed76335af94f417d68c896b8667575b2e765c8be8645068401c7dc7e4  Spec/Altitude.lean
01d7ea1d9c37f0b9730643fa571b109c8c834f133d9996917c6b04283a310eb8  Spec/Assignment.lean
b1d8c183288f429ec40bc39c0c2ec845167819e691c3b565199ef71dd88520ec  Spec/AssignmentAltitude.lean
7cf8af53a41f491c62fc6c8ded28e09d3612a2611533ff69315f16ada3c8a4bd  Spec/Binary64.lean
25eb2a136569c34608c11c8894bfbb70649f0813cacc76d145920dadc55ef6c2  Spec/Bits.lean
c5795181b72b74a0f0f4d079325f9f2e4e8848a92959b83a8829add03c92e953  Spec/CPR.lean
eb779814d00954185340a8e24fc463100099035882a6bc91be49b99af738b672  Spec/CPRContracts.lean
efd3487caa852b4857379c470908c66d61d2cfea9479677fee76a058aba0d164  Spec/CPRFormula.lean
d2af3fa179d6dd05823b5abb00f8e592ccc1858232dd61d96f881fe2735a7b45  Spec/CommB.lean
48e8f82c9e8a15821b7c7f7bf787ee9b2f2cf92bdd4d13d61c0205889fa6de36  Spec/CommBLayouts.lean
1a1b1aee3ab9d787e609b71a4ea8d484ae1416124be5deac2ce911a226fc2e09  Spec/Frame.lean
799c9737457b47cb0ac548d0dd861adf82afe758d030b39697daf91fc833e12f  Spec/Message.lean
ac6dbd969733cf582dc37155a369e273d98ec1fcff91c54a4e1bf23a366665d2  Spec/Parity.lean
f2059548eb091562d5e9c1e36ccbedffb17b90436e80b89c0961f326e5a3bde3  Spec/PayloadBits.lean
95dc8ecd19fb66901371d773e777f5fac2b779460edd33274589843893d35bff  Spec/Presentation.lean
782f6f2e1f486b4645c19178eb583f3be828dc540e7fe62b850550a393a4ddf8  Spec/Semantics.lean
-/

import Model.Types
import Spec.Frame
import Spec.Parity
import Spec.CommB
import Spec.Semantics
import Spec.Assignment

/-!
# Complete reference message interface

Wire layouts come from Annex10 IV, fourth edition (2007), the sections cited
in Frame. ADSB and CommB give independently named payload fields. This module
composes them and identifies oracle receiver policies separately. Exact fields
and derived reports are both retained: JSON alone cannot support bit round-trips.
-/
namespace Lean1090.Spec

/-- Annex10 IV (4th ed., 2007) §3.1.2.3.3.2: parity from independently assigned information
fields and a chosen AP/PI overlay. Zero overlay constructs DF17 parity. -/
def withOverlay (body : FrameBody) (overlay : BitVec 24) : Frame :=
  ⟨body, Parity.overlay body.informationBits (packFields body.parts) overlay⟩

/-- Annex10 IV (4th ed., 2007) §3.1.2.3.3: the full frame's exact syndrome, expressed on
field assignments without decoding serialized bytes. -/
def frameSyndrome (f : Frame) : BitVec 24 :=
  Parity.checksum f.body.informationBits (packFields f.body.parts) ^^^ f.parity

/-- rs1090-derived decode/mod.rs and bds05/65 acceptance policy: DF17
requires zero PI syndrome; DF18 does not. ADSB altitude/reserved-bit filters
apply to both. Standard Comm-D is accepted despite the D001 oracle over-read. -/
def frameAccepted (f : Frame) : Bool :=
  match f.body with
  | .extended supplementary _ _ me =>
      adsbHardValid me.toNat && (supplementary || frameSyndrome f == 0)
  | _ => true

/-- Annex10 IV (4th ed., 2007) §§3.1.2.3.3,3.1.2.5.2.2: announced address or AP recovery.
DF19 reserves its trailing bits; it has no address interpretation here. -/
def frameAddress (f : Frame) : Option (BitVec 24) :=
  match f.body with
  | .allCall _ aa | .extended _ _ aa _ => some aa
  | .military _ _ => none
  | _ => some (frameSyndrome f)

/-- Sun 2nd ed., chs.5,13: standard altitude with explicit units.
GNSS TC20–22 uses metres; the separately named oracle view preserves its
barometric interpretation for discrepancy comparison. -/
def frameAltitude (f : Frame) : Option Altitude.Value :=
  match f.body with
  | .shortACAS h | .longACAS h _ => Altitude.decodeAC13 h.ac.toNat
  | .surveillance false h | .commB false h _ => Altitude.decodeAC13 h.code.toNat
  | .extended _ _ _ me =>
      let tc := payloadBits me.toNat 1 5
      if tc ≥ 9 && tc ≤ 18 then
        (Altitude.decodeAC12 (payloadBits me.toNat 9 12)).map Altitude.Value.feet
      else if tc ≥ 20 && tc ≤ 22 then
        (Altitude.decodeGNSSMetres (payloadBits me.toNat 9 12)).map Altitude.Value.metres
      else none
  | _ => none

/-- rs1090-derived decode/mod.rs and bds05.rs: compatibility altitude in
feet, including reserved metric conversion and the TC20–22 source conflict. -/
def frameOracleAltitude (f : Frame) : Option Int :=
  match f.body with
  | .shortACAS h | .longACAS h _ => Altitude.oracleAC13 h.ac.toNat
  | .surveillance false h | .commB false h _ => Altitude.oracleAC13 h.code.toNat
  | .extended _ _ _ me =>
      let tc := payloadBits me.toNat 1 5
      if (tc ≥ 9 && tc ≤ 18) || (tc ≥ 20 && tc ≤ 22) then adsbAltitude me.toNat
      else none
  | _ => none

/-- Annex10 IV (4th ed., 2007) §3.1.2.6.7.1 identity, plus explicitly rs1090-derived
TC28 squawk layout (bds61.rs) where no independent full table was available. -/
def frameIdentity (f : Frame) : Option Nat :=
  match f.body with
  | .surveillance true h | .commB true h _ => some (identityCode h.code)
  | .extended _ _ _ me =>
      if payloadBits me.toNat 1 5 == 28 then
        some (identityCode (BitVec.ofNat 13 (payloadBits me.toNat 12 13)))
      else none
  | _ => none

/-- Sun 2nd ed. chs.4–8 and declared rs1090-derived fallback layouts in ADSB:
unpack every selected payload field, including reserved and unavailable codes. -/
def frameADSB (f : Frame) : Option PayloadRecord :=
  match f.body with
  | .extended _ _ _ me =>
      match decodeADSB me.toNat with | .ok record => some record | .error _ => none
  | _ => none

/-- rs1090-derived commb.rs: candidate inference uses the oracle outer
altitude interpretation even when the standard altitude view differs. -/
def frameCommB (f : Frame) : List (Nat × PayloadRecord) :=
  match f.body with
  | .commB identity _ mb =>
      inferCommB (if identity then 21 else 20) (frameOracleAltitude f) mb.toNat
  | _ => []

/-- Source-defined exact report projection. DF11 CL/IC is an additional
standard view; failure to identify CL/IC does not reject a received DF11. -/
def report (f : Frame) : Report :=
  ⟨frameSyndrome f, frameAddress f,
   (match f.body with | .allCall _ _ => Parity.interrogator (frameSyndrome f) | _ => none),
   frameAltitude f, frameIdentity f, frameADSB f, frameCommB f,
   (match f.body with | .extended _ _ _ me => some (Semantics.adsb me.toNat) | _ => none),
   (match f.body with
    | .commB _ _ mb => (frameCommB f).map fun (reg, _) => (reg, Semantics.commB reg mb.toNat)
    | _ => [])⟩

/-- Independent wire-field validity domain: field widths are enforced by
BitVec and the source/receiver predicates state parity and payload acceptance.
No report coherence or decoder result is a hypothesis. The complete semantic
report occurs in the round-trip conclusion, not inside this predicate. -/
def Valid (f : Frame) : Prop := frameAccepted f = true

instance (f : Frame) : Decidable (Valid f) := by unfold Valid; infer_instance

/-- Annex10 IV layouts + explicit rs1090-derived acceptance: total reference
decoding of exactly one7/14-byte message. Errors are none, including bad lengths,
unsupported DF, DF17 PI failure or oracle payload plausibility failure. -/
def decode (bytes : List UInt8) : Option Message := do
  let f ← decodeFrame bytes
  if frameAccepted f then some ⟨f, report f⟩ else none

/-- Annex10 IV independent encoder from separately assigned named wire fields.
It neither calls the decoder nor searches for a preimage. Redundant reports
are not serialized. The round-trip conclusion constructs the coherent report;
Valid constrains only independently assigned frame fields. -/
def encode (f : Message) : List UInt8 := encodeFrame f.fields

/-- rs1090-derived Message::from_bytes boundary policy: consume one DF-sized
prefix and return the untouched suffix. The whole-buffer decode API is stricter. -/
def decodePrefix (bytes : List UInt8) : Option (Message × List UInt8) := do
  let first ← bytes.head?
  let count := frameBytes (first.toNat / 8)
  let message ← decode (bytes.take count)
  some (message, bytes.drop count)

/-- Annex10 IV independent encoder-side assignment. Its expected report is
assembled from source columns and separate altitude bit arithmetic, without
calling any decoder or decoder-only helper. Checked transitively by the gate. -/
def assigned (f : Frame) : Message := ⟨f, Assignment.expectedReport f⟩

/-- Annex10 IV layouts: nonempty valid examples for all supported families,
including a nonempty identification payload and two-bit Comm-D descriptor. -/
def frameWitnesses : List Frame :=
  let acas : ACASFields := ⟨0,0,0,0,0,0,0,6200⟩
  let surv : SurveillanceFields := ⟨0,0,0,6200⟩
  [withOverlay (.shortACAS acas) 0x406b90,
   withOverlay (.surveillance false surv) 0x406b90,
   withOverlay (.surveillance true surv) 0x406b90,
   withOverlay (.allCall 5 0x406b90) 0,
   withOverlay (.longACAS acas 0) 0x406b90,
   withOverlay (.extended false 5 0x406b90 0x2015a678d4d220) 0,
   withOverlay (.extended true 0 0x406b90 0x2015a678d4d220) 0,
   ⟨.military 0 0, 0⟩,
   withOverlay (.commB false surv 0x202cc371c31de0) 0x406b90,
   withOverlay (.commB true surv 0x202cc371c31de0) 0x406b90,
   withOverlay (.commD 0 0 0 0) 0x406b90]

/-- All eleven format-family witnesses satisfy the acceptance domain. This
proves non-vacuity, not the unproved universal field round-trip capstone. -/
theorem message_nonvacuous :
    ∀ f ∈ frameWitnesses, Valid f := by decide +kernel

/-- A concrete standard Comm-D word is decoded, exposing the oracle D001
115-bit-reader disagreement rather than removing this format from scope. -/
theorem commD_witness :
    decodeFrame (valueBytes 14 0xc000000000000000000000000000) =
      some ⟨.commD 0 0 0 0, 0⟩ := by decide +kernel

end Lean1090.Spec

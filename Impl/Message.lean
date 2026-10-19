import Model.Types
import Impl.Frame
import Impl.Parity
import Impl.CommB
import Impl.Semantics

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl
open Lean1090.Spec

-- Initial algorithm: Spec/Message.lean:23.
/-- Annex10 IV (4th ed., 2007) §3.1.2.3.3: the full frame's exact syndrome, expressed on
field assignments without decoding serialized bytes. -/
def frameSyndrome (f : Frame) : BitVec 24 :=
  Parity.checksum (informationBits f.body) (packFields (frameParts f.body)) ^^^ f.parity

-- Initial algorithm: Spec/Message.lean:28.
/-- rs1090-derived decode/mod.rs and bds05/65 acceptance policy: DF17
requires zero PI syndrome; DF18 does not. ADSB altitude/reserved-bit filters
apply to both. Standard Comm-D is accepted despite the D001 oracle over-read. -/
def frameAcceptedWithSyndrome (f : Frame) (syndrome : BitVec 24) : Bool :=
  match f.body with
  | .extended supplementary _ _ me =>
      adsbHardValid me.toNat && (supplementary || syndrome == 0)
  | _ => true

/-- Standalone acceptance uses the same helper as the complete decoder. -/
def frameAccepted (f : Frame) : Bool :=
  frameAcceptedWithSyndrome f (frameSyndrome f)

-- Initial algorithm: Spec/Message.lean:37.
/-- Annex10 IV (4th ed., 2007) §§3.1.2.3.3,3.1.2.5.2.2: announced address or AP recovery.
DF19 reserves its trailing bits; it has no address interpretation here. -/
def frameAddressWithSyndrome (f : Frame) (syndrome : BitVec 24) : Option (BitVec 24) :=
  match f.body with
  | .allCall _ aa | .extended _ _ aa _ => some aa
  | .military _ _ => none
  | _ => some syndrome

/-- Standalone address recovery shares the decoder's address-selection helper. -/
def frameAddress (f : Frame) : Option (BitVec 24) :=
  frameAddressWithSyndrome f (frameSyndrome f)

-- Initial algorithm: Spec/Message.lean:45.
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

-- Initial algorithm: Spec/Message.lean:61.
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

-- Initial algorithm: Spec/Message.lean:73.
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

-- Initial algorithm: Spec/Message.lean:84.
/-- Sun 2nd ed. chs.4–8 and declared rs1090-derived fallback layouts in ADSB:
unpack every selected payload field, including reserved and unavailable codes. -/
def frameADSB (f : Frame) : Option PayloadRecord :=
  match f.body with
  | .extended _ _ _ me =>
      match decodeADSB me.toNat with | .ok record => some record | .error _ => none
  | _ => none

-- Initial algorithm: Spec/Message.lean:92.
/-- rs1090-derived commb.rs: candidate inference uses the oracle outer
altitude interpretation even when the standard altitude view differs. -/
def frameCommB (f : Frame) : List (Nat × PayloadRecord) :=
  match f.body with
  | .commB identity _ mb =>
      inferCommB (if identity then 21 else 20) (frameOracleAltitude f) mb.toNat
  | _ => []

-- Initial algorithm: Spec/Message.lean:100.
/-- Source-defined exact report projection. DF11 CL/IC is an additional
standard view; failure to identify CL/IC does not reject a received DF11. -/
def reportWithSyndrome (f : Frame) (syndrome : BitVec 24) : Report :=
  ⟨syndrome, frameAddressWithSyndrome f syndrome,
   (match f.body with | .allCall _ _ => Parity.interrogator syndrome | _ => none),
   frameAltitude f, frameIdentity f, frameADSB f, frameCommB f,
   (match f.body with | .extended _ _ _ me => some (Semantics.adsb me.toNat) | _ => none),
   (match f.body with
    | .commB _ _ mb => (frameCommB f).map fun (reg, _) => (reg, Semantics.commB reg mb.toNat)
    | _ => [])⟩

/-- Standalone reports use the same projection as the complete decoder. -/
def report (f : Frame) : Report :=
  reportWithSyndrome f (frameSyndrome f)

-- Initial algorithm: Spec/Message.lean:119.
/-- Annex10 IV layouts + explicit rs1090-derived acceptance: total reference
decoding of exactly one7/14-byte message. Errors are none, including bad lengths,
unsupported DF, DF17 PI failure or oracle payload plausibility failure.
After parsing succeeds, one pure syndrome calculation supplies acceptance and
every report use. A later payload-plausibility rejection may now calculate its
syndrome before rejection; malformed lengths and unsupported DFs still stop at
the live frame parser. The parser returns its already decoded wire word, so
CRC does not reconstruct that word from field assignments. -/
def decode (bytes : List UInt8) : Option Message := do
  let (f, word) ← decodeFrameWithWord bytes
  let syndrome := Parity.syndrome (informationBits f.body + 24) word
  if frameAcceptedWithSyndrome f syndrome then some ⟨f, reportWithSyndrome f syndrome⟩ else none

-- Initial algorithm: Spec/Message.lean:132.
/-- rs1090-derived Message::from_bytes boundary policy: consume one DF-sized
prefix and return the untouched suffix. The whole-buffer decode API is stricter. -/
def decodePrefix (bytes : List UInt8) : Option (Message × List UInt8) := do
  let first ← bytes.head?
  let count := frameBytes (first.toNat / 8)
  let message ← decode (bytes.take count)
  some (message, bytes.drop count)

end Lean1090.Impl

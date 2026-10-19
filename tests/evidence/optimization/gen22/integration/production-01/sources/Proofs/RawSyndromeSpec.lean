import Proofs.FrameRoundTrips
import Proofs.ParityOverlay

/-!
# CRC of the complete transmitted frame word

The independent encoder concatenates every information field and the explicit
24 parity bits. Byte reconstruction preserves that whole bounded word. CRC
linearity then separates information with trailing zeros from the parity word,
whose leading zeros leave its 24-bit value unchanged. Successful parsing is
handled by the existing every-byte round trip, with no validity or parity
assumption and no dependency on the implementation decoder.
-/

namespace Lean1090.Proofs.RawSyndromeSpec
open Spec

/-- Every structural constructor supplies exactly its declared information width. -/
theorem parts_width (body : FrameBody) :
    BitPacking.width body.parts = body.informationBits := by
  cases body <;>
    simp [FrameBody.parts, ACASFields.parts, SurveillanceFields.parts,
      BitPacking.width, FrameBody.informationBits]

/-- Both supported wire widths contain an integral number of bytes. -/
theorem encoded_width (body : FrameBody) :
    ((body.informationBits + 24) / 8) * 8 = body.informationBits + 24 := by
  cases body <;> norm_num [FrameBody.informationBits]

/-- Byte encoding preserves all information and parity bits, including spare bits. -/
theorem bytesValue_encodeFrame (f : Frame) :
    bytesValue (encodeFrame f) = packFields f.body.parts * 2 ^ 24 + f.parity.toNat := by
  unfold encodeFrame
  rw [WireBytes.bytesValue_valueBytes, WireBytes.byte_radix, encoded_width]
  have widths : BitPacking.width (f.body.parts ++ [(24, f.parity.toNat)]) =
      f.body.informationBits + 24 := by
    rw [BitPacking.width_append, parts_width]
    rfl
  have bound : packFields (f.body.parts ++ [(24, f.parity.toNat)]) <
      2 ^ (f.body.informationBits + 24) := by
    rw [← widths]
    exact BitPacking.pack_bound _
  have parity : packFields [(24, f.parity.toNat)] = f.parity.toNat := by
    simp [packFields, Nat.mod_eq_of_lt f.parity.isLt]
  rw [Nat.mod_eq_of_lt bound, BitPacking.pack_append]
  change packFields f.body.parts * 2 ^ 24 + packFields [(24, f.parity.toNat)] = _
  rw [parity]

/-- CRC over the complete encoded word equals field-based syndrome for every frame. -/
theorem syndrome_encodeFrame (f : Frame) :
    Parity.syndrome (f.body.informationBits + 24) (bytesValue (encodeFrame f)) =
      frameSyndrome f := by
  rw [bytesValue_encodeFrame, ParityFacts.disjoint_append_xor 24 _ _ f.parity.isLt,
    CRCLinear]
  have low : Parity.syndrome (f.body.informationBits + 24) f.parity.toNat = f.parity := by
    rw [Nat.add_comm]
    simpa only [BitVec.ofNat_toNat, BitVec.setWidth_eq] using
      ParityFacts.syndrome_low_word f.body.informationBits f.parity.toNat f.parity.isLt
  rw [low]
  rfl

/-- Successful structural parsing preserves the raw-word CRC, without acceptance assumptions. -/
theorem syndrome_decodeFrame (bytes : List UInt8) (f : Frame)
    (decoded : decodeFrame bytes = some f) :
    Parity.syndrome (f.body.informationBits + 24) (bytesValue bytes) = frameSyndrome f := by
  rw [← FrameRoundTrip.encode_decode bytes f decoded]
  exact syndrome_encodeFrame f

/-- A successfully parsed byte length agrees with the frame's declared wire width. -/
theorem decoded_width (bytes : List UInt8) (f : Frame)
    (decoded : decodeFrame bytes = some f) :
    bytes.length * 8 = f.body.informationBits + 24 := by
  rw [← FrameRoundTrip.encode_decode bytes f decoded]
  simpa only [encodeFrame, WireBytes.valueBytes_length] using encoded_width f.body

/-- The same universal equality when the raw CRC width comes from the byte list. -/
theorem syndrome_decodeFrame_length (bytes : List UInt8) (f : Frame)
    (decoded : decodeFrame bytes = some f) :
    Parity.syndrome (bytes.length * 8) (bytesValue bytes) = frameSyndrome f := by
  rw [decoded_width bytes f decoded]
  exact syndrome_decodeFrame bytes f decoded

set_option maxRecDepth 10000 in
theorem short_spares_witness :
    let f : Frame := ⟨.shortACAS ⟨1, 1, 1, 7, 3, 15, 3, 8191⟩, 0xFEDCBA⟩
    Parity.syndrome 56 (bytesValue (encodeFrame f)) = frameSyndrome f := by decide

set_option maxRecDepth 10000 in
theorem allCall_parity_witness :
    let f : Frame := ⟨.allCall 7 0xFFFFFF, 0xFFFFFF⟩
    Parity.syndrome 56 (bytesValue (encodeFrame f)) = frameSyndrome f := by decide

set_option maxRecDepth 10000 in
theorem long_extended_witness :
    let f : Frame := ⟨.extended false 5 0xA1B2C3 0xFEDCBA98765432, 0⟩
    Parity.syndrome 112 (bytesValue (encodeFrame f)) = frameSyndrome f := by decide

set_option maxRecDepth 10000 in
theorem military_df19_witness :
    let f : Frame := ⟨.military 7 0xFFFFFFFFFFFFFFFFFFFF, 0xABCDEF⟩
    Parity.syndrome 112 (bytesValue (encodeFrame f)) = frameSyndrome f := by decide

set_option maxRecDepth 10000 in
theorem commD_spares_witness :
    let f : Frame := ⟨.commD 1 1 15 0xFFFFFFFFFFFFFFFFFFFF, 0xFFFFFF⟩
    Parity.syndrome 112 (bytesValue (encodeFrame f)) = frameSyndrome f := by decide

#print axioms parts_width
#print axioms encoded_width
#print axioms bytesValue_encodeFrame
#print axioms syndrome_encodeFrame
#print axioms syndrome_decodeFrame
#print axioms decoded_width
#print axioms syndrome_decodeFrame_length
#print axioms short_spares_witness
#print axioms allCall_parity_witness
#print axioms long_extended_witness
#print axioms military_df19_witness
#print axioms commD_spares_witness
end Lean1090.Proofs.RawSyndromeSpec

import Impl.Frame
import Spec.Frame
import Proofs.FrameBits
import Proofs.ByteWords

/-! The live frame parser preserves its parsed wire word without changing
the frozen all-byte-list parsing result. No decoder-refinement import is used. -/
namespace Lean1090.Proofs.FrameWord

private theorem readACAS_eq (width word : Nat) :
    Impl.readACAS width word = Spec.readACAS width word := by
  simp only [Impl.readACAS, Spec.readACAS, FrameBits.field_eq]

private theorem readSurveillance_eq (width word : Nat) :
    Impl.readSurveillance width word = Spec.readSurveillance width word := by
  simp only [Impl.readSurveillance, Spec.readSurveillance, FrameBits.field_eq]

/-- For every byte list, successful parsing returns the same frozen frame and
the exact word already computed by the parser; failures remain failures. -/
theorem decodeFrameWithWord_eq (bytes : List UInt8) :
    Impl.decodeFrameWithWord bytes =
      (Spec.decodeFrame bytes).map (fun frame => (frame, Spec.bytesValue bytes)) := by
  unfold Impl.decodeFrameWithWord Spec.decodeFrame
  simp only [ByteWords.bytesValue_eq, FrameBits.field_eq, readACAS_eq,
    readSurveillance_eq, Impl.frameBytes]
  cases hfirst : bytes.head? with
  | none => rfl
  | some first =>
    split
    · rfl
    · simp only [Option.map_bind, Option.map_some]

/-- The public parser projects the live paired parser for all inputs. -/
theorem decodeFrame_eq (bytes : List UInt8) :
    Impl.decodeFrame bytes = Spec.decodeFrame bytes := by
  rw [Impl.decodeFrame, decodeFrameWithWord_eq]
  cases Spec.decodeFrame bytes <;> rfl

/-- Function equality for consumers of the unchanged public parser API. -/
theorem decodeFrame_function_eq : @Impl.decodeFrame = @Spec.decodeFrame := by
  funext bytes
  exact decodeFrame_eq bytes

/-- A successful paired parse supplies both independent reference facts. -/
theorem successful_parse (bytes : List UInt8) (frame : Spec.Frame) (word : Nat)
    (h : Impl.decodeFrameWithWord bytes = some (frame, word)) :
    Spec.decodeFrame bytes = some frame ∧ word = Spec.bytesValue bytes := by
  rw [decodeFrameWithWord_eq] at h
  cases decoded : Spec.decodeFrame bytes with
  | none => simp [decoded] at h
  | some found =>
    simp only [decoded, Option.map_some, Option.some.injEq, Prod.mk.injEq] at h
    rcases h with ⟨rfl, rfl⟩
    exact ⟨rfl, rfl⟩

/-- Empty input still fails before parsing a word. -/
theorem empty_witness : Impl.decodeFrameWithWord [] = none := by decide +kernel

/-- A short DF0 frame returns the complete seven-byte wire value. -/
theorem short_word_witness :
    (Impl.decodeFrameWithWord [0, 1, 2, 3, 4, 5, 6]).map Prod.snd =
      some 0x00010203040506 := by decide +kernel

/-- A long DF17 word preserves all high bits across the 64-bit boundary. -/
theorem long_word_witness :
    (Impl.decodeFrameWithWord [0x8D, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]).map
      Prod.snd = some 0x8D0102030405060708090A0B0C0D := by decide +kernel

/-- Unsupported DF1 remains rejected even at the expected short length. -/
theorem unsupported_witness :
    Impl.decodeFrameWithWord [8, 0, 0, 0, 0, 0, 0] = none := by decide +kernel

/-- The parser keeps exact-length rejection on a supported DF. -/
theorem wrong_length_witness :
    Impl.decodeFrameWithWord [0x8D, 1, 2, 3, 4, 5, 6] = none := by decide +kernel

/-- Comm-D retains the complete wire value, including its high spare bits. -/
theorem commD_word_witness :
    (Impl.decodeFrameWithWord [0xFF, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]).map
      Prod.snd = some 0xFF0102030405060708090A0B0C0D := by decide +kernel

#print axioms decodeFrameWithWord_eq
#print axioms decodeFrame_eq
#print axioms decodeFrame_function_eq
#print axioms successful_parse
#print axioms empty_witness
#print axioms short_word_witness
#print axioms long_word_witness
#print axioms unsupported_witness
#print axioms wrong_length_witness
#print axioms commD_word_witness

end Lean1090.Proofs.FrameWord

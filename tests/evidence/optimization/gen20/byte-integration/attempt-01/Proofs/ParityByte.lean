import Proofs.ParityByteBits
import Proofs.FoldBlocks

/-! Byte batching preserves the unrestricted original bit-loop recurrence. -/
namespace Lean1090.Proofs.ParityByte

/-- Up to sixteen complete bytes visit exactly the original MSB-first bits.
The natural input word is unrestricted, including bits above the chosen width. -/
theorem syndromeBytes_eq_bits (byteCount word : Nat) (bounded : byteCount ≤ 16) :
    Impl.Parity.syndromeBytes byteCount word =
      Impl.Parity.syndromeBits (8 * byteCount) word := by
  unfold Impl.Parity.syndromeBytes Impl.Parity.syndromeBits
  dsimp only
  simp only [ParityBits.cachedBit_eq]
  apply congrArg (fun r : UInt32 => BitVec.ofNat 24 r.toNat)
  rw [Nat.mul_comm 8 byteCount, FoldBlocks.fold_blocks]
  apply congrArg (fun f : (i : Nat) → i < byteCount → UInt32 → UInt32 =>
    Nat.fold byteCount f 0)
  funext i hi remainder
  rw [ParityByteBits.byteStep_eq_fold]
  apply congrArg (fun f : (j : Nat) → j < 8 → UInt32 → UInt32 =>
    Nat.fold 8 f remainder)
  funext j hj r
  rw [ParityByteBits.cachedByte_wordBit_eq word (8 * (byteCount - 1 - i)) (7 - j)
    (by omega) (by omega) (by omega)]
  congr 1
  congr 1
  omega

/-- The guarded byte implementation equals the original bit loop for every
natural width and word. Non-byte widths and widths above 128 use that loop. -/
theorem syndrome_eq_bits (width word : Nat) :
    Impl.Parity.syndrome width word = Impl.Parity.syndromeBits width word := by
  unfold Impl.Parity.syndrome
  split
  · rename_i h
    rw [syndromeBytes_eq_bits (width / 8) word (by omega)]
    have width_eq : 8 * (width / 8) = width := by omega
    rw [width_eq]
  · rfl

/-- Empty input and non-byte short input preserve the original zero/fallback
behavior, including natural words much larger than either cached word. -/
theorem empty_and_short_witness :
    Impl.Parity.syndrome 0 (2^256 + 19) = 0 ∧
    Impl.Parity.syndrome 7 (2^256 + 0x65) =
      Impl.Parity.syndromeBits 7 (2^256 + 0x65) := by
  decide +kernel

/-- The first byte and both sides of the low-word boundary retain bit order. -/
theorem low_word_boundaries_witness :
    Impl.Parity.syndrome 8 (2^256 + 0xA5) =
      Impl.Parity.syndromeBits 8 (2^256 + 0xA5) ∧
    Impl.Parity.syndrome 56 (2^256 + 0x5D484FDEA248F5) =
      Impl.Parity.syndromeBits 56 (2^256 + 0x5D484FDEA248F5) ∧
    Impl.Parity.syndrome 64 (2^256 + 0xFEDCBA9876543210) =
      Impl.Parity.syndromeBits 64 (2^256 + 0xFEDCBA9876543210) := by
  decide +kernel

/-- Long frames and the last two cached-byte boundaries retain both words. -/
theorem high_word_boundaries_witness :
    Impl.Parity.syndrome 112 (2^256 + 0x8D40621D58C382D690C8AC2863A7) =
      Impl.Parity.syndromeBits 112 (2^256 + 0x8D40621D58C382D690C8AC2863A7) ∧
    Impl.Parity.syndrome 120 (2^256 + 2^119 + 2^64 + 0x81) =
      Impl.Parity.syndromeBits 120 (2^256 + 2^119 + 2^64 + 0x81) ∧
    Impl.Parity.syndrome 128 (2^256 + 2^127 + 2^64 + 0x81) =
      Impl.Parity.syndromeBits 128 (2^256 + 2^127 + 2^64 + 0x81) := by
  decide +kernel

/-- The first width above the cache keeps the arbitrary-precision bit path. -/
theorem beyond_cache_witness :
    Impl.Parity.syndrome 129 (2^256 + 2^128 + 2^64 + 7) =
      Impl.Parity.syndromeBits 129 (2^256 + 2^128 + 2^64 + 7) := by
  decide +kernel

#print axioms syndromeBytes_eq_bits
#print axioms syndrome_eq_bits
#print axioms empty_and_short_witness
#print axioms low_word_boundaries_witness
#print axioms high_word_boundaries_witness
#print axioms beyond_cache_witness

end Lean1090.Proofs.ParityByte

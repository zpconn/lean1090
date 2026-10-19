import Proofs.ParityBits

/-! Byte batching preserves the order of eight CRC updates and every cached bit. -/
namespace Lean1090.Proofs.ParityByteBits

/-- The unrolled byte update performs exactly eight MSB-first word updates,
for every machine-word remainder and byte argument. -/
theorem byteStep_eq_fold (remainder : UInt32) (byte : UInt64) :
    Impl.Parity.byteStep remainder byte =
      Nat.fold 8 (fun j _ r => Impl.Parity.wordStep r
        (Impl.Parity.wordBit byte (7 - j))) remainder := by
  simp only [Nat.fold_succ, Nat.fold_zero, Impl.Parity.byteStep]

/-- Every bit of an aligned cached byte is the corresponding bit of the
original arbitrary natural word, including the two cache boundary bytes. -/
theorem cachedByte_wordBit_eq (word offset j : Nat) (ho : offset < 128)
    (ha : offset % 8 = 0) (hj : j < 8) :
    Impl.Parity.wordBit
      (Impl.Parity.cachedByte word.toUInt64 (word >>> 64).toUInt64 offset) j =
      word.testBit (offset + j) := by
  unfold Impl.Parity.cachedByte
  split
  · rename_i low
    have inside : offset + j < 64 := by omega
    have count : offset.toUInt64.toNat = offset :=
      UInt64.toNat_ofNat_of_lt' (Nat.lt_trans low (by decide))
    rw [ParityBits.wordBit_eq _ _ (by omega), UInt64.toNat_shiftRight,
      count, Nat.mod_eq_of_lt low, Nat.testBit_shiftRight,
      UInt64.toNat_ofNat', Nat.testBit_mod_two_pow]
    simp only [inside, decide_true, Bool.true_and]
  · rename_i high
    have small : offset - 64 < 64 := by omega
    have inside : offset - 64 + j < 64 := by omega
    have count : (offset - 64).toUInt64.toNat = offset - 64 :=
      UInt64.toNat_ofNat_of_lt' (Nat.lt_trans small (by decide))
    rw [ParityBits.wordBit_eq _ _ (by omega), UInt64.toNat_shiftRight,
      count, Nat.mod_eq_of_lt small, Nat.testBit_shiftRight,
      UInt64.toNat_ofNat', Nat.testBit_mod_two_pow]
    simp only [inside, decide_true, Bool.true_and, Nat.testBit_shiftRight]
    congr 1
    omega

/-- A non-palindromic byte checks the MSB-first update order. -/
theorem byte_order_witness : Impl.Parity.byteStep 0 0xA3 = 0xA3 := by
  decide +kernel

/-- The byte update ignores high byte bits and high remainder bits. -/
theorem high_machine_bits_witness :
    Impl.Parity.byteStep 0x80800000 (2^63 + 0xA5) =
      Impl.Parity.byteStep 0x800000 0xA5 := by
  decide +kernel

/-- The low byte includes bit zero of an over-wide input. -/
theorem first_cached_byte_witness :
    Impl.Parity.wordBit
      (Impl.Parity.cachedByte (2^200 + 1 : Nat).toUInt64
        ((2^200 + 1 : Nat) >>> 64).toUInt64 0) 0 = true := by
  decide +kernel

/-- The final low-cache byte includes bit 63 without wrapping its shift. -/
theorem low_cache_boundary_witness :
    Impl.Parity.wordBit
      (Impl.Parity.cachedByte (2^63 : Nat).toUInt64
        ((2^63 : Nat) >>> 64).toUInt64 56) 7 = true := by
  decide +kernel

/-- Offset 64 starts the high cache, even for inputs extending beyond it. -/
theorem high_cache_boundary_witness :
    Impl.Parity.wordBit
      (Impl.Parity.cachedByte (2^200 + 2^64 : Nat).toUInt64
        ((2^200 + 2^64 : Nat) >>> 64).toUInt64 64) 0 = true := by
  decide +kernel

/-- The final cached byte includes bit 127 of an over-wide input. -/
theorem last_cached_byte_witness :
    Impl.Parity.wordBit
      (Impl.Parity.cachedByte (2^200 + 2^127 : Nat).toUInt64
        ((2^200 + 2^127 : Nat) >>> 64).toUInt64 120) 7 = true := by
  decide +kernel

/-- An input bit beyond both caches does not leak into the last cached byte. -/
theorem above_cache_ignored_witness :
    Impl.Parity.wordBit
      (Impl.Parity.cachedByte (2^200 : Nat).toUInt64
        ((2^200 : Nat) >>> 64).toUInt64 120) 7 = false := by
  decide +kernel

#print axioms byteStep_eq_fold
#print axioms cachedByte_wordBit_eq
#print axioms byte_order_witness
#print axioms high_machine_bits_witness
#print axioms first_cached_byte_witness
#print axioms low_cache_boundary_witness
#print axioms high_cache_boundary_witness
#print axioms last_cached_byte_witness
#print axioms above_cache_ignored_witness

end Lean1090.Proofs.ParityByteBits

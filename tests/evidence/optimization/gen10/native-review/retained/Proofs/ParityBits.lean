import Impl.Parity
import Capstones

/-!
The cached machine-word bit extractor preserves arbitrary natural-number
inputs and indices. The first two words are only a fast prefix: indices at
least 128 retain the original arbitrary-precision operation.
-/

namespace Lean1090.Proofs.ParityBits

/-- UInt64 shifts mask their count modulo 64. Below 64 the native shift/mask
test is exactly the corresponding bit of its natural-number interpretation. -/
theorem wordBit_eq (word : UInt64) (i : Nat) (small : i < 64) :
    Impl.Parity.wordBit word i = word.toNat.testBit i := by
  have sizeBound : i < UInt64.size := Nat.lt_trans small (by decide)
  have index : i.toUInt64.toNat = i := UInt64.toNat_ofNat_of_lt' sizeBound
  have bit : word.toNat.testBit i = decide ((word.toNat >>> i) % 2 = 1) := by
    simpa only [Nat.testBit_shiftRight, Nat.add_zero] using
      (Nat.testBit_zero (word.toNat >>> i))
  unfold Impl.Parity.wordBit
  rw [bit, Bool.eq_iff_iff]
  simp only [beq_iff_eq, decide_eq_true_eq, ← UInt64.toNat_inj,
    UInt64.toNat_and, UInt64.toNat_shiftRight, index, UInt64.toNat_one,
    Nat.mod_eq_of_lt small, Nat.and_one_is_mod]

/-- Two cached 64-bit words plus the unbounded fallback reproduce every bit
of every natural number, including over-wide inputs and indices beyond 127. -/
theorem cachedBit_eq (word i : Nat) :
    Impl.Parity.cachedBit word word.toUInt64 (word >>> 64).toUInt64 i =
      word.testBit i := by
  unfold Impl.Parity.cachedBit
  split
  · rename_i small
    rw [wordBit_eq _ _ small, UInt64.toNat_ofNat', Nat.testBit_mod_two_pow]
    simp only [small, decide_true, Bool.true_and]
  · rename_i notSmall
    split
    · rename_i below128
      have small : i - 64 < 64 := by omega
      rw [wordBit_eq _ _ small, UInt64.toNat_ofNat', Nat.testBit_mod_two_pow]
      simp only [small, decide_true, Bool.true_and, Nat.testBit_shiftRight]
      congr 1
      omega
    · rfl

/-- The cache boundary belongs to the high-word path. -/
theorem high_boundary_witness :
    Impl.Parity.cachedBit (2^64) (2^64 : Nat).toUInt64
      ((2^64 : Nat) >>> 64).toUInt64 64 = true := by
  decide +kernel

/-- The first bit beyond the cache still uses the full natural-number word. -/
theorem fallback_boundary_witness :
    Impl.Parity.cachedBit (2^128) (2^128 : Nat).toUInt64
      ((2^128 : Nat) >>> 64).toUInt64 128 = true := by
  decide +kernel

#print axioms wordBit_eq
#print axioms cachedBit_eq
#print axioms high_boundary_witness
#print axioms fallback_boundary_witness

end Lean1090.Proofs.ParityBits

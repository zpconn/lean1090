import Proofs.ParityBits
import Proofs.ParityByte
import Proofs.ParityLinear
import Mathlib.Tactic.IntervalCases

/-! Machine-word CRC updates and a list-free fold preserve the frozen recurrence. -/
namespace Lean1090.Proofs.ParityWord

private theorem bit23_mask (value : BitVec 32) :
    (value &&& 0x800000#32 == 0#32) = !value.getLsbD 23 := by
  rw [Bool.eq_iff_iff]
  simp only [beq_iff_eq]
  constructor
  · intro equal
    have bit := congrArg (fun x : BitVec 32 => x.getLsbD 23) equal
    simpa using bit
  · intro bit
    apply BitVec.eq_of_getLsbD_eq
    intro i small
    interval_cases i <;> simp_all

private theorem wordStep_bits (value : BitVec 32) (bit : Bool) :
    ((((value <<< 1) ||| (if bit then 1#32 else 0#32)) ^^^
      (if (value &&& 0x800000#32) == 0#32 then 0#32 else 0x1FFF409#32)) &&&
        0xFFFFFF#32).setWidth 24 =
      (((value.setWidth 24) <<< 1) ^^^ (if bit then 1 else 0)) ^^^
        (if (value.setWidth 24).msb then 0xFFF409#24 else 0) := by
  rw [bit23_mask]
  apply BitVec.eq_of_getLsbD_eq
  intro i small
  interval_cases i <;> cases bit <;> cases h : value.getLsbD 23 <;>
    simp_all [BitVec.msb_setWidth]

/-- Every UInt32 state projects to the same 24-bit polynomial step. High bits
of the input state are irrelevant; no bounded-state hypothesis is needed. -/
theorem wordStep_eq (remainder : UInt32) (bit : Bool) :
    BitVec.ofNat 24 (Impl.Parity.wordStep remainder bit).toNat =
      Spec.Parity.step (BitVec.ofNat 24 remainder.toNat) bit := by
  rw [parity_step_eq]
  change (Impl.Parity.wordStep remainder bit).toBitVec.setWidth 24 =
    ((remainder.toBitVec.setWidth 24 <<< 1) ^^^ (if bit then 1 else 0)) ^^^
      (if (remainder.toBitVec.setWidth 24).msb then
        BitVec.ofNat 24 Spec.Parity.generator else 0)
  simp only [Impl.Parity.wordStep, UInt32.toBitVec_and, UInt32.toBitVec_xor,
    UInt32.toBitVec_or, UInt32.toBitVec_shiftLeft, apply_ite,
    beq_iff_eq, ← UInt32.toBitVec_inj, UInt32.toBitVec_ofNat]
  have shiftOne (x : BitVec 32) : x <<< (1#32 % 32) = x <<< (1 : Nat) := by rfl
  have generator24 : BitVec.ofNat 24 Spec.Parity.generator = 0xFFF409#24 := by
    decide +kernel
  simp only [shiftOne, generator24]
  simpa only [apply_ite, beq_iff_eq] using
    wordStep_bits remainder.toBitVec bit

/-- The original public update remains a delegate to the same native step. -/
theorem step_eq (remainder : BitVec 24) (bit : Bool) :
    Impl.Parity.step remainder bit = Spec.Parity.step remainder bit := by
  unfold Impl.Parity.step
  rw [wordStep_eq]
  congr 1
  apply BitVec.eq_of_toNat_eq
  simp only [BitVec.toNat_ofNat, UInt32.toNat_ofNat']
  have bound : remainder.toNat < UInt32.size :=
    Nat.lt_trans remainder.isLt (by decide)
  rw [Nat.mod_eq_of_lt bound, BitVec.toNat_mod_cancel]

/-- A bounded natural fold visits precisely the ascending range of indices. -/
theorem fold_range {α : Type} (n : Nat) (f : Nat → α → α) (init : α) :
    Nat.fold n (fun i _ a => f i a) init =
      (List.range n).foldl (fun a i => f i a) init := by
  induction n with
  | zero => rfl
  | succ n ih =>
    simp only [Nat.fold_succ, List.range_succ, List.foldl_append,
      List.foldl_cons, List.foldl_nil, ih]

/-- The list-free machine-word loop refines the frozen recurrence for every
natural width and word, including zero widths and indices beyond the cache. -/
theorem syndrome_eq (width word : Nat) :
    Impl.Parity.syndrome width word = Spec.Parity.syndrome width word := by
  rw [ParityByte.syndrome_eq_bits]
  unfold Impl.Parity.syndromeBits Spec.Parity.syndrome
  simp only [ParityBits.cachedBit_eq, fold_range]
  symm
  exact List.foldl_hom (fun r : UInt32 => BitVec.ofNat 24 r.toNat)
    (g₁ := fun r i => Impl.Parity.wordStep r (word.testBit (width - 1 - i)))
    (g₂ := fun r i => Spec.Parity.step r (word.testBit (width - 1 - i)))
    (l := List.range width) (init := 0)
    (fun r i => (wordStep_eq r (word.testBit (width - 1 - i))).symm)

/-- A high bit outside the 24-bit state does not trigger polynomial feedback. -/
theorem high_state_witness :
    Impl.Parity.wordStep 0x80000000 true = 1 := by
  decide +kernel

/-- The top state bit does trigger feedback even with additional high bits. -/
theorem feedback_state_witness :
    Impl.Parity.wordStep 0x80800000 false = 0xFFF409 := by
  decide +kernel

/-- Zero-width input performs no steps, regardless of word magnitude. -/
theorem zero_width_witness :
    Impl.Parity.syndrome 0 (2^256 + 19) = 0 := by
  decide +kernel

/-- A complete short frame exercises all 56 input bits. -/
theorem short_frame_witness :
    Impl.Parity.syndrome 56 0x5D484FDEA248F5 =
      Spec.Parity.syndrome 56 0x5D484FDEA248F5 := by
  decide +kernel

/-- A complete long frame exercises both cached machine words. -/
theorem long_frame_witness :
    Impl.Parity.syndrome 112 0x8D40621D58C382D690C8AC2863A7 =
      Spec.Parity.syndrome 112 0x8D40621D58C382D690C8AC2863A7 := by
  decide +kernel

/-- Width 129 reaches the arbitrary-precision bit path above both caches. -/
theorem beyond_cache_witness :
    Impl.Parity.syndrome 129 (2^180 + 2^128 + 2^64 + 7) =
      Spec.Parity.syndrome 129 (2^180 + 2^128 + 2^64 + 7) := by
  decide +kernel

/-- Bits above the chosen width do not enter the recurrence. -/
theorem overwide_word_witness :
    Impl.Parity.syndrome 7 (2^256 + 0x65) =
      Impl.Parity.syndrome 7 0x65 := by
  decide +kernel

#print axioms wordStep_eq
#print axioms step_eq
#print axioms fold_range
#print axioms syndrome_eq
#print axioms high_state_witness
#print axioms feedback_state_witness
#print axioms zero_width_witness
#print axioms short_frame_witness
#print axioms long_frame_witness
#print axioms beyond_cache_witness
#print axioms overwide_word_witness

end Lean1090.Proofs.ParityWord

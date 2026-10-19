import Capstones

/-!
# Universal XOR linearity of the reference parity recurrence

The arithmetic append step is proved equal to a shift and two conditional XOR
terms. Bit-vector identities prove its linearity; induction then lifts it to
arbitrary list lengths, input words and initial remainders. No finite-width
input enumeration or executable proof oracle is needed.
-/

namespace Lean1090.Proofs
open Spec
/-- Appending a bit shifts the previous remainder and inserts its low bit. -/
private theorem appendBit (remainder : BitVec 24) (bit : Bool) :
    BitVec.ofNat 24 (2 * remainder.toNat + if bit then 1 else 0) =
      (remainder <<< 1) ^^^ (if bit then 1 else 0) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  rw [BitVec.getLsbD_ofNat, BitVec.getLsbD_xor, BitVec.getLsbD_shiftLeft]
  have hsmall : (if bit then 1 else 0 : Nat) < 2 ^ 1 := by cases bit <;> decide
  rw [show (2 : Nat) = 2 ^ 1 from rfl, Nat.testBit_two_pow_mul_add _ hsmall]
  cases i with
  | zero => cases bit <;> simp
  | succ i =>
    cases bit <;> simp [hi, BitVec.testBit_toNat]

theorem parity_step_eq (remainder : BitVec 24) (bit : Bool) :
    Parity.step remainder bit =
      ((remainder <<< 1) ^^^ (if bit then 1 else 0)) ^^^
        (if remainder.msb then BitVec.ofNat 24 Parity.generator else 0) := by
  by_cases high : 2 ^ 23 ≤ remainder.toNat
  · simp only [Parity.step, high, ↓reduceIte, BitVec.ofNat_xor]
    rw [appendBit]
    norm_num at high
    simp [BitVec.msb_eq_decide, high]
  · simp only [Parity.step, high, ↓reduceIte]
    rw [appendBit]
    norm_num at high
    simp [BitVec.msb_eq_decide, Nat.not_le_of_lt high]

private theorem xor_select (value : BitVec 24) (a b : Bool) :
    (if a ^^ b then value else 0) =
      (if a then value else 0) ^^^ (if b then value else 0) := by
  cases a <;> cases b <;> simp

private theorem step_linear (a b : BitVec 24) (x y : Bool) :
    Parity.step (a ^^^ b) (x ^^ y) = Parity.step a x ^^^ Parity.step b y := by
  simp only [parity_step_eq, BitVec.shiftLeft_xor_distrib, BitVec.msb_xor, xor_select]
  ac_rfl

private theorem fold_linear (width a b : Nat) (indices : List Nat) (r s : BitVec 24) :
    indices.foldl (fun rem i => Parity.step rem ((a ^^^ b).testBit (width - 1 - i)))
        (r ^^^ s) =
      indices.foldl (fun rem i => Parity.step rem (a.testBit (width - 1 - i))) r ^^^
      indices.foldl (fun rem i => Parity.step rem (b.testBit (width - 1 - i))) s := by
  induction indices generalizing r s with
  | nil => rfl
  | cons index indices ih =>
    simp only [List.foldl_cons, Nat.testBit_xor, step_linear]
    simpa only [Nat.testBit_xor] using ih
      (Parity.step r (a.testBit (width - 1 - index)))
      (Parity.step s (b.testBit (width - 1 - index)))

/-- The exact frozen linearity contract, for every width and pair of Nat words. -/
theorem CRCLinear : Capstones.CRCLinear := by
  intro width a b
  exact fold_linear width a b (List.range width) 0 0

#print axioms CRCLinear
end Lean1090.Proofs

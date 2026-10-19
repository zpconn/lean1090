import Proofs.ParityLinear

/-!
# AP/PI parity overlay recovery

A bounded word of at most 24 bits is unchanged by the recurrence; leading
zero bits preserve its result. Nonoverlapping information/parity fields add
as XOR, so the previously proved universal linearity cancels the checksum
and recovers exactly the transmitted overlay. The helper lemmas are general
in their widths and inputs and may also support polynomial refinement.
-/

namespace Lean1090.Proofs.ParityFacts
open Spec

theorem fold_congr_on {α β : Type} (indices : List α) (f g : β → α → β)
    (same : ∀ index ∈ indices, ∀ initial, f initial index = g initial index)
    (initial : β) : indices.foldl f initial = indices.foldl g initial := by
  induction indices generalizing initial with
  | nil => rfl
  | cons index indices ih =>
    simp only [List.foldl_cons]
    rw [same index (by simp)]
    exact ih (fun j hj => same j (by simp [hj])) _

theorem syndrome_succ (width word : Nat) :
    Parity.syndrome (width + 1) word =
      Parity.step (Parity.syndrome width (word / 2)) (word.testBit 0) := by
  unfold Parity.syndrome
  rw [List.range_succ, List.foldl_append]
  simp only [List.foldl_cons, List.foldl_nil, Nat.add_sub_cancel, Nat.sub_self]
  congr 1
  apply fold_congr_on
  intro i hi remainder
  rw [Nat.testBit_div_two]
  congr 2
  have hi := List.mem_range.mp hi
  omega

theorem syndrome_small (width word : Nat) (hw : width ≤ 24) (bound : word < 2 ^ width) :
    Parity.syndrome width word = BitVec.ofNat 24 word := by
  induction width generalizing word with
  | zero =>
    have : word = 0 := by simpa using bound
    subst word
    rfl
  | succ width ih =>
    have bound24 : word < 2 ^ 24 := lt_of_lt_of_le bound (Nat.pow_le_pow_right (by decide) hw)
    have small : word / 2 < 2 ^ width := by
      rw [Nat.pow_succ] at bound
      omega
    rw [syndrome_succ, ih (word / 2) (by omega) small]
    have half24 : word / 2 < 2 ^ 24 := by omega
    have half23 : ¬ 2 ^ 23 ≤ word / 2 := by norm_num at bound24 ⊢; omega
    simp only [Parity.step, BitVec.toNat_ofNat, Nat.mod_eq_of_lt half24, half23, ↓reduceIte]
    congr 1
    rw [Nat.testBit_zero]
    by_cases parity : word % 2 = 1 <;> simp [parity] <;> omega
end Lean1090.Proofs.ParityFacts

namespace Lean1090.Proofs.ParityFacts
open Spec

theorem syndrome_leading_zero (width word : Nat) (bound : word < 2 ^ width) :
    Parity.syndrome (width + 1) word = Parity.syndrome width word := by
  unfold Parity.syndrome
  rw [List.range_succ_eq_map]
  simp only [List.foldl_cons, List.foldl_map, Nat.add_sub_cancel, Nat.sub_zero,
    Nat.testBit_lt_two_pow bound]
  change (List.range width).foldl
    (fun rem i => Parity.step rem (word.testBit (width - (i + 1)))) 0 = _
  apply fold_congr_on
  intro i _ remainder
  congr 2
  omega

theorem syndrome_low_word (padding word : Nat) (bound : word < 2 ^ 24) :
    Parity.syndrome (24 + padding) word = BitVec.ofNat 24 word := by
  induction padding with
  | zero => exact syndrome_small 24 word (by decide) bound
  | succ padding ih =>
    rw [show 24 + (padding + 1) = (24 + padding) + 1 from rfl,
      syndrome_leading_zero _ _ (lt_of_lt_of_le bound (Nat.pow_le_pow_right (by decide) (by omega)))]
    exact ih

theorem disjoint_append_xor (width high low : Nat) (bound : low < 2 ^ width) :
    high * 2 ^ width + low = (high * 2 ^ width) ^^^ low := by
  apply Nat.eq_of_testBit_eq
  intro i
  rw [Nat.mul_comm high, Nat.testBit_two_pow_mul_add high bound,
    Nat.testBit_xor, Nat.testBit_two_pow_mul]
  by_cases below : i < width
  · simp [below, Nat.not_le_of_lt below]
  · have small : low < 2 ^ i :=
      lt_of_lt_of_le bound (Nat.pow_le_pow_right (by decide) (by omega))
    simp [below, Nat.testBit_lt_two_pow small, show width ≤ i by omega]

end Lean1090.Proofs.ParityFacts

namespace Lean1090.Proofs
open Spec

/-- The transmitted overlay is recovered exactly, for every information field. -/
theorem ParityOverlay : Capstones.ParityOverlay := by
  intro width _ information _ address
  rw [ParityFacts.disjoint_append_xor 24 information
    (Parity.overlay width information address).toNat
    (Parity.overlay width information address).isLt]
  rw [CRCLinear]
  have low := ParityFacts.syndrome_low_word width
    (Parity.overlay width information address).toNat
    (Parity.overlay width information address).isLt
  rw [Nat.add_comm 24 width] at low
  rw [low, BitVec.ofNat_toNat]
  change Parity.checksum width information ^^^
    (Parity.checksum width information ^^^ address) = address
  simp [← BitVec.xor_assoc]

#print axioms ParityOverlay
end Lean1090.Proofs

import Capstones

/-!
# Finite single-bit parity guarantee

The kernel computes every syndrome once in a finite list for each supported
frame width. Nonzero membership and list distinctness imply the exact frozen
single-bit capstone for arbitrary bit indices.
-/

set_option maxRecDepth 100000
set_option maxHeartbeats 0

namespace Lean1090.Proofs
open Spec

private def bitSyndromes (width : Nat) : List (BitVec 24) :=
  List.ofFn fun i : Fin width => Parity.syndrome width (2 ^ i.val)

private theorem bits56 :
    0 ∉ bitSyndromes 56 ∧ (bitSyndromes 56).Nodup := by
  decide +kernel

private theorem bits112 :
    0 ∉ bitSyndromes 112 ∧ (bitSyndromes 112).Nodup := by
  decide +kernel

private theorem singleBit_of_list (width : Nat)
    (nonzero : 0 ∉ bitSyndromes width)
    (distinct : (bitSyndromes width).Nodup) :
    (∀ i : Fin width, Parity.syndrome width (2 ^ i.val) ≠ 0) ∧
    (∀ i j : Fin width,
      Parity.syndrome width (2 ^ i.val) = Parity.syndrome width (2 ^ j.val) → i = j) := by
  constructor
  · intro i zero
    apply nonzero
    exact List.mem_ofFn.mpr ⟨i, zero⟩
  · exact List.nodup_ofFn.mp distinct

/-- All single-bit errors have distinct nonzero syndromes, at both frame widths. -/
theorem CRCSingleBit : Capstones.CRCSingleBit := by
  intro width admissible
  rcases admissible with rfl | rfl
  · exact singleBit_of_list 56 bits56.1 bits56.2
  · exact singleBit_of_list 112 bits112.1 bits112.2

#print axioms CRCSingleBit

end Lean1090.Proofs

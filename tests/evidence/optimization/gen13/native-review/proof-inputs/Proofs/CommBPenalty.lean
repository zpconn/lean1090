import Impl.CommB
import Proofs.AffineValue
import Mathlib.Tactic.Ring

/-!
The BDS50 wind table covers every possible signed difference of its two
ten-bit speed codes. It preserves all three software-binary64 rounds and
both independent status checks, without assuming a valid or bounded payload.
-/

namespace Lean1090.Proofs.CommBPenalty

set_option maxHeartbeats 2000000
set_option maxRecDepth 4000

theorem table_size : Impl.cbWindPenaltyTable.size = 2047 := by
  simp [Impl.cbWindPenaltyTable]

theorem table_get (code : Fin 2047) :
    Impl.cbWindPenaltyTable[code.val]'(by simp [table_size]) =
      Impl.Binary64.sub 0
        (Impl.Binary64.div (Impl.Binary64.round (2 * ((code.val : Rat) - 1023))).abs 100) := by
  simp [Impl.cbWindPenaltyTable]

/-- Ten-bit code bounds justify the subtraction before casting the table index. -/
theorem signed_index (tas gs : Nat) (ht : tas < 1024) (hg : gs < 1024) :
    tas + 1023 - gs < 2047 ∧
    2 * (((tas + 1023 - gs : Nat) : Rat) - 1023) =
      (tas : Rat) * 2 - (gs : Rat) * 2 := by
  constructor
  · omega
  · rw [Nat.cast_sub (show gs ≤ tas + 1023 by omega), Nat.cast_add]
    norm_num
    ring

/-- Direct raw-field formula, including independently missing speed statuses. -/
theorem cbWindPenalty50_eq_raw (word : Nat) :
    Impl.cbWindPenalty50 word =
      if Impl.payloadBits word 46 1 == 0 || Impl.payloadBits word 24 1 == 0 then 0
      else Impl.Binary64.sub 0
        (Impl.Binary64.div (Impl.Binary64.sub
          ((Impl.payloadBits word 47 10 : Rat) * 2)
          ((Impl.payloadBits word 25 10 : Rat) * 2)).abs 100) := by
  have ht : Impl.payloadBits word 47 10 < 1024 := Impl.payloadBits_lt word 47 10
  have hg : Impl.payloadBits word 25 10 < 1024 := Impl.payloadBits_lt word 25 10
  have index := (signed_index _ _ ht hg).2
  simp only [Impl.cbWindPenalty50, Impl.cbWindPenaltyTable, Array.getElem_ofFn]
  split
  · rfl
  · rw [index]
    rfl

/-- The live table equals the old semantic-field match on every natural word. -/
theorem cbWindPenalty50_eq_runtime (word : Nat) :
    Impl.cbWindPenalty50 word =
      match Impl.commBValue 0x50 word "TAS", Impl.commBValue 0x50 word "groundspeed" with
      | some tas, some gs =>
        Impl.Binary64.sub 0 (Impl.Binary64.div (Impl.Binary64.sub tas gs).abs 100)
      | _, _ => 0 := by
  rw [cbWindPenalty50_eq_raw]
  simp [Impl.commBValue, Impl.commBLayout, Impl.bds50Layout, Impl.cbColumn,
    Impl.payloadValue, AffineValue.affineValue_eq, Impl.payloadInteger]
  by_cases ht : Impl.payloadBits word 46 1 = 0 <;>
    by_cases hg : Impl.payloadBits word 24 1 = 0 <;> simp_all

/-- Both absent statuses suppress the penalty even for nonzero speed bits. -/
theorem missing_both_witness : Impl.cbWindPenalty50 1023 = 0 := by
  rw [cbWindPenalty50_eq_raw]
  decide +kernel

/-- Either unavailable speed independently suppresses the penalty. -/
theorem missing_one_witness :
    Impl.cbWindPenalty50 (2^10 + 1023) = 0 ∧
    Impl.cbWindPenalty50 (2^32 + 1023 * 2^22) = 0 := by
  simp only [cbWindPenalty50_eq_raw]
  decide +kernel

/-- Equal speeds select the central zero-difference entry. -/
theorem equal_witness :
    Impl.cbWindPenalty50 (2^32 + 341 * 2^22 + 2^10 + 341) = 0 := by
  rw [cbWindPenalty50_eq_raw]
  decide +kernel

/-- Adjacent speed codes retain nonexact binary64 division, not rational 1/50. -/
theorem fractional_witness :
    Impl.cbWindPenalty50 (2^32 + 2^10 + 1) < 0 ∧
    Impl.cbWindPenalty50 (2^32 + 2^10 + 1) ≠ (-1 / 50 : Rat) := by
  simp only [cbWindPenalty50_eq_raw]
  decide +kernel

/-- Both signed endpoints retain the complete rounded 2046-knot penalty. -/
theorem extremes_witness :
    Impl.cbWindPenalty50 (2^32 + 2^10 + 1023) =
      Impl.Binary64.sub 0 (Impl.Binary64.div 2046 100) ∧
    Impl.cbWindPenalty50 (2^32 + 1023 * 2^22 + 2^10) =
      Impl.Binary64.sub 0 (Impl.Binary64.div 2046 100) := by
  simp only [cbWindPenalty50_eq_raw]
  decide +kernel

/-- Extra high bits do not affect either extreme's field extraction. -/
theorem overwide_witness :
    Impl.cbWindPenalty50 (2^130 + 2^32 + 2^10 + 1023) =
      Impl.cbWindPenalty50 (2^32 + 2^10 + 1023) := by
  simp only [cbWindPenalty50_eq_raw]
  decide +kernel

#print axioms table_size
#print axioms table_get
#print axioms signed_index
#print axioms cbWindPenalty50_eq_raw
#print axioms cbWindPenalty50_eq_runtime
#print axioms missing_both_witness
#print axioms missing_one_witness
#print axioms equal_witness
#print axioms fractional_witness
#print axioms extremes_witness
#print axioms overwide_witness

end Lean1090.Proofs.CommBPenalty

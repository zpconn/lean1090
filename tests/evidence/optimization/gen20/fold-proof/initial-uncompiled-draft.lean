import Init.Data.Nat.Fold

/-! Regroup an ascending fold into consecutive blocks without changing order. -/
namespace Lean1090.Proofs.FoldBlocks

/-- Consecutive blocks visit exactly the indices of the flat fold, in the same
order. The accumulator and transition are arbitrary; neither block dimension
requires a positivity assumption. -/
theorem fold_blocks {α : Type u} (blockCount blockSize : Nat)
    (f : Nat → α → α) (init : α) :
    Nat.fold (blockCount * blockSize) (fun i _ a => f i a) init =
      Nat.fold blockCount (fun i _ a =>
        Nat.fold blockSize (fun j _ b => f (i * blockSize + j) b) a) init := by
  induction blockCount with
  | zero => rfl
  | succ count ih =>
    rw [Nat.succ_mul, Nat.fold_add, Nat.fold_succ, ih]

/-- Decimal accumulation makes the exact index order observable: reversing
either a block or the order of blocks changes this result. -/
theorem ordered_blocks_witness :
    Nat.fold 2 (fun i _ a =>
      Nat.fold 3 (fun j _ b => 10 * b + (i * 3 + j + 1)) a) 0 = 123456 := by
  decide +kernel

/-- Empty blocks and an empty outer fold both preserve a nonzero initial value. -/
theorem empty_blocks_witness :
    Nat.fold 7 (fun i _ a => Nat.fold 0 (fun j _ b => 10 * b + i + j) a) 37 = 37 ∧
    Nat.fold 0 (fun i _ a => Nat.fold 7 (fun j _ b => 10 * b + i + j) a) 37 = 37 := by
  decide +kernel

#print axioms fold_blocks
#print axioms ordered_blocks_witness
#print axioms empty_blocks_witness

end Lean1090.Proofs.FoldBlocks

import Proofs.CPRGeometry

/-! The finite threshold table counts precisely the integers above a real
zone ratio; no transcendental approximation enters this counting argument. -/
namespace Lean1090.Proofs.CPRTableClassification
open Spec.CPR CPRGeometry

set_option maxRecDepth 100000 in
set_option maxHeartbeats 0 in
theorem count_check : ∀ n : Fin 58,
    59 - ((List.finRange 57).takeWhile (fun i =>
      decide ((n.val + 2 : Int) < ((59 - i.val : Nat) : Int)))).length = n.val + 2 := by
  decide +kernel

theorem count_ratio (r : ℝ) (lower : 2 ≤ r) (upper : r < 60) :
    59 - ((List.finRange 57).takeWhile (fun i =>
      decide (r < ((59 - i.val : Nat) : ℝ)))).length = Int.toNat ⌊r⌋ := by
  have jl : (2 : Int) ≤ ⌊r⌋ := (Int.le_floor).mpr (by norm_num; exact lower)
  have ju : ⌊r⌋ < (60 : Int) := (Int.floor_lt).mpr (by norm_num; exact upper)
  have j0 : 0 ≤ ⌊r⌋ := by omega
  let n : Fin 58 := ⟨Int.toNat ⌊r⌋ - 2, by omega⟩
  have n_eq : n.val + 2 = Int.toNat ⌊r⌋ := by dsimp [n]; omega
  have cast_eq : (n.val + 2 : Int) = ⌊r⌋ := by omega
  have predicates : (fun i : Fin 57 => decide (r < ((59 - i.val : Nat) : ℝ))) =
      (fun i : Fin 57 => decide ((n.val + 2 : Int) < ((59 - i.val : Nat) : Int))) := by
    funext i
    rw [cast_eq]
    congr 1
    exact propext (by simpa using (Int.floor_lt (a := r) (z := ((59 - i.val : Nat) : Int))).symm)
  rw [predicates, count_check, n_eq]

theorem length_append_failure {α : Type} (p : α → Bool) (xs : List α) (last : α)
    (reject : p last = false) :
    ((xs ++ [last]).takeWhile p).length = (xs.takeWhile p).length := by
  rw [List.takeWhile_append]
  simp only [List.takeWhile_cons, reject, Bool.false_eq_true, ↓reduceIte]
  split_ifs with complete
  · simpa using complete.symm
  · rfl

set_option maxRecDepth 100000 in
theorem table_representation : transitions =
    (List.finRange 57).map (fun i => transitions.getD i.val 0) ++ [8700000000] := by
  decide +kernel

theorem classify (x : Rat) (positive : 0 < x) (polar : x < 87)
    (r : ℝ) (lower : 2 ≤ r) (upper : r < 60)
    (comparison : ∀ i : Fin 57,
      (transitions.getD i.val 0 : Rat) / 100000000 ≤ x ↔
        r < ((59 - i.val : Nat) : ℝ)) : nlTable x = Int.toNat ⌊r⌋ := by
  have absx : absQ x = x := by rw [absQ_eq_abs, abs_of_pos positive]
  have neq : (absQ x == 87) = false := by simp [absx, ne_of_lt polar]
  unfold nlTable
  rw [neq]
  simp only [Bool.false_eq_true, ↓reduceIte, absx]
  rw [table_representation, length_append_failure]
  · rw [List.takeWhile_map, List.length_map]
    have predicate :
        ((fun t : Nat => decide ((t : Rat) / 100000000 ≤ x)) ∘
          (fun i : Fin 57 => transitions.getD i.val 0)) =
        (fun i : Fin 57 => decide (r < ((59 - i.val : Nat) : ℝ))) := by
      funext i
      simp only [Function.comp_apply]
      congr 1
      exact propext (comparison i)
    rw [predicate]
    exact count_ratio r lower upper
  · norm_num
    exact polar

end Lean1090.Proofs.CPRTableClassification

import Proofs.WireBytes

/-! Generic field concatenation and extraction facts. No fixed frame, field
value, or finite test corpus is assumed. -/
namespace Lean1090.Proofs.BitPacking
open Spec

/-- Total transmitted width of separately supplied fields. -/
def width (parts : List (Nat × Nat)) : Nat := (parts.map Prod.fst).sum

private theorem fold_pack (parts : List (Nat × Nat)) (initial : Nat) :
    parts.foldl (fun acc (w, v) => acc * 2 ^ w + v % 2 ^ w) initial =
      initial * 2 ^ width parts + packFields parts := by
  induction parts generalizing initial with
  | nil => simp [width, packFields]
  | cons part rest ih =>
    rcases part with ⟨w, v⟩
    simp only [List.foldl_cons, width, List.map_cons, List.sum_cons]
    rw [ih]
    change (initial * 2 ^ w + v % 2 ^ w) * 2 ^ width rest + packFields rest =
      initial * 2 ^ (w + width rest) +
        rest.foldl (fun acc (w, v) => acc * 2 ^ w + v % 2 ^ w) (0 * 2 ^ w + v % 2 ^ w)
    rw [ih, pow_add]
    ring

theorem pack_cons (w v : Nat) (rest : List (Nat × Nat)) :
    packFields ((w, v) :: rest) =
      v % 2 ^ w * 2 ^ width rest + packFields rest := by
  unfold packFields
  rw [List.foldl_cons, fold_pack]
  simp [packFields]

theorem width_append (left right : List (Nat × Nat)) :
    width (left ++ right) = width left + width right := by
  simp [width]

theorem pack_append (left right : List (Nat × Nat)) :
    packFields (left ++ right) =
      packFields left * 2 ^ width right + packFields right := by
  unfold packFields
  rw [List.foldl_append, fold_pack]
  rfl

theorem pack_bound (parts : List (Nat × Nat)) :
    packFields parts < 2 ^ width parts := by
  induction parts with
  | nil => simp [width, packFields]
  | cons part rest ih =>
    rcases part with ⟨w, v⟩
    rw [pack_cons]
    change v % 2 ^ w * 2 ^ width rest + packFields rest < 2 ^ (w + width rest)
    rw [pow_add]
    have bound := Nat.mod_lt v (Nat.two_pow_pos w)
    have product := Nat.mul_le_mul_right (2 ^ width rest) (show v % 2 ^ w + 1 ≤ 2 ^ w by omega)
    nlinarith

/-- Appending low bits cannot change a preceding field; preceding high bits
are removed by that field's fixed width. -/
theorem field_concatenation (high middle low trailing bits : Nat)
    (lowBound : low < 2 ^ trailing) :
    BitVec.ofNat bits (((high * 2 ^ bits + middle) * 2 ^ trailing + low) / 2 ^ trailing) =
      BitVec.ofNat bits middle := by
  apply BitVec.eq_of_toNat_eq
  simp only [BitVec.toNat_ofNat]
  rw [Nat.add_comm _ low, Nat.add_mul_div_right _ _ (Nat.two_pow_pos trailing),
    Nat.div_eq_of_lt lowBound, Nat.zero_add]
  rw [Nat.add_comm, Nat.add_mul_mod_self_right]

/-- Any column of a concatenated field sequence is extracted independently
of all preceding/following values, including zero-width adjacent fields. -/
theorem field_pack (before after : List (Nat × Nat)) (bits value : Nat) :
    field (width before + bits + width after) (width before) bits
      (packFields (before ++ (bits, value) :: after)) = BitVec.ofNat bits value := by
  have widths : width before + bits + width after - width before - bits = width after := by omega
  rw [field, widths]
  have repr : packFields (before ++ (bits, value) :: after) =
      (packFields before * 2 ^ bits + value % 2 ^ bits) * 2 ^ width after + packFields after := by
    rw [pack_append, pack_cons]
    change packFields before * 2 ^ (bits + width after) +
      (value % 2 ^ bits * 2 ^ width after + packFields after) = _
    rw [pow_add]
    ring
  rw [repr, field_concatenation _ _ _ _ _ (pack_bound after)]
  apply BitVec.eq_of_toNat_eq
  simp only [BitVec.toNat_ofNat, Nat.mod_mod]

/-- Column codes read from the successive widths, MSB first. Used only in the
proof to connect the declared layouts to the independent field packer. -/
def extractParts : List Nat → Nat → List (Nat × Nat)
  | [], _ => []
  | bits :: rest, word =>
      (bits, word / 2 ^ rest.sum % 2 ^ bits) :: extractParts rest word

theorem extractParts_width (widths : List Nat) (word : Nat) :
    width (extractParts widths word) = widths.sum := by
  induction widths with
  | nil => rfl
  | cons bits rest ih => simpa [extractParts, width] using congrArg (bits + ·) ih

/-- Rejoining every contiguous column reproduces every defined bit. -/
theorem pack_extractParts (widths : List Nat) (word : Nat) :
    packFields (extractParts widths word) = word % 2 ^ widths.sum := by
  induction widths with
  | nil =>
    change 0 = word % 1
    exact (Nat.mod_one word).symm
  | cons bits rest ih =>
    rw [extractParts, pack_cons, extractParts_width, ih]
    simp only [Nat.mod_mod, List.sum_cons]
    rw [Nat.add_comm bits, pow_add, Nat.mod_mul]
    ring

#print axioms field_pack
end Lean1090.Proofs.BitPacking

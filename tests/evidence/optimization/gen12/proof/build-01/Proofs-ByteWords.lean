import Impl.Bits
import Proofs.WireBytes

/-! Exact machine-word byte folds and the public all-list refinement.
The intermediate modulo theorem has no length premise. Only the bounded
branches discard the modulo, using the independent reference byte bound. -/
namespace Lean1090.Proofs.ByteWords

private theorem byte_cast (byte : UInt8) :
    UInt64.ofNat byte.toNat = byte.toUInt64 := by
  simpa only [UInt8.toNat_toUInt64] using
    (UInt64.ofNat_toNat (x := byte.toUInt64))

/-- Casting commutes with the complete byte fold, including overflowing lists. -/
theorem fold_word (bytes : List UInt8) (initial : Nat) :
    bytes.foldl (fun word byte => 256 * word + byte.toUInt64) (UInt64.ofNat initial) =
      UInt64.ofNat (bytes.foldl (fun n byte => 256 * n + byte.toNat) initial) := by
  apply List.foldl_hom UInt64.ofNat
  intro n byte
  simp only [UInt64.ofNat_add, UInt64.ofNat_mul, byte_cast]
  rfl

/-- The word fold is the reference value modulo 2^64 for every list. -/
theorem bytesWord_eq (bytes : List UInt8) :
    Impl.bytesWord bytes = UInt64.ofNat (Spec.bytesValue bytes) := by
  exact fold_word bytes 0

/-- A prefix of at most eight bytes fits without wraparound. -/
theorem bytesWord_toNat (bytes : List UInt8) (small : bytes.length ≤ 8) :
    (Impl.bytesWord bytes).toNat = Spec.bytesValue bytes := by
  rw [bytesWord_eq, UInt64.toNat_ofNat']
  apply Nat.mod_eq_of_lt
  exact Nat.lt_of_lt_of_le (WireBytes.bytesValue_lt bytes) (by
    calc
      256 ^ bytes.length ≤ 256 ^ 8 := Nat.pow_le_pow_right (by decide) small
      _ = 2 ^ 64 := by decide)

/-- The prefix worker returns the existing suffix and the exact modular fold. -/
theorem bytesWordPrefix_eq (count : Nat) (bytes : List UInt8) (initial : UInt64) :
    Impl.bytesWordPrefix count bytes initial =
      ((bytes.take count).foldl (fun word byte => 256 * word + byte.toUInt64) initial,
        bytes.drop count) := by
  induction count generalizing bytes initial with
  | zero => simp [Impl.bytesWordPrefix]
  | succ count ih =>
    cases bytes with
    | nil => simp [Impl.bytesWordPrefix]
    | cons byte rest => simpa [Impl.bytesWordPrefix] using ih rest (256 * initial + byte.toUInt64)

private theorem fold_bytes (bytes : List UInt8) (initial : Nat) :
    bytes.foldl (fun n byte => 256 * n + byte.toNat) initial =
      initial * 256 ^ bytes.length + Spec.bytesValue bytes := by
  induction bytes generalizing initial with
  | nil => simp [Spec.bytesValue]
  | cons byte rest ih =>
    simp only [List.foldl_cons, List.length_cons, pow_succ]
    rw [ih]
    change (256 * initial + byte.toNat) * 256 ^ rest.length + Spec.bytesValue rest =
      initial * (256 ^ rest.length * 256) +
        rest.foldl (fun n byte => 256 * n + byte.toNat) (256 * 0 + byte.toNat)
    rw [ih]
    ring

/-- Concatenating byte strings is exact radix-256 concatenation. -/
theorem bytesValue_append (left right : List UInt8) :
    Spec.bytesValue (left ++ right) =
      Spec.bytesValue left * 256 ^ right.length + Spec.bytesValue right := by
  unfold Spec.bytesValue
  rw [List.foldl_append, fold_bytes]
  rfl

/-- Universal public refinement: no validity or length premise. -/
theorem bytesValue_eq (bytes : List UInt8) :
    Impl.bytesValue bytes = Spec.bytesValue bytes := by
  unfold Impl.bytesValue
  split
  · exact bytesWord_toNat bytes (by assumption)
  · split
    · rename_i short medium
      rw [bytesWordPrefix_eq]
      change ((Impl.bytesWord (bytes.take 8)).toNat <<< (8 * (bytes.length - 8))) +
        (Impl.bytesWord (bytes.drop 8)).toNat = Spec.bytesValue bytes
      rw [bytesWord_toNat (bytes.take 8) (by simp),
        bytesWord_toNat (bytes.drop 8) (by simp only [List.length_drop]; omega)]
      rw [Nat.shiftLeft_eq, Nat.mul_comm 8 (bytes.length - 8), ← WireBytes.byte_radix]
      simpa only [List.take_append_drop, List.length_drop] using
        (bytesValue_append (bytes.take 8) (bytes.drop 8)).symm
    · rfl

/-- Empty input exercises the one-word branch at zero length. -/
theorem empty_witness : Impl.bytesValue [] = 0 := by decide
/-- A seven-byte maximum is still represented exactly. -/
theorem seven_witness : Impl.bytesValue (List.replicate 7 (255 : UInt8)) = 2 ^ 56 - 1 := by decide
/-- The full UInt64 maximum must not wrap at eight bytes. -/
theorem eight_witness : Impl.bytesValue (List.replicate 8 (255 : UInt8)) = 2 ^ 64 - 1 := by decide
/-- The ninth byte crosses the machine-word boundary. -/
theorem nine_witness : Impl.bytesValue ((1 : UInt8) :: List.replicate 8 0) = 2 ^ 64 := by decide
/-- A long Mode S frame retains every bit. -/
theorem fourteen_witness : Impl.bytesValue (List.replicate 14 (255 : UInt8)) = 2 ^ 112 - 1 := by decide
/-- Sixteen bytes use two complete words and an unbounded final combination. -/
theorem sixteen_witness : Impl.bytesValue (List.replicate 16 (255 : UInt8)) = 2 ^ 128 - 1 := by decide
/-- Longer arbitrary inputs retain the original unbounded fold. -/
theorem fallback_witness : Impl.bytesValue ((1 : UInt8) :: List.replicate 16 0) = 2 ^ 128 := by decide

#print axioms bytesWord_eq
#print axioms bytesWord_toNat
#print axioms bytesWordPrefix_eq
#print axioms bytesValue_eq
#print axioms empty_witness
#print axioms seven_witness
#print axioms eight_witness
#print axioms nine_witness
#print axioms fourteen_witness
#print axioms sixteen_witness
#print axioms fallback_witness
end Lean1090.Proofs.ByteWords

import Capstones
import Mathlib.Tactic.Ring

/-! Generic byte-order facts used by the structural frame round-trip proof.
These prove the independently defined base-256 encoder/decoder inverse for all
lengths and words; no fixed corpus or enumerated message field is assumed. -/
namespace Lean1090.Proofs.WireBytes
open Spec

private theorem fold_bytes (bytes : List UInt8) (initial : Nat) :
    bytes.foldl (fun n b => 256 * n + b.toNat) initial =
      initial * 256 ^ bytes.length + bytesValue bytes := by
  induction bytes generalizing initial with
  | nil => simp [bytesValue]
  | cons b bs ih =>
    simp only [List.foldl_cons, List.length_cons, pow_succ]
    rw [ih]
    change (256 * initial + b.toNat) * 256 ^ bs.length + bytesValue bs =
      initial * (256 ^ bs.length * 256) +
        bs.foldl (fun n b => 256 * n + b.toNat) (256 * 0 + b.toNat)
    rw [ih]
    ring

theorem bytesValue_cons (b : UInt8) (bs : List UInt8) :
    bytesValue (b :: bs) = b.toNat * 256 ^ bs.length + bytesValue bs := by
  unfold bytesValue
  rw [List.foldl_cons, fold_bytes]
  simp [bytesValue]

theorem valueBytes_length (count word : Nat) :
    (valueBytes count word).length = count := by
  simp [valueBytes]

theorem valueBytes_succ (count word : Nat) :
    valueBytes (count + 1) word =
      UInt8.ofNat (word / 256 ^ count) :: valueBytes count word := by
  unfold valueBytes
  rw [List.range_succ_eq_map, List.map_cons, List.map_map]
  congr 1
  apply List.map_congr_left
  intro i _
  have indices : count - (i + 1) = count - 1 - i := by omega
  change UInt8.ofNat (word / 256 ^ (count - (i + 1))) =
    UInt8.ofNat (word / 256 ^ (count - 1 - i))
  rw [indices]

/-- The transmitted leading byte, with the independently specified MSB order. -/
theorem valueBytes_head (count word : Nat) (positive : 0 < count) :
    (valueBytes count word).head? =
      some (UInt8.ofNat (word / 256 ^ (count - 1))) := by
  cases count with
  | zero => omega
  | succ count => rw [valueBytes_succ]; rfl

theorem bytesValue_valueBytes (count word : Nat) :
    bytesValue (valueBytes count word) = word % 256 ^ count := by
  induction count with
  | zero =>
    change 0 = word % 1
    exact (Nat.mod_one word).symm
  | succ count ih =>
    rw [valueBytes_succ, bytesValue_cons, valueBytes_length, ih]
    simp only [UInt8.toNat_ofNat', Nat.reducePow]
    rw [pow_succ, Nat.mod_mul]
    ring

theorem bytesValue_lt (bytes : List UInt8) :
    bytesValue bytes < 256 ^ bytes.length := by
  induction bytes with
  | nil => simp [bytesValue]
  | cons b bs ih =>
    rw [bytesValue_cons, List.length_cons, pow_succ]
    have bounded : b.toNat + 1 ≤ 256 := by
      have boundedByte := b.toNat_lt_size
      change b.toNat < 256 at boundedByte
      omega
    have product := Nat.mul_le_mul_right (256 ^ bs.length) bounded
    nlinarith

private theorem bytesValue_head (b : UInt8) (bs : List UInt8) :
    bytesValue (b :: bs) / 256 ^ bs.length = b.toNat := by
  rw [bytesValue_cons, Nat.add_comm, Nat.add_mul_div_right _ _ (by positivity)]
  simp [Nat.div_eq_of_lt (bytesValue_lt bs)]

private theorem bytesValue_tail (b : UInt8) (bs : List UInt8) :
    bytesValue (b :: bs) % 256 ^ bs.length = bytesValue bs := by
  rw [bytesValue_cons, Nat.add_comm, Nat.add_mul_mod_self_right]
  exact Nat.mod_eq_of_lt (bytesValue_lt bs)

theorem bytesValue_injective {xs ys : List UInt8} (sameLength : xs.length = ys.length)
    (sameValue : bytesValue xs = bytesValue ys) : xs = ys := by
  induction xs generalizing ys with
  | nil => simpa using sameLength.symm
  | cons b bs ih =>
    cases ys with
    | nil => simp at sameLength
    | cons c cs =>
      have lengthTail : bs.length = cs.length := by simpa using sameLength
      have headNat : b.toNat = c.toNat := by
        rw [← bytesValue_head b bs, ← bytesValue_head c cs, lengthTail, sameValue]
      have headEq : b = c := UInt8.toNat_inj.mp headNat
      have tailValue : bytesValue bs = bytesValue cs := by
        rw [← bytesValue_tail b bs, ← bytesValue_tail c cs, lengthTail, sameValue]
      rw [headEq, ih lengthTail tailValue]

theorem valueBytes_bytesValue (bytes : List UInt8) :
    valueBytes bytes.length (bytesValue bytes) = bytes := by
  apply bytesValue_injective (valueBytes_length _ _)
  rw [bytesValue_valueBytes, Nat.mod_eq_of_lt (bytesValue_lt bytes)]

/-- A byte radix is eight wire bits, independently of message contents. -/
theorem byte_radix (count : Nat) : (256 : Nat) ^ count = 2 ^ (count * 8) := by
  rw [show (256 : Nat) = 2 ^ 8 by decide, ← pow_mul]
  congr 1
  omega

/-- The five-bit DF read from the leading byte equals the first five wire bits. -/
theorem byteHeader_field (count word : Nat) (positive : 0 < count) :
    (UInt8.ofNat (word / 256 ^ (count - 1))).toNat / 8 =
      (field (count * 8) 0 5 word).toNat := by
  rw [UInt8.toNat_ofNat', byte_radix]
  change (word / 2 ^ ((count - 1) * 8) % (8 * 32)) / 8 =
    word / 2 ^ (count * 8 - 0 - 5) % 32
  rw [Nat.mod_mul_right_div_self, Nat.div_div_eq_div_mul]
  have exponent : (count - 1) * 8 + 3 = count * 8 - 0 - 5 := by omega
  have power : 2 ^ ((count - 1) * 8) * 8 = 2 ^ (count * 8 - 0 - 5) := by
    change 2 ^ ((count - 1) * 8) * 2 ^ 3 = _
    rw [← pow_add, exponent]
  rw [power]

/-- The outer reader's DF and the mathematical word's first five bits agree. -/
theorem bytesValue_header (first : UInt8) (rest : List UInt8) :
    (field ((first :: rest).length * 8) 0 5 (bytesValue (first :: rest))).toNat =
      first.toNat / 8 := by
  rw [← byteHeader_field _ _ (by simp)]
  simp only [List.length_cons, Nat.add_sub_cancel, bytesValue_head, UInt8.ofNat_toNat]

#print axioms bytesValue_valueBytes
#print axioms valueBytes_bytesValue
end Lean1090.Proofs.WireBytes

import Impl.PayloadBits

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl
open Lean1090.Spec

/-- Fold one word in transmission order. At most eight bytes fit exactly;
longer lists retain the usual UInt64 reduction modulo 2^64. -/
@[inline] def bytesWord (bytes : List UInt8) : UInt64 :=
  bytes.foldl (fun word byte => 256 * word + byte.toUInt64) 0

/-- Consume a prefix without copying its list nodes. The recursive call returns
directly; only the endpoint constructs the accumulated word/suffix pair. -/
def bytesWordPrefix : Nat → List UInt8 → UInt64 → UInt64 × List UInt8
  | 0, bytes, word => (word, bytes)
  | _ + 1, [], word => (word, [])
  | count + 1, byte :: rest, word =>
      bytesWordPrefix count rest (256 * word + byte.toUInt64)

-- Initial algorithm: Spec/Bits.lean:13.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: fold bytes in transmission order.
Up to sixteen bytes use exact UInt64 chunks followed by one Nat combination.
Arbitrary longer lists use the original unbounded fold. -/
def bytesValue (bytes : List UInt8) : Nat :=
  let count := bytes.length
  if count ≤ 8 then
    (bytesWord bytes).toNat
  else if count ≤ 16 then
    let (high, rest) := bytesWordPrefix 8 bytes 0
    (high.toNat <<< (8 * (count - 8))) + (bytesWord rest).toNat
  else
    bytes.foldl (fun n b => 256 * n + b.toNat) 0

-- Initial algorithm: Spec/Bits.lean:17.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: extract a zero-based MSB-first field.
All protocol callers supply a field contained within `total` bits. The native
mask follows an arbitrary natural-number shift, so unrestricted words and
truncating position subtraction preserve the reference behavior as well. -/
def field (total start width word : Nat) : BitVec width :=
  if small : width < 64 then
    BitVec.ofNatLT (payloadWordBits (word >>> (total - start - width)).toUInt64 0 width) (by
      unfold payloadWordBits
      rw [UInt64.toNat_and, payloadWordMask_toNat width small]
      exact Nat.lt_of_le_of_lt Nat.and_le_right
        (Nat.sub_lt (Nat.two_pow_pos width) (by decide)))
  else BitVec.ofNat width (word / 2 ^ (total - start - width))

-- Initial algorithm: Spec/Bits.lean:27.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: concatenate separately supplied fields. -/
def packFields (fields : List (Nat × Nat)) : Nat :=
  fields.foldl (fun acc (width, value) => acc * 2 ^ width + value % 2 ^ width) 0

-- Initial algorithm: Spec/Bits.lean:31.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.2: DF bit 1 selects 56 or 112 bits. -/
def frameBytes (df : Nat) : Nat := if df < 16 then 7 else 14

end Lean1090.Impl

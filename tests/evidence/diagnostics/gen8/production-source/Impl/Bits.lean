import Model.Types

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl
open Lean1090.Spec

-- Initial algorithm: Spec/Bits.lean:13.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: fold bytes in transmission order. -/
def bytesValue (bytes : List UInt8) : Nat :=
  bytes.foldl (fun n b => 256 * n + b.toNat) 0

-- Initial algorithm: Spec/Bits.lean:17.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: extract a zero-based MSB-first field.
All protocol callers supply a field contained within `total` bits. -/
def field (total start width word : Nat) : BitVec width :=
  BitVec.ofNat width (word / 2 ^ (total - start - width))

-- Initial algorithm: Spec/Bits.lean:27.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: concatenate separately supplied fields. -/
def packFields (fields : List (Nat × Nat)) : Nat :=
  fields.foldl (fun acc (width, value) => acc * 2 ^ width + value % 2 ^ width) 0

-- Initial algorithm: Spec/Bits.lean:31.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.2: DF bit 1 selects 56 or 112 bits. -/
def frameBytes (df : Nat) : Nat := if df < 16 then 7 else 14

end Lean1090.Impl

import Impl.Bits

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl.Parity
open Lean1090.Spec

-- Initial algorithm: Spec/Parity.lean:16.
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: generator including leading x^24. -/
def generator : Nat := 0x1FFF409

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: one remainder update in a
machine word. Only the low 24 bits of the incoming state affect the result.
The final mask retains exactly the polynomial remainder's 24 coefficients. -/
@[inline] def wordStep (remainder : UInt32) (bit : Bool) : UInt32 :=
  let shifted := (remainder <<< 1) ||| (if bit then 1 else 0)
  let feedback := if (remainder &&& 0x800000) == 0 then 0 else 0x1FFF409
  (shifted ^^^ feedback) &&& 0xFFFFFF

-- Initial algorithm: Spec/Parity.lean:19.
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: multiply the remainder by x,
append one coefficient, then cancel x^24 when present. The public bit-vector
API delegates to the same machine-word update used by the complete CRC. -/
def step (remainder : BitVec 24) (bit : Bool) : BitVec 24 :=
  BitVec.ofNat 24 (wordStep remainder.toNat.toUInt32 bit).toNat

/-- Extract a bit from a machine word. Callers use an index below 64. -/
@[inline] def wordBit (word : UInt64) (i : Nat) : Bool :=
  ((word >>> i.toUInt64) &&& 1) == 1

/-- Read cached low/high words for the first 128 bits. The original natural
number supplies higher bits, preserving the unrestricted input domain. -/
@[inline] def cachedBit (word : Nat) (low high : UInt64) (i : Nat) : Bool :=
  if i < 64 then wordBit low i
  else if i < 128 then wordBit high (i - 64)
  else word.testBit i

-- Initial algorithm: Spec/Parity.lean:25.
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: receiver remainder of the full
word, with no initial/final complement and no extra trailing zero bits.
The specialized natural-number fold uses a tail-recursive native loop with
a machine-word remainder, avoiding a temporary list of bit indices. Widths
and words remain unrestricted; indices beyond the cache use `cachedBit`'s
original arbitrary-precision path. -/
def syndrome (width word : Nat) : BitVec 24 :=
  let low := word.toUInt64
  let high := (word >>> 64).toUInt64
  let remainder := width.fold
    (fun i _ rem => wordStep rem (cachedBit word low high (width - 1 - i))) 0
  BitVec.ofNat 24 remainder.toNat

-- Initial algorithm: Spec/Parity.lean:31.
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: sender appends 24 zero bits. -/
def checksum (informationWidth information : Nat) : BitVec 24 :=
  syndrome (informationWidth + 24) (information * 2^24)

-- Initial algorithm: Spec/Parity.lean:61.
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.2: recover CL/IC only when
the remaining seventeen syndrome bits are zero; this does not establish
which interrogator actually transmitted a possibly corrupted message. -/
def interrogator (s : BitVec 24) : Option (BitVec 3 × BitVec 4) :=
  if s.toNat < 128 then
    some (BitVec.ofNat 3 (s.toNat / 16), BitVec.ofNat 4 s.toNat)
  else none

end Lean1090.Impl.Parity

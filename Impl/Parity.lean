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

-- Initial algorithm: Spec/Parity.lean:19.
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: multiply the remainder by x,
append one coefficient, then cancel x^24 when present. -/
def step (remainder : BitVec 24) (bit : Bool) : BitVec 24 :=
  let shifted := 2 * remainder.toNat + if bit then 1 else 0
  BitVec.ofNat 24 (if remainder.toNat ≥ 2^23 then shifted ^^^ generator else shifted)

-- Initial algorithm: Spec/Parity.lean:25.
/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: receiver remainder of the full
word, with no initial/final complement and no extra trailing zero bits. -/
def syndrome (width word : Nat) : BitVec 24 :=
  (List.range width).foldl
    (fun rem i => step rem (word.testBit (width - 1 - i))) 0

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

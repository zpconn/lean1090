import Spec.Bits
import Mathlib.Algebra.Polynomial.Div
import Mathlib.Data.ZMod.Basic

/-!
# Mode S parity

Reference source: ICAO Annex 10 IV, fourth edition, §3.1.2.3.3.1.2
(polynomial), §3.1.2.3.3.2 and §3.1.2.3.3.2.2 (downlink overlay).
The shift-register recurrence and GF(2)[X] remainder below are separate
definitions, so their proposed equality is a substantive obligation.
-/

namespace Lean1090.Spec.Parity

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: generator including leading x^24. -/
def generator : Nat := 0x1FFF409

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: multiply the remainder by x,
append one coefficient, then cancel x^24 when present. -/
def step (remainder : BitVec 24) (bit : Bool) : BitVec 24 :=
  let shifted := 2 * remainder.toNat + if bit then 1 else 0
  BitVec.ofNat 24 (if remainder.toNat ≥ 2^23 then shifted ^^^ generator else shifted)

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: receiver remainder of the full
word, with no initial/final complement and no extra trailing zero bits. -/
def syndrome (width word : Nat) : BitVec 24 :=
  (List.range width).foldl
    (fun rem i => step rem (word.testBit (width - 1 - i))) 0

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: sender appends 24 zero bits. -/
def checksum (informationWidth information : Nat) : BitVec 24 :=
  syndrome (informationWidth + 24) (information * 2^24)

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: a wire word as a polynomial
over GF(2); LSB bit i is the coefficient of X^i. -/
noncomputable def polynomial (width word : Nat) : Polynomial (ZMod 2) :=
  (List.range width).foldl
    (fun p i => p + Polynomial.monomial i (if word.testBit i then 1 else 0)) 0

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: independently state G(X)
using its published list of powers, not the recurrence's integer constant. -/
noncomputable def generatorPolynomial : Polynomial (ZMod 2) :=
  [0, 3, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24].foldl
    (fun p i => p + Polynomial.monomial i 1) 0

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.1.2: mathematical polynomial division. -/
noncomputable def polynomialRemainder (width word : Nat) : Polynomial (ZMod 2) :=
  (polynomial width word).modByMonic generatorPolynomial

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.2.2: XOR sender parity with
the 24-bit address, or with the CL/IC overlay for DF11. -/
def overlay (informationWidth information : Nat) (address : BitVec 24) : BitVec 24 :=
  checksum informationWidth information ^^^ address

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.2: DF11's CL occupies the next
three bits after seventeen zero bits; IC occupies the final four. -/
def interrogatorOverlay (cl : BitVec 3) (ic : BitVec 4) : BitVec 24 :=
  BitVec.ofNat 24 (16 * cl.toNat + ic.toNat)

/-- Annex 10 IV (4th ed.), §3.1.2.3.3.2: recover CL/IC only when
the remaining seventeen syndrome bits are zero; this does not establish
which interrogator actually transmitted a possibly corrupted message. -/
def interrogator (s : BitVec 24) : Option (BitVec 3 × BitVec 4) :=
  if s.toNat < 128 then
    some (BitVec.ofNat 3 (s.toNat / 16), BitVec.ofNat 4 s.toNat)
  else none

end Lean1090.Spec.Parity

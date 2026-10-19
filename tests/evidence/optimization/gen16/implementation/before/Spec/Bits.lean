import Std

/-!
# Wire bit order

ICAO Annex 10, Volume IV, fourth edition (July 2007), §3.1.2.3.1.3
and §3.1.2.3.2: the first transmitted bit is most significant. Acquisition
details for the consulted edition are recorded in `docs/SOURCES.md`.
-/

namespace Lean1090.Spec

/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: fold bytes in transmission order. -/
def bytesValue (bytes : List UInt8) : Nat :=
  bytes.foldl (fun n b => 256 * n + b.toNat) 0

/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: extract a zero-based MSB-first field.
All protocol callers supply a field contained within `total` bits. -/
def field (total start width word : Nat) : BitVec width :=
  BitVec.ofNat width (word / 2 ^ (total - start - width))

/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: independently serialize a fixed
number of octets by successive powers of 256, most significant first. -/
def valueBytes (count word : Nat) : List UInt8 :=
  (List.range count).map fun i => UInt8.ofNat (word / 256 ^ (count - 1 - i))

/-- Annex 10 IV (4th ed.), §3.1.2.3.1.3: concatenate separately supplied fields. -/
def packFields (fields : List (Nat × Nat)) : Nat :=
  fields.foldl (fun acc (width, value) => acc * 2 ^ width + value % 2 ^ width) 0

/-- Annex 10 IV (4th ed.), §3.1.2.3.1.2: DF bit 1 selects 56 or 112 bits. -/
def frameBytes (df : Nat) : Nat := if df < 16 then 7 else 14

end Lean1090.Spec

import Model.Types

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl.Altitude
open Lean1090.Spec
open Lean1090.Spec.Altitude

-- Initial algorithm: Spec/Altitude.lean:19.
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”, bit permutation: select one
LSB-indexed bit. Natural shifts and masks preserve arbitrary words and indices. -/
def bit (word place : Nat) : Nat := (word >>> place) &&& 1

-- Initial algorithm: Spec/Altitude.lean:22.
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”, reflected Gray code: prefix-XOR its bits. -/
def grayDecode (width word : Nat) : Nat :=
  (List.range width).foldl
    (fun binary index => binary ^^^ (word >>> index)) 0

-- Initial algorithm: Spec/Altitude.lean:30.
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: D2 D4 A1 A2 A4 B1 B2 B4 order. -/
def gray500 (word : Nat) : Nat :=
  [2, 0, 11, 9, 7, 5, 3, 1].foldl (fun acc place => 2 * acc + bit word place) 0

-- Initial algorithm: Spec/Altitude.lean:34.
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: C1 C2 C4 order. -/
def gray100 (word : Nat) : Nat :=
  4 * bit word 12 + 2 * bit word 10 + bit word 8

-- Initial algorithm: Spec/Altitude.lean:38.
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: decoded C counts 0, 5 and 6 are invalid. -/
def validGillham (word : Nat) : Bool :=
  let c := grayDecode 3 (gray100 word)
  word < 8192 && bit word 6 == 0 && bit word 4 == 0 &&
    c != 0 && c != 5 && c != 6

-- Initial algorithm: Spec/Altitude.lean:44.
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: h=500 N500+100 N100−1300 feet,
with 7→5 remapping and reflection of N100 in odd 500-foot blocks. -/
def decodeGillham (word : Nat) : Option Int :=
  if validGillham word then
    let n500 := grayDecode 8 (gray500 word)
    let c := grayDecode 3 (gray100 word)
    let n100 := if c == 7 then 5 else c
    let n100 := if n500 % 2 == 1 then 6 - n100 else n100
    some (500 * (n500 : Int) + 100 * (n100 : Int) - 1300)
  else none

-- Initial algorithm: Spec/Altitude.lean:91.
/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: 13-bit field, including M=1 metric values,
Q=1 25-foot values, Q=0 Gillham, and unavailable all-zero encoding. -/
def decodeAC13 (word : Nat) : Option Value :=
  if word ≥ 8192 || word == 0 then none
  else if bit word 6 == 1 then
    some (.metres (word / 128 * 64 + word % 64))
  else if bit word 4 == 1 then
    let n := word / 128 * 32 + bit word 5 * 16 + word % 16
    some (.feet (25 * (n : Int) - 1000))
  else (decodeGillham word).map Value.feet

-- Initial algorithm: Spec/Altitude.lean:113.
/-- Sun, 2nd ed. (2021), ch.5 “Barometric altitude”: ADS-B omits the M bit of AC13. -/
def expandAC12 (word : Nat) : Nat := word / 64 * 128 + word % 64

-- Initial algorithm: Spec/Altitude.lean:116.
/-- Sun, 2nd ed. (2021), ch.5 “Barometric altitude”: decode a 12-bit barometric altitude field. -/
def decodeAC12 (word : Nat) : Option Int :=
  if word < 4096 then
    match decodeAC13 (expandAC12 word) with
    | some (.feet height) => some height
    | _ => none
  else none

-- Initial algorithm: Spec/Altitude.lean:129.
/-- Sun, 2nd ed. (2021), ch.5 “GNSS height”: that chapter describes a 12-bit height in metres.
This is deliberately distinct from AC12 barometric semantics; the oracle's
use of its barometric decoder for TC20–22 is a documented source conflict. -/
def decodeGNSSMetres (word : Nat) : Option Nat :=
  if word < 4096 then some word else none

-- Initial algorithm: Spec/Altitude.lean:139.
/-- Explicit rs1090-derived compatibility policy, commit 685dfaa, decode/mod.rs
`AC13Field::read`: Annex 10 IV (2007) §3.1.2.6.5.4(e) reserves M=1 rather
than specifying this overlapping bit extraction or conversion. User authorized
this fallback. Preserve the oracle's M/Q rejection and integer truncation.
The pinned gray2alt also rejects negative Gillham heights; binary25 negative
heights remain available. This is receiver policy, not standard validity. -/
def oracleAC13 (word : Nat) : Option Int :=
  if word ≥ 8192 || word == 0 then none
  else if bit word 6 == 1 then
    if bit word 4 == 1 then none
    else
      let metres := ((word &&& 0x1f80) / 4) ||| (word &&& 0x3f)
      some ((metres * 328084 / 100000 : Nat) : Int)
  else
    match decodeAC13 word with
    | some (.feet height) =>
        if bit word 4 == 0 && height < 0 then none else some height
    | _ => none

/-- Explicit rs1090-derived compatibility policy, commit 685dfaa,
decode/bds/bds05.rs `decode_ac12`, default bds-infer: >50000 feet is a
message-level rejection (outer none); unavailable/invalid height is accepted
with missing altitude (some none). Negative Gillham heights are likewise
missing; negative binary25 heights remain available. Applies to both
barometric and GNSS TC. -/
def oracleAC12 (word : Nat) : Option (Option Int) :=
  if word ≥ 4096 then none else
    match decodeAC12 word with
    | some height =>
        if bit word 4 == 0 && height < 0 then some none
        else if height > 50000 then none else some (some height)
    | none => some none

end Lean1090.Impl.Altitude

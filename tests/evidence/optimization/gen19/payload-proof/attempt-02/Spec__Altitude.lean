import Model.Types

/-!
# Altitude fields, independent reference semantics

Source: Junzi Sun, *The 1090 Megahertz Riddle*, second edition,
chapter 13, “Altitude code”, and chapter 5, “Altitude decoding”.
https://mode-s.org/1090mhz/content/mode-s/3-surveillance.html#altitude-code
https://mode-s.org/1090mhz/content/ads-b/3-airborne-position.html#altitude-decoding

All arithmetic here is exact. In particular, the Gillham encoder is the
algebraic inverse of the published Gray-code construction; it does not search
for an input on which the decoder happens to return the requested height.
The oracle's altitude plausibility filters are separate policy, not semantics.
-/

namespace Lean1090.Spec.Altitude

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”, bit permutation: select one LSB-indexed bit. -/
def bit (word place : Nat) : Nat := (word / 2 ^ place) % 2

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”, reflected Gray code: prefix-XOR its bits. -/
def grayDecode (width word : Nat) : Nat :=
  (List.range width).foldl
    (fun binary index => binary ^^^ (word / 2 ^ index)) 0

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”, inverse reflected Gray code: b XOR (b >> 1). -/
def grayEncode (binary : Nat) : Nat := binary ^^^ (binary / 2)

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: D2 D4 A1 A2 A4 B1 B2 B4 order. -/
def gray500 (word : Nat) : Nat :=
  [2, 0, 11, 9, 7, 5, 3, 1].foldl (fun acc place => 2 * acc + bit word place) 0

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: C1 C2 C4 order. -/
def gray100 (word : Nat) : Nat :=
  4 * bit word 12 + 2 * bit word 10 + bit word 8

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: decoded C counts 0, 5 and 6 are invalid. -/
def validGillham (word : Nat) : Bool :=
  let c := grayDecode 3 (gray100 word)
  word < 8192 && bit word 6 == 0 && bit word 4 == 0 &&
    c != 0 && c != 5 && c != 6

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

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: exact domain of its 8+3-bit Gillham construction. -/
def RepresentableGillham (height : Int) : Prop :=
  -1200 ≤ height ∧ height ≤ 126700 ∧ height % 100 = 0

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: place independently computed Gray symbols
into the published C1 A1 C2 A2 C4 A4 M B1 Q B2 D2 B4 D4 layout. -/
def packGillham (g500 g100 : Nat) : Nat :=
  bit g100 2 * 2^12 + bit g500 5 * 2^11 +
  bit g100 1 * 2^10 + bit g500 4 * 2^9 +
  bit g100 0 * 2^8  + bit g500 3 * 2^7 +
  bit g500 2 * 2^5  + bit g500 1 * 2^3 +
  bit g500 7 * 2^2  + bit g500 0 * 2 + bit g500 6

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: inverse Gillham construction; rejects
non-integral 100-foot values and heights outside the representable range. -/
def encodeGillham (height : Int) : Option Nat :=
  if -1200 ≤ height ∧ height ≤ 126700 ∧ height % 100 = 0 then
    let h := (height + 1200).toNat
    let n500 := h / 500
    let c := h % 500 / 100 + 1
    let c := if n500 % 2 == 1 then 6 - c else c
    let c := if c == 5 then 7 else c
    some (packGillham (grayEncode n500) (grayEncode c))
  else none

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: N is an unsigned 11-bit integer. -/
def Representable25 (height : Int) : Prop :=
  -1000 ≤ height ∧ height ≤ 50175 ∧ (height + 1000) % 25 = 0

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: inverse h=25N−1000, with separate M=0,Q=1. -/
def encode25AC13 (height : Int) : Option Nat :=
  if -1000 ≤ height ∧ height ≤ 50175 ∧ (height + 1000) % 25 = 0 then
    let n := ((height + 1000) / 25).toNat
    some (n / 32 * 128 + n / 16 % 2 * 32 + 16 + n % 16)
  else none

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

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: independently insert the M=1 bit around
the 12-bit metric height; zero metres is distinct from unavailable. -/
def encodeMetricAC13 (height : Nat) : Option Nat :=
  if height < 4096 then some (height / 64 * 128 + 64 + height % 64) else none

/-- Sun, 2nd ed. (2021), ch.13 “Altitude code”: choose the requested standard feet encoding. -/
def encodeFeetAC13 (encoding : FeetEncoding) (height : Int) : Option Nat :=
  match encoding with
  | .binary25 => encode25AC13 height
  | .gillham100 => encodeGillham height

/-- Sun, 2nd ed. (2021), ch.5 “Barometric altitude”: ADS-B omits the M bit of AC13. -/
def expandAC12 (word : Nat) : Nat := word / 64 * 128 + word % 64

/-- Sun, 2nd ed. (2021), ch.5 “Barometric altitude”: decode a 12-bit barometric altitude field. -/
def decodeAC12 (word : Nat) : Option Int :=
  if word < 4096 then
    match decodeAC13 (expandAC12 word) with
    | some (.feet height) => some height
    | _ => none
  else none

/-- Sun, 2nd ed. (2021), ch.5 “Barometric altitude”: encode independently via a standard
feet code and remove its zero M bit; no Float conversion is involved. -/
def encodeFeetAC12 (encoding : FeetEncoding) (height : Int) : Option Nat :=
  (encodeFeetAC13 encoding height).map (fun word => word / 128 * 64 + word % 64)

/-- Sun, 2nd ed. (2021), ch.5 “GNSS height”: that chapter describes a 12-bit height in metres.
This is deliberately distinct from AC12 barometric semantics; the oracle's
use of its barometric decoder for TC20–22 is a documented source conflict. -/
def decodeGNSSMetres (word : Nat) : Option Nat :=
  if word < 4096 then some word else none

/-- Sun, 2nd ed. (2021), ch.5 “GNSS height”: inverse unsigned 12-bit metre field. -/
def encodeGNSSMetres (height : Nat) : Option Nat :=
  if height < 4096 then some height else none

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

/-- The 25-foot altitude capstone has a concrete ordinary flight-height
witness in both13-bit and12-bit layouts (Annex10 IV (4th ed., 2007) §3.1.2.6.5.4(d)). -/
theorem binary25_nonvacuous :
    Representable25 38000 ∧ encode25AC13 38000 = some 6200 ∧
    decodeAC13 6200 = some (.feet 38000) ∧
    encodeFeetAC12 .binary25 38000 = some 3128 ∧ decodeAC12 3128 = some 38000 := by
  unfold Representable25
  decide +kernel

/-- The Gillham altitude capstone has a concrete ordinary flight-height
witness (Annex10 IV (4th ed., 2007) §3.1.2.6.5.4(c), Sun, 2nd ed. (2021), ch.13 Altitude code). -/
theorem gillham_nonvacuous :
    RepresentableGillham 38000 ∧ encodeGillham 38000 = some 3203 ∧
    decodeGillham 3203 = some 38000 ∧
    encodeFeetAC12 .gillham100 38000 = some 1603 ∧ decodeAC12 1603 = some 38000 := by
  unfold RepresentableGillham
  decide +kernel

/-- Sun, 2nd ed. (2021), ch.13 invalid-C rule: a nonzero bounded code can still be invalid;
the rejection capstone therefore has a substantive concrete witness. -/
theorem invalid_gillham_nonvacuous :
    2 < 8192 ∧ validGillham 2 = false ∧ decodeGillham 2 = none := by decide +kernel

end Lean1090.Spec.Altitude

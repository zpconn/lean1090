import Std

/-!
# Runtime exact binary64 arithmetic for inference decisions

rs1090-derived policy support, rather than an ICAO wire field.
Rust's `f64` documentation identifies IEEE binary64 and the 53-bit
significand; its linked `f32` documentation specifies round-to-nearest,
ties-to-even for arithmetic. Sources actually consulted:
https://doc.rust-lang.org/std/primitive.f64.html
https://doc.rust-lang.org/std/primitive.f32.html#floating-point-arithmetic

We model finite numeric values as rationals, rounding at every operation.
This deliberately does not use Lean's opaque Float arithmetic in predicates.
Signed zero has the same numeric comparison behavior and is collapsed here.
The model is only a model of binary64 for finite operands/results and nonzero
divisors. The inference finite-range obligation must establish those bounds;
overflow, NaN, division by zero, and general Float presentation are not claimed
to be modeled by these rational operations. `inRange` exposes that boundary.
-/

namespace Lean1090.Impl.Binary64

/-- Exact total power formula, also used to construct the immutable format table. -/
def powerTwoFormula (exponent : Int) : Rat :=
  if exponent < 0 then 1 / (2 ^ exponent.natAbs : Nat)
  else (2 ^ exponent.toNat : Nat)

/-- Every binary64 format exponent from −1074 through 1023, keyed only by exponent.
Entries use the original exact formula, with no dependency on rounding or lookup. -/
def powerTwoTable : Array Rat := Array.ofFn fun code : Fin 2098 =>
  powerTwoFormula ((code.val : Int) - 1074)

/-- Rust f64, `MANTISSA_DIGITS`, `MIN_EXP`: exact integer powers of two.
Exponents outside the format table retain the unrestricted total formula. -/
def powerTwo (exponent : Int) : Rat :=
  if h : -1074 ≤ exponent ∧ exponent ≤ 1023 then
    powerTwoTable[(exponent + 1074).toNat]'(by
      have bound : (exponent + 1074).toNat < 2098 := by omega
      simpa [powerTwoTable] using bound)
  else powerTwoFormula exponent

/-- Rust f64, arithmetic nearest/ties-even: round a nonnegative ratio
to an integer by quotient/remainder, independent of Float. -/
def nearestEven (numerator denominator : Nat) : Nat :=
  let q := numerator / denominator
  let r := numerator % denominator
  if 2 * r > denominator || (2 * r == denominator && q % 2 == 1) then q + 1
  else q

/-- Rust f64, `MANTISSA_DIGITS`: binade exponent of a nonzero rational.
The initial numerator/denominator bit-length estimate differs by at most one. -/
def exponent (value : Rat) : Int :=
  let candidate := (value.num.natAbs.log2 : Int) - (value.den.log2 : Int)
  if value.abs < powerTwo candidate then candidate - 1 else candidate

/-- Rust f64 arithmetic: nearest representable finite significand with 53
bits, including the fixed 2^-1074 subnormal quantum. For overflow this remains
a mathematical extension; callers must prove `inRange` for every result. -/
def round (value : Rat) : Rat :=
  if value == 0 then 0 else
    let quantum := powerTwo (max (-1074) (exponent value - 52))
    let scaled := value.abs / quantum
    let rounded := (nearestEven scaled.num.natAbs scaled.den : Rat) * quantum
    if value < 0 then -rounded else rounded

/-- Rust f64 `MAX`: largest finite positive binary64 value. -/
def maxFinite : Rat := ((2^53 - 1 : Nat) : Rat) * powerTwo 971

/-- Rust f64 `MAX`: necessary finite-value boundary for this exact model. -/
def inRange (value : Rat) : Prop := value.abs ≤ maxFinite

/-- Rust f64 decimal literals: round their exact rational decimal values once. -/
def literal (value : Rat) : Rat := round value

/-- Rust f64 addition: one rounding after exact addition, no reassociation. -/
def add (a b : Rat) : Rat := round (a + b)

/-- Rust f64 subtraction: one rounding after exact subtraction. -/
def sub (a b : Rat) : Rat := round (a - b)

/-- Rust f64 multiplication: one rounding after exact multiplication. -/
def mul (a b : Rat) : Rat := round (a * b)

/-- Rust f64 division: one rounding after division; requires b≠0 for the
IEEE interpretation. Rat's total zero-divisor convention is not IEEE semantics. -/
def div (a b : Rat) : Rat := round (a / b)

/-- Rust f64 `from_bits`: numeric value of finite binary64 bits; reject
exponent 2047 instead of inventing a rational value for infinity or NaN. -/
def fromBits (bits : BitVec 64) : Option Rat :=
  let e : Nat := bits.toNat / 2^52 % 2048
  let fraction : Nat := bits.toNat % 2^52
  if e == 2047 then none else
    let magnitude := if e == 0 then (fraction : Rat) * powerTwo (-1074)
      else ((2^52 + fraction : Nat) : Rat) * powerTwo ((e : Int) - 1075)
    some (if bits.toNat / 2^63 == 0 then magnitude else -magnitude)

end Lean1090.Impl.Binary64

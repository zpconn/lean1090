import Impl.CPRFloat
import Impl.Libm

/-!
Tested presentation boundary. This evaluates the precision/order expressions
already included in the proved result; it does not make inference decisions.
No new external primitive is introduced. Binary32 and binary64 arithmetic use
Lean's existing runtime operations. The transcendental results are tested,
not covered by the exact decoder's mathematical refinement theorem.

The norm and angle functions use a pure Lean translation of the pinned Rust
libm algorithms; their exhaustive oracle validation is a runtime test.
-/

namespace Lean1090.Impl.Numeric
open Lean1090.Spec.Presentation

/-- Convert a rational directly to nearest/ties-even binary32, avoiding a
potentially double-rounded intermediate binary64 conversion. -/
def toFloat32 (value : Rat) : Float32 :=
  let quantum := Binary64.powerTwo (max (-149) (Binary64.exponent value - 23))
  let scaled := value.abs / quantum
  let magnitude := (Binary64.nearestEven scaled.num.natAbs scaled.den : Rat) * quantum
  let sign := if value < 0 then 2^31 else 0
  let exponent := Binary64.exponent magnitude
  let bits := if magnitude == 0 then sign
    else if exponent > 127 then sign + 255 * 2^23
    else if exponent < -126 then
      sign + (magnitude / Binary64.powerTwo (-149)).floor.toNat
    else sign + (exponent + 127).toNat * 2^23 +
      (magnitude / Binary64.powerTwo (exponent - 23)).floor.toNat - 2^23
  Float32.ofBits bits.toUInt32

/-- Pinned Rust libm norm, used only at the tested presentation boundary. -/
abbrev hypot := Libm.hypot

/-- Evaluate the frozen expression tree, preserving every rounding point and
operand order. Float32 operations round before the result is widened. -/
def eval : FloatExpr → Float
  | .literal .binary64 q => CPR.Policy.toFloat q
  | .literal .binary32 q => (toFloat32 q).toFloat
  | .add .binary64 a b => eval a + eval b
  | .sub .binary64 a b => eval a - eval b
  | .mul .binary64 a b => eval a * eval b
  | .div .binary64 a b => eval a / eval b
  | .add .binary32 a b => ((eval a).toFloat32 + (eval b).toFloat32).toFloat
  | .sub .binary32 a b => ((eval a).toFloat32 - (eval b).toFloat32).toFloat
  | .mul .binary32 a b => ((eval a).toFloat32 * (eval b).toFloat32).toFloat
  | .div .binary32 a b => ((eval a).toFloat32 / (eval b).toFloat32).toFloat
  | .abs64 a => (eval a).abs
  | .hypot64 a b => hypot (eval a) (eval b)
  | .atan2_64 y x => Libm.atan2 (eval y) (eval x)
  | .addIfNegative64 a => let value := eval a; if value < 0 then value + 360 else value

end Lean1090.Impl.Numeric

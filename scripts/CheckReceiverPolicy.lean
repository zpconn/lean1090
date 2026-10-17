import Spec.ADSB

/-! Exhaustive kernel regression for the independent AC12 acceptance domain.
The domain predicate itself has no decoder dependency; this separate check
confirms the refactoring retained the old receiver behavior for all12-bit codes.
-/
set_option maxRecDepth 100000
set_option maxHeartbeats 20000000

open Lean1090.Spec

example : (List.range 4096).all (fun code =>
    altitudeCodeAdmissible code == (Altitude.oracleAC12 code).isSome) = true := by
  decide +kernel

import Std

namespace Lean1090.Model.BDS50

/-- Exact lossless field codes and all five semantic outputs. The score is
retained, making the threshold decision inspectable without rescoring. -/
structure Result where
  fields : List (String × Nat)
  roll : Option Rat
  track : Option Rat
  groundspeed : Option Rat
  trackRate : Option Rat
  tas : Option Rat
  score : Rat
  deriving DecidableEq, Repr


end Lean1090.Model.BDS50

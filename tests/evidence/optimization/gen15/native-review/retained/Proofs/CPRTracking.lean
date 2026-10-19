import Capstones
import Spec.CPRFloat
import Impl.CPRPolicy
import Impl.CPRFloat

/-! Initial runtime CPR policy refinement. The numerical geography is an
explicit argument on both sides, as required by the approved contract. -/

namespace Lean1090.Proofs

/-- Every stream, initial reference, numerical boundary and callback produces
the exact specified state and sequence of positions. -/
theorem CPRTrackingRefinement : Capstones.CPRTrackingRefinement Impl.decodePositions := by
  intro geography update reference reports
  rfl

/-- The exact local runtime decoder initially implements the frozen equations. -/
theorem cprLocalRefinement (mode : Spec.CPR.Medium) (code : Spec.CPR.Encoded)
    (reference : Spec.CPR.Position) :
    Impl.CPR.decodeLocal mode code reference = Spec.CPR.decodeLocal mode code reference := rfl

/-- The exact global runtime decoder initially implements the frozen equations. -/
theorem cprGlobalRefinement (even odd : Spec.CPR.Encoded) (latestOdd : Bool) :
    Impl.CPR.decodeGlobal even odd latestOdd = Spec.CPR.decodeGlobal even odd latestOdd := rfl

/-- Numerical adapter equality is equality of the specified Float programs;
it does not give Lean's opaque Float arithmetic mathematical proof semantics. -/
theorem cprLocalFloatRefinement (mode : Spec.CPR.Medium) (code : Spec.CPR.Encoded)
    (reference : Spec.CPR.Position) :
    Impl.CPR.Policy.decodeLocalFloat mode code reference =
      Spec.CPR.Policy.decodeLocalFloat mode code reference := rfl

theorem cprGlobalFloatRefinement (even odd : Spec.CPR.Encoded) (latestOdd : Bool) :
    Impl.CPR.Policy.decodeGlobalFloat even odd latestOdd =
      Spec.CPR.Policy.decodeGlobalFloat even odd latestOdd := rfl

#print axioms CPRTrackingRefinement
#print axioms cprLocalRefinement
#print axioms cprGlobalRefinement
#print axioms cprLocalFloatRefinement
#print axioms cprGlobalFloatRefinement

end Lean1090.Proofs

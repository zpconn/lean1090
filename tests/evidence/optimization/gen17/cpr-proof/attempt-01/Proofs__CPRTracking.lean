import Capstones
import Spec.CPRFloat
import Impl.CPRPolicy
import Impl.CPRFloat
import Proofs.Binary64Runtime

/-! Runtime CPR policy refinement through the exact binary64 arithmetic bridge.
The numerical geography is an explicit argument on both sides, as required
by the approved contract. Float-program equality below is congruence through
unchanged Float operations, not a claim about their real-number semantics. -/

namespace Lean1090.Proofs

private theorem speedGT_function_eq :
    @Impl.CPR.Policy.speedGT = @Spec.CPR.Policy.speedGT := by
  unfold Impl.CPR.Policy.speedGT Spec.CPR.Policy.speedGT
  simp only [Binary64Runtime.div_function_eq]

private theorem validMotion_function_eq :
    @Impl.CPR.Policy.validMotion = @Spec.CPR.Policy.validMotion := by
  unfold Impl.CPR.Policy.validMotion Spec.CPR.Policy.validMotion
  simp only [Binary64Runtime.sub_function_eq, Binary64Runtime.div_function_eq,
    speedGT_function_eq] <;> rfl

private theorem stepAirborne_function_eq :
    @Impl.CPR.Policy.stepAirborne = @Spec.CPR.Policy.stepAirborne := by
  unfold Impl.CPR.Policy.stepAirborne Spec.CPR.Policy.stepAirborne
  simp only [Binary64Runtime.sub_function_eq, validMotion_function_eq] <;> rfl

private theorem step_function_eq :
    @Impl.CPR.Policy.step = @Spec.CPR.Policy.step := by
  unfold Impl.CPR.Policy.step Spec.CPR.Policy.step
  simp only [stepAirborne_function_eq] <;> rfl

/-- Every single live stream step preserves the complete state and result. -/
theorem cprStreamStepRefinement :
    @Impl.CPR.Policy.streamStep = @Spec.CPR.Policy.streamStep := by
  unfold Impl.CPR.Policy.streamStep Spec.CPR.Policy.streamStep
  simp only [step_function_eq] <;> rfl

/-- Every stream, initial reference, numerical boundary and callback produces
the exact specified state and sequence of positions. -/
theorem CPRTrackingRefinement : Capstones.CPRTrackingRefinement Impl.decodePositions := by
  intro geography update reference reports
  unfold Impl.decodePositions Impl.CPR.Policy.decodePositions Spec.CPR.Policy.decodePositions
  simp only [cprStreamStepRefinement] <;> rfl

/-- The separate reference-refresh utility preserves its rounded age check. -/
theorem cprUpdateGlobalReferenceRefinement :
    @Impl.CPR.Policy.updateGlobalReference = @Spec.CPR.Policy.updateGlobalReference := by
  unfold Impl.CPR.Policy.updateGlobalReference Spec.CPR.Policy.updateGlobalReference
  simp only [Binary64Runtime.sub_function_eq] <;> rfl

/-- The exact local runtime decoder initially implements the frozen equations. -/
theorem cprLocalRefinement (mode : Spec.CPR.Medium) (code : Spec.CPR.Encoded)
    (reference : Spec.CPR.Position) :
    Impl.CPR.decodeLocal mode code reference = Spec.CPR.decodeLocal mode code reference := rfl

/-- The exact global runtime decoder initially implements the frozen equations. -/
theorem cprGlobalRefinement (even odd : Spec.CPR.Encoded) (latestOdd : Bool) :
    Impl.CPR.decodeGlobal even odd latestOdd = Spec.CPR.decodeGlobal even odd latestOdd := rfl

/-- All rational inputs produce the same specified Float program result. -/
theorem cprToFloatRefinement : @Impl.CPR.Policy.toFloat = @Spec.CPR.Policy.toFloat := by
  unfold Impl.CPR.Policy.toFloat Spec.CPR.Policy.toFloat
  simp only [Binary64Runtime.round_function_eq, Binary64Runtime.exponent_function_eq,
    Binary64Runtime.powerTwo_function_eq]

/-- Finite, infinite and NaN distance interpretations are all preserved. -/
theorem cprDistanceFromFloatRefinement :
    @Impl.CPR.Policy.distanceFromFloat = @Spec.CPR.Policy.distanceFromFloat := by
  unfold Impl.CPR.Policy.distanceFromFloat Spec.CPR.Policy.distanceFromFloat
  simp only [Binary64Runtime.fromBits_function_eq]

private theorem positionFromFloats_function_eq :
    @Impl.CPR.Policy.positionFromFloats = @Spec.CPR.Policy.positionFromFloats := by
  unfold Impl.CPR.Policy.positionFromFloats Spec.CPR.Policy.positionFromFloats
  simp only [Binary64Runtime.fromBits_function_eq]

/-- Numerical adapter equality is equality of the specified Float programs;
it does not give Lean's opaque Float arithmetic mathematical proof semantics. -/
theorem cprLocalFloatRefinement (mode : Spec.CPR.Medium) (code : Spec.CPR.Encoded)
    (reference : Spec.CPR.Position) :
    Impl.CPR.Policy.decodeLocalFloat mode code reference =
      Spec.CPR.Policy.decodeLocalFloat mode code reference := by
  unfold Impl.CPR.Policy.decodeLocalFloat Spec.CPR.Policy.decodeLocalFloat
  simp only [cprToFloatRefinement, positionFromFloats_function_eq] <;> rfl

theorem cprGlobalFloatRefinement (even odd : Spec.CPR.Encoded) (latestOdd : Bool) :
    Impl.CPR.Policy.decodeGlobalFloat even odd latestOdd =
      Spec.CPR.Policy.decodeGlobalFloat even odd latestOdd := by
  unfold Impl.CPR.Policy.decodeGlobalFloat Spec.CPR.Policy.decodeGlobalFloat
  simp only [positionFromFloats_function_eq] <;> rfl

/-- The complete live numerical geography equals the specified Float program.
This adds no real-arithmetic guarantee for opaque Float operations. -/
theorem cprNumericalGeographyRefinement :
    @Impl.CPR.Policy.numericalGeography = @Spec.CPR.Policy.numericalGeography := by
  unfold Impl.CPR.Policy.numericalGeography Spec.CPR.Policy.numericalGeography
  simp only [cprDistanceFromFloatRefinement,
    show @Impl.CPR.Policy.decodeLocalFloat = @Spec.CPR.Policy.decodeLocalFloat from
      funext fun mode => funext fun code => funext fun reference =>
        cprLocalFloatRefinement mode code reference,
    show @Impl.CPR.Policy.decodeGlobalFloat = @Spec.CPR.Policy.decodeGlobalFloat from
      funext fun even => funext fun odd => funext fun latestOdd =>
        cprGlobalFloatRefinement even odd latestOdd]
  unfold Impl.CPR.Policy.haversineFloat Spec.CPR.Policy.haversineFloat
  simp only [cprToFloatRefinement]

#print axioms cprStreamStepRefinement
#print axioms CPRTrackingRefinement
#print axioms cprUpdateGlobalReferenceRefinement
#print axioms cprLocalRefinement
#print axioms cprGlobalRefinement
#print axioms cprToFloatRefinement
#print axioms cprDistanceFromFloatRefinement
#print axioms cprLocalFloatRefinement
#print axioms cprGlobalFloatRefinement
#print axioms cprNumericalGeographyRefinement

end Lean1090.Proofs

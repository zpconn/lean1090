import Impl.BDS50
import Spec.BDS50

namespace Lean1090.Proofs.BDS50

@[simp] theorem bits_eq (w s n : Nat) : Impl.BDS50.bits w s n = Spec.payloadBits w s n := rfl
@[simp] theorem signed_eq (w s n : Nat) : Impl.BDS50.signed w s n = Spec.cbSigned w s n := by
  simp [Impl.BDS50.signed, Spec.cbSigned, Spec.payloadInteger]
@[simp] theorem status_eq (w s a n : Nat) : Impl.BDS50.status w s a n = Spec.cbStatus w s a n := rfl

@[simp] theorem roll_eq (w : Nat) : Impl.BDS50.roll w = Spec.commBValue 0x50 w "roll" := by
  simp [Impl.BDS50.roll, Impl.BDS50.value, Spec.commBValue, Spec.commBLayout, Spec.bds50Layout,
    Spec.cbColumn, Spec.payloadValue, Spec.payloadInteger, Impl.BDS50.signed]
@[simp] theorem track_eq (w : Nat) : Impl.BDS50.track w = Spec.commBValue 0x50 w "track" := by
  simp [Impl.BDS50.track, Impl.BDS50.value, Spec.commBValue, Spec.commBLayout, Spec.bds50Layout,
    Spec.cbColumn, Spec.payloadValue, Spec.payloadInteger, Impl.BDS50.signed, Spec.cbWrapAngle]
@[simp] theorem groundSpeed_eq (w : Nat) : Impl.BDS50.groundSpeed w = Spec.commBValue 0x50 w "groundspeed" := by
  simp [Impl.BDS50.groundSpeed, Impl.BDS50.value, Spec.commBValue, Spec.commBLayout, Spec.bds50Layout,
    Spec.cbColumn, Spec.payloadValue, Spec.payloadInteger]
@[simp] theorem rate_eq (w : Nat) : Impl.BDS50.rate w = Spec.commBValue 0x50 w "track_rate" := by
  simp [Impl.BDS50.rate, Impl.BDS50.value, Spec.commBValue, Spec.commBLayout, Spec.bds50Layout,
    Spec.cbColumn, Spec.payloadValue, Spec.payloadInteger, Impl.BDS50.signed]
@[simp] theorem tas_eq (w : Nat) : Impl.BDS50.trueAirspeed w = Spec.commBValue 0x50 w "TAS" := by
  simp [Impl.BDS50.trueAirspeed, Impl.BDS50.value, Spec.commBValue, Spec.commBLayout, Spec.bds50Layout,
    Spec.cbColumn, Spec.payloadValue, Spec.payloadInteger]
@[simp] theorem wireValid_eq (w : Nat) : Impl.BDS50.wireValid w = Spec.bdsWireValid 0x50 w := by
  simp [Impl.BDS50.wireValid, Spec.bdsWireValid, Spec.cbValid50]
  rfl

@[simp] theorem round_eq (x : Rat) : Impl.Binary64.round x = Spec.Binary64.round x := rfl
@[simp] theorem add_eq (x y : Rat) : Impl.Binary64.add x y = Spec.Binary64.add x y := rfl
@[simp] theorem sub_eq (x y : Rat) : Impl.Binary64.sub x y = Spec.Binary64.sub x y := rfl
@[simp] theorem mul_eq (x y : Rat) : Impl.Binary64.mul x y = Spec.Binary64.mul x y := rfl
@[simp] theorem div_eq (x y : Rat) : Impl.Binary64.div x y = Spec.Binary64.div x y := rfl
@[simp] theorem literal_eq (x : Rat) : Impl.Binary64.literal x = Spec.Binary64.literal x := rfl
@[simp] theorem gaussian_eq (x m s : Rat) : Impl.BDS50.gaussian x m s = Spec.cbGaussian x m s := rfl
@[simp] theorem laplace_eq (x m s : Rat) : Impl.BDS50.laplace x m s = Spec.cbLaplace x m s := rfl
@[simp] theorem scoreField_eq (x : Option Rat) (f : Rat → Rat) :
    Impl.BDS50.scoreField x f = Spec.cbScoreField x f := rfl
@[simp] theorem terms_eq (w : Nat) : Impl.BDS50.densityTerms w = Spec.cbDensityTerms 0x50 w := by
  simp [Impl.BDS50.densityTerms, Spec.cbDensityTerms]
@[simp] theorem density_eq (w : Nat) : Impl.BDS50.density w = Spec.cbDensity 0x50 w := by
  simp [Impl.BDS50.density, Spec.cbDensity, funext (fun a => funext (fun b => add_eq a b))]
@[simp] theorem penalty_eq (w : Nat) : Impl.BDS50.penalty w = Spec.cbPenalty 0x50 w := by
  simp [Impl.BDS50.penalty, Spec.cbPenalty]
  rfl
@[simp] theorem score_eq (w : Nat) : Impl.BDS50.combinedScore w = Spec.cbCombinedScore 0x50 w := by
  simp [Impl.BDS50.combinedScore, Spec.cbCombinedScore]

@[simp] theorem fields_eq (w : Nat) : Impl.BDS50.fields w =
    (Spec.decodePayloadFields Spec.bds50Layout w).map (fun f => (f.name, f.code)) := rfl

/-- All Nat inputs, including over-wide values, empty payload, status mismatches,
hard rejects, sentinel rates, and scores on either side of the inclusive gate. -/
theorem refinement (w : Nat) : Impl.BDS50.decode w = Spec.bds50Reference w := by
  simp [Impl.BDS50.decode, Spec.bds50Reference, Spec.commBEligible, Spec.commBCoreEligible,
    Spec.commBCoreRegisters, Spec.cbScorePasses, Spec.decodeBDS, Spec.bdsLayout, Spec.commBLayout]
  split <;> split <;> simp_all

/-- Concrete inclusive-gate witness: roll22.5°, rate2.625°/s, with both
status flags present and the remaining three fields absent. Adjacent rate
codes straddle the threshold; the equality is checked by the Lean kernel. -/
theorem exact_threshold_nonvacuous :
    Impl.BDS50.wireValid 40532396648603648 = true ∧
    Impl.BDS50.combinedScore 40532396648603648 = -3 ∧
    (Impl.BDS50.decode 40532396648603648).isSome = true ∧
    (Impl.BDS50.decode 40532396648601600).isSome = true ∧
    (Impl.BDS50.decode 40532396648605696).isSome = false := by decide +kernel

theorem pilot_nonvacuous : ∃ word result, Impl.BDS50.decode word = some result := by
  refine ⟨40532396648603648, ?_⟩
  have h : (Impl.BDS50.decode 40532396648603648).isSome = true := by decide +kernel
  cases he : Impl.BDS50.decode 40532396648603648 with
  | none => simp [he] at h
  | some result => exact ⟨result, rfl⟩

#print axioms refinement
#print axioms pilot_nonvacuous
#print axioms exact_threshold_nonvacuous
end Lean1090.Proofs.BDS50

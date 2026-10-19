import Proofs.CPRGeometry
import Proofs.CPRTransitionCertificates
import Proofs.CPRNLClassification

/-! Kernel-checked bounds for the frozen CPR latitude-zone certificates. -/

namespace Lean1090.Proofs.CPRLatitudeZones
open Spec.CPR CPRGeometry

def GridGap (c : NLCertificate) (mode : Medium) (odd : Bool) : Prop :=
  ⌊((c.upper12 : Rat) / 1000000000000) / (dLat mode odd / scale)⌋ <
    ⌈((c.lower12 : Rat) / 1000000000000) / (dLat mode odd / scale)⌉

instance (c : NLCertificate) (mode : Medium) (odd : Bool) : Decidable (GridGap c mode odd) := by
  unfold GridGap
  infer_instance

theorem all_grid_gaps (c : NLCertificate) (member : c ∈ nlCertificates)
    (mode : Medium) (odd : Bool) : GridGap c mode odd := by
  have checks : nlCertificates.all (fun c => decide
      (GridGap c .airborne false ∧ GridGap c .airborne true ∧
       GridGap c .surface false ∧ GridGap c .surface true)) = true := by decide +kernel
  have row := of_decide_eq_true ((List.all_eq_true.mp checks) c member)
  cases mode <;> cases odd <;> simp_all

theorem grid_avoids (step lower upper : Rat) (index : Int) (positive : 0 < step)
    (gap : ⌊upper / step⌋ < ⌈lower / step⌉) :
    ¬ (lower ≤ absQ (step * (index : Rat)) ∧ absQ (step * (index : Rat)) ≤ upper) := by
  rw [absQ_eq_abs, abs_mul, abs_of_pos positive]
  intro inside
  have lower : lower / step ≤ (|index| : Int) := by
    rw [div_le_iff₀ positive]
    simpa only [Int.cast_abs, mul_comm] using inside.1
  have upper : ((|index| : Int) : Rat) ≤ upper / step := by
    rw [le_div_iff₀ positive]
    simpa only [Int.cast_abs, mul_comm] using inside.2
  have := Int.ceil_le.mpr lower
  have := Int.le_floor.mpr upper
  omega

theorem avoids_decodable_latitudes (c : NLCertificate) (member : c ∈ nlCertificates) :
    AvoidsDecodableLatitudes c := by
  intro latitude decodable
  obtain ⟨mode, odd, index, grid, _, _⟩ := decodable
  rw [grid]
  exact grid_avoids _ _ _ index
    (div_pos (dLat_pos mode odd) (by norm_num [scale]))
    (all_grid_gaps c member mode odd)

end Lean1090.Proofs.CPRLatitudeZones

#print axioms Lean1090.Proofs.CPRLatitudeZones.avoids_decodable_latitudes

namespace Lean1090.Proofs

/-- The executable latitude-zone table agrees with the real arccos formula on
all four reconstructed CPR grids. All 57 transition enclosures and the finite
grid-separation checks are proved above and in the imported proof modules. -/
theorem CPRLatitudeZones : Capstones.CPRLatitudeZones := by
  constructor
  · intro certificate member
    exact ⟨CPRTransitionCertificates.certificates certificate member,
      CPRLatitudeZones.avoids_decodable_latitudes certificate member⟩
  · exact CPRNLClassification.classification CPRTransitionCertificates.certificates
      CPRLatitudeZones.avoids_decodable_latitudes

end Lean1090.Proofs

#print axioms Lean1090.Proofs.CPRLatitudeZones

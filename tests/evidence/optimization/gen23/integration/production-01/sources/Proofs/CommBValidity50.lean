import Impl.CommB

/-!
The BDS50 roll-validity table stores the original rational predicate for all
ten-bit codes. Its lookup theorem is symbolic in every natural payload, with
no validity, status, width, or corpus-membership assumption.
-/

namespace Lean1090.Proofs.CommBValidity50

/-- The complete ten-bit code space is represented, including rejected codes. -/
theorem table_size : Impl.cbRollValid50Table.size = 1024 := by
  simp [Impl.cbRollValid50Table]

/-- Each entry is the original signed roll, multiplication, division and bound. -/
theorem table_get (code : Fin 1024) :
    Impl.cbRollValid50Table[code.val]'(by simp [table_size]) =
      decide (((Impl.payloadInteger .twosComplement 10 code.val : Rat) * 45 / 256).abs ≤ 45) := by
  simp [Impl.cbRollValid50Table]

/-- Lookup equals the original roll check for every natural-number word. -/
theorem cbRollValid50_eq_old (word : Nat) :
    Impl.cbRollValid50 word = decide ((Impl.cbSigned word 2 10 * 45 / 256).abs ≤ 45) := by
  simp [Impl.cbRollValid50, Impl.cbRollValid50Table, Impl.cbSigned]
  rfl

/-- The complete old predicate is preserved, including independently checked
statuses, groundspeed and conditional true-airspeed bounds. -/
theorem cbValid50_eq_old (word : Nat) :
    Impl.cbValid50 word =
      (Impl.cbStatus word 1 2 10 && Impl.cbStatus word 12 13 11 &&
       Impl.cbStatus word 24 25 10 && Impl.cbStatus word 35 36 10 &&
       Impl.cbStatus word 46 47 10 &&
       (Impl.cbSigned word 2 10 * 45 / 256).abs ≤ 45 &&
       Impl.payloadBits word 25 10 * 2 ≤ 700 &&
       (Impl.payloadBits word 46 1 == 0 ||
        (Impl.payloadBits word 47 10 * 2 ≥ 80 &&
         Impl.payloadBits word 47 10 * 2 ≤ 600))) := by
  simp only [Impl.cbValid50, cbRollValid50_eq_old]

/-- A zero roll code passes even when the whole candidate is empty. -/
theorem zero_witness : Impl.cbRollValid50 0 = true ∧ Impl.cbValid50 0 = true := by
  simp only [cbRollValid50_eq_old, cbValid50_eq_old]
  decide +kernel

/-- Both signed inclusive endpoints, +45 and -45 degrees, pass. -/
theorem inclusive_boundaries_witness :
    Impl.cbRollValid50 (256 * 2^45) = true ∧
    Impl.cbRollValid50 (768 * 2^45) = true := by
  simp only [cbRollValid50_eq_old]
  decide +kernel

/-- The adjacent codes just outside either inclusive endpoint fail. -/
theorem rejected_neighbors_witness :
    Impl.cbRollValid50 (257 * 2^45) = false ∧
    Impl.cbRollValid50 (767 * 2^45) = false := by
  simp only [cbRollValid50_eq_old]
  decide +kernel

/-- Both sign-transition extrema fail; the all-one signed code represents -1. -/
theorem signed_codes_witness :
    Impl.cbRollValid50 (511 * 2^45) = false ∧
    Impl.cbRollValid50 (512 * 2^45) = false ∧
    Impl.cbRollValid50 (1023 * 2^45) = true := by
  simp only [cbRollValid50_eq_old]
  decide +kernel

/-- The same plausible nonzero roll requires its unchanged availability flag. -/
theorem status_witness :
    Impl.cbValid50 (256 * 2^45) = false ∧
    Impl.cbValid50 (2^55 + 256 * 2^45) = true := by
  simp only [cbValid50_eq_old]
  decide +kernel

/-- The TAS endpoints and adjacent rejected codes remain independent of roll. -/
theorem true_airspeed_witness :
    Impl.cbValid50 (2^10 + 39) = false ∧
    Impl.cbValid50 (2^10 + 40) = true ∧
    Impl.cbValid50 (2^10 + 300) = true ∧
    Impl.cbValid50 (2^10 + 301) = false := by
  simp only [cbValid50_eq_old]
  decide +kernel

/-- Extra high bits leave the extracted roll and this inner predicate intact;
the separate wire-width guard is deliberately not a hypothesis of refinement. -/
theorem overwide_witness :
    Impl.cbRollValid50 (2^130 + 768 * 2^45) = true ∧
    Impl.cbValid50 (2^130 + 2^55 + 768 * 2^45) = true := by
  simp only [cbRollValid50_eq_old, cbValid50_eq_old]
  decide +kernel

#print axioms table_size
#print axioms table_get
#print axioms cbRollValid50_eq_old
#print axioms cbValid50_eq_old
#print axioms zero_witness
#print axioms inclusive_boundaries_witness
#print axioms rejected_neighbors_witness
#print axioms signed_codes_witness
#print axioms status_witness
#print axioms true_airspeed_witness
#print axioms overwide_witness

end Lean1090.Proofs.CommBValidity50

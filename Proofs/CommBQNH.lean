import Proofs.Binary64Runtime
import Impl.CommB
import Spec.CommB
import Proofs.PayloadBits

/-!
The immutable QNH table stores every twelve-bit code's exact software binary64
result, including codes outside the receiver's plausibility range. Lookup
equality holds for every natural-number payload, without a validity, score,
altitude, or corpus-membership hypothesis.
-/

namespace Lean1090.Proofs.CommBQNH

/-- Every possible twelve-bit QNH code has one table entry. -/
theorem table_size : Impl.cbQNHValueTable.size = 4096 := by
  simp [Impl.cbQNHValueTable]

/-- Each entry retains literal rounding followed by multiplication and addition. -/
theorem table_get (code : Fin 4096) :
    Impl.cbQNHValueTable[code.val]'(by simp [table_size]) =
      Impl.Binary64.add (Impl.Binary64.mul (code.val : Rat)
        (Impl.Binary64.literal (1 / 10))) 800 := by
  simp [Impl.cbQNHValueTable]

/-- Every payload, including an over-wide natural, has the unchanged QNH value. -/
theorem cbQNH64_eq_runtime (word : Nat) :
    Impl.cbQNH64 word =
      Impl.Binary64.add (Impl.Binary64.mul (Impl.payloadBits word 28 12 : Rat)
        (Impl.Binary64.literal (1 / 10))) 800 := by
  simp [Impl.cbQNH64, Impl.cbQNHValueTable]

/-- The live lookup equals the frozen software reference for every input. -/
theorem cbQNH64_eq (word : Nat) : Impl.cbQNH64 word = Spec.cbQNH64 word := by
  rw [cbQNH64_eq_runtime, PayloadBits.payloadBits_eq]
  simp only [Binary64Runtime.add_eq, Binary64Runtime.mul_eq, Binary64Runtime.literal_eq, Spec.cbQNH64]

/-- The minimum code is exactly the inclusive 800 hPa plausibility boundary. -/
theorem zero_witness : Impl.cbQNH64 0 = 800 := by
  rw [cbQNH64_eq]
  decide +kernel

/-- A fractional code remains above 800 and retains its binary64 rounding. -/
theorem fractional_witness :
    800 < Impl.cbQNH64 (1 * 2^17) ∧
    Impl.cbQNH64 (1 * 2^17) ≠ (8001 / 10 : Rat) := by
  simp only [cbQNH64_eq]
  decide +kernel

/-- Adjacent codes bracket the receiver's inclusive 1200 hPa boundary. -/
theorem plausibility_boundary_witness :
    Impl.cbQNH64 (3999 * 2^17) < 1200 ∧
    Impl.cbQNH64 (4000 * 2^17) = 1200 ∧
    1200 < Impl.cbQNH64 (4001 * 2^17) := by
  simp only [cbQNH64_eq]
  decide +kernel

/-- The final table code is represented even though it exceeds plausibility. -/
theorem maximal_witness : Impl.cbQNH64 (4095 * 2^17) = (2419 / 2 : Rat) := by
  rw [cbQNH64_eq]
  decide +kernel

/-- Bits outside the payload field do not affect its final table entry. -/
theorem maximal_wide_witness :
    Impl.cbQNH64 (2^130 + 4095 * 2^17) = Spec.cbQNH64 (4095 * 2^17) := by
  rw [cbQNH64_eq]
  decide +kernel

#print axioms table_size
#print axioms table_get
#print axioms cbQNH64_eq_runtime
#print axioms cbQNH64_eq
#print axioms zero_witness
#print axioms fractional_witness
#print axioms plausibility_boundary_witness
#print axioms maximal_witness
#print axioms maximal_wide_witness

end Lean1090.Proofs.CommBQNH

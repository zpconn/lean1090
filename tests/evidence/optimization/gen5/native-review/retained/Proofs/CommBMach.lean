import Impl.CommB
import Spec.CommB
import Proofs.PayloadBits

/-!
The immutable Mach table stores every ten-bit code's exact software binary64
result. Lookup equality is symbolic in arbitrary natural-number payloads;
there is no validity, altitude, score, or corpus-membership hypothesis.
-/

namespace Lean1090.Proofs.CommBMach

/-- Every possible ten-bit Mach code has one table entry. -/
theorem table_size : Impl.cbMachValueTable.size = 1024 := by
  simp [Impl.cbMachValueTable]

/-- Each table entry is the original two-operation software binary64 result. -/
theorem table_get (code : Fin 1024) :
    Impl.cbMachValueTable[code.val]'(by simp [table_size]) =
      Impl.Binary64.div (Impl.Binary64.mul (code.val : Rat)
        (Impl.Binary64.literal (256 / 125))) 512 := by
  simp [Impl.cbMachValueTable]

/-- Every payload, including an over-wide natural, has the unchanged Mach value. -/
theorem cbMach64_eq_runtime (word : Nat) :
    Impl.cbMach64 word =
      Impl.Binary64.div (Impl.Binary64.mul (Impl.payloadBits word 25 10 : Rat)
        (Impl.Binary64.literal (256 / 125))) 512 := by
  simp [Impl.cbMach64, Impl.cbMachValueTable]

/-- The live lookup equals the frozen software reference for every input. -/
theorem cbMach64_eq (word : Nat) : Impl.cbMach64 word = Spec.cbMach64 word := by
  rw [cbMach64_eq_runtime, PayloadBits.payloadBits_eq]
  rfl

/-- The minimum code remains zero. -/
theorem zero_witness : Impl.cbMach64 0 = 0 := by
  rw [cbMach64_eq]
  decide +kernel

/-- Adjacent codes bracket the receiver's Mach-one plausibility boundary. -/
theorem plausibility_boundary_witness :
    Impl.cbMach64 (249 * 2^22) < 1 ∧
    Impl.cbMach64 (250 * 2^22) = 1 ∧
    1 < Impl.cbMach64 (251 * 2^22) := by
  simp only [cbMach64_eq]
  decide +kernel

/-- The final table code is covered even in a payload wider than 112 bits. -/
theorem maximal_wide_witness :
    Impl.cbMach64 (2^130 + 1023 * 2^22) = Spec.cbMach64 (1023 * 2^22) := by
  rw [cbMach64_eq]
  decide +kernel

#print axioms table_size
#print axioms table_get
#print axioms cbMach64_eq_runtime
#print axioms cbMach64_eq
#print axioms zero_witness
#print axioms plausibility_boundary_witness
#print axioms maximal_wide_witness

end Lean1090.Proofs.CommBMach

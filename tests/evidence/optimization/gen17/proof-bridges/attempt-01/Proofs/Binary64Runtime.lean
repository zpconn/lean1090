import Impl.Binary64
import Spec.Binary64

/-!
The runtime power table is indexed only by format exponents. Its constructor
uses the original exact formula and cannot recurse through lookup or rounding.
All equalities below are unconditional, including exponents outside the table
and rational inputs outside the finite IEEE interpretation of the model.
-/

namespace Lean1090.Proofs.Binary64Runtime

theorem powerTwoFormula_eq (e : Int) :
    Impl.Binary64.powerTwoFormula e = Spec.Binary64.powerTwo e := rfl

theorem powerTwoTable_size : Impl.Binary64.powerTwoTable.size = 2098 := by
  simp [Impl.Binary64.powerTwoTable]

theorem powerTwoTable_get (code : Fin 2098) :
    Impl.Binary64.powerTwoTable[code.val]'(by simp [powerTwoTable_size]) =
      Spec.Binary64.powerTwo ((code.val : Int) - 1074) := by
  simp [Impl.Binary64.powerTwoTable, powerTwoFormula_eq]

/-- The lookup and unrestricted fallback agree with the frozen formula for all Ints. -/
theorem powerTwo_eq (e : Int) :
    Impl.Binary64.powerTwo e = Spec.Binary64.powerTwo e := by
  unfold Impl.Binary64.powerTwo
  split
  next h =>
    have index : ((e + 1074).toNat : Int) - 1074 = e := by omega
    simp only [Impl.Binary64.powerTwoTable, Array.getElem_ofFn, powerTwoFormula_eq, index]
  next => exact powerTwoFormula_eq e

theorem powerTwo_fallback (e : Int) (h : e < -1074 ∨ 1023 < e) :
    Impl.Binary64.powerTwo e = Impl.Binary64.powerTwoFormula e := by
  unfold Impl.Binary64.powerTwo
  split
  next h' => omega
  next => rfl

theorem nearestEven_eq (n d : Nat) :
    Impl.Binary64.nearestEven n d = Spec.Binary64.nearestEven n d := rfl

theorem exponent_eq (x : Rat) : Impl.Binary64.exponent x = Spec.Binary64.exponent x := by
  simp only [Impl.Binary64.exponent, Spec.Binary64.exponent, powerTwo_eq]

theorem round_eq (x : Rat) : Impl.Binary64.round x = Spec.Binary64.round x := by
  simp only [Impl.Binary64.round, Spec.Binary64.round, exponent_eq, powerTwo_eq,
    nearestEven_eq]

theorem maxFinite_eq : Impl.Binary64.maxFinite = Spec.Binary64.maxFinite := by
  simp only [Impl.Binary64.maxFinite, Spec.Binary64.maxFinite, powerTwo_eq]

theorem inRange_eq (x : Rat) : Impl.Binary64.inRange x = Spec.Binary64.inRange x := by
  simp only [Impl.Binary64.inRange, Spec.Binary64.inRange, maxFinite_eq]

theorem literal_eq (x : Rat) : Impl.Binary64.literal x = Spec.Binary64.literal x :=
  round_eq x

theorem add_eq (a b : Rat) : Impl.Binary64.add a b = Spec.Binary64.add a b :=
  round_eq (a + b)

theorem sub_eq (a b : Rat) : Impl.Binary64.sub a b = Spec.Binary64.sub a b :=
  round_eq (a - b)

theorem mul_eq (a b : Rat) : Impl.Binary64.mul a b = Spec.Binary64.mul a b :=
  round_eq (a * b)

theorem div_eq (a b : Rat) : Impl.Binary64.div a b = Spec.Binary64.div a b :=
  round_eq (a / b)

theorem fromBits_eq (bits : BitVec 64) :
    Impl.Binary64.fromBits bits = Spec.Binary64.fromBits bits := by
  simp only [Impl.Binary64.fromBits, Spec.Binary64.fromBits, powerTwo_eq]

theorem powerTwo_function_eq : Impl.Binary64.powerTwo = Spec.Binary64.powerTwo :=
  funext powerTwo_eq
theorem nearestEven_function_eq : Impl.Binary64.nearestEven = Spec.Binary64.nearestEven :=
  funext fun n => funext fun d => nearestEven_eq n d
theorem exponent_function_eq : Impl.Binary64.exponent = Spec.Binary64.exponent :=
  funext exponent_eq
theorem round_function_eq : Impl.Binary64.round = Spec.Binary64.round := funext round_eq
theorem inRange_function_eq : Impl.Binary64.inRange = Spec.Binary64.inRange := funext inRange_eq
theorem literal_function_eq : Impl.Binary64.literal = Spec.Binary64.literal := funext literal_eq
theorem add_function_eq : Impl.Binary64.add = Spec.Binary64.add :=
  funext fun a => funext fun b => add_eq a b
theorem sub_function_eq : Impl.Binary64.sub = Spec.Binary64.sub :=
  funext fun a => funext fun b => sub_eq a b
theorem mul_function_eq : Impl.Binary64.mul = Spec.Binary64.mul :=
  funext fun a => funext fun b => mul_eq a b
theorem div_function_eq : Impl.Binary64.div = Spec.Binary64.div :=
  funext fun a => funext fun b => div_eq a b
theorem fromBits_function_eq : Impl.Binary64.fromBits = Spec.Binary64.fromBits :=
  funext fromBits_eq

/-- Boundary checks rewrite through the symbolic proof before kernel evaluation;
they never reduce the complete table. -/
theorem below_table_witness :
    Impl.Binary64.powerTwo (-1075) = (1 / (2 ^ 1075 : Nat) : Rat) := by
  rw [powerTwo_eq]
  decide +kernel

theorem first_entry_witness :
    Impl.Binary64.powerTwo (-1074) = (1 / (2 ^ 1074 : Nat) : Rat) := by
  rw [powerTwo_eq]
  decide +kernel

theorem sign_and_zero_witness :
    Impl.Binary64.powerTwo (-1) = (1 / 2 : Rat) ∧
    Impl.Binary64.powerTwo 0 = 1 ∧ Impl.Binary64.powerTwo 1 = 2 := by
  simp only [powerTwo_eq]
  decide +kernel

theorem last_entry_witness :
    Impl.Binary64.powerTwo 1023 = ((2 ^ 1023 : Nat) : Rat) := by
  rw [powerTwo_eq]
  decide +kernel

theorem above_table_witness :
    Impl.Binary64.powerTwo 1024 = ((2 ^ 1024 : Nat) : Rat) := by
  rw [powerTwo_eq]
  decide +kernel

#print axioms powerTwoFormula_eq
#print axioms powerTwoTable_size
#print axioms powerTwoTable_get
#print axioms powerTwo_eq
#print axioms powerTwo_fallback
#print axioms nearestEven_eq
#print axioms exponent_eq
#print axioms round_eq
#print axioms maxFinite_eq
#print axioms inRange_eq
#print axioms literal_eq
#print axioms add_eq
#print axioms sub_eq
#print axioms mul_eq
#print axioms div_eq
#print axioms fromBits_eq
#print axioms powerTwo_function_eq
#print axioms nearestEven_function_eq
#print axioms exponent_function_eq
#print axioms round_function_eq
#print axioms inRange_function_eq
#print axioms literal_function_eq
#print axioms add_function_eq
#print axioms sub_function_eq
#print axioms mul_function_eq
#print axioms div_function_eq
#print axioms fromBits_function_eq
#print axioms below_table_witness
#print axioms first_entry_witness
#print axioms sign_and_zero_witness
#print axioms last_entry_witness
#print axioms above_table_witness

end Lean1090.Proofs.Binary64Runtime

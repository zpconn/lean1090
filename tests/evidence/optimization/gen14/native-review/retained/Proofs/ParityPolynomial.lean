import Proofs.ParityOverlay
import Mathlib.Tactic.IntervalCases

/-!
# CRC refinement to polynomial division over GF(2)

Coefficient lemmas identify the independent reference polynomial with the wire
bits. They prove the recurrence's arithmetic step is one Horner step followed
by cancellation of the degree-24 generator term. Mathlib's uniqueness theorem
for division by a monic polynomial identifies that step with `modByMonic`.
Induction over every input width then proves the frozen capstone, including
zero widths and words containing bits above the selected width.

The generator identity checks its independently published powers against the
integer mask. All remaining reasoning is symbolic; no finite input sampling
stands in for the universal polynomial statement.
-/

namespace Lean1090.Proofs.ParityFacts
open Spec Polynomial

private def coefficient (bit : Bool) : ZMod 2 := if bit then 1 else 0

private theorem coefficient_xor (a b : Bool) :
    coefficient (a ^^ b) = coefficient a + coefficient b := by
  cases a <;> cases b <;> decide +kernel

private theorem polynomial_extend (width word : Nat) :
    Parity.polynomial (width + 1) word =
      Parity.polynomial width word + monomial width (coefficient (word.testBit width)) := by
  unfold Parity.polynomial
  rw [List.range_succ, List.foldl_append]
  rfl

theorem polynomial_coeff (width word i : Nat) :
    (Parity.polynomial width word).coeff i =
      if i < width then coefficient (word.testBit i) else 0 := by
  induction width with
  | zero => simp [Parity.polynomial]
  | succ width ih =>
    rw [polynomial_extend, coeff_add, ih, coeff_monomial]
    by_cases equal : width = i
    · subst i
      simp
    · by_cases below : i < width
      · simp [equal, below, show i < width + 1 by omega]
      · simp [equal, below, show ¬ i < width + 1 by omega]

theorem polynomial_succ (width word : Nat) :
    Parity.polynomial (width + 1) word =
      Parity.polynomial width (word / 2) * X + C (coefficient (word.testBit 0)) := by
  ext i
  cases i with
  | zero => simp [polynomial_coeff]
  | succ i => simp [polynomial_coeff, coeff_mul_X, Nat.testBit_div_two]

theorem polynomial_xor (width a b : Nat) :
    Parity.polynomial width (a ^^^ b) = Parity.polynomial width a + Parity.polynomial width b := by
  ext i
  simp only [polynomial_coeff, coeff_add, Nat.testBit_xor]
  by_cases hi : i < width <;> simp [hi, coefficient_xor]

theorem polynomial_bitvec_coeff (value : BitVec 24) (i : Nat) :
    (Parity.polynomial 24 value.toNat).coeff i = coefficient (value.getLsbD i) := by
  rw [polynomial_coeff, BitVec.testBit_toNat]
  by_cases hi : i < 24
  · simp [hi]
  · have hbit : value.getLsbD i = false := by
      apply Bool.eq_false_iff.mpr
      intro positive
      exact hi (BitVec.lt_of_getLsbD positive)
    simp [hi, hbit, coefficient]

private theorem generator_eq :
    Parity.generatorPolynomial = Parity.polynomial 25 Parity.generator := by
  ext i
  rw [polynomial_coeff]
  by_cases hi : i < 25
  · interval_cases i <;> norm_num [Parity.generatorPolynomial, Parity.generator, coefficient,
      coeff_monomial, coeff_one, Nat.testBit_eq_decide_div_mod_eq]
  · have h : ∀ j : Nat, j ≤ 24 → j ≠ i := by omega
    simp [Parity.generatorPolynomial, hi, coeff_monomial, coeff_one, h]
    omega

private theorem generator_monic : Parity.generatorPolynomial.Monic := by
  rw [generator_eq]
  apply monic_of_degree_le 24
  · rw [degree_le_iff_coeff_zero]
    intro i hi
    rw [polynomial_coeff]
    have : 24 < i := by exact_mod_cast hi
    simp [show ¬ i < 25 by omega]
  · rw [polynomial_coeff]
    decide +kernel

private theorem generator_degree : Parity.generatorPolynomial.degree = 24 := by
  rw [generator_eq]
  apply degree_eq_of_le_of_coeff_ne_zero
  · rw [degree_le_iff_coeff_zero]
    intro i hi
    rw [polynomial_coeff]
    have : 24 < i := by exact_mod_cast hi
    simp [show ¬ i < 25 by omega]
  · rw [polynomial_coeff]
    decide +kernel

private theorem polynomial_degree (width word : Nat) :
    (Parity.polynomial width word).degree < width := by
  rw [degree_lt_iff_coeff_zero]
  intro i hi
  simp [polynomial_coeff, show ¬ i < width by omega]

private theorem polynomial_shift (value : BitVec 24) :
    Parity.polynomial 24 value.toNat * X =
      Parity.polynomial 24 (value <<< 1).toNat + monomial 24 (coefficient value.msb) := by
  ext i
  cases i with
  | zero =>
    rw [coeff_mul_X_zero, coeff_add, polynomial_bitvec_coeff, BitVec.getLsbD_shiftLeft]
    simp [coefficient]
  | succ i =>
    rw [coeff_mul_X, coeff_add, polynomial_bitvec_coeff, polynomial_bitvec_coeff,
      BitVec.getLsbD_shiftLeft, coeff_monomial]
    simp only [Nat.add_sub_cancel, Nat.succ_lt_succ_iff, Nat.not_lt_zero, decide_false,
      Bool.not_false, Bool.and_true]
    by_cases below : i + 1 < 24
    · simp [show i < 23 by omega, show 24 ≠ i + 1 by omega]
    · by_cases equal : i + 1 = 24
      · have : i = 23 := by omega
        subst i
        simp [BitVec.msb_eq_getLsbD_last, coefficient]
      · have high : ¬ i < 24 := by omega
        have hbit : value.getLsbD i = false := by
          apply Bool.eq_false_iff.mpr
          intro positive
          exact high (BitVec.lt_of_getLsbD positive)
        simp [Ne.symm equal, hbit, coefficient]

private theorem generator_split :
    Parity.generatorPolynomial = monomial 24 1 + Parity.polynomial 24 Parity.generator := by
  rw [generator_eq, show 25 = 24 + 1 from rfl, polynomial_extend]
  have top : coefficient (Parity.generator.testBit 24) = 1 := by decide +kernel
  rw [top, add_comm]

private theorem polynomial_bit (bit : Bool) :
    Parity.polynomial 24 (if bit then (1 : BitVec 24) else 0).toNat = C (coefficient bit) := by
  cases bit <;> ext i <;> rw [polynomial_bitvec_coeff] <;>
    simp [BitVec.getLsbD_one, coeff_one, coefficient]

private theorem polynomial_ofNat (word : Nat) :
    Parity.polynomial 24 (BitVec.ofNat 24 word).toNat = Parity.polynomial 24 word := by
  ext i
  rw [polynomial_bitvec_coeff, BitVec.getLsbD_ofNat, polynomial_coeff]
  by_cases below : i < 24 <;> simp [below, coefficient]

private theorem polynomial_zero (width : Nat) : Parity.polynomial width 0 = 0 := by
  ext i
  simp [polynomial_coeff, coefficient]

private theorem polynomial_step_decomposition (value : BitVec 24) (bit : Bool) :
    Parity.polynomial 24 (Parity.step value bit).toNat +
      Parity.generatorPolynomial * C (coefficient value.msb) =
        Parity.polynomial 24 value.toNat * X + C (coefficient bit) := by
  rw [parity_step_eq]
  cases sign : value.msb with
  | false =>
    simp only [Bool.false_eq_true, ↓reduceIte,
      BitVec.toNat_xor, polynomial_xor, coefficient, C_0, mul_zero, add_zero]
    rw [polynomial_bit]
    have shifted := polynomial_shift value
    simp only [sign, coefficient, Bool.false_eq_true, ↓reduceIte, map_zero, add_zero] at shifted
    rw [shifted]
    change Parity.polynomial 24 (value <<< 1).toNat + C (coefficient bit) +
      Parity.polynomial 24 0 = Parity.polynomial 24 (value <<< 1).toNat + C (coefficient bit)
    rw [polynomial_zero, add_zero]
  | true =>
    simp only [↓reduceIte, BitVec.toNat_xor, polynomial_xor,
      coefficient, C_1, mul_one]
    rw [polynomial_bit, polynomial_ofNat, generator_split, polynomial_shift]
    simp only [sign, coefficient, ↓reduceIte]
    have cancel := CharTwo.add_self_eq_zero (Parity.polynomial 24 Parity.generator)
    calc
      _ = (Parity.polynomial 24 (value <<< 1).toNat + monomial 24 1 +
        C (coefficient bit)) +
        (Parity.polynomial 24 Parity.generator + Parity.polynomial 24 Parity.generator) := by ac_rfl
      _ = _ := by rw [cancel, add_zero]; rfl

private theorem polynomial_step_mod (value : BitVec 24) (bit : Bool) :
    Parity.polynomial 24 (Parity.step value bit).toNat =
      (Parity.polynomial 24 value.toNat * X + C (coefficient bit)).modByMonic
        Parity.generatorPolynomial := by
  exact (div_modByMonic_unique (C (coefficient value.msb))
    (Parity.polynomial 24 (Parity.step value bit).toNat) generator_monic
    ⟨polynomial_step_decomposition value bit,
      by rw [generator_degree]; exact polynomial_degree _ _⟩).2.symm

private theorem remainder_step (p : Polynomial (ZMod 2)) (c : ZMod 2) :
    (p.modByMonic Parity.generatorPolynomial * X + C c).modByMonic Parity.generatorPolynomial =
      (p * X + C c).modByMonic Parity.generatorPolynomial := by
  apply modByMonic_eq_of_dvd_sub generator_monic
  have factor : p.modByMonic Parity.generatorPolynomial * X + C c - (p * X + C c) =
      (p.modByMonic Parity.generatorPolynomial - p) * X := by ring
  rw [factor]
  exact dvd_mul_of_dvd_left (dvd_modByMonic_sub p Parity.generatorPolynomial) X

theorem polynomial_syndrome (width word : Nat) :
    Parity.polynomial 24 (Parity.syndrome width word).toNat =
      (Parity.polynomial width word).modByMonic Parity.generatorPolynomial := by
  induction width generalizing word with
  | zero =>
    change Parity.polynomial 24 0 = (0 : Polynomial (ZMod 2)).modByMonic _
    rw [polynomial_zero, zero_modByMonic]
  | succ width ih =>
    rw [syndrome_succ, polynomial_step_mod, ih, polynomial_succ, remainder_step]

end Lean1090.Proofs.ParityFacts

namespace Lean1090.Proofs

/-- The exact frozen universal equivalence with Mathlib polynomial division. -/
theorem CRCPolynomial : Capstones.CRCPolynomial :=
  ParityFacts.polynomial_syndrome

#print axioms CRCPolynomial
end Lean1090.Proofs

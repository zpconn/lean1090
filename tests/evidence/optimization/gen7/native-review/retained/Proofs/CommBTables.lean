import Impl.CommB
import Proofs.CommBArithmetic
import Proofs.PayloadBits
import Proofs.CommBMach

/-!
Exact immutable density tables. Every equality is symbolic in the complete
natural-number payload; no validity, score, or corpus-membership assumption
is used. Array lookup reduces to the pure software binary64 table body.
-/

namespace Lean1090.Proofs.CommBTables
open Impl

set_option maxHeartbeats 2000000
set_option maxRecDepth 4000

private theorem density40 (word : Nat) :
    cbDensityTermsFast 0x40 word = cbDensityTerms 0x40 word := by
  simp [cbDensityTermsFast, cbDensityTerms, cbDensityTableGet,
    cbQNHScoreTable, cbSelectedScoreTable, commBValue, commBLayout,
    bds40Layout, cbColumn, payloadValue, cbScoreField, cbQNH64]
  repeat' split <;> simp_all

private theorem density50 (word : Nat) :
    cbDensityTermsFast 0x50 word = cbDensityTerms 0x50 word := by
  simp [cbDensityTermsFast, cbDensityTerms, cbDensityTableGet,
    cbRollScoreTable, cbRateScoreTable, cbTASScoreTable,
    cbGroundSpeedScoreTable, commBValue, commBLayout,
    bds50Layout, cbColumn, payloadValue, cbScoreField, payloadInteger]
  have power : (2 : Rat)^10 = 1024 := by norm_num
  by_cases h1 : payloadBits word 1 1 = 0 <;>
    by_cases h35 : payloadBits word 35 1 = 0 <;>
    by_cases h37 : payloadBits word 37 9 = 511 <;>
    by_cases h46 : payloadBits word 46 1 = 0 <;>
    by_cases h24 : payloadBits word 24 1 = 0 <;>
    simp_all

private theorem verticalMagnitude (word : Nat) :
    payloadBits word 47 10 % 512 = payloadBits word 48 9 := by
  simp [PayloadBits.payloadBits_eq, Spec.payloadBits, Nat.mod_mod_of_dvd]

private theorem density60 (word : Nat) :
    cbDensityTermsFast 0x60 word = cbDensityTerms 0x60 word := by
  simp [cbDensityTermsFast, cbDensityTerms, cbDensityTableGet,
    cbIASScoreTable, cbMachScoreTable, cbVerticalScoreTable,
    commBValue, commBLayout, bds60Layout, cbColumn, payloadValue,
    cbScoreField, CommBMach.cbMach64_eq_runtime, cbVertical60, cbSigned, verticalMagnitude,
    payloadInteger]
  have power : (2 : Rat)^10 = 1024 := by norm_num
  by_cases h13 : payloadBits word 13 1 = 0 <;>
    by_cases h24 : payloadBits word 24 1 = 0 <;>
    by_cases h46 : payloadBits word 46 1 = 0 <;> simp_all

private theorem density44 (word : Nat) :
    cbDensityTermsFast 0x44 word = cbDensityTerms 0x44 word := by
  simp [cbDensityTermsFast, cbDensityTerms, cbDensityTableGet,
    cbTemperature44ScoreTable, cbWindScoreTable, cbPressureScoreTable,
    commBValue, commBLayout, bds44Layout, cbColumn, payloadValue,
    cbScoreField, cbTemperature44, cbSigned, payloadInteger]
  have power : (2 : Rat)^11 = 2048 := by norm_num
  by_cases h5 : payloadBits word 5 1 = 0 <;>
    by_cases h35 : payloadBits word 35 1 = 0 <;> simp_all

private theorem density45 (word : Nat) :
    cbDensityTermsFast 0x45 word = cbDensityTerms 0x45 word := by
  simp [cbDensityTermsFast, cbDensityTerms, cbDensityTableGet,
    cbTemperature45ScoreTable, cbPressureScoreTable, commBValue,
    commBLayout, bds45Layout, cbColumn, payloadValue,
    cbScoreField, payloadInteger]
  have power : (2 : Rat)^10 = 1024 := by norm_num
  by_cases h16 : payloadBits word 16 1 = 0 <;>
    by_cases h27 : payloadBits word 27 1 = 0 <;> simp_all

/-- All field-code table lookups equal the software reference, for every
register and every natural-number payload, including over-wide payloads. -/
theorem density_terms_eq (register word : Nat) :
    cbDensityTermsFast register word = cbDensityTerms register word := by
  by_cases h40 : register = 0x40
  · subst register; exact density40 word
  by_cases h50 : register = 0x50
  · subst register; exact density50 word
  by_cases h60 : register = 0x60
  · subst register; exact density60 word
  by_cases h44 : register = 0x44
  · subst register; exact density44 word
  by_cases h45 : register = 0x45
  · subst register; exact density45 word
  simp_all [cbDensityTermsFast, cbDensityTerms]

/-- The exact field order has at most four terms, with no validity hypothesis. -/
theorem density_terms_length (register word : Nat) :
    (cbDensityTermsFast register word).length ≤ 4 := by
  rw [density_terms_eq]
  unfold cbDensityTerms
  split <;> simp only [List.length_append, List.length_cons, List.length_nil]
  all_goals try omega
  all_goals simp only [cbScoreField]
  all_goals repeat' split <;> simp_all

#print axioms density_terms_eq
#print axioms density_terms_length

end Lean1090.Proofs.CommBTables

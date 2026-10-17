import Spec.CommBArithmetic

namespace Lean1090.Spec

/-- Concrete nonempty wire examples for every direct register codec. These
are hand-selected field assignments, not discovered by searching the decoder.
BDS65 is a direct codec witness: per-message inference never returns it. -/
def bdsWitnessWord : Nat → Nat
  | 0x05 => 0x48000000000000
  | 0x10 => 0x10000000000000
  | 0x17 => 0x02000000000000
  | 0x18 => 0x00000081c00000
  | 0x19 => 0x00100000000000
  | 0x20 => 0x202cc371c31de0
  | 0x21 => 0x80000000000000
  | 0x30 => 0x30000000000000
  | 0x40 => 0x80000000000000
  | 0x44 => 0x10000000000000
  | 0x45 => 0x00010000000000
  | 0x50 => 0x80000000000000
  | 0x60 => 0x80000000000000
  | 0x65 => 0xf8000000000000
  | _ => 0

/-- Concrete witnesses split into independent named field assignments using
source table positions; no source-word field is stored in the resulting record. -/
def bdsWitness (register : Nat) : PayloadRecord :=
  let word := bdsWitnessWord register
  ⟨register, decodePayloadFields ((bdsLayout register word).getD []) word⟩

/-- Concrete inhabitant of the BDS05 assignment domain. -/
theorem bds05_nonvacuous : ValidBDS (bdsWitness 0x05) := by decide +kernel

/-- Concrete inhabitant of the BDS10 assignment domain. -/
theorem bds10_nonvacuous : ValidBDS (bdsWitness 0x10) := by decide +kernel

/-- Concrete inhabitant of the BDS17 assignment domain. -/
theorem bds17_nonvacuous : ValidBDS (bdsWitness 0x17) := by decide +kernel

/-- Concrete inhabitant of the BDS18 assignment domain. -/
theorem bds18_nonvacuous : ValidBDS (bdsWitness 0x18) := by decide +kernel

/-- Concrete inhabitant of the BDS19 assignment domain. -/
theorem bds19_nonvacuous : ValidBDS (bdsWitness 0x19) := by decide +kernel

/-- Concrete inhabitant of the BDS20 assignment domain. -/
theorem bds20_nonvacuous : ValidBDS (bdsWitness 0x20) := by decide +kernel

/-- Concrete inhabitant of the BDS21 assignment domain. -/
theorem bds21_nonvacuous : ValidBDS (bdsWitness 0x21) := by decide +kernel

/-- Concrete inhabitant of the BDS30 assignment domain. -/
theorem bds30_nonvacuous : ValidBDS (bdsWitness 0x30) := by decide +kernel

/-- Concrete inhabitant of the BDS40 assignment domain. -/
theorem bds40_nonvacuous : ValidBDS (bdsWitness 0x40) := by decide +kernel

/-- Concrete inhabitant of the BDS44 assignment domain. -/
theorem bds44_nonvacuous : ValidBDS (bdsWitness 0x44) := by decide +kernel

/-- Concrete inhabitant of the BDS45 assignment domain. -/
theorem bds45_nonvacuous : ValidBDS (bdsWitness 0x45) := by decide +kernel

/-- Concrete inhabitant of the BDS50 assignment domain. -/
theorem bds50_nonvacuous : ValidBDS (bdsWitness 0x50) := by decide +kernel

/-- Concrete inhabitant of the BDS60 assignment domain. -/
theorem bds60_nonvacuous : ValidBDS (bdsWitness 0x60) := by decide +kernel

/-- Concrete inhabitant of the BDS65 assignment domain. -/
theorem bds65_nonvacuous : ValidBDS (bdsWitness 0x65) := by decide +kernel

/-- Sun (2nd ed.) table17.2: GS1000kt and TAS60kt are representable
wire assignments, though both violate the oracle's civil-airliner envelope. -/
def bds50FullDomainWord : Nat := 0x17d00041e

/-- Independent named field assignment for the full-range source witness. -/
def bds50FullDomain : PayloadRecord :=
  ⟨0x50, decodePayloadFields bds50Layout bds50FullDomainWord⟩

/-- The broader field-code round-trip domain is genuinely broader: it accepts
and reconstructs source-representable speeds that the compatibility decoder
rejects. This prevents a plausible-flight filter weakening the source capstone. -/
theorem bdsFields_nonvacuous :
    ValidBDSFields bds50FullDomain ∧
    decodeBDSFields 0x50 (encodeBDS bds50FullDomain) = some bds50FullDomain ∧
    commBValue 0x50 bds50FullDomainWord "groundspeed" = some 1000 ∧
    commBValue 0x50 bds50FullDomainWord "TAS" = some 60 ∧
    decodeBDS 0x50 bds50FullDomainWord = none := by decide +kernel

/-- Every one of the fourteen direct register schemas has a structurally valid
assignment, independent of candidate inference or its acceptance thresholds. -/
theorem bdsAllFields_nonvacuous :
    ∀ r ∈ commBRegisters, ValidBDSFields (bdsWitness r) := by decide +kernel

/-- Non-vacuity of inference including the binary64 density gate: a present
MCP selected altitude of0ft passes with its actual score (about -2.59). The
conclusion verifies actual list membership, not just a nonempty field domain. -/
theorem commBInference_nonvacuous :
    commBEligible 20 none 0x40 (bdsWitnessWord 0x40) = true ∧
    (0x40, bdsWitness 0x40) ∈ inferCommB 20 none (bdsWitnessWord 0x40) := by
  decide +kernel

/-- Concrete domain witness for the finite-arithmetic capstone, including
valid fields, successful score-based inference and every traced intermediate. -/
theorem commBArithmetic_nonvacuous :
    bdsWireValid 0x40 (bdsWitnessWord 0x40) = true ∧
    commBEligible 20 none 0x40 (bdsWitnessWord 0x40) = true ∧
    CommBScoreArithmeticFinite 0x40 (bdsWitnessWord 0x40) := by
  decide +kernel

end Lean1090.Spec

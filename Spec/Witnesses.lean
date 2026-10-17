import Spec.Message
import Spec.CommBWitnesses
import Spec.CPRFormula
import Spec.CPRContracts

/-! Concrete domains for the checkpoint-1 capstones. These are actual proved
lemmas, unlike the main universally quantified capstone propositions. Format
sources are those on the referenced definitions; kernel evaluation is used
rather than a runtime-trusted proof decision procedure. -/
namespace Lean1090.Spec

/-- Annex10 IV (4th ed., 2007) §3.1.2.5.2.2: a concrete DF11 field assignment. -/
def messageWitness : Message := assigned (withOverlay (.allCall 5 0x406b90) 0)

/-- Refinement quantifies all inputs; this valid nonempty message establishes
that its domain also includes successful decoding, not only malformed inputs. -/
theorem refinement_nonvacuous :
    Valid messageWitness.fields ∧ decode (encode messageWitness) = some messageWitness := by
  decide +kernel

/-- Both round-trip implications have a concrete successful input/output
for each format family, including standard Comm-D despite the oracle bug. -/
theorem roundTrips_nonvacuous :
    ∀ f ∈ frameWitnesses,
      Valid f ∧ decode (encode (assigned f)) = some (assigned f) := by
  decide +kernel

/-- The prefix contract includes an actual nonempty unused suffix. -/
theorem prefix_nonvacuous :
    decodePrefix (encode messageWitness ++ [0xAA]) = some (messageWitness, [0xAA]) := by
  decide +kernel

/-- Annex10 IV polynomial domain witness: published example has zero CRC.
The polynomial-equality capstone itself has no extra hypotheses. -/
theorem crc_polynomial_nonvacuous :
    0x8D406B902015A678D4D220AA4BDA < 2^112 ∧
    Parity.syndrome 112 0x8D406B902015A678D4D220AA4BDA = 0 := by decide +kernel

/-- XOR-linearity has concrete nonzero operands; no oracle agreement or
CRC-validity assumption restricts its universal domain. -/
theorem crc_linear_nonvacuous :
    Parity.syndrome 56 (1 ^^^ 2) =
      Parity.syndrome 56 1 ^^^ Parity.syndrome 56 2 := by decide +kernel

/-- Both allowed frame widths contain distinct first/last single-bit errors
with nonzero and unequal syndromes. This does not substitute for all bit pairs. -/
theorem crc_singleBit_nonvacuous :
    (Parity.syndrome 56 1 ≠ 0 ∧ Parity.syndrome 56 (2^55) ≠ 0 ∧
      Parity.syndrome 56 1 ≠ Parity.syndrome 56 (2^55)) ∧
    (Parity.syndrome 112 1 ≠ 0 ∧ Parity.syndrome 112 (2^111) ≠ 0 ∧
      Parity.syndrome 112 1 ≠ Parity.syndrome 112 (2^111)) := by decide +kernel

/-- A real DF11-sized information word with nonzero seven-bit PI overlay
satisfies every overlay theorem hypothesis and recovers the chosen overlay. -/
theorem parity_overlay_nonvacuous :
    0x5D406B90 < 2^32 ∧
    Parity.syndrome 56 (0x5D406B90*2^24 +
      (Parity.overlay 32 0x5D406B90 0x55).toNat) = 0x55 := by decide +kernel

/-- Nonintegral representable-step assignments fail both altitude domains;
invalid received-code witness is Altitude.invalid_gillham_nonvacuous. -/
theorem altitude_rejection_nonvacuous :
    ¬ Altitude.Representable25 1 ∧ ¬ Altitude.RepresentableGillham 1 := by
  unfold Altitude.Representable25 Altitude.RepresentableGillham
  decide +kernel

/-- NL certification is a real finite obligation with57 candidate intervals,
not an empty list. Attainable-latitude witness is CPR.nl_nonvacuous. -/
theorem nl_certificate_nonvacuous :
    CPR.nlCertificates.length = 57 ∧
    ⟨59,10470471299968,10470471300000⟩ ∈ CPR.nlCertificates := by
  constructor
  · decide +kernel
  · exact List.mem_cons_self

/-- All arithmetic-domain capstone premises hold for a scored BDS40 payload;
CommBWitnesses also proves its inference membership and finite trace. -/
theorem commB_arithmetic_domain_nonvacuous :
    0x40 ∈ commBCoreRegisters ∧ bdsWitnessWord 0x40 < 2^56 := by decide +kernel

end Lean1090.Spec

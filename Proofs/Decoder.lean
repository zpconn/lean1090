import Impl.Message
import Capstones
import Proofs.CommBTables
import Proofs.ScoreGate
import Proofs.ParityBits
import Proofs.PayloadBits
import Proofs.CommBMach
import Proofs.SyndromeReuse
import Proofs.AffineValue
/-!
The first complete implementation preserves the frozen pure algorithms while
separating their executable dependencies from the specification and Mathlib.
These proofs bind the real runtime functions and the complete Message result,
including exact semantic values and numerical expression trees. Component
equalities make the all-input proof modular and keep kernel reduction bounded.
-/
namespace Lean1090.Proofs
private theorem decoder_ACASFields_parts_eq : @Impl.acasParts = @Spec.ACASFields.parts := by
  rfl
private theorem decoder_Altitude_bit_eq : @Impl.Altitude.bit = @Spec.Altitude.bit := by
  rfl
private theorem decoder_Altitude_gray100_eq : @Impl.Altitude.gray100 = @Spec.Altitude.gray100 := by
  unfold Impl.Altitude.gray100 Spec.Altitude.gray100
  simp only [decoder_Altitude_bit_eq]
private theorem decoder_Altitude_gray500_eq : @Impl.Altitude.gray500 = @Spec.Altitude.gray500 := by
  unfold Impl.Altitude.gray500 Spec.Altitude.gray500
  simp only [decoder_Altitude_bit_eq]
private theorem decoder_Altitude_grayDecode_eq : @Impl.Altitude.grayDecode = @Spec.Altitude.grayDecode := by
  rfl
private theorem decoder_Altitude_validGillham_eq :
    @Impl.Altitude.validGillham = @Spec.Altitude.validGillham := by
  unfold Impl.Altitude.validGillham Spec.Altitude.validGillham
  simp only [decoder_Altitude_bit_eq, decoder_Altitude_gray100_eq, decoder_Altitude_grayDecode_eq]
private theorem decoder_Altitude_decodeGillham_eq :
    @Impl.Altitude.decodeGillham = @Spec.Altitude.decodeGillham := by
  unfold Impl.Altitude.decodeGillham Spec.Altitude.decodeGillham
  simp only [decoder_Altitude_gray100_eq, decoder_Altitude_gray500_eq, decoder_Altitude_grayDecode_eq,
    decoder_Altitude_validGillham_eq]
private theorem decoder_Altitude_decodeAC13_eq : @Impl.Altitude.decodeAC13 = @Spec.Altitude.decodeAC13 := by
  unfold Impl.Altitude.decodeAC13 Spec.Altitude.decodeAC13
  simp only [decoder_Altitude_bit_eq, decoder_Altitude_decodeGillham_eq]
private theorem decoder_Altitude_expandAC12_eq : @Impl.Altitude.expandAC12 = @Spec.Altitude.expandAC12 := by
  rfl
private theorem decoder_Altitude_decodeAC12_eq : @Impl.Altitude.decodeAC12 = @Spec.Altitude.decodeAC12 := by
  unfold Impl.Altitude.decodeAC12 Spec.Altitude.decodeAC12
  simp only [decoder_Altitude_decodeAC13_eq, decoder_Altitude_expandAC12_eq]
  rfl
private theorem decoder_Altitude_decodeGNSSMetres_eq :
    @Impl.Altitude.decodeGNSSMetres = @Spec.Altitude.decodeGNSSMetres := by
  rfl
private theorem decoder_Altitude_oracleAC12_eq : @Impl.Altitude.oracleAC12 = @Spec.Altitude.oracleAC12 := by
  unfold Impl.Altitude.oracleAC12 Spec.Altitude.oracleAC12
  simp only [decoder_Altitude_decodeAC12_eq]
  rfl
private theorem decoder_Altitude_oracleAC13_eq : @Impl.Altitude.oracleAC13 = @Spec.Altitude.oracleAC13 := by
  unfold Impl.Altitude.oracleAC13 Spec.Altitude.oracleAC13
  simp only [decoder_Altitude_bit_eq, decoder_Altitude_decodeAC13_eq]
  rfl
private theorem decoder_Binary64_powerTwo_eq : @Impl.Binary64.powerTwo = @Spec.Binary64.powerTwo := by
  rfl
private theorem decoder_Binary64_exponent_eq : @Impl.Binary64.exponent = @Spec.Binary64.exponent := by
  unfold Impl.Binary64.exponent Spec.Binary64.exponent
  simp only [decoder_Binary64_powerTwo_eq]
private theorem decoder_Binary64_nearestEven_eq :
    @Impl.Binary64.nearestEven = @Spec.Binary64.nearestEven := by
  rfl
private theorem decoder_Binary64_round_eq : @Impl.Binary64.round = @Spec.Binary64.round := by
  unfold Impl.Binary64.round Spec.Binary64.round
  simp only [decoder_Binary64_exponent_eq, decoder_Binary64_nearestEven_eq, decoder_Binary64_powerTwo_eq]
private theorem decoder_Binary64_add_eq : @Impl.Binary64.add = @Spec.Binary64.add := by
  unfold Impl.Binary64.add Spec.Binary64.add
  simp only [decoder_Binary64_round_eq]
private theorem decoder_Binary64_div_eq : @Impl.Binary64.div = @Spec.Binary64.div := by
  unfold Impl.Binary64.div Spec.Binary64.div
  simp only [decoder_Binary64_round_eq]
private theorem decoder_Binary64_literal_eq : @Impl.Binary64.literal = @Spec.Binary64.literal := by
  unfold Impl.Binary64.literal Spec.Binary64.literal
  simp only [decoder_Binary64_round_eq]
private theorem decoder_Binary64_mul_eq : @Impl.Binary64.mul = @Spec.Binary64.mul := by
  unfold Impl.Binary64.mul Spec.Binary64.mul
  simp only [decoder_Binary64_round_eq]
private theorem decoder_Binary64_sub_eq : @Impl.Binary64.sub = @Spec.Binary64.sub := by
  unfold Impl.Binary64.sub Spec.Binary64.sub
  simp only [decoder_Binary64_round_eq]
private theorem decoder_FrameBody_informationBits_eq :
    @Impl.informationBits = @Spec.FrameBody.informationBits := by
  rfl
private theorem decoder_SurveillanceFields_parts_eq :
    @Impl.surveillanceParts = @Spec.SurveillanceFields.parts := by
  rfl
private theorem decoder_FrameBody_parts_eq : @Impl.frameParts = @Spec.FrameBody.parts := by
  unfold Impl.frameParts Spec.FrameBody.parts
  simp only [decoder_ACASFields_parts_eq, decoder_SurveillanceFields_parts_eq]
  rfl
private theorem decoder_Parity_generator_eq : @Impl.Parity.generator = @Spec.Parity.generator := by
  rfl
private theorem decoder_Parity_step_eq : @Impl.Parity.step = @Spec.Parity.step := by
  unfold Impl.Parity.step Spec.Parity.step
  simp only [decoder_Parity_generator_eq]
  rfl
private theorem decoder_Parity_syndrome_eq : @Impl.Parity.syndrome = @Spec.Parity.syndrome := by
  funext width word
  unfold Impl.Parity.syndrome Spec.Parity.syndrome
  simp only [ParityBits.cachedBit_eq, decoder_Parity_step_eq]
private theorem decoder_Parity_checksum_eq : @Impl.Parity.checksum = @Spec.Parity.checksum := by
  unfold Impl.Parity.checksum Spec.Parity.checksum
  simp only [decoder_Parity_syndrome_eq]
private theorem decoder_Parity_interrogator_eq : @Impl.Parity.interrogator = @Spec.Parity.interrogator := by
  rfl
private theorem decoder_Presentation_scaled_eq : @Impl.Presentation.scaled = @Spec.Presentation.scaled := by
  rfl
private theorem decoder_Presentation_velocitySpeed_eq :
    @Impl.Presentation.velocitySpeed = @Spec.Presentation.velocitySpeed := by
  rfl
private theorem decoder_Presentation_oraclePi_eq :
    @Impl.Presentation.oraclePi = @Spec.Presentation.oraclePi := by
  rfl
private theorem decoder_Presentation_velocityTrack_eq :
    @Impl.Presentation.velocityTrack = @Spec.Presentation.velocityTrack := by
  unfold Impl.Presentation.velocityTrack Spec.Presentation.velocityTrack
  simp only [decoder_Presentation_oraclePi_eq]
private theorem decoder_adsbMovement_eq : @Impl.adsbMovement = @Spec.adsbMovement := by
  rfl
private theorem decoder_payloadBits_eq : @Impl.payloadBits = @Spec.payloadBits := by
  funext word start width
  exact PayloadBits.payloadBits_eq word start width
private theorem decoder_adsbOracleVelocityComponents_eq :
    @Impl.adsbOracleVelocityComponents = @Spec.adsbOracleVelocityComponents := by
  unfold Impl.adsbOracleVelocityComponents Spec.adsbOracleVelocityComponents
  simp only [decoder_payloadBits_eq]
private theorem decoder_Presentation_oracleADSBFloats_eq :
    @Impl.Presentation.oracleADSBFloats = @Spec.Presentation.oracleADSBFloats := by
  unfold Impl.Presentation.oracleADSBFloats Spec.Presentation.oracleADSBFloats
  simp only [decoder_Presentation_scaled_eq, decoder_Presentation_velocitySpeed_eq,
    decoder_Presentation_velocityTrack_eq, decoder_adsbMovement_eq,
    decoder_adsbOracleVelocityComponents_eq, decoder_payloadBits_eq]
private theorem decoder_Presentation_signedCode_eq :
    @Impl.Presentation.signedCode = @Spec.Presentation.signedCode := by
  unfold Impl.Presentation.signedCode Spec.Presentation.signedCode
  simp only [decoder_payloadBits_eq]
private theorem decoder_Presentation_oracleMeteoTemperature_eq :
    @Impl.Presentation.oracleMeteoTemperature = @Spec.Presentation.oracleMeteoTemperature := by
  unfold Impl.Presentation.oracleMeteoTemperature Spec.Presentation.oracleMeteoTemperature
  simp only [decoder_Presentation_signedCode_eq]
private theorem decoder_Presentation_statusValue_eq :
    @Impl.Presentation.statusValue = @Spec.Presentation.statusValue := by
  unfold Impl.Presentation.statusValue Spec.Presentation.statusValue
  simp only [decoder_payloadBits_eq]
private theorem decoder_Presentation_oracleCommBFloats_eq :
    @Impl.Presentation.oracleCommBFloats = @Spec.Presentation.oracleCommBFloats := by
  unfold Impl.Presentation.oracleCommBFloats Spec.Presentation.oracleCommBFloats
  simp only [decoder_Presentation_oracleMeteoTemperature_eq, decoder_Presentation_scaled_eq,
    decoder_Presentation_signedCode_eq, decoder_Presentation_statusValue_eq, decoder_payloadBits_eq]
  rfl
private theorem decoder_Presentation_oracleVerticalSource_eq :
    @Impl.Presentation.oracleVerticalSource = @Spec.Presentation.oracleVerticalSource := by
  unfold Impl.Presentation.oracleVerticalSource Spec.Presentation.oracleVerticalSource
  simp only [decoder_payloadBits_eq]
private theorem decoder_Presentation_standardGNSSHeightMetres_eq :
    @Impl.Presentation.standardGNSSHeightMetres = @Spec.Presentation.standardGNSSHeightMetres := by
  unfold Impl.Presentation.standardGNSSHeightMetres Spec.Presentation.standardGNSSHeightMetres
  simp only [decoder_payloadBits_eq]
private theorem decoder_adsbSigned_eq : @Impl.adsbSigned = @Spec.adsbSigned := by
  rfl
private theorem decoder_Presentation_standardGeoMinusBaro_eq :
    @Impl.Presentation.standardGeoMinusBaro = @Spec.Presentation.standardGeoMinusBaro := by
  unfold Impl.Presentation.standardGeoMinusBaro Spec.Presentation.standardGeoMinusBaro
  simp only [decoder_adsbSigned_eq, decoder_payloadBits_eq]
private theorem decoder_Presentation_standardVelocityComponents_eq :
    @Impl.Presentation.standardVelocityComponents = @Spec.Presentation.standardVelocityComponents := by
  unfold Impl.Presentation.standardVelocityComponents Spec.Presentation.standardVelocityComponents
  simp only [decoder_adsbSigned_eq, decoder_payloadBits_eq]
private theorem decoder_Presentation_standardVerticalSource_eq :
    @Impl.Presentation.standardVerticalSource = @Spec.Presentation.standardVerticalSource := by
  unfold Impl.Presentation.standardVerticalSource Spec.Presentation.standardVerticalSource
  simp only [decoder_payloadBits_eq]
private theorem decoder_Semantics_emergency_eq : @Impl.Semantics.emergency = @Spec.Semantics.emergency := by
  rfl
private theorem decoder_Semantics_wakeVortex_eq :
    @Impl.Semantics.wakeVortex = @Spec.Semantics.wakeVortex := by
  rfl
private theorem decoder_adsbCharacter_eq : @Impl.adsbCharacter = @Spec.adsbCharacter := by
  rfl
private theorem decoder_adsbCallsign_eq : @Impl.adsbCallsign = @Spec.adsbCallsign := by
  unfold Impl.adsbCallsign Spec.adsbCallsign
  simp only [decoder_adsbCharacter_eq, decoder_payloadBits_eq]
private theorem decoder_Semantics_adsbLabels_eq :
    @Impl.Semantics.adsbLabels = @Spec.Semantics.adsbLabels := by
  unfold Impl.Semantics.adsbLabels Spec.Semantics.adsbLabels
  simp only [decoder_Presentation_oracleVerticalSource_eq, decoder_Presentation_standardVerticalSource_eq,
    decoder_Semantics_emergency_eq, decoder_Semantics_wakeVortex_eq, decoder_adsbCallsign_eq,
    decoder_payloadBits_eq]
private theorem decoder_adsbAirspeed_eq : @Impl.adsbAirspeed = @Spec.adsbAirspeed := by
  unfold Impl.adsbAirspeed Spec.adsbAirspeed
  simp only [decoder_payloadBits_eq]
private theorem decoder_adsbBarometricSetting_eq :
    @Impl.adsbBarometricSetting = @Spec.adsbBarometricSetting := by
  unfold Impl.adsbBarometricSetting Spec.adsbBarometricSetting
  simp only [decoder_payloadBits_eq]
private theorem decoder_adsbNUCp_eq : @Impl.adsbNUCp = @Spec.adsbNUCp := by
  rfl
private theorem decoder_adsbSelectedAltitude_eq :
    @Impl.adsbSelectedAltitude = @Spec.adsbSelectedAltitude := by
  unfold Impl.adsbSelectedAltitude Spec.adsbSelectedAltitude
  simp only [decoder_payloadBits_eq]
private theorem decoder_adsbVerticalRate_eq : @Impl.adsbVerticalRate = @Spec.adsbVerticalRate := by
  unfold Impl.adsbVerticalRate Spec.adsbVerticalRate
  simp only [decoder_adsbSigned_eq, decoder_payloadBits_eq]
private theorem decoder_identityCode_eq : @Impl.identityCode = @Spec.identityCode := by
  rfl
private theorem decoder_Semantics_adsbStandardValues_eq :
    @Impl.Semantics.adsbStandardValues = @Spec.Semantics.adsbStandardValues := by
  unfold Impl.Semantics.adsbStandardValues Spec.Semantics.adsbStandardValues
  simp only [decoder_Altitude_decodeAC12_eq, decoder_Presentation_standardGNSSHeightMetres_eq,
    decoder_Presentation_standardGeoMinusBaro_eq, decoder_Presentation_standardVelocityComponents_eq,
    decoder_adsbAirspeed_eq, decoder_adsbBarometricSetting_eq, decoder_adsbMovement_eq,
    decoder_adsbNUCp_eq, decoder_adsbSelectedAltitude_eq, decoder_adsbVerticalRate_eq,
    decoder_identityCode_eq, decoder_payloadBits_eq]
private theorem decoder_adsbAltitude_eq : @Impl.adsbAltitude = @Spec.adsbAltitude := by
  unfold Impl.adsbAltitude Spec.adsbAltitude
  simp only [decoder_Altitude_oracleAC12_eq, decoder_payloadBits_eq]
private theorem decoder_adsbGeoMinusBaro_eq : @Impl.adsbGeoMinusBaro = @Spec.adsbGeoMinusBaro := by
  unfold Impl.adsbGeoMinusBaro Spec.adsbGeoMinusBaro
  simp only [decoder_adsbSigned_eq, decoder_payloadBits_eq]
private theorem decoder_Semantics_oracleReservedVelocityData_eq :
    @Impl.Semantics.oracleReservedVelocityData = @Spec.Semantics.oracleReservedVelocityData := by
  unfold Impl.Semantics.oracleReservedVelocityData Spec.Semantics.oracleReservedVelocityData
  simp only [decoder_payloadBits_eq]
private theorem decoder_Semantics_adsbOracleValues_eq :
    @Impl.Semantics.adsbOracleValues = @Spec.Semantics.adsbOracleValues := by
  unfold Impl.Semantics.adsbOracleValues Spec.Semantics.adsbOracleValues
  simp only [decoder_Semantics_oracleReservedVelocityData_eq,
    decoder_Semantics_adsbStandardValues_eq, decoder_adsbAirspeed_eq, decoder_adsbAltitude_eq,
    decoder_adsbGeoMinusBaro_eq, decoder_adsbNUCp_eq, decoder_adsbOracleVelocityComponents_eq,
    decoder_adsbVerticalRate_eq, decoder_payloadBits_eq]
private theorem decoder_Semantics_adsbStandardFloats_eq :
    @Impl.Semantics.adsbStandardFloats = @Spec.Semantics.adsbStandardFloats := by
  unfold Impl.Semantics.adsbStandardFloats Spec.Semantics.adsbStandardFloats
  simp only [decoder_Presentation_oracleADSBFloats_eq, decoder_Presentation_standardVelocityComponents_eq,
    decoder_Presentation_velocitySpeed_eq, decoder_Presentation_velocityTrack_eq, decoder_payloadBits_eq]
private theorem decoder_payloadInteger_eq : @Impl.payloadInteger = @Spec.payloadInteger := by
  rfl
private theorem decoder_payloadValue_eq : @Impl.payloadValue = @Spec.payloadValue := by
  funext column word
  exact AffineValue.payloadValue_eq column word
private theorem decoder_Semantics_tableValues_eq :
    @Impl.Semantics.tableValues = @Spec.Semantics.tableValues := by
  unfold Impl.Semantics.tableValues Spec.Semantics.tableValues
  simp only [decoder_payloadValue_eq]
private theorem decoder_adsbKind_eq : @Impl.adsbKind = @Spec.adsbKind := by
  unfold Impl.adsbKind Spec.adsbKind
  simp only [decoder_payloadBits_eq]
private theorem decoder_adsbIdentificationLayout_eq :
    @Impl.adsbIdentificationLayout = @Spec.adsbIdentificationLayout := by
  rfl
private theorem decoder_adsbOperationPrefix_eq : @Impl.adsbOperationPrefix = @Spec.adsbOperationPrefix := by
  rfl
private theorem decoder_adsbOperationSuffix_eq : @Impl.adsbOperationSuffix = @Spec.adsbOperationSuffix := by
  rfl
private theorem decoder_adsbPositionLayout_eq : @Impl.adsbPositionLayout = @Spec.adsbPositionLayout := by
  rfl
private theorem decoder_adsbStatusLayout_eq : @Impl.adsbStatusLayout = @Spec.adsbStatusLayout := by
  rfl
private theorem decoder_adsbSurfaceLayout_eq : @Impl.adsbSurfaceLayout = @Spec.adsbSurfaceLayout := by
  rfl
private theorem decoder_adsbTargetLayout_eq : @Impl.adsbTargetLayout = @Spec.adsbTargetLayout := by
  rfl
private theorem decoder_adsbVelocityLayout_eq : @Impl.adsbVelocityLayout = @Spec.adsbVelocityLayout := by
  rfl
private theorem decoder_adsbLayoutOfKind_eq : @Impl.adsbLayoutOfKind = @Spec.adsbLayoutOfKind := by
  unfold Impl.adsbLayoutOfKind Spec.adsbLayoutOfKind
  simp only [decoder_adsbIdentificationLayout_eq, decoder_adsbOperationPrefix_eq,
    decoder_adsbOperationSuffix_eq, decoder_adsbPositionLayout_eq, decoder_adsbStatusLayout_eq,
    decoder_adsbSurfaceLayout_eq, decoder_adsbTargetLayout_eq, decoder_adsbVelocityLayout_eq]
private theorem decoder_adsbLayout_eq : @Impl.adsbLayout = @Spec.adsbLayout := by
  unfold Impl.adsbLayout Spec.adsbLayout
  simp only [decoder_adsbKind_eq, decoder_adsbLayoutOfKind_eq]
private theorem decoder_Semantics_adsb_eq : @Impl.Semantics.adsb = @Spec.Semantics.adsb := by
  unfold Impl.Semantics.adsb Spec.Semantics.adsb
  simp only [decoder_Presentation_oracleADSBFloats_eq, decoder_Semantics_adsbLabels_eq,
    decoder_Semantics_adsbOracleValues_eq, decoder_Semantics_adsbStandardFloats_eq,
    decoder_Semantics_adsbStandardValues_eq, decoder_Semantics_tableValues_eq, decoder_adsbLayout_eq]
private theorem decoder_cbCharacter_eq : @Impl.cbCharacter = @Spec.cbCharacter := by
  rfl
private theorem decoder_cbDashPlaceholder_eq : @Impl.cbDashPlaceholder = @Spec.cbDashPlaceholder := by
  rfl
private theorem decoder_Semantics_airline_eq : @Impl.Semantics.airline = @Spec.Semantics.airline := by
  unfold Impl.Semantics.airline Spec.Semantics.airline
  simp only [decoder_cbCharacter_eq, decoder_cbDashPlaceholder_eq, decoder_payloadBits_eq]
private theorem decoder_Semantics_hazard_eq : @Impl.Semantics.hazard = @Spec.Semantics.hazard := by
  rfl
private theorem decoder_cbCallsign_eq : @Impl.cbCallsign = @Spec.cbCallsign := by
  unfold Impl.cbCallsign Spec.cbCallsign
  simp only [decoder_cbCharacter_eq, decoder_payloadBits_eq]
private theorem decoder_cbRegistrationCodes_eq : @Impl.cbRegistrationCodes = @Spec.cbRegistrationCodes := by
  unfold Impl.cbRegistrationCodes Spec.cbRegistrationCodes
  simp only [decoder_cbDashPlaceholder_eq, decoder_payloadBits_eq]
private theorem decoder_cbRegistration_eq : @Impl.cbRegistration = @Spec.cbRegistration := by
  unfold Impl.cbRegistration Spec.cbRegistration
  simp only [decoder_cbCharacter_eq, decoder_cbRegistrationCodes_eq, decoder_payloadBits_eq]
private theorem decoder_cbSelected_eq : @Impl.cbSelected = @Spec.cbSelected := by
  rfl
private theorem decoder_cbSigned_eq : @Impl.cbSigned = @Spec.cbSigned := by
  unfold Impl.cbSigned Spec.cbSigned
  simp only [decoder_payloadBits_eq, decoder_payloadInteger_eq]
private theorem decoder_cbTemperature44_eq : @Impl.cbTemperature44 = @Spec.cbTemperature44 := by
  unfold Impl.cbTemperature44 Spec.cbTemperature44
  simp only [decoder_cbSigned_eq]
private theorem decoder_cbVertical60_eq : @Impl.cbVertical60 = @Spec.cbVertical60 := by
  unfold Impl.cbVertical60 Spec.cbVertical60
  simp only [decoder_cbSigned_eq, decoder_payloadBits_eq]
private theorem decoder_cbWrapAngle_eq : @Impl.cbWrapAngle = @Spec.cbWrapAngle := by
  rfl
private theorem decoder_cbColumn_eq : @Impl.cbColumn = @Spec.cbColumn := by
  rfl
private theorem decoder_bds10Layout_eq : @Impl.bds10Layout = @Spec.bds10Layout := by
  unfold Impl.bds10Layout Spec.bds10Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds17Layout_eq : @Impl.bds17Layout = @Spec.bds17Layout := by
  unfold Impl.bds17Layout Spec.bds17Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds18Layout_eq : @Impl.bds18Layout = @Spec.bds18Layout := by
  unfold Impl.bds18Layout Spec.bds18Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds19Layout_eq : @Impl.bds19Layout = @Spec.bds19Layout := by
  unfold Impl.bds19Layout Spec.bds19Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds20Layout_eq : @Impl.bds20Layout = @Spec.bds20Layout := by
  unfold Impl.bds20Layout Spec.bds20Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds21Layout_eq : @Impl.bds21Layout = @Spec.bds21Layout := by
  unfold Impl.bds21Layout Spec.bds21Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds30Layout_eq : @Impl.bds30Layout = @Spec.bds30Layout := by
  unfold Impl.bds30Layout Spec.bds30Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds40Layout_eq : @Impl.bds40Layout = @Spec.bds40Layout := by
  unfold Impl.bds40Layout Spec.bds40Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds44Layout_eq : @Impl.bds44Layout = @Spec.bds44Layout := by
  unfold Impl.bds44Layout Spec.bds44Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds45Layout_eq : @Impl.bds45Layout = @Spec.bds45Layout := by
  unfold Impl.bds45Layout Spec.bds45Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds50Layout_eq : @Impl.bds50Layout = @Spec.bds50Layout := by
  unfold Impl.bds50Layout Spec.bds50Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_bds60Layout_eq : @Impl.bds60Layout = @Spec.bds60Layout := by
  unfold Impl.bds60Layout Spec.bds60Layout
  simp only [decoder_cbColumn_eq]
private theorem decoder_commBLayout_eq : @Impl.commBLayout = @Spec.commBLayout := by
  unfold Impl.commBLayout Spec.commBLayout
  simp only [decoder_bds10Layout_eq, decoder_bds17Layout_eq, decoder_bds18Layout_eq,
    decoder_bds19Layout_eq, decoder_bds20Layout_eq, decoder_bds21Layout_eq, decoder_bds30Layout_eq,
    decoder_bds40Layout_eq, decoder_bds44Layout_eq, decoder_bds45Layout_eq, decoder_bds50Layout_eq,
    decoder_bds60Layout_eq]
  rfl
/-- Includes FC003's separate DTE oracle byte order; each extracted byte is
rewritten through the already proved runtime/reference bit extraction equality. -/
private theorem decoder_commBValue_eq : @Impl.commBValue = @Spec.commBValue := by
  unfold Impl.commBValue Spec.commBValue
  simp only [decoder_cbSelected_eq, decoder_cbTemperature44_eq, decoder_cbVertical60_eq,
    decoder_cbWrapAngle_eq, decoder_commBLayout_eq, decoder_payloadBits_eq, decoder_payloadValue_eq]
  rfl
/-- FC003: the shipped DTE semantic value refines the approved reference
for every payload, including words outside the 56-bit wire domain. -/
theorem DTEOracleRefinement (word : Nat) :
    Impl.commBValue 0x10 word "dte" = Spec.commBValue 0x10 word "dte" := by
  rw [decoder_commBValue_eq]

#print axioms DTEOracleRefinement

private theorem decoder_Semantics_commBLabels_eq :
    @Impl.Semantics.commBLabels = @Spec.Semantics.commBLabels := by
  unfold Impl.Semantics.commBLabels Spec.Semantics.commBLabels
  simp only [decoder_Semantics_airline_eq, decoder_Semantics_hazard_eq, decoder_cbCallsign_eq,
    decoder_cbRegistration_eq, decoder_commBValue_eq, decoder_payloadBits_eq]
private theorem decoder_Semantics_commBStandardFloats_eq :
    @Impl.Semantics.commBStandardFloats = @Spec.Semantics.commBStandardFloats := by
  unfold Impl.Semantics.commBStandardFloats Spec.Semantics.commBStandardFloats
  simp only [decoder_Presentation_oracleCommBFloats_eq, decoder_cbSigned_eq]
private theorem decoder_cbThreat_eq : @Impl.cbThreat = @Spec.cbThreat := by
  unfold Impl.cbThreat Spec.cbThreat
  simp only [decoder_Altitude_oracleAC13_eq, decoder_payloadBits_eq]
  rfl
private theorem decoder_standardThreatBearing_eq :
    @Impl.standardThreatBearing = @Spec.standardThreatBearing := by
  rfl
private theorem decoder_standardThreatRange_eq : @Impl.standardThreatRange = @Spec.standardThreatRange := by
  rfl
private theorem decoder_cbStandardThreat_eq : @Impl.cbStandardThreat = @Spec.cbStandardThreat := by
  unfold Impl.cbStandardThreat Spec.cbStandardThreat
  simp only [decoder_Altitude_decodeGillham_eq, decoder_payloadBits_eq, decoder_standardThreatBearing_eq,
    decoder_standardThreatRange_eq]
  rfl
private theorem decoder_Semantics_commB_eq : @Impl.Semantics.commB = @Spec.Semantics.commB := by
  unfold Impl.Semantics.commB Spec.Semantics.commB
  simp only [decoder_Presentation_oracleCommBFloats_eq, decoder_Semantics_adsb_eq,
    decoder_Semantics_commBLabels_eq, decoder_Semantics_commBStandardFloats_eq,
    decoder_Semantics_tableValues_eq, decoder_cbStandardThreat_eq, decoder_cbThreat_eq,
    decoder_commBLayout_eq, decoder_commBValue_eq]
private theorem decoder_altitudeCodeAdmissible_eq :
    @Impl.altitudeCodeAdmissible = @Spec.altitudeCodeAdmissible := by
  unfold Impl.altitudeCodeAdmissible Spec.altitudeCodeAdmissible
  simp only [decoder_Altitude_bit_eq, decoder_Altitude_gray100_eq, decoder_Altitude_gray500_eq,
    decoder_Altitude_grayDecode_eq, decoder_Altitude_validGillham_eq]
private theorem decoder_adsbHardValid_eq : @Impl.adsbHardValid = @Spec.adsbHardValid := by
  unfold Impl.adsbHardValid Spec.adsbHardValid
  simp only [decoder_altitudeCodeAdmissible_eq, decoder_payloadBits_eq]
private theorem decoder_bdsLayout_eq : @Impl.bdsLayout = @Spec.bdsLayout := by
  unfold Impl.bdsLayout Spec.bdsLayout
  simp only [decoder_adsbLayout_eq, decoder_adsbPositionLayout_eq, decoder_commBLayout_eq]
private theorem decoder_cbValid17_eq : @Impl.cbValid17 = @Spec.cbValid17 := by
  unfold Impl.cbValid17 Spec.cbValid17
  simp only [decoder_payloadBits_eq]
private theorem decoder_cbValid18_eq : @Impl.cbValid18 = @Spec.cbValid18 := by
  unfold Impl.cbValid18 Spec.cbValid18
  simp only [decoder_payloadBits_eq]
private theorem decoder_cbValid19_eq : @Impl.cbValid19 = @Spec.cbValid19 := by
  unfold Impl.cbValid19 Spec.cbValid19
  simp only [decoder_payloadBits_eq]
private theorem decoder_cbValid21_eq : @Impl.cbValid21 = @Spec.cbValid21 := by
  unfold Impl.cbValid21 Spec.cbValid21
  simp only [decoder_cbCharacter_eq, decoder_cbDashPlaceholder_eq, decoder_cbRegistrationCodes_eq,
    decoder_payloadBits_eq]
private theorem decoder_cbQNH64_eq : @Impl.cbQNH64 = @Spec.cbQNH64 := by
  unfold Impl.cbQNH64 Spec.cbQNH64
  simp only [decoder_Binary64_add_eq, decoder_Binary64_literal_eq, decoder_Binary64_mul_eq,
    decoder_payloadBits_eq]
private theorem decoder_cbStatus_eq : @Impl.cbStatus = @Spec.cbStatus := by
  unfold Impl.cbStatus Spec.cbStatus
  simp only [decoder_payloadBits_eq]
private theorem decoder_cbValid40_eq : @Impl.cbValid40 = @Spec.cbValid40 := by
  unfold Impl.cbValid40 Spec.cbValid40
  simp only [decoder_cbQNH64_eq, decoder_cbSelected_eq, decoder_cbStatus_eq, decoder_payloadBits_eq]
private theorem decoder_cbValid44_eq : @Impl.cbValid44 = @Spec.cbValid44 := by
  unfold Impl.cbValid44 Spec.cbValid44
  simp only [decoder_cbStatus_eq, decoder_cbTemperature44_eq, decoder_payloadBits_eq]
private theorem decoder_cbValid45_eq : @Impl.cbValid45 = @Spec.cbValid45 := by
  unfold Impl.cbValid45 Spec.cbValid45
  simp only [decoder_cbSigned_eq, decoder_cbStatus_eq, decoder_payloadBits_eq]
private theorem decoder_cbValid50_eq : @Impl.cbValid50 = @Spec.cbValid50 := by
  unfold Impl.cbValid50 Spec.cbValid50
  simp only [decoder_cbSigned_eq, decoder_cbStatus_eq, decoder_payloadBits_eq]
private theorem decoder_cbMach64_eq : @Impl.cbMach64 = @Spec.cbMach64 := by
  funext word
  exact CommBMach.cbMach64_eq word
private theorem decoder_cbValid60_eq : @Impl.cbValid60 = @Spec.cbValid60 := by
  unfold Impl.cbValid60 Spec.cbValid60
  simp only [decoder_cbMach64_eq, decoder_cbStatus_eq, decoder_cbVertical60_eq, decoder_payloadBits_eq]
private theorem decoder_bdsWireValid_eq : @Impl.bdsWireValid = @Spec.bdsWireValid := by
  unfold Impl.bdsWireValid Spec.bdsWireValid
  simp only [decoder_adsbHardValid_eq, decoder_cbValid17_eq, decoder_cbValid18_eq, decoder_cbValid19_eq,
    decoder_cbValid21_eq, decoder_cbValid40_eq, decoder_cbValid44_eq, decoder_cbValid45_eq,
    decoder_cbValid50_eq, decoder_cbValid60_eq, decoder_payloadBits_eq]
  rfl
private theorem decoder_bytesValue_eq : @Impl.bytesValue = @Spec.bytesValue := by
  rfl
private theorem decoder_cbGaussian_eq : @Impl.cbGaussian = @Spec.cbGaussian := by
  unfold Impl.cbGaussian Spec.cbGaussian
  simp only [decoder_Binary64_div_eq, decoder_Binary64_literal_eq, decoder_Binary64_mul_eq,
    decoder_Binary64_sub_eq]
private theorem decoder_cbLaplace_eq : @Impl.cbLaplace = @Spec.cbLaplace := by
  unfold Impl.cbLaplace Spec.cbLaplace
  simp only [decoder_Binary64_div_eq, decoder_Binary64_literal_eq, decoder_Binary64_sub_eq]
private theorem decoder_cbScoreField_eq : @Impl.cbScoreField = @Spec.cbScoreField := by
  rfl
private theorem decoder_cbDensityTerms_eq : @Impl.cbDensityTerms = @Spec.cbDensityTerms := by
  unfold Impl.cbDensityTerms Spec.cbDensityTerms
  simp only [decoder_cbGaussian_eq, decoder_cbLaplace_eq, decoder_cbMach64_eq, decoder_cbQNH64_eq,
    decoder_cbScoreField_eq, decoder_cbTemperature44_eq, decoder_commBValue_eq]
  rfl
private theorem decoder_cbDensity_eq : @Impl.cbDensity = @Spec.cbDensity := by
  unfold Impl.cbDensity Spec.cbDensity
  simp only [decoder_Binary64_add_eq, decoder_Binary64_div_eq, decoder_cbDensityTerms_eq]
private theorem decoder_cbPenalty_eq : @Impl.cbPenalty = @Spec.cbPenalty := by
  unfold Impl.cbPenalty Spec.cbPenalty
  simp only [decoder_Binary64_div_eq, decoder_Binary64_literal_eq, decoder_Binary64_sub_eq,
    decoder_cbMach64_eq, decoder_commBValue_eq]
  rfl
private theorem decoder_cbCombinedScore_eq : @Impl.cbCombinedScore = @Spec.cbCombinedScore := by
  unfold Impl.cbCombinedScore Spec.cbCombinedScore
  simp only [decoder_Binary64_add_eq, decoder_cbDensity_eq, decoder_cbPenalty_eq]
private theorem decoder_cbScorePasses_eq : @Impl.cbScorePasses = @Spec.cbScorePasses := by
  funext register word
  have terms_eq : Impl.cbDensityTermsFast register word = Spec.cbDensityTerms register word := by
    rw [CommBTables.density_terms_eq, decoder_cbDensityTerms_eq]
  have fallback_eq :
      (fun _ : Unit => decide (Impl.cbCombinedScore register word ≥ -3)) () =
        decide (Binary64Error.scoreReference (Impl.cbDensityTermsFast register word)
          (Impl.cbPenalty register word) ≥ -3) := by
    rw [terms_eq, decoder_cbPenalty_eq, decoder_cbCombinedScore_eq]
    rfl
  unfold Impl.cbScorePasses
  rw [ScoreGate.choose_eq _ _ _ (CommBTables.density_terms_length register word) fallback_eq,
    terms_eq, decoder_cbPenalty_eq]
  rfl
private theorem decoder_commBCoreRegisters_eq : @Impl.commBCoreRegisters = @Spec.commBCoreRegisters := by
  rfl
private theorem decoder_commBCoreEligible_eq : @Impl.commBCoreEligible = @Spec.commBCoreEligible := by
  unfold Impl.commBCoreEligible Spec.commBCoreEligible
  simp only [decoder_bdsWireValid_eq, decoder_cbScorePasses_eq, decoder_commBCoreRegisters_eq]
private theorem decoder_commBOperationEligible_eq :
    @Impl.commBOperationEligible = @Spec.commBOperationEligible := by
  rfl
private theorem decoder_commBPositionEligible_eq :
    @Impl.commBPositionEligible = @Spec.commBPositionEligible := by
  unfold Impl.commBPositionEligible Spec.commBPositionEligible
  simp only [decoder_adsbAltitude_eq, decoder_bdsWireValid_eq, decoder_payloadBits_eq]
private theorem decoder_commBEligible_eq : @Impl.commBEligible = @Spec.commBEligible := by
  unfold Impl.commBEligible Spec.commBEligible
  simp only [decoder_commBCoreEligible_eq, decoder_commBOperationEligible_eq,
    decoder_commBPositionEligible_eq]
private theorem decoder_commBRegisters_eq : @Impl.commBRegisters = @Spec.commBRegisters := by
  unfold Impl.commBRegisters Spec.commBRegisters
  simp only [decoder_commBCoreRegisters_eq]
private theorem decoder_field_eq : @Impl.field = @Spec.field := by
  rfl
private theorem decoder_frameBytes_eq : @Impl.frameBytes = @Spec.frameBytes := by
  rfl
private theorem decoder_readACAS_eq : @Impl.readACAS = @Spec.readACAS := by
  unfold Impl.readACAS Spec.readACAS
  simp only [decoder_field_eq]
private theorem decoder_readSurveillance_eq : @Impl.readSurveillance = @Spec.readSurveillance := by
  unfold Impl.readSurveillance Spec.readSurveillance
  simp only [decoder_field_eq]
private theorem decoder_decodeFrame_eq : @Impl.decodeFrame = @Spec.decodeFrame := by
  unfold Impl.decodeFrame Spec.decodeFrame
  simp only [decoder_bytesValue_eq, decoder_field_eq, decoder_frameBytes_eq, decoder_readACAS_eq,
    decoder_readSurveillance_eq]
  rfl
private theorem decoder_packFields_eq : @Impl.packFields = @Spec.packFields := by
  rfl
private theorem decoder_frameSyndrome_eq : @Impl.frameSyndrome = @Spec.frameSyndrome := by
  unfold Impl.frameSyndrome Spec.frameSyndrome
  simp only [decoder_FrameBody_informationBits_eq, decoder_FrameBody_parts_eq, decoder_Parity_checksum_eq,
    decoder_packFields_eq]
private theorem decoder_frameAccepted_eq : @Impl.frameAccepted = @Spec.frameAccepted := by
  funext frame
  rw [SyndromeReuse.frameAccepted_old]
  unfold Spec.frameAccepted
  simp only [decoder_adsbHardValid_eq, decoder_frameSyndrome_eq]
  rfl
private theorem decoder_decodePayloadFields_eq : @Impl.decodePayloadFields = @Spec.decodePayloadFields := by
  unfold Impl.decodePayloadFields Spec.decodePayloadFields
  simp only [decoder_payloadBits_eq]
private theorem decoder_decodeADSB_eq : @Impl.decodeADSB = @Spec.decodeADSB := by
  unfold Impl.decodeADSB Spec.decodeADSB
  simp only [decoder_adsbHardValid_eq, decoder_adsbKind_eq, decoder_adsbLayout_eq,
    decoder_decodePayloadFields_eq]
  rfl
private theorem decoder_frameADSB_eq : @Impl.frameADSB = @Spec.frameADSB := by
  unfold Impl.frameADSB Spec.frameADSB
  simp only [decoder_decodeADSB_eq]
  rfl
private theorem decoder_frameAddress_eq : @Impl.frameAddress = @Spec.frameAddress := by
  funext frame
  rw [SyndromeReuse.frameAddress_old]
  unfold Spec.frameAddress
  simp only [decoder_frameSyndrome_eq]
  rfl
private theorem decoder_frameAltitude_eq : @Impl.frameAltitude = @Spec.frameAltitude := by
  unfold Impl.frameAltitude Spec.frameAltitude
  simp only [decoder_Altitude_decodeAC12_eq, decoder_Altitude_decodeAC13_eq,
    decoder_Altitude_decodeGNSSMetres_eq, decoder_payloadBits_eq]
  rfl
private theorem decoder_frameOracleAltitude_eq : @Impl.frameOracleAltitude = @Spec.frameOracleAltitude := by
  unfold Impl.frameOracleAltitude Spec.frameOracleAltitude
  simp only [decoder_Altitude_oracleAC13_eq, decoder_adsbAltitude_eq, decoder_payloadBits_eq]
  rfl
private theorem decoder_decodeBDS_eq : @Impl.decodeBDS = @Spec.decodeBDS := by
  unfold Impl.decodeBDS Spec.decodeBDS
  simp only [decoder_bdsLayout_eq, decoder_bdsWireValid_eq, decoder_decodePayloadFields_eq]
private theorem decoder_inferCommB_eq : @Impl.inferCommB = @Spec.inferCommB := by
  unfold Impl.inferCommB Spec.inferCommB
  simp only [decoder_commBEligible_eq, decoder_commBRegisters_eq, decoder_decodeBDS_eq]
private theorem decoder_frameCommB_eq : @Impl.frameCommB = @Spec.frameCommB := by
  unfold Impl.frameCommB Spec.frameCommB
  simp only [decoder_frameOracleAltitude_eq, decoder_inferCommB_eq]
  rfl
private theorem decoder_frameIdentity_eq : @Impl.frameIdentity = @Spec.frameIdentity := by
  unfold Impl.frameIdentity Spec.frameIdentity
  simp only [decoder_identityCode_eq, decoder_payloadBits_eq]
  rfl
private theorem decoder_report_eq : @Impl.report = @Spec.report := by
  funext frame
  rw [SyndromeReuse.report_old]
  unfold Spec.report
  simp only [decoder_Parity_interrogator_eq, decoder_Semantics_adsb_eq, decoder_Semantics_commB_eq,
    decoder_frameADSB_eq, decoder_frameAddress_eq, decoder_frameAltitude_eq, decoder_frameCommB_eq,
    decoder_frameIdentity_eq, decoder_frameSyndrome_eq]
  rfl
private theorem decoder_decode_eq : @Impl.decode = @Spec.decode := by
  funext bytes
  rw [SyndromeReuse.decode_old]
  unfold Spec.decode
  simp only [decoder_decodeFrame_eq, decoder_frameAccepted_eq, decoder_report_eq]
private theorem decoder_decodePrefix_eq : @Impl.decodePrefix = @Spec.decodePrefix := by
  unfold Impl.decodePrefix Spec.decodePrefix
  simp only [decoder_decode_eq, decoder_frameBytes_eq]
/-- All byte inputs, malformed inputs, every Comm-B candidate and all exact
semantic projections are covered; no report construction occurs outside this function. -/
theorem Refinement : Capstones.Refinement Impl.decode := by
  intro bytes
  exact congrFun decoder_decode_eq bytes
/-- Prefix refinement includes the message and untouched suffix. -/
theorem PrefixRefinement : Capstones.PrefixRefinement Impl.decodePrefix := by
  intro bytes
  exact congrFun decoder_decodePrefix_eq bytes
#print axioms Refinement
#print axioms PrefixRefinement
end Lean1090.Proofs

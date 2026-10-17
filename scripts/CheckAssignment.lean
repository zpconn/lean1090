import Spec.StandardFullExamples

/-! Independent assignment regression obligations. The code under test is not
part of its own input/expected value: altitude expectations use the original
reference decoder, while complete message expectations are the frozen literal
snapshots anchored separately to published source quantities. These checks do
not replace the outstanding universal MessageRoundTrips capstone.
-/
set_option maxRecDepth 100000
set_option maxHeartbeats 0

open Lean1090.Spec
open Lean1090.Spec.StandardFullExamples

/-- All8192 standard13-bit altitude values, including invalid/metric codes. -/
theorem independent_ac13 : (List.range 8192).all (fun code =>
    decide (Assignment.altitude13 code = Altitude.decodeAC13 code)) = true := by
  decide +kernel

/-- All8192 compatibility13-bit values, including overlapping metric bits. -/
theorem independent_compatibility13 : (List.range 8192).all (fun code =>
    decide (Assignment.compatibility13 code = Altitude.oracleAC13 code)) = true := by
  decide +kernel

/-- All4096 standard12-bit altitude values and compatibility receiver values. -/
theorem independent_ac12 : (List.range 4096).all (fun code =>
    decide (Assignment.altitude12 code = Altitude.decodeAC12 code ∧
      Assignment.compatibility12 code = (Altitude.oracleAC12 code).join)) = true := by
  decide +kernel

/-- Complete literal source-backed regression fixture: quick_startExpected. -/
theorem assigned_quick_startExpected :
    (quick_startExpected.map fun m => assigned m.fields) = quick_startExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: identificationExpected. -/
theorem assigned_identificationExpected :
    (identificationExpected.map fun m => assigned m.fields) = identificationExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: airborne_evenExpected. -/
theorem assigned_airborne_evenExpected :
    (airborne_evenExpected.map fun m => assigned m.fields) = airborne_evenExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: airborne_oddExpected. -/
theorem assigned_airborne_oddExpected :
    (airborne_oddExpected.map fun m => assigned m.fields) = airborne_oddExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: surface_evenExpected. -/
theorem assigned_surface_evenExpected :
    (surface_evenExpected.map fun m => assigned m.fields) = surface_evenExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: surface_oddExpected. -/
theorem assigned_surface_oddExpected :
    (surface_oddExpected.map fun m => assigned m.fields) = surface_oddExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: surface_localExpected. -/
theorem assigned_surface_localExpected :
    (surface_localExpected.map fun m => assigned m.fields) = surface_localExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: velocity_groundExpected. -/
theorem assigned_velocity_groundExpected :
    (velocity_groundExpected.map fun m => assigned m.fields) = velocity_groundExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: velocity_airExpected. -/
theorem assigned_velocity_airExpected :
    (velocity_airExpected.map fun m => assigned m.fields) = velocity_airExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: crc_goodExpected. -/
theorem assigned_crc_goodExpected :
    (crc_goodExpected.map fun m => assigned m.fields) = crc_goodExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: address_parityExpected. -/
theorem assigned_address_parityExpected :
    (address_parityExpected.map fun m => assigned m.fields) = address_parityExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: all_callExpected. -/
theorem assigned_all_callExpected :
    (all_callExpected.map fun m => assigned m.fields) = all_callExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: altitudeExpected. -/
theorem assigned_altitudeExpected :
    (altitudeExpected.map fun m => assigned m.fields) = altitudeExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: identityExpected. -/
theorem assigned_identityExpected :
    (identityExpected.map fun m => assigned m.fields) = identityExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: gicbExpected. -/
theorem assigned_gicbExpected :
    (gicbExpected.map fun m => assigned m.fields) = gicbExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: commb_identificationExpected. -/
theorem assigned_commb_identificationExpected :
    (commb_identificationExpected.map fun m => assigned m.fields) = commb_identificationExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: selected_altitudeExpected. -/
theorem assigned_selected_altitudeExpected :
    (selected_altitudeExpected.map fun m => assigned m.fields) = selected_altitudeExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: track_turnExpected. -/
theorem assigned_track_turnExpected :
    (track_turnExpected.map fun m => assigned m.fields) = track_turnExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: heading_speedExpected. -/
theorem assigned_heading_speedExpected :
    (heading_speedExpected.map fun m => assigned m.fields) = heading_speedExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: meteo_routineExpected. -/
theorem assigned_meteo_routineExpected :
    (meteo_routineExpected.map fun m => assigned m.fields) = meteo_routineExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: meteo_hazardExpected. -/
theorem assigned_meteo_hazardExpected :
    (meteo_hazardExpected.map fun m => assigned m.fields) = meteo_hazardExpected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: inference_df20Expected. -/
theorem assigned_inference_df20Expected :
    (inference_df20Expected.map fun m => assigned m.fields) = inference_df20Expected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: inference_df21Expected. -/
theorem assigned_inference_df21Expected :
    (inference_df21Expected.map fun m => assigned m.fields) = inference_df21Expected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: raw_only_1Expected. -/
theorem assigned_raw_only_1Expected :
    (raw_only_1Expected.map fun m => assigned m.fields) = raw_only_1Expected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: raw_only_2Expected. -/
theorem assigned_raw_only_2Expected :
    (raw_only_2Expected.map fun m => assigned m.fields) = raw_only_2Expected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: raw_only_3Expected. -/
theorem assigned_raw_only_3Expected :
    (raw_only_3Expected.map fun m => assigned m.fields) = raw_only_3Expected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: raw_only_4Expected. -/
theorem assigned_raw_only_4Expected :
    (raw_only_4Expected.map fun m => assigned m.fields) = raw_only_4Expected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: raw_only_5Expected. -/
theorem assigned_raw_only_5Expected :
    (raw_only_5Expected.map fun m => assigned m.fields) = raw_only_5Expected := by
  decide +kernel

/-- Complete literal source-backed regression fixture: raw_only_6Expected. -/
theorem assigned_raw_only_6Expected :
    (raw_only_6Expected.map fun m => assigned m.fields) = raw_only_6Expected := by
  decide +kernel

-- Print proof axioms so the final gate can audit these actual theorems too.
#print axioms independent_ac13
#print axioms independent_compatibility13
#print axioms independent_ac12
#print axioms assigned_quick_startExpected
#print axioms assigned_identificationExpected
#print axioms assigned_airborne_evenExpected
#print axioms assigned_airborne_oddExpected
#print axioms assigned_surface_evenExpected
#print axioms assigned_surface_oddExpected
#print axioms assigned_surface_localExpected
#print axioms assigned_velocity_groundExpected
#print axioms assigned_velocity_airExpected
#print axioms assigned_crc_goodExpected
#print axioms assigned_address_parityExpected
#print axioms assigned_all_callExpected
#print axioms assigned_altitudeExpected
#print axioms assigned_identityExpected
#print axioms assigned_gicbExpected
#print axioms assigned_commb_identificationExpected
#print axioms assigned_selected_altitudeExpected
#print axioms assigned_track_turnExpected
#print axioms assigned_heading_speedExpected
#print axioms assigned_meteo_routineExpected
#print axioms assigned_meteo_hazardExpected
#print axioms assigned_inference_df20Expected
#print axioms assigned_inference_df21Expected
#print axioms assigned_raw_only_1Expected
#print axioms assigned_raw_only_2Expected
#print axioms assigned_raw_only_3Expected
#print axioms assigned_raw_only_4Expected
#print axioms assigned_raw_only_5Expected
#print axioms assigned_raw_only_6Expected

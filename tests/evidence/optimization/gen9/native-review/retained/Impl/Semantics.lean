import Model.Types
import Impl.CommB
import Impl.Presentation

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl.Semantics
open Lean1090.Spec
open Lean1090.Spec.Semantics
open Lean1090.Spec.Presentation
open Lean1090.Impl.Presentation

-- Initial algorithm: Spec/Semantics.lean:23.
/-- Source-table affine projections, including every raw/reserved/status
column so booleans and discriminants remain explicitly proof-visible. -/
def tableValues (layout : List PayloadColumn) (word : Nat) : Values :=
  layout.map fun c => (c.name, payloadValue c word)

-- Initial algorithm: Spec/Semantics.lean:28.
/-- Sun, 2nd ed. (2021), table4.1 category meanings; output spelling is rs1090-derived
from bds08.rs WakeVortex's serde names, including its TC2 category mapping. -/
def wakeVortex (tc category : Nat) : String :=
  if tc == 1 then "Reserved" else if category == 0 then "n/a" else
  if tc == 2 then
    if category == 1 then "Surface emergency vehicle"
    else if category == 3 then "Surface service vehicle" else "Obstruction"
  else if tc == 3 then
    (["n/a", "Glider", "Lighter than air", "Parachutist", "Ultralight",
      "Reserved", "UAV", "Space"].getD category "Reserved")
  else if tc == 4 then
    (["n/a", "<7000kg", "<34,000kg", "<136,000kg", "High vortex",
      "Heavy", "High performance", "Rotorcraft"].getD category "Reserved")
  else "Reserved"

-- Initial algorithm: Spec/Semantics.lean:43.
/-- rs1090-derived bds61.rs EmergencyState serde names for the eight codes. -/
def emergency (code : Nat) : String :=
  ["none", "general", "medical", "minimum_fuel", "no_communication",
    "unlawful_interference", "downed_aircraft", "reserved"].getD code "reserved"

-- Initial algorithm: Spec/Semantics.lean:48.
/-- Sun, 2nd ed. (2021), tables5.1/6.1/7.1–7.3: exact non-affine ADS-B quantities. The
GNSS height is metres and the ground components honor subtype2's factor4.
Selected-altitude rounding is explicitly rs1090-derived, bds62.rs. -/
def adsbStandardValues (word : Nat) : Values :=
  let tc := payloadBits word 1 5
  let b := payloadBits word
  if 5 <= tc && tc <= 8 then
    [("NUCp", some (adsbNUCp tc)), ("groundspeed", adsbMovement (b 6 7))]
  else if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("NUCp", some (adsbNUCp tc)),
     ("NICb", if tc < 19 then some (b 8 1) else none),
     ("altitude_feet", if tc < 19 then (Altitude.decodeAC12 (b 9 12)).map (fun n => (n : Rat)) else none),
     ("height_metres", (standardGNSSHeightMetres word).map (fun n => (n : Rat)))]
  else if tc == 19 then
    let components := standardVelocityComponents word
    let subtype := b 6 3
    [("east_velocity", components.map (fun p => (p.1 : Rat))),
     ("north_velocity", components.map (fun p => (p.2 : Rat))),
     ("vertical_rate", (adsbVerticalRate word).map (fun n => (n : Rat))),
     ("geo_minus_baro", (standardGeoMinusBaro word).map (fun n => (n : Rat))),
     ("airspeed", if subtype == 3 || subtype == 4 then
       (adsbAirspeed word).map (fun n => (n : Rat)) else none)]
  else if tc == 28 then
    [("squawk", some (identityCode (BitVec.ofNat 13 (b 12 13))))]
  else if tc == 29 then
    [("selected_altitude", (adsbSelectedAltitude word).map (fun n => (n : Rat))),
     ("barometric_setting", adsbBarometricSetting word)]
  else []

/-- FC002: native-endian oracle quantity on the pinned x86_64 target.
The raw reserved column remains MSB-first in the standard view. -/
def oracleReservedVelocityData (word : Nat) : Nat :=
  payloadBits word 14 8 + 256 * payloadBits word 22 8 +
    65536 * payloadBits word 30 6

-- Initial algorithm: Spec/Semantics.lean:89.
/-- rs1090-derived bds05.rs/bds09.rs: compatibility values at documented
GNSS altitude, subtype2, zero-component and GNSS-minus-baro discrepancies. -/
def adsbOracleValues (word : Nat) : Values :=
  let tc := payloadBits word 1 5
  if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("NUCp", some (adsbNUCp tc)),
     ("NICb", if tc < 19 then some (payloadBits word 8 1) else none),
     ("altitude_feet", (adsbAltitude word).map (fun n => (n : Rat)))]
  else if tc == 19 then
    let (ew, ns) := adsbOracleVelocityComponents word
    let subtype := payloadBits word 6 3
    ([("east_velocity", if subtype == 1 || subtype == 2 then some ew else none),
     ("north_velocity", if subtype == 1 || subtype == 2 then some ns else none),
     ("vertical_rate", (adsbVerticalRate word).map (fun n => (n : Rat))),
     ("geo_minus_baro", (adsbGeoMinusBaro word).map (fun n => (n : Rat))),
     ("airspeed", if subtype == 3 || subtype == 4 then
       (adsbAirspeed word).map (fun n => (n : Rat)) else none)] : Values) ++
      (if subtype == 0 || subtype ≥ 5 then
        [("reserved_data", some (oracleReservedVelocityData word : Rat))] else [])
  else adsbStandardValues word

-- Initial algorithm: Spec/Semantics.lean:96.
/-- Sun, 2nd ed. (2021), tables4.1/7.1; rs1090-derived bds61/62 enum labels. Internal source
labels are explicit; serialized aliases are described in SCOPE.md. -/
def adsbLabels (oracle : Bool) (word : Nat) : Labels :=
  let b := payloadBits word
  let tc := b 1 5
  if 1 <= tc && tc <= 4 then
    [("callsign", some (adsbCallsign word)), ("wake_vortex", some (wakeVortex tc (b 6 3)))]
  else if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("source", some (if tc < 19 then "barometric" else "GNSS"))]
  else if tc == 19 then
    [("vrate_src", some (if oracle then oracleVerticalSource word else standardVerticalSource word)),
     ("airspeed_type", if b 6 3 == 3 || b 6 3 == 4 then
        some (if b 25 1 == 0 then "IAS" else "TAS") else none)]
  else if tc == 28 then
    [("subtype", some (["no_information", "emergency_priority", "acas_ra"].getD (b 6 3) "reserved")),
     ("emergency_state", some (emergency (b 9 3)))]
  else if tc == 29 then
    [("source", some (if b 9 1 == 0 then "MCP/FCU" else "FMS"))]
  else []

-- Initial algorithm: Spec/Semantics.lean:116.
/-- Sun, 2nd ed. (2021), table7.2 standard signed components feed the same tested hypot/atan2
formula as the oracle. No Float accuracy is claimed by this expression. -/
def adsbStandardFloats (word : Nat) : List NumericField :=
  let tc := payloadBits word 1 5
  let subtype := payloadBits word 6 3
  if tc == 19 && (subtype == 1 || subtype == 2) then
    let components := standardVelocityComponents word
    [⟨"groundspeed", components.map (fun p => velocitySpeed p.1 p.2), .null⟩,
     ⟨"track", components.map (fun p => velocityTrack p.1 p.2), .null⟩]
  else oracleADSBFloats word

-- Initial algorithm: Spec/Semantics.lean:127.
/-- Sun chs.4–8 plus declared rs1090-derived fallback tables: complete
exact payload view and the separate standard/oracle numeric expressions. -/
def adsb (word : Nat) : Payload :=
  ⟨tableValues ((adsbLayout word).getD []) word,
   adsbStandardValues word, adsbOracleValues word,
   adsbLabels false word, adsbLabels true word,
   adsbStandardFloats word, oracleADSBFloats word, none, none⟩

-- Initial algorithm: Spec/Semantics.lean:135.
/-- rs1090-derived bds21.rs: optional airline string uses the same placeholder
removal as registration. Valid inference currently requires it unavailable. -/
def airline (word : Nat) : Option String :=
  if payloadBits word 44 1 == 0 then none else
    some (String.ofList (([payloadBits word 45 6, payloadBits word 51 6].filter
      (fun c => !cbDashPlaceholder c)).map cbCharacter))

-- Initial algorithm: Spec/Semantics.lean:142.
/-- Sun, 2nd ed. (2021), table18.2 hazard meanings, with rs1090-derived enum spelling. -/
def hazard (value : Option Rat) : Option String :=
  value.map fun v => if v == 0 then "Nil" else if v == 1 then "Light"
    else if v == 2 then "Moderate" else "Severe"

-- Initial algorithm: Spec/Semantics.lean:147.
/-- ICAO Annex10 IV, 4th ed. (2007), table3-8 strings and Sun, 2nd ed. (2021), table18.1/18.2 enums; target-source names
and JSON label spelling are rs1090-derived bds21/40/44/45 policies. -/
def commBLabels (register word : Nat) : Labels :=
  if register == 0x20 then [("callsign", some (cbCallsign word))]
  else if register == 0x21 then
    [("registration", cbRegistration word), ("airline", airline word)]
  else if register == 0x40 then
    [("target_altitude_source", some (["Unknown", "AircraftAltitude",
      "FcpMcuSelectedAltitude", "FmsSelectedAltitude"].getD (payloadBits word 55 2) "Unknown"))]
  else if register == 0x44 then
    [("figure_of_merit", some (["Invalid", "INS", "GNSS", "DMEDME", "VORDME"].getD
      (payloadBits word 1 4) "Reserved")),
     ("turbulence", hazard (commBValue register word "turbulence"))]
  else if register == 0x45 then
    ["turbulence", "wind_shear", "microburst", "icing", "wake_vortex"].map
      fun name => (name, hazard (commBValue register word name))
  else []

-- Initial algorithm: Spec/Semantics.lean:165.
/-- Sun, 2nd ed. (2021), table18.1 temperature is signed quarter-degrees without the oracle's
legacy wrap. ICAO §4.3.8.4.2.2.1.6 range/bearing are typed estimates/sectors
in standardThreat, so no scalar Float replaces those standard meanings.
Other numeric programs use the exact operands and oracle operation order. -/
def commBStandardFloats (register word : Nat) : List NumericField :=
  if register == 0x30 then [] else
    (oracleCommBFloats register word).map fun field =>
      if register == 0x44 && field.key == "temperature" then
        { field with value := some (.literal .binary64 (cbSigned word 24 11 / 4)) }
      else field

-- Initial algorithm: Spec/Semantics.lean:176.
/-- Sun chs.16–18 and declared oracle adjustments in commBValue: all exact
field quantities and nonlinear strings, plus BDS30's separate source/oracle
threat meanings. Position/operation candidates reuse their ADS-B semantics. -/
def commB (register word : Nat) : Payload :=
  if register == 0x05 || register == 0x65 then adsb word else
    let layout := (commBLayout register).getD []
    { tableValues := tableValues layout word
      standardValues := tableValues layout word
      oracleValues := layout.map fun c => (c.name, commBValue register word c.name)
      standardLabels := commBLabels register word
      oracleLabels := commBLabels register word
      standardFloats := commBStandardFloats register word
      oracleFloats := oracleCommBFloats register word
      standardThreat := if register == 0x30 then cbStandardThreat word else none
      oracleThreat := if register == 0x30 then some (cbThreat word) else none }

end Lean1090.Impl.Semantics

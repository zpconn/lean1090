import Impl.PayloadBits
import Impl.Altitude
import Impl.Frame

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl
open Lean1090.Spec

-- Initial algorithm: Spec/ADSB.lean:22.
/-- Sun 2nd ed., ch.4 layout diagram: TC, category and eight six-bit symbols. -/
def adsbIdentificationLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "category", start := 6, width := 3}] ++
  (List.range 8).map fun i => {name := "char" ++ toString i, start := 9+6*i, width := 6}

-- Initial algorithm: Spec/ADSB.lean:27.
/-- Sun 2nd ed., table5.1: airborne position and barometric/GNSS altitude code. -/
def adsbPositionLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "ss", start := 6, width := 2},
   {name := "saf_or_nicb", start := 8, width := 1}, {name := "altitude_code", start := 9, width := 12},
   {name := "time_sync", start := 21, width := 1}, {name := "parity", start := 22, width := 1},
   {name := "lat_cpr", start := 23, width := 17}, {name := "lon_cpr", start := 40, width := 17}]

-- Initial algorithm: Spec/ADSB.lean:34.
/-- Sun 2nd ed., table6.1: surface movement, track, time and CPR fields. -/
def adsbSurfaceLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "movement", start := 6, width := 7},
   {name := "track_status", start := 13, width := 1},
   {name := "track", start := 14, width := 7, scale := 360/128, status := 13},
   {name := "time_sync", start := 21, width := 1}, {name := "parity", start := 22, width := 1},
   {name := "lat_cpr", start := 23, width := 17}, {name := "lon_cpr", start := 40, width := 17}]

-- Initial algorithm: Spec/ADSB.lean:42.
/-- Sun 2nd ed., tables7.1–7.3: velocity variants. Reserved subtype payload
preservation is rs1090-derived, bds09.rs ReservedVelocityData. -/
def adsbVelocityLayout (subtype : Nat) : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
   {name := "intent_change", start := 9, width := 1}, {name := "ifr_capability", start := 10, width := 1},
   {name := "NACv", start := 11, width := 3}] ++
  (if subtype == 1 || subtype == 2 then
    [{name := "ew_sign", start := 14, width := 1}, {name := "ew_velocity", start := 15, width := 10},
     {name := "ns_sign", start := 25, width := 1}, {name := "ns_velocity", start := 26, width := 10}]
   else if subtype == 3 || subtype == 4 then
    [{name := "heading_status", start := 14, width := 1},
     {name := "heading", start := 15, width := 10, scale := 360/1024, status := 14},
     {name := "airspeed_type", start := 25, width := 1}, {name := "airspeed_code", start := 26, width := 10}]
   else [{name := "reserved_data", start := 14, width := 22}]) ++
  [{name := "vrate_source", start := 36, width := 1}, {name := "vrate_sign", start := 37, width := 1},
   {name := "vertical_rate_code", start := 38, width := 9}, {name := "reserved", start := 47, width := 2},
   {name := "gnss_sign", start := 49, width := 1}, {name := "geo_minus_baro_code", start := 50, width := 7}]

-- Initial algorithm: Spec/ADSB.lean:60.
/-- rs1090-derived: bds61.rs AircraftStatus reads this same layout for ALL
subtypes, including ACAS-RA; no independently read ICAO table supports that
choice. The unused tail is retained for exact field reconstruction. -/
def adsbStatusLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
   {name := "emergency_state", start := 9, width := 3}, {name := "squawk_code", start := 12, width := 13},
   {name := "unused", start := 25, width := 32}]

-- Initial algorithm: Spec/ADSB.lean:68.
/-- rs1090-derived: bds62.rs TargetStateAndStatusInformation. TC29's subtype
is TWO bits; its value does not alter the oracle's chosen layout. -/
def adsbTargetLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 2},
   {name := "reserved0", start := 8, width := 1}, {name := "alt_source", start := 9, width := 1},
   {name := "selected_altitude_code", start := 10, width := 11},
   {name := "barometric_setting_code", start := 21, width := 9},
   {name := "heading_status", start := 30, width := 1},
   {name := "selected_heading", start := 31, width := 9, scale := 180/256, status := 30},
   {name := "NACp", start := 40, width := 4}, {name := "nic_baro", start := 44, width := 1},
   {name := "SIL", start := 45, width := 2}, {name := "mode_status", start := 47, width := 1},
   {name := "autopilot", start := 48, width := 1, status := 47},
   {name := "vnav_mode", start := 49, width := 1, status := 47},
   {name := "alt_hold", start := 50, width := 1, status := 47}, {name := "imf", start := 51, width := 1},
   {name := "approach_mode", start := 52, width := 1, status := 47},
   {name := "tcas_operational", start := 53, width := 1}, {name := "lnav_mode", start := 54, width := 1, status := 47},
   {name := "reserved1", start := 55, width := 2}]

-- Initial algorithm: Spec/ADSB.lean:86.
/-- Sun 2nd ed., tables8.2/8.3 give enclosing blocks; individual bit names
inside CC/OM are rs1090-derived from bds65.rs CapabilityClass/OperationalMode.
Airborne skips bits33–40; surface calls those GPS antenna offset. -/
def adsbOperationPrefix (surface : Bool) : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
   {name := "cc_reserved0", start := 9, width := 2}] ++
  (if surface then
    [{name := "poe", start := 11, width := 1}, {name := "1090ES", start := 12, width := 1},
     {name := "cc_reserved1", start := 13, width := 2}, {name := "GRND", start := 15, width := 1},
     {name := "UATin", start := 16, width := 1}, {name := "NACv", start := 17, width := 3},
     {name := "NICc", start := 20, width := 1}, {name := "lw_codes", start := 21, width := 4}]
   else
    [{name := "ACAS", start := 11, width := 1}, {name := "CDTI", start := 12, width := 1},
     {name := "cc_reserved1", start := 13, width := 2}, {name := "ARV", start := 15, width := 1},
     {name := "TS", start := 16, width := 1}, {name := "TC", start := 17, width := 2},
     {name := "cc_padding", start := 19, width := 6}]) ++
  [{name := "om_reserved", start := 25, width := 2}, {name := "tcas_ra_active", start := 27, width := 1},
   {name := "ident_switch_active", start := 28, width := 1},
   {name := "reserved_recv_atc_service", start := 29, width := 1},
   {name := "single_antenna_flag", start := 30, width := 1},
   {name := "system_design_assurance", start := 31, width := 2},
   {name := if surface then "gps_antenna_offset" else "om_padding", start := 33, width := 8},
   {name := "version", start := 41, width := 3}]

-- Initial algorithm: Spec/ADSB.lean:110.
/-- Sun 2nd ed., tables8.2/8.3: version1/2 trailer. Version0 and3–7
opaque treatment is rs1090-derived from bds65.rs ADSBVersionAirborne/Surface. -/
def adsbOperationSuffix (surface : Bool) (version : Nat) : List PayloadColumn :=
  if version == 1 || version == 2 then
    [{name := if version == 1 then "NICs" else "NICa", start := 44, width := 1},
     {name := "NACp", start := 45, width := 4},
     {name := if surface then "reserved_accuracy" else if version == 1 then "BAQ" else "GVA",
       start := 49, width := 2},
     {name := "SIL", start := 51, width := 2},
     {name := if surface then "TAH" else "BAI", start := 53, width := 1},
     {name := "HRD", start := 54, width := 1}] ++
    (if version == 2 then [{name := "SILs", start := 55, width := 1},
                           {name := "reserved_tail", start := 56, width := 1}]
     else [{name := "reserved_tail", start := 55, width := 2}])
  else [{name := "unused_version_tail", start := 44, width := 13}]

-- Initial algorithm: Spec/ADSB.lean:126.
/-- Sun 2nd ed., table3.3 plus explicitly rs1090-derived reserved ME variants:
exact layout selector key tc*64+subtype*8+version; irrelevant components zero. -/
def adsbKind (word : Nat) : Nat :=
  let tc := payloadBits word 1 5
  let st := if tc == 29 then payloadBits word 6 2 else payloadBits word 6 3
  tc * 64 + (if tc == 19 || tc == 28 || tc == 29 || tc == 31 then st * 8 else 0) +
    (if tc == 31 && st < 2 then payloadBits word 41 3 else 0)

-- Initial algorithm: Spec/ADSB.lean:134.
/-- Sun 2nd ed., cited individual layouts; all32 typecodes and every oracle
subtype are represented. Reserved codes remain distinct, not invalidated. -/
def adsbLayoutOfKind (kind : Nat) : Option (List PayloadColumn) :=
  let tc := kind / 64
  let st := kind / 8 % 8
  let version := kind % 8
  if tc > 31 then none else
  if tc >= 1 && tc <= 4 then some adsbIdentificationLayout
  else if tc >= 5 && tc <= 8 then some adsbSurfaceLayout
  else if (tc >= 9 && tc <= 18) || (tc >= 20 && tc <= 22) then some adsbPositionLayout
  else if tc == 19 then some (adsbVelocityLayout st)
  else if tc == 28 then some adsbStatusLayout
  else if tc == 29 then some adsbTargetLayout
  else if tc == 31 then
    if st < 2 then some (adsbOperationPrefix (st == 1) ++ adsbOperationSuffix (st == 1) version)
    else some [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
               {name := "reserved_status_data", start := 9, width := 40}, {name := "ignored_tail", start := 49, width := 8}]
  else if tc >= 25 && tc <= 27 then
    some [{name := "tc", start := 1, width := 5}, {name := "unused", start := 6, width := 8},
          {name := "ignored_tail", start := 14, width := 43}]
  else some [{name := "tc", start := 1, width := 5}, {name := "reserved_payload", start := 6, width := 51}]

-- Initial algorithm: Spec/ADSB.lean:156.
/-- Sun 2nd ed., table3.3 and individual layouts: select from received fields. -/
def adsbLayout (word : Nat) : Option (List PayloadColumn) := adsbLayoutOfKind (adsbKind word)

-- Initial algorithm: Spec/ADSB.lean:159.
/-- rs1090-derived bds05.rs decode_ac12: TC20–22 shares the barometric
interpretation; default bds-infer rejects decoded heights above50000ft. -/
def adsbAltitude (word : Nat) : Option Int :=
  (Altitude.oracleAC12 (payloadBits word 9 12)).join

-- Initial algorithm: Spec/ADSB.lean:164.
/-- rs1090-derived 50000ft acceptance limit, stated independently on the
altitude code: Q=1's unsigned count is at most2040; a valid Gillham count
must satisfy500*N500+100*N100≤51300. Invalid Gillham is accepted as missing.
This predicate neither calls an altitude decoder nor assumes its result. The
Gray arithmetic and code validity are Sun2nded.(2021), ch.13 Altitude code. -/
def altitudeCodeAdmissible (code : Nat) : Bool :=
  code < 4096 &&
  (if Altitude.bit code 4 == 1 then code / 32 * 16 + code % 16 ≤ 2040
   else
     let word := code / 64 * 128 + code % 64
     if !Altitude.validGillham word then true else
       let n500 := Altitude.grayDecode 8 (Altitude.gray500 word)
       let c := Altitude.grayDecode 3 (Altitude.gray100 word)
       let c := if c == 7 then 5 else c
       let n100 := if n500 % 2 == 1 then 6-c else c
       500*n500 + 100*n100 ≤ 51300)

-- Initial algorithm: Spec/ADSB.lean:181.
/-- rs1090-derived bds05.rs altitude ceiling and bds65.rs two reserved-bit
assertions; these are receiver acceptance policies, not standard valid-code claims. -/
def adsbHardValid (word : Nat) : Bool :=
  let tc := payloadBits word 1 5
  if (tc >= 9 && tc <= 18) || (tc >= 20 && tc <= 22) then
    altitudeCodeAdmissible (payloadBits word 9 12)
  else if tc == 31 && payloadBits word 6 3 < 2 then
    payloadBits word 9 2 == 0 && payloadBits word 25 2 == 0
  else true

-- Initial algorithm: Spec/ADSB.lean:191.
/-- Sun 2nd ed. field tables above, plus declared receiver policies:
slow reference payload decoder with explicit error rather than silent missing fields. -/
def decodeADSB (word : Nat) : Except PayloadError PayloadRecord :=
  if word >= 2^56 then .error .outOfRange else
    match adsbLayout word with
    | none => .error (.sourceUnavailable (adsbKind word))
    | some layout => if adsbHardValid word then
        .ok ⟨adsbKind word, decodePayloadFields layout word⟩
      else .error (.malformed "oracle altitude/reserved-bit policy")

-- Initial algorithm: Spec/ADSB.lean:230.
/-- Sun 2nd ed., ch.4 §4.1 character alphabet; undefined six-bit codes map
'#' as rs1090 bds08.rs does. Spaces are dealt with by the presentation policy. -/
def adsbCharacter (code : Nat) : Char :=
  if 1 ≤ code && code ≤ 26 then Char.ofNat (64 + code)
  else if 48 ≤ code && code ≤ 57 then Char.ofNat code
  else if code == 32 then ' ' else '#'

-- Initial algorithm: Spec/ADSB.lean:237.
/-- rs1090-derived bds08.rs callsign_read removes ALL space symbols,
including embedded spaces. Raw codes remain available for bit round-trips. -/
def adsbCallsign (word : Nat) : String :=
  String.ofList (((List.range 8).map (fun i => payloadBits word (9+6*i) 6)).filterMap
    fun c => if c == 32 then none else some (adsbCharacter c))

-- Initial algorithm: Spec/ADSB.lean:243.
/-- Sun 2nd ed., table6.2: exact lower endpoints of movement quantization bins.
Code124 denotes at least175kt and is reported as175kt by the oracle. -/
def adsbMovement (code : Nat) : Option Rat :=
  if code == 0 || code >= 125 then none
  else if code == 1 then some 0
  else if code <= 8 then some ((code - 1 : Nat) / 8)
  else if code <= 12 then some (1 + (code - 9 : Nat) / 4)
  else if code <= 38 then some (2 + (code - 13 : Nat) / 2)
  else if code <= 93 then some (15 + (code - 39 : Nat))
  else if code <= 108 then some (70 + 2 * (code - 94 : Nat))
  else if code <= 123 then some (100 + 5 * (code - 109 : Nat))
  else some 175

-- Initial algorithm: Spec/ADSB.lean:256.
/-- Sun 2nd ed., tables7.1–7.3: sign-magnitude arithmetic before Float output. -/
def adsbSigned (sign magnitude : Nat) : Int :=
  if sign == 0 then magnitude else -(magnitude : Int)

-- Initial algorithm: Spec/ADSB.lean:260.
/-- Sun 2nd ed., table7.1: unavailable vertical rate code0; otherwise64ft/min. -/
def adsbVerticalRate (word : Nat) : Option Int :=
  let code := payloadBits word 38 9
  if code == 0 then none else some (adsbSigned (payloadBits word 37 1) ((code-1)*64))

-- Initial algorithm: Spec/ADSB.lean:265.
/-- rs1090-derived bds09.rs read_geobaro: codes0 AND1 yield none; code127
is decoded. This differs from the availability prose in Sun §7.2. -/
def adsbGeoMinusBaro (word : Nat) : Option Int :=
  let code := payloadBits word 50 7
  if code <= 1 then none else some (adsbSigned (payloadBits word 49 1) ((code-1)*25))

-- Initial algorithm: Spec/ADSB.lean:271.
/-- Sun 2nd ed., table7.3: true/indicated airspeed, with factor4 for subtype4. -/
def adsbAirspeed (word : Nat) : Option Nat :=
  let code := payloadBits word 26 10
  if code == 0 then none else
    some ((code - 1) * if payloadBits word 6 3 == 4 then 4 else 1)

-- Initial algorithm: Spec/ADSB.lean:277.
/-- rs1090-derived bds09.rs GroundSpeedDecoding: subtype2 shares subtype1's
unscaled components and zero codes become -1 before sign. The standard
subtype2 factor4 and missing-value rules are separately described in THEOREMS.md. -/
def adsbOracleVelocityComponents (word : Nat) : Int × Int :=
  let component := fun sign code =>
    (if sign == 0 then 1 else -1 : Int) * ((code : Int) - 1)
  (component (payloadBits word 14 1) (payloadBits word 15 10),
   component (payloadBits word 25 1) (payloadBits word 26 10))

-- Initial algorithm: Spec/ADSB.lean:286.
/-- rs1090-derived bds62.rs: selected altitude is rounded by integer arithmetic
`((32*(code-1)+16)/100)*100`; codes0/1 are unavailable. -/
def adsbSelectedAltitude (word : Nat) : Option Nat :=
  let code := payloadBits word 10 11
  if code <= 1 then none else some (((code-1)*32+16)/100*100)

-- Initial algorithm: Spec/ADSB.lean:292.
/-- rs1090-derived bds62.rs: exact input to the separately tested f32 formula
`800.0f32 + (code-1) as f32 * 0.8f32`; zero is unavailable. -/
def adsbBarometricSetting (word : Nat) : Option Rat :=
  let code := payloadBits word 21 9
  if code == 0 then none else some (800 + (code-1 : Nat) * (4/5 : Rat))

-- Initial algorithm: Spec/ADSB.lean:298.
/-- Sun 2nd ed., ch.9 table9.3 and rs1090 bds05/06 output convention:
NUCp comes directly from TC, not from the decoded CPR position. -/
def adsbNUCp (tc : Nat) : Nat :=
  if 5 ≤ tc && tc ≤ 8 then 14 - tc
  else if tc < 19 then 18 - tc else if tc == 20 || tc == 21 then 29 - tc else 0

end Lean1090.Impl

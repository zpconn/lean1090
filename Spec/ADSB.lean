import Spec.PayloadBits
import Spec.Altitude
import Spec.Frame

/-!
# ADS-B payload reference

Primary layouts: Junzi Sun, The 1090 Megahertz Riddle, second edition
(2021), ch.4 diagram and table4.1, tables5.1,6.1,6.2,7.1–7.3,8.2–8.3.
TC28/29 and the detailed capability/operational-mode subfields of TC31 are
explicitly rs1090-derived from commit685dfaa34c5ab186c691bca3cfe2a22e12517d30,
`decode/bds/bds61.rs`, `bds62.rs`, `bds65.rs`: no underlying ICAO table for
those details was independently available. Source acquisition is in docs/SOURCES.md.

The lossless record contains individually named codes. `encodeADSB` places
those codes by a separate table-driven encoder. No input word is retained.
Exact semantic projections follow the tables; named oracle projections identify
places where the requested compatibility behavior differs from Sun.
-/
namespace Lean1090.Spec

/-- Sun 2nd ed., ch.4 layout diagram: TC, category and eight six-bit symbols. -/
def adsbIdentificationLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "category", start := 6, width := 3}] ++
  (List.range 8).map fun i => {name := "char" ++ toString i, start := 9+6*i, width := 6}

/-- Sun 2nd ed., table5.1: airborne position and barometric/GNSS altitude code. -/
def adsbPositionLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "ss", start := 6, width := 2},
   {name := "saf_or_nicb", start := 8, width := 1}, {name := "altitude_code", start := 9, width := 12},
   {name := "time_sync", start := 21, width := 1}, {name := "parity", start := 22, width := 1},
   {name := "lat_cpr", start := 23, width := 17}, {name := "lon_cpr", start := 40, width := 17}]

/-- Sun 2nd ed., table6.1: surface movement, track, time and CPR fields. -/
def adsbSurfaceLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "movement", start := 6, width := 7},
   {name := "track_status", start := 13, width := 1},
   {name := "track", start := 14, width := 7, scale := 360/128, status := 13},
   {name := "time_sync", start := 21, width := 1}, {name := "parity", start := 22, width := 1},
   {name := "lat_cpr", start := 23, width := 17}, {name := "lon_cpr", start := 40, width := 17}]

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

/-- rs1090-derived: bds61.rs AircraftStatus reads this same layout for ALL
subtypes, including ACAS-RA; no independently read ICAO table supports that
choice. The unused tail is retained for exact field reconstruction. -/
def adsbStatusLayout : List PayloadColumn :=
  [{name := "tc", start := 1, width := 5}, {name := "subtype", start := 6, width := 3},
   {name := "emergency_state", start := 9, width := 3}, {name := "squawk_code", start := 12, width := 13},
   {name := "unused", start := 25, width := 32}]

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

/-- Sun 2nd ed., table3.3 plus explicitly rs1090-derived reserved ME variants:
exact layout selector key tc*64+subtype*8+version; irrelevant components zero. -/
def adsbKind (word : Nat) : Nat :=
  let tc := payloadBits word 1 5
  let st := if tc == 29 then payloadBits word 6 2 else payloadBits word 6 3
  tc * 64 + (if tc == 19 || tc == 28 || tc == 29 || tc == 31 then st * 8 else 0) +
    (if tc == 31 && st < 2 then payloadBits word 41 3 else 0)

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

/-- Sun 2nd ed., table3.3 and individual layouts: select from received fields. -/
def adsbLayout (word : Nat) : Option (List PayloadColumn) := adsbLayoutOfKind (adsbKind word)

/-- rs1090-derived bds05.rs decode_ac12: TC20–22 shares the barometric
interpretation; default bds-infer rejects decoded heights above50000ft. -/
def adsbAltitude (word : Nat) : Option Int :=
  (Altitude.oracleAC12 (payloadBits word 9 12)).join

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

/-- rs1090-derived bds05.rs altitude ceiling and bds65.rs two reserved-bit
assertions; these are receiver acceptance policies, not standard valid-code claims. -/
def adsbHardValid (word : Nat) : Bool :=
  let tc := payloadBits word 1 5
  if (tc >= 9 && tc <= 18) || (tc >= 20 && tc <= 22) then
    altitudeCodeAdmissible (payloadBits word 9 12)
  else if tc == 31 && payloadBits word 6 3 < 2 then
    payloadBits word 9 2 == 0 && payloadBits word 25 2 == 0
  else true

/-- Sun 2nd ed. field tables above, plus declared receiver policies:
slow reference payload decoder with explicit error rather than silent missing fields. -/
def decodeADSB (word : Nat) : Except PayloadError PayloadRecord :=
  if word >= 2^56 then .error .outOfRange else
    match adsbLayout word with
    | none => .error (.sourceUnavailable (adsbKind word))
    | some layout => if adsbHardValid word then
        .ok ⟨adsbKind word, decodePayloadFields layout word⟩
      else .error (.malformed "oracle altitude/reserved-bit policy")

/-- Sun 2nd ed. field layouts above: independent encoding from separate field
assignments; does not call decodeADSB or search any code space. -/
def encodeADSB (record : PayloadRecord) : Nat :=
  match adsbLayoutOfKind record.kind with
  | some layout => encodePayloadFields layout record.fields
  | none => 0

/-- Sun 2nd ed. layout discriminants: canonical kind computed from named field
assignments, independently of wire decoding and without invoking the encoder. -/
def adsbAssignmentKind (record : PayloadRecord) : Nat :=
  let tc := (payloadField record "tc").getD 0
  let st := (payloadField record "subtype").getD 0
  let version := (payloadField record "version").getD 0
  tc * 64 + (if tc == 19 || tc == 28 || tc == 29 || tc == 31 then st * 8 else 0) +
    (if tc == 31 && st < 2 then version else 0)

/-- Independent assignment-domain condition: fields fit the source table, the
chosen discriminants agree, and oracle acceptance constraints hold on the named
altitude/reserved fields. It never assumes the desired round-trip conclusion. -/
def ValidADSB (record : PayloadRecord) : Prop :=
  (adsbLayoutOfKind record.kind).elim False (fun layout =>
    ValidPayloadFields layout record.fields ∧ record.kind = adsbAssignmentKind record ∧
    (let tc := record.kind / 64
     if (9 ≤ tc ∧ tc ≤ 18) ∨ (20 ≤ tc ∧ tc ≤ 22) then
       altitudeCodeAdmissible ((payloadField record "altitude_code").getD 0) = true
     else if tc = 31 ∧ record.kind / 8 % 8 < 2 then
       payloadField record "cc_reserved0" = some 0 ∧ payloadField record "om_reserved" = some 0
     else True))

/-- Sun 2nd ed., ch.4 §4.1 character alphabet; undefined six-bit codes map
'#' as rs1090 bds08.rs does. Spaces are dealt with by the presentation policy. -/
def adsbCharacter (code : Nat) : Char :=
  if 1 ≤ code && code ≤ 26 then Char.ofNat (64 + code)
  else if 48 ≤ code && code ≤ 57 then Char.ofNat code
  else if code == 32 then ' ' else '#'

/-- rs1090-derived bds08.rs callsign_read removes ALL space symbols,
including embedded spaces. Raw codes remain available for bit round-trips. -/
def adsbCallsign (word : Nat) : String :=
  String.ofList (((List.range 8).map (fun i => payloadBits word (9+6*i) 6)).filterMap
    fun c => if c == 32 then none else some (adsbCharacter c))

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

/-- Sun 2nd ed., tables7.1–7.3: sign-magnitude arithmetic before Float output. -/
def adsbSigned (sign magnitude : Nat) : Int :=
  if sign == 0 then magnitude else -(magnitude : Int)

/-- Sun 2nd ed., table7.1: unavailable vertical rate code0; otherwise64ft/min. -/
def adsbVerticalRate (word : Nat) : Option Int :=
  let code := payloadBits word 38 9
  if code == 0 then none else some (adsbSigned (payloadBits word 37 1) ((code-1)*64))

/-- rs1090-derived bds09.rs read_geobaro: codes0 AND1 yield none; code127
is decoded. This differs from the availability prose in Sun §7.2. -/
def adsbGeoMinusBaro (word : Nat) : Option Int :=
  let code := payloadBits word 50 7
  if code <= 1 then none else some (adsbSigned (payloadBits word 49 1) ((code-1)*25))

/-- Sun 2nd ed., table7.3: true/indicated airspeed, with factor4 for subtype4. -/
def adsbAirspeed (word : Nat) : Option Nat :=
  let code := payloadBits word 26 10
  if code == 0 then none else
    some ((code - 1) * if payloadBits word 6 3 == 4 then 4 else 1)

/-- rs1090-derived bds09.rs GroundSpeedDecoding: subtype2 shares subtype1's
unscaled components and zero codes become -1 before sign. The standard
subtype2 factor4 and missing-value rules are separately described in THEOREMS.md. -/
def adsbOracleVelocityComponents (word : Nat) : Int × Int :=
  let component := fun sign code =>
    (if sign == 0 then 1 else -1 : Int) * ((code : Int) - 1)
  (component (payloadBits word 14 1) (payloadBits word 15 10),
   component (payloadBits word 25 1) (payloadBits word 26 10))

/-- rs1090-derived bds62.rs: selected altitude is rounded by integer arithmetic
`((32*(code-1)+16)/100)*100`; codes0/1 are unavailable. -/
def adsbSelectedAltitude (word : Nat) : Option Nat :=
  let code := payloadBits word 10 11
  if code <= 1 then none else some (((code-1)*32+16)/100*100)

/-- rs1090-derived bds62.rs: exact input to the separately tested f32 formula
`800.0f32 + (code-1) as f32 * 0.8f32`; zero is unavailable. -/
def adsbBarometricSetting (word : Nat) : Option Rat :=
  let code := payloadBits word 21 9
  if code == 0 then none else some (800 + (code-1 : Nat) * (4/5 : Rat))

/-- Sun 2nd ed., ch.9 table9.3 and rs1090 bds05/06 output convention:
NUCp comes directly from TC, not from the decoded CPR position. -/
def adsbNUCp (tc : Nat) : Nat :=
  if 5 ≤ tc && tc ≤ 8 then 14 - tc
  else if tc < 19 then 18 - tc else if tc == 20 || tc == 21 then 29 - tc else 0

/-- Sun 2nd ed. (2021), tables5.1,6.1,7.1–7.3,8.2–8.3 and the
explicitly rs1090-derived fallback layouts above: decode all representable
field codes, independently of receiver plausibility/reserved-bit filtering. -/
def decodeADSBFields (word : Nat) : Except PayloadError PayloadRecord :=
  if word ≥ 2^56 then .error .outOfRange else
    match adsbLayout word with
    | none => .error (.sourceUnavailable (adsbKind word))
    | some layout => .ok ⟨adsbKind word, decodePayloadFields layout word⟩

/-- Source-table assignment domain from the cited ADSB layouts: exact bounds
and discriminants only. No50000ft or capability-reserved-bit oracle filter
narrows the full field-code round-trip guarantee. -/
def ValidADSBFields (record : PayloadRecord) : Prop :=
  (adsbLayoutOfKind record.kind).elim False (fun layout =>
    ValidPayloadFields layout record.fields ∧ record.kind = adsbAssignmentKind record)

instance (record : PayloadRecord) : Decidable (ValidADSBFields record) := by
  unfold ValidADSBFields
  cases adsbLayoutOfKind record.kind <;> simp only [Option.elim] <;> infer_instance

/-- Sun 2nd ed., tables7.1/7.2: standard ground-velocity components.
Code0 means unavailable; supersonic subtype2 has four-knot resolution. -/
def adsbVelocityComponents (word : Nat) : Option (Int × Int) :=
  let ew := payloadBits word 15 10
  let ns := payloadBits word 26 10
  if ew == 0 || ns == 0 then none else
    let scale := if payloadBits word 6 3 == 2 then 4 else 1
    some (adsbSigned (payloadBits word 14 1) ((ew-1)*scale),
      adsbSigned (payloadBits word 25 1) ((ns-1)*scale))

/-- Sun 2nd ed., §7.2: standard GNSS-minus-baro code availability.
Codes0/127 are unavailable; code1 represents zero difference. -/
def adsbStandardGeoMinusBaro (word : Nat) : Option Int :=
  let code := payloadBits word 50 7
  if code == 0 || code == 127 then none
  else some (adsbSigned (payloadBits word 49 1) ((code-1)*25))

/-- Sun 2nd ed., table7.1: source0 is GNSS and source1 barometric.
The oracle enum reverses these labels; raw source bits are always retained. -/
def adsbVerticalSource (word : Nat) : String :=
  if payloadBits word 36 1 == 0 then "GNSS" else "barometric"

instance (record : PayloadRecord) : Decidable (ValidADSB record) := by
  unfold ValidADSB
  cases adsbLayoutOfKind record.kind <;> simp only [Option.elim] <;> infer_instance

/-- Source-table domains: one ordinary input for every TC, plus every
velocity/status subtype and operational-status version. Layout selectors are
not restricted to a single happy-path message in the non-vacuity check. -/
def adsbWitnessWords : List Nat :=
  (List.range 32).map (fun tc => tc * 2^51) ++
  ([19,28,29,31].flatMap fun tc =>
    (List.range (if tc == 29 then 4 else 8)).map fun st =>
      tc*2^51 + st*2^(if tc == 29 then 49 else 48)) ++
  ([0,1].flatMap fun st => (List.range 8).map fun version =>
    31*2^51 + st*2^48 + version*2^13)

/-- A concrete assignment obtained by naming the independently specified
field codes; the resulting record does not retain its original input word. -/
def adsbWitness (word : Nat) : PayloadRecord :=
  ⟨adsbKind word, decodePayloadFields ((adsbLayout word).getD []) word⟩

/-- Every listed TC/subtype/version example satisfies all assignment bounds,
discriminants and receiver hypotheses. This is kernel-checked non-vacuity. -/
theorem adsb_nonvacuous :
    ∀ word ∈ adsbWitnessWords, ValidADSB (adsbWitness word) := by decide +kernel

/-- Sun, 2nd ed. (2021), table6.2 sanity check: division in movement scaling is rational. -/
theorem movement_eighth : adsbMovement 2 = some (1/8) := by decide +kernel

/-- Source-table round-trips include50175ft, outside the receiver heuristic.
This concrete assignment has every schema hypothesis and is rejected only
by the separate oracle-compatibility payload decoder. -/
theorem adsb_full_fields_nonvacuous :
    ValidADSBFields (adsbWitness 0x48fff000000000) ∧
    decodeADSBFields 0x48fff000000000 = .ok (adsbWitness 0x48fff000000000) ∧
    (decodeADSB 0x48fff000000000).isOk = false := by
  constructor
  · decide +kernel
  constructor
  · rfl
  · decide +kernel

end Lean1090.Spec

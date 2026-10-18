import Impl.PayloadBits

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl
open Lean1090.Spec

-- Initial algorithm: Spec/CommBLayouts.lean:5.
/-- Field-schema constructor; bit numbering follows ICAO Annex 10 IV (4th ed., 2007) table 3-3. -/
def cbColumn (name : String) (start width : Nat) (scale : Rat := 1)
    (offset : Rat := 0) (status : Nat := 0)
    (coding : PayloadCoding := .unsigned) : PayloadColumn :=
  ⟨name, start, width, coding, scale, offset, status⟩

-- Initial algorithm: Spec/CommBLayouts.lean:11.
/-- ICAO Annex 10 IV (4th ed., amendment85), table 3-6; Sun (2nd ed.), ch.16, table 16.1. Config is the continuation flag. -/
def bds10Layout : List PayloadColumn :=
  [cbColumn "bds" 1 8,
   cbColumn "config" 9 1,
   cbColumn "reserved" 10 5,
   cbColumn "ovc" 15 1,
   cbColumn "acas" 16 1,
   cbColumn "subnet" 17 7,
   cbColumn "level5" 24 1,
   cbColumn "mode_s" 25 1,
   cbColumn "uplink" 26 3,
   cbColumn "downlink" 29 4,
   cbColumn "identification" 33 1,
   cbColumn "squitter" 34 1,
   cbColumn "sic" 35 1,
   cbColumn "gicb" 36 1,
   cbColumn "acas_hybrid" 37 1,
   cbColumn "acas_ra" 38 1,
   cbColumn "acas_rtca" 39 2,
   cbColumn "dte" 41 16]

-- Initial algorithm: Spec/CommBLayouts.lean:32.
/-- Sun (2nd ed.), ch.16, table 16.2; retained spare bits match rs1090-derived observable parsing. -/
def bds17Layout : List PayloadColumn :=
  [cbColumn "bds05" 1 1,
   cbColumn "bds06" 2 1,
   cbColumn "bds07" 3 1,
   cbColumn "bds08" 4 1,
   cbColumn "bds09" 5 1,
   cbColumn "bds0a" 6 1,
   cbColumn "bds20" 7 1,
   cbColumn "bds21" 8 1,
   cbColumn "bds40" 9 1,
   cbColumn "bds41" 10 1,
   cbColumn "bds42" 11 1,
   cbColumn "bds43" 12 1,
   cbColumn "bds44" 13 1,
   cbColumn "bds45" 14 1,
   cbColumn "bds48" 15 1,
   cbColumn "bds50" 16 1,
   cbColumn "bds51" 17 1,
   cbColumn "bds52" 18 1,
   cbColumn "bds53" 19 1,
   cbColumn "bds54" 20 1,
   cbColumn "bds55" 21 1,
   cbColumn "bds56" 22 1,
   cbColumn "bds5f" 23 1,
   cbColumn "bds60" 24 1,
   cbColumn "reserved" 25 5,
   cbColumn "zero_tail" 30 27]

-- Initial algorithm: Spec/CommBLayouts.lean:61.
/-- rs1090-derived: pinned bds18.rs field order. No independently read normative table was available for this bitmap. -/
def bds18Layout : List PayloadColumn :=
  [cbColumn "bds38" 1 1,
   cbColumn "bds37" 2 1,
   cbColumn "bds36" 3 1,
   cbColumn "bds35" 4 1,
   cbColumn "bds34" 5 1,
   cbColumn "bds33" 6 1,
   cbColumn "bds32" 7 1,
   cbColumn "bds31" 8 1,
   cbColumn "bds30" 9 1,
   cbColumn "bds2f" 10 1,
   cbColumn "bds2e" 11 1,
   cbColumn "bds2d" 12 1,
   cbColumn "bds2c" 13 1,
   cbColumn "bds2b" 14 1,
   cbColumn "bds2a" 15 1,
   cbColumn "bds29" 16 1,
   cbColumn "bds28" 17 1,
   cbColumn "bds27" 18 1,
   cbColumn "bds26" 19 1,
   cbColumn "bds25" 20 1,
   cbColumn "bds24" 21 1,
   cbColumn "bds23" 22 1,
   cbColumn "bds22" 23 1,
   cbColumn "bds21" 24 1,
   cbColumn "bds20" 25 1,
   cbColumn "bds1f" 26 1,
   cbColumn "bds1e" 27 1,
   cbColumn "bds1d" 28 1,
   cbColumn "bds1c" 29 1,
   cbColumn "bds1b" 30 1,
   cbColumn "bds1a" 31 1,
   cbColumn "bds19" 32 1,
   cbColumn "bds18" 33 1,
   cbColumn "bds17" 34 1,
   cbColumn "bds16" 35 1,
   cbColumn "bds15" 36 1,
   cbColumn "bds14" 37 1,
   cbColumn "bds13" 38 1,
   cbColumn "bds12" 39 1,
   cbColumn "bds11" 40 1,
   cbColumn "bds10" 41 1,
   cbColumn "bds0f" 42 1,
   cbColumn "bds0e" 43 1,
   cbColumn "bds0d" 44 1,
   cbColumn "bds0c" 45 1,
   cbColumn "bds0b" 46 1,
   cbColumn "bds0a" 47 1,
   cbColumn "bds09" 48 1,
   cbColumn "bds08" 49 1,
   cbColumn "bds07" 50 1,
   cbColumn "bds06" 51 1,
   cbColumn "bds05" 52 1,
   cbColumn "bds04" 53 1,
   cbColumn "bds03" 54 1,
   cbColumn "bds02" 55 1,
   cbColumn "bds01" 56 1]

-- Initial algorithm: Spec/CommBLayouts.lean:120.
/-- rs1090-derived: pinned bds19.rs field order. No independently read normative table was available for this bitmap. -/
def bds19Layout : List PayloadColumn :=
  [cbColumn "bds70" 1 1,
   cbColumn "bds6f" 2 1,
   cbColumn "bds6e" 3 1,
   cbColumn "bds6d" 4 1,
   cbColumn "bds6c" 5 1,
   cbColumn "bds6b" 6 1,
   cbColumn "bds6a" 7 1,
   cbColumn "bds69" 8 1,
   cbColumn "bds68" 9 1,
   cbColumn "bds67" 10 1,
   cbColumn "bds66" 11 1,
   cbColumn "bds65" 12 1,
   cbColumn "bds64" 13 1,
   cbColumn "bds63" 14 1,
   cbColumn "bds62" 15 1,
   cbColumn "bds61" 16 1,
   cbColumn "bds60" 17 1,
   cbColumn "bds5f" 18 1,
   cbColumn "bds5e" 19 1,
   cbColumn "bds5d" 20 1,
   cbColumn "bds5c" 21 1,
   cbColumn "bds5b" 22 1,
   cbColumn "bds5a" 23 1,
   cbColumn "bds59" 24 1,
   cbColumn "bds58" 25 1,
   cbColumn "bds57" 26 1,
   cbColumn "bds56" 27 1,
   cbColumn "bds55" 28 1,
   cbColumn "bds54" 29 1,
   cbColumn "bds53" 30 1,
   cbColumn "bds52" 31 1,
   cbColumn "bds51" 32 1,
   cbColumn "bds50" 33 1,
   cbColumn "bds4f" 34 1,
   cbColumn "bds4e" 35 1,
   cbColumn "bds4d" 36 1,
   cbColumn "bds4c" 37 1,
   cbColumn "bds4b" 38 1,
   cbColumn "bds4a" 39 1,
   cbColumn "bds49" 40 1,
   cbColumn "bds48" 41 1,
   cbColumn "bds47" 42 1,
   cbColumn "bds46" 43 1,
   cbColumn "bds45" 44 1,
   cbColumn "bds44" 45 1,
   cbColumn "bds43" 46 1,
   cbColumn "bds42" 47 1,
   cbColumn "bds41" 48 1,
   cbColumn "bds40" 49 1,
   cbColumn "bds3f" 50 1,
   cbColumn "bds3e" 51 1,
   cbColumn "bds3d" 52 1,
   cbColumn "bds3c" 53 1,
   cbColumn "bds3b" 54 1,
   cbColumn "bds3a" 55 1,
   cbColumn "bds39" 56 1]

-- Initial algorithm: Spec/CommBLayouts.lean:179.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-8 and §3.1.2.9.1.2; Sun (2nd ed.), ch.16 table 16.3. -/
def bds20Layout : List PayloadColumn :=
  [cbColumn "bds" 1 8,
   cbColumn "char1" 9 6,
   cbColumn "char2" 15 6,
   cbColumn "char3" 21 6,
   cbColumn "char4" 27 6,
   cbColumn "char5" 33 6,
   cbColumn "char6" 39 6,
   cbColumn "char7" 45 6,
   cbColumn "char8" 51 6]

-- Initial algorithm: Spec/CommBLayouts.lean:191.
/-- rs1090-derived: pinned bds21.rs ac_status, seven six-bit registration characters, al_status, two airline characters. -/
def bds21Layout : List PayloadColumn :=
  [cbColumn "ac_status" 1 1,
   cbColumn "reg_char1" 2 6,
   cbColumn "reg_char2" 8 6,
   cbColumn "reg_char3" 14 6,
   cbColumn "reg_char4" 20 6,
   cbColumn "reg_char5" 26 6,
   cbColumn "reg_char6" 32 6,
   cbColumn "reg_char7" 38 6,
   cbColumn "al_status" 44 1,
   cbColumn "airline_char1" 45 6,
   cbColumn "airline_char2" 51 6]

-- Initial algorithm: Spec/CommBLayouts.lean:205.
/-- ICAO Annex 10 IV (4th ed., 2007) §4.3.8.4.2.2.1.1–6; Sun (2nd ed.), ch.16 table 16.4. TID is projected according to TTI separately. -/
def bds30Layout : List PayloadColumn :=
  [cbColumn "bds" 1 8,
   cbColumn "issued_ra" 9 1,
   cbColumn "corrective" 10 1 1 0 9,
   cbColumn "downward_sense" 11 1 1 0 9,
   cbColumn "increased_rate" 12 1 1 0 9,
   cbColumn "sense_reversal" 13 1 1 0 9,
   cbColumn "altitude_crossing" 14 1 1 0 9,
   cbColumn "positive" 15 1 1 0 9,
   cbColumn "reserved" 16 7,
   cbColumn "no_below" 23 1 1 0 9,
   cbColumn "no_above" 24 1 1 0 9,
   cbColumn "no_left" 25 1 1 0 9,
   cbColumn "no_right" 26 1 1 0 9,
   cbColumn "terminated" 27 1,
   cbColumn "multiple" 28 1,
   cbColumn "threat_type" 29 2,
   cbColumn "threat_identity_data" 31 26]

-- Initial algorithm: Spec/CommBLayouts.lean:225.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-10; Sun (2nd ed.), ch.17 table 17.1. Selected altitudes are feet; barometric setting is hPa. -/
def bds40Layout : List PayloadColumn :=
  [cbColumn "mcp_valid" 1 1,
   cbColumn "selected_mcp" 2 12 16 0 1,
   cbColumn "fms_valid" 14 1,
   cbColumn "selected_fms" 15 12 16 0 14,
   cbColumn "qnh_valid" 27 1,
   cbColumn "barometric_setting" 28 12 (1/10) 800 27,
   cbColumn "reserved" 40 8,
   cbColumn "mcp_status" 48 1,
   cbColumn "vnav_mode" 49 1,
   cbColumn "alt_hold_mode" 50 1,
   cbColumn "approach_mode" 51 1,
   cbColumn "reserved2" 52 2,
   cbColumn "source_status" 54 1,
   cbColumn "target_altitude_source" 55 2]

-- Initial algorithm: Spec/CommBLayouts.lean:242.
/-- Sun (2nd ed.), ch.18 table 18.1. Temperature scale follows that table; rs1090 wraparound correction is a separate projection. -/
def bds44Layout : List PayloadColumn :=
  [cbColumn "figure_of_merit" 1 4,
   cbColumn "wind_valid" 5 1,
   cbColumn "wind_speed" 6 9 1 0 5,
   cbColumn "wind_direction" 15 9 (180/256) 0 5,
   cbColumn "temperature" 24 11 (1/4) 0 0 .twosComplement,
   cbColumn "pressure_valid" 35 1,
   cbColumn "pressure" 36 11 1 0 35,
   cbColumn "turbulence_valid" 47 1,
   cbColumn "turbulence" 48 2 1 0 47,
   cbColumn "humidity_valid" 50 1,
   cbColumn "humidity" 51 6 (100/64) 0 50]

-- Initial algorithm: Spec/CommBLayouts.lean:256.
/-- Sun (2nd ed.), ch.18 table 18.2. Hazard codes 0/1/2/3 mean nil/light/moderate/severe. -/
def bds45Layout : List PayloadColumn :=
  [cbColumn "turbulence_valid" 1 1,
   cbColumn "turbulence" 2 2 1 0 1,
   cbColumn "wind_shear_valid" 4 1,
   cbColumn "wind_shear" 5 2 1 0 4,
   cbColumn "microburst_valid" 7 1,
   cbColumn "microburst" 8 2 1 0 7,
   cbColumn "icing_valid" 10 1,
   cbColumn "icing" 11 2 1 0 10,
   cbColumn "wake_vortex_valid" 13 1,
   cbColumn "wake_vortex" 14 2 1 0 13,
   cbColumn "temperature_valid" 16 1,
   cbColumn "static_temperature" 17 10 (1/4) 0 16 .twosComplement,
   cbColumn "pressure_valid" 27 1,
   cbColumn "static_pressure" 28 11 1 0 27,
   cbColumn "height_valid" 39 1,
   cbColumn "radio_height" 40 12 16 0 39,
   cbColumn "reserved" 52 5]

-- Initial algorithm: Spec/CommBLayouts.lean:276.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-10; Sun (2nd ed.), ch.17 table 17.2. Angles are degrees, track rate degrees/second, speeds knots. -/
def bds50Layout : List PayloadColumn :=
  [cbColumn "roll_valid" 1 1,
   cbColumn "roll" 2 10 (45/256) 0 1 .twosComplement,
   cbColumn "track_valid" 12 1,
   cbColumn "track" 13 11 (90/512) 0 12 .twosComplement,
   cbColumn "groundspeed_valid" 24 1,
   cbColumn "groundspeed" 25 10 2 0 24,
   cbColumn "track_rate_valid" 35 1,
   cbColumn "track_rate" 36 10 (8/256) 0 35 .twosComplement,
   cbColumn "tas_valid" 46 1,
   cbColumn "TAS" 47 10 2 0 46]

-- Initial algorithm: Spec/CommBLayouts.lean:289.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-10; Sun (2nd ed.), ch.17 table 17.3. Heading is degrees, IAS knots, rates feet/minute. -/
def bds60Layout : List PayloadColumn :=
  [cbColumn "heading_valid" 1 1,
   cbColumn "heading" 2 11 (90/512) 0 1 .twosComplement,
   cbColumn "ias_valid" 13 1,
   cbColumn "IAS" 14 10 1 0 13,
   cbColumn "mach_valid" 24 1,
   cbColumn "Mach" 25 10 (1/250) 0 24,
   cbColumn "barometric_rate_valid" 35 1,
   cbColumn "vrate_barometric" 36 10 32 0 35 .twosComplement,
   cbColumn "inertial_rate_valid" 46 1,
   cbColumn "vrate_inertial" 47 10 32 0 46 .twosComplement]

-- Initial algorithm: Spec/CommBLayouts.lean:302.
/-- Sun chs.16–18 register catalogue; supplementary bitmaps/registration are
explicitly rs1090-derived as recorded above. BDS05/65 use ADSB layouts separately. -/
def commBLayout (register : Nat) : Option (List PayloadColumn) :=
  match register with
  | 0x10 => some bds10Layout
  | 0x17 => some bds17Layout
  | 0x18 => some bds18Layout
  | 0x19 => some bds19Layout
  | 0x20 => some bds20Layout
  | 0x21 => some bds21Layout
  | 0x30 => some bds30Layout
  | 0x40 => some bds40Layout
  | 0x44 => some bds44Layout
  | 0x45 => some bds45Layout
  | 0x50 => some bds50Layout
  | 0x60 => some bds60Layout
  | _ => none

end Lean1090.Impl

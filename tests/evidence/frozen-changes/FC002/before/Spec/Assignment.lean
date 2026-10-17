import Spec.AssignmentAltitude
import Spec.Semantics
import Spec.Parity

/-!
Encoder-side complete message assignment, independent of decoder entrypoints.
The input is the independently chosen Frame fields. Named payload assignments
are assembled from individual source-table bit columns by a bit-by-bit fold;
there is no call to decodeADSB/decodeBDS or their record helpers. Register sets
are selected directly by the documented predicates, not by inference output.
Altitude meanings use the separate MSB-first assignment interpretation.
Mathematical scales, source tables, string alphabets and Float-expression
formulas are shared specification constants. Source anchors independently test
those constants against the published examples. scripts/CheckHypotheses.lean
checks the actual transitive dependency graph of the final assigned constructor.
-/
namespace Lean1090.Spec.Assignment
open Presentation

/-- ICAO Annex10 IV, fourth edition (2007), table3-3: assigned payload bits
are numbered1…56 from the MSB. Build each field one bit at a time instead of
calling the reference decoder's division/modulus field reader. -/
def columnCode (word start width : Nat) : Nat :=
  (List.range width).foldl (fun value i =>
    2*value + if word.testBit (56-start-i) then 1 else 0) 0

/-- ICAO Annex10 IV, fourth edition (2007), table3-3; Sun, second edition
(2021), tables5.1–8.3 and16.1–18.2: construct independent named assignments
in published column order, including reserved/status/unavailable codes. -/
def payloadAssignment (kind word : Nat) (columns : List PayloadColumn) : PayloadRecord :=
  ⟨kind, columns.map fun c => ⟨c.name, columnCode word c.start c.width⟩⟩

/-- Sun, second edition (2021), table3.3 and tables5.1–8.3: the chosen TC,
subtype and version determine the source-table assignment. Receiver rejection
is stated by adsbHardValid independently of payload record construction. -/
def adsbAssignment (word : Nat) : Option PayloadRecord :=
  if word ≥ 2^56 || !adsbHardValid word then none else
    (adsbLayout word).map (payloadAssignment (adsbKind word) word)

/-- rs1090-derived commb.rs at685dfaa: the BDS05 candidate agrees with the
outer AC13 meaning and uses TC9–18/20–21; BDS65 is excluded by the documented
offset/leftover policy. Other candidates use their independent predicates. -/
def candidate (df : Nat) (outer : Option Int) (reg word : Nat) : Bool :=
  (df == 20 || df == 21) && word != 0 &&
  (if reg == 0x05 then
    let tc := columnCode word 1 5
    df == 20 && tc ≥ 9 && tc < 22 && tc != 19 &&
      bdsWireValid 0x05 word && decide (compatibility12 (columnCode word 9 12) = outer)
   else if reg == 0x65 then false else commBCoreEligible reg word)

/-- Sun, second edition (2021), tables5.1/8.2–8.3/16.1–18.2 plus the explicit
rs1090-derived candidate predicates: enumerate the assignment's qualifying
registers and construct their named fields directly from source columns. -/
def commBAssignments (df : Nat) (outer : Option Int) (word : Nat) : List (Nat × PayloadRecord) :=
  commBRegisters.filterMap fun reg =>
    if candidate df outer reg word then
      (bdsLayout reg word).map fun cols => (reg, payloadAssignment reg word cols)
    else none

/-- Sun, second edition (2021), tables5.1/6.1/7.1–7.3: exact expected meanings
of independently assigned ADS-B codes. Altitude uses the independent bit fold;
other scales and availability formulas are shared source-table constants. -/
def adsbStandardValues (word : Nat) : Semantics.Values :=
  let tc := payloadBits word 1 5
  let b := payloadBits word
  if 5 <= tc && tc <= 8 then
    [("NUCp", some (adsbNUCp tc)), ("groundspeed", adsbMovement (b 6 7))]
  else if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("NUCp", some (adsbNUCp tc)),
     ("NICb", if tc < 19 then some (b 8 1) else none),
     ("altitude_feet", if tc < 19 then (altitude12 (b 9 12)).map (fun n => (n : Rat)) else none),
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

/-- rs1090-derived bds05/bds09 compatibility values, pinned685dfaa: the
independent altitude assignment preserves the documented source discrepancy;
other numeric code formulas remain explicitly shared source constants. -/
def adsbCompatibilityValues (word : Nat) : Semantics.Values :=
  let tc := payloadBits word 1 5
  if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("NUCp", some (adsbNUCp tc)),
     ("NICb", if tc < 19 then some (payloadBits word 8 1) else none),
     ("altitude_feet", (compatibility12 (payloadBits word 9 12)).map (fun n => (n : Rat)))]
  else if tc == 19 then
    let (ew, ns) := adsbOracleVelocityComponents word
    let subtype := payloadBits word 6 3
    [("east_velocity", if subtype == 1 || subtype == 2 then some ew else none),
     ("north_velocity", if subtype == 1 || subtype == 2 then some ns else none),
     ("vertical_rate", (adsbVerticalRate word).map (fun n => (n : Rat))),
     ("geo_minus_baro", (adsbGeoMinusBaro word).map (fun n => (n : Rat))),
     ("airspeed", if subtype == 3 || subtype == 4 then
       (adsbAirspeed word).map (fun n => (n : Rat)) else none)]
  else adsbStandardValues word

/-- Sun, second edition (2021), chs.4–8 tables: complete assignment meaning.
Labels, affine tables and expression ASTs are shared mathematical projection
constants; the decoder-only semantic constructors are never invoked here. -/
def adsbMeaning (word : Nat) : Semantics.Payload :=
  ⟨Semantics.tableValues ((adsbLayout word).getD []) word,
   adsbStandardValues word, adsbCompatibilityValues word,
   Semantics.adsbLabels false word, Semantics.adsbLabels true word,
   Semantics.adsbStandardFloats word, oracleADSBFloats word, none, none⟩

/-- ICAO Annex10 IV, fourth edition (2007), §4.3.8.4.2.2.1.6: independent
threat field assignment; the compatibility view applies the explicit rs1090
altitude/range/bearing policy instead of the standard quantized-range meaning. -/
def compatibilityThreat (word : Nat) : CommBThreat :=
  match columnCode word 29 2 with
  | 0 => .none
  | 1 => .address (columnCode word 31 24)
  | 2 =>
    let range := columnCode word 44 7
    let bearing := columnCode word 51 6
    .orientation (compatibility13 (columnCode word 31 13))
      (if range == 0 then none else some ((range - 1 : Nat) / 10 : Rat))
      (if bearing == 0 then none else some (6 * (bearing - 1) + 3))
  | _ => .unassigned

/-- ICAO Annex10 IV, fourth edition (2007), amendment85, §4.3.8.4.2.2.1.6
printed pages4-21–22: assigned standard threat meanings. Typed range/bearing
constructors use their published total finite-code tables. -/
def standardThreat (word : Nat) : Option StandardCommBThreat :=
  if word ≥ 2^56 then none else
    match columnCode word 29 2 with
    | 0 => some .none
    | 1 => if columnCode word 55 2 == 0 then
        some (.address (columnCode word 31 24)) else none
    | 2 => some (.orientation (gillhamHeight (columnCode word 31 13))
        (standardThreatRange (Fin.ofNat 128 (columnCode word 44 7)))
        (standardThreatBearing (Fin.ofNat 64 (columnCode word 51 6))))
    | _ => some .unassigned

/-- Sun, second edition (2021), tables16.1–18.2 and ICAO Annex10 IV, fourth
edition (2007), threat tables cited above: complete named candidate meanings,
including source/oracle threat disagreement. No decoded candidate is an input. -/
def commBMeaning (register word : Nat) : Semantics.Payload :=
  if register == 0x05 || register == 0x65 then adsbMeaning word else
    let layout := (commBLayout register).getD []
    { tableValues := Semantics.tableValues layout word
      standardValues := Semantics.tableValues layout word
      oracleValues := layout.map fun c => (c.name, commBValue register word c.name)
      standardLabels := Semantics.commBLabels register word
      oracleLabels := Semantics.commBLabels register word
      standardFloats := Semantics.commBStandardFloats register word
      oracleFloats := oracleCommBFloats register word
      standardThreat := if register == 0x30 then standardThreat word else none
      oracleThreat := if register == 0x30 then some (compatibilityThreat word) else none }

/-- Sun, second edition (2021), chs.5/13: assigned outer altitude value,
including a distinct unsigned GNSS metre height for TC20–22. -/
def altitude (f : Frame) : Option Altitude.Value :=
  match f.body with
  | .shortACAS h | .longACAS h _ => altitude13 h.ac.toNat
  | .surveillance false h | .commB false h _ => altitude13 h.code.toNat
  | .extended _ _ _ me =>
      let tc := columnCode me.toNat 1 5
      if tc ≥ 9 && tc ≤ 18 then
        (altitude12 (columnCode me.toNat 9 12)).map Altitude.Value.feet
      else if tc ≥ 20 && tc ≤ 22 then some (.metres (columnCode me.toNat 9 12))
      else none
  | _ => none

/-- rs1090-derived outer AC13 meaning for the DF20 candidate predicate;
DF21 identity replies have no outer altitude. -/
def outerAltitude (f : Frame) : Option Int :=
  match f.body with
  | .commB false h _ => compatibility13 h.code.toNat
  | _ => none

/-- Annex10 IV, fourth edition (2007), §§3.1.2.3.3/3.1.2.5.2.2/3.1.2.6.7.1:
construct the complete expected report directly from assigned fields. Parity
polynomials, identity permutations and table meanings are shared mathematical
specifications; no report, payload decoder or inference function is called. -/
def expectedReport (f : Frame) : Report :=
  let syndrome := Parity.checksum f.body.informationBits (packFields f.body.parts) ^^^ f.parity
  let address := match f.body with
    | .allCall _ aa | .extended _ _ aa _ => some aa
    | .military _ _ => none
    | _ => some syndrome
  let interrogator := match f.body with
    | .allCall _ _ => Parity.interrogator syndrome
    | _ => none
  let identity := match f.body with
    | .surveillance true h | .commB true h _ => some (identityCode h.code)
    | .extended _ _ _ me => if columnCode me.toNat 1 5 == 28 then
        some (identityCode (BitVec.ofNat 13 (columnCode me.toNat 12 13))) else none
    | _ => none
  let adsb := match f.body with
    | .extended _ _ _ me => adsbAssignment me.toNat
    | _ => none
  let candidates := match f.body with
    | .commB isIdentity _ mb => commBAssignments (if isIdentity then 21 else 20)
        (outerAltitude f) mb.toNat
    | _ => []
  { crc := syndrome, address, interrogator, altitude := altitude f, identity, adsb,
    commB := candidates
    semanticADSB := match f.body with
      | .extended _ _ _ me => some (adsbMeaning me.toNat)
      | _ => none
    semanticCommB := match f.body with
      | .commB _ _ mb => candidates.map fun (reg, _) => (reg, commBMeaning reg mb.toNat)
      | _ => [] }

end Lean1090.Spec.Assignment

import Impl.CommBLayouts
import Impl.ADSB
import Impl.Binary64

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl
open Lean1090.Spec

-- Initial algorithm: Spec/CommB.lean:23.
/-- Sun chs.17–18 status fields; rs1090-derived rejection requires zero
payload when status is zero. The width includes the sign where present. -/
def cbStatus (word status start width : Nat) : Bool :=
  payloadBits word status 1 == 1 || payloadBits word start width == 0

-- Initial algorithm: Spec/CommB.lean:28.
/-- Sun, 2nd ed. (2021), ch.17 two's complement quantities, before unit scaling. -/
def cbSigned (word start width : Nat) : Rat :=
  (payloadInteger .twosComplement width (payloadBits word start width) : Rat)

-- Initial algorithm: Spec/CommB.lean:32.
/-- rs1090-derived bds40.rs read_selected: exact integer presentation rule
`((raw * 16 + 8) / 100) * 100` feet, including its non-nearest-100 behavior. -/
def cbSelected (code : Nat) : Rat := (((code * 16 + 8) / 100) * 100 : Nat)

-- Initial algorithm: Spec/CommB.lean:36.
/-- rs1090-derived bds44.rs read_temperature: signed quarter-degrees followed
by a +256-degree wrap correction whenever the initial temperature is < -80. -/
def cbTemperature44 (word : Nat) : Rat :=
  let initial := cbSigned word 24 11 / 4
  if initial < -80 then initial + 256 else initial

-- Initial algorithm: Spec/CommB.lean:42.
/-- rs1090-derived bds60.rs read_vertical: magnitude code 0 or 511 denotes
zero regardless of sign; all other codes use signed 32 ft/min scaling. -/
def cbVertical60 (word start : Nat) : Rat :=
  let magnitude := payloadBits word (start + 1) 9
  if magnitude == 0 || magnitude == 511 then 0 else cbSigned word start 10 * 32

-- Initial algorithm: Spec/CommB.lean:48.
/-- rs1090-derived bds40.rs: binary64 `raw * 0.1 + 800`, preserving two rounds. -/
def cbQNH64 (word : Nat) : Rat :=
  Binary64.add (Binary64.mul (payloadBits word 28 12 : Rat)
    (Binary64.literal (1 / 10))) 800

-- Initial algorithm: Spec/CommB.lean:53.
/-- rs1090-derived bds60.rs: binary64 `raw * 2.048 / 512`, preserving the
rounded decimal constant and operation order instead of replacing it by /250. -/
def cbMach64 (word : Nat) : Rat :=
  Binary64.div (Binary64.mul (payloadBits word 25 10 : Rat)
    (Binary64.literal (256 / 125))) 512

-- Initial algorithm: Spec/CommB.lean:59.
/-- rs1090-derived bds50/bds60: wrap negative heading/track to [0,360). -/
def cbWrapAngle (value : Rat) : Rat := if value < 0 then value + 360 else value

-- Initial algorithm: Spec/CommB.lean:62.
/-- Sun chs.16–18 standard unit projections, with named rs1090-derived
presentation exceptions: BDS10 DTE native-endian reporting on the pinned x86_64
target (bds10.rs/deku0.20.3), BDS40 altitude rounding, BDS44 temperature correction,
BDS50 unavailable rate sentinel, BDS60 rate sentinels and wrapped headings.
The QNH/Mach values here are exact pre-Float quantities; score arithmetic uses
`cbQNH64` / `cbMach64` separately. -/
def commBValue (register word : Nat) (name : String) : Option Rat := do
  let layout ← commBLayout register
  let c ← layout.find? (fun c => c.name == name)
  let value ← payloadValue c word
  match register, name with
  | 0x10, "dte" => some (payloadBits word 41 8 + 256 * payloadBits word 49 8 : Rat)
  | 0x40, "selected_mcp" => some (cbSelected (payloadBits word 2 12))
  | 0x40, "selected_fms" => some (cbSelected (payloadBits word 15 12))
  | 0x44, "temperature" => some (cbTemperature44 word)
  | 0x50, "track" => some (cbWrapAngle value)
  | 0x50, "track_rate" =>
    if payloadBits word 37 9 == 511 then none else some value
  | 0x60, "heading" => some (cbWrapAngle value)
  | 0x60, "vrate_barometric" => some (cbVertical60 word 36)
  | 0x60, "vrate_inertial" => some (cbVertical60 word 47)
  | _, _ => some value

-- Initial algorithm: Spec/CommB.lean:83.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-8: A–Z, digits, space; all unassigned
symbols remain visible as '#', following rs1090's output policy. -/
def cbCharacter (code : Nat) : Char :=
  if 1 ≤ code && code ≤ 26 then Char.ofNat (64 + code)
  else if 48 ≤ code && code ≤ 57 then Char.ofNat code
  else if code == 32 then ' ' else '#'

-- Initial algorithm: Spec/CommB.lean:90.
/-- rs1090-derived bds08.rs callsign_read, reused by BDS20: discard every
code 32 (including interior spaces); code zero remains its lookup character. -/
def cbCallsign (word : Nat) : String :=
  String.ofList (((List.range 8).map fun i => payloadBits word (9 + 6*i) 6)
    |>.filter (· != 32) |>.map cbCharacter)

-- Initial algorithm: Spec/CommB.lean:96.
/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.6: TTI selects address or AC13/range/bearing.
rs1090-derived edge policy: range127 is12.6NM and bearing61–63 are numeric
midpoints, although the normative table assigns saturation/reserved meanings. -/
def cbThreat (word : Nat) : CommBThreat :=
  match payloadBits word 29 2 with
  | 0 => .none
  | 1 => .address (payloadBits word 31 24)
  | 2 =>
    let range := payloadBits word 44 7
    let bearing := payloadBits word 51 6
    .orientation (Altitude.oracleAC13 (payloadBits word 31 13))
      (if range == 0 then none else some ((range - 1 : Nat) / 10 : Rat))
      (if bearing == 0 then none else some (6 * (bearing - 1) + 3))
  | _ => .unassigned

-- Initial algorithm: Spec/CommB.lean:111.
/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.6.2 coding table, actually read on
printed page4-21:0 unavailable;1 below0.05;2–126 (n−1)/10±0.05;
127 above12.55 nautical miles. -/
def standardThreatRange (code : Fin 128) : StandardThreatRange :=
  if code.val == 0 then .unavailable
  else if code.val == 1 then .lessThan (1/20)
  else if code.val == 127 then .greaterThan (251/20)
  else .estimate ((code.val-1 : Nat) / 10) (1/20)

-- Initial algorithm: Spec/CommB.lean:120.
/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.6.3 coding table, actually read on
printed page4-22:1–60 identify sectors6(n−1)…6n degrees;61–63 unassigned. -/
def standardThreatBearing (code : Fin 64) : StandardThreatBearing :=
  if code.val == 0 then .unavailable
  else if code.val ≤ 60 then .sector (6*(code.val-1)) (6*code.val)
  else .unassigned code.val

-- Initial algorithm: Spec/CommB.lean:127.
/-- ICAO Annex10 IV (4th ed., 2007) §4.3.8.4.2.2.1.5–6, printed pages4-21–22:
standard view kept separately from `cbThreat`'s explicit oracle compatibility.
A nonzero required address padding field is rejected. Unassigned TTI/bearing
codes remain explicitly unassigned and never become fabricated quantities. -/
def cbStandardThreat (word : Nat) : Option StandardCommBThreat :=
  if word ≥ 2^56 then none else
    match payloadBits word 29 2 with
    | 0 => some .none
    | 1 => if payloadBits word 55 2 == 0 then
        some (.address (payloadBits word 31 24)) else none
    | 2 => some (.orientation (Altitude.decodeGillham (payloadBits word 31 13))
        (standardThreatRange ⟨payloadBits word 44 7, Nat.mod_lt _ (by decide)⟩)
        (standardThreatBearing ⟨payloadBits word 51 6, Nat.mod_lt _ (by decide)⟩))
    | _ => some .unassigned

-- Initial algorithm: Spec/CommB.lean:150.
/-- rs1090-derived bds21.rs: code 0, 32 and 45 are removed dash placeholders. -/
def cbDashPlaceholder (code : Nat) : Bool := code == 0 || code == 32 || code == 45

-- Initial algorithm: Spec/CommB.lean:153.
/-- rs1090-derived bds21.rs: seven six-bit aircraft-registration characters. -/
def cbRegistrationCodes (word : Nat) : List Nat :=
  ((List.range 7).map fun i => payloadBits word (2 + 6*i) 6).filter
    (fun c => !cbDashPlaceholder c)

-- Initial algorithm: Spec/CommB.lean:158.
/-- rs1090-derived bds21.rs: registration is absent for false status,
otherwise the dash-less string (which can be empty). -/
def cbRegistration (word : Nat) : Option String :=
  if payloadBits word 1 1 == 0 then none
  else some (String.ofList ((cbRegistrationCodes word).map cbCharacter))

-- Initial algorithm: Spec/CommB.lean:164.
/-- rs1090-derived bds17.rs: default-feature must-set/must-clear bits and
27-bit zero suffix; the intervening five reserved bits are *not* rejected. -/
def cbValid17 (word : Nat) : Bool :=
  payloadBits word 7 1 == 1 && payloadBits word 30 27 == 0 &&
  [10,11,12,15,20,21,22].all (fun i => payloadBits word i 1 == 0)

-- Initial algorithm: Spec/CommB.lean:170.
/-- rs1090-derived bds18.rs: default-feature allowed bitmap and four
mandatory support indications. Index 1 is register 0x38, index56 register01. -/
def cbValid18 (word : Nat) : Bool :=
  let allowed := [0x30,0x21,0x20,0x1f,0x1e,0x1d,0x1c,0x1b,0x1a,
    0x19,0x18,0x17,0x10,0x0f,0x0b,0x0a,0x09,0x08,0x07,0x06,0x05]
  (List.range 56).all (fun i => allowed.contains (56-i) || payloadBits word (i+1) 1 == 0) &&
  [0x20,0x19,0x18,0x17].all (fun r => payloadBits word (57-r) 1 == 1)

-- Initial algorithm: Spec/CommB.lean:178.
/-- rs1090-derived bds19.rs: only the listed register-support bits may be set. -/
def cbValid19 (word : Nat) : Bool :=
  let allowed := [0x65,0x62,0x61,0x60,0x5f,0x53,0x52,0x51,0x50,0x45,0x44,0x40]
  (List.range 56).all (fun i => allowed.contains (112-i) || payloadBits word (i+1) 1 == 0)

-- Initial algorithm: Spec/CommB.lean:183.
/-- rs1090-derived bds21.rs: false status allows only stripped placeholders;
airline status must be false and both airline characters placeholders; a
present aircraft registration has at most two '#' unknown symbols. -/
def cbValid21 (word : Nat) : Bool :=
  let codes := cbRegistrationCodes word
  (if payloadBits word 1 1 == 0 then codes.isEmpty
   else (codes.filter (fun c => cbCharacter c == '#')).length ≤ 2) &&
  payloadBits word 44 1 == 0 &&
  cbDashPlaceholder (payloadBits word 45 6) && cbDashPlaceholder (payloadBits word 51 6)

-- Initial algorithm: Spec/CommB.lean:193.
/-- rs1090-derived bds40.rs: status consistency, both spare regions zero,
rounded selected altitude ≤50000ft, binary64 pressure in [800,1200]hPa.
Mode/status and target-source/status consistency are not enforced by rs1090. -/
def cbValid40 (word : Nat) : Bool :=
  cbStatus word 1 2 12 && cbStatus word 14 15 12 && cbStatus word 27 28 12 &&
  payloadBits word 40 8 == 0 && payloadBits word 52 2 == 0 &&
  cbSelected (payloadBits word 2 12) ≤ 50000 &&
  cbSelected (payloadBits word 15 12) ≤ 50000 &&
  cbQNH64 word ≥ 800 && cbQNH64 word ≤ 1200

-- Initial algorithm: Spec/CommB.lean:203.
/-- rs1090-derived bds44.rs: FOM1/2 only, wind≤250kt, temperature fallback
followed by [-80,60]C, and both turbulence and humidity absent/zero. -/
def cbValid44 (word : Nat) : Bool :=
  (payloadBits word 1 4 == 1 || payloadBits word 1 4 == 2) &&
  cbStatus word 5 6 18 && payloadBits word 6 9 ≤ 250 &&
  cbTemperature44 word ≥ -80 && cbTemperature44 word ≤ 60 &&
  cbStatus word 35 36 11 && payloadBits word 47 10 == 0

-- Initial algorithm: Spec/CommB.lean:211.
/-- rs1090-derived bds45.rs: all hazard fields absent, spare bits zero,
status consistency for pressure/height. An unavailable temperature may retain
its sign bit, but its nine magnitude bits must be zero. -/
def cbValid45 (word : Nat) : Bool :=
  payloadBits word 1 15 == 0 && payloadBits word 52 5 == 0 &&
  (if payloadBits word 16 1 == 0 then payloadBits word 18 9 == 0
   else cbSigned word 17 10 / 4 ≥ -80 && cbSigned word 17 10 / 4 ≤ 60) &&
  cbStatus word 27 28 11 && cbStatus word 39 40 12

-- Initial algorithm: Spec/CommB.lean:220.
/-- rs1090-derived bds50.rs: per-field status consistency, |roll|≤45°,
groundspeed≤700kt and present TAS in [80,600]kt. A track-rate magnitude511
is unavailable, not a malformed payload. -/
def cbValid50 (word : Nat) : Bool :=
  cbStatus word 1 2 10 && cbStatus word 12 13 11 && cbStatus word 24 25 10 &&
  cbStatus word 35 36 10 && cbStatus word 46 47 10 &&
  (cbSigned word 2 10 * 45 / 256).abs ≤ 45 &&
  payloadBits word 25 10 * 2 ≤ 700 &&
  (payloadBits word 46 1 == 0 ||
    (payloadBits word 47 10 * 2 ≥ 80 && payloadBits word 47 10 * 2 ≤ 600))

-- Initial algorithm: Spec/CommB.lean:231.
/-- rs1090-derived bds60.rs: per-field status consistency, IAS≤500kt,
binary64 Mach≤1, inertial vertical-rate magnitude≤6000ft/min after sentinel
handling. Barometric vertical rate has no plausibility bound. -/
def cbValid60 (word : Nat) : Bool :=
  cbStatus word 1 2 11 && cbStatus word 13 14 10 && cbStatus word 24 25 10 &&
  cbStatus word 35 36 10 && cbStatus word 46 47 10 &&
  payloadBits word 14 10 ≤ 500 && cbMach64 word ≤ 1 &&
  (cbVertical60 word 47).abs ≤ 6000

-- Initial algorithm: Spec/CommB.lean:240.
/-- rs1090-derived register decoder predicates before the score gate.
BDS10/20/30 use their byte header; only BDS10 additionally checks spare bits.
BDS30 accepts every TTI variant and retains otherwise ignored bits. -/
def bdsWireValid (register word : Nat) : Bool :=
  word < 2^56 && match register with
  | 0x05 =>
    let tc := payloadBits word 1 5
    ((tc ≥ 9 && tc ≤ 18) || (tc ≥ 20 && tc ≤ 22)) && adsbHardValid word
  | 0x65 => payloadBits word 1 5 == 31 && payloadBits word 6 3 < 2 && adsbHardValid word
  | 0x10 => payloadBits word 1 8 == 0x10 && payloadBits word 10 5 == 0
  | 0x17 => cbValid17 word
  | 0x18 => cbValid18 word
  | 0x19 => cbValid19 word
  | 0x20 => payloadBits word 1 8 == 0x20
  | 0x21 => cbValid21 word
  | 0x30 => payloadBits word 1 8 == 0x30
  | 0x40 => cbValid40 word
  | 0x44 => cbValid44 word
  | 0x45 => cbValid45 word
  | 0x50 => cbValid50 word
  | 0x60 => cbValid60 word
  | _ => false

-- Initial algorithm: Spec/CommB.lean:263.
/-- Sun, 2nd ed. (2021), tables5.1,8.2–8.3 and16.1–18.2: select a register layout from
wire discriminants. BDS65's detailed subfields are explicitly rs1090-derived
through ADSB. This direct register decoder is distinct from Comm-B inference. -/
def bdsLayout (register word : Nat) : Option (List PayloadColumn) :=
  if register == 0x05 then some adsbPositionLayout
  else if register == 0x65 then adsbLayout word
  else commBLayout register

-- Initial algorithm: Spec/CommB.lean:282.
/-- Sun chs.5,8,16–18 tables, plus explicitly rs1090-derived supplementary layouts:
named reference decoder before Comm-B candidate-set inference. -/
def decodeBDS (register word : Nat) : Option PayloadRecord := do
  let layout ← bdsLayout register word
  if bdsWireValid register word then
    some ⟨register, decodePayloadFields layout word⟩ else none

-- Initial algorithm: Spec/CommB.lean:358.
/-- rs1090-derived density.rs: Gaussian score in exact binary64 operation
order: z=(value-mu)/sigma; then (-0.5*z)*z. -/
def cbGaussian (value mu sigma : Rat) : Rat :=
  let z := Binary64.div (Binary64.sub value (Binary64.literal mu)) (Binary64.literal sigma)
  Binary64.mul (Binary64.mul (-1/2) z) z

-- Initial algorithm: Spec/CommB.lean:364.
/-- rs1090-derived density.rs: negative absolute deviation divided by scale. -/
def cbLaplace (value median scale : Rat) : Rat :=
  if scale ≤ 0 then 0 else
    Binary64.div (-(Binary64.sub value (Binary64.literal median)).abs) (Binary64.literal scale)

-- Initial algorithm: Spec/CommB.lean:369.
/-- rs1090-derived density.rs: skip absent fields, preserving source order. -/
def cbScoreField (value : Option Rat) (score : Rat → Rat) : List Rat :=
  match value with | none => [] | some value => [score value]

-- Initial algorithm: Spec/CommB.lean:373.
/-- rs1090-derived density.rs: each register's complete field-density list,
including the exact field order which affects binary64 rounding. -/
def cbDensityTerms (register word : Nat) : List Rat :=
  let value := commBValue register word
  match register with
  | 0x40 =>
    cbScoreField ((value "barometric_setting").map fun _ => cbQNH64 word)
      (fun x => cbLaplace x (10132/10) (54/10)) ++
    cbScoreField (value "selected_mcp") (fun x => cbGaussian x 24688 10844) ++
    cbScoreField (value "selected_fms") (fun x => cbGaussian x 24688 10844)
  | 0x50 =>
    cbScoreField (value "roll") (fun x => cbLaplace x 0 10) ++
    cbScoreField (value "track_rate") (fun x => cbLaplace x 0 (70/100)) ++
    cbScoreField (value "TAS") (fun x => cbGaussian x 413 120) ++
    cbScoreField (value "groundspeed") (fun x => cbGaussian x 418 129)
  | 0x60 =>
    cbScoreField (value "IAS") (fun x => cbGaussian x 272 55) ++
    cbScoreField ((value "Mach").map fun _ => cbMach64 word)
      (fun x => cbGaussian x (69/100) (21/100)) ++
    cbScoreField (value "vrate_inertial") (fun x => cbGaussian x (-298) 1669)
  | 0x44 =>
    [cbLaplace (cbTemperature44 word) (-21) (990/100)] ++
    cbScoreField (value "wind_speed") (fun x => cbGaussian x 52 29) ++
    cbScoreField (value "pressure") (fun x => cbLaplace x 393 290)
  | 0x45 =>
    cbScoreField (value "static_temperature") (fun x => cbGaussian x (-142/10) (164/10)) ++
    cbScoreField (value "static_pressure") (fun x => cbLaplace x 393 290)
  | _ => []

-- Initial algorithm: Spec/CommB.lean:402.
/-- rs1090-derived density.rs Acc: binary64 sequential sum divided by count;
no scored fields yields zero for the combined gate. -/
def cbDensity (register word : Nat) : Rat :=
  let terms := cbDensityTerms register word
  if terms.isEmpty then 0
  else Binary64.div (terms.foldl Binary64.add 0) (terms.length : Rat)

-- Initial algorithm: Spec/CommB.lean:409.
/-- rs1090-derived penalty.rs: BDS50 wind and opposite-sign turn penalties,
BDS60 IAS/Mach-ratio penalty; source operation order is preserved. -/
def cbPenalty (register word : Nat) : Rat :=
  let value := commBValue register word
  match register with
  | 0x50 =>
    let p := match value "TAS", value "groundspeed" with
      | some tas, some gs => Binary64.sub 0 (Binary64.div (Binary64.sub tas gs).abs 100)
      | _, _ => 0
    match value "roll", value "track_rate" with
    | some roll, some rate =>
      if roll.abs > 5 && rate.abs > Binary64.literal (3/10) &&
          decide (roll > 0) != decide (rate > 0) then Binary64.sub p 2 else p
    | _, _ => p
  | 0x60 =>
    match value "IAS", value "Mach" with
    | some ias, some _ =>
      let mach := cbMach64 word
      if mach > 0 then
        let ratio := Binary64.div ias mach
        if ratio < 250 || ratio > 800 then -3 else 0
      else 0
    | _, _ => 0
  | _ => 0

-- Initial algorithm: Spec/CommB.lean:434.
/-- rs1090-derived bds/mod.rs validate_score_gate: the final score, exposing
the exact proof-visible rational that represents the oracle binary64 result. -/
def cbCombinedScore (register word : Nat) : Rat :=
  Binary64.add (cbDensity register word) (cbPenalty register word)

-- Initial algorithm: Spec/CommB.lean:439.
/-- rs1090-derived bds/mod.rs validate_score_gate: accept score≥-3. The raw
Message::from_bytes path applies this only to 40/44/45/50/60, not to 05. -/
def cbScorePasses (register word : Nat) : Bool :=
  cbCombinedScore register word ≥ -3

-- Initial algorithm: Spec/CommB.lean:444.
/-- rs1090-derived commb.rs: per-message core candidates in decoder order,
excluding ADSB-backed BDS05/65 which are integrated separately. -/
def commBCoreRegisters : List Nat :=
  [0x10,0x17,0x18,0x19,0x20,0x21,0x30,0x40,0x44,0x45,0x50,0x60]

-- Initial algorithm: Spec/CommB.lean:449.
/-- rs1090-derived commb.rs candidate predicate: both wire/field constraints
and the score gate for the five scored candidates. -/
def commBCoreEligible (register word : Nat) : Bool :=
  commBCoreRegisters.contains register && bdsWireValid register word &&
  (if [0x40,0x44,0x45,0x50,0x60].contains register then cbScorePasses register word else true)

-- Initial algorithm: Spec/CommB.lean:464.
/-- rs1090-derived commb.rs DF20 reader: BDS05 is tried only for TC9–18,
20–21 (the Rust half-open range excludes22), and its altitude must equal the
outer AC13 altitude exactly, including None=None. There is no density gate. -/
def commBPositionEligible (df : Nat) (outerAltitude : Option Int) (word : Nat) : Bool :=
  let tc := payloadBits word 1 5
  df == 20 && tc ≥ 9 && tc < 22 && tc != 19 &&
    bdsWireValid 0x05 word && decide (adsbAltitude word = outerAltitude)

-- Initial algorithm: Spec/CommB.lean:472.
/-- rs1090-derived commb.rs + deku_derive0.20.3 emit_try_from:
the TC31 subtype0/1 guard is followed by a TryFrom decoder with no five-bit
skip. It reads reserved subtype7 and40 data bits, consumes43bits of56, and
TryFrom rejects leftover bytes. Thus BDS65 never survives this API. A direct
BDS65 schema codec remains available for field round-trip statements. -/
def commBOperationEligible (_word : Nat) : Bool := false

-- Initial algorithm: Spec/CommB.lean:479.
/-- rs1090-derived commb.rs: actual per-message eligibility includes the
empty-MB short circuit, DF20 altitude policy and the BDS65 offset rejection.
No winner selection is performed here; sanitize is a separate stateful API. -/
def commBEligible (df : Nat) (outerAltitude : Option Int) (register word : Nat) : Bool :=
  (df == 20 || df == 21) && word != 0 &&
  (if register == 0x05 then commBPositionEligible df outerAltitude word
   else if register == 0x65 then commBOperationEligible word
   else commBCoreEligible register word)

-- Initial algorithm: Spec/CommB.lean:488.
/-- rs1090-derived commb.rs: complete reported-register order for DF20/21. -/
def commBRegisters : List Nat := 0x05 :: commBCoreRegisters ++ [0x65]

-- Initial algorithm: Spec/CommB.lean:491.
/-- rs1090-derived commb.rs DF20/DF21 readers: retain every eligible
candidate, in the same order, with no cross-candidate suppression. -/
def inferCommB (df : Nat) (outerAltitude : Option Int) (word : Nat) : List (Nat × PayloadRecord) :=
  commBRegisters.filterMap fun register =>
    if commBEligible df outerAltitude register word then
      (decodeBDS register word).map fun record => (register, record)
    else none

end Lean1090.Impl

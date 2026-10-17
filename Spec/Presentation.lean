import Model.Types
import Spec.ADSB

/-!
# Exact operands and explicitly unproved floating presentation

All `oracle*` definitions are rs1090-derived from pinned commit
685dfaa34c5ab186c691bca3cfe2a22e12517d30, files decode/bds/bds06.rs,
bds09.rs, bds30.rs, bds40.rs, bds44.rs, bds45.rs, bds50.rs, bds60.rs,
bds62.rs. `docs/SOURCES.md` records acquisition. Source-table alternatives
are separately named and cite Sun's second edition (2021).

This AST specifies operation precision and order. It is NOT an assertion that
Lean/Rust Float or libm is formally verified. Its evaluator and serialization
are part of the later tested presentation boundary. Exact field decoding and
exact operands belong to the proof domain. No Float operation is used to
implement an acceptance predicate here; Comm-B decisions use Spec.Binary64.
CPR's ordered formulas and reference policies are documented separately in
Spec.CPR, Spec.CPRContracts and SCOPE.md.
-/
namespace Lean1090.Spec.Presentation

/-- rs1090 numeric readers: a cast from an exact integer/rational operand. -/
def literal (p : Precision) (q : Rat) : FloatExpr := .literal p q

/-- rs1090 angle readers: multiply THEN divide, without algebraic reassociation. -/
def scaled (p : Precision) (value numerator denominator : Rat) : FloatExpr :=
  .div p (.mul p (.literal p value) (.literal p numerator)) (.literal p denominator)

/-- rs1090 bds09.rs: Rust's binary64 PI constant, represented exactly as Rat. -/
def oraclePi : Rat := 884279719003555 / 281474976710656

/-- rs1090 bds09.rs GroundSpeedDecoding: hypot(abs(EW),abs(NS)), with signed
integer components supplied by a separately named standard or oracle view. -/
def velocitySpeed (ew ns : Int) : FloatExpr :=
  .hypot64 (.abs64 (.literal .binary64 ew)) (.abs64 (.literal .binary64 ns))

/-- rs1090 bds09.rs GroundSpeedDecoding: atan2(EW,NS) * (360/(2*PI)),
then add360 iff negative. Parenthesization is part of the tested contract. -/
def velocityTrack (ew ns : Int) : FloatExpr :=
  .addIfNegative64 (.mul .binary64
    (.atan2_64 (.literal .binary64 ew) (.literal .binary64 ns))
    (.div .binary64 (.literal .binary64 360)
      (.mul .binary64 (.literal .binary64 2) (.literal .binary64 oraclePi))))

/-- Sun 2nd ed., table7.2 and equations7.6–7.9: component0 is unavailable;
subtype2 has4kt resolution. This is distinct from the pinned oracle defect. -/
def standardVelocityComponents (word : Nat) : Option (Int × Int) := do
  let subtype := payloadBits word 6 3
  if subtype != 1 && subtype != 2 then none else do
    let ew := payloadBits word 15 10
    let ns := payloadBits word 26 10
    if ew == 0 || ns == 0 then none else
      let factor := if subtype == 2 then 4 else 1
      some (adsbSigned (payloadBits word 14 1) ((ew-1)*factor),
        adsbSigned (payloadBits word 25 1) ((ns-1)*factor))

/-- Sun 2nd ed., table7.1 and §7.1:0 denotes GNSS,1 barometric. -/
def standardVerticalSource (word : Nat) : String :=
  if payloadBits word 36 1 == 0 then "GNSS" else "barometric"

/-- rs1090-derived bds09.rs VerticalRateSource reverses Sun's source labels. -/
def oracleVerticalSource (word : Nat) : String :=
  if payloadBits word 36 1 == 0 then "barometric" else "GNSS"

/-- Sun 2nd ed., §7.2 equation7.4:0 and127 are unavailable; code1 means0ft.
The oracle's different availability is adsbGeoMinusBaro in Spec.ADSB. -/
def standardGeoMinusBaro (word : Nat) : Option Int :=
  let code := payloadBits word 50 7
  if code == 0 || code == 127 then none
  else some (adsbSigned (payloadBits word 49 1) ((code-1)*25))

/-- Sun 2nd ed., §5.5.2: TC20–22 height is unsigned metres, not Q/Gillham
feet. This exact quantity is distinct from the oracle AC12 compatibility view. -/
def standardGNSSHeightMetres (word : Nat) : Option Nat :=
  let tc := payloadBits word 1 5
  if 20 <= tc && tc <= 22 then some (payloadBits word 9 12) else none

/-- rs1090-derived bds06.rs,bds09.rs,bds62.rs: all floating payload fields
reported for ADS-B before resolved CPR coordinates. Subtype4's heading is
computed in binary32 then widened exactly by its serde helper. -/
def oracleADSBFloats (word : Nat) : List NumericField :=
  let tc := payloadBits word 1 5
  let bits := payloadBits word
  if 5 <= tc && tc <= 8 then
    [⟨"groundspeed", (adsbMovement (bits 6 7)).map (.literal .binary64), .null⟩,
     ⟨"track", if bits 13 1 == 0 then none else
       some (scaled .binary64 (bits 14 7) 360 128), .null⟩]
  else if tc == 19 then
    let st := bits 6 3
    if st == 1 || st == 2 then
      let (ew, ns) := adsbOracleVelocityComponents word
      [⟨"groundspeed", some (velocitySpeed ew ns), .null⟩,
       ⟨"track", some (velocityTrack ew ns), .null⟩]
    else if st == 3 || st == 4 then
      [⟨"heading", if bits 14 1 == 0 then none else
        some (scaled (if st == 3 then .binary64 else .binary32) (bits 15 10) 360 1024), .omit⟩]
    else []
  else if tc == 29 then
    let pressure := bits 21 9
    [⟨"barometric_setting", if pressure == 0 then none else
       some (.add .binary32 (.literal .binary32 800)
         (.mul .binary32 (.literal .binary32 (pressure-1)) (.literal .binary32 (4/5)))), .omit⟩,
     ⟨"selected_heading", if bits 30 1 == 0 then none else
       some (scaled .binary32 (bits 31 9) 180 256), .omit⟩]
  else []

/-- rs1090-derived status-gated numeric readers: zero status omits the exact
operand; invalid nonzero unavailable fields are rejected upstream by inference. -/
def statusValue (word status : Nat) (value : FloatExpr) : Option FloatExpr :=
  if payloadBits word status 1 == 0 then none else some value

/-- Sun, 2nd ed. (2021), ch.17 signed EHS fields, also used by the oracle: combine sign and
magnitude as two's complement before scaling. -/
def signedCode (word sign start width : Nat) : Int :=
  let raw := payloadBits word start width
  if payloadBits word sign 1 == 0 then raw else (raw : Int) - (2^width : Nat)

/-- rs1090-derived bds44.rs read_temperature: quarter-degree signed value;
legacy avionics compatibility adds256 when below−80. Arithmetic here is exact
because all possible operands and results are dyadic and small. -/
def oracleMeteoTemperature (word : Nat) : Rat :=
  let signed := signedCode word 24 25 10
  let temperature : Rat := (signed : Rat) / 4
  if temperature < -80 then temperature + 256 else temperature

/-- rs1090-derived bds30/40/44/45/50/60: every floating field on a successfully
selected candidate. Integer-valued fields (including rates and rounded selected
altitudes) remain exact in other semantic projections; no Float expression is
introduced for them. Register65 shares ADS-B fields but has no floating payload.
The candidate decoder, not this presentation function, enforces validity. -/
def oracleCommBFloats (bds word : Nat) : List NumericField :=
  let bits := payloadBits word
  match bds with
  | 0x30 =>
      if bits 29 2 != 2 then [] else
        let range := bits 44 7
        [⟨"threat_range", if range == 0 then none else
          some (.div .binary32
            (.sub .binary32 (.literal .binary32 range) (.literal .binary32 1))
            (.literal .binary32 10)), .null⟩]
  | 0x40 =>
      [⟨"barometric_setting", statusValue word 27
        (.add .binary64 (.mul .binary64 (.literal .binary64 (bits 28 12))
          (.literal .binary64 (1/10))) (.literal .binary64 800)), .omit⟩]
  | 0x44 =>
      [⟨"wind_direction", statusValue word 5 (scaled .binary64 (bits 15 9) 180 256), .null⟩,
       ⟨"temperature", some (.literal .binary64 (oracleMeteoTemperature word)), .null⟩,
       ⟨"humidity", statusValue word 50 (scaled .binary64 (bits 51 6) 100 64), .null⟩]
  | 0x45 =>
      [⟨"static_temperature", statusValue word 16
        (scaled .binary64 (signedCode word 17 18 9) 1 4), .null⟩]
  | 0x50 =>
      [⟨"roll", statusValue word 1
        (scaled .binary64 (signedCode word 2 3 9) 45 256), .null⟩,
       ⟨"track", statusValue word 12
        (.addIfNegative64 (scaled .binary64 (signedCode word 13 14 10) 90 512)), .null⟩,
       ⟨"track_rate", if bits 37 9 == 511 then none else statusValue word 35
        (scaled .binary64 (signedCode word 36 37 9) 8 256), .null⟩]
  | 0x60 =>
      [⟨"heading", statusValue word 1
        (.addIfNegative64 (scaled .binary64 (signedCode word 2 3 10) 90 512)), .omit⟩,
       ⟨"Mach", statusValue word 24 (scaled .binary64 (bits 25 10) (256/125) 512), .omit⟩]
  | _ => []

end Lean1090.Spec.Presentation

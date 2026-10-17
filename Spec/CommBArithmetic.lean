import Spec.CommB

/-! Proof-visible domain of the exact finite binary64 score model.
Every quantity here is rational. The later correctness proof must establish
finite range for the operands, exact pre-round result, and rounded result of
every arithmetic operation, as well as nonzero divisors. The trace follows
rs1090 685dfaa density.rs, penalty.rs and the qnh/Mach field readers. -/
namespace Lean1090.Spec

/-- rs1090 density.rs gaussian: operands, exact results and rounded results
in operation order. Exact pre-round values detect potential overflow. -/
def cbGaussianTrace (value mu sigma : Rat) : List Rat :=
  let m := Binary64.literal mu
  let s := Binary64.literal sigma
  let d := Binary64.sub value m
  let z := Binary64.div d s
  let h := Binary64.mul (-1/2) z
  [value, m, s, value-m, d, d/s, z, (-1/2)*z, h, h*z, Binary64.mul h z]

/-- rs1090 density.rs Laplace: trace only the live branch; scale is positive
for all fitted constants in the pinned model. -/
def cbLaplaceTrace (value median scale : Rat) : List Rat :=
  if scale ≤ 0 then [0] else
    let m := Binary64.literal median
    let b := Binary64.literal scale
    let d := Binary64.sub value m
    [value, m, b, value-m, d, -d.abs, -d.abs/b, Binary64.div (-d.abs) b]

/-- rs1090 density.rs: omit traces of absent fields exactly as the score does. -/
def cbTraceField (value : Option Rat) (trace : Rat → List Rat) : List Rat :=
  match value with | none => [] | some x => trace x

/-- rs1090 density.rs: intermediate trace for the exact fitted distributions;
field order and constants coincide with cbDensityTerms. -/
def cbDensityTrace (register word : Nat) : List Rat :=
  let v := commBValue register word
  match register with
  | 0x40 =>
    cbTraceField ((v "barometric_setting").map fun _ => cbQNH64 word)
      (fun x => cbLaplaceTrace x (10132/10) (54/10)) ++
    cbTraceField (v "selected_mcp") (fun x => cbGaussianTrace x 24688 10844) ++
    cbTraceField (v "selected_fms") (fun x => cbGaussianTrace x 24688 10844)
  | 0x50 =>
    cbTraceField (v "roll") (fun x => cbLaplaceTrace x 0 10) ++
    cbTraceField (v "track_rate") (fun x => cbLaplaceTrace x 0 (70/100)) ++
    cbTraceField (v "TAS") (fun x => cbGaussianTrace x 413 120) ++
    cbTraceField (v "groundspeed") (fun x => cbGaussianTrace x 418 129)
  | 0x60 =>
    cbTraceField (v "IAS") (fun x => cbGaussianTrace x 272 55) ++
    cbTraceField ((v "Mach").map fun _ => cbMach64 word)
      (fun x => cbGaussianTrace x (69/100) (21/100)) ++
    cbTraceField (v "vrate_inertial") (fun x => cbGaussianTrace x (-298) 1669)
  | 0x44 =>
    cbLaplaceTrace (cbTemperature44 word) (-21) (990/100) ++
    cbTraceField (v "wind_speed") (fun x => cbGaussianTrace x 52 29) ++
    cbTraceField (v "pressure") (fun x => cbLaplaceTrace x 393 290)
  | 0x45 =>
    cbTraceField (v "static_temperature") (fun x => cbGaussianTrace x (-142/10) (164/10)) ++
    cbTraceField (v "static_pressure") (fun x => cbLaplaceTrace x 393 290)
  | _ => []

/-- rs1090 bds40/bds60 field readers: non-dyadic QNH/Mach paths. The trace
includes both paths as a harmless superset; no Float operation is used. -/
def cbFieldArithmeticTrace (word : Nat) : List Rat :=
  let q : Rat := payloadBits word 28 12
  let m : Rat := payloadBits word 25 10
  let tenth := Binary64.literal (1/10)
  let machScale := Binary64.literal (256/125)
  let qProduct := Binary64.mul q tenth
  let mProduct := Binary64.mul m machScale
  [q,m,tenth,machScale,q*tenth,qProduct,qProduct+800,cbQNH64 word,
   m*machScale,mProduct,mProduct/512,cbMach64 word]

/-- rs1090 density.rs Acc: trace every exact/rounded addition in order. -/
def cbAccumulationTrace (total : Rat) : List Rat → List Rat
  | [] => [total]
  | score :: scores =>
    let next := Binary64.add total score
    [total,score,total+score,next] ++ cbAccumulationTrace next scores

/-- rs1090 penalty.rs: all intermediate values from the live penalty branches. -/
def cbPenaltyTrace (register word : Nat) : List Rat :=
  let v := commBValue register word
  if register == 0x50 then
    let wind := match v "TAS", v "groundspeed" with
      | some tas, some gs =>
        let d := Binary64.sub tas gs
        let p := Binary64.div d.abs 100
        [tas,gs,tas-gs,d,d.abs,d.abs/100,p,-p,Binary64.sub 0 p]
      | _, _ => [0]
    let p := match v "TAS", v "groundspeed" with
      | some tas, some gs => Binary64.sub 0 (Binary64.div (Binary64.sub tas gs).abs 100)
      | _, _ => 0
    let turn := match v "roll", v "track_rate" with
      | some roll, some rate =>
        if roll.abs > 5 && rate.abs > Binary64.literal (3/10) &&
            decide (roll > 0) != decide (rate > 0)
        then [p,p-2,Binary64.sub p 2] else [p]
      | _, _ => [p]
    wind ++ turn ++ [cbPenalty register word]
  else if register == 0x60 then
    match v "IAS", v "Mach" with
    | some ias, some _ =>
      let mach := cbMach64 word
      if mach > 0 then [ias,mach,ias/mach,Binary64.div ias mach,cbPenalty register word]
      else [0]
    | _, _ => [0]
  else [0]

/-- rs1090 density.rs/penalty.rs: denominator set, including dynamic count
and IAS/Mach only when their division branches execute. -/
def cbScoreDivisors (register word : Nat) : List Rat :=
  let constants : List Rat := [512,100,54/10,10844,10,70/100,120,129,55,21/100,
    1669,990/100,29,290,164/10]
  let constants := constants.map Binary64.literal
  let terms := cbDensityTerms register word
  let count := if terms.isEmpty then [] else [(terms.length : Rat)]
  let ratio := if register == 0x60 && (commBValue register word "IAS").isSome &&
      (commBValue register word "Mach").isSome && cbMach64 word > 0
    then [cbMach64 word] else []
  constants ++ count ++ ratio

/-- rs1090-derived arithmetic-domain obligation: all score intermediates are
finite and every executed divisor nonzero. This is a theorem target, not an
extra acceptance filter and not an assumption hiding rejected messages. -/
def CommBScoreArithmeticFinite (register word : Nat) : Prop :=
  let terms := cbDensityTerms register word
  let total := terms.foldl Binary64.add 0
  let meanTrace := if terms.isEmpty then [0]
    else [total/(terms.length : Rat), cbDensity register word]
  let finalTrace := [cbDensity register word + cbPenalty register word,
    cbCombinedScore register word]
  (∀ x ∈ cbFieldArithmeticTrace word ++ cbDensityTrace register word ++
    cbAccumulationTrace 0 terms ++ meanTrace ++ cbPenaltyTrace register word ++ finalTrace,
      Binary64.inRange x) ∧
  (∀ d ∈ cbScoreDivisors register word, d ≠ 0)

instance (register word : Nat) : Decidable (CommBScoreArithmeticFinite register word) := by
  dsimp only [CommBScoreArithmeticFinite, Binary64.inRange]
  infer_instance

end Lean1090.Spec

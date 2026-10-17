import Spec.CommB

/-! Deterministic Comm-B test inputs made from named fields and encodeBDS.
Output is a reference fixture for differential tests, not a differential-test
result. Every rejected payload is retained. See docs/FUZZING.md. -/

open Lean1090.Spec

namespace CommBFuzz

def registers : List Nat := [0x05,0x10,0x17,0x18,0x19,0x20,0x21,0x30,0x40,0x44,0x45,0x50,0x60,0x65]
def scored : List Nat := [0x40,0x44,0x45,0x50,0x60]

def layout (reg : Nat) : List PayloadColumn :=
  if reg == 0x05 then adsbPositionLayout
  else if reg == 0x65 then adsbOperationPrefix false ++ adsbOperationSuffix false 0
  else (commBLayout reg).getD []

def assign (r : PayloadRecord) (name : String) (code : Nat) : PayloadRecord :=
  {r with fields := r.fields.map fun f => if f.name == name then {f with code} else f}

def assignMany (r : PayloadRecord) (fields : List (String × Nat)) : PayloadRecord :=
  fields.foldl (fun r (name, code) => assign r name code) r

def base (reg : Nat) : PayloadRecord :=
  let r : PayloadRecord := ⟨reg, (layout reg).map fun c => ⟨c.name, 0⟩⟩
  assignMany r (match reg with
    | 0x05 => [("tc",9),("altitude_code",3128)]
    | 0x10 | 0x20 | 0x30 => [("bds",reg)]
    | 0x17 => [("bds20",1)]
    | 0x18 => [("bds20",1),("bds19",1),("bds18",1),("bds17",1)]
    | 0x19 => [("bds65",1)]
    | 0x21 => [("ac_status",1)]
    | 0x40 => [("mcp_valid",1),("selected_mcp",2000),("fms_valid",1),
        ("selected_fms",2000),("qnh_valid",1),("barometric_setting",2132)]
    | 0x44 => [("figure_of_merit",1),("wind_valid",1),("wind_speed",52),
        ("wind_direction",128),("temperature",1964),("pressure_valid",1),("pressure",393)]
    | 0x45 => [("temperature_valid",1),("static_temperature",940),
        ("pressure_valid",1),("static_pressure",393),("height_valid",1),("radio_height",200)]
    | 0x50 => [("roll_valid",1),("track_valid",1),("track",600),
        ("groundspeed_valid",1),("groundspeed",209),("track_rate_valid",1),
        ("tas_valid",1),("TAS",206)]
    | 0x60 => [("heading_valid",1),("heading",600),("ias_valid",1),("IAS",272),
        ("mach_valid",1),("Mach",173),("barometric_rate_valid",1),
        ("vrate_barometric",1015),("inertial_rate_valid",1),("vrate_inertial",1015)]
    | 0x65 => [("tc",31)]
    | _ => [])

def signed (width : Nat) (value : Int) : Nat := (value % (2^width : Nat)).toNat
def qCode (count : Nat) : Nat := count / 16 * 32 + 16 + count % 16

structure Boundary where
  reg : Nat
  name : String
  field : String
  codes : List Nat
  context : List (String × Nat) := []

def boundaries : List Boundary :=
  [⟨0x05,"ac12_50000ft_q","altitude_code",[qCode 2039,qCode 2040,qCode 2041,qCode 2047],[]⟩,
   ⟨0x05,"ac12_50000ft_gillham","altitude_code",
      [49900,50000,50100].filterMap (Altitude.encodeFeetAC12 .gillham100),[]⟩,
   ⟨0x05,"position_tc_inference","tc",[8,9,18,19,20,21,22,23],[]⟩,
   ⟨0x10,"capability_header","bds",[15,16,17],[]⟩,
   ⟨0x10,"capability_reserved","reserved",[0,1,31],[]⟩,
   ⟨0x17,"required_identification","bds20",[0,1],[]⟩,
   ⟨0x17,"required_zero_suffix","zero_tail",[0,1,2^27-1],[]⟩,
   ⟨0x20,"identification_header","bds",[31,32,33],[]⟩,
   ⟨0x21,"airline_status","al_status",[0,1],[]⟩,
   ⟨0x21,"airline_placeholder1","airline_char1",[0,1,32,45,63],[]⟩,
   ⟨0x21,"airline_placeholder2","airline_char2",[0,1,32,45,63],[]⟩,
   ⟨0x30,"ra_header","bds",[47,48,49],[]⟩,
   ⟨0x40,"mcp_rounded50000","selected_mcp",[0,1,3124,3125,3126,3127,3128,3129,3130,3131,3132,4095],[]⟩,
   ⟨0x40,"fms_rounded50000","selected_fms",[0,1,3124,3125,3126,3127,3128,3129,3130,3131,3132,4095],[]⟩,
   ⟨0x40,"pressure_800_1200","barometric_setting",[0,1,3999,4000,4001,4095],[]⟩,
   ⟨0x44,"figure_of_merit_1_2","figure_of_merit",[0,1,2,3,15],[]⟩,
   ⟨0x44,"wind_250","wind_speed",[0,1,249,250,251,511],[]⟩,
   ⟨0x44,"temperature_m80_60_wrap","temperature",
      [0,239,240,241,1023,1024,1025,1263,1264,1265,1727,1728,1729,2047],[]⟩,
   ⟨0x45,"temperature_m80_60","static_temperature",[0,239,240,241,703,704,705,1023],[]⟩,
   ⟨0x45,"missing_temperature_sign","static_temperature",[0,1,511,512,513,1023],[("temperature_valid",0)]⟩,
   ⟨0x50,"roll_45","roll",[-257,-256,-255,255,256,257].map (signed 10),[]⟩,
   ⟨0x50,"groundspeed_700","groundspeed",[0,1,349,350,351,1023],[]⟩,
   ⟨0x50,"tas_80_600","TAS",[0,1,39,40,41,299,300,301,1023],[]⟩,
   ⟨0x50,"rate_sentinel","track_rate",[0,1,510,511,512,513,1022,1023],[]⟩,
   ⟨0x50,"exact_minus3_inclusive","track_rate",[83,84,85],
      [("roll_valid",1),("roll",128),("track_valid",0),("track",0),
       ("groundspeed_valid",0),("groundspeed",0),("track_rate_valid",1),
       ("tas_valid",0),("TAS",0)]⟩,
   ⟨0x60,"ias_500","IAS",[0,1,499,500,501,1023],[]⟩,
   ⟨0x60,"mach_1","Mach",[0,1,249,250,251,1023],[]⟩,
   ⟨0x60,"inertial_rate_6000_sentinels","vrate_inertial",
      [0,1,186,187,188,510,511,512,513,836,837,838,1022,1023],[]⟩,
   ⟨0x60,"barometric_rate_sentinels","vrate_barometric",[0,1,510,511,512,513,1022,1023],[]⟩,
   ⟨0x60,"ias_mach_ratio_250_800","IAS",[124,125,126,399,400,401],[("Mach",125)]⟩,
   ⟨0x65,"operational_status_tc","tc",[30,31],[]⟩]

structure Counts where
  rows : Nat := 0
  hardPass : Nat := 0
  scorePass : Nat := 0
  exactThreshold : Nat := 0
  deriving Repr

abbrev Coverage := Std.HashMap String Counts

def fraction (q : Rat) : String := s!"{q.num}/{q.den}"

def emit (out : IO.FS.Handle) (coverage : IO.Ref Coverage)
    (seed : UInt64) (tag : String) (r : PayloadRecord) : IO Unit := do
  let some schema := bdsAssignmentLayout r
    | throw (IO.userError s!"no independent encoder layout for {tag}")
  unless decide (ValidPayloadFields schema r.fields) do
    throw (IO.userError s!"out-of-width or malformed named assignment: {tag}")
  let word := encodeBDS r
  let hard := bdsWireValid r.kind word
  let terms := cbDensityTerms r.kind word
  let penalty := cbPenalty r.kind word
  let score := cbCombinedScore r.kind word
  let passes := cbScorePasses r.kind word
  let outer := if r.kind == 0x05 then adsbAltitude word else none
  let fields := String.intercalate ";" (r.fields.map fun f => s!"{f.name}:{f.code}")
  let termText := String.intercalate ";" (terms.map fraction)
  let alt := outer.map toString |>.getD "none"
  out.putStrLn s!"{seed},{tag},{r.kind},{word},{hard},{score.num},{score.den},{passes},{alt},{commBEligible 20 outer r.kind word},{commBEligible 20 none r.kind word},{commBEligible 21 outer r.kind word},{fraction penalty},{termText},{fields}"
  coverage.modify fun map =>
    let key := s!"{r.kind}:{tag}"
    let old := map[key]?.getD {}
    map.insert key {
      rows := old.rows+1
      hardPass := old.hardPass + (if hard then 1 else 0)
      scorePass := old.scorePass + (if passes then 1 else 0)
      exactThreshold := old.exactThreshold + (if score == -3 then 1 else 0) }

def next (seed : UInt64) : UInt64 := seed * 6364136223846793005 + 1442695040888963407

-- Scramble all64 state bits before bounded draws. Raw low LCG bits would
-- alternate predictably in support bitmaps instead of varying combinations.
def draw (seed : UInt64) : Nat :=
  let z := (seed ^^^ (seed >>> 30)) * 0xbf58476d1ce4e5b9
  let z := (z ^^^ (z >>> 27)) * 0x94d049bb133111eb
  (z ^^^ (z >>> 31)).toNat

-- Bounds describe code assignments, including signed two's-complement codes.
def randomRanges (reg : Nat) : List (String × Int × Int × Nat) :=
  match reg with
  | 0x05 => [("altitude_code",0,4095,12),("lat_cpr",0,131071,17),("lon_cpr",0,131071,17)]
  | 0x40 => [("selected_mcp",0,3130,12),("selected_fms",0,3130,12),("barometric_setting",0,4000,12)]
  | 0x44 => [("figure_of_merit",1,2,4),("wind_speed",0,250,9),("wind_direction",0,511,9),
      ("temperature",-320,240,11),("pressure",0,2047,11)]
  | 0x45 => [("static_temperature",-320,240,10),("static_pressure",0,2047,11),("radio_height",0,4095,12)]
  | 0x50 => [("roll",-256,256,10),("track",0,2047,11),("groundspeed",0,350,10),
      ("track_rate",0,1023,10),("TAS",40,300,10)]
  | 0x60 => [("heading",0,2047,11),("IAS",0,500,10),("Mach",0,250,10),
      ("vrate_barometric",-511,511,10),("vrate_inertial",-187,187,10)]
  | _ => []

def randomRecord (seed : UInt64) (reg : Nat) (wide : Bool) : PayloadRecord × UInt64 := Id.run do
  let mut r := base reg
  let mut seed := seed
  if wide || (randomRanges reg).isEmpty then
    for column in layout reg do
      -- Keep only the layout selector stable. Header mismatches have their
      -- own retained families; BDS65 has no encoder layout for subtype>1.
      let header := ["bds","tc","subtype","version"].contains column.name
      let fixed := if wide then false else match reg with
        | 0x10 => column.name == "reserved"
        | 0x17 => ["bds20","bds41","bds42","bds43","bds48","bds54","bds55","bds56","zero_tail"].contains column.name
        | 0x18 =>
          let code := 57-column.start
          [0x20,0x19,0x18,0x17].contains code ||
            ![0x30,0x21,0x20,0x1f,0x1e,0x1d,0x1c,0x1b,0x1a,0x19,0x18,0x17,0x10,0x0f,0x0b,0x0a,0x09,0x08,0x07,0x06,0x05].contains code
        | 0x19 => ![0x65,0x62,0x61,0x60,0x5f,0x53,0x52,0x51,0x50,0x45,0x44,0x40].contains (113-column.start)
        | 0x21 => ["ac_status","al_status","airline_char1","airline_char2"].contains column.name
        | 0x65 => ["cc_reserved0","om_reserved"].contains column.name
        | _ => false
      if !header && !fixed then
        seed := next seed
        let code := if !wide && reg == 0x21 then 1+draw seed%26 else draw seed % 2^column.width
        r := assign r column.name code
  else
    for (name, lo, hi, width) in randomRanges reg do
      seed := next seed
      r := assign r name (signed width (lo + (draw seed % (hi-lo+1).toNat : Nat)))
  return (r, seed)

structure Sweep where
  reg : Nat
  field : String
  size : Nat
  context : List (String × Nat) := []

def sweeps : List Sweep :=
  [⟨0x40,"barometric_setting",4096,[]⟩,
   ⟨0x44,"wind_speed",512,[]⟩,
   ⟨0x44,"temperature",2048,[("wind_speed",52),("pressure_valid",0),("pressure",0)]⟩,
   ⟨0x45,"static_temperature",1024,[("pressure_valid",0),("static_pressure",0)]⟩,
   ⟨0x50,"track_rate",1024,[]⟩,
   ⟨0x60,"IAS",1024,[("mach_valid",0),("Mach",0),("inertial_rate_valid",0),("vrate_inertial",0)]⟩]

-- Seeded cross-field contexts keep the varied coordinate inside its hard
-- envelope while sweeping another coordinate across the score threshold.
def contextualSweeps (seed : UInt64) : List Sweep :=
  let a := draw seed
  let b := draw (next seed)
  [⟨0x40,"barometric_setting",4096,
      [("selected_mcp",1200+a%1001),("selected_fms",1200+b%1001)]⟩,
   ⟨0x44,"wind_speed",512,
      [("temperature",signed 11 (-120+(a%81 : Nat))),("pressure",200+b%401)]⟩,
   ⟨0x45,"static_temperature",1024,[("static_pressure",100+a%601)]⟩,
   ⟨0x50,"track_rate",1024,
      [("roll",signed 10 (-50+(a%101 : Nat))),("groundspeed",180+b%61),("TAS",180+a%61)]⟩,
   ⟨0x60,"IAS",1024,
      [("Mach",172+a%2),("vrate_inertial",signed 10 (-20+(b%41 : Nat)))]⟩]

def scoreSweep (out : IO.FS.Handle) (coverage : IO.Ref Coverage) (seed : UInt64)
    (s : Sweep) : IO Unit := do
  let start := assignMany (base s.reg) s.context
  let mut previous : Option (Nat × Rat) := none
  let mut below : Option (Nat × Rat) := none
  let mut above : Option (Nat × Rat) := none
  for code in List.range s.size do
    let r := assign start s.field code
    let word := encodeBDS r
    if bdsWireValid s.reg word then
      let score := cbCombinedScore s.reg word
      if score == -3 then emit out coverage seed s!"score_exact:{s.field}" r
      if score < -3 then
        if below.isNone || (below.map (fun p => decide (score > p.2))).getD false then below := some (code,score)
      else
        if above.isNone || (above.map (fun p => decide (score < p.2))).getD false then above := some (code,score)
      match previous with
      | some (prevCode, prevScore) =>
        if prevCode+1 == code && decide (prevScore ≥ -3) != decide (score ≥ -3) then
          emit out coverage seed s!"score_crossing_before:{s.field}" (assign start s.field prevCode)
          emit out coverage seed s!"score_crossing_after:{s.field}" r
      | none => pure ()
      previous := some (code,score)
    else previous := none
  match below, above with
  | some (b,_), some (a,_) =>
    emit out coverage seed s!"score_nearest_below:{s.field}" (assign start s.field b)
    emit out coverage seed s!"score_nearest_at_or_above:{s.field}" (assign start s.field a)
  | _, _ => throw (IO.userError s!"score sweep did not bracket -3: {s.reg}:{s.field}")

end CommBFuzz

open CommBFuzz

def main (args : List String) : IO UInt32 := do
  let path := args.headD ".cache/commb-generated.csv"
  let count := (args[1]?.bind String.toNat?).getD 1000
  let initialSeed := (args[2]?.bind String.toNat?).getD 0x1090c0
  let seed0 := initialSeed.toUInt64
  let out ← IO.FS.Handle.mk path .write
  let coverage ← IO.mkRef ({} : Coverage)
  -- Fail on misspelled field names rather than silently leaving a base
  -- assignment unchanged. All emitted assignments are width-checked too.
  for b in boundaries do
    unless (layout b.reg).any (fun c => c.name == b.field) do
      throw (IO.userError s!"unknown boundary field {b.reg}:{b.field}")
  for reg in registers do
    for (name,_,_,_) in randomRanges reg do
      unless (layout reg).any (fun c => c.name == name) do
        throw (IO.userError s!"unknown random field {reg}:{name}")
  out.putStrLn "seed,tag,register,word,hard_valid,score_num,score_den,score_pass,outer_altitude,eligible_df20_matching_altitude,eligible_df20_none,eligible_df21,penalty,density_terms,named_fields"
  for reg in registers do
    emit out coverage seed0 "base" (base reg)
    for c in layout reg do
      if !["tc","subtype","version"].contains c.name then
        for code in [0,1,2^c.width-1] do
          emit out coverage seed0 s!"field_extrema:{c.name}" (assign (base reg) c.name code)
      if c.status != 0 then
        let start := base reg
        let fields := start.fields.map fun f =>
          let reset := (layout reg).any fun q =>
            q.name == f.name && (q.status == c.status || q.start == c.status)
          if reset then {f with code := 0} else f
        let cleared := {start with fields}
        emit out coverage seed0 s!"status_absent_zero:{c.name}" cleared
        emit out coverage seed0 s!"status_absent_nonzero:{c.name}" (assign cleared c.name 1)
  for b in boundaries do
    for code in b.codes do
      emit out coverage seed0 s!"bound:{b.name}" (assign (assignMany (base b.reg) b.context) b.field code)
  -- The registration unknown-symbol bound is on a count, not a scalar code.
  for n in [1,2,3] do
    let r := (List.range n).foldl (fun r i => assign r s!"reg_char{i+1}" 63) (base 0x21)
    emit out coverage seed0 "bound:registration_unknown_count" r
  for roll in [-30,-29,-28,28,29,30] do
    for rate in [-11,-10,-9,9,10,11] do
      emit out coverage seed0 "bound:opposite_turn_penalty"
        (assignMany (base 0x50) [("roll",signed 10 roll),("track_rate",signed 10 rate)])
  for s in sweeps do scoreSweep out coverage seed0 s
  for seed in [next seed0, next (next seed0)] do
    for s in contextualSweeps seed do scoreSweep out coverage seed s
  let mut seed := seed0
  for i in List.range count do
    let reg := registers[i % registers.length]?.getD 0x50
    let wide := i % 5 == 0
    let (r, nextSeed) := randomRecord seed reg wide
    seed := nextSeed
    emit out coverage seed (if wide then "random_full_field_domains" else "random_structured") r
  out.flush
  let cov ← IO.FS.Handle.mk (path ++ ".coverage.csv") .write
  cov.putStrLn "register_and_tag,rows,hard_pass,hard_fail,score_pass,score_fail,exact_minus3"
  let mut total := 0
  for (key,c) in (← coverage.get).toList.mergeSort (fun a b => a.1 ≤ b.1) do
    total := total+c.rows
    cov.putStrLn s!"{key},{c.rows},{c.hardPass},{c.rows-c.hardPass},{c.scorePass},{c.rows-c.scorePass},{c.exactThreshold}"
  cov.flush
  IO.eprintln s!"Comm-B encoded fixtures: {total} rows; {count} random assignments; seed {initialSeed}. Coverage: {path}.coverage.csv"
  return 0

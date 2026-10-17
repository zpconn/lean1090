import Spec.CommB

/-! Structured BDS50 corpus, produced through the independent encodeBDS.
Each boundary family is tagged; adaptive sweeps emit both sides of every
observed score-gate crossing. All generated payloads are compared by the
external driver, including rejects, rather than filtering to passing cases. -/
open Lean1090

def makeRecord (roll track gs rate tas : Nat) (mask : Nat := 31) : Spec.PayloadRecord :=
  ⟨0x50,
   [⟨"roll_valid", mask % 2⟩, ⟨"roll", roll % 1024⟩,
    ⟨"track_valid", mask / 2 % 2⟩, ⟨"track", track % 2048⟩,
    ⟨"groundspeed_valid", mask / 4 % 2⟩, ⟨"groundspeed", gs % 1024⟩,
    ⟨"track_rate_valid", mask / 8 % 2⟩, ⟨"track_rate", rate % 1024⟩,
    ⟨"tas_valid", mask / 16 % 2⟩, ⟨"TAS", tas % 1024⟩]⟩

def signedCode (x : Int) : Nat := (x % 1024).toNat

def appendRecord (out : IO.FS.Handle) (tag : String) (r : Spec.PayloadRecord) : IO Unit := do
  if !decide (Spec.ValidBDSFields r) then throw (IO.userError "invalid generated field shape")
  let word := Spec.encodeBDS r
  out.putStrLn s!"{word},{tag}"

def main (args : List String) : IO UInt32 := do
  let path := args.headD ".cache/bds50/generated.csv"
  let out ← IO.FS.Handle.mk path .write
  -- Independent one-step probes around every BDS50 hard bound.
  for roll in [-257,-256,-255,255,256,257] do
    appendRecord out "roll_bound" (makeRecord (signedCode roll) 600 209 0 206)
  for gs in [0,1,349,350,351,1023] do
    appendRecord out "groundspeed_bound" (makeRecord 0 600 gs 0 206)
  for tas in [0,1,39,40,41,299,300,301,1023] do
    appendRecord out "tas_bound" (makeRecord 0 600 209 0 tas)
  for rate in [0,1,510,511,512,513,1022,1023] do
    appendRecord out "rate_sentinel" (makeRecord 0 600 209 rate 206)
  -- Exact score -3 is attainable: roll22.5 degrees, rate2.625 degrees/s,
  -- no other scored fields. Adjacent rate codes straddle the inclusive gate.
  for rate in [83,84,85] do
    appendRecord out (if rate == 84 then "score_exact_threshold" else "score_one_step")
      (makeRecord 128 0 0 rate 0 9)
  -- Status consistency: absent-zero, absent-nonzero, all zero and each field.
  for mask in List.range 32 do
    appendRecord out "status_zero" (makeRecord 0 0 0 0 0 mask)
    appendRecord out "status_nonzero" (makeRecord 1 1 1 1 40 mask)
  -- Penalty activation boundaries: |roll| > 5, |rate| > rounded 0.3,
  -- and both matching and conflicting signs.
  for roll in [-30,-29,-28,28,29,30] do
    for rate in [-11,-10,-9,9,10,11] do
      appendRecord out "penalty_boundary"
        (makeRecord (signedCode roll) 600 209 (signedCode rate) 206)
  -- Deterministic, in-envelope random field assignments, never random raw MB.
  let mut seed : UInt64 := 0x109050
  for _ in List.range 4096 do
    seed := seed * 6364136223846793005 + 1442695040888963407
    let roll := signedCode ((seed.toNat % 513 : Int) - 256)
    seed := seed * 6364136223846793005 + 1442695040888963407
    let track := seed.toNat % 2048
    seed := seed * 6364136223846793005 + 1442695040888963407
    let gs := seed.toNat % 351
    seed := seed * 6364136223846793005 + 1442695040888963407
    let rate := seed.toNat % 1024
    seed := seed * 6364136223846793005 + 1442695040888963407
    let tas := 40 + seed.toNat % 261
    appendRecord out "random_valid_fields" (makeRecord roll track gs rate tas)
  -- Every signed rate code around cross-field contexts. For every transition
  -- in the actual exact binary64 score gate, retain neighboring wire codes.
  -- This targets -3 even where its precise value is not representable by a
  -- payload; metadata distinguishes these from an exact threshold hit.
  for roll in [-128,-29,0,29,128] do
    for gs in [100,150,209,250,300] do
      let mut previous : Option (Nat × Bool) := none
      for index in List.range 1023 do
        let rate := signedCode ((index : Int) - 511)
        let r := makeRecord (signedCode roll) 600 gs rate 206
        let word := Spec.encodeBDS r
        let passes := Spec.cbCombinedScore 0x50 word ≥ -3
        if Spec.cbCombinedScore 0x50 word == -3 then
          appendRecord out "score_exact_threshold" r
        match previous with
        | some (lastRate, lastPasses) =>
          if passes != lastPasses then
            for near in [signedCode ((index : Int)-513), lastRate, rate,
                         signedCode ((index : Int)-510)] do
              appendRecord out "score_threshold_neighbor"
                (makeRecord (signedCode roll) 600 gs near 206)
        | none => pure ()
        previous := some (rate, passes)
  out.flush
  return 0

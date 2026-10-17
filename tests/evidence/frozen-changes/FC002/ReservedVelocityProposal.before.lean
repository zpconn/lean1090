import Spec.Message

/-! Review-only prototype for the unapplied RESERVED-VELOCITY-PROPOSAL.diff.
No frozen source or implementation uses these definitions. -/
set_option maxRecDepth 100000
set_option maxHeartbeats 0
open Lean1090.Spec

namespace ReservedVelocityProposal

def proposedData (word : Nat) : Nat :=
  payloadBits word 14 8 + 256 * payloadBits word 22 8 +
    65536 * payloadBits word 30 6

def independentData (word : Nat) : Nat :=
  Assignment.columnCode word 14 8 + 256 * Assignment.columnCode word 22 8 +
    65536 * Assignment.columnCode word 30 6

open Lean1090.Spec.Semantics Lean1090.Spec.Assignment

def proposedOracleValues (word : Nat) : Values :=
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
        [("reserved_data", some (proposedData word : Rat))] else [])
  else Semantics.adsbStandardValues word


def proposedAssignmentValues (word : Nat) : Semantics.Values :=
  let tc := payloadBits word 1 5
  if (9 <= tc && tc <= 18) || (20 <= tc && tc <= 22) then
    [("NUCp", some (adsbNUCp tc)),
     ("NICb", if tc < 19 then some (payloadBits word 8 1) else none),
     ("altitude_feet", (compatibility12 (payloadBits word 9 12)).map (fun n => (n : Rat)))]
  else if tc == 19 then
    let (ew, ns) := adsbOracleVelocityComponents word
    let subtype := payloadBits word 6 3
    ([("east_velocity", if subtype == 1 || subtype == 2 then some ew else none),
     ("north_velocity", if subtype == 1 || subtype == 2 then some ns else none),
     ("vertical_rate", (adsbVerticalRate word).map (fun n => (n : Rat))),
     ("geo_minus_baro", (adsbGeoMinusBaro word).map (fun n => (n : Rat))),
     ("airspeed", if subtype == 3 || subtype == 4 then
       (adsbAirspeed word).map (fun n => (n : Rat)) else none)] : Semantics.Values) ++
      (if subtype == 0 || subtype ≥ 5 then
        [("reserved_data", some (columnCode word 14 8 +
          256 * columnCode word 22 8 + 65536 * columnCode word 30 6 : Rat))] else [])
  else Assignment.adsbStandardValues word


-- Literal one-bit placements: first wire byte becomes least significant.
example : proposedData 0x98040000000000 = 128 ∧
    payloadBits 0x98040000000000 14 22 = 2097152 := by decide +kernel
example : proposedData 0x9d77ed76f421dc = 3649277 ∧
    payloadBits 0x9d77ed76f421dc 14 22 = 4156343 := by decide +kernel

-- The frozen semantic model currently omits this oracle meaning.
example : ((decode [0x90,0x11,0x22,0x33,0x98,4,0,0,0,0,0,0,0,0]).bind
    (·.decoded.semanticADSB)).map
    (fun p => p.oracleValues.any (fun kv => kv.1 == "reserved_data")) = some false := by
  decide +kernel

-- Check independent bit-fold agreement on all single-bit and all-one fields,
-- for every reserved subtype, in the kernel (not native_decide).
example : ([0,5,6,7].flatMap fun st =>
    (0 :: (2^22-1) :: (List.range 22).map (2^·)).map fun data =>
      19*2^51 + st*2^48 + data*2^21).all
    (fun word => proposedData word == independentData word) = true := by decide +kernel

end ReservedVelocityProposal

def main (args : List String) : IO Unit := do
  let path ← match args with
    | [path] => pure path
    | _ => throw (IO.userError "usage: ReservedVelocityProposal.lean words.txt")
  let text ← IO.FS.readFile path
  IO.println "word,proposed,independent,wire_value"
  for line in text.splitOn "\n" do
    unless line.isEmpty do
      let some word := line.toNat? | throw (IO.userError "invalid input word")
      unless decide (ReservedVelocityProposal.proposedOracleValues word =
          ReservedVelocityProposal.proposedAssignmentValues word) do
        throw (IO.userError s!"proposed independent meaning mismatch: {word}")
      IO.println s!"{word},{ReservedVelocityProposal.proposedData word},{ReservedVelocityProposal.independentData word},{payloadBits word 14 22}"

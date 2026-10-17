import Spec.CommBWitnesses

/-! Checkpoint-1 specification sanity checks. These exercise source examples,
layout coverage and concrete witnesses; they are not the section4 unit or
differential suite, and do not replace the universal capstone proofs.
Run: lake env lean --run scripts/PayloadExamples.lean
-/
open Lean1090.Spec

/-- Every payload bit is assigned once, detecting overlaps and gaps even when
total declared widths happen to sum to56. -/
def coversPayload (layout : List PayloadColumn) : Bool :=
  (List.range 56).all fun i =>
    (layout.filter fun c => c.start ≤ i+1 && i+1 < c.start+c.width).length == 1

/-- All TC/subtype/version combinations with two independently varied tails.
Rejected payloads are counted separately; accepted cases must re-encode fully. -/
def payloadDraftWords : List Nat :=
  (List.range 2048).flatMap fun key =>
    let head := key / 64 * 2^51 + (key / 8 % 8) * 2^48 + (key % 8)*2^13
    [head, head + 0x0700abcde001]

/-- Exercise each source field bit and its all-ones maximum without the
receiver's status consistency or plausibility filters. Discriminants are
assigned explicitly so each input denotes its selected source schema. -/
def commBFieldDraftWords (register : Nat) : List Nat :=
  let patterns := 0 :: (2^56-1) :: (List.range 56).map (2^·)
  if register == 0x05 then
    ([9,10,11,12,13,14,15,16,17,18,20,21,22] : List Nat).flatMap fun tc =>
      patterns.map fun word => tc*2^51 + word%2^51
  else if register == 0x65 then
    ([0,1] : List Nat).flatMap fun subtype =>
      patterns.map fun word => 31*2^51 + subtype*2^48 + word%2^48
  else if register == 0x10 || register == 0x20 || register == 0x30 then
    patterns.map fun word => register*2^48 + word%2^48
  else patterns

private def require (condition : Bool) (message : String) : IO Unit :=
  if condition then pure () else throw (IO.userError message)

def main : IO Unit := do
  let layouts := (List.range 2048).filterMap adsbLayoutOfKind
  require (layouts.all coversPayload) "ADSB layout has an overlap or gap"
  require (commBRegisters.all fun register =>
    coversPayload ((bdsLayout register (bdsWitnessWord register)).getD []))
    "Comm-B layout has an overlap or gap"
  let decoded := payloadDraftWords.filterMap fun word =>
    match decodeADSB word with
    | .error _ => none
    | .ok fields => some (word, fields)
  require (decoded.all fun (word, fields) => encodeADSB fields == word)
    "ADSB source fields fail exact reconstruction"
  require (commBRegisters.all fun r =>
    decodeBDS r (encodeBDS (bdsWitness r)) == some (bdsWitness r))
    "Comm-B witness does not round-trip"
  require (payloadDraftWords.all fun word =>
    match decodeADSBFields word with
    | .error _ => false
    | .ok fields => encodeADSB fields == word)
    "Full ADSB field-code domain rejects or fails reconstruction"
  require (commBRegisters.all fun r =>
    decodeBDSFields r (encodeBDS (bdsWitness r)) == some (bdsWitness r))
    "Full Comm-B field-code witness does not round-trip"
  require (commBRegisters.all fun r => (commBFieldDraftWords r).all fun word =>
    match decodeBDSFields r word with
    | none => false
    | some fields => decide (ValidBDSFields fields) && encodeBDS fields == word)
    "Full Comm-B field-code bit or maximum assignment fails reconstruction"
  require (decodeBDSFields 0x50 (encodeBDS bds50FullDomain) == some bds50FullDomain &&
      decodeBDS 0x50 bds50FullDomainWord == none &&
      commBValue 0x50 bds50FullDomainWord "groundspeed" == some 1000 &&
      commBValue 0x50 bds50FullDomainWord "TAS" == some 60)
    "Representable source speeds were restricted to the oracle plausibility envelope"
  require (cbCallsign 0x202cc371c31de0 == "KLM1017")
    "Sun table16.3 identification example differs"
  require (commBValue 0x40 0xaee57730a80106 "selected_mcp" == some 24000)
    "Sun section17.1 selected altitude example differs"
  require (commBValue 0x44 0x185bd5cf400000 "temperature" == some (-195/4))
    "Sun section18.1 temperature example differs"
  require (adsbCallsign 0x202cc371c32ce0 == "KLM1023")
    "Sun section4.3 ADSB identification example differs"
  require (adsbMovement 41 == some 17 && adsbMovement 25 == some 8 &&
      adsbMovement 124 == some 175 && adsbMovement 125 == none)
    "Surface movement quantization table differs"
  require (adsbOracleVelocityComponents 0x99440994083817 == (-8, -159))
    "Sun section7.3 velocity components differ"
  require (adsbVerticalRate 0x99440994083817 == some (-832))
    "Sun section7.1 vertical rate differs"
  require ((inferCommB 20 none 0xf8000000000000).map Prod.fst == [0x21,0x50,0x60])
    "Pinned oracle TC31 Comm-B offset behavior differs"
  require (standardThreatRange 127 == .greaterThan (251/20) &&
      standardThreatBearing 61 == .unassigned 61)
    "Standard ACAS threat saturation/reserved semantics differ"
  let fullBDSCount := (commBRegisters.map fun r => (commBFieldDraftWords r).length).foldl (·+·) 0
  IO.println s!"Payload draft checks passed: {layouts.length} layouts, {decoded.length}/{payloadDraftWords.length} oracle-accepted patterns, {payloadDraftWords.length} full ADSB patterns, {fullBDSCount} full Comm-B bit/max patterns, {commBRegisters.length} register witnesses, published examples."

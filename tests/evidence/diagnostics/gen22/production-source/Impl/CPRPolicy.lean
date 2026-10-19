import Model.Types
import Impl.CPR
import Impl.Binary64

/-!
# Initial runtime CPR tracking policy

The initial implementation preserves the frozen pure state algorithms.
Runtime imports contain only Model and Impl; Proofs/ establishes refinement.

Source: pinned rs1090 commit685dfaa, crates/rs1090/src/decode/cpr.rs,
`decode_position`, `decode_positions`, `update_global_reference`,
`find_nearest_airport`, and AircraftState. This file specifies application
policy, not an ICAO encoding rule. The explicit geography input is the tested
Float boundary: distance values must be the finite binary64 results of the
source haversine formula. Arithmetic around those inputs rounds with Binary64.
No geographic accuracy claim is made about that Float boundary.
-/

namespace Lean1090.Impl.CPR.Policy
open Lean1090.Spec.CPR Lean1090.Spec.CPR.Policy

/-- rs1090 f64 `<` at the distance policy boundary; NaN never passes. -/
def distanceLT (distance : Distance) (threshold : Rat) : Bool :=
  match distance with
  | .finite km => km < threshold
  | .negativeInfinity => true
  | _ => false

/-- rs1090 f64 `>` at the distance policy boundary; NaN never passes. -/
def distanceGT (distance : Distance) (threshold : Rat) : Bool :=
  match distance with
  | .finite km => km > threshold
  | .positiveInfinity => true
  | _ => false

/-- rs1090 cpr.rs distance/time speed: positive finite hours are required
by the caller's guard; the nonfinite numerator cases preserve IEEE behavior. -/
def speedGT (distance : Distance) (hours threshold : Rat) : Bool :=
  match distance with
  | .finite km => Binary64.div km hours > threshold
  | .positiveInfinity => true
  | _ => false

/-- rs1090 cpr.rs `aircraft.entry(...).or_insert`: initial timestamp is
the first incoming timestamp, also used for both empty parity slots. -/
def initial (timestamp : Rat) : AircraftState :=
  ⟨timestamp, none, none, none, [], [], 0, timestamp, none, timestamp, none⟩

/-- rs1090 cpr.rs BTreeSet insert: deterministic sorted unique evidence. -/
def insertCode (code : Nat) (codes : List Nat) : List Nat :=
  if codes.contains code then codes else (code :: codes).mergeSort (· ≤ ·)

/-- rs1090 cpr.rs `stable_supported_bds`: capability filtering activates at3. -/
def stableSupported (state : AircraftState) : Option (List Nat) :=
  if state.bds17Count ≥ 3 then some state.supportedBDS else none

/-- rs1090 cpr.rs `update_bds17`: union reported true bits and saturate u8
counter; supported codes are restricted to the source's eleven named fields. -/
def updateBDS17 (state : AircraftState) (reported : List Nat) : AircraftState :=
  let permitted := [0x05, 0x06, 0x08, 0x09, 0x20, 0x21, 0x40, 0x44, 0x45, 0x50, 0x60]
  let supported := reported.foldl
    (fun codes code => if permitted.contains code then insertCode code codes else codes)
    state.supportedBDS
  { state with supportedBDS := supported, bds17Count := min 255 (state.bds17Count + 1) }

/-- rs1090 cpr.rs `is_near_airport`: strict10-km threshold, all airports. -/
def nearAirport (geo : Geography) (p : Position) : Bool :=
  geo.airports.any (fun airport => distanceLT (geo.distanceKm p airport.position) 10)

/-- rs1090 cpr.rs `find_nearest_airport`: strict10-km threshold; preserve
the first source entry on a distance tie, matching Iterator.min_by. -/
def nearestAirport (geo : Geography) (p : Position) : Option String :=
  let best := geo.airports.foldl (fun best airport =>
    let distance := geo.distanceKm p airport.position
    if distanceLT distance 10 then
      match best with
      | none => some (distance, airport.icao)
      | some (oldDistance, _) =>
        let nearer : Bool := match distance, oldDistance with
          | .finite a, .finite b => a < b
          | .negativeInfinity, .finite _ => true
          | _, _ => false
        if nearer then some (distance, airport.icao) else best
    else best) (none : Option (Distance × String))
  best.map Prod.snd

/-- rs1090 cpr.rs source execution: reject excessive speed for gaps<1800s,
then any jump>500km for gaps<30s. The jump test really applies to global
results too, despite the nearby source comment describing reference-only. -/
def validMotion (geo : Geography) (state : AircraftState) (timestamp : Rat)
    (candidate : Position) : Bool :=
  match state.position with
  | none => true
  | some previous =>
    let distance := geo.distanceKm candidate previous
    let dt := absQ (Binary64.sub timestamp state.timestamp)
    let hours := Binary64.div dt 3600
    let tooFast := dt < 1800 && hours > 0 && speedGT distance hours 1200
    let tooFar := distanceGT distance 500 && dt < 30
    !tooFast && !tooFar

/-- rs1090 cpr.rs `decode_position`, BDS05 branch: pair before local fallback,
strict30/180s windows, cross-parity out-of-order rejection, motion validation,
and parity-slot replacement even when the position attempt failed. -/
def stepAirborne (geo : Geography) (updateReference : UpdateReference)
    (state : AircraftState) (reference : Option Position)
    (timestamp : Rat) (code : Encoded) (altitude : Option Int)
    (metadata : AirborneMetadata := {}) : StepResult :=
  let previousTimestamp := if code.odd then state.evenTimestamp else state.oddTimestamp
  let previousMessage := if code.odd then state.evenMessage else state.oddMessage
  let gap := Binary64.sub timestamp previousTimestamp
  if gap < 0 then ⟨state, reference, none, true⟩ else
  let global := if absQ gap < 30 then
    previousMessage.bind (fun old => if code.odd then geo.globalPosition old code true
      else geo.globalPosition code old false)
    else none
  let candidate := if global.isNone && Binary64.sub timestamp state.timestamp < 180 then
      state.position.bind (fun p => geo.localPosition .airborne code p)
    else global
  let accepted := candidate.filter (validMotion geo state timestamp)
  let (state, reference) := match accepted with
    | none => (state, reference)
    | some p =>
      ({ state with
          timestamp := timestamp
          position := some p
          lastAltitude := altitude
          airport := none
          seenBDS := insertCode 0x05 state.seenBDS },
        if updateReference ⟨code, altitude, metadata, p⟩ then some p else reference)
  let state := if code.odd then
      { state with oddTimestamp := timestamp, oddMessage := some code }
    else { state with evenTimestamp := timestamp, evenMessage := some code }
  ⟨state, reference, accepted, false⟩

/-- rs1090 cpr.rs `decode_position`, BDS06 branch: own previous position
first with strict1-km check; global reference next. First position requires
an airport within10km; existing positions bypass that airport condition.
There is no timestamp-age, speed, or out-of-order check in this branch. -/
def stepSurface (geo : Geography) (state : AircraftState)
    (reference : Option Position) (timestamp : Rat) (code : Encoded) : StepResult :=
  let localResult := state.position.bind (fun p =>
    (geo.localPosition .surface code p).filter (fun q => distanceLT (geo.distanceKm p q) 1))
  let candidate := if localResult.isSome then localResult else reference.bind (fun p =>
    (geo.localPosition .surface code p).filter (fun q => state.position.isSome || nearAirport geo q))
  match candidate with
  | none => ⟨state, reference, none, false⟩
  | some p =>
    let airport := if state.airport.isSome then state.airport else nearestAirport geo p
    let state := { state with
      timestamp := timestamp
      position := some p
      lastAltitude := none
      airport := airport
      seenBDS := insertCode 0x06 state.seenBDS }
    ⟨state, reference, some p, false⟩

/-- rs1090 cpr.rs `decode_position`, remaining ME variants: evidence codes. -/
def otherCode : OtherMessage → Option Nat
  | .identification => some 0x08
  | .velocity => some 0x09
  | .emergency => some 0x61
  | .targetState => some 0x62
  | .operationalStatus => some 0x65
  | .reserved => none

/-- rs1090 cpr.rs `decode_position`: complete per-aircraft transition. -/
def step (geo : Geography) (updateReference : UpdateReference)
    (state : AircraftState) (reference : Option Position)
    (timestamp : Rat) (message : Message) : StepResult :=
  match message with
  | .airborne code altitude metadata =>
    stepAirborne geo updateReference state reference timestamp code altitude metadata
  | .surface code => stepSurface geo state reference timestamp code
  | .other kind =>
    let state := match otherCode kind with
      | none => state
      | some code => { state with seenBDS := insertCode code state.seenBDS }
    ⟨state, reference, none, false⟩

/-- rs1090 cpr.rs `update_global_reference`: surface/missing altitude sorts
before any reported airborne altitude; equal keys preserve earlier address. -/
def lowerAltitude (a b : Option Int) : Bool :=
  match a, b with
  | none, some _ => true
  | some x, some y => x < y
  | _, _ => false

/-- rs1090 cpr.rs `update_global_reference`: scan aircraft in BTreeMap
address order, retain those active within strictly300s (negative age qualifies),
then choose the lowest altitude, preferring missing altitude. -/
def updateGlobalReference (aircraft : List (Nat × AircraftState))
    (reference : Option Position) (timestamp : Rat) : Option Position × Bool :=
  let ordered := aircraft.mergeSort (fun a b => a.1 ≤ b.1)
  let best := ordered.foldl (fun best (_, state) =>
    if Binary64.sub timestamp state.timestamp < 300 then
      match state.position with
      | none => best
      | some p => match best with
        | none => some (state.lastAltitude, p)
        | some (altitude, _) =>
          if lowerAltitude state.lastAltitude altitude then some (state.lastAltitude, p) else best
    else best) (none : Option (Option Int × Position))
  match best with
  | none => (reference, false)
  | some (_, p) => (some p, true)

/-- rs1090 cpr.rs address map insertion: one state per address. -/
def streamStep (geo : Geography) (updateReference : UpdateReference)
    (stream : StreamState) (report : TimedReport) : StreamState × Option Position :=
  let old := (stream.aircraft.find? (fun entry => entry.1 == report.address)).map Prod.snd
  let result := step geo updateReference (old.getD (initial report.timestamp))
    stream.reference report.timestamp report.message
  let remaining := stream.aircraft.filter (fun entry => entry.1 != report.address)
  (⟨(report.address, result.state) :: remaining, result.reference⟩, result.resolved)

/-- rs1090 cpr.rs `decode_positions`: ordered fold, no automatic invocation
of the separate `update_global_reference` utility. -/
def decodePositions (geo : Geography) (updateReference : UpdateReference)
    (reference : Option Position) (reports : List TimedReport) :
    StreamState × List (Option Position) :=
  let (state, reversed) := reports.foldl (fun (state, results) report =>
    let (state, result) := streamStep geo updateReference state report
    (state, result :: results)) (⟨[], reference⟩, [])
  (state, reversed.reverse)


end Lean1090.Impl.CPR.Policy

namespace Lean1090.Impl

/-- Complete pure runtime stream transition, including output positions. -/
def decodePositions := CPR.Policy.decodePositions

end Lean1090.Impl

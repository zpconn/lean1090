import Lean
import Spec

/-!
Transitive environment audit of hypothesis domains and the independent
encoder-side assigned result used by the message round-trip conclusion.

Run with `lake env lean scripts/CheckHypotheses.lean`.  This inspects elaborated
constant types and bodies, including opaque bodies and theorem proofs.  It does
not rely on source spelling, reducibility settings, or a source-text search.
Every traversed edge is a constant occurrence in the actual Lean environment.
Shared arithmetic and encoder formulas are permitted; decoder entry points and
decoder-only helpers are not.  A finite traversal budget fails closed.
-/

open Lean Elab Command Meta Term

namespace HypothesisAudit

/-- All required hypothesis predicates and the independent round-trip conclusion constructor. -/
def roots : List Name :=
  [``Lean1090.Spec.Valid,
   ``Lean1090.Spec.ValidADSB,
   ``Lean1090.Spec.ValidADSBFields,
   ``Lean1090.Spec.ValidBDS,
   ``Lean1090.Spec.ValidBDSFields,
   ``Lean1090.Spec.CPR.LocalAdmissible,
   ``Lean1090.Spec.CPR.GlobalAdmissible,
   ``Lean1090.Spec.assigned]

/-- Decoder-only helpers whose names do not start with `decode`.
The `decode*` rule additionally covers future Spec decoder entry points. -/
def decoderHelpers : List Name :=
  [``Lean1090.Spec.readACAS,
   ``Lean1090.Spec.readSurveillance,
   ``Lean1090.Spec.frameADSB,
   ``Lean1090.Spec.frameAltitude,
   ``Lean1090.Spec.frameOracleAltitude,
   ``Lean1090.Spec.frameIdentity,
   ``Lean1090.Spec.frameAddress,
   ``Lean1090.Spec.adsbAltitude,
   ``Lean1090.Spec.cbThreat,
   ``Lean1090.Spec.cbStandardThreat,
   ``Lean1090.Spec.Semantics.adsb,
   ``Lean1090.Spec.Semantics.commB,
   ``Lean1090.Spec.Semantics.adsbStandardValues,
   ``Lean1090.Spec.Semantics.adsbOracleValues,
   ``Lean1090.Spec.frameCommB,
   ``Lean1090.Spec.report,
   ``Lean1090.Spec.inferCommB,
   ``Lean1090.Spec.inferCommBCore,
   ``Lean1090.Spec.CPR.localCoordinate,
   ``Lean1090.Spec.CPR.localLatitude,
   ``Lean1090.Spec.CPR.globalLatitudes,
   ``Lean1090.Spec.CPR.SameDecodedZone,
   ``Lean1090.Spec.Altitude.oracleAC12,
   ``Lean1090.Spec.Altitude.oracleAC13]

def decoderForbidden (name : Name) : Bool :=
  decoderHelpers.any (·.isPrefixOf name) ||
    ((`Lean1090.Spec).isPrefixOf name &&
      name.anyS (fun part => part.startsWith "decode" && part != "decoded"))

/-- Inspect both a declaration's type and its body, even if opaque. -/
def dependencies (info : ConstantInfo) : Array Name :=
  info.type.getUsedConstants ++
    match info.value? (allowOpaque := true) with
    | some body => body.getUsedConstants
    | none => #[]

/-- Depth-first graph search with a visited set.  Paths retain every edge for
an actionable rejection message. Exhausting the budget is an error, not PASS. -/
def dependencyPath (env : Environment) (forbidden : Name → Bool)
    (fuel : Nat) (pending : List (Name × List Name)) (seen : NameSet) :
    Except String (Option (List Name)) :=
  match fuel, pending with
  | _, [] => .ok none
  | 0, _ => .error "dependency traversal budget exhausted"
  | fuel + 1, (name, path) :: rest =>
    if forbidden name then .ok (some path.reverse)
    else if seen.contains name then dependencyPath env forbidden fuel rest seen
    else match env.find? name with
      | none => .error s!"missing environment declaration: {name}"
      | some info =>
        let next := (dependencies info).toList.map fun child => (child, child :: path)
        dependencyPath env forbidden fuel (next ++ rest) (seen.insert name)

def findPath (env : Environment) (root : Name) (forbidden : Name → Bool) :
    Except String (Option (List Name)) :=
  dependencyPath env forbidden 1000000 [(root, [root])] {}

def renderPath (path : List Name) : String :=
  String.intercalate " → " (path.map toString)

/-- Kernel-checked definitional identity, not merely the presence of a named
division constant somewhere in the reference's dependency graph. -/
private theorem polynomial_reference_identity (width word : Nat) :
    Lean1090.Spec.Parity.polynomialRemainder width word =
      (Lean1090.Spec.Parity.polynomial width word).modByMonic
        Lean1090.Spec.Parity.generatorPolynomial := rfl

/-- Deliberately bad indirect definitions exercise body traversal. -/
def bodyTrapHelper (bytes : List UInt8) : Prop := Lean1090.Spec.decode bytes = none
def bodyTrap (bytes : List UInt8) : Prop := bodyTrapHelper bytes

/-- The former assigned definition must be rejected, even through a wrapper. -/
def assignmentTrapHelper (f : Lean1090.Spec.Frame) : Lean1090.Spec.Message :=
  ⟨f, Lean1090.Spec.report f⟩
def assignmentTrap (f : Lean1090.Spec.Frame) : Lean1090.Spec.Message :=
  assignmentTrapHelper f

/-- A decoder dependency occurring only in the declaration type must also be
detected. The implementation body itself is merely the identity function. -/
theorem typeTrapHelper : (Lean1090.Spec.decode [] = none) → (Lean1090.Spec.decode [] = none) :=
  fun h => h
theorem typeTrap : (Lean1090.Spec.decode [] = none) → (Lean1090.Spec.decode [] = none) :=
  typeTrapHelper

run_elab do
  let env ← getEnv
  for trap in [``bodyTrap, ``typeTrap] do
    match findPath env trap decoderForbidden with
    | .ok (some path) =>
      unless path.getLast? == some ``Lean1090.Spec.decode do
        throwError "unexpected self-test rejection path: {renderPath path}"
    | .ok none => throwError "hypothesis-audit self-test missed {trap}"
    | .error reason => throwError "hypothesis-audit self-test failed: {reason}"
  match findPath env ``assignmentTrap decoderForbidden with
  | .ok (some path) =>
    unless path.getLast? == some ``Lean1090.Spec.report do
      throwError "unexpected assignment self-test rejection path: {renderPath path}"
  | .ok none => throwError "hypothesis-audit self-test missed old assigned/report dependency"
  | .error reason => throwError "assignment-audit self-test failed: {reason}"
  logInfo "Hypothesis audit self-tests: indirect body/type and assigned/report dependencies rejected."

  let mut failures : List String := []
  for root in roots do
    match findPath env root decoderForbidden with
    | .ok none =>
      if root == ``Lean1090.Spec.assigned then
        logInfo m!"Independent assignment constructor: {root}"
      else logInfo m!"Independent hypothesis domain: {root}"
    | .ok (some path) => failures := failures ++ [renderPath path]
    | .error reason => failures := failures ++ [s!"{root}: {reason}"]

  -- This is an environment/type check of the independent CRC specification.
  -- It requires Mathlib's real polynomial division constant and GF(2) type.
  let remainder ← getConstInfo ``Lean1090.Spec.Parity.polynomialRemainder
  let expected ← elabType (← `(Nat → Nat → Polynomial (ZMod 2)))
  unless ← isDefEq remainder.type expected do
    throwError "Parity.polynomialRemainder does not have type Nat → Nat → Polynomial (ZMod 2)"
  let some body := remainder.value? | throwError "polynomialRemainder has no inspectable body"
  unless body.getUsedConstants.contains ``Polynomial.modByMonic do
    throwError "Parity.polynomialRemainder does not invoke Mathlib Polynomial.modByMonic"
  let recurrence := fun name =>
    name == ``Lean1090.Spec.Parity.step || name == ``Lean1090.Spec.Parity.syndrome ||
      name == ``Lean1090.Spec.Parity.checksum
  match findPath env ``Lean1090.Spec.Parity.polynomialRemainder recurrence with
  | .ok none => logInfo "Parity reference: Mathlib Polynomial.modByMonic over ZMod 2; no CRC recurrence dependency."
  | .ok (some path) => throwError "polynomial reference depends on recurrence: {renderPath path}"
  | .error reason => throwError "polynomial reference audit failed: {reason}"

  unless failures.isEmpty do
    throwError "Circular hypothesis dependencies:\n{String.intercalate "\n" failures}"
  logInfo "Hypothesis dependency audit: all seven required predicates and assigned are independent of decoder entry points/helpers."

end HypothesisAudit

import Lean
import Spec

/-! Review-only dependency export. No decoder/proof/gate dependencies. -/
open Lean Elab Command

namespace ReviewDependencies

def roots : List Name :=
  [``Lean1090.Spec.Valid, ``Lean1090.Spec.ValidADSB,
   ``Lean1090.Spec.ValidADSBFields, ``Lean1090.Spec.ValidBDS,
   ``Lean1090.Spec.ValidBDSFields, ``Lean1090.Spec.CPR.LocalAdmissible,
   ``Lean1090.Spec.CPR.GlobalAdmissible, ``Lean1090.Spec.CPR.WithinResolution,
   ``Lean1090.Spec.assigned, ``Lean1090.Spec.Parity.polynomial,
   ``Lean1090.Spec.Parity.polynomialRemainder, ``Lean1090.Spec.CPR.nlFormula,
   ``Lean1090.Spec.CPR.CertifiesTransition,
   ``Lean1090.Spec.CPR.AvoidsDecodableLatitudes,
   ``Lean1090.Spec.Altitude.Representable25,
   ``Lean1090.Spec.Altitude.RepresentableGillham,
   ``Lean1090.Spec.Altitude.validGillham]

def dependencies (info : ConstantInfo) : Array Name :=
  info.type.getUsedConstants ++
    match info.value? (allowOpaque := true) with
    | some body => body.getUsedConstants
    | none => #[]

/-- Supplementary library semantics copied for the mathematical review. The
entire standard library is a documented boundary, not recursively duplicated. -/
def libraryRoots : List Name :=
  [``Polynomial.modByMonic, ``Polynomial.divModByMonicAux,
   ``Polynomial.div_wf_lemma, ``Polynomial.monomial, ``ZMod,
   ``Real.arccos, ``Real.arcsin, ``Real.pi, ``Real.cos, ``Real.sqrt,
   ``Rat.floor, ``Int.floor]

def moduleName (env : Environment) (name : Name) : Name :=
  match env.getModuleIdxFor? name with
  | some idx => env.header.moduleNames[idx.toNat]?.getD .anonymous
  | none => .anonymous

def projectLocal (env : Environment) (name : Name) : Bool :=
  [`Spec, `Model].any (·.isPrefixOf (moduleName env name))

def closure (env : Environment) (fuel : Nat) (pending : List Name)
    (seen : NameSet) (localNames externalNames : Array Name) :
    Except String (Array Name × Array Name) :=
  match fuel, pending with
  | _, [] => .ok (localNames, externalNames)
  | 0, _ => .error "dependency traversal exhausted"
  | fuel + 1, name :: rest =>
    if seen.contains name then closure env fuel rest seen localNames externalNames
    else if !projectLocal env name then
      closure env fuel rest (seen.insert name) localNames (externalNames.push name)
    else match env.find? name with
      | none => .error s!"missing declaration {name}"
      | some info =>
        closure env fuel ((dependencies info).toList ++ rest) (seen.insert name)
          (localNames.push name) externalNames

def rangeJSON (range : DeclarationRange) : Json := Json.mkObj
  [("line", toJson range.pos.line), ("column", toJson range.pos.column),
   ("endLine", toJson range.endPos.line), ("endColumn", toJson range.endPos.column)]

run_elab do
  let env ← getEnv
  let .ok (localNames, externalNames) := closure env 1000000 roots {} #[] #[]
    | throwError "dependency traversal failed"
  let mut entries := #[]
  for name in localNames ++ externalNames ++ libraryRoots.toArray do
    let range ← findDeclarationRanges? name
    let projection ← getProjectionFnInfo? name
    let mut parent := name.getPrefix
    let mut sourceParent := Json.null
    if range.isNone && projectLocal env name then
      for _ in List.range 64 do
        if sourceParent == Json.null && !parent.isAnonymous then
          if let some parentRange ← findDeclarationRanges? parent then
            sourceParent := Json.mkObj [("name", toJson parent.toString),
              ("module", toJson (moduleName env parent).toString),
              ("projectLocal", toJson true), ("range", rangeJSON parentRange.range)]
          else parent := parent.getPrefix
      if sourceParent == Json.null then
        throwError "No authored source parent for {name}"
    let some info := env.find? name | throwError "missing declaration {name}"
    entries := entries.push (Json.mkObj
      [("name", toJson name.toString), ("module", toJson (moduleName env name).toString),
       ("projectLocal", toJson (projectLocal env name)),
       ("range", range.map (rangeJSON ·.range) |>.getD Json.null),
       ("sourceParent", sourceParent),
       ("dependencies", toJson ((dependencies info).map toString)),
       ("projection", toJson projection.isSome)])
  IO.FS.writeFile ".cache/review-dependencies.json"
    (Json.mkObj [("roots", toJson (roots.map toString)),
      ("libraryRoots", toJson (libraryRoots.map toString)),
      ("declarations", Json.arr entries)]).pretty
  logInfo m!"Review dependency export: {localNames.size} project declarations; {externalNames.size} library boundary declarations."

end ReviewDependencies

import Model.Types
import Impl.Bits

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl
open Lean1090.Spec

-- Initial algorithm: Spec/Frame.lean:15.
/-- Annex 10 IV (4th ed.), §§3.1.2.8.2–3: unpack named ACAS fields. -/
def readACAS (width word : Nat) : ACASFields :=
  ⟨field width 5 1 word, field width 6 1 word, field width 7 1 word,
   field width 8 3 word, field width 11 2 word, field width 13 4 word,
   field width 17 2 word, field width 19 13 word⟩

-- Initial algorithm: Spec/Frame.lean:21.
/-- Annex 10 IV (4th ed.), §§3.1.2.6.5–8: unpack surveillance fields. -/
def readSurveillance (width word : Nat) : SurveillanceFields :=
  ⟨field width 5 3 word, field width 8 5 word,
   field width 13 6 word, field width 19 13 word⟩

-- Initial algorithm: Spec/Frame.lean:26.
/-- Annex 10 IV (4th ed.), cited layouts on FrameBody: parse one complete
frame. This layer decodes wire fields, including reserved codes; the semantic
decoder checks payload validity and applies the separately identified policies. -/
def decodeFrame (bytes : List UInt8) : Option Frame := do
  let first ← bytes.head?
  let df := first.toNat / 8
  let count := frameBytes df
  if bytes.length != count then none else do
    let width := count * 8
    let word := bytesValue bytes
    let parity := field width (width - 24) 24 word
    let body : FrameBody ← match df with
      | 0 => some (.shortACAS (readACAS width word))
      | 4 => some (.surveillance false (readSurveillance width word))
      | 5 => some (.surveillance true (readSurveillance width word))
      | 11 => some (.allCall (field width 5 3 word) (field width 8 24 word))
      | 16 => some (.longACAS (readACAS width word) (field width 32 56 word))
      | 17 => some (.extended false (field width 5 3 word)
          (field width 8 24 word) (field width 32 56 word))
      | 18 => some (.extended true (field width 5 3 word)
          (field width 8 24 word) (field width 32 56 word))
      | 19 => some (.military (field width 5 3 word) (field width 8 80 word))
      | 20 => some (.commB false (readSurveillance width word) (field width 32 56 word))
      | 21 => some (.commB true (readSurveillance width word) (field width 32 56 word))
      | n =>
        if 24 ≤ n then
          some (.commD (field width 2 1 word) (field width 3 1 word)
            (field width 4 4 word) (field width 8 80 word))
        else none
    some ⟨body, parity⟩

-- Initial algorithm: Spec/Frame.lean:57.
/-- Annex 10 IV (4th ed.), §§3.1.2.8.2–3: encoder's ACAS field sequence. -/
def acasParts (f : ACASFields) : List (Nat × Nat) :=
  [(1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat),
   (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat)]

-- Initial algorithm: Spec/Frame.lean:62.
/-- Annex 10 IV (4th ed.), §§3.1.2.6.5–8: encoder's surveillance sequence. -/
def surveillanceParts (f : SurveillanceFields) : List (Nat × Nat) :=
  [(3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat)]

-- Initial algorithm: Spec/Frame.lean:66.
/-- Annex 10 IV (4th ed.), layouts cited on FrameBody: construct fields
in transmission order, independently of the extraction decoder. -/
def frameParts : FrameBody → List (Nat × Nat)
  | .shortACAS f => (5, 0) :: acasParts f
  | .surveillance id f => (5, if id then 5 else 4) :: surveillanceParts f
  | .allCall ca aa => [(5, 11), (3, ca.toNat), (24, aa.toNat)]
  | .longACAS f mv => (5, 16) :: acasParts f ++ [(56, mv.toNat)]
  | .extended supp cf aa me =>
      [(5, if supp then 18 else 17), (3, cf.toNat), (24, aa.toNat), (56, me.toNat)]
  | .military af bits => [(5, 19), (3, af.toNat), (80, bits.toNat)]
  | .commB id f mb => (5, if id then 21 else 20) :: surveillanceParts f ++ [(56, mb.toNat)]
  | .commD spare ke nd md =>
      [(2, 3), (1, spare.toNat), (1, ke.toNat), (4, nd.toNat), (80, md.toNat)]

-- Initial algorithm: Spec/Frame.lean:80.
/-- Annex 10 IV (4th ed.), §3.1.2.3.1.2: short frames have 32 information bits. -/
def informationBits : FrameBody → Nat
  | .shortACAS _ | .surveillance _ _ | .allCall _ _ => 32
  | _ => 88

-- Initial algorithm: Spec/Frame.lean:92.
/-- Annex 10 IV (4th ed.), §3.1.2.6.7.1: exact Mode A identity digits.
Returned value is the four-digit octal code as a Nat, not decimal text. -/
def identityCode (code : BitVec 13) : Nat :=
  let bit := fun n => (code.toNat >>> n) &&& 1
  let a := bit 11 + 2 * bit 9 + 4 * bit 7
  let b := bit 5 + 2 * bit 3 + 4 * bit 1
  let c := bit 12 + 2 * bit 10 + 4 * bit 8
  let d := bit 4 + 2 * bit 2 + 4 * bit 0
  512 * a + 64 * b + 8 * c + d

end Lean1090.Impl

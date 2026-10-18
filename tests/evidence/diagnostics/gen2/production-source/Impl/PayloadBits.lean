import Model.Types

/-!
Initial complete runtime path, implementing the frozen pure algorithms.
Only shared Model data and runtime modules are imported. Source locations below
identify the reference algorithms used for this initial implementation; they
are not runtime calls or a generation step. Future changes must preserve the
all-input refinement theorem and include every exact semantic projection.
-/

namespace Lean1090.Impl
open Lean1090.Spec

-- Initial algorithm: Spec/PayloadBits.lean:7.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: extract a field at a one-based payload bit position. -/
def payloadBits (word start width : Nat) : Nat :=
  word / 2 ^ (56 - (start - 1 + width)) % 2 ^ width

-- Initial algorithm: Spec/PayloadBits.lean:31.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: decode named fields independently by position. -/
def decodePayloadFields (layout : List PayloadColumn) (word : Nat) : List PayloadField :=
  layout.map fun c => ⟨c.name, payloadBits word c.start c.width⟩

-- Initial algorithm: Spec/PayloadBits.lean:41.
/-- Sun, 2nd ed. (2021), ch.17, signed EHS fields: integer interpretation before scaling. -/
def payloadInteger (coding : PayloadCoding) (width code : Nat) : Int :=
  if coding = .twosComplement ∧ code ≥ 2 ^ (width - 1) then
    (code : Int) - (2 ^ width : Nat) else code

-- Initial algorithm: Spec/PayloadBits.lean:46.
/-- Sun chs.6–8,16–18 tables: exact field interpretation, with absent status
represented by `none`; nonlinear fields have dedicated projections. -/
def payloadValue (column : PayloadColumn) (word : Nat) : Option Rat :=
  if column.status != 0 && payloadBits word column.status 1 == 0 then none
  else some ((payloadInteger column.coding column.width
    (payloadBits word column.start column.width) : Rat) * column.scale + column.offset)

end Lean1090.Impl

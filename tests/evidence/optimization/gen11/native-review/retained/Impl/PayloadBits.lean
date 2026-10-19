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

/-- Extract a bounded field from one machine word. Callers establish that the
shift and width are below 64 and the requested field fits in this word. -/
@[inline] def payloadWordBits (word : UInt64) (shift width : Nat) : Nat :=
  ((word >>> shift.toUInt64) &&& (((1 : UInt64) <<< width.toUInt64) - 1)).toNat

/-- Below the machine-word width, the native mask has its exact natural value. -/
theorem payloadWordMask_toNat (width : Nat) (small : width < 64) :
    (((1 : UInt64) <<< width.toUInt64) - 1).toNat = 2^width - 1 := by
  have sizeBound : width < UInt64.size := Nat.lt_trans small (by decide)
  have index : width.toUInt64.toNat = width := UInt64.toNat_ofNat_of_lt' sizeBound
  have powerBound : 2^width < 2^64 := Nat.pow_lt_pow_right (by decide) small
  have shifted : ((1 : UInt64) <<< width.toUInt64).toNat = 2^width := by
    rw [UInt64.toNat_shiftLeft, UInt64.toNat_one, index,
      Nat.mod_eq_of_lt small, Nat.one_shiftLeft, Nat.mod_eq_of_lt powerBound]
  have nonzero : (1 : UInt64) ≤ (1 : UInt64) <<< width.toUInt64 := by
    rw [UInt64.le_iff_toNat_le, UInt64.toNat_one, shifted]
    exact Nat.two_pow_pos width
  rw [UInt64.toNat_sub_of_le _ _ nonzero, shifted, UInt64.toNat_one]

-- Reference algorithm: Spec/PayloadBits.lean:7.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: extract a field at a one-based payload bit position. -/
def payloadBits (word start width : Nat) : Nat :=
  let shift := 56 - (start - 1 + width)
  if width < 64 then payloadWordBits word.toUInt64 shift width
  else word / 2 ^ shift % 2 ^ width

/-- Every extracted value fits its requested width, including the unrestricted
natural-number fallback. This core-only bound supports runtime array indices. -/
theorem payloadBits_lt (word start width : Nat) : payloadBits word start width < 2^width := by
  unfold payloadBits
  split
  · rename_i small
    unfold payloadWordBits
    rw [UInt64.toNat_and, payloadWordMask_toNat width small]
    exact Nat.lt_of_le_of_lt Nat.and_le_right (Nat.sub_lt (Nat.two_pow_pos width) (by decide))
  · exact Nat.mod_lt _ (Nat.two_pow_pos width)

-- Initial algorithm: Spec/PayloadBits.lean:31.
/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: decode named fields independently by position. -/
def decodePayloadFields (layout : List PayloadColumn) (word : Nat) : List PayloadField :=
  layout.map fun c => ⟨c.name, payloadBits word c.start c.width⟩

-- Initial algorithm: Spec/PayloadBits.lean:41.
/-- Sun, 2nd ed. (2021), ch.17, signed EHS fields: integer interpretation before scaling. -/
def payloadInteger (coding : PayloadCoding) (width code : Nat) : Int :=
  if coding = .twosComplement ∧ code ≥ 2 ^ (width - 1) then
    (code : Int) - (2 ^ width : Nat) else code

/-- Exact affine interpretation of an integer field. Identity scale and zero
offset need no rational multiplication or addition; every other case keeps
the original exact operations in their original order. -/
@[inline] def affineValue (value : Int) (scale offset : Rat) : Rat :=
  let scaled := if scale == 1 then (value : Rat) else (value : Rat) * scale
  if offset == 0 then scaled else scaled + offset

-- Initial algorithm: Spec/PayloadBits.lean:46.
/-- Sun chs.6–8,16–18 tables: exact field interpretation, with absent status
represented by `none`; nonlinear fields have dedicated projections. -/
def payloadValue (column : PayloadColumn) (word : Nat) : Option Rat :=
  if column.status != 0 && payloadBits word column.status 1 == 0 then none
  else some (affineValue (payloadInteger column.coding column.width
    (payloadBits word column.start column.width)) column.scale column.offset)

end Lean1090.Impl

import Model.Types

/-! Auditable field schemas for 56-bit Mode S ME/MB payloads. Bit numbers are
one-based and most significant first, as in ICAO Annex 10 IV, table 3-3. -/
namespace Lean1090.Spec

/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: extract a field at a one-based payload bit position. -/
def payloadBits (word start width : Nat) : Nat :=
  word / 2 ^ (56 - (start - 1 + width)) % 2 ^ width

/-- A schema record contains exactly its declared fields in table order and each
code fits its field width. This condition does not invoke decoding or encoding. -/
def ValidPayloadFields : List PayloadColumn → List PayloadField → Prop
  | [], [] => True
  | c :: cs, f :: fs => f.name = c.name ∧ f.code < 2 ^ c.width ∧ ValidPayloadFields cs fs
  | _, _ => False

/-- Decidability follows the finite field list, independently of the decoder. -/
def validPayloadFieldsDecidable : (cs : List PayloadColumn) → (fs : List PayloadField) →
    Decidable (ValidPayloadFields cs fs)
  | [], [] => isTrue True.intro
  | [], _ :: _ => isFalse id
  | _ :: _, [] => isFalse id
  | c :: cs, f :: fs =>
    letI := validPayloadFieldsDecidable cs fs
    inferInstanceAs (Decidable (f.name = c.name ∧ f.code < 2 ^ c.width ∧ ValidPayloadFields cs fs))

instance (cs : List PayloadColumn) (fs : List PayloadField) :
    Decidable (ValidPayloadFields cs fs) := validPayloadFieldsDecidable cs fs

/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: decode named fields independently by position. -/
def decodePayloadFields (layout : List PayloadColumn) (word : Nat) : List PayloadField :=
  layout.map fun c => ⟨c.name, payloadBits word c.start c.width⟩

/-- ICAO Annex 10 IV (4th ed., 2007) table 3-3: independent encoder places each supplied field
at its table position; it does not call a decoder or search for a preimage. -/
def encodePayloadFields : List PayloadColumn → List PayloadField → Nat
  | c :: cs, f :: fs => f.code * 2 ^ (56 - (c.start - 1 + c.width)) + encodePayloadFields cs fs
  | _, _ => 0

/-- Sun, 2nd ed. (2021), ch.17, signed EHS fields: integer interpretation before scaling. -/
def payloadInteger (coding : PayloadCoding) (width code : Nat) : Int :=
  if coding = .twosComplement ∧ code ≥ 2 ^ (width - 1) then
    (code : Int) - (2 ^ width : Nat) else code

/-- Sun chs.6–8,16–18 tables: exact field interpretation, with absent status
represented by `none`; nonlinear fields have dedicated projections. -/
def payloadValue (column : PayloadColumn) (word : Nat) : Option Rat :=
  if column.status != 0 && payloadBits word column.status 1 == 0 then none
  else some ((payloadInteger column.coding column.width
    (payloadBits word column.start column.width) : Rat) * column.scale + column.offset)

/-- Source-table field lookup. Missing fields remain distinguishable from code zero. -/
def payloadField (record : PayloadRecord) (name : String) : Option Nat :=
  (record.fields.find? fun f => f.name == name).map (·.code)

/-- Source-table layout width/coverage review aid. -/
def payloadLayoutBits (layout : List PayloadColumn) : Nat :=
  (layout.map (·.width)).sum

end Lean1090.Spec

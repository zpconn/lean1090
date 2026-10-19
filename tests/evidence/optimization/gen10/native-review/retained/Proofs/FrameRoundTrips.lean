import Proofs.BitPacking
import Mathlib.Tactic.IntervalCases

/-! Structural frame round-trips for every field assignment and every successfully
parsed byte list, including the two-bit Comm-D descriptor. Generic contiguous
field reconstruction retains spare bits and is independent of receiver policy. -/
namespace Lean1090.Proofs.FrameRoundTrip
open Spec WireBytes BitPacking
set_option linter.unusedSimpArgs false
set_option maxHeartbeats 200000
/-- Proof-only decomposition of the frozen byte parser. -/
private def parseWord (df width word : Nat) : Option Frame := do
  let parity := field width (width-24) 24 word
  let body : FrameBody ← match df with
    | 0 => some (.shortACAS (readACAS width word))
    | 4 => some (.surveillance false (readSurveillance width word))
    | 5 => some (.surveillance true (readSurveillance width word))
    | 11 => some (.allCall (field width 5 3 word) (field width 8 24 word))
    | 16 => some (.longACAS (readACAS width word) (field width 32 56 word))
    | 17 => some (.extended false (field width 5 3 word) (field width 8 24 word) (field width 32 56 word))
    | 18 => some (.extended true (field width 5 3 word) (field width 8 24 word) (field width 32 56 word))
    | 19 => some (.military (field width 5 3 word) (field width 8 80 word))
    | 20 => some (.commB false (readSurveillance width word) (field width 32 56 word))
    | 21 => some (.commB true (readSurveillance width word) (field width 32 56 word))
    | n => if 24 ≤ n then some (.commD (field width 2 1 word) (field width 3 1 word) (field width 4 4 word) (field width 8 80 word)) else none
  some ⟨body, parity⟩
private theorem parse_encoded (count df word : Nat) (positive : 0 < count)
    (bounded : word < 256^count) (count_eq : frameBytes df = count)
    (header : (field (count*8) 0 5 word).toNat = df) :
    decodeFrame (valueBytes count word) = parseWord df (count*8) word := by
  unfold decodeFrame
  rw [valueBytes_head _ _ positive]
  simp only [bind, Option.bind_some]
  rw [byteHeader_field _ _ positive, header, count_eq, valueBytes_length]
  simp only [bne_self_eq_false, Bool.false_eq_true, ite_false]
  rw [bytesValue_valueBytes, Nat.mod_eq_of_lt bounded]
  rfl

private theorem forward_shortACAS (f : ACASFields) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.shortACAS f, p⟩) = some ⟨.shortACAS f, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 0), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (24, p.toNat)]
  have h0 : field 56 0 5 (packFields parts) = 0 := by
    simpa [parts, width] using field_pack []
      [(1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (24, p.toNat)] 5 0
  have h1 : field 56 5 1 (packFields parts) = f.vs := by
    simpa [parts, width] using field_pack [(5, 0)]
      [(1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (24, p.toNat)] 1 f.vs.toNat
  have h2 : field 56 6 1 (packFields parts) = f.cc := by
    simpa [parts, width] using field_pack [(5, 0), (1, f.vs.toNat)]
      [(1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (24, p.toNat)] 1 f.cc.toNat
  have h3 : field 56 7 1 (packFields parts) = f.spare1 := by
    simpa [parts, width] using field_pack [(5, 0), (1, f.vs.toNat), (1, f.cc.toNat)]
      [(3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (24, p.toNat)] 1 f.spare1.toNat
  have h4 : field 56 8 3 (packFields parts) = f.sl := by
    simpa [parts, width] using field_pack [(5, 0), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat)]
      [(2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (24, p.toNat)] 3 f.sl.toNat
  have h5 : field 56 11 2 (packFields parts) = f.spare2 := by
    simpa [parts, width] using field_pack [(5, 0), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat)]
      [(4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (24, p.toNat)] 2 f.spare2.toNat
  have h6 : field 56 13 4 (packFields parts) = f.ri := by
    simpa [parts, width] using field_pack [(5, 0), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat)]
      [(2, f.spare3.toNat), (13, f.ac.toNat), (24, p.toNat)] 4 f.ri.toNat
  have h7 : field 56 17 2 (packFields parts) = f.spare3 := by
    simpa [parts, width] using field_pack [(5, 0), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat)]
      [(13, f.ac.toNat), (24, p.toNat)] 2 f.spare3.toNat
  have h8 : field 56 19 13 (packFields parts) = f.ac := by
    simpa [parts, width] using field_pack [(5, 0), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat)]
      [(24, p.toNat)] 13 f.ac.toNat
  have h9 : field 56 32 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 0), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat)]
      [] 24 p.toNat
  have header : (field (7*8) 0 5 (packFields parts)).toNat = 0 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^56 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^7 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 7 (packFields parts)) = _
  rw [parse_encoded 7 0 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3, h4, h5, h6, h7, h8, h9]

private theorem forward_surveillanceAltitude (f : SurveillanceFields) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.surveillance false f, p⟩) = some ⟨.surveillance false f, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 4), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (24, p.toNat)]
  have h0 : field 56 0 5 (packFields parts) = 4 := by
    simpa [parts, width] using field_pack []
      [(3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (24, p.toNat)] 5 4
  have h1 : field 56 5 3 (packFields parts) = f.fs := by
    simpa [parts, width] using field_pack [(5, 4)]
      [(5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (24, p.toNat)] 3 f.fs.toNat
  have h2 : field 56 8 5 (packFields parts) = f.dr := by
    simpa [parts, width] using field_pack [(5, 4), (3, f.fs.toNat)]
      [(6, f.um.toNat), (13, f.code.toNat), (24, p.toNat)] 5 f.dr.toNat
  have h3 : field 56 13 6 (packFields parts) = f.um := by
    simpa [parts, width] using field_pack [(5, 4), (3, f.fs.toNat), (5, f.dr.toNat)]
      [(13, f.code.toNat), (24, p.toNat)] 6 f.um.toNat
  have h4 : field 56 19 13 (packFields parts) = f.code := by
    simpa [parts, width] using field_pack [(5, 4), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat)]
      [(24, p.toNat)] 13 f.code.toNat
  have h5 : field 56 32 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 4), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat)]
      [] 24 p.toNat
  have header : (field (7*8) 0 5 (packFields parts)).toNat = 4 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^56 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^7 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 7 (packFields parts)) = _
  rw [parse_encoded 7 4 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3, h4, h5]

private theorem forward_surveillanceIdentity (f : SurveillanceFields) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.surveillance true f, p⟩) = some ⟨.surveillance true f, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 5), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (24, p.toNat)]
  have h0 : field 56 0 5 (packFields parts) = 5 := by
    simpa [parts, width] using field_pack []
      [(3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (24, p.toNat)] 5 5
  have h1 : field 56 5 3 (packFields parts) = f.fs := by
    simpa [parts, width] using field_pack [(5, 5)]
      [(5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (24, p.toNat)] 3 f.fs.toNat
  have h2 : field 56 8 5 (packFields parts) = f.dr := by
    simpa [parts, width] using field_pack [(5, 5), (3, f.fs.toNat)]
      [(6, f.um.toNat), (13, f.code.toNat), (24, p.toNat)] 5 f.dr.toNat
  have h3 : field 56 13 6 (packFields parts) = f.um := by
    simpa [parts, width] using field_pack [(5, 5), (3, f.fs.toNat), (5, f.dr.toNat)]
      [(13, f.code.toNat), (24, p.toNat)] 6 f.um.toNat
  have h4 : field 56 19 13 (packFields parts) = f.code := by
    simpa [parts, width] using field_pack [(5, 5), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat)]
      [(24, p.toNat)] 13 f.code.toNat
  have h5 : field 56 32 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 5), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat)]
      [] 24 p.toNat
  have header : (field (7*8) 0 5 (packFields parts)).toNat = 5 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^56 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^7 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 7 (packFields parts)) = _
  rw [parse_encoded 7 5 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3, h4, h5]

private theorem forward_allCall (ca : BitVec 3) (aa : BitVec 24) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.allCall ca aa, p⟩) = some ⟨.allCall ca aa, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 11), (3, ca.toNat), (24, aa.toNat), (24, p.toNat)]
  have h0 : field 56 0 5 (packFields parts) = 11 := by
    simpa [parts, width] using field_pack []
      [(3, ca.toNat), (24, aa.toNat), (24, p.toNat)] 5 11
  have h1 : field 56 5 3 (packFields parts) = ca := by
    simpa [parts, width] using field_pack [(5, 11)]
      [(24, aa.toNat), (24, p.toNat)] 3 ca.toNat
  have h2 : field 56 8 24 (packFields parts) = aa := by
    simpa [parts, width] using field_pack [(5, 11), (3, ca.toNat)]
      [(24, p.toNat)] 24 aa.toNat
  have h3 : field 56 32 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 11), (3, ca.toNat), (24, aa.toNat)]
      [] 24 p.toNat
  have header : (field (7*8) 0 5 (packFields parts)).toNat = 11 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^56 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^7 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 7 (packFields parts)) = _
  rw [parse_encoded 7 11 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3]

private theorem forward_longACAS (f : ACASFields) (mv : BitVec 56) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.longACAS f mv, p⟩) = some ⟨.longACAS f mv, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)]
  have h0 : field 112 0 5 (packFields parts) = 16 := by
    simpa [parts, width] using field_pack []
      [(1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)] 5 16
  have h1 : field 112 5 1 (packFields parts) = f.vs := by
    simpa [parts, width] using field_pack [(5, 16)]
      [(1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)] 1 f.vs.toNat
  have h2 : field 112 6 1 (packFields parts) = f.cc := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat)]
      [(1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)] 1 f.cc.toNat
  have h3 : field 112 7 1 (packFields parts) = f.spare1 := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat)]
      [(3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)] 1 f.spare1.toNat
  have h4 : field 112 8 3 (packFields parts) = f.sl := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat)]
      [(2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)] 3 f.sl.toNat
  have h5 : field 112 11 2 (packFields parts) = f.spare2 := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat)]
      [(4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)] 2 f.spare2.toNat
  have h6 : field 112 13 4 (packFields parts) = f.ri := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat)]
      [(2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)] 4 f.ri.toNat
  have h7 : field 112 17 2 (packFields parts) = f.spare3 := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat)]
      [(13, f.ac.toNat), (56, mv.toNat), (24, p.toNat)] 2 f.spare3.toNat
  have h8 : field 112 19 13 (packFields parts) = f.ac := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat)]
      [(56, mv.toNat), (24, p.toNat)] 13 f.ac.toNat
  have h9 : field 112 32 56 (packFields parts) = mv := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat)]
      [(24, p.toNat)] 56 mv.toNat
  have h10 : field 112 88 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 16), (1, f.vs.toNat), (1, f.cc.toNat), (1, f.spare1.toNat), (3, f.sl.toNat), (2, f.spare2.toNat), (4, f.ri.toNat), (2, f.spare3.toNat), (13, f.ac.toNat), (56, mv.toNat)]
      [] 24 p.toNat
  have header : (field (14*8) 0 5 (packFields parts)).toNat = 16 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^112 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^14 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 14 (packFields parts)) = _
  rw [parse_encoded 14 16 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10]

private theorem forward_extended (cf : BitVec 3) (aa : BitVec 24) (me : BitVec 56) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.extended false cf aa me, p⟩) = some ⟨.extended false cf aa me, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 17), (3, cf.toNat), (24, aa.toNat), (56, me.toNat), (24, p.toNat)]
  have h0 : field 112 0 5 (packFields parts) = 17 := by
    simpa [parts, width] using field_pack []
      [(3, cf.toNat), (24, aa.toNat), (56, me.toNat), (24, p.toNat)] 5 17
  have h1 : field 112 5 3 (packFields parts) = cf := by
    simpa [parts, width] using field_pack [(5, 17)]
      [(24, aa.toNat), (56, me.toNat), (24, p.toNat)] 3 cf.toNat
  have h2 : field 112 8 24 (packFields parts) = aa := by
    simpa [parts, width] using field_pack [(5, 17), (3, cf.toNat)]
      [(56, me.toNat), (24, p.toNat)] 24 aa.toNat
  have h3 : field 112 32 56 (packFields parts) = me := by
    simpa [parts, width] using field_pack [(5, 17), (3, cf.toNat), (24, aa.toNat)]
      [(24, p.toNat)] 56 me.toNat
  have h4 : field 112 88 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 17), (3, cf.toNat), (24, aa.toNat), (56, me.toNat)]
      [] 24 p.toNat
  have header : (field (14*8) 0 5 (packFields parts)).toNat = 17 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^112 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^14 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 14 (packFields parts)) = _
  rw [parse_encoded 14 17 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3, h4]

private theorem forward_extendedSupplementary (cf : BitVec 3) (aa : BitVec 24) (me : BitVec 56) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.extended true cf aa me, p⟩) = some ⟨.extended true cf aa me, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 18), (3, cf.toNat), (24, aa.toNat), (56, me.toNat), (24, p.toNat)]
  have h0 : field 112 0 5 (packFields parts) = 18 := by
    simpa [parts, width] using field_pack []
      [(3, cf.toNat), (24, aa.toNat), (56, me.toNat), (24, p.toNat)] 5 18
  have h1 : field 112 5 3 (packFields parts) = cf := by
    simpa [parts, width] using field_pack [(5, 18)]
      [(24, aa.toNat), (56, me.toNat), (24, p.toNat)] 3 cf.toNat
  have h2 : field 112 8 24 (packFields parts) = aa := by
    simpa [parts, width] using field_pack [(5, 18), (3, cf.toNat)]
      [(56, me.toNat), (24, p.toNat)] 24 aa.toNat
  have h3 : field 112 32 56 (packFields parts) = me := by
    simpa [parts, width] using field_pack [(5, 18), (3, cf.toNat), (24, aa.toNat)]
      [(24, p.toNat)] 56 me.toNat
  have h4 : field 112 88 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 18), (3, cf.toNat), (24, aa.toNat), (56, me.toNat)]
      [] 24 p.toNat
  have header : (field (14*8) 0 5 (packFields parts)).toNat = 18 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^112 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^14 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 14 (packFields parts)) = _
  rw [parse_encoded 14 18 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3, h4]

private theorem forward_military (af : BitVec 3) (bits : BitVec 80) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.military af bits, p⟩) = some ⟨.military af bits, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 19), (3, af.toNat), (80, bits.toNat), (24, p.toNat)]
  have h0 : field 112 0 5 (packFields parts) = 19 := by
    simpa [parts, width] using field_pack []
      [(3, af.toNat), (80, bits.toNat), (24, p.toNat)] 5 19
  have h1 : field 112 5 3 (packFields parts) = af := by
    simpa [parts, width] using field_pack [(5, 19)]
      [(80, bits.toNat), (24, p.toNat)] 3 af.toNat
  have h2 : field 112 8 80 (packFields parts) = bits := by
    simpa [parts, width] using field_pack [(5, 19), (3, af.toNat)]
      [(24, p.toNat)] 80 bits.toNat
  have h3 : field 112 88 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 19), (3, af.toNat), (80, bits.toNat)]
      [] 24 p.toNat
  have header : (field (14*8) 0 5 (packFields parts)).toNat = 19 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^112 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^14 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 14 (packFields parts)) = _
  rw [parse_encoded 14 19 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3]

private theorem forward_commBAltitude (f : SurveillanceFields) (mb : BitVec 56) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.commB false f mb, p⟩) = some ⟨.commB false f mb, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 20), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat), (24, p.toNat)]
  have h0 : field 112 0 5 (packFields parts) = 20 := by
    simpa [parts, width] using field_pack []
      [(3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat), (24, p.toNat)] 5 20
  have h1 : field 112 5 3 (packFields parts) = f.fs := by
    simpa [parts, width] using field_pack [(5, 20)]
      [(5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat), (24, p.toNat)] 3 f.fs.toNat
  have h2 : field 112 8 5 (packFields parts) = f.dr := by
    simpa [parts, width] using field_pack [(5, 20), (3, f.fs.toNat)]
      [(6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat), (24, p.toNat)] 5 f.dr.toNat
  have h3 : field 112 13 6 (packFields parts) = f.um := by
    simpa [parts, width] using field_pack [(5, 20), (3, f.fs.toNat), (5, f.dr.toNat)]
      [(13, f.code.toNat), (56, mb.toNat), (24, p.toNat)] 6 f.um.toNat
  have h4 : field 112 19 13 (packFields parts) = f.code := by
    simpa [parts, width] using field_pack [(5, 20), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat)]
      [(56, mb.toNat), (24, p.toNat)] 13 f.code.toNat
  have h5 : field 112 32 56 (packFields parts) = mb := by
    simpa [parts, width] using field_pack [(5, 20), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat)]
      [(24, p.toNat)] 56 mb.toNat
  have h6 : field 112 88 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 20), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat)]
      [] 24 p.toNat
  have header : (field (14*8) 0 5 (packFields parts)).toNat = 20 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^112 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^14 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 14 (packFields parts)) = _
  rw [parse_encoded 14 20 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3, h4, h5, h6]

private theorem forward_commBIdentity (f : SurveillanceFields) (mb : BitVec 56) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.commB true f mb, p⟩) = some ⟨.commB true f mb, p⟩ := by
  let parts : List (Nat × Nat) := [(5, 21), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat), (24, p.toNat)]
  have h0 : field 112 0 5 (packFields parts) = 21 := by
    simpa [parts, width] using field_pack []
      [(3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat), (24, p.toNat)] 5 21
  have h1 : field 112 5 3 (packFields parts) = f.fs := by
    simpa [parts, width] using field_pack [(5, 21)]
      [(5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat), (24, p.toNat)] 3 f.fs.toNat
  have h2 : field 112 8 5 (packFields parts) = f.dr := by
    simpa [parts, width] using field_pack [(5, 21), (3, f.fs.toNat)]
      [(6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat), (24, p.toNat)] 5 f.dr.toNat
  have h3 : field 112 13 6 (packFields parts) = f.um := by
    simpa [parts, width] using field_pack [(5, 21), (3, f.fs.toNat), (5, f.dr.toNat)]
      [(13, f.code.toNat), (56, mb.toNat), (24, p.toNat)] 6 f.um.toNat
  have h4 : field 112 19 13 (packFields parts) = f.code := by
    simpa [parts, width] using field_pack [(5, 21), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat)]
      [(56, mb.toNat), (24, p.toNat)] 13 f.code.toNat
  have h5 : field 112 32 56 (packFields parts) = mb := by
    simpa [parts, width] using field_pack [(5, 21), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat)]
      [(24, p.toNat)] 56 mb.toNat
  have h6 : field 112 88 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(5, 21), (3, f.fs.toNat), (5, f.dr.toNat), (6, f.um.toNat), (13, f.code.toNat), (56, mb.toNat)]
      [] 24 p.toNat
  have header : (field (14*8) 0 5 (packFields parts)).toNat = 21 := by rw [h0]; rfl
  have bitsBound : packFields parts < 2^112 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^14 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    ACASFields.parts, SurveillanceFields.parts, Nat.reduceAdd, Nat.reduceDiv,
    List.cons_append, List.nil_append, Bool.false_eq_true, ite_true, ite_false]
  change decodeFrame (valueBytes 14 (packFields parts)) = _
  rw [parse_encoded 14 21 _ (by decide) bounded (by decide) header]
  simp only [parseWord, readACAS, readSurveillance, Nat.reduceMul, Nat.reduceSub,
    bind, Option.bind_some, h1, h2, h3, h4, h5, h6]

private theorem leading_two_bits (word : Nat) :
    (field 112 0 5 word).toNat / 8 = (field 112 0 2 word).toNat := by
  change (word / 2^107 % (8*4)) / 8 = word / 2^110 % 4
  rw [Nat.mod_mul_right_div_self, Nat.div_div_eq_div_mul]

private theorem parse_commD (df word : Nat) (header : 24 ≤ df) :
    parseWord df 112 word = some ⟨.commD (field 112 2 1 word)
      (field 112 3 1 word) (field 112 4 4 word) (field 112 8 80 word),
      field 112 88 24 word⟩ := by
  unfold parseWord
  split <;> try omega
  simp only [header, ite_true, bind, Option.bind_some, Nat.reduceSub]

private theorem forward_commD (spare ke : BitVec 1) (nd : BitVec 4)
    (md : BitVec 80) (p : BitVec 24) :
    decodeFrame (encodeFrame ⟨.commD spare ke nd md, p⟩) =
      some ⟨.commD spare ke nd md, p⟩ := by
  let parts : List (Nat × Nat) := [(2, 3), (1, spare.toNat), (1, ke.toNat), (4, nd.toNat), (80, md.toNat), (24, p.toNat)]
  have h0 : field 112 0 2 (packFields parts) = 3 := by
    simpa [parts, width] using field_pack [] [(1, spare.toNat), (1, ke.toNat), (4, nd.toNat), (80, md.toNat), (24, p.toNat)] 2 3
  have h1 : field 112 2 1 (packFields parts) = spare := by
    simpa [parts, width] using field_pack [(2, 3)] [(1, ke.toNat), (4, nd.toNat), (80, md.toNat), (24, p.toNat)] 1 spare.toNat
  have h2 : field 112 3 1 (packFields parts) = ke := by
    simpa [parts, width] using field_pack [(2, 3), (1, spare.toNat)] [(4, nd.toNat), (80, md.toNat), (24, p.toNat)] 1 ke.toNat
  have h3 : field 112 4 4 (packFields parts) = nd := by
    simpa [parts, width] using field_pack [(2, 3), (1, spare.toNat), (1, ke.toNat)] [(80, md.toNat), (24, p.toNat)] 4 nd.toNat
  have h4 : field 112 8 80 (packFields parts) = md := by
    simpa [parts, width] using field_pack [(2, 3), (1, spare.toNat), (1, ke.toNat), (4, nd.toNat)] [(24, p.toNat)] 80 md.toNat
  have h5 : field 112 88 24 (packFields parts) = p := by
    simpa [parts, width] using field_pack [(2, 3), (1, spare.toNat), (1, ke.toNat), (4, nd.toNat), (80, md.toNat)] [] 24 p.toNat
  let df := (field 112 0 5 (packFields parts)).toNat
  have div_header : df / 8 = 3 := by
    dsimp only [df]
    rw [leading_two_bits, h0]
    rfl
  have lower : 24 ≤ df := by omega
  have bitsBound : packFields parts < 2^112 := by
    simpa only [parts, width, List.map_cons, List.map_nil, List.sum_cons, List.sum_nil,
      Nat.reduceAdd] using pack_bound parts
  have bounded : packFields parts < 256^14 := by
    rw [byte_radix]
    norm_num only [Nat.reduceMul]
    exact bitsBound
  have count_eq : frameBytes df = 14 := by simp [frameBytes, show ¬ df < 16 by omega]
  simp only [encodeFrame, FrameBody.parts, FrameBody.informationBits,
    Nat.reduceAdd, Nat.reduceDiv, List.cons_append, List.nil_append]
  change decodeFrame (valueBytes 14 (packFields parts)) = _
  rw [parse_encoded 14 df _ (by decide) bounded count_eq rfl]
  rw [show 14*8=112 by decide, parse_commD df _ lower, h1, h2, h3, h4, h5]

/-- All independently assigned structural fields survive wire serialization. -/
theorem decode_encode (frame : Frame) : decodeFrame (encodeFrame frame) = some frame := by
  rcases frame with ⟨body, parity⟩
  cases body with
  | shortACAS f => exact forward_shortACAS f parity
  | surveillance identity f =>
      cases identity
      · exact forward_surveillanceAltitude f parity
      · exact forward_surveillanceIdentity f parity
  | allCall ca aa => exact forward_allCall ca aa parity
  | longACAS f mv => exact forward_longACAS f mv parity
  | extended supplementary cf aa me =>
      cases supplementary
      · exact forward_extended cf aa me parity
      · exact forward_extendedSupplementary cf aa me parity
  | military af bits => exact forward_military af bits parity
  | commB identity f mb =>
      cases identity
      · exact forward_commBAltitude f mb parity
      · exact forward_commBIdentity f mb parity
  | commD spare ke nd md => exact forward_commD spare ke nd md parity

#print axioms decode_encode

private theorem repack_allCall (word : Nat) (header : (field 56 0 5 word).toNat = 11) :
    packFields ((FrameBody.allCall (field 56 5 3 word) (field 56 8 24 word)).parts ++
      [(24, (field 56 32 24 word).toNat)]) = word % 2^56 := by
  simp only [FrameBody.parts, List.cons_append, List.nil_append, field,
    BitVec.toNat_ofNat, Nat.reduceSub] at ⊢ header
  have reconstruction := pack_extractParts [5,3,24,24] word
  simp only [extractParts, List.sum_cons, List.sum_nil, Nat.reduceAdd] at reconstruction
  rw [header] at reconstruction
  exact reconstruction


private theorem repack_shortACAS (word : Nat) (header : (field 56 0 5 word).toNat = 0) :
    packFields ((FrameBody.shortACAS (readACAS 56 word)).parts ++
      [(24, (field 56 32 24 word).toNat)]) = word % 2^56 := by
  simp only [FrameBody.parts, ACASFields.parts, readACAS, List.cons_append,
    List.nil_append, field, BitVec.toNat_ofNat, Nat.reduceSub] at ⊢ header
  have reconstruction := pack_extractParts [5,1,1,1,3,2,4,2,13,24] word
  simp only [extractParts, List.sum_cons, List.sum_nil, Nat.reduceAdd] at reconstruction
  rw [header] at reconstruction
  exact reconstruction

private theorem repack_surveillance (id : Bool) (word : Nat)
    (header : (field 56 0 5 word).toNat = if id then 5 else 4) :
    packFields ((FrameBody.surveillance id (readSurveillance 56 word)).parts ++
      [(24, (field 56 32 24 word).toNat)]) = word % 2^56 := by
  simp only [FrameBody.parts, SurveillanceFields.parts, readSurveillance, List.cons_append,
    List.nil_append, field, BitVec.toNat_ofNat, Nat.reduceSub] at ⊢ header
  have reconstruction := pack_extractParts [5,3,5,6,13,24] word
  simp only [extractParts, List.sum_cons, List.sum_nil, Nat.reduceAdd] at reconstruction
  rw [header] at reconstruction
  exact reconstruction

private theorem repack_longACAS (word : Nat) (header : (field 112 0 5 word).toNat = 16) :
    packFields ((FrameBody.longACAS (readACAS 112 word) (field 112 32 56 word)).parts ++
      [(24, (field 112 88 24 word).toNat)]) = word % 2^112 := by
  simp only [FrameBody.parts, ACASFields.parts, readACAS, List.cons_append,
    List.nil_append, field, BitVec.toNat_ofNat, Nat.reduceSub] at ⊢ header
  have reconstruction := pack_extractParts [5,1,1,1,3,2,4,2,13,56,24] word
  simp only [extractParts, List.sum_cons, List.sum_nil, Nat.reduceAdd] at reconstruction
  rw [header] at reconstruction
  exact reconstruction

private theorem repack_extended (supp : Bool) (word : Nat)
    (header : (field 112 0 5 word).toNat = if supp then 18 else 17) :
    packFields ((FrameBody.extended supp (field 112 5 3 word) (field 112 8 24 word)
      (field 112 32 56 word)).parts ++ [(24, (field 112 88 24 word).toNat)]) = word % 2^112 := by
  simp only [FrameBody.parts, List.cons_append, List.nil_append,
    field, BitVec.toNat_ofNat, Nat.reduceSub] at ⊢ header
  have reconstruction := pack_extractParts [5,3,24,56,24] word
  simp only [extractParts, List.sum_cons, List.sum_nil, Nat.reduceAdd] at reconstruction
  rw [header] at reconstruction
  exact reconstruction

private theorem repack_military (word : Nat) (header : (field 112 0 5 word).toNat = 19) :
    packFields ((FrameBody.military (field 112 5 3 word) (field 112 8 80 word)).parts ++
      [(24, (field 112 88 24 word).toNat)]) = word % 2^112 := by
  simp only [FrameBody.parts, List.cons_append, List.nil_append,
    field, BitVec.toNat_ofNat, Nat.reduceSub] at ⊢ header
  have reconstruction := pack_extractParts [5,3,80,24] word
  simp only [extractParts, List.sum_cons, List.sum_nil, Nat.reduceAdd] at reconstruction
  rw [header] at reconstruction
  exact reconstruction

private theorem repack_commB (id : Bool) (word : Nat)
    (header : (field 112 0 5 word).toNat = if id then 21 else 20) :
    packFields ((FrameBody.commB id (readSurveillance 112 word) (field 112 32 56 word)).parts ++
      [(24, (field 112 88 24 word).toNat)]) = word % 2^112 := by
  simp only [FrameBody.parts, SurveillanceFields.parts, readSurveillance, List.cons_append,
    List.nil_append, field, BitVec.toNat_ofNat, Nat.reduceSub] at ⊢ header
  have reconstruction := pack_extractParts [5,3,5,6,13,56,24] word
  simp only [extractParts, List.sum_cons, List.sum_nil, Nat.reduceAdd] at reconstruction
  rw [header] at reconstruction
  exact reconstruction

private theorem repack_commD (word : Nat) (header : (field 112 0 2 word).toNat = 3) :
    packFields ((FrameBody.commD (field 112 2 1 word) (field 112 3 1 word)
      (field 112 4 4 word) (field 112 8 80 word)).parts ++
      [(24, (field 112 88 24 word).toNat)]) = word % 2^112 := by
  simp only [FrameBody.parts, List.cons_append, List.nil_append,
    field, BitVec.toNat_ofNat, Nat.reduceSub] at ⊢ header
  have reconstruction := pack_extractParts [2,1,1,4,80,24] word
  simp only [extractParts, List.sum_cons, List.sum_nil, Nat.reduceAdd] at reconstruction
  rw [header] at reconstruction
  exact reconstruction


private theorem encode_parseWord (df word : Nat) (boundedDF : df < 32)
    (header : (field (frameBytes df * 8) 0 5 word).toNat = df)
    (frame : Frame) (parsed : parseWord df (frameBytes df * 8) word = some frame) :
    encodeFrame frame = valueBytes (frameBytes df) (word % 2^(frameBytes df * 8)) := by
  by_cases commD : 24 ≤ df
  · have count : frameBytes df = 14 := by simp [frameBytes, show ¬df < 16 by omega]
    rw [count] at header parsed ⊢
    have top : (field 112 0 2 word).toNat = 3 := by
      rw [← leading_two_bits, header]
      omega
    rw [show 14*8=112 by decide, parse_commD df word commD] at parsed
    cases parsed
    unfold encodeFrame
    rw [repack_commD word top]
    simp [FrameBody.informationBits]
  · have bound : df < 24 := by omega
    interval_cases df <;>
      simp only [frameBytes, Nat.reduceLT, ite_true, ite_false, Nat.reduceMul,
        parseWord, Nat.reduceSub, Nat.reduceLeDiff, bind, Option.bind_some, Option.bind_none,
        Option.some.injEq, reduceCtorEq] at parsed header ⊢
    all_goals
      cases parsed
      unfold encodeFrame
      first
      | rw [repack_shortACAS word header]; simp [FrameBody.informationBits]
      | rw [repack_surveillance false word header]; simp [FrameBody.informationBits]
      | rw [repack_surveillance true word header]; simp [FrameBody.informationBits]
      | rw [repack_allCall word header]; simp [FrameBody.informationBits]
      | rw [repack_longACAS word header]; simp [FrameBody.informationBits]
      | rw [repack_extended false word header]; simp [FrameBody.informationBits]
      | rw [repack_extended true word header]; simp [FrameBody.informationBits]
      | rw [repack_military word header]; simp [FrameBody.informationBits]
      | rw [repack_commB false word header]; simp [FrameBody.informationBits]
      | rw [repack_commB true word header]; simp [FrameBody.informationBits]


/-- Successful structural decoding retains every byte, including spare bits. -/
theorem encode_decode (bytes : List UInt8) (frame : Frame)
    (decoded : decodeFrame bytes = some frame) : encodeFrame frame = bytes := by
  cases bytes with
  | nil => simp [decodeFrame] at decoded
  | cons first rest =>
    have lengthEq : (first :: rest).length = frameBytes (first.toNat / 8) := by
      by_contra mismatch
      simp [decodeFrame, mismatch] at decoded
      exact mismatch (by simpa using decoded.1)
    have positive : 0 < frameBytes (first.toNat / 8) := by
      rw [← lengthEq]
      simp
    have bounded : bytesValue (first :: rest) < 256 ^ frameBytes (first.toNat / 8) := by
      rw [← lengthEq]
      exact bytesValue_lt (first :: rest)
    have boundedDF : first.toNat / 8 < 32 := by
      have boundedByte := first.toNat_lt_size
      change first.toNat < 256 at boundedByte
      omega
    have header : (field (frameBytes (first.toNat / 8) * 8) 0 5
        (bytesValue (first :: rest))).toNat = first.toNat / 8 := by
      rw [← lengthEq]
      exact bytesValue_header first rest
    have repr : valueBytes (frameBytes (first.toNat / 8)) (bytesValue (first :: rest)) =
        first :: rest := by
      rw [← lengthEq]
      exact valueBytes_bytesValue (first :: rest)
    have parsed : parseWord (first.toNat / 8) (frameBytes (first.toNat / 8) * 8)
        (bytesValue (first :: rest)) = some frame := by
      rw [← parse_encoded _ _ _ positive bounded rfl header, repr]
      exact decoded
    have reconstructed := encode_parseWord _ _ boundedDF header frame parsed
    rw [← byte_radix, Nat.mod_eq_of_lt bounded] at reconstructed
    exact reconstructed.trans repr

end Lean1090.Proofs.FrameRoundTrip

namespace Lean1090.Proofs
/-- Both exact inverses of every structural frame layout. -/
theorem FrameRoundTrips : Capstones.FrameRoundTrips :=
  ⟨FrameRoundTrip.decode_encode, FrameRoundTrip.encode_decode⟩

#print axioms FrameRoundTrips
end Lean1090.Proofs

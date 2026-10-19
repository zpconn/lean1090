import Proofs.Binary64Bounds

/-!
# Conservative Comm-B field bounds

These all-input bounds cover every schema column and compatibility projection,
plus the exact QNH/Mach arithmetic trace. A kernel-checked finite 10-bit check
proves every positive modeled Mach value is at least 1/1000, bounding the live
IAS/Mach divisor without assuming a valid or plausible message. They support
the complete CommBArithmetic capstone in Proofs.CommBArithmetic.
-/
namespace Lean1090.Proofs.CommBArithmeticFacts
open Spec Binary64Facts

theorem payloadBits_lt (word start width : Nat) : payloadBits word start width < 2 ^ width :=
  Nat.mod_lt _ (Nat.two_pow_pos width)

theorem payloadInteger_abs_bound (word start width : Nat) (coding : PayloadCoding) :
    ((payloadInteger coding width (payloadBits word start width) : Int) : Rat).abs ≤ (2 ^ width : Nat) := by
  have rawBound := payloadBits_lt word start width
  have rawRat : (payloadBits word start width : Rat) ≤ (2 ^ width : Nat) := by exact_mod_cast rawBound.le
  have rawNonneg : (0 : Rat) ≤ payloadBits word start width := by positivity
  rw [rat_abs_eq_abs, abs_le]
  unfold payloadInteger
  split
  · simp only [Int.cast_sub, Int.cast_natCast]
    constructor <;> linarith
  · simp only [Int.cast_natCast]
    constructor <;> linarith

theorem payloadValue_bound (column : PayloadColumn) (word : Nat) (value : Rat)
    (width : column.width ≤ 56) (scale : column.scale.abs ≤ 1024)
    (offset : column.offset.abs ≤ 1024) (decoded : payloadValue column word = some value) :
    value.abs ≤ 2 ^ 68 := by
  unfold payloadValue at decoded
  split at decoded
  · contradiction
  · cases decoded
    have raw := payloadInteger_abs_bound word column.start column.width column.coding
    have powerBound : ((2 ^ column.width : Nat) : Rat) ≤ 2 ^ 56 := by
      exact_mod_cast Nat.pow_le_pow_right (by decide : 0 < (2 : Nat)) width
    have product := mul_le_mul (le_trans raw powerBound) scale Rat.abs_nonneg (by positivity : (0 : Rat) ≤ 2 ^ 56)
    simp only [rat_abs_eq_abs] at scale offset product ⊢
    have sum := abs_add_le (((payloadInteger column.coding column.width
      (payloadBits word column.start column.width) : Int) : Rat) * column.scale) column.offset
    rw [abs_mul] at sum
    norm_num at product ⊢
    linarith

theorem layout_bounds (register : Nat) (layout : List PayloadColumn)
    (selected : commBLayout register = some layout) :
    ∀ column ∈ layout, column.width ≤ 56 ∧ column.scale.abs ≤ 1024 ∧ column.offset.abs ≤ 1024 := by
  unfold commBLayout at selected
  split at selected <;> cases selected <;> decide +kernel


theorem selected_bound (code : Nat) (bound : code < 4096) : (cbSelected code).abs ≤ 2 ^ 68 := by
  unfold cbSelected
  rw [Rat.abs_of_nonneg (by positivity)]
  have product := Nat.div_mul_le_self (code * 16 + 8) 100
  exact_mod_cast (show (code * 16 + 8) / 100 * 100 ≤ 2 ^ 68 by omega)

theorem temperature_bound (word : Nat) : (cbTemperature44 word).abs ≤ 2 ^ 68 := by
  have signed := payloadInteger_abs_bound word 24 11 .twosComplement
  change (cbSigned word 24 11).abs ≤ 2048 at signed
  have initial := abs_div_bound (cbSigned word 24 11) 4 2048 4 signed (by decide) (by decide)
  dsimp only [cbTemperature44]
  split
  · have h := abs_add_bound (cbSigned word 24 11 / 4) 256 (2048 / 4) 256 initial (by decide)
    norm_num at h ⊢
    linarith
  · norm_num at initial ⊢
    linarith

theorem vertical_bound (word start : Nat) : (cbVertical60 word start).abs ≤ 2 ^ 68 := by
  have signed := payloadInteger_abs_bound word start 10 .twosComplement
  change (cbSigned word start 10).abs ≤ 1024 at signed
  dsimp only [cbVertical60]
  split
  · decide +kernel
  · have h := abs_mul_bound (cbSigned word start 10) 32 1024 32 signed (by decide)
    norm_num at h ⊢
    linarith

theorem wrap_bound (value : Rat) (bound : value.abs ≤ 2 ^ 68) : (cbWrapAngle value).abs ≤ 2 ^ 70 := by
  unfold cbWrapAngle
  split
  · have h := abs_add_bound value 360 (2 ^ 68) 360 bound (by decide)
    norm_num at h ⊢
    linarith
  · norm_num at bound ⊢
    linarith

/-- FC003's DTE quantity combines two bounded bytes in native little-endian
order; its exact value fits well inside the existing arithmetic envelope. -/
theorem dte_bound (word : Nat) :
    ((payloadBits word 41 8 : Rat) + 256 * payloadBits word 49 8).abs ≤ 2 ^ 68 := by
  have low : (payloadBits word 41 8 : Rat) ≤ 256 := by
    exact_mod_cast (payloadBits_lt word 41 8).le
  have high : (payloadBits word 49 8 : Rat) ≤ 256 := by
    exact_mod_cast (payloadBits_lt word 49 8).le
  rw [Rat.abs_of_nonneg (by positivity)]
  norm_num
  linarith

theorem value_bound (register word : Nat) (name : String) (value : Rat)
    (decoded : commBValue register word name = some value) : value.abs ≤ 2 ^ 70 := by
  unfold commBValue at decoded
  obtain ⟨layout, selected, rest⟩ := Option.bind_eq_some_iff.mp decoded
  obtain ⟨column, found, rest⟩ := Option.bind_eq_some_iff.mp rest
  obtain ⟨original, parsed, result⟩ := Option.bind_eq_some_iff.mp rest
  obtain ⟨width, scale, offset⟩ := layout_bounds register layout selected column (List.mem_of_find?_eq_some found)
  have originalBound := payloadValue_bound column word original width scale offset parsed
  have selectedMCP := selected_bound (payloadBits word 2 12) (payloadBits_lt word 2 12)
  have selectedFMS := selected_bound (payloadBits word 15 12) (payloadBits_lt word 15 12)
  have temperature := temperature_bound word
  have verticalBaro := vertical_bound word 36
  have verticalInertial := vertical_bound word 47
  have wrapped := wrap_bound original originalBound
  have dte := dte_bound word
  split at result
  all_goals first
    | (cases result; norm_num at *; linarith)
    | (split at result <;> cases result; norm_num at *; linarith)

theorem field_arithmetic_bounds (word : Nat) :
    (∀ x ∈ cbFieldArithmeticTrace word, x.abs ≤ 2 ^ 70) ∧
    (cbQNH64 word).abs ≤ 2 ^ 70 ∧ (cbMach64 word).abs ≤ 2 ^ 70 := by
  let q : Rat := payloadBits word 28 12
  let m : Rat := payloadBits word 25 10
  let tenth := Binary64.literal (1/10)
  let scale := Binary64.literal (256/125)
  let qp := Binary64.mul q tenth
  let mp := Binary64.mul m scale
  have hq : q.abs ≤ 4096 := by
    rw [Rat.abs_of_nonneg (by dsimp [q]; positivity)]
    dsimp [q]
    exact_mod_cast (payloadBits_lt word 28 12).le
  have hm : m.abs ≤ 1024 := by
    rw [Rat.abs_of_nonneg (by dsimp [m]; positivity)]
    dsimp [m]
    exact_mod_cast (payloadBits_lt word 25 10).le
  have htenth : tenth.abs ≤ 1 := by decide +kernel
  have hscale : scale.abs ≤ 3 := by decide +kernel
  have hqpExact := abs_mul_bound q tenth 4096 1 hq htenth
  have hmpExact := abs_mul_bound m scale 1024 3 hm hscale
  have hqp := round_bound_of_abs_le (q * tenth) (4096 * 1) hqpExact
  have hmp := round_bound_of_abs_le (m * scale) (1024 * 3) hmpExact
  change qp.abs ≤ _ at hqp
  change mp.abs ≤ _ at hmp
  have hqSum := abs_add_bound qp 800 (3 * (4096 * 1) + 1) 800 hqp (by decide)
  have hQNH := round_bound_of_abs_le (qp + 800) (3 * (4096 * 1) + 1 + 800) hqSum
  change (cbQNH64 word).abs ≤ _ at hQNH
  have hmDivision := abs_div_bound mp 512 (3 * (1024 * 3) + 1) 512 hmp (by decide) (by decide)
  have hMach := round_bound_of_abs_le (mp / 512) ((3 * (1024 * 3) + 1) / 512) hmDivision
  change (cbMach64 word).abs ≤ _ at hMach
  constructor
  · intro x member
    change x ∈ [q, m, tenth, scale, q*tenth, qp, qp+800, cbQNH64 word,
      m*scale, mp, mp/512, cbMach64 word] at member
    simp only [List.mem_cons, List.not_mem_nil, or_false] at member
    rcases member with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
    all_goals norm_num at *; linarith
  · norm_num at *
    constructor <;> linarith

theorem mach_positive_lower_bound (word : Nat) (positive : 0 < cbMach64 word) :
    (1/1000 : Rat) ≤ cbMach64 word := by
  have checked : ∀ code : Fin 1024,
      let value := Binary64.div
        (Binary64.mul (code.val : Rat) (Binary64.literal (256 / 125))) 512
      0 < value → (1/1000 : Rat) ≤ value := by decide +kernel
  exact checked ⟨payloadBits word 25 10, payloadBits_lt word 25 10⟩ positive

#print axioms field_arithmetic_bounds
#print axioms mach_positive_lower_bound

end Lean1090.Proofs.CommBArithmeticFacts

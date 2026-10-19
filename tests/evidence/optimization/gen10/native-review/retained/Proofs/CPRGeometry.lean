import Capstones
import Mathlib.Data.Rat.Floor
import Mathlib.Tactic.FieldSimp
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring

/-! Rational CPR geometry: quantization and nearest-cell reconstruction.
The reference definitions remain unchanged; all lemmas here are checked by
the kernel and use the actual frozen encoder and decoder expressions. -/

namespace Lean1090.Proofs.CPRGeometry
open Spec.CPR

theorem absQ_eq_abs (x : Rat) : absQ x = |x| := by
  unfold absQ
  split_ifs with negative
  · exact (abs_of_neg negative).symm
  · exact (abs_of_nonneg (le_of_not_gt negative)).symm

def quantize (step coordinate : Rat) : Rat :=
  step * (((coordinate / step + 1 / 2).floor : Int) : Rat)

theorem quantize_error (step coordinate : Rat) (positive : 0 < step) :
    |quantize step coordinate - coordinate| ≤ step / 2 := by
  have lower := Int.floor_le (coordinate / step + 1 / 2)
  have upper := Int.lt_floor_add_one (coordinate / step + 1 / 2)
  have lower' := mul_le_mul_of_nonneg_left lower (le_of_lt positive)
  have upper' := mul_lt_mul_of_pos_left upper positive
  have cancel : step * (coordinate / step) = coordinate := by field_simp
  change |step * (⌊coordinate / step + 1 / 2⌋ : Rat) - coordinate| ≤ step / 2
  apply abs_le.mpr
  constructor <;> nlinarith

theorem dLat_pos (mode : Medium) (odd : Bool) : 0 < dLat mode odd := by
  cases mode <;> cases odd <;> norm_num [dLat, span, parity]

theorem roundedLatitude_quantize (mode : Medium) (odd : Bool) (latitude : Rat) :
    roundedLatitude mode odd latitude = quantize (dLat mode odd / scale) latitude := by
  have nonzero := ne_of_gt (dLat_pos mode odd)
  unfold roundedLatitude quantize
  simp only [scale, Nat.cast_ofNat]
  field_simp

theorem latitude_quantization_error (mode : Medium) (odd : Bool) (latitude : Rat) :
    absQ (roundedLatitude mode odd latitude - latitude) ≤
      dLat mode odd / (2 * scale) := by
  rw [absQ_eq_abs, roundedLatitude_quantize]
  have positive : 0 < dLat mode odd / (scale : Rat) := by
    exact div_pos (dLat_pos mode odd) (by norm_num [scale])
  have bound := quantize_error (dLat mode odd / scale) latitude positive
  convert bound using 1
  norm_num [scale]
  ring

theorem encodeCoordinate_mod (width coordinate : Rat) (nonzero : width ≠ 0) :
    encodeCoordinate width coordinate =
      ((coordinate / width * 131072 + 1 / 2).floor % 131072).toNat := by
  unfold encodeCoordinate
  simp only [scale, Nat.cast_ofNat]
  have interior : modQ coordinate width / width * 131072 + 1 / 2 =
      coordinate / width * 131072 + 1 / 2 -
        ((131072 * (coordinate / width).floor : Int) : Rat) := by
    unfold modQ
    push_cast
    field_simp
    ring
  rw [interior]
  change (⌊coordinate / width * 131072 + 1 / 2 -
      ((131072 * (coordinate / width).floor : Int) : Rat)⌋ % 131072).toNat = _
  rw [Int.floor_sub_intCast]
  congr 1
  change (⌊coordinate / width * 131072 + 1 / 2⌋ -
    131072 * ⌊coordinate / width⌋) % 131072 =
    ⌊coordinate / width * 131072 + 1 / 2⌋ % 131072
  omega

theorem encodeCoordinate_lt_scale (width coordinate : Rat) :
    encodeCoordinate width coordinate < scale := by
  unfold encodeCoordinate scale
  have lower := Int.emod_nonneg
    (modQ coordinate width / width * (131072 : Rat) + 1 / 2).floor (by decide : (131072 : Int) ≠ 0)
  have upper := Int.emod_lt_of_pos
    (modQ coordinate width / width * (131072 : Rat) + 1 / 2).floor (by decide : (0 : Int) < 131072)
  norm_cast at lower upper ⊢
  omega

theorem localCoordinate_normal (width reference : Rat) (code : Nat)
    (nonzero : width ≠ 0) :
    localCoordinate width reference code = width *
      ((⌊reference / width - (code : Rat) / scale + 1 / 2⌋ : Rat) +
        (code : Rat) / scale) := by
  unfold localCoordinate
  dsimp only
  have interior : modQ reference width / width - (code : Rat) / scale + 1 / 2 =
      (reference / width - (code : Rat) / scale + 1 / 2) -
        ((reference / width).floor : Rat) := by
    unfold modQ
    field_simp
    ring
  rw [interior]
  change width * (((⌊reference / width⌋ +
      ⌊reference / width - (code : Rat) / scale + 1 / 2 -
        (⌊reference / width⌋ : Rat)⌋ : Int) : Rat) + (code : Rat) / scale) = _
  rw [Int.floor_sub_intCast]
  have cancel : ⌊reference / width⌋ +
      (⌊reference / width - (code : Rat) / scale + 1 / 2⌋ - ⌊reference / width⌋) =
      ⌊reference / width - (code : Rat) / scale + 1 / 2⌋ := by omega
  rw [cancel]

theorem localCoordinate_nearest (width reference : Rat) (code : Nat) (index : Int)
    (positive : 0 < width)
    (margin : |reference - width * ((index : Rat) + (code : Rat) / scale)| < width / 2) :
    localCoordinate width reference code =
      width * ((index : Rat) + (code : Rat) / scale) := by
  rw [localCoordinate_normal width reference code (ne_of_gt positive)]
  have lower : (index : Rat) + (code : Rat) / scale - 1 / 2 < reference / width := by
    apply (lt_div_iff₀ positive).mpr
    have := (abs_lt.mp margin).1
    nlinarith
  have upper : reference / width < (index : Rat) + (code : Rat) / scale + 1 / 2 := by
    apply (div_lt_iff₀ positive).mpr
    have := (abs_lt.mp margin).2
    nlinarith
  have index_eq : ⌊reference / width - (code : Rat) / scale + 1 / 2⌋ = index := by
    apply Int.floor_eq_iff.mpr
    constructor <;> linarith
  rw [index_eq]

theorem quantize_grid (width coordinate : Rat) (nonzero : width ≠ 0) :
    ∃ index : Int, quantize (width / scale) coordinate =
      width * ((index : Rat) + (encodeCoordinate width coordinate : Rat) / scale) := by
  let k : Int := (coordinate / width * 131072 + 1 / 2).floor
  refine ⟨k / 131072, ?_⟩
  have floor_arg : coordinate / (width / (scale : Rat)) + 1 / 2 =
      coordinate / width * 131072 + 1 / 2 := by
    norm_num [scale]
    field_simp
  have castmod : ((k % 131072).toNat : Rat) = ((k % 131072 : Int) : Rat) := by
    exact_mod_cast Int.toNat_of_nonneg (Int.emod_nonneg k (by decide : (131072 : Int) ≠ 0))
  have division : (131072 : Rat) * ((k / 131072 : Int) : Rat) +
      ((k % 131072 : Int) : Rat) = (k : Rat) := by
    exact_mod_cast Int.mul_ediv_add_emod k 131072
  unfold quantize
  rw [floor_arg, encodeCoordinate_mod width coordinate nonzero]
  change width / (scale : Rat) * (k : Rat) =
    width * (((k / 131072 : Int) : Rat) + ((k % 131072).toNat : Rat) / scale)
  rw [castmod]
  norm_num [scale]
  rw [← division]
  ring

theorem localCoordinate_round_trip (width coordinate reference : Rat)
    (positive : 0 < width)
    (margin : absQ (reference - quantize (width / scale) coordinate) < width / 2) :
    localCoordinate width reference (encodeCoordinate width coordinate) =
      quantize (width / scale) coordinate := by
  obtain ⟨index, quantized⟩ := quantize_grid width coordinate (ne_of_gt positive)
  rw [quantized, absQ_eq_abs] at margin
  rw [quantized]
  exact localCoordinate_nearest width reference _ index positive margin

theorem quantize_mono (step : Rat) (positive : 0 < step) : Monotone (quantize step) := by
  intro a b ordered
  unfold quantize
  apply mul_le_mul_of_nonneg_left _ (le_of_lt positive)
  have ordered' : a / step + 1 / 2 ≤ b / step + 1 / 2 := by
    have := (div_le_div_iff_of_pos_right positive).mpr ordered
    linarith
  exact_mod_cast Int.floor_mono ordered'

theorem roundedLatitude_range (mode : Medium) (odd : Bool) (latitude : Rat)
    (lower : -90 ≤ latitude) (upper : latitude ≤ 90) :
    -90 ≤ roundedLatitude mode odd latitude ∧ roundedLatitude mode odd latitude ≤ 90 := by
  have positive : 0 < dLat mode odd / (scale : Rat) :=
    div_pos (dLat_pos mode odd) (by norm_num [scale])
  have minus : quantize (dLat mode odd / scale) (-90) = -90 := by
    cases mode <;> cases odd <;> decide +kernel
  have plus : quantize (dLat mode odd / scale) 90 = 90 := by
    cases mode <;> cases odd <;> decide +kernel
  rw [roundedLatitude_quantize]
  constructor
  · simpa only [minus] using quantize_mono _ positive lower
  · simpa only [plus] using quantize_mono _ positive upper

theorem localLatitude_round_trip (mode : Medium) (odd : Bool) (p reference : Position)
    (margin : absQ (reference.lat - roundedLatitude mode odd p.lat) < dLat mode odd / 2) :
    localLatitude mode (encode mode odd p) reference = roundedLatitude mode odd p.lat := by
  simp only [localLatitude, encode]
  rw [roundedLatitude_quantize] at margin ⊢
  exact localCoordinate_round_trip _ _ _ (dLat_pos mode odd) margin

theorem dLon_pos (mode : Medium) (odd : Bool) (latitude : Rat) :
    0 < dLon mode odd latitude := by
  unfold dLon
  apply div_pos
  · cases mode <;> norm_num [span]
  · exact_mod_cast (show 0 < zones latitude odd by unfold zones; omega)

theorem dLon_le_360 (mode : Medium) (odd : Bool) (latitude : Rat) :
    dLon mode odd latitude ≤ 360 := by
  have one : (1 : Rat) ≤ (zones latitude odd : Rat) := by
    exact_mod_cast (show 1 ≤ zones latitude odd by unfold zones; omega)
  unfold dLon
  apply (div_le_iff₀ (by linarith : (0 : Rat) < (zones latitude odd : Rat))).mpr
  cases mode <;> simp only [span] <;> nlinarith

theorem dLon_turn (mode : Medium) (odd : Bool) (latitude : Rat) :
    ∃ stride : Int, dLon mode odd latitude * (stride : Rat) = 360 := by
  have nonzero : (zones latitude odd : Rat) ≠ 0 := by
    have : 0 < zones latitude odd := by unfold zones; omega
    exact_mod_cast ne_of_gt this
  cases mode with
  | airborne =>
    refine ⟨(zones latitude odd : Nat), ?_⟩
    simp [dLon, span, nonzero]
  | surface =>
    refine ⟨4 * (zones latitude odd : Nat), ?_⟩
    push_cast
    simp only [dLon, span]
    field_simp
    norm_num

theorem normalize_add_turns (coordinate : Rat) (turns : Int) :
    normalizeLongitude (coordinate + 360 * (turns : Rat)) = normalizeLongitude coordinate := by
  unfold normalizeLongitude modQ
  have argument : (coordinate + 360 * (turns : Rat) + 180) / 360 =
      (coordinate + 180) / 360 + (turns : Rat) := by ring
  rw [argument]
  change coordinate + 360 * (turns : Rat) + 180 -
      360 * (⌊(coordinate + 180) / 360 + (turns : Rat)⌋ : Rat) - 180 =
      coordinate + 180 - 360 * (⌊(coordinate + 180) / 360⌋ : Rat) - 180
  rw [Int.floor_add_intCast]
  push_cast
  ring

theorem normalize_of_small (coordinate : Rat) (lower : -180 ≤ coordinate)
    (upper : coordinate < 180) : normalizeLongitude coordinate = coordinate := by
  have zero : ⌊(coordinate + 180) / 360⌋ = 0 := by
    apply Int.floor_eq_iff.mpr
    norm_num
    constructor <;> linarith
  unfold normalizeLongitude modQ
  change coordinate + 180 - 360 * (⌊(coordinate + 180) / 360⌋ : Rat) - 180 = coordinate
  rw [zero]
  norm_num

theorem localCoordinate_circular (width coordinate reference : Rat) (stride : Int)
    (positive : 0 < width) (turn : width * (stride : Rat) = 360)
    (margin : longitudeDistance reference (quantize (width / scale) coordinate) < width / 2) :
    ∃ turns : Int, localCoordinate width reference (encodeCoordinate width coordinate) =
      quantize (width / scale) coordinate + 360 * (turns : Rat) := by
  let q := quantize (width / scale) coordinate
  let turns : Int := ((reference - q + 180) / 360).floor
  obtain ⟨index, grid⟩ := quantize_grid width coordinate (ne_of_gt positive)
  have shifted : q + 360 * (turns : Rat) =
      width * (((index + stride * turns : Int) : Rat) +
        (encodeCoordinate width coordinate : Rat) / scale) := by
    dsimp [q]
    rw [grid, ← turn]
    push_cast
    ring
  have normalized : normalizeLongitude (reference - q) =
      reference - (q + 360 * (turns : Rat)) := by
    dsimp [normalizeLongitude, modQ, turns]
    ring
  have near : |reference - (q + 360 * (turns : Rat))| < width / 2 := by
    change absQ (normalizeLongitude (reference - q)) < width / 2 at margin
    rw [normalized, absQ_eq_abs] at margin
    exact margin
  refine ⟨turns, ?_⟩
  change _ = q + 360 * (turns : Rat)
  rw [shifted] at near ⊢
  exact localCoordinate_nearest width reference _ _ positive near

theorem longitude_quantization_error (width coordinate : Rat)
    (positive : 0 < width) (upper : width ≤ 360) :
    longitudeDistance (quantize (width / scale) coordinate) coordinate ≤
      width / (2 * scale) := by
  have step_pos : 0 < width / (scale : Rat) :=
    div_pos positive (by norm_num [scale])
  have error := quantize_error (width / scale) coordinate step_pos
  have small : |quantize (width / scale) coordinate - coordinate| < 180 := by
    norm_num [scale] at error ⊢
    linarith
  unfold longitudeDistance
  rw [normalize_of_small _ (le_of_lt (abs_lt.mp small).1) (abs_lt.mp small).2, absQ_eq_abs]
  convert error using 1
  norm_num [scale]
  ring

theorem local_longitude_resolution (width coordinate reference : Rat) (stride : Int)
    (positive : 0 < width) (upper : width ≤ 360) (turn : width * (stride : Rat) = 360)
    (margin : longitudeDistance reference (quantize (width / scale) coordinate) < width / 2) :
    longitudeDistance (localCoordinate width reference (encodeCoordinate width coordinate)) coordinate ≤
      width / (2 * scale) := by
  obtain ⟨turns, decoded⟩ := localCoordinate_circular width coordinate reference stride positive turn margin
  rw [decoded]
  unfold longitudeDistance
  rw [show quantize (width / scale) coordinate + 360 * (turns : Rat) - coordinate =
      (quantize (width / scale) coordinate - coordinate) + 360 * (turns : Rat) by ring,
    normalize_add_turns]
  exact longitude_quantization_error width coordinate positive upper

theorem roundedLongitude_quantize (mode : Medium) (odd : Bool) (p : Position) :
    roundedLongitude mode odd p =
      quantize (dLon mode odd (roundedLatitude mode odd p.lat) / scale) p.lon := by
  have nonzero := ne_of_gt (dLon_pos mode odd (roundedLatitude mode odd p.lat))
  unfold roundedLongitude quantize
  dsimp only
  simp only [scale, Nat.cast_ofNat]
  field_simp

end Lean1090.Proofs.CPRGeometry

namespace Lean1090.Proofs
open Spec.CPR CPRGeometry

/-- Every valid quantized-reference margin, in both media and parities, selects
the correct latitude cell and the correct longitude cell modulo a full turn. -/
theorem CPRLocal : Capstones.CPRLocal := by
  intro mode odd p reference admissible
  obtain ⟨valid, _, latitude_margin, longitude_margin⟩ := admissible
  have latitude_decoded := localLatitude_round_trip mode odd p reference latitude_margin
  have latitude_range := roundedLatitude_range mode odd p.lat valid.1 valid.2.1
  let latitude := roundedLatitude mode odd p.lat
  let width := dLon mode odd latitude
  let longitude := localCoordinate width reference.lon (encodeCoordinate width p.lon)
  refine ⟨⟨latitude, longitude⟩, ?_, ?_⟩
  · have lat_code := encodeCoordinate_lt_scale (dLat mode odd) p.lat
    have lon_code := encodeCoordinate_lt_scale
      (dLon mode odd (roundedLatitude mode odd p.lat)) p.lon
    simp only [decodeLocal]
    rw [latitude_decoded]
    simp only [encode, latitude_range.1, latitude_range.2, lat_code, lon_code,
      and_self, ↓reduceIte]
    rfl
  · change absQ (latitude - p.lat) ≤ dLat mode odd / (2 * scale) ∧
      longitudeDistance longitude p.lon ≤ width / (2 * scale)
    constructor
    · exact latitude_quantization_error mode odd p.lat
    · obtain ⟨stride, turn⟩ := dLon_turn mode odd latitude
      apply local_longitude_resolution width p.lon reference.lon stride
        (dLon_pos mode odd latitude) (dLon_le_360 mode odd latitude) turn
      rw [← roundedLongitude_quantize]
      exact longitude_margin

end Lean1090.Proofs

#print axioms Lean1090.Proofs.CPRLocal

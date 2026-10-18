import Proofs.CPRGeometry

/-! Universal global CPR reconstruction from independently encoded grids. -/

namespace Lean1090.Proofs.CPRGlobalGeometry
open Spec.CPR CPRGeometry

theorem latitude_wrap (cells : Int) (index : Int) (fraction latitude : Rat)
    (cells_pos : 0 < cells) (fraction_nonneg : 0 ≤ fraction) (fraction_lt : fraction < 1)
    (grid : latitude = (360 / (cells : Rat)) * ((index : Rat) + fraction))
    (lower : -90 ≤ latitude) (upper : latitude ≤ 90) :
    let raw := (360 / (cells : Rat)) * (((index % cells : Int) : Rat) + fraction)
    (if raw ≥ 270 then raw - 360 else raw) = latitude := by
  have cells_pos' : (0 : Rat) < (cells : Rat) := by exact_mod_cast cells_pos
  have cells_ne := ne_of_gt cells_pos'
  have remainder_nonneg : (0 : Rat) ≤ ((index % cells : Int) : Rat) := by
    exact_mod_cast Int.emod_nonneg index (ne_of_gt cells_pos)
  have remainder_upper : ((index % cells : Int) : Rat) + 1 ≤ (cells : Rat) := by
    have := Int.emod_lt_of_pos index cells_pos
    exact_mod_cast (show index % cells + 1 ≤ cells by omega)
  have decomposition : (cells : Rat) * ((index / cells : Int) : Rat) +
      ((index % cells : Int) : Rat) = (index : Rat) := by
    exact_mod_cast Int.mul_ediv_add_emod index cells
  have scaled : latitude / 360 = ((index / cells : Int) : Rat) +
      (((index % cells : Int) : Rat) + fraction) / (cells : Rat) := by
    rw [grid, ← decomposition]
    field_simp
    ring
  have quotient : ⌊latitude / 360⌋ = index / cells := by
    apply Int.floor_eq_iff.mpr
    rw [scaled]
    constructor
    · have : 0 ≤ (((index % cells : Int) : Rat) + fraction) / (cells : Rat) :=
        div_nonneg (by linarith) (le_of_lt cells_pos')
      linarith
    · have : (((index % cells : Int) : Rat) + fraction) / (cells : Rat) < 1 := by
        apply (div_lt_iff₀ cells_pos').mpr
        linarith
      linarith
  have raw_eq : (360 / (cells : Rat)) * (((index % cells : Int) : Rat) + fraction) =
      latitude - 360 * ((index / cells : Int) : Rat) := by
    rw [grid, ← decomposition]
    field_simp
    ring
  dsimp only
  rw [raw_eq, ← quotient]
  by_cases negative : latitude < 0
  · have floor_eq : ⌊latitude / 360⌋ = -1 := by
      apply Int.floor_eq_iff.mpr
      norm_num
      constructor <;> linarith
    rw [floor_eq]
    norm_num
    linarith
  · have floor_eq : ⌊latitude / 360⌋ = 0 := by
      apply Int.floor_eq_iff.mpr
      norm_num
      constructor <;> linarith
    rw [floor_eq]
    norm_num
    linarith

theorem global_latitude_index (a b r₀ r₁ : Rat) (z₀ z₁ : Int)
    (grid₀ : r₀ = 6 * ((z₀ : Rat) + a))
    (grid₁ : r₁ = (360 / 59) * ((z₁ : Rat) + b))
    (margin : absQ (r₀ - r₁) < 3 / 59) :
    (59 * a - 60 * b + 1 / 2).floor = 60 * z₁ - 59 * z₀ := by
  rw [absQ_eq_abs] at margin
  have bounds := abs_lt.mp margin
  change ⌊59 * a - 60 * b + 1 / 2⌋ = _
  apply Int.floor_eq_iff.mpr
  push_cast
  constructor <;> linarith

theorem globalLatitudes_grid (even odd : Encoded) (r₀ r₁ : Rat) (z₀ z₁ : Int)
    (lat₀ : even.lat < scale) (lat₁ : odd.lat < scale)
    (grid₀ : r₀ = dLat .airborne false * ((z₀ : Rat) + (even.lat : Rat) / scale))
    (grid₁ : r₁ = dLat .airborne true * ((z₁ : Rat) + (odd.lat : Rat) / scale))
    (lower₀ : -90 ≤ r₀) (upper₀ : r₀ ≤ 90)
    (lower₁ : -90 ≤ r₁) (upper₁ : r₁ ≤ 90)
    (margin : absQ (r₀ - r₁) < 3 / 59) :
    globalLatitudes even odd = (r₀, r₁) := by
  have lat₀' : (even.lat : Rat) < (scale : Rat) := by exact_mod_cast lat₀
  have lat₁' : (odd.lat : Rat) < (scale : Rat) := by exact_mod_cast lat₁
  have frac₀_nonneg : (0 : Rat) ≤ even.lat / (scale : Rat) := by positivity
  have frac₁_nonneg : (0 : Rat) ≤ odd.lat / (scale : Rat) := by positivity
  have frac₀_lt : (even.lat : Rat) / scale < 1 := by
    apply (div_lt_iff₀ (by norm_num [scale] : (0 : Rat) < scale)).mpr
    simpa using lat₀'
  have frac₁_lt : (odd.lat : Rat) / scale < 1 := by
    apply (div_lt_iff₀ (by norm_num [scale] : (0 : Rat) < scale)).mpr
    simpa using lat₁'
  have grid₀' : r₀ = 6 * ((z₀ : Rat) + (even.lat : Rat) / scale) := by
    norm_num [dLat, span, parity] at grid₀
    exact grid₀
  have grid₁' : r₁ = (360 / 59) * ((z₁ : Rat) + (odd.lat : Rat) / scale) := by
    simpa [dLat, span, parity] using grid₁
  have index := global_latitude_index _ _ _ _ z₀ z₁ grid₀' grid₁' margin
  have mod₀ : (60 * z₁ - 59 * z₀) % 60 = z₀ % 60 := by omega
  have mod₁ : (60 * z₁ - 59 * z₀) % 59 = z₁ % 59 := by omega
  unfold globalLatitudes
  dsimp only
  rw [index, mod₀, mod₁]
  apply Prod.ext
  · exact latitude_wrap 60 z₀ _ r₀ (by norm_num) frac₀_nonneg frac₀_lt
      (by norm_num; exact grid₀') lower₀ upper₀
  · exact latitude_wrap 59 z₁ _ r₁ (by norm_num) frac₁_nonneg frac₁_lt
      (by simpa using grid₁') lower₁ upper₁

theorem globalLatitudes_round_trip (pEven pOdd : Position)
    (valid₀ : ValidPosition pEven) (valid₁ : ValidPosition pOdd)
    (margin : absQ (roundedLatitude .airborne false pEven.lat -
      roundedLatitude .airborne true pOdd.lat) < 3 / 59) :
    globalLatitudes (encode .airborne false pEven) (encode .airborne true pOdd) =
      (roundedLatitude .airborne false pEven.lat, roundedLatitude .airborne true pOdd.lat) := by
  obtain ⟨z₀, grid₀⟩ := quantize_grid (dLat .airborne false) pEven.lat (ne_of_gt (dLat_pos _ _))
  obtain ⟨z₁, grid₁⟩ := quantize_grid (dLat .airborne true) pOdd.lat (ne_of_gt (dLat_pos _ _))
  rw [← roundedLatitude_quantize] at grid₀ grid₁
  have range₀ := roundedLatitude_range .airborne false pEven.lat valid₀.1 valid₀.2.1
  have range₁ := roundedLatitude_range .airborne true pOdd.lat valid₁.1 valid₁.2.1
  apply globalLatitudes_grid _ _ _ _ z₀ z₁
    (encodeCoordinate_lt_scale _ _) (encodeCoordinate_lt_scale _ _)
    grid₀ grid₁ range₀.1 range₀.2 range₁.1 range₁.2 margin


theorem nlTable_pos (latitude : Rat) : 0 < nlTable latitude := by
  have length := (List.takeWhile_sublist
    (l := transitions) (fun (t : Nat) => decide ((t : Rat) / 100000000 ≤ absQ latitude))).length_le
  have size : transitions.length = 58 := by decide +kernel
  unfold nlTable
  split_ifs <;> omega

theorem normalize_grid_mod (n : Int) (index : Int) (fraction : Rat) (nonzero : n ≠ 0) :
    normalizeLongitude ((360 / (n : Rat)) * (((index % n : Int) : Rat) + fraction)) =
    normalizeLongitude ((360 / (n : Rat)) * ((index : Rat) + fraction)) := by
  have nonzero' : (n : Rat) ≠ 0 := by exact_mod_cast nonzero
  have decomposition : (n : Rat) * ((index / n : Int) : Rat) +
      ((index % n : Int) : Rat) = (index : Rat) := by
    exact_mod_cast Int.mul_ediv_add_emod index n
  have difference : (360 / (n : Rat)) * (((index % n : Int) : Rat) + fraction) =
      (360 / (n : Rat)) * ((index : Rat) + fraction) + 360 * ((-(index / n) : Int) : Rat) := by
    push_cast
    rw [← decomposition]
    field_simp
    ring
  rw [difference, normalize_add_turns]

theorem normalize_left_distance (a b : Rat) :
    longitudeDistance (normalizeLongitude a) b = longitudeDistance a b := by
  have normalization : normalizeLongitude a = a + 360 * ((-((a+180)/360).floor : Int) : Rat) := by
    unfold normalizeLongitude modQ
    push_cast
    ring
  unfold longitudeDistance
  rw [normalization]
  rw [show a + 360 * ((-((a+180)/360).floor : Int) : Rat) - b =
    (a-b) + 360 * ((-((a+180)/360).floor : Int) : Rat) by ring]
  rw [normalize_add_turns]

set_option maxHeartbeats 2000000 in
theorem global_longitude_index (n : Nat) (a b r₀ r₁ : Rat) (z₀ z₁ : Int)
    (nlarge : 2 ≤ n)
    (grid₀ : r₀ = 360 / (n : Rat) * ((z₀ : Rat) + a))
    (grid₁ : r₁ = 360 / ((n-1 : Nat) : Rat) * ((z₁ : Rat) + b))
    (margin : longitudeDistance r₀ r₁ < 180 / ((n * (n-1) : Nat) : Rat)) :
    ∃ turns : Int, (a * (n-1 : Nat) - b*n + 1/2).floor =
      (n : Int)*z₁ - (n-1 : Nat)*z₀ + (n : Int)*(n-1 : Nat)*turns := by
  let turns : Int := ((r₀-r₁+180)/360).floor
  refine ⟨turns, ?_⟩
  have npos : (0 : Rat) < (n : Rat) := by exact_mod_cast (show 0 < n by omega)
  have kpos : (0 : Rat) < ((n-1 : Nat) : Rat) := by exact_mod_cast (show 0 < n-1 by omega)
  have product_pos := mul_pos npos kpos
  have near : |r₀-r₁-360*(turns : Rat)| < 180 / ((n : Rat)*((n-1 : Nat) : Rat)) := by
    unfold longitudeDistance normalizeLongitude modQ at margin
    rw [absQ_eq_abs] at margin
    push_cast at margin
    convert margin using 1; dsimp [turns]; congr 1; ring
  have bounds := abs_lt.mp near
  have lower := bounds.1
  rw [← neg_div] at lower
  have low := (div_lt_iff₀ product_pos).mp lower
  have high := (lt_div_iff₀ product_pos).mp bounds.2
  have linear : (r₀-r₁-360*(turns : Rat)) * ((n : Rat)*((n-1 : Nat) : Rat)) =
      360 * (a * (n-1 : Nat) - b*n -
        (((n : Int)*z₁ - (n-1 : Nat)*z₀ + (n : Int)*(n-1 : Nat)*turns : Int) : Rat)) := by
    rw [grid₀, grid₁]
    push_cast
    field_simp
    ring
  change ⌊a * (n-1 : Nat) - b*n + 1/2⌋ = _
  apply Int.floor_eq_iff.mpr
  constructor <;> nlinarith


theorem global_longitude_grid (n : Nat) (latestOdd : Bool) (a b r₀ r₁ : Rat) (z₀ z₁ : Int)
    (npos : 0 < n)
    (grid₀ : r₀ = 360 / (max n 1 : Nat) * ((z₀ : Rat) + a))
    (grid₁ : r₁ = 360 / (max (n-1) 1 : Nat) * ((z₁ : Rat) + b))
    (margin : n = 1 ∨ longitudeDistance r₀ r₁ < 180 / ((n*(n-1) : Nat) : Rat)) :
    let m := (a * (n-1 : Nat) - b*n + 1/2).floor
    let ni := max (n - parity latestOdd) 1
    normalizeLongitude ((360 : Rat) / ni *
      (((m % (ni : Int) : Int) : Rat) + if latestOdd then b else a)) =
    normalizeLongitude (if latestOdd then r₁ else r₀) := by
  by_cases one : n = 1
  · subst n
    cases latestOdd
    · simpa [parity, grid₀] using normalize_grid_mod 1 z₀ a (by decide)
    · simpa [parity, grid₁] using normalize_grid_mod 1 z₁ b (by decide)
  · have large : 2 ≤ n := by omega
    have nmax : max n 1 = n := max_eq_left (by omega)
    have kmax : max (n-1) 1 = n-1 := max_eq_left (by omega)
    rw [nmax] at grid₀
    rw [kmax] at grid₁
    obtain ⟨turns, index⟩ := global_longitude_index n a b r₀ r₁ z₀ z₁ large
      grid₀ grid₁ (margin.resolve_left one)
    have mod₀ : ((n : Int)*z₁ - (n-1 : Nat)*z₀ + (n : Int)*(n-1 : Nat)*turns) % n =
        z₀ % n := by
      rw [show (n : Int)*z₁ - (n-1 : Nat)*z₀ + (n : Int)*(n-1 : Nat)*turns =
        z₀ + (n : Int)*(z₁-z₀+(n-1 : Nat)*turns) by
          rw [Int.natCast_sub (by omega : 1 ≤ n)]; push_cast; ring]
      exact Int.add_mul_emod_self_left _ _ _
    have mod₁ : ((n : Int)*z₁ - (n-1 : Nat)*z₀ + (n : Int)*(n-1 : Nat)*turns) % (n-1 : Nat) =
        z₁ % (n-1 : Nat) := by
      rw [show (n : Int)*z₁ - (n-1 : Nat)*z₀ + (n : Int)*(n-1 : Nat)*turns =
        z₁ + (n-1 : Nat)*(z₁-z₀+(n : Int)*turns) by
          rw [Int.natCast_sub (by omega : 1 ≤ n)]; push_cast; ring]
      exact Int.add_mul_emod_self_left _ _ _
    dsimp only
    rw [index]
    cases latestOdd
    · simp only [parity, Nat.sub_zero, nmax, Bool.false_eq_true, ↓reduceIte]
      rw [mod₀, grid₀]
      exact normalize_grid_mod n z₀ a (by exact_mod_cast ne_of_gt npos)
    · simp only [parity, kmax, ↓reduceIte]
      rw [mod₁, grid₁]
      exact normalize_grid_mod (n-1 : Nat) z₁ b (by exact_mod_cast (show n-1 ≠ 0 by omega))


theorem global_longitude_round_trip (pEven pOdd : Position) (latestOdd : Bool)
    (sameZone : nlTable (roundedLatitude .airborne false pEven.lat) =
      nlTable (roundedLatitude .airborne true pOdd.lat))
    (margin : let n := nlTable (roundedLatitude .airborne false pEven.lat)
      n = 1 ∨ longitudeDistance (roundedLongitude .airborne false pEven)
        (roundedLongitude .airborne true pOdd) < 180 / ((n*(n-1) : Nat) : Rat)) :
    let lat := if latestOdd then roundedLatitude .airborne true pOdd.lat
      else roundedLatitude .airborne false pEven.lat
    let n := nlTable lat
    let a : Rat := (encode .airborne false pEven).lon / (scale : Rat)
    let b : Rat := (encode .airborne true pOdd).lon / (scale : Rat)
    let m := (a * (n-1 : Nat) - b*n + 1/2).floor
    let ni := max (n - parity latestOdd) 1
    normalizeLongitude ((360 : Rat) / ni *
      (((m % (ni : Int) : Int) : Rat) + if latestOdd then b else a)) =
    normalizeLongitude (roundedLongitude .airborne latestOdd (if latestOdd then pOdd else pEven)) := by
  obtain ⟨z₀, grid₀⟩ := quantize_grid
    (dLon .airborne false (roundedLatitude .airborne false pEven.lat)) pEven.lon
    (ne_of_gt (dLon_pos _ _ _))
  obtain ⟨z₁, grid₁⟩ := quantize_grid
    (dLon .airborne true (roundedLatitude .airborne true pOdd.lat)) pOdd.lon
    (ne_of_gt (dLon_pos _ _ _))
  rw [← roundedLongitude_quantize] at grid₀ grid₁
  have grid₀' : roundedLongitude .airborne false pEven =
      360 / (max (nlTable (roundedLatitude .airborne false pEven.lat)) 1 : Nat) *
        ((z₀ : Rat) + ((encode .airborne false pEven).lon : Rat) / scale) := by
    simpa only [dLon, span, zones, parity, Bool.false_eq_true, ↓reduceIte, Nat.sub_zero, encode] using grid₀
  have grid₁' : roundedLongitude .airborne true pOdd =
      360 / (max (nlTable (roundedLatitude .airborne false pEven.lat)-1) 1 : Nat) *
        ((z₁ : Rat) + ((encode .airborne true pOdd).lon : Rat) / scale) := by
    simpa only [dLon, span, zones, parity, ↓reduceIte, sameZone, encode] using grid₁
  have decoded := global_longitude_grid
    (nlTable (roundedLatitude .airborne false pEven.lat)) latestOdd
    (((encode .airborne false pEven).lon : Rat) / scale)
    (((encode .airborne true pOdd).lon : Rat) / scale)
    (roundedLongitude .airborne false pEven) (roundedLongitude .airborne true pOdd)
    z₀ z₁ (nlTable_pos _) grid₀' grid₁' margin
  cases latestOdd
  · simpa only [Bool.false_eq_true, ↓reduceIte] using decoded
  · simpa only [↓reduceIte, sameZone] using decoded

end Lean1090.Proofs.CPRGlobalGeometry

namespace Lean1090.Proofs
open Spec.CPR CPRGeometry CPRGlobalGeometry

/-- Quantized global pairing reconstructs the selected report, including
circular longitude across the antimeridian and the one-zone polar case. -/
theorem CPRGlobal : Capstones.CPRGlobal := by
  intro pEven pOdd latestOdd admissible
  obtain ⟨valid₀, valid₁, latitudeMargin, sameZone, longitudeMargin⟩ := admissible
  have latitudes := globalLatitudes_round_trip pEven pOdd valid₀ valid₁ latitudeMargin
  have range₀ := roundedLatitude_range .airborne false pEven.lat valid₀.1 valid₀.2.1
  have range₁ := roundedLatitude_range .airborne true pOdd.lat valid₁.1 valid₁.2.1
  have longitude := global_longitude_round_trip pEven pOdd latestOdd sameZone longitudeMargin
  let chosen := if latestOdd then pOdd else pEven
  refine ⟨⟨roundedLatitude .airborne latestOdd chosen.lat,
    normalizeLongitude (roundedLongitude .airborne latestOdd chosen)⟩, ?_, ?_⟩
  · unfold decodeGlobal
    rw [latitudes]
    dsimp only
    have lat₀ := encodeCoordinate_lt_scale (dLat .airborne false) pEven.lat
    have lat₁ := encodeCoordinate_lt_scale (dLat .airborne true) pOdd.lat
    have lon₀ := encodeCoordinate_lt_scale
      (dLon .airborne false (roundedLatitude .airborne false pEven.lat)) pEven.lon
    have lon₁ := encodeCoordinate_lt_scale
      (dLon .airborne true (roundedLatitude .airborne true pOdd.lat)) pOdd.lon
    simp only [encode, lat₀, lat₁, lon₀, lon₁, range₀.1, range₀.2, range₁.1, range₁.2,
      sameZone, beq_self_eq_true, Bool.not_false, decide_true, Bool.and_self, ↓reduceIte]
    simp only [encode] at longitude
    rw [longitude]
    cases latestOdd <;> rfl
  · change absQ (roundedLatitude .airborne latestOdd chosen.lat - chosen.lat) ≤
        dLat .airborne latestOdd / (2*scale) ∧
      longitudeDistance (normalizeLongitude (roundedLongitude .airborne latestOdd chosen)) chosen.lon ≤
        dLon .airborne latestOdd (roundedLatitude .airborne latestOdd chosen.lat) / (2*scale)
    constructor
    · exact latitude_quantization_error _ _ _
    · rw [normalize_left_distance, roundedLongitude_quantize]
      exact longitude_quantization_error _ _ (dLon_pos _ _ _) (dLon_le_360 _ _ _)

end Lean1090.Proofs

#print axioms Lean1090.Proofs.CPRGlobal

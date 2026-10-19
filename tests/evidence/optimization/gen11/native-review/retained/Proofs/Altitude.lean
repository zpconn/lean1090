import Capstones

/-!
# Altitude capstones

Every representable altitude lies on one of two finite integer grids. The
finite identities below are evaluated by the Lean kernel, then arithmetic
places every altitude satisfying the frozen domains on those grids. Receiver
plausibility limits do not restrict these proofs.
-/

set_option maxRecDepth 100000
set_option maxHeartbeats 0

namespace Lean1090.Proofs
open Spec

private theorem binary25_grid : ∀ n : Fin 2048,
    let height : Int := 25 * n.val - 1000
    (Altitude.encode25AC13 height).bind Altitude.decodeAC13 = some (.feet height) ∧
    (Altitude.encodeFeetAC12 .binary25 height).bind Altitude.decodeAC12 = some height := by
  decide +kernel

private theorem gillham_grid : ∀ n : Fin 1280,
    let height : Int := 100 * n.val - 1200
    (Altitude.encodeGillham height).bind Altitude.decodeGillham = some height ∧
    (Altitude.encodeFeetAC12 .gillham100 height).bind Altitude.decodeAC12 = some height := by
  decide +kernel

private theorem bind_some_witness {α β : Type} (input : Option α)
    (decode : α → Option β) (value : β) (h : input.bind decode = some value) :
    ∃ code, input = some code ∧ decode code = some value := by
  cases input with
  | none => simp at h
  | some code => exact ⟨code, rfl, h⟩

/-- Both AC13 and AC12 round-trip on the entire mathematical altitude domain. -/
theorem AltitudeRoundTrips : Capstones.AltitudeRoundTrips := by
  constructor
  · intro height admissible
    obtain ⟨lower, upper, divisible⟩ := admissible
    let n : Nat := ((height + 1000) / 25).toNat
    have hn : n < 2048 := by dsimp [n]; omega
    have height_grid : height = 25 * (n : Int) - 1000 := by dsimp [n]; omega
    obtain ⟨ac13, ac12⟩ := binary25_grid ⟨n, hn⟩
    simp only [height_grid] at *
    exact ⟨bind_some_witness _ _ _ ac13, bind_some_witness _ _ _ ac12⟩
  · intro height admissible
    obtain ⟨lower, upper, divisible⟩ := admissible
    let n : Nat := ((height + 1200) / 100).toNat
    have hn : n < 1280 := by dsimp [n]; omega
    have height_grid : height = 100 * (n : Int) - 1200 := by dsimp [n]; omega
    obtain ⟨ac13, ac12⟩ := gillham_grid ⟨n, hn⟩
    simp only [height_grid] at *
    exact ⟨bind_some_witness _ _ _ ac13, bind_some_witness _ _ _ ac12⟩

/-- Invalid Gillham symbols and every out-of-domain altitude are rejected. -/
theorem AltitudeRejection : Capstones.AltitudeRejection := by
  refine ⟨?_, ?_, ?_⟩
  · intro word invalid
    simp [Altitude.decodeGillham, invalid]
  · intro height invalid
    simpa [Altitude.encode25AC13, Altitude.Representable25] using invalid
  · intro height invalid
    simpa [Altitude.encodeGillham, Altitude.RepresentableGillham] using invalid

#print axioms AltitudeRoundTrips
#print axioms AltitudeRejection

end Lean1090.Proofs

import Proofs.BitPacking
import Spec.Message

/-! Kernel-exhaustive equivalence of two independent altitude interpretations
on their complete finite code domains. -/
namespace Lean1090.Proofs.Assignment
open Spec

theorem altitude13_eq (code : Nat) (bound : code < 8192) :
    Spec.Assignment.altitude13 code = Altitude.decodeAC13 code := by
  have all : (List.range 8192).all (fun c =>
      decide (Spec.Assignment.altitude13 c = Altitude.decodeAC13 c)) = true := by decide +kernel
  exact of_decide_eq_true (List.all_eq_true.mp all code (List.mem_range.mpr bound))

theorem compatibility13_eq (code : Nat) (bound : code < 8192) :
    Spec.Assignment.compatibility13 code = Altitude.oracleAC13 code := by
  have all : (List.range 8192).all (fun c =>
      decide (Spec.Assignment.compatibility13 c = Altitude.oracleAC13 c)) = true := by decide +kernel
  exact of_decide_eq_true (List.all_eq_true.mp all code (List.mem_range.mpr bound))

theorem altitude12_eq (code : Nat) (bound : code < 4096) :
    Spec.Assignment.altitude12 code = Altitude.decodeAC12 code ∧
    Spec.Assignment.compatibility12 code = (Altitude.oracleAC12 code).join := by
  have all : (List.range 4096).all (fun c =>
      decide (Spec.Assignment.altitude12 c = Altitude.decodeAC12 c ∧
        Spec.Assignment.compatibility12 c = (Altitude.oracleAC12 c).join)) = true := by decide +kernel
  exact of_decide_eq_true (List.all_eq_true.mp all code (List.mem_range.mpr bound))

theorem gillham_eq (code : Nat) (bound : code < 8192) :
    Spec.Assignment.gillhamHeight code = Altitude.decodeGillham code := by
  have all : (List.range 8192).all (fun c =>
      decide (Spec.Assignment.gillhamHeight c = Altitude.decodeGillham c)) = true := by decide +kernel
  exact of_decide_eq_true (List.all_eq_true.mp all code (List.mem_range.mpr bound))

end Lean1090.Proofs.Assignment

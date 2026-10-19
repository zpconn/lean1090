import Proofs.Assignment
import Proofs.FrameRoundTrips

/-! Complete messages preserve both their independently assigned meaning and
all transmitted bits. Semantic agreement is proved, never required as input. -/
namespace Lean1090.Proofs
open Spec

theorem MessageRoundTrips : Capstones.MessageRoundTrips := by
  constructor
  · intro fields valid
    unfold Spec.decode
    rw [FrameRoundTrip.decode_encode]
    simp only [bind, Option.bind_some]
    have accepted : frameAccepted fields = true := valid
    simp only [accepted, ite_true, Spec.assigned]
    rw [Assignment.expected_report_eq]
  · intro bytes message decoded
    unfold Spec.decode at decoded
    cases parsed : decodeFrame bytes with
    | none => simp [parsed] at decoded
    | some frame =>
      simp only [parsed, bind, Option.bind_some] at decoded
      split at decoded
      · have equal := Option.some.inj decoded
        subst message
        exact FrameRoundTrip.encode_decode bytes frame parsed
      · contradiction

#print axioms MessageRoundTrips
end Lean1090.Proofs

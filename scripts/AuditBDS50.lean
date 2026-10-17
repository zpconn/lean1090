/-! Import-free pilot proof audit, compiled by scripts/check_pilot.py after
the integration imports. No frozen Lean source imports Impl or Proofs. -/

namespace Lean1090.PilotAudit

theorem fullRefinement : Capstones.BDS50Refinement Impl.BDS50.decode :=
  Proofs.BDS50.refinement
#print axioms fullRefinement
#print axioms Proofs.BDS50.pilot_nonvacuous
#print axioms Proofs.BDS50.exact_threshold_nonvacuous

end Lean1090.PilotAudit

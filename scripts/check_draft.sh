#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
if [[ -f spec.lock ]]; then python3 scripts/check_lock.py; fi
python3 scripts/audit_source.py
lake build
lake build Proofs.BDS50 bds50Pilot
python3 scripts/check_impl_imports.py
lake env lean scripts/CheckHypotheses.lean
lake env lean scripts/CheckReceiverPolicy.lean
lake env lean scripts/CheckAssignment.lean
python3 scripts/check_pilot.py
python3 scripts/check_witness_axioms.py
lake env lean --run scripts/PayloadExamples.lean
lake env lean --run scripts/AltitudeCPRExamples.lean
lake env lean bench/evidence/SemanticProbes.lean
python3 scripts/check_documents.py
printf '%s\n' 'Amended checkpoint and BDS50 pilot checks pass. This is not the final project gate.'

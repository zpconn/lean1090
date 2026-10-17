#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
python3 scripts/check_lock.py
mode=${1:---quick}
case "$mode" in --quick) generated=100000;; --full) generated=10000000;;
  *) printf '%s\n' 'usage: scripts/check_all.sh [--quick|--full]' >&2; exit 2;;
esac
python3 scripts/audit_source.py
lake build
python3 scripts/check_impl_imports.py
# Fail early if a required final proof is absent; a draft check is no substitute.
python3 scripts/check_final.py
lake env lean scripts/CheckHypotheses.lean
lake env lean scripts/CheckReceiverPolicy.lean
lake env lean scripts/CheckAssignment.lean
python3 scripts/check_witness_axioms.py
for required in scripts/run_unit_tests.sh scripts/run_differential.sh; do
  if [[ ! -x "$required" ]]; then
    printf 'FAIL: required section-4 gate component absent: %s\n' "$required" >&2
    exit 1
  fi
done
scripts/run_unit_tests.sh
# Keep the targeted stratum mandatory even if uniform random inputs all reject.
mkdir -p .cache/gate
lake env lean --run scripts/FuzzCommB.lean .cache/gate/commb.csv 100000 1085632
python3 scripts/check_commb_fuzz.py .cache/gate/commb.csv
# Includes the corpus and scripts/FuzzCommB.lean's structured boundary strata.
scripts/run_differential.sh --corpus --generated "$generated" --commb-boundaries .cache/gate/commb.csv

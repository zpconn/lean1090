#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

# Every complete quick/full invocation runs all mandatory strata. Diagnostic
# mode accumulates failures across strata and exits nonzero only at the end.
# Component-only modes never claim a complete gate pass.
cpr_only=false
altitude_only=false
reserved_only=false
dte_only=false
diagnostic=false
corpus=false
generated=100000
commb_boundaries=
while (($#)); do
  case "$1" in
    --cpr-only) cpr_only=true; shift;;
    --altitude-only) altitude_only=true; shift;;
    --reserved-velocity-only) reserved_only=true; shift;;
    --dte-only) dte_only=true; shift;;
    --diagnostic) diagnostic=true; shift;;
    --corpus) corpus=true; shift;;
    --generated)
      [[ $# -ge 2 ]] || { echo 'missing --generated value' >&2; exit 2; }
      generated=$2; shift 2;;
    --commb-boundaries)
      [[ $# -ge 2 ]] || { echo 'missing --commb-boundaries path' >&2; exit 2; }
      commb_boundaries=$2; shift 2;;
    *) echo "unknown differential argument: $1" >&2; exit 2;;
  esac
done
[[ "$generated" =~ ^[0-9]+$ ]] || { echo 'generated count must be a natural number' >&2; exit 2; }
components=0
for flag in "$cpr_only" "$altitude_only" "$reserved_only" "$dte_only"; do
  if "$flag"; then components=$((components + 1)); fi
done
if ((components > 1)); then
  echo 'choose only one differential component mode' >&2
  exit 2
fi
python3 scripts/check_lock.py
mode=--quick
if ((generated > 100000)); then mode=--full; fi
if "$cpr_only"; then
  python3 scripts/check_cpr_differential.py "$mode"
  echo 'CPR stratum passed; whole-message differential suite was not requested.'
  exit 0
fi
if "$altitude_only"; then
  python3 scripts/check_altitude_differential.py
  echo 'Exhaustive altitude stratum passed; whole-message differential suite was not requested.'
  exit 0
fi
if "$reserved_only"; then
  python3 scripts/check_reserved_velocity_differential.py
  echo 'Reserved velocity stratum passed; whole-message differential suite was not requested.'
  exit 0
fi
if "$dte_only"; then
  python3 scripts/check_dte_differential.py
  echo 'Exhaustive DTE stratum passed; whole-message differential suite was not requested.'
  exit 0
fi
if ! "$corpus" || ((generated < 100000)) || [[ ! -f "$commb_boundaries" ]]; then
  echo 'FAIL: complete differential suite requires --corpus, at least 100000 generated messages, and an existing --commb-boundaries file.' >&2
  exit 1
fi
mkdir -p tests/evidence/differential-campaign
status_file=tests/evidence/differential-campaign/components.tsv
printf 'component\texit_code\n' > "$status_file"
failed=false
run_component() {
  local name=$1
  shift
  local result=0
  "$@" || result=$?
  printf '%s\t%s\n' "$name" "$result" >> "$status_file"
  if ((result != 0)); then
    failed=true
    if ! "$diagnostic"; then exit "$result"; fi
  fi
}
run_component altitude python3 scripts/check_altitude_differential.py
run_component reserved_velocity python3 scripts/check_reserved_velocity_differential.py
run_component dte python3 scripts/check_dte_differential.py
run_component numeric python3 scripts/check_numeric.py
run_component cpr python3 scripts/check_cpr_differential.py "$mode"
run_component tracking python3 scripts/check_tracking.py --diagnostic
message_args=(--corpus --generated "$generated" --commb-boundaries "$commb_boundaries")
if "$diagnostic"; then message_args+=(--diagnostic); fi
run_component message python3 scripts/check_message_differential.py "${message_args[@]}"
cat "$status_file"
if "$failed"; then
  echo 'FAIL: differential campaign completed with findings; retained component evidence lists every mismatch.' >&2
  exit 1
fi
echo 'Complete differential campaign passed all mandatory strata.'

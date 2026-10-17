#!/usr/bin/env bash
set -euo pipefail
project_root=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
cd "$project_root"
mode=${1:---check}
case "$mode" in --check|--worker-decode|--worker-cpr|--probe-formats|--probe-cpr|--probe-hex|--build-only) ;; *) echo "usage: $0 --check|--worker-decode|--worker-cpr|--probe-formats|--probe-cpr|--probe-hex HEX|--build-only" >&2; exit 2;; esac
if [[ "$mode" == --probe-hex && $# -ne 2 ]] || [[ "$mode" != --probe-hex && $# -gt 1 ]]; then
    echo "invalid argument count" >&2; exit 2
fi
oracle_commit=685dfaa34c5ab186c691bca3cfe2a22e12517d30
[[ $(git -C vendor/rs1090 rev-parse HEAD) == "$oracle_commit" ]]
[[ -z $(git -C vendor/rs1090 status --porcelain --untracked-files=no) ]]
python3 - <<'PY'
from pathlib import Path
import hashlib
p = Path('vendor/rs1090/crates/rs1090/data/long_flight.csv')
b = p.read_bytes()
assert hashlib.sha256(b).hexdigest() == '3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505'
assert len(b.splitlines()) == 172432
PY
env -u RUSTFLAGS -u CARGO_ENCODED_RUSTFLAGS \
    CARGO_HOME="$project_root/.cache/cargo" \
    CARGO_TARGET_DIR="$project_root/.cache/rs1090-target" \
    cargo build --locked --manifest-path bench/oracle/Cargo.toml --profile dist
[[ "$mode" == --build-only ]] && exit 0
python3 - "$mode" "${2:-}" <<'PY'
import os
from pathlib import Path
import sys
mode = sys.argv[1]
if hasattr(os, 'sched_getaffinity'):
    allowed = sorted(os.sched_getaffinity(0))
    cpu = int(os.environ.get('BENCH_CPU', allowed[0]))
    if cpu not in allowed:
        raise SystemExit(f'BENCH_CPU={cpu} not in allowed CPU set {allowed}')
    os.sched_setaffinity(0, {cpu})
    print(f'oracle affinity CPU={cpu}', file=sys.stderr, flush=True)
else:
    print('oracle affinity unavailable on this OS', file=sys.stderr, flush=True)
binary = str(Path('.cache/rs1090-target/dist/lean1090-oracle-bench').resolve())
args = [binary, mode]
if mode == '--probe-hex':
    args.append(sys.argv[2])
elif mode not in ('--probe-formats', '--probe-cpr'):
    args.append('vendor/rs1090/crates/rs1090/data/long_flight.csv')
os.execv(binary, args)
PY

"""The complete checkpoint lock inventory; does not create or update a lock."""
from pathlib import Path

def frozen_paths():
    paths = [path for root in (Path('Spec'), Path('Model'))
             for path in root.rglob('*') if path.is_file()]
    paths += [Path(p) for p in (
        'Spec.lean', 'Model.lean', 'Capstones.lean', 'bench/BENCHMARK.md',
        'scripts/Final.lean', 'scripts/CheckHypotheses.lean',
        'scripts/check_impl_imports.py', 'scripts/check_final.py',
        'scripts/check_lock.py', 'scripts/frozen_paths.py',
        'scripts/CheckReceiverPolicy.lean', 'scripts/FuzzCommB.lean',
        'scripts/CheckAssignment.lean', 'scripts/test_lock.py',
        'scripts/check_commb_fuzz.py',
        'scripts/bench_bds50.py', 'scripts/FuzzBDS50.lean',
        'scripts/audit_source.py', 'scripts/check_witness_axioms.py',
        'scripts/AuditWitnesses.lean', 'scripts/AuditBDS50.lean',
        'scripts/check_pilot.py', 'scripts/compile_fragment.py',
        'scripts/check_all.sh', 'scripts/check_draft.sh', 'scripts/check_documents.py',
        'bench/oracle/Cargo.toml', 'bench/oracle/Cargo.lock', 'bench/oracle/src/main.rs',
        'bench/run_oracle.sh', 'bench/interleave.py',
        'bench/bds50/Cargo.toml', 'bench/bds50/Cargo.lock', 'bench/bds50/src/main.rs',
    )]
    return sorted(set(paths))

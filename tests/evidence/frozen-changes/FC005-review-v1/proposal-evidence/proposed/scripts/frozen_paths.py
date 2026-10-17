"""The complete checkpoint lock inventory; does not create or update a lock."""
from pathlib import Path

def frozen_paths():
    paths = [path for root in (Path('Spec'), Path('Model'))
             for path in root.rglob('*') if path.is_file()]
    # Freeze membership as well as content: newly added suite members require
    # their own approved lock entries, including new oracle helper sources.
    paths += list(Path('scripts').glob('check_*_differential.py'))
    paths += list(Path('scripts').glob('Fuzz*.lean'))
    paths += list(Path('Tests').glob('*Differential.lean'))
    paths += list(Path('Tests').glob('*Generator.lean'))
    for root in ('differential/message-oracle/src', 'differential/cpr-oracle/src',
                 'differential/tracking-oracle/src'):
        paths += list(Path(root).rglob('*.rs'))
    paths += list(Path('review/upstream-units').glob('*.py'))
    paths += [Path(p) for p in (
        'Tests/Tracking.lean',
        'Tests/Upstream.lean',
        'Tests/UpstreamCorpus.lean',
        'differential/tracking-oracle/Cargo.lock',
        'differential/tracking-oracle/Cargo.toml',
        'differential/tracking-oracle/src/main.rs',
        'review/upstream-units/assemble.py',
        'review/upstream-units/inventory.py',
        'review/upstream-units/manual.py',
        'review/upstream-units/port.py',
        'review/upstream-units/run.py',
        'review/upstream-units/run_corpus.py',
        'review/upstream-units/rust_port.py',
        'scripts/check_tracking.py',
        'scripts/generate_tracking.py',
        'scripts/run_unit_tests.sh',

        'scripts/run_differential.sh', 'scripts/check_numeric.py',
        'scripts/check_altitude_differential.py', 'scripts/check_cpr_differential.py',
        'scripts/check_dte_differential.py', 'scripts/check_message_differential.py',
        'scripts/check_reserved_velocity_differential.py', 'scripts/FuzzCPR.lean',
        'Tests/AltitudeDifferential.lean', 'Tests/CommBDifferential.lean',
        'Tests/DTEDifferential.lean', 'Tests/ReservedVelocityDifferential.lean',
        'Tests/MessageGenerator.lean', 'Tests/Numeric.lean', 'tests/numeric_oracle.rs',
        'differential/message-oracle/Cargo.toml', 'differential/message-oracle/Cargo.lock',
        'differential/message-oracle/src/main.rs', 'differential/message-oracle/src/commb.rs',
        'differential/cpr-oracle/Cargo.toml', 'differential/cpr-oracle/Cargo.lock',
        'differential/cpr-oracle/src/main.rs',
        'lakefile.toml', 'lean-toolchain', 'lake-manifest.json',
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

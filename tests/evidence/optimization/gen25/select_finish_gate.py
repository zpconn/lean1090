#!/usr/bin/env python3
"""Select only completed gen25 scratch; archive/cleanup needs explicit --execute.

The caller attests that fixed/fresh producers have stopped. Selection metadata
never authorizes deletion itself: the unchanged wrapper verifies retained bytes.
"""
import sys
sys.dont_write_bytecode = True
import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import stat
import subprocess

ROOT = Path(__file__).resolve().parents[4]
BASE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / 'review/diagnostics'))
import cleanup_verified_scratch as clean
import run_generation_benchmark as provenance
PREFIXES = {'altitude': 'altitude-exhaustive-', 'reserved_velocity': 'reserved-velocity-',
            'dte': 'dte-exhaustive-', 'cpr': 'cpr-synthetic-', 'message': 'message-differential-'}
HELPERS = {
    'review/diagnostics/finish_generation_gate.py': 'b92cf9198a28167d171909a7b4b4137be2e9084fee56c9b61e7f4b1c45d32963',
    'review/diagnostics/archive_generation_gate.py': 'cbdee009df5943250ab24a4cd9f712c27b3c76e08ced20046714e5733f00577e',
    'review/diagnostics/cleanup_verified_scratch.py': 'cb115045f0743cce197d1d9af1d66678dd76a9a96b1babb5eca4d3d519dc31ce'}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load(path):
    return json.loads(Path(path).read_text())


def rel(path):
    return str(path.relative_to(ROOT))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--quiescent-note', required=True)
    parser.add_argument('--execute', action='store_true')
    args = parser.parse_args()
    assert args.quiescent_note.strip()
    gate_path, log = BASE / 'gate-evidence.json', BASE / 'gate-full.log'
    gate = load(gate_path)
    inputs = provenance.gate_input_hashes()
    assert len(inputs) == 202
    provenance.verify_gate_evidence(gate, sha(log), inputs)
    fresh_path = BASE / 'independent-review/fresh-completion.json'
    fresh = load(fresh_path)
    assert fresh['status'] == 'passed' and fresh['source_count'] == 127
    assert fresh['binary_count'] == 3 and fresh['retained_members'] == 33
    assert fresh['full_coverage_reproduced'] and fresh['decompressed_diagnostic_streams_reproduced']
    assert fresh['source_and_binary_hashes_rechecked_after_cleanup'] and fresh['native_held_inputs_rechecked']
    fresh_root = clean.local(fresh['raw_scratch_deleted'])
    assert fresh_root.parent == ROOT / '.cache' and clean.SCRATCH.fullmatch(fresh_root.name)
    assert fresh_root.name.startswith(PREFIXES['message']) and not fresh_root.exists()
    protected_paths = [ROOT / '.cache/reserved-velocity-proposal', ROOT / '.cache/gen15-interrupted-gate', fresh_root]
    protected = {rel(p): {'exists': clean.local(p).exists()} for p in protected_paths}
    assert all(protected[rel(p)]['exists'] for p in protected_paths[:2])
    for name, digest in HELPERS.items():
        assert sha(ROOT / name) == digest, name
    start, end = (datetime.fromisoformat(gate[k]).timestamp() for k in ('started_at', 'finished_at'))
    assert start <= end
    cache = clean.local(ROOT / '.cache')
    inventory, candidates = [], {name: [] for name in PREFIXES}
    for path in sorted(cache.iterdir()):
        component = next((name for name, prefix in PREFIXES.items() if path.name.startswith(prefix)), None)
        if component is None:
            continue
        st = path.lstat()
        birth = int(subprocess.check_output(['stat', '-c', '%W', '--', str(path)], text=True).strip())
        within = birth > 0 and start <= birth <= end and start <= st.st_mtime <= end
        row = dict(path=rel(path), prefix=PREFIXES[component], mode=st.st_mode, device=st.st_dev,
                   inode=st.st_ino, birth_seconds=birth, mtime_ns=st.st_mtime_ns,
                   ctime_ns=st.st_ctime_ns, within_gate_interval=within)
        if within and path not in protected_paths and clean.SCRATCH.fullmatch(path.name):
            clean.local(path)
            assert stat.S_ISDIR(st.st_mode), path
            members = {}
            for child in sorted(path.iterdir()):
                identity = clean.identity(child)
                assert identity['links'] == 1, child
                members[child.name] = {key: identity[key] for key in ('bytes', 'inode', 'mtime_ns', 'allocated_bytes')}
            assert members, path
            row['members'] = members
            candidates[component].append(rel(path))
        inventory.append(row)
    assert all(len(paths) == 1 for paths in candidates.values()), candidates
    selected = {name: paths[0] for name, paths in candidates.items()}
    assert selected['message'] == fresh['fixed_gate_scratch_preserved']
    command = ['python3', '-B', 'review/diagnostics/finish_generation_gate.py', '--generation', '25',
               '--gate-evidence', rel(gate_path), '--gate-log', rel(log),
               '--receipt', rel(BASE / 'post-gate-archive-cleanup'), '--apply', '--quiescent']
    for name in PREFIXES:
        command += ['--scratch', selected[name]]
    command += ['--archive-root', '.cache/gen25-gate/fixed-message-archive']
    for name in PREFIXES:
        if name != 'message':
            command += ['--archive-root', '.cache/gen25-gate/component-archives/' + name]
    for path in protected_paths:
        command += ['--protect', rel(path)]
    record = dict(status='prepared_exact_selection_after_gate_pass', recorded_utc=datetime.now(timezone.utc).isoformat(),
        gate_evidence_sha256=sha(gate_path), gate_log_sha256=sha(log),
        gate_interval=[gate['started_at'], gate['finished_at']],
        discovery_scope='Single nonrecursive .cache inventory restricted to five approved prefixes; unique approved temporary names with birthtime and mtime inside the passed gate interval. Fresh and historical roots are protected.',
        inventory=inventory, selected=selected, protected=protected,
        fresh_completion_sha256=sha(fresh_path), quiescence=args.quiescent_note,
        command=command, helper_hashes=HELPERS,
        deletion_requirement='Unchanged wrapper archives and flushes first, then verifies every selected raw byte against sealed gzip counterparts before any unlink; unmatched directories remain.',
        selector_sha256=sha(__file__))
    selection_path = BASE / 'gate-cleanup-selection.json'
    if selection_path.exists():
        prior = load(selection_path)
        for key in record.keys() - {'recorded_utc', 'quiescence'}:
            assert record[key] == prior[key], key
    else:
        clean.durable(selection_path, record)
    if not args.execute:
        print(json.dumps({'status': 'selection_only_no_archive_or_cleanup', 'selection_sha256': sha(selection_path), 'command': command}))
        return
    assert not (BASE / 'post-gate-archive-cleanup').exists(), 'Preserve any previous wrapper attempt.'
    assert provenance.gate_input_hashes() == inputs
    with (BASE / 'gate-archive-cleanup.stdout').open('x') as out, (BASE / 'gate-archive-cleanup.stderr').open('x') as err:
        result = subprocess.run(command, cwd=ROOT, env=dict(os.environ, PYTHONDONTWRITEBYTECODE='1'), stdout=out, stderr=err)
        out.flush(); os.fsync(out.fileno())
        err.flush(); os.fsync(err.fileno())
    clean.durable(BASE / 'gate-archive-cleanup-execution.json', dict(command=command, exit_code=result.returncode,
        selection_sha256=sha(selection_path), stdout_sha256=sha(BASE / 'gate-archive-cleanup.stdout'),
        stderr_sha256=sha(BASE / 'gate-archive-cleanup.stderr'), controller_sha256=sha(__file__)))
    raise SystemExit(result.returncode)


if __name__ == '__main__':
    main()

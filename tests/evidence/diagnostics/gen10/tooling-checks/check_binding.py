#!/usr/bin/env python3
"""Read-only positive/negative provenance checks; no native execution."""
import copy
import hashlib
import json
from pathlib import Path
import sys
from unittest.mock import patch
sys.path.insert(0, str(Path('review/diagnostics').resolve()))
import bind_benchmark_history as b

args = [Path('.cache/gen10-costs/driver/driver-build.json'), Path('bench/runs/gen10/summary.json'),
        Path('tests/evidence/publication/attribution-rewrite/history.json'), Path('bench/runs/gen10/correctness-inputs.json')]
original_read, original_sha, original_inventory = b.read, b.sha, b.gate_input_hashes
expected = original_read('tests/evidence/diagnostics/gen10/benchmark-source-binding.json')
assert b.inspect(*args) == expected
checks = ['unchanged_original_mapped_current_binding']

def reject(label, target, change):
    def altered(path):
        value = copy.deepcopy(original_read(path))
        if Path(path) == args[target]: change(value)
        return value
    with patch.object(b, 'read', altered):
        try: b.inspect(*args)
        except (AssertionError, RuntimeError, KeyError): checks.append(label)
        else: raise AssertionError('accepted invalid binding: ' + label)

reject('reject_unknown_original_commit', 1, lambda d: d.update(commit='0'*40))
reject('reject_changed_original_raw_header', 2, lambda d: next(r for r in d['commits'] if r['old']==expected['timed_original_commit']).update(raw_commit='changed'))
reject('reject_changed_mapped_tree', 2, lambda d: next(r for r in d['commits'] if r['old']==expected['timed_original_commit']).update(tree='0'*40))
reject('reject_missing_audited_proof', 3, lambda d: d.pop('Proofs/Decoder.lean'))
reject('reject_linked_source_digest_mismatch', 0, lambda d: d['linked_project_inventory']['sources'].update({'Impl/Bits.lean': '0'*64}))
reject('reject_wrong_worker_digest', 1, lambda d: d.update(binary_sha256='0'*64))
for label, name in [('reject_changed_working_source', 'Impl/Bits.lean'), ('reject_changed_worker_bytes', '.lake/build/bin/lean1090-bench')]:
    with patch.object(b, 'sha', lambda path: '0'*64 if str(path)==name else original_sha(path)):
        try: b.inspect(*args)
        except AssertionError: checks.append(label)
        else: raise AssertionError(label)
with patch.object(b, 'gate_input_hashes', lambda: {**original_inventory(), 'Proofs/Unrecorded.lean':'0'*64}):
    try: b.inspect(*args)
    except AssertionError: checks.append('reject_new_audited_module')
    else: raise AssertionError('accepted added proof module')
record = {'status':'passed','checks':checks,'count':len(checks),
          'method':'Original live metadata inspected read-only; negative controls patch only in-memory return values.',
          'binder_sha256': original_sha('review/diagnostics/bind_benchmark_history.py'),
          'renderer_sha256': original_sha('review/diagnostics/write_cost_report.py'),
          'archiver_sha256': original_sha('review/diagnostics/archive_cost_campaign.py'),
          'binding_sha256': original_sha('tests/evidence/diagnostics/gen10/benchmark-source-binding.json')}
out = Path('tests/evidence/diagnostics/gen10/tooling-checks/binding-checks.json')
assert not out.exists()
out.write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(record))

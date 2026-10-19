#!/usr/bin/env python3
"""Seal an already passed independent gen15 retention review; never run decoders."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
import hashlib
import json

B = Path('tests/evidence/optimization/gen15')
R = B / 'fresh-independent-review'
def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(4 * 1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()
def load(path):
    return json.loads(Path(path).read_text())

assert not (R / 'completion.json').exists()
review = load(R / 'fresh-retention-review.json')
assert review['status'] == 'passed_fresh_retention_and_source_binding' and not review['findings']
assert review['script_sha256'] == sha(R / 'check_retention.py')
log = load(R / 'review-01.log')
assert log['sha256'] == sha(R / 'fresh-retention-review.json') and log['status'] == review['status']
held = load(B / 'gate-evidence.json')['input_hashes_before']
assert len(held) == 186 and all(sha(path) == digest for path, digest in held.items())
inspection = load(B / 'native-review/inspection-inputs.json')
native = {path: row['sha256'] for path, row in inspection['inputs'].items()}
assert len(native) == 144 and all(sha(path) == digest for path, digest in native.items())
files = {str(path.relative_to(R)): {'sha256': sha(path), 'bytes': path.stat().st_size}
         for path in sorted(R.rglob('*')) if path.is_file()}
assert not any('__pycache__' in path for path in files)
result = {
    'status': 'passed', 'findings': [],
    'review_sha256': sha(R / 'fresh-retention-review.json'),
    'script_sha256': sha(R / 'check_retention.py'),
    'files': files,
    'retained_reviewer_attempts': [{'attempt': 1, 'status': 'passed', 'script': 'check_retention.py', 'log': 'review-01.log'}],
    'held_inputs_unchanged_after_independent_replay': len(held), 'held_input_hashes': held,
    'native_inputs_unchanged_after_independent_replay': len(native), 'native_input_hashes': native,
    'scope': 'Independent fresh retained-evidence replay only; fixed full gate and its archive are reviewed separately.',
    'bytecode_policy': 'PYTHONDONTWRITEBYTECODE=1 and python3 -B at process start; sys.dont_write_bytecode before imports.'
}
(R / 'completion.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'completion_sha256': sha(R / 'completion.json'), 'review_sha256': result['review_sha256'], 'files': len(files), 'held_inputs': len(held), 'native_inputs': len(native)}))

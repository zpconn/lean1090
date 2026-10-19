#!/usr/bin/env python3
"""Retain the original presentation seal and check a later authorized docs edit."""
import sys
sys.dont_write_bytecode = True
import hashlib
import json
import os
import shutil
import subprocess
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
E = Path(__file__).resolve().parent
S = E / 'after-docs'
os.environ['PYTHONDONTWRITEBYTECODE'] = '1'

def sha(p):
    with Path(p).open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()

def read(p):
    return json.loads(Path(p).read_text())

def rel(p):
    return str(p.relative_to(ROOT))

def save(p, value):
    with p.open('x') as f:
        json.dump(value, f, indent=2)
        f.write('\n')

assert not S.exists()
S.mkdir()
(S / 'original').mkdir()
original_names = ['readme-verification.json', 'completion.json', 'seal_presentation.py',
                  'seal.stdout', 'seal.stderr', 'readme.stdout', 'readme.stderr',
                  'check_presentation.py', 'execution.json']
original_hashes = {rel(E / name): sha(E / name) for name in original_names}
for name in original_names:
    shutil.copyfile(E / name, S / 'original' / name)
    assert sha(S / 'original' / name) == original_hashes[rel(E / name)]
original = read(E / 'completion.json')
assert original['status'] == 'passed'
for name, digest in original['outputs'].items():
    assert sha(ROOT / name) == digest, name
previous = read(E / 'readme-verification.json')
current_inputs = {name: sha(ROOT / name) for name in previous['inputs']}
changed = {name: {'sealed_sha256': digest, 'current_sha256': current_inputs[name]}
           for name, digest in previous['inputs'].items() if digest != current_inputs[name]}
assert set(changed) == {'docs/OPTIMIZATION.md'}, changed
shutil.copyfile(ROOT / 'docs/OPTIMIZATION.md', S / 'OPTIMIZATION-current.md')
target = E / 'readme-verification-after-docs.json'
assert not target.exists()
argv = [sys.executable, '-B', rel(E / 'check_presentation.py'), '--generation', '22',
        '--output', rel(target)]
started = datetime.now(timezone.utc).isoformat()
save(S / 'before.json', {'status': 'verification_pending', 'original_files': original_hashes,
                       'authorized_document_update': changed, 'argv': argv,
                       'script_sha256': sha(__file__), 'started_utc': started})
with (E / 'readme-after-docs.stdout').open('x') as out, (E / 'readme-after-docs.stderr').open('x') as err:
    result = subprocess.run(argv, cwd=ROOT, stdout=out, stderr=err)
command = {'argv': argv, 'started_utc': started, 'finished_utc': datetime.now(timezone.utc).isoformat(),
           'exit_code': result.returncode, 'stdout_sha256': sha(E / 'readme-after-docs.stdout'),
           'stderr_sha256': sha(E / 'readme-after-docs.stderr')}
save(S / 'command.json', command)
assert result.returncode == 0
after = read(target)
assert after['status'] == 'passed' and not after['findings'] and all(after['checks'].values())
assert after['inputs'] == current_inputs
assert after['capstones'] == previous['capstones']
assert after['measurements'] == previous['measurements']
assert after['campaign_counts'] == previous['campaign_counts']
assert len(after['checks']) == 32 and len(after['capstones']) == 23
assert all(link['valid'] for link in after['local_links'])
for name, digest in original_hashes.items():
    assert sha(ROOT / name) == digest, name
for name, digest in original['outputs'].items():
    assert sha(ROOT / name) == digest, name
assert sha(ROOT / 'docs/OPTIMIZATION.md') == sha(S / 'OPTIMIZATION-current.md')
record = {'status': 'passed', 'generation': 22, 'original_completion_sha256': sha(E / 'completion.json'),
          'original_readme_verification_sha256': sha(E / 'readme-verification.json'),
          'authorized_document_update': changed, 'current_input_map': after['inputs'],
          'new_readme_verification': rel(target), 'new_readme_verification_sha256': sha(target),
          'command': command, 'checks': len(after['checks']), 'local_links': len(after['local_links']),
          'capstones_verbatim': True, 'measurements_and_campaign_counts_unchanged': True,
          'original_seals_sources_logs_and_all_presentation_outputs_unchanged': True,
          'scope': 'Parent confirmed authorized optimization-document status/link update after the original seal. Only the existing packaging checker ran; no render, visual change, decoder, proof, benchmark or profiler ran.',
          'files': {rel(p): sha(p) for p in sorted(S.rglob('*')) if p.is_file()}}
save(E / 'after-docs-supplement.json', record)
print(json.dumps({'status': 'passed', 'supplement_sha256': sha(E / 'after-docs-supplement.json'),
                  'updated_check_sha256': sha(target), 'changed': changed}))

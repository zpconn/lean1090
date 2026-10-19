#!/usr/bin/env python3
"""Seal completed gen22 presentation and recorded visual inspection only."""
import sys
sys.dont_write_bytecode = True
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
E = Path(__file__).resolve().parent

def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()

def load(path):
    return json.loads(Path(path).read_text())

def save(path, value):
    with path.open('x') as stream:
        stream.write(json.dumps(value, indent=2) + '\n')

execution = load(E / 'execution.json')
verification = load(E / 'verification.json')
readme = load(E / 'readme-verification.json')
assert execution['status'] == verification['status'] == readme['status'] == 'passed'
assert execution['review_sha256'] == sha(ROOT / 'bench/runs/gen22/results-review.json')
assert execution['all_held_inputs_unchanged'] and execution['capstone_section_unchanged']
assert all(readme['checks'].values()) and not readme['findings']
assert verification['source_rows'] == 46 and verification['frames'] == 23
assert verification['plotted_values_checked'] == 1104
assert len(readme['checks']) == 32 and len(readme['capstones']) == 23
assert all(item['valid'] for item in readme['local_links'])
for path, digest in execution['before_hashes'].items():
    assert sha(ROOT / path) == digest, path
for path, digest in execution['outputs'].items():
    assert sha(ROOT / path) == digest, path
for command in execution['commands']:
    assert command['exit_code'] == 0
    for stream in ('stdout', 'stderr'):
        assert sha(E / (command['label'] + '.' + stream)) == command[stream + '_sha256']
assert all(not path.read_bytes() for path in E.glob('*.stderr'))
previews = verification['saved_readme_size_previews']
assert len(previews) == 4
visual = {
    'status': 'passed',
    'scope': 'Manual view_image inspection of final PNG and extracted GIF generations 0, 11 and 22 at 800 px README width; source/artist/all-frame checks are separate.',
    'observations': [
        'Titles, scales, units, legends and current endpoint labels are readable.',
        'The 2.00x target remains visible and explicitly applies to both modes.',
        'Decode and decode-plus-CPR differ by line style and marker shape as well as color.',
        'The animation uses fixed axes and shows only recorded generations through each frame.',
        'The earliest Rust endpoint label sits close to the left axis but remains readable; no changed rendering or missing value was found.',
        'Exact median target status: ' + execution['exact_target_status']['README_status_text'] + ' No uncertainty intervals or new workload measurements were introduced.'
    ],
    'image_sha256': {name: sha(ROOT / 'docs/images' / name) for name in ('throughput.gif', 'throughput.svg', 'throughput.png')},
    'validation_sha256': sha(E / 'verification.json'),
    'previews': {path: sha(ROOT / path) for path in previews},
}
save(E / 'visual-review.json', visual)
paths = [ROOT / path for path in execution['outputs']]
paths += [ROOT / path for path in ('review/packaging/check_presentation.py', 'review/presentation/render_throughput.py', 'review/presentation/verify_throughput.py')]
paths += [path for path in E.iterdir() if path.is_file() and path.name not in ('seal.stdout', 'seal.stderr', 'completion.json')]
completion = {
    'status': 'passed', 'generation': 22,
    'completed_utc': datetime.now(timezone.utc).isoformat(),
    'benchmark_review_sha256': execution['review_sha256'],
    'timed_commit': execution['timed_commit'],
    'csv_rows': verification['source_rows'], 'gif_frames': verification['frames'],
    'exact_target_status': execution['exact_target_status'],
    'signed_cpr_overhead': execution['signed_cpr_overhead'],
    'csv_sha256': sha(ROOT / 'bench/results.csv'), 'csv_unchanged': True,
    'commands': execution['commands'],
    'outputs': {str(path.relative_to(ROOT)): sha(path) for path in sorted(set(paths))},
    'checks': {
        'source_artist_frame_values': verification['plotted_values_checked'],
        'README_checks': len(readme['checks']), 'local_links': len(readme['local_links']),
        'capstones_verbatim': True,
        'correctness_inputs': 197,
        'all_held_inputs_rehashed_at_completion': len(execution['before_hashes']),
        'all_correctness_and_measured_native_inputs_held': True,
    },
    'prior_presentation_git_binding': execution['prior_presentation_commit'],
    'producer_attempts': [{'attempt': 1, 'status': 'passed'}],
    'limitations': 'Presentation only. No benchmark, decoder, proof build or profiler executed. Original presentation remains in Git history; all benchmark CSV/report/archive bytes retained. Evidence-local checker adds exact per-mode and conjunctive target status plus signed CPR overhead from exact medians; generic checker and renderer are unchanged. Separate independent presentation review follows this producer seal.',
}
save(E / 'completion.json', completion)
print(json.dumps({'status': 'passed', 'completion_sha256': sha(E / 'completion.json'), 'visual_review_sha256': sha(E / 'visual-review.json'), 'checks': completion['checks']}))

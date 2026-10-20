"""Seal analysis of the already captured CPR samples; no native execution."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import hashlib
import json
import re

ROOT = Path(__file__).resolve().parents[5]
E = Path(__file__).resolve().parent

def sha(p):
    with p.open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()

def load(p):
    return json.loads(p.read_text())

def save(p, value):
    with p.open('x') as f:
        json.dump(value, f, indent=2)
        f.write('\n')

capture = load(E / 'capture.json')
analysis = load(E / 'analysis.json')
isolated = load(E.parent / 'isolated-perf-completion.json')
assert isolated['status'] == analysis['status'] == 'passed'
assert isolated['all_jobs_stopped'] and isolated['sequential_modes'] == ['decode', 'cpr']
assert capture['mode'] == 'cpr' and capture['record_exit_code'] == 0
assert capture['all_input_hashes_unchanged']
assert capture['before_hashes'] == capture['after_hashes']
for name, digest in capture['before_hashes'].items():
    assert sha(ROOT / name) == digest, name
row = next(r for r in isolated['results'] if r['mode'] == 'cpr')
assert row['capture_sha256'] == sha(E / 'capture.json')
raw = capture['raw_data']
assert sha(ROOT / raw['path']) == raw['sha256']
assert (ROOT / raw['path']).stat().st_size == raw['bytes']
lost = []
for name in ['report-self.txt', 'report-children.txt']:
    matches = [(i, line) for i, line in enumerate((E / name).read_text().splitlines(), 1)
               if re.fullmatch(r'# Total Lost Samples: 0', line)]
    assert len(matches) == 1
    lost.append({'file': name, 'line': matches[0][0], 'text': matches[0][1]})
assert analysis['total_samples'] == analysis['visible_CPR_loop_samples'] + analysis['excluded_samples']
assert analysis['reported_lost_samples'] == 0
assert (E / 'analyze_cpr_perf.py').read_bytes() == (
    ROOT / 'tests/evidence/diagnostics/gen24-cpr/perf/analyze_cpr_perf.py').read_bytes()
result = {
    'status': 'passed', 'reviewed_at_utc': datetime.now(timezone.utc).isoformat(),
    'capture_exit_code': 0,
    'analysis_command': ['python3', '-B', str((E / 'analyze_cpr_perf.py').relative_to(ROOT))],
    'analysis_exit_code': 0,
    'capture_helper_sha256': capture['helper_source_sha256'],
    'analysis_helper_sha256': sha(E / 'analyze_cpr_perf.py'),
    'captured_input_hash_count': len(capture['before_hashes']),
    'all_input_hashes_still_match': True,
    'gen25_fresh_native_binding': capture['fresh_gen25_binding'],
    'samples': analysis['total_samples'], 'included_decode_stacks': None,
    'included_cpr_loop_stacks': analysis['visible_CPR_loop_samples'],
    'excluded_samples': analysis['excluded_samples'],
    'lost_sample_report_lines': lost,
    'unknown_frame_stacks': analysis['all_samples_with_unknown_frame'],
    'unknown_decode_leaf_samples': None,
    'unknown_cpr_leaf_samples': analysis['included_unknown_leaves'],
    'raw_data': raw, 'capture_sha256': sha(E / 'capture.json'),
    'no_throughput_claim': True,
}
save(E / 'completion.json', result)
text = f"""# Generation 25 CPR actual-worker diagnostic sampling

One actual frozen worker run was sampled on CPU 0 with cpu-clock:u at 199 Hz after both diagnostic builds. Decode and CPR captures ran sequentially with other native/profile jobs held. This is not a benchmark. All {result['captured_input_hash_count']} protected inputs and 22 fresh native sets remain unchanged. The explicit source binding relates timed {capture['timed_commit']} to artifact {capture['git_head']}; documentation commits have no measured speed attribution.

All {result['samples']} recorded samples were parsed; {result['included_cpr_loop_stacks']} have a visible frozen runCPROnce ancestor and {result['excluded_samples']} are excluded, not assumed to be preparation. Unknown frames appear in {result['unknown_frame_stacks']} stacks, with {result['unknown_cpr_leaf_samples']} included unknown leaves. Both retained reports explicitly state zero lost samples. Conditional shares can be biased by inlining, tail calls and unwinding. Eager immutable table startup, including the complete power-of-two table, is outside the visible loop subset; scalar first-use constants may remain inside. No table-hit frequency or throughput effect is inferred from samples.
"""
with (E / 'README.md').open('x') as f:
    f.write(text)
save(E / 'artifact-hashes.json', {'status': 'passed', 'files': {
    p.name: sha(p) for p in sorted(E.iterdir()) if p.is_file()
    and p.name not in {'artifact-hashes.json', 'seal-execution.log'}}})
print(json.dumps({'status': 'passed', 'completion_sha256': sha(E / 'completion.json'),
                  'samples': result['samples'], 'included': result['included_cpr_loop_stacks'],
                  'excluded': result['excluded_samples'], 'unknown_stacks': result['unknown_frame_stacks'],
                  'included_unknown_leaves': result['unknown_cpr_leaf_samples']}))

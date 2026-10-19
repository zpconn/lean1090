#!/usr/bin/env python3
"""Read-only independent presentation receipt/data review; never render or run Lean."""
import sys
sys.dont_write_bytecode = True
import csv
import ast
from datetime import datetime, timezone
from decimal import Decimal
import hashlib
import io
import json
import os
from pathlib import Path
import re
import subprocess
from urllib.parse import unquote, urlsplit
from PIL import Image

ROOT = Path(__file__).resolve().parents[5]
E = Path(__file__).resolve().parent
os.environ['GIT_OPTIONAL_LOCKS'] = '0'
os.environ['PYTHONDONTWRITEBYTECODE'] = '1'
os.chdir(ROOT)

def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()

def load(path):
    return json.loads(Path(path).read_text())

def git_blob(commit, path):
    return subprocess.check_output(['git', 'show', f'{commit}:{path}'])

def unfenced(text):
    return re.sub(r'(?ms)^```[^\n]*\n.*?^```\s*$', '', text)

def anchors(text):
    result, counts = set(), {}
    for heading in re.findall(r'(?m)^#{1,6}\s+(.+?)\s*#*$', unfenced(text)):
        base = re.sub(r'[^\w\- ]', '', heading.lower()).replace(' ', '-')
        number = counts.get(base, 0)
        counts[base] = number + 1
        result.add(base if not number else base + '-' + str(number))
    return result

assert not (E / 'independent-review.json').exists()
completion = load(E / 'completion.json')
execution = load(E / 'execution.json')
verification = load(E / 'verification.json')
readme_check = load(E / 'readme-verification.json')
visual = load(E / 'visual-review.json')
manifest = load('docs/images/throughput-data.json')
summary = load('bench/runs/gen23/summary.json')
review = load('bench/runs/gen23/results-review.json')
checks = []

def require(name, condition):
    assert condition, name
    checks.append(name)

require('passed completed producer and independent benchmark review',
        completion['status'] == execution['status'] == review['status'] == 'passed'
        and not review['findings'] and review['generation'] == 23
        and review['commit'] == summary['commit'] == completion['timed_commit']
        and review['binary_sha256'] == summary['binary_sha256']
        and completion['benchmark_review_sha256'] == sha('bench/runs/gen23/results-review.json'))
held = {**completion['outputs'], **readme_check['inputs'], **execution['before_hashes']}
held[str((E / 'completion.json').relative_to(ROOT))] = sha(E / 'completion.json')
held['bench/runs/gen23/summary.json'] = sha('bench/runs/gen23/summary.json')
held['bench/runs/gen23/results-review.json'] = sha('bench/runs/gen23/results-review.json')
# Prior-presentation hashes are intentionally old; all three current maps must
# agree whenever they bind the same live file.
for mapping in [completion['outputs'], readme_check['inputs'], execution['before_hashes']]:
    for name, digest in mapping.items():
        require('bound current file: ' + name, sha(name) == digest)
require('all three recorded presentation commands succeeded',
        [c['label'] for c in completion['commands']] == ['render', 'verify', 'readme']
        and completion['commands'] == execution['commands']
        and all(c['exit_code'] == 0 and c['environment']['PYTHONDONTWRITEBYTECODE'] == '1'
                for c in completion['commands']))
for item in completion['commands']:
    for stream in ['stdout', 'stderr']:
        require(item['label'] + ' completed ' + stream,
                sha(E / (item['label'] + '.' + stream)) == item[stream + '_sha256'])
require('unchanged generic renderer and checkers', all(
    git_blob(summary['commit'], name) == Path(name).read_bytes() for name in
    ['review/presentation/render_throughput.py', 'review/presentation/verify_throughput.py',
     'review/packaging/check_presentation.py']))
original_checker = Path('tests/evidence/optimization/gen22/presentation/check_presentation.py').read_text()
adapted = (E / 'check_presentation.py').read_text()
preparation = load(E / 'preparation.json')
import difflib
actual_diff = ''.join(difflib.unified_diff(original_checker.splitlines(True), adapted.splitlines(True),
    fromfile='tests/evidence/optimization/gen22/presentation/check_presentation.py',
    tofile='tests/evidence/optimization/gen23/presentation/check_presentation.py'))
require('exact unchanged checker and its two signed-overhead checks',
    actual_diff == (E / 'check_presentation.py.diff').read_text()
    and 'README_signed_CPR_overheads_match_exact_medians' in adapted
    and 'README_CPR_overhead_scope_and_noise_disclosed' in adapted)
for name in ('run_refresh.py', 'check_presentation.py', 'seal_presentation.py'):
    previous = Path('tests/evidence/optimization/gen22/presentation') / name
    current = E / name
    exact_diff = ''.join(difflib.unified_diff(previous.read_text().splitlines(True), current.read_text().splitlines(True),
        fromfile=str(previous), tofile=str(current.relative_to(ROOT))))
    require('exact retained producer source diff: ' + name,
            exact_diff == (E / (name + '.diff')).read_text())
for name, digest in preparation['inputs'].items():
    require('prior or generic preparation input: ' + name, sha(name) == digest)
for name, digest in preparation['files'].items():
    require('producer preparation binds ' + name, sha(name) == digest)
# Independently calculate status from integer medians, without either producer
# checker or its Decimal display strings. Decode alone reaches its target.
reached = {}
for mode in ('decode', 'cpr'):
    medians = next(row for row in summary['results'] if row['mode'] == mode)['medians_nanoseconds']
    require('positive integer medians: ' + mode,
            all(type(medians[n]) is int and medians[n] > 0 for n in ('lean1090', 'rs1090')))
    reached[mode] = medians['rs1090'] >= 2 * medians['lean1090']
    require('independent exact target decision: ' + mode,
            review[mode + '_target_ratio'] == {'numerator': 2, 'denominator': 1}
            and review[mode + '_threshold_reached'] is reached[mode]
            and execution['exact_target_status']['mode_reached'][mode] is reached[mode])
require('decode alone reaches its exact 2/1 target', reached == {'decode': True, 'cpr': False}
        and review['all_mode_thresholds_reached'] is False
        and execution['exact_target_status']['all_modes_reached'] is False
        and execution['exact_target_status']['README_status_text'] == 'decode has reached its target; CPR remains below target.')

csv_bytes = Path('bench/results.csv').read_bytes()
rows = list(csv.DictReader(io.StringIO(csv_bytes.decode())))
require('all 46 prior CSV rows preserved byte-identically', csv_bytes.startswith(git_blob(summary['commit'], 'bench/results.csv')))
require('48 unique rows over 24 generations and both modes', len(rows) == 48
        and {(int(row['generation']), row['mode']) for row in rows}
        == {(g, m) for g in range(24) for m in ('decode', 'cpr')})
require('chart manifest binds every CSV field and source hash',
        [{k: v for k, v in row.items() if k != 'ratio_recomputed'} for row in manifest['rows']] == rows
        and manifest['source_sha256'] == sha('bench/results.csv') == completion['csv_sha256']
        and manifest['generator_sha256'] == sha(manifest['generator']))
for row, rendered in zip(rows, manifest['rows']):
    ratio = Decimal(row['lean1090_msg_s']) / Decimal(row['rs1090_msg_s'])
    require('exact positive measured ratio: ' + row['generation'] + '/' + row['mode'],
            Decimal(row['lean1090_msg_s']) > 0 and Decimal(row['rs1090_msg_s']) > 0
            and ratio == Decimal(rendered['ratio_recomputed'])
            and abs(ratio - Decimal(row['lean_over_rs1090'])) < Decimal('1e-14'))
require('both targets 2.00 and all 24 frames accounted',
        Decimal(manifest['target_ratio']) == Decimal('2.00')
        and manifest['generations'] == list(range(24))
        and manifest['frame_count'] == len(manifest['frames']) == 24
        and verification['plotted_values_checked'] == sum(4 * (g + 1) for g in range(24)) == 1200
        and verification['target_visible_in_all_frames']
        and verification['source_rows'] == 48 and verification['frames'] == 24)
require('retained artist/frame verification binds exact current sources',
        verification['status'] == 'passed'
        and verification['manifest_sha256'] == sha('docs/images/throughput-data.json')
        and verification['generator_sha256'] == sha('review/presentation/render_throughput.py')
        and verification['checker_sha256'] == sha('review/presentation/verify_throughput.py')
        and all(0 <= n < 1 for n in verification['gif_mean_absolute_RGB_quantization_error_by_frame']))
for name, metadata in manifest['outputs'].items():
    require('chart saved output: ' + name, sha(Path('docs/images') / name) == metadata['sha256']
            and (Path('docs/images') / name).stat().st_size == metadata['bytes'])
with Image.open('docs/images/throughput.gif') as gif:
    require('decoded GIF exactly 24 full-size looping frames', gif.n_frames == 24
            and gif.size == (1080, 750) and gif.info['loop'] == 0)
    decoded_frames = []
    for g in range(24):
        gif.seek(g)
        decoded_frames.append(hashlib.sha256(gif.convert('RGB').tobytes()).hexdigest())
        require('frame duration and visible data span: ' + str(g),
                gif.info['duration'] == manifest['gif_frame_durations_ms'][g]
                and manifest['frames'][g]['plotted_generations'] == list(range(g + 1)))
    require('all decoded GIF frames distinct', len(set(decoded_frames)) == 24)
with Image.open('docs/images/throughput.png') as png:
    require('static image binds final exact frame pixels',
            hashlib.sha256(png.convert('RGB').tobytes()).hexdigest() == manifest['frames'][-1]['pixel_sha256'])
svg = Path('docs/images/throughput.svg').read_text()
require('SVG labels include current generation and both-mode target',
        'GENERATION 23' in svg and 'Target 2.00× · both modes' in svg
        and 'Decode  2.41×' in svg and 'Decode + CPR  1.84×' in svg)

readme = Path('README.md').read_text()
old_readme = git_blob(summary['commit'], 'README.md').decode()
capstones = Path('Capstones.lean').read_text()
source_defs = re.findall(r'(?ms)^def \w+.*?(?=\n\n/--|\n\nend Lean1090.Capstones)', capstones)
section = readme.split('<!-- CAPSTONES:BEGIN -->', 1)[1].split('<!-- CAPSTONES:END -->', 1)[0]
require('all 23 complete capstone definitions remain verbatim', len(source_defs) == 23
        and re.findall(r'```lean\n(.*?)\n```', section, re.S) == ['\n\n'.join(source_defs)]
        and readme.split('<!-- CAPSTONES:BEGIN -->', 1)[1] == old_readme.split('<!-- CAPSTONES:BEGIN -->', 1)[1])
require('manifest has exactly the same 23 final contract names',
        [re.match(r'def (\w+)', d)[1] for d in source_defs]
        == re.findall(r'(?m)^theorem (\w+) :', Path('scripts/Final.lean').read_text()))
latest = {r['mode']: r for r in rows if r['generation'] == '23'}
measurements = {}
for mode, row in latest.items():
    ratio = Decimal(row['lean1090_msg_s']) / Decimal(row['rs1090_msg_s'])
    native = next(r for r in summary['results'] if r['mode'] == mode)
    require('README/report actual numbers: ' + mode,
            all(token in readme for token in [f"{Decimal(row['lean1090_msg_s']):,.0f} msg/s",
                f"{Decimal(row['rs1090_msg_s']):,.0f} msg/s", f'{ratio:.5f}×'])
            and f'{ratio:.12f}×' in Path('bench/GEN23.md').read_text()
            and abs(ratio - Decimal(str(native['lean_over_rust']))) < Decimal('1e-14'))
    measurements[mode] = str(ratio)
require('README explicitly states decode-only success and measurement limits',
        'generation 23' in readme and summary['commit'] in readme
        and '2.00× in both modes' in readme and 'decode has reached its target; CPR remains below target' in readme
        and Decimal(measurements['decode']) >= 2 and Decimal(measurements['cpr']) < 2
        and 'they do not establish performance on other hosts or inputs' in readme
        and 'tested, not proved equal to real arithmetic' in readme)
require('all 32 retained README checks pass', readme_check['status'] == 'passed'
        and not readme_check['findings'] and len(readme_check['checks']) == 32
        and all(readme_check['checks'].values()))
link_count = 0
for link in readme_check['local_links']:
    document = Path(link['document'])
    url = urlsplit(link['target'].strip('<>'))
    target = (document.parent / unquote(url.path)).resolve() if url.path else document.resolve()
    require('local link: ' + str(document) + ' -> ' + link['target'],
            link['valid'] and target.exists()
            and (not url.fragment or target.suffix != '.md' or unquote(url.fragment) in anchors(target.read_text())))
    link_count += 1
require('all current retained local links checked', link_count == len(readme_check['local_links']) == completion['checks']['local_links'])
document_ast = ast.parse(Path('review/packaging/check_presentation.py').read_text())
documents = next(ast.literal_eval(n.value) for n in document_ast.body if isinstance(n, ast.Assign) and any(isinstance(t, ast.Name) and t.id == 'DOCUMENTS' for t in n.targets))
expected_links = []
for document in documents:
    for target in re.findall(r'\]\(([^\s)]+)(?:\s+"[^"]*")?\)', unfenced(Path(document).read_text())):
        url = urlsplit(target.strip('<>'))
        if not url.scheme and not url.netloc:
            expected_links.append((document, target))
require('complete current document link enumeration independently reproduced', expected_links == [(r['document'], r['target']) for r in readme_check['local_links']])

# Independently derive the new README paragraph from integer durations.
mode_medians={row['mode']:row['medians_nanoseconds'] for row in summary['results']}
reporting=load('bench/runs/gen23/report-verification.json')
for implementation,label in [('lean1090','Lean'),('rs1090','rs1090')]:
    delta=mode_medians['cpr'][implementation]-mode_medians['decode'][implementation]
    display=format(Decimal(delta)/Decimal(172432000), '+.12f')
    item=reporting['cpr_overhead']['implementations'][implementation]
    require('signed overhead exact integer inputs: '+implementation,
        item['difference_nanoseconds']==delta and item['microseconds_per_message_divisor']==172432000
        and item['median_nanoseconds']=={m:mode_medians[m][implementation] for m in ('decode','cpr')}
        and execution['signed_cpr_overhead']['displayed_microseconds_per_message'][implementation]==display
        and f'**{display} µs/message for {label}**' in readme)
require('signed overhead source, formula and measurement-noise scope retained',
    completion['signed_cpr_overhead']==execution['signed_cpr_overhead']
    and execution['signed_cpr_overhead']['source_sha256']==sha('bench/runs/gen23/report-verification.json')
    and execution['signed_cpr_overhead']['exact_inputs']==reporting['cpr_overhead']
    and all(t in readme for t in ['difference between independently measured mode medians','includes measurement noise','not an isolated timing of CPR work']))

require('CPR overhead history link and data remain bound', '[CPR overhead history](bench/CPR-OVERHEAD.md)' in readme and all(name in execution['before_hashes'] for name in ['bench/CPR-OVERHEAD.md','bench/cpr-overhead.json']))
for preview, digest in visual['previews'].items():
    require('visually viewed preview: ' + preview, sha(preview) == digest)
for name, digest in execution['before_hashes'].items():
    require('producer held input still unchanged: ' + name, sha(name) == digest)
for name, digest in held.items():
    require('final reviewed input unchanged: ' + name, sha(name) == digest)

result = {
    'status': 'passed', 'generation': 23,
    'recorded_utc': datetime.now(timezone.utc).isoformat(),
    'producer_completion_sha256': sha(E / 'completion.json'),
    'checker_sha256': sha(__file__), 'findings': [],
    'checks_count': len(checks), 'checks': checks,
    'input_bindings': held, 'csv_rows': 48, 'gif_frames': 24,
    'retained_artist_values_verified': 1200, 'capstones_verbatim': 23,
    'local_links_rechecked': link_count, 'latest_ratios': measurements,
    'target': '2.00 in both modes; decode reached, CPR unmet',
    'exact_target_decisions': reached,
    'visual_inspection': {
        'method': 'view_image of all four retained 800 px previews before running this checker',
        'previews': visual['previews'],
        'observations': [
            'Static and final GIF show 2.41× decode / 1.84× CPR; decode is above and CPR below the visible 2.00× target.',
            'Units, titles, legends, both series and the final 529.1k/219.5k endpoints are readable.',
            'GIF previews at generations 0, 12 and 23 keep identical scales and no future points.',
            'The generation-0 rs1090 endpoint is close to the left y-axis tick labels; this existing cosmetic limitation remains readable and does not obscure the plotted value.',
            'No fabricated uncertainty, pyModeS series or cross-host performance claim appears.'
        ]},
    'execution_limits': 'No producer renderer/checker, benchmark, build, proof, native decoder or profiler was rerun. The independently read unchanged artist/frame checker and its source-bound successful log establish all 1200 plotted values; this review independently rehashed receipts, recomputed ratios, decoded GIF structure, verified static pixel binding, capstones and links.',
    'all_jobs_stopped': True,
}
(E / 'independent-review.json').write_text(json.dumps(result, indent=2, ensure_ascii=False) + '\n')
print(json.dumps({'status': 'passed', 'checks': len(checks), 'sha256': sha(E / 'independent-review.json')}))

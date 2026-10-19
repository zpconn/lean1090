#!/usr/bin/env python3
"""Read-only independent presentation receipt/data review; never render or run Lean."""
import sys
sys.dont_write_bytecode = True
import csv
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
summary = load('bench/runs/gen18/summary.json')
review = load('bench/runs/gen18/results-review.json')
checks = []

def require(name, condition):
    assert condition, name
    checks.append(name)

require('passed completed producer and independent benchmark review',
        completion['status'] == execution['status'] == review['status'] == 'passed'
        and not review['findings'] and review['generation'] == 18
        and review['commit'] == summary['commit'] == completion['timed_commit']
        and review['binary_sha256'] == summary['binary_sha256']
        and completion['benchmark_review_sha256'] == sha('bench/runs/gen18/results-review.json'))
held = {**completion['outputs'], **readme_check['inputs'], **execution['before_hashes']}
held[str((E / 'completion.json').relative_to(ROOT))] = sha(E / 'completion.json')
held['bench/runs/gen18/summary.json'] = sha('bench/runs/gen18/summary.json')
held['bench/runs/gen18/results-review.json'] = sha('bench/runs/gen18/results-review.json')
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
original_checker = Path('review/packaging/check_presentation.py').read_text()
adapted = (E / 'check_presentation.py').read_text()
expected = original_checker.replace('ROOT = Path(__file__).resolve().parents[2]',
                                    'ROOT = Path(__file__).resolve().parents[5]')
fresh_definition = "    fresh_summary = f'tests/evidence/optimization/gen{generation}/fresh/fresh-message/summary.json' if generation == 18 else f'tests/evidence/optimization/gen{generation}/fresh-message/summary.json'\n"
expected = expected.replace('    assert generation >= 0\n', '    assert generation >= 0\n' + fresh_definition)
expected = expected.replace("        f'tests/evidence/optimization/gen{generation}/fresh-message/summary.json',", '        fresh_summary,')
expected = expected.replace("        campaign = json.loads((ROOT / f'tests/evidence/optimization/gen{generation}/{kind}-message/summary.json').read_text())",
    "        campaign_path = fresh_summary if kind == 'fresh' else f'tests/evidence/optimization/gen{generation}/fixed-message/summary.json'\n        campaign = json.loads((ROOT / campaign_path).read_text())")
require('evidence-local checker has only exact root and nested-summary adaptations', adapted == expected)

csv_bytes = Path('bench/results.csv').read_bytes()
rows = list(csv.DictReader(io.StringIO(csv_bytes.decode())))
require('all 36 prior CSV rows preserved byte-identically', csv_bytes.startswith(git_blob(summary['commit'], 'bench/results.csv')))
require('38 unique rows over 19 generations and both modes', len(rows) == 38
        and {(int(row['generation']), row['mode']) for row in rows}
        == {(g, m) for g in range(19) for m in ('decode', 'cpr')})
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
require('both targets 2.00 and all 19 frames accounted',
        Decimal(manifest['target_ratio']) == Decimal('2.00')
        and manifest['generations'] == list(range(19))
        and manifest['frame_count'] == len(manifest['frames']) == 19
        and verification['plotted_values_checked'] == sum(4 * (g + 1) for g in range(19)) == 760
        and verification['target_visible_in_all_frames']
        and verification['source_rows'] == 38 and verification['frames'] == 19)
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
    require('decoded GIF exactly 19 full-size looping frames', gif.n_frames == 19
            and gif.size == (1080, 750) and gif.info['loop'] == 0)
    decoded_frames = []
    for g in range(19):
        gif.seek(g)
        decoded_frames.append(hashlib.sha256(gif.convert('RGB').tobytes()).hexdigest())
        require('frame duration and visible data span: ' + str(g),
                gif.info['duration'] == manifest['gif_frame_durations_ms'][g]
                and manifest['frames'][g]['plotted_generations'] == list(range(g + 1)))
    require('all decoded GIF frames distinct', len(set(decoded_frames)) == 19)
with Image.open('docs/images/throughput.png') as png:
    require('static image binds final exact frame pixels',
            hashlib.sha256(png.convert('RGB').tobytes()).hexdigest() == manifest['frames'][-1]['pixel_sha256'])
svg = Path('docs/images/throughput.svg').read_text()
require('SVG labels include current generation and both-mode target',
        'GENERATION 18' in svg and 'Target 2.00× · both modes' in svg
        and 'Decode  1.67×' in svg and 'Decode + CPR  1.34×' in svg)

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
latest = {r['mode']: r for r in rows if r['generation'] == '18'}
measurements = {}
for mode, row in latest.items():
    ratio = Decimal(row['lean1090_msg_s']) / Decimal(row['rs1090_msg_s'])
    native = next(r for r in summary['results'] if r['mode'] == mode)
    require('README/report actual numbers: ' + mode,
            all(token in readme for token in [f"{Decimal(row['lean1090_msg_s']):,.0f} msg/s",
                f"{Decimal(row['rs1090_msg_s']):,.0f} msg/s", f'{ratio:.5f}×'])
            and f'{ratio:.12f}×' in Path('bench/GEN18.md').read_text()
            and abs(ratio - Decimal(str(native['lean_over_rust']))) < Decimal('1e-14')
    measurements[mode] = str(ratio)
require('README explicitly keeps both targets unmet and measurement limits',
        'generation 18' in readme and summary['commit'] in readme
        and '2.00× in both modes' in readme and 'neither target is reached' in readme
        and all(Decimal(r) < 2 for r in measurements.values())
        and 'they do not establish performance on other hosts or inputs' in readme
        and 'tested, not proved equal to real arithmetic' in readme)
require('all 29 retained README checks pass', readme_check['status'] == 'passed'
        and not readme_check['findings'] and len(readme_check['checks']) == 29
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
require('all 93 retained local links checked', link_count == 93)
for preview, digest in visual['previews'].items():
    require('visually viewed preview: ' + preview, sha(preview) == digest)
for name, digest in execution['before_hashes'].items():
    require('producer held input still unchanged: ' + name, sha(name) == digest)
for name, digest in held.items():
    require('final reviewed input unchanged: ' + name, sha(name) == digest)

result = {
    'status': 'passed', 'generation': 18,
    'recorded_utc': datetime.now(timezone.utc).isoformat(),
    'producer_completion_sha256': sha(E / 'completion.json'),
    'checker_sha256': sha(__file__), 'findings': [],
    'checks_count': len(checks), 'checks': checks,
    'input_bindings': held, 'csv_rows': 38, 'gif_frames': 19,
    'retained_artist_values_verified': 760, 'capstones_verbatim': 23,
    'local_links_rechecked': link_count, 'latest_ratios': measurements,
    'target': '2.00 in both modes; neither reached',
    'visual_inspection': {
        'method': 'view_image of all four retained 800 px previews before running this checker',
        'previews': visual['previews'],
        'observations': [
            'Static and final GIF show 1.67× decode / 1.34× CPR, both below the visible 2.00× line.',
            'Units, titles, legends, both series and the final 357.1k/213.5k endpoints are readable.',
            'GIF previews at generations 0, 9 and 18 keep identical scales and no future points.',
            'The generation-0 rs1090 endpoint is close to the left y-axis tick labels; this existing cosmetic limitation remains readable and does not obscure the plotted value.',
            'No fabricated uncertainty, pyModeS series or cross-host performance claim appears.'
        ]},
    'execution_limits': 'No producer renderer/checker, benchmark, build, proof, native decoder or profiler was rerun. The independently read unchanged artist/frame checker and its source-bound successful log establish all 760 plotted values; this review independently rehashed receipts, recomputed ratios, decoded GIF structure, verified static pixel binding, capstones and links.',
    'all_jobs_stopped': True,
}
(E / 'independent-review.json').write_text(json.dumps(result, indent=2, ensure_ascii=False) + '\n')
print(json.dumps({'status': 'passed', 'checks': len(checks), 'sha256': sha(E / 'independent-review.json')}))

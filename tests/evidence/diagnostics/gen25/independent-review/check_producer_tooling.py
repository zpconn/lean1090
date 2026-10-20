"""Read-only independent source/delta and compact score-context review."""
import sys
sys.dont_write_bytecode = True
import ast
from collections import Counter, defaultdict
from datetime import datetime, timezone
import difflib
import hashlib
import json
from pathlib import Path
import re

E = Path('tests/evidence/diagnostics/gen25')
OLD = Path('tests/evidence/diagnostics/gen24')
P = 'lp_lean1090_Lean1090_Impl_'
checks = []
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())


def check(label, condition):
    assert condition, label
    checks.append(label)


def advance(text):
    return re.sub(r'(?<!\d)(23|24)(?!\d)', lambda m: {'23': '24', '24': '25'}[m[0]], text)


t = load(E / 'producer-tooling.json')
p = load(E / 'producer-preparation.json')
check('tooling binds preparation', t['preparation_sha256'] == sha(E / 'producer-preparation.json'))
check('fourteen exact source bindings', len(t['files']) == len(p['files']) == 14 and set(t['files']) == set(p['files']))
delta = ''
for name, binding in p['files'].items():
    current, prior = Path(name), Path(binding['from'])
    check(name + ' current hash', sha(current) == binding['sha256'] == t['files'][name])
    check(name + ' prior hash', sha(prior) == binding['prior_sha256'])
    ast.parse(current.read_text(), filename=name)
    checks.append(name + ' AST parsed without import')
    delta += ''.join(difflib.unified_diff(prior.read_text().splitlines(True), current.read_text().splitlines(True), fromfile=str(prior), tofile=str(current)))
check('exact full delta', delta == (E / 'producer-preparation.diff').read_text() and sha(E / 'producer-preparation.diff') == p['diff_sha256'])
for name in ['extract_constant_contexts.py', 'extract_pack_fields.py', 'extract_power_contexts.py', 'extract_priority_contexts.py', 'extract_bit_contexts.py', 'extract_crc_contexts.py', 'extract_affine_contexts.py', 'extract_semantic_callers.py', 'extract_ratio_contexts.py']:
    check(name + ' exact generation-only adaptation', advance((OLD / name).read_text()) == (E / name).read_text())
check('cleanup exact path adaptation', (OLD / 'cleanup_cache.py').read_text().replace('gen24', 'gen25') == (E / 'cleanup_cache.py').read_text())
check('perf parser unchanged except path', (OLD / 'perf/analyze_perf_gen24.py').read_text().replace('gen24', 'gen25') == (E / 'perf/analyze_perf_gen25.py').read_text())
check('perf seal only paths and actual source identities', advance((OLD / 'seal_perf.py').read_text()).replace('timed cc337104 to artifact d0f58661', 'timed eaa7b362 to artifact 240cc329') == (E / 'seal_perf.py').read_text())
check('perf source binds 22 actual sets', load(E / 'perf/completion.json')['gen25_fresh_native_binding']['linked_project_objects'] == 22)
for name, digest in load(E / 'preparation.json')['generic_helpers'].items():
    check(name + ' shared unchanged', sha(name) == digest)

finalizer = (E / 'finalize.py').read_text()
for marker in ["assert source['score_scaling_identity_live_path_verified']", "assert source['commb_semantic_reuse_live_path_verified']", "assert source['raw_word_syndrome_live_path_verified']", "assert source['pack_fields_fold_anchor'] is None", "assert history() == count", "for name, digest in campaign['protected_inputs'].items()", "assert sha(name) == digest, name", "'score_scale_contexts_sha256': sha(E / 'score-scale-contexts.json')"]:
    check('retained finalizer guard ' + marker, marker in finalizer)
check('actual internal execution logs retained', all(name in finalizer for name in ['driver-build-command.json', 'source-binding-command.json', 'driver-build.stdout', 'driver-build.stderr', 'source-binding.stdout', 'source-binding.stderr']))
check('nonexistent outer console logs omitted', all(name not in finalizer and not (E / name).exists() for name in ['build-controller.stdout', 'build-controller.stderr']))
check('all former score extraction algorithms retained', (OLD / 'extract_score_scale_contexts.py').read_text().replace('gen24', 'gen25').split("out={'status':")[0] == (E / 'extract_score_scale_contexts.py').read_text().split('previous_path=')[0])
for term in ['No denominator-equality hit rate', 'measured benchmark regressed', 'cannot be summed as savings']:
    check('honest score interpretation ' + term, term in finalizer)

source = load(E / 'independent-review/source-review.json')
check('actual source flag', source['score_scaling_identity_live_path_verified'])
priority = load(E / 'priority-helper-contexts.json')
score = load(E / 'score-scale-contexts.json')
check('score actual generations', [g['generation'] for g in score['generations']] == [24, 25])
previous = score['generations'][0]
check('prior sealed rows byte-bound unchanged', previous['rows'] == load(OLD / 'score-scale-contexts.json')['rows'] and previous['source_sha256'] == sha(OLD / 'score-scale-contexts.json'))
check('current rows match current generation', score['generations'][1]['rows'] == score['rows'])
for name, digest in score['bindings'].items():
    check(name + ' score binding', sha(name) == digest)
check('extractor actual absolute source binding', score['bindings'][str((E / 'extract_score_scale_contexts.py').resolve())] == sha(E / 'extract_score_scale_contexts.py'))
groups = {}
for context in score['contexts']:
    group = groups.setdefault((context['stage'], context['symbol']), {'counts': Counter(), 'children': defaultdict(Counter)})
    group['counts'].update(contexts=1, native_entries=sum(e['calls'] for e in context['incoming']), self_ir=context['self_ir'], incoming_inclusive_ir_non_additive=sum(e['inclusive_ir_non_additive'] for e in context['incoming']))
    for edge in context['outgoing']:
        group['children'][edge['symbol']].update(calls=edge['calls'], inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
rows = [{'stage': stage, 'symbol': symbol, **g['counts'], 'direct_children': [{'symbol': child, **v} for child, v in sorted(g['children'].items())]} for (stage, symbol), g in sorted(groups.items())]
check('all current score groups reconstructed from full retained contexts', rows == score['rows'])
for row in rows:
    match = next((r for r in priority['rows'] if (r['stage'], r['symbol']) == (row['stage'], row['symbol'])), None)
    if match:
        check(row['symbol'] + ' priority reconciliation', all(row[k] == match[k] for k in ['contexts', 'native_entries', 'self_ir', 'incoming_inclusive_ir_non_additive']) and sorted(row['direct_children'], key=lambda r: r['symbol']) == sorted(match['direct_children'], key=lambda r: r['symbol']))
check('choose and both scaled folds present', any(r['symbol'] == P + 'ScoreGate_choose' for r in rows) and sum('List_foldl' in r['symbol'] for r in rows) == 2)
check('guard frequency not inferred', any('denominator-equality frequency' in s for s in score['limits']))
bound = dict(t['files'])
for name in ['producer-preparation.json', 'producer-tooling.json', 'producer-preparation.diff', 'score-scale-contexts.json', 'score-scale-contexts.stdout', 'score-scale-contexts.stderr']:
    bound[str(E / name)] = sha(E / name)
for path in sorted((E / 'unexecuted-preparation-correction').rglob('*')):
    if path.is_file():
        bound[str(path)] = sha(path)
record = {'status': 'passed', 'reviewed_utc': datetime.now(timezone.utc).isoformat(),
          'reviewer': 'payload_roundtrips; independent of decode producer authorship',
          'checks_passed': len(checks), 'checks': checks, 'findings': [], 'files': bound,
          'producer_tooling_sha256': sha(E / 'producer-tooling.json'),
          'producer_preparation_sha256': sha(E / 'producer-preparation.json'),
          'checker_sha256': sha(__file__), 'retained_reviewer_attempts': [],
          'scope': 'Read-only source/diff/hash/AST review and score context group reconstruction; no producer import, native execution, profile/parser rerun or cleanup. FC independently recounts all raw profiles.',
          'assessment': ['Fourteen source bindings and exact diff preserve all corpus, count, output, history, source and stage checks. Current score extraction retains the prior algorithm and binds prior sealed rows separately.',
                         'Actual choose and both scaledTotals folds retain their complete direct children. Costs are overlapping inclusive observations; no equality-arm frequency, exclusive savings or elapsed causation is inferred.',
                         'The retained unexecuted CRC selector correction precedes finalization. Perf top20 and fixed22 native-set count are unchanged. Only absent outer console logs are omitted; internal execution records remain.',
                         'Cleanup is the exact prior generation-scoped helper with paths advanced. Both independent seals and durable exact counterparts remain required, with raw perf and unmatched paths protected.']}
out = E / 'independent-review/producer-tooling-review.json'
with out.open('x') as handle:
    json.dump(record, handle, indent=2)
    handle.write('\n')
print(json.dumps({'status': 'passed', 'checks': len(checks), 'sha256': sha(out)}))

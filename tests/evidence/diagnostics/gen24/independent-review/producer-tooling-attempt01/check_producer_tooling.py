"""Independent read-only source/delta review and compact supplement checks."""
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

E = Path('tests/evidence/diagnostics/gen24')
P = 'lp_lean1090_Lean1090_Impl_'
checks = []
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())


def check(label, value):
    assert value, label
    checks.append(label)


def advance(text):
    return re.sub(r'(?<!\d)(22|23)(?!\d)', lambda m: {'22': '23', '23': '24'}[m[0]], text)


t = load(E / 'producer-tooling.json')
p = load(E / 'producer-preparation.json')
check('tooling preparation binding', t['preparation_sha256'] == sha(E / 'producer-preparation.json'))
check('exact thirteen current source bindings', len(t['files']) == len(p['files']) == 13 and set(t['files']) == set(p['files']))
diff = ''
for name, binding in p['files'].items():
    current, old = Path(name), Path(binding['from'])
    check(name + ' current source hash', sha(current) == binding['sha256'] == t['files'][name])
    check(name + ' retained prior source hash', sha(old) == binding['prior_sha256'])
    ast.parse(current.read_text(), filename=name)
    checks.append(name + ' AST syntax without import')
    diff += ''.join(difflib.unified_diff(old.read_text().splitlines(True), current.read_text().splitlines(True), fromfile=str(old), tofile=str(current)))
check('complete exact source diff retained', diff == (E / 'producer-preparation.diff').read_text() and p['diff_sha256'] == sha(E / 'producer-preparation.diff'))
for name in ('extract_constant_contexts.py', 'extract_pack_fields.py', 'extract_power_contexts.py', 'extract_bit_contexts.py', 'extract_crc_contexts.py', 'extract_ratio_contexts.py'):
    check(name + ' exact generation pair adaptation', advance(Path(p['files'][str(E / name)]['from']).read_text()) == (E / name).read_text())
check('cleanup exact path-only adaptation', Path('tests/evidence/diagnostics/gen23/cleanup_cache.py').read_text().replace('gen23', 'gen24') == (E / 'cleanup_cache.py').read_text())
check('perf parser exact path-only adaptation', Path('tests/evidence/diagnostics/gen23/perf/analyze_perf_gen23.py').read_text().replace('gen23', 'gen24') == (E / 'perf/analyze_perf_gen24.py').read_text())
draft = (E / 'unexecuted-preparation-correction/seal_perf.py').read_text()
check('unexecuted correction only restores fixed native count and prose', draft.replace("'linked_project_objects':23", "'linked_project_objects':22").replace('23 fresh native sets', '22 fresh native sets') == (E / 'seal_perf.py').read_text())
check('executed perf source hash/current22 sets', load(E / 'perf/completion.json')['gen24_fresh_native_binding']['linked_project_objects'] == 22)
for name, digest in load(E / 'preparation.json')['generic_helpers'].items():
    check(name + ' shared helper unchanged', sha(name) == digest)

f = (E / 'finalize.py').read_text()
for marker in ("assert source['commb_semantic_reuse_live_path_verified']", "assert source['pack_fields_fold_anchor'] is None", "'--generation', '24'", "'--previous-generation', '23'", "assert history() == count", "for name, digest in campaign['protected_inputs'].items()", "assert sha(name) == digest, name", "'semantic_caller_contexts_sha256': sha(E / 'semantic-caller-contexts.json')"):
    check('finalizer guard/binding ' + marker, marker in f)
priority_text = (E / 'extract_priority_contexts.py').read_text()
check('priority complete local helper reconciliation retained', 'assert local == expected, family' in priority_text)
check('correct actual numeric constructor namespace', 'Presentation_oracleCommBFloats' in priority_text and 'Presentation_oracleCommBFloats' in f)
check('current semantic anchors selected without fabricated names', "key.startswith('commb_semantic_') and key.endswith('_anchor') and value" in priority_text and "key.startswith('commb_semantic_') and key.endswith('_anchor') and value" in f)
affine = (E / 'extract_affine_contexts.py').read_text()
check('affine equality is observed, not required', "'same_payload_value_entries_by_stage': entry_populations[0] == entry_populations[1]" in affine)
check('affine direct multiplication observation remains narrow', "if child['symbol'] == 'l_Rat_mul'" in affine and "assert local == expected, family" in affine)

source = load(E / 'independent-review/source-review.json')
priority = load(E / 'priority-helper-contexts.json')
semantic = load(E / 'semantic-caller-contexts.json')
anchors = {k: v for k, v in source.items() if k.startswith('commb_semantic_') and k.endswith('_anchor') and v}
check('five actual semantic anchors', source['commb_semantic_reuse_live_path_verified'] and len(anchors) == 5 and semantic['current_shared_map_anchors'] == anchors)
maps = [r for r in priority['rows'] if r['symbol'] in anchors.values()]
check('semantic current rows/contexts exactly selected', semantic['current_shared_map_rows'] == maps and semantic['current_shared_map_contexts'] == [r for r in priority['contexts'] if r['symbol'] in anchors.values()])
oracle_rows = [r for r in maps if r['symbol'] == source['commb_semantic_oracle_values_anchor']]
check('oracle shared map observation nonvacuous', oracle_rows and sum(r['native_entries'] for r in oracle_rows) > 0)
check('no observed direct second layout/search/scalar decode in oracle map', all(c['calls'] == 0 for r in oracle_rows for c in r['direct_children'] if c['symbol'] in {P + n for n in ('payloadValue', 'commBLayout', 'findPayloadField')}))
check('semantic comparison actual generations', [g['generation'] for g in semantic['generations']] == [23, 24])
for generation in semantic['generations']:
    groups = defaultdict(Counter)
    for context in generation['contexts']:
        for edge in context['incoming']:
            parent = 'Semantics_commB' if P + 'Semantics_commB' in edge['caller'] else 'Semantics_adsb' if P + 'Semantics_adsb' in edge['caller'] else 'other'
            symbol = re.split(r"'| \[clone ", edge['caller'], maxsplit=1)[0]
            groups[symbol, parent].update(calls=edge['calls'], inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
    expected = [{'direct_caller': s, 'semantic_ancestor': a, **counts} for (s, a), counts in sorted(groups.items())]
    check(str(generation['generation']) + ' complete semantic incoming groups', expected == generation['payload_value_direct_callers'])
    check(str(generation['generation']) + ' semantic own population reconciliation', sum(r['calls'] for r in expected) == generation['payload_value_total']['native_entries'] and sum(r['inclusive_ir_non_additive'] for r in expected) == generation['payload_value_total']['incoming_inclusive_ir_non_additive'])
    for name, digest in generation['bindings'].items():
        check(name + ' semantic retained binding', sha(name) == digest)

score_script = E / 'extract_score_scale_contexts.py'
ast.parse(score_script.read_text(), filename=str(score_script))
score = load(E / 'score-scale-contexts.json')
check('score supplement actual bound source', score['bindings'][str(score_script)] == sha(score_script))
for name, digest in score['bindings'].items():
    check(name + ' score supplement binding', sha(name) == digest)
groups = {}
for context in score['contexts']:
    group = groups.setdefault((context['stage'], context['symbol']), {'counts': Counter(), 'children': defaultdict(Counter)})
    group['counts'].update(contexts=1, native_entries=sum(e['calls'] for e in context['incoming']), self_ir=context['self_ir'], incoming_inclusive_ir_non_additive=sum(e['inclusive_ir_non_additive'] for e in context['incoming']))
    for edge in context['outgoing']:
        group['children'][edge['symbol']].update(calls=edge['calls'], inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
rows = [{'stage': stage, 'symbol': symbol, **g['counts'], 'direct_children': [{'symbol': child, **v} for child, v in sorted(g['children'].items())]} for (stage, symbol), g in sorted(groups.items())]
check('score groups completely derive from retained caller contexts', rows == score['rows'])
for row in rows:
    prior = next((r for r in priority['rows'] if (r['stage'], r['symbol']) == (row['stage'], row['symbol'])), None)
    if prior:
        check(row['symbol'] + ' score/priority reconciliation', all(row[k] == prior[k] for k in ('contexts', 'native_entries', 'self_ir', 'incoming_inclusive_ir_non_additive')) and sorted(row['direct_children'], key=lambda r: r['symbol']) == sorted(prior['direct_children'], key=lambda r: r['symbol']))
check('both actual scaled loops and choose represented', sum('List_foldl' in row['symbol'] for row in rows) == 2 and any(row['symbol'] == P + 'ScoreGate_choose' for row in rows))
check('denominator hit rate explicitly not inferred', any('denominator-equality frequency' in s for s in score['limits']))

bound = dict(t['files'])
for name in ('extract_score_scale_contexts.py', 'score-scale-contexts.json', 'score-scale-contexts.stdout', 'score-scale-contexts.stderr', 'semantic-caller-contexts.json'):
    bound[str(E / name)] = sha(E / name)
for path in sorted((E / 'unexecuted-preparation-correction').iterdir()):
    bound[str(path)] = sha(path)
record = {
    'status': 'passed', 'reviewed_utc': datetime.now(timezone.utc).isoformat(),
    'reviewer': 'payload_roundtrips; independent of decode producer authorship',
    'checks_passed': len(checks), 'checks': checks, 'findings': [], 'files': bound,
    'producer_tooling_sha256': sha(E / 'producer-tooling.json'),
    'producer_preparation_sha256': sha(E / 'producer-preparation.json'),
    'retained_reviewer_attempts': [{'attempt': 1, 'status': 'passed'}],
    'scope': 'Read-only source/hash/AST/exact-diff review plus compact JSON group reconciliation. No producer import, native/profile execution, raw parser rerun, cleanup, or modification. FC independently recounts raw sources.',
    'assessment': [
        'All thirteen old/current sources and exact delta bind the current generation. Full corpus/census/partition/held-input/history checks remain; shared parser and renderer are unchanged.',
        'Five actual semantic map boundaries supplement the existing partition. Both generations reconcile to their own observations; changed affine populations are recorded rather than asserted equal. Numeric expression construction remains within the existing pure boundary.',
        'Semantic oracle-map observations are nonempty and contain no second direct scalar/layout/search calls. Source/native proof, not missing counters alone, establishes sharing; inlined identity/empty branches have no inferred counter.',
        'Score supplement uses only three disjoint family profiles and unchanged stage propagation. Both real loops, choose and lazy constants are retained; direct arithmetic and inclusive rows overlap. Equal-denominator input populations and timing savings are not observed or inferred.',
        'The draft native-count metadata correction is preserved and precedes execution. Current perf parser retains top20 unchanged; fixed 22 native sets are accurate.',
        'Cleanup is exactly the previous generation-scoped helper with paths advanced. Final independent seals and durable exact counterparts are required, unique raw perf and unmatched files remain protected.'
    ]
}
out = E / 'independent-review/producer-tooling-review.json'
with out.open('x') as handle:
    handle.write(json.dumps(record, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'checks': len(checks), 'sha256': sha(out)}))

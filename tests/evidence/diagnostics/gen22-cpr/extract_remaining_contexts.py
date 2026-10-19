#!/usr/bin/env python3
"""Read remaining conversion contexts from the existing profile, never run code."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from collections import defaultdict
import gzip, hashlib, json
sys.path.insert(0, str(Path.cwd() / 'review/diagnostics'))
import analyze_callgrind as parser

E = Path('tests/evidence/diagnostics/gen22-cpr')
P = 'lp_lean1090_Lean1090_Impl_'
target = E / 'remaining-conversion-contexts.json'
assert not target.exists()
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
analysis = json.loads(gzip.decompress((E/'analysis/analysis.json.gz').read_bytes()))
review = json.loads((E/'independent-review/source-review.json').read_text())
assert review['dyadic_to_float_live_path_verified']
assert review['dyadic_to_float_at_most_one_fallback_per_entry']
raw = E/'retained/callgrind/callgrind.out.1.gz'
profile = parser.parse(raw)
assert hashlib.sha256(gzip.decompress(raw.read_bytes())).hexdigest() == analysis['raw_sha256']
labels = {row['symbol']: row['bucket'] for row in analysis['self_cost_contexts']}
selected = {P+suffix for suffix in ['Binary64_fromBits', 'Binary64_round',
            'Binary64_exponent', 'CPR_Policy_toFloat', 'CPR_Policy_toFloatFallback']}
fallback = review['dyadic_to_float_fallback_anchor']
edges = []
groups = defaultdict(lambda: {'calls':0, 'inclusive_Ir_non_additive':0})
for caller, node in profile.nodes.items():
    for callee, events in node.edges.items():
        symbol = parser.base_name(callee)
        if symbol not in selected:
            continue
        calls, cost = node.calls.get(callee,0), events.get('Ir',0)
        if not calls and not cost:
            continue
        assert callee in labels and labels[callee] != 'outside_root', callee
        under_fallback = fallback in [parser.base_name(part) for part in caller.split("'")]
        row = {'stage':labels[callee], 'target':symbol, 'caller':caller, 'callee':callee,
               'direct_caller':parser.base_name(caller), 'under_fallback':under_fallback,
               'calls':calls, 'inclusive_Ir_non_additive':cost}
        edges.append(row)
        group = groups[row['stage'],symbol,row['direct_caller'],under_fallback]
        group['calls'] += calls
        group['inclusive_Ir_non_additive'] += cost
helpers = [r for r in analysis['helper_observations_non_additive'] if r['symbol'] in selected]
for row in helpers:
    found=[e for e in edges if e['stage']==row['stage'] and e['target']==row['symbol']]
    assert sum(e['calls'] for e in found)==row['native_entries']
    assert sum(e['inclusive_Ir_non_additive'] for e in found)==row['inclusive_Ir_non_additive']
fallback_edges=[e for e in edges if e['target']==fallback]
assert all(e['direct_caller']==review['dyadic_to_float_anchor'] for e in fallback_edges)
result={'status':'passed','kind':'existing_profile_remaining_conversion_contexts',
 'profile':str(raw),'profile_sha256':sha(raw),'raw_profile_sha256':analysis['raw_sha256'],
 'analysis_sha256':sha(E/'analysis/analysis.json.gz'),
 'source_review_sha256':sha(E/'independent-review/source-review.json'),
 'extractor_sha256':sha(__file__),'parser_sha256':sha('review/diagnostics/analyze_callgrind.py'),
 'helper_rows_non_additive':helpers,
 'grouped_direct_edges':[dict(stage=k[0],target=k[1],direct_caller=k[2],under_fallback=k[3],**v)
                         for k,v in sorted(groups.items())],
 'full_context_edges':edges,
 'actual_fallback_calls_inside_root':sum(e['calls'] for e in fallback_edges),
 'limits':['Uses the existing complete profile; no native call or timing added.',
           'All inclusive costs overlap exclusive stages, ancestors, descendants and other listed rows.',
           'Fallback has a source-verified callable boundary; zero incoming calls is a corpus observation, not a guarantee for arbitrary rationals.',
           'Wrapper-minus-fallback still includes positive zero and accepted dyadics; no separate population is inferred.']}
target.write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':'passed','helper_rows':len(helpers),'direct_groups':len(groups),
                 'fallback_calls':result['actual_fallback_calls_inside_root'],'sha256':sha(target)}))

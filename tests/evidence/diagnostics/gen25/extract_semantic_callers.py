"""Compare retained semantic caller contexts and actual shared map boundaries."""
import sys
sys.dont_write_bytecode = True
from collections import Counter
from pathlib import Path
import hashlib, json, re
E = Path('tests/evidence/diagnostics/gen25')
P = 'lp_lean1090_Lean1090_Impl_'
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
read = lambda p: json.loads(Path(p).read_text())
base = lambda s: re.split(r"'| \[clone ", s, maxsplit=1)[0]


def collect(generation):
    root = Path(f'tests/evidence/diagnostics/gen{generation}')
    analysis = read(root / 'analysis/analysis.json')
    priority = read(root / 'priority-helper-contexts.json')
    selected = [r for r in priority['contexts']
                if r['stage'] == 'semantic_oracle_values' and r['symbol'] == P + 'payloadValue']
    groups = {}
    for context in selected:
        for edge in context['incoming']:
            ancestor = ('Semantics_commB' if P + 'Semantics_commB' in edge['caller'] else
                        'Semantics_adsb' if P + 'Semantics_adsb' in edge['caller'] else 'other')
            groups.setdefault((base(edge['caller']), ancestor), Counter()).update(
                calls=edge['calls'], inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
    rows = [{'direct_caller': k[0], 'semantic_ancestor': k[1], **v} for k, v in sorted(groups.items())]
    whole = next(r for r in priority['rows'] if r['stage'] == 'semantic_oracle_values' and r['symbol'] == P + 'payloadValue')
    assert sum(r['calls'] for r in rows) == whole['native_entries']
    assert sum(r['inclusive_ir_non_additive'] for r in rows) == whole['incoming_inclusive_ir_non_additive']
    floats = [{'family': family, 'stage': stage, **row}
              for family, profile in analysis['families'].items()
              for stage, helpers in profile['stage_helper_observations_non_additive'].items()
              for row in helpers if 'oracleCommBFloats' in row['symbol'] or 'commBStandardFloats' in row['symbol']]
    return {'generation': generation, 'payload_value_direct_callers': rows,
            'payload_value_total': {k: whole[k] for k in ('native_entries', 'self_ir', 'incoming_inclusive_ir_non_additive')},
            'semantic_commb': next(r for r in priority['rows'] if r['stage'] == 'semantic_oracle_values' and r['symbol'] == P + 'Semantics_commB'),
            'actual_float_constructor_helper_rows': floats, 'contexts': selected,
            'bindings': {str(root / name): sha(root / name) for name in (
                'analysis/analysis.json', 'priority-helper-contexts.json', 'independent-review/source-review.json')}}


def main():
    target = E / 'semantic-caller-contexts.json'
    assert not target.exists()
    source = read(E / 'independent-review/source-review.json')
    assert source['commb_semantic_reuse_live_path_verified']
    generations = [collect(g) for g in (24, 25)]
    priority = read(E / 'priority-helper-contexts.json')
    anchors = {key: value for key, value in source.items()
               if key.startswith('commb_semantic_') and key.endswith('_anchor') and value}
    maps = [r for r in priority['rows'] if r['symbol'] in anchors.values()]
    contexts = [r for r in priority['contexts'] if r['symbol'] in anchors.values()]
    # The inspected changed map has no direct second scalar decode/layout/search.
    oracle = source['commb_semantic_oracle_values_anchor']
    forbidden = {P + n for n in ('payloadValue', 'commBLayout', 'findPayloadField')}
    assert all(child['calls'] == 0 for row in maps if row['symbol'] == oracle
               for child in row['direct_children'] if child['symbol'] in forbidden)
    result = {'status': 'passed', 'kind': 'retained_semantic_payload_callers_and_constructor_boundaries',
              'generations': generations, 'current_shared_map_anchors': anchors,
              'current_shared_map_rows': maps, 'current_shared_map_contexts': contexts,
              **{key: generations[-1][key] for key in ('payload_value_direct_callers', 'payload_value_total',
                    'semantic_commb', 'actual_float_constructor_helper_rows', 'contexts')},
              'bindings': {str(p): sha(p) for p in (Path(__file__), E / 'independent-review/source-review.json',
                           Path('Impl/Semantics.lean'), Path('Impl/CommB.lean'), Path('Impl/Presentation.lean'))},
              'limits': [
                  'Complete incoming/direct-edge observations retain caller context; inclusive ancestors and descendants overlap and cannot be added as savings.',
                  'Standard tableValues and labels were already shared in generated C. Current oracle scalars reuse table values; public commBValue remains live outside this semantic map.',
                  'Presentation_oracleCommBFloats and standard replacement construct exact numeric expressions; no new Float execution or callback change is introduced.',
                  'BDS30 empty and ordinary identity numeric-list branches inline. They have no standalone native counters; the BDS44 replacement map is independently callable.',
                  'Each generation reconciles observed semantic payloadValue entries and inclusive edges to its own helper accounting; equal populations are not assumed.',
                  'Source/native proof establishes the map structure, while profiles establish only observed corpus populations. No timing prediction follows.']}
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'sha256': sha(target), 'generations': [
        {'generation': g['generation'], 'callers': g['payload_value_direct_callers']} for g in generations]}))


if __name__ == '__main__':
    main()

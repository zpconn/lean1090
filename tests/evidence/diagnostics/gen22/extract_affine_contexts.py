#!/usr/bin/env python3
"""Compare actual affine normalization boundaries in retained generation 21/22 profiles."""
import sys
sys.dont_write_bytecode = True
from collections import Counter, defaultdict, deque
from pathlib import Path
import hashlib
import json

sys.path.insert(0, str(Path.cwd() / 'review/diagnostics'))
import analyze_callgrind as parser

BASE = Path('tests/evidence/diagnostics/gen22')
P = 'lp_lean1090_Lean1090_Impl_'
SELECTED = {P + name for name in ('payloadValue', 'affineValue', 'integerScale')}
SELECTED.update(('l_Rat_mul', 'l_Rat_normalize'))
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
read = lambda p: json.loads(Path(p).read_text())


def collect(generation):
    root = Path(f'tests/evidence/diagnostics/gen{generation}')
    analysis = read(root / 'analysis/analysis.json')
    groups, contexts, profiles = {}, [], {}
    for family, info in analysis['families'].items():
        raw = root / 'callgrind' / family / 'callgrind.out.1.gz'
        profiles[str(raw)] = sha(raw)
        profile = parser.parse(raw)
        labels = defaultdict(set)
        pending = deque((name, 'output_model_control') for name in profile.nodes
                        if parser.base_name(name) == parser.DECODE)
        while pending:
            name, inherited = pending.popleft()
            stage = parser.stage_for(name, inherited)
            if stage in labels[name]:
                continue
            labels[name].add(stage)
            pending.extend((child, stage) for child, events in profile.nodes[name].edges.items()
                           if any(events.values()))
        observed = {}
        for name, node in profile.nodes.items():
            symbol = parser.base_name(name)
            if symbol not in SELECTED or len(labels[name]) != 1:
                continue
            stage = next(iter(labels[name]))
            incoming = [{'caller': caller, 'calls': parent.calls.get(name, 0),
                         'inclusive_ir_non_additive': parent.edges[name].get('Ir', 0)}
                        for caller, parent in profile.nodes.items() if name in parent.edges]
            values = Counter(contexts=1, self_ir=node.own.get('Ir', 0),
                             native_entries=sum(row['calls'] for row in incoming),
                             incoming_inclusive_ir_non_additive=sum(row['inclusive_ir_non_additive'] for row in incoming))
            observed.setdefault((stage, symbol), Counter()).update(values)
            group = groups.setdefault((stage, symbol), {'counts': Counter(), 'children': defaultdict(Counter)})
            group['counts'].update(values)
            outgoing = []
            for child, events in node.edges.items():
                if not any(events.values()):
                    continue
                edge = {'context': child, 'symbol': parser.base_name(child),
                        'calls': node.calls.get(child, 0),
                        'inclusive_ir_non_additive': events.get('Ir', 0)}
                outgoing.append(edge)
                group['children'][edge['symbol']].update(calls=edge['calls'],
                    inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
            contexts.append({'family': family, 'stage': stage, 'symbol': symbol, 'context': name,
                             'self_ir': node.own.get('Ir', 0), 'incoming': incoming, 'outgoing': outgoing})
        expected = {(stage, row['symbol']): Counter(
            contexts=row['contexts'], self_ir=row['self_events'].get('Ir', 0),
            native_entries=row['native_entries'],
            incoming_inclusive_ir_non_additive=row['incoming_inclusive_events_non_additive'].get('Ir', 0))
            for stage, rows in info['stage_helper_observations_non_additive'].items()
            for row in rows if row['symbol'] in SELECTED}
        assert observed == expected, (generation, family)
    rows = [{'stage': stage, 'symbol': symbol, **group['counts'],
             'direct_children': [{'symbol': child, **values}
                                 for child, values in sorted(group['children'].items())]}
            for (stage, symbol), group in sorted(groups.items())]
    power = [dict(stage=row['stage'], caller=row['symbol'], **child)
             for row in rows for child in row['direct_children'] if child['symbol'] == 'lean_nat_pow']
    return {'generation': generation, 'rows': rows, 'contexts': contexts,
            'direct_power_edges': power,
            'direct_power_totals': {'calls': sum(row['calls'] for row in power),
                'inclusive_ir_non_additive': sum(row['inclusive_ir_non_additive'] for row in power)},
            'profile_sha256': profiles, 'analysis_sha256': sha(root / 'analysis/analysis.json'),
            'source_review_sha256': sha(root / 'independent-review/source-review.json'),
            'unobserved_selected_symbols': sorted(SELECTED - {row['symbol'] for row in rows})}


def main():
    out = BASE / 'affine-native-contexts.json'
    assert not out.exists()
    source = read(BASE / 'independent-review/source-review.json')
    assert source['integer_affine_normalization_live_path_verified']
    assert source['payload_value_anchor'] == P + 'payloadValue'
    generations = [collect(generation) for generation in (21, 22)]
    payload_rows = [[row for row in generation['rows'] if row['symbol'] == P + 'payloadValue'] for generation in generations]
    assert {row['stage']: row['native_entries'] for row in payload_rows[0]} == {row['stage']: row['native_entries'] for row in payload_rows[1]}
    assert all(child['calls'] == 0 for row in payload_rows[1] for child in row['direct_children'] if child['symbol'] == 'l_Rat_mul')
    result = {'status': 'passed', 'kind': 'actual_affine_normalization_boundary_and_direct_edge_comparison',
              'generations': generations, 'selected_symbols': sorted(SELECTED),
              'extractor_sha256': sha(__file__), 'parser_sha256': sha('review/diagnostics/analyze_callgrind.py'),
              'same_payload_value_entries_by_stage': True,
              'limits': [
                  'Only the three disjoint full-decoder families are summed; candidate and score probes remain separate overlapping diagnostics.',
                  'Stage ownership uses the unchanged exclusive attribution algorithm; selected groups reconcile all entry/self/inclusive measures to each generation helper analysis.',
                  'Current source/native inspection verifies integerScale and affineValue inline into callable payloadValue; no standalone helper hits are inferred.',
                  'Actual payloadValue-to-Rat.mul calls and direct normalization descendants are recounted in both generations; zero current direct Rat.mul calls do not mean no integer multiplication or rational normalization work.',
                  'Normalization product, gcd and exact-division operations can inline or take small-value branches. Direct child calls do not by themselves count every nonunit-scale input or logical normalization.',
                  'Inclusive rows and direct descendants overlap ancestors and each other; only self costs by unique stage partition the collection.',
                  'All-input proof and retained status/identity/offset guards establish semantics; corpus counts do not replace those proofs or measure arbitrary unseen fields.',
                  'No timing explanation or throughput prediction follows from these instruction observations.']}
    out.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'generations': [
        {'generation': g['generation'], 'contexts': len(g['contexts']), **g['direct_power_totals']}
        for g in generations], 'sha256': sha(out)}))


if __name__ == '__main__':
    main()

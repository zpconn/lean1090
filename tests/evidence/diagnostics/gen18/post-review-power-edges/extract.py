#!/usr/bin/env python3
"""Post-review, existing-profile power edges; no decoder or source changes."""
import sys
sys.dont_write_bytecode = True
from collections import Counter, defaultdict, deque
from pathlib import Path
import hashlib
import json

sys.path.insert(0, str(Path.cwd() / 'review/diagnostics'))
import analyze_callgrind as parser

BASE = Path('tests/evidence/diagnostics/gen18')
OUT = BASE / 'post-review-power-edges/contexts.json'
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
P = 'lp_lean1090_Lean1090_Impl_'
SELECTED = {P + n for n in ('Altitude_bit', 'Altitude_grayDecode',
                           'identityCode', 'identityCode___lam__0', 'payloadInteger')}
SELECTED.add('lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0')


def main():
    assert not OUT.exists()
    analysis_path = BASE / 'analysis/analysis.json'
    analysis = json.loads(analysis_path.read_text())
    seals = [BASE / 'archive-manifest.json', BASE / 'validation.json',
             BASE / 'independent-review/independent-review.json',
             Path('docs/GEN18-COST-BREAKDOWN.md')]
    before = {str(p): sha(p) for p in seals}
    assert json.loads(seals[2].read_text())['status'] == 'passed'
    groups, contexts, profiles = defaultdict(Counter), [], {}
    for family, info in analysis['families'].items():
        raw = BASE / 'callgrind' / family / 'callgrind.out.1.gz'
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
            count = Counter(contexts=1, self_ir=node.own.get('Ir', 0),
                            native_entries=sum(x['calls'] for x in incoming),
                            incoming_inclusive_ir_non_additive=sum(x['inclusive_ir_non_additive'] for x in incoming))
            observed.setdefault((stage, symbol), Counter()).update(count)
            outgoing = []
            for child, events in node.edges.items():
                if not any(events.values()):
                    continue
                edge = {'context': child, 'symbol': parser.base_name(child),
                        'calls': node.calls.get(child, 0),
                        'inclusive_ir_non_additive': events.get('Ir', 0)}
                outgoing.append(edge)
                groups[stage, symbol, edge['symbol']].update(
                    calls=edge['calls'], inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
            contexts.append({'family': family, 'stage': stage, 'symbol': symbol,
                             'context': name, 'self_ir': node.own.get('Ir', 0),
                             'incoming': incoming, 'outgoing': outgoing})
        expected = {(stage, row['symbol']): Counter(
            contexts=row['contexts'], self_ir=row['self_events'].get('Ir', 0),
            native_entries=row['native_entries'],
            incoming_inclusive_ir_non_additive=row['incoming_inclusive_events_non_additive'].get('Ir', 0))
            for stage, rows in info['stage_helper_observations_non_additive'].items()
            for row in rows if row['symbol'] in SELECTED}
        assert observed == expected, family
    rows = [dict(stage=k[0], caller=k[1], callee=k[2], **v)
            for k, v in sorted(groups.items())]
    power = [r for r in rows if r['callee'] == 'lean_nat_pow']
    assert {str(p): sha(p) for p in seals} == before
    result = {'status': 'passed', 'kind': 'post_review_existing_profile_bit_power_edges',
              'profile_sha256': profiles, 'analysis_sha256': sha(analysis_path),
              'script_sha256': sha(__file__), 'parser_sha256': sha('review/diagnostics/analyze_callgrind.py'),
              'sealed_producer_artifacts_unchanged': before,
              'runtime_source_sha256': {p: sha(p) for p in
                  ['Impl/Altitude.lean', 'Impl/Frame.lean', 'Impl/PayloadBits.lean']},
              'direct_power_edges': power, 'all_selected_direct_edges': rows,
              'contexts': contexts,
              'summed_direct_power_edge_observations': {
                  'calls': sum(r['calls'] for r in power),
                  'inclusive_ir_non_additive': sum(r['inclusive_ir_non_additive'] for r in power)},
              'limits': [
                  'Only the three disjoint full-decoder family profiles are aggregated, not overlapping register probes.',
                  'Caller stages use the unchanged exclusive attribution algorithm; selected caller totals reconcile to the independently reviewed helper analysis.',
                  'Incoming inclusive and direct-child costs overlap ancestors/descendants and can repeat recursive visits; the sum is an edge observation, not a new exclusive partition or predicted saving.',
                  'This separate post-review supplement leaves all sealed report, validation, archive and independent-review bytes unchanged. No runtime execution or optimization is performed.']}
    OUT.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'power_rows': len(power), 'contexts': len(contexts),
                      'totals': result['summed_direct_power_edge_observations'], 'sha256': sha(OUT)}))


if __name__ == '__main__':
    main()

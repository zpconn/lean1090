#!/usr/bin/env python3
"""Selected actual helper contexts and direct edges; no new decoder execution."""
import sys
sys.dont_write_bytecode = True
from collections import Counter, defaultdict, deque
import hashlib
import importlib.util
import json
from pathlib import Path

E = Path('tests/evidence/diagnostics/gen24')
P = 'lp_lean1090_Lean1090_Impl_'
sha = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
read = lambda path: json.loads(Path(path).read_text())


def main():
    out = E / 'priority-helper-contexts.json'
    assert not out.exists()
    analysis = read(E / 'analysis/analysis.json')
    source = read(E / 'independent-review/source-review.json')
    parser = Path('review/diagnostics/analyze_callgrind.py')
    spec = importlib.util.spec_from_file_location('gen24_priority_parser', parser)
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    selected = {P + name for name in (
        'ScoreGate_choose', 'ScoreGate_commonDenominator', 'ScoreGate_scaledNumerator',
        'ScoreGate_scaledTotals', 'bdsWireValid', 'payloadValue', 'affineValue',
        'decodeFrameWithWord', 'decodeFrame', 'frameSyndrome', 'frameParts', 'acasParts', 'surveillanceParts', 'Semantics_tableValues', 'Semantics_commB', 'Semantics_commBStandardFloats', 'Presentation_oracleCommBFloats', 'commBValue', 'findPayloadField', 'cbSelectedValid40', 'cbQNHValid40', 'cbRollValid50', 'cbMachValid60', 'cbVerticalValid60', 'Semantics_adsb', 'reportWithSyndrome', 'integerScale', 'Parity_syndrome', 'Parity_checksum', 'bytesValue', 'packFields', 'field')}
    selected.update(source['integer_score_gate_anchors'].values())
    selected.update((source['parity_fold_anchor'], source['pack_fields_fold_anchor'],
                     'l_Rat_mul', 'l_Rat_add', 'l_Rat_div'))
    selected.update(value for key, value in source.items() if key.startswith('commb_semantic_') and key.endswith('_anchor') and value)
    selected.discard(None)
    selected.update(row['symbol'] for profile in analysis['families'].values()
                    for rows in profile['stage_helper_observations_non_additive'].values()
                    for row in rows if row['symbol'].startswith(P + 'cbValid'))
    groups, contexts, inputs = {}, [], {}
    for family, info in analysis['families'].items():
        path = E / 'callgrind' / family / 'callgrind.out.1.gz'
        inputs[str(path)] = sha(path)
        profile = module.parse(path)
        labels = defaultdict(set)
        pending = deque((name, 'output_model_control') for name in profile.nodes
                        if module.base_name(name) == module.DECODE)
        while pending:
            name, inherited = pending.popleft()
            stage = module.stage_for(name, inherited)
            if stage in labels[name]:
                continue
            labels[name].add(stage)
            pending.extend((child, stage) for child, events in profile.nodes[name].edges.items()
                           if any(events.values()))
        local = {}
        for name, node in profile.nodes.items():
            symbol = module.base_name(name)
            if symbol not in selected or len(labels[name]) != 1:
                continue
            stage = next(iter(labels[name]))
            incoming = [{'caller': caller, 'calls': parent.calls.get(name, 0),
                         'inclusive_ir_non_additive': parent.edges[name].get('Ir', 0)}
                        for caller, parent in profile.nodes.items() if name in parent.edges]
            outgoing = [{'context': child, 'symbol': module.base_name(child),
                         'calls': node.calls.get(child, 0), 'inclusive_ir_non_additive': events.get('Ir', 0)}
                        for child, events in node.edges.items() if any(events.values())]
            values = Counter(contexts=1, self_ir=node.own.get('Ir', 0),
                             native_entries=sum(row['calls'] for row in incoming),
                             incoming_inclusive_ir_non_additive=sum(row['inclusive_ir_non_additive'] for row in incoming))
            local.setdefault((stage, symbol), Counter()).update(values)
            group = groups.setdefault((stage, symbol), {'counts': Counter(), 'children': defaultdict(Counter)})
            group['counts'].update(values)
            for row in outgoing:
                group['children'][row['symbol']].update(calls=row['calls'], inclusive_ir_non_additive=row['inclusive_ir_non_additive'])
            contexts.append({'family': family, 'stage': stage, 'symbol': symbol, 'context': name,
                             'self_ir': node.own.get('Ir', 0), 'incoming': incoming, 'outgoing': outgoing})
        expected = {(stage, row['symbol']): Counter(contexts=row['contexts'], self_ir=row['self_events'].get('Ir', 0),
                    native_entries=row['native_entries'], incoming_inclusive_ir_non_additive=row['incoming_inclusive_events_non_additive'].get('Ir', 0))
                    for stage, rows in info['stage_helper_observations_non_additive'].items()
                    for row in rows if row['symbol'] in selected}
        assert local == expected, family
    rows = [{'stage': stage, 'symbol': symbol, **group['counts'],
             'direct_children': [{'symbol': child, **values} for child, values in sorted(
                 group['children'].items(), key=lambda item: item[1]['inclusive_ir_non_additive'], reverse=True)]}
            for (stage, symbol), group in groups.items()]
    rows.sort(key=lambda row: (row['stage'], -row['incoming_inclusive_ir_non_additive']))
    result = {'status': 'passed', 'kind': 'selected_unique_stage_helpers_and_actual_direct_call_edges',
              'rows': rows, 'contexts': contexts, 'profile_hashes': inputs,
              'analysis_sha256': sha(E / 'analysis/analysis.json'),
              'source_review_sha256': sha(E / 'independent-review/source-review.json'),
              'parser_sha256': sha(parser), 'extractor_sha256': sha(__file__),
              'unobserved_selected_symbols': sorted(selected - {row['symbol'] for row in rows}),
              'limits': [
                  'Only the three disjoint family profiles are aggregated. Register probes are separate overlapping evidence.',
                  'Self costs retain unique caller-stage attribution. Inclusive incoming costs overlap ancestors, descendants and recursive visits, including within a row.',
                  'Direct children are actual positive-cost call boundaries; inline arithmetic has no separate entry count. Descendants may cross stage boundaries.',
                  'Rational multiplication rows describe observed native boundaries, not all logical affine multiplications. Missing symbols are not zero work.',
                  'Selected helpers support prioritization but do not establish a throughput effect or select an implementation change.']}
    out.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'rows': len(rows), 'contexts': len(contexts), 'sha256': sha(out)}))


if __name__ == '__main__':
    main()

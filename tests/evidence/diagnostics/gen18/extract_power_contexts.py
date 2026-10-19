#!/usr/bin/env python3
"""Recount actual power lookup/formula contexts from existing gen17/18 profiles."""
import sys
sys.dont_write_bytecode = True
from collections import Counter
import hashlib
import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
E = ROOT / 'tests/evidence/diagnostics/gen18'


def read(path):
    return json.loads(path.read_text())


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = E / 'power-native-contexts.json'
    assert not target.exists()
    source = read(E / 'independent-review/source-review.json')
    assert source['power_two_table_live_path_verified']
    keys = ('lookup', 'formula', 'table_entry', 'table_initializer', 'module_initializer')
    anchors = {key: source['power_two_' + key + '_anchor'] for key in keys}
    assert all(isinstance(symbol, str) and symbol for symbol in anchors.values())
    parser = ROOT / 'review/diagnostics/analyze_callgrind.py'
    spec = importlib.util.spec_from_file_location('gen18_power_parser', parser)
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    rows, contexts = [], []
    modes = ['adsb', 'commb', 'other'] + [kind + register for kind in ('candidate', 'score')
             for register in ('40', '44', '45', '50', '60')]
    for generation in (17, 18):
        root = ROOT / f'tests/evidence/diagnostics/gen{generation}'
        analysis = read(root / 'analysis/analysis.json')
        for mode in modes:
            path = root / 'callgrind' / mode / 'callgrind.out.1.gz'
            profile = module.parse(path)
            info = (analysis['families'][mode] if mode in ('adsb', 'commb', 'other') else
                    analysis['non_additive_register_' + ('candidate' if mode.startswith('candidate') else 'score') + '_probes'][mode.removeprefix('candidate').removeprefix('score')])
            row = {'generation': generation, 'profile': mode, 'profile_sha256': sha(path),
                   'direct_lookup_formula_calls': 0, 'direct_lookup_formula_inclusive_ir_non_additive': 0}
            for label, symbol in anchors.items():
                totals = Counter(native_entries=0, self_ir=0, incoming_inclusive_ir_non_additive=0)
                for name in sorted(profile.nodes):
                    if module.base_name(name) != symbol:
                        continue
                    node = profile.nodes[name]
                    incoming = [{'caller': caller, 'native_entries': value.calls.get(name, 0),
                                 'inclusive_ir_non_additive': value.edges[name].get('Ir', 0)}
                                for caller, value in profile.nodes.items() if name in value.edges]
                    outgoing = [{'callee': callee, 'symbol': module.base_name(callee),
                                 'native_entries': node.calls.get(callee, 0),
                                 'inclusive_ir_non_additive': events.get('Ir', 0)}
                                for callee, events in node.edges.items() if any(events.values())]
                    contexts.append({'generation': generation, 'profile': mode, 'anchor': label,
                                     'context': name, 'self_ir': node.own.get('Ir', 0),
                                     'incoming': incoming, 'outgoing': outgoing})
                    totals.update(native_entries=sum(edge['native_entries'] for edge in incoming),
                                  self_ir=node.own.get('Ir', 0),
                                  incoming_inclusive_ir_non_additive=sum(edge['inclusive_ir_non_additive'] for edge in incoming))
                    if label == 'lookup':
                        edges = [edge for edge in outgoing if edge['symbol'] == anchors['formula']]
                        row['direct_lookup_formula_calls'] += sum(edge['native_entries'] for edge in edges)
                        row['direct_lookup_formula_inclusive_ir_non_additive'] += sum(edge['inclusive_ir_non_additive'] for edge in edges)
                grouped = [helper for helpers in info['stage_helper_observations_non_additive'].values()
                           for helper in helpers if helper['symbol'] == symbol]
                assert totals['self_ir'] == sum(helper['self_events'].get('Ir', 0) for helper in grouped)
                assert totals['native_entries'] == sum(helper['native_entries'] for helper in grouped)
                assert totals['incoming_inclusive_ir_non_additive'] == sum(helper['incoming_inclusive_events_non_additive'].get('Ir', 0) for helper in grouped)
                row[label] = dict(totals)
            if generation == 18:
                assert row['direct_lookup_formula_calls'] <= row['lookup']['native_entries']
                for label in ('table_entry', 'table_initializer', 'module_initializer'):
                    assert row[label]['native_entries'] == 0 and row[label]['self_ir'] == 0
            rows.append(row)
    result = {'kind': 'actual_power_lookup_formula_and_initialization_call_contexts',
              'source_review_sha256': sha(E / 'independent-review/source-review.json'),
              'parser_sha256': sha(parser), 'anchors': anchors, 'rows': rows, 'contexts': contexts,
              'limits': [
                  'Each incoming inclusive row can overlap callers, descendants and recursive visits; only exclusive stage self costs are additive.',
                  'Candidate and score probes overlap each other and family work; never sum them as a corpus partition.',
                  'Formula calls are observed direct lookup edges. No table-hit frequency is inferred from inclusive cost or an absent symbol.',
                  'The native lookup has two mutually exclusive out-of-range formula sites and at most one dynamic formula call per invocation.',
                  'The full table is forced and made persistent during module initialization before main. Unobserved constructor entries inside collected roots do not mean zero startup work.',
                  'Both generations retain the same lookup/formula/table boundaries; only their actual observed calls and costs are compared. No wall-clock effect is inferred.']}
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'rows': len(rows), 'contexts': len(contexts), 'sha256': sha(target)}))


if __name__ == '__main__':
    main()

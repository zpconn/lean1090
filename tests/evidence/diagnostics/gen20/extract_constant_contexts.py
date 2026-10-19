#!/usr/bin/env python3
"""Recount live Comm-B guard contexts in retained gen19/gen20 profiles only."""
import sys
sys.dont_write_bytecode = True
from collections import Counter
import hashlib
import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
E = ROOT / 'tests/evidence/diagnostics/gen20'
SYMBOL = 'lp_lean1090_Lean1090_Impl_bdsWireValid'


def read(path):
    return json.loads(path.read_text())


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = E / 'constant-native-contexts.json'
    assert not target.exists()
    source = read(E / 'independent-review/source-review.json')
    assert source['commb_payload_limit_live_path_verified']
    parser = ROOT / 'review/diagnostics/analyze_callgrind.py'
    spec = importlib.util.spec_from_file_location('gen20_constant_parser', parser)
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    rows, contexts, previous = [], [], {}
    modes = ['adsb', 'commb', 'other'] + [kind + register for kind in ('candidate', 'score')
             for register in ('40', '44', '45', '50', '60')]
    for generation in (19, 20):
        root = ROOT / f'tests/evidence/diagnostics/gen{generation}'
        analysis = read(root / 'analysis/analysis.json')
        for mode in modes:
            path = root / 'callgrind' / mode / 'callgrind.out.1.gz'
            profile = module.parse(path)
            info = (analysis['families'][mode] if mode in ('adsb', 'commb', 'other') else
                    analysis['non_additive_register_' + ('candidate' if mode.startswith('candidate') else 'score') + '_probes'][mode.removeprefix('candidate').removeprefix('score')])
            names = {name for name in profile.nodes if module.base_name(name) == SYMBOL}
            totals = Counter(native_entries=0, self_ir=0, inclusive_ir_non_additive=0,
                             direct_parser_calls=0, direct_parser_ir_non_additive=0)
            for name in sorted(names):
                node = profile.nodes[name]
                incoming = [{'caller': caller, 'native_entries': value.calls.get(name, 0),
                             'inclusive_ir_non_additive': value.edges.get(name, {}).get('Ir', 0)}
                            for caller, value in profile.nodes.items() if name in value.edges]
                outgoing = [{'callee': callee, 'symbol': module.base_name(callee),
                             'native_entries': node.calls.get(callee, 0),
                             'inclusive_ir_non_additive': events.get('Ir', 0)}
                            for callee, events in node.edges.items() if any(events.values())]
                own = node.own.get('Ir', 0)
                contexts.append({'generation': generation, 'profile': mode, 'context': name,
                                 'self_ir': own, 'incoming': incoming, 'outgoing': outgoing})
                totals.update(native_entries=sum(row['native_entries'] for row in incoming), self_ir=own,
                              inclusive_ir_non_additive=sum(row['inclusive_ir_non_additive'] for row in incoming),
                              direct_parser_calls=sum(row['native_entries'] for row in outgoing if row['symbol'] == 'lean_cstr_to_nat'),
                              direct_parser_ir_non_additive=sum(row['inclusive_ir_non_additive'] for row in outgoing if row['symbol'] == 'lean_cstr_to_nat'))
            grouped = [row for helpers in info['stage_helper_observations_non_additive'].values()
                       for row in helpers if row['symbol'] == SYMBOL]
            assert totals['self_ir'] == sum(row['self_events'].get('Ir', 0) for row in grouped)
            assert totals['native_entries'] == sum(row['native_entries'] for row in grouped)
            assert totals['inclusive_ir_non_additive'] == sum(row['incoming_inclusive_events_non_additive'].get('Ir', 0) for row in grouped)
            if generation == 19:
                previous[mode] = totals['native_entries']
            else:
                assert totals['native_entries'] == previous[mode], mode
                assert totals['direct_parser_calls'] == 0, mode
            rows.append({'generation': generation, 'profile': mode, **totals,
                         'profile_sha256': sha(path)})
    output = {'kind': 'actual_commb_guard_and_direct_parser_context_observations',
              'source_review_sha256': sha(E / 'independent-review/source-review.json'), 'parser_sha256': sha(parser),
              'rows': rows, 'contexts': contexts, 'same_guard_call_populations': True,
              'current_guard_direct_parser_calls_zero': True,
              'limits': ['Exact self costs are distinct from incoming inclusive observations; inclusive callers and descendants overlap.',
                         'Each family or register probe is an independent process/context; probe costs must not be added to the whole corpus.',
                         'The retained source/native evidence establishes eager global initialization. Direct parser absence in the live guard does not imply zero startup construction.',
                         'No time, cycle, throughput or benchmark-regression explanation is inferred.']}
    target.write_text(json.dumps(output, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'rows': len(rows), 'contexts': len(contexts), 'sha256': sha(target)}))


if __name__ == '__main__':
    main()

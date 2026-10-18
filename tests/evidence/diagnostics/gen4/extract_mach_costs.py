#!/usr/bin/env python3
"""Extract supplemental Mach/penalty observations from existing gen4 profiles."""
from collections import Counter
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

E = Path('tests/evidence/diagnostics/gen4')
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    path = E / 'analysis/analysis.json'
    analysis = json.loads(path.read_text())
    stages = list(analysis['stage_definitions'])
    family_rows = []
    for stage in stages:
        for short in ('cbMach64', 'cbPenalty'):
            counts = Counter()
            sources = []
            for family, profile in analysis['families'].items():
                for row in profile['stage_helper_observations_non_additive'].get(stage, []):
                    if row['symbol'] == P + short:
                        sources.append({'family': family, **row})
                        counts.update(native_entries=row['native_entries'], self_ir=row['self_events'].get('Ir', 0),
                                      inclusive_ir=row['incoming_inclusive_events_non_additive'].get('Ir', 0))
            family_rows.append({'stage': stage, 'symbol': P + short,
                                'observed_contexts': bool(sources), 'totals': dict(counts), 'source_rows': sources})
    probes = []
    for kind in ('candidate', 'score'):
        for register, profile in analysis[f'non_additive_register_{kind}_probes'].items():
            matching = [row for rows in profile['stage_helper_observations_non_additive'].values() for row in rows
                        if row['symbol'] in (P + 'cbMach64', P + 'cbPenalty')]
            probes.append({'kind': kind, 'register': register, 'root_entries': profile['root_incoming_calls'],
                           'observed_symbol_rows': matching})
    spec = importlib.util.spec_from_file_location('mach_callgrind', 'review/diagnostics/analyze_callgrind.py')
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    rawpath = E / 'callgrind/commb/callgrind.out.1.gz'
    profile = module.parse(rawpath)
    contexts = []
    for name, node in profile.nodes.items():
        if module.base_name(name) != P + 'cbMach64':
            continue
        incoming = []
        for caller, caller_node in profile.nodes.items():
            if name in caller_node.calls:
                incoming.append({'caller': caller, 'calls': caller_node.calls[name],
                                 'inclusive_events': dict(caller_node.edges.get(name, {}))})
        contexts.append({'symbol_with_callers': name, 'self_events': dict(node.own), 'incoming': incoming,
                         'outgoing': [{'target': target, 'calls': node.calls[target],
                                       'inclusive_events': dict(events)} for target, events in node.edges.items()
                                      if any(events.values())]})
    aggregate = Counter()
    for context in contexts:
        aggregate.update(self_ir=context['self_events'].get('Ir', 0))
        for edge in context['incoming']:
            aggregate.update(native_entries=edge['calls'], inclusive_ir=edge['inclusive_events'].get('Ir', 0))
    grouped = next(row for row in family_rows if row['stage'] == 'commb_inference' and row['symbol'] == P + 'cbMach64')
    assert dict(aggregate) == grouped['totals']
    result = {
        'kind': 'supplemental_existing_profile_extraction_not_benchmark', 'generation': 4,
        'no_native_execution_or_source_changes': True,
        'analysis': str(path), 'analysis_sha256': sha(path), 'raw_profile': str(rawpath), 'raw_profile_sha256': sha(rawpath),
        'extractor_sha256': sha(__file__), 'unique_stage_observations': family_rows, 'register_probes': probes,
        'full_commb_mach_contexts': contexts, 'raw_context_totals_match_grouped_analysis': True,
        'limits': ['All inclusive observations overlap other helpers and the exclusive stages.',
                   'Candidate/score probes are separate executions and cannot be subtracted as exact partitions.',
                   'No observed symbol is not a claim that semantically similar inlined computation is absent.',
                   'No elapsed-time, cycle or predicted-throughput conclusion.']}
    output = E / 'mach-penalty-observations.json'
    assert not output.exists()
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'output': str(output), 'sha256': sha(output), 'contexts': len(contexts), 'raw_totals': dict(aggregate)}))


if __name__ == '__main__':
    main()

#!/usr/bin/env python3
"""Compare actual CRC loop boundaries in retained generation 19/20 profiles."""
import sys
sys.dont_write_bytecode = True
from collections import Counter, defaultdict, deque
from pathlib import Path
import hashlib
import json

sys.path.insert(0, str(Path.cwd() / 'review/diagnostics'))
import analyze_callgrind as parser

BASE = Path('tests/evidence/diagnostics/gen20')
P = 'lp_lean1090_Lean1090_Impl_'
SOURCES = {g: json.loads(Path(f'tests/evidence/diagnostics/gen{g}/independent-review/source-review.json').read_text()) for g in (19, 20)}
SELECTED = {P + name for name in ('Parity_syndrome', 'Parity_syndromeBytes', 'Parity_syndromeBits', 'Parity_step', 'Parity_byteStep', 'Parity_cachedByte')}
SELECTED.update(value for source in SOURCES.values() for key, value in source.items() if key.startswith('parity_') and key.endswith('_anchor'))
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
    out = BASE / 'crc-byte-contexts.json'
    assert not out.exists()
    source = SOURCES[20]
    assert source['byte_crc_live_path_verified'] and source['word_crc_live_path_verified']
    generations = [collect(generation) for generation in (19, 20)]
    analysis = read(BASE / 'analysis/analysis.json')
    campaign = read(BASE / 'campaign.json')
    census = {row['df']: row for row in campaign['live_crc_census']['per_df']}
    families = {'adsb': (17, 18), 'commb': (20, 21), 'other': tuple(df for df in range(32) if df not in (17, 18, 20, 21))}
    profiles = {**analysis['families'], **{kind + register: profile for kind in ('candidate', 'score') for register, profile in analysis['non_additive_register_' + kind + '_probes'].items()}}
    rows = []
    keys = ('parity_byte_wrapper_anchor', 'parity_byte_fold_anchor', 'parity_bit_wrapper_anchor', 'parity_bit_fold_anchor')
    for name, profile in profiles.items():
        anchors = profile['native_anchor_counts_and_non_additive_inclusive_events']
        expected = sum(census[df]['crc_call_predictions'] for df in families.get(name, ()))
        bit_updates = sum(census[df]['crc_step_predictions'] for df in families.get(name, ()))
        assert bit_updates % 8 == 0
        observed = {key: anchors.get(source[key], {}).get('native_entries', 0) for key in keys}
        assert observed['parity_byte_wrapper_anchor'] == observed['parity_byte_fold_anchor'] == expected, (name, observed, expected)
        assert observed['parity_bit_wrapper_anchor'] == observed['parity_bit_fold_anchor'] == 0, (name, observed)
        assert anchors.get(P + 'Parity_step', {}).get('native_entries', 0) == 0
        rows.append({'profile': name, 'expected_crc_calls_from_checked_census': expected,
                     'predicted_byte_iterations_not_native_entries': bit_updates // 8,
                     'predicted_bit_updates_not_native_entries': bit_updates, 'observed_native_entries': observed})
    result = {'status': 'passed', 'kind': 'actual_crc_byte_and_fallback_boundary_contexts',
              'generations': generations, 'selected_symbols': sorted(SELECTED), 'native_counts': rows,
              'extractor_sha256': sha(__file__), 'parser_sha256': sha('review/diagnostics/analyze_callgrind.py'),
              'source_review_sha256': sha(BASE / 'independent-review/source-review.json'),
              'checked_live_crc_census': campaign['live_crc_census'],
              'limits': [
                  'Only the three disjoint full-decoder families are summed. All ten candidate/score probes are separately checked and overlap full-decoder work.',
                  'Native entries and direct edges are actual collected boundaries. Byte iterations and equivalent bit updates are separate predictions from the accepted-corpus widths, not measured inlined-step calls.',
                  'The generic bit-loop and wrapper are callable in the actual binary but unobserved in this 7/14-byte accepted corpus. All-input proofs retain arbitrary widths and values.',
                  'Stage ownership uses the unchanged exclusive attribution algorithm; each selected caller group reconciles to its generation helper analysis.',
                  'Incoming inclusive costs overlap ancestors, descendants and recursive visits; only self costs by unique stage partition the collection.',
                  'The byte step and cached-byte extraction inline into the loop. Missing standalone boundaries do not imply absent work or allocation-free execution.',
                  'No wall-clock explanation or performance projection follows from these instruction counts.']}
    out.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'profiles': len(rows), 'contexts': {g['generation']: len(g['contexts']) for g in generations}, 'sha256': sha(out)}))


if __name__ == '__main__':
    main()

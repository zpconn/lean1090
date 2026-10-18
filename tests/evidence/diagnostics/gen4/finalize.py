#!/usr/bin/env python3
"""Archive and render the completed gen4 diagnostic; never run a decoder."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

E = Path('tests/evidence/diagnostics/gen4')
C = Path('.cache/gen5-planning')
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def save(path, value):
    text = json.dumps(value, indent=2) + '\n'
    if path.exists():
        assert path.read_text() == text, str(path)
    else:
        path.write_text(text)


def run(argv, label):
    result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    for suffix, value in (('stdout', result.stdout), ('stderr', result.stderr)):
        path = E / (label + '.' + suffix)
        if path.exists():
            assert path.read_bytes() == value, str(path)
        else:
            path.write_bytes(value)
    assert result.returncode == 0, (label, result.returncode, result.stderr.decode())


def history():
    historical = read(E / 'historical-inputs.json')
    addition = read(E / 'historical-approved-addition.json')
    assert addition['path'] == 'bench/runs/gen4/results-review.json'
    paths = {str(p) for root in historical['roots'] for p in Path(root).rglob('*') if p.is_file()}
    paths.update(historical['individual_paths'])
    assert paths == set(historical['files']) | {addition['path']}, 'unapproved historical membership change'
    for name, item in historical['files'].items():
        assert sha(name) == item['sha256'] and Path(name).stat().st_size == item['bytes'], name
    assert sha(addition['path']) == addition['sha256'], 'approved review changed'
    return len(historical['files'])


def main():
    assert not (E / 'validation.json').exists(), 'preserve completed validation'
    campaign = read(C / 'campaign.json')
    assert campaign['status'] == 'passed' and len(campaign['profiles']) == 13
    history_count = history()
    source = read(E / 'source-review.json')
    previous_build = read('tests/evidence/diagnostics/gen3/driver/driver-build.json')
    current_build = read(C / 'driver/driver-build.json')
    commb_object = '.lake/build/ir/Impl/CommB.c.o.export'
    assert current_build['reused_production_objects'][commb_object] == previous_build['reused_production_objects'][commb_object]
    run([sys.executable, 'review/diagnostics/analyze_callgrind.py', '--self-test'], 'parser-fixtures')
    run([sys.executable, 'review/diagnostics/archive_cost_campaign.py', '--cache', str(C),
         '--output', str(E), '--perf-data', str(C / 'perf-gen4/perf.data'),
         '--extra-evidence', 'source-review.json', '--extra-evidence', 'source-inspection',
         '--extra-evidence', 'historical-inputs.json', '--extra-evidence', 'finalize.py',
         '--extra-evidence', 'historical-approved-addition.json',
         '--extra-evidence', 'parser-fixtures.stdout', '--extra-evidence', 'parser-fixtures.stderr'], 'archive')
    argv = [sys.executable, 'review/diagnostics/analyze_callgrind.py', '--generation', '4',
            '--output', str(E / 'analysis'), '--extra-anchor', source['exact_fallback_anchor'],
            '--extra-anchor', source['parity_fold_anchor'], '--extra-anchor', P + 'payloadBits']
    for family in ('adsb', 'commb', 'other'):
        argv.extend(['--profile', f'{family}={E}/callgrind/{family}/callgrind.out.1.gz'])
    for kind in ('candidate', 'score'):
        for register in ('40', '44', '45', '50', '60'):
            argv.extend(['--' + kind, f'{register}={E}/callgrind/{kind}{register}/callgrind.out.1.gz'])
    run(argv, 'analyze')
    analysis = read(E / 'analysis/analysis.json')
    previous = read('tests/evidence/diagnostics/gen3/analysis/analysis.json')
    helper_rows = []
    for stage in ('frame_crc', 'adsb_fields', 'commb_inference', 'semantic_oracle_values', 'output_model_control'):
        row = {'stage': stage}
        for label, record in (('gen3', previous), ('gen4', analysis)):
            counts = Counter()
            for family in record['families'].values():
                for helper in family['stage_helper_observations_non_additive'].get(stage, []):
                    if helper['symbol'] == P + 'payloadBits':
                        counts.update(entries=helper['native_entries'], self_ir=helper['self_events'].get('Ir', 0),
                                      inclusive_ir=helper['incoming_inclusive_events_non_additive'].get('Ir', 0))
            row[label] = dict(counts)
        helper_rows.append(row)
    save(E / 'payload-helper-comparison.json', {
        'kind': 'overlapping_native_symbol_observations_not_benchmark',
        'symbol': P + 'payloadBits', 'rows': helper_rows,
        'limits': 'Self costs by unique caller stage are exclusive; incoming inclusive edge counts overlap other helpers and can include recursive/re-entrant work. No elapsed-time inference.'})

    # Inspect actual outgoing call edges under each retained payloadBits context.
    # This is not branch instrumentation; exact powers are a source-bound marker
    # for the wide fallback, while inlined shifts stay in payloadBits self cost.
    spec = importlib.util.spec_from_file_location('callgrind_gen4', 'review/diagnostics/analyze_callgrind.py')
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    edge_rows = []
    for family in ('adsb', 'commb', 'other'):
        profile = module.parse(E / 'callgrind' / family / 'callgrind.out.1.gz')
        context_names = {name for name in profile.nodes if module.base_name(name) == P + 'payloadBits'}
        outgoing = Counter()
        for name in context_names:
            node = profile.nodes[name]
            for target, count in node.calls.items():
                if any(node.edges.get(target, {}).values()):
                    outgoing[module.base_name(target)] += count
        edge_rows.append({'family': family, 'payload_contexts': len(context_names),
                          'collected_outgoing_calls': dict(sorted(outgoing.items()))})
    save(E / 'payload-call-edges.json', {
        'kind': 'observed_positive_cost_outgoing_native_call_edges', 'rows': edge_rows,
        'limits': 'Only actual retained call boundaries are counted. Inlined instructions have no entry count. Wide-fallback conclusions also require the freshly bound C/assembly showing both Nat powers remain callable on that path.'})
    notes = [
        'Generation 4 changes payload extraction for widths below 64. The freshly bound generated C in `generated-c/Impl/PayloadBits.c` keeps UInt64 conversion, shifts and a mask in that branch; the original natural-power/division/remainder formula remains for arbitrary wider widths. The helper is inlined into the live `payloadBits` symbol. Its absence as a separate linked symbol is not zero extraction work. The source/native binding and assembly are retained in [source-review.json](../tests/evidence/diagnostics/gen4/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen4/source-inspection/).',
        '',
        'The three Comm-B source changes are erased bound proofs. Its freshly built native object remains byte-identical to generation 3. No runtime stage boundary changed; instruction deltas below compare the same corpus populations and live entry points.',
        '',
        'The following `payloadBits` observations group actual native symbols by their uniquely attributed stage. The inclusive costs overlap other helpers and do not form an additional cost partition or a predicted speedup. Complete observations are in [payload-helper-comparison.json](../tests/evidence/diagnostics/gen4/payload-helper-comparison.json).',
        '',
        '| Caller stage | Gen3 entries | Gen4 entries | Gen3 self Ir | Gen4 self Ir | Gen3 inclusive Ir | Gen4 inclusive Ir |',
        '|---|---:|---:|---:|---:|---:|---:|']
    for row in helper_rows:
        a, b = row['gen3'], row['gen4']
        if a or b:
            notes.append(f"| {row['stage']} | {a.get('entries', 0):,} | {b.get('entries', 0):,} | {a.get('self_ir', 0):,} | {b.get('self_ir', 0):,} | {a.get('inclusive_ir', 0):,} | {b.get('inclusive_ir', 0):,} |")
    powers = sum(row['collected_outgoing_calls'].get('lean_nat_pow', 0) for row in edge_rows)
    notes += ['', f'Across all three families, retained `payloadBits` contexts have **{powers:,}** observed outgoing calls to `lean_nat_pow`; the exact positive-cost outgoing edges are retained in [payload-call-edges.json](../tests/evidence/diagnostics/gen4/payload-call-edges.json). These are native call observations, not guessed field-width counts. The arbitrary-width fallback remains in source and native code even when a workload does not reach it.', '',
        'The CRC cached halves and original arbitrary-index fallback remain unchanged. The exact interval gate, callable boxed software fallback and 13 eagerly initialized immutable density arrays remain unchanged. Table construction occurs during module initialization before `main`, outside decoder-root collection and warmed benchmark loops. Other lazy scalar constants and separate allocator state may differ; no unmeasured correction is applied.', '',
        'Native perf capture completed before the native census and Callgrind workers began. Family and probe profiles then intentionally overlapped, with at most six active profiles. Other agents performed read-only evidence review and benchmark archival. No host-wide isolation or timing decomposition is claimed. Sampling exclusions, unknown frames and the explicitly reported lost-sample counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen4/perf/README.md).', '',
        'The largest-stage helper table retains raw inclusive incoming-edge observations. A recursive or re-entrant visit may overlap within one row, and descendants may cross a later stage boundary. Only self events form the exclusive partition; helper costs must not be added to it.']
    notes_path = E / 'context-notes.md'
    assert not notes_path.exists()
    notes_path.write_text('\n'.join(notes) + '\n')
    run([sys.executable, 'review/diagnostics/write_cost_report.py', '--generation', '4',
         '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
         '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
         '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
         '--benchmark', 'bench/runs/gen4/summary.json', '--previous-analysis',
         'tests/evidence/diagnostics/gen3/analysis/analysis.json', '--previous-generation', '3',
         '--evidence-root', str(E), '--source-review', str(E / 'source-review.json'),
         '--context-notes', str(notes_path), '--output', 'docs/GEN4-COST-BREAKDOWN.md'], 'report')
    history_count_after = history()
    assert history_count == history_count_after
    for name, digest in campaign['protected_inputs'].items():
        assert sha(name) == digest, name
    totals = Counter()
    for profile in analysis['families'].values():
        assert profile['self_event_sum_matches_summary'] and profile['stage_attribution_complete']
        assert not profile['nonzero_outside_root']
        totals.update({key: value.get('Ir', 0) for key, value in profile['exclusive_stage_events'].items()})
    archive = read(E / 'archive-manifest.json')
    save(E / 'validation.json', {
        'status': 'passed', 'completed_utc': datetime.now(timezone.utc).isoformat(),
        'commit': campaign['commit'], 'profiles': 13, 'all_self_sums_exact': True,
        'all_stage_contexts_unique': True, 'all_root_counts_outputs_and_census_validated': True,
        'interval_native_counts_match_checked_populations': True,
        'protected_inputs_unchanged': True, 'protected_input_count': len(campaign['protected_inputs']),
        'historical_reports_evidence_and_samples_unchanged': True, 'historical_file_count': history_count,
        'historical_approved_addition': read(E / 'historical-approved-addition.json'),
        'archive_files': archive['file_count'], 'archive_bytes': archive['stored_bytes'],
        'exclusive_stage_ir': dict(totals), 'total_ir': sum(totals.values()),
        'report': 'docs/GEN4-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN4-COST-BREAKDOWN.md'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'archive_manifest_sha256': sha(E / 'archive-manifest.json'),
        'payload_helper_comparison_sha256': sha(E / 'payload-helper-comparison.json'),
        'payload_call_edges_sha256': sha(E / 'payload-call-edges.json'),
        'interval_census': campaign['interval_census']})
    print(json.dumps(read(E / 'validation.json')))


if __name__ == '__main__':
    main()

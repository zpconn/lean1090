#!/usr/bin/env python3
"""Archive and report the completed gen6 instruction campaign; no native run."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys

E = Path('tests/evidence/diagnostics/gen6')
C = Path('.cache/gen7-planning')
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def save(path, value):
    assert not path.exists(), 'preserve existing evidence: ' + str(path)
    path.write_text(json.dumps(value, indent=2) + '\n')


def run(argv, label):
    result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    for suffix, value in (('stdout', result.stdout), ('stderr', result.stderr)):
        path = E / (label + '.' + suffix)
        assert not path.exists(), str(path)
        path.write_bytes(value)
    assert result.returncode == 0, (label, result.returncode, result.stderr.decode())


def history():
    before = read(E / 'historical-inputs.json')
    addition = read(E / 'historical-approved-addition.json')
    assert addition['path'] == before['permitted_pending_addition'] == 'bench/runs/gen6/results-review.json'
    paths = {str(p) for root in before['roots'] for p in Path(root).rglob('*') if p.is_file()}
    paths.update(before['individual_paths'])
    assert paths == set(before['files']) | {addition['path']}, 'unexpected historical membership'
    for name, record in before['files'].items():
        assert sha(name) == record['sha256'] and Path(name).stat().st_size == record['bytes'], name
    assert sha(addition['path']) == addition['sha256']
    return len(before['files'])


def grouped(analysis, symbol, stage=None):
    counts = Counter()
    contexts = 0
    for profile in analysis['families'].values():
        for key, rows in profile['stage_helper_observations_non_additive'].items():
            if stage is not None and stage != key:
                continue
            for row in rows:
                if row['symbol'] == symbol:
                    contexts += row['contexts']
                    counts.update(native_entries=row['native_entries'], self_ir=row['self_events'].get('Ir', 0),
                                  inclusive_ir=row['incoming_inclusive_events_non_additive'].get('Ir', 0))
    return {'contexts': contexts, **counts}


def main():
    assert not (E / 'validation.json').exists()
    campaign = read(C / 'campaign.json')
    assert campaign['status'] == 'passed' and len(campaign['profiles']) == 13
    count = history()
    source = read(E / 'source-review.json')
    capture = read(E / 'perf/capture.json')
    assert datetime.fromisoformat(capture['completed_utc']) < datetime.fromisoformat(campaign['started_utc'])
    run([sys.executable, 'review/diagnostics/analyze_callgrind.py', '--self-test'], 'parser-fixtures')
    run([sys.executable, 'review/diagnostics/archive_cost_campaign.py', '--cache', str(C), '--output', str(E),
         '--perf-data', str(C / 'perf-gen6/perf.data'), '--extra-evidence', 'source-review.json',
         '--extra-evidence', 'source-inspection', '--extra-evidence', 'historical-inputs.json',
         '--extra-evidence', 'historical-approved-addition.json', '--extra-evidence', 'finalize.py',
         '--extra-evidence', 'parser-fixtures.stdout', '--extra-evidence', 'parser-fixtures.stderr'], 'archive')
    argv = [sys.executable, 'review/diagnostics/analyze_callgrind.py', '--generation', '6', '--output', str(E / 'analysis')]
    for symbol in (source['exact_fallback_anchor'], source['parity_fold_anchor'], P + 'payloadBits', P + 'cbMach64', P + 'cbValid60'):
        argv.extend(['--extra-anchor', symbol])
    for family in ('adsb', 'commb', 'other'):
        argv.extend(['--profile', f'{family}={E}/callgrind/{family}/callgrind.out.1.gz'])
    for kind in ('candidate', 'score'):
        for register in ('40', '44', '45', '50', '60'):
            argv.extend(['--' + kind, f'{register}={E}/callgrind/{kind}{register}/callgrind.out.1.gz'])
    run(argv, 'analyze')
    analysis = read(E / 'analysis/analysis.json')
    previous = read('tests/evidence/diagnostics/gen5/analysis/analysis.json')
    comparison = []
    for name in ('frameSyndrome', 'Parity_checksum', 'packFields', 'frameAccepted', 'frameAcceptedWithSyndrome', 'frameAddress', 'frameAddressWithSyndrome', 'report', 'reportWithSyndrome'):
        for stage in analysis['stage_definitions']:
            before, after = grouped(previous, P + name, stage), grouped(analysis, P + name, stage)
            if before['contexts'] or after['contexts']:
                comparison.append({'symbol': P + name, 'stage': stage, 'gen5': before, 'gen6': after})
    save(E / 'helper-comparison.json', {
        'kind': 'non_additive_retained_native_boundary_comparison', 'rows': comparison,
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'previous_analysis_sha256': sha('tests/evidence/diagnostics/gen5/analysis/analysis.json'),
        'limits': 'Only self events by unique stage are partitions. Incoming inclusive costs overlap. New helpers replace old boundaries; inlined acceptance remains in decode residual control. Missing symbols are not zero computations or measured savings.'})
    assert source['shared_syndrome_decode_verified']
    assert campaign['live_crc_census']['population'] == 'accepted_corpus_only'
    notes = [
        'Generation 6 computes one pure syndrome after successful frame parsing and passes it to the live acceptance/report/address helpers. The actual timed-worker source/C/object/trace binding and retained assembly are in [source-review.json](../tests/evidence/diagnostics/gen6/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen6/source-inspection/). This is local immutable sharing within one decode call, with no cross-message state.', '',
        'The diagnostic performs an additional CRC census only after collection and complete output consumption. It checks every parsed frame and exact syndrome against the retained result. The old shadow census remains byte-identical to generation 0, including its explicitly historical repeated-call prediction. Native syndrome/checksum/fold/step entries must instead match the new census. All corpus rows are accepted; no rejected-input cost is measured by that population.', '',
        'The native acceptance logic can be inlined into `decode`; such self work remains in residual control under the operational partition. `frameAddressWithSyndrome` retains frame/CRC attribution, and `reportWithSyndrome` retains the existing output/semantic boundaries. A missing old wrapper symbol is not an absent computation. Exact observed caller/helper rows and both generations are retained in [helper-comparison.json](../tests/evidence/diagnostics/gen6/helper-comparison.json).', '',
        'Standalone public acceptance/address/report wrappers delegate to the same helpers and may compute their own syndrome. The profiled root is the complete live `Impl.decode`, whose shared path is independently inspected. The same syndrome supplies DF11 interrogator interpretation. The new eager order can compute a CRC for a frame rejected later by payload plausibility; malformed parsing still exits first. That general-input difference is not a corpus instruction-count claim.', '',
        'The existing exact density/Mach tables and interval gate remain live. Table initialization precedes `main`, outside decoder-root collection and warmed benchmark loops. `cbMach64` remains inlined into its callers; missing standalone entry counts do not mean zero Mach work. Scalar lazy constants and allocator state can differ across these single-pass diagnostic processes, and no unmeasured correction is applied.', '',
        'Native perf capture completed before the native census and Callgrind workers began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only review and benchmark archival; host-wide isolation is not claimed. Perf reports 398 samples, of which 147 have a visible decoder stack; these conditional observations and extensive unknown ancestry do not form a whole-decoder timing breakdown. Full capture and attribution limits are retained in [perf/README.md](../tests/evidence/diagnostics/gen6/perf/README.md).', '',
        'Grouped helper inclusive values are raw incoming-edge observations. Recursive/re-entrant visits can overlap within a row, and descendants can cross a later stage boundary. They must not be added to stage totals or interpreted as predicted speedups. No production or frozen source changed during this diagnostic.']
    notes_path = E / 'context-notes.md'
    assert not notes_path.exists()
    notes_path.write_text('\n'.join(notes) + '\n')
    run([sys.executable, 'review/diagnostics/write_cost_report.py', '--generation', '6',
         '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
         '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
         '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
         '--benchmark', 'bench/runs/gen6/summary.json', '--previous-analysis',
         'tests/evidence/diagnostics/gen5/analysis/analysis.json', '--previous-generation', '5',
         '--evidence-root', str(E), '--source-review', str(E / 'source-review.json'),
         '--context-notes', str(notes_path), '--output', 'docs/GEN6-COST-BREAKDOWN.md'], 'report')
    assert history() == count
    for name, digest in campaign['protected_inputs'].items():
        assert sha(name) == digest, name
    stages = Counter()
    for profile in analysis['families'].values():
        assert profile['self_event_sum_matches_summary'] and profile['stage_attribution_complete']
        assert not profile['nonzero_outside_root']
        stages.update({name: events.get('Ir', 0) for name, events in profile['exclusive_stage_events'].items()})
    archive = read(E / 'archive-manifest.json')
    save(E / 'validation.json', {
        'status': 'passed', 'completed_utc': datetime.now(timezone.utc).isoformat(),
        'commit': campaign['commit'], 'profiles': 13, 'all_self_sums_exact': True,
        'all_stage_contexts_unique': True, 'all_root_counts_outputs_and_census_validated': True,
        'interval_native_counts_match_checked_populations': True,
        'protected_inputs_unchanged': True, 'protected_input_count': len(campaign['protected_inputs']),
        'historical_reports_evidence_and_samples_unchanged': True, 'historical_file_count': count,
        'historical_approved_addition': read(E / 'historical-approved-addition.json'),
        'archive_files': archive['file_count'], 'archive_bytes': archive['stored_bytes'],
        'exclusive_stage_ir': dict(stages), 'total_ir': sum(stages.values()),
        'report': 'docs/GEN6-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN6-COST-BREAKDOWN.md'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'archive_manifest_sha256': sha(E / 'archive-manifest.json'),
        'helper_comparison_sha256': sha(E / 'helper-comparison.json'),
        'shared_syndrome_native_counts_match_checked_corpus': True,
        'live_crc_census': campaign['live_crc_census'],
        'interval_census': campaign['interval_census']})
    print(json.dumps(read(E / 'validation.json')))


if __name__ == '__main__':
    main()

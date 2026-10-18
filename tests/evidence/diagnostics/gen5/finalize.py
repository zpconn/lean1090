#!/usr/bin/env python3
"""Archive and report the completed gen5 instruction campaign; no native run."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys

E = Path('tests/evidence/diagnostics/gen5')
C = Path('.cache/gen6-planning')
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
    assert addition['path'] == before['permitted_pending_addition'] == 'bench/runs/gen5/results-review.json'
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
         '--perf-data', str(C / 'perf-gen5/perf.data'), '--extra-evidence', 'source-review.json',
         '--extra-evidence', 'source-inspection', '--extra-evidence', 'historical-inputs.json',
         '--extra-evidence', 'historical-approved-addition.json', '--extra-evidence', 'finalize.py',
         '--extra-evidence', 'parser-fixtures.stdout', '--extra-evidence', 'parser-fixtures.stderr'], 'archive')
    argv = [sys.executable, 'review/diagnostics/analyze_callgrind.py', '--generation', '5', '--output', str(E / 'analysis')]
    for symbol in (source['exact_fallback_anchor'], source['parity_fold_anchor'], P + 'payloadBits', P + 'cbMach64', P + 'cbValid60'):
        argv.extend(['--extra-anchor', symbol])
    for family in ('adsb', 'commb', 'other'):
        argv.extend(['--profile', f'{family}={E}/callgrind/{family}/callgrind.out.1.gz'])
    for kind in ('candidate', 'score'):
        for register in ('40', '44', '45', '50', '60'):
            argv.extend(['--' + kind, f'{register}={E}/callgrind/{kind}{register}/callgrind.out.1.gz'])
    run(argv, 'analyze')
    analysis = read(E / 'analysis/analysis.json')
    previous = read('tests/evidence/diagnostics/gen4/analysis/analysis.json')
    comparison = []
    for name in ('cbMach64', 'cbValid60', 'cbPenalty', 'Binary64_round', 'payloadBits'):
        for stage in analysis['stage_definitions']:
            before, after = grouped(previous, P + name, stage), grouped(analysis, P + name, stage)
            if before['contexts'] or after['contexts']:
                comparison.append({'symbol': P + name, 'stage': stage, 'gen4': before, 'gen5': after})
    save(E / 'helper-comparison.json', {
        'kind': 'non_additive_retained_native_boundary_comparison', 'rows': comparison,
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'previous_analysis_sha256': sha('tests/evidence/diagnostics/gen4/analysis/analysis.json'),
        'limits': 'Only self events by unique stage are partitions. Incoming inclusive counts overlap. Inlined cbMach64 work remains in callers; its absent boundary is not zero computation or a measured saving.'})
    mach = grouped(analysis, P + 'cbMach64')
    # The verified current binary inlines this exact helper; prove the observed
    # absence from the profiles separately rather than silently assigning cost 0.
    assert mach['contexts'] == 0, 'reinspect actual native anchor before describing it as absent'
    notes = [
        'Generation 5 replaces repeated software-binary64 Mach conversion with one immutable 1,024-entry exact value table keyed only by `payloadBits word 25 10`. The actual timed-worker source/C/object/trace binding and retained assembly are in [source-review.json](../tests/evidence/diagnostics/gen5/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen5/source-inspection/). The field-indexed table loads in the hard-validity, penalty and slow-density callers are the live implementation.', '',
        '**The standalone `cbMach64` native boundary is absent because Clang inlines it. This does not mean zero Mach work.** No separate `cbMach64` context is observed in these profiles. Its field extraction, array access and reference handling remain in retained callers. Therefore this report does not subtract its former inclusive cost as a measured saving, or equate absent entry counts with an eliminated computation. The exclusive stage and candidate/score measurements remain the primary comparisons.', '',
        'The following retained caller-boundary observations compare the same corpus populations. They overlap each other and the exclusive stages; only the self-event partition is additive. Full per-stage observations, including the previously separate Mach boundary, are in [helper-comparison.json](../tests/evidence/diagnostics/gen5/helper-comparison.json).', '',
        '| Native boundary in Comm-B inference | Gen4 entries | Gen5 entries | Gen4 self Ir | Gen5 self Ir | Gen4 inclusive Ir | Gen5 inclusive Ir |',
        '|---|---:|---:|---:|---:|---:|---:|']
    for row in comparison:
        if row['stage'] != 'commb_inference' or row['symbol'] == P + 'cbMach64':
            continue
        a, b = row['gen4'], row['gen5']
        notes.append(f"| `{row['symbol'].removeprefix(P)}` | {a.get('native_entries', 0):,} | {b.get('native_entries', 0):,} | {a.get('self_ir', 0):,} | {b.get('self_ir', 0):,} | {a.get('inclusive_ir', 0):,} | {b.get('inclusive_ir', 0):,} |")
    notes += ['',
        'The Mach value table is constructed with the original software multiplication/division sequence during module initialization and then marked persistent. Its construction and the existing 13 density-table initializations precede `main`, outside decoder-root collection and warmed benchmark loops. Other software arithmetic remains live, including the IAS/Mach penalty division. Scalar lazy constants and allocator state can still differ across these single-pass diagnostic processes; no unmeasured correction is applied.', '',
        'The CRC fold, payload extraction, exact interval gate and callable boxed full-software fallback retain their existing live paths. The report reconciles observed CRC and interval/fallback native entries with the checked corpus census. A missing small helper symbol is never substituted for a logical decision count.', '',
        'Native perf capture completed before any native census or Callgrind worker began. Later family/probe jobs intentionally overlapped, with at most six active profiles. Other agents performed read-only review and benchmark-report archival; host-wide isolation is not claimed. Sampling exclusions and unwind limitations are retained in [perf/README.md](../tests/evidence/diagnostics/gen5/perf/README.md). These conditional sample observations are not a whole-decoder timing decomposition.', '',
        'Grouped helper inclusive values are raw incoming-edge observations. Recursive/re-entrant visits can overlap within a row, and descendants can cross a later stage boundary. They must not be added to stage totals or interpreted as predicted speedups. No production or frozen source was changed during this diagnostic.']
    notes_path = E / 'context-notes.md'
    assert not notes_path.exists()
    notes_path.write_text('\n'.join(notes) + '\n')
    run([sys.executable, 'review/diagnostics/write_cost_report.py', '--generation', '5',
         '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
         '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
         '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
         '--benchmark', 'bench/runs/gen5/summary.json', '--previous-analysis',
         'tests/evidence/diagnostics/gen4/analysis/analysis.json', '--previous-generation', '4',
         '--evidence-root', str(E), '--source-review', str(E / 'source-review.json'),
         '--context-notes', str(notes_path), '--output', 'docs/GEN5-COST-BREAKDOWN.md'], 'report')
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
        'report': 'docs/GEN5-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN5-COST-BREAKDOWN.md'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'archive_manifest_sha256': sha(E / 'archive-manifest.json'),
        'helper_comparison_sha256': sha(E / 'helper-comparison.json'),
        'mach_native_context_absence_observed_and_attributed_to_verified_inlining': True,
        'interval_census': campaign['interval_census']})
    print(json.dumps(read(E / 'validation.json')))


if __name__ == '__main__':
    main()

#!/usr/bin/env python3
"""Resume reporting after the retained perf-label mismatch; no recollection."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys

E = Path('tests/evidence/diagnostics/gen6')


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def main():
    assert not (E / 'validation.json').exists()
    assert not Path('docs/GEN6-COST-BREAKDOWN.md').exists()
    assert "KeyError: 'report parity/address'" in (E / 'report.stderr').read_text()
    archive_hash = sha(E / 'archive-manifest.json')
    analysis_hash = sha(E / 'analysis/analysis.json')
    writer = Path('review/diagnostics/write_cost_report.py')
    retained_writer = E / 'corrected-write_cost_report.py'
    assert not retained_writer.exists()
    retained_writer.write_bytes(writer.read_bytes())
    argv = [sys.executable, str(writer), '--generation', '6',
            '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
            '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
            '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
            '--benchmark', 'bench/runs/gen6/summary.json', '--previous-analysis',
            'tests/evidence/diagnostics/gen5/analysis/analysis.json', '--previous-generation', '5',
            '--evidence-root', str(E), '--source-review', str(E / 'source-review.json'),
            '--context-notes', str(E / 'context-notes.md'), '--output', 'docs/GEN6-COST-BREAKDOWN.md']
    result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    for suffix, data in [('stdout', result.stdout), ('stderr', result.stderr)]:
        path = E / ('report-after-perf-label-fix.' + suffix)
        assert not path.exists()
        path.write_bytes(data)
    assert result.returncode == 0, result.stderr.decode()
    campaign = read(E / 'campaign.json')
    assert campaign['status'] == 'passed' and len(campaign['profiles']) == 13
    for path, digest in campaign['protected_inputs'].items():
        assert sha(path) == digest, path
    before = read(E / 'historical-inputs.json')
    addition = read(E / 'historical-approved-addition.json')
    paths = {str(p) for root in before['roots'] for p in Path(root).rglob('*') if p.is_file()}
    paths.update(before['individual_paths'])
    assert paths == set(before['files']) | {addition['path']}
    for path, record in before['files'].items():
        assert sha(path) == record['sha256'] and Path(path).stat().st_size == record['bytes'], path
    assert sha(addition['path']) == addition['sha256']
    assert sha(E / 'archive-manifest.json') == archive_hash
    assert sha(E / 'analysis/analysis.json') == analysis_hash
    assert sha(retained_writer) == sha(writer)
    analysis = read(E / 'analysis/analysis.json')
    stages = Counter()
    for profile in analysis['families'].values():
        assert profile['self_event_sum_matches_summary'] and profile['stage_attribution_complete']
        assert not profile['nonzero_outside_root']
        stages.update({name: events.get('Ir', 0) for name, events in profile['exclusive_stage_events'].items()})
    archive = read(E / 'archive-manifest.json')
    validation = {
        'status': 'passed', 'completed_utc': datetime.now(timezone.utc).isoformat(),
        'commit': campaign['commit'], 'profiles': 13, 'all_self_sums_exact': True,
        'all_stage_contexts_unique': True, 'all_root_counts_outputs_and_census_validated': True,
        'interval_native_counts_match_checked_populations': True,
        'protected_inputs_unchanged': True, 'protected_input_count': len(campaign['protected_inputs']),
        'historical_reports_evidence_and_samples_unchanged': True,
        'historical_file_count': len(before['files']), 'historical_approved_addition': addition,
        'archive_files': archive['file_count'], 'archive_bytes': archive['stored_bytes'],
        'exclusive_stage_ir': dict(stages), 'total_ir': sum(stages.values()),
        'report': 'docs/GEN6-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN6-COST-BREAKDOWN.md'),
        'analysis_sha256': analysis_hash, 'archive_manifest_sha256': archive_hash,
        'helper_comparison_sha256': sha(E / 'helper-comparison.json'),
        'shared_syndrome_native_counts_match_checked_corpus': True,
        'live_crc_census': campaign['live_crc_census'], 'interval_census': campaign['interval_census'],
        'renderer_correction': {
            'reason': 'The gen6 perf detail label changed from report parity/address to shared frame syndrome. Render all actual detail labels instead of assuming the old name.',
            'authority': 'Root authorized diagnostic-only renderer correction, preserving failure and initial archive with no profile rerun.',
            'command': argv, 'exit_code': result.returncode,
            'corrected_renderer_sha256': sha(writer),
            'initial_renderer_sha256': archive['files']['tooling/write_cost_report.py']['stored_sha256'],
            'primary_archive_analysis_and_profile_inputs_unchanged': True,
            'post_profile_reporting_only': True,
            'files': {str(p): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in
                      (Path(__file__), retained_writer, E / 'report.stdout', E / 'report.stderr',
                       E / 'report-after-perf-label-fix.stdout', E / 'report-after-perf-label-fix.stderr')}}}
    (E / 'validation.json').write_text(json.dumps(validation, indent=2) + '\n')
    print(json.dumps({key: validation[key] for key in ('status', 'total_ir', 'exclusive_stage_ir',
                                                      'report_sha256', 'archive_files', 'protected_input_count')}))


if __name__ == '__main__':
    main()

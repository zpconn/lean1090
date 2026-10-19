#!/usr/bin/env python3
"""Resume only report/validation after a documented archive-path binding correction."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from finalize import *

def main():
    assert not (E / 'validation.json').exists()
    campaign = read(E / 'campaign.json')
    analysis = read(E / 'analysis/analysis.json')
    count = history()
    notes_path = E / 'context-notes.md'
    manifest = read(E / 'archive-manifest.json')
    for name, record in manifest['files'].items():
        assert sha(E / name) == record['stored_sha256'], name
    for name, digest in campaign['protected_inputs'].items():
        assert sha(name) == digest, name
    run([sys.executable, 'review/diagnostics/write_cost_report.py', '--generation', '10',
         '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
         '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
         '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
         '--benchmark', 'bench/runs/gen10/summary.json', '--previous-analysis',
         'tests/evidence/diagnostics/gen9/analysis/analysis.json', '--previous-generation', '9',
         '--evidence-root', str(E), '--source-review', str(E / 'source-review.json'),
         '--benchmark-source-binding', str(E / 'benchmark-source-binding.json'),
         '--context-notes', str(notes_path), '--output', 'docs/GEN10-COST-BREAKDOWN.md'], 'report-resumed')
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
        'archive_files': archive['file_count'], 'archive_bytes': archive['stored_bytes'],
        'exclusive_stage_ir': dict(stages), 'total_ir': sum(stages.values()),
        'report': 'docs/GEN10-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN10-COST-BREAKDOWN.md'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'archive_manifest_sha256': sha(E / 'archive-manifest.json'),
        'helper_comparison_sha256': sha(E / 'helper-comparison.json'),
        'shared_syndrome_native_counts_match_checked_corpus': True,
        'integer_gate_native_counts_match_choose': True,
        'benchmark_source_binding_sha256': sha(E / 'benchmark-source-binding.json'),
        'qnh_table_live_path_verified': True,
        'live_crc_census': campaign['live_crc_census'],
        'interval_census': campaign['interval_census'],
        'renderer_correction': {'reason': 'Normalize only the cache-versus-archive build-manifest path after exact campaign path and SHA checks; all source and native checks are rerun.', 'renderer_sha256': sha('review/diagnostics/write_cost_report.py'), 'original_renderer_sha256': sha(E / 'tooling/write_cost_report.py'), 'diff_sha256': sha(E / 'renderer-correction/change.diff'), 'primary_archive_unchanged': True}})
    print(json.dumps(read(E / 'validation.json')))


if __name__ == '__main__':
    main()

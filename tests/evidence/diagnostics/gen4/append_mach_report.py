#!/usr/bin/env python3
"""Retain and append the root-requested Mach detail before independent review."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

E = Path('tests/evidence/diagnostics/gen4')
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    path = Path('docs/GEN4-COST-BREAKDOWN.md')
    validation_path = E / 'validation.json'
    validation = json.loads(validation_path.read_text())
    assert sha(path) == validation['report_sha256'] == 'cb6fec20bdde37e526e9b9f4e7a087058128af5536438cea7ce6a544d7625c10'
    for original, retained in ((path, E / 'report-before-mach-addendum.md'),
                                (validation_path, E / 'validation-before-mach-addendum.json')):
        assert not retained.exists()
        retained.write_bytes(original.read_bytes())
    data_path = E / 'mach-penalty-observations.json'
    data = json.loads(data_path.read_text())
    assert data['analysis_sha256'] == validation['analysis_sha256']
    assert data['raw_context_totals_match_grouped_analysis']
    stages = {row['stage']: row for row in data['unique_stage_observations'] if row['symbol'] == P + 'cbMach64'}
    stage_labels = {'frame_crc': 'Frame / CRC', 'adsb_fields': 'ADS-B fields',
                    'commb_inference': 'Comm-B inference', 'semantic_oracle_values': 'Semantic / oracle values',
                    'output_model_control': 'Output / control'}
    lines = ['', '## Supplemental Mach and penalty observations', '',
        'This section was requested after the main report was rendered, using only the existing raw profiles and analysis. The earlier report and validation are retained as `report-before-mach-addendum.md` and `validation-before-mach-addendum.json`. No decoder, compiler, profiler or benchmark ran for this extraction.', '',
        'The live `cbMach64` decodes the ten-bit field at payload bit 25, then preserves the software-binary64 multiplication by the rounded literal 256/125 followed by division by 512. The source is retained at [production-source/Impl/CommB.lean](../tests/evidence/diagnostics/gen4/production-source/Impl/CommB.lean). A proposed immutable 1,024-entry exact table would be keyed only by that field code and must prove equality to this operation sequence for every word. This is an optimization candidate, not an implemented change or a throughput prediction.', '',
        '| Unique caller stage | Observed cbMach64 entries | Self Ir | Inclusive Ir (non-additive) |',
        '|---|---:|---:|---:|']
    for stage, label in stage_labels.items():
        row = stages[stage]['totals']
        lines.append(f"| {label} | {row.get('native_entries', 0):,} | {row.get('self_ir', 0):,} | {row.get('inclusive_ir', 0):,} |")
    mach = stages['commb_inference']['totals']
    stage_ir = validation['exclusive_stage_ir']['commb_inference']
    lines += ['', f"All {mach['native_entries']:,} observed calls belong uniquely to Comm-B inference. Their {mach['inclusive_ir']:,} inclusive instructions are {100*mach['inclusive_ir']/stage_ir:.2f}% of that stage and {100*mach['inclusive_ir']/validation['total_ir']:.2f}% of the aggregate, with overlapping descendants. Zero entries in another stage means this native boundary was not observed there; it does not rule out a different or inlined computation. These costs overlap the hard-validity and penalty paths below and must not be added to the stage totals.", '',
        '| Observed whole-decoder caller path | cbMach64 entries | Self Ir | Inclusive Ir (non-additive) |',
        '|---|---:|---:|---:|']
    seen = set()
    for context in data['full_commb_mach_contexts']:
        symbol = context['symbol_with_callers']
        if "cbMach64'" + P + 'cbPenalty' in symbol:
            label = 'BDS60 score penalty'
        elif "'" + P + 'decodeBDS' in symbol:
            label = 'BDS60 accepted-record validity recheck'
        else:
            assert "'" + P + 'commBCoreEligible' in symbol and "'" + P + 'cbValid60' in symbol
            label = 'BDS60 candidate hard-validity check'
        assert label not in seen
        seen.add(label)
        calls = sum(edge['calls'] for edge in context['incoming'])
        events = sum(edge['inclusive_events'].get('Ir', 0) for edge in context['incoming'])
        lines.append(f"| {label} | {calls:,} | {context['self_events'].get('Ir', 0):,} | {events:,} |")
    lines += ['', 'These three actual caller contexts reproduce the grouped Mach entry and instruction totals exactly. The candidate/score-only probes below are separate executions with distinct allocator and lazy-constant context, so their costs cannot be subtracted to reconstruct a whole-decoder substage.', '',
        '| Register probe | Root inputs | cbMach64 entries | cbMach64 inclusive Ir | cbPenalty entries | cbPenalty inclusive Ir |',
        '|---|---:|---:|---:|---:|---:|']
    for row in data['register_probes']:
        values = {item['symbol']: item for item in row['observed_symbol_rows']}
        m, p = values.get(P + 'cbMach64', {}), values.get(P + 'cbPenalty', {})
        lines.append(f"| BDS{row['register']} {row['kind']} | {row['root_entries']:,} | {m.get('native_entries', 0):,} | {m.get('incoming_inclusive_events_non_additive', {}).get('Ir', 0):,} | {p.get('native_entries', 0):,} | {p.get('incoming_inclusive_events_non_additive', {}).get('Ir', 0):,} |")
    lines += ['', 'BDS44/45 have no reached score gates in this corpus, so no observed penalty/Mach calls. The complete extraction retains self costs, raw caller names and outgoing software-multiply/divide observations in [mach-penalty-observations.json](../tests/evidence/diagnostics/gen4/mach-penalty-observations.json); [extract_mach_costs.py](../tests/evidence/diagnostics/gen4/extract_mach_costs.py) reproduces them from the existing evidence.', '',
        f"Supplement input SHA-256: `{sha(data_path)}`. The primary analysis and raw archive are unchanged.", '']
    path.write_text(path.read_text() + '\n'.join(lines))
    addition_paths = [E / name for name in ('extract_mach_costs.py', 'mach-penalty-observations.json',
                                           'append_mach_report.py', 'report-before-mach-addendum.md',
                                           'validation-before-mach-addendum.json')]
    validation['report_sha256'] = sha(path)
    validation['mach_addendum'] = {
        'authorized_by': 'Root requested retaining the measured Mach/penalty breakdown in the completed diagnostic report before independent review and next-candidate selection.',
        'completed_utc': datetime.now(timezone.utc).isoformat(),
        'no_native_execution_or_source_changes': True,
        'files': {str(p): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in addition_paths},
        'primary_analysis_and_archive_unchanged': True}
    assert sha(E / 'analysis/analysis.json') == validation['analysis_sha256']
    assert sha(E / 'archive-manifest.json') == validation['archive_manifest_sha256']
    validation_path.write_text(json.dumps(validation, indent=2) + '\n')
    print(json.dumps({'report_sha256': sha(path), 'validation_sha256': sha(validation_path),
                      'additions': list(validation['mach_addendum']['files'])}))


if __name__ == '__main__':
    main()

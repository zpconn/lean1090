#!/usr/bin/env python3
"""Archive and report the completed gen9 instruction campaign; no native run."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys

E = Path('tests/evidence/diagnostics/gen9')
C = Path('.cache/gen10-planning')
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
    assert addition['path'] == before['permitted_pending_addition'] == 'bench/runs/gen9/results-review.json'
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
         '--perf-data', str(C / 'perf-gen9/perf.data'), '--extra-evidence', 'source-review.json',
         '--extra-evidence', 'source-inspection', '--extra-evidence', 'historical-inputs.json',
         '--extra-evidence', 'historical-approved-addition.json', '--extra-evidence', 'finalize.py',
         '--extra-evidence', 'parser-fixtures.stdout', '--extra-evidence', 'parser-fixtures.stderr',
         '--extra-evidence', 'driver-build.stdout', '--extra-evidence', 'driver-build.stderr',
         '--extra-evidence', 'tooling-checks', '--extra-evidence', 'extract_field_contexts.py'], 'archive')
    argv = [sys.executable, 'review/diagnostics/analyze_callgrind.py', '--generation', '9', '--output', str(E / 'analysis')]
    for symbol in (source['exact_fallback_anchor'], source['parity_fold_anchor'], P + 'field', P + 'bytesValue', P + 'packFields', P + 'payloadBits', P + 'payloadValue', P + 'affineValue', P + 'cbMach64', P + 'cbValid60', *source['integer_score_gate_anchors'].values()):
        argv.extend(['--extra-anchor', symbol])
    for family in ('adsb', 'commb', 'other'):
        argv.extend(['--profile', f'{family}={E}/callgrind/{family}/callgrind.out.1.gz'])
    for kind in ('candidate', 'score'):
        for register in ('40', '44', '45', '50', '60'):
            argv.extend(['--' + kind, f'{register}={E}/callgrind/{kind}{register}/callgrind.out.1.gz'])
    run(argv, 'analyze')
    analysis = read(E / 'analysis/analysis.json')
    previous = read('tests/evidence/diagnostics/gen8/analysis/analysis.json')
    comparison = []
    symbols = [P + name for name in ('field', 'bytesValue', 'packFields', 'Parity_syndrome', 'Parity_checksum', 'payloadValue', 'affineValue', 'ScoreGate_choose', 'ScoreGate_commonDenominator', 'ScoreGate_scaledNumerator', 'ScoreGate_scaledTotals', 'ScoreGate_mass', 'ScoreGate_center', 'ScoreGate_envelope', 'cbScorePasses', 'cbPenalty')]
    symbols.extend(source['integer_score_gate_anchors'].values())
    symbols.extend(('lean_nat_pow', 'l_BitVec_ofNat', 'lean_nat_big_shiftr', 'lean_uint64_of_big_nat'))
    symbols.append(source['parity_fold_anchor'])
    for symbol in dict.fromkeys(symbols):
        for stage in analysis['stage_definitions']:
            before, after = grouped(previous, symbol, stage), grouped(analysis, symbol, stage)
            if before['contexts'] or after['contexts']:
                comparison.append({'symbol': symbol, 'stage': stage, 'gen8': before, 'gen9': after})
    save(E / 'helper-comparison.json', {
        'kind': 'non_additive_retained_native_boundary_comparison', 'rows': comparison,
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'previous_analysis_sha256': sha('tests/evidence/diagnostics/gen8/analysis/analysis.json'),
        'limits': 'Only self events by unique stage are partitions. Incoming inclusive costs overlap. Integer helpers remain live; inline affine and scaled numerator work remains in callers. Missing symbols are not zero computations or measured savings.'})
    assert source['shared_syndrome_decode_verified']
    assert campaign['live_crc_census']['population'] == 'accepted_corpus_only'
    assert source['integer_score_gate_verified']
    assert source['field_mask_verified']
    run([sys.executable, str(E / 'extract_field_contexts.py')], 'field-contexts')
    perf = read(E / 'perf/analysis.json')
    perf_completion = read(E / 'perf/completion.json')
    assert perf_completion['samples'] == perf['total_samples']
    assert perf_completion['included_decode_stacks'] == perf['decode_descendant_samples']
    unknown_leaves = perf_completion['unknown_decode_leaf_samples']
    notes = [
        'Generation 9 changes the live frame field extractor for widths below 64. It performs the exact natural-number shift before conversion to UInt64, then applies the native low mask and returns its proved-bounded value. The original natural power/division/BitVec reduction remains for wider fields. The universal equality covers arbitrary total, start, width and word values, including large shifts and truncating subtraction. Retained timed-worker source/C/object/trace and assembly evidence is in [source-review.json](../tests/evidence/diagnostics/gen9/source-review.json) and [source-inspection/](../tests/evidence/diagnostics/gen9/source-inspection/).', '',
        'The actual linked decodeFrame retains 26 static calls to the same live field function; these are call sites, not per-message counts. The timed-worker narrow branch shifts before conversion and masking, while the wide branch retains the original power/division path. The existing mask helper is inlined. A separate recount of gen8/gen9 profiles below preserves actual field caller contexts and direct outgoing helper counts. Missing native edges do not mean zero inlined work or remove arbitrary-input fallback behavior.', '',
        'The live syndrome fold, checksum, byte fold, field extractor and field-packing helper are retained as explicit nested anchors. Their incoming inclusive costs overlap each other and the exclusive stage totals; they are not additive subdivisions. Complete helper self costs remain the exact partition. Generation 8 affine guards and generation 7 exact integer score decisions remain live and unchanged. Rational center/envelope/mass are pure reference APIs used only by the post-collection census. The unchanged software-score callback remains lazy.', '',
        'One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs; the old repeated-call prediction stays historical. Rejected-input costs are not claimed from this accepted corpus. Native acceptance can be inlined into residual control, while address and parity helpers retain operational frame/CRC attribution. Integer choose/common-denominator/pair-fold and fallback native counts remain reconciled with the separately checked register populations.', '',
        'All immutable density and Mach tables are initialized before main. Their construction is outside collected decoder roots and warmed benchmark loops. The Mach accessor remains inlined into its callers. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied.', '',
        f"The native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews and archived benchmark documentation; no host-wide isolation is claimed. Of {perf['total_samples']:,} samples, {perf['decode_descendant_samples']:,} have a visible decoder ancestor and {perf['excluded_samples']:,} are excluded; {perf['all_samples_with_unknown_frame']:,} stacks contain an unknown frame and {unknown_leaves:,} included leaves are unknown. Most recorded samples lack a usable decoder ancestor, so these conditional observations cannot allocate whole-decoder time reliably. The exact capture conditions and reported zero-lost counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen9/perf/README.md). These are diagnostics, not benchmark timings.", '',
        'The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within one inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.', '',
        (E / 'field-caller-contexts.md').read_text()]
    notes_path = E / 'context-notes.md'
    assert not notes_path.exists()
    notes_path.write_text('\n'.join(notes) + '\n')
    run([sys.executable, 'review/diagnostics/write_cost_report.py', '--generation', '9',
         '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
         '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
         '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
         '--benchmark', 'bench/runs/gen9/summary.json', '--previous-analysis',
         'tests/evidence/diagnostics/gen8/analysis/analysis.json', '--previous-generation', '8',
         '--evidence-root', str(E), '--source-review', str(E / 'source-review.json'),
         '--context-notes', str(notes_path), '--output', 'docs/GEN9-COST-BREAKDOWN.md'], 'report')
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
        'report': 'docs/GEN9-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN9-COST-BREAKDOWN.md'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'archive_manifest_sha256': sha(E / 'archive-manifest.json'),
        'helper_comparison_sha256': sha(E / 'helper-comparison.json'),
        'shared_syndrome_native_counts_match_checked_corpus': True,
        'integer_gate_native_counts_match_choose': True,
        'field_contexts_sha256': sha(E / 'field-caller-contexts.json'),
        'field_native_entries_same_population': True,
        'live_crc_census': campaign['live_crc_census'],
        'interval_census': campaign['interval_census']})
    print(json.dumps(read(E / 'validation.json')))


if __name__ == '__main__':
    main()

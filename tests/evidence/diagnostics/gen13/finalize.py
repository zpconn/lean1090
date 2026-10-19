#!/usr/bin/env python3
"""Archive and report the completed gen13 instruction campaign; no native run."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys
sys.dont_write_bytecode = True

E = Path('tests/evidence/diagnostics/gen13')
C = Path('.cache/gen13-costs')
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
    paths = {str(p) for root in before['roots'] for p in Path(root).rglob('*') if p.is_file()}
    paths.update(before['individual_paths'])
    assert paths == set(before['files']), 'unexpected historical membership'
    for name, record in before['files'].items():
        assert sha(name) == record['sha256'] and Path(name).stat().st_size == record['bytes'], name
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
         '--perf-data', str(C / 'perf-gen13/perf.data'), '--extra-evidence', 'source-review.json',
         '--extra-evidence', 'source-inspection', '--extra-evidence', 'historical-inputs.json',
         '--extra-evidence', 'snapshot_history.py', '--extra-evidence', 'history.stdout',
         '--extra-evidence', 'history.stderr',
         '--extra-evidence', 'finalize.py',
         '--extra-evidence', 'parser-fixtures.stdout', '--extra-evidence', 'parser-fixtures.stderr',
         '--extra-evidence', 'driver-build.stdout', '--extra-evidence', 'driver-build.stderr',
         '--extra-evidence', 'tooling-checks'], 'archive')
    argv = [sys.executable, 'review/diagnostics/analyze_callgrind.py', '--generation', '13', '--output', str(E / 'analysis')]
    for symbol in (source['exact_fallback_anchor'], source['parity_fold_anchor'], source['byte_word_prefix_anchor'], source['byte_word_fallback_anchor'], source['wind_penalty_anchor'], source['wind_penalty_table_entry_anchor'], P + 'bytesWord', P + 'field', P + 'bytesValue', P + 'packFields', P + 'payloadBits', P + 'payloadValue', P + 'affineValue', P + 'cbMach64', P + 'cbQNH64', P + 'cbValid40', P + 'cbDensityTerms', P + 'cbValid60', *source['integer_score_gate_anchors'].values()):
        argv.extend(['--extra-anchor', symbol])
    for family in ('adsb', 'commb', 'other'):
        argv.extend(['--profile', f'{family}={E}/callgrind/{family}/callgrind.out.1.gz'])
    for kind in ('candidate', 'score'):
        for register in ('40', '44', '45', '50', '60'):
            argv.extend(['--' + kind, f'{register}={E}/callgrind/{kind}{register}/callgrind.out.1.gz'])
    run(argv, 'analyze')
    analysis = read(E / 'analysis/analysis.json')
    previous = read('tests/evidence/diagnostics/gen12/analysis/analysis.json')
    comparison = []
    symbols = [P + name for name in ('field', 'bytesValue', 'packFields', 'Parity_syndrome', 'Parity_checksum', 'payloadValue', 'affineValue', 'ScoreGate_choose', 'ScoreGate_commonDenominator', 'ScoreGate_scaledNumerator', 'ScoreGate_scaledTotals', 'ScoreGate_mass', 'ScoreGate_center', 'ScoreGate_envelope', 'cbScorePasses', 'cbPenalty', 'cbQNH64', 'cbValid40', 'cbDensityTerms')]
    symbols.extend(source['integer_score_gate_anchors'].values())
    symbols.extend([source['byte_word_prefix_anchor'], source['byte_word_fallback_anchor'], P + 'bytesWord'])
    symbols.extend([source['wind_penalty_anchor'], source['wind_penalty_table_entry_anchor']])
    symbols.extend(('lean_nat_pow', 'l_BitVec_ofNat', 'lean_nat_big_shiftr', 'lean_uint64_of_big_nat'))
    symbols.extend([source['parity_fold_anchor'], read('tests/evidence/diagnostics/gen12/source-review.json')['parity_fold_anchor']])
    for symbol in dict.fromkeys(symbols):
        for stage in analysis['stage_definitions']:
            before, after = grouped(previous, symbol, stage), grouped(analysis, symbol, stage)
            if before['contexts'] or after['contexts']:
                comparison.append({'symbol': symbol, 'stage': stage, 'gen12': before, 'gen13': after})
    save(E / 'helper-comparison.json', {
        'kind': 'non_additive_retained_native_boundary_comparison', 'rows': comparison,
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'previous_analysis_sha256': sha('tests/evidence/diagnostics/gen12/analysis/analysis.json'),
        'limits': 'Only self events by unique stage are partitions. Incoming inclusive costs overlap. Integer helpers remain live; inline affine and scaled numerator work remains in callers. Missing symbols are not zero computations or measured savings.'})
    assert source['shared_syndrome_decode_verified']
    assert campaign['live_crc_census']['population'] == 'accepted_corpus_only'
    assert source['integer_score_gate_verified']
    assert source['field_mask_verified']
    assert source['qnh_table_live_path_verified']
    assert source['word_crc_live_path_verified']
    assert source['byte_words_live_path_verified']
    assert source['bds50_wind_penalty_live_path_verified']
    byte_counts = []
    for family, profile in analysis['families'].items():
        result = next(json.loads(line) for line in (E / 'native' / (family + '.jsonl')).read_text().splitlines()
                      if json.loads(line).get('phase') == 'result')
        short = sum(row['digest']['count'] for row in result['per_df'] if row['df'] < 16)
        long = sum(row['digest']['count'] for row in result['per_df'] if row['df'] >= 16)
        anchors = profile['native_anchor_counts_and_non_additive_inclusive_events']
        value = anchors[P + 'bytesValue']['native_entries']
        prefix = anchors.get(source['byte_word_prefix_anchor'], {}).get('native_entries', 0)
        fallback = anchors.get(source['byte_word_fallback_anchor'], {}).get('native_entries', 0)
        assert value == short + long == result['digest']['count']
        assert prefix == long and fallback == 0
        byte_counts.append({'family': family, 'seven_byte_frames': short, 'fourteen_byte_frames': long,
                            'bytesValue_entries': value, 'prefix_entries': prefix, 'wide_fallback_entries': fallback})
    save(E / 'byte-native-counts.json', {'rows': byte_counts, 'source_review_sha256': sha(E / 'source-review.json'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'limits': 'Expected prefix population is the separately checked corpus DF/length census. Native boundary counts are actual Callgrind incoming calls. The >16-byte fallback is confirmed callable in retained native inspection; its absence from these profiles means no collected entries. Inlined UInt64 byte updates have no standalone entry count.'})
    penalty_rows = []
    for kind in ('candidate', 'score'):
        for register in ('40', '44', '45', '50', '60'):
            profile = analysis['non_additive_register_' + kind + '_probes'][register]
            row = profile['native_anchor_counts_and_non_additive_inclusive_events'].get(P + 'cbPenalty', {})
            penalty_rows.append({'probe': kind + register, 'register': register, 'kind': kind,
                'probe_entries': profile['root_incoming_calls'], 'probe_total_ir': profile['total_events'].get('Ir', 0),
                'native_entries': row.get('native_entries', 0), 'self_ir': row.get('self_events', {}).get('Ir', 0),
                'incoming_inclusive_ir_non_additive': row.get('incoming_inclusive_events_non_additive', {}).get('Ir', 0)})
    save(E / 'penalty-probe-costs.json', {'rows': penalty_rows, 'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'limits': 'Separate candidate and score probes overlap whole-decoder work and each other. These are actual cbPenalty incoming call-edge observations; inclusive costs can overlap recursively and must not be added to exclusive stage totals. Zero score probes for registers 44/45 reflect zero reached corpus populations, not free hypothetical work.'})
    bds50 = next(row for row in campaign['interval_census']['registers'] if row['register_decimal'] == 0x50)
    expected_wind = bds50['reached'] + bds50['fallback_accept'] + bds50['fallback_reject']
    wind_rows = []
    profiles = [(family, profile, expected_wind if family == 'commb' else 0) for family, profile in analysis['families'].items()]
    for kind in ('candidate', 'score'):
        profiles.extend((kind + register, profile, expected_wind if register == '50' else 0)
                        for register, profile in analysis['non_additive_register_' + kind + '_probes'].items())
    for label, profile, expected in profiles:
        anchors = profile['native_anchor_counts_and_non_additive_inclusive_events']
        wind = anchors.get(source['wind_penalty_anchor'], {})
        entry = anchors.get(source['wind_penalty_table_entry_anchor'], {})
        assert wind.get('native_entries', 0) == expected, (label, wind, expected)
        assert entry.get('native_entries', 0) == 0, (label, entry)
        wind_rows.append({'profile': label, 'expected_lookup_calls': expected,
            'native_lookup_entries': wind.get('native_entries', 0),
            'lookup_self_ir': wind.get('self_events', {}).get('Ir', 0),
            'lookup_incoming_inclusive_ir_non_additive': wind.get('incoming_inclusive_events_non_additive', {}).get('Ir', 0),
            'table_entry_constructor_calls_inside_collected_root': entry.get('native_entries', 0)})
    save(E / 'wind-native-counts.json', {'rows': wind_rows, 'checked_BDS50_interval_census': bds50,
        'source_review_sha256': sha(E / 'source-review.json'), 'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'limits': 'Native incoming calls are observed. Expected population is reached BDS50 scores plus lazy fallback calls, from the separate post-collection checked census. Candidate and score probes overlap each other and whole-message work. The full persistent table is initialized before main; zero constructor entries inside decoder roots does not mean zero startup work.'})
    perf = read(E / 'perf/analysis.json')
    perf_completion = read(E / 'perf/completion.json')
    assert perf_completion['samples'] == perf['total_samples']
    assert perf_completion['included_decode_stacks'] == perf['decode_descendant_samples']
    unknown_leaves = perf_completion['unknown_decode_leaf_samples']
    notes = [
        'Generation 13 replaces only the BDS50 wind penalty with an exact immutable 2,047-entry table keyed by the signed difference of two ten-bit field codes. The entry retains the original software binary64 rounding, absolute value, division by 100 and subtraction from zero; both status checks and the separate turn penalty remain. The equality is proved for every Nat word, including missing statuses and words beyond the message width. [Source/native review](../tests/evidence/diagnostics/gen13/source-review.json) retains the fresh timed-worker C and actual lookup/initializer assembly.', '',
        'The complete table is created and marked persistent during module initialization, before main and before collection. The live cbWindPenalty50 helper checks statuses, extracts the two field codes and reads one table entry; both fast inference and the full software fallback use the same cbPenalty path. The final BDS50 turn subtraction and BDS60 IAS/Mach division remain live software operations. No table is keyed by a message or corpus item. All other production source/C/object/trace sets are unchanged from generation 12, as recorded by the source review.', '',
        f"The diagnostic checkout and original timed generation-13 commit are both `{campaign['commit']}`. The driver reuses all production objects from the exact 22-set fresh benchmark inventory, with unchanged source/C/object/trace and binary hashes. No historical attribution remapping is needed for this generation. The benchmark remains a separate measurement; these counters are not throughput samples.", '',
        'The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.', '',
        'One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.', '',
        'All immutable density, Mach, QNH and wind-penalty tables initialize before main. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.', '',
        f"Native perf recording completed before any native census or Callgrind worker began. Family/probe profiles intentionally overlapped with at most six active workers. Other agents performed read-only reviews; no host-wide isolation is claimed. Of {perf['total_samples']:,} samples, {perf['decode_descendant_samples']:,} have a visible decoder ancestor and {perf['excluded_samples']:,} are excluded; {perf['all_samples_with_unknown_frame']:,} stacks contain an unknown frame and {unknown_leaves:,} included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen13/perf/README.md).", '',
        'The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.', '']
    notes_path = E / 'context-notes.md'
    notes.extend(['Byte-helper native entries reconcile with the separately checked corpus lengths:', '',
                  '| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |',
                  '|---|---:|---:|---:|---:|---:|'])
    for row in byte_counts:
        notes.append(f"| {row['family']} | {row['seven_byte_frames']:,} | {row['fourteen_byte_frames']:,} | {row['bytesValue_entries']:,} | {row['prefix_entries']:,} | {row['wide_fallback_entries']:,} |")
    notes.extend(['', 'These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen13/byte-native-counts.json).', ''])
    notes.extend(['The live `cbPenalty` boundary in each supplemental register probe:', '',
                  '| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |',
                  '|---|---:|---:|---:|---:|---:|---:|'])
    for row in penalty_rows:
        notes.append(f"| {row['probe']} | {row['probe_entries']:,} | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} | {row['probe_total_ir']:,} |")
    notes.extend(['', 'Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen13/penalty-probe-costs.json).', ''])
    notes.extend(['The new live wind lookup and eager table construction are distinguished explicitly:', '',
        '| Profile | Expected lookup calls | Observed lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Entry construction inside root |',
        '|---|---:|---:|---:|---:|---:|---:|'])
    for row in wind_rows:
        notes.append(f"| {row['profile']} | {row['expected_lookup_calls']:,} | {row['native_lookup_entries']:,} | {row['lookup_self_ir']:,} | {row['lookup_incoming_inclusive_ir_non_additive']:,} | {row['table_entry_constructor_calls_inside_collected_root']:,} |")
    notes.extend(['', 'The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen13/wind-native-counts.json).', ''])
    assert not notes_path.exists()
    notes_path.write_text('\n'.join(notes) + '\n')
    run([sys.executable, 'review/diagnostics/write_cost_report.py', '--generation', '13',
         '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
         '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
         '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
         '--benchmark', 'bench/runs/gen13/summary.json', '--previous-analysis',
         'tests/evidence/diagnostics/gen12/analysis/analysis.json', '--previous-generation', '12',
         '--evidence-root', str(E), '--source-review', str(E / 'source-review.json'),
         '--context-notes', str(notes_path), '--output', 'docs/GEN13-COST-BREAKDOWN.md'], 'report')
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
        'report': 'docs/GEN13-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN13-COST-BREAKDOWN.md'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'archive_manifest_sha256': sha(E / 'archive-manifest.json'),
        'helper_comparison_sha256': sha(E / 'helper-comparison.json'),
        'shared_syndrome_native_counts_match_checked_corpus': True,
        'integer_gate_native_counts_match_choose': True,
        'qnh_table_live_path_verified': True,
        'word_crc_live_path_verified': True,
        'byte_words_live_path_verified': True,
        'byte_native_counts_match_corpus_lengths': True,
        'byte_native_counts_sha256': sha(E / 'byte-native-counts.json'),
        'penalty_probe_costs_sha256': sha(E / 'penalty-probe-costs.json'),
        'bds50_wind_penalty_live_path_verified': True,
        'wind_native_counts_match_checked_populations': True,
        'wind_native_counts_sha256': sha(E / 'wind-native-counts.json'),
        'live_crc_census': campaign['live_crc_census'],
        'interval_census': campaign['interval_census']})
    print(json.dumps(read(E / 'validation.json')))


if __name__ == '__main__':
    main()

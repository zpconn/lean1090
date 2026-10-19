#!/usr/bin/env python3
"""Archive and report the completed gen17 instruction campaign; no native run."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys
sys.dont_write_bytecode = True

E = Path('tests/evidence/diagnostics/gen17')
C = Path('.cache/gen17-costs')
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
    from snapshot_history import verify
    return verify(read(E / 'historical-inputs.json'))


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
    source = read(E / 'independent-review/source-review.json')
    capture = read(E / 'perf/capture.json')
    assert datetime.fromisoformat(capture['completed_utc']) < datetime.fromisoformat(campaign['started_utc'])
    run([sys.executable, 'review/diagnostics/analyze_callgrind.py', '--self-test'], 'parser-fixtures')
    run([sys.executable, 'review/diagnostics/archive_cost_campaign.py', '--cache', str(C), '--output', str(E),
         '--perf-data', str(C / 'perf-gen17/perf.data'), '--extra-evidence', 'independent-review/source-review.json',
         '--extra-evidence', 'independent-review/source-inspection', '--extra-evidence', 'historical-inputs.json',
         '--extra-evidence', 'snapshot_history.py', '--extra-evidence', 'history.stdout',
         '--extra-evidence', 'history.stderr',
         '--extra-evidence', 'finalize.py', '--extra-evidence', 'extract_ratio_contexts.py',
         '--extra-evidence', 'extract_constant_contexts.py', '--extra-evidence', 'benchmark-source-binding.json',
         '--extra-evidence', 'seal_perf.py', '--extra-evidence', 'perf-analysis.stdout', '--extra-evidence', 'perf-analysis.stderr', '--extra-evidence', 'perf-seal.stdout', '--extra-evidence', 'perf-seal.stderr', '--extra-evidence', 'cleanup_cache.py', '--extra-evidence', 'extract_power_contexts.py',
         '--extra-evidence', 'parser-fixtures.stdout', '--extra-evidence', 'parser-fixtures.stderr',
         '--extra-evidence', 'driver-build.stdout', '--extra-evidence', 'driver-build.stderr',
         '--extra-evidence', 'driver-build-command.json', '--extra-evidence', 'source-binding-command.json', '--extra-evidence', 'source-binding.stdout', '--extra-evidence', 'source-binding.stderr', '--extra-evidence', 'run_prepared.py', '--extra-evidence', 'preparation.json', '--extra-evidence', 'build-prepared.stdout', '--extra-evidence', 'build-prepared.stderr', '--extra-evidence', 'extract_pack_fields.py'], 'archive')
    power_anchors = [value for key, value in source.items() if key.startswith('power_two_') and key.endswith('_anchor') and value]
    assert source['power_two_table_live_path_verified']
    argv = [sys.executable, 'review/diagnostics/analyze_callgrind.py', '--generation', '17', '--output', str(E / 'analysis')]
    for symbol in (source['exact_fallback_anchor'], source['pack_fields_fold_anchor'], source['parity_fold_anchor'], source['byte_word_prefix_anchor'], source['byte_word_fallback_anchor'], source['wind_penalty_anchor'], source['wind_penalty_table_entry_anchor'], source['ratio_enclosure_anchor'], P + 'bdsWireValid', 'lean_cstr_to_nat', P + 'commBPayloadLimit', P + 'Binary64_round', P + 'Binary64_div', 'l_Rat_div', P + 'bytesWord', P + 'field', P + 'bytesValue', P + 'packFields', P + 'payloadBits', P + 'payloadValue', P + 'affineValue', P + 'cbMach64', P + 'cbQNH64', P + 'cbValid40', P + 'cbDensityTerms', P + 'cbValid60', *source['integer_score_gate_anchors'].values()):
        argv.extend(['--extra-anchor', symbol])
    for symbol in power_anchors:
        argv.extend(['--extra-anchor', symbol])
    for family in ('adsb', 'commb', 'other'):
        argv.extend(['--profile', f'{family}={E}/callgrind/{family}/callgrind.out.1.gz'])
    for kind in ('candidate', 'score'):
        for register in ('40', '44', '45', '50', '60'):
            argv.extend(['--' + kind, f'{register}={E}/callgrind/{kind}{register}/callgrind.out.1.gz'])
    run(argv, 'analyze')
    analysis = read(E / 'analysis/analysis.json')
    previous = read('tests/evidence/diagnostics/gen16/analysis/analysis.json')
    comparison = []
    symbols = [P + name for name in ('field', 'bytesValue', 'packFields', 'Parity_syndrome', 'Parity_checksum', 'payloadValue', 'affineValue', 'ScoreGate_choose', 'ScoreGate_commonDenominator', 'ScoreGate_scaledNumerator', 'ScoreGate_scaledTotals', 'ScoreGate_mass', 'ScoreGate_center', 'ScoreGate_envelope', 'cbScorePasses', 'cbPenalty', 'cbQNH64', 'cbValid40', 'cbDensityTerms')]
    symbols.extend(source['integer_score_gate_anchors'].values())
    symbols.extend([source['byte_word_prefix_anchor'], source['byte_word_fallback_anchor'], P + 'bytesWord'])
    symbols.extend([source['wind_penalty_anchor'], source['wind_penalty_table_entry_anchor'], source['ratio_enclosure_anchor'], P + 'bdsWireValid', 'lean_cstr_to_nat', P + 'commBPayloadLimit', P + 'Binary64_round', P + 'Binary64_div', 'l_Rat_div'])
    symbols.extend((source['pack_fields_fold_anchor'], 'lean_nat_shiftl', 'lean_nat_big_shiftl', 'lean_nat_pow', 'l_BitVec_ofNat', 'lean_nat_big_shiftr', 'lean_uint64_of_big_nat'))
    symbols.extend([source['parity_fold_anchor'], read('tests/evidence/diagnostics/gen16/independent-review/source-review.json')['parity_fold_anchor']])
    symbols.extend(power_anchors)
    for symbol in dict.fromkeys(symbols):
        for stage in analysis['stage_definitions']:
            before, after = grouped(previous, symbol, stage), grouped(analysis, symbol, stage)
            if before['contexts'] or after['contexts']:
                comparison.append({'symbol': symbol, 'stage': stage, 'gen16': before, 'gen17': after})
    save(E / 'helper-comparison.json', {
        'kind': 'non_additive_retained_native_boundary_comparison', 'rows': comparison,
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'previous_analysis_sha256': sha('tests/evidence/diagnostics/gen16/analysis/analysis.json'),
        'limits': 'Only self events by unique stage are partitions. Incoming inclusive costs overlap. Integer helpers remain live; inline affine and scaled numerator work remains in callers. Missing symbols are not zero computations or measured savings.'})
    assert source['pack_fields_shift_mask_verified']
    assert source['shared_syndrome_decode_verified']
    assert campaign['live_crc_census']['population'] == 'accepted_corpus_only'
    assert source['integer_score_gate_verified']
    assert source['field_mask_verified']
    assert source['qnh_table_live_path_verified']
    assert source['word_crc_live_path_verified']
    assert source['byte_words_live_path_verified']
    assert source['bds50_wind_penalty_live_path_verified']
    assert source['bds60_ratio_enclosure_live_path_verified']
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
    save(E / 'byte-native-counts.json', {'rows': byte_counts, 'source_review_sha256': sha(E / 'independent-review/source-review.json'),
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
        'source_review_sha256': sha(E / 'independent-review/source-review.json'), 'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'limits': 'Native incoming calls are observed. Expected population is reached BDS50 scores plus lazy fallback calls, from the separate post-collection checked census. Candidate and score probes overlap each other and whole-message work. The full persistent table is initialized before main; zero constructor entries inside decoder roots does not mean zero startup work.'})
    run([sys.executable, str(E / 'extract_ratio_contexts.py')], 'ratio-contexts')
    ratio_contexts = read(E / 'ratio-native-contexts.json')
    run([sys.executable, str(E / 'extract_constant_contexts.py')], 'constant-contexts')
    constant_contexts = read(E / 'constant-native-contexts.json')
    run([sys.executable, str(E / 'extract_pack_fields.py')], 'pack-contexts')
    pack = read(E / 'pack-fields-direct-costs.json')
    run([sys.executable, str(E / 'extract_power_contexts.py')], 'power-contexts')
    power = read(E / 'power-native-contexts.json')
    perf = read(E / 'perf/analysis.json')
    perf_completion = read(E / 'perf/completion.json')
    assert perf_completion['samples'] == perf['total_samples']
    assert perf_completion['included_decode_stacks'] == perf['decode_descendant_samples']
    unknown_leaves = perf_completion['unknown_decode_leaf_samples']
    notes = [
        'Generation 17 changes only Binary64.powerTwo: an immutable 2,098-entry table covers format exponents −1074 through 1023, with the original total formula retained outside that range. Equality is proved for every integer exponent and propagated through decoder and CPR proofs. [Source/native review](../tests/evidence/diagnostics/gen17/independent-review/source-review.json) retains the actual indexed lookup, mutually exclusive formula fallback branches and complete eager initializer. The field-packing implementation is unchanged from generation 16. Instruction observations below compare this live implementation with generation 16; no speedup is inferred from instruction differences.', '',
        'The current checkout contains the committed generation-17 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.', '',
        'The live UInt32 loop, syndrome, checksum, byte fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.', '',
        'One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed UInt32 loop has one entry per syndrome. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.', '',
        'All immutable density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.', '',
        f"Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of {perf['total_samples']:,} samples, {perf['decode_descendant_samples']:,} have a visible decoder ancestor and {perf['excluded_samples']:,} are excluded; {perf['all_samples_with_unknown_frame']:,} stacks contain an unknown frame and {unknown_leaves:,} included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen17/perf/README.md).", '',
        'The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.', '']
    notes_path = E / 'context-notes.md'
    notes.extend(['Byte-helper native entries reconcile with the separately checked corpus lengths:', '',
                  '| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |',
                  '|---|---:|---:|---:|---:|---:|'])
    for row in byte_counts:
        notes.append(f"| {row['family']} | {row['seven_byte_frames']:,} | {row['fourteen_byte_frames']:,} | {row['bytesValue_entries']:,} | {row['prefix_entries']:,} | {row['wide_fallback_entries']:,} |")
    notes.extend(['', 'These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen17/byte-native-counts.json).', ''])
    notes.extend(['The live `cbPenalty` boundary in each supplemental register probe:', '',
                  '| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |',
                  '|---|---:|---:|---:|---:|---:|---:|'])
    for row in penalty_rows:
        notes.append(f"| {row['probe']} | {row['probe_entries']:,} | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} | {row['probe_total_ir']:,} |")
    notes.extend(['', 'Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen17/penalty-probe-costs.json).', ''])
    notes.extend(['The retained live wind lookup and eager table construction are distinguished explicitly:', '',
        '| Profile | Expected lookup calls | Observed lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Entry construction inside root |',
        '|---|---:|---:|---:|---:|---:|---:|'])
    for row in wind_rows:
        notes.append(f"| {row['profile']} | {row['expected_lookup_calls']:,} | {row['native_lookup_entries']:,} | {row['lookup_self_ir']:,} | {row['lookup_incoming_inclusive_ir_non_additive']:,} | {row['table_entry_constructor_calls_inside_collected_root']:,} |")
    notes.extend(['', 'The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen17/wind-native-counts.json).', ''])
    notes.extend(['The BDS60 ratio enclosure and its observed software-round fallback:', '',
        '| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |',
        '|---|---:|---:|---:|---:|---:|---:|'])
    for row in ratio_contexts['rows']:
        if row['generation'] != 17:
            continue
        ratio = row['ratio']
        notes.append(f"| {row['profile']} | {ratio['native_entries']:,} | {row['ratio_shortcut_entries']:,} | {row['ratio_round_fallback_entries']:,} | {ratio['self_ir']:,} | {ratio['incoming_inclusive_ir_non_additive']:,} | {row['ratio_round_fallback_inclusive_ir_non_additive']:,} |")
    notes.extend(['', 'These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen17/ratio-native-contexts.json) also records generation 16 and 17 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.', ''])
    notes.extend(['The live Comm-B guard and its direct decimal-parser calls:', '',
        '| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |',
        '|---|---|---:|---:|---:|---:|---:|'])
    for row in constant_contexts['rows']:
        notes.append(f"| {row['generation']} | {row['profile']} | {row['native_entries']:,} | {row['self_ir']:,} | {row['inclusive_ir_non_additive']:,} | {row['direct_parser_calls']:,} | {row['direct_parser_ir_non_additive']:,} |")
    notes.extend(['', 'These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen17/constant-native-contexts.json).', ''])
    notes.extend(['The live general packing fold and its observed direct native calls:', '',
        '| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |',
        '|---|---:|---:|---:|---|---:|---:|'])
    for item in pack['generations']:
        totals = item['total']
        for symbol, values in sorted(item['direct_children_total'].items()):
            notes.append(f"| {item['generation']} | {totals['entry_calls']:,} | {totals['self_ir']:,} | {totals['incoming_inclusive_ir']:,} | `{symbol}` | {values['calls']:,} | {values['inclusive_ir']:,} |")
    notes.extend(['', 'Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The generic power/modulus branch remains in the actual binary for widths at least 64, even if the corpus has no observed calls. [Exact packing contexts](../tests/evidence/diagnostics/gen17/pack-fields-direct-costs.json).', ''])
    notes.extend(['The live power-of-two lookup, formula fallback and startup construction:', '',
        '| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |',
        '|---|---|---:|---:|---:|---:|---:|---:|'])
    for row in power['rows']:
        lookup = row['lookup']
        constructors = sum(row[key]['native_entries'] for key in ('table_entry', 'table_initializer', 'module_initializer'))
        notes.append(f"| {row['generation']} | {row['profile']} | {lookup['native_entries']:,} | {lookup['self_ir']:,} | {lookup['incoming_inclusive_ir_non_additive']:,} | {row['direct_lookup_formula_calls']:,} | {row['direct_lookup_formula_inclusive_ir_non_additive']:,} | {constructors:,} |")
    notes.extend(['', 'These are actual retained incoming boundaries and direct lookup-to-formula edges. Generation 16 implements the formula inside powerTwo and has no separate formula/table symbols. In generation 17, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen17/power-native-contexts.json).', ''])
    assert not notes_path.exists()
    notes_path.write_text('\n'.join(notes) + '\n')
    run([sys.executable, 'review/diagnostics/write_cost_report.py', '--generation', '17',
         '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
         '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
         '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
         '--benchmark', 'bench/runs/gen17/summary.json', '--previous-analysis',
         'tests/evidence/diagnostics/gen16/analysis/analysis.json', '--previous-generation', '16',
         '--evidence-root', str(E), '--source-review', str(E / 'independent-review/source-review.json'),
         '--benchmark-source-binding', str(E / 'benchmark-source-binding.json'),
         '--context-notes', str(notes_path), '--output', 'docs/GEN17-COST-BREAKDOWN.md'], 'report')
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
        'historical_binding_method': 'committed Git inventory and diff; ignored transcripts/raw perf held by exact filesystem identity, not freshly content-rehashed',
        'archive_files': archive['file_count'], 'archive_bytes': archive['stored_bytes'],
        'exclusive_stage_ir': dict(stages), 'total_ir': sum(stages.values()),
        'report': 'docs/GEN17-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN17-COST-BREAKDOWN.md'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'archive_manifest_sha256': sha(E / 'archive-manifest.json'),
        'helper_comparison_sha256': sha(E / 'helper-comparison.json'),
        'shared_syndrome_native_counts_match_checked_corpus': True,
        'integer_gate_native_counts_match_choose': True,
        'power_two_table_live_path_verified': True,
        'power_native_contexts_sha256': sha(E / 'power-native-contexts.json'),
        'qnh_table_live_path_verified': True,
        'pack_fields_shift_mask_verified': True,
        'pack_fields_direct_costs_sha256': sha(E / 'pack-fields-direct-costs.json'),
        'word_crc_live_path_verified': True,
        'byte_words_live_path_verified': True,
        'byte_native_counts_match_corpus_lengths': True,
        'byte_native_counts_sha256': sha(E / 'byte-native-counts.json'),
        'penalty_probe_costs_sha256': sha(E / 'penalty-probe-costs.json'),
        'bds50_wind_penalty_live_path_verified': True,
        'bds60_ratio_enclosure_live_path_verified': True,
        'commb_payload_limit_live_path_verified': source['commb_payload_limit_live_path_verified'],
        'constant_native_contexts_sha256': sha(E / 'constant-native-contexts.json'),
        'benchmark_source_binding_sha256': sha(E / 'benchmark-source-binding.json'),
        'ratio_native_contexts_sha256': sha(E / 'ratio-native-contexts.json'),
        'wind_native_counts_match_checked_populations': True,
        'wind_native_counts_sha256': sha(E / 'wind-native-counts.json'),
        'live_crc_census': campaign['live_crc_census'],
        'interval_census': campaign['interval_census']})
    print(json.dumps(read(E / 'validation.json')))


if __name__ == '__main__':
    main()

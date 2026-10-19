#!/usr/bin/env python3
"""Archive and report the completed gen21 instruction campaign; no native run."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys
sys.dont_write_bytecode = True

E = Path('tests/evidence/diagnostics/gen21')
C = Path('.cache/gen21-costs')
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
    correction = read(E / 'finalizer-correction.json')
    for name, digest in correction['preserved_bindings'].items():
        assert sha(name) == digest, name
    for name, digest in correction['corrected_bindings'].items():
        assert sha(name) == digest, name
    campaign = read(C / 'campaign.json')
    assert campaign['status'] == 'passed' and len(campaign['profiles']) == 13
    count = history()
    source = read(E / 'independent-review/source-review.json')
    analysis = read(E / 'analysis/analysis.json')
    byte_counts = read(E / 'byte-native-counts.json')['rows']
    penalty_rows = read(E / 'penalty-probe-costs.json')['rows']
    run([sys.executable, str(E / 'extract_ratio_contexts_corrected.py')], 'ratio-contexts-02')
    ratio_contexts = read(E / 'ratio-native-contexts.json')
    run([sys.executable, str(E / 'extract_constant_contexts.py')], 'constant-contexts')
    constant_contexts = read(E / 'constant-native-contexts.json')
    run([sys.executable, str(E / 'extract_pack_fields.py')], 'pack-contexts')
    pack = read(E / 'pack-fields-direct-costs.json')
    run([sys.executable, str(E / 'extract_power_contexts.py')], 'power-contexts')
    power = read(E / 'power-native-contexts.json')
    run([sys.executable, str(E / 'extract_priority_contexts.py')], 'priority-contexts')
    priority = read(E / 'priority-helper-contexts.json')
    run([sys.executable, str(E / 'extract_bit_contexts.py')], 'bit-contexts')
    bit_contexts = read(E / 'bit-extraction-contexts.json')
    run([sys.executable, str(E / 'extract_crc_contexts.py')], 'crc-contexts')
    crc_contexts = read(E / 'crc-byte-contexts.json')
    run([sys.executable, str(E / 'extract_affine_contexts.py')], 'affine-contexts')
    affine = read(E / 'affine-native-contexts.json')
    perf = read(E / 'perf/analysis.json')
    perf_completion = read(E / 'perf/completion.json')
    assert perf_completion['samples'] == perf['total_samples']
    assert perf_completion['included_decode_stacks'] == perf['decode_descendant_samples']
    unknown_leaves = perf_completion['unknown_decode_leaf_samples']
    notes = [
        'Generation 21 uses exact integer-times-rational normalization on the existing nonunit-scale affine branch. Identity scaling, zero offset, status and extraction behavior remain unchanged. The unconditional helper equality covers every integer and rational scale. [Current source/native review](../tests/evidence/diagnostics/gen21/independent-review/source-review.json) binds actual payloadValue code, inlined normalization, both shortcuts and surviving call boundaries. This report collects actual Impl.decode only; the separate CPR diagnostic covers tracking and numeric geography. Comparisons with generation 20 are instruction observations, not throughput predictions or inferred path distributions.', '',
        'The current checkout contains the committed generation-21 result artifacts after the timed source commit. The explicit benchmark-source binding verifies ancestry and equality of the complete audited Lean inventory, linked native sources/C/objects/traces, lock and actual timed worker. The two commit identities are recorded separately; this diagnostic is not a new benchmark.', '',
        'The live UInt32 byte loop and generic bit-loop fallback, syndrome, checksum, byte-value fold, frame field extractor and field-packing helper are retained as explicit nested anchors. The old standalone Parity.step boundary is absent because its update is inlined; absence is not zero work. The byte prefix and original arbitrary-precision byte-fold boundaries are explicit comparison rows. The latter is reachable only for input lists longer than sixteen bytes, outside the accepted 7/14-byte corpus. Incoming inclusive costs overlap each other and the exclusive stages; they are not additive subdivisions. Whole-message output construction, semantic affine guards, machine-word field extraction and exact integer score decisions remain live.', '',
        'One syndrome is computed for each successfully parsed corpus frame and reused through acceptance, report and address recovery. The separate post-collection CRC census checks all 172,432 accepted corpus frames against retained outputs. Its bit-update count is a prediction from widths, not a native step-call measurement. The observed byte loop has one entry per syndrome in this accepted corpus. Its byte-iteration count is predicted from frame widths, and each byte performs eight inlined updates. The callable bit-loop fallback has no observed entries here; it remains live for other widths. This accepted corpus does not measure rejection paths or arbitrary huge widths; those may retain arbitrary-precision index operations and allocations. Rational center/envelope/mass remain reference APIs used by the post-collection score census. Integer choose/common-denominator/pair-fold and lazy fallback entries are reconciled with the separately checked register populations.', '',
        'All immutable density, Mach, QNH, wind-penalty and power-of-two tables initialize before main. The power constructor invokes the original formula directly, without calling its own lookup. Scalar lazy constants can initialize on early collected calls, and each process has its own allocator state; no unmeasured correction is applied. The persistent tables depend only on format/field codes, never messages or corpus contents. Missing standalone or inlined helper boundaries do not imply zero computation.', '',
        f"Native perf recording completed before any native census or Callgrind worker began. The decode family/probe campaign permits at most six overlapping workers and may overlap the separate CPR instruction diagnostic. Other agents performed read-only reviews; no host-wide isolation is claimed. Of {perf['total_samples']:,} samples, {perf['decode_descendant_samples']:,} have a visible decoder ancestor and {perf['excluded_samples']:,} are excluded; {perf['all_samples_with_unknown_frame']:,} stacks contain an unknown frame and {unknown_leaves:,} included leaves are unknown. These conditional observations cannot reliably allocate whole-decoder time. Capture conditions and loss counters are retained in [perf/README.md](../tests/evidence/diagnostics/gen21/perf/README.md).", '',
        'The helper comparison retains actual per-stage native entries, self counts and incoming inclusive edge totals for both generations. Recursive/re-entrant calls can overlap within an inclusive row, and descendants can cross a later stage boundary. Only the exact self-event stage partition is additive. No instruction delta is interpreted as a predicted speedup. No production, proof or frozen source changed during collection.', '']
    notes.extend(['The initial finalizer completed archival and full raw analysis, then stopped because one comparison extractor still selected generation 19/20 raw paths against generation 20/21 analysis. The original source, failed logs, archive and analysis remain unchanged. A corrected copy selects the intended 20/21 profiles and this resumed finalizer continues after the completed work; no native collection was repeated. [Correction record](../tests/evidence/diagnostics/gen21/finalizer-correction.json).', ''])
    notes_path = E / 'context-notes.md'
    notes.extend(['CRC wrapper and loop entries reconcile with the separately checked accepted-corpus census:', '',
                  '| Profile | Predicted CRC calls | Observed byte wrapper / loop | Observed bit wrapper / loop | Predicted byte iterations | Predicted bit updates |',
                  '|---|---:|---:|---:|---:|---:|'])
    for row in crc_contexts['native_counts']:
        observed = row['observed_native_entries']
        notes.append(f"| {row['profile']} | {row['expected_crc_calls_from_checked_census']:,} | {observed['parity_byte_wrapper_anchor']:,} / {observed['parity_byte_fold_anchor']:,} | {observed['parity_bit_wrapper_anchor']:,} / {observed['parity_bit_fold_anchor']:,} | {row['predicted_byte_iterations_not_native_entries']:,} | {row['predicted_bit_updates_not_native_entries']:,} |")
    notes.extend(['', 'Observed entries are incoming native calls; iteration predictions are separate mathematical census data. All ten overlapping register probes are checked separately. The generic fallback remains callable and proved for arbitrary inputs; its zero accepted-corpus count does not remove its implementation or cost for unseen widths. Byte extraction and eight updates inline into the actual loop, which still contains natural-index and ownership work. [CRC boundary and direct-child evidence](../tests/evidence/diagnostics/gen21/crc-byte-contexts.json) compares both generations without copying old profiles or inferring elapsed time.', '',
                  '| Generation | CRC boundary | Native entries | Self Ir | Incoming inclusive Ir |',
                  '|---|---|---:|---:|---:|'])
    for generation in crc_contexts['generations']:
        for row in generation['rows']:
            notes.append(f"| {generation['generation']} | `{row['symbol'].removeprefix(P)}` | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} |")
    notes.extend(['', 'These nested inclusive rows overlap each other and frame/CRC stage cost. Only the exclusive stage partition can be added.', ''])
    notes.extend(['Byte-helper native entries reconcile with the separately checked corpus lengths:', '',
                  '| Family | 7-byte frames | 14-byte frames | bytesValue entries | Prefix entries | >16-byte fallback entries |',
                  '|---|---:|---:|---:|---:|---:|'])
    for row in byte_counts:
        notes.append(f"| {row['family']} | {row['seven_byte_frames']:,} | {row['fourteen_byte_frames']:,} | {row['bytesValue_entries']:,} | {row['prefix_entries']:,} | {row['wide_fallback_entries']:,} |")
    notes.extend(['', 'These boundary counts do not measure the inlined byte-update iterations, which remain live inside bytesValue. The arbitrary-length fallback is outside this corpus, not removed. The exact count reconciliation is retained in [byte-native-counts.json](../tests/evidence/diagnostics/gen21/byte-native-counts.json).', ''])
    notes.extend(['The live `cbPenalty` boundary in each supplemental register probe:', '',
                  '| Probe | Probe entries | Penalty entries | Penalty self Ir | Penalty incoming inclusive Ir | Whole probe Ir |',
                  '|---|---:|---:|---:|---:|---:|---:|'])
    for row in penalty_rows:
        notes.append(f"| {row['probe']} | {row['probe_entries']:,} | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} | {row['probe_total_ir']:,} |")
    notes.extend(['', 'Candidate and score probes are overlapping views, not additive stages. Candidate probes include register hard checks and conditional scoring; score probes select the reached-score population before entering the collected root. Each inclusive penalty count includes its descendants and is not an additional cost to add to the whole probe or whole decoder. Exact rows are retained in [penalty-probe-costs.json](../tests/evidence/diagnostics/gen21/penalty-probe-costs.json).', ''])
    notes.extend(['The retained live wind lookup and eager table construction are distinguished explicitly:', '',
        '| Profile | Expected lookup calls | Observed lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Entry construction inside root |',
        '|---|---:|---:|---:|---:|---:|---:|'])
    for row in wind_rows:
        notes.append(f"| {row['profile']} | {row['expected_lookup_calls']:,} | {row['native_lookup_entries']:,} | {row['lookup_self_ir']:,} | {row['lookup_incoming_inclusive_ir_non_additive']:,} | {row['table_entry_constructor_calls_inside_collected_root']:,} |")
    notes.extend(['', 'The expected lookup population includes reached BDS50 scores and any lazy fallback calls, checked separately after collection. Construction happens before the measured decoder root; its zero observed root entries are not a zero startup-cost claim. Inclusive lookup costs overlap the penalty and whole-profile costs. Exact reconciliation is retained in [wind-native-counts.json](../tests/evidence/diagnostics/gen21/wind-native-counts.json).', ''])
    notes.extend(['The BDS60 ratio enclosure and its observed software-round fallback:', '',
        '| Profile | Ratio entries | Definite shortcuts | Software-round fallback entries | Ratio self Ir | Ratio incoming inclusive Ir | Fallback incoming inclusive Ir |',
        '|---|---:|---:|---:|---:|---:|---:|'])
    for row in ratio_contexts['rows']:
        if row['generation'] != 21:
            continue
        ratio = row['ratio']
        notes.append(f"| {row['profile']} | {ratio['native_entries']:,} | {row['ratio_shortcut_entries']:,} | {row['ratio_round_fallback_entries']:,} | {ratio['self_ir']:,} | {ratio['incoming_inclusive_ir_non_additive']:,} | {row['ratio_round_fallback_inclusive_ir_non_additive']:,} |")
    notes.extend(['', 'These are actual incoming helper and direct helper-to-round call records. The retained native CFG proves a single conditional round site; the shortcut count is helper entries minus those observed round entries. It is not a prediction of unseen input populations. Candidate and score probes overlap each other and the family profiles; all inclusive columns are non-additive. The retained [ratio-native-contexts.json](../tests/evidence/diagnostics/gen21/ratio-native-contexts.json) also records generation 20 and 21 cbPenalty direct edges, including the unchanged exact Rat.div and enclosure. Do not add inclusive descendants twice or infer wall-clock effects.', ''])
    notes.extend(['The live Comm-B guard and its direct decimal-parser calls:', '',
        '| Generation | Profile | Guard calls | Guard self Ir | Guard inclusive Ir | Direct parser calls | Parser inclusive Ir |',
        '|---|---|---:|---:|---:|---:|---:|'])
    for row in constant_contexts['rows']:
        notes.append(f"| {row['generation']} | {row['profile']} | {row['native_entries']:,} | {row['self_ir']:,} | {row['inclusive_ir_non_additive']:,} | {row['direct_parser_calls']:,} | {row['direct_parser_ir_non_additive']:,} |")
    notes.extend(['', 'These direct-edge observations refer only to the actual bdsWireValid context; other parser uses are separate. The same input populations are checked across generations. The persistent format constant initializes before message work, so zero direct calls inside this guard do not imply zero initialization work. Incoming inclusive columns overlap callers and other nested helpers; they are not additive stage totals. [Exact context evidence](../tests/evidence/diagnostics/gen21/constant-native-contexts.json).', ''])
    notes.extend(['The live general packing fold and its observed direct native calls:', '',
        '| Generation | Fold entries | Fold self Ir | Fold inclusive Ir | Direct native callee | Calls | Direct inclusive Ir |',
        '|---|---:|---:|---:|---|---:|---:|'])
    for item in pack['generations']:
        totals = item['total']
        for symbol, values in sorted(item['direct_children_total'].items()):
            notes.append(f"| {item['generation']} | {totals['entry_calls']:,} | {totals['self_ir']:,} | {totals['incoming_inclusive_ir']:,} | `{symbol}` | {values['calls']:,} | {values['inclusive_ir']:,} |")
    notes.extend(['', 'Direct children plus fold self cost reconcile to this nonrecursive loop boundary. They overlap whole-stage costs and other nested helpers. Native small-word shifts, masks and conversions may inline; missing helper symbols do not imply zero work. The generic power/modulus branch remains in the actual binary for widths at least 64, even if the corpus has no observed calls. [Exact packing contexts](../tests/evidence/diagnostics/gen21/pack-fields-direct-costs.json).', ''])
    notes.extend(['The live power-of-two lookup, formula fallback and startup construction:', '',
        '| Generation | Profile | Lookup calls | Lookup self Ir | Lookup incoming inclusive Ir | Direct formula calls | Formula direct inclusive Ir | Constructor calls inside root |',
        '|---|---|---:|---:|---:|---:|---:|---:|'])
    for row in power['rows']:
        lookup = row['lookup']
        constructors = sum(row[key]['native_entries'] for key in ('table_entry', 'table_initializer', 'module_initializer'))
        notes.append(f"| {row['generation']} | {row['profile']} | {lookup['native_entries']:,} | {lookup['self_ir']:,} | {lookup['incoming_inclusive_ir_non_additive']:,} | {row['direct_lookup_formula_calls']:,} | {row['direct_lookup_formula_inclusive_ir_non_additive']:,} | {constructors:,} |")
    notes.extend(['', 'These are actual retained incoming boundaries and direct lookup-to-formula edges. Both generations retain the same immutable format-exponent table. In the current worker, the two out-of-range call sites are mutually exclusive, with at most one dynamic formula invocation per lookup; the in-range path performs an indexed load. No frequency is inferred from inclusive instruction counts. The complete constructor is forced before main, outside these decode roots; its unobserved root calls do not erase startup work. Inclusive columns and overlapping register probes must not be added. [Exact power contexts](../tests/evidence/diagnostics/gen21/power-native-contexts.json).', ''])
    notes.extend(['The four optimized extraction paths, compared at actual retained native boundaries:', '',
        '| Generation | Stage | Native boundary | Entries | Self Ir | Incoming inclusive Ir | Direct pow calls | Direct pow inclusive Ir |',
        '|---|---|---|---:|---:|---:|---:|---:|'])
    for generation in bit_contexts['generations']:
        for row in generation['rows']:
            powers = [child for child in row['direct_children'] if child['symbol'] == 'lean_nat_pow']
            notes.append(f"| {generation['generation']} | {row['stage']} | `{row['symbol'].removeprefix(P)}` | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} | {sum(child['calls'] for child in powers):,} | {sum(child['inclusive_ir_non_additive'] for child in powers):,} |")
    notes.extend(['', 'Both generations inline the identity lambda into identityCode; missing standalone rows do not erase the live extraction. Other small arithmetic can inline too. Native entry populations across these changed boundaries are not assumed equal. The current direct-power count is zero only for these selected caller boundaries, consistent with the checked shift/mask implementation; it is not a zero-work claim or a claim about all decoder powers. Incoming inclusive columns overlap stage totals and other helpers. [Exact old/new contexts and direct children](../tests/evidence/diagnostics/gen21/bit-extraction-contexts.json) bind both raw profile sets without copying them or predicting timing.', ''])
    notes.extend(['The exact affine helper is compared at surviving native boundaries:', '',
                  '| Generation | Stage | Boundary | Entries | Self Ir | Incoming inclusive Ir |',
                  '|---|---|---|---:|---:|---:|'])
    for generation in affine['generations']:
        for row in generation['rows']:
            notes.append(f"| {generation['generation']} | {row['stage']} | `{row['symbol'].removeprefix(P)}` | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} |")
    notes.extend(['', 'The payloadValue entry populations are independently checked equal by stage across these two profiles. Inline integerScale/affineValue calls have no standalone native entry count. The current source and all-input proof establish normalization and preserved guards; actual direct children below show the observed arithmetic boundaries.', '',
                  '| Generation | Stage | Direct child of payloadValue | Calls | Inclusive Ir |',
                  '|---|---|---|---:|---:|'])
    for generation in affine['generations']:
        for row in generation['rows']:
            if row['symbol'] != P + 'payloadValue':
                continue
            for child in row['direct_children']:
                notes.append(f"| {generation['generation']} | {row['stage']} | `{child['symbol'].removeprefix(P)}` | {child['calls']:,} | {child['inclusive_ir_non_additive']:,} |")
    notes.extend(['', 'These are overlapping incoming/direct-edge observations, not exclusive savings. Zero current direct Rat.mul calls concern only the listed payloadValue contexts: normalization still performs a numerator product, gcd and exact divisions, with small-value operations possibly inlined. Child calls do not count every nonunit input or logical operation. [Exact affine contexts](../tests/evidence/diagnostics/gen21/affine-native-contexts.json) retain both profile hashes and group reconciliation.', ''])
    notes.extend(['Selected actual nested helpers for prioritization:', '',
        '| Stage | Native helper | Entries | Self Ir | Incoming inclusive Ir |',
        '|---|---|---:|---:|---:|'])
    for row in priority['rows']:
        notes.append(f"| {row['stage']} | `{row['symbol'].removeprefix(P)}` | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} |")
    notes.extend(['', 'These rows aggregate only the three disjoint family profiles. Incoming inclusive observations overlap each other and stage totals, including recursive visits and descendants crossing a stage boundary. Direct native children and exact caller contexts are retained in [priority-helper-contexts.json](../tests/evidence/diagnostics/gen21/priority-helper-contexts.json). Rat multiplication rows do not count every logical affine operation; inline work remains in callers. These observations do not select an optimization or infer throughput.', ''])
    assert not notes_path.exists()
    notes_path.write_text('\n'.join(notes) + '\n')
    run([sys.executable, 'review/diagnostics/write_cost_report.py', '--generation', '21',
         '--analysis', str(E / 'analysis/analysis.json'), '--census', str(E / 'native/all.jsonl'),
         '--native-df', str(E / 'native-df/summary.json'), '--perf', str(E / 'perf/analysis.json'),
         '--build', str(E / 'driver/driver-build.json'), '--campaign', str(E / 'campaign.json'),
         '--benchmark', 'bench/runs/gen21/summary.json', '--previous-analysis',
         'tests/evidence/diagnostics/gen20/analysis/analysis.json', '--previous-generation', '20',
         '--evidence-root', str(E), '--source-review', str(E / 'independent-review/source-review.json'),
         '--benchmark-source-binding', str(E / 'benchmark-source-binding.json'),
         '--context-notes', str(notes_path), '--output', 'docs/GEN21-COST-BREAKDOWN.md'], 'report')
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
        'status': 'passed', 'finalizer_correction_sha256': sha(E / 'finalizer-correction.json'), 'completed_utc': datetime.now(timezone.utc).isoformat(),
        'commit': campaign['commit'], 'profiles': 13, 'all_self_sums_exact': True,
        'all_stage_contexts_unique': True, 'all_root_counts_outputs_and_census_validated': True,
        'interval_native_counts_match_checked_populations': True,
        'protected_inputs_unchanged': True, 'protected_input_count': len(campaign['protected_inputs']),
        'historical_reports_evidence_and_samples_unchanged': True, 'historical_file_count': count,
        'historical_binding_method': 'committed Git inventory and diff; ignored transcripts/raw perf held by exact filesystem identity, not freshly content-rehashed',
        'archive_files': archive['file_count'], 'archive_bytes': archive['stored_bytes'],
        'exclusive_stage_ir': dict(stages), 'total_ir': sum(stages.values()),
        'report': 'docs/GEN21-COST-BREAKDOWN.md', 'report_sha256': sha('docs/GEN21-COST-BREAKDOWN.md'),
        'analysis_sha256': sha(E / 'analysis/analysis.json'),
        'archive_manifest_sha256': sha(E / 'archive-manifest.json'),
        'helper_comparison_sha256': sha(E / 'helper-comparison.json'),
        'priority_helper_contexts_sha256': sha(E / 'priority-helper-contexts.json'),
        'bit_extraction_contexts_sha256': sha(E / 'bit-extraction-contexts.json'),
        'shared_syndrome_native_counts_match_checked_corpus': True,
        'integer_gate_native_counts_match_choose': True,
        'power_two_table_live_path_verified': True,
        'dyadic_to_float_live_path_verified': source['dyadic_to_float_live_path_verified'],
        'systematic_bit_extraction_verified': source['systematic_bit_extraction_verified'],
        'integer_affine_normalization_live_path_verified': True,
        'affine_native_contexts_sha256': sha(E / 'affine-native-contexts.json'),
        'power_native_contexts_sha256': sha(E / 'power-native-contexts.json'),
        'qnh_table_live_path_verified': True,
        'pack_fields_shift_mask_verified': True,
        'pack_fields_direct_costs_sha256': sha(E / 'pack-fields-direct-costs.json'),
        'word_crc_live_path_verified': True,
        'byte_crc_live_path_verified': True,
        'byte_crc_native_counts_match_checked_corpus': True,
        'crc_byte_contexts_sha256': sha(E / 'crc-byte-contexts.json'),
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

#!/usr/bin/env python3
"""Retain caller-separated CRC observations from existing gen5 profiles only."""
from collections import Counter
from datetime import datetime, timezone
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

E = Path('tests/evidence/diagnostics/gen5')
REPORT = Path('docs/GEN5-COST-BREAKDOWN.md')
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def write_new(path, content):
    assert not path.exists(), 'preserve prior evidence: ' + str(path)
    path.write_bytes(content)


def main():
    parser_path = Path('review/diagnostics/analyze_callgrind.py')
    spec = importlib.util.spec_from_file_location('callgrind_reader', parser_path)
    cg = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = cg
    spec.loader.exec_module(cg)
    analysis = read(E / 'analysis/analysis.json')
    census = next(json.loads(line) for line in (E / 'native/all.jsonl').read_text().splitlines()
                  if json.loads(line).get('kind') == 'post_decode_shadow_census')
    per_df = {row['df']: row for row in census['per_df']}
    family_dfs = {'adsb': [17, 18], 'commb': [20, 21],
                  'other': [i for i in range(32) if i not in [17, 18, 20, 21]]}
    roles = {P + 'frameAccepted': 'acceptance', P + 'report': 'report_syndrome',
             P + 'frameAddress': 'address_recovery'}
    anchors = ('frameSyndrome', 'Parity_checksum', 'frameParts', 'packFields')
    records, inputs, expectations = [], {}, {}
    for family in family_dfs:
        path = E / f'callgrind/{family}/callgrind.out.1.gz'
        inputs[str(path)] = sha(path)
        profile = cg.parse(path)
        expected = {
            'acceptance': per_df[17]['count'] if family == 'adsb' else 0,
            'report_syndrome': sum(per_df[df]['count'] for df in family_dfs[family]),
            'address_recovery': sum(per_df[df]['count'] for df in family_dfs[family]
                                    if df in (0, 4, 5, 16, 20, 21)),
            'df11_interrogator': per_df[11]['count'] if family == 'other' else 0}
        expectations[family] = expected
        # Each selected target context has one actual incoming native caller.
        # Caller suffixes are retained verbatim, and their direct edges are
        # checked rather than relying on a substring match alone.
        for name, node in profile.nodes.items():
            symbol = cg.base_name(name)
            if symbol not in {P + a for a in anchors} | {P + 'Parity_interrogator'}:
                continue
            incoming = [{'caller_context': caller.name, 'native_entries': caller.calls[name],
                         'inclusive_ir_non_additive': edge.get('Ir', 0)}
                        for caller in profile.nodes.values()
                        if (edge := caller.edges.get(name)) and edge.get('Ir', 0) > 0]
            if not incoming:
                assert node.own.get('Ir', 0) == 0
                continue
            assert len(incoming) == 1, (family, name, incoming)
            parts = name.split("'")
            direct = cg.base_name(incoming[0]['caller_context'])
            assert parts[1] == direct, (name, direct)
            if symbol == P + 'Parity_interrogator':
                assert direct == P + 'report'
                role = 'df11_interrogator'
            elif symbol == P + 'frameSyndrome':
                role = roles[direct]
            else:
                assert direct == P + 'frameSyndrome'
                role = roles[parts[2]]
            records.append({'family': family, 'role': role, 'symbol': symbol,
                            'callee_context': name, 'self_ir': node.own.get('Ir', 0),
                            **incoming[0]})
        for anchor in anchors:
            observed = [r for r in records if r['family'] == family and r['symbol'] == P + anchor]
            for role in ('acceptance', 'report_syndrome', 'address_recovery'):
                assert sum(r['native_entries'] for r in observed if r['role'] == role) == expected[role]
            total = sum(r['native_entries'] for r in observed)
            assert total == sum(per_df[df]['crc_call_predictions'] for df in family_dfs[family])
            existing = analysis['families'][family]['native_anchor_counts_and_non_additive_inclusive_events'].get(P + anchor)
            if existing:
                assert total == existing['native_entries']
                assert sum(r['inclusive_ir_non_additive'] for r in observed) == existing['incoming_inclusive_events_non_additive']['Ir']
        assert sum(r['native_entries'] for r in records if r['family'] == family and
                   r['role'] == 'df11_interrogator') == expected['df11_interrogator']
    totals = {}
    for record in records:
        key = record['role'] + '/' + record['symbol'].removeprefix(P)
        totals.setdefault(key, Counter()).update({field: record[field] for field in
                                                  ('native_entries', 'self_ir', 'inclusive_ir_non_additive')})
    assert totals['report_syndrome/frameSyndrome']['native_entries'] == 172432
    assert totals['acceptance/frameSyndrome']['native_entries'] == 31395
    assert totals['address_recovery/frameSyndrome']['native_entries'] == 83591
    assert totals['df11_interrogator/Parity_interrogator']['native_entries'] == 38456
    c_path = E / 'generated-c/Impl/Message.c'
    c = c_path.read_text()
    report_c = c[c.index('LEAN_EXPORT lean_object* ' + P + 'report(lean_object* v_f_218_){'):]
    report_c = report_c[:report_c.index('LEAN_EXPORT lean_object* ' + P + 'decode(')]
    assert report_c.count(P + 'frameSyndrome(') == 1
    assert 'v___x_220_ = ' + P + 'frameSyndrome(v_f_218_);' in report_c
    assert P + 'Parity_interrogator(v___x_220_)' in report_c
    inputs.update({str(p): sha(p) for p in (parser_path, E / 'analysis/analysis.json',
                                         E / 'native/all.jsonl', c_path)})
    result = {
        'status': 'passed', 'kind': 'existing_profile_native_caller_contexts',
        'inputs': inputs, 'families': expectations, 'records': records, 'totals': totals,
        'frame_syndrome_calls': 287418, 'calls_beyond_one_per_corpus_message': 114986,
        'df11_reuses_report_syndrome': True, 'df11_additional_checksum_calls': 0,
        'generated_C_evidence': {'path': str(c_path), 'report_syndrome_line': 924,
                                 'interrogator_reuse_line': 929},
        'limits': [
            'Only retained native call contexts are separated. The other-family report context mixes DF11 and other formats; ADS-B report mixes DF17/18. No costs are prorated by message count.',
            'frameSyndrome includes checksum, field-list construction and packing. Their incoming inclusive costs overlap; do not add them.',
            '114986 is a corpus call-count difference against one syndrome per message, not a measured instruction saving or predicted speedup. Reusing the acceptance result changes which report call disappears.',
            'DF11 already has one checksum shared between syndrome reporting and interrogator interpretation in generated C; its interrogator operation has its own observed cost, with no new checksum.'],
        'no_native_execution_or_source_changes': True}
    result_path = E / 'crc-caller-contexts.json'
    write_new(result_path, (json.dumps(result, indent=2) + '\n').encode())
    old_report, old_validation = REPORT.read_bytes(), (E / 'validation.json').read_bytes()
    old_report_path, old_validation_path = E / 'report-before-crc-addendum.md', E / 'validation-before-crc-addendum.json'
    write_new(old_report_path, old_report)
    write_new(old_validation_path, old_validation)
    lines = ['## Caller-separated syndrome and checksum observations', '',
        'This supplement reads the existing three family profiles only. Each row retains an actual native caller context. `frameSyndrome` includes its checksum, field-list construction and packing; the columns overlap and must not be added. Full caller names, self costs, packing costs and reconciliation checks are retained in [crc-caller-contexts.json](../tests/evidence/diagnostics/gen5/crc-caller-contexts.json).', '',
        '| Use / family | frameSyndrome calls | frameSyndrome inclusive Ir | checksum calls | checksum inclusive Ir |',
        '|---|---:|---:|---:|---:|']
    for role, label in [('acceptance', 'DF17 acceptance'), ('report_syndrome', 'Report syndrome'),
                        ('address_recovery', 'AP address recovery')]:
        for family in family_dfs:
            cells = {a: [r for r in records if r['family'] == family and r['role'] == role and r['symbol'] == P + a]
                     for a in ('frameSyndrome', 'Parity_checksum')}
            if not cells['frameSyndrome']:
                continue
            assert all(len(rows) == 1 for rows in cells.values())
            frame, checksum = (cells[a][0] for a in ('frameSyndrome', 'Parity_checksum'))
            lines.append(f"| {label} / {family} | {frame['native_entries']:,} | {frame['inclusive_ir_non_additive']:,} | {checksum['native_entries']:,} | {checksum['inclusive_ir_non_additive']:,} |")
        a, b = totals[role + '/frameSyndrome'], totals[role + '/Parity_checksum']
        lines.append(f"| **{label} total** | **{a['native_entries']:,}** | **{a['inclusive_ir_non_additive']:,}** | **{b['native_entries']:,}** | **{b['inclusive_ir_non_additive']:,}** |")
    lines += ['',
        'There are 287,418 observed syndrome/checksum calls: 172,432 from report construction, 31,395 from DF17 acceptance, and 83,591 from AP address recovery. This is 114,986 calls beyond one per corpus message. The same corpus result must still be returned for every message; these call counts do not predict the cost of a proposed sharing implementation.', '',
        '**DF11 already shares its syndrome inside `report`.** Retained generated [Message.c](../tests/evidence/diagnostics/gen5/generated-c/Impl/Message.c) computes `v___x_220_` once at line 924 and passes that same value to `Parity.interrogator` at line 929. The native profile observes 38,456 interrogator calls, with 83,025,031 inclusive Ir and no additional syndrome/checksum call. Its syndrome cost is part of the mixed other-family report context, so no separate DF11 CRC instruction cost is assigned.', '',
        'Likewise the ADS-B report context mixes DF17 and DF18. Reusing a DF17 acceptance syndrome would remove that message’s later report computation, whose exact subpopulation instruction cost is not isolated here. The AP address-recovery context is separately observed, but compiler and allocation changes still prevent treating its current inclusive cost as a promised saving. No native decoder or profiler was rerun for this supplement.', '']
    REPORT.write_bytes(old_report + ('\n' + '\n'.join(lines)).encode())
    validation = json.loads(old_validation)
    assert validation['report_sha256'] == hashlib.sha256(old_report).hexdigest()
    assert validation['analysis_sha256'] == sha(E / 'analysis/analysis.json')
    assert validation['archive_manifest_sha256'] == sha(E / 'archive-manifest.json')
    validation['report_sha256'] = sha(REPORT)
    validation['crc_caller_addendum'] = {
        'authorized_by': 'Root requested caller-separated syndrome/checksum observations before choosing the next change and before final independent review.',
        'completed_utc': datetime.now(timezone.utc).isoformat(),
        'primary_analysis_and_archive_unchanged': True, 'no_native_execution_or_source_changes': True,
        'files': {str(p): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in
                  (Path(__file__), result_path, old_report_path, old_validation_path)}}
    (E / 'validation.json').write_text(json.dumps(validation, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'totals': totals, 'report_sha256': sha(REPORT),
                      'validation_sha256': sha(E / 'validation.json'), 'supplement_sha256': sha(result_path)}))


if __name__ == '__main__':
    main()

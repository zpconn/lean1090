#!/usr/bin/env python3
"""Small pure accounting checks; no captured profile or decoder is executed."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
import copy
import hashlib
import importlib.util
import json

E = Path(__file__).resolve().parent
ROOT = E.parents[4]


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(spec)
    sys.modules[name] = result
    spec.loader.exec_module(result)
    return result


def main():
    old = module('gen22_previous_parser', E / 'before/analyze_callgrind.py')
    new = module('gen22_current_parser', ROOT / 'review/diagnostics/analyze_callgrind.py')
    report = module('gen22_report_crc', ROOT / 'review/diagnostics/write_cost_report.py')
    old.fixture_checks()
    new.fixture_checks()
    # Every prior stage entry and inheritance rule remains exactly as before.
    symbols = ['decode', 'decodeFrame', 'frameSyndrome', 'Parity_syndrome',
               'Parity_checksum', 'frameCommB', 'frameADSB', 'frameAltitude',
               'Semantics_commB', 'reportWithSyndrome', 'payloadValue', 'frameParts']
    for name in symbols:
        for stage in new.STAGES:
            assert old.stage_for(new.PREFIX + name, stage) == new.stage_for(new.PREFIX + name, stage)
    P = new.PREFIX
    row = lambda count: {'native_entries': count}
    legacy = {P + name: row(3) for name in ('frameSyndrome', 'Parity_checksum', 'Parity_syndrome')}
    report.check_crc_boundaries(legacy, {}, 3)
    current = {P + name: row(3) for name in ('decodeFrameWithWord', 'Parity_syndrome')}
    source = {'raw_word_syndrome_live_path_verified': True,
              'decode_frame_with_word_anchor': P + 'decodeFrameWithWord'}
    report.check_crc_boundaries(current, source, 3)
    failures = []
    for missing in ('frameSyndrome', 'Parity_checksum', 'Parity_syndrome'):
        bad = copy.deepcopy(legacy)
        del bad[P + missing]
        failures.append((bad, {}, 'legacy missing ' + missing))
    for name in ('decodeFrameWithWord', 'Parity_syndrome'):
        bad = copy.deepcopy(current)
        bad[P + name] = row(2)
        failures.append((bad, source, 'wrong live count ' + name))
    for name in ('frameSyndrome', 'Parity_checksum', 'packFields'):
        bad = copy.deepcopy(current)
        bad[P + name] = row(1)
        failures.append((bad, source, 'unexpected reconstruction ' + name))
    failures.append((current, {}, 'new path without source verification'))
    failures.append((current, {**source, 'decode_frame_with_word_anchor': P + 'decodeFrame'},
                     'incorrect source parser anchor'))
    for anchors, review, label in failures:
        try:
            report.check_crc_boundaries(anchors, review, 3)
        except (AssertionError, KeyError):
            pass
        else:
            raise AssertionError(label)
    print(json.dumps({'status': 'passed', 'old_and_new_parser_fixtures': True,
        'prior_stage_comparisons': len(symbols) * len(new.STAGES),
        'crc_positive_cases': 2, 'crc_negative_cases': len(failures),
        'no_profile_or_decoder_execution': True}))


if __name__ == '__main__':
    main()

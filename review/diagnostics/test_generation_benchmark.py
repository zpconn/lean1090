#!/usr/bin/env python3
"""Pure provenance checks only: never builds, runs a decoder, or times a worker."""
import copy
import csv
import importlib.util
from pathlib import Path
import unittest

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('generation_benchmark', HERE/'run_generation_benchmark.py')
runner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(runner)


class ProvenanceChecks(unittest.TestCase):
    def test_recorded_baseline_protocol_both_modes(self):
        for mode in ('decode', 'cpr'):
            folder = runner.ROOT/'bench/runs/baseline-FC006'/mode
            meta = runner.read_json(folder/'metadata.json')
            with (folder/'samples.csv').open() as stream:
                rows = list(csv.DictReader(stream))
            result = runner.validate_mode_data(mode, meta, rows, meta['lean_binary_sha256'], meta['oracle_binary_sha256'], 0)
            self.assertEqual(result['samples'], 48)
            self.assertEqual(result['medians_nanoseconds'], meta['medians_nanoseconds'])

    def baseline(self):
        folder = runner.ROOT/'bench/runs/baseline-FC006/decode'
        meta = runner.read_json(folder/'metadata.json')
        with (folder/'samples.csv').open() as stream:
            rows = list(csv.DictReader(stream))
        return meta, rows

    def check(self, meta, rows):
        return runner.validate_mode_data('decode', meta, rows, 'lean-hash', 'oracle-hash', 0)

    def synthetic_bound_baseline(self):
        meta, rows = self.baseline()
        meta.update(lean_binary_sha256='lean-hash', oracle_binary_sha256='oracle-hash')
        return meta, rows

    def test_protocol_mutations_fail(self):
        mutations = [
            lambda m,r: r.pop(),
            lambda m,r: r[0].update(implementation='lean1090'),
            lambda m,r: r[0].update(order='2'),
            lambda m,r: r[0].update(pair='2'),
            lambda m,r: r[0].update(phase='measured'),
            lambda m,r: r[0].update(messages='1'),
            lambda m,r: r[0].update(positions='1'),
            lambda m,r: r[0].update(nanoseconds='0'),
            lambda m,r: r[0].update(messages_per_second='1'),
            lambda m,r: m.update(status='in-progress'),
            lambda m,r: m.update(mode='cpr'),
            lambda m,r: m.update(corpus_sha256='wrong'),
            lambda m,r: m.update(lean_binary_sha256='stale'),
            lambda m,r: m.update(oracle_binary_sha256='stale'),
            lambda m,r: m.update(oracle_commit='wrong'),
            lambda m,r: m.update(affinity=[1]),
            lambda m,r: m['windows_power_plan_after'].update(scheme_guid='changed'),
            lambda m,r: m['windows_power_plan_before'].update(status='documented-manual-capture'),
            lambda m,r: m['medians_nanoseconds'].update(lean1090=1),
            lambda m,r: m['messages_per_second'].update(lean1090=1),
            lambda m,r: m.update(lean_over_rust=1),
        ]
        for index, mutate in enumerate(mutations):
            with self.subTest(mutation=index):
                meta, rows = self.synthetic_bound_baseline()
                mutate(meta, rows)
                with self.assertRaises(RuntimeError):
                    self.check(meta, rows)

    def test_utc_backstep_preserved(self):
        meta, rows = self.synthetic_bound_baseline()
        rows[1]['recorded_at'] = '2020-01-01T00:00:00+00:00'
        old = copy.deepcopy(rows)
        result = self.check(meta, rows)
        self.assertTrue(any(item['order'] == 2 for item in result['utc_sample_backsteps']))
        self.assertEqual(rows, old)

    def gate(self):
        current = {'Impl/Message.lean':'code-hash', 'spec.lock':'lock-hash'}
        evidence = {'schema':1, 'command':['scripts/check_all.sh','--full'], 'exit_code':0,
            'status':'passed', 'generated_messages':10000000, 'gate_log_sha256':'log-hash',
            'input_hashes_before':dict(current), 'input_hashes_after':dict(current),
            'started_at':'2026-10-18T17:00:00+00:00', 'finished_at':'2026-10-18T18:00:00+00:00'}
        return evidence, current

    def test_full_gate_evidence(self):
        evidence, current = self.gate()
        self.assertEqual(runner.verify_gate_evidence(evidence,'log-hash',current)['status'],'verified')
        for field,value in [('schema',0),('command',['scripts/check_all.sh','--quick']),('exit_code',1),
                            ('status','failed'),('generated_messages',100000),('gate_log_sha256','wrong'),
                            ('input_hashes_before',{}),('input_hashes_after',{})]:
            with self.subTest(field=field):
                changed = copy.deepcopy(evidence);changed[field]=value
                with self.assertRaises(RuntimeError):
                    runner.verify_gate_evidence(changed,'log-hash',current)
        evidence['finished_at'] = '2026-10-18T16:00:00+00:00'
        self.assertTrue(runner.verify_gate_evidence(evidence,'log-hash',current)['gate_utc_backstep'])


if __name__ == '__main__':
    unittest.main()

#!/usr/bin/env python3
"""Reporting-only target checks; never build or execute a decoder or benchmark."""
import sys
sys.dont_write_bytecode = True
import copy
import importlib.util
import unittest
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import archive_generation_benchmark_target as report


def results(decode, cpr, lean=100):
    return [{'mode': mode, 'medians_nanoseconds': {'rs1090': rust, 'lean1090': lean}}
            for mode, rust in [('decode', decode), ('cpr', cpr)]]


class Targets(unittest.TestCase):
    def setUp(self):
        self.plan = {mode + '_target_ratio': {'numerator': 2, 'denominator': 1}
                     for mode in ('decode', 'cpr')}

    def test_both_modes_must_reach_target(self):
        for decode, cpr, expected in [(200, 200, True), (201, 250, True),
                                      (200, 199, False), (199, 200, False),
                                      (199, 199, False), (10000, 1, False)]:
            with self.subTest(decode=decode, cpr=cpr):
                fields, joint = report.reporting_targets(self.plan, results(decode, cpr))
                self.assertEqual(joint, expected)
                self.assertEqual(fields['all_mode_thresholds_reached'], expected)
                self.assertEqual(fields['decode_threshold_reached'], decode >= 200)
                self.assertEqual(fields['cpr_threshold_reached'], cpr >= 200)

    def test_exact_integer_boundary_above_binary64_precision(self):
        lean = 2**100 + 7
        for difference, expected in [(-1, False), (0, True), (1, True)]:
            _, reached = report.reporting_targets(self.plan,
                                                  results(lean*2, lean*2+difference, lean))
            self.assertEqual(reached, expected)

    def test_independent_rational_targets_and_result_order(self):
        self.plan['cpr_target_ratio'] = {'numerator': 7, 'denominator': 3}
        rows = results(600, 700, 300)
        self.assertTrue(report.reporting_targets(self.plan, rows[::-1])[1])
        rows[1]['medians_nanoseconds']['rs1090'] -= 1
        self.assertFalse(report.reporting_targets(self.plan, rows)[1])
        self.assertEqual(report.target_label(self.plan, 'cpr'), '7/3')

    def test_reject_malformed_targets(self):
        invalid = [None, {}, [], {'numerator': 2},
                   {'numerator': 2, 'denominator': 1, 'extra': 0}]
        for field in ('numerator', 'denominator'):
            for value in (True, False, 0, -1, 2.0, '2', None):
                invalid.append({'numerator': 2, 'denominator': 1} | {field: value})
        for mode in ('decode', 'cpr'):
            for ratio in invalid:
                with self.subTest(mode=mode, ratio=ratio):
                    plan = copy.deepcopy(self.plan)
                    plan[mode+'_target_ratio'] = ratio
                    with self.assertRaises(RuntimeError):
                        report.reporting_targets(plan, results(200, 200))

    def test_reject_missing_duplicate_or_unknown_result_modes(self):
        for rows in [results(200, 200)[:1], results(200, 200)*2,
                     [results(200, 200)[0]]*2,
                     [results(200, 200)[0], {'mode': 'other'}]]:
            with self.assertRaises(RuntimeError):
                report.reporting_targets(self.plan, rows)
        for mode in ('decode', 'cpr'):
            for value in (0, -1, True, 1.0):
                rows = results(200, 200)
                next(r for r in rows if r['mode'] == mode)['medians_nanoseconds']['lean1090'] = value
                with self.assertRaises(RuntimeError):
                    report.reporting_targets(self.plan, rows)

    def test_legacy_decode_only_decision_and_fields(self):
        for plan, ratio, rust in [({}, (11, 10), 110),
                                  ({'decode_target_ratio': {'numerator': 3, 'denominator': 2}},
                                   (3, 2), 150)]:
            fields, reached = report.reporting_targets(plan, results(rust, 1))
            self.assertEqual(report.target_ratio(plan), ratio)
            self.assertTrue(reached)
            self.assertEqual(set(fields), {'decode_target_ratio', 'decode_threshold_reached'})
            # Preserve the original standalone helper's mode-less result API.
            self.assertTrue(report.decode_threshold_reached(plan, results(rust, 1)[0] |
                                                           {'mode': 'decode'}))
            self.assertTrue(report.decode_threshold_reached(plan, {'medians_nanoseconds':
                {'rs1090': rust, 'lean1090': 100}}))

    def test_generation15_report_stays_byte_identical(self):
        root = report.ROOT
        plan = report.load(root/'tests/evidence/optimization/gen15/benchmark-preparation/plan.json')
        source = root/'.cache/bench-runs/gen15-e659220'
        data = report.validate_source(source, 15)
        prior = report.parse_prior_csv((root/plan['prior_csv_snapshot']).read_bytes(), 15)
        fresh = report.load(root/plan['fresh_verification'])
        old_spec = importlib.util.spec_from_file_location('original_target_report',
            root/'tests/evidence/optimization/dual-target-reporting/before.py')
        old = importlib.util.module_from_spec(old_spec)
        old_spec.loader.exec_module(old)
        expected = (root/'bench/GEN15.md').read_text()
        self.assertEqual(old.report_text(plan, data, source, prior, fresh), expected)
        self.assertEqual(report.report_text(plan, data, source, prior, fresh), expected)
        dual = plan | self.plan
        rendered = report.report_text(dual, data, source, prior, fresh)
        self.assertIn('2.00× decode: unmet; 2.00× cpr: unmet', rendered)
        self.assertNotIn('Stop for user review', rendered)


if __name__ == '__main__':
    unittest.main(verbosity=2)

#!/usr/bin/env python3
"""Read direct conversion/normalization edges from the existing CPR profile only."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from collections import defaultdict
import argparse
import hashlib
import json
sys.path.insert(0, str(Path.cwd() / 'review/diagnostics'))
import analyze_callgrind as parser


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--profile', type=Path, required=True)
    ap.add_argument('--analysis', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    assert not args.output.exists()
    analysis = json.loads(args.analysis.read_text())
    profile = parser.parse(args.profile)
    assert sha(args.profile) == analysis['raw_sha256']
    stages = {row['symbol']: row['bucket'] for row in analysis['self_cost_contexts']}
    wanted = {'lean_nat_pow', 'lean_nat_gcd', 'l_Rat_mul', 'l_Rat_div', 'l_Rat_inv',
              'lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat',
              'lp_lean1090_Lean1090_Impl_Binary64_round',
              'lp_lean1090_Lean1090_Impl_Binary64_exponent',
              'lp_lean1090_Lean1090_Impl_Binary64_powerTwo'}
    rows = []
    groups = defaultdict(lambda: {'calls': 0, 'inclusive_Ir_non_additive': 0})
    for caller, node in profile.nodes.items():
        for callee, costs in node.edges.items():
            target = parser.base_name(callee)
            if target not in wanted or not costs['Ir']:
                continue
            assert callee in stages, callee
            row = {'stage': stages[callee], 'caller': caller, 'callee': callee,
                   'calls': node.calls[callee], 'inclusive_Ir_non_additive': costs['Ir']}
            rows.append(row)
            key = (row['stage'], target, parser.base_name(caller))
            groups[key]['calls'] += row['calls']
            groups[key]['inclusive_Ir_non_additive'] += row['inclusive_Ir_non_additive']
    for target in wanted:
        for stage in {r['stage'] for r in rows if parser.base_name(r['callee']) == target}:
            found = [r for r in rows if r['stage'] == stage and parser.base_name(r['callee']) == target]
            expected = [r for r in analysis['helper_observations_non_additive']
                        if r['symbol'] == target and r['stage'] == stage]
            assert len(expected) == 1
            assert sum(r['calls'] for r in found) == expected[0]['native_entries']
            assert sum(r['inclusive_Ir_non_additive'] for r in found) == expected[0]['inclusive_Ir_non_additive']
    grouped = [dict(stage=k[0], target=k[1], direct_caller=k[2], **v)
               for k, v in groups.items()]
    grouped.sort(key=lambda r: r['inclusive_Ir_non_additive'], reverse=True)
    result = {'status': 'passed', 'profile': str(args.profile), 'profile_sha256': sha(args.profile),
              'analysis': str(args.analysis), 'analysis_sha256': sha(args.analysis),
              'script_sha256': sha(Path(__file__)), 'grouped_direct_edges': grouped,
              'full_context_edges': rows,
              'interpretation': 'Each row is an actual direct call edge with the callee-inclusive instruction cost. Conversion, rounding, exponent, power, rational and GCD costs nest and overlap; do not sum them or add them to stage totals. No exponent-frequency or future-table-hit claim is inferred from these call counts.'}
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(grouped, indent=2))


if __name__ == '__main__':
    main()

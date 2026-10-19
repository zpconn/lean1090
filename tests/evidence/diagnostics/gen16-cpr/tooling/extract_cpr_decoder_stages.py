#!/usr/bin/env python3
"""Reapply the existing decoder partition within the complete CPR profile."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from collections import Counter, defaultdict, deque
import argparse
import hashlib
import json
import analyze_callgrind as parser


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--profile', type=Path, required=True)
    ap.add_argument('--analysis', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    assert not args.output.exists()
    profile = parser.parse(args.profile)
    analysis = json.loads(args.analysis.read_text())
    labels = defaultdict(set)
    queue = deque((n, 'output_model_control') for n in profile.nodes
                  if parser.base_name(n) == parser.DECODE)
    while queue:
        name, inherited = queue.popleft()
        stage = parser.stage_for(name, inherited)
        if stage in labels[name]:
            continue
        labels[name].add(stage)
        for callee, costs in profile.nodes[name].edges.items():
            if any(costs.values()):
                queue.append((callee, stage))
    buckets = Counter()
    contexts = []
    for name, node in profile.nodes.items():
        if labels[name] and node.own['Ir']:
            assert len(labels[name]) == 1, name
            stage = next(iter(labels[name]))
            buckets[stage] += node.own['Ir']
            contexts.append({'symbol': name, 'stage': stage, 'self_Ir': node.own['Ir']})
    expected = {r['symbol']: r['self_Ir'] for r in analysis['self_cost_contexts']
                if r['bucket'] == 'decoder'}
    assert {r['symbol']: r['self_Ir'] for r in contexts} == expected
    assert sum(buckets.values()) == analysis['exclusive_stages']['decoder']
    sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
    result = {'status': 'passed', 'profile_sha256': sha(args.profile),
              'analysis_sha256': sha(args.analysis), 'script_sha256': sha(Path(__file__)),
              'parser_sha256': sha(Path(parser.__file__)), 'exclusive_decoder_stages': dict(buckets),
              'total_decoder_Ir': sum(buckets.values()), 'self_contexts': contexts,
              'interpretation': 'These five self-cost buckets replace the decoder row; never add them to it.'}
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'exclusive_decoder_stages': dict(buckets)}))


if __name__ == '__main__':
    main()

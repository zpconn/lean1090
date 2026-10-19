#!/usr/bin/env python3
"""Recount actual payloadValue edges in retained gen7/gen8 profiles; no native run."""
from collections import Counter, defaultdict, deque
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

E = Path('tests/evidence/diagnostics/gen8')
P = 'lp_lean1090_Lean1090_Impl_'
TARGET = P + 'payloadValue'
CALLEES = ('l_Rat_mul', 'l_Rat_add', 'l_Rat_ofInt', 'l_instDecidableEqRat_decEq')


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    parser_path = Path('review/diagnostics/analyze_callgrind.py')
    spec = importlib.util.spec_from_file_location('affine_callgrind_reader', parser_path)
    cg = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = cg
    spec.loader.exec_module(cg)
    source = json.loads((E / 'source-review.json').read_text())
    assert source['affine_payload_value_verified']
    inputs = {str(parser_path): sha(parser_path), str(E / 'source-review.json'): sha(E / 'source-review.json')}
    records, outgoing, aggregate = [], [], []
    for generation in (7, 8):
        directory = Path(f'tests/evidence/diagnostics/gen{generation}')
        apath = directory / 'analysis/analysis.json'
        analysis = json.loads(apath.read_text())
        inputs[str(apath)] = sha(apath)
        for family in ('adsb', 'commb', 'other'):
            path = directory / f'callgrind/{family}/callgrind.out.1.gz'
            inputs[str(path)] = sha(path)
            profile = cg.parse(path)
            labels = defaultdict(set)
            queue = deque((name, 'output_model_control') for name in profile.nodes if cg.base_name(name) == P + 'decode')
            while queue:
                name, inherited = queue.popleft()
                stage = cg.stage_for(name, inherited)
                if stage in labels[name]:
                    continue
                labels[name].add(stage)
                queue.extend((callee, stage) for callee, edge in profile.nodes[name].edges.items() if any(edge.values()))
            grouped = defaultdict(Counter)
            for name, node in profile.nodes.items():
                if cg.base_name(name) != TARGET:
                    continue
                incoming = [
                    {'caller_context': caller.name, 'native_entries': caller.calls[name],
                     'inclusive_ir_non_additive': edge.get('Ir', 0)}
                    for caller in profile.nodes.values()
                    if (edge := caller.edges.get(name)) and any(edge.values())]
                if not incoming:
                    assert not any(node.own.values())
                    continue
                assert len(labels[name]) == 1, (generation, family, name, labels[name])
                stage = next(iter(labels[name]))
                row = {'generation': generation, 'family': family, 'stage': stage, 'context': name,
                       'self_ir': node.own.get('Ir', 0), 'incoming': incoming,
                       'native_entries': sum(x['native_entries'] for x in incoming),
                       'incoming_inclusive_ir_non_additive': sum(x['inclusive_ir_non_additive'] for x in incoming)}
                records.append(row)
                grouped[stage].update({key: row[key] for key in ('self_ir', 'native_entries', 'incoming_inclusive_ir_non_additive')})
                grouped[stage]['contexts'] += 1
                for target, edge in node.edges.items():
                    if cg.base_name(target) not in CALLEES or not any(edge.values()):
                        continue
                    assert labels[target] == {stage}, (name, target, labels[target])
                    outgoing.append({'generation': generation, 'family': family, 'stage': stage,
                                     'caller_context': name, 'callee_context': target,
                                     'callee': cg.base_name(target), 'native_entries': node.calls[target],
                                     'inclusive_ir_non_additive': edge.get('Ir', 0)})
            expected = analysis['families'][family]['stage_helper_observations_non_additive']
            for stage, totals in grouped.items():
                existing = next(r for r in expected[stage] if r['symbol'] == TARGET)
                assert totals['contexts'] == existing['contexts']
                assert totals['native_entries'] == existing['native_entries']
                assert totals['self_ir'] == existing['self_events'].get('Ir', 0)
                assert totals['incoming_inclusive_ir_non_additive'] == existing['incoming_inclusive_events_non_additive'].get('Ir', 0)
                edges = {}
                for callee in CALLEES:
                    rows = [r for r in outgoing if r['generation'] == generation and r['family'] == family and r['stage'] == stage and r['callee'] == callee]
                    edges[callee] = {key: sum(r[key] for r in rows) for key in ('native_entries', 'inclusive_ir_non_additive')}
                # Actual reviewed payloadValue has at most one direct multiplication
                # and addition on each present branch; no inferred field population.
                assert edges['l_Rat_mul']['native_entries'] <= totals['native_entries']
                assert edges['l_Rat_add']['native_entries'] <= totals['native_entries']
                aggregate.append({'generation': generation, 'family': family, 'stage': stage,
                                  **totals, 'outgoing_edges': edges})
    for family in ('adsb', 'commb', 'other'):
        for stage in {r['stage'] for r in aggregate}:
            old = sum(r['native_entries'] for r in aggregate if r['generation'] == 7 and r['family'] == family and r['stage'] == stage)
            new = sum(r['native_entries'] for r in aggregate if r['generation'] == 8 and r['family'] == family and r['stage'] == stage)
            assert old == new, (family, stage, old, new)
    result = {'status': 'passed', 'kind': 'existing_profile_payload_value_caller_and_direct_edges',
              'inputs': inputs, 'records': records, 'outgoing_records': outgoing, 'aggregate': aggregate,
              'limits': [
                  'These are actual retained native boundaries and direct outgoing edges. Inlined affineValue has no standalone collected boundary; that is not zero affine work.',
                  'Incoming payloadValue and outgoing Rat costs overlap with each other and the stage totals. Only unique-stage self events form a partition.',
                  'Direct mul/add entry counts do not identify every scale/offset field population, because absent status returns also skip work. No branch population is inferred.',
                  'Each generation uses its own retained native caller contexts and allocator/constant state. No instruction difference predicts throughput.'],
              'no_native_execution_or_source_changes': True}
    path = E / 'affine-caller-contexts.json'
    assert not path.exists()
    path.write_text(json.dumps(result, indent=2) + '\n')
    lines = ['### Live affine-value observations', '',
             'The same native `payloadValue` entry populations are observed in both generations. The direct `Rat.mul` and `Rat.add` edges below are actual collected calls; the inlined affine helper has no separate native boundary. Full caller contexts, self costs and edge records are retained in [affine-caller-contexts.json](../tests/evidence/diagnostics/gen8/affine-caller-contexts.json). Incoming and outgoing inclusive costs overlap and must not be added to one another or to stage totals.', '',
             '| Generation / family / stage | payloadValue calls | payloadValue inclusive Ir | Direct mul calls | Direct mul inclusive Ir | Direct add calls | Direct add inclusive Ir |',
             '|---|---:|---:|---:|---:|---:|---:|']
    for r in aggregate:
        mul, add = (r['outgoing_edges'][name] for name in ('l_Rat_mul', 'l_Rat_add'))
        lines.append(f"| Gen{r['generation']} / {r['family']} / {r['stage']} | {r['native_entries']:,} | {r['incoming_inclusive_ir_non_additive']:,} | {mul['native_entries']:,} | {mul['inclusive_ir_non_additive']:,} | {add['native_entries']:,} | {add['inclusive_ir_non_additive']:,} |")
    lines += ['', 'These counts do not separate every scale/offset assignment: missing-status fields also avoid arithmetic. The actual generated C and linked assembly independently establish the guarded identity branches. This is an instruction diagnostic, not a throughput prediction.', '']
    md = E / 'affine-caller-contexts.md'
    assert not md.exists()
    md.write_text('\n'.join(lines))
    print(json.dumps({'status': 'passed', 'records': len(records), 'outgoing_records': len(outgoing), 'aggregate': aggregate}))


if __name__ == '__main__':
    main()

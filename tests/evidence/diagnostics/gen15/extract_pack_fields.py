#!/usr/bin/env python3
"""Read-only direct-child detail for the already reviewed decoder profiles."""
import sys
sys.dont_write_bytecode = True
from collections import Counter
import hashlib
import importlib.util
import json
from pathlib import Path

E = Path('tests/evidence/diagnostics/gen15')
SYMBOL = 'lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0'

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

p = Path('review/diagnostics/analyze_callgrind.py')
spec = importlib.util.spec_from_file_location('gen15_pack_detail', p)
m = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = m
spec.loader.exec_module(m)
rows, combined, total = [], {}, Counter()
for family in ('adsb', 'commb', 'other'):
    path = E / 'callgrind' / family / 'callgrind.out.1.gz'
    profile = m.parse(path)
    contexts, children, counts = [], {}, Counter()
    for name, node in profile.nodes.items():
        if m.base_name(name) != SYMBOL:
            continue
        own = node.own.get('Ir', 0)
        incoming_calls = sum(n.calls.get(name, 0) for n in profile.nodes.values())
        incoming_ir = sum(n.edges.get(name, {}).get('Ir', 0) for n in profile.nodes.values())
        direct = []
        for child, events in node.edges.items():
            symbol = m.base_name(child)
            call_count, ir = node.calls.get(child, 0), events.get('Ir', 0)
            direct.append({'context': child, 'symbol': symbol, 'calls': call_count, 'inclusive_ir': ir})
            children.setdefault(symbol, Counter()).update(calls=call_count, inclusive_ir=ir)
            combined.setdefault(symbol, Counter()).update(calls=call_count, inclusive_ir=ir)
        assert own + sum(row['inclusive_ir'] for row in direct) == incoming_ir
        contexts.append({'context': name, 'entry_calls': incoming_calls, 'self_ir': own,
                         'incoming_inclusive_ir': incoming_ir, 'direct_children': direct})
        counts.update(entry_calls=incoming_calls, self_ir=own, incoming_inclusive_ir=incoming_ir)
    total.update(counts)
    rows.append({'family': family, **counts, 'direct_children': children, 'contexts': contexts,
                 'profile_sha256': sha(path)})
c = E / 'generated-c/Impl/Bits.c'
lines = c.read_text().splitlines()
start = next(i for i,line in enumerate(lines) if line.startswith('LEAN_EXPORT lean_object* '+SYMBOL+'(') and line.endswith('{'))
end = next(i for i in range(start+1,len(lines)) if lines[i].startswith('LEAN_EXPORT '))
output = {'status': 'passed', 'kind': 'existing_raw_profile_direct_pack_fields_child_detail',
          'rows': rows, 'total': dict(total), 'direct_children_total': combined,
          'main_report_sha256': sha(Path('docs/GEN15-COST-BREAKDOWN.md')),
          'validation_sha256': sha(E/'validation.json'), 'archive_manifest_sha256': sha(E/'archive-manifest.json'),
          'generated_c': {'path': str(c), 'sha256': sha(c), 'start_line': start+1, 'end_line':end,
                          'source': '\n'.join(lines[start:end])+'\n'},
          'limits': ['Only three disjoint full-decoder family profiles are aggregated; no additional native workload ran.',
                     'Direct inclusive child totals partition this nonrecursive native fold call with its own self cost, but overlap whole-stage and other nested totals.',
                     'Native helper absence does not imply zero operations: generated C has lean_nat_mul and lean_nat_mod, whose small-value operations can inline into fold self cost.',
                     'Observed big/overflow helper calls count only crossings of those native boundaries, not all semantic multiplications or remainders.',
                     'No benchmark prediction or next optimization selection is made.'],
          'extractor_sha256': sha(Path(__file__)), 'parser_sha256': sha(p)}
target=E/'pack-fields-direct-costs.json';assert not target.exists()
target.write_text(json.dumps(output,indent=2)+'\n')
print(json.dumps({'status':'passed','total':dict(total),'direct_children':combined,'sha256':sha(target)}))

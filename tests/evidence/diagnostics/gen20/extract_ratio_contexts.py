#!/usr/bin/env python3
"""Read existing gen19/gen20 Callgrind data; no decoder runs or timing estimates."""
import sys
sys.dont_write_bytecode = True
from collections import Counter
import hashlib
import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
E = ROOT / 'tests/evidence/diagnostics/gen20'
P = 'lp_lean1090_Lean1090_Impl_'

def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def read(path):
    return json.loads(Path(path).read_text())

def main():
    target = E / 'ratio-native-contexts.json'
    assert not target.exists()
    source = read(E / 'independent-review/source-review.json')
    assert source['bds60_ratio_enclosure_live_path_verified']
    assert source['ratio_enclosure_anchor'] == P + 'cbRatioOutside250800'
    parser = ROOT / 'review/diagnostics/analyze_callgrind.py'
    spec = importlib.util.spec_from_file_location('gen20_ratio_profile_parser', parser)
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    analysis = read(E / 'analysis/analysis.json')
    previous_analysis = read(ROOT / 'tests/evidence/diagnostics/gen19/analysis/analysis.json')
    mode_names = ['adsb', 'commb', 'other'] + [kind + r for kind in ('candidate', 'score') for r in ('40','44','45','50','60')]
    summaries = []
    direct_rows = []
    for generation, analyses in [(19, previous_analysis), (20, analysis)]:
        root = ROOT / f'tests/evidence/diagnostics/gen{generation}'
        for mode in mode_names:
            path = root / 'callgrind' / mode / 'callgrind.out.1.gz'
            profile = module.parse(path)
            info = analyses['families'][mode] if mode in ('adsb','commb','other') else analyses['non_additive_register_' + ('candidate' if mode.startswith('candidate') else 'score') + '_probes'][mode.removeprefix('candidate').removeprefix('score')]
            roots = {'ratio': P + 'cbRatioOutside250800', 'penalty': P + 'cbPenalty'}
            stats = {}
            for label, symbol in roots.items():
                nodes = {name for name in profile.nodes if module.base_name(name) == symbol}
                entries = sum(node.calls.get(name,0) for node in profile.nodes.values() for name in nodes)
                own = sum(profile.nodes[name].own.get('Ir',0) for name in nodes)
                inclusive = sum(node.edges.get(name,{}).get('Ir',0) for node in profile.nodes.values() for name in nodes)
                stats[label] = {'native_entries': entries, 'self_ir': own, 'incoming_inclusive_ir_non_additive': inclusive}
                anchor = info['native_anchor_counts_and_non_additive_inclusive_events'].get(symbol,{})
                if generation in (19,20) or label=='penalty':
                    assert entries==anchor.get('native_entries',0)
                    assert own==anchor.get('self_events',{}).get('Ir',0)
                    assert inclusive==anchor.get('incoming_inclusive_events_non_additive',{}).get('Ir',0)
                edges = []
                for name in sorted(nodes):
                    node=profile.nodes[name]
                    for callee, cost in sorted(node.edges.items()):
                        if not any(cost.values()):continue
                        base=module.base_name(callee)
                        if base not in (P+'Binary64_round',P+'Binary64_div',P+'cbRatioOutside250800','l_Rat_div','l_Rat_blt'):continue
                        edges.append({'caller':name,'callee':callee,'callee_symbol':base,'native_entries':node.calls[callee], 'incoming_inclusive_ir_non_additive':cost.get('Ir',0)})
                direct_rows.append({'generation':generation,'profile':mode,'root_label':label,'root_symbol':symbol,'stats':stats[label],'edges':edges,'profile_sha256':sha(path)})
            ratio_record=direct_rows[-2]
            fallback=sum(row['native_entries'] for row in ratio_record['edges'] if row['callee_symbol']==P+'Binary64_round')
            fallback_ir=sum(row['incoming_inclusive_ir_non_additive'] for row in ratio_record['edges'] if row['callee_symbol']==P+'Binary64_round')
            assert fallback<=stats['ratio']['native_entries']<=stats['penalty']['native_entries']
            if mode not in ('commb','candidate60','score60'):assert stats['ratio']['native_entries']==0 and fallback==0
            summaries.append({'generation':generation,'profile':mode,**stats,'ratio_round_fallback_entries':fallback,'ratio_round_fallback_inclusive_ir_non_additive':fallback_ir,'ratio_shortcut_entries':stats['ratio']['native_entries']-fallback})
    result={'kind':'actual_ratio_and_penalty_native_context_observations','source_review_sha256':sha(E/'independent-review/source-review.json'),'parser_sha256':sha(parser),'analysis_sha256':sha(E/'analysis/analysis.json'),'previous_analysis_sha256':sha(ROOT/'tests/evidence/diagnostics/gen19/analysis/analysis.json'),'rows':summaries,'direct_contexts':direct_rows,'limits':['Each native entry count is from retained incoming call records; only positive-cost direct edges are attributed to observed fallback work.','The source/native review proves one conditional software-round site per ratio helper invocation. Subtraction of those observed calls from helper entries counts shortcut invocations, not input distributions outside the corpus.','Both generations form exact Rat division in cbPenalty before the unchanged integer enclosure and optional software rounding. Their inclusive costs overlap callers and are not additive stage partitions.','Families and standalone candidate/score probes are distinct overlapping contexts and cannot be added as workload totals.','No elapsed-time estimate or explanation of the measured throughput is inferred from these instruction counts.']}
    target.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'status':'passed','rows':len(summaries),'direct_context_groups':len(direct_rows),'sha256':sha(target)}))

if __name__=='__main__':main()

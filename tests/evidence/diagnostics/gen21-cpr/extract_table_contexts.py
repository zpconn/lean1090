#!/usr/bin/env python3
"""Count actual table-lookup/formula edges in the completed CPR profile."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from collections import defaultdict
import argparse,hashlib,json
sys.path.insert(0,str(Path.cwd()/'review/diagnostics'))
import analyze_callgrind as parser

def sha(p):
 with p.open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--profile',type=Path,required=True);p.add_argument('--analysis',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
 assert not a.output.exists()
 source=Path('tests/evidence/diagnostics/gen21/independent-review/source-review.json');s=json.loads(source.read_text())
 assert s['status']=='passed_read_only_source_and_native_review' and s['power_two_table_live_path_verified']
 lookup,formula,entry=[s[k] for k in ['power_two_lookup_anchor','power_two_formula_anchor','power_two_table_entry_anchor']]
 analysis=json.loads(a.analysis.read_text());profile=parser.parse(a.profile)
 assert sha(a.profile)==analysis['raw_sha256']
 stages={r['symbol']:r['bucket'] for r in analysis['self_cost_contexts']}
 helpers={(r['stage'],r['symbol']):r for r in analysis['helper_observations_non_additive']}
 edges=[];groups=defaultdict(lambda:{'calls':0,'inclusive_Ir_non_additive':0})
 for caller,node in profile.nodes.items():
  for callee,costs in node.edges.items():
   target=parser.base_name(callee)
   if target not in {lookup,formula,entry} or not costs['Ir']:continue
   assert callee in stages,callee
   stage=stages[callee];row={'stage':stage,'caller':caller,'callee':callee,'calls':node.calls[callee],'inclusive_Ir_non_additive':costs['Ir']};edges.append(row)
   g=groups[(stage,target,parser.base_name(caller))];g['calls']+=row['calls'];g['inclusive_Ir_non_additive']+=row['inclusive_Ir_non_additive']
 for stage,target in {(r['stage'],parser.base_name(r['callee'])) for r in edges}:
  rows=[r for r in edges if r['stage']==stage and parser.base_name(r['callee'])==target];h=helpers[(stage,target)]
  assert sum(r['calls'] for r in rows)==h['native_entries']
  assert sum(r['inclusive_Ir_non_additive'] for r in rows)==h['inclusive_Ir_non_additive']
 counts=[]
 for stage in analysis['exclusive_stages']:
  incoming=[r for r in edges if r['stage']==stage and parser.base_name(r['callee'])==lookup]
  fallback=[r for r in edges if r['stage']==stage and parser.base_name(r['caller'])==lookup and parser.base_name(r['callee'])==formula]
  n=sum(r['calls'] for r in incoming);f=sum(r['calls'] for r in fallback)
  assert 0<=f<=n
  if n or f:counts.append({'stage':stage,'lookup_entries':n,'direct_formula_fallback_calls':f,'table_lookup_calls_from_verified_branch_partition':n-f})
 constructor=sum(r['calls'] for r in edges if parser.base_name(r['callee'])==entry)
 # The linked initializer is independently inspected; no constructor belongs to this collected loop.
 assert constructor==0
 grouped=[dict(stage=k[0],target=k[1],direct_caller=k[2],**v) for k,v in sorted(groups.items())]
 result={'status':'passed','profile':str(a.profile),'profile_sha256':sha(a.profile),'analysis':str(a.analysis),'analysis_sha256':sha(a.analysis),'script_sha256':sha(Path(__file__)),'source_review':str(source),'source_review_sha256':sha(source),'anchors':{'lookup':lookup,'formula':formula,'table_entry':entry},'by_stage':counts,'total':{key:sum(r[key] for r in counts) for key in ['lookup_entries','direct_formula_fallback_calls','table_lookup_calls_from_verified_branch_partition']},'table_constructor_entries_inside_root':constructor,'grouped_direct_edges':grouped,'full_context_edges':edges,'interpretation':['Actual native incoming and direct fallback edges only; inclusive costs overlap and never determine table coverage.','Independent native review proves two mutually exclusive C fallback sites and at most one formula call per lookup; lookup minus observed formula calls is the remaining table branch population.','The eagerly initialized 2,098-entry table is outside collection. Zero observed constructor entries here does not imply zero startup work.','Counts apply only to this corpus and diagnostic loop, not arbitrary exponents or all programs.']}
 a.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':'passed','total':result['total'],'by_stage':counts,'constructor_entries':constructor}))
if __name__=='__main__':main()

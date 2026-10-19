#!/usr/bin/env python3
"""Exclusive CPR loop self-cost partition; inclusive helpers remain non-additive."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from collections import Counter,defaultdict,deque
import argparse,gzip,hashlib,json
import analyze_callgrind as parser
ROOT_SYMBOL='l_Lean1090_Diagnostics_CPRCosts_runCPR'
PREFIX='lp_lean1090_Lean1090_Impl_'
POLICY=PREFIX+'CPR_Policy_'
NUMERIC={'toFloat','haversineFloat','distanceFromFloat','positionFromFloats','nlFloat','moduloFloat','decodeLocalFloat','decodeGlobalFloat','numericalGeography'}
DESCRIPTIONS={'decoder':'Actual Impl.decode and all descendants, including its complete model projection','numeric_geography':'Live Float geographic kernels and their exact-rational conversion boundary','motion_policy':'validMotion and its policy arithmetic, excluding geographic kernels','airborne_pairing_policy':'stepAirborne pairing/time/parity/update logic, excluding motion and geographic kernels','surface_reference_policy':'stepSurface reference/airport/update logic, excluding geographic kernels','state_tracking_control':'streamStep lookup/filter and remaining tracking policy control','tracking_projection':'Frozen trackingReport/advance projection before the live policy','loop_output_control':'Diagnostic loop, array append, output wrappers, retained return and residual runtime control'}
def transition(symbol,inherited):
 symbol=parser.base_name(symbol)
 if symbol==PREFIX+'decode' or inherited=='decoder':return 'decoder'
 if inherited=='numeric_geography':return inherited
 if symbol.startswith(POLICY) and any(symbol==POLICY+n or symbol.startswith(POLICY+n+'___') for n in NUMERIC):return 'numeric_geography'
 if symbol==POLICY+'validMotion':return 'motion_policy'
 if inherited=='motion_policy':return inherited
 if symbol==POLICY+'stepAirborne':return 'airborne_pairing_policy'
 if symbol==POLICY+'stepSurface':return 'surface_reference_policy'
 if inherited in {'airborne_pairing_policy','surface_reference_policy'}:return inherited
 if symbol==POLICY+'streamStep':return 'state_tracking_control'
 if 'CPRCosts_trackingReport' in symbol or 'CPRCosts_advance' in symbol:return 'tracking_projection'
 return inherited

def analyze(profile):
 roots=[n for n in profile.nodes if parser.base_name(n)==ROOT_SYMBOL]
 if not roots:raise ValueError('collected CPR root absent')
 labels=defaultdict(set);queue=deque((n,'loop_output_control') for n in roots)
 while queue:
  name,inherited=queue.popleft();stage=transition(name,inherited)
  if stage in labels[name]:continue
  labels[name].add(stage)
  for callee,counts in profile.nodes[name].edges.items():
   if any(counts.values()):queue.append((callee,stage))
 buckets=Counter();functions=[];groups={};incoming=Counter();inclusive=Counter()
 for node in profile.nodes.values():
  for callee,counts in node.edges.items():incoming[callee]+=node.calls[callee];inclusive[callee]+=counts['Ir']
 for name,node in profile.nodes.items():
  tags=sorted(labels[name]);bucket=tags[0] if len(tags)==1 else 'shared_ambiguous' if tags else 'outside_root';cost=node.own['Ir'];buckets[bucket]+=cost
  if cost:functions.append({'symbol':name,'stages':tags,'bucket':bucket,'self_Ir':cost})
  if tags:
   key=(bucket,parser.base_name(name));entry=groups.setdefault(key,{'stage':bucket,'symbol':key[1],'contexts':0,'native_entries':0,'self_Ir':0,'inclusive_Ir_non_additive':0})
   entry['contexts']+=1;entry['native_entries']+=incoming[name];entry['self_Ir']+=cost;entry['inclusive_Ir_non_additive']+=inclusive[name]
 assert sum(buckets.values())==profile.summary['Ir']
 if buckets['outside_root']:raise ValueError('nonzero events outside collected root')
 anchors={}
 for entry in groups.values():
  sym=entry['symbol']
  if sym.startswith(POLICY) or sym in {ROOT_SYMBOL,PREFIX+'decode'}:
   item=anchors.setdefault(sym,{'native_entries':0,'self_Ir':0,'inclusive_Ir_non_additive':0,'stages':set()})
   for k in ['native_entries','self_Ir','inclusive_Ir_non_additive']:item[k]+=entry[k]
   item['stages'].add(entry['stage'])
 for item in anchors.values():item['stages']=sorted(item['stages'])
 functions.sort(key=lambda x:x['self_Ir'],reverse=True)
 helpers=sorted(groups.values(),key=lambda x:x['inclusive_Ir_non_additive'],reverse=True)
 return {'events':['Ir'],'root':ROOT_SYMBOL,'root_calls':sum(incoming[n] for n in roots),'total_Ir':profile.summary['Ir'],'exclusive_stages':dict(buckets),'stage_descriptions':DESCRIPTIONS,'exclusive_sum_verified':True,'ambiguous_contexts':[x for x in functions if x['bucket']=='shared_ambiguous'],'native_anchor_counts_and_non_additive_inclusive':anchors,'helper_observations_non_additive':helpers,'self_cost_contexts':functions,'limitations':['This is an instruction diagnostic, not a runtime or benchmark prediction.','The diagnostic loop mirrors frozen timed work; it additionally returns the retained output/state across its collection boundary. Loop/output residual includes that diagnostic return.','Array capacity and empty state, timestamp/airport loading, module initialization, complete output consumption and audit replays are outside collection.','Inclusive helper costs overlap their parents and each other and must never be added to exclusive stage totals.','Ambiguous merged caller contexts remain separate rather than being distributed by message count.']}

def fixtures():
 def node(name,own):
  n=parser.Node(name);n.own['Ir']=own;return n
 r=node(ROOT_SYMBOL,1);d=node(PREFIX+'decode',2);s=node(POLICY+'streamStep',3);m=node('malloc',4)
 r.edges[d.name]['Ir']=6;r.calls[d.name]=1;r.edges[s.name]['Ir']=7;r.calls[s.name]=1
 d.edges[m.name]['Ir']=4;d.calls[m.name]=1;s.edges[m.name]['Ir']=4;s.calls[m.name]=1
 p=parser.Profile(Path('fixture'),['Ir'],{n.name:n for n in [r,d,s,m]},Counter(Ir=10),{})
 result=analyze(p);assert result['exclusive_stages']['shared_ambiguous']==4 and result['total_Ir']==10
 assert transition(POLICY+'decodeGlobalFloat','airborne_pairing_policy')=='numeric_geography'
 assert transition(PREFIX+'Binary64_div','motion_policy')=='motion_policy'
 assert transition(POLICY+'validMotion','airborne_pairing_policy')=='motion_policy'
 assert transition(POLICY+'decodeLocalFloat','decoder')=='decoder'
 orphan=node('unreachable',1);p.nodes[orphan.name]=orphan;p.summary['Ir']+=1
 try:analyze(p)
 except ValueError:pass
 else:raise AssertionError('outside root accepted')
 return {'status':'passed','cases':6,'checked':'Shared ambiguity, exact sum, geographic/motion/decoder precedence and outside-root rejection'}
def main():
 a=argparse.ArgumentParser();a.add_argument('--profile',type=Path);a.add_argument('--output',type=Path,required=True);args=a.parse_args();assert not args.output.exists();args.output.mkdir(parents=True)
 (args.output/'fixture-checks.json').write_text(json.dumps(fixtures(),indent=2)+'\n')
 if not args.profile:return
 profile=parser.parse(args.profile);assert profile.events==['Ir'];result=analyze(profile);raw=gzip.decompress(args.profile.read_bytes()) if args.profile.suffix=='.gz' else args.profile.read_bytes()
 result.update(profile=str(args.profile),raw_sha256=hashlib.sha256(raw).hexdigest(),container_sha256=hashlib.sha256(args.profile.read_bytes()).hexdigest(),analyzer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),parser_sha256=hashlib.sha256(Path(parser.__file__).read_bytes()).hexdigest())
 (args.output/'analysis.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'total_Ir':result['total_Ir'],'exclusive_stages':result['exclusive_stages'],'root_calls':result['root_calls']}))
if __name__=='__main__':main()

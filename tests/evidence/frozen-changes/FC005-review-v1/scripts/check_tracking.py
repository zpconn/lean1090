#!/usr/bin/env python3
"""Fresh actual Impl.decodePositions / rs1090 decode_positions comparison.
Diagnostic mode accumulates all differences; success requires every position
within 1e-9 degrees, matching row routing and final public tracking state.
"""
import argparse,collections,gzip,hashlib,json,math,os,platform,struct,subprocess,sys,time
from pathlib import Path
from generate_tracking import ROOT,write
PIN='685dfaa34c5ab186c691bca3cfe2a22e12517d30'
REQUIRED=['df17','df18','airborne_even','airborne_odd','pair_even_then_odd','pair_odd_then_even',
 'pair_gap_inside','pair_gap_exact','pair_gap_outside','opposite_slot_empty','global_success','global_rejected',
 'local_age_inside','local_age_exact','local_age_outside','local_attempt','local_success','local_rejected','local_no_previous_position',
 'cross_parity_out_of_order','same_parity_out_of_order_replacement','cache_unchanged_early_return',
 'cache_replace_accepted','cache_replace_failed','speed_gap_inside','speed_gap_exact','speed_gap_outside',
 'speed_below_threshold','speed_exact_threshold','speed_above_threshold','accepted_callback_true','accepted_callback_false','speed_zero_dt','speed_rejection','jump_rejection','motion_pass','distance_below_500','distance_above_500',
 'surface_odd','surface_even','surface_has_previous','surface_own_within_1km','surface_own_outside_1km',
 'surface_own_decode_rejected','surface_shared_attempt','surface_existing_bypasses_airport','surface_first_near_airport',
 'surface_first_far_from_airport','surface_no_shared_reference','surface_shared_decode_rejected',
 'surface_out_of_order','surface_stale_previous','surface_recent_previous',
 'reference_initialized','reference_updated','reference_unchanged','other_adsb','non_adsb','decode_rejected']
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def floatof(b):return struct.unpack('>d',struct.pack('>Q',b))[0]
def position(a,b):
 if a is None or b is None:return a==b,a==b,0.
 error=max(abs(floatof(x)-floatof(y)) for x,y in zip(a,b));return error<=1e-9,a==b,error

def compare(out):
 populations=collections.defaultdict(collections.Counter);counts=collections.Counter();by_stream=collections.defaultdict(collections.Counter);bad=[];maxerr=0.;rows=finals=resolved=identical=missing=0
 A=list(map(json.loads,(out/'oracle.jsonl').read_text().splitlines()));B=list(map(json.loads,(out/'lean.jsonl').read_text().splitlines()))
 if len(A)!=len(B):bad.append(dict(kind='cardinality',oracle=len(A),lean=len(B)))
 for a,b in zip(A,B):
  labels=a.get('branches',[]);counts.update(labels);by_stream[a['stream']].update(labels);population=populations['corpus' if a['stream']=='full_corpus' else 'synthetic']
  if (a['stream'],a.get('id'),a.get('final'))!=(b['stream'],b.get('id'),b.get('final')):bad.append(dict(kind='row_identity',oracle=a,lean=b));continue
  if a.get('final'):
   finals+=1;population['streams']+=1;ok,_,err=position(a['reference'],b['reference']);maxerr=max(maxerr,err)
   if not ok:bad.append(dict(kind='final_reference',oracle=a,lean=b))
   if len(a['aircraft'])!=len(b['aircraft']):bad.append(dict(kind='state_cardinality',oracle=a,lean=b));continue
   for x,y in zip(a['aircraft'],b['aircraft']):
    ok,_,err=position(x['position'],y['position']);maxerr=max(maxerr,err)
    if not ok or {k:v for k,v in x.items() if k!='position'}!={k:v for k,v in y.items() if k!='position'}:bad.append(dict(kind='final_aircraft_state',stream=a['stream'],oracle=x,lean=y))
  else:
   rows+=1;population['messages']+=1;ok,exact,err=position(a['position'],b['position']);maxerr=max(maxerr,err)
   if a['position'] is not None:resolved+=1;identical+=exact;population['resolved_positions']+=1;population['position_bit_identical']+=exact
   else:missing+=a['position']==b['position'];population['unresolved_equal']+=a['position']==b['position']
   if not ok or a['routed']!=b['routed']:bad.append(dict(kind='message',oracle=a,lean=b,error_degrees=err))
 for branch in REQUIRED:
  if counts[branch]==0:bad.append(dict(kind='missing_branch',branch=branch))
 (out/'mismatches.jsonl').write_text(''.join(json.dumps(b,sort_keys=True)+'\n' for b in bad))
 return dict(messages=rows,streams=finals,resolved_positions=resolved,position_bit_identical=identical,
   unresolved_equal=missing,maximum_error_degrees=maxerr,mismatches=len(bad),required_branches=len(REQUIRED),
   populations={k:dict(v) for k,v in populations.items()},branch_counts=dict(sorted(counts.items())),per_stream_branch_counts={k:dict(sorted(v.items())) for k,v in by_stream.items()})
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',default='tests/evidence/tracking-diagnostic');p.add_argument('--no-corpus',action='store_true');p.add_argument('--random-tracks',type=int,default=200);p.add_argument('--seed',type=int,default=109005);p.add_argument('--diagnostic',action='store_true');a=p.parse_args();out=(ROOT/a.output).resolve();out.mkdir(parents=True,exist_ok=True);commands=[]
 env={**os.environ,'CARGO_HOME':str(ROOT/'.cache/cargo')}
 def run(cmd,stdin=None,stdout=None):
  start=time.time();r=subprocess.run(cmd,cwd=ROOT,env=env,stdin=stdin,stdout=stdout or subprocess.PIPE,stderr=subprocess.PIPE,text=stdout is None)
  commands.append(dict(command=cmd,exit=r.returncode,elapsed_seconds=time.time()-start,stderr=r.stderr.decode() if isinstance(r.stderr,bytes) else r.stderr,stdout=r.stdout if isinstance(r.stdout,str) else None))
  (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
  if r.returncode:raise RuntimeError(f'failed command {cmd}; see commands.json')
  return r.stdout
 assert run(['git','-C','vendor/rs1090','rev-parse','HEAD']).strip()==PIN
 run(['git','-C','vendor/rs1090','diff','--exit-code','HEAD','--','crates/rs1090','Cargo.toml','Cargo.lock'])
 run(['python3','scripts/check_lock.py'])
 run(['lake','env','lean','--version']);run(['cargo','--version'])
 meta=write(out,not a.no_corpus,a.random_tracks,a.seed)
 run(['cargo','build','--offline','--locked','--profile','dist','--manifest-path','differential/tracking-oracle/Cargo.toml','--target-dir','.cache/rs1090-target'])
 run(['lake','build','Impl'])
 for name,cmd in [('oracle',[str(ROOT/'.cache/rs1090-target/dist/lean1090-tracking-oracle')]),('lean',['lake','env','lean','--run','Tests/Tracking.lean',str(out/'airports.jsonl')])]:
  with (out/'input.jsonl').open('rb') as inp,(out/(name+'.jsonl')).open('wb') as dest:run(cmd,inp,dest)
 result=compare(out);assert result['messages']==meta['messages'];assert result['streams']==meta['streams']
 files=['Tests/Tracking.lean','scripts/check_tracking.py','scripts/generate_tracking.py','differential/tracking-oracle/Cargo.toml','differential/tracking-oracle/Cargo.lock','differential/tracking-oracle/src/main.rs','Impl/CPRPolicy.lean','Impl/CPRFloat.lean','Impl/Message.lean','Impl/Semantics.lean','vendor/rs1090/crates/rs1090/src/decode/cpr.rs','vendor/rs1090/crates/rs1090/data/airports.json','vendor/rs1090/crates/rs1090/data/long_flight.csv','spec.lock','lean-toolchain','lake-manifest.json']
 result.update(generation=meta,pinned_rs1090=PIN,platform=platform.platform(),machine=platform.machine(),source_sha256={f:sha(ROOT/f) for f in files},input_sha256=sha(out/'input.jsonl'),tolerance_degrees=1e-9,
   implementation_entrypoint='Impl.decodePositions',oracle_entrypoint='rs1090::decode::cpr::decode_positions',
   trace_validation='Every separate sequential decode_position result is bit-identical to actual batch decode_positions before branch labels are emitted; final public state is also compared.',
   limitation='Finite recorded strata; not proof of numerical geography, airport database accuracy, or exhaustive streams.')
 (out/'summary.json').write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
 for name in ('input.jsonl','airports.jsonl','oracle.jsonl','lean.jsonl'):
  path=out/name
  with gzip.GzipFile(str(path)+'.gz','wb',mtime=0) as f:f.write(path.read_bytes())
  path.unlink()
 print(json.dumps({k:v for k,v in result.items() if k not in ('per_stream_branch_counts','generation','source_sha256')},indent=2))
 return int(result['mismatches']!=0)
if __name__=='__main__':sys.exit(main())

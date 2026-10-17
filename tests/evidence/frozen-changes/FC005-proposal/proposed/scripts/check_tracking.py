#!/usr/bin/env python3
"""Fresh actual Impl.decodePositions / rs1090 decode_positions comparison.
Diagnostic mode accumulates all differences; success requires every position
within 1e-9 degrees, matching row routing and final public tracking state.
"""
import argparse,collections,gzip,hashlib,json,math,os,platform,struct,subprocess,sys,time
from pathlib import Path
from generate_tracking import ROOT,write
PIN='685dfaa34c5ab186c691bca3cfe2a22e12517d30'
# Each label has one documented role. Outcome IDs name distinct source decision
# arms/results, so boundary splits and aliases never inflate the outcome count.
# Lines refer only to the pinned vendor/rs1090/.../decode/cpr.rs.
_CATALOG = '''
df17|real_outcome|887-894|routing.df17|The batch dispatch selects ExtendedSquitterADSB.
df18|real_outcome|895-902|routing.df18|The batch dispatch selects ExtendedSquitterTisB.
non_adsb|real_outcome|903|routing.other|A successfully decoded frame has no tracking dispatch.
decode_rejected|real_outcome|885-905|routing.missing|Message::from_bytes failed; the batch skips the missing message.
airborne|real_outcome|671-675|payload.airborne|The ME dispatch selects BDS05.
surface|real_outcome|789-792|payload.surface|The ME dispatch selects BDS06.
other_adsb|real_outcome|852-866|payload.other|The other-ME arm records supported evidence and produces no position.
airborne_even|real_outcome|678-685,778-786|parity.even|Even reads the odd slot and eventually replaces the even slot unless returned early.
airborne_odd|real_outcome|678-685,778-786|parity.odd|Odd reads the even slot and eventually replaces the odd slot unless returned early.
pair_even_then_odd|cooccurring_duplicate|678-699||The odd parity arm with a populated even slot; not another decision.
pair_odd_then_even|cooccurring_duplicate|678-699||The even parity arm with a populated odd slot; not another decision.
cross_parity_out_of_order|real_outcome|688-690|ordering.return|Negative time relative to the opposite slot returns before any state update.
cache_unchanged_early_return|cooccurring_duplicate|688-690||Same event as cross_parity_out_of_order; state/cache preservation is checked.
same_parity_out_of_order_replacement|negative_control|688-690,778-786||Only the opposite timestamp is checked; replacement of an older same-parity slot is permitted.
pair_gap_inside|real_outcome|692-700|pair_window.inside|The strict absolute 30-second pair window passes after the ordering check.
pair_gap_exact|boundary_split|692-700|pair_window.outside|Exactly 30 seconds fails the strict pair window.
pair_gap_outside|boundary_split|692-700|pair_window.outside|More than 30 seconds fails the same strict pair-window condition.
opposite_slot_empty|real_outcome|696-699|pair_slot.empty|The opposite slot is None, so global reconstruction has no candidate.
global_success|real_outcome|697,702-705|global_result.some|airborne_position returns Some, so the local fallback is skipped.
global_rejected|real_outcome|697,702-705|global_result.none|airborne_position returns None, so the local-age condition is considered.
local_age_inside|real_outcome|704-706|local_age.inside|The signed age is strictly less than 180 seconds, including negative ages.
local_age_exact|boundary_split|704-706|local_age.outside|Exactly 180 seconds fails the signed local-age condition.
local_age_outside|boundary_split|704-706|local_age.outside|Greater than 180 seconds fails the same signed condition.
local_attempt|real_outcome|707-713|local_reference.some|A previous accepted position exists for local fallback.
local_no_previous_position|real_outcome|707-713|local_reference.none|No previous accepted position exists for local fallback.
local_success|real_outcome|708-713|local_result.some|The actual airborne_position_with_reference returns Some.
local_rejected|real_outcome|708-713|local_result.none|The actual airborne_position_with_reference returns None.
speed_gap_inside|real_outcome|720-729|speed_window.inside|Absolute age below 1800 seconds enables speed validation.
speed_gap_exact|boundary_split|727-737|speed_window.outside|Exactly 1800 seconds bypasses speed validation.
speed_gap_outside|boundary_split|727-737|speed_window.outside|Greater than 1800 seconds bypasses the same condition.
speed_zero_dt|real_outcome|728-736|speed_duration.zero|Zero absolute duration bypasses division/speed rejection.
speed_below_threshold|boundary_split|730-735|speed_threshold.pass|Computed speed below 1200 km/h does not reject.
speed_exact_threshold|boundary_split|730-735|speed_threshold.pass|Computed speed equal to 1200 km/h does not reject.
speed_above_threshold|boundary_split|730-735|speed_threshold.reject|Computed speed greater than 1200 km/h rejects.
speed_rejection|cooccurring_duplicate|733-735|speed_threshold.reject|Same rejected event as speed_above_threshold.
jump_rejection|real_outcome|743-748|jump.reject|Candidate survives speed but exceeds 500 km with absolute age below 30 seconds.
motion_pass|real_outcome|743-748|jump.pass|After surviving speed validation, the compound jump-rejection condition is false; its conjuncts are not counted separately.
distance_below_500|outcome_split|743-748||Distance context only; speed rejection or age can prevent the jump condition from evaluating.
distance_exact_500|outcome_split|743-748||Exact distance boundary context; not required because no exact binary64 fixture is assumed.
distance_above_500|outcome_split|743-748||Distance context only; does not by itself imply jump rejection.
cache_replace_accepted|real_outcome|755-786|airborne_result.some|Accepted candidate updates public state then replaces its parity cache.
cache_replace_failed|real_outcome|755-786|airborne_result.none|No accepted candidate; public position is preserved but its parity cache is replaced.
accepted_callback_true|cooccurring_duplicate|768-774||Aggregate alias for callback present and true.
accepted_callback_false|outcome_split|768-774||Aggregate of callback absent or callback returning false; not one source branch.
callback_absent|real_outcome|768-775|callback.absent|No update callback was supplied.
callback_true|real_outcome|769-774|callback.true|A supplied callback returns true and updates shared reference.
callback_false|real_outcome|769-774|callback.false|A supplied callback returns false and leaves shared reference unchanged.
surface_even|context|580-592,789-792||Surface parity selects the low-level grid; decode_position has no surface parity policy branch.
surface_odd|context|580-592,789-792||Surface parity selects the low-level grid; decode_position has no surface parity policy branch.
surface_has_previous|real_outcome|794-806|surface_previous.some|An existing accepted position permits an own-reference attempt.
surface_own_decode_rejected|real_outcome|795-802|surface_own_decode.none|The own-reference decoder returns None; short circuit skips distance.
surface_own_within_1km|real_outcome|800-805|surface_own_distance.inside|Decoded distance is strictly below 1 km and the own-reference candidate is retained.
surface_own_outside_1km|real_outcome|800-805|surface_own_distance.outside|Decoded distance is at least 1 km, so own-reference candidate is discarded.
surface_shared_attempt|real_outcome|807-813|surface_shared.some|No own candidate remains and a shared reference exists.
surface_no_shared_reference|real_outcome|807-833|surface_shared.none|No own candidate remains and no shared reference exists.
surface_shared_decode_rejected|real_outcome|817-831|surface_shared_decode.none|Shared-reference decoder returns None.
surface_existing_bypasses_airport|real_outcome|818-826|surface_first.existing|Existing position bypasses first-surface airport proximity validation.
surface_first_near_airport|real_outcome|818-823|surface_first_airport.near|First position is within strict 10-km airport proximity and accepted.
surface_first_far_from_airport|real_outcome|818-823|surface_first_airport.far|First position is not within strict 10-km airport proximity and rejected.
surface_out_of_order|negative_control|789-850||No surface timestamp gate exists; a backward timestamp can still update position.
surface_stale_previous|negative_control|789-850||No surface 180-second age gate exists; this tests absence of an airborne-only rule.
surface_recent_previous|negative_control|789-850||Age below 180 seconds is context, not a surface policy branch.
reference_initialized|outcome_split|768-774||A true callback changed None to Some; initialization is not a separate source branch.
reference_updated|outcome_split|768-774||A true callback changed an existing coordinate; source uses the same assignment.
reference_unchanged|outcome_split|688-690,755-775,789-866||Can result from early return, failure, absent/false callback, unchanged coordinates, or non-airborne message.
resolved|outcome_split|755-776,834-850||Aggregate accepted position across airborne and surface paths.
unresolved|outcome_split|688-690,755-776,834-866||Aggregate missing position across different policy outcomes.
surface_own_1km_just_inside|boundary_split|800-805|surface_own_distance.inside|Decoded distance lies in the 2-m band below 1 km; targeted fixtures are additionally required within one latitude code.
surface_own_1km_just_outside|boundary_split|800-805|surface_own_distance.outside|Decoded distance lies in the 2-m band at/above 1 km; targeted fixtures are additionally required strictly above and within one latitude code.
airborne_backward_motion|context|705,720-721||Nonzero movement with negative signed age witnesses use of absolute duration for motion.
backward_speed_below_threshold|boundary_split|720-735|speed_threshold.pass|Nonzero backward-time movement at or below 1200 km/h passes; targeted fixtures must be strictly below.
backward_speed_above_threshold|boundary_split|720-735|speed_threshold.reject|Nonzero backward-time movement above 1200 km/h rejects; missing abs would accept.
signed_local_age_backward_motion|negative_control|704-713||A negative age permits local fallback; targeted fixtures at -180 seconds and on both sides test that an absolute-age rule would be wrong.
transition_surface_to_airborne_airport_cleared|state_effect|755-766||Accepted airborne position clears an existing airport; assignment outcome, not a new conditional arm.
transition_airborne_to_surface_altitude_reset|state_effect|834-844||Accepted surface position resets a nonempty altitude to None; assignment outcome, not a new conditional arm.
surface_airport_lookup_none|real_outcome|846-849|surface_airport.lookup|No airport was set, so nearest-airport lookup runs.
surface_airport_lookup_found|outcome_split|104-127,847-848||Lookup result is Some; a result split inside surface_airport.lookup, not another tracking branch.
surface_airport_lookup_missing|outcome_split|104-127,847-848||Lookup result is None; a result split inside surface_airport.lookup, not another tracking branch.
surface_airport_preserved_existing|real_outcome|846-849|surface_airport.preserve|An existing airport skips lookup and remains unchanged.
surface_airport_preserved_despite_new_nearest|negative_control|846-849||The existing airport is retained even when a fresh lookup would return another airport; no unconditional refresh exists.
'''
CATALOG = {}
for _row in _CATALOG.strip().splitlines():
 _label,_role,_lines,_outcome,_note = _row.split('|',4)
 assert _label not in CATALOG
 CATALOG[_label] = dict(role=_role,source='vendor/rs1090/crates/rs1090/src/decode/cpr.rs',lines=_lines,
  real_outcome=_outcome or None,note=_note,required=_label not in ('distance_exact_500','airborne','surface','resolved','unresolved'))
REQUIRED=[label for label,entry in CATALOG.items() if entry['required']]
REAL_OUTCOMES=sorted({entry['real_outcome'] for entry in CATALOG.values() if entry['real_outcome']})
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def floatof(b):return struct.unpack('>d',struct.pack('>Q',b))[0]
def position(a,b):
 if a is None or b is None:return a==b,a==b,0.
 if len(a)!=2 or len(b)!=2:return False,False,float('inf')
 x=list(map(floatof,a));y=list(map(floatof,b))
 if not all(math.isfinite(v) for v in x+y):return False,False,float('inf')
 error=max(abs(u-v) for u,v in zip(x,y));return error<=1e-9,a==b,error

def targeted_strata(rows,bad):
 """Require the requested boundary witnesses themselves, not incidental labels."""
 indexed={(r['stream'],r.get('id')):r for r in rows if not r.get('final')};witnesses=[]
 def row(name,i):
  r=indexed.get((name,i))
  if r is None:bad.append(dict(kind='missing_targeted_stratum',stream=name,id=i))
  else:witnesses.append(r)
  return r
 def check(ok,r,claim):
  if not ok:bad.append(dict(kind='targeted_stratum',claim=claim,oracle=r))
 for parity in (0,1):
  # Great-circle length of one surface latitude code at this parity.
  step_km=6371.*math.radians(90./((60-parity)*131072))
  for side in ('inside','outside'):
   for reference in ('no_shared','shared'):
    r=row(f'surface_own_1km_{side}_parity{parity}_{reference}',2)
    if r is None:continue
    d=r.get('metrics',{}).get('own_reference_distance_km',float('nan'))
    check(math.isfinite(d) and abs(d-1.)<step_km and ((d<1.) if side=='inside' else (d>1.)),r,'decoded distance within one surface latitude code of the correct side of 1 km')
    expected_label='surface_own_1km_just_'+side
    check(expected_label in r['branches'],r,'1 km boundary label present')
    check((r['position'] is not None)==(side=='inside' or reference=='shared'),r,'own-reference inside accepted; outside requires the shared fallback')
  for side in ('below','above'):
   r=row(f'backward_speed_1200_{side}_parity{parity}',3)
   if r is None:continue
   m=r.get('metrics',{});dt=m.get('motion_signed_dt_seconds',float('nan'));d=m.get('motion_distance_km',float('nan'));speed=m.get('speed_kmh',float('nan'))
   check(dt<0. and d>0. and math.isfinite(speed) and abs(speed-1200.)<.001 and ((speed<1200.) if side=='below' else (speed>1200.)),r,'nonzero backward motion brackets 1200 km/h within 0.001 km/h')
   check(m.get('motion_dt_seconds')==abs(dt),r,'motion duration is absolute signed dt')
   check((r['position'] is not None)==(side=='below'),r,'backward below speed accepted and backward above speed rejected')
   check('backward_speed_'+side+'_threshold' in r['branches'],r,'backward speed boundary label present')
  for side in ('outside_abs','exact_abs','inside_abs'):
   r=row(f'signed_local_age_motion_{side}_parity{parity}',3)
   if r is None:continue
   m=r.get('metrics',{});age=m.get('signed_local_age_seconds',float('nan'));d=m.get('motion_distance_km',float('nan'))
   correct_side=(age < -180.) if side=='outside_abs' else (age == -180. if side=='exact_abs' else age > -180.)
   check(math.isfinite(age) and age<0. and abs(age+180.)<1e-6 and correct_side and d>0.,r,'signed local-age witness at the requested side of -180 seconds has nonzero motion')
   check(r['position'] is not None and 'local_success' in r['branches'] and 'signed_local_age_backward_motion' in r['branches'],r,'signed local window permits all three negative-age moving positions')
 lifecycle='surface_airborne_airport_altitude_lifecycle'
 for i,airport,altitude,label in [(0,'EHAM',None,'surface_airport_lookup_found'),(1,None,500,'transition_surface_to_airborne_airport_cleared'),(2,'EHAM',None,'transition_airborne_to_surface_altitude_reset'),(5,'EHAM',None,'surface_airport_preserved_despite_new_nearest'),(6,None,500,'transition_surface_to_airborne_airport_cleared'),(7,'LFBO',None,'surface_airport_lookup_found'),(8,'LFBO',None,'surface_airport_preserved_existing')]:
  r=row(lifecycle,i)
  if r is None:continue
  state=r.get('label_integrity',{})
  check(r['position'] is not None and state.get('after_airport')==airport and state.get('after_altitude')==altitude and label in r['branches'],r,'real airport/altitude transition matches the labeled lifecycle')
 for last,airport,altitude in [(1,None,500),(2,'EHAM',None),(5,'EHAM',None),(6,None,500),(7,'LFBO',None),(8,'LFBO',None)]:
  name=f'{lifecycle}_prefix{last}'
  prefix=[r for r in rows if r['stream']==name]
  observed_ids=[r['id'] for r in prefix if not r.get('final')]
  terminal=[r for r in prefix if r.get('final')]
  check(observed_ids==list(range(last+1)) and len(terminal)==1,dict(stream=name,ids=observed_ids,terminal_count=len(terminal)),'independent prefix must end exactly at the transition and expose final Impl state')
  if len(terminal)!=1:continue
  r=terminal[0];witnesses.append(r)
  states=[a for a in r['aircraft'] if a['address']==0xabc001]
  check(len(states)==1 and states[0]['airport']==airport and states[0]['altitude']==altitude and states[0]['position'] is not None,r,'terminal prefix state exposes the expected intermediate airport and altitude')
 return witnesses

def compare(out):
 populations=collections.defaultdict(collections.Counter);counts=collections.Counter();by_stream=collections.defaultdict(collections.Counter);bad=[];integrity_counts=collections.Counter();maxerr=0.;rows=finals=resolved=identical=missing=0
 A=list(map(json.loads,(out/'oracle.jsonl').read_text().splitlines()));B=list(map(json.loads,(out/'lean.jsonl').read_text().splitlines()))
 if len(A)!=len(B):bad.append(dict(kind='cardinality',oracle=len(A),lean=len(B)))
 for a,b in zip(A,B):
  labels=a.get('branches',[]);
  if len(labels)!=len(set(labels)):bad.append(dict(kind='duplicate_labels',stream=a['stream'],id=a.get('id'),labels=labels))
  for label in labels:
   if label not in CATALOG:bad.append(dict(kind='unknown_label',stream=a['stream'],id=a.get('id'),label=label))
  counts.update(labels);by_stream[a['stream']].update(labels);population=populations['corpus' if a['stream']=='full_corpus' else 'synthetic']
  if (a['stream'],a.get('id'),a.get('final'))!=(b['stream'],b.get('id'),b.get('final')):bad.append(dict(kind='row_identity',oracle=a,lean=b));continue
  if a.get('final'):
   finals+=1;population['streams']+=1;ok,_,err=position(a['reference'],b['reference']);maxerr=max(maxerr,err)
   if not ok:bad.append(dict(kind='final_reference',oracle=a,lean=b))
   if len(a['aircraft'])!=len(b['aircraft']):bad.append(dict(kind='state_cardinality',oracle=a,lean=b));continue
   for x,y in zip(a['aircraft'],b['aircraft']):
    ok,_,err=position(x['position'],y['position']);maxerr=max(maxerr,err)
    if not ok or {k:v for k,v in x.items() if k!='position'}!={k:v for k,v in y.items() if k!='position'}:bad.append(dict(kind='final_aircraft_state',stream=a['stream'],oracle=x,lean=y))
  else:
   integrity=a.get('label_integrity',{})
   for flag in ('position_asserted','public_state_asserted'):
    if integrity.get(flag) is not True:bad.append(dict(kind='label_integrity',stream=a['stream'],id=a['id'],flag=flag,actual=integrity.get(flag)))
    else:integrity_counts[flag]+=1
   if a.get('routed'):
    predicted=integrity.get('candidate') if 'airborne' not in labels or integrity.get('motion_pass') is True else None
    if not all(k in integrity for k in ('candidate','motion_pass','predicted_position','actual_position')) or predicted!=integrity.get('predicted_position') or integrity.get('predicted_position')!=integrity.get('actual_position') or integrity.get('actual_position')!=a['position']:
     bad.append(dict(kind='label_prediction',oracle=a))
    else:integrity_counts['routed_candidate_equals_real_outcome']+=1
   rows+=1;population['messages']+=1;ok,exact,err=position(a['position'],b['position']);maxerr=max(maxerr,err)
   if a['position'] is not None:resolved+=1;identical+=exact;population['resolved_positions']+=1;population['position_bit_identical']+=exact
   else:missing+=a['position']==b['position'];population['unresolved_equal']+=a['position']==b['position']
   if not ok or a['routed']!=b['routed']:bad.append(dict(kind='message',oracle=a,lean=b,error_degrees=err))
 for branch in REQUIRED:
  if counts[branch]==0:bad.append(dict(kind='missing_branch',branch=branch))
 outcome_counts=collections.Counter()
 for a in A:
  outcome_counts.update({CATALOG[label]['real_outcome'] for label in a.get('branches',[]) if label in CATALOG and CATALOG[label]['real_outcome']})
 witnesses=targeted_strata(A,bad)
 (out/'targeted-witnesses.json').write_text(json.dumps(witnesses,indent=2,sort_keys=True)+'\n')
 (out/'coverage-catalog.json').write_text(json.dumps(CATALOG,indent=2,sort_keys=True)+'\n')
 (out/'mismatches.jsonl').write_text(''.join(json.dumps(b,sort_keys=True)+'\n' for b in bad))
 return dict(messages=rows,streams=finals,resolved_positions=resolved,position_bit_identical=identical,
   unresolved_equal=missing,maximum_error_degrees=maxerr,mismatches=len(bad),required_labels=len(REQUIRED),observed_labels=len(counts),
   distinct_real_outcomes_required=len(REAL_OUTCOMES),distinct_real_outcomes_covered=sum(outcome_counts[o]>0 for o in REAL_OUTCOMES),
   real_outcome_counts=dict(sorted(outcome_counts.items())),label_catalog=CATALOG,label_integrity_counts=dict(integrity_counts),targeted_witnesses=len(witnesses),
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
   trace_validation='Every sequential decode_position result is asserted bit-identical to actual batch decode_positions. Every airborne shadow candidate is asserted equal to the real output after motion validation; every surface candidate is asserted equal unconditionally. These assertions validate oracle labels, not Lean numeric acceptance: Lean positions pass at 1e-9 degrees, with bit identity only reported.',
   limitation='Finite recorded strata; not proof of numerical geography, airport database accuracy, or exhaustive streams.')
 (out/'summary.json').write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
 for name in ('input.jsonl','airports.jsonl','oracle.jsonl','lean.jsonl'):
  path=out/name
  with gzip.GzipFile(str(path)+'.gz','wb',mtime=0) as f:f.write(path.read_bytes())
  path.unlink()
 print(json.dumps({k:v for k,v in result.items() if k not in ('per_stream_branch_counts','generation','source_sha256','label_catalog')},indent=2))
 return int(result['mismatches']!=0)
if __name__=='__main__':sys.exit(main())

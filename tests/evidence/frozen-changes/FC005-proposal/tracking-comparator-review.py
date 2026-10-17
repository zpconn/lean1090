from pathlib import Path
import sys,json,gzip,copy,tempfile,struct,hashlib
sys.path.insert(0,str(Path('scripts').resolve()))
import check_tracking as checker
src=Path('tests/evidence/tracking-diagnostic')
with gzip.open(src/'oracle.jsonl.gz','rt') as f: oracle=[json.loads(l) for l in f]
with gzip.open(src/'lean.jsonl.gz','rt') as f: lean=[json.loads(l) for l in f]
selected=set();uncovered=set(checker.REQUIRED)
for i,a in enumerate(oracle):
 if uncovered.intersection(a.get('branches',[])):
  selected.add(i);uncovered.difference_update(a.get('branches',[]))
 if a['stream'].startswith(('surface_own_1km_','backward_speed_1200_','signed_local_age_motion_','surface_airborne_airport_altitude_lifecycle')):selected.add(i)
assert not uncovered,uncovered
selected.add(next(i for i,a in enumerate(oracle) if a.get('position') is not None))
selected.add(next(i for i,a in enumerate(oracle) if a.get('final') and a['aircraft']))
selected.add(next(i for i,a in enumerate(oracle) if 'surface' in a.get('branches',[]) and a.get('position') is None))
A=[oracle[i] for i in sorted(selected)];B=[lean[i] for i in sorted(selected)]
resolved=next(i for i,a in enumerate(B) if a.get('position') is not None)
unresolved_surface=next(i for i,a in enumerate(A) if 'surface' in a.get('branches',[]) and a.get('position') is None)
near=next(i for i,a in enumerate(A) if a['stream']=='surface_own_1km_inside_parity0_no_shared' and a.get('id')==2)
final=next(i for i,a in enumerate(A) if a['stream']=='surface_airborne_airport_altitude_lifecycle_prefix1' and a.get('final'))
def bits(x):return struct.unpack('>Q',struct.pack('>d',x))[0]
def delta(b,d):b[resolved]['position'][0]=bits(checker.floatof(b[resolved]['position'][0])+d)
def drop_prefix(a,b):
 name='surface_airborne_airport_altitude_lifecycle_prefix1'
 a[:]=[r for r in a if r['stream']!=name];b[:]=[r for r in b if r['stream']!=name]
cases=[]
with tempfile.TemporaryDirectory(prefix='lean1090-tracking-comparator-v2-') as tmp:
 p=Path(tmp)
 for name,change,expected_fail in [
  ('intact',lambda a,b:None,False),
  ('below_1e-9_not_bit_identical',lambda a,b:delta(b,5e-10),False),
  ('above_1e-9',lambda a,b:delta(b,2e-9),True),
  ('resolved_became_missing',lambda a,b:b[resolved].update(position=None),True),
  ('missing_output_row',lambda a,b:b.pop(),True),
  ('wrong_routing',lambda a,b:b[resolved].update(routed=not b[resolved]['routed']),True),
  ('branch_evidence_missing',lambda a,b:[x.update(branches=[]) for x in a],True),
  ('wrong_row_identity',lambda a,b:b[resolved].update(id=999999999),True),
  ('unknown_label',lambda a,b:a[resolved]['branches'].append('invented_branch'),True),
  ('duplicate_label',lambda a,b:a[resolved]['branches'].append(a[resolved]['branches'][0]),True),
  ('position_assertion_flag_false',lambda a,b:a[resolved]['label_integrity'].update(position_asserted=False),True),
  ('state_assertion_flag_false',lambda a,b:a[resolved]['label_integrity'].update(public_state_asserted=False),True),
  ('shadow_prediction_false',lambda a,b:a[resolved]['label_integrity'].update(predicted_position=None),True),
  ('unresolved_surface_candidate_disagrees',lambda a,b:a[unresolved_surface]['label_integrity'].update(candidate=A[resolved]['position']),True),
  ('near_threshold_metric_not_near',lambda a,b:a[near]['metrics'].update(own_reference_distance_km=.5),True),
  ('missing_transition_prefix',drop_prefix,True),
  ('wrong_intermediate_airport',lambda a,b:b[final]['aircraft'][0].update(airport='EHAM'),True),
  ('nonfinite_second_coordinate',lambda a,b:b[resolved]['position'].__setitem__(1,bits(float('nan'))),True),
  ('one_coordinate_only',lambda a,b:b[resolved]['position'].pop(),True)]:
  a,b=copy.deepcopy(A),copy.deepcopy(B);change(a,b)
  for name_,data in [('oracle',a),('lean',b)]:
   (p/(name_+'.jsonl')).write_text(''.join(json.dumps(x)+'\n' for x in data))
  r=checker.compare(p);assert bool(r['mismatches'])==expected_fail,(name,r)
  if name=='below_1e-9_not_bit_identical':assert r['position_bit_identical']<r['resolved_positions']
  cases.append({'case':name,'expected_rejection':expected_fail,'mismatches':r['mismatches'],'maximum_error_degrees':r['maximum_error_degrees'],'position_bit_identical':r['position_bit_identical'],'resolved_positions':r['resolved_positions']})
result={'cases':cases,'selected_actual_trace_rows':len(A),'checker_sha256':hashlib.sha256(Path('scripts/check_tracking.py').read_bytes()).hexdigest(),'source_summary_sha256':hashlib.sha256((src/'summary.json').read_bytes()).hexdigest(),'note':'Comparator injection checks against selected actual trace rows covering all required labels and targeted streams. Bit inequality under 1e-9 is accepted. Not an additional full stream campaign.'}
out=Path('tests/evidence/frozen-changes/FC005-proposal');out.mkdir(parents=True,exist_ok=True)
(out/'tracking-comparator-review.json').write_text(json.dumps(result,indent=2)+'\n')
(out/'tracking-comparator-review.py').write_bytes(Path(__file__).read_bytes())
print(json.dumps(result,indent=2))

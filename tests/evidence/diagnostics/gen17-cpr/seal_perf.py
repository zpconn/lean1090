#!/usr/bin/env python3
"""Seal completed actual-worker sampling; no native execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
R=Path.cwd();E=R/'tests/evidence/diagnostics/gen17-cpr';P=E/'perf'
def sha(p):
 with p.open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def load(p):return json.loads(p.read_text())
def write(p,v):
 assert not p.exists();p.write_text(json.dumps(v,indent=2)+'\n')
a=load(P/'analysis.json');c=load(P/'capture.json');done=load(E/'isolated-perf-completion.json')
assert done['status']=='passed' and done['all_jobs_stopped'] and done['sequential_modes']==['decode','cpr']
assert c['record_exit_code']==0 and c['all_input_hashes_unchanged'] and c['before_hashes']==c['after_hashes']
for name,value in c['before_hashes'].items():assert sha(R/name)==value,name
raw=done['results'][1]['raw'];assert sha(R/raw['path'])==raw['sha256'] and (R/raw['path']).stat().st_size==raw['bytes']
assert done['results'][1]['capture_sha256']==sha(P/'capture.json')
lost=[]
for name in ['report-self.txt','report-children.txt']:
 for i,line in enumerate((P/name).read_text().splitlines(),1):
  if line.startswith('# Total Lost Samples:'):
   assert re.fullmatch(r'# Total Lost Samples:\s*0',line)
   lost.append({'file':name,'line':i,'text':line})
assert len(lost)==2 and a['reported_lost_samples']==0
assert a['total_samples']==a['visible_CPR_loop_samples']+a['excluded_samples']
record={'status':'passed','reviewed_at_utc':datetime.now(timezone.utc).isoformat(),'capture_exit_code':0,
 'analysis_command':['python3','-B','tests/evidence/diagnostics/gen17-cpr/perf/analyze_cpr_perf.py'],'analysis_exit_code':0,
 'capture_helper_sha256':sha(E/'run_isolated_perf.py'),'analysis_helper_sha256':sha(P/'analyze_cpr_perf.py'),
 'captured_input_hash_count':len(c['before_hashes']),'all_input_hashes_still_match':True,
 'gen17_fresh_native_binding':{'linked_project_objects':22,'build_record':'bench/runs/gen17/binary-built.json','build_record_sha256':sha(R/'bench/runs/gen17/binary-built.json'),
 'fresh_native_record':'bench/runs/gen17/fresh-native-inputs.json','fresh_native_record_sha256':sha(R/'bench/runs/gen17/fresh-native-inputs.json'),
 'source_equivalence':'tests/evidence/diagnostics/gen17/benchmark-source-binding.json','source_equivalence_sha256':sha(R/'tests/evidence/diagnostics/gen17/benchmark-source-binding.json')},
 'samples':a['total_samples'],'included_decode_stacks':None,'included_cpr_loop_stacks':a['visible_CPR_loop_samples'],
 'excluded_samples':a['excluded_samples'],'lost_sample_report_lines':lost,'unknown_frame_stacks':a['all_samples_with_unknown_frame'],
 'unknown_decode_leaf_samples':None,'unknown_cpr_leaf_samples':a['included_unknown_leaves'],'raw_data':raw,
 'capture_sha256':sha(P/'capture.json'),'no_throughput_claim':True}
write(P/'completion.json',record)
write(P/'artifact-hashes.json',{'status':'passed','files':{str(p.relative_to(P)):sha(p) for p in sorted(P.rglob('*')) if p.is_file()}})
print(json.dumps({k:record[k] for k in ['status','samples','included_cpr_loop_stacks','excluded_samples','unknown_frame_stacks','unknown_cpr_leaf_samples','captured_input_hash_count']}))

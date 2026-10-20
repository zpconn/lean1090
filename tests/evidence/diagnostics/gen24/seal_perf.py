#!/usr/bin/env python3
"""Seal completed actual-worker sampling; no native execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
R=Path.cwd();E=R/'tests/evidence/diagnostics/gen24';P=E/'perf'
def sha(p):
 with p.open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def load(p):return json.loads(p.read_text())
def write(p,v):
 assert not p.exists();p.write_text(json.dumps(v,indent=2)+'\n')
a=load(P/'analysis.json');c=load(P/'capture.json');done=load(R/'tests/evidence/diagnostics/gen24-cpr/isolated-perf-completion.json')
assert done['status']=='passed' and done['all_jobs_stopped'] and done['sequential_modes']==['decode','cpr']
assert c['record_exit_code']==0 and c['all_input_hashes_unchanged'] and c['before_hashes']==c['after_hashes']
for name,value in c['before_hashes'].items():assert sha(R/name)==value,name
raw=done['results'][0]['raw'];assert sha(R/raw['path'])==raw['sha256'] and (R/raw['path']).stat().st_size==raw['bytes']
assert done['results'][0]['capture_sha256']==sha(P/'capture.json')
lost=[]
for name in ['report-self.txt','report-children.txt']:
 for i,line in enumerate((P/name).read_text().splitlines(),1):
  if line.startswith('# Total Lost Samples:'):
   assert re.fullmatch(r'# Total Lost Samples:\s*0',line)
   lost.append({'file':name,'line':i,'text':line})
assert len(lost)==2
assert a['total_samples']==a['decode_descendant_samples']+a['excluded_samples']
record={'status':'passed','reviewed_at_utc':datetime.now(timezone.utc).isoformat(),'capture_exit_code':0,
 'analysis_command':['python3','-B','tests/evidence/diagnostics/gen24/perf/analyze_perf_gen24.py'],'analysis_exit_code':0,
 'capture_helper_sha256':sha(R/'tests/evidence/diagnostics/gen24-cpr/run_isolated_perf.py'),'analysis_helper_sha256':sha(P/'analyze_perf_gen24.py'),
 'captured_input_hash_count':len(c['before_hashes']),'all_input_hashes_still_match':True,
 'gen24_fresh_native_binding':{'linked_project_objects':22,'build_record':'bench/runs/gen24/binary-built.json','build_record_sha256':sha(R/'bench/runs/gen24/binary-built.json'),
 'fresh_native_record':'bench/runs/gen24/fresh-native-inputs.json','fresh_native_record_sha256':sha(R/'bench/runs/gen24/fresh-native-inputs.json'),
 'source_equivalence':'tests/evidence/diagnostics/gen24/benchmark-source-binding.json','source_equivalence_sha256':sha(R/'tests/evidence/diagnostics/gen24/benchmark-source-binding.json')},
 'samples':a['total_samples'],'included_decode_stacks':a['decode_descendant_samples'],'included_cpr_loop_stacks':None,
 'excluded_samples':a['excluded_samples'],'lost_sample_report_lines':lost,'unknown_frame_stacks':a['all_samples_with_unknown_frame'],
 'unknown_decode_leaf_samples':sum(json.loads(line)['leaf']=='[unknown]' for line in (P/'decode-samples.jsonl').read_text().splitlines()),'unknown_cpr_leaf_samples':None,'raw_data':raw,
 'capture_sha256':sha(P/'capture.json'),'no_throughput_claim':True}
write(P/'completion.json',record)
(P/'README.md').write_text(f'''# Generation 24 decode actual-worker diagnostic sampling

One actual frozen worker run was sampled on CPU 0 with cpu-clock:u at 199 Hz after both diagnostic builds. Decode and CPR captures ran sequentially with other native/profile jobs held. This is not a benchmark. All {record['captured_input_hash_count']} protected inputs and 22 fresh native sets remained unchanged. The explicit source binding relates timed cc337104 to artifact d0f58661; documentation commits have no measured speed attribution.

All {record['samples']} recorded samples were parsed; {record['included_decode_stacks']} have a visible Impl.decode ancestor and {record['excluded_samples']} are excluded, not assumed to be preparation. Unknown frames appear in {record['unknown_frame_stacks']} stacks, with {record['unknown_decode_leaf_samples']} included unknown leaves. Both retained reports explicitly state zero lost samples. Conditional shares can be biased by inlining, tail calls and unwinding. Eager immutable table startup, including the complete power-of-two table, is outside the visible decode subset; scalar first-use constants may remain inside. No table-hit frequency or throughput effect is inferred from samples.
''')
write(P/'artifact-hashes.json',{'status':'passed','files':{str(p.relative_to(P)):sha(p) for p in sorted(P.rglob('*')) if p.is_file()}})
print(json.dumps({k:record[k] for k in ['status','samples','included_decode_stacks','excluded_samples','unknown_frame_stacks','unknown_decode_leaf_samples','captured_input_hash_count']}))

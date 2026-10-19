#!/usr/bin/env python3
"""Replay the compact exact-rational input set and verify recorded probe bindings."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
from fractions import Fraction
from collections import Counter
import gzip,hashlib,json,struct,math
G=Path('tests/evidence/optimization/gen18');P=G/'runtime-review/probe';R=G/'fresh/independent-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def load(p):return json.loads(Path(p).read_text())
m=load(P/'inputs.json');c=load(P/'completion.json');e=load(P/'attempt-01/execution.json');seed=load(P/'seed.json')
assert c['status']==e['status']=='passed' and e['exit_code']==0 and c['summary']['mismatches']==0
for p,h in c['files'].items():assert sha(p)==h,p
assert sha(P/'inputs.json')==c['input_manifest_sha256']==e['inputs_manifest_sha256']
assert sha(P/'seed.json')==m['seed_record_sha256'] and sha(P/'prepare_inputs.py')==m['generator_sha256']==seed['generator_source_sha256']
assert sha(m['probe_source'])==m['probe_source_sha256']==c['source_sha256']==e['source_sha256']
assert e['held_inputs_before']==e['held_inputs_after'] and len(e['held_inputs_before'])==194
for p,h in e['held_inputs_before'].items():assert sha(p)==h,p
assert e['integration_sha256']==sha(G/'integration/targeted-build.json')
assert seed['recorded_utc']<m['recorded_utc']<e['started_utc']<e['finished_utc']<c['recorded_utc']
assert e['started_monotonic_ns']<e['finished_monotonic_ns']
assert (P/'attempt-01/failures.jsonl').read_bytes()==(P/'attempt-01/stderr.log').read_bytes()==b''
stdout=(P/'attempt-01/stdout.log').read_text()
json_lines=[line for line in stdout.splitlines() if line.startswith('{')]
assert len(json_lines)==1 and json.loads(json_lines[0])==c['summary']
assert stdout.count('warning:')==2 and 'error:' not in stdout
raw=gzip.decompress(Path(m['retained_path']).read_bytes());assert sha(m['retained_path'])==m['compressed_sha256'] and hashlib.sha256(raw).hexdigest()==m['raw_sha256'] and len(raw)==m['raw_bytes']
classes=Counter();branches=Counter();edges=set();finite_count=0;fnv=14695981039346656037;random_expected=[];x=seed['seed']
while len(random_expected)<8192:
 x=(6364136223846793005*x+1442695040888963407)&((1<<64)-1)
 if ((x>>52)&2047)!=2047:random_expected.append(x)
for line in raw.decode().splitlines():
 label,nstr,dstr,bstr,branch=line.split('\t');n,d=int(nstr),int(dstr);q=Fraction(n,d);assert d>0 and (n,d)==(q.numerator,q.denominator)
 k=d.bit_length()-1;got='zero' if n==0 else 'fast' if abs(n)<2**53 and k<=1074 and d==2**k else 'fallback';assert got==branch
 category=label.split(':')[0];classes[category]+=1;branches[got]+=1
 if bstr!='-':
  bits=int(bstr);sign=bits>>63;exp=(bits>>52)&2047;fraction=bits&((1<<52)-1);assert exp!=2047 and bits<1<<64
  significand=fraction if exp==0 else (1<<52)+fraction;power=-1074 if exp==0 else exp-1075
  exact=Fraction(significand*(1<<max(power,0)),1<<max(-power,0));exact=-exact if sign else exact;assert q==exact
  if category=='exponent-boundary':edges.add((exp,sign,fraction))
  if category=='seeded-finite':assert bits==random_expected[int(label.split(':')[1])]
  finite_count+=1
 try:value=float(q)
 except OverflowError:value=-math.inf if n<0 else math.inf
 bits=struct.unpack('>Q',struct.pack('>d',value))[0] if value!=0 else 0
 if bstr!='-':assert bits==(int(bstr) if q!=0 else 0)
 output=f'{label}\t{nstr}\t{dstr}\t{bits}\t{bits}\n'.encode()
 for byte in output:fnv=((fnv^byte)*1099511628211)&((1<<64)-1)
assert edges=={(e,s,f) for e in range(2047) for s in [0,1] for f in [0,1,(1<<51)-1,1<<51,(1<<52)-2,(1<<52)-1]}
assert dict(classes)==m['classes'] and dict(branches)==m['expected_branches']
assert sum(classes.values())==m['cases']==c['summary']['cases']==33174 and finite_count==m['finite_bit_checks']==c['summary']['finite_bit_checks']==32756
assert fnv==c['summary']['output_fnv1a64_decimal']
for key in ['zero','fast','fallback']:assert branches[key]==c['summary'][key+'_cases']
out={'status':'passed_read_only_probe_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'script_sha256':sha(__file__),'bindings':{str(p):sha(p) for p in [P/'completion.json',P/'inputs.json',P/'seed.json',P/'prepare_inputs.py',P/'inputs.tsv.gz',P/'attempt-01/execution.json',P/'attempt-01/stdout.log',Path(m['probe_source'])]},'cases':33174,'finite_checks':32756,'branches':dict(branches),'classes':dict(classes),'independently_recomputed_output_fnv1a64':fnv,'all_finite_exponent_sign_endpoint_combinations':24564,'seeded_finite_patterns_replayed':8192,'held_inputs_rehashed':194,'reviewer_attempts':[{'log':'probe-review-01.log','status':'failed_reviewer_stdout_schema','reason':'Lean emitted two constructor-name linter warnings before the JSON record; prior checker incorrectly parsed entire stdout as JSON.'},{'log':'probe-review-02.log','status':'passed'}],'findings':[],'limits':['Recorded Lean --run probe compares live toFloat against its original fallback; this review does not rerun either decoder.','Python Fraction-to-float conversion independently reproduced the full recorded aggregate output digest, with rational zero canonicalized to positive zero. This is supplemental test evidence, not a replacement for the kernel theorem.','No corpus fast-path hit rate or timing inference.']}
p=R/'probe-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':out['status'],'sha256':sha(p),'cases':33174,'fnv':fnv}))

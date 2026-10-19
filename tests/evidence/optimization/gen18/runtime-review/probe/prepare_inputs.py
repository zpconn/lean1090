#!/usr/bin/env python3
"""Record seed before generating compact exact integer/rational probe inputs."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
from fractions import Fraction
from collections import Counter
import gzip,hashlib,json,secrets
P=Path('tests/evidence/optimization/gen18/runtime-review/probe');C=Path('.cache/gen18-float-probe')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def write(p,j):
 assert not p.exists();p.write_text(json.dumps(j,indent=2)+'\n')
assert not (P/'seed.json').exists() and not C.exists()
seed=secrets.randbits(64)
write(P/'seed.json',{'recorded_utc':datetime.now(timezone.utc).isoformat(),'seed':seed,'sampling':'secrets.randbits(64), recorded before generating any cases','random_finite_patterns':8192,'generator':'UInt64 LCG x := 6364136223846793005*x + 1442695040888963407 modulo 2^64; reject exponent field 2047','generator_source_sha256':sha(__file__)})
C.mkdir();rows=[];classes=Counter();branches=Counter();exponents=set();signs=set()
def add(label,value,bits=None):
 n,d=value.numerator,value.denominator;k=d.bit_length()-1
 branch='zero' if n==0 else 'fast' if abs(n)<2**53 and k<=1074 and d==1<<k else 'fallback'
 rows.append(f'{label}\t{n}\t{d}\t{bits if bits is not None else "-"}\t{branch}\n');classes[label.split(':')[0]]+=1;branches[branch]+=1

def finite(label,bits):
 sign,e,f=bits>>63,(bits>>52)&2047,bits&((1<<52)-1);assert e!=2047
 n=f if e==0 else (1<<52)+f;power=-1074 if e==0 else e-1075
 q=Fraction(n*(1<<max(power,0)),1<<max(-power,0));q=-q if sign else q
 add(label,q,bits);exponents.add(e);signs.add(sign)
for e in range(2047):
 for sign in [0,1]:
  for f in [0,1,(1<<51)-1,1<<51,(1<<52)-2,(1<<52)-1]:
   finite(f'exponent-boundary:{e}:{sign}:{f}',(sign<<63)|(e<<52)|f)
x=seed;generated=0
while generated<8192:
 x=(6364136223846793005*x+1442695040888963407)&((1<<64)-1)
 if (x>>52)&2047==2047:continue
 finite(f'seeded-finite:{generated}',x);generated+=1
for n in [0,1,2,3,5,7,(1<<52)-1,1<<52,(1<<52)+1,(1<<53)-1,1<<53,(1<<53)+1,(1<<54)-1]:
 for k in [0,1,2,52,53,1021,1022,1023,1073,1074,1075,1076,1100]:
  for sign in [1,-1]:add(f'dyadic-boundary:{n}:{k}:{sign}',Fraction(sign*n,1<<k))
for n in [1,2,5,(1<<53)-1,1<<53,(1<<53)+1,(1<<1024)-1,1<<1024]:
 for d in [3,5,7,10,11]:
  for sign in [1,-1]:add(f'nondyadic-or-wide:{n}:{d}:{sign}',Fraction(sign*n,d))
raw=''.join(rows).encode();plain=C/'inputs.tsv';plain.write_bytes(raw)
target=P/'inputs.tsv.gz';assert not target.exists()
with target.open('xb') as stream:
 with gzip.GzipFile(filename='',mode='wb',fileobj=stream,mtime=0) as z:z.write(raw)
assert gzip.decompress(target.read_bytes())==raw
write(P/'inputs.json',{'status':'prepared_not_executed','recorded_utc':datetime.now(timezone.utc).isoformat(),'seed_record_sha256':sha(P/'seed.json'),'generator_sha256':sha(__file__),'probe_source':'review/diagnostics/Gen18FloatProbe.lean','probe_source_sha256':sha('review/diagnostics/Gen18FloatProbe.lean'),'raw_path':str(plain),'raw_sha256':hashlib.sha256(raw).hexdigest(),'raw_bytes':len(raw),'retained_path':str(target),'compressed_sha256':sha(target),'cases':len(rows),'classes':dict(classes),'expected_branches':dict(branches),'finite_exponent_fields':len(exponents),'finite_signs':sorted(signs),'finite_bit_checks':classes['exponent-boundary']+classes['seeded-finite'],'coverage':'Every finite exponent field 0..2046, both signs, six significand endpoints; independent seeded finite patterns; exact normal/subnormal and 2^53 guard boundaries; k>1074 underflow/ties; nondyadic and huge numerator fallback. Rat canonicalization defines the guard. Negative zero expected to canonicalize to +0.','no_native_execution':True})
print(json.dumps({'status':'prepared_not_executed','cases':len(rows),'classes':dict(classes),'expected_branches':dict(branches),'inputs_manifest_sha256':sha(P/'inputs.json')}))

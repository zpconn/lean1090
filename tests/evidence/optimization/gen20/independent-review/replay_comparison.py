#!/usr/bin/env python3
"""Replay only frozen comparison functions over sealed gzip data, no decoders."""
import os,sys
sys.dont_write_bytecode=True
os.environ['PYTHONDONTWRITEBYTECODE']='1'
from pathlib import Path
from datetime import datetime,timezone
import gzip,hashlib,importlib.util,json,tempfile,time,traceback
P=Path('tests/evidence/optimization/gen20');Q=P/'fresh-message';R=P/'independent-review'
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(1<<20),b''):h.update(b)
 return h.hexdigest()
def raw(p):
 h=hashlib.sha256();size=lines=0
 with gzip.open(p,'rb') as f:
  for b in iter(lambda:f.read(1<<20),b''):h.update(b);size+=len(b);lines+=b.count(b'\n')
 return {'sha256':h.hexdigest(),'bytes':size,'rows':lines}
class GzipInput:
 def __init__(self,path):self.path=path
 def open(self,**kwargs):return gzip.open(self.path,'rt',**kwargs)
manifest=json.loads((P/'fresh-retained-hashes.json').read_text());summary=json.loads((Q/'summary.json').read_text());pre=json.loads((P/'fresh-preflight.json').read_text())
assert manifest['status']=='passed' and summary['status']=='PASS'
for path,row in manifest['files'].items():assert sha(path)==row['sha256']
for group in ['source_sha256','binary_sha256']:
 for p,h in pre[group].items():assert sha(p)==h
source=Path('scripts/check_message_differential.py');assert sha(source)==summary['source_sha256'][str(source)]
module_spec=importlib.util.spec_from_file_location('frozen_comparison_replay',source);module=importlib.util.module_from_spec(module_spec);module_spec.loader.exec_module(module)
# The guarded CLI main is never invoked: no build, generation or decoder run.
assert module.LOG==[]
cache=Path(tempfile.mkdtemp(prefix='gen20-comparison-replay-',dir='.cache'))
record={'status':'running','started_utc':datetime.now(timezone.utc).isoformat(),'started_monotonic_ns':time.monotonic_ns(),'comparison_source_sha256':sha(source),'retention_manifest_sha256':sha(P/'fresh-retained-hashes.json'),'summary_sha256':sha(Q/'summary.json'),'temporary_output':str(cache),'native_execution':False}
def write():(R/'comparison-replay.json').write_text(json.dumps(record,indent=2)+'\n')
assert not (R/'comparison-replay.json').exists();write()
try:
 message=module.compare_messages(GzipInput(Q/'metadata.jsonl.gz'),GzipInput(Q/'lean.jsonl.gz'),GzipInput(Q/'oracle.jsonl.gz'),cache,summary['message']['counts']['messages'])
 boundaries=module.load_boundaries(GzipInput(Q/'fresh-commb.csv.gz'))
 direct=module.compare_direct(boundaries,GzipInput(Q/'direct-lean.jsonl.gz'),GzipInput(Q/'direct-oracle.jsonl.gz'),cache,message['commb'])
 for register,values in message['commb'].items():
  if not values['direct_inputs'] or not values['direct_lean_accepted'] or not values['direct_oracle_accepted']:message['coverage_errors'].append(f'missing accepted direct Comm-B register {register}')
 assert message==summary['message'] and direct==summary['direct_registers'] and not module.LOG
 streams={}
 for name in ['mismatches.jsonl.gz','standard-differences.jsonl.gz','direct-mismatches.jsonl.gz']:
  got=raw(cache/name);expected=raw(Q/name);assert got==expected,name
  streams[name]={'decompressed':got,'retained_sha256':sha(Q/name),'replay_compressed_sha256':sha(cache/name)}
 for group in ['source_sha256','binary_sha256']:
  for p,h in pre[group].items():assert sha(p)==h
 assert sha(P/'fresh-retained-hashes.json')==record['retention_manifest_sha256']
 record.update(status='passed',finished_utc=datetime.now(timezone.utc).isoformat(),finished_monotonic_ns=time.monotonic_ns(),message_counts=message['counts'],direct_counts=direct['counts'],full_coverage_and_counts_equal=True,streams=streams,all_sources_and_binaries_unchanged=True,comparison_source_sha256_after=sha(source),temporary_outputs_verified_duplicate=True);write()
 # Only the three newly created replay outputs are removed after byte-exact
 # decompressed equality and durable retained receipt; unique failures stay.
 with (R/'comparison-replay.json').open('rb') as f:os.fsync(f.fileno())
 fd=os.open(R,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
 assert {x.name for x in cache.iterdir()}==set(streams)
 for name,info in streams.items():assert sha(cache/name)==info['replay_compressed_sha256'];(cache/name).unlink()
 cache.rmdir();record['temporary_duplicate_outputs_removed']=True;write();print(json.dumps(record,indent=2))
except BaseException as e:
 record.update(status='failed',error=repr(e),traceback=traceback.format_exc(),temporary_outputs_preserved=True);write();raise

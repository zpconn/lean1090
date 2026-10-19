#!/usr/bin/env python3
"""Bind root-authorized stable sources/binaries before the fresh campaign."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,importlib.util,json,subprocess
R=Path.cwd();P=R/'tests/evidence/optimization/gen18/fresh';G=P.parent
load=lambda p:json.loads(Path(p).read_text())
def sha(p):
 with Path(p).open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def rel(p):return str(p.relative_to(R))
assert not (P/'fresh-preflight.json').exists()
build=load(G/'integration/targeted-build.json');assert build['status']=='passed' and build['exit_code']==0
spec=importlib.util.spec_from_file_location('fresh_gate_inventory',R/'review/diagnostics/run_generation_benchmark.py');module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
gate=module.gate_input_hashes();assert len(gate)==190 and gate==build['all_inputs_before']==build['all_inputs_after']
prep=load(P/'preparation.json');review=load(P/'independent-review/preparation-review.json');assert review['status']=='passed_read_only_preparation_review' and not review['findings']
for name,digest in review['bindings'].items():assert sha(R/name)==digest,name
names=set(load(R/'tests/evidence/optimization/gen17/fresh-message-run.json')['source_sha256_before'])
for folder in ['Impl','Model','Spec','Proofs','CLI','Tests']:names.update(rel(p) for p in (R/folder).rglob('*.lean'))
names.update(['lakefile.toml','lake-manifest.json','lean-toolchain','Capstones.lean']);assert len(names)==115
sources={name:sha(R/name) for name in sorted(names)}
binaries={'.lake/build/bin/'+name:sha(R/'.lake/build/bin'/name) for name in ['lean1090','messageGenerator','commbDifferential']}
for name,digest in binaries.items():assert digest==build['binary_hashes'][Path(name).name]
probe=G/'runtime-review/probe/completion.json';assert load(probe)['status']=='passed'
helpers={name:row['sha256'] for name,row in prep['helpers'].items()}
for name,digest in helpers.items():assert sha(R/name)==digest,name
ignore=P/'.gitignore';assert '/fresh-message/*.gz' in ignore.read_text().splitlines()
subprocess.run(['git','check-ignore','-q',str((P/'fresh-message/input.hex.gz').relative_to(R))],check=True)
helpers[rel(ignore)]=sha(ignore)
assert not list((P/'fresh-message').glob('*')) and not (P/'fresh-execution.json').exists()
cache=R/'.cache/gen18-gate';assert cache.is_dir() and not any(cache.iterdir())
record={'status':'passed','authorized_by':'/root','authorization':'Root explicit release after combined integration passed and boundary probe/preparation review passed; held sources and current three binaries, no rebuild.','recorded_utc':datetime.now(timezone.utc).isoformat(),'seed_record_sha256':sha(P/'fresh-seeds.json'),'source_count':len(sources),'source_sha256':sources,'binary_sha256':binaries,'helpers':helpers,'integrated_build_record_sha256':sha(G/'integration/targeted-build.json'),'integrated_build_log_sha256':sha(G/'integration/targeted-build.log'),'gate_input_count':len(gate),'gate_inputs':gate,'probe_completion_sha256':sha(probe),'independent_preparation_review_sha256':sha(P/'independent-review/preparation-review.json'),'scoped_transcript_ignore_sha256':sha(ignore),'preparer_sha256':sha(__file__)}
(P/'fresh-preflight.json').write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':'passed','sources':len(sources),'binaries':len(binaries),'gate_inputs':len(gate),'sha256':sha(P/'fresh-preflight.json')}))

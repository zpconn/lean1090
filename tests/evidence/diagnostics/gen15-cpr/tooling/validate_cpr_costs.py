#!/usr/bin/env python3
"""Untimed exact input, full-message, position and state checks for CPRCosts."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import argparse,gzip,hashlib,json,subprocess
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
 buildpath=ROOT/a.build;build=json.loads(buildpath.read_text());out=ROOT/a.output
 assert not out.exists();out.mkdir(parents=True)
 protected=dict(build['unchanged_native_inputs']);protected.update(build['artifacts']);before={n:sha(ROOT/n) for n in protected};assert before==protected
 binary=next(ROOT/n for n in build['artifacts'] if n.endswith('/cpr-costs'));worker=ROOT/'.lake/build/bin/lean1090-bench';corpus=ROOT/'vendor/rs1090/crates/rs1090/data/long_flight.csv'
 hashes={'worker':sha(worker),'corpus':sha(corpus),'airports':sha(ROOT/'vendor/rs1090/crates/rs1090/data/airports.json')};commands=[]
 def run(label,argv):
  started=datetime.now(timezone.utc).isoformat()
  with (out/(label+'.stdout')).open('w') as stdout,(out/(label+'.stderr')).open('w') as stderr:r=subprocess.run([str(x) for x in argv],cwd=ROOT,stdout=stdout,stderr=stderr)
  commands.append({'label':label,'argv':[str(x) for x in argv],'exit_code':r.returncode,'started_utc':started,'finished_utc':datetime.now(timezone.utc).isoformat()});(out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');assert r.returncode==0,label
 run('driver-tracking',[binary,'all',corpus,'--audit',out/'driver-tracking.jsonl'])
 run('worker-tracking',[worker,'--audit-tracking',corpus])
 comparisons=[]
 for mode in ['inputs','airports']:
  run('driver-'+mode,[binary,'--audit-'+mode,corpus]);run('worker-'+mode,[worker,'--audit-'+mode,corpus])
  x=out/('driver-'+mode+'.stdout');y=out/('worker-'+mode+'.stdout');assert x.read_bytes()==y.read_bytes();comparisons.append({'kind':mode,'lines':len(x.read_bytes().splitlines()),'sha256':sha(x),'exact_bytes':True})
 driver=out/'driver-tracking.jsonl';oracle=out/'worker-tracking.stdout';assert driver.read_bytes()==oracle.read_bytes()
 rows=[json.loads(s) for s in driver.read_text().splitlines()];assert len(rows)==172433 and rows[-1]['final'] is True
 assert [r['id'] for r in rows[:-1]]==list(range(172432))
 markers=[json.loads(s) for s in (out/'driver-tracking.stdout').read_text().splitlines()];assert [r['phase'] for r in markers]==['prepared','decoded','result'];result=markers[-1]
 assert result['digest']['count']==172432 and result['positions']==sum(r['position'] is not None for r in rows[:-1])==11347 and result['final_state']==rows[-1] and result['batch_state_check']
 after={n:sha(ROOT/n) for n in protected};assert after==before
 assert sha(worker)==hashes['worker'] and sha(corpus)==hashes['corpus']
 summary={'status':'passed','kind':'untimed live CPR workload validation','build':str(buildpath.relative_to(ROOT)),'build_sha256':sha(buildpath),'inputs_before':before,'inputs_after':after,'all_inputs_unchanged':True,'worker_and_inputs':hashes,'comparisons':comparisons,'tracking_rows':172432,'tracking_bit_identical':172432,'resolved_positions':result['positions'],'final_state_projection_exact':True,'complete_batch_StreamState_and_routed_positions_equal':True,'result':result,'commands':commands,'artifacts':{str(x.relative_to(out)):{'sha256':sha(x),'bytes':x.stat().st_size} for x in sorted(out.iterdir()) if x.is_file()}}
 (out/'summary.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps({'status':'passed','tracking_rows':172432,'positions':result['positions'],'result':result}))
if __name__=='__main__':main()

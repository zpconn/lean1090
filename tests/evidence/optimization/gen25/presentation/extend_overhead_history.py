#!/usr/bin/env python3
"""Append reviewed generation 25; preserve the exact prior structured rows."""
import sys
sys.dont_write_bytecode=True
import csv, hashlib, json, statistics, subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[5]
OUT=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'review/diagnostics'))
import archive_generation_benchmark_target as archive
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
jsonpath=ROOT/'bench/cpr-overhead.json'; mdpath=ROOT/'bench/CPR-OVERHEAD.md'
assert not (OUT/'overhead-extension.json').exists()
old=json.loads(jsonpath.read_text());oldmd=mdpath.read_text()
assert [r['generation'] for r in old['generations']]==list(range(25))
before={str(p.relative_to(ROOT)):sha(p) for p in [jsonpath,mdpath]}
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip()
for path,digest in before.items():
 assert hashlib.sha256(subprocess.check_output(['git','show',commit+':'+path],cwd=ROOT)).hexdigest()==digest
for name,digest in old['source_sha256'].items():assert sha(ROOT/name)==digest
records=list(old['generations']);sources=dict(old['source_sha256']);review_bindings={}
for generation in range(25,26):
 base=ROOT/f'bench/runs/gen{generation}';summary=json.loads((base/'summary.json').read_text())
 review=json.loads((base/'results-review.json').read_text());report=json.loads((base/'report-verification.json').read_text())
 assert review['status']=='passed' and not review['findings'] and review['commit']==summary['commit']
 bymode={r['mode']:r for r in summary['results']};assert set(bymode)=={'decode','cpr'}
 for mode in ('decode','cpr'):
  p=base/mode/'samples.csv';rows=list(csv.DictReader(p.open()));assert len(rows)==48
  assert all(int(r['messages'])==172432 for r in rows)
  assert sha(p)==bymode[mode]['samples_sha256']
  for impl in ('lean1090','rs1090'):
   warm=[r for r in rows if r['implementation']==impl and r['phase']=='warmup']
   values=[int(r['nanoseconds']) for r in rows if r['implementation']==impl and r['phase']=='measured']
   assert len(warm)==3 and len(values)==21
   assert sorted(values)[10]==bymode[mode]['medians_nanoseconds'][impl]
  sources[str(p.relative_to(ROOT))]=sha(p)
 overhead=archive.cpr_overhead(summary['results']);assert overhead==report['cpr_overhead']==review['cpr_overhead']
 p=base/'summary.json';sources[str(p.relative_to(ROOT))]=sha(p)
 records.append({'generation':generation,'recorded_commit':summary['commit'],'summary':str(p.relative_to(ROOT)),'summary_sha256':sha(p),'overhead':overhead})
 for p in [base/'results-review.json',base/'report-verification.json']:review_bindings[str(p.relative_to(ROOT))]=sha(p)
assert records[:25]==old['generations']
for path,digest in sources.items():assert sha(ROOT/path)==digest
head=oldmd.split('| [0](BASELINE.md)',1)[0]
lines=[head.rstrip()]
for row in records:
 g=row['generation'];values=row['overhead']['implementations'];lean=values['lean1090'];rust=values['rs1090'];link='BASELINE.md' if g==0 else f'GEN{g}.md'
 lines.append(f"| [{g}]({link}) | {lean['median_nanoseconds']['decode']/172432000:.9f} | {lean['median_nanoseconds']['cpr']/172432000:.9f} | {lean['microseconds_per_message']:.9f} | {rust['microseconds_per_message']:.9f} |")
assert all(line in oldmd for line in lines[1:26])
lines.extend(['','All 104 implementation/mode medians were independently recomputed from 21 measured samples apiece, after the three warmups. Generations 0–24 retain the original reviewed values; generation 25 extends them from reviewed raw samples. [Structured values and exact integer differences](cpr-overhead.json) retain source hashes and the original recorded commit IDs. Historical attribution is documented in [the commit mapping](../docs/COMMIT-ATTRIBUTION.md).',''])
jsonpath.write_text(json.dumps({'schema':1,'generations':records,'source_sha256':sources},indent=2)+'\n')
mdpath.write_text('\n'.join(lines))
record={'status':'passed','source_commit':commit,'before_sha256':before,'outputs':{str(p.relative_to(ROOT)):sha(p) for p in [jsonpath,mdpath]},'preserved_generation_count':25,'appended_generations':list(range(25,26)),'new_raw_samples_checked':96,'new_medians_recomputed':4,'prior_structured_rows_and_displayed_rows_preserved':True,'source_sha256':sources,'result_review_bindings':review_bindings,'helper_sha256':sha(ROOT/'review/diagnostics/archive_generation_benchmark_target.py'),'script_sha256':sha(__file__),'sealed_reports_and_samples_unchanged':True,'no_measurement_or_build_executed':True}
with (OUT/'overhead-extension.json').open('x') as f:json.dump(record,f,indent=2);f.write('\n')
print(json.dumps({'status':'passed','sha256':sha(OUT/'overhead-extension.json'),'appended_generations':list(range(25,26))}))

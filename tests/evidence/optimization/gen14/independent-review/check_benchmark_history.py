import os, sys
sys.dont_write_bytecode=True
os.environ["PYTHONDONTWRITEBYTECODE"]="1"
"""Add byte-for-byte prior-history checks to the new gen14 review only."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,subprocess
E=Path('tests/evidence/optimization/gen14/independent-review');review=Path('bench/runs/gen14/results-review.json')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
x=json.loads(review.read_text());assert 'historical_artifact_review' not in x
assert sha(review)==(E/'benchmark-review-01.log').read_text().splitlines()[0]
commit=x['timed_commit'];roots=['bench/runs/baseline-FC006','bench/BASELINE.md']+[f'bench/runs/gen{g}' for g in range(1,14)]+[f'bench/GEN{g}.md' for g in range(1,14)]+[f'tests/evidence/diagnostics/gen{g}' for g in range(14)]+[f'docs/GEN{g}-COST-BREAKDOWN.md' for g in range(14)]
current=subprocess.check_output(['git','ls-files','--',*roots],text=True).splitlines()
tracked=subprocess.check_output(['git','ls-tree','-r','--name-only',commit,'--',*roots],text=True).splitlines()
assert current==tracked
assert not subprocess.check_output(['git','ls-files','--others','--exclude-standard','--',*roots]).strip()
proc=subprocess.Popen(['git','cat-file','--batch'],stdin=subprocess.PIPE,stdout=subprocess.PIPE)
count=0;total=0
for path in tracked:
 proc.stdin.write((commit+':'+path+'\n').encode());proc.stdin.flush()
 header=proc.stdout.readline().decode().split();assert len(header)==3 and header[1]=='blob',path
 size=int(header[2]);expected=proc.stdout.read(size);assert proc.stdout.read(1)==b'\n'
 actual=Path(path).read_bytes();assert actual==expected,path
 count+=1;total+=size
proc.stdin.close();assert proc.wait()==0
records={}
for g in range(14):
 p=Path(f'tests/evidence/diagnostics/gen{g}/perf/capture.json');cap=json.loads(p.read_text());raw=cap['raw_data'];assert sha(raw['path'])==raw['sha256'] and Path(raw['path']).stat().st_size==raw['bytes'];records[str(p)]=raw['sha256']
historical_manifest=Path('tests/evidence/diagnostics/gen13/historical-inputs.json')
old=json.loads(historical_manifest.read_text())
assert len(old['files'])==10414
for path,item in old['files'].items():
 if path=='bench/results.csv':
  prefix=E/'results-prefix-before-gen14.csv'
  assert sha(prefix)==item['sha256'] and prefix.stat().st_size==item['bytes']
  assert Path(path).read_bytes().startswith(prefix.read_bytes())
 else:assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
x['historical_manifest_recheck']={'manifest':str(historical_manifest),'sha256':sha(historical_manifest),'all_recorded_files':len(old['files']),'all_historical_bytes_including_ignored_caches_unchanged':True,'authorized_results_append':'Historical bench/results.csv is verified as the exact retained 28-row byte prefix; the primary review verifies precisely the two appended rows.'}
x['historical_artifact_review']={'status':'passed','checked_utc':datetime.now(timezone.utc).isoformat(),'committed_files':count,'committed_bytes':total,'roots':roots,'exact_bytes_equal_timed_commit':True,'tracked_and_untracked_membership_unchanged':True,'prior_raw_perf_hashes':records,'checker':str(Path(__file__)),'checker_sha256':sha(__file__)}
review.write_text(json.dumps(x,indent=2)+'\n')
print(json.dumps({'historical_files':count,'historical_bytes':total,'prior_raw_perf_files':len(records),'results_review_sha256':sha(review)},indent=2))

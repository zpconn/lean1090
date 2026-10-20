#!/usr/bin/env python3
"""Read only source/diff check; no controller import or execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,difflib,hashlib,json,subprocess
E=Path('tests/evidence/optimization/gen25/presentation');P=Path('tests/evidence/optimization/gen24/presentation')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
checks=[];bindings={}
def check(label,condition):
 assert condition,label
 checks.append(label)
for name in ['run_refresh.py','check_presentation.py','seal_presentation.py','extend_overhead_history.py']:
 old=(P/name).read_text();new=(E/name).read_text();ast.parse(new)
 check('syntax '+name,True)
 check('exact diff '+name,(E/(name+'.diff')).read_text()==''.join(difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile=str(P/name),tofile=str(E/name))))
 for p in [P/name,E/name,E/(name+'.diff')]:bindings[str(p)]=sha(p)
check('local packaging checker unchanged',(P/'check_presentation.py').read_bytes()==(E/'check_presentation.py').read_bytes())
s=(E/'run_refresh.py').read_text();t=(E/'seal_presentation.py').read_text();h=(E/'extend_overhead_history.py').read_text()
for label,condition in [
 ('actual reviewed results required',"args.expected_review_sha256" in s and "review['status'] == 'passed' and not review['findings']" in s),
 ('exact integer target decisions',"medians['rs1090'] >= 2 * medians['lean1090']" in s and "review['all_mode_thresholds_reached'] is all(reached.values())" in s),
 ('signed overhead and noise preserved',"cpr_ns - decode_ns" in s and "includes measurement noise" in s),
 ('all capstones unchanged',"read_text().split('<!-- CAPSTONES:BEGIN -->', 1)[1] == capstones" in s),
 ('current exact shape',"len(rows) == 52" in s and "verification['frames'] == 26" in t and "verification['plotted_values_checked'] == 1404" in t),
 ('no optional CLI workload enabled',"'--check-cli'" not in s),
 ('old overhead rows retained',"records[:25]==old['generations']" in h and "all(line in oldmd for line in lines[1:26])" in h),
 ('only generation 25 appended',"for generation in range(25,26):" in h and "'new_raw_samples_checked':96" in h and "'new_medians_recomputed':4" in h),
 ('raw sample median guards retained',"len(warm)==3 and len(values)==21" in h and "sorted(values)[10]==bymode[mode]['medians_nanoseconds'][impl]" in h),
 ('no benchmark overwrite or repeat command',all(token not in s+h for token in ['interleave.py','lake build','check_all.sh']))]:check(label,condition)
for name in ['review/presentation/render_throughput.py','review/presentation/verify_throughput.py','review/packaging/check_presentation.py','review/diagnostics/archive_generation_benchmark_target.py']:
 check('generic helper unchanged '+name,subprocess.check_output(['git','show','HEAD:'+name])==Path(name).read_bytes());bindings[name]=sha(name)
bindings[str(Path(__file__))]=sha(__file__)
out={'status':'passed','checked_utc':datetime.now(timezone.utc).isoformat(),'checks':checks,'check_count':len(checks),'findings':[],'bindings':bindings,'assessment':['Generation/path/count adaptation only for refresh/seal; unchanged local checker and generic rendering. Target status derives from exact medians without assuming success.','Overhead extension preserves every structured/displayed generation 0–24 and appends only generation 25 from its 96 recorded samples and four independent medians.','No producer controller, renderer, benchmark, native worker, proof or profiler executed by this source review. Completed presentation and manual visual review remain separate.']}
p=E/'adapter-review.json';assert not p.exists();p.write_text(json.dumps(out,indent=2)+'\n');print(json.dumps({'status':'passed','checks':len(checks),'sha256':sha(p)}))

import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,importlib.util,json,shutil,subprocess
root=Path.cwd();out=root/'tests/evidence/optimization/gen15/attempt-01-interrupted-for-cleanup'
cache=root/'.cache/gen15-interrupted-gate'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
assert not (out/'interruption.json').exists() and not cache.exists()
spec=importlib.util.spec_from_file_location('archive',root/'review/diagnostics/archive_generation_gate.py');a=importlib.util.module_from_spec(spec);spec.loader.exec_module(a)
runner,components,status=a.discover_components()
g=root/'tests/evidence/optimization/gen15/gate-evidence.json';old=json.loads(g.read_text())
assert old['status']=='running'
assert a.provenance_helper().gate_input_hashes()==old['input_hashes_before']
paths=[('component-'+name,folder) for name,_,folder,_ in components]
paths.append(('unit-tests',root/'tests/evidence/upstream-unit-tests'))
files=[]
for label,folder in paths:
 for p in sorted(folder.rglob('*')):
  assert not p.is_symlink()
  if not p.is_file():continue
  t=cache/label/p.relative_to(folder);t.parent.mkdir(parents=True,exist_ok=True)
  before=sha(p);shutil.copyfile(p,t);assert sha(t)==before==sha(p)
  files.append({'original':str(p.relative_to(root)),'retained':str(t.relative_to(root)),'bytes':p.stat().st_size,'sha256':before})
for name in ['gate-evidence.json','gate-full.log','run_full_gate.py']:
 p=out.parent/name;t=out/name;shutil.copyfile(p,t);assert sha(p)==sha(t)
shutil.copyfile(status,out/'components.tsv')
record={'status':'interrupted_not_passed','recorded_utc':datetime.now(timezone.utc).isoformat(),'reason':'User requested a pause for disk cleanup. The gate was suspended with SIGSTOP. On explicit user resume, the recorded process group no longer exists; no final completion was recorded. Restart the complete full gate.','old_process_group':1126929,'host_process_probe_exit_code':1,'old_gate_record_sha256':sha(out/'gate-evidence.json'),'old_gate_log_sha256':sha(out/'gate-full.log'),'gate_inputs_unchanged':True,'input_count':len(old['input_hashes_before']),'snapshot_caveat':'Generic output directories are preserved as found; incomplete component output may coexist with prior-run files. This snapshot is not a passing campaign.','copied_files':files,'protected_raw_working_directory':'.cache/message-differential-0gzplfih','cleanup_receipts':'tests/evidence/maintenance/disk-cleanup-20261019','current_df':subprocess.check_output(['df','-h','.', '/mnt/c'],text=True)}
(out/'interruption.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({'status':record['status'],'input_count':record['input_count'],'snapshot_files':len(files),'snapshot_bytes':sum(x['bytes'] for x in files),'record_sha256':sha(out/'interruption.json')}))

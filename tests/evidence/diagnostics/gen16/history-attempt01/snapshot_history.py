#!/usr/bin/env python3
"""Compact old-history binding; no copies or full rehash of archived transcripts."""
import sys
sys.dont_write_bytecode = True
from datetime import datetime, timezone
import hashlib,json,os,subprocess
from pathlib import Path
E=Path('tests/evidence/diagnostics/gen16')
ROOTS=['tests/evidence','bench','docs']
EXCLUDED=('tests/evidence/diagnostics/gen16/','tests/evidence/diagnostics/gen16-cpr/')
os.environ['GIT_OPTIONAL_LOCKS']='0'
def git(*args): return subprocess.check_output(['git',*args])
def identity(p):
 s=p.stat(); return dict(bytes=s.st_size,mtime_ns=s.st_mtime_ns,ctime_ns=s.st_ctime_ns,device=s.st_dev,inode=s.st_ino)
def inspect():
 commit=git('rev-parse','HEAD').decode().strip()
 subprocess.run(['git','diff','--exit-code',commit,'--',*ROOTS],check=True,stdout=subprocess.PIPE)
 inventory=git('ls-tree','-rz',commit,'--',*ROOTS)
 ignored=git('ls-files','-z','--others','--ignored','--exclude-standard','--',*ROOTS)
 untracked=git('ls-files','-z','--others','--exclude-standard','--',*ROOTS)
 paths={Path(p.decode()) for raw in (ignored,untracked) for p in raw.split(b'\0') if p and not p.decode().startswith(EXCLUDED)}
 identities={str(p):identity(p) for p in sorted(paths) if p.is_file()}
 assert all(not p.is_symlink() for p in paths)
 perf_paths=sorted(Path('.cache').glob('**/perf.data'))
 perf={str(p):identity(p) for p in perf_paths if 'gen16' not in str(p)}
 return {'commit':commit,'roots':ROOTS,'git_tree':git('rev-parse',commit+'^{tree}').decode().strip(),
  'committed_inventory_sha256':hashlib.sha256(inventory).hexdigest(),'committed_file_count':len(inventory.split(b'\0'))-1,
  'untracked_and_ignored_file_identities':identities,'retained_historical_perf_identities':perf}
def verify(record):
 current=inspect()
 assert current==record['binding'],'historical committed content or retained file identities changed'
 return current['committed_file_count']
if __name__=='__main__':
 out=E/'historical-inputs.json'; assert not out.exists()
 data={'kind':'compact_committed_history_and_retained_identity_binding','captured_utc':datetime.now(timezone.utc).isoformat(),
 'binding':inspect(),'limits':['Committed historical bytes are checked by git diff against the bound tree and inventory, without duplicating old artifacts.',
 'Ignored/untracked compressed transcripts and raw perf are held by exact filesystem identity, size and times during this campaign; their entire contents are not freshly rehashed here. Earlier sealed integrity reviews remain authoritative.',
 'Only the two concurrently created gen16 diagnostic evidence directories are excluded from untracked membership; current authorization prose outside these roots is not measured evidence.']}
 out.write_text(json.dumps(data,indent=2)+'\n')
 print(json.dumps({'status':'passed','committed_files':data['binding']['committed_file_count'],'ignored_or_untracked_files':len(data['binding']['untracked_and_ignored_file_identities']),'raw_perf_files':len(data['binding']['retained_historical_perf_identities']),'sha256':hashlib.sha256(out.read_bytes()).hexdigest()}))

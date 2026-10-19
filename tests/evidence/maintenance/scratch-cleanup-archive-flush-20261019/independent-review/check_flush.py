#!/usr/bin/env python3
import sys
sys.dont_write_bytecode=True
from pathlib import Path
import hashlib,json,os,tempfile
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'review/diagnostics'))
import cleanup_verified_scratch as clean
import finish_generation_gate as wrapper
checks=[]
with tempfile.TemporaryDirectory(prefix='lean1090-independent-flush-') as tmp:
 root=Path(tmp);base=root/'tests/evidence/optimization/gen2';archive=root/'.cache/gen2-gate/fixed-message-archive';fresh=base/'fresh-message';manifest=base/'gate-archive.json'
 paths=[manifest,archive/'input.hex.gz',base/'fixed-message/summary.json',base/'fixed-message/retained-archive.json',base/'components/altitude/summary.json',base/'components.tsv',fresh/'input.hex.gz',fresh/'summary.json',base/'fresh-retained-hashes.json']
 for i,p in enumerate(paths):p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(('fixture '+str(i)+'\n').encode())
 before={p:p.read_bytes() for p in paths}
 data={'components':{'message':{'retained_files':{'input':{'path':str((archive/'input.hex.gz').relative_to(root))}},'versioned_metadata':{'summary':{'path':str((base/'fixed-message/summary.json').relative_to(root))}}}}}
 events=[];real_file=wrapper.sync_file;real_dir=clean.sync_dir
 def file(p):real_file(p);events.append(('file',p))
 def directory(p):real_dir(p);events.append(('dir',p))
 with patch.object(clean,'ROOT',root),patch.object(wrapper,'sync_file',file),patch.object(clean,'sync_dir',directory):
  result=wrapper.flush_archives(manifest,data,[archive,fresh])
 assert {p for kind,p in events if kind=='file'}==set(paths)
 firstdir=next(i for i,x in enumerate(events) if x[0]=='dir');assert all(k=='file' for k,_ in events[:firstdir]) and all(k=='dir' for k,_ in events[firstdir:])
 dirs=[p for kind,p in events if kind=='dir'];assert [len(p.parts) for p in dirs]==sorted([len(p.parts) for p in dirs],reverse=True) and root in dirs
 assert before=={p:p.read_bytes() for p in paths}
 checks.append({'name':'all retained, selected fresh, sibling seal, metadata, status and directory links flushed in leaf-to-root order without content changes','status':'passed','files':len(paths),'directories':len(dirs)})
 with patch.object(clean,'ROOT',root):
  for kind in ('fifo','symlink','directory'):
   bad=root/('bad-'+kind)
   if kind=='fifo':os.mkfifo(bad)
   elif kind=='symlink':bad.symlink_to(paths[0])
   else:bad.mkdir()
   with patch.object(wrapper.os,'open') as opened:
    try:wrapper.sync_file(bad)
    except ValueError:pass
    else:raise AssertionError('nonregular opened')
    opened.assert_not_called()
   checks.append({'name':kind+' rejected before open','status':'passed'})
  p=root/'swap';p.write_bytes(b'old');old=root/'old';real_open=os.open
  def replacing_open(path,flags):
   assert flags & os.O_NOFOLLOW and flags & os.O_NONBLOCK
   p.rename(old);p.write_bytes(b'new');return real_open(path,flags)
  with patch.object(wrapper.os,'open',replacing_open):
   try:wrapper.sync_file(p)
   except ValueError as e:assert 'changed at open' in str(e)
   else:raise AssertionError('changed inode accepted')
  assert p.read_bytes()==b'new' and old.read_bytes()==b'old'
  checks.append({'name':'inode replacement between lstat and open is rejected with no-follow/nonblock flags','status':'passed'})
output={'status':'passed','independent_flush_cases':len(checks),'checks':checks,'scope':'Only disposable /tmp fixtures fsynced; no live archive or scratch operation.'}
p=Path(__file__).parent/'independent-flush-cases.json';assert not p.exists();p.write_text(json.dumps(output,indent=2)+'\n');print(json.dumps({'status':'passed','cases':len(checks)}))

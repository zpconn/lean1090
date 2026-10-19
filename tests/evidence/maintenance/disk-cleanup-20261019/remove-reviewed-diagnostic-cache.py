import sys
sys.dont_write_bytecode=True
from pathlib import Path
import json,hashlib,os,datetime,collections
root=Path.cwd(); base=root/'tests/evidence/maintenance/disk-cleanup-20261019'; reviewpath=base/'diagnostic-cache-review.json'; expected='7cb6e8ad70c6c5eabe20fa976d0f620222adc88b07ca9d4bb7b94680b97cf3b2'
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
 return h.hexdigest()
assert sha(reviewpath)==expected
review=json.loads(reviewpath.read_text()); selected=[]; keep=[]
classes={'verified_retained_duplicate','rebuildable_bound_binary_or_symbol_log'}
for group in review['candidate_roots']:
 for f in group['files']:
  p=root/f['path'];assert not p.is_symlink() and p.is_file() and p.resolve()==p
  assert p.parts[:len(root.parts)+1]==root.parts+('.cache',)
  if f['classification'] in classes:
   s=p.stat();selected.append({**f,'device':s.st_dev,'inode':s.st_ino,'links':s.st_nlink,'allocated_bytes':s.st_blocks*512})
  else:keep.append(f)
inodes={}
for f in selected:
 k=(f['device'],f['inode']);v=inodes.setdefault(k,{'selected_links':0,'original_links':f['links'],'allocated_bytes':f['allocated_bytes']});v['selected_links']+=1;assert v['original_links']==f['links']
assert all(x['selected_links']<=x['original_links'] for x in inodes.values())
rec={'status':'authorized_predelete','started_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'authorization':'Parent authorized exactly the two reviewed classifications after per-file binding review. No whole-directory deletion.','review':str(reviewpath.relative_to(root)),'review_sha256':expected,'classes':sorted(classes),'selected_files':len(selected),'apparent_bytes_sum':sum(f['bytes'] for f in selected),'allocated_bytes_sum_by_path':sum(f['allocated_bytes'] for f in selected),'allocated_bytes_unique_inodes':sum(f['allocated_bytes'] for f in inodes.values()),'allocated_bytes_with_all_links_selected':sum(f['allocated_bytes'] for f in inodes.values() if f['selected_links']==f['original_links']),'keep_files':len(keep),'explanation':'Removed only verified retained duplicates and rebuildable diagnostic executables, objects and symbol inventories explicitly bound in retained manifests. Original source, generated C, commands, source/native hashes and historical manifests remain unchanged. Every unique/unbound file and all original perf.data remain. Historical omitted-binary paths intentionally become absent; rebuild from their recorded source and command provenance.','selected':selected,'kept':keep}
rec['filesystem_free_before']=os.statvfs(root).f_bavail*os.statvfs(root).f_frsize
pre=base/'diagnostic-cache-cleanup-before.json';receipt=base/'diagnostic-cache-cleanup.json';events=base/'diagnostic-cache-cleanup-events.jsonl';assert not any(p.exists() for p in [pre,receipt,events])
def durable(p,obj):
 with p.open('w') as f:json.dump(obj,f,indent=2);f.write('\n');f.flush();os.fsync(f.fileno())
durable(pre,rec);durable(receipt,rec)
with events.open('w') as event:
 def emit(x):event.write(json.dumps(x)+'\n');event.flush();os.fsync(event.fileno())
 for i,f in enumerate(selected,1):
  p=root/f['path'];s=p.stat();assert not p.is_symlink() and s.st_ino==f['inode'] and s.st_dev==f['device'];assert s.st_size==f['bytes'] and sha(p)==f['sha256']
  emit({'event':'verified_before_unlink','path':f['path'],'sha256':f['sha256'],'utc':datetime.datetime.now(datetime.timezone.utc).isoformat()})
  p.unlink();emit({'event':'unlinked','path':f['path']})
  if i%200==0:print(f'{i}/{len(selected)} removed',flush=True)
for f in keep:
 p=root/f['path'];assert p.is_file() and sha(p)==f['sha256']
retained={}
for f in selected:
 if f['classification']=='verified_retained_duplicate':
  b=f['binding'];retained[b['path']]=b['sha256']
 else:
  for b in f['binding']:
   p=root/b['manifest'];assert p.is_file()
for p,h in retained.items():assert sha(root/p)==h
assert all(not (root/f['path']).exists() for f in selected)
rec.update(status='completed',finished_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),all_selected_absent=True,all_keep_hashes_unchanged=True,retained_duplicate_files_rechecked=len(retained),filesystem_free_after=os.statvfs(root).f_bavail*os.statvfs(root).f_frsize,events_sha256=sha(events))
rec['filesystem_free_delta_observed']=rec['filesystem_free_after']-rec['filesystem_free_before'];rec['free_delta_caveat']='Other authorized cleanup runs concurrently; filesystem free-space delta is not attributed solely to these files. Allocated bytes with all hard links selected is the per-inode attributable removal count.'
durable(receipt,rec)
print(json.dumps({'status':rec['status'],'files':len(selected),'apparent_bytes':rec['apparent_bytes_sum'],'attributable_allocated_bytes':rec['allocated_bytes_with_all_links_selected'],'observed_filesystem_free_delta':rec['filesystem_free_delta_observed'],'receipt':str(receipt.relative_to(root)),'sha256':sha(receipt)},indent=2),flush=True)

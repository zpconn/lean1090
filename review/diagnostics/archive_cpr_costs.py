#!/usr/bin/env python3
"""Retain the completed CPR diagnostic with deterministic compressed raw evidence."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
import argparse,gzip,hashlib,json,re,shutil
ROOT=Path(__file__).resolve().parents[2]
def archive_subdirectories(perf_subdir='perf-gen15-cpr'):
 assert re.fullmatch(r'perf-[A-Za-z0-9_-]+',perf_subdir), 'perf subdirectory must be one simple perf-* name'
 return ['driver-attempt01','driver','driver-final','validation','callgrind',perf_subdir]
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
 return h.hexdigest()
def retain(src,dst):
 assert src.is_file() and not src.is_symlink() and not dst.exists();dst.parent.mkdir(parents=True,exist_ok=True)
 rawsha=sha(src);size=src.stat().st_size
 compressed=size>131072 and src.suffix not in {'.gz'}
 if compressed:
  dst=Path(str(dst)+'.gz');assert not dst.exists()
  with src.open('rb') as inp,dst.open('wb') as out,gzip.GzipFile(filename='',mode='wb',fileobj=out,mtime=0) as z:shutil.copyfileobj(inp,z,1024*1024)
  h=hashlib.sha256();count=0
  with gzip.open(dst,'rb') as inp:
   for b in iter(lambda:inp.read(1024*1024),b''):h.update(b);count+=len(b)
  assert h.hexdigest()==rawsha and count==size
 else:shutil.copyfile(src,dst);assert sha(dst)==rawsha
 assert sha(src)==rawsha
 return dst,{'source':str(src.relative_to(ROOT)),'source_sha256':rawsha,'source_bytes':size,'stored_sha256':sha(dst),'stored_bytes':dst.stat().st_size,'encoding':'deterministic-gzip-mtime0-no-filename' if compressed else 'identity'}
def main():
 a=argparse.ArgumentParser();a.add_argument('--cache',type=Path,default=Path('.cache/gen15-cpr'));a.add_argument('--output',type=Path,default=Path('tests/evidence/diagnostics/gen15-cpr'));a.add_argument('--perf-subdir',default='perf-gen15-cpr',help='single perf-* cache subdirectory; historical default preserved');args=a.parse_args();cache=ROOT/args.cache;out=ROOT/args.output
 subdirectories=archive_subdirectories(args.perf_subdir)
 manifest=out/'archive-manifest.json';assert not manifest.exists()
 build=json.loads((cache/'driver-final/driver-build.json').read_text());run=json.loads((cache/'callgrind/run.json').read_text());val=json.loads((cache/'validation/summary.json').read_text());assert build['status']==run['status']==val['status']=='passed'
 assert run['root']=='l_Lean1090_Diagnostics_CPRCosts_runCPR' and run['prepared']['selected']==run['decoded']['retained']==172432
 expected=val['result'].copy();actual=run['result'].copy();assert expected.pop('batch_state_check') is True and actual.pop('batch_state_check') is False and actual==expected
 for n,h in build['unchanged_native_inputs'].items():assert sha(ROOT/n)==h,n
 for n,h in build['artifacts'].items():assert sha(ROOT/n)==h,n
 files={};omitted={}
 for sub in subdirectories:
  directory=cache/sub
  for src in sorted(directory.rglob('*')):
   if src.is_dir():continue
   if not src.is_file():
    # Valgrind control FIFOs are ephemeral IPC, never evidence or deletion candidates.
    continue
   assert not src.is_symlink()
   with src.open('rb') as f:magic=f.read(4)
   if magic==b'\x7fELF' or src.name in {'vgdb-shared-mem-vgdb-5-by-zpconn-on-???'}:
    omitted[str(src.relative_to(ROOT))]={'sha256':sha(src),'bytes':src.stat().st_size,'reason':'Rebuildable diagnostic executable/object or ephemeral control state; source/commands/native associations retained.'};continue
   if src.name.startswith('vgdb-'):
    omitted[str(src.relative_to(ROOT))]={'sha256':sha(src),'bytes':src.stat().st_size,'reason':'Ephemeral profiler IPC state; protocol and command acknowledgements retained.'};continue
   dst,entry=retain(src,out/('retained/'+sub)/src.relative_to(directory));files[str(dst.relative_to(out))]=entry
 # Capture all new tooling sources exactly, including the analyzer and parser used.
 for name in ['CPRCosts.lean','build_cpr_costs.py','validate_cpr_costs.py','profile_cpr_costs.py','analyze_cpr_costs.py','archive_cpr_costs.py','analyze_callgrind.py','extract_cpr_power_contexts.py','extract_cpr_decoder_stages.py']:
  src=ROOT/'review/diagnostics'/name;dst,entry=retain(src,out/'tooling'/name);files[str(dst.relative_to(out))]=entry
 record={'status':'passed','files':files,'omitted_binaries':omitted,'file_count':len(files),'stored_bytes':sum(x['stored_bytes'] for x in files.values()),'full_profile_result_matches_native_validation':True,'tracking_rows':172432,'resolved_positions':11347,'all_production_inputs_unchanged':True,'notes':['Raw perf and Callgrind recordings are retained in deterministic gzip with raw and stored hashes.','No originals are deleted or overwritten by this archiver. Rebuildable ignored binaries are represented by hashes and source/command provenance.','Per-row audit compares bit identity; the project differential acceptance tolerance remains 1e-9 degrees.','The CPR driver uses immediate live streamStep, matching frozen worker, and checks the complete final state against the batch API only outside collection.']}
 manifest.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':'passed','manifest':str(manifest.relative_to(ROOT)),'sha256':sha(manifest),'files':len(files),'stored_bytes':record['stored_bytes']}))
if __name__=='__main__':main()

from pathlib import Path
import gzip,hashlib,io,json,shutil
ROOT=Path.cwd(); CACHE=ROOT/'.cache/gen1-planning'; OUT=ROOT/'tests/evidence/diagnostics/gen0'
OUT.mkdir(parents=True,exist_ok=True)
manifest_path=OUT/'archive-manifest.json'
manifest=json.loads(manifest_path.read_text()) if manifest_path.exists() else {'kind':'gen0_untimed_diagnostic_archive','files':{},'omitted_cached_binaries':{},'incomplete_profiles':[]}
def sha(data):return hashlib.sha256(data).hexdigest()
def archive(source,destination,compress=False):
    source=Path(source);destination=Path(destination);data=source.read_bytes();target=OUT/destination
    if compress:
        buffer=io.BytesIO()
        with gzip.GzipFile(filename='',mode='wb',fileobj=buffer,compresslevel=9,mtime=0) as stream:stream.write(data)
        stored=buffer.getvalue();target=Path(str(target)+'.gz')
    else:stored=data
    key=str(target.relative_to(OUT));entry={'source':str(source.relative_to(ROOT)),'source_sha256':sha(data),'source_bytes':len(data),'stored_sha256':sha(stored),'stored_bytes':len(stored),'encoding':'deterministic-gzip-mtime0-no-filename' if compress else 'identity'}
    if target.exists() and target.read_bytes()!=stored:raise RuntimeError('refusing to replace prior archive bytes: '+key)
    target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(stored);manifest['files'][key]=entry
    if compress:assert gzip.decompress(target.read_bytes())==data
for name in ['callgraph-review.md','profile-options.md','driver-all-census.jsonl','driver-validation.json','driver-review.json','probe-campaign.json','driver-empty-df19.jsonl','driver-wait-df19.jsonl','driver-bad-command.stderr']:
    archive(CACHE/name,name)
for p in sorted(CACHE.glob('driver-score*')):
    if p.is_file():archive(p,p.name)
for dirname in ['driver-v1','driver-v2','driver-v3']:
    for p in sorted((CACHE/dirname).rglob('*')):
        if not p.is_file():continue
        if p.name=='decode-costs' or p.name.endswith('.o') or p.name=='driver-symbols.log':
            manifest['omitted_cached_binaries'][str(p.relative_to(ROOT))]={'sha256':sha(p.read_bytes()),'bytes':p.stat().st_size,'reason':'binary/object/large symbol log retained only in cache'};continue
        archive(p,p.relative_to(CACHE))
for dirname in ['callgrind-controls-smoke','callgrind-controls-smoke-v3','callgrind-controls-smoke-v3-no-ptrace','probe-jobs','callgrind']:
    directory=CACHE/dirname
    if not directory.exists():continue
    for p in sorted(directory.rglob('*')):
        if not p.is_file() or p.name.startswith('vgdb-'):continue
        archive(p,p.relative_to(CACHE) if dirname!='callgrind' else Path('initial-direct-callgrind')/p.relative_to(directory),p.name.startswith('callgrind.out') or p.suffix=='.out')
manifest['incomplete_profiles']=[]
for directory in sorted((CACHE/'callgrind-v3').iterdir()):
    state=json.loads((directory/'run.json').read_text())
    if state['status']!='passed':
        manifest['incomplete_profiles'].append({'mode':directory.name,'status':state['status'],'source':str((directory/'run.json').relative_to(ROOT))});continue
    for p in sorted(directory.rglob('*')):
        if not p.is_file() or p.name.startswith('vgdb-'):continue
        archive(p,p.relative_to(CACHE),p.name.startswith('callgrind.out'))
# Preserve the actual generated production code linked into every profile.
build=json.loads((CACHE/'driver-v3/driver-build.json').read_text())
for name,digest in build['reused_production_objects'].items():
    object_path=ROOT/name;assert sha(object_path.read_bytes())==digest,name
    cpath=Path(str(object_path).removesuffix('.o.export'))
    archive(cpath,Path('generated-c')/cpath.relative_to(ROOT/'.lake/build/ir'))
for p in [ROOT/'.cache/profiling-tools/packages.json',ROOT/'.cache/profiling-tools/bin/valgrind',ROOT/'.cache/profiling-tools/bin/perf']:
    archive(p,Path('profiling-tools')/p.name)
archive(ROOT/'review/diagnostics/DecodeCosts.lean',Path('current-driver')/'DecodeCosts.lean')
archive(ROOT/'review/diagnostics/build_decode_costs.py',Path('current-driver')/'build_decode_costs.py')
archive(ROOT/'review/diagnostics/profile_decode_costs.py',Path('current-driver')/'profile_decode_costs.py')
archive(Path(__file__).resolve(),'archive_diagnostics.py')
manifest['file_count']=len(manifest['files']);manifest['stored_bytes']=sum(e['stored_bytes'] for e in manifest['files'].values())
manifest['notes']=['This archive records untimed instruction diagnostics, not benchmark samples or an optimization.', 'Raw profile dumps are compressed deterministically, with original and stored SHA-256 hashes. Originals remain in cache.', 'Initial controller timeout/ptrace retries are diagnostic tooling failures or warnings, not decoder/differential failures.', 'The primary controlled dump is callgrind.out.1.gz. Termination dumps can contain zero totals with wrapped summaries after instrumentation-off; they are retained only as tool artifacts.', 'Candidate and score probes are supplemental overlapping views, not additive costs.', 'Analysis, native-df and perf evidence maintained by the analysis agent is outside this manifest membership.']
manifest_path.write_text(json.dumps(manifest,indent=2)+'\n')
print(json.dumps({'files':manifest['file_count'],'stored_bytes':manifest['stored_bytes'],'incomplete_profiles':manifest['incomplete_profiles'],'manifest':str(manifest_path.relative_to(ROOT))}))

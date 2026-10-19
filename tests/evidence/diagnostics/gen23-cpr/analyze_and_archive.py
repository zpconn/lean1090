#!/usr/bin/env python3
"""Read completed counters, compress evidence, and archive; no decoder runs."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import gzip, hashlib, json, os, shutil, subprocess

ROOT = Path.cwd()
BASE = ROOT / 'tests/evidence/diagnostics/gen23-cpr'
CACHE = ROOT / '.cache/gen23-cpr-costs'
def sha(p):
    h = hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()
def load(p): return json.loads(p.read_text())
def write(p, obj):
    assert not p.exists()
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(json.dumps(obj, indent=2) + '\n')

# Preparation never executes this file. Collection, source review and parent release
# must already have completed before any analysis/archive writes.
collection = load(BASE / 'collect-execution.json')
assert collection['status'] == 'passed' and collection['all_inputs_unchanged']
source_review = load(BASE / 'independent-review/source-review.json')
assert source_review['status'] == 'passed_read_only_source_and_native_review'
assert source_review['worker_sha256'] == collection['worker_sha256']
assert source_review['raw_word_syndrome_live_path_verified']
assert source_review['decode_frame_with_word_anchor']
assert source_review['commb_validity_tables_live_path_verified']
run = load(CACHE / 'callgrind/run.json')
assert run['status'] == 'passed'
assert load(CACHE / 'validation/summary.json')['status'] == 'passed'
commands = []
def execute(label, argv):
    started = datetime.now(timezone.utc).isoformat()
    with (BASE / (label + '.log')).open('x') as out:
        r = subprocess.run([sys.executable, '-B', *map(str, argv)], stdout=out,
                           stderr=subprocess.STDOUT, cwd=ROOT)
    commands.append({'label':label, 'argv':[sys.executable,'-B',*map(str,argv)],
                     'started_utc':started,'finished_utc':datetime.now(timezone.utc).isoformat(),
                     'exit_code':r.returncode,'log_sha256':sha(BASE/(label+'.log'))})
    (BASE / 'analysis-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    assert r.returncode == 0, label

raw = CACHE / 'callgrind/callgrind.out.1'
analysis = CACHE / 'analysis/analysis.json'
execute('analyze', ['review/diagnostics/analyze_cpr_costs.py','--profile',raw,'--output',CACHE/'analysis'])
for label, script, output in [
    ('decoder-stages','review/diagnostics/extract_cpr_decoder_stages.py',CACHE/'decoder-stages.json'),
    ('power-contexts','review/diagnostics/extract_cpr_power_contexts.py',CACHE/'power-contexts.json'),
    ('numeric-contexts',BASE/'extract_numeric_contexts.py',CACHE/'numeric-contexts.json'),
    ('table-contexts',BASE/'extract_table_contexts.py',CACHE/'table-contexts.json')]:
    execute(label,[script,'--profile',raw,'--analysis',analysis,'--output',output])

records = []
for source, destination in [(analysis, BASE/'analysis/analysis.json.gz'),
                            (CACHE/'decoder-stages.json',BASE/'decoder-stages.json.gz'),
                            (CACHE/'numeric-contexts.json',BASE/'numeric-contexts.json.gz'),
                            (CACHE/'table-contexts.json',BASE/'table-contexts.json.gz')]:
    destination.parent.mkdir(parents=True,exist_ok=True)
    assert not destination.exists()
    before = sha(source)
    with source.open('rb') as inp, destination.open('xb') as out:
        with gzip.GzipFile(filename='', mode='wb', fileobj=out, mtime=0) as z:
            shutil.copyfileobj(inp,z,1<<20)
        out.flush();os.fsync(out.fileno())
    digest,size = hashlib.sha256(),0
    with gzip.open(destination,'rb') as f:
        for b in iter(lambda:f.read(1<<20),b''):
            digest.update(b);size+=len(b)
    assert before == sha(source) == digest.hexdigest() and size == source.stat().st_size
    records.append({'source':str(source.relative_to(ROOT)),'raw_sha256':before,'raw_bytes':size,
                    'retained':str(destination.relative_to(ROOT)),'compressed_sha256':sha(destination)})
write(BASE/'analysis-retention.json',{'status':'passed','files':records})
a = load(analysis)
write(BASE/'analysis/summary.json',{k:v for k,v in a.items() if k not in
    ['self_cost_contexts','helper_observations_non_additive']})
write(BASE/'decoder-stages-summary.json',{k:v for k,v in load(CACHE/'decoder-stages.json').items()
                                        if k!='self_contexts'})
write(BASE/'numeric-contexts-summary.json',{k:v for k,v in load(CACHE/'numeric-contexts.json').items()
                                         if k!='full_context_edges'})
write(BASE/'table-contexts-summary.json',{k:v for k,v in load(CACHE/'table-contexts.json').items() if k!='full_context_edges'})
for source,destination in [(CACHE/'power-contexts.json',BASE/'power-contexts.json'),
                           (CACHE/'analysis/fixture-checks.json',BASE/'analysis/fixture-checks.json')]:
    assert not destination.exists();shutil.copyfile(source,destination);assert sha(source)==sha(destination)
execute('archive',['review/diagnostics/archive_cpr_costs.py','--cache',CACHE,'--output',BASE,
                   '--perf-subdir','perf-gen23-cpr'])
print(json.dumps({'status':'passed','total_Ir':a['total_Ir'],'exclusive_stages':a['exclusive_stages'],
                  'analysis_sha256':sha(BASE/'analysis/analysis.json.gz'),
                  'archive_manifest_sha256':sha(BASE/'archive-manifest.json')}))

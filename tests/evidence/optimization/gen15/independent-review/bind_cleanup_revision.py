#!/usr/bin/env python3
import sys
sys.dont_write_bytecode = True
import ast, json, hashlib
from datetime import datetime, timezone
from pathlib import Path
b = Path('tests/evidence/maintenance/scratch-cleanup-archive-flush-20261019')
o = Path('tests/evidence/optimization/gen15/independent-review')
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
r = json.loads((b/'independent-review.json').read_text())
v = json.loads((b/'validation.json').read_text())
assert sha(b/'independent-review.json') == '66fe9441bf19a995638679833f61c75ff25c3a9e994685198141abbce6096d6a'
assert r['status'] == 'passed' and not r['blocking_findings'] and r['total_fixture_cases'] == 54
assert v['status'] == 'passed_author_validation_pending_independent_review'
assert r['producer_validation_sha256'] == sha(b/'validation.json')
for p,h in r['helpers'].items(): assert sha(p) == h
for p,item in r['artifacts'].items(): assert sha(p) == item['sha256'] and Path(p).stat().st_size == item['bytes']
for p,item in v['files'].items(): assert sha(b/p) == item['sha256'] and (b/p).stat().st_size == item['bytes']
old = json.loads((o/'cleanup-tooling-bindings.json').read_text())
for p,h in old['helpers'].items():
    q = b/'before'/Path(p).name
    assert sha(q if q.exists() else Path(p)) == h
for p,h in json.loads((b/'prior-evidence-hashes.json').read_text()).items(): assert sha(p) == h
paths = {p for p in b.rglob('*') if p.is_file()}
paths |= {o/n for n in ('check_post_gate_cleanup-before-second-receipt.py', 'check_post_gate_cleanup-attempt-01.py',
    'post-gate-cleanup-review-01.log', 'post-gate-cleanup-review-02.log', 'post-gate-cleanup-review.json',
    'check_gate_review-before-second-cleanup.py', 'gate-core-review.json', 'gate-core-review-01.log',
    'check_gate_core_review.py', 'gate-review-01.log', 'cleanup-revision-attempt-01-error.json', 'bind_cleanup_revision.py')}
d = {'status':'passed_read_only_bindings', 'recorded_utc':datetime.now(timezone.utc).isoformat(),
     'current_helpers':r['helpers'],
     'files':{str(p):{'sha256':sha(p), 'bytes':p.stat().st_size} for p in sorted(paths)},
     'independent_revision_review_sha256':sha(b/'independent-review.json'),
     'producer_validation_sha256':sha(b/'validation.json'),
     'producer_validation_status_preserved':v['status'],
     'original_wrapper_sha256':sha(b/'before/finish_generation_gate.py'),
     'new_wrapper_not_used_in_recorded_live_cleanup':True,
     'reviewer_attempts':[
       {'stage':'sequential_cleanup_binding', 'attempt':1, 'status':'failed_review_binding_assumption',
        'reason':'Old test helper changed under reviewed correction; preserved original source is the required historical binding.'},
       {'stage':'sequential_cleanup_binding', 'attempt':2, 'status':'passed', 'report_sha256':sha(o/'post-gate-cleanup-review.json')},
       {'stage':'revision_binding', 'attempt':1, 'status':'failed_review_schema_assumption',
        'reason':'Producer validation retains pending-independent status; subsequent independent report supplies pass. Following gate checker therefore stopped for missing binding file.'},
       {'stage':'revision_binding', 'attempt':2, 'status':'passed'}], 'findings':[]}
p = o/'cleanup-revision-bindings.json'
assert not p.exists()
p.write_text(json.dumps(d,indent=2,sort_keys=True)+'\n')
ast.parse((o/'check_gate_review.py').read_text())
print(json.dumps({'status':d['status'], 'sha256':sha(p), 'retained_files':len(paths)},indent=2))

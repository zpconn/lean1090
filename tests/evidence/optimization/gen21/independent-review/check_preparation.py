#!/usr/bin/env python3
"""Read-only review of the generation 21 fresh producer preparation."""
import sys
sys.dont_write_bytecode = True
import ast
import csv
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

P = Path('tests/evidence/optimization/gen21')
O = Path('tests/evidence/optimization/gen20')
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
load = lambda p: json.loads(Path(p).read_text())
bindings = {}
checks = []
def bind(p, expected=None):
    h = sha(p)
    assert expected is None or h == expected, str(p)
    bindings[str(p)] = h
    return h
def check(condition, label):
    assert condition, label
    checks.append(label)

prep = load(P / 'preparation.json')
bind(P / 'preparation.json', '2a2c30cac7fc52cb75a690b0f5cc6ad4055f53185ad4b15fa6cd73447b6aaab8')
for name, info in prep['helpers'].items():
    bind(name, info['sha256'])
    bind(info['reused_from'], info['prior_sha256'])
names = list(prep['adaptations'])
check(len(names)==7,'all seven producer/helper adaptations')
for name in names:
    info=prep['adaptations'][name];old,new=O/name,P/name
    expected=old.read_text().replace('gen20','__CURRENT__').replace('gen19','gen20').replace('__CURRENT__','gen21')
    check(new.read_text()==expected,name+': exact generation path adaptation')
    ast.parse(new.read_text(),filename=str(new))
    bind(old,info['prior_sha256']);bind(new,info['sha256']);bind(info['diff_path'],info['diff_sha256'])
bind(P / 'prepare_preflight.py', prep['preflight_preparer_sha256'])
for p, h in prep['history_bindings'].items():
    bind(p, h)
prior = prep['source_inventory_prior']
bind(prior['path'], prior['sha256'])
old_names = set(load(prior['path'])['source_sha256_before'])
current = set(old_names)
for directory in ['Impl', 'Model', 'Spec', 'Proofs', 'CLI', 'Tests']:
    current.update(str(p) for p in Path(directory).rglob('*.lean'))
current.update(['lakefile.toml', 'lake-manifest.json', 'lean-toolchain', 'Capstones.lean'])
check(len(old_names) == len(current) == 120, 'complete source inventory remains 120')
check(sorted(current - old_names) == sorted(prep['selected_scope']['new_proofs']), 'no new proof modules')
bind('bench/results.csv', prep['prior_csv_sha256'])
check(len(list(csv.DictReader(Path('bench/results.csv').read_text().splitlines()))) == 42, 'exact 42 prior result rows')
bind(prep['reporting_helper']['path'], prep['reporting_helper']['sha256'])
build = load(P / 'integration/targeted-build.json')
check(build['status'] == 'passed' and build['exit_code'] == 0, 'combined build passed')
check(len(build['all_inputs_after']) == 195 and build['all_inputs_before'] == build['all_inputs_after'], '195 held build inputs')
bind(P / 'integration/targeted-build.json')
for p, h in build['all_inputs_after'].items():
    check(sha(p) == h, 'held correctness input: ' + p)
check(not (P / 'fresh-execution.json').exists(), 'producer not executed at review')
orchestrator = ast.parse((P / 'fresh-orchestrate.py').read_text())
retained = next(ast.literal_eval(n.value) for n in orchestrator.body if isinstance(n, ast.Assign) and any(isinstance(t, ast.Name) and t.id == 'EXPECTED_RETENTION' for t in n.targets))
check(len(retained) == len(set(retained)) == 33, 'exact 33 unique retained members')
out = P / 'independent-review/preparation-review.json'
assert not out.exists()
record = dict(status='passed_read_only_preparation_review', findings=[], recorded_utc=datetime.now(timezone.utc).isoformat(), checks=checks, check_count=len(checks), bindings=bindings, reviewer_sha256=sha(__file__), source_count=120, gate_input_count=195, retained_file_count=33,
    assessment=['Only generation paths changed from the reviewed generation 20 producer; exact counts and retention membership are preserved.', 'The preflight requires explicit root release, successful source-identical integration and this review before sampling collision-checked seeds.', 'The 10M whole-message and 100k Comm-B commands, all before/after source and binary checks, exact retention membership and gzip verification are unchanged.', 'Overwrite rejection, failure retention, and post-seal independent review before selected cleanup remain intact.', 'No controller import, generation, compiler, native decoder or cleanup executed by this review.'])
out.write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(dict(status='passed', checks=len(checks), review=str(out), sha256=sha(out))))

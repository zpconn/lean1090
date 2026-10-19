#!/usr/bin/env python3
"""Read-only review of the generation 23 fresh producer preparation."""
import sys
sys.dont_write_bytecode = True
import ast
import csv
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

P = Path('tests/evidence/optimization/gen23')
O = Path('tests/evidence/optimization/gen22')
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
bind(P / 'preparation.json', 'd0f9b0a56c9fbc269ae904bb2745fcd0de3f6b7c62656b064a82c74846a1fb18')
for name, info in prep['helpers'].items():
    bind(name, info['sha256'])
    bind(info['reused_from'], info['prior_sha256'])
names = list(prep['adaptations'])
check(len(names)==7,'all seven producer/helper adaptations')
for name in names:
    info=prep['adaptations'][name];old,new=O/name,P/name
    expected=old.read_text().replace('gen22','__CURRENT__').replace('gen21','gen22').replace('__CURRENT__','gen23').replace('==122','==125').replace('==197','==200')
    if name == 'finish_campaign.py':
        insertion="native_review=load(G/'native-review/review.json')\nassert native_review['status']=='passed' and not native_review['findings']\nassert native_review['commb_validity_tables_live_path_verified'] and native_review['linked_native_sets']==22\n"
        expected=expected.replace("assert all(x['status']=='passed'",insertion+"assert all(x['status']=='passed'",1)
    check(new.read_text()==expected,name+': exact generation/count adaptation and explicit native guard')
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
check(len(old_names) == 122 and len(current) == 125, 'complete source inventory adds exactly three proofs')
check(sorted(current - old_names) == sorted(prep['selected_scope']['new_proofs']), 'only the three CommBValidity proofs added')
bind('bench/results.csv', prep['prior_csv_sha256'])
check(len(list(csv.DictReader(Path('bench/results.csv').read_text().splitlines()))) == 46, 'exact 46 prior result rows')
bind(prep['reporting_helper']['path'], prep['reporting_helper']['sha256'])
check(prep['expected_gate_input_count'] == 200 and prep['expected_fresh_source_count'] == 125, 'future preflight expects 200 inputs and 125 sources')
check(sorted(current - old_names) == ['Proofs/CommBValidity40.lean', 'Proofs/CommBValidity50.lean', 'Proofs/CommBValidity60.lean'], 'exact new source names')
for p,h in prep['unchanged_generator_inputs'].items(): bind(p,h)
preflight = (P / 'prepare_preflight.py').read_text()
check("gate==build['all_inputs_before']==build['all_inputs_after']" in preflight, 'later execution checks exact actual build inventory')
check("build['status']=='passed' and build['exit_code']==0" in preflight, 'later execution requires successful combined build')
check("assert h==build['binary_hashes'][Path(name).name]" in preflight, 'later execution binds actual binaries')
check(not (P / 'fresh-preflight.json').exists() and not (P / 'fresh-seeds.json').exists(), 'no seeds or preflight before release')
check(not (P / 'fresh-execution.json').exists(), 'producer not executed at review')
orchestrator = ast.parse((P / 'fresh-orchestrate.py').read_text())
retained = next(ast.literal_eval(n.value) for n in orchestrator.body if isinstance(n, ast.Assign) and any(isinstance(t, ast.Name) and t.id == 'EXPECTED_RETENTION' for t in n.targets))
check(len(retained) == len(set(retained)) == 33, 'exact 33 unique retained members')
out = P / 'independent-review/preparation-review.json'
assert not out.exists()
record = dict(status='passed_read_only_preparation_review', findings=[], recorded_utc=datetime.now(timezone.utc).isoformat(), checks=checks, check_count=len(checks), bindings=bindings, reviewer_sha256=sha(__file__), source_count=125, gate_input_count=200, retained_file_count=33,
    assessment=['Generation paths and independently derived inventory cardinalities changed; the finisher adds an explicit current native flag/status/22-set guard from the reviewed generation 22 producer; exact retention membership is preserved.', 'The preflight requires explicit root release, successful source-identical integration and this review before sampling collision-checked seeds.', 'The 10M whole-message and 100k Comm-B commands, all before/after source and binary checks, exact retention membership and gzip verification are unchanged.', 'Overwrite rejection, failure retention, and post-seal independent review before selected cleanup remain intact.', 'Combined build and current binary/content bindings are intentionally deferred; the reviewed preflight requires them before recording seeds or starting generation.', 'No controller import, generation, compiler, native decoder or cleanup executed by this review.'])
out.write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(dict(status='passed', checks=len(checks), review=str(out), sha256=sha(out))))

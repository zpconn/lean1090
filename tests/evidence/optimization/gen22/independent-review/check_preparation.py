#!/usr/bin/env python3
"""Read-only review of the generation 22 fresh producer preparation."""
import sys
sys.dont_write_bytecode = True
import ast
import csv
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

P = Path('tests/evidence/optimization/gen22')
O = Path('tests/evidence/optimization/gen21')
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
bind(P / 'preparation.json', 'bd1c9524cc95364c645626dfa2fbf31df1d58c7d229963e33359b93e856e516f')
for name, info in prep['helpers'].items():
    bind(name, info['sha256'])
    bind(info['reused_from'], info['prior_sha256'])
names = list(prep['adaptations'])
check(len(names)==7,'all seven producer/helper adaptations')
for name in names:
    info=prep['adaptations'][name];old,new=O/name,P/name
    expected=old.read_text().replace('gen21','__CURRENT__').replace('gen20','gen21').replace('__CURRENT__','gen22').replace('==120','==122').replace('==195','==197')
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
check(len(old_names) == 120 and len(current) == 122, 'complete source inventory adds exactly two proofs')
check(sorted(current - old_names) == sorted(prep['selected_scope']['new_proofs']), 'only FrameWord and RawSyndromeSpec added')
bind('bench/results.csv', prep['prior_csv_sha256'])
check(len(list(csv.DictReader(Path('bench/results.csv').read_text().splitlines()))) == 44, 'exact 44 prior result rows')
bind(prep['reporting_helper']['path'], prep['reporting_helper']['sha256'])
check(prep['expected_gate_input_count'] == 197 and prep['expected_fresh_source_count'] == 122, 'future preflight expects 197 inputs and 122 sources')
check(sorted(current - old_names) == ['Proofs/FrameWord.lean', 'Proofs/RawSyndromeSpec.lean'], 'exact new source names')
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
record = dict(status='passed_read_only_preparation_review', findings=[], recorded_utc=datetime.now(timezone.utc).isoformat(), checks=checks, check_count=len(checks), bindings=bindings, reviewer_sha256=sha(__file__), source_count=122, gate_input_count=197, retained_file_count=33,
    assessment=['Only generation paths and the two independently derived inventory cardinalities changed from the reviewed generation 21 producer; exact retention membership is preserved.', 'The preflight requires explicit root release, successful source-identical integration and this review before sampling collision-checked seeds.', 'The 10M whole-message and 100k Comm-B commands, all before/after source and binary checks, exact retention membership and gzip verification are unchanged.', 'Overwrite rejection, failure retention, and post-seal independent review before selected cleanup remain intact.', 'Combined build and current binary/content bindings are intentionally deferred; the reviewed preflight requires them before recording seeds or starting generation.', 'No controller import, generation, compiler, native decoder or cleanup executed by this review.'])
out.write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(dict(status='passed', checks=len(checks), review=str(out), sha256=sha(out))))

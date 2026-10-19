"""Source-only review of fixed archive/cleanup and benchmark-plan preparation."""
import sys
sys.dont_write_bytecode=True
import ast,csv,hashlib,json,re
from pathlib import Path
from datetime import datetime,timezone
P=Path('tests/evidence/optimization/gen24');B=P/'benchmark-preparation';checks=[];bindings={}
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 got=sha(p);assert h is None or got==h,str(p);bindings[str(p)]=got;return got
for path in [P/'gate-cleanup-preparation.json',B/'preparation.json']:
 bind(path);prep=load(path)
 for name,h in prep['files'].items():bind(name,h)
prep=load(B/'preparation.json');prior=Path(prep['previous_preparer']);bind(prior,prep['previous_preparer_sha256'])
s=(B/'prepare.py').read_text();ast.parse(s)
expected=prior.read_text().replace("'gen23'","'gen24'").replace('gen23','gen24').replace('GEN23','GEN24').replace("== 23","== 24").replace('raw, 23','raw, 24').replace('== 200','== 202').replace('== 125','== 127').replace('== 46','== 48').replace("'prior_rows': 46","'prior_rows': 48").replace('commb_validity_tables_live_path_verified','commb_semantic_reuse_live_path_verified').replace('07ef4d93ce00a5a265adfbe38ab483675fd3d3d989601ff854ace85e5f96e49c','c630842cf75c288fef94e3466471a300c9b85089aba6fb42113253c1894c49d7')
check(s==expected,'Plan finalizer exact generation/count/pending-hash/native-flag adaptation')
pending=load(B/'plan-pending.json');protocol=load(B/'execution-protocol.json')
check(pending['status']=='pending_validation_not_ready_for_timing' and pending['generation']==24,'Pending status contains no measured outcome')
check(not (B/'plan.json').exists() and not Path('bench/runs/gen24').exists(),'Final plan and measurement absent at preparation review')
check((B/'results-before.csv').read_bytes()==Path('bench/results.csv').read_bytes() and sha('bench/results.csv')==pending['prior_csv_sha256'],'Exact current CSV prefix retained')
check(len(list(csv.DictReader(Path('bench/results.csv').read_text().splitlines())))==pending['prior_csv_rows']==48,'Exactly 48 prior rows')
for mode in ['decode','cpr']:check(pending[mode+'_target_ratio']==dict(numerator=2,denominator=1),'Exact '+mode+' 2/1 target')
for key,value in [('correctness_inputs',202),('fresh_source_count',127),('fresh_retained_members',33),('fresh_binary_count',3),('native_sets',22),('fixed_generated_messages',10000000),('fresh_generated_messages',10000000)]:check(pending['requirements'][key]==value,'Exact plan requirement '+key)
for name,h in protocol['helpers'].items():bind(name,h)
helper=pending['reporting_helper'];bind(helper['path'],helper['sha256']);bind(helper['independent_review'],helper['independent_review_sha256'])
check(helper['sha256']=='c180278ec4c561b48a03d4932dcd3c4576ce350da0673b93184a9403a50f2312','Reviewed signed-overhead helper unchanged')
check(all(protocol[k] is None for k in ['commit','worker_sha256','resolved_output']),'Future commit/worker/output remain unresolved')
check(protocol['output_resolution']==pending['output_protocol'],'One canonical output protocol')
check(pending['output_protocol']['source_parent']=='.cache/bench-runs' and pending['output_protocol']['source_basename']=='gen24-<actual committed HEAD first 7 hex characters>','Canonical benchmark output uses actual committed HEAD prefix')
check(protocol['benchmark_command_template'][protocol['benchmark_command_template'].index('--output')+1]=='.cache/bench-runs/gen24-<ACTUAL_COMMIT_FIRST_7>','Runner command follows canonical output protocol')
check(pending['output_protocol']['expected_original_files']==48 and pending['output_protocol']['mode_samples']==dict(decode=48,cpr=48),'Original archive and sample cardinalities unchanged')
check('without clamping or noise correction' in protocol['exact_signed_cpr_overhead'],'Signed overhead and noise preserved')
# The new controller only selects paths; actual deletion remains in exact reviewed helpers.
selector=(P/'select_finish_gate.py').read_text();post=(P/'verify_post_gate.py').read_text();tree=ast.parse(selector);ast.parse(post)
helpers=next(ast.literal_eval(n.value) for n in tree.body if isinstance(n,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='HELPERS' for t in n.targets))
for name,h in helpers.items():bind(name,h)
prefixes=next(ast.literal_eval(n.value) for n in tree.body if isinstance(n,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='PREFIXES' for t in n.targets))
check(prefixes=={'altitude':'altitude-exhaustive-','reserved_velocity':'reserved-velocity-','dte':'dte-exhaustive-','cpr':'cpr-synthetic-','message':'message-differential-'},'Exactly five established scratch classes selected')
checks_required=[("parser.add_argument('--quiescent-note', required=True)",'Explicit caller quiescence required'),("parser.add_argument('--execute', action='store_true')",'Execution opt-in required'),("provenance.verify_gate_evidence(gate, sha(log), inputs)",'Passed current gate verified'),("fresh['full_coverage_reproduced'] and fresh['decompressed_diagnostic_streams_reproduced']",'Completed independent fresh coverage/replay required'),("assert fresh_root.name.startswith(PREFIXES['message']) and not fresh_root.exists()",'Completed fresh raw root is excluded/protected'),("path not in protected_paths and clean.SCRATCH.fullmatch(path.name)",'Narrow exact temp names and explicit protection'),("birth > 0 and start <= birth <= end and start <= st.st_mtime <= end",'Birth and modification inside gate interval'),("assert stat.S_ISDIR(st.st_mode)",'Selected paths must be directories'),("identity = clean.identity(child)",'Every selected member receives strict regular-file identity check'),("assert identity['links'] == 1",'Hard-linked files rejected'),("assert all(len(paths) == 1 for paths in candidates.values())",'Exactly one eligible directory per component or stop'),("assert selected['message'] == fresh['fixed_gate_scratch_preserved']",'Fixed message identity agrees with executed fresh protection'),("clean.durable(selection_path, record)",'Durable selection before wrapper'),("if not args.execute:",'Selection-only default'),("assert not (BASE / 'post-gate-archive-cleanup').exists()",'Prior wrapper attempts cannot be overwritten')]
for needle,label in checks_required:check(needle in selector,label)
check("clean.local(path)" in selector and "clean.local(p)" in selector,'Selected and protected paths use existing symlink rejection')
check('.cache/reserved-velocity-proposal' in selector and '.cache/gen15-interrupted-gate' in selector,'Both historical failure roots protected')
check("command += ['--protect', rel(path)]" in selector and "'--apply', '--quiescent'" in selector,'Wrapper receives all protections and explicit quiescence')
check(not re.search(r'\.(?:unlink|rmdir)\(|rmtree|\brm\s+-',selector),'Controller contains no direct removal operation')
check("'review/diagnostics/finish_generation_gate.py'" in selector and "'--archive-root', '.cache/gen24-gate/fixed-message-archive'" in selector,'Unchanged durable archive-first wrapper performs actual deletion')
check("with (BASE / 'gate-archive-cleanup.stdout').open('x')" in selector and 'os.fsync' in selector,'Execution logs preserved exclusively and flushed before completion receipt')
for needle,label in [("assert files == 62",'Seven-component archive cardinality'),("assert len(cleanup['results']) == 5",'Exactly five cleanup results'),("file['gzip_eof_verified']",'Exact complete-gzip counterpart checks'),("file['identity']['bytes'] == file['retained']['raw_bytes']",'Raw length binding'),("(ROOT / name).exists() == record['exists']",'Protected existence unchanged'),("plan['prior_csv_rows'] == 48",'Current CSV prefix binding'),("provenance.gate_input_hashes() == inputs",'Post-verification current correctness hold')]:check(needle in post,label)
check('subprocess' not in post,'Post verifier executes no external workload or deletion')
for old in ['GEN23','gen23','== 200','== 125','== 46']:check(old not in s+selector+post,'No stale current-generation guard '+old)
out=P/'independent-review/finishing-preparation-review.json';assert not out.exists()
record=dict(status='passed_read_only_preparation_review',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks_passed=len(checks),checks=checks,bindings=bindings,reviewer_sha256=sha(__file__),notes=['Source/AST review only; controllers were not imported/executed, scratch was not inventoried and no archive/deletion/timing was performed.', 'Metadata selection never replaces byte verification: the unchanged reviewed wrapper archives and fsyncs, verifies complete sealed counterparts, and retains unmatched scratch before unlink.', 'Elapsed time does not imply quiescence; explicit operator attestation remains mandatory. Future plan creation remains gated on actual completed validation.'])
out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),sha256=sha(out))))

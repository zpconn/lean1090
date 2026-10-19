#!/usr/bin/env python3
"""Read-only post-gate evidence review; writes only gate-review.json beside itself."""
from pathlib import Path
from datetime import datetime, timezone
import csv, gzip, hashlib, importlib.util, io, json, re, sys, subprocess

sys.dont_write_bytecode=True
ROOT=Path.cwd()
BASE=Path('tests/evidence/optimization/gen15')
OUT=BASE/'independent-review/gate-review.json'
def load(path):return json.loads(Path(path).read_text())
def sha(path):
    h=hashlib.sha256()
    with Path(path).open('rb') as f:
        for chunk in iter(lambda:f.read(4*1024*1024),b''):h.update(chunk)
    return h.hexdigest()
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    m=importlib.util.module_from_spec(spec);sys.modules[name]=m;spec.loader.exec_module(m);return m
provenance=module('gate_provenance_review','review/diagnostics/run_generation_benchmark.py')
archiver=module('gate_archiver_review','review/diagnostics/archive_generation_gate.py')
gate=load(BASE/'gate-evidence.json');archive=load(BASE/'gate-archive.json')
inputs=provenance.gate_input_hashes()
resume_bindings=load(BASE/'independent-review/resume-bindings.json')
for path,item in resume_bindings['files'].items():
    assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
resume=load(BASE/'independent-review/resume-readiness.json')
interruption=load(BASE/'independent-review/interruption-review.json')
assert resume['status']=='passed_read_only_resume_readiness' and resume['findings']==[]
assert interruption['status']=='passed_interrupted_attempt_preservation_review' and interruption['findings']==[]
assert resume['current_gate_input_hashes']==inputs
assert interruption['readiness_sha256']==sha(BASE/'independent-review/resume-readiness.json')
assert interruption['original_gate_status']=='interrupted_not_passed' and interruption['original_gate_had_no_final_completion']
assert interruption['original_gate_had_completed_components']==6
assert gate['started_at']==interruption['restarted_gate_started_at']
assert gate['command']==interruption['restarted_gate_command']==['scripts/check_all.sh','--full']
assert interruption['old_gate_started_at']<interruption['interruption_recorded_at']<gate['started_at']
for inventory in (interruption['attempt_files'],interruption['snapshot_files'],resume['cleanup_evidence_files']):
    for path,item in inventory.items():
        assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
assert {str(p) for p in (BASE/'attempt-01-interrupted-for-cleanup').rglob('*') if p.is_file()}==set(interruption['attempt_files'])
assert {str(p) for p in Path('.cache/gen15-interrupted-gate').rglob('*') if p.is_file()}==set(interruption['snapshot_files'])
assert load(BASE/'attempt-01-interrupted-for-cleanup/gate-evidence.json')['input_hashes_before']==inputs
verification=provenance.verify_gate_evidence(gate,sha(BASE/'gate-full.log'),inputs)
assert len(inputs)==186 and archive['status']=='passed' and archive['generation']==15
assert archive['gate_evidence_sha256']==sha(BASE/'gate-evidence.json')
assert archive['gate_log_sha256']==sha(BASE/'gate-full.log')
assert archive['helper_sha256']==sha('review/diagnostics/archive_generation_gate.py')
assert archive['provenance_helper_sha256']==sha('review/diagnostics/run_generation_benchmark.py')
runner,components,status_path=archiver.discover_components()
assert sha(runner)==archive['runner_sha256']
component_names=[name for name, *_ in components]
assert set(component_names)==set(archive['components']) and len(component_names)==7
statuses=list(csv.DictReader((BASE/'components.tsv').open(),delimiter='\t'))
assert [x['component'] for x in statuses]==component_names and all(x['exit_code']=='0' for x in statuses)
assert (BASE/'components.tsv').read_bytes()==status_path.read_bytes()
text=(BASE/'gate-full.log').read_text();objects=[]
decoder=json.JSONDecoder()
for m in re.finditer(r'^\{',text,re.MULTILINE):
    try:v,_=decoder.raw_decode(text,m.start())
    except ValueError:continue
    if isinstance(v,dict):objects.append(v)
for expected in ['Final manifest: 23 exact theorem types and permitted axioms.',
                 'Witness axiom audit: 152 proofs; only the three permitted axioms (or fewer).',
                 'Hypothesis dependency audit: all seven required predicates and assigned are independent of decoder entry points/helpers.',
                 'Complete differential campaign passed all mandatory strata.']:
    assert expected in text,expected
assert any(o.get('assertions')==1011 and o.get('assertion_failures')==0 for o in objects)
assert '"corpus_rows": 172432' in text or '172432' in text
for a in re.findall(r'depends on axioms:\s*\[([^\]]*)\]',text):
    assert set(s.strip() for s in a.split(',') if s.strip()) <= {'propext','Classical.choice','Quot.sound'}
component_counts={};retained_total=0;retained_bytes=0;summaries={}
for name,script,source_dir,argv in components:
    record=archive['components'][name]
    assert record['script_sha256']==sha(script) and record['runner_command_tokens']==argv
    original=record['original_files'];retained=record['retained_files']
    assert set(original)==set(retained)
    assert archiver.inventory(source_dir)==original
    retained_dir=Path(retained['summary.json']['path']).parent
    assert archiver.inventory(ROOT/retained_dir)==retained
    for member in original:
        a,b=original[member],retained[member]
        assert a['sha256']==b['sha256'] and a['bytes']==b['bytes']
    for r in record['versioned_metadata'].values():
        assert sha(r['path'])==r['sha256'] and Path(r['path']).stat().st_size==r['bytes']
    summary=load(retained['summary.json']['path']);summaries[name]=summary
    archiver.check_summary(name,summary,inputs)
    assert archiver.bind_printed_summary(name,summary,text,objects)==record['full_gate_log_binding']
    component_counts[name]=len(retained);retained_total+=len(retained);retained_bytes+=sum(r['bytes'] for r in retained.values())
assert retained_total==62 and archive['copied_fixed_message_files']==15
assert summaries['altitude']['counts']['ac12_cases']+summaries['altitude']['counts']['ac13_cases']==12288
assert summaries['reserved_velocity']['comparisons']==16480
assert summaries['dte']['comparisons']==65536
assert summaries['numeric']['exact_comparisons']==20936723
assert summaries['cpr']['counts']['calls']==535748 and summaries['cpr']['counts']['D009']==204
assert summaries['tracking']['messages']==178297 and summaries['tracking']['resolved_positions']==16460 and summaries['tracking']['mismatches']==0

fresh=load(BASE/'fresh-message/summary.json');fixed=summaries['message']
fresh_record=load(BASE/'fresh-message-run.json');fresh_verify=load(BASE/'fresh-final-verification.json');seeds=load(BASE/'fresh-seeds.json')
assert fresh_record['status']=='passed' and fresh_record['exit_code']==0 and fresh_verify['status']=='passed'
expected=load(BASE/'independent-review/final-bindings.json')
assert sha(BASE/'fresh-final-verification.json')==expected['fresh_final_verification_sha256']
assert fresh_record['summary_sha256']==fresh_verify['summary_sha256']==sha(BASE/'fresh-message/summary.json')
assert fresh_record['seed_record_sha256']==sha(BASE/'fresh-seeds.json')
assert fresh_verify['run_record_sha256']==sha(BASE/'fresh-message-run.json')
assert seeds['message_seed']==fresh['seed']
assert seeds['recorded_utc']<fresh_record['started_utc'] and fixed['seed']!=fresh['seed']
assert fresh_record['source_sha256_before']==fresh_record['source_sha256_after']
assert fresh_record['binary_sha256_before']==fresh_record['binary_sha256_after']
assert len(fresh_record['source_sha256_before'])==111 and len(fresh_record['binary_sha256_before'])==3
for inventory in (fresh_record['source_sha256_before'],fresh_record['binary_sha256_before']):
    for path,digest in inventory.items():assert sha(path)==digest,path
for summary in (fixed,fresh):
    assert summary['status']=='PASS' and summary['generated_messages']==10000000
    c=summary['message']['counts'];assert c['messages']==10476164==c['exact_matches']+c['D001']
    assert not summary['message']['coverage_errors'] and not summary['message']['mismatch_fields']
    assert len(summary['message']['df'])==32 and len(summary['message']['adsb'])==70 and len(summary['message']['commb'])==14
    assert summary['direct_registers']['counts']['cases']==summary['direct_registers']['counts']['exact_matches']==101244
    for path,digest in summary['source_sha256'].items():assert sha(path)==digest,path
assert fixed['message']['counts']['exact_matches']==9542689 and fixed['message']['counts']['D001']==933475
fresh_artifact_count=0
for path,r in fresh_verify['verified_artifacts'].items():
    assert sha(path)==r['compressed_sha256'];fresh_artifact_count+=1
# The completed verifier already retained the uncompressed-size/hash checks;
# this review binds those checked streams through their compressed hashes.

# Bind all original nine transcript digests, two standalone snapshots and
# the separately verified difference-stream retention without weakening either.
assert fresh_verify['retained_raw_artifact_count']==9 and fresh_artifact_count==11
assert sha(BASE/'fresh-message/summary.json')==expected['fresh_summary_sha256']
retention_path=BASE/'fresh-retained-hashes.json';retention=load(retention_path)
assert sha(retention_path)==expected['fresh_retention_sha256'] and retention['status']=='passed'
assert retention['existing_raw_verification']['sha256']==sha(BASE/'fresh-final-verification.json')
assert retention['existing_raw_verification']['raw_transcripts']==9 and retention['existing_raw_verification']['standalone_snapshots']==2
retention_execution=load(BASE/'fresh-retention-execution.json')
assert retention_execution['exit_code']==0 and not retention_execution['stderr']
assert retention_execution['helper_sha256']==retention_execution['helper_sha256_after']==retention['helper_source_sha256']==sha(BASE/'fresh-retained-hashes.py')
assert retention['retention_execution_sha256']==sha(BASE/'fresh-retention-execution.json')
printed,_=json.JSONDecoder().raw_decode(retention_execution['stdout'])
assert {k:v for k,v in retention.items() if k not in ['files','retention_execution_sha256','verified_utc','exact_membership_count','final_source_hash_count','final_binary_hash_count','final_source_binary_hashes_match']}=={k:v for k,v in printed.items() if k!='verified_utc'}
assert printed['verified_utc']<=retention['verified_utc']
execution=load(BASE/'fresh-execution.json');preflight=load(BASE/'fresh-preflight.json')
assert execution['status']=='passed' and execution['exit_code']==0 and execution['final_source_binary_hashes_match']
assert execution['retained_file_count']==retention['exact_membership_count']==33
assert execution['final_source_hash_count']==retention['final_source_hash_count']==111
assert execution['final_binary_hash_count']==retention['final_binary_hash_count']==3
assert execution['retention_execution_sha256']==sha(BASE/'fresh-retention-execution.json')
assert execution['verification_sha256']==sha(BASE/'fresh-final-verification.json')
assert execution['preflight_sha256']==sha(BASE/'fresh-preflight.json')
assert execution['orchestrator_sha256']==sha(BASE/'fresh-orchestrate.py')
assert preflight['status']=='passed' and preflight['authorized_by']=='/root'
assert preflight['integrated_build_record_sha256']==sha(BASE/'integration/targeted-build.json')
assert preflight['integrated_build_log_sha256']==sha(BASE/'integration/targeted-build.log')
for command in execution['commands']:
    assert command['exit_code']==0 and sha(command['log'])==command['log_sha256']
    assert command['helper_sha256']==command['helper_sha256_after']==sha(command['command'][1])
assert retention_execution['finished_monotonic_ns']>=retention_execution['started_monotonic_ns']
actual_fresh={str(p) for p in BASE.glob('fresh*') if p.is_file() and p!=retention_path}|{str(p) for p in (BASE/'fresh-message').rglob('*') if p.is_file()}
assert actual_fresh==set(retention['files']) and len(actual_fresh)==33
for path,record in retention['files'].items():assert sha(path)==record['sha256'] and Path(path).stat().st_size==record['bytes'],path
expected_differences={'mismatches.jsonl.gz':fresh['message']['counts']['D001'],'standard-differences.jsonl.gz':fresh['message']['counts']['standard_view_differences'],'direct-mismatches.jsonl.gz':0}
assert {Path(p).name for p in retention['diagnostic_streams']}==set(expected_differences)
for path,record in retention['diagnostic_streams'].items():
    assert sha(path)==record['compressed_sha256'] and record['rows']==record['expected_rows']==expected_differences[Path(path).name]
    digest=hashlib.sha256();size=rows=0
    with gzip.open(path,'rb') as stream:
        for chunk in iter(lambda:stream.read(4*1024*1024),b''):
            digest.update(chunk);size+=len(chunk);rows+=chunk.count(b'\n')
    assert digest.hexdigest()==record['decompressed_sha256'] and size==record['decompressed_bytes'] and rows==record['rows']

# Independent replay by a different agent binds the fresh producer's records.
fresh_review_dir=BASE/'fresh-independent-review';fresh_independent=load(fresh_review_dir/'fresh-retention-review.json');fresh_completion=load(fresh_review_dir/'completion.json')
assert sha(fresh_review_dir/'fresh-retention-review.json')==expected['independent_fresh_review_sha256']
assert sha(fresh_review_dir/'completion.json')==expected['independent_fresh_completion_sha256']
assert fresh_independent['status']=='passed_fresh_retention_and_source_binding' and fresh_independent['findings']==[]
assert fresh_completion['status']=='passed' and fresh_completion['findings']==[]
assert fresh_completion['review_sha256']==sha(fresh_review_dir/'fresh-retention-review.json')
assert {str(p.relative_to(fresh_review_dir)) for p in fresh_review_dir.rglob('*') if p.is_file()}==set(fresh_completion['files'])|{'completion.json'}
for path,item in fresh_completion['files'].items():assert sha(fresh_review_dir/path)==item['sha256'] and (fresh_review_dir/path).stat().st_size==item['bytes']
for path,digest in fresh_completion['held_input_hashes'].items():assert sha(path)==digest,path
assert len(fresh_completion['held_input_hashes'])==fresh_completion['held_inputs_unchanged_after_independent_replay']==186
assert len(fresh_completion['native_input_hashes'])==fresh_completion['native_inputs_unchanged_after_independent_replay']==expected['native_inputs']
for path,digest in fresh_completion['native_input_hashes'].items():assert sha(path)==digest,path
assert fresh_completion['retained_reviewer_attempts']==expected['independent_fresh_reviewer_attempts']
assert fresh_independent['retention_sha256']==sha(retention_path) and fresh_independent['verifier_sha256']==sha(BASE/'fresh-final-verification.json')
assert fresh_independent['execution_sha256']==sha(BASE/'fresh-execution.json')
assert fresh_independent['counts']==fresh['message']['counts'] and fresh_independent['direct_counts']==fresh['direct_registers']['counts']
assert fresh_independent['successful_retained_members']==33 and fresh_independent['failed_fresh_attempts']==0
assert fresh_independent['unchanged_source_hashes']==111 and fresh_independent['unchanged_binary_hashes']==3
for path,item in fresh_independent['independently_decompressed_raw'].items():
 record=fresh_verify['verified_artifacts'][path];assert item=={'sha256':record['uncompressed_sha256'],'bytes':record['uncompressed_bytes']}
assert len(fresh_independent['independently_decompressed_raw'])==11
for path,item in fresh_independent['independently_decompressed_diagnostic_streams'].items():
 record=retention['diagnostic_streams'][path];assert item=={'sha256':record['decompressed_sha256'],'bytes':record['decompressed_bytes'],'rows':record['rows']}
assert len(fresh_independent['independently_decompressed_diagnostic_streams'])==3
plan_review=load(BASE/'independent-review/benchmark-preparation-review.json')
assert sha(BASE/'independent-review/benchmark-preparation-review.json')==expected['benchmark_preparation_review_sha256']
assert plan_review['status']=='passed' and plan_review['findings']==[] and plan_review['prior_result_rows']==30
assert plan_review['exact_target']=={'numerator':3,'denominator':2} and not plan_review['measurement_started_by_reviewer']
for path,digest in plan_review['files'].items():assert sha(path)==digest,path

# The completed gen14 benchmark and diagnostic are immutable historical evidence.
history=load(BASE/'independent-review/gen14-complete-history.json')
assert history['gen14_final_review_sha256']=='0409d020646467981d2b0af210429c9505bbb3927c38cde218d9674df491f5e3'
assert {str(p) for root in history['roots'] for p in Path(root).rglob('*') if p.is_file()}==set(history['files'])
for path,item in history['files'].items():assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
prior_review=load('tests/evidence/diagnostics/gen14/independent-review.json')
assert prior_review['non_review_evidence_membership_count']==history['non_review_diagnostic_membership']==597
assert prior_review['archive_files']==575
preparation=load(BASE/'independent-review/preparation.json')
for path,digest in preparation['history_sha256'].items():assert sha(path)==digest,path
prior=Path('tests/evidence/diagnostics/gen14');diagnostic_manifest=load(prior/'archive-manifest.json')
for name,r in diagnostic_manifest['files'].items():
    p=prior/name;assert p.stat().st_size==r['stored_bytes'] and sha(p)==r['stored_sha256']
bench=Path('bench/runs/gen14');bench_manifest=load(bench/'archive-verification.json')
for name,item in bench_manifest['files'].items():
    assert sha(bench/name)==item['sha256']==sha(Path(bench_manifest['source'])/name)
    assert (bench/name).stat().st_size==item['bytes']
assert len(bench_manifest['files'])==48
older=load(prior/'historical-inputs.json');assert len(older['files'])==preparation['prior_gen14_history_files']==11640
members={str(p) for root in older['roots'] for p in Path(root).rglob('*') if p.is_file()}|set(older['individual_paths'])
assert members==set(older['files'])
for path,item in older['files'].items():assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
raw_perf={}
for generation in range(15):
    cap_path=Path('tests/evidence/diagnostics')/f'gen{generation}'/'perf/capture.json'
    capture=load(cap_path);raw=capture['raw_data']
    assert sha(raw['path'])==raw['sha256'] and Path(raw['path']).stat().st_size==raw['bytes']
    raw_perf[str(cap_path)]=raw['sha256']
# Preserve source/proof/native review bindings. The helper author reviews
# evidence bindings here; cost_analysis independently reviews proof/native and fresh retention.
integrated=load(BASE/'independent-review/integration-review.json')
assert integrated['status']=='passed_integrated_build_and_refinement_binding_review' and integrated['findings']==[]
for path,digest in integrated['final_source_sha256'].items():assert sha(path)==digest==inputs[path]
item=integrated['successful_integrated_build']
assert sha(item['manifest'])==item['manifest_sha256'] and sha(item['log'])==item['log_sha256']
assert item['exit_code']==0 and item['jobs']==expected['integrated_jobs']
proof_review_path=Path(expected['independent_proof_review_path']);proof_review=load(proof_review_path)
assert sha(proof_review_path)==expected['independent_proof_review_sha256']
assert proof_review['status']=='passed' and proof_review['findings']==[]
assert proof_review['sources']=={p:h for p,h in integrated['final_source_sha256'].items() if p!='Proofs/Decoder.lean'}
for path,item in proof_review['inputs'].items():
    assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
integration_proof=load(BASE/'native-review/integration-proof-review.json')
assert sha(BASE/'native-review/integration-proof-review.json')==expected['independent_integration_proof_review_sha256']
assert integration_proof['status']=='passed' and integration_proof['findings']==[]
assert integration_proof['source_proof_review_sha256']==sha(proof_review_path)
assert integration_proof['sources']==integrated['final_source_sha256']
assert integration_proof['integrated_build_sha256']==sha(BASE/'integration/targeted-build.json')
assert integration_proof['integrated_log_sha256']==sha(BASE/'integration/targeted-build.log')
assert integration_proof['integrated_allowed_axiom_facts']==len(integrated['all_successful_printed_axioms'])==expected['integrated_fact_count']
assert {x['name']:x['axioms'] for x in integration_proof['integrated_facts']}==integrated['all_successful_printed_axioms']
native=load(BASE/'native-review/review.json');native_inputs=load(BASE/'native-review/inspection-inputs.json')
assert native['integration_proof_review_sha256']==sha(BASE/'native-review/integration-proof-review.json')
assert native['status']=='passed' and all(native['checks'].values()) and native['all_captured_inputs_unchanged']
assert len(native['checks'])==expected['native_checks'] and len(native_inputs['inputs'])==expected['native_inputs']
assert sha(BASE/'native-review/review.json')==expected['native_review_sha256']
assert sha(BASE/'native-review/inspection-inputs.json')==expected['native_inspection_sha256']
native_binding=load(BASE/'independent-review/native-binding-review.json')
assert native_binding['status']=='passed_independent_native_binding_review' and native_binding['findings']==[]
assert native_binding['native_review_sha256']==sha(BASE/'native-review/review.json')
assert native_binding['native_inspection_sha256']==sha(BASE/'native-review/inspection-inputs.json')
assert native_binding['integration_review_sha256']==sha(BASE/'independent-review/integration-review.json')
assert native_binding['native_inputs']==len(native_inputs['inputs']) and native_binding['native_files']==len(native['files'])
assert native_binding[expected['native_live_path_key']]
assert sha(BASE/'independent-review/native-binding-review.json')==expected['native_binding_review_sha256']
for path,digest in native_binding['execution_log_bindings'].items():assert sha(path)==digest,path
for path,item in native['files'].items():
    p=BASE/'native-review'/path;assert sha(p)==item['sha256'] and p.stat().st_size==item['bytes'],p
for path,item in native_inputs['inputs'].items():assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
retained_native=native_inputs.get('retained',native_inputs.get('retained_files',{}));assert retained_native
for original,retained in retained_native.items():assert sha(BASE/'native-review'/retained)==sha(original)
locked=0
for line in Path('spec.lock').read_text().splitlines():
    match=re.fullmatch(r'([0-9a-f]{64})\s+(.+)',line)
    if match:
        digest,path=match.groups();assert sha(path)==digest;locked+=1
assert locked==104 and sha('spec.lock')=='5217cce1fcaab1267b9544acf56992bec8accee67fb1645446887cba37bffaf8'
prefix=BASE/'independent-review/results-prefix-before-gen15.csv'
assert sha(prefix)==preparation['result_prefix_sha256']
assert Path('bench/results.csv').read_bytes()==prefix.read_bytes()
assert len(list(csv.DictReader(io.StringIO(prefix.read_text()))))==30
assert provenance.gate_input_hashes()==inputs
cleanup_review=load(BASE/'independent-review/post-gate-cleanup-review.json')
cleanup_binding=load(BASE/'independent-review/cleanup-tooling-bindings.json')
assert cleanup_review['status']=='passed' and cleanup_review['findings']==[]
assert cleanup_review['correctness_inputs_unchanged']==186
assert cleanup_review['gate_archive_sha256']==sha(BASE/'gate-archive.json')
assert cleanup_review['tooling_bindings_sha256']==sha(BASE/'independent-review/cleanup-tooling-bindings.json')
assert cleanup_review['script_sha256']==sha(BASE/'independent-review/check_post_gate_cleanup.py')
for inventory in (cleanup_review['receipt_files'],cleanup_binding['evidence_files']):
    for path,item in inventory.items():
        assert sha(path)==item['sha256'] and Path(path).stat().st_size==item['bytes'],path
assert {str(p) for p in (BASE/'post-gate-archive-cleanup').rglob('*') if p.is_file()}==set(cleanup_review['receipt_files'])
for path,digest in cleanup_binding['helpers'].items():assert sha(path)==digest,path
assert all(not Path(path).exists() for path in cleanup_review['deleted_directories'])
assert all(Path(row['directory']).is_dir() for row in cleanup_review['retained_directories'])
result={'status':'passed','reviewer':'payload_roundtrips','recorded_utc':datetime.now(timezone.utc).isoformat(),
 'post_gate_cleanup':{'review_sha256':sha(BASE/'independent-review/post-gate-cleanup-review.json'),'receipt_files':len(cleanup_review['receipt_files']),'deleted_directories':cleanup_review['deleted_directories'],'retained_directories':cleanup_review['retained_directories'],'deleted_allocated_bytes':cleanup_review['deleted_allocated_bytes'],'reviewed_tooling_sha256':sha(BASE/'independent-review/cleanup-tooling-bindings.json')},
 'prior_full_gate_attempt':{'status':'interrupted_not_passed','review_sha256':sha(BASE/'independent-review/interruption-review.json'),'completed_components_before_interruption':6,'retained_snapshot_files':interruption['snapshot_file_count'],'retained_snapshot_bytes':interruption['snapshot_bytes'],'current_pass_is_a_new_complete_run':True},
 'authorized_cleanup_review':{'readiness_sha256':sha(BASE/'independent-review/resume-readiness.json'),'receipt_files_rechecked':len(resume['cleanup_evidence_files']),'retained_source_and_history_checks_waived':0,'fresh_campaign_reused_after_unchanged_111_source_3_binary_binding':True,'reviewer_attempt_bindings_sha256':sha(BASE/'independent-review/resume-bindings.json')},
 'scope':'Read-only full-gate/current-source, complete seven-component archive, fresh-campaign provenance and historical artifact-integrity review; no builds/tests/native decoder runs.',
 'gate_verification':verification,'correctness_inputs':186,'exact_capstone_types':23,'witness_axiom_audits':152,'unit_fixture_assertions':1011,
 'component_archive_files':component_counts,'complete_component_archive_files':retained_total,'complete_component_archive_bytes':retained_bytes,
 'every_component_original_and_retained_membership_size_sha_matches':True,'every_component_summary_bound_to_passed_full_gate_log':True,
 'fixed_message_counts':fixed['message']['counts'],'fresh_message_counts':fresh['message']['counts'],'direct_register_cases_each':101244,
 'fixed_message_seed':fixed['seed'],'fresh_message_seed':seeds['message_seed'],'fresh_commb_seed':seeds['commb_seed'],
 'fresh_source_hashes':111,'fresh_binary_hashes':3,'fresh_compressed_artifact_hashes':fresh_artifact_count,
 'supplemental_fresh_retention_sha256':sha(retention_path),'fresh_retained_membership_files':len(actual_fresh),'fresh_difference_streams_redecompressed_and_row_counted':3,
 'gen14_benchmark_files_unchanged':len(bench_manifest['files']),'gen14_diagnostic_archive_files_unchanged':len(diagnostic_manifest['files']),
 'gen14_report_review_manifest_and_raw_perf_unchanged':True,'gen14_complete_historical_files_verified':len(history['files']),'gen14_non_review_diagnostic_membership_preserved':597,
 'older_historical_files_verified':len(older['files']),'prior_raw_perf_hashes':raw_perf,
 'reviewed_hashes':{str(p):sha(p) for p in [BASE/'gate-evidence.json',BASE/'gate-full.log',BASE/'gate-archive.json',BASE/'fresh-message-run.json',BASE/'fresh-final-verification.json',BASE/'fresh-seeds.json',BASE/'native-review/review.json',BASE/'native-review/inspection-inputs.json',proof_review_path,Path(__file__)]},
 'independent_fresh_retention_reviewer_attempts':fresh_completion['retained_reviewer_attempts'],
 'independent_fresh_retention_review_sha256':sha(fresh_review_dir/'fresh-retention-review.json'),'independent_fresh_retention_completion_sha256':sha(fresh_review_dir/'completion.json'),'benchmark_preparation_review_sha256':sha(BASE/'independent-review/benchmark-preparation-review.json'),
 'independent_integration_proof_review_sha256':sha(BASE/'native-review/integration-proof-review.json'),
 'independent_native_binding_review_sha256':sha(BASE/'independent-review/native-binding-review.json'),
 'independent_helper_proof_review':{'path':str(proof_review_path),'sha256':sha(proof_review_path),'reviewer':'cost_analysis'},
 'native_review_files_verified':len(native['files']),'native_review_inputs_verified':len(native_inputs['inputs']),
 'frozen_files_checked':locked,'historical_result_rows_preserved':30,'historical_result_prefix_sha256':sha(prefix),
 'remaining_findings':[],'limitations':['This verifies retained successful executions and their source/artifact bindings; it does not rerun tests.','Original nine fresh transcripts and two snapshots were bound by compressed SHA to completed decompression-verification records. The three extra difference streams were independently decompressed and row-counted in this review.','The gate reviewer produced the fresh campaign; cost_analysis independently verifies its source/binary/raw retention. The separate independent proof/native assessment is retained and bound.','Benchmark timing has not occurred in this review.']}
assert not OUT.exists();OUT.write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({k:result[k] for k in ['status','correctness_inputs','complete_component_archive_files','complete_component_archive_bytes','fixed_message_counts','fresh_message_counts','gen14_benchmark_files_unchanged','gen14_diagnostic_archive_files_unchanged']},indent=2))
print('gate_review_sha256',sha(OUT))

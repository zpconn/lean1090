#!/usr/bin/env python3
"""Read-only post-gate evidence review; writes only gate-review.json beside itself."""
from pathlib import Path
from datetime import datetime, timezone
import csv, gzip, hashlib, importlib.util, io, json, re, sys

sys.dont_write_bytecode=True
ROOT=Path.cwd()
BASE=Path('tests/evidence/optimization/gen3')
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
verification=provenance.verify_gate_evidence(gate,sha(BASE/'gate-full.log'),inputs)
assert len(inputs)==174 and archive['status']=='passed' and archive['generation']==3
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
assert fresh_record['summary_sha256']==fresh_verify['summary_sha256']==sha(BASE/'fresh-message/summary.json')
assert fresh_record['seed_record_sha256']==sha(BASE/'fresh-seeds.json')
assert fresh_verify['run_record_sha256']==sha(BASE/'fresh-message-run.json')
assert seeds['message_seed']==fresh['seed']==2991522103 and seeds['commb_seed']==2632950597
assert seeds['recorded_utc']<fresh_record['started_utc'] and fixed['seed']!=fresh['seed']
assert fresh_record['source_sha256_before']==fresh_record['source_sha256_after']
assert fresh_record['binary_sha256_before']==fresh_record['binary_sha256_after']
assert len(fresh_record['source_sha256_before'])==99 and len(fresh_record['binary_sha256_before'])==3
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
assert fresh['message']['counts']['exact_matches']==9542847 and fresh['message']['counts']['D001']==933317
fresh_artifact_count=0
for path,r in fresh_verify['verified_artifacts'].items():
    assert sha(path)==r['compressed_sha256'];fresh_artifact_count+=1
# The completed verifier already retained the uncompressed-size/hash checks;
# this review binds those checked streams through their compressed hashes.

# Preserve the already-reviewed generation-2 benchmark and raw diagnostics.
gen2=Path('tests/evidence/diagnostics/gen2');diagnostic_manifest=load(gen2/'archive-manifest.json')
assert sha(gen2/'archive-manifest.json')=='30129816421c646a544b07afcbd5ed2c052005719eb8e0486e0aea039d2987d7'
assert sha('docs/GEN2-COST-BREAKDOWN.md')=='5ad33dd7012933d45a839fc713493d6347191b133983dd041247ba21973203c0'
assert sha(gen2/'independent-review.json')=='38b36c2b71ffdb100490fc003da9bf5abee66ac46c1721b3b796752dd1ecfa40'
for name,r in diagnostic_manifest['files'].items():
    p=gen2/name;assert p.stat().st_size==r['stored_bytes'] and sha(p)==r['stored_sha256']
capture=load(gen2/'perf/capture.json');assert sha(capture['raw_data']['path'])==capture['raw_data']['sha256']
bench=Path('bench/runs/gen2');bench_manifest=load(bench/'archive-verification.json')
for name,digest in bench_manifest['files'].items():
    assert sha(bench/name)==digest==sha(Path(bench_manifest['source_directory'])/name)
assert len(bench_manifest['files'])==48
assert provenance.gate_input_hashes()==inputs
result={'status':'passed','reviewer':'payload_roundtrips','recorded_utc':datetime.now(timezone.utc).isoformat(),
 'scope':'Read-only full-gate/current-source, complete seven-component archive, fresh-campaign provenance and prior-generation artifact-integrity review; no builds/tests/native decoder runs.',
 'gate_verification':verification,'correctness_inputs':174,'exact_capstone_types':23,'witness_axiom_audits':152,'unit_fixture_assertions':1011,
 'component_archive_files':component_counts,'complete_component_archive_files':retained_total,'complete_component_archive_bytes':retained_bytes,
 'every_component_original_and_retained_membership_size_sha_matches':True,'every_component_summary_bound_to_passed_full_gate_log':True,
 'fixed_message_counts':fixed['message']['counts'],'fresh_message_counts':fresh['message']['counts'],'direct_register_cases_each':101244,
 'fixed_message_seed':fixed['seed'],'fresh_message_seed':seeds['message_seed'],'fresh_commb_seed':seeds['commb_seed'],
 'fresh_source_hashes':99,'fresh_binary_hashes':3,'fresh_compressed_artifact_hashes':fresh_artifact_count,
 'gen2_benchmark_files_unchanged':len(bench_manifest['files']),'gen2_diagnostic_archive_files_unchanged':len(diagnostic_manifest['files']),
 'gen2_report_review_manifest_and_raw_perf_unchanged':True,
 'reviewed_hashes':{str(p):sha(p) for p in [BASE/'gate-evidence.json',BASE/'gate-full.log',BASE/'gate-archive.json',BASE/'fresh-message-run.json',BASE/'fresh-final-verification.json',BASE/'fresh-seeds.json',Path(__file__)]},
 'remaining_findings':[],'limitations':['This verifies retained successful executions and their source/artifact bindings; it does not rerun tests.','Large fresh transcripts were checked by compressed SHA against the completed decompression-verification record; decompression was not repeated.','Benchmark timing has not occurred in this review.']}
assert not OUT.exists();OUT.write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({k:result[k] for k in ['status','correctness_inputs','complete_component_archive_files','complete_component_archive_bytes','fixed_message_counts','fresh_message_counts','gen2_benchmark_files_unchanged','gen2_diagnostic_archive_files_unchanged']},indent=2))
print('gate_review_sha256',sha(OUT))

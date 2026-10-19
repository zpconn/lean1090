#!/usr/bin/env python3
"""Independent retained CPR input/output, native-build and perf evidence checks."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from collections import Counter
from datetime import datetime,timezone
import gzip,hashlib,json,re,subprocess
B=Path('tests/evidence/diagnostics/gen23-cpr');R=B/'independent-review'
def data(p):
 p=Path(p);return gzip.decompress(p.read_bytes()) if p.suffix=='.gz' else p.read_bytes()
def read(p):return json.loads(data(p))
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(1<<20),b''):h.update(b)
 return h.hexdigest()
m=read(B/'archive-manifest.json');stored=rawbytes=0
for n,r in m['files'].items():
 p=B/n;assert sha(p)==r['stored_sha256'] and p.stat().st_size==r['stored_bytes'],n
 raw=data(p) if r['encoding']!='identity' else p.read_bytes()
 assert hashlib.sha256(raw).hexdigest()==r['source_sha256'] and len(raw)==r['source_bytes'],n
 assert sha(r['source'])==r['source_sha256'],n
 stored+=p.stat().st_size;rawbytes+=len(raw)
assert len(m['files'])==m['file_count'] and stored==m['stored_bytes']
for p,r in m['omitted_binaries'].items():assert sha(p)==r['sha256'] and Path(p).stat().st_size==r['bytes']
source=read(B/'independent-review/source-review.json');assert sha(B/'independent-review/source-review.json')=='cb39fc1cadaefc2a1c194e8feb340c3d92447292ae623e9cf38bd4e230b574da'
for r in source['commands']:assert r['exit_code']==0 and sha(r['output'])==r['sha256']
for r in source['generated_C_excerpts'].values():
 assert sha(r['path'])==r['sha256'] and sha(r['source'])==r['source_sha256']
 assert Path(r['path']).read_text() in Path(r['source']).read_text()
for k in ['actual_frozen_preparation_and_routing_text_equal','output_capacity_and_empty_state_before_root','complete_outputs_and_state_retained','live_decode_then_immediate_streamStep','post_collection_consumer_and_batch_audit','byte_crc_live_path_verified','integer_affine_normalization_live_path_verified','raw_word_syndrome_live_path_verified','commb_validity_tables_live_path_verified']:assert source[k]
build=read(B/'retained/driver-final/driver-build.json');val=read(B/'retained/validation/summary.json');run=read(B/'retained/callgrind/run.json')
assert build['status']==val['status']==run['status']=='passed'
assert sha(B/'retained/driver-final/driver-build.json')==source['driver_build_manifest_sha256']==val['build_sha256']
assert build['commit']==source['commit']==subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()
assert build['reused_production_object_count']==21 and build['fresh_benchmark_native_binding']['linked_project_objects']==22
assert sha(build['fresh_benchmark_native_binding']['path'])==build['fresh_benchmark_native_binding']['sha256']
assert build['lock_sha256']==sha('spec.lock')
for group in ['unchanged_native_inputs','artifacts','production_sources']:
 for p,h in build[group].items():assert sha(p)==h,p
assert val['inputs_before']==val['inputs_after']==dict(build['unchanged_native_inputs'],**build['artifacts'])
for p,h in val['inputs_before'].items():assert sha(p)==h,p
for command in build['commands']:
 if command['label']=='driver-clang':
  argv=command['argv'];assert '-O3' in argv and '-ffp-contract=off' in argv and not any(x.startswith(('-march=','-mcpu=','-mtune=')) for x in argv)
assert run['hashes']['binary']==build['artifacts']['.cache/gen23-cpr-costs/driver-final/cpr-costs']==source['driver_sha256']
assert run['hashes']['lock']==sha('spec.lock') and run['hashes']['corpus']==sha('vendor/rs1090/crates/rs1090/data/long_flight.csv')
assert run['prepared']['selected']==run['decoded']['retained']==172432 and run['prepared']['airports']==6903
assert run['prepared']['reference'] is None and run['prepared']['update_reference'] is False
assert '--instr-atstart=no' in run['argv'] and '--collect-atstart=no' in run['argv'] and '--toggle-collect='+source['root'] in run['argv']
assert run['root']==source['root'] and run['events']=='Ir'
assert [r['label'] for r in run['control']]==['initial-state','instrument-on','enabled-state','dump','instrument-off','disabled-state']
for c in run['control']:assert c['returncode']==0 and '--max-invoke-ms=0' in c['argv']
for n,t in [('initial-state','instrumentation: off'),('enabled-state','instrumentation: on'),('disabled-state','instrumentation: off')]:assert (B/'retained/callgrind'/f'{n}.stdout').read_text().startswith(t)
# Replay retained audits, never execute the worker or diagnostic.
for kind,n in [('inputs',172432),('airports',6903)]:
 left=data(B/'retained/validation'/f'driver-{kind}.stdout.gz');right=data(B/'retained/validation'/f'worker-{kind}.stdout.gz')
 assert left==right and len(left.splitlines())==n
 expected=next(x for x in val['comparisons'] if x['kind']==kind);assert hashlib.sha256(left).hexdigest()==expected['sha256']
left=data(B/'retained/validation/driver-tracking.jsonl.gz');right=data(B/'retained/validation/worker-tracking.stdout.gz');assert left==right
rows=[json.loads(x) for x in left.splitlines()];assert len(rows)==172433 and rows[-1]['final'] is True
assert [r['id'] for r in rows[:-1]]==list(range(172432))
assert sum(r['position'] is not None for r in rows[:-1])==val['resolved_positions']==11347
assert val['tracking_rows']==val['tracking_bit_identical']==172432
assert val['result']['final_state']==rows[-1] and len(rows[-1]['aircraft'])==29
actual=run['result'].copy();expected=val['result'].copy();assert actual.pop('batch_state_check') is False and expected.pop('batch_state_check') is True and actual==expected
assert val['complete_batch_StreamState_and_routed_positions_equal'] and val['final_state_projection_exact']
decode_rows=[json.loads(x) for x in Path('tests/evidence/diagnostics/gen23/native/all.jsonl').read_text().splitlines() if x]
assert val['result']['digest']==next(x['digest'] for x in decode_rows if x.get('phase')=='result')
# Perf: independently parse all raw retained stacks, periods and leaf counts.
cap=read(B/'perf/capture.json');comp=read(B/'perf/completion.json');perf=read(B/'perf/analysis.json')
assert comp['capture_exit_code']==comp['analysis_exit_code']==cap['record_exit_code']==0
assert cap['before_hashes']==cap['after_hashes']
for p,h in cap['before_hashes'].items():assert sha(p)==h,p
assert len(cap['before_hashes'])==comp['captured_input_hash_count']==293
assert cap['mode']=='cpr' and cap['stdin']=='run\nquit\n'
assert cap['affinity_requested']==[0]
assert cap['raw_data']==comp['raw_data']
assert sha(cap['raw_data']['path'])==cap['raw_data']['sha256']
assert sha(B/'perf/capture.json')==comp['capture_sha256']
blocks=[x for x in (B/'perf/script.txt').read_text().split('\n\n') if x.strip()];included=[];stages=Counter();unknown=0;leaves=Counter();allleaves=Counter();nested=Counter()
for i,block in enumerate(blocks):
 lines=block.splitlines();period=re.search(r':\s+(\d+) cpu-clock:u:',lines[0]);assert period
 frames=[]
 for line in lines[1:]:
  match=re.match(r'^\s*([0-9a-f]+)\s+(.*?)\s+\((.*?)\)\s*$',line)
  if match:frames.append({'ip':match[1],'symbol':re.sub(r'\+0x[0-9a-f]+$','',match[2]),'dso':match[3]})
 names=[f['symbol'] for f in frames];leaf=names[0] if names else 'no_frames';allleaves[leaf]+=1;unknown+=int('[unknown]' in names)
 if not any('runCPROnce' in n for n in names) or any('WholeDecoder_consume' in n for n in names):continue
 if 'lp_lean1090_Lean1090_Impl_decode' in names:stage='decoder'
 elif any('Lean1090_Impl_CPR_Policy_' in n for n in names):stage='CPR policy or numerical geography'
 elif any('trackingReport' in n or 'WholeDecoder_advance' in n for n in names):stage='tracking projection or unresolved advance'
 else:stage='loop, output control or erased ancestry'
 stages[stage]+=1;leaves[leaf]+=1
 for k,test in [('software binary64','Impl_Binary64_'),('rational arithmetic','Rat_'),('haversine','haversineFloat'),('global position','decodeGlobalFloat'),('local position','decodeLocalFloat'),('motion checks','validMotion')]:
  if any(test in n for n in names):nested[k]+=1
 included.append({'sample_index':i,'period':int(period[1]),'stage':stage,'leaf':leaf,'stack':frames})
assert included==[json.loads(x) for x in (B/'perf/loop-samples.jsonl').read_text().splitlines()]
assert len(blocks)==perf['total_samples']==comp['samples']
assert len(included)==perf['visible_CPR_loop_samples']==comp['included_cpr_loop_stacks']
assert len(blocks)-len(included)==perf['excluded_samples']
assert unknown==perf['all_samples_with_unknown_frame']==comp['unknown_frame_stacks']
assert leaves['[unknown]']==perf['included_unknown_leaves']==comp['unknown_cpr_leaf_samples']
assert dict(stages)==perf['disjoint_visible_stages'] and dict(nested)==perf['nested_overlapping_categories']
assert [list(x) for x in leaves.most_common(30)]==perf['included_leaf_top30']
assert [list(x) for x in allleaves.most_common(30)]==perf['all_leaf_top30']
for n in ['report-self.txt','report-children.txt']:assert '# Total Lost Samples: 0' in (B/'perf'/n).read_text().splitlines()
sequence=read(B/'isolated-perf-completion.json');assert sequence['status']=='passed' and sequence['sequential_modes']==['decode','cpr']
prev=None
for row in sequence['results']:
 assert sha(row['capture'])==row['capture_sha256'];record=read(row['capture'])
 assert record['raw_data']==row['raw'] and sha(row['raw']['path'])==row['raw']['sha256']
 if prev:assert prev<=record['started_utc']
 prev=record['completed_utc']
# Deterministic compressed analysis retains the exact raw content and explicitly
# records raw/stored hashes; independent raw recount covers all contexts.
ret=read(B/'analysis-retention.json')
for row in ret['files']:
 raw=data(row['retained']);assert sha(row['retained'])==row['compressed_sha256'] and len(raw)==row['raw_bytes'] and hashlib.sha256(raw).hexdigest()==row['raw_sha256']
 assert sha(row['source'])==row['raw_sha256']
out={'status':'passed','recorded_utc':datetime.now(timezone.utc).isoformat(),'archive_manifest_sha256':sha(B/'archive-manifest.json'),'archive_files':len(m['files']),'archive_stored_bytes':stored,'archive_decoded_bytes':rawbytes,'omitted_bound_files':len(m['omitted_binaries']),'native_build_sha256':sha(B/'retained/driver-final/driver-build.json'),'source_review_sha256':sha(B/'independent-review/source-review.json'),'fresh_native_sets':22,'reused_objects':21,'input_hashes_checked':len(val['inputs_before']),'tracking_rows_exact':172432,'resolved_positions_exact':11347,'full_batch_state_equal':True,'input_rows_exact':172432,'airport_rows_exact':6903,'full_message_digest':val['result']['digest'],'profile_matches_native_audit':True,'perf_samples':len(blocks),'perf_included':len(included),'perf_excluded':len(blocks)-len(included),'perf_unknown_stacks':unknown,'perf_included_unknown_leaves':leaves['[unknown]'],'perf_lost_samples':0,'perf_stages':dict(stages),'perf_all_293_inputs_unchanged':True,'isolated_sequence_verified':True,'script_sha256':sha(__file__),'findings':[]}
assert not (R/'evidence-checks.json').exists()
(R/'evidence-checks.json').write_text(json.dumps(out,indent=2)+'\n');print(json.dumps(out,indent=2))

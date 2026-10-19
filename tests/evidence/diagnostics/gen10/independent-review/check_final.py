#!/usr/bin/env python3
"""Read-only independent gen10 evidence checks; writes only its scratch result."""
from pathlib import Path
from collections import Counter
from datetime import datetime, timezone
import gzip, hashlib, json, re, subprocess

BASE = Path('tests/evidence/diagnostics/gen10')
def read(p): return json.loads(Path(p).read_text())
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p): return [json.loads(x) for x in Path(p).read_text().splitlines() if x]

manifest=read(BASE/'archive-manifest.json')
analysis=read(BASE/'analysis/analysis.json')
campaign=read(BASE/'campaign.json')
build=read(BASE/'driver/driver-build.json')
validation=read(BASE/'validation.json')
assert validation['status']==campaign['status']==build['status']=='passed'
assert len(manifest['files'])==manifest['file_count']==validation['archive_files']
stored=0
for name,record in manifest['files'].items():
    p=BASE/name; b=p.read_bytes();stored+=len(b)
    assert len(b)==record['stored_bytes'] and hashlib.sha256(b).hexdigest()==record['stored_sha256'],name
    decoded=gzip.decompress(b) if 'gzip' in record['encoding'] else b
    assert len(decoded)==record['source_bytes'] and hashlib.sha256(decoded).hexdigest()==record['source_sha256'],name
assert stored==manifest['stored_bytes']
for name,record in manifest['files'].items():
    source=Path(record['source'])
    if name=='tooling/write_cost_report.py':
        correction=validation['renderer_correction']
        assert record['source_sha256']==correction['original_renderer_sha256']
        assert sha(source)==correction['renderer_sha256']==sha(BASE/'renderer-correction/write_cost_report.py')
        assert sha(BASE/'renderer-correction/change.diff')==correction['diff_sha256']
    else:
        assert sha(source)==record['source_sha256'] and source.stat().st_size==record['source_bytes'],name
for name,record in manifest['omitted_binaries'].items():
    assert sha(name)==record['sha256'] and Path(name).stat().st_size==record['bytes'],name
for name,digest in campaign['protected_inputs'].items(): assert sha(name)==digest,name
assert len(campaign['protected_inputs'])==validation['protected_input_count']

# Independently parse only self costs and native edge entry counts. Do not use
# the production analyzer/parser for the recount.
def recount(p, root, context_output=None):
    names={};current=None;callee=None;edge=False;total=0;reported={};incoming=Counter();self_cost=Counter();inclusive=Counter();edge_counts=Counter();edge_ir=Counter();pos=0
    def namekey(v):
        m=re.fullmatch(r'\((\d+)\)(?: (.*))?',v)
        if m:
            key=('id',m[1])
            if m[2] is not None:
                assert key not in names or names[key]==m[2]
                names[key]=m[2]
            return key
        return ('name',v)
    with gzip.open(p,'rt') as f:
        for line in f:
            line=line.strip()
            if line.startswith('positions:'): pos=len(line.split()[1:])
            elif line.startswith('events:'): assert line.split()[1:]==['Ir']
            elif line.startswith(('summary:','totals:')):
                k,v=line.split(':'); reported[k]=int(v)
            elif line.startswith('fn='): current=namekey(line[3:])
            elif line.startswith('cfn='): callee=namekey(line[4:])
            elif line.startswith('calls='):
                assert callee is not None
                count=int(line.split('=',1)[1].split()[0]);incoming[callee]+=count;edge_counts[(current,callee)]+=count;edge=True
            elif line and (line[0].isdigit() or line[0] in '+-*'):
                fields=line.split();assert len(fields)==pos+1,(p,line)
                if edge:
                    inclusive[callee]+=int(fields[pos]);edge_ir[(current,callee)]+=int(fields[pos]);edge=False
                else:
                    total+=int(fields[pos]);self_cost[current]+=int(fields[pos])
    assert not edge
    assert total==reported.get('summary',0)==reported.get('totals',0),(p,total,reported)
    entries=Counter()
    for key,n in incoming.items():
        name=names[key] if key[0]=='id' else key[1]
        entries[re.split(r"'| \[clone ",name,maxsplit=1)[0]]+=n
    # The retained full caller contexts provide a second attribution route,
    # independent of the analyzer's graph propagation implementation.
    stages=Counter();prefix='lp_lean1090_Lean1090_Impl_'
    def context_stage(key):
        name=names[key] if key[0]=='id' else key[1]
        chain=name.split("'")
        if root not in chain: return None
        stage='output_model_control' if root==prefix+'decode' else 'commb_inference'
        for symbol in reversed(chain[:chain.index(root)]):
            local=symbol.removeprefix(prefix)
            if 'Lean1090_Impl_Semantics_' in symbol or 'Lean1090_Impl_Presentation_' in symbol:stage='semantic_oracle_values'
            elif stage in ('commb_inference','semantic_oracle_values'):pass
            elif local in ('frameCommB','inferCommB','commBEligible','commBCoreEligible'):stage='commb_inference'
            elif local in ('frameADSB','decodeADSB','adsbHardValid'):stage='adsb_fields'
            elif local in ('frameAltitude','frameOracleAltitude','frameIdentity'):stage='semantic_oracle_values'
            elif local in ('decodeFrame','frameSyndrome','frameAddress','frameAccepted','frameAddressWithSyndrome','frameAcceptedWithSyndrome') or symbol.startswith(prefix+'Parity_'):stage='frame_crc'
        return stage
    grouped={}
    allkeys=set(self_cost)|set(incoming)|set(inclusive)
    for key in allkeys:
        stage=context_stage(key)
        if stage is None:
            assert not self_cost[key],(p,key,self_cost[key])
            continue
        name=names[key] if key[0]=='id' else key[1]
        symbol=re.split(r"'| \[clone ",name,maxsplit=1)[0]
        item=grouped.setdefault((stage,symbol),Counter())
        item['self']+=self_cost[key];item['entries']+=incoming[key];item['inclusive']+=inclusive[key];item['contexts']+=1
        stages[stage]+=self_cost[key]
    payload_contexts=[];payload_edges=Counter()
    for key in allkeys:
        name=names[key] if key[0]=='id' else key[1]
        if re.split(r"'| \[clone ",name,maxsplit=1)[0]==prefix+'payloadBits' and context_stage(key) is not None:payload_contexts.append(key)
    for (caller,callee),cost in edge_ir.items():
        if caller in payload_contexts and cost>0:
            name=names[callee] if callee[0]=='id' else callee[1]
            payload_edges[re.split(r"'| \[clone ",name,maxsplit=1)[0]]+=edge_counts[(caller,callee)]
    if context_output is not None:
        def full(key): return names[key] if key[0]=='id' else key[1]
        for key in allkeys:
            if re.split(r"'| \[clone ",full(key),maxsplit=1)[0] not in {prefix+a for a in ['cbMach64','cbQNH64','cbValid40','cbDensityTerms','frameSyndrome','Parity_checksum','frameParts','packFields','Parity_interrogator','payloadValue','field']}:continue
            context_output[full(key)]={
                'stage':context_stage(key),
                'self_events': {'Ir':self_cost[key]},
                'incoming': {full(a): {'calls':n, 'inclusive_events':{'Ir':edge_ir[(a,b)]}} for (a,b),n in edge_counts.items() if b==key},
                'outgoing': {full(b): {'calls':edge_counts[(a,b)],'inclusive_events':{'Ir':n}} for (a,b),n in edge_ir.items() if a==key and n>0}}
    return total,entries,stages,grouped,{'payload_contexts' :len(payload_contexts),'collected_outgoing_calls':dict(payload_edges)}

profiles={**analysis['families'],**{'score'+k:v for k,v in analysis['non_additive_register_score_probes'].items()},
          **{'candidate'+k:v for k,v in analysis['non_additive_register_candidate_probes'].items()}}
assert len(profiles)==13
recounted={};counts={};stage_totals=Counter();grouped_all={};helper_rows_checked=0;payload_edges_all={};mach_contexts={}
jobs={x['mode']:x for x in campaign['profiles']}
assert set(jobs)==set(profiles)
for mode,p in profiles.items():
    path=Path(p['path']);contexts={};total,entries,independent_stages,grouped,edges=recount(path,p['root'],contexts);mach_contexts[mode]=contexts;payload_edges_all[mode]=edges
    run=read(BASE/'callgrind'/mode/'run.json');job=jobs[mode]
    assert total==p['total_events'].get('Ir',0)==run['primary_ir']==job['primary_ir']
    assert p['container_sha256']==sha(path)
    assert p['sha256']==hashlib.sha256(gzip.decompress(path.read_bytes())).hexdigest()==run['profile_files']['callgrind.out.1']
    assert run['status']=='passed' and run['returncode']==0 and job['native_output_matches']
    assert [x['label'] for x in run['control']]==['initial-state','instrument-on','enabled-state','dump','instrument-off','disabled-state']
    assert all(x['returncode']==0 and '--max-invoke-ms=0' in x['argv'] for x in run['control'])
    assert '--instr-atstart=no' in run['argv'] and '--collect-atstart=no' in run['argv'] and '--toggle-collect='+run['root'] in run['argv']
    assert (BASE/'callgrind'/mode/'initial-state.stdout').read_text().strip()=='instrumentation: off'
    assert (BASE/'callgrind'/mode/'enabled-state.stdout').read_text().startswith('instrumentation: on\n')
    assert (BASE/'callgrind'/mode/'disabled-state.stdout').read_text().strip()=='instrumentation: off'
    assert run['prepared']['selected']==run['decoded']['retained']==job['selected']
    if mode in analysis['families']:assert run['prepared']['corpus_rows']==172432
    assert run['root']==p['root'] and entries[p['root']]==p['root_incoming_calls']==job['selected']
    assert run['hashes']['binary']==campaign['driver_binary_sha256']
    assert run['hashes']['corpus']==campaign['corpus_sha256'] and run['hashes']['lock']==build['lock_sha256']
    native=rows(BASE/'native'/f'{mode}.jsonl')
    native_result=next(x for x in native if x.get('phase')=='result')
    assert run['result']['digest']==job['digest']==native_result['digest']
    assert p['stage_attribution_complete'] and p['ambiguous_context_count']==0 and not p['nonzero_outside_root']
    assert sum(v.get('Ir',0) for v in p['exclusive_stage_events'].values())==total
    assert independent_stages==Counter({k:v.get('Ir',0) for k,v in p['exclusive_stage_events'].items()}),(mode,independent_stages)
    assert not p['exclusive_stage_events'].get('outside_root',{}).get('Ir',0)
    for symbol,record in p['native_anchor_counts_and_non_additive_inclusive_events'].items():
        assert entries[symbol]==record['native_entries'],(mode,symbol)
    if mode in analysis['families']:stage_totals.update({k:v.get('Ir',0) for k,v in p['exclusive_stage_events'].items()})
    for stage, helpers in p['stage_helper_observations_non_additive'].items():
        for helper in helpers:
            actual=grouped.get((stage,helper['symbol']),Counter())
            assert actual['contexts']==helper['contexts'],(mode,stage,helper['symbol'],'contexts')
            assert actual['entries']==helper['native_entries'],(mode,stage,helper['symbol'],'entries',actual,helper)
            assert actual['self']==helper['self_events'].get('Ir',0),(mode,stage,helper['symbol'],'self')
            assert actual['inclusive']==helper['incoming_inclusive_events_non_additive'].get('Ir',0),(mode,stage,helper['symbol'],'inclusive',actual,helper)
            helper_rows_checked+=1
        assert sum(h['self_events'].get('Ir',0) for h in helpers)==independent_stages[stage]
    for symbol, helper in p['crc_nested_events_non_additive'].items():
        actual=grouped.get(('frame_crc',symbol),Counter())
        assert actual['entries']==helper['native_entries'] and actual['self']==helper['self_events'].get('Ir',0) and actual['inclusive']==helper['incoming_inclusive_events_non_additive'].get('Ir',0),(mode,symbol)
    grouped_all[mode]=grouped
    counts[mode]=entries;recounted[mode]=total
assert dict(stage_totals)==validation['exclusive_stage_ir']
assert sum(recounted[m] for m in analysis['families'])==validation['total_ir']

all_rows=rows(BASE/'native/all.jsonl');old_rows=rows('tests/evidence/diagnostics/gen0/driver-all-census.jsonl')
all_result=next(x for x in all_rows if x.get('phase')=='result')
old_result=next(x for x in old_rows if x.get('phase')=='result')
assert all_result['digest']==old_result['digest'] and all_result['per_df']==old_result['per_df']
census=next(x for x in all_rows if x.get('kind')=='post_decode_shadow_census')
assert census==next(x for x in old_rows if x.get('kind')=='post_decode_shadow_census')
interval=next(x for x in all_rows if x.get('kind')=='post_decode_interval_census')
assert interval==campaign['interval_census']==validation['interval_census']
choose='lp_lean1090_Lean1090_Impl_ScoreGate_choose'
fallback=read(BASE/'source-review.json')['exact_fallback_anchor']
reached=0;fallbacks=0
for row in interval['registers']:
    reg=row['register_decimal'];r=f'{reg:02x}';n=row['reached'];fb=row['fallback_accept']+row['fallback_reject']
    c=[r for df in census['per_df'] for r in df['commb'] if r['register_decimal']==reg]
    assert n==sum(x['score_attempt_predictions'] for x in c)
    assert row['fast_accept']+row['fallback_accept']==sum(x['score_pass'] for x in c)
    assert n==row['fast_accept']+row['fast_reject']+fb==sum(x['count'] for x in row['term_lengths'])
    for prefix in ('score','candidate'):
        assert counts[prefix+r][choose]==n and counts[prefix+r][fallback]==fb
    reached+=n;fallbacks+=fb
assert sum(counts[m][choose] for m in analysis['families'])==reached==45510
assert sum(counts[m][fallback] for m in analysis['families'])==fallbacks==0
live_rows=[x for x in all_rows if x.get('kind')=='post_decode_crc_census']
assert len(live_rows)==1
live_crc=live_rows[0]
assert live_crc==campaign['live_crc_census']==validation['live_crc_census']
assert live_crc['strategy']=='one_syndrome_per_successfully_parsed_frame'
assert live_crc['population']=='accepted_corpus_only'
assert live_crc['input_rows']==live_crc['retained_accepted_rows']==172432
assert live_crc['parsed_fields_and_syndromes_checked'] and not live_crc['native_call_counts']
assert [x['df'] for x in live_crc['per_df']]==list(range(32))
for current,old in zip(live_crc['per_df'],census['per_df']):
    assert current['parsed_frames']==current['crc_call_predictions']==old['count']
    assert current['crc_step_predictions']==old['count']*(56 if old['df']<16 else 112)
crc_entries=0;crc_steps=0
for family, dfs in [('adsb',[17,18]),('commb',[20,21]),('other',[x for x in range(32) if x not in [17,18,20,21]])]:
    records=[x for x in live_crc['per_df'] if x['df'] in dfs]
    calls=sum(x['crc_call_predictions'] for x in records)
    steps=sum(x['crc_call_predictions']*(56 if x['df']<16 else 112) for x in records)
    for symbol in ['lp_lean1090_Lean1090_Impl_frameSyndrome','lp_lean1090_Lean1090_Impl_Parity_checksum','lp_lean1090_Lean1090_Impl_Parity_syndrome',read(BASE/'source-review.json')['parity_fold_anchor']]:
        assert counts[family][symbol]==calls,(family,symbol,calls)
    assert counts[family]['lp_lean1090_Lean1090_Impl_Parity_step']==steps
    crc_entries+=calls;crc_steps+=steps
assert crc_entries==172432 and crc_steps==sum(x['crc_step_predictions'] for x in live_crc['per_df'])
assert sum(grouped_all[m].get(('frame_crc','l_Nat_testBit'),Counter())['entries'] for m in analysis['families'])==0
native_df=read(BASE/'native-df/summary.json')
for row in native_df['per_df']:
    if row['messages']:
        assert row['complete_output_digest']==all_result['per_df'][row['df']]['digest']
assert sum(x['messages'] for x in native_df['per_df'])==172432
assert sum(x['loop_small_allocations'] for x in native_df['per_df'])==native_df['sum_separate_df_loop_small_allocations']
assert all_result['loop_small_allocations']==native_df['complete_corpus_loop_small_allocations']

benchmark=read('bench/runs/gen10/summary.json')
binding=read(BASE/'benchmark-source-binding.json')
assert campaign['commit']==build['commit']==binding['diagnostic_commit']
assert benchmark['commit']==binding['timed_original_commit']
assert sha(BASE/'benchmark-source-binding.json')==validation['benchmark_source_binding_sha256']
assert binding['build_manifest_sha256']==sha(BASE/'driver/driver-build.json')
assert binding['benchmark_sha256']==sha('bench/runs/gen10/summary.json')
for name,digest in binding['all_audited_lean_sources'].items():
    assert sha(name)==digest
    for revision in [campaign['commit'],binding['timed_mapped_commit']]:
        assert hashlib.sha256(subprocess.check_output(['git','cat-file','blob',revision+':'+name])).hexdigest()==digest
assert campaign['build_manifest_sha256']==sha(BASE/'driver/driver-build.json')
assert campaign['driver_binary_sha256']==build['artifacts'][campaign['driver_binary']]==sha(campaign['driver_binary'])
assert campaign['corpus_sha256']==sha(campaign['corpus'])
assert benchmark['binary_sha256']==campaign['protected_inputs']['.lake/build/bin/lean1090-bench']
fresh=read(BASE/'driver/fresh-native-inputs.json')
assert len(fresh)==22 and build['reused_production_object_count']==21
assert sha(BASE/'driver/fresh-native-inputs.json')==build['fresh_benchmark_native_binding']['sha256']==sha('bench/runs/gen10/fresh-native-inputs.json')
for record in fresh:
    assert sha(record['source'])==record['source_sha256']==build['linked_project_inventory']['sources'][record['source']]
    blob=subprocess.check_output(['git','cat-file','blob',campaign['commit']+':'+record['source']])
    assert hashlib.sha256(blob).hexdigest()==record['source_sha256']
    for name,item in record['artifacts'].items(): assert sha(name)==item['sha256']==build['unchanged_native_inputs'][name]

# Historical committed evidence must retain both exact bytes and membership.
historical=[f'docs/GEN{i}-COST-BREAKDOWN.md' for i in range(10)]+[f'tests/evidence/diagnostics/gen{i}' for i in range(10)]+['bench/runs/baseline-FC006']+[f'bench/runs/gen{i}' for i in range(1,10)]
subprocess.run(['git','diff','--exit-code','HEAD','--',*historical],check=True,capture_output=True)
assert not subprocess.check_output(['git','ls-files','--others','--exclude-standard','--',*historical]).strip()
historical_files=subprocess.check_output(['git','ls-files','--',*historical],text=True).splitlines()
for name in historical_files:
    blob=subprocess.check_output(['git','cat-file','blob','HEAD:'+name]);assert Path(name).read_bytes()==blob,name
history=read(BASE/'historical-inputs.json')
assert len(history['files'])==validation['historical_file_count']
actual_history={str(p) for root in history['roots'] for p in Path(root).rglob('*') if p.is_file()}|set(history['individual_paths'])
assert actual_history==set(history['files'])
for name,item in history['files'].items():
    assert sha(name)==item['sha256'] and Path(name).stat().st_size==item['bytes'],name

report=Path('docs/GEN10-COST-BREAKDOWN.md').read_text()
labels={'frame_crc':'Frame / CRC','commb_inference':'Comm-B candidate inference / raw records',
        'semantic_oracle_values':'Semantic / oracle value construction','adsb_fields':'ADS-B fields / checks',
        'output_model_control':'Output-model construction / residual control'}
grand=sum(stage_totals.values())
for mode,p in analysis['families'].items():
    n=p['root_incoming_calls'];ir=p['total_events']['Ir']
    assert f'| {mode} | {n:,} | {ir:,} | {ir/n:,.1f} | {100*ir/grand:.2f}% |' in report
previous=read('tests/evidence/diagnostics/gen9/analysis/analysis.json')
for key,label in labels.items():
    family=[analysis['families'][m]['exclusive_stage_events'][key]['Ir'] for m in ('adsb','commb','other')]
    total=sum(family)
    assert f'| {label} | '+''.join(f'{n:,} | ' for n in family)+f'{total:,} | {100*total/grand:.2f}% |' in report
    old=sum(p['exclusive_stage_events'].get(key,{}).get('Ir',0) for p in previous['families'].values())
    assert f'| {label} | {old:,} | {total:,} | {total-old:+,} | {total/old:.5f} | {old/172432:,.2f} | {total/172432:,.2f} |' in report
for row in native_df['per_df']:
    if row['messages']:
        n=row['messages'];a=row['loop_small_allocations']
        assert f"| {row['df']} | {n:,} | {a:,} | {a/n:.2f} | Yes |" in report
for name,digest in re.findall(r'\| `([^`]+)` \| `([0-9a-f]{64})` \|',report): assert sha(name)==digest,name
assert sha('docs/GEN10-COST-BREAKDOWN.md')==validation['report_sha256']
assert sha(BASE/'analysis/analysis.json')==validation['analysis_sha256']
assert sha(BASE/'archive-manifest.json')==validation['archive_manifest_sha256']
perf=read(BASE/'perf/analysis.json')
blocks=[x for x in (BASE/'perf/script.txt').read_text().split('\n\n') if x.strip()]
period_total=period_decode=unknown=0;included=[];excluded=Counter()
for index,block in enumerate(blocks):
    lines=block.splitlines();period=int(re.search(r':\s+(\d+) cpu-clock:u:',lines[0]).group(1));period_total+=period
    symbols=[]
    for line in lines[1:]:
        m=re.match(r'^\s*[0-9a-f]+\s+(.*?)\s+\(.*?\)\s*$',line)
        if m:symbols.append(re.sub(r'\+0x[0-9a-f]+$','',m[1]))
    unknown+=int('[unknown]' in symbols)
    if 'lp_lean1090_Lean1090_Impl_decode' in symbols:
        period_decode+=period;included.append(index)
    elif any('runDecodeOnce' in x for x in symbols):excluded['worker decode-loop stack, no decode frame']+=1
    elif any('WholeDecoder' in x for x in symbols):excluded['worker other phase, no decode frame']+=1
    else:excluded['no decode or worker frame; may include unwind failures']+=1
assert len(blocks)==perf['total_samples']
assert len(included)==perf['decode_descendant_samples']
assert perf['excluded_samples']==len(blocks)-len(included) and perf['excluded_by_visible_context']==dict(excluded)
assert period_total==perf['total_period'] and period_decode==perf['decode_descendant_period'] and unknown==perf['all_samples_with_unknown_frame']
sample_records=rows(BASE/'perf/decode-samples.jsonl')
assert [x['sample_index'] for x in sample_records]==included
assert sum(x['period'] for x in sample_records)==period_decode
assert Counter(x['stage'] for x in sample_records)==perf['disjoint_top_stages']
assert Counter(x['substage'] for x in sample_records)==perf['disjoint_detail_stages']

for record in sample_records:
    block=blocks[record['sample_index']].splitlines();parsed=[]
    for line in block[1:]:
        m=re.match(r'^\s*([0-9a-f]+)\s+(.*?)\s+\((.*?)\)\s*$',line)
        if m:parsed.append({'ip':m[1],'symbol':re.sub(r'\+0x[0-9a-f]+$','',m[2]),'dso':m[3]})
    assert record['stack']==parsed
    names=[r['symbol'] for r in parsed];ancestors=names[:names.index('lp_lean1090_Lean1090_Impl_decode')]
    def has(suffix):return any('lp_lean1090_Lean1090_Impl_'+suffix in name for name in ancestors)
    mapping=any('Impl_report_spec' in name or 'Impl_reportWithSyndrome_spec' in name for name in ancestors)
    if has('decodeFrame'):stage=substage='frame extraction'
    elif has('frameAccepted'):stage=substage='acceptance'
    elif has('report') or mapping:
        stage='report/projection'
        if has('Semantics_commB') or mapping:substage='Comm-B semantic projection'
        elif any(has(x) for x in ['frameCommB','inferCommB','commB','decodeBDS']):substage='Comm-B inference and raw payload'
        elif has('Semantics_adsb'):substage='ADS-B semantic projection'
        elif has('frameADSB') or has('decodeADSB'):substage='ADS-B raw payload'
        elif any(has(x) for x in ['frameSyndrome','frameAddress','Parity_']):substage='report parity/address'
        elif has('frameAltitude') or has('Altitude_'):substage='altitude'
        elif has('frameIdentity'):substage='identity'
        else:substage='report other/self/unresolved substage'
    elif has('frameSyndrome') or has('Parity_'):stage=substage='shared frame syndrome'
    else:stage=substage='decode self/other'
    assert (record['stage'],record['substage'],record['leaf'])==(stage,substage,names[0])

capture=read(BASE/'perf/capture.json')
assert capture['before_hashes']==capture['after_hashes']
assert campaign['prior_perf_capture']['sha256']==sha(BASE/'perf/capture.json')
assert capture['completed_utc'] < min(x['started_utc'] for x in campaign['native_runs'])
assert sum(perf['disjoint_top_stages'].values())==sum(perf['disjoint_detail_stages'].values())==len(included)
raw_perf=capture['raw_data']
assert sha(raw_perf['path'])==raw_perf['sha256'] and Path(raw_perf['path']).stat().st_size==raw_perf['bytes']

bench_archive=read('bench/runs/gen10/archive-verification.json')
for name,item in bench_archive['files'].items():
    assert sha(Path('bench/runs/gen10')/name)==item['sha256']==sha(Path(bench_archive['source'])/name),name
    assert (Path('bench/runs/gen10')/name).stat().st_size==item['bytes']
helper_comparison=read(BASE/'helper-comparison.json')
assert helper_comparison['analysis_sha256']==sha(BASE/'analysis/analysis.json')
assert helper_comparison['previous_analysis_sha256']==sha('tests/evidence/diagnostics/gen9/analysis/analysis.json')
old_groups={};old_contexts={}
for mode,profile in previous['families'].items():
    contexts={};_,_,_,groups,_=recount(Path(profile['path']),profile['root'],contexts);old_contexts[mode]=contexts
    for key,item in groups.items():old_groups.setdefault(key,Counter()).update(item)
new_groups={}
for mode in analysis['families']:
    for key,item in grouped_all[mode].items():new_groups.setdefault(key,Counter()).update(item)
for row in helper_comparison['rows']:
    for generation,groups in [('gen9',old_groups),('gen10',new_groups)]:
        item=groups.get((row['stage'],row['symbol']),Counter())
        expected={'contexts':0} if not item else {'contexts':item['contexts'],'native_entries':item['entries'],'self_ir':item['self'],'inclusive_ir':item['inclusive']}
        assert row[generation]==expected,(row,expected)
assert sha(BASE/'helper-comparison.json')==validation['helper_comparison_sha256']
assert all(not any(n.split("'")[0]=='lp_lean1090_Lean1090_Impl_cbMach64' for n in mach_contexts[m]) for m in profiles)
largest=max(stage_totals,key=stage_totals.get)
combined={}
for mode in analysis['families']:
    for (stage,symbol),item in grouped_all[mode].items():
        if stage==largest:combined.setdefault(symbol,Counter()).update(item)
assert sum(x['self'] for x in combined.values())==stage_totals[largest]
top_helpers=sorted(combined.items(),key=lambda kv:kv[1]['inclusive'],reverse=True)[:15]
for symbol,item in top_helpers:
    assert f"| `{symbol}` | {item['entries']:,} | {item['self']:,} | {item['inclusive']:,} |" in report,(symbol,item)
assert 'recursive or re-entrant visits can overlap within one row' in report
assert 'descendants can cross a later stage boundary' in report
source_review=read(BASE/'source-review.json')
assert source_review['fresh_project_modules_verified']==len(fresh)
assert source_review['binary_sha256']==benchmark['binary_sha256']
assert source_review['driver_binary_sha256']==campaign['driver_binary_sha256']
assert source_review['driver_build_manifest_sha256']==sha(BASE/'driver/driver-build.json')
for command in source_review['commands']:assert sha(command['output'])==command['sha256']
assert sha(source_review['symbol_inventory']['path'])==source_review['symbol_inventory']['sha256']
for name,digest in campaign['protected_inputs'].items(): assert sha(name)==digest,name

historical_perf=[]
for generation in range(10):
    previous_capture=read(Path('tests/evidence/diagnostics')/f'gen{generation}'/'perf/capture.json')
    raw=previous_capture['raw_data']
    assert sha(raw['path'])==raw['sha256'] and Path(raw['path']).stat().st_size==raw['bytes']
    historical_perf.append(raw)

# Every live CRC context in these accepted families must originate in decode,
# including the raw packing work that feeds the unique syndrome computation.
prefix='lp_lean1090_Lean1090_Impl_';shared_crc_contexts=[]
per_df={r['df']:r for r in live_crc['per_df']}
for family,dfs in [('adsb',[17,18]),('commb',[20,21]),('other',[i for i in range(32) if i not in [17,18,20,21]])]:
    expected=sum(per_df[i]['parsed_frames'] for i in dfs)
    for local in ['frameSyndrome','Parity_checksum','frameParts','packFields']:
        observed=0
        for name,item in mach_contexts[family].items():
            parts=name.split("'")
            if parts[0]!=prefix+local:continue
            positive={k:v for k,v in item['incoming'].items() if v['inclusive_events']['Ir']>0}
            if not positive:
                assert not item['self_events']['Ir'];continue
            assert len(positive)==1
            caller,edge=next(iter(positive.items()))
            assert parts[1]==caller.split("'")[0]
            if local=='frameSyndrome':assert parts[1]==prefix+'decode'
            else:assert prefix+'frameSyndrome' in parts[1:] and prefix+'decode' in parts[1:]
            observed+=edge['calls']
            shared_crc_contexts.append({'family':family,'context':name,'caller':caller,**edge,'self_ir':item['self_events']['Ir']})
        assert observed==expected,(family,local,observed,expected)
    interrogators=0
    for name,item in mach_contexts[family].items():
        parts=name.split("'")
        if parts[0]!=prefix+'Parity_interrogator':continue
        for caller,edge in item['incoming'].items():
            if edge['inclusive_events']['Ir']>0:
                assert caller.split("'")[0]==prefix+'reportWithSyndrome'
                interrogators+=edge['calls']
    assert interrogators==(per_df[11]['parsed_frames'] if family=='other' else 0)
assert source_review['shared_syndrome_decode_verified']
# Exact observed integer helper entries must reconcile independently with
# actual choose entries in every root, including legitimate empty score probes.
assert source_review['integer_score_gate_verified']
integer_anchors=source_review['integer_score_gate_anchors']
assert set(integer_anchors)=={'common_denominator','totals_entry'}
integer_observations={}
for mode in profiles:
    actual={name:counts[mode][symbol] for name,symbol in integer_anchors.items()}
    assert all(n==counts[mode][choose] for n in actual.values()),(mode,actual)
    integer_observations[mode]={'choose':counts[mode][choose],**actual}
    assert all(counts[mode]['lp_lean1090_Lean1090_Impl_ScoreGate_'+n]==0 for n in ['center','mass','envelope','scaledNumerator','scaledTotals'])
# Recount QNH observation boundaries without treating inlining as zero work.
assert source_review['qnh_table_live_path_verified']
qnh_contexts={}
for mode,contexts in mach_contexts.items():
    assert counts[mode]['lp_lean1090_Lean1090_Impl_cbQNH64']==0
    qnh_contexts[mode]=[{'context':name,**item} for name,item in contexts.items()
                        if name.split("'")[0] in {prefix+'cbValid40',prefix+'cbDensityTerms'}]
unknown_leaves=sum(row['leaf']=='[unknown]' for row in sample_records)
perf_completion=read(BASE/'perf/completion.json')
assert unknown_leaves==perf_completion['unknown_decode_leaf_samples']
assert perf_completion['samples']==len(blocks)
assert perf_completion['included_decode_stacks']==len(included)
assert str(unknown_leaves)+' included leaf positions' in (BASE/'perf/README.md').read_text()

result={'status':'passed' ,'reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'archive_files':len(manifest['files']),'archive_stored_bytes':stored,'protected_live_inputs':len(campaign['protected_inputs']),
 'profiles_independently_recounted':recounted,'family_ir':{m:recounted[m] for m in analysis['families']},
 'exclusive_stages':dict(stage_totals),'total_ir':sum(stage_totals.values()),'interval_choose_entries':reached,
 'fallback_entries':fallbacks,'historical_committed_files_checked':len(historical_files),'historical_snapshot_files_checked':len(history['files']),'historical_allowed_addition':None,
 'fresh_native_sets':len(fresh),'reused_production_objects':build['reused_production_object_count'],
 'gen10_benchmark_files_unchanged':len(bench_archive['files']),
 'historical_raw_perf_files_unchanged':historical_perf,
 'helper_group_rows_independently_recounted':helper_rows_checked,'payload_outgoing_edges_independently_recounted':{m:payload_edges_all[m] for m in analysis['families']},'mach_native_contexts_all_13_profiles':{m:sum(n.split("'")[0]=='lp_lean1090_Lean1090_Impl_cbMach64' for n in mach_contexts[m]) for m in profiles},'helper_comparison_sha256':sha(BASE/'helper-comparison.json'),'old_new_helper_observations_recounted':True,'shared_crc_contexts_independently_recounted':shared_crc_contexts,'live_crc_census':live_crc,'integer_gate_observations':integer_observations,'integer_reference_and_inlined_wrapper_entries':0,'perf_included_unknown_leaves':unknown_leaves,'qnh_live_caller_contexts_independently_recounted':qnh_contexts,'largest_stage_top_helpers':{symbol:dict(x) for symbol,x in top_helpers},
 'crc_checksum_syndrome_fold_entries':crc_entries,'crc_step_entries':crc_steps,'frame_crc_nat_testBit_entries':0,
 'perf_raw_samples':len(blocks),'perf_visible_decoder_samples':len(included),'perf_unknown_frame_samples':unknown,
 'report_sha256':sha('docs/GEN10-COST-BREAKDOWN.md'),'analysis_sha256':sha(BASE/'analysis/analysis.json'),
 'manifest_sha256':sha(BASE/'archive-manifest.json'),'validation_sha256':sha(BASE/'validation.json')}
assert not (BASE/'independent-review/final-checks.json').exists()
(BASE/'independent-review/final-checks.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))

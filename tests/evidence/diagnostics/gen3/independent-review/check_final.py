#!/usr/bin/env python3
"""Read-only independent gen3 evidence checks; writes only its scratch result."""
from pathlib import Path
from collections import Counter
from datetime import datetime, timezone
import gzip, hashlib, json, re, subprocess

BASE = Path('tests/evidence/diagnostics/gen3')
def read(p): return json.loads(Path(p).read_text())
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p): return [json.loads(x) for x in Path(p).read_text().splitlines() if x]

manifest=read(BASE/'archive-manifest.json')
analysis=read(BASE/'analysis/analysis.json')
campaign=read(BASE/'campaign.json')
build=read(BASE/'driver/driver-build.json')
validation=read(BASE/'validation.json')
assert validation['status']==campaign['status']==build['status']=='passed'
assert len(manifest['files'])==manifest['file_count']==435
stored=0
for name,record in manifest['files'].items():
    p=BASE/name; b=p.read_bytes();stored+=len(b)
    assert len(b)==record['stored_bytes'] and hashlib.sha256(b).hexdigest()==record['stored_sha256'],name
    decoded=gzip.decompress(b) if 'gzip' in record['encoding'] else b
    assert len(decoded)==record['source_bytes'] and hashlib.sha256(decoded).hexdigest()==record['source_sha256'],name
assert stored==manifest['stored_bytes']
for name,digest in campaign['protected_inputs'].items(): assert sha(name)==digest,name
assert len(campaign['protected_inputs'])==230

# Independently parse only self costs and native edge entry counts. Do not use
# the production analyzer/parser for the recount.
def recount(p, root):
    names={};current=None;callee=None;edge=False;total=0;reported={};incoming=Counter();self_cost=Counter();inclusive=Counter();pos=0
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
                incoming[callee]+=int(line.split('=',1)[1].split()[0]);edge=True
            elif line and (line[0].isdigit() or line[0] in '+-*'):
                fields=line.split();assert len(fields)==pos+1,(p,line)
                if edge: inclusive[callee]+=int(fields[pos]);edge=False
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
            elif local in ('decodeFrame','frameSyndrome','frameAddress','frameAccepted') or symbol.startswith(prefix+'Parity_'):stage='frame_crc'
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
        item['self']+=self_cost[key];item['entries']+=incoming[key];item['inclusive']+=inclusive[key]
        stages[stage]+=self_cost[key]
    return total,entries,stages,grouped

profiles={**analysis['families'],**{'score'+k:v for k,v in analysis['non_additive_register_score_probes'].items()},
          **{'candidate'+k:v for k,v in analysis['non_additive_register_candidate_probes'].items()}}
assert len(profiles)==13
recounted={};counts={};stage_totals=Counter();grouped_all={};helper_rows_checked=0
jobs={x['mode']:x for x in campaign['profiles']}
assert set(jobs)==set(profiles)
for mode,p in profiles.items():
    path=Path(p['path']);total,entries,independent_stages,grouped=recount(path,p['root'])
    run=read(BASE/'callgrind'/mode/'run.json');job=jobs[mode]
    assert total==p['total_events'].get('Ir',0)==run['primary_ir']==job['primary_ir']
    assert p['container_sha256']==sha(path)
    assert p['sha256']==hashlib.sha256(gzip.decompress(path.read_bytes())).hexdigest()==run['profile_files']['callgrind.out.1']
    assert run['status']=='passed' and run['returncode']==0 and job['native_output_matches']
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
assert sum(recounted[m] for m in analysis['families'])==validation['total_ir']==52042380076

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
crc_entries=0;crc_steps=0
for family, dfs in [('adsb',[17,18]),('commb',[20,21]),('other',[x for x in range(32) if x not in [17,18,20,21]])]:
    records=[x for x in census['per_df'] if x['df'] in dfs]
    calls=sum(x['crc_call_predictions'] for x in records)
    steps=sum(x['crc_call_predictions']*(56 if x['df']<16 else 112) for x in records)
    for symbol in ['lp_lean1090_Lean1090_Impl_Parity_checksum','lp_lean1090_Lean1090_Impl_Parity_syndrome',read(BASE/'source-review.json')['parity_fold_anchor']]:
        assert counts[family][symbol]==calls,(family,symbol,calls)
    assert counts[family]['lp_lean1090_Lean1090_Impl_Parity_step']==steps
    crc_entries+=calls;crc_steps+=steps
assert crc_entries==287418 and crc_steps==26320784
assert sum(grouped_all[m].get(('frame_crc','l_Nat_testBit'),Counter())['entries'] for m in analysis['families'])==0
native_df=read(BASE/'native-df/summary.json')
for row in native_df['per_df']:
    if row['messages']:
        assert row['complete_output_digest']==all_result['per_df'][row['df']]['digest']
assert sum(x['messages'] for x in native_df['per_df'])==172432
assert sum(x['loop_small_allocations'] for x in native_df['per_df'])==57118004
assert all_result['loop_small_allocations']==57117834

benchmark=read('bench/runs/gen3/summary.json')
assert campaign['commit']==build['commit']==benchmark['commit']
assert campaign['build_manifest_sha256']==sha(BASE/'driver/driver-build.json')
assert campaign['driver_binary_sha256']==build['artifacts'][campaign['driver_binary']]==sha(campaign['driver_binary'])
assert campaign['corpus_sha256']==sha(campaign['corpus'])
assert benchmark['binary_sha256']==campaign['protected_inputs']['.lake/build/bin/lean1090-bench']
fresh=read(BASE/'driver/fresh-native-inputs.json')
assert len(fresh)==22 and build['reused_production_object_count']==21
assert sha(BASE/'driver/fresh-native-inputs.json')==build['fresh_benchmark_native_binding']['sha256']==sha('bench/runs/gen3/fresh-native-inputs.json')
for record in fresh:
    assert sha(record['source'])==record['source_sha256']==build['linked_project_inventory']['sources'][record['source']]
    blob=subprocess.check_output(['git','cat-file','blob',campaign['commit']+':'+record['source']])
    assert hashlib.sha256(blob).hexdigest()==record['source_sha256']
    for name,item in record['artifacts'].items(): assert sha(name)==item['sha256']==build['unchanged_native_inputs'][name]

# Historical committed evidence must retain both exact bytes and membership.
historical=['docs/GEN0-COST-BREAKDOWN.md','docs/GEN1-COST-BREAKDOWN.md','docs/GEN2-COST-BREAKDOWN.md',
            'tests/evidence/diagnostics/gen0','tests/evidence/diagnostics/gen1','tests/evidence/diagnostics/gen2',
            'bench/runs/baseline-FC006','bench/runs/gen1','bench/runs/gen2']
subprocess.run(['git','diff','--exit-code','HEAD','--',*historical],check=True,capture_output=True)
assert not subprocess.check_output(['git','ls-files','--others','--exclude-standard','--',*historical]).strip()
historical_files=subprocess.check_output(['git','ls-files','--',*historical],text=True).splitlines()
for name in historical_files:
    blob=subprocess.check_output(['git','cat-file','blob','HEAD:'+name]);assert Path(name).read_bytes()==blob,name

report=Path('docs/GEN3-COST-BREAKDOWN.md').read_text()
labels={'frame_crc':'Frame / CRC','commb_inference':'Comm-B candidate inference / raw records',
        'semantic_oracle_values':'Semantic / oracle value construction','adsb_fields':'ADS-B fields / checks',
        'output_model_control':'Output-model construction / residual control'}
grand=sum(stage_totals.values())
for mode,p in analysis['families'].items():
    n=p['root_incoming_calls'];ir=p['total_events']['Ir']
    assert f'| {mode} | {n:,} | {ir:,} | {ir/n:,.1f} | {100*ir/grand:.2f}% |' in report
previous=read('tests/evidence/diagnostics/gen2/analysis/analysis.json')
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
assert sha('docs/GEN3-COST-BREAKDOWN.md')==validation['report_sha256']
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
assert len(blocks)==perf['total_samples']==573
assert len(included)==perf['decode_descendant_samples']==393
assert perf['excluded_samples']==len(blocks)-len(included) and perf['excluded_by_visible_context']==dict(excluded)
assert period_total==perf['total_period'] and period_decode==perf['decode_descendant_period'] and unknown==perf['all_samples_with_unknown_frame']==569
sample_records=rows(BASE/'perf/decode-samples.jsonl')
assert [x['sample_index'] for x in sample_records]==included
assert sum(x['period'] for x in sample_records)==period_decode
assert Counter(x['stage'] for x in sample_records)==perf['disjoint_top_stages']
assert Counter(x['substage'] for x in sample_records)==perf['disjoint_detail_stages']
capture=read(BASE/'perf/capture.json')
assert capture['before_hashes']==capture['after_hashes']
assert campaign['prior_perf_capture']['sha256']==sha(BASE/'perf/capture.json')
assert capture['completed_utc'] < min(x['started_utc'] for x in campaign['native_runs'])
assert sum(perf['disjoint_top_stages'].values())==sum(perf['disjoint_detail_stages'].values())==393
raw_perf=capture['raw_data']
assert sha(raw_perf['path'])==raw_perf['sha256'] and Path(raw_perf['path']).stat().st_size==raw_perf['bytes']

bench_archive=read('bench/runs/gen3/archive-verification.json')
for name,item in bench_archive['files'].items():
    assert sha(Path('bench/runs/gen3')/name)==item['sha256']==sha(Path(bench_archive['source'])/name),name
    assert (Path('bench/runs/gen3')/name).stat().st_size==item['bytes']
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
for generation in range(3):
    previous_capture=read(Path('tests/evidence/diagnostics')/f'gen{generation}'/'perf/capture.json')
    raw=previous_capture['raw_data']
    assert sha(raw['path'])==raw['sha256'] and Path(raw['path']).stat().st_size==raw['bytes']
    historical_perf.append(raw)

result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'archive_files':len(manifest['files']),'archive_stored_bytes':stored,'protected_live_inputs':len(campaign['protected_inputs']),
 'profiles_independently_recounted':recounted,'family_ir':{m:recounted[m] for m in analysis['families']},
 'exclusive_stages':dict(stage_totals),'total_ir':sum(stage_totals.values()),'interval_choose_entries':reached,
 'fallback_entries':fallbacks,'historical_committed_files_checked':len(historical_files),
 'fresh_native_sets':len(fresh),'reused_production_objects':build['reused_production_object_count'],
 'gen3_benchmark_files_unchanged':len(bench_archive['files']),
 'historical_raw_perf_files_unchanged':historical_perf,
 'helper_group_rows_independently_recounted':helper_rows_checked,'largest_stage_top_helpers':{symbol:dict(x) for symbol,x in top_helpers},
 'crc_checksum_syndrome_fold_entries':crc_entries,'crc_step_entries':crc_steps,'frame_crc_nat_testBit_entries':0,
 'perf_raw_samples':len(blocks),'perf_visible_decoder_samples':len(included),'perf_unknown_frame_samples':unknown,
 'report_sha256':sha('docs/GEN3-COST-BREAKDOWN.md'),'analysis_sha256':sha(BASE/'analysis/analysis.json'),
 'manifest_sha256':sha(BASE/'archive-manifest.json'),'validation_sha256':sha(BASE/'validation.json')}
(BASE/'independent-review/final-checks.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))

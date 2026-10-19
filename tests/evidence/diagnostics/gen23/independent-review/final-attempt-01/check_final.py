#!/usr/bin/env python3
"""Read-only independent gen23 evidence checks; writes only its scratch result."""
from pathlib import Path
from collections import Counter
from datetime import datetime, timezone
import gzip, hashlib, json, re, subprocess, sys
sys.dont_write_bytecode=True

BASE = Path('tests/evidence/diagnostics/gen23')
def read(p): return json.loads(Path(p).read_text())
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p): return [json.loads(x) for x in Path(p).read_text().splitlines() if x]

manifest=read(BASE/'archive-manifest.json')
analysis=read(BASE/'analysis/analysis.json')
campaign=read(BASE/'campaign.json')
build=read(BASE/'driver/driver-build.json')
validation=read(BASE/'validation.json')
power_record=read(BASE/'power-native-contexts.json')
power_anchors=power_record['anchors']
priority_record=read(BASE/'priority-helper-contexts.json')
P='lp_lean1090_Lean1090_Impl_'
bit_selected={P+n for n in ['Altitude_bit','Altitude_grayDecode','identityCode','identityCode___lam__0','payloadInteger']}|{'lp_lean1090_List_foldl___at___00Lean1090_Impl_Altitude_grayDecode_spec__0'}
priority_selected={P+n for n in ['ScoreGate_choose','ScoreGate_commonDenominator','ScoreGate_scaledNumerator','ScoreGate_scaledTotals','bdsWireValid','payloadValue','affineValue','frameSyndrome','Parity_syndrome','Parity_checksum','bytesValue','packFields','field']}
affine_selected={P+n for n in ['payloadValue','affineValue','integerScale']}|{'l_Rat_mul','l_Rat_normalize'}
priority_selected.update(P+n for n in ['frameParts','acasParts','surveillanceParts','Semantics_tableValues','Semantics_commB','Semantics_adsb','reportWithSyndrome','integerScale'])
priority_selected.update(P+n for n in ['Semantics_commBStandardFloats','oracleCommBFloats','commBValue','findPayloadField','cbSelectedValid40','cbQNHValid40','cbRollValid50','cbMachValid60','cbVerticalValid60'])
priority_source=read(BASE/'independent-review/source-review.json')
priority_selected.update(priority_source['integer_score_gate_anchors'].values())
priority_selected.update([P+'decodeFrameWithWord',P+'decodeFrame'])
priority_selected.update([priority_source['parity_fold_anchor'],priority_source['pack_fields_fold_anchor'],'l_Rat_mul','l_Rat_add','l_Rat_div'])
priority_selected.discard(None)
crc_record=read(BASE/'crc-byte-contexts.json')
crc_selected={P+n for n in ['decodeFrameWithWord','decodeFrame','frameSyndrome','Parity_checksum','packFields','Parity_syndrome','Parity_syndromeBytes','Parity_syndromeBits','Parity_step','Parity_byteStep','Parity_cachedByte']}
assert priority_source['commb_validity_tables_live_path_verified'] and priority_source['integer_affine_normalization_live_path_verified'] and priority_source['raw_word_syndrome_live_path_verified']
for source in [priority_source,read('tests/evidence/diagnostics/gen22/independent-review/source-review.json')]:
    crc_selected.update(v for k,v in source.items() if k.startswith('parity_') and k.endswith('_anchor'))
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
            elif local in ('decodeFrame','decodeFrameWithWord','frameSyndrome','frameAddress','frameAccepted','frameAddressWithSyndrome','frameAcceptedWithSyndrome') or symbol.startswith(prefix+'Parity_'):stage='frame_crc'
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
            if re.split(r"'| \[clone ",full(key),maxsplit=1)[0] not in priority_selected and not full(key).startswith(prefix+'cbValid') and re.split(r"'| \[clone ",full(key),maxsplit=1)[0] not in {prefix+a for a in ['cbMach64','cbQNH64','cbValid40','cbDensityTerms','frameSyndrome','Parity_checksum','frameParts','packFields','Parity_interrogator','payloadValue','field','cbRatioOutside250800','cbPenalty','bdsWireValid','Binary64_powerTwo','Binary64_powerTwoFormula','Binary64_powerTwoTable___lam__0']} | {'lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0'} | set(power_anchors.values()) | bit_selected | crc_selected | affine_selected:continue
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
fallback=read(BASE/'independent-review/source-review.json')['exact_fallback_anchor']
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
assert live_crc['parsed_wire_word_checked'] and live_crc['raw_word_syndrome_checked'] and live_crc['standalone_frame_syndrome_checked_after_collection']
assert [x['df'] for x in live_crc['per_df']]==list(range(32))
for current,old in zip(live_crc['per_df'],census['per_df']):
    assert current['parsed_frames']==current['crc_call_predictions']==old['count']
    assert current['crc_step_predictions']==old['count']*(56 if old['df']<16 else 112)
crc_entries=0;crc_steps=0;crc_byte_iterations=0;crc_observed=[]
for family, dfs in [('adsb',[17,18]),('commb',[20,21]),('other',[x for x in range(32) if x not in [17,18,20,21]])]:
    records=[x for x in live_crc['per_df'] if x['df'] in dfs]
    calls=sum(x['crc_call_predictions'] for x in records)
    steps=sum(x['crc_call_predictions']*(56 if x['df']<16 else 112) for x in records)
    for symbol in [P+'decodeFrameWithWord',P+'Parity_syndrome',priority_source['parity_fold_anchor']]:
        assert counts[family][symbol]==calls,(family,symbol,calls)
    byte_entries=counts[family][priority_source['parity_byte_fold_anchor']]
    bit_entries=counts[family][priority_source['parity_bit_fold_anchor']]
    byte_wrapper_entries=counts[family][priority_source['parity_byte_wrapper_anchor']]
    bit_wrapper_entries=counts[family][priority_source['parity_bit_wrapper_anchor']]
    assert byte_entries==byte_wrapper_entries==calls and bit_entries==bit_wrapper_entries==0
    assert counts[family][P+'Parity_byteStep']==counts[family][P+'Parity_wordStep']==0
    assert steps%8==0
    crc_byte_iterations+=steps//8
    crc_observed.append(dict(family=family,byte_loop_entries=byte_entries,bit_loop_entries=bit_entries,byte_wrapper_entries=byte_wrapper_entries,bit_wrapper_entries=bit_wrapper_entries,predicted_byte_iterations=steps//8,equivalent_bit_update_predictions=steps))
    assert counts[family]['lp_lean1090_Lean1090_Impl_Parity_step']==0
    assert read(BASE/'independent-review/source-review.json')['word_crc_live_path_verified']
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

benchmark=read('bench/runs/gen23/summary.json')
assert campaign['commit']==build['commit']==subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()
source_binding=read(BASE/'benchmark-source-binding.json')
assert source_binding['diagnostic_commit']==build['commit'] and source_binding['timed_original_commit']==benchmark['commit']
assert source_binding['history'] is None and source_binding['timed_mapped_commit']==benchmark['commit']
assert source_binding['binary_sha256']==benchmark['binary_sha256']
subprocess.run(['git','merge-base','--is-ancestor',benchmark['commit'],build['commit']],check=True)
for name,digest in source_binding['all_audited_lean_sources'].items():
    assert sha(name)==digest
    for commit in (benchmark['commit'],build['commit']):assert hashlib.sha256(subprocess.check_output(['git','cat-file','blob',commit+':'+name])).hexdigest()==digest
assert source_binding['fresh_native_inputs_sha256']==sha('bench/runs/gen23/fresh-native-inputs.json')
assert sha(BASE/'benchmark-source-binding.json')==validation['benchmark_source_binding_sha256']
assert campaign['build_manifest_sha256']==sha(BASE/'driver/driver-build.json')
assert campaign['driver_binary_sha256']==build['artifacts'][campaign['driver_binary']]==sha(campaign['driver_binary'])
assert campaign['corpus_sha256']==sha(campaign['corpus'])
assert benchmark['binary_sha256']==campaign['protected_inputs']['.lake/build/bin/lean1090-bench']
fresh=read(BASE/'driver/fresh-native-inputs.json')
assert len(fresh)==22 and build['reused_production_object_count']==21
assert sha(BASE/'driver/fresh-native-inputs.json')==build['fresh_benchmark_native_binding']['sha256']==sha('bench/runs/gen23/fresh-native-inputs.json')
for record in fresh:
    assert sha(record['source'])==record['source_sha256']==build['linked_project_inventory']['sources'][record['source']]
    blob=subprocess.check_output(['git','cat-file','blob',campaign['commit']+':'+record['source']])
    assert hashlib.sha256(blob).hexdigest()==record['source_sha256']
    for name,item in record['artifacts'].items(): assert sha(name)==item['sha256']==build['unchanged_native_inputs'][name]

# Compact history uses committed Git inventory and exact held identities for
# already-sealed ignored raw files; no claim of freshly rehashing old large raws.
import importlib.util
hs=importlib.util.spec_from_file_location('gen23_review_history',BASE/'snapshot_history.py')
hm=importlib.util.module_from_spec(hs);hs.loader.exec_module(hm)
history=read(BASE/'historical-inputs.json')
historical_count=hm.verify(history)
assert historical_count==validation['historical_file_count']
report=Path('docs/GEN23-COST-BREAKDOWN.md').read_text()
labels={'frame_crc':'Frame / CRC','commb_inference':'Comm-B candidate inference / raw records',
        'semantic_oracle_values':'Semantic / oracle value construction','adsb_fields':'ADS-B fields / checks',
        'output_model_control':'Output-model construction / residual control'}
grand=sum(stage_totals.values())
for mode,p in analysis['families'].items():
    n=p['root_incoming_calls'];ir=p['total_events']['Ir']
    assert f'| {mode} | {n:,} | {ir:,} | {ir/n:,.1f} | {100*ir/grand:.2f}% |' in report
previous=read('tests/evidence/diagnostics/gen22/analysis/analysis.json')
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
assert sha('docs/GEN23-COST-BREAKDOWN.md')==validation['report_sha256']
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

bench_archive=read('bench/runs/gen23/archive-verification.json')
for name,item in bench_archive['files'].items():
    assert sha(Path('bench/runs/gen23')/name)==item['sha256']==sha(Path(bench_archive['source'])/name),name
    assert (Path('bench/runs/gen23')/name).stat().st_size==item['bytes']
helper_comparison=read(BASE/'helper-comparison.json')
assert helper_comparison['analysis_sha256']==sha(BASE/'analysis/analysis.json')
assert helper_comparison['previous_analysis_sha256']==sha('tests/evidence/diagnostics/gen22/analysis/analysis.json')
old_groups={};old_contexts={}
for mode,profile in previous['families'].items():
    contexts={};_,_,_,groups,_=recount(Path(profile['path']),profile['root'],contexts);old_contexts[mode]=contexts
    for key,item in groups.items():old_groups.setdefault(key,Counter()).update(item)
new_groups={}
for mode in analysis['families']:
    for key,item in grouped_all[mode].items():new_groups.setdefault(key,Counter()).update(item)
for row in helper_comparison['rows']:
    for generation,groups in [('gen22',old_groups),('gen23',new_groups)]:
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
source_review=read(BASE/'independent-review/source-review.json')
assert source_review['fresh_project_modules_verified']==len(fresh)
assert source_review['binary_sha256']==benchmark['binary_sha256']
assert source_review['driver_binary_sha256']==campaign['driver_binary_sha256']
assert source_review['driver_build_manifest_sha256']==sha(BASE/'driver/driver-build.json')
for command in source_review['commands']:assert sha(command['output'])==command['sha256']
assert sha(source_review['symbol_inventory']['path'])==source_review['symbol_inventory']['sha256']
for name,digest in campaign['protected_inputs'].items(): assert sha(name)==digest,name

# Every live CRC context in these accepted families must originate in decode,
# including the raw packing work that feeds the unique syndrome computation.
prefix='lp_lean1090_Lean1090_Impl_';shared_crc_contexts=[]
per_df={r['df']:r for r in live_crc['per_df']}
for family,dfs in [('adsb',[17,18]),('commb',[20,21]),('other',[i for i in range(32) if i not in [17,18,20,21]])]:
    expected=sum(per_df[i]['parsed_frames'] for i in dfs)
    for local in ['decodeFrame','frameSyndrome','Parity_checksum','frameParts','packFields']:
        assert counts[family][prefix+local]==0,(family,local)
    for local in ['decodeFrameWithWord','Parity_syndrome']:
        observed=0
        for name,item in mach_contexts[family].items():
            parts=name.split("'")
            if parts[0]!=prefix+local:continue
            positive={k:v for k,v in item['incoming'].items() if v['inclusive_events']['Ir']>0}
            if not positive:
                assert not item['self_events']['Ir'];continue
            assert len(positive)==1
            caller,edge=next(iter(positive.items()))
            assert parts[1]==caller.split("'")[0]==prefix+'decode'
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
# Recount current byte boundaries from the independent raw parser, using the
# separately recorded accepted-corpus length census only as the expected population.
assert source_review['byte_words_live_path_verified']
byte_record=read(BASE/'byte-native-counts.json')
assert byte_record['source_review_sha256']==sha(BASE/'independent-review/source-review.json')
byte_counts=[]
for family,dfs in [('adsb',[17,18]),('commb',[20,21]),('other',[i for i in range(32) if i not in [17,18,20,21]])]:
    short=sum(per_df[i]['parsed_frames'] for i in dfs if i<16)
    long=sum(per_df[i]['parsed_frames'] for i in dfs if i>=16)
    actual={'family':family,'seven_byte_frames':short,'fourteen_byte_frames':long,
            'bytesValue_entries':counts[family][prefix+'bytesValue'],
            'prefix_entries':counts[family][source_review['byte_word_prefix_anchor']],
            'wide_fallback_entries':counts[family][source_review['byte_word_fallback_anchor']]}
    assert actual['bytesValue_entries']==short+long and actual['prefix_entries']==long and actual['wide_fallback_entries']==0
    assert counts[family][prefix+'bytesWord']==0
    byte_counts.append(actual)
    assert f"| {family} | {short:,} | {long:,} | {actual['bytesValue_entries']:,} | {long:,} | 0 |" in report
assert byte_counts==byte_record['rows']
assert sha(BASE/'byte-native-counts.json')==validation['byte_native_counts_sha256']

# Supplemental cbPenalty observations are independently summed from the raw
# caller-context parse; they are overlapping probes, never new stage totals.
penalty_record=read(BASE/'penalty-probe-costs.json')
assert penalty_record['analysis_sha256']==sha(BASE/'analysis/analysis.json')
penalty_counts=[]
for kind in ['candidate','score']:
    for register in ['40','44','45','50','60']:
        mode=kind+register;profile=profiles[mode];item=Counter()
        for (stage,symbol),values in grouped_all[mode].items():
            if symbol==prefix+'cbPenalty':item.update(values)
        row={'probe':mode,'register':register,'kind':kind,'probe_entries':counts[mode][profile['root']],
             'probe_total_ir':recounted[mode],'native_entries':item['entries'],'self_ir':item['self'],
             'incoming_inclusive_ir_non_additive':item['inclusive']}
        assert row['native_entries']==counts[mode][prefix+'cbPenalty']
        penalty_counts.append(row)
        assert f"| {mode} | {row['probe_entries']:,} | {row['native_entries']:,} | {row['self_ir']:,} | {row['incoming_inclusive_ir_non_additive']:,} | {row['probe_total_ir']:,} |" in report
assert penalty_counts==penalty_record['rows']
assert sha(BASE/'penalty-probe-costs.json')==validation['penalty_probe_costs_sha256']

# Recount actual wind lookup and constructor boundaries independently from raw
# incoming edges. Expected population is the separately checked live census;
# constructor absence inside decode roots is not a claim about startup cost.
assert source_review['bds50_wind_penalty_live_path_verified']
wind_record=read(BASE/'wind-native-counts.json')
assert wind_record['source_review_sha256']==sha(BASE/'independent-review/source-review.json')
assert wind_record['analysis_sha256']==sha(BASE/'analysis/analysis.json')
wind_census=next(row for row in interval['registers'] if row['register_decimal']==0x50)
assert wind_record['checked_BDS50_interval_census']==wind_census
wind_expected=wind_census['reached']+wind_census['fallback_accept']+wind_census['fallback_reject']
wind_rows=[]
wind_order=list(analysis['families'])+[kind+reg for kind in ['candidate','score'] for reg in analysis['non_additive_register_'+kind+'_probes']]
for mode in wind_order:
    expected=wind_expected if mode in ['commb','candidate50','score50'] else 0
    observed=counts[mode][source_review['wind_penalty_anchor']]
    constructors=counts[mode][source_review['wind_penalty_table_entry_anchor']]
    assert observed==expected and constructors==0
    item=Counter()
    for (stage,symbol),values in grouped_all[mode].items():
        if symbol==source_review['wind_penalty_anchor']:item.update(values)
    assert item['entries']==observed
    row={'profile':mode,'expected_lookup_calls':expected,'native_lookup_entries':observed,
         'lookup_self_ir':item['self'],'lookup_incoming_inclusive_ir_non_additive':item['inclusive'],
         'table_entry_constructor_calls_inside_collected_root':constructors}
    wind_rows.append(row)
    assert f"| {mode} | {expected:,} | {observed:,} | {item['self']:,} | {item['inclusive']:,} | {constructors:,} |" in report
assert wind_rows==wind_record['rows'] and wind_expected==10641
assert sha(BASE/'wind-native-counts.json')==validation['wind_native_counts_sha256']

# Independently reconstruct direct ratio/penalty records from raw caller edges.
# The new enclosure has one conditional software-round site; checked native
# structure permits helper entries minus direct round entries to count shortcuts.
assert source_review['bds60_ratio_enclosure_live_path_verified']
assert source_review['ratio_enclosure_anchor']==prefix+'cbRatioOutside250800'
ratio_record=read(BASE/'ratio-native-contexts.json')
assert ratio_record['source_review_sha256']==sha(BASE/'independent-review/source-review.json')
assert ratio_record['parser_sha256']==sha('review/diagnostics/analyze_callgrind.py')
assert ratio_record['analysis_sha256']==sha(BASE/'analysis/analysis.json')
assert ratio_record['previous_analysis_sha256']==sha('tests/evidence/diagnostics/gen22/analysis/analysis.json')
ratio_rows=[];ratio_direct=[]
ratio_modes=['adsb','commb','other']+[kind+r for kind in ('candidate','score') for r in ('40','44','45','50','60')]
previous_profiles={**previous['families'],**{'score'+k:v for k,v in previous['non_additive_register_score_probes'].items()},**{'candidate'+k:v for k,v in previous['non_additive_register_candidate_probes'].items()}}
for generation, profs, retained_contexts in [(22,previous_profiles,old_contexts),(23,profiles,mach_contexts)]:
    for mode in ratio_modes:
        info=profs[mode];path=Path(info['path'])
        if mode not in retained_contexts:
            ctx={};old_total,_,_,_,_=recount(path,info['root'],ctx)
            assert old_total==info['total_events']['Ir']
            retained_contexts[mode]=ctx
        ctx=retained_contexts[mode];stats={}
        for label,symbol in [('ratio',prefix+'cbRatioOutside250800'),('penalty',prefix+'cbPenalty')]:
            nodes={name:item for name,item in ctx.items() if re.split(r"'| \[clone ",name,maxsplit=1)[0]==symbol}
            n=sum(edge['calls'] for item in nodes.values() for edge in item['incoming'].values())
            own=sum(item['self_events']['Ir'] for item in nodes.values())
            inclusive=sum(edge['inclusive_events']['Ir'] for item in nodes.values() for edge in item['incoming'].values())
            stats[label]={'native_entries':n,'self_ir':own,'incoming_inclusive_ir_non_additive':inclusive}
            edges=[]
            for name,item in sorted(nodes.items()):
                for callee,edge in sorted(item['outgoing'].items()):
                    base=re.split(r"'| \[clone ",callee,maxsplit=1)[0]
                    if base not in {prefix+'Binary64_round',prefix+'Binary64_div',prefix+'cbRatioOutside250800','l_Rat_div','l_Rat_blt'}:continue
                    edges.append({'caller':name,'callee':callee,'callee_symbol':base,'native_entries':edge['calls'],'incoming_inclusive_ir_non_additive':edge['inclusive_events']['Ir']})
            ratio_direct.append({'generation':generation,'profile':mode,'root_label':label,'root_symbol':symbol,'stats':stats[label],'edges':edges,'profile_sha256':sha(path)})
        round_edges=[edge for edge in ratio_direct[-2]['edges'] if edge['callee_symbol']==prefix+'Binary64_round']
        fb=sum(edge['native_entries'] for edge in round_edges)
        fb_ir=sum(edge['incoming_inclusive_ir_non_additive'] for edge in round_edges)
        assert 0<=fb<=stats['ratio']['native_entries']<=stats['penalty']['native_entries']
        if mode not in ['commb','candidate60','score60']:assert stats['ratio']['native_entries']==fb==0
        row={'generation':generation,'profile':mode,**stats,'ratio_round_fallback_entries':fb,'ratio_round_fallback_inclusive_ir_non_additive':fb_ir,'ratio_shortcut_entries':stats['ratio']['native_entries']-fb}
        ratio_rows.append(row)
        if generation==23:
            r=row['ratio']
            assert f"| {mode} | {r['native_entries']:,} | {row['ratio_shortcut_entries']:,} | {fb:,} | {r['self_ir']:,} | {r['incoming_inclusive_ir_non_additive']:,} | {fb_ir:,} |" in report
assert ratio_rows==ratio_record['rows'] and len(ratio_rows)==26
assert ratio_direct==ratio_record['direct_contexts'] and len(ratio_direct)==52
assert sha(BASE/'ratio-native-contexts.json')==validation['ratio_native_contexts_sha256']


# Independently reproduce the exact live guard/parser context supplement.
constant_record=read(BASE/'constant-native-contexts.json')
assert constant_record['source_review_sha256']==sha(BASE/'independent-review/source-review.json')
assert constant_record['parser_sha256']==sha('review/diagnostics/analyze_callgrind.py')
constant_rows=[];constant_contexts=[];old_guard_counts={}
for generation, profs, context_sets in [(22,previous_profiles,old_contexts),(23,profiles,mach_contexts)]:
    for mode in ratio_modes:
        ctx=context_sets[mode];totals=Counter(native_entries=0,self_ir=0,inclusive_ir_non_additive=0,direct_parser_calls=0,direct_parser_ir_non_additive=0)
        for name,item in sorted(ctx.items()):
            if name.split("'")[0]!=prefix+'bdsWireValid':continue
            incoming=[{'caller':caller,'native_entries':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for caller,edge in sorted(item['incoming'].items())]
            outgoing=[{'callee':callee,'symbol':callee.split("'")[0],'native_entries':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for callee,edge in sorted(item['outgoing'].items())]
            constant_contexts.append({'generation':generation,'profile':mode,'context':name,'self_ir':item['self_events']['Ir'],'incoming':incoming,'outgoing':outgoing})
            totals.update(native_entries=sum(x['native_entries'] for x in incoming),self_ir=item['self_events']['Ir'],inclusive_ir_non_additive=sum(x['inclusive_ir_non_additive'] for x in incoming),direct_parser_calls=sum(x['native_entries'] for x in outgoing if x['symbol']=='lean_cstr_to_nat'),direct_parser_ir_non_additive=sum(x['inclusive_ir_non_additive'] for x in outgoing if x['symbol']=='lean_cstr_to_nat'))
        if generation==22:old_guard_counts[mode]=totals['native_entries']
        else:assert totals['native_entries']==old_guard_counts[mode] and totals['direct_parser_calls']==0
        constant_rows.append({'generation':generation,'profile':mode,**totals,'profile_sha256':sha(profs[mode]['path'])})
assert constant_rows==constant_record['rows']
def canonical_contexts(records):
    return [{**x,'incoming':sorted(x['incoming'],key=lambda a:a['caller']),'outgoing':sorted(x['outgoing'],key=lambda a:a['callee'])} for x in records]
assert canonical_contexts(constant_contexts)==canonical_contexts(constant_record['contexts'])
assert sha(BASE/'constant-native-contexts.json')==validation['constant_native_contexts_sha256']
assert source_review['commb_payload_limit_live_path_verified']


pack_record=read(BASE/'pack-fields-direct-costs.json')
pack_symbol='lp_lean1090_List_foldl___at___00Lean1090_Impl_packFields_spec__0'
pack_results=[]
for pack_generation,pack_context_sets in [(22,old_contexts),(23,mach_contexts)]:
 pack_rows=[];pack_total=Counter(entry_calls=0,self_ir=0,incoming_inclusive_ir=0);pack_children={}
 for family in ('adsb','commb','other'):
     children={};contexts=[];totals=Counter(entry_calls=0,self_ir=0,incoming_inclusive_ir=0)
     for name,item in pack_context_sets[family].items():
         if name.split("'")[0]!=pack_symbol:continue
         incoming_calls=sum(x['calls'] for x in item['incoming'].values())
         incoming_ir=sum(x['inclusive_events']['Ir'] for x in item['incoming'].values())
         direct=[]
         for child,edge in item['outgoing'].items():
             symbol=child.split("'")[0]
             row={'context':child,'symbol':symbol,'calls':edge['calls'],'inclusive_ir':edge['inclusive_events']['Ir']}
             direct.append(row)
             children.setdefault(symbol,Counter()).update(calls=row['calls'],inclusive_ir=row['inclusive_ir'])
             pack_children.setdefault(symbol,Counter()).update(calls=row['calls'],inclusive_ir=row['inclusive_ir'])
         assert item['self_events']['Ir']+sum(x['inclusive_ir'] for x in direct)==incoming_ir
         contexts.append({'context':name,'entry_calls':incoming_calls,'self_ir':item['self_events']['Ir'],'incoming_inclusive_ir':incoming_ir,'direct_children':direct})
         totals.update(entry_calls=incoming_calls,self_ir=item['self_events']['Ir'],incoming_inclusive_ir=incoming_ir)
     pack_total.update(totals)
     pack_rows.append({'family':family,**totals,'direct_children':children,'contexts':contexts,'profile_sha256':sha(Path(f'tests/evidence/diagnostics/gen{pack_generation}')/'callgrind'/family/'callgrind.out.1.gz')})
 def canonical_pack(rows):
     return [{**r,'contexts':sorted([{**c,'direct_children':sorted(c['direct_children'],key=lambda x:x['context'])} for c in r['contexts']],key=lambda x:x['context'])} for r in rows]
 assert canonical_pack(pack_rows)==canonical_pack(next(g for g in pack_record['generations'] if g['generation']==pack_generation)['rows'])
 g=next(g for g in pack_record['generations'] if g['generation']==pack_generation)
 assert dict(pack_total)==g['total'] and pack_children==g['direct_children_total']
 pc=g['generated_c'];lines=Path(pc['path']).read_text().splitlines()
 assert sha(pc['path'])==pc['sha256'] and '\n'.join(lines[pc['start_line']-1:pc['end_line']])+'\n'==pc['source']
 pack_results.append({'generation':pack_generation,'total':dict(pack_total),'direct_children':pack_children})
assert pack_record['raw_word_path_zero_collected_packing_entries'] and pack_record['same_fold_entry_populations']
assert pack_results[0]['total']['entry_calls']==0 and pack_results[1]['total']['entry_calls']==0
assert pack_record['source_review_sha256']==sha(BASE/'independent-review/source-review.json')
assert sha(BASE/'pack-fields-direct-costs.json')==validation['pack_fields_direct_costs_sha256']
# New power-table supplement: independent raw incoming/self/direct-edge counts
# for every actual anchor, including absent startup boundaries.
assert power_record['source_review_sha256']==sha(BASE/'independent-review/source-review.json')
assert power_record['parser_sha256']==sha('review/diagnostics/analyze_callgrind.py')
assert source_review['power_two_table_live_path_verified']
assert power_anchors=={k:source_review['power_two_'+k+'_anchor'] for k in ['lookup','formula','table_entry','table_initializer','module_initializer']}
power_rows=[];power_contexts=[]
for generation,profs,context_sets,group_sets in [(22,previous_profiles,old_contexts,None),(23,profiles,mach_contexts,grouped_all)]:
 for mode in ratio_modes:
  ctx=context_sets[mode];row={'generation':generation,'profile':mode,'profile_sha256':sha(profs[mode]['path']),'direct_lookup_formula_calls':0,'direct_lookup_formula_inclusive_ir_non_additive':0}
  for label,symbol in power_anchors.items():
   total=Counter(native_entries=0,self_ir=0,incoming_inclusive_ir_non_additive=0)
   for name,item in sorted(ctx.items()):
    if name.split("'")[0]!=symbol:continue
    incoming=[{'caller':caller,'native_entries':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for caller,edge in item['incoming'].items()]
    outgoing=[{'callee':callee,'symbol':callee.split("'")[0],'native_entries':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for callee,edge in item['outgoing'].items()]
    power_contexts.append({'generation':generation,'profile':mode,'anchor':label,'context':name,'self_ir':item['self_events']['Ir'],'incoming':incoming,'outgoing':outgoing})
    total.update(native_entries=sum(e['native_entries'] for e in incoming),self_ir=item['self_events']['Ir'],incoming_inclusive_ir_non_additive=sum(e['inclusive_ir_non_additive'] for e in incoming))
    if label=='lookup':
     direct=[e for e in outgoing if e['symbol']==power_anchors['formula']]
     row['direct_lookup_formula_calls']+=sum(e['native_entries'] for e in direct)
     row['direct_lookup_formula_inclusive_ir_non_additive']+=sum(e['inclusive_ir_non_additive'] for e in direct)
   row[label]=dict(total)
   if generation==23:
    grouped=Counter()
    for (stage,base),item in group_sets[mode].items():
     if base==symbol:grouped.update(item)
    assert (total['native_entries'],total['self_ir'],total['incoming_inclusive_ir_non_additive'])==(grouped['entries'],grouped['self'],grouped['inclusive'])
  if generation==23:
   assert 0<=row['direct_lookup_formula_calls']<=row['lookup']['native_entries']
   for label in ['table_entry','table_initializer','module_initializer']:assert row[label]['native_entries']==row[label]['self_ir']==0
  power_rows.append(row)
assert power_rows==power_record['rows']
assert canonical_contexts(power_contexts)==canonical_contexts(power_record['contexts'])
assert sha(BASE/'power-native-contexts.json')==validation['power_native_contexts_sha256']
# New prioritization supplement: independently reconstruct every selected raw
# family context and direct child, using caller-chain stages rather than graph propagation.
assert priority_record['analysis_sha256']==sha(BASE/'analysis/analysis.json')
assert priority_record['source_review_sha256']==sha(BASE/'independent-review/source-review.json')
assert priority_record['parser_sha256']==sha('review/diagnostics/analyze_callgrind.py')
assert priority_record['extractor_sha256']==sha(BASE/'extract_priority_contexts.py')
priority_selected.update(symbol for mode in analysis['families'] for stage,symbol in grouped_all[mode] if symbol.startswith(prefix+'cbValid'))
priority_contexts=[];priority_groups={}
for mode in analysis['families']:
 assert priority_record['profile_hashes'][str(BASE/'callgrind'/mode/'callgrind.out.1.gz')]==sha(BASE/'callgrind'/mode/'callgrind.out.1.gz')
 for name,item in mach_contexts[mode].items():
  symbol=re.split(r"'| \[clone ",name,maxsplit=1)[0];stage=item['stage']
  if symbol not in priority_selected or stage is None:continue
  incoming=[{'caller':caller,'calls':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for caller,edge in item['incoming'].items()]
  outgoing=[{'context':child,'symbol':re.split(r"'| \[clone ",child,maxsplit=1)[0],'calls':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for child,edge in item['outgoing'].items()]
  priority_contexts.append({'family':mode,'stage':stage,'symbol':symbol,'context':name,'self_ir':item['self_events']['Ir'],'incoming':incoming,'outgoing':outgoing})
  counts_,children=priority_groups.setdefault((stage,symbol),(Counter(),{}))
  counts_.update(contexts=1,self_ir=item['self_events']['Ir'],native_entries=sum(r['calls'] for r in incoming),incoming_inclusive_ir_non_additive=sum(r['inclusive_ir_non_additive'] for r in incoming))
  for row in outgoing:children.setdefault(row['symbol'],Counter()).update(calls=row['calls'],inclusive_ir_non_additive=row['inclusive_ir_non_additive'])
def canonical_priority(rows):
 return sorted([{**r,'incoming':sorted(r['incoming'],key=lambda x:x['caller']),'outgoing':sorted(r['outgoing'],key=lambda x:x['context'])} for r in rows],key=lambda x:(x['family'],x['context']))
assert canonical_priority(priority_contexts)==canonical_priority(priority_record['contexts'])
expected_priority={(r['stage'],r['symbol']):r for r in priority_record['rows']}
assert set(expected_priority)==set(priority_groups)
for key,(cnt,children) in priority_groups.items():
 row=expected_priority[key]
 assert {k:row[k] for k in cnt}==dict(cnt)
 assert {r['symbol']:{k:v for k,v in r.items() if k!='symbol'} for r in row['direct_children']}==dict(children)
assert priority_record['unobserved_selected_symbols']==sorted(priority_selected-{symbol for stage,symbol in priority_groups})
assert sha(BASE/'priority-helper-contexts.json')==validation['priority_helper_contexts_sha256']
# Independently regroup the late semantic supplement from raw-recounted contexts.
semantic=read(BASE/'semantic-caller-contexts.json')
semantic_contexts=[r for r in priority_contexts if r['stage']=='semantic_oracle_values' and r['symbol']==P+'payloadValue']
semantic_groups={}
for r in semantic_contexts:
 for edge in r['incoming']:
  ancestor='Semantics_commB' if P+'Semantics_commB' in edge['caller'] else 'Semantics_adsb' if P+'Semantics_adsb' in edge['caller'] else 'other'
  key=(re.split(r"'| \[clone ",edge['caller'],maxsplit=1)[0],ancestor)
  semantic_groups.setdefault(key,Counter()).update(calls=edge['calls'],inclusive_ir_non_additive=edge['inclusive_ir_non_additive'])
semantic_rows=[dict(direct_caller=k[0],semantic_ancestor=k[1],**v) for k,v in sorted(semantic_groups.items())]
assert semantic_rows==semantic['payload_value_direct_callers']
assert canonical_priority(semantic_contexts)==canonical_priority(semantic['contexts'])
whole=expected_priority['semantic_oracle_values',P+'payloadValue']
assert {k:whole[k] for k in ['native_entries','self_ir','incoming_inclusive_ir_non_additive']}==semantic['payload_value_total']
assert sum(r['calls'] for r in semantic_rows)==whole['native_entries'] and sum(r['inclusive_ir_non_additive'] for r in semantic_rows)==whole['incoming_inclusive_ir_non_additive']
assert semantic['semantic_commb']==expected_priority['semantic_oracle_values',P+'Semantics_commB']
float_rows=[dict(family=family,stage=stage,**row) for family,profile in analysis['families'].items() for stage,helpers in profile['stage_helper_observations_non_additive'].items() for row in helpers if 'oracleCommBFloats' in row['symbol'] or 'commBStandardFloats' in row['symbol']]
assert semantic['actual_float_constructor_helper_rows']==float_rows
for path,h in semantic['bindings'].items():assert sha(path)==h,path

# Gen20 bit supplement: independently rebuild all selected callers and their
# incoming/outgoing observations from this reviewer's raw parser.
bit_record=read(BASE/'bit-extraction-contexts.json')
assert bit_record['selected_symbols']==sorted(bit_selected)
assert bit_record['parser_sha256']==sha('review/diagnostics/analyze_callgrind.py')
assert bit_record['extractor_sha256']==sha(BASE/'extract_bit_contexts.py')
bit_results=[]
for generation, context_sets in [(22,old_contexts),(23,mach_contexts)]:
 record=next(g for g in bit_record['generations'] if g['generation']==generation)
 root=Path(f'tests/evidence/diagnostics/gen{generation}')
 assert record['analysis_sha256']==sha(root/'analysis/analysis.json')
 assert record['source_review_sha256']==sha(root/'independent-review/source-review.json')
 grouped={};contexts=[]
 for mode in analysis['families']:
  assert record['profile_sha256'][str(root/'callgrind'/mode/'callgrind.out.1.gz')]==sha(root/'callgrind'/mode/'callgrind.out.1.gz')
  for name,item in context_sets[mode].items():
   symbol=re.split(r"'| \[clone ",name,maxsplit=1)[0];stage=item['stage']
   if symbol not in bit_selected or stage is None:continue
   incoming=[{'caller':caller,'calls':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for caller,edge in item['incoming'].items()]
   outgoing=[{'context':child,'symbol':re.split(r"'| \[clone ",child,maxsplit=1)[0],'calls':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for child,edge in item['outgoing'].items()]
   contexts.append({'family':mode,'stage':stage,'symbol':symbol,'context':name,'self_ir':item['self_events']['Ir'],'incoming':incoming,'outgoing':outgoing})
   counters,children=grouped.setdefault((stage,symbol),(Counter(),{}))
   counters.update(contexts=1,self_ir=item['self_events']['Ir'],native_entries=sum(r['calls'] for r in incoming),incoming_inclusive_ir_non_additive=sum(r['inclusive_ir_non_additive'] for r in incoming))
   for row in outgoing:children.setdefault(row['symbol'],Counter()).update(calls=row['calls'],inclusive_ir_non_additive=row['inclusive_ir_non_additive'])
 assert canonical_priority(contexts)==canonical_priority(record['contexts'])
 expected={(r['stage'],r['symbol']):r for r in record['rows']}
 assert set(expected)==set(grouped)
 power=[]
 for key,(counters,children) in grouped.items():
  row=expected[key];assert {k:row[k] for k in counters}==dict(counters)
  assert {r['symbol']:{k:v for k,v in r.items() if k!='symbol'} for r in row['direct_children']}==dict(children)
  if 'lean_nat_pow' in children:power.append(dict(stage=key[0],caller=key[1],symbol='lean_nat_pow',**children['lean_nat_pow']))
 assert sorted(power,key=lambda x:json.dumps(x,sort_keys=True))==sorted(record['direct_power_edges'],key=lambda x:json.dumps(x,sort_keys=True))
 totals={'calls':sum(r['calls'] for r in power),'inclusive_ir_non_additive':sum(r['inclusive_ir_non_additive'] for r in power)}
 assert totals==record['direct_power_totals']
 assert record['unobserved_selected_symbols']==sorted(bit_selected-{symbol for stage,symbol in grouped})
 bit_results.append(dict(generation=generation,contexts=len(contexts),helper_groups=len(grouped),direct_power_totals=totals))
assert bit_results[1]['direct_power_totals']['calls']==0
assert sha(BASE/'bit-extraction-contexts.json')==validation['bit_extraction_contexts_sha256']
# Exact affine-boundary and all direct-child recount from independent raw contexts.
affine_record=read(BASE/'affine-native-contexts.json')
assert affine_record['selected_symbols']==sorted(affine_selected)
assert affine_record['parser_sha256']==sha('review/diagnostics/analyze_callgrind.py')
assert affine_record['extractor_sha256']==sha(BASE/'extract_affine_contexts.py')
affine_results=[]
for generation, context_sets in [(22,old_contexts),(23,mach_contexts)]:
 record=next(g for g in affine_record['generations'] if g['generation']==generation)
 root=Path(f'tests/evidence/diagnostics/gen{generation}')
 assert record['analysis_sha256']==sha(root/'analysis/analysis.json')
 assert record['source_review_sha256']==sha(root/'independent-review/source-review.json')
 grouped={};contexts=[]
 for mode in analysis['families']:
  assert record['profile_sha256'][str(root/'callgrind'/mode/'callgrind.out.1.gz')]==sha(root/'callgrind'/mode/'callgrind.out.1.gz')
  for name,item in context_sets[mode].items():
   symbol=re.split(r"'| \[clone ",name,maxsplit=1)[0];stage=item['stage']
   if symbol not in affine_selected or stage is None:continue
   incoming=[{'caller':caller,'calls':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for caller,edge in item['incoming'].items()]
   outgoing=[{'context':child,'symbol':re.split(r"'| \[clone ",child,maxsplit=1)[0],'calls':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for child,edge in item['outgoing'].items()]
   contexts.append({'family':mode,'stage':stage,'symbol':symbol,'context':name,'self_ir':item['self_events']['Ir'],'incoming':incoming,'outgoing':outgoing})
   counters,children=grouped.setdefault((stage,symbol),(Counter(),{}))
   counters.update(contexts=1,self_ir=item['self_events']['Ir'],native_entries=sum(r['calls'] for r in incoming),incoming_inclusive_ir_non_additive=sum(r['inclusive_ir_non_additive'] for r in incoming))
   for row in outgoing:children.setdefault(row['symbol'],Counter()).update(calls=row['calls'],inclusive_ir_non_additive=row['inclusive_ir_non_additive'])
 assert canonical_priority(contexts)==canonical_priority(record['contexts'])
 expected={(r['stage'],r['symbol']):r for r in record['rows']}
 assert set(expected)==set(grouped)
 power=[]
 for key,(counters,children) in grouped.items():
  row=expected[key];assert {k:row[k] for k in counters}==dict(counters)
  assert {r['symbol']:{k:v for k,v in r.items() if k!='symbol'} for r in row['direct_children']}==dict(children)
  if 'lean_nat_pow' in children:power.append(dict(stage=key[0],caller=key[1],symbol='lean_nat_pow',**children['lean_nat_pow']))
 assert sorted(power,key=lambda x:json.dumps(x,sort_keys=True))==sorted(record['direct_power_edges'],key=lambda x:json.dumps(x,sort_keys=True))
 totals={'calls':sum(r['calls'] for r in power),'inclusive_ir_non_additive':sum(r['inclusive_ir_non_additive'] for r in power)}
 assert totals==record['direct_power_totals']
 assert record['unobserved_selected_symbols']==sorted(affine_selected-{symbol for stage,symbol in grouped})
 affine_results.append(dict(generation=generation,contexts=len(contexts),helper_groups=len(grouped),direct_power_totals=totals))
payload_entries=[]
for generation in affine_record['generations']:
 payload_rows=[row for row in generation['rows'] if row['symbol']==P+'payloadValue']
 payload_entries.append({row['stage']:row['native_entries'] for row in payload_rows})
 if generation['generation']==23:assert not any(child['calls'] for row in payload_rows for child in row['direct_children'] if child['symbol']=='l_Rat_mul')
assert payload_entries[0]==payload_entries[1] and affine_record['same_payload_value_entries_by_stage']
assert sha(BASE/'affine-native-contexts.json')==validation['affine_native_contexts_sha256']
crc_record=read(BASE/'crc-byte-contexts.json')
assert crc_record['selected_symbols']==sorted(crc_selected)
assert crc_record['parser_sha256']==sha('review/diagnostics/analyze_callgrind.py')
assert crc_record['extractor_sha256']==sha(BASE/'extract_crc_contexts.py')
crc_results=[]
for generation, context_sets in [(22,old_contexts),(23,mach_contexts)]:
 record=next(g for g in crc_record['generations'] if g['generation']==generation)
 root=Path(f'tests/evidence/diagnostics/gen{generation}')
 assert record['analysis_sha256']==sha(root/'analysis/analysis.json')
 assert record['source_review_sha256']==sha(root/'independent-review/source-review.json')
 grouped={};contexts=[]
 for mode in analysis['families']:
  assert record['profile_sha256'][str(root/'callgrind'/mode/'callgrind.out.1.gz')]==sha(root/'callgrind'/mode/'callgrind.out.1.gz')
  for name,item in context_sets[mode].items():
   symbol=re.split(r"'| \[clone ",name,maxsplit=1)[0];stage=item['stage']
   if symbol not in crc_selected or stage is None:continue
   incoming=[{'caller':caller,'calls':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for caller,edge in item['incoming'].items()]
   outgoing=[{'context':child,'symbol':re.split(r"'| \[clone ",child,maxsplit=1)[0],'calls':edge['calls'],'inclusive_ir_non_additive':edge['inclusive_events']['Ir']} for child,edge in item['outgoing'].items()]
   contexts.append({'family':mode,'stage':stage,'symbol':symbol,'context':name,'self_ir':item['self_events']['Ir'],'incoming':incoming,'outgoing':outgoing})
   counters,children=grouped.setdefault((stage,symbol),(Counter(),{}))
   counters.update(contexts=1,self_ir=item['self_events']['Ir'],native_entries=sum(r['calls'] for r in incoming),incoming_inclusive_ir_non_additive=sum(r['inclusive_ir_non_additive'] for r in incoming))
   for row in outgoing:children.setdefault(row['symbol'],Counter()).update(calls=row['calls'],inclusive_ir_non_additive=row['inclusive_ir_non_additive'])
 assert canonical_priority(contexts)==canonical_priority(record['contexts'])
 expected={(r['stage'],r['symbol']):r for r in record['rows']}
 assert set(expected)==set(grouped)
 power=[]
 for key,(counters,children) in grouped.items():
  row=expected[key];assert {k:row[k] for k in counters}==dict(counters)
  assert {r['symbol']:{k:v for k,v in r.items() if k!='symbol'} for r in row['direct_children']}==dict(children)
  if 'lean_nat_pow' in children:power.append(dict(stage=key[0],caller=key[1],symbol='lean_nat_pow',**children['lean_nat_pow']))
 assert sorted(power,key=lambda x:json.dumps(x,sort_keys=True))==sorted(record['direct_power_edges'],key=lambda x:json.dumps(x,sort_keys=True))
 totals={'calls':sum(r['calls'] for r in power),'inclusive_ir_non_additive':sum(r['inclusive_ir_non_additive'] for r in power)}
 assert totals==record['direct_power_totals']
 assert record['unobserved_selected_symbols']==sorted(crc_selected-{symbol for stage,symbol in grouped})
 crc_results.append(dict(generation=generation,contexts=len(contexts),helper_groups=len(grouped),direct_power_totals=totals))
assert crc_results[1]['direct_power_totals']['calls']==0
assert sha(BASE/'crc-byte-contexts.json')==validation['crc_byte_contexts_sha256']
assert crc_record['source_review_sha256']==sha(BASE/'independent-review/source-review.json')
assert crc_record['checked_live_crc_census']==live_crc
crc_native=[]
for mode in list(analysis['families'])+[kind+reg for kind in ['candidate','score'] for reg in analysis['non_additive_register_'+kind+'_probes']]:
    dfs=next((ds for fam,ds in [('adsb',[17,18]),('commb',[20,21]),('other',[x for x in range(32) if x not in [17,18,20,21]])] if fam==mode),[])
    expected=sum(per_df[df]['crc_call_predictions'] for df in dfs)
    steps=sum(per_df[df]['crc_step_predictions'] for df in dfs)
    observed={key:counts[mode][source_review[key]] for key in ['parity_byte_wrapper_anchor','parity_byte_fold_anchor','parity_bit_wrapper_anchor','parity_bit_fold_anchor']}
    assert observed['parity_byte_wrapper_anchor']==observed['parity_byte_fold_anchor']==expected
    assert observed['parity_bit_wrapper_anchor']==observed['parity_bit_fold_anchor']==0
    parser_entries=counts[mode][P+'decodeFrameWithWord'];syndrome_entries=counts[mode][P+'Parity_syndrome']
    reconstruction={name:counts[mode][P+name] for name in ['decodeFrame','frameSyndrome','Parity_checksum','packFields']}
    assert parser_entries==syndrome_entries==expected and not any(reconstruction.values())
    crc_native.append(dict(profile=mode,observed_parser_entries=parser_entries,observed_syndrome_entries=syndrome_entries,observed_reconstruction_entries=reconstruction,expected_crc_calls_from_checked_census=expected,predicted_byte_iterations_not_native_entries=steps//8,predicted_bit_updates_not_native_entries=steps,observed_native_entries=observed))
assert crc_native==crc_record['native_counts']
completion=read(BASE/'perf/completion.json')
assert completion['samples']==len(blocks) and completion['included_decode_stacks']==len(included)
assert len(capture['before_hashes'])==293 and all(sha(p)==h for p,h in capture['before_hashes'].items())
sequence=read('tests/evidence/diagnostics/gen23-cpr/isolated-perf-completion.json')
assert sequence['status']=='passed' and sequence['sequential_modes']==['decode','cpr']
assert sequence['finished_utc']<min(x['started_utc'] for x in campaign['native_runs'])
unknown_leaves=sum(row['leaf']=='[unknown]' for row in sample_records)
assert unknown_leaves==completion['unknown_decode_leaf_samples']
assert completion['captured_input_hash_count']==293
for name in ['report-self.txt','report-children.txt']:assert '# Total Lost Samples: 0' in (BASE/'perf'/name).read_text().splitlines()
hm.verify(history)
for name,digest in campaign['protected_inputs'].items(): assert sha(name)==digest,name
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),
 'archive_files':len(manifest['files']),'archive_stored_bytes':stored,'protected_live_inputs':len(campaign['protected_inputs']),
 'profiles_independently_recounted':recounted,'exclusive_stages':dict(stage_totals),'total_ir':sum(stage_totals.values()),
 'affine_comparisons_independently_recounted':affine_results,'affine_supplement_sha256':sha(BASE/'affine-native-contexts.json'),'integer_affine_normalization_live_path_verified':True,
 'helper_group_rows_independently_recounted':helper_rows_checked,'crc_context_comparisons':crc_results,'crc_native_counts':crc_native,'crc_supplement_sha256':sha(BASE/'crc-byte-contexts.json'),
 'bit_extraction_comparisons_independently_recounted':bit_results,'bit_extraction_supplement_sha256':sha(BASE/'bit-extraction-contexts.json'),
 'priority_helper_rows_independently_recounted':len(priority_groups),'priority_contexts_independently_recounted':len(priority_contexts),'priority_supplement_sha256':sha(BASE/'priority-helper-contexts.json'),
 'fresh_native_sets':len(fresh),'reused_production_objects':build['reused_production_object_count'],
 'historical_committed_files':historical_count,'historical_ignored_identity_count':len(history['binding']['untracked_and_ignored_file_identities']),
 'historical_perf_identity_count':len(history['binding']['retained_historical_perf_identities']),
 'historical_limits':history['limits'],'benchmark_files_unchanged':len(bench_archive['files']),
 'raw_word_syndrome_live_path_verified':True,'shared_crc_context_count':len(shared_crc_contexts),'crc_entries':crc_entries,'predicted_crc_iterations':crc_steps,'predicted_byte_iterations':crc_byte_iterations,'observed_crc_paths':crc_observed,
 'integer_gate_observations':integer_observations,'choose_entries':reached,'fallback_entries':fallbacks,
 'all_helper_rows_and_inclusive_contexts_recounted':True,'old_new_selected_context_comparisons_recounted':True,
 'ratio_summary_rows':len(ratio_rows),'ratio_direct_context_groups':len(ratio_direct),
 'constant_summary_rows':len(constant_rows),'constant_contexts':len(constant_contexts),
 'power_rows_independently_recounted':power_rows,'power_contexts_recounted':len(power_contexts),'pack_comparisons':pack_results,'wind_rows':wind_rows,'byte_counts':byte_counts,
 'perf_raw_samples':len(blocks),'perf_visible_decoder_samples':len(included),'perf_unknown_frame_samples':unknown,'perf_included_unknown_leaves':unknown_leaves,
 'semantic_supplement_sha256':sha(BASE/'semantic-caller-contexts.json'),'semantic_direct_caller_rows':semantic_rows,'commb_validity_tables_live_path_verified':True,
 'report_sha256':sha('docs/GEN23-COST-BREAKDOWN.md'),'analysis_sha256':sha(BASE/'analysis/analysis.json'),
 'manifest_sha256':sha(BASE/'archive-manifest.json'),'validation_sha256':sha(BASE/'validation.json'),
 'source_review_sha256':sha(BASE/'independent-review/source-review.json'),'checker_sha256':sha(__file__)}
assert not (BASE/'independent-review/final-checks.json').exists()
(BASE/'independent-review/final-checks.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))

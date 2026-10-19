#!/usr/bin/env python3
"""Independently check retained gen15 proof/native evidence; no decoder execution."""
import sys
sys.dont_write_bytecode=True
import hashlib
import json
from pathlib import Path
import re
import subprocess
import difflib

OUT = Path(__file__).resolve().parent
P = 'lp_lean1090_Lean1090_Impl_'
WORD = 'lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__1'
FALLBACK = 'lp_lean1090_List_foldl___at___00Lean1090_Impl_bytesValue_spec__0'
ALLOWED = {'propext', 'Classical.choice', 'Quot.sound'}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def body(text, symbol):
    match = re.search(r'\b' + re.escape(symbol) + r'\([^;{}]*\)\s*\{', text)
    assert match, symbol
    depth = 0
    for i in range(match.end() - 1, len(text)):
        depth += (text[i] == '{') - (text[i] == '}')
        if depth == 0:
            return text[match.start():i + 1]
    raise AssertionError(symbol)


def calls(text):
    return re.findall(r'\b(?:call|jmp)\s+[0-9a-f]+ <([^>+]+)>', text)


def instructions(text):
    rows = []
    for line in text.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+(\w+)\s*(.*)', line)
        if match:
            rows.append({'address': int(match[1], 16), 'op': match[2], 'args': match[3]})
    return rows


def facts(text):
    pattern = r"'([^']+)' (?:depends on axioms:\s*\[([^]]*)\]|does not depend on any axioms)"
    return [{'name': name, 'axioms': sorted(x.strip() for x in ax.split(',') if x.strip())}
            for name, ax in re.findall(pattern, text, re.S)]


def graph(text):
    rows = instructions(text)
    indices = {r['address']: i for i, r in enumerate(rows)}
    edges, exits = {}, {}
    for i, r in enumerate(rows):
        edges[i] = []
        if r['op'] == 'ret':
            exits[i] = 'ret'
            continue
        if r['op'].startswith('j'):
            m = re.match(r'([0-9a-f]+) <([^>]+)>', r['args'])
            assert m, r
            target = int(m[1], 16)
            if target in indices:
                edges[i].append(indices[target])
            else:
                assert r['op'] == 'jmp', r
                exits[i] = m[2]
            if r['op'] == 'jmp':
                continue
        assert i + 1 < len(rows), r
        edges[i].append(i + 1)
    return rows, edges, exits


def counted_paths(text, start, tracked):
    """Count selected external calls on every static normal-exit path."""
    rows, edges, exits = graph(text)
    begin = next(i for i, row in enumerate(rows) if row['address'] == start)
    pending, seen, ended = [(begin, (0,) * len(tracked))], set(), set()
    while pending:
        i, counters = pending.pop()
        if (i, counters) in seen:
            continue
        seen.add((i, counters))
        row = rows[i]
        updated = list(counters)
        if row['op'] == 'call':
            for j, name in enumerate(tracked):
                if '<' + name + '>' in row['args']:
                    updated[j] += 1
        assert max(updated, default=0) <= 2, ('selected call repeated in a loop', row)
        if i in exits:
            ended.add((tuple(updated), exits[i]))
        pending.extend((j, tuple(updated)) for j in edges[i])
    assert ended
    return {'start': hex(start), 'reachable_instruction_count': len({i for i, _ in seen}),
            'tracked': tracked, 'normal_exits': [{'counts': list(c), 'target': t} for c, t in sorted(ended)]}


def event_paths(text, events):
    """Follow all CFG successors and retain selected call/load event sequences."""
    rows, edges, exits = graph(text)
    pending, seen, ended = [(0, ())], set(), set()
    while pending:
        i, sequence = pending.pop()
        if (i, sequence) in seen:
            continue
        seen.add((i, sequence))
        sequence += (events[rows[i]['address']],) if rows[i]['address'] in events else ()
        assert len(sequence) <= 8
        if i in exits:
            ended.add((sequence, exits[i]))
        pending.extend((j, sequence) for j in edges[i])
    return {'instruction_count': len(rows), 'reachable_instructions': len({i for i, _ in seen}),
            'event_sites': {hex(k): v for k, v in events.items()},
            'normal_exits': [{'events': list(s), 'target': t} for s, t in sorted(ended)]}


def main():
    assert not (OUT/'review.json').exists()
    inspection=json.loads((OUT/'inspection-inputs.json').read_text())
    assert all(sha(p)==r['sha256'] for p,r in inspection['inputs'].items())
    assert all((OUT/d).read_bytes()==Path(p).read_bytes() for p,d in inspection['retained'].items())
    assert all(r['exit_code']==0 and not (OUT/r['stderr']).read_bytes() for r in inspection['commands'])
    retained=OUT/'retained';c=(retained/'.lake/build/ir/Impl/CommB.c').read_text()
    old=(retained/'tests/evidence/diagnostics/gen14/generated-c/Impl/CommB.c').read_text()
    source=(retained/'Impl/CommB.lean').read_text();proof=(retained/'Proofs/CommBConstant.lean').read_text()
    decoder=(retained/'Proofs/Decoder.lean').read_text();build=inspection['successful_integrated_build']
    logpath=Path(inspection['successful_integrated_build_path']).with_suffix('.log');log=logpath.read_text()
    helper=json.loads((OUT/'source-proof-review.json').read_text());supplement=json.loads((OUT/'constant-path-capture.json').read_text())
    constant=P+'commBPayloadLimit';wire=body(c,P+'bdsWireValid');oldwire=body(old,P+'bdsWireValid');init=body(c,'initialize_lean1090_Impl_CommB')
    normalize=lambda x:re.sub(r'(?<=_)\d+(?=_)','N',x)
    checks={}
    checks['integrated_build_passed_3523_jobs']=build['status']=='passed' and build['exit_code']==0 and 'Build completed successfully (3523 jobs).' in log and sha(logpath)==build['log_sha256']
    checks['three_integrated_sources_unchanged']=len(build['inputs_after'])==3 and build['inputs_before']==build['inputs_after'] and all(sha(p)==h for p,h in build['inputs_after'].items())
    checks['independent_universal_helper_review_bound']=helper['status']=='passed' and not helper['findings'] and helper['unconditional_all_register_word_equality_verified'] and all(sha(p)==r['sha256'] for p,r in helper['inputs'].items())
    checks['exact_runtime_scope_diff_retained']=sha(OUT/'verified-before-after.diff')==helper['verified_diff_sha256'] and (OUT/'runtime-changed-files.txt').read_text().strip()=='Impl/CommB.lean'
    checks['constant_transparent_exact_and_noinline']='@[noinline] def commBPayloadLimit : Nat := 2^56' in source and 'theorem payload_limit_eq : Impl.commBPayloadLimit = 2^56 := rfl' in proof
    checks['C_literal_parse_moved_to_zero_argument_initializer']=body(c,'_init_'+constant).count('lean_cstr_to_nat("72057594037927936")')==1 and 'lean_cstr_to_nat' not in wire
    checks['C_live_guard_reads_same_global_once']=wire.count('= '+constant+';')==1 and 'lean_nat_dec_lt' in wire
    checks['C_guard_and_all_dispatch_branches_otherwise_identical']=normalize(wire)==normalize(oldwire.replace('lean_cstr_to_nat("72057594037927936")',constant))
    checks['C_initialization_once_before_main_persistent']=init.count(constant+' = _init_'+constant+'();')==1 and 'lean_mark_persistent('+constant+');' in init and 'if (_G_initialized)' in init and '_G_initialized = true;' in init
    protected=['cbRatioOutside250800','cbPenalty','cbValid50','cbValid60','cbValid18','cbValid19','cbValid40','cbWindPenalty50','cbWindPenaltyTable___lam__0','cbScorePasses','commBCoreEligible','decodeBDS','cbDensityTermsFast','cbQNH64','cbMach64']
    checks['other_CommB_C_bodies_identical_modulo_generated_local_numbers']=all(normalize(body(c,P+n))==normalize(body(old,P+n)) for n in protected)
    asm=(OUT/'binary-bdsWireValid.txt').read_text();rows=instructions(asm)
    global_i=next(i for i,r in enumerate(rows) if '<'+constant+'>' in r['args'])
    checks['native_guard_global_load_dominates_dispatch']=rows[global_i]['op']=='lea' and rows[global_i+1]['op']=='mov' and '(%rax),%rax' in rows[global_i+1]['args'] and all(not r['op'].startswith(('j','call')) for r in rows[:global_i+2])
    checks['native_guard_has_no_parser_or_constant_getter_call']='lean_cstr_to_nat' not in calls(asm) and constant not in calls(asm)
    checks['native_guard_retains_big_Nat_comparison']=any('lean_nat_big' in name for name in calls(asm))
    checks['native_literal_rodata_and_persistent_initialization_verified']=supplement['status']=='passed' and supplement['literal_ascii']=='72057594037927936' and supplement['inspection_sha256']==sha(OUT/'inspection-inputs.json') and supplement['binary_sha256']==inspection['inputs']['.lake/build/bin/lean1090']['sha256'] and supplement['all_binary_bytes_unchanged']
    initialization=(OUT/'binary-initialize_lean1090_Impl_CommB.txt').read_text().splitlines();index=next(i for i,l in enumerate(initialization) if '<'+constant+'>' in l)
    checks['native_initializer_parser_result_stored_and_marked_persistent']='lean_cstr_to_nat' in initialization[index-1] and 'mov    %rax,(%rcx)' in initialization[index+1] and 'mov    %rax,%rdi' in initialization[index+2] and 'lean_mark_persistent' in initialization[index+3]
    checks['actual_inference_and_direct_decoder_call_live_guard']=all(calls((OUT/('binary-'+name+'.txt')).read_text()).count(P+'bdsWireValid')==1 for name in ['commBCoreEligible','decodeBDS'])
    checks['live_inference_delegates_to_same_core']=P+'commBCoreEligible' in calls((OUT/'binary-commBEligible.txt').read_text())
    checks['frozen_adapters_remain_live']='Impl.decodeBDS' in (retained/'Tests/CommBDifferential.lean').read_text() and (retained/'Bench/WholeDecoder.lean').read_text().count('Impl.decode input.bytes')==3
    checks['score_paths_and_lazy_full_model_fallback_preserved']=all(calls((OUT/f).read_text()).count(P+'cbPenalty')==1 for f in ['binary-cbScorePasses.txt','binary-cbScorePasses___lam__0___boxed.txt']) and calls((OUT/'binary-ScoreGate_choose.txt').read_text()).count('lean_apply_1')==1
    checks['decode_keeps_single_syndrome_and_report']=all(calls((OUT/'binary-decode.txt').read_text()).count(P+n)==1 for n in ['decodeFrame','frameSyndrome','reportWithSyndrome'])
    prior={r['source']:r for r in json.loads((retained/'bench/runs/gen14/fresh-native-inputs.json').read_text())};unchanged=[]
    for row in inspection['linked_project_objects']:
        if row['source'] in ('CLI/Main.lean','Impl/CommB.lean'):continue
        previous=prior[row['source']]
        assert sha(row['source'])==previous['source_sha256']
        assert all(sha(row[k])==previous['artifacts'][row[k]]['sha256'] for k in ('c','object','trace'))
        unchanged.append(row['source'])
    checks['other_native_sets_unchanged_and_count_derived']=len(unchanged)==len(inspection['linked_project_objects'])-2
    baseline=json.loads((OUT/'before-native-inventory.json').read_text())
    checks['prebuild_native_inventory_matched_prior_timed_generation']=not baseline['observed_source_changes'] and not baseline['actual_native_mismatches'] and all(r.get('equals_prior_timed',True) for r in baseline['inputs'].values())
    for path in ['spec.lock','lakefile.toml','TRUSTED.md']:
        checks[path+'_unchanged_from_HEAD']=subprocess.check_output(['git','show',inspection['commit']+':'+path])==(retained/path).read_bytes()
    locked=[line.split(None,1) for line in (retained/'spec.lock').read_text().splitlines()]
    checks['all_104_frozen_hashes_match']=len(locked)==104 and all(sha(p)==h for h,p in locked)
    checks['no_new_trust_state_or_forbidden_proofs']=not re.search(r'IO\.Ref|ST\.Ref|@\[(?:extern|implemented_by)|\b(?:unsafe|partial|axiom|sorry|admit|native_decide|bv_decide)\b|panic!|get!|unreachable!',source+'\n'+proof)
    trace=json.loads((retained/'.lake/build/ir/Impl/CommB.c.o.export.trace').read_text());compiler=next(r['message'] for r in trace['log'] if r['message'].startswith('.> '))
    checks['native_flags_remain_O3_ffp_contract_off']='-O3' in compiler and '-ffp-contract=off' in compiler
    fs=facts(log);checks['all_149_printed_facts_allowed']=len(fs)==149 and all(set(f['axioms'])<=ALLOWED for f in fs)
    checks['Decoder_imports_helper_and_preserves_refinement']='import Proofs.CommBConstant' in decoder and 'Impl.commBPayloadLimit' in decoder and any(f['name']=='Lean1090.Proofs.Refinement' for f in fs)
    assert all(checks.values()),{k:v for k,v in checks.items() if not v}
    integration={'status':'passed','findings':[],'reviewer':'/root/cost_analysis; independent of helper and integration authors','sources':build['inputs_after'],'source_proof_review_sha256':sha(OUT/'source-proof-review.json'),'integrated_build_path':inspection['successful_integrated_build_path'],'integrated_build_sha256':sha(inspection['successful_integrated_build_path']),'integrated_log_sha256':sha(logpath),'integrated_allowed_axiom_facts':len(fs),'integrated_facts':fs,'assessment':'The imported helper exposes exact constant and all-input old-body equality; Decoder unfolds the same transparent constant to retain its existing bdsWireValid/whole-decoder refinement. No new hypothesis or statement change.','limits':'Retained integrated proof-build evidence and source assessment, not an independent build.'}
    (OUT/'integration-proof-review.json').write_text(json.dumps(integration,indent=2)+'\n')
    assert all(sha(p)==r['sha256'] for p,r in inspection['inputs'].items())
    out={'status':'passed','findings':[],'checks':checks,'commb_payload_limit_live_path_verified':True,'source_proof_review_sha256':sha(OUT/'source-proof-review.json'),'integration_proof_review_sha256':sha(OUT/'integration-proof-review.json'),'constant_path_capture_sha256':sha(OUT/'constant-path-capture.json'),'all_captured_inputs_unchanged':True,'unchanged_native_sources':unchanged,'scope':'Static source/C/object/linked integrated CLI inspection and retained kernel-build evidence; no build, decoder, profile, test suite or benchmark execution.','limits':['This is the integrated CLI, not the future freshly built timed worker. No throughput or measured saving is claimed.','The exact format constant initializes once before main and is marked persistent. Its parser work moves out of the guard; global loads, comparisons and normal dispatch remain. This contains no message-keyed cache or mutable cross-message state.','The public live guard is still called by both inference and direct register decoding, including frozen adapters. All old arithmetic, field extraction, tables and score fallback semantics remain.'],'future_diagnostic':'Retain the live bdsWireValid boundary and its direct lean_cstr_to_nat calls. The initializer may be inlined into module initialization; absence of a standalone initializer symbol is not zero startup work.','files':{str(p.relative_to(OUT)):{'sha256':sha(p),'bytes':p.stat().st_size} for p in sorted(OUT.rglob('*')) if p.is_file() and p.name not in ('review.json','validate.stdout','validate.stderr')}}
    (OUT/'review.json').write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps({'status':'passed','checks':len(checks),'inputs':len(inspection['inputs']),'files':len(out['files']),'review_sha256':sha(OUT/'review.json'),'source_proof_review_sha256':out['source_proof_review_sha256'],'integration_proof_review_sha256':out['integration_proof_review_sha256']}))
if __name__=='__main__':main()

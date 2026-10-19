#!/usr/bin/env python3
"""Independent bounded source/C/object/linked-path review; never executes a decoder."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
R=Path('tests/evidence/optimization/gen22/native-review');P='lp_lean1090_Lean1090_Impl_'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
c=load(R/'native-inputs.json');b=load(R.parent/'integration/targeted-build.json');checks=[];bindings={}
def check(ok,n):
 assert ok,n
 checks.append(n)
def bind(p,h=None):
 d=sha(p);check(h is None or h==d,'binding '+str(p));bindings[str(p)]=d;return d
def body(s):
 row=c['generated_c_excerpts'][s];bind(row['path'],row['sha256']);bind(row['source'],row['source_sha256'])
 return '\n'.join(re.sub(r'^\d+: ','',l) for l in Path(row['path']).read_text().splitlines())
def assembly(p):
 rows=[]
 for l in Path(p).read_text().splitlines():
  m=re.match(r'\s*([0-9a-f]+):\s+(\S+)\s*(.*)',l)
  if m:rows.append(dict(address=int(m[1],16),op=m[2],arg=m[3]))
 check(bool(rows),'nonempty actual assembly '+str(p));return rows
def asm(s):return assembly(R/'native-inspection'/(s+'.txt'))
def targets(rows):return [m[1] for r in rows if r['op'] in ('call','jmp') and (m:=re.search(r'<([^>]+)>',r['arg']))]
def cfg_counts(rows,symbols):
 by={r['address']:i for i,r in enumerate(rows)};todo=[(0,(0,)*len(symbols))];seen=set();term=set()
 while todo:
  i,counts=todo.pop()
  if (i,counts) in seen:continue
  seen.add((i,counts));r=rows[i];counts=tuple(n+int(r['op']=='call' and '<'+s+'>' in r['arg']) for n,s in zip(counts,symbols))
  assert max(counts,default=0)<=1,('repeated call on possible path',symbols,r)
  m=re.match(r'([0-9a-f]+) ',r['arg']) if r['op'].startswith('j') else None;target=int(m[1],16) if m else None
  if r['op'].startswith('ret') or (r['op']=='jmp' and target not in by):term.add(counts);continue
  if r['op'].startswith('j'):
   assert target in by,('unresolved branch',r)
   todo.append((by[target],counts))
   if r['op']=='jmp':continue
  if i+1<len(rows):todo.append((i+1,counts))
 return sorted(term),len(seen)
bind(R/'native-inputs.json','738394fd946d5a8dc405d1fc79430f0146a48094084e4b3bd9fa2df502785e09')
bind(R.parent/'integration/targeted-build.json',c['integration_record_sha256']);bind(R.parent/'integration/targeted-build.log',b['log_sha256'])
check(b['status']=='passed' and b['exit_code']==0,'combined build passed')
check(len(b['all_inputs_after'])==197 and b['all_inputs_before']==b['all_inputs_after'],'all 197 correctness inputs stable')
for p,h in c['held_inputs'].items():check(sha(p)==h,'held '+p)
check(c['worker_sha256']==b['binary_hashes']['lean1090-bench'],'actual linked worker equals passed combined worker')
for command in c['commands']:
 check(command['exit_code']==0 and not command['stderr'],'successful static command '+command['output']);bind(command['output'],command['sha256'])
oldpath=Path('tests/evidence/optimization/gen21/native-review/native-inputs.json');bind(oldpath);old={r['source']:r for r in load(oldpath)['linked_inventory']};differences={}
for row in c['linked_inventory']:
 differences[row['source']]=[k for k in ['source_sha256','c_sha256','object_sha256','trace_sha256'] if row[k]!=old[row['source']][k]]
 check(' -O3 ' in row['compile_command'] and '-ffp-contract=off' in row['compile_command'] and not re.search(r'-(?:march|mcpu|mtune)=',row['compile_command']),'native compilation flags '+row['source'])
check(len(differences)==22 and {p for p,d in differences.items() if d}=={'Impl/Frame.lean','Impl/Message.lean'},'exact two changed native sets; twenty sibling source/C/object/trace sets unchanged')
parser=body(P+'decodeFrameWithWord');decode=body(P+'decode');projection=body(P+'decodeFrame');info=body(P+'informationBits');syndrome=body(P+'Parity_syndrome');accept=body(P+'frameAcceptedWithSyndrome');report=body(P+'reportWithSyndrome')
check(parser.count(P+'bytesValue(')==1 and decode.count(P+'decodeFrameWithWord(')==1,'one source byte fold and one paired parser call site')
check(decode.count(P+'Parity_syndrome(')==1,'one main raw syndrome call site')
check(parser.index('l_List_head_x3f___redArg')<parser.index('l_List_lengthTR___redArg')<parser.index(P+'bytesValue('),'head/length checks precede full word computation')
check('return v___x_45_;' in parser and 'return v___x_57_;' in parser and parser.index('return v___x_57_;')<parser.index(P+'bytesValue('),'empty and wrong-length exits occur before byte fold')
check('v___x_60_ = '+P+'bytesValue(v_bytes_43_);' in parser and 'lean_ctor_set(v___x_67_, 1, v___x_60_);' in parser,'exact complete byte-fold value stored as pair second field')
check('v_snd_271_ = lean_ctor_get(v_val_266_, 1);' in decode and P+'Parity_syndrome(v___x_278_, v_snd_271_)' in decode,'main syndrome consumes the returned pair word directly')
check(P+'informationBits(v_body_275_)' in decode and 'lean_unsigned_to_nat(24u)' in decode and 'lean_nat_add(v___x_276_, v___x_277_)' in decode,'width is frame information width plus exactly 24 bits')
check(info.count('lean_unsigned_to_nat(32u)')==3 and info.count('lean_unsigned_to_nat(88u)')==1,'every current frame constructor selects the unchanged 32/88 information width')
for name,txt in [('decode',decode),('paired parser',parser),('shared report',report)]:
 for absent in ['frameSyndrome','Parity_checksum','frameParts','packFields']:
  check(P+absent+'(' not in txt,name+' does not reconstruct CRC via '+absent)
check(P+'bytesValue(' not in decode,'main decoder does not reread bytes after parser')
check(decode.index(P+'Parity_syndrome(')<decode.index(P+'frameAcceptedWithSyndrome(')<decode.index(P+'reportWithSyndrome('),'raw syndrome is shared by original acceptance and report order')
check('v_syndrome_13_' in accept and P+'adsbHardValid(v_me_16_)' in accept and 'if (v_supplementary_15_ == 0)' in accept,'original DF17/DF18 policy and supplied syndrome remain live')
check(P+'frameAddressWithSyndrome(v_f_231_, v_syndrome_232_)' in report and P+'Parity_interrogator(v_syndrome_232_)' in report,'report/address/DF11 consume the same syndrome')
check(projection.count(P+'decodeFrameWithWord(')==1 and 'lean_ctor_get(v_val_145_, 0)' in projection,'public frame parser is a live paired-parser projection')
check(P+'decodeFrame' in c['missing_requested_symbols'],'public parser projection is not a standalone timed-worker symbol')
for name in ['frameSyndrome','Parity_checksum','frameParts','packFields']:
 check(P+name in c['missing_requested_symbols'],'old reconstruction symbol absent in timed worker: '+name)
rows=asm(P+'decode');calls=targets(rows);prows=asm(P+'decodeFrameWithWord');pcalls=targets(prows)
check(calls.count(P+'decodeFrameWithWord')==calls.count(P+'Parity_syndrome')==calls.count(P+'reportWithSyndrome')==1,'actual linked main has one site for parser/syndrome/report')
check(pcalls.count(P+'bytesValue')==1,'actual paired parser has one byte-fold site')
for absent in ['frameSyndrome','Parity_checksum','frameParts','packFields','bytesValue','decodeFrame']:
 check(P+absent not in calls,'actual main has no direct '+absent)
check(P+'adsbHardValid' in calls and P+'frameAcceptedWithSyndrome' not in calls,'acceptance is inlined in linked main, preserving hard-validity call')
at='\n'.join(r['op']+' '+r['arg'] for r in rows);pt='\n'.join(r['op']+' '+r['arg'] for r in prows)
check('mov 0x10(%r13),%r12' in at and 'mov %r12,%rsi' in at,'linked main loads pair second field and passes it as raw CRC argument')
check('mov %rax,%r14' in pt and 'mov %r14,0x10(%rax)' in pt,'linked paired parser carries full returned Nat into pair storage')
main_counts,main_states=cfg_counts(rows,[P+'decodeFrameWithWord',P+'Parity_syndrome',P+'reportWithSyndrome'])
parser_counts,parser_states=cfg_counts(prows,[P+'bytesValue'])
check(main_counts==[(1,0,0),(1,1,0),(1,1,1)],'conservative main CFG preserves failure/rejection/success call boundaries')
check(parser_counts==[(0,),(1,)],'conservative parser CFG performs zero or one byte fold')
check('lean_alloc_small_object_core' in pcalls and 'lean_alloc_small_object_core' in calls,'pair/frame/message allocation and reuse remain; no allocation-free claim')
check('lean_ctor_set(v___x_273_, 1, v___x_282_)' in decode and 'lean_alloc_ctor(0, 2, 0)' in decode,'exclusive pair can be reused as message; shared path still allocates')
check(P+'Parity_syndromeBytes(' in syndrome and P+'Parity_syndromeBits(' in syndrome,'unrestricted CRC retains both byte loop and generic bit fallback')
for name in ['Parity_syndrome','Parity_syndromeBytes','Parity_syndromeBits','bytesValue','informationBits','reportWithSyndrome']:
 check(P+name in c['present_symbols'],'actual callable '+name)
for module in ['Frame','Message']:
 init=body('initialize_lean1090_Impl_'+module)
 check('lean_alloc_ctor' not in init and 'lean_obj_once' not in init and '_init_lp_' not in init,'no new table/cache initializer in '+module)
callers=load(R/'caller-bindings.json');bind(R/'caller-bindings.json')
check(callers['parent_capture_sha256']==sha(R/'native-inputs.json') and callers['worker_sha256']==c['worker_sha256'] and callers['all_inputs_unchanged'],'supplement binds same worker and held inputs')
for row in callers['benchmark_callers']:
 for key,hkey in [('c_source','c_sha256'),('c_excerpt','c_excerpt_sha256'),('assembly','assembly_sha256')]:bind(row[key],row[hkey])
 check(Path(row['c_excerpt']).read_text().count(P+'decode(')==1 and targets(assembly(row['assembly'])).count(P+'decode')==1,'actual frozen '+row['mode']+' loop calls current complete decoder')
obj=callers['public_parser_object'];bind(obj['path'],obj['sha256']);bind(obj['assembly'],obj['assembly_sha256'])
check('R_X86_64_PLT32\t'+P+'decodeFrameWithWord-0x4' in Path(obj['assembly']).read_text(),'public API object has real relocation to shared live parser')
source=R.parent/'independent-review/source-proof-review.json';bind(source,'2e83efcff5f650874590e1dbe3ccb99a901b3099b3d46421a1c65a04a8b20a26');check(load(source)['status']=='passed' and not load(source)['findings'],'all-input proof and live-adapter review passed')
for p,h in c['held_inputs'].items():check(sha(p)==h,'final held '+p)
context=dict(decode_frame_with_word_anchor=P+'decodeFrameWithWord',decode_anchor=P+'decode',raw_syndrome_anchor=P+'Parity_syndrome',bytes_value_anchor=P+'bytesValue',public_parser_object_symbol=P+'decodeFrame',public_parser_timed_symbol_absent=True,old_reconstruction_timed_symbols_absent=[P+n for n in ['frameSyndrome','Parity_checksum','frameParts','packFields']],main_call_count_symbols=[P+'decodeFrameWithWord',P+'Parity_syndrome',P+'reportWithSyndrome'],possible_main_call_counts=main_counts,possible_parser_byte_fold_counts=parser_counts,main_cfg_states=main_states,parser_cfg_states=parser_states,source_native_differences=differences)
p=R/'parsed-word-native-context.json';assert not p.exists();p.write_text(json.dumps(context,indent=2)+'\n');bind(p)
files={str(p):dict(sha256=sha(p),bytes=p.stat().st_size) for p in sorted(R.rglob('*')) if p.is_file() and p.name not in ['review.json','review-01.log']}
record=dict(status='passed',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks_passed=len(checks),checks=checks,bindings=bindings,files=files,held_inputs=c['held_inputs'],held_input_count=len(c['held_inputs']),linked_native_sets=len(c['linked_inventory']),all_inputs_unchanged=True,raw_word_syndrome_live_path_verified=True,worker=c['worker'],worker_sha256=c['worker_sha256'],integration_record_sha256=c['integration_record_sha256'],unchanged_sibling_native_sets=20,source_delta=['Impl/Frame.lean','Impl/Message.lean'],native_context_sha256=sha(p),limitations=['Static linked-path review establishes call sites/data flow, not measured frequency or throughput.','The public parser is present in its production object and delegates to the paired parser, but is not a standalone symbol in the timed worker.','Original standalone frameSyndrome/checksum/parts APIs remain available in source/C; their absence in the timed binary does not change their semantics.','Pair/frame/message allocations and ownership-dependent reuse remain. No allocation-free claim.','Only the raw word supplying main CRC changes; byte/bit syndrome algorithms, acceptance, report fields and CPR/Float callbacks are unchanged.','Future instruction diagnostics must classify decodeFrameWithWord in frame/CRC and use actual syndrome entry counts; old main frameSyndrome/checksum assumptions no longer apply.'])
p=R/'review.json';assert not p.exists();p.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),held=len(c['held_inputs']),linked_sets=len(c['linked_inventory']),review_sha256=sha(p))))

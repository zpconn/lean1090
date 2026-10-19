"""Independent static review of live Comm-B scalar and expression sharing."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
R=Path('tests/evidence/optimization/gen24/native-review');P='lp_lean1090_Lean1090_Impl_';M='lp_lean1090_List_mapTR_loop___at___00Lean1090_Impl_'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest();load=lambda p:json.loads(Path(p).read_text())
c=load(R/'native-inputs.json');b=load(R.parent/'integration/targeted-build.json');checks=[];bindings={}
def check(ok,label):
 assert ok,label
 checks.append(label)
def bind(p,h=None):
 actual=sha(p);assert h is None or h==actual,str(p);bindings[str(p)]=actual;return actual
def body(symbol):
 row=c['generated_c_excerpts'][symbol];bind(row['path'],row['sha256']);bind(row['source'],row['source_sha256'])
 return '\n'.join(re.sub(r'^\d+: ','',l) for l in Path(row['path']).read_text().splitlines())
def asm(symbol):
 p=R/'native-inspection'/(symbol+'.txt');bind(p);t=p.read_text();check('<'+symbol+'>:' in t,'Actual linked assembly '+symbol);return t
def targets(t):return re.findall(r'(?:call|jmp)\s+[^<]*<([^>+]+)>',t)
bind(R/'native-inputs.json','d8b03b07ac0075fe241880658e7075b1c3272784de5a884389626aa08104c70b');bind(R.parent/'integration/targeted-build.json',c['integration_record_sha256']);bind(R.parent/'integration/targeted-build.log',b['log_sha256'])
check(b['status']=='passed' and b['exit_code']==0 and b['all_inputs_before']==b['all_inputs_after'] and len(b['all_inputs_after'])==202,'Combined build binds 202 unchanged correctness inputs')
for p,h in c['held_inputs'].items():bind(p,h)
check(c['all_inputs_unchanged'] and c['worker_sha256']==b['binary_hashes']['lean1090-bench'],'Actual worker matches completed combined build')
for command in c['commands']:
 check(command['exit_code']==0 and not command['stderr'],'Static capture passed '+command['output']);bind(command['output'],command['sha256'])
oldpath=Path('tests/evidence/optimization/gen23/native-review/native-inputs.json');bind(oldpath);old={r['source']:r for r in load(oldpath)['linked_inventory']};differences={}
for row in c['linked_inventory']:
 differences[row['source']]=[k for k in ['source_sha256','c_sha256','object_sha256','trace_sha256'] if row[k]!=old[row['source']][k]]
 check(' -O3 ' in row['compile_command'] and '-ffp-contract=off' in row['compile_command'] and not re.search(r'-(?:march|mcpu|mtune)=',row['compile_command']),'Unchanged native flags '+row['source'])
check(len(differences)==22 and {p for p,d in differences.items() if d}=={'Impl/CommB.lean','Impl/Semantics.lean'},'Only CommB and Semantics native sets changed; all 20 siblings byte-identical')
# Complete frozen-worker -> decoder -> report -> semantic constructor linkage.
callers=load(R/'caller-bindings.json');bind(R/'caller-bindings.json')
check(callers['parent_capture_sha256']==sha(R/'native-inputs.json') and callers['worker_sha256']==c['worker_sha256'] and callers['all_inputs_unchanged'],'Frozen caller supplement binds identical worker and held inputs')
for row in callers['benchmark_callers']:
 for key,hkey in [('c_source','c_sha256'),('c_excerpt','c_excerpt_sha256'),('assembly','assembly_sha256')]:bind(row[key],row[hkey])
 check(Path(row['c_excerpt']).read_text().count(P+'decode(')==1 and targets(Path(row['assembly']).read_text()).count(P+'decode')==1,'Frozen '+row['mode']+' executes actual decoder')
for caller,callee in [('decode',P+'reportWithSyndrome'),('reportWithSyndrome',M+'reportWithSyndrome_spec__0')]:
 check(callee in targets(asm(P+caller)) and callee+'(' in body(P+caller),'Actual live '+caller+' reaches '+callee)
report=load(R/'report-map-bindings.json');bind(R/'report-map-bindings.json')
for key in ['source','c_excerpt','assembly']:bind(report[key],report[key+'_sha256'])
check(report['parent_capture_sha256']==sha(R/'native-inputs.json') and report['worker_sha256']==c['worker_sha256'] and report['all_inputs_unchanged'],'Report map capture binds actual worker')
check(targets(Path(report['assembly']).read_text()).count(P+'Semantics_commB')==2 and Path(report['c_excerpt']).read_text().count(P+'Semantics_commB(')==1,'Actual report map calls current semantics: one C site, two assembly sites in exclusive reuse/allocation branches')
# Native sharing has positive call and pointer-flow evidence, not symbol absence alone.
s=body(P+'Semantics_commB');a=asm(P+'Semantics_commB');calls=targets(a)
for symbol in [M+'Semantics_tableValues_spec__0',P+'Presentation_oracleCommBFloats',M+'Semantics_commBOracleValues_spec__0',P+'Semantics_commBLabels',M+'Semantics_commBStandardFloatsFromOracle_spec__0']:
 check(calls.count(symbol)==1,'One native call site in common Comm-B path '+symbol)
check(P+'commBValue' not in calls and P+'Semantics_commBStandardFloats' not in calls,'Main semantic body uses sharing maps rather than old standalone scalar/numeric constructor')
for source in ['v_values_1347_ = '+P+'Semantics_tableValues(', 'v_oracleFloats_1348_ = '+P+'Presentation_oracleCommBFloats(',P+'Semantics_commBOracleValues(v_register_1330_, v_word_1331_, v_values_1347_)',P+'Semantics_commBStandardFloatsFromOracle(v_register_1330_, v_word_1331_, v_oracleFloats_1348_)']:
 check(source in s,'Generated C carries shared values: '+source)
for record in ['v___x_1341_','v___x_1344_']:
 for field,var in [(0,'v___y_1333_'),(1,'v___y_1333_'),(3,'v___y_1334_'),(4,'v___y_1334_'),(5,'v___y_1336_'),(6,'v___y_1335_')]:
  check(f'lean_ctor_set({record}, {field}, {var});' in s,'Payload C field identity '+record+'/'+str(field))
for reg,offset in [('r12','0x8'),('r12','0x10'),('r13','0x30'),('r15','0x38')]:
 check(len(re.findall(r'mov\s+%'+reg+','+offset+r'\(%rax\)',a))==2,'Both actual record branches store '+reg+' at '+offset)
check(re.search(r'mov\s+%r12,%rdx',a) and re.search(r'mov\s+%r15,%rsi',a) and re.search(r'mov\s+%r15,%r13',a),'Actual value-map arguments and identity numeric pointer sharing')
check('$0x61,%r14' in a and '$0x89,%r14' in a and re.search(r'mov\s+\$0x1,%r13d',a) and 'lean_nat_big_eq' in calls,'Actual normal and big-Nat BDS30/44 branch guards with BDS30 empty list')
check(P+'Semantics_adsb' in calls and '$0xb,%r14' in a and '$0xcb,%r14' in a,'Existing register 05/65 ADS-B dispatch stays live')
# Ordered correction map: status none bypasses correction entirely.
scalar=M+'Semantics_commBOracleValues_spec__0';sc=body(scalar);sca=asm(scalar);scalls=targets(sca)
check('if (lean_obj_tag(v_snd_1176_) == 0)\n{\nv___y_1171_ = v_head_1165_;\ngoto v___jp_1170_;\n}' in sc,'Absent status returns original pair before adjustment')
check(sc.index('if (lean_obj_tag(v_snd_1176_) == 0)')<sc.index('lean_unsigned_to_nat(16u)'),'None guard dominates all register corrections in generated C')
check(not any(x in scalls for x in [P+'commBLayout',P+'commBValue',P+'payloadValue']) and not any('find_' in x for x in scalls),'Actual oracle map does not repeat layout search or payloadValue')
for n in ['cbSelected','cbTemperature44','cbVertical60','cbWrapAngle','payloadBits']:
 check(P+n in scalls,'Original correction helper remains live '+n)
check('l_Rat_add' in scalls and 'l_Rat_mul' in scalls,'DTE exact original arithmetic remains live')
for n in [16,64,68,80,96,47,36,511,41,49]:check('lean_unsigned_to_nat('+str(n)+'u)' in sc,'Original correction register/field/sentinel constant '+str(n))
check('l_List_reverse___redArg' in scalls and 'v_a_1162_ = v_tail_1166_;' in sc and 'goto _start;' in sc,'Oracle correction map preserves list traversal and final order')
table=M+'Semantics_tableValues_spec__0';check(targets(asm(table)).count(P+'payloadValue')==1,'One payloadValue call site in table decode map');body(table)
public_calls=targets(asm(P+'commBValue'));body(P+'commBValue')
check(P+'commBLayout' in public_calls and P+'payloadValue' in public_calls,'Public standalone commBValue remains a live full decode helper')
# Pure NumericField expression sharing: only BDS44 constructs replacement temperature.
standard=body(P+'Semantics_commBStandardFloatsFromOracle')
check('return v_fields_1129_;' in standard and 'lean_unsigned_to_nat(48u)' in standard and 'lean_unsigned_to_nat(68u)' in standard,'C standard view preserves BDS30 empty/BDS44 map/identity branches')
check(P+'Presentation_oracleCommBFloats' not in standard,'Derived standard view does not reconstruct the oracle list')
num=M+'Semantics_commBStandardFloatsFromOracle_spec__0';ns=body(num);na=asm(num);ncalls=targets(na)
check('lean_string_dec_eq(v_key_1101_' in ns and 'v___y_1096_ = v_head_1090_;' in ns,'Replacement map tests exact key and preserves unmatched original fields')
cfile=Path(c['generated_c_excerpts'][num]['source']);constant=next(l for l in cfile.read_text().splitlines() if num+'___closed__0_value =' in l)
check('.m_data = "temperature"' in constant,'Key comparison is exactly case-sensitive temperature')
check('v_missing_1102_ = lean_ctor_get_uint8' in ns and 'sizeof(void*)*2, v_missing_1102_' in ns,'Replacement preserves missing-policy byte')
check(P+'cbSigned' in ncalls and 'l_Rat_div' in ncalls and 'lean_unsigned_to_nat(24u)' in ns and 'lean_unsigned_to_nat(11u)' in ns,'BDS44 replacement computes exact signed field and original rational division')
check('lean_alloc_ctor(0, 1, 1)' in ns and 'lean_alloc_ctor(1, 1, 0)' in ns and 'v___x_1108_ = 1;' in ns,'BDS44 constructs the pure binary64 literal expression under Some')
for label,t in [('common semantics',calls),('scalar map',scalls),('numeric map',ncalls)]:
 check(not any('toFloat' in x or 'Float_' in x or 'Numeric_eval' in x for x in t),'No moved Float evaluator/direct callback in '+label)
for symbol in [P+'commBAdjustValue',P+'Semantics_commBOracleValues',P+'Semantics_commBStandardFloatsFromOracle']:
 check(symbol in c['missing_requested_symbols'],'Wrapper inlined, positive map/control-flow evidence retained: '+symbol)
for file in ['runtime-design-review.json','source-proof-review.json','build-preparation-review.json']:
 path=R.parent/'independent-review'/file;bind(path);check(load(path)['status'] in ['passed','passed_read_only_runtime_design_review','passed_read_only_preparation_review'] and not load(path)['findings'],'Passed independent '+file)
v=R.parent/'integration/validation.json';bind(v);check(load(v)['printed_fact_count']==346,'Combined validator binds all 346 permitted facts')
for p,h in c['held_inputs'].items():bind(p,h)
context=dict(source_native_differences=differences,common_constructor=P+'Semantics_commB',scalar_map=scalar,table_value_map=table,numeric_replacement_map=num,scalar_direct_calls=sorted(set(scalls)),numeric_direct_calls=sorted(set(ncalls)),constructor_direct_calls=sorted(set(calls)),missing_requested_symbols=c['missing_requested_symbols'],source_and_proof_boundary='All-Nat old-body and exact list/expression equalities; no Float evaluation changed.',native_boundary='One common-path table decode and oracle NumericField construction. Ordered scalar map consumes that existing list. Numeric identity branches alias the oracle list, BDS30 returns empty, BDS44 maps the exact temperature replacement. Standalone public helper remains live.')
p=R/'semantic-sharing-native-context.json';assert not p.exists();p.write_text(json.dumps(context,indent=2)+'\n');bind(p)
files={str(p):dict(sha256=sha(p),bytes=p.stat().st_size) for p in sorted(R.rglob('*')) if p.is_file() and 'review-attempt-' not in str(p) and p.name!='review.json'}
record=dict(status='passed',findings=[],reviewed_utc=datetime.now(timezone.utc).isoformat(),checks_passed=len(checks),checks=checks,bindings=bindings,files=files,held_inputs=c['held_inputs'],held_input_count=len(c['held_inputs']),linked_native_sets=22,all_inputs_unchanged=True,commb_semantic_reuse_live_path_verified=True,worker=c['worker'],worker_sha256=c['worker_sha256'],integration_record_sha256=c['integration_record_sha256'],unchanged_sibling_native_sets=20,source_delta=['Impl/CommB.lean','Impl/Semantics.lean'],native_context_sha256=sha(p),limitations=['Static call sites and pointer flow establish sharing, not invocation frequencies or measured speedups.', 'Inline wrappers are supported by actual map bodies and generated C/assembly control flow, not inferred from missing symbols.', 'Correction arithmetic, list traversal, allocation and reference counting remain; no allocation-free claim.', 'No hardware Float, CPR callback, evaluator, score arithmetic, frozen adapter or benchmark source changed.'])
out=R/'review.json';assert not out.exists();out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',checks=len(checks),held=len(c['held_inputs']),review_sha256=sha(out))))

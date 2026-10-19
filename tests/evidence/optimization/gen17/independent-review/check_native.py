#!/usr/bin/env python3
"""Read-only integrated proof and linked table review; no decoder invocation."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess
R=Path('tests/evidence/optimization/gen17/independent-review');B=R.parent;N=R/'native-inspection'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
load=lambda p:json.loads(Path(p).read_text())
checks=[]
def check(value,label):
 assert value,label
 checks.append(label)
n=load(R/'native-inputs.json');b=load(B/'integration/targeted-build.json');c=load(R/'central-source-proof-review.json');cp=load(R/'cpr-bridge-review.json')
check(b['status']=='passed' and b['exit_code']==0,'combined build passed')
check(b['inputs_before']==b['inputs_after'] and len(b['inputs_after'])==9,'nine source inputs unchanged')
check(b['all_inputs_before']==b['all_inputs_after'] and len(b['all_inputs_after'])==188,'188 combined correctness inputs unchanged')
check(sha(B/'integration/targeted-build.log')==b['log_sha256'],'combined build log binding')
check(sha(B/'integration/targeted-build.json')==n['integration_record_sha256'],'capture integration binding')
check(c['status']=='passed_source_and_helper_proof' and not c['findings'],'central all-input proof review passed')
check(cp['status']=='passed' and not cp['findings'],'independent CPR bridges passed')
for p,h in cp['bindings'].items():check(sha(p)==h,'CPR binding '+p)
for p,h in b['all_inputs_after'].items():assert sha(p)==h,p
for p,h in b['inputs_after'].items():check(sha(p)==h==sha(B/'integration/sources'/p),'source snapshot '+p)
log=(B/'integration/targeted-build.log').read_text();facts={}
for name,ax,empty in re.findall(r"'([^']+)' (?:depends on axioms: \[([^\]]*)\]|(does not depend on any axioms))",log):
 axioms=[] if empty else [x.strip() for x in ax.split(',') if x.strip()];assert set(axioms)<={'propext','Classical.choice','Quot.sound'},name;facts[name]=axioms
check(len(facts)==200,'200 integrated printed facts use permitted axioms')
bridge=load(B/'proof-bridges/summary.json');check(bridge['status']=='passed' and bridge['all_printed_axioms_allowed'],'six dependent bridges pass')
check(sha(B/'proof-bridges/attempt-01/build.log')==bridge['log_sha256'],'dependent proof log binding')
statements={}
for p,h in bridge['sources'].items():
 check(sha(p)==h,'dependent proof source '+p)
 old=(B/'proof-bridges/before'/p).read_text();new=Path(p).read_text()
 def decl(s):return {name:re.sub(r'\s+',' ',ty).strip() for name,ty in re.findall(r'^(?:private )?theorem (\w+)([\s\S]*?):=',s,re.M)}
 a,z=decl(old),decl(new);check(all(name in z and z[name]==ty for name,ty in a.items()),'unchanged theorem signatures '+p);statements[p]=len(a)
check(n['all_inputs_unchanged'] and len(n['linked_inventory'])==22,'22 linked source/C/object/trace sets captured')
for p,h in n['held_inputs'].items():assert sha(p)==h,p
for item in n['commands']:check(item['exit_code']==0 and not item['stderr'] and sha(item['output'])==item['sha256'],'captured command '+item['output'])
for item in n['generated_c_excerpts'].values():check(sha(item['path'])==item['sha256'] and sha(item['source'])==item['source_sha256'],'C excerpt '+item['function'])
old={x['source']:x for x in load('bench/runs/gen16/fresh-native-inputs.json')};changes={}
for row in n['linked_inventory']:
 prior=old[row['source']];changed=[k for k in ['c','object','trace'] if row[k+'_sha256']!=prior['artifacts'][row[k]]['sha256']]
 if changed:changes[row['source']]=changed
 else:assert row['source_sha256']==prior['source_sha256']
check(changes=={'Impl/Binary64.lean':['c','object','trace']},'only Binary64 native set changed; 21 others byte-identical')
P='lp_lean1090_Lean1090_Impl_';S=P+'Binary64_'
asm=lambda x:(N/(x+'.txt')).read_text()
ctext=lambda x:(N/(x+'.c.txt')).read_text()
# Compiler-independent C guard/index inspection backed by exact linked call/load paths.
powc=ctext(S+'powerTwo');powa=asm(S+'powerTwo');lamc=ctext(S+'powerTwoTable___lam__0');lama=asm(S+'powerTwoTable___lam__0')
check(powc.count('lean_int_dec_le(')==2 and powc.count(S+'powerTwoFormula(')==2,'inclusive lower/upper guards preserve both fallback branches')
check('lean_array_fget_borrowed' in powc and 'lean_int_add' in powc and 'l_Int_toNat' in powc,'proved checked index compiles to table lookup')
check('<'+S+'powerTwoFormula>' in powa and '<'+S+'powerTwoTable>' in powa and re.search(r'mov\s+0x18\(%r14,%rcx,4\)',powa),'linked fallback and actual indexed table load')
check(S+'powerTwoFormula(' in lamc and '<'+S+'powerTwoFormula>' in lama and not re.search(r'\b'+S+r'powerTwo\(',lamc),'entry constructor calls raw formula without lookup recursion')
ctor='_init_'+S+'powerTwoTable___closed__1';check('2098u' in ctext(ctor) and '$0x1065' in asm(ctor) and '<l_Array_ofFn___redArg>' in asm(ctor),'linked complete2098-entry constructor (tagged2098=0x1065)')
init='initialize_lean1090_Impl_Binary64';ic=ctext(init);ia=asm(init)
check(ic.index(S+'powerTwoTable =')<ic.index(S+'maxFinite ='),'generated module initializer orders table before maxFinite')
check(ia.index('<'+S+'powerTwoTable>')<ia.index('<lean_mark_persistent>')<ia.index('<'+S+'maxFinite___closed__3_once>'),'linked table store/persistence precede maxFinite initialization')
check('<'+ctor+'>' in ia and '<lean_obj_once_cold>' in ia,'module initializer forces once-cell constructor, not lazy decode-only initialization')
main=asm('main');check(main.index('<initialize_lean1090_Bench_WholeDecoder>')<main.index('<lean_io_mark_end_initialization>')<main.index('<lean_run_main>'),'actual main initializes table dependency before worker loop')
chain=['initialize_lean1090_Bench_WholeDecoder','initialize_lean1090_Impl','initialize_lean1090_Impl_Message','initialize_lean1090_Impl_CommB',init]
for a,z in zip(chain,chain[1:]):check(z in n['initialization_graph'][a] and '<'+z+'>' in asm(a),'linked initializer edge '+a+' -> '+z)
for caller in ['exponent','round','fromBits']:
 check(S+'powerTwo(' in ctext(S+caller) and '<'+S+'powerTwo>' in asm(S+caller),'live binary64 consumer '+caller)
for caller in ['cbGaussian','cbLaplace']:
 check('<'+S+'round>' in asm(P+caller),'live Comm-B software consumer '+caller)
check('<'+S+'powerTwo>' in asm(P+'CPR_Policy_toFloat') and '<'+S+'round>' in asm(P+'CPR_Policy_toFloat'),'live CPR conversion reaches table and original rounding')
check(S+'powerTwo(' in ctext(P+'Numeric_toFloat32'),'numeric Float32 generated body retains live table calls')
check(n['missing_requested_symbols']==[P+'Numeric_toFloat32'],'numeric Float32 standalone symbol absent from headline worker; no zero-work claim')
# Frozen adapter source identity and live routing; no obsolete copies introduced.
for p,h in c['unchanged_live_adapter_source_hashes'].items():check(sha(p)==h,'unchanged adapter path '+p)
tracking=Path('Tests/Tracking.lean').read_text();check(all(s in tracking for s in ['Impl.Binary64.fromBits','Impl.CPR.Policy.toFloat','Impl.decodePositions']),'tracking frozen adapter routes live full programs')
check('import Impl.Numeric' in Path('Tests/Numeric.lean').read_text(),'numeric frozen adapter routes live module')
lock=[line.split('  ',1) for line in Path('spec.lock').read_text().splitlines()];check(len(lock)==104 and all(sha(p)==h for h,p in lock),'all104lockedfilesunchanged')
for p,h in n['held_inputs'].items():assert sha(p)==h,p
bindings={str(p):sha(p) for p in [R/'native-inputs.json',R/'central-source-proof-review.json',R/'cpr-bridge-review.json',B/'integration/targeted-build.json',B/'integration/targeted-build.log',B/'proof-bridges/summary.json',B/'implementation/summary.json',Path('bench/runs/gen16/fresh-native-inputs.json'),R/'capture_native-attempt-01.py',R/'native-capture-01.log',R/'capture_native.py',R/'native-capture-02.log',R/'check_native-attempt-01.py',R/'native-review-01.log',Path(__file__)]}
files={str(p):{'sha256':sha(p),'bytes':p.stat().st_size} for p in sorted(N.glob('*')) if p.is_file()}
result={'status':'passed','reviewed_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'checks_passed':len(checks),'checks':checks,'bindings':bindings,'files':files,'held_input_count':len(n['held_inputs']),'all_captured_inputs_unchanged':True,'linked_native_sets':22,'unchanged_native_sets_vs_gen16':21,'changed_native_sets':changes,'printed_integrated_axiom_facts':facts,'existing_bridge_statement_counts':statements,'power_two_table_live_path_verified':True,'power_two_initializer_mode':'eager module initialization before main loop; constructor once-cell forced by initializer','initialization_chain':chain,'mathematical_scope':'Every integer exponent, arbitrary rationals and complete decoder/CPR function congruence; no range or acceptance assumptions added.','notes':['PowerTwoFormula remains live for construction and both outside-range branches.','Only Binary64 source/C/object/trace changed among the22 linked sets; proof bridges are erased.','No startup duration, hit frequency or speedup was measured or inferred.','Numeric.toFloat32 is absent as a standalone headline-worker symbol; its generated live body and frozen numeric adapter source are retained.','One reviewer-only capture attempt failed on an external library response-file token before capture; original script/log retained.','Final integrated200printedfacts (including3axiom-free facts) contain only the three permitted axioms; earlier failed helper/CPR logs remain preserved.'],'limits':['Static source/C/linked disassembly and retained successful proof logs only; no decoder, tests or build run by native reviewer.','Full fixed/fresh correctness campaigns and isolated timing are separate evidence.']}
out=R/'native-review.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'status':'passed','sha256':sha(out),'checks':len(checks),'held_inputs':len(n['held_inputs']),'linked_sets':22,'files':len(files),'facts':len(facts)}))

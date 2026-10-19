"""Independent exact runtime delta and boundary review, without builds."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re,subprocess,difflib
R=Path('tests/evidence/optimization/gen24/independent-review')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
read=lambda p:json.loads(Path(p).read_text())
bindings={};checks=[]
def bind(p):bindings[str(p)]=sha(p)
def check(x,label):assert x,label;checks.append(label)
def old(p):return subprocess.check_output(['git','show','HEAD:'+str(p)],text=True)
sources={p:Path(p).read_text() for p in ['Impl/CommB.lean','Impl/Semantics.lean']}
baseline={p:old(p) for p in sources}
for p,s in sources.items():
 bind(p);(R/(Path(p).stem+'.runtime.diff')).write_text(''.join(difflib.unified_diff(baseline[p].splitlines(True),s.splitlines(True),fromfile='HEAD:'+p,tofile=p)))
a=sources['Impl/CommB.lean'];b=baseline['Impl/CommB.lean'];start='-- Initial algorithm: Spec/CommB.lean:62.';stop='-- Initial algorithm: Spec/CommB.lean:83.'
old_section=b[b.index(start):b.index(stop)];new_section=a[a.index(start):a.index(stop)]
check(a.replace(new_section,old_section)==b,'CommB runtime changes only the old correction body factoring and its delegated call')
match='  match register, name with\n'
old_match=old_section[old_section.index(match):].strip();new_match=new_section[new_section.index(match):new_section.index('/-- Sun chs.16')].strip()
check(old_match==new_match,'All nine named correction branches and default are byte-identical to the committed match')
lookup='  let layout ← commBLayout register\n  let c ← layout.find? (fun c => c.name == name)\n  let value ← payloadValue c word\n'
check(lookup in old_section and lookup+'  commBAdjustValue register word name value' in new_section,'Public commBValue retains layout/name/status lookup before correction')
check('@[inline] def commBAdjustValue' in new_section and '(value : Rat) : Option Rat :=' in new_section,'Adjustment takes an already-present exact rational and returns the original option')
s=sources['Impl/Semantics.lean'];o=baseline['Impl/Semantics.lean']
helper=s[s.index('/-- Derive the standard numeric expressions'):s.index('-- Initial algorithm: Spec/Semantics.lean:165.')]
check('if register == 0x30 then [] else if register == 0x44 then' in helper,'Numeric reuse keeps BDS30 empty standard expressions and isolates BDS44 transformation')
transform='''if field.key == "temperature" then
        { field with value := some (.literal .binary64 (cbSigned word 24 11 / 4)) }
      else field'''
check(transform in helper and ('if register == 0x44 && '+transform.removeprefix('if ')) in o,'BDS44 temperature replaces only the expression; key and omission policy remain exact, independent of prior presence')
check(helper.rstrip().endswith('else fields'),'All other registers return the supplied immutable expression list directly')
check('  if register == 0x30 then [] else\n    commBStandardFloatsFromOracle register word (oracleCommBFloats register word)' in s,'Standalone standard-float API still delegates to current expression constructor with BDS30 guard')
check('values.map fun (name, value) =>\n    (name, value.bind (commBAdjustValue register word name))' in s,'Oracle rational reuse preserves order/names and leaves every absent status as none')
old_comm=o[o.index('def commB (register word'):o.index('\nend Lean1090.Impl.Semantics')]
new_comm=s[s.index('def commB (register word'):s.index('\nend Lean1090.Impl.Semantics')]
expected=old_comm.replace('    { tableValues := tableValues layout word\n      standardValues := tableValues layout word\n      oracleValues := layout.map fun c => (c.name, commBValue register word c.name)', '    let values := tableValues layout word\n    let oracleFloats := oracleCommBFloats register word\n    { tableValues := values\n      standardValues := values\n      oracleValues := commBOracleValues register word values').replace('standardFloats := commBStandardFloats register word','standardFloats := commBStandardFloatsFromOracle register word oracleFloats').replace('oracleFloats := oracleCommBFloats register word','oracleFloats := oracleFloats')
check(new_comm==expected,'Complete payload record changes exactly two shared local lists and their consumers; labels, threats and ADS-B delegates unchanged')
# Everything preceding the added helper and following the final payload is unchanged.
check(s[:s.index('/-- Derive the standard numeric expressions')]==o[:o.index('-- Initial algorithm: Spec/Semantics.lean:165.')],'Every earlier semantic definition is byte-identical')
check(s[s.index('\nend Lean1090.Impl.Semantics'):]==o[o.index('\nend Lean1090.Impl.Semantics'):],'Namespace suffix unchanged')
for p in ['Impl/Presentation.lean','Impl/Numeric.lean','Impl/CPRFloat.lean','Impl/JSON.lean','Impl/Message.lean','Impl/CommBLayouts.lean','Impl/PayloadBits.lean']:
 bind(p);check(Path(p).read_text()==old(p),p+' unchanged; pure expression construction and existing Float evaluation boundary preserved')
for p,needle in [('Tests/CommBDifferential.lean','let meaning := Impl.Semantics.commB register word'),('Tests/DTEDifferential.lean','let meaning := Impl.Semantics.commB 0x10 word'),('Tests/Upstream.lean','Impl.Semantics.commB reg w'),('Impl/Message.lean','Semantics.commB')]:
 bind(p);check(needle in Path(p).read_text(),p+' still invokes the live semantic path')
for p,s in sources.items():
 check([x for x in s.splitlines() if x.startswith('import ')]==[x for x in baseline[p].splitlines() if x.startswith('import ')],p+' imports unchanged')
 check(not re.search(r'\b(?:Float|Float32|unsafe|partial|native_decide|sorry|admit)\b', '\n'.join(x[1:] for x in (R/(Path(p).stem+'.runtime.diff')).read_text().splitlines() if x.startswith('+') and not x.startswith('+++') and not x.startswith('+--') and 'pre-Float' not in x)),p+' adds no Float evaluator or prohibited implementation construct')
locked={p:h for h,p in [x.split('  ',1) for x in Path('spec.lock').read_text().splitlines()]}
check(len(locked)==104 and all(sha(p)==h for p,h in locked.items()),'All 104 frozen entries retain exact locked hashes')
bind('spec.lock');rec=read('tests/evidence/optimization/gen24/runtime/attempt-01/result.json')
check(rec['exit_code']==0,'Runtime target build exited successfully')
bind('tests/evidence/optimization/gen24/runtime/attempt-01/result.json');bind('tests/evidence/optimization/gen24/runtime/attempt-01/build.log')
result=dict(status='passed_read_only_runtime_design_review',recorded_utc=datetime.now(timezone.utc).isoformat(),head=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),checks=checks,checks_passed=len(checks),bindings=bindings,findings=[],proof_obligations=['For each selected layout, column names are unique and find? of every listed column returns that column, preserving arbitrary registers/words and field order.','Unconditional list equality between reuse of tableValues and the original per-column commBValue lookup, including missing status and every named correction.','Unconditional NumericField-list equality for BDS30, BDS44 and the identity branch, preserving expression structure, missing policy and exact rational operands.','Complete Semantics.commB and public commBValue refinement retain existing theorem types and frozen adapter liveness.'],native_obligations=['Actual linked Semantics.commB must compute one tableValues list and one oracle expression list per invocation and reuse them through the intended fields.','Oracle-value mapping must consume present values via adjustment without repeating layout search/payloadValue per column; public commBValue remains live for its other callers.','Shared pure expression constructors must not invoke new Float computations; the tested evaluation boundary stays unchanged.'],limits=['Source-level review and existing runtime build evidence only; proofs and generated-C/object/linked paths will be checked after their owners release stable artifacts.','No benchmark or expected speedup is inferred from overlapping diagnostic costs.'],checker_sha256=sha(__file__))
p=R/'runtime-design-review.json';assert not p.exists();p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status=result['status'],checks=len(checks),sha256=sha(p))))

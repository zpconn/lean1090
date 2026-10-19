#!/usr/bin/env python3
"""Prepare, but do not run, the generation22 presentation refresh."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import ast,difflib,hashlib,json,re
O=Path('tests/evidence/optimization/gen21/presentation');E=Path('tests/evidence/optimization/gen22/presentation')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
created=[]
for name in ['run_refresh.py','check_presentation.py','seal_presentation.py']:
 a=(O/name).read_text();b=re.sub(r'(gen|GEN|generation |Generation )(20|21)\b',lambda m:m[1]+str(int(m[2])+1),a)
 if name=='run_refresh.py':
  for old,new in [("review['generation'] == 21","review['generation'] == 22"),("'generation': 21","'generation': 22"),("'generation':21","'generation':22"),('len(held) == 195','len(held) == 197'),('len(rows) == 44','len(rows) == 46'),("row['generation'] == '21'","row['generation'] == '__CURRENT__'"),("row['generation'] == '20'","row['generation'] == '21'"),("row['generation'] == '__CURRENT__'","row['generation'] == '22'"),("'--expected-generations', '22'","'--expected-generations', '23'"),("'--generation', '21'","'--generation', '22'")]:b=b.replace(old,new)
  old="    assert prefix.count('neither target is reached.') == 1\n    prefix = prefix.replace('neither target is reached.', status_text)"
  new="""    previous_statuses = ('both targets are reached.',
                         'decode has reached its target; CPR remains below target.',
                         'CPR has reached its target; decode remains below target.',
                         'neither target is reached.')
    found_statuses = [text for text in previous_statuses if text in prefix]
    assert len(found_statuses) == 1 and prefix.count(found_statuses[0]) == 1
    prefix = prefix.replace(found_statuses[0], status_text)"""
  assert b.count(old)==1;b=b.replace(old,new)
  old="    assert prefix.count(marker) == 1 and 'CPR overhead is **' not in prefix"
  assert b.count(old)==1;b=b.replace(old,"    assert prefix.count(marker) == 1 and prefix.count('CPR overhead is **') == 1")
  old="    prefix = prefix.replace(marker, paragraph + marker)"
  new="    prefix, overhead_replacements = re.subn(r'(?m)^CPR overhead is \\*\\*[^\\n]*\\n\\n', lambda _: paragraph, prefix)\n    assert overhead_replacements == 1"
  assert b.count(old)==1;b=b.replace(old,new)
 elif name=='seal_presentation.py':
  for old,new in [("verification['source_rows'] == 44 and verification['frames'] == 22","verification['source_rows'] == 46 and verification['frames'] == 23"),("verification['plotted_values_checked'] == 1012","verification['plotted_values_checked'] == 1104"),('generations 0, 11 and 21','generations 0, 11 and 22'),("'generation': 21","'generation': 22"),("'correctness_inputs': 195","'correctness_inputs': 197"),("'The 2.00x target is visible above both series and explicitly applies to both modes.'","'The 2.00x target remains visible and explicitly applies to both modes.'"),("'Both current ratios are below 2.00x; no uncertainty intervals or new workload measurements were introduced.'","'Exact median target status: ' + execution['exact_target_status']['README_status_text'] + ' No uncertainty intervals or new workload measurements were introduced.'")]:b=b.replace(old,new)
 ast.parse(b,filename=str(E/name))
 with (E/name).open('x') as f:f.write(b)
 d=E/(name+'.diff');d.write_text(''.join(difflib.unified_diff(a.splitlines(True),b.splitlines(True),fromfile=str(O/name),tofile=str(E/name))))
 created.extend([E/name,d])
paths=[O/name for name in ['run_refresh.py','check_presentation.py','seal_presentation.py']]+[Path(name) for name in ['review/packaging/check_presentation.py','review/presentation/render_throughput.py','review/presentation/verify_throughput.py']]
r={'status':'prepared_not_executed','recorded_utc':datetime.now(timezone.utc).isoformat(),'generation':22,'expected_csv_rows':46,'expected_frames':23,'expected_correctness_inputs':197,'inputs':{str(p):sha(p) for p in paths},'files':{str(p):sha(p) for p in created},'changes':['Generation/path/count changes only in existing source, native, capstone, links, all-frame and artist checks; shared renderer/verifier/packaging checker unchanged.','Refresh target wording from whichever prior exact target state is present; derive each current mode and conjunction from reviewed integer medians, including decode-only success.','Replace the existing signed CPR overhead paragraph exactly once with both new exact median differences and unchanged independent-mode/noise limits.','Visual seal derives target interpretation from executed result instead of claiming both ratios remain below target.','No speculative result hashes, commits, values or target outcomes are embedded; execution requires root release and the actual passed result review hash.'],'release_command_template':'PYTHONDONTWRITEBYTECODE=1 python3 -B tests/evidence/optimization/gen22/presentation/run_refresh.py --execute --expected-review-sha256 <actual-passed-gen22-results-review-SHA256>','syntax_validation':'ast.parse only; no controller imports/execution, rendering or current README/assets edits.','preparer_sha256':sha(__file__)}
with (E/'preparation.json').open('x') as f:f.write(json.dumps(r,indent=2)+'\n')
print(json.dumps({'status':r['status'],'preparation_sha256':sha(E/'preparation.json')}))

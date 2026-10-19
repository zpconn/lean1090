#!/usr/bin/env python3
"""Pure parser fixture: no decoder execution and no production artifacts changed."""
from pathlib import Path
import hashlib, importlib.util, json, sys, tempfile
sys.dont_write_bytecode = True
source=Path('review/diagnostics/analyze_callgrind.py')
spec=importlib.util.spec_from_file_location('reviewed_callgrind',source)
module=importlib.util.module_from_spec(spec)
sys.modules[spec.name]=module
spec.loader.exec_module(module)
assert module.stage_for(module.PREFIX+'frameAddressWithSyndrome','output_model_control')=='frame_crc'
assert module.stage_for(module.PREFIX+'frameAcceptedWithSyndrome','output_model_control')=='frame_crc'
assert module.stage_for(module.PREFIX+'reportWithSyndrome','output_model_control')=='output_model_control'
text=f'''positions: line
events: Ir
summary: 10
fn=(1) {module.DECODE}
1 2
cfn=(2) {module.PREFIX}decodeFrame
calls=1 2
1 8
fn=(2)
2 1
cfn=(3) shared_stage_ancestor
calls=1 3
2 7
fn=(3)
3 3
cfn=(4) {module.PREFIX}Semantics_adsb
calls=1 4
3 4
fn=(4)
4 4
totals: 10
'''
with tempfile.TemporaryDirectory(prefix='lean1090-review-stage-crossing-') as directory:
    p=Path(directory)/'fixture.callgrind';p.write_text(text)
    result=module.analyze(module.parse(p),module.DECODE,'output_model_control')
expected={'frame_crc':4,'semantic_oracle_values':4,'output_model_control':2}
assert {k:v.get('Ir',0) for k,v in result['exclusive_stage_events'].items() if v.get('Ir',0)}==expected
helpers=result['stage_helper_observations_non_additive']
ancestor=next(x for x in helpers['frame_crc'] if x['symbol']=='shared_stage_ancestor')
assert ancestor['self_events']=={'Ir':3}
assert ancestor['incoming_inclusive_events_non_additive']=={'Ir':7}
assert ancestor['native_entries']==1
semantic=next(x for x in helpers['semantic_oracle_values'] if x['symbol']==module.PREFIX+'Semantics_adsb')
assert semantic['self_events']=={'Ir':4}
for stage,n in expected.items():
    assert sum(x['self_events'].get('Ir',0) for x in helpers[stage])==n
assert result['self_event_sum_matches_summary'] and result['stage_attribution_complete']
output={'status':'passed','analyzer_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
        'fixture':text,'exact_total_ir':10,'exclusive_stage_ir':expected,
        'ancestor_self_ir':3,'ancestor_raw_inclusive_ir':7,'later_stage_descendant_ir':4,
        'conclusion':'Raw inclusive observation includes the later semantic stage; self costs remain exactly partitioned.',
        'limits':'Pure synthetic Callgrind parser fixture only; no native execution, build or performance claim.'}
print(json.dumps(output,indent=2))

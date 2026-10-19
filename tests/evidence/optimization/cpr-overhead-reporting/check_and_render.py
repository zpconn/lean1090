#!/usr/bin/env python3
"""Review-only reporting probe; writes drafts beside itself, never bench/."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
from datetime import datetime, timezone
import csv, hashlib, importlib.util, json, statistics
ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / 'review/diagnostics'))
spec = importlib.util.spec_from_file_location('overhead_candidate', OUT / 'archive_generation_benchmark_target.py')
helper = importlib.util.module_from_spec(spec)
spec.loader.exec_module(helper)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
COUNT = 172432
assert helper.COUNT == COUNT

def fixture(a, b, c, d):
    return [{'mode':'decode','medians_nanoseconds':{'lean1090':a,'rs1090':c}},
            {'mode':'cpr','medians_nanoseconds':{'lean1090':b,'rs1090':d}}]

checks = []
for label, values, expected in [
    ('positive_and_negative', (1000, 2000, 2000, 1000), (1000, -1000)),
    ('zero', (1000,1000,1000,1000), (0,0)),
    ('one_nanosecond_above_binary64_precision', (2**60,2**60+1,2**60+1,2**60), (1,-1))]:
    result=helper.cpr_overhead(fixture(*values))['implementations']
    for name, value in zip(('lean1090','rs1090'), expected):
        assert result[name]['difference_nanoseconds']==value
        assert result[name]['microseconds_per_message_divisor']==COUNT*1000
        assert result[name]['microseconds_per_message']==value/(COUNT*1000)
    checks.append(label)
for label, data in [('missing_mode',fixture(1,2,1,2)[:1]),
                    ('duplicate_mode',[fixture(1,2,1,2)[0]]*2),
                    ('zero_median',fixture(0,1,1,1)),
                    ('negative_median',fixture(1,-1,1,1)),
                    ('float_median',fixture(1.0,1,1,1)),
                    ('bool_median',fixture(True,1,1,1))]:
    try: helper.cpr_overhead(data)
    except RuntimeError: checks.append(label)
    else: raise AssertionError(label)
records=[]; sources={}
for generation in range(20):
    base=ROOT/'bench/runs'/('baseline-FC006' if generation==0 else f'gen{generation}')
    summary_path=base/'summary.json'; summary=json.loads(summary_path.read_text())
    sources[str(summary_path.relative_to(ROOT))]=sha(summary_path)
    by_mode={r['mode']:r for r in summary['results']}
    assert len(by_mode)==2 and set(by_mode)=={'decode','cpr'}
    for mode in ('decode','cpr'):
        sample_path=base/mode/'samples.csv'; sources[str(sample_path.relative_to(ROOT))]=sha(sample_path)
        rows=list(csv.DictReader(sample_path.open()))
        assert len(rows)==48 and all(int(r['messages'])==COUNT for r in rows)
        assert sha(sample_path)==by_mode[mode]['samples_sha256']
        for implementation in ('lean1090','rs1090'):
            warmups=[r for r in rows if r['phase']=='warmup' and r['implementation']==implementation]
            measured=[int(r['nanoseconds']) for r in rows if r['phase']=='measured' and r['implementation']==implementation]
            assert len(warmups)==3 and len(measured)==21
            assert statistics.median(measured)==by_mode[mode]['medians_nanoseconds'][implementation]
    overhead=helper.cpr_overhead(summary['results'])
    records.append({'generation':generation,'recorded_commit':summary['commit'],
                    'summary':str(summary_path.relative_to(ROOT)),
                    'summary_sha256':sha(summary_path),'overhead':overhead})
assert records[-1]['overhead']['implementations']['lean1090']['difference_nanoseconds']==115989688
assert records[-1]['overhead']['implementations']['rs1090']['difference_nanoseconds']==2515659
assert any(r['overhead']['implementations']['rs1090']['difference_nanoseconds']<0 for r in records)
for p,digest in sources.items(): assert sha(ROOT/p)==digest
lines=['# CPR overhead by generation','','This supplement adds the requested overhead metric without changing any sealed benchmark report or sample. Future generation reports include it directly.','','For each implementation, overhead is `1e6 / cpr_msg_s - 1e6 / decode_msg_s`, in microseconds per message. The calculation below subtracts exact full-corpus median nanoseconds first, then divides by `172432 * 1000`. It compares independently measured mode medians, includes measurement noise, and is not an isolated timing of CPR work. Signed differences, including negative rs1090 values, are retained.','','| Generation | Lean decode µs/msg | Lean + CPR µs/msg | Lean CPR overhead µs/msg | rs1090 CPR overhead µs/msg |','| --- | ---: | ---: | ---: | ---: |']
for r in records:
    gen=r['generation']; v=r['overhead']['implementations']; lean=v['lean1090']; rust=v['rs1090']
    link='BASELINE.md' if gen==0 else f'GEN{gen}.md'
    lines.append(f"| [{gen}]({link}) | {lean['median_nanoseconds']['decode']/(COUNT*1000):.9f} | {lean['median_nanoseconds']['cpr']/(COUNT*1000):.9f} | {lean['microseconds_per_message']:.9f} | {rust['microseconds_per_message']:.9f} |")
lines.extend(['','All 80 implementation/mode medians were independently recomputed from 21 measured samples apiece, after the three warmups. [Structured values and exact integer differences](cpr-overhead.json) retain source hashes and the original recorded commit IDs. Historical attribution is documented in [the commit mapping](../docs/COMMIT-ATTRIBUTION.md).',''])
for name,data in [('CPR-OVERHEAD.md','\n'.join(lines)),('cpr-overhead.json',json.dumps({'schema':1,'generations':records,'source_sha256':sources},indent=2)+'\n')]:
    target=OUT/name
    with target.open('x') as stream: stream.write(data)
report={'status':'passed_candidate_validation','recorded_utc':datetime.now(timezone.utc).isoformat(),'helper_sha256':sha(OUT/'archive_generation_benchmark_target.py'),'probe_sha256':sha(Path(__file__)),'edge_checks':checks,'generation_count':20,'raw_sample_count':1920,'medians_recomputed':80,'historical_files_unchanged':True,'source_sha256':sources,'drafts':{name:sha(OUT/name) for name in ['CPR-OVERHEAD.md','cpr-overhead.json']},'note':'Drafts only in ignored scratch. Live reporting helper, benchmark harness, interleaver and sealed evidence unchanged.'}
with (OUT/'validation.json').open('x') as stream:json.dump(report,stream,indent=2);stream.write('\n')
print(json.dumps({k:report[k] for k in ['status','edge_checks','generation_count','raw_sample_count','medians_recomputed','historical_files_unchanged','drafts']},indent=2))

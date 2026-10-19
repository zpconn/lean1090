#!/usr/bin/env python3
"""Archive completed timing evidence and append results; never build or benchmark.

Prepare a plan and exact prior-CSV snapshot before timing. After timing, invoke
with --plan and --source. --inspect only validates retained measurement data.
Optional plan.decode_target_ratio is an exact positive numerator/denominator;
omitting it retains the historical 11/10 reporting threshold. This reporting
choice does not change timing, workloads, or recorded measurements.
All validation and report construction precede writes to bench/. Existing
destinations are rejected; partial failures are retained, never auto-retried.
"""
from __future__ import annotations

import argparse
import csv
from datetime import datetime, timezone
import hashlib
import io
import json
from pathlib import Path
import shutil
import subprocess
import sys

sys.dont_write_bytecode = True
from run_generation_benchmark import COUNT, ORACLE_COMMIT, validate_mode_data, verify_gate_evidence

ROOT = Path(__file__).resolve().parents[2]
CSV_HEADER = ['commit', 'generation', 'lean1090_msg_s', 'rs1090_msg_s', 'note', 'mode', 'lean_over_rs1090']
# Exact original inventory produced by the retained benchmark wrapper. New
# wrapper outputs require review here; report/archive files are never inputs.
ORIGINAL_FILES = set('''after-cpr-git.json after-cpr-lock.log after-decode-git.json
after-decode-lock.log after-effective-clang-drivers.json after-environment/environment.json
after-environment.log after-host.json after-host.log after-timing-git.json after-timing-lock.log
before-build-git.json before-build-lock.log before-cpr-git.json before-cpr-lock.log
before-decode-git.json before-decode-lock.log before-effective-clang-drivers.json
before-environment/environment.json before-environment.log before-host.json before-host.log
binary-built.json clock-events.json commands.json correctness-inputs.json cpr/lean1090.stderr.log
cpr/metadata.json cpr/rs1090.stderr.log cpr/samples.csv cpr-interleave.log decode/lean1090.stderr.log
decode/metadata.json decode/rs1090.stderr.log decode/samples.csv decode-interleave.log
fresh-build-removals.json fresh-native-inputs.json gate-evidence.json gate-full.log gate-verification.json
lean-fresh-build.log oracle-prebuild.log provenance-scripts/capture_benchmark_host.py
provenance-scripts/run_generation_benchmark.py scope.json status.json summary.json'''.split())
COMMAND_LOGS = {name for name in ORIGINAL_FILES if name.endswith('.log') and '/' not in name} - {'gate-full.log'}


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load(path):
    return json.loads(Path(path).read_text())


def stamp():
    return datetime.now(timezone.utc).isoformat()


def committed_sha(commit, name):
    return hashlib.sha256(subprocess.check_output(['git', 'show', commit+':'+name], cwd=ROOT)).hexdigest()


def parse_prior_csv(raw, generation):
    reader = csv.DictReader(io.StringIO(raw.decode()))
    require(reader.fieldnames == CSV_HEADER, 'CSV header differs from canonical column order')
    rows = list(reader)
    require(len(rows) == generation*2, 'prior row count differs')
    require([(int(r['generation']), r['mode']) for r in rows] == [(i,m) for i in range(generation) for m in ('decode','cpr')], 'prior generation/mode sequence differs')
    require(raw.endswith(b'\n'), 'prior CSV lacks a final newline')
    return rows


def inventory(path):
    require(path.is_dir() and not path.is_symlink(), 'real source directory required')
    result = {}
    for item in sorted(path.rglob('*')):
        require(not item.is_symlink(), 'symlink in evidence: '+str(item))
        if item.is_file():
            result[str(item.relative_to(path))] = {'sha256': sha(item), 'bytes': item.stat().st_size}
        else:
            require(item.is_dir(), 'nonregular evidence entry: '+str(item))
    require(bool(result), 'empty evidence directory')
    return result


def validate_source(source, generation):
    files = inventory(source)
    require(set(files) == ORIGINAL_FILES, 'original evidence inventory differs; missing='+repr(sorted(ORIGINAL_FILES-set(files)))+'; added='+repr(sorted(set(files)-ORIGINAL_FILES)))
    summary, status = load(source/'summary.json'), load(source/'status.json')
    require(summary['status'] == status['status'] == 'complete', 'timing incomplete')
    require(summary['generation'] == status['generation'] == generation, 'wrong generation')
    build, fresh = load(source/'binary-built.json'), load(source/'fresh-native-inputs.json')
    inputs = load(source/'correctness-inputs.json')
    require(build['commit'] == summary['commit'] and build['sha256'] == summary['binary_sha256'], 'build identity differs')
    require(len(fresh) == build['project_c_objects_regenerated'], 'fresh native cardinality differs')
    require(build['spec_lock_sha256'] == summary['spec_lock_sha256'] == inputs['spec.lock'] == committed_sha(summary['commit'], 'spec.lock'), 'build/summary/committed lock binding differs')
    sources, artifacts = set(), set()
    for item in fresh:
        name = item['source']; path = Path(name)
        require(name not in sources, 'duplicate fresh native source: '+name); sources.add(name)
        require(not path.is_absolute() and '..' not in path.parts and path.suffix == '.lean', 'invalid linked source path')
        require(name in {'Impl.lean', 'Bench/WholeDecoder.lean'} or path.parts[0] in {'Impl', 'Model'}, 'foreign linked project source')
        require(item['source_sha256'] == inputs[name] == committed_sha(summary['commit'], name), 'fresh source does not match committed correctness input: '+name)
        stem = '.lake/build/ir/'+str(path.with_suffix('.c'))
        require(set(item['artifacts']) == {stem, stem+'.o.export', stem+'.o.export.trace'}, 'source/native path binding differs: '+name)
        for name, data in item['artifacts'].items():
            require(name not in artifacts, 'duplicate fresh native artifact: '+name); artifacts.add(name)
            require(data['sha256'] == build['native_hashes'][name], 'native record differs: '+name)
    worker = '.lake/build/bin/lean1090-bench'
    require(build['path'] == worker and build['native_hashes'][worker] == build['sha256'], 'worker/native binding differs')
    require(set(build['native_hashes']) == artifacts | {worker, worker+'.rsp', worker+'.trace'}, 'native inventory has missing or foreign artifacts')
    require('Bench/WholeDecoder.lean' in sources and build['worker_source_sha256'] == inputs['Bench/WholeDecoder.lean'], 'worker source binding differs')
    for name in ('run_generation_benchmark.py', 'capture_benchmark_host.py'):
        require(sha(source/'provenance-scripts'/name) == committed_sha(summary['commit'], 'review/diagnostics/'+name), 'provenance script differs from timed commit')
    git_files = ['before-build', 'before-decode', 'after-decode', 'before-cpr', 'after-cpr', 'after-timing']
    for label in git_files:
        data = load(source/(label+'-git.json'))
        require(data['clean'] and data['stdout'] == '' and data['commit'] == summary['commit'], 'unclean/wrong recorded commit')
        require(data['oracle_commit'] == ORACLE_COMMIT and data['oracle_tracked_status'] == '', 'oracle changed')
        require((source/(label+'-lock.log')).read_text().strip() == 'Lock audit: 104 frozen files match SHA-256.', 'lock check missing')
    gate = verify_gate_evidence(load(source/'gate-evidence.json'), sha(source/'gate-full.log'), inputs)
    require(load(source/'gate-verification.json')['commit_to_measure'] == summary['commit'], 'gate commit differs')
    results, metas, clocks, plans = [], {}, {}, []
    commands = load(source/'commands.json')
    require(len(commands) == len(COMMAND_LOGS) and {c['log'] for c in commands} == COMMAND_LOGS, 'command log inventory differs')
    require(all(c['exit_code'] == 0 and c['log'] in files for c in commands), 'failed command or absent command log')
    for mode in ('decode', 'cpr'):
        meta = load(source/mode/'metadata.json'); metas[mode] = meta
        with (source/mode/'samples.csv').open(newline='') as stream:
            rows = list(csv.DictReader(stream))
        result = validate_mode_data(mode, meta, rows, summary['binary_sha256'], summary['oracle_binary_sha256'], 0)
        result.update(samples_sha256=sha(source/mode/'samples.csv'), metadata_sha256=sha(source/mode/'metadata.json'))
        require(result == summary['results'][len(results)], 'summary differs from raw samples')
        results.append(result)
        plans.extend(meta['windows_power_plan_'+part]['scheme_guid'] for part in ('before', 'after'))
        matches = [c for c in commands if c['log'] == mode+'-interleave.log']
        require(len(matches) == 1 and matches[0]['exit_code'] == 0, 'missing/duplicate/failed interleave command')
        cmd = matches[0]
        delta = datetime.fromisoformat(cmd['finish']['utc']) - datetime.fromisoformat(cmd['start']['utc'])
        utc_ns = (delta.days*86400 + delta.seconds)*10**9 + delta.microseconds*1000
        mono_ns = cmd['finish']['monotonic_ns'] - cmd['start']['monotonic_ns']
        require(mono_ns > 0, 'nonpositive outer monotonic duration')
        clocks[mode] = {'utc_elapsed_ns': utc_ns, 'monotonic_elapsed_ns': mono_ns,
                        'utc_minus_monotonic_ns': utc_ns-mono_ns, 'sample_backsteps': result['utc_sample_backsteps']}
    require(len(set(plans)) == 1, 'power plan changed across four captures')
    events = load(source/'clock-events.json')
    backsteps = []
    for i, event in enumerate(events):
        actual = i > 0 and datetime.fromisoformat(event['utc']) < datetime.fromisoformat(events[i-1]['utc'])
        require((i == 0 or 'utc_backstep' in event) and event.get('utc_backstep', False) == actual, 'incorrect wrapper backstep flag')
        if actual:
            backsteps.append(event)
    require(backsteps == summary['utc_backsteps_retained'], 'wrapper backstep summary differs')
    return {'summary': summary, 'build': build, 'fresh_native_sets': len(fresh), 'gate': gate,
            'results': results, 'metadata': metas, 'clocks': clocks, 'wrapper_backsteps': backsteps,
            'power_plan_guid': plans[0], 'source_files': files}


def target_ratio(plan):
    """Validate the reporting target without floating-point conversion."""
    ratio = plan.get('decode_target_ratio', {'numerator': 11, 'denominator': 10})
    require(type(ratio) is dict and set(ratio) == {'numerator', 'denominator'},
            'decode_target_ratio requires exactly numerator and denominator')
    numerator, denominator = ratio['numerator'], ratio['denominator']
    require(type(numerator) is int and type(denominator) is int and
            numerator > 0 and denominator > 0,
            'decode_target_ratio values must be positive integers (not bools)')
    return numerator, denominator


def target_label(plan):
    numerator, denominator = target_ratio(plan)
    # Use two decimal places only if exact; otherwise display the fraction.
    hundredths, remainder = divmod(numerator * 100, denominator)
    return (f'{hundredths // 100}.{hundredths % 100:02d}' if remainder == 0
            else f'{numerator}/{denominator}')


def decode_threshold_reached(plan, result):
    numerator, denominator = target_ratio(plan)
    medians = result['medians_nanoseconds']
    rust, lean = medians['rs1090'], medians['lean1090']
    require(type(rust) is int and type(lean) is int and rust > 0 and lean > 0,
            'threshold comparison requires positive integer medians')
    return rust * denominator >= lean * numerator


def report_text(plan, data, source, old_rows, fresh):
    g = plan['generation']; s = data['summary']; results = data['results']; meta = data['metadata']['decode']
    reached = decode_threshold_reached(plan, results[0])
    label = target_label(plan)
    action = (f'The {label}× decode threshold is reached. Stop for user review before further optimization or final deliverable work.'
              if reached else f'The {label}× decode threshold remains unmet. A complete diagnostic and independent review precede the next optimization.')
    gains = []
    for result in results:
        prior = next(row for row in old_rows if int(row['generation']) == g-1 and row['mode'] == result['mode'])
        gains.append((result['messages_per_second']['lean1090']/float(prior['lean1090_msg_s'])-1)*100)
    rows = '\n'.join(f"| {r['mode']} | {r['medians_nanoseconds']['lean1090']/1e6:.6f} | {r['medians_nanoseconds']['rs1090']/1e6:.6f} | {r['messages_per_second']['lean1090']:.6f} | {r['messages_per_second']['rs1090']:.6f} | {r['lean_over_rust']:.12f}× |" for r in results)
    clock_lines = '\n'.join(f"- {mode}: outer UTC {c['utc_elapsed_ns']/1e9:.9f} s; monotonic {c['monotonic_elapsed_ns']/1e9:.9f} s; UTC minus monotonic {c['utc_minus_monotonic_ns']/1000:.3f} µs. Adjacent sample-label backsteps: {len(c['sample_backsteps'])}." for mode,c in data['clocks'].items())
    observations = []
    for side in ('before', 'after'):
        host = load(source/(side+'-host.json'))
        core = host['cpu_activity_sample']['cores'].get('cpu0', {})
        aggregate = host['cpu_activity_sample']['cores'].get('cpu', {})
        observations.append(f"{side}: CPU 0 {core.get('busy_percent_idle_includes_iowait', 'unavailable')}%, aggregate {aggregate.get('busy_percent_idle_includes_iowait', 'unavailable')}%")
    env = load(source/'before-environment/environment.json')
    return f"""# Generation {g}: {plan['title']}

Decode throughput is **{results[0]['lean_over_rust']:.12f}× rs1090**; CPR throughput is **{results[1]['lean_over_rust']:.12f}×**. Lean throughput changed by {gains[0]:+.2f}% / {gains[1]:+.2f}% versus gen{g-1}. {action}

{plan['change_description']}

| Mode | Lean median ms | rs1090 median ms | Lean msg/s | rs1090 msg/s | Lean / rs1090 |
| --- | ---: | ---: | ---: | ---: | ---: |
{rows}

Each mode retains all 48 rows: three AB warmup pairs, then 21 measured AB pairs, A=rs1090/B=Lean, CPU 0. Every interval decodes all {COUNT:,} prepared messages. The headline calls exactly Impl.decode including complete model construction; CPR begins with empty state and resolves 11,347 positions on each side. No sample was dropped, adjusted or repeated. [Raw decode samples](runs/gen{g}/decode/samples.csv), [CPR samples](runs/gen{g}/cpr/samples.csv), [summary](runs/gen{g}/summary.json).

Timed commit: `{s['commit']}`. Actual worker SHA-256: `{s['binary_sha256']}`. Oracle SHA-256: `{s['oracle_binary_sha256']}`. The fresh build regenerated {data['fresh_native_sets']} linked project C/object sets. All six recorded tree checks were clean and all lock checks passed; lock SHA-256 `{s['spec_lock_sha256']}`. [Build provenance](runs/gen{g}/binary-built.json), [fresh native inputs](runs/gen{g}/fresh-native-inputs.json), [commands](runs/gen{g}/commands.json).

The full gate passed with {data['gate']['input_count']} unchanged correctness inputs. The separately verified fresh campaign contains {fresh['message_counts']['messages']:,} messages: {fresh['message_counts']['exact_matches']:,} exact plus {fresh['message_counts'].get('D001',0):,} documented D001; all {fresh['direct_counts']['cases']:,} direct Comm-B cases match. Coverage is {fresh['df_attempts']} DF attempts, {fresh['adsb_branches']} ADS-B branches and {fresh['commb_registers']} registers, with no gaps. [Validation evidence](../tests/evidence/optimization/gen{g}/).

Environment: {meta['cpu_model']}; {meta['platform']}. {meta['lean_version']}; {meta['rust_version']}. C compiler: {env['c_compiler'].splitlines()[0]}. Recorded compile/effective-driver evidence remains in the archive. All four Windows power-plan captures have GUID `{data['power_plan_guid']}`; raw plan output: `{meta['windows_power_plan_before']['output']}`.

The operator's recorded isolation note is: “{load(source/'scope.json')['operator_note']}” Guest bracketing observations: {'; '.join(observations)}. These observations do not establish Windows host-wide isolation. WSL may hide physical temperatures, governors, contention and frequency changes; raw availability and limits are retained in [host evidence](runs/gen{g}/before-host.json).

Worker monotonic durations determine every median and ratio. Raw UTC labels are retained without correction. Wrapper UTC backsteps: {len(data['wrapper_backsteps'])}.

{clock_lines}

[Structured reporting checks](runs/gen{g}/report-verification.json) retain every observed clock backstep and exact nanosecond difference. [Archive verification](runs/gen{g}/archive-verification.json) hashes all {len(data['source_files'])} original files copied byte-identically. Exactly two results rows were appended while preserving all {len(old_rows)} previous rows and their original bytes. This automated archival report does not replace the separate independent result review. No benchmark, build, profiler or publication is invoked by the reporting helper.
"""


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, required=True)
    parser.add_argument('--plan', type=Path)
    parser.add_argument('--inspect-generation', type=int, help='Read-only validation of an existing run; no output files written.')
    args = parser.parse_args(); source = args.source.resolve()
    if args.inspect_generation is not None:
        require(args.plan is None, 'inspection must not accept a mutation plan')
        data = validate_source(source, args.inspect_generation)
        print(json.dumps({'status': 'passed', 'source': str(source), 'source_files': len(data['source_files']), 'results': data['results'], 'clocks': data['clocks']}, indent=2))
        return
    require(args.plan is not None, '--plan required for archival')
    plan = load(args.plan); g = plan['generation']; destination = ROOT/'bench/runs'/f'gen{g}'; report = ROOT/'bench'/f'GEN{g}.md'; csv_path = ROOT/'bench/results.csv'
    require(not destination.exists() and not report.exists(), 'refuse to overwrite existing archive/report')
    require(source.parent == (ROOT/'.cache/bench-runs').resolve() and source.name.startswith(f'gen{g}-'), 'unexpected source location')
    old_bytes = (ROOT/plan['prior_csv_snapshot']).read_bytes()
    require(hashlib.sha256(old_bytes).hexdigest() == plan['prior_csv_sha256'] and csv_path.read_bytes() == old_bytes, 'prior CSV prefix changed')
    old_rows = parse_prior_csv(old_bytes, g)
    require(len(old_rows) == plan['prior_csv_rows'], 'plan row count differs')
    data = validate_source(source,g); s = data['summary']
    require(source.name == f'gen{g}-{s["commit"][:7]}', 'source name differs from measured commit')
    require(subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip() == s['commit'], 'HEAD differs from measured commit')
    for name,digest in load(source/'correctness-inputs.json').items():
        require(committed_sha(s['commit'],name) == digest, 'gate input differs from committed blob: '+name)
    for name,digest in data['build']['native_hashes'].items():
        require(sha(ROOT/name) == digest, 'current native artifact changed: '+name)
    require(sha(ROOT/'.lake/build/bin/lean1090-bench') == s['binary_sha256'], 'current worker differs')
    fresh_path = ROOT/plan['fresh_verification']; require(sha(fresh_path) == plan['fresh_verification_sha256'], 'fresh verification changed')
    fresh = load(fresh_path); require(fresh['status'] == 'passed' and fresh['exit_code'] == 0, 'fresh validation failed')
    text = report_text(plan,data,source,old_rows,fresh)
    appended = io.StringIO(newline=''); writer = csv.writer(appended,lineterminator='\n')
    for r in data['results']:
        writer.writerow([s['commit'],g,r['messages_per_second']['lean1090'],r['messages_per_second']['rs1090'],plan['row_note'],r['mode'],r['lean_over_rust']])
    new_bytes = old_bytes + appended.getvalue().encode()
    reached = decode_threshold_reached(plan, data['results'][0])
    numerator, denominator = target_ratio(plan)
    verification = {'status':'passed','verified_utc':stamp(),'helper_sha256':sha(__file__),'plan_sha256':sha(args.plan),'commit':s['commit'],'results':data['results'],'clocks':data['clocks'],'wrapper_backsteps':data['wrapper_backsteps'],'fresh_verification_sha256':sha(fresh_path),'prior_csv_sha256':plan['prior_csv_sha256'],'prior_csv_bytes':len(old_bytes),'prior_rows_preserved':len(old_rows),'rows_appended':2,'csv_after_sha256':hashlib.sha256(new_bytes).hexdigest(),'report_sha256':hashlib.sha256(text.encode()).hexdigest(),'decode_target_ratio':{'numerator':numerator,'denominator':denominator},'decode_threshold_reached':reached,'next':'Stop for user review.' if reached else 'Complete diagnostic and independent review before another optimization.'}
    require(inventory(source) == data['source_files'], 'source evidence changed during validation')
    shutil.copytree(source,destination)
    require(inventory(destination) == data['source_files'], 'archive copy differs')
    (destination/'report-verification.json').write_text(json.dumps(verification,indent=2)+'\n')
    with report.open('x') as stream:
        stream.write(text)
    require(csv_path.read_bytes() == old_bytes, 'prior CSV changed before append')
    with csv_path.open('ab') as stream:
        stream.write(appended.getvalue().encode())
    require(csv_path.read_bytes() == new_bytes and sha(report) == verification['report_sha256'], 'written report/CSV differs')
    archive = {'status':'passed','source':str(source.relative_to(ROOT)),'destination':str(destination.relative_to(ROOT)),'file_count':len(data['source_files']),'files':data['source_files'],'verified_utc':stamp(),'added_artifacts':{str((destination/'report-verification.json').relative_to(ROOT)):sha(destination/'report-verification.json'),str(report.relative_to(ROOT)):sha(report),'bench/results.csv':sha(csv_path)},'note':'Every original file copied byte-identically; verifier/report/results hashes are separate. Independent result review is separate.'}
    require(inventory(source) == data['source_files'], 'source evidence changed during archival')
    (destination/'archive-verification.json').write_text(json.dumps(archive,indent=2)+'\n')
    print(json.dumps({'status':'passed','archive':str(destination.relative_to(ROOT)),'archive_sha256':sha(destination/'archive-verification.json'),'report':str(report.relative_to(ROOT)),'report_sha256':sha(report),'decode_target_ratio':{'numerator':numerator,'denominator':denominator},'decode_threshold_reached':reached,'next':verification['next']},indent=2))


if __name__ == '__main__':
    main()

#!/usr/bin/env python3
"""Archive completed timing evidence and append results; never build or benchmark.

Prepare a plan and exact prior-CSV snapshot before timing. After timing, invoke
with --plan and --source. --inspect only validates retained measurement data.
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


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load(path):
    return json.loads(Path(path).read_text())


def stamp():
    return datetime.now(timezone.utc).isoformat()


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
    summary, status = load(source/'summary.json'), load(source/'status.json')
    require(summary['status'] == status['status'] == 'complete', 'timing incomplete')
    require(summary['generation'] == status['generation'] == generation, 'wrong generation')
    build, fresh = load(source/'binary-built.json'), load(source/'fresh-native-inputs.json')
    require(build['commit'] == summary['commit'] and build['sha256'] == summary['binary_sha256'], 'build identity differs')
    require(len(fresh) == build['project_c_objects_regenerated'], 'fresh native cardinality differs')
    for item in fresh:
        for name, data in item['artifacts'].items():
            require(data['sha256'] == build['native_hashes'][name], 'native record differs: '+name)
    git_files = ['before-build', 'before-decode', 'after-decode', 'before-cpr', 'after-cpr', 'after-timing']
    for label in git_files:
        data = load(source/(label+'-git.json'))
        require(data['clean'] and data['stdout'] == '' and data['commit'] == summary['commit'], 'unclean/wrong recorded commit')
        require(data['oracle_commit'] == ORACLE_COMMIT and data['oracle_tracked_status'] == '', 'oracle changed')
        require((source/(label+'-lock.log')).read_text().strip() == 'Lock audit: 104 frozen files match SHA-256.', 'lock check missing')
    gate = verify_gate_evidence(load(source/'gate-evidence.json'), sha(source/'gate-full.log'), load(source/'correctness-inputs.json'))
    require(load(source/'gate-verification.json')['commit_to_measure'] == summary['commit'], 'gate commit differs')
    results, metas, clocks, plans = [], {}, {}, []
    commands = load(source/'commands.json')
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
            'power_plan_guid': plans[0], 'source_files': inventory(source)}


def report_text(plan, data, source, old_rows, fresh):
    g = plan['generation']; s = data['summary']; results = data['results']; meta = data['metadata']['decode']
    reached = results[0]['medians_nanoseconds']['rs1090']*10 >= results[0]['medians_nanoseconds']['lean1090']*11
    action = ('The 1.10× decode threshold is reached. Stop for user review before further optimization or final deliverable work.'
              if reached else 'The 1.10× decode threshold remains unmet. A complete diagnostic and independent review precede the next optimization.')
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
    old_rows = list(csv.DictReader(io.StringIO(old_bytes.decode())))
    require(len(old_rows) == plan['prior_csv_rows'] == g*2, 'prior row count differs')
    require([(int(r['generation']),r['mode']) for r in old_rows] == [(i,m) for i in range(g) for m in ('decode','cpr')], 'prior generation/mode sequence differs')
    require(old_bytes.endswith(b'\n'), 'prior CSV lacks a final newline')
    data = validate_source(source,g); s = data['summary']
    require(source.name == f'gen{g}-{s["commit"][:7]}', 'source name differs from measured commit')
    require(subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip() == s['commit'], 'HEAD differs from measured commit')
    for name,digest in load(source/'correctness-inputs.json').items():
        require(hashlib.sha256(subprocess.check_output(['git','show',s['commit']+':'+name],cwd=ROOT)).hexdigest() == digest, 'gate input differs from committed blob: '+name)
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
    reached = data['results'][0]['medians_nanoseconds']['rs1090']*10 >= data['results'][0]['medians_nanoseconds']['lean1090']*11
    verification = {'status':'passed','verified_utc':stamp(),'helper_sha256':sha(__file__),'plan_sha256':sha(args.plan),'commit':s['commit'],'results':data['results'],'clocks':data['clocks'],'wrapper_backsteps':data['wrapper_backsteps'],'fresh_verification_sha256':sha(fresh_path),'prior_csv_sha256':plan['prior_csv_sha256'],'prior_csv_bytes':len(old_bytes),'prior_rows_preserved':len(old_rows),'rows_appended':2,'csv_after_sha256':hashlib.sha256(new_bytes).hexdigest(),'report_sha256':hashlib.sha256(text.encode()).hexdigest(),'decode_threshold_reached':reached,'next':'Stop for user review.' if reached else 'Complete diagnostic and independent review before another optimization.'}
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
    print(json.dumps({'status':'passed','archive':str(destination.relative_to(ROOT)),'archive_sha256':sha(destination/'archive-verification.json'),'report':str(report.relative_to(ROOT)),'report_sha256':sha(report),'decode_threshold_reached':reached,'next':verification['next']},indent=2))


if __name__ == '__main__':
    main()

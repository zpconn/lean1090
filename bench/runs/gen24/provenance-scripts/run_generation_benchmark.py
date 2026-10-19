#!/usr/bin/env python3
"""Fresh committed native build and provenance around the frozen two-mode benchmark.

Outputs stay below ignored .cache throughout timing. Requires prior full-gate
success bound to the exact current correctness inputs; never runs that gate.
No profiler/build/test may run concurrently with the two measured modes.
"""
from __future__ import annotations

import argparse
import csv
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import shlex
import shutil
import statistics
import subprocess
import time

ROOT = Path(__file__).resolve().parents[2]
BINARY = ROOT / '.lake/build/bin/lean1090-bench'
ORACLE = ROOT / '.cache/rs1090-target/dist/lean1090-oracle-bench'
IR = ROOT / '.lake/build/ir'
COUNT = 172432
CORPUS_SHA = '3e5aa149f2d45d675f79960f03c39a6a0e4f7c6acc3c067bebdd7b9be6ce5505'
ORACLE_COMMIT = '685dfaa34c5ab186c691bca3cfe2a22e12517d30'
INPUT_ROOTS = ('Spec/', 'Model/', 'Impl/', 'Proofs/', 'Tests/', 'Numeric/', 'CLI/', 'Bench/',
               'scripts/', 'differential/', 'bench/oracle/', 'bench/bds50/', 'review/upstream-units/')
INPUT_NAMES = {'.gitignore', 'spec.lock', 'lean-toolchain', 'lakefile.toml', 'lake-manifest.json',
               'TRUSTED.md', 'bench/BENCHMARK.md', 'bench/check_worker.py', 'bench/interleave.py',
               'bench/run_oracle.sh', 'tests/numeric_oracle.rs'}


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read_json(path):
    return json.loads(Path(path).read_text())


def output(args):
    return subprocess.check_output(args, cwd=ROOT, text=True)


def tracked():
    return [Path(os.fsdecode(p)) for p in subprocess.check_output(
        ['git', 'ls-files', '-z'], cwd=ROOT).split(b'\0') if p]


def gate_input_hashes():
    """All tracked runtime/proof/gate/oracle sources, plus all frozen members."""
    frozen = set()
    for line in (ROOT/'spec.lock').read_text().splitlines():
        digest, separator, name = line.partition('  ')
        require(separator and len(digest) == 64 and all(c in '0123456789abcdef' for c in digest), 'malformed lock line')
        require(name not in frozen, 'duplicate lock member')
        frozen.add(name)
    def relevant(p):
        return (str(p) in INPUT_NAMES or str(p) in frozen or str(p).startswith(INPUT_ROOTS) or
                (len(p.parts) == 1 and p.suffix == '.lean'))
    untracked = [Path(os.fsdecode(p)) for p in subprocess.check_output(
        ['git', 'ls-files', '--others', '--exclude-standard', '-z'], cwd=ROOT).split(b'\0') if p]
    unstaged_new = [str(p) for p in untracked if relevant(p)]
    require(not unstaged_new, 'stage new correctness-input files before capturing gate inputs: '+repr(unstaged_new))
    paths = {str(p) for p in tracked() if relevant(p)}
    require(frozen <= paths, 'a frozen member is not tracked')
    return {name: sha(ROOT / name) for name in sorted(paths)}


def verify_gate_evidence(data, log_sha, current):
    """Pure validation. Source snapshots must have been captured around the gate."""
    require(data.get('schema') == 1, 'gate evidence schema must be 1')
    require(data.get('command') == ['scripts/check_all.sh', '--full'], 'full gate command required')
    require(data.get('exit_code') == 0 and data.get('status') == 'passed', 'full gate did not pass')
    require(data.get('generated_messages') == 10000000, 'full gate must generate 10M messages')
    require(data.get('gate_log_sha256') == log_sha, 'full gate log hash differs')
    require(data.get('input_hashes_before') == current, 'gate before-inputs differ from current inputs')
    require(data.get('input_hashes_after') == current, 'gate after-inputs differ from current inputs')
    for key in ('started_at', 'finished_at'):
        require(isinstance(data.get(key), str), f'gate evidence missing {key}')
        parsed = datetime.fromisoformat(data[key])
        require(parsed.tzinfo is not None, f'gate {key} needs a timezone')
    # UTC may step backward; retain it instead of rewriting chronology.
    return {'status': 'verified', 'input_count': len(current), 'log_sha256': log_sha,
            'raw_gate_started_at': data['started_at'], 'raw_gate_finished_at': data['finished_at'],
            'gate_utc_backstep': datetime.fromisoformat(data['finished_at']) < datetime.fromisoformat(data['started_at'])}


def validate_mode_data(mode, metadata, rows, expected_binary, expected_oracle, cpu):
    """Pure: exact frozen ABAB protocol and recorded arithmetic; no timestamp repair."""
    require(mode in ('decode', 'cpr'), 'unsupported mode')
    require(metadata.get('status') == 'complete' and metadata.get('mode') == mode, 'incomplete/wrong mode')
    require(len(rows) == 48, 'expected all 48 warmup/measured rows')
    require(metadata.get('messages') == COUNT and metadata.get('corpus_sha256') == CORPUS_SHA, 'wrong corpus')
    require(metadata.get('lean_binary_sha256') == expected_binary, 'timed Lean binary differs')
    require(metadata.get('oracle_binary_sha256') == expected_oracle, 'timed oracle binary differs')
    require(metadata.get('oracle_commit') == ORACLE_COMMIT, 'wrong oracle commit')
    require(metadata.get('cpu') == cpu and metadata.get('affinity') == [cpu], 'worker affinity differs')
    require(metadata.get('ordering') == 'ABAB; A=rs1090, B=lean1090; 3 warmup pairs then 21 measured pairs', 'ordering metadata differs')
    plans = [metadata.get('windows_power_plan_'+part, {}) for part in ('before', 'after')]
    require(all(plan.get('status') == 'queried' for plan in plans), 'actual Windows power-plan queries required')
    require(bool(plans[0].get('scheme_guid')) and plans[0]['scheme_guid'] == plans[1].get('scheme_guid'), 'power plan changed')
    backsteps, last_stamp = [], None
    for index, row in enumerate(rows):
        require(int(row['order']) == index+1, 'row order differs')
        require(row['implementation'] == ('rs1090' if index % 2 == 0 else 'lean1090'), 'ABAB order differs')
        require(row['phase'] == ('warmup' if index < 6 else 'measured'), 'warmup/measured phase differs')
        require(int(row['pair']) == (index//2+1 if index < 6 else (index-6)//2+1), 'pair number differs')
        require(int(row['messages']) == COUNT, 'message cardinality differs')
        require(int(row['positions']) == (0 if mode == 'decode' else 11347), 'position cardinality differs')
        ns = int(row['nanoseconds'])
        require(ns > 0, 'nonpositive sample')
        require(float(row['messages_per_second']) == COUNT*1e9/ns, 'sample throughput arithmetic differs')
        stamp = datetime.fromisoformat(row['recorded_at'])
        require(stamp.tzinfo is not None, 'sample timestamp lacks timezone')
        if last_stamp is not None and stamp < last_stamp:
            backsteps.append({'order': index+1, 'previous': rows[index-1]['recorded_at'], 'current': row['recorded_at']})
        last_stamp = stamp
    medians = {}
    for side in ('rs1090', 'lean1090'):
        samples = [int(row['nanoseconds']) for row in rows if row['phase'] == 'measured' and row['implementation'] == side]
        require(len(samples) == 21, 'expected 21 measurements per implementation')
        medians[side] = statistics.median(samples)
        require(metadata['medians_nanoseconds'][side] == medians[side], 'median differs')
        require(metadata['messages_per_second'][side] == COUNT*1e9/medians[side], 'median throughput differs')
        require(metadata['resolved_positions'][side] == (0 if mode == 'decode' else 11347), 'position summary differs')
    require(metadata['lean_over_rust'] == medians['rs1090']/medians['lean1090'], 'ratio differs')
    return {'mode': mode, 'samples': 48, 'medians_nanoseconds': medians,
            'messages_per_second': metadata['messages_per_second'], 'lean_over_rust': metadata['lean_over_rust'],
            'windows_power_plan': plans[0]['scheme_guid'], 'utc_sample_backsteps': backsteps}


class Run:
    def __init__(self, args):
        self.args = args
        self.out = args.output.resolve()
        self.commands = []
        self.clock_events = []
        self.commit = None
        self.lock_sha = None
        self.input_hashes = None
        self.objects = []
        self.native_hashes = {}

    def write(self, name, data):
        (self.out / name).write_text(json.dumps(data, indent=2)+'\n')

    def stamp(self, label):
        event = {'event': label, 'utc': datetime.now(timezone.utc).isoformat(), 'monotonic_ns': time.monotonic_ns()}
        if self.clock_events:
            event['utc_backstep'] = datetime.fromisoformat(event['utc']) < datetime.fromisoformat(self.clock_events[-1]['utc'])
        self.clock_events.append(event)
        self.write('clock-events.json', self.clock_events)
        return event

    def command(self, args, log_name):
        item = {'argv': list(map(str, args)), 'start': self.stamp('start '+log_name), 'log': log_name}
        self.commands.append(item)
        self.write('commands.json', self.commands)
        with (self.out / log_name).open('w') as stream:
            result = subprocess.run(item['argv'], cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT, check=False)
        item.update(finish=self.stamp('finish '+log_name), exit_code=result.returncode)
        self.write('commands.json', self.commands)
        require(result.returncode == 0, f'{log_name}: command exited {result.returncode}; evidence retained')
        return item

    def clean(self, label):
        head = output(['git', 'rev-parse', 'HEAD']).strip()
        status = output(['git', 'status', '--porcelain=v1', '--untracked-files=all'])
        oracle_head = output(['git', '-C', 'vendor/rs1090', 'rev-parse', 'HEAD']).strip()
        oracle_status = output(['git', '-C', 'vendor/rs1090', 'status', '--porcelain=v1', '--untracked-files=no'])
        self.write(label+'-git.json', {'at': self.stamp(label), 'commit': head, 'stdout': status,
            'command': ['git', 'status', '--porcelain=v1', '--untracked-files=all'],
            'clean': status == '', 'oracle_commit': oracle_head, 'oracle_tracked_status': oracle_status})
        require(status == '', 'tracked/untracked working tree must be clean')
        require(self.commit is None or head == self.commit, 'commit changed during run')
        require(oracle_head == ORACLE_COMMIT and oracle_status == '', 'oracle source differs')
        require(self.lock_sha is None or sha(ROOT/'spec.lock') == self.lock_sha, 'lock changed during run')
        self.command(['python3', 'scripts/check_lock.py'], label+'-lock.log')
        if self.input_hashes is not None:
            require(gate_input_hashes() == self.input_hashes, 'correctness input changed during run')
        return head

    def source_committed(self, source):
        relative = source.relative_to(ROOT)
        expected = subprocess.check_output(['git', 'show', self.commit+':'+str(relative)], cwd=ROOT)
        require(source.is_file() and expected == source.read_bytes(), f'{relative}: source differs from committed source')

    def linked_objects(self):
        rsp = BINARY.with_suffix('.rsp')
        objects = []
        for token in shlex.split(rsp.read_text()):
            candidate = Path(token)
            if not candidate.is_absolute():
                candidate = ROOT / candidate
            if token.endswith('.c.o.export'):
                candidate = candidate.resolve()
                require(candidate.is_relative_to(IR), 'unexpected non-project native object; review link inputs')
                objects.append(candidate)
            elif candidate.is_relative_to(ROOT/'.lake/build') and candidate.suffix in ('.a', '.o'):
                raise RuntimeError('unexpected local archive/object kind; review before timing: '+token)
        require(objects and len(objects) == len(set(objects)), 'missing/duplicate project object list')
        return objects

    def fresh_build(self):
        self.command(['bench/run_oracle.sh', '--build-only'], 'oracle-prebuild.log')
        # The complete tracked Lean-source inventory includes new imports even if
        # an old response file has not yet discovered them. No fixed object count.
        sources = [ROOT/p for p in tracked() if p.suffix == '.lean']
        expected_c = {IR/source.relative_to(ROOT).with_suffix('.c'): source for source in sources}
        for source in sources:
            self.source_committed(source)
        old_objects = self.linked_objects() if BINARY.with_suffix('.rsp').is_file() else []
        for obj in old_objects:
            require(Path(str(obj).removesuffix('.o.export')) in expected_c, 'old native object has no committed source')
        removals = set()
        for cfile in expected_c:
            removals.update(Path(str(cfile)+suffix) for suffix in
                            ('', '.hash', '.o.export', '.o.export.hash', '.o.export.trace',
                             '.o', '.o.hash', '.o.trace', '.o.noexport', '.o.noexport.hash', '.o.noexport.trace'))
        removals.update((BINARY, Path(str(BINARY)+'.hash'), Path(str(BINARY)+'.trace'), BINARY.with_suffix('.rsp')))
        self.write('fresh-build-removals.json', [{'path': str(p.relative_to(ROOT)), 'sha256': sha(p)}
                                                for p in sorted(removals) if p.is_file()])
        for path in removals:
            require(path.resolve().is_relative_to(ROOT/'.lake/build'), 'removal escaped generated build directory')
            path.unlink(missing_ok=True)
        require(not any(p.exists() for p in removals), 'native artifact survived deletion')
        build = self.command(['lake', '--no-cache', '--rehash', '-v', 'build', 'lean1090-bench'], 'lean-fresh-build.log')
        self.objects = self.linked_objects()
        records = []
        for obj in self.objects:
            cfile = Path(str(obj).removesuffix('.o.export'))
            require(cfile in expected_c, 'new linked native object has no committed Lean source')
            source = expected_c[cfile]
            self.source_committed(source)
            trace = Path(str(obj)+'.trace')
            require(all(p.is_file() for p in (cfile, obj, trace)), 'fresh C/object/trace missing')
            require(all(p in removals for p in (cfile, obj, trace)), 'linked artifact was not explicitly invalidated')
            records.append({'source': str(source.relative_to(ROOT)), 'source_sha256': sha(source),
                'artifacts': {str(p.relative_to(ROOT)): {'sha256': sha(p), 'mtime_ns': p.stat().st_mtime_ns}
                              for p in (cfile, obj, trace)},
                'freshness': 'all generated paths removed before build and recreated; mtimes retained raw, not used across UTC clock steps'})
        self.native_hashes = {str(p.relative_to(ROOT)): sha(p) for obj in self.objects for p in
                             (obj, Path(str(obj).removesuffix('.o.export')), Path(str(obj)+'.trace'))}
        self.native_hashes.update({str(p.relative_to(ROOT)): sha(p) for p in
                                  (BINARY, BINARY.with_suffix('.rsp'), Path(str(BINARY)+'.trace'))})
        self.write('fresh-native-inputs.json', records)
        self.write('binary-built.json', {'at': self.stamp('binary built'), 'commit': self.commit,
            'sha256': sha(BINARY), 'path': str(BINARY.relative_to(ROOT)), 'spec_lock_sha256': self.lock_sha,
            'build_command': build, 'project_c_objects_regenerated': len(self.objects),
            'old_project_object_count': len(old_objects),
            'object_membership_added': sorted(str(p.relative_to(ROOT)) for p in set(self.objects)-set(old_objects)),
            'object_membership_removed': sorted(str(p.relative_to(ROOT)) for p in set(old_objects)-set(self.objects)),
            'worker_source_sha256': sha(ROOT/'Bench/WholeDecoder.lean'), 'native_hashes': self.native_hashes})

    def unchanged_native(self):
        require(all((ROOT/name).is_file() and sha(ROOT/name) == value for name,value in self.native_hashes.items()),
                'native build artifact changed during timing')

    def observe(self, label):
        self.command(['python3', 'review/diagnostics/capture_benchmark_host.py', '--output',
                      str(self.out/(label+'-host.json'))], label+'-host.log')
        self.command(['python3', 'bench/check_worker.py', '--capture-environment-only', '--output',
                      str(self.out/(label+'-environment'))], label+'-environment.log')
        host = read_json(self.out/(label+'-host.json'))
        require(all(value in (None, '') for value in host['compilation_environment'].values()), 'inspect compilation overrides before timing')
        require(all(value['status'] == 'unavailable' and value.get('errno') == 2 for value in host['cargo_config_candidates']),
                'inspect existing/unreadable Cargo configuration before timing')
        fingerprints = host['dist_oracle_fingerprints']['records']
        require(fingerprints and all(value['fields']['rustflags'] == [] for value in fingerprints), 'oracle fingerprint flags differ')
        env = read_json(self.out/(label+'-environment/environment.json'))
        require(env['worker_binary_sha256'] == sha(BINARY), 'environment capture refers to another binary')
        # The frozen capture has a historical module list; supplement it with
        # every actual project object in the dynamic response file.
        traces = [Path(str(obj)+'.trace') for obj in self.objects] + [Path(str(BINARY)+'.trace')]
        drivers = []
        for trace in traces:
            commands = [entry['message'][3:] for entry in read_json(trace)['log'] if entry['message'].startswith('.> ')]
            require(commands, 'missing compiler command in '+str(trace))
            for text in commands:
                args = shlex.split(text)
                require(Path(args[0]).name == 'clang', 'unexpected C compiler command')
                normal = subprocess.run(args+['-###'], cwd=ROOT, capture_output=True, text=True, check=True)
                disabled = subprocess.run(args+['-###', '--no-default-config'], cwd=ROOT, capture_output=True, text=True, check=True)
                drivers.append({'trace': str(trace.relative_to(ROOT)), 'trace_sha256': sha(trace), 'argv': args,
                    'normal_stdout': normal.stdout, 'normal_stderr': normal.stderr,
                    'no_default_config_stdout': disabled.stdout, 'no_default_config_stderr': disabled.stderr})
                self.write(label+'-effective-clang-drivers.json', drivers)
                require(normal.stdout == disabled.stdout and normal.stderr == disabled.stderr, 'Clang default configuration changed effective driver')
                if '-c' in args:
                    require('"-target-cpu" "x86-64"' in normal.stderr and '"-tune-cpu" "generic"' in normal.stderr, 'CPU-specific target flags')
                    require('"-O3"' in normal.stderr and '"-ffp-contract=off"' in normal.stderr, 'missing O3/ffp-contract=off')
                    require('"-target-feature"' not in normal.stderr, 'explicit CPU target feature in effective compiler command')
        self.unchanged_native()

    def execute(self):
        require(self.out.is_relative_to((ROOT/'.cache').resolve()) and self.out != ROOT/'.cache', 'output must be below project .cache')
        require(not self.out.exists(), 'output exists; never overwrite or retry into previous evidence')
        require(subprocess.run(['git', 'check-ignore', '--quiet', str(self.out/'probe')], cwd=ROOT).returncode == 0,
                'output must be git-ignored')
        self.out.mkdir(parents=True, exist_ok=False)
        self.write('status.json', {'status': 'in-progress', 'generation': self.args.generation})
        try:
            self.commit = self.clean('before-build')
            self.lock_sha = sha(ROOT/'spec.lock')
            self.input_hashes = gate_input_hashes()
            evidence = read_json(self.args.gate_evidence)
            gate = verify_gate_evidence(evidence, sha(self.args.gate_log), self.input_hashes)
            gate.update(evidence_path=str(self.args.gate_evidence.resolve()), evidence_sha256=sha(self.args.gate_evidence),
                        log_path=str(self.args.gate_log.resolve()), commit_to_measure=self.commit)
            self.write('gate-verification.json', gate)
            self.write('correctness-inputs.json', self.input_hashes)
            shutil.copyfile(self.args.gate_evidence, self.out/'gate-evidence.json')
            shutil.copyfile(self.args.gate_log, self.out/'gate-full.log')
            scripts = self.out/'provenance-scripts'
            scripts.mkdir()
            for name in ('run_generation_benchmark.py', 'capture_benchmark_host.py'):
                source = ROOT/'review/diagnostics'/name
                self.source_committed(source)
                shutil.copyfile(source, scripts/name)
            self.write('scope.json', {'generation': self.args.generation, 'commit': self.commit,
                'operator_note': self.args.operator_note,
                'precondition': 'All tests/builds/profilers and collaborating work are stopped before timing; no host-wide quiescence is inferred.',
                'no_mutations': 'No source edits, machine settings changes, gate weakening, sample deletion or automatic retry.'})
            self.fresh_build()
            self.observe('before')
            binary_sha, oracle_sha = sha(BINARY), sha(ORACLE)
            results = []
            for mode in ('decode', 'cpr'):
                self.clean('before-'+mode)
                self.unchanged_native()
                require(sha(BINARY) == binary_sha and sha(ORACLE) == oracle_sha, 'worker binary changed')
                self.command(['python3', 'bench/interleave.py', '--mode', mode, '--cpu', str(self.args.cpu),
                              '--lean-worker', str(BINARY), '--output', str(self.out/mode)], mode+'-interleave.log')
                meta = read_json(self.out/mode/'metadata.json')
                with (self.out/mode/'samples.csv').open() as stream:
                    rows = list(csv.DictReader(stream))
                result = validate_mode_data(mode, meta, rows, binary_sha, oracle_sha, self.args.cpu)
                result.update(samples_sha256=sha(self.out/mode/'samples.csv'), metadata_sha256=sha(self.out/mode/'metadata.json'))
                results.append(result)
                self.clean('after-'+mode)
                self.unchanged_native()
                require(sha(ORACLE) == oracle_sha, 'oracle changed during mode')
            require(results[0]['windows_power_plan'] == results[1]['windows_power_plan'], 'power plan changed between modes')
            self.observe('after')
            self.clean('after-timing')
            self.unchanged_native()
            require(sha(BINARY) == binary_sha and sha(ORACLE) == oracle_sha, 'worker changed after timing')
            self.write('summary.json', {'status': 'complete', 'generation': self.args.generation,
                'commit': self.commit, 'binary_sha256': binary_sha, 'oracle_binary_sha256': oracle_sha,
                'spec_lock_sha256': self.lock_sha, 'results': results, 'completed_at': self.stamp('complete'),
                'utc_backsteps_retained': [event for event in self.clock_events if event.get('utc_backstep')],
                'next': 'Review and archive all raw samples/provenance; no automatic optimization or publication.'})
            self.write('status.json', {'status': 'complete', 'generation': self.args.generation})
            print(json.dumps(results, indent=2))
        except BaseException as error:
            self.write('status.json', {'status': 'invalid', 'generation': self.args.generation,
                'error': type(error).__name__+': '+str(error), 'at': self.stamp('failed'),
                'retention': 'All partial evidence retained; no automatic retry or sample removal.'})
            raise


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--generation', type=int)
    parser.add_argument('--output', type=Path)
    parser.add_argument('--gate-evidence', type=Path)
    parser.add_argument('--gate-log', type=Path)
    parser.add_argument('--cpu', type=int, default=0)
    parser.add_argument('--operator-note', default='No known project work overlaps timed modes; host observations retained.')
    parser.add_argument('--print-gate-inputs', action='store_true', help='Read-only hash inventory for before/after full gate; no build/timing')
    args = parser.parse_args()
    if args.print_gate_inputs:
        print(json.dumps(gate_input_hashes(), indent=2))
        return
    if args.generation is None or args.generation < 1 or any(value is None for value in (args.output, args.gate_evidence, args.gate_log)):
        parser.error('--generation N (N>=1), --output, --gate-evidence and --gate-log are required')
    require(args.cpu >= 0, 'CPU must be nonnegative')
    Run(args).execute()


if __name__ == '__main__':
    main()

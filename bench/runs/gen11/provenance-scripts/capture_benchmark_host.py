#!/usr/bin/env python3
"""Read-only supplementary observations; writes only the requested JSON artifact.

No builds, benchmarks, settings changes, Windows queries or credential dumps.
Run before/after timing, never concurrently with measured benchmark workers.
"""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import platform
import re
import shutil
import subprocess
import time
import tomllib

ROOT = Path(__file__).resolve().parents[2]
COUNTERS = ('user', 'nice', 'system', 'idle', 'iowait', 'irq', 'softirq', 'steal', 'guest', 'guest_nice')
PROFILE_KEYS = {'inherits', 'opt-level', 'debug', 'split-debuginfo', 'strip', 'debug-assertions',
                'overflow-checks', 'lto', 'panic', 'incremental', 'codegen-units', 'rpath',
                'rustflags', 'trim-paths'}
BUILD_KEYS = {'rustflags', 'rustdocflags', 'target', 'jobs', 'rustc', 'rustc-wrapper',
              'rustc-workspace-wrapper', 'incremental', 'target-dir'}
TARGET_KEYS = {'rustflags', 'rustdocflags', 'linker'}


def utc():
    return datetime.now(timezone.utc).isoformat()


def digest(data):
    return hashlib.sha256(data).hexdigest()


def unavailable(error):
    # Exception strings can contain file contents; record only class/errno.
    return {'status': 'unavailable', 'error_type': type(error).__name__, 'errno': getattr(error, 'errno', None)}


def read(path):
    try:
        return {'status': 'available', 'value': Path(path).read_text().strip()}
    except (OSError, UnicodeError) as error:
        return unavailable(error)


def safe_flag(value):
    """Keep compilation flags, but omit any value suggesting embedded credentials."""
    if isinstance(value, str):
        if re.search(r'(?i)(?:token|password|passwd|secret|credential|authorization|api[_-]?key)|://[^/\s]+@', value):
            return {'status': 'redacted_possible_secret', 'sha256': digest(value.encode())}
        return value
    if isinstance(value, list):
        return [safe_flag(item) for item in value]
    if isinstance(value, (int, float, bool)) or value is None:
        return value
    return {'status': 'omitted_unexpected_type', 'type': type(value).__name__}


def profile_settings(table):
    if not isinstance(table, dict):
        return {}
    result = {key: safe_flag(value) for key, value in table.items() if key in PROFILE_KEYS}
    for key in ('build-override', 'package'):
        if key in table and isinstance(table[key], dict):
            result[key] = (profile_settings(table[key]) if key == 'build-override' else
                           {package: profile_settings(fields) for package, fields in table[key].items()})
    return result


def compilation_config(data):
    result = {}
    if isinstance(data.get('build'), dict):
        result['build'] = {key: safe_flag(value) for key, value in data['build'].items() if key in BUILD_KEYS}
    if isinstance(data.get('target'), dict):
        result['target'] = {target: {key: safe_flag(value) for key, value in fields.items() if key in TARGET_KEYS}
                            for target, fields in data['target'].items() if isinstance(fields, dict)}
    if isinstance(data.get('profile'), dict):
        result['profile'] = {profile: profile_settings(fields) for profile, fields in data['profile'].items()}
    return result


def config_record(path, reasons):
    result = {'path': str(path), 'reasons': reasons}
    try:
        raw = path.read_bytes()
        result.update(status='available', sha256=digest(raw), bytes=len(raw),
                      symlink=path.is_symlink(), resolved_path=str(path.resolve()))
        try:
            result['compilation_settings'] = compilation_config(tomllib.loads(raw.decode()))
        except (UnicodeError, tomllib.TOMLDecodeError) as error:
            result['parse'] = unavailable(error)
    except OSError as error:
        result.update(unavailable(error))
    return result


def cargo_configs():
    candidates = {}
    def add(directory, reason):
        for name in ('config', 'config.toml'):
            candidates.setdefault(directory / name, []).append(reason)
    for folder in [ROOT, *ROOT.parents]:
        add(folder / '.cargo', 'project invocation directory or ancestor')
    # These are candidates, not assertions that Cargo loads manifest-directory configs.
    for folder in [ROOT / 'bench/oracle', ROOT / 'bench']:
        add(folder / '.cargo', 'manifest-directory ancestor; relevant if invocation cwd changes')
    add(ROOT / '.cache/cargo', 'frozen oracle build explicitly sets CARGO_HOME here')
    add(Path.home() / '.cargo', 'default Cargo home; overridden by frozen oracle build')
    if os.environ.get('CARGO_HOME'):
        add(Path(os.environ['CARGO_HOME']).expanduser().absolute(), 'current shell CARGO_HOME; frozen runner overrides')
    return [config_record(path, reasons) for path, reasons in sorted(candidates.items())]


def environment_flags():
    explicit = {'CC', 'CXX', 'LEAN_CC', 'CFLAGS', 'CXXFLAGS', 'CPPFLAGS', 'LDFLAGS',
                'RUSTFLAGS', 'CARGO_ENCODED_RUSTFLAGS', 'CARGO_BUILD_RUSTFLAGS', 'CARGO_BUILD_RUSTDOCFLAGS',
                'CARGO_BUILD_TARGET', 'CARGO_BUILD_JOBS', 'CARGO_INCREMENTAL', 'RUSTC', 'RUSTC_WRAPPER',
                'RUSTC_WORKSPACE_WRAPPER', 'CARGO_BUILD_RUSTC', 'CARGO_BUILD_RUSTC_WRAPPER',
                'CARGO_BUILD_RUSTC_WORKSPACE_WRAPPER'}
    patterns = [r'CARGO_TARGET_[A-Z0-9_]+_(?:RUSTFLAGS|RUSTDOCFLAGS|LINKER)',
                r'CARGO_PROFILE_[A-Z0-9_]+_(?:OPT_LEVEL|DEBUG|SPLIT_DEBUGINFO|STRIP|DEBUG_ASSERTIONS|OVERFLOW_CHECKS|LTO|PANIC|INCREMENTAL|CODEGEN_UNITS|RPATH)',
                r'(?:CFLAGS|CXXFLAGS|CPPFLAGS|LDFLAGS|CC|CXX)_[A-Za-z0-9_-]+']
    keys = explicit | {key for key in os.environ if any(re.fullmatch(pattern, key) for pattern in patterns)}
    return {key: safe_flag(os.environ.get(key)) for key in sorted(keys)}


def command_version(name):
    executable = shutil.which(name)
    if not executable:
        return {'status': 'unavailable', 'reason': 'not on PATH'}
    # --version performs no compilation; disable rustup auto-install as an extra guard.
    env = dict(os.environ, RUSTUP_AUTO_INSTALL='0', RUSTUP_NO_UPDATE_CHECK='1')
    try:
        proc = subprocess.run([executable, '--version', '--verbose'], cwd=ROOT, env=env,
                              text=True, capture_output=True, timeout=15, check=False)
        return {'status': 'available' if proc.returncode == 0 else 'failed', 'executable': executable,
                'argv': [name, '--version', '--verbose'], 'exit_code': proc.returncode,
                'stdout': proc.stdout.strip(), 'stderr': proc.stderr.strip()}
    except (OSError, subprocess.TimeoutExpired) as error:
        return unavailable(error)


def process_snapshot():
    command = ['ps', '-eo', 'pid,ppid,comm,pcpu,etime']
    try:
        result = subprocess.run(command, text=True, capture_output=True, timeout=15, check=False)
        return {'status': 'available' if result.returncode == 0 else 'failed',
                'argv': command, 'captured_at_utc': utc(), 'exit_code': result.returncode,
                'stdout': result.stdout, 'stderr': result.stderr,
                'note': 'No process arguments or environment are read. pcpu is lifetime-average, not the one-second CPU sample. '
                        'Process visibility depends on the invocation sandbox/namespace.'}
    except (OSError, subprocess.TimeoutExpired) as error:
        return unavailable(error)


def cpu_ticks():
    ticks = {}
    for line in Path('/proc/stat').read_text().splitlines():
        fields = line.split()
        if re.fullmatch(r'cpu\d*', fields[0]):
            values = list(map(int, fields[1:]))
            ticks[fields[0]] = dict(zip(COUNTERS, values))
    return ticks


def cpu_sample():
    try:
        began_utc, began = utc(), time.monotonic_ns()
        before = cpu_ticks()
        time.sleep(1.0)
        after = cpu_ticks()
        ended = time.monotonic_ns()
        per_core = {}
        for core in sorted(before.keys() & after.keys(), key=lambda name: -1 if name == 'cpu' else int(name[3:])):
            delta = {key: after[core].get(key, 0) - before[core].get(key, 0) for key in COUNTERS}
            # guest counters already contribute to user/nice; avoid double-counting.
            total = sum(delta[key] for key in COUNTERS[:8])
            idle = delta['idle'] + delta['iowait']
            valid = total > 0 and all(value >= 0 for value in delta.values())
            per_core[core] = {'before_ticks': before[core], 'after_ticks': after[core], 'delta_ticks': delta,
                              'total_ticks_excluding_guest_double_count': total,
                              'busy_percent_idle_includes_iowait': 100 * (total-idle) / total if valid else None,
                              'status': 'available' if valid else 'counter_delta_unavailable'}
        return {'status': 'available', 'start_utc': began_utc, 'end_utc': utc(),
                'requested_seconds': 1.0, 'elapsed_seconds': (ended-began)/1e9,
                'clock_ticks_per_second': os.sysconf('SC_CLK_TCK'), 'cores': per_core,
                'removed_or_added_cpu_labels': sorted(before.keys() ^ after.keys())}
    except (OSError, ValueError) as error:
        return unavailable(error)


def sysfs_values(patterns, reason):
    paths = sorted({path for pattern in patterns for path in Path('/sys').glob(pattern)})
    if not paths:
        return {'status': 'unavailable', 'reason': reason}
    return {'status': 'available', 'values': {str(path): read(path) for path in paths}}


def host_observations():
    cpuinfo = read('/proc/cpuinfo')
    if cpuinfo.get('status') == 'available':
        fields = []
        allowed = {'processor', 'vendor_id', 'cpu family', 'model', 'model name', 'stepping', 'microcode',
                   'cpu MHz', 'cache size', 'physical id', 'siblings', 'core id', 'cpu cores', 'flags'}
        for block in cpuinfo['value'].split('\n\n'):
            row = {}
            for line in block.splitlines():
                key, separator, value = line.partition(':')
                if separator and key.strip() in allowed:
                    row[key.strip()] = value.strip()
            if row:
                fields.append(row)
        cpuinfo = {'status': 'available', 'processors': fields}
    return {'platform': platform.platform(), 'logical_cpu_count': os.cpu_count(),
            'affinity': sorted(os.sched_getaffinity(0)) if hasattr(os, 'sched_getaffinity') else None,
            'cpuinfo': cpuinfo, 'loadavg_before_sample': read('/proc/loadavg'),
            'uptime': read('/proc/uptime'), 'memory': read('/proc/meminfo'),
            'pressure': {kind: read('/proc/pressure/'+kind) for kind in ('cpu', 'memory', 'io')},
            'cpufreq': sysfs_values(['devices/system/cpu/cpu[0-9]*/cpufreq/'+field for field in
                                    ('scaling_governor', 'scaling_driver', 'scaling_cur_freq', 'scaling_min_freq',
                                     'scaling_max_freq', 'cpuinfo_cur_freq', 'energy_performance_preference')],
                                   'no per-CPU cpufreq interface; typical under WSL2'),
            'thermal': sysfs_values(['class/thermal/thermal_zone*/'+field for field in ('type', 'temp')],
                                   'no thermal zones exposed to this Linux guest'),
            'hwmon': sysfs_values(['class/hwmon/hwmon*/'+field for field in
                                  ('name', 'temp*_input', 'temp*_label', 'temp*_crit', 'fan*_input',
                                   'power*_input', 'power*_average', 'freq*_input')],
                                 'no hwmon readings exposed to this Linux guest')}


def fingerprints():
    directory = ROOT / '.cache/rs1090-target/dist/.fingerprint'
    paths = sorted(set(directory.glob('lean1090-oracle-bench-*/bin-lean1090-oracle-bench.json')) |
                   set(directory.glob('rs1090-*/lib-rs1090.json')))
    records = []
    for path in paths:
        try:
            raw = path.read_bytes()
            data = json.loads(raw)
            allowed = ('rustc', 'profile', 'rustflags', 'features', 'declared_features', 'target', 'config', 'compile_kind')
            records.append({'path': str(path.relative_to(ROOT)), 'sha256': digest(raw),
                            'mtime_utc': datetime.fromtimestamp(path.stat().st_mtime, timezone.utc).isoformat(),
                            'fields': {key: safe_flag(data[key]) for key in allowed if key in data}})
        except (OSError, UnicodeError, json.JSONDecodeError) as error:
            records.append({'path': str(path), **unavailable(error)})
    manifest = config_record(ROOT / 'bench/oracle/Cargo.toml', ['frozen oracle manifest profile declarations'])
    return {'status': 'available' if records else 'unavailable', 'records': records, 'manifest': manifest,
            'note': 'Cargo fingerprint profile/config values are opaque hashes, not decoded effective profiles. '
                    'Multiple rs1090 artifacts may exist; all matching candidates are retained, without claiming selection.'}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if not args.output.parent.is_dir():
        parser.error('--output parent directory must already exist')
    started = utc()
    result = {'schema': 1, 'capture_start_utc': started, 'project_root': str(ROOT),
              'script_sha256': digest(Path(__file__).read_bytes()),
              'classification': 'supplementary read-only host/build observation, not a benchmark',
              'host': host_observations(), 'processes': process_snapshot(),
              'compilation_environment': environment_flags(),
              'cargo_config_candidates': cargo_configs(),
              'versions': {name: command_version(name) for name in ('rustc', 'cargo')},
              'dist_oracle_fingerprints': fingerprints()}
    result['cpu_activity_sample'] = cpu_sample()
    result['loadavg_after_sample'] = read('/proc/loadavg')
    result['capture_end_utc'] = utc()
    result['limitations'] = [
        'This one-second Linux guest observation does not prove host-wide quiescence or isolation during later timing.',
        'WSL2 may hide physical temperatures, governors, host contention and frequency changes; absent interfaces are explicit.',
        'No Windows power-plan query, worker execution, binary fingerprinting, build or settings change occurs here; frozen tools own those records.',
        'Only allowlisted build/target/profile config values and compile-related environment variables are recorded; credentials, registries and arbitrary env sections are omitted.',
        'Config candidates are observations, not a Cargo merge/precedence interpreter. Includes, CLI --config arguments and external wrappers are not resolved.',
        'Frozen bench/run_oracle.sh clears RUSTFLAGS/CARGO_ENCODED_RUSTFLAGS and sets CARGO_HOME/target directory; other selected variables/configs are observed rather than neutralized.',
        'Fingerprint rustflags are retained verbatim unless a possible credential is redacted; opaque profile hashes require the manifest and original build evidence for interpretation.'
    ]
    # Exclusive creation avoids overwriting prior evidence. This is the only write.
    with args.output.open('x') as output:
        json.dump(result, output, indent=2, sort_keys=True)
        output.write('\n')
    print(json.dumps({'output': str(args.output), 'capture_start_utc': started,
                      'capture_end_utc': result['capture_end_utc'], 'cpu_sample_status': result['cpu_activity_sample']['status']}))


if __name__ == '__main__':
    main()

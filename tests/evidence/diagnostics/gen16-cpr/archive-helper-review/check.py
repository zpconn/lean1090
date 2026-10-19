#!/usr/bin/env python3
"""No native work: complete miniature archives exercise the optional path."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
import contextlib, gzip, hashlib, importlib.util, io, json, tempfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[4]
SOURCE = ROOT / 'review/diagnostics/archive_cpr_costs.py'
spec = importlib.util.spec_from_file_location('archive_under_review', SOURCE)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
checks = []


def fixture(name, option):
    with tempfile.TemporaryDirectory(prefix='lean1090-cpr-archive-') as temp:
        root = Path(temp)
        cache, out = root / 'cache', root / 'evidence'
        out.mkdir()
        chosen = option or 'perf-gen15-cpr'
        for directory in ['driver-final', 'validation', 'callgrind', chosen, 'perf-unselected']:
            (cache / directory).mkdir(parents=True, exist_ok=True)
        result = {'digest': {'count': 172432}, 'positions': 11347}
        build = {'status': 'passed', 'unchanged_native_inputs': {}, 'artifacts': {}}
        run = {'status': 'passed', 'root': 'l_Lean1090_Diagnostics_CPRCosts_runCPR',
               'prepared': {'selected': 172432}, 'decoded': {'retained': 172432},
               'result': {**result, 'batch_state_check': False}}
        val = {'status': 'passed', 'result': {**result, 'batch_state_check': True}}
        for path, value in [(cache / 'driver-final/driver-build.json', build),
                            (cache / 'callgrind/run.json', run),
                            (cache / 'validation/summary.json', val)]:
            path.write_text(json.dumps(value))
        (cache / chosen / 'perf.data').write_bytes(b'raw-profile-block\n' * 18000)
        (cache / 'perf-unselected/perf.data').write_bytes(b'unselected evidence')
        (cache / 'driver-final/cpr-costs').write_bytes(b'\x7fELFfake-rebuildable')
        toolroot = root / 'review/diagnostics'
        toolroot.mkdir(parents=True)
        names = ['CPRCosts.lean','build_cpr_costs.py','validate_cpr_costs.py',
                 'profile_cpr_costs.py','analyze_cpr_costs.py','archive_cpr_costs.py',
                 'analyze_callgrind.py','extract_cpr_power_contexts.py','extract_cpr_decoder_stages.py']
        for filename in names:
            (toolroot / filename).write_text('fixture ' + filename)
        before = {str(p.relative_to(root)): sha(p) for p in root.rglob('*') if p.is_file()}
        module.ROOT = root
        sys.argv = ['archive', '--cache', 'cache', '--output', 'evidence']
        if option:
            sys.argv += ['--perf-subdir', option]
        with contextlib.redirect_stdout(io.StringIO()):
            module.main()
        manifest = json.loads((out / 'archive-manifest.json').read_text())
        expected = {f'retained/{chosen}/perf.data.gz', 'retained/driver-final/driver-build.json',
                    'retained/callgrind/run.json', 'retained/validation/summary.json'}
        expected |= {'tooling/' + n for n in names}
        assert set(manifest['files']) == expected
        assert set(manifest['omitted_binaries']) == {'cache/driver-final/cpr-costs'}
        for rel, row in manifest['files'].items():
            path = out / rel
            raw = gzip.decompress(path.read_bytes()) if path.suffix == '.gz' else path.read_bytes()
            assert sha(path) == row['stored_sha256']
            assert hashlib.sha256(raw).hexdigest() == row['source_sha256']
            assert len(raw) == row['source_bytes']
        assert all(sha(root / p) == h for p, h in before.items())
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                module.main()
        except AssertionError:
            pass
        else:
            raise AssertionError('existing archive was overwritten')
        checks.append({'case': name, 'status': 'passed', 'retained_files': len(expected),
                       'originals_unchanged': True, 'overwrite_rejected': True})


assert module.archive_subdirectories() == ['driver-attempt01','driver','driver-final','validation','callgrind','perf-gen15-cpr']
checks.append({'case': 'historical default inventory', 'status': 'passed'})
fixture('full historical-default archive', None)
fixture('full generation16 override archive', 'perf-gen16-cpr')
for bad in ['', '.', '..', '../perf-gen16-cpr', '/tmp/perf-gen16-cpr', 'perf-foo/bar', 'perf-foo\\bar', 'driver-final']:
    try:
        module.archive_subdirectories(bad)
    except AssertionError:
        checks.append({'case': 'reject ' + repr(bad), 'status': 'passed'})
    else:
        raise AssertionError('unsafe name accepted: ' + repr(bad))
result = {'status': 'passed', 'helper_sha256': sha(SOURCE), 'test_sha256': sha(Path(__file__)),
          'cases': checks, 'native_or_profile_execution': False}
target = HERE / 'tests.json'
assert not target.exists()
target.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps({'status': 'passed', 'cases': len(checks), 'helper_sha256': sha(SOURCE)}))

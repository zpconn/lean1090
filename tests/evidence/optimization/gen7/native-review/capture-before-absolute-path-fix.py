#!/usr/bin/env python3
"""Capture an already-successful gen7 build; never execute native decoders."""
import argparse
import hashlib
import json
from pathlib import Path
import shlex
import subprocess

OUT = Path(__file__).resolve().parent
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--build', required=True, type=Path)
    args = parser.parse_args()
    assert not (OUT / 'inspection-inputs.json').exists()
    build = args.build
    build_data = json.loads(build.read_text())
    assert build_data['exit_code'] == 0
    assert sha(build.with_suffix('.log')) == build_data['log_sha256']
    assert 'Build completed successfully' in build.with_suffix('.log').read_text()
    binary = Path('.lake/build/bin/lean1090')
    sources = ['Impl/ScoreGate.lean', 'Impl/CommB.lean', 'Impl/Message.lean',
               'Impl/JSON.lean', 'CLI/Main.lean', 'Bench/WholeDecoder.lean',
               'Proofs/ScoreGateInteger.lean', 'Proofs/ScoreGate.lean',
               'Proofs/CommBTables.lean', 'Proofs/Decoder.lean',
               'Tests/CommBDifferential.lean', 'Tests/Upstream.lean',
               'TRUSTED.md', 'lakefile.toml', 'spec.lock']
    paths = set(map(Path, sources)) | {build, build.with_suffix('.log'), binary,
            Path(str(binary) + '.rsp'), Path(str(binary) + '.trace'),
            Path('bench/runs/gen6/fresh-native-inputs.json'),
            Path('tests/evidence/diagnostics/gen6/generated-c/Impl/ScoreGate.c'),
            Path('tests/evidence/diagnostics/gen6/generated-c/Impl/CommB.c')}
    object_rows = []
    for token in shlex.split(Path(str(binary) + '.rsp').read_text()):
        if not token.endswith('.c.o.export'):
            continue
        obj = Path(token)
        assert str(obj).startswith('.lake/build/ir/'), obj
        source = Path(str(obj).removeprefix('.lake/build/ir/').removesuffix('.c.o.export') + '.lean')
        assert source.is_file(), source
        c = Path(str(obj).removesuffix('.o.export'))
        trace = Path(str(obj) + '.trace')
        paths.update([source, c, obj, trace])
        object_rows.append({'source': str(source), 'c': str(c), 'object': str(obj), 'trace': str(trace)})
    assert object_rows and len({r['source'] for r in object_rows}) == len(object_rows)
    assert any(r['source'] == 'Impl/ScoreGate.lean' for r in object_rows)
    before = {str(p): {'sha256': sha(p), 'bytes': p.stat().st_size} for p in sorted(paths)}
    retained = {}
    for path in sorted(paths):
        if path == binary or path.name.endswith('.o.export'):
            continue
        destination = OUT / 'retained' / path
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(path.read_bytes())
        retained[str(path)] = str(destination.relative_to(OUT))
    commands = []

    def command(argv, name):
        result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        (OUT / (name + '.txt')).write_bytes(result.stdout)
        (OUT / (name + '.stderr')).write_bytes(result.stderr)
        commands.append({'argv': argv, 'stdout': name + '.txt', 'stderr': name + '.stderr', 'exit_code': result.returncode})
        assert result.returncode == 0, argv
        return result.stdout.decode()

    symbols = command(['nm', '-g', '--defined-only', str(binary)], 'binary-symbols')
    live_symbols = {line.split()[-1] for line in symbols.splitlines() if line.split()}
    requested = {P + name for name in ('ScoreGate_choose', 'ScoreGate_commonDenominator',
                 'ScoreGate_scaledNumerator', 'ScoreGate_scaledTotals', 'ScoreGate_mass',
                 'ScoreGate_center', 'ScoreGate_envelope', 'cbScorePasses',
                 'cbScorePasses___lam__0___boxed', 'cbDensityTermsFast',
                 'commBCoreEligible', 'commBEligible', 'inferCommB', 'decodeBDS',
                 'decode', 'reportWithSyndrome', 'Semantics_commB')}
    requested.update(s for s in live_symbols if 'Impl_ScoreGate' in s and not ('___closed__' in s or s.startswith('_init_')))
    requested.add('initialize_lean1090_Impl_ScoreGate')
    for symbol in sorted(requested):
        command(['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + symbol,
                 str(binary)], 'binary-' + symbol.removeprefix(P))
    for symbol in ('choose', 'commonDenominator', 'scaledNumerator', 'scaledTotals'):
        command(['objdump', '-dr', '--no-show-raw-insn', '--disassemble=' + P + 'ScoreGate_' + symbol,
                 '.lake/build/ir/Impl/ScoreGate.c.o.export'], 'object-' + symbol)
    command(['git', 'diff', 'HEAD', '--', 'Impl/ScoreGate.lean'], 'runtime-diff')
    command(['git', 'diff', 'HEAD', '--name-only', '--', 'Impl'], 'runtime-changed-files')
    command(['git', 'show', 'HEAD:Impl/ScoreGate.lean'], 'prior-ScoreGate-source')
    for path, row in before.items():
        assert sha(path) == row['sha256'], path
    record = {'kind': 'static_compiled_structure_review_no_decoder_execution',
              'commit': subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip(),
              'successful_integrated_build_path': str(build),
              'successful_integrated_build': build_data, 'inputs': before, 'retained': retained,
              'linked_project_objects': object_rows,
              'commands': commands, 'all_captured_inputs_unchanged': True,
              'requested_binary_symbols': {s: s in live_symbols for s in sorted(requested)},
              'binary_scope': 'Current integrated CLI. The future freshly built timed worker is not claimed inspected here.',
              'limits': 'Source, generated C, object and linked assembly inspection only. No build, decoder run, test campaign, profiler or benchmark.'}
    (OUT / 'inspection-inputs.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({'status': 'captured', 'inputs': len(before), 'commands': len(commands),
                      'project_objects': len(object_rows), 'cli_sha256': before[str(binary)]['sha256']}))


if __name__ == '__main__':
    main()

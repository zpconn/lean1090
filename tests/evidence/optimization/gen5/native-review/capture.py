#!/usr/bin/env python3
"""Capture existing compiled artifacts; never build or execute a decoder."""
import hashlib
import json
from pathlib import Path
import shlex
import subprocess

OUT = Path(__file__).resolve().parent
ROOT = Path.cwd()
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    assert not (OUT / 'inspection-inputs.json').exists()
    build = Path('tests/evidence/optimization/gen5/integration/targeted-build.json')
    build_data = json.loads(build.read_text())
    assert build_data['exit_code'] == 0
    assert sha(build.with_suffix('.log')) == build_data['log_sha256']
    sources = ['Impl/CommB.lean', 'Impl/PayloadBits.lean', 'Impl/Binary64.lean', 'Impl/ScoreGate.lean',
               'Proofs/CommBMach.lean', 'Proofs/CommBTables.lean', 'Proofs/Decoder.lean',
               'Tests/CommBDifferential.lean', 'CLI/Main.lean', 'TRUSTED.md', 'lakefile.toml', 'spec.lock']
    binaries = [Path('.lake/build/bin/lean1090'), Path('.lake/build/bin/commbDifferential')]
    paths = set(map(Path, sources)) | {build, build.with_suffix('.log')} | set(binaries)
    for binary in binaries:
        paths.update([Path(str(binary) + '.rsp'), Path(str(binary) + '.trace')])
    for module in ('Impl/CommB', 'Impl/PayloadBits', 'Impl/Binary64', 'Impl/ScoreGate',
                   'Impl/JSON', 'Impl/Message', 'CLI/Main', 'Tests/CommBDifferential'):
        c = Path('.lake/build/ir/' + module + '.c')
        paths.update([c, Path(str(c) + '.o.export'), Path(str(c) + '.o.export.trace')])
    before = {str(path): {'sha256': sha(path), 'bytes': path.stat().st_size} for path in sorted(paths)}
    retained = {}
    for path in sorted(paths):
        if path in binaries or path.name.endswith('.o.export'):
            continue
        destination = OUT / 'retained' / path
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(path.read_bytes())
        retained[str(path)] = str(destination.relative_to(OUT))
    commands = []

    def command(argv, name):
        result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=False)
        (OUT / (name + '.txt')).write_bytes(result.stdout)
        (OUT / (name + '.stderr')).write_bytes(result.stderr)
        commands.append({'argv': argv, 'stdout': name + '.txt', 'stderr': name + '.stderr',
                         'exit_code': result.returncode})
        assert result.returncode == 0, argv
        return result.stdout.decode()

    for name, symbol in [('mach', P + 'cbMach64'), ('table-entry', P + 'cbMachValueTable___lam__0'),
                         ('table-initializer', '_init_' + P + 'cbMachValueTable___closed__1'),
                         ('module-initializer', 'initialize_lean1090_Impl_CommB'),
                         ('valid60', P + 'cbValid60'), ('penalty', P + 'cbPenalty'),
                         ('density-terms', P + 'cbDensityTerms'), ('score', P + 'cbScorePasses'),
                         ('decode-bds', P + 'decodeBDS'), ('main', 'main')]:
        command(['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + symbol,
                 str(binaries[0])], 'binary-' + name)
    command(['objdump', '-dr', '--no-show-raw-insn', '--disassemble=' + P + 'cbMach64',
             '.lake/build/ir/Impl/CommB.c.o.export'], 'object-mach')
    command(['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + P + 'cbMach64',
             str(binaries[1])], 'adapter-mach')
    command(['git', 'diff', 'HEAD', '--', 'Impl/CommB.lean'], 'runtime-diff')
    for binary in binaries:
        argv = ['nm', '-g', '--defined-only', str(binary)]
        result = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        assert result.returncode == 0
        relevant = '\n'.join(line for line in result.stdout.decode().splitlines()
                             if any(name in line for name in ('cbMach', 'cbValid60', 'cbPenalty', 'cbScorePasses',
                                                              'commBCoreEligible', 'decodeBDS', 'initialize_lean1090_Impl_CommB')))
        name = binary.name + '-symbols.txt'
        (OUT / name).write_text(relevant + '\n')
        commands.append({'argv': argv, 'exit_code': result.returncode, 'retained_filtered_stdout': name,
                         'complete_stdout_sha256': hashlib.sha256(result.stdout).hexdigest(),
                         'filter': 'Mach, validity, penalty, score, eligibility, decodeBDS and module initializer symbols'})
    for path, record in before.items():
        assert sha(path) == record['sha256'], path
    record = {'kind': 'static_compiled_structure_review_no_decoder_execution',
              'commit': subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip(),
              'successful_integrated_build': build_data, 'inputs': before, 'retained': retained,
              'commands': commands, 'all_captured_inputs_unchanged': True,
              'binary_scope': 'Current integration CLI and frozen Comm-B test adapter; not a fresh timed benchmark worker.',
              'limits': 'Read-only source/C/object/assembly inspection. No compiler, decoder, test, profiling or benchmark execution.'}
    (OUT / 'inspection-inputs.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({'status': 'captured', 'inputs': len(before), 'commands': len(commands),
                      'cli_sha256': before[str(binaries[0])]['sha256']}))


if __name__ == '__main__':
    main()

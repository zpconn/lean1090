#!/usr/bin/env python3
"""Capture already-built generation 6 artifacts; never execute native decoders."""
import hashlib
import json
from pathlib import Path
import subprocess

OUT = Path(__file__).resolve().parent
P = 'lp_lean1090_Lean1090_Impl_'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    assert not (OUT / 'inspection-inputs.json').exists()
    build = Path('tests/evidence/optimization/gen6/integration/targeted-build.json')
    build_data = json.loads(build.read_text())
    assert build_data['exit_code'] == 0 and sha(build.with_suffix('.log')) == build_data['log_sha256']
    binary = Path('.lake/build/bin/lean1090')
    sources = ['Impl/Message.lean', 'Impl/Frame.lean', 'Impl/Parity.lean', 'Impl/CommB.lean',
               'Impl/Semantics.lean', 'Impl/JSON.lean', 'CLI/Main.lean', 'Bench/WholeDecoder.lean',
               'Proofs/SyndromeReuse.lean', 'Proofs/Decoder.lean', 'Tests/Upstream.lean',
               'Tests/Tracking.lean', 'Tests/ReservedVelocityDifferential.lean',
               'Tests/AltitudeDifferential.lean', 'Tests/DTEDifferential.lean', 'Tests/UpstreamCorpus.lean',
               'TRUSTED.md', 'lakefile.toml', 'spec.lock']
    paths = set(map(Path, sources)) | {build, build.with_suffix('.log'), binary,
                                          Path(str(binary) + '.rsp'), Path(str(binary) + '.trace'),
                                          Path('bench/runs/gen5/fresh-native-inputs.json'),
                                          Path('tests/evidence/diagnostics/gen5/generated-c/Impl/Message.c')}
    for module in ('Impl/Message', 'Impl/Frame', 'Impl/Parity', 'Impl/CommB', 'Impl/Semantics', 'Impl/JSON', 'CLI/Main'):
        c = Path('.lake/build/ir/' + module + '.c')
        paths.update([c, Path(str(c) + '.o.export'), Path(str(c) + '.o.export.trace')])
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

    for symbol in ('decode', 'decodePrefix', 'frameSyndrome', 'frameAccepted', 'frameAcceptedWithSyndrome',
                   'frameAddress', 'frameAddressWithSyndrome', 'report', 'reportWithSyndrome', 'Parity_interrogator'):
        command(['objdump', '-d', '--no-show-raw-insn', '--disassemble=' + P + symbol, str(binary)], 'binary-' + symbol)
    command(['objdump', '-d', '--no-show-raw-insn', '--disassemble=lp_lean1090_Lean1090_CLI_runLine', str(binary)], 'binary-cli-runLine')
    command(['objdump', '-dr', '--no-show-raw-insn', '--disassemble=' + P + 'decode',
             '.lake/build/ir/Impl/Message.c.o.export'], 'object-decode')
    command(['nm', '-g', '--defined-only', str(binary)], 'binary-symbols')
    command(['git', 'diff', 'HEAD', '--', 'Impl/Message.lean'], 'runtime-diff')
    command(['git', 'diff', 'HEAD', '--name-only', '--', 'Impl'], 'runtime-changed-files')
    for path, row in before.items():
        assert sha(path) == row['sha256'], path
    record = {'kind': 'static_compiled_structure_review_no_decoder_execution',
              'commit': subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip(),
              'successful_integrated_build': build_data, 'inputs': before, 'retained': retained,
              'commands': commands, 'all_captured_inputs_unchanged': True,
              'binary_scope': 'Current integrated CLI. The future freshly built timed worker is not claimed inspected here.',
              'limits': 'Source, generated C, object and linked assembly inspection only. No build, decoder run, test campaign, profiler or benchmark.'}
    (OUT / 'inspection-inputs.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({'status': 'captured', 'inputs': len(before), 'commands': len(commands),
                      'cli_sha256': before[str(binary)]['sha256']}))


if __name__ == '__main__':
    main()

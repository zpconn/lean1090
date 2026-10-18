#!/usr/bin/env python3
"""Audit compiled import graphs of the runtime and frozen semantic modules.

The frozen semantic roots are Spec/, Model/, their aggregates, and Capstones.
They may directly import only Spec, Model, Mathlib, or Lean's Init/Std/Lean
libraries; Mathlib's transitive package dependencies are permitted. Neither
Impl nor Proofs may occur anywhere in their transitive closure. In particular,
a differently named local helper cannot hide an implementation dependency.

scripts/Final.lean is an import-free frozen declaration fragment. check_final.py
compiles it in a temporary wrapper that supplies the implementation/proof imports.
The fragment cannot itself import Impl, Proofs, or any other module.

FC004 freezes named differential adapters; FC005 adds tracking and upstream unit adapters. Those adapters may directly
import Impl in addition to the reference/platform imports, but never Proofs,
including transitively. FC006 also includes the frozen whole-decoder benchmark worker. This exception applies only to the exact adapter paths
below. It changes no Spec/Model/Capstones or proof-manifest import permission.
"""
from pathlib import Path
import os
import json
import shutil
from frozen_paths import frozen_paths
import subprocess
import tempfile


def project_modules(directory):
    paths = sorted(Path(directory).rglob('*.lean'))
    aggregate = Path(directory + '.lean')
    if aggregate.exists():
        paths.append(aggregate)
    return [str(path.with_suffix('')).replace('/', '.') for path in paths]


differential_adapters = [
    'Tests/AltitudeDifferential.lean', 'Tests/CommBDifferential.lean',
    'Tests/DTEDifferential.lean', 'Tests/ReservedVelocityDifferential.lean',
    'Tests/Numeric.lean', 'scripts/FuzzCPR.lean',
    'Tests/Tracking.lean', 'Tests/Upstream.lean', 'Tests/UpstreamCorpus.lean',
    'Bench/WholeDecoder.lean',
]
differential_modules = [str(Path(path).with_suffix('')).replace('/', '.')
                        for path in differential_adapters]

runtime = project_modules('Impl')
semantic = project_modules('Spec') + project_modules('Model') + ['Capstones']
if not runtime:
    raise SystemExit('FAIL: no implementation modules to audit')
subprocess.run(['lake', 'build', *sorted(set(runtime + semantic + differential_modules))], check=True)

runtime_check = r'''
open Lean Elab Command
run_elab do
  let env ← getEnv
  for name in env.header.moduleNames do
    if (`Spec).isPrefixOf name || (`Mathlib).isPrefixOf name then
      throwError "Impl transitively imports forbidden runtime module: {name}"
  logInfo "Impl transitive import audit: no Spec or Mathlib modules."
'''
semantic_check = r'''
open Lean Elab Command
private def frozenSemantic (name : Name) : Bool :=
  (`Spec).isPrefixOf name || (`Model).isPrefixOf name || name == `Capstones
private def permittedDirectImport (name : Name) : Bool :=
  [`Spec, `Model, `Mathlib, `Init, `Std, `Lean].any (·.isPrefixOf name)
private def differentialAdapter (filename : String) : Bool :=
  FROZEN_DIFFERENTIAL_LEAN_FILES.contains filename
private def permittedFrozenImport (filename : String) (name : Name) : Bool :=
  permittedDirectImport name || (differentialAdapter filename && (`Impl).isPrefixOf name)
run_elab do
  for filename in FROZEN_LEAN_FILES do
    let source ← IO.FS.readFile filename
    let (imports, _, messages) ← Lean.Elab.parseImports source (some filename)
    if messages.hasErrors then
      throwError "Frozen Lean source header does not parse: {filename}"
    for dependency in imports do
      if !permittedFrozenImport filename dependency.module then
        throwError "Frozen Lean source {filename} has forbidden direct import: {dependency.module}"
      if (filename == "scripts/Final.lean" || filename == "scripts/AuditBDS50.lean") &&
          dependency.module != `Init then
        throwError "Frozen proof manifest must be an import-free declaration fragment: {filename}"
  let env ← getEnv
  for name in env.header.moduleNames do
    if (`Impl).isPrefixOf name || (`Proofs).isPrefixOf name then
      throwError "Frozen semantic module transitively imports forbidden module: {name}"
  if env.header.modules.size != env.header.moduleData.size then
    throwError "Module graph metadata is incomplete"
  let mut checked : Nat := 0
  for (mod, data) in env.header.modules.zip env.header.moduleData do
    if frozenSemantic mod.module then
      checked := checked + 1
      for dependency in data.imports do
        if !permittedDirectImport dependency.module then
          throwError "Frozen semantic module {mod.module} has forbidden direct import: {dependency.module}"
  logInfo m!"Frozen semantic import audit: {checked} modules; direct imports only Spec, Model, Mathlib, Init, Std, Lean; no transitive Impl or Proofs."
'''

differential_check = r'''
open Lean Elab Command
run_elab do
  let env ← getEnv
  for name in env.header.moduleNames do
    if (`Proofs).isPrefixOf name then
      throwError "Frozen differential adapter transitively imports forbidden module: {name}"
  logInfo "Frozen differential adapter import audit: no transitive Proofs modules."
'''

semantic_check = semantic_check.replace('FROZEN_DIFFERENTIAL_LEAN_FILES',
                                        json.dumps(differential_adapters))
semantic_check = semantic_check.replace('FROZEN_LEAN_FILES', json.dumps(
    [str(path) for path in frozen_paths() if path.suffix == '.lean']))


def run_check(path, imports, body, env=None, expected_failure=None):
    path.write_text('\n'.join('import ' + module for module in imports) +
                    '\nimport Lean\n' + body)
    command = ([str(lean_executable), str(path)] if env is not None else
               ['lake', 'env', 'lean', str(path)])
    if expected_failure is None:
        subprocess.run(command, check=True, env=env)
    else:
        result = subprocess.run(command, text=True, capture_output=True, env=env)
        if result.returncode == 0 or expected_failure not in result.stdout + result.stderr:
            raise SystemExit('FAIL: import-audit negative self-test failed:\n' +
                             result.stdout + result.stderr)


with tempfile.TemporaryDirectory(prefix='lean1090-import-audit-') as temp:
    directory = Path(temp)
    check = directory / 'CheckImports.lean'
    run_check(check, runtime, runtime_check)
    run_check(check, semantic, semantic_check)
    # Adapters define separate executable entrypoints; inspect each compiled
    # environment independently rather than combining their main declarations.
    for module in differential_modules:
        run_check(check, [module], differential_check)

    # These test the compiled transitive graph, not text matching import lines.
    run_check(check, runtime + ['Spec'], runtime_check,
              expected_failure='Impl transitively imports forbidden runtime module')

    # A frozen Spec module must also reject an innocently named local helper,
    # even when that helper contains no forbidden import of its own.
    environment = os.environ.copy()
    lean_prefix = subprocess.run(['lake', 'env', 'lean', '--print-prefix'],
                                 text=True, capture_output=True, check=True).stdout.strip()
    lean_executable = Path(lean_prefix) / 'bin/lean'
    lean_path = subprocess.run(['lake', 'env', 'printenv', 'LEAN_PATH'],
                               text=True, capture_output=True, check=True).stdout.strip()
    environment['LEAN_PATH'] = str(directory) + os.pathsep + lean_path
    # Lean resolves a namespace from the first directory containing it. Mirror
    # existing namespace artifacts as symlinks so the temporary fixture does
    # not hide ordinary Spec/Proofs imports, and never alter project artifacts.
    for namespace in ('Spec', 'Proofs'):
        original = Path('.lake/build/lib/lean') / namespace
        if original.exists():
            shutil.copytree(original.resolve(), directory / namespace,
                            copy_function=os.symlink)
        for aggregate in original.parent.glob(namespace + '.*'):
            if aggregate.is_file():
                (directory / aggregate.name).symlink_to(aggregate.resolve())

    fixtures = [('GuardTrap.Helper', 'import Std\n'),
                ('Spec.GuardTrap', 'import GuardTrap.Helper\n'),
                ('Proofs.GuardTrap', 'import Std\n'),
                ('GuardTrap.RuntimeBridge', 'import Impl.BDS50\n'),
                ('Spec.DifferentialTrap', 'import Tests.AltitudeDifferential\n')]
    for name, source in fixtures:
        path = directory / (name.replace('.', '/') + '.lean')
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(source)
        subprocess.run([str(lean_executable), '--root=' + str(directory), '-o', str(path.with_suffix('.olean')), str(path)],
                       check=True, env=environment)
    run_check(check, semantic + ['Proofs.GuardTrap'], semantic_check, env=environment,
              expected_failure='Frozen semantic module transitively imports forbidden module: Proofs.GuardTrap')
    run_check(check, semantic + ['GuardTrap.RuntimeBridge'], semantic_check, env=environment,
              expected_failure='Frozen semantic module transitively imports forbidden module: Impl')
    run_check(check, semantic + ['Spec.GuardTrap'], semantic_check, env=environment,
              expected_failure='Frozen semantic module Spec.GuardTrap has forbidden direct import: GuardTrap.Helper')
    run_check(check, semantic + ['Spec.DifferentialTrap'], semantic_check, env=environment,
              expected_failure='Frozen semantic module transitively imports forbidden module: Impl')
    run_check(check, ['Tests.AltitudeDifferential', 'Proofs.GuardTrap'],
              differential_check, env=environment,
              expected_failure='Frozen differential adapter transitively imports forbidden module: Proofs.GuardTrap')

print(f'Import audit: {len(runtime)} runtime modules, {len(semantic)} frozen semantic modules; '
      f'{len(differential_modules)} frozen differential adapters; six rejection self-tests passed. '
      'Final.lean is an import-free declaration fragment.')

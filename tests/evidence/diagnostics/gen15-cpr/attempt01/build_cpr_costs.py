#!/usr/bin/env python3
"""Build only the untimed diagnostic driver, reusing unchanged native objects.

No Lake target or production/frozen source is modified. Commands and hashes are
retained so a profile can be tied to the exact production objects it executes.
This script does not run the resulting executable or any benchmark.

Prerequisite: the caller has freshly built the frozen worker from the committed
sources and retained that build's provenance. Source/HEAD and before/after hash
checks below establish association and immutability; they do not independently
prove that native artifacts were freshly compiled from those sources.
"""
import sys
sys.dont_write_bytecode = True
import argparse
import hashlib
import json
import os
import re
import shlex
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def command_from_trace(path):
    records = json.loads(path.read_text())["log"]
    commands = [record["message"][3:] for record in records
                if record["message"].startswith(".> ")]
    if len(commands) != 1:
        raise RuntimeError(f"expected exactly one command in {path}")
    return shlex.split(commands[0])


def response_quote(value):
    return '"' + value.replace('\\', '\\\\').replace('"', '\\"') + '"'


def replace_exact_paths(argv, replacements):
    for original in replacements:
        if argv.count(original) != 1:
            raise RuntimeError("expected exactly one native artifact argument: " + original)
    return [replacements.get(item, item) for item in argv]


def committed_source(root, commit, relative):
    result = subprocess.run(["git", "cat-file", "blob", f"{commit}:{relative}"],
                            cwd=root, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if result.returncode:
        raise RuntimeError(f"linked Lean source is not committed at {commit}: {relative}")
    return result.stdout


def discover_project_objects(root, response, read_committed):
    """Inspect the worker's actual object list without compiling or linking.

    Project objects may come only from Impl/Model, plus the one worker being
    replaced. System libraries/search paths remain exactly as the worker uses
    them. Explicit foreign objects, archives and nested response files fail.
    """
    root = root.resolve()
    ir = root / ".lake/build/ir"
    worker = ir / "Bench/WholeDecoder.c.o.export"
    if response.count(str(worker)) != 1:
        raise RuntimeError("benchmark response must contain exactly one worker object")
    objects, generated_c, sources, object_sources = {}, {}, {}, {}
    path_option = None
    for item in response:
        if item.startswith("@") or (item.startswith("-Wl,") and
                any(argument.startswith("@") for argument in item[4:].split(","))):
            raise RuntimeError("nested linker response files are not supported")
        if path_option is not None:
            if item.startswith("-"):
                raise RuntimeError(f"missing path after {path_option}")
            path_option = None
            continue
        if item in ("-L", "--sysroot"):
            path_option = item
            continue
        if item.startswith("-"):
            if re.search(r"\.(?:o(?:\.export)?|obj|a)(?:,|$)", item):
                raise RuntimeError("unexpected object/archive hidden in linker option: " + item)
            continue
        if not item.endswith(".c.o.export"):
            raise RuntimeError("unexpected explicit linker input: " + item)
        path = Path(os.path.abspath(root / item))
        try:
            relative_object = path.relative_to(ir)
        except ValueError as error:
            raise RuntimeError("external project object: " + item) from error
        module = relative_object.as_posix().removesuffix(".c.o.export")
        if module != "Bench/WholeDecoder" and not (
                module in ("Impl", "Model") or module.startswith(("Impl/", "Model/"))):
            raise RuntimeError("unexpected project module: " + module)
        source = root / (module + ".lean")
        cpath = Path(str(path).removesuffix(".o.export"))
        for candidate in (path, cpath, source):
            if not candidate.is_file() or candidate.resolve() != candidate:
                raise RuntimeError("missing or symlinked project input: " + str(candidate))
        key = str(path.relative_to(root))
        if key in objects:
            raise RuntimeError("duplicate linked project object: " + key)
        source_key = str(source.relative_to(root))
        source_bytes = source.read_bytes()
        if source_bytes != read_committed(source_key):
            raise RuntimeError("linked Lean source differs from committed HEAD: " + source_key)
        objects[key] = sha(path)
        generated_c[str(cpath.relative_to(root))] = sha(cpath)
        sources[source_key] = hashlib.sha256(source_bytes).hexdigest()
        object_sources[key] = source_key
    if path_option is not None:
        raise RuntimeError(f"missing path after {path_option}")
    if len(objects) < 2:
        raise RuntimeError("worker response has no reusable production/model objects")
    return {"objects": objects, "generated_c": generated_c,
            "sources": sources, "object_sources": object_sources,
            "worker_object": str(worker.relative_to(root))}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", default=".cache/gen15-cpr/driver")
    parser.add_argument("--fresh-native-inputs", type=Path,
                        help="fresh benchmark build inventory; require exact linked source/C/object association")
    args = parser.parse_args()
    output = (ROOT / args.output).resolve()
    output.relative_to(ROOT)
    output.mkdir(parents=True, exist_ok=True)
    source = ROOT / "review/diagnostics/CPRCosts.lean"
    generated = output / "CPRCosts.c"
    object_path = output / "CPRCosts.c.o"
    binary = output / "cpr-costs"
    response = output / "cpr-costs.rsp"
    original_response = ROOT / ".lake/build/bin/lean1090-bench.rsp"
    original_object = ROOT / ".lake/build/ir/Bench/WholeDecoder.c.o.export"
    original_c = ROOT / ".lake/build/ir/Bench/WholeDecoder.c"
    lock_before = sha(ROOT / "spec.lock")
    commit = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
    rsp = shlex.split(original_response.read_text())
    inventory = discover_project_objects(ROOT, rsp,
        lambda relative: committed_source(ROOT, commit, relative))
    original_hashes = {name: digest for name, digest in inventory["objects"].items()
                       if name != inventory["worker_object"]}
    production_objects = [ROOT / name for name in original_hashes]
    source_hashes = {str(path.relative_to(ROOT)): sha(path)
                     for path in sorted((ROOT / "Impl").rglob("*.lean"))}
    source_hashes["Impl.lean"] = sha(ROOT / "Impl.lean")
    source_hashes.update({name: digest for name, digest in inventory["sources"].items()
                          if name != "Bench/WholeDecoder.lean"})
    worker_compile_trace = Path(str(original_object) + ".trace")
    worker_link_trace = ROOT / ".lake/build/bin/lean1090-bench.trace"
    unchanged_inputs = {**inventory["objects"], **inventory["generated_c"],
                        **inventory["sources"], **source_hashes,
                        **{str(path.relative_to(ROOT)): sha(path) for path in
                           (original_response, worker_compile_trace, worker_link_trace, source)}}
    fresh_binding = None
    if args.fresh_native_inputs:
        fresh_path = (ROOT / args.fresh_native_inputs).resolve()
        fresh_name = str(fresh_path.relative_to(ROOT))
        fresh_bytes = fresh_path.read_bytes()
        fresh_rows = json.loads(fresh_bytes)
        fresh_sources, fresh_artifacts = {}, {}
        for row in fresh_rows:
            if row["source"] in fresh_sources:
                raise RuntimeError("duplicate source in fresh native inventory")
            fresh_sources[row["source"]] = row["source_sha256"]
            for name, item in row["artifacts"].items():
                if name in fresh_artifacts:
                    raise RuntimeError("duplicate artifact in fresh native inventory")
                fresh_artifacts[name] = item["sha256"]
        if fresh_sources != inventory["sources"]:
            raise RuntimeError("linked sources differ from fresh benchmark build inventory")
        fresh_objects = {name: digest for name, digest in fresh_artifacts.items() if name.endswith(".c.o.export")}
        fresh_c = {name: digest for name, digest in fresh_artifacts.items() if name.endswith(".c")}
        if fresh_objects != inventory["objects"] or fresh_c != inventory["generated_c"]:
            raise RuntimeError("linked objects/generated C differ from fresh benchmark build inventory")
        if any(sha(ROOT / name) != digest for name, digest in fresh_artifacts.items()):
            raise RuntimeError("fresh benchmark native artifact/trace changed")
        unchanged_inputs.update(fresh_artifacts)
        unchanged_inputs[fresh_name] = hashlib.sha256(fresh_bytes).hexdigest()
        (output / "fresh-native-inputs.json").write_bytes(fresh_bytes)
        fresh_binding = {"path": fresh_name, "sha256": unchanged_inputs[fresh_name],
                         "linked_project_objects": len(fresh_objects),
                         "sources_generated_c_objects_and_traces_match": True}
    compile_argv = command_from_trace(worker_compile_trace)
    link_argv = command_from_trace(worker_link_trace)
    original_compile_argv = compile_argv[:]
    original_link_argv = link_argv[:]
    compile_argv = replace_exact_paths(compile_argv,
        {str(original_object): str(object_path), str(original_c): str(generated)})
    if "-O3" not in compile_argv or "-ffp-contract=off" not in compile_argv:
        raise RuntimeError("missing baseline native flags")
    link_argv = replace_exact_paths(link_argv,
        {str(ROOT / ".lake/build/bin/lean1090-bench"): str(binary),
         "@" + str(original_response): "@" + str(response)})
    replaced = replace_exact_paths(rsp, {str(original_object): str(object_path)})
    commands = []

    def run(argv, label):
        commands.append({"label": label, "argv": argv})
        result = subprocess.run(argv, cwd=ROOT, text=True, stdout=subprocess.PIPE,
                                stderr=subprocess.STDOUT)
        (output / f"{label}.log").write_text(result.stdout)
        if result.returncode:
            raise RuntimeError(f"{label} failed ({result.returncode}); see {output / (label + '.log')}")

    run(["lake", "env", "lean", "-c", str(generated), str(source)], "driver-lean")
    run(compile_argv, "driver-clang")
    response.write_text("\n".join(map(response_quote, replaced)) + "\n")
    run(link_argv, "driver-link")
    run(["nm", "-g", str(binary)], "driver-symbols")
    after = {str(path.relative_to(ROOT)): sha(path) for path in production_objects}
    if after != original_hashes:
        raise RuntimeError("a reused production object changed during diagnostic build")
    if sha(ROOT / "spec.lock") != lock_before:
        raise RuntimeError("spec.lock changed during diagnostic build")
    if any(sha(ROOT / name) != digest for name, digest in source_hashes.items()):
        raise RuntimeError("a production source changed during diagnostic build")
    if any(sha(ROOT / name) != digest for name, digest in unchanged_inputs.items()):
        raise RuntimeError("a source, generated C, object, worker response or native trace changed during diagnostic build")
    if subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip() != commit:
        raise RuntimeError("HEAD changed during diagnostic build")
    symbols = (output / "driver-symbols.log").read_text()
    roots = ["lp_lean1090_Lean1090_Impl_decode", "lp_lean1090_Lean1090_Impl_CPR_Policy_streamStep",
             "lp_lean1090_Lean1090_Diagnostics_CPRCosts_runCPR"]
    if any(not any(line.endswith(" " + root) for line in symbols.splitlines()) for root in roots):
        raise RuntimeError("required unchanged production profiling root is missing")
    result = {
        "kind": "untimed_diagnostic_build", "status": "passed",
        "commit": commit,
        "lock_sha256": lock_before, "commands": commands, "collection_roots": roots,
        "reused_production_objects": original_hashes, "production_sources": source_hashes,
        "reused_production_object_count": len(production_objects),
        "linked_project_inventory": inventory,
        "linked_project_sources_equal_committed_head": True,
        "fresh_benchmark_native_binding": fresh_binding,
        "native_freshness_precondition": "Caller must supply a fresh committed-worker build and its retained source/object provenance; identity checks here do not independently establish freshness.",
        "unchanged_native_inputs": unchanged_inputs,
        "original_worker_compile_argv": original_compile_argv,
        "original_worker_link_argv": original_link_argv,
        "artifacts": {str(path.relative_to(ROOT)): sha(path)
                      for path in [source, Path(__file__).resolve(), generated, object_path, binary, response]},
        "original_response_sha256": sha(original_response),
        "notes": ["No production object was recompiled or changed.",
                  "The only replaced response-file entry is Bench/WholeDecoder.c.o.export.",
                  "The production/model object list is discovered from the actual worker response; no object count is fixed.",
                  "Every linked project object maps to an existing Lean source equal to the pinned HEAD blob, including Model and the worker.",
                  "Native compile/link flags are copied unchanged from the worker traces; only input/output artifact paths are substituted.",
                  "No Lake target, frozen source, benchmark or decoder optimization was changed."]}
    (output / "driver-build.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({"status": "passed", "binary": str(binary), "build_evidence": str(output / "driver-build.json")}))


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Build only the untimed diagnostic driver, reusing unchanged native objects.

No Lake target or production/frozen source is modified. Commands and hashes are
retained so a profile can be tied to the exact production objects it executes.
This script does not run the resulting executable or any benchmark.
"""
import argparse
import hashlib
import json
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


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", default=".cache/gen1-planning")
    args = parser.parse_args()
    output = (ROOT / args.output).resolve()
    output.relative_to(ROOT)
    output.mkdir(parents=True, exist_ok=True)
    source = ROOT / "review/diagnostics/DecodeCosts.lean"
    generated = output / "DecodeCosts.c"
    object_path = output / "DecodeCosts.c.o"
    binary = output / "decode-costs"
    response = output / "decode-costs.rsp"
    original_response = ROOT / ".lake/build/bin/lean1090-bench.rsp"
    original_object = ROOT / ".lake/build/ir/Bench/WholeDecoder.c.o.export"
    original_c = ROOT / ".lake/build/ir/Bench/WholeDecoder.c"
    lock_before = sha(ROOT / "spec.lock")
    rsp = shlex.split(original_response.read_text())
    if rsp.count(str(original_object)) != 1:
        raise RuntimeError("benchmark response must contain one worker object")
    production_objects = [Path(item) for item in rsp
                          if item.endswith(".o.export") and item != str(original_object)]
    if len(production_objects) != 20:
        raise RuntimeError("expected exactly 20 reused production/model objects")
    original_hashes = {str(path.relative_to(ROOT)): sha(path) for path in production_objects}
    source_hashes = {str(path.relative_to(ROOT)): sha(path)
                     for path in sorted((ROOT / "Impl").rglob("*.lean"))}
    source_hashes["Impl.lean"] = sha(ROOT / "Impl.lean")
    commands = []

    def run(argv, label):
        commands.append({"label": label, "argv": argv})
        result = subprocess.run(argv, cwd=ROOT, text=True, stdout=subprocess.PIPE,
                                stderr=subprocess.STDOUT)
        (output / f"{label}.log").write_text(result.stdout)
        if result.returncode:
            raise RuntimeError(f"{label} failed ({result.returncode}); see {output / (label + '.log')}")

    run(["lake", "env", "lean", "-c", str(generated), str(source)], "driver-lean")
    compile_argv = command_from_trace(Path(str(original_object) + ".trace"))
    if compile_argv.count(str(original_object)) != 1 or compile_argv.count(str(original_c)) != 1:
        raise RuntimeError("unexpected worker compile command")
    compile_argv = [str(object_path) if item == str(original_object)
                    else str(generated) if item == str(original_c) else item
                    for item in compile_argv]
    if "-O3" not in compile_argv or "-ffp-contract=off" not in compile_argv:
        raise RuntimeError("missing baseline native flags")
    run(compile_argv, "driver-clang")
    replaced = [str(object_path) if item == str(original_object) else item for item in rsp]
    response.write_text("\n".join(map(response_quote, replaced)) + "\n")
    link_argv = command_from_trace(ROOT / ".lake/build/bin/lean1090-bench.trace")
    original_binary = str(ROOT / ".lake/build/bin/lean1090-bench")
    original_rsp_arg = "@" + str(original_response)
    if link_argv.count(original_binary) != 1 or link_argv.count(original_rsp_arg) != 1:
        raise RuntimeError("unexpected worker link command")
    link_argv = [str(binary) if item == original_binary
                 else "@" + str(response) if item == original_rsp_arg else item
                 for item in link_argv]
    run(link_argv, "driver-link")
    run(["nm", "-g", str(binary)], "driver-symbols")
    after = {str(path.relative_to(ROOT)): sha(path) for path in production_objects}
    if after != original_hashes:
        raise RuntimeError("a reused production object changed during diagnostic build")
    if sha(ROOT / "spec.lock") != lock_before:
        raise RuntimeError("spec.lock changed during diagnostic build")
    if any(sha(ROOT / name) != digest for name, digest in source_hashes.items()):
        raise RuntimeError("a production source changed during diagnostic build")
    symbols = (output / "driver-symbols.log").read_text()
    roots = ["lp_lean1090_Lean1090_Impl_decode", "lp_lean1090_Lean1090_Impl_cbScorePasses",
             "lp_lean1090_Lean1090_Impl_commBCoreEligible"]
    if any(not any(line.endswith(" " + root) for line in symbols.splitlines()) for root in roots):
        raise RuntimeError("required unchanged production profiling root is missing")
    result = {
        "kind": "untimed_diagnostic_build", "status": "passed",
        "commit": subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
        "lock_sha256": lock_before, "commands": commands, "collection_roots": roots,
        "reused_production_objects": original_hashes, "production_sources": source_hashes,
        "artifacts": {str(path.relative_to(ROOT)): sha(path)
                      for path in [source, Path(__file__).resolve(), generated, object_path, binary, response]},
        "original_response_sha256": sha(original_response),
        "notes": ["No production object was recompiled or changed.",
                  "The only replaced response-file entry is Bench/WholeDecoder.c.o.export.",
                  "No Lake target, frozen source, benchmark or decoder optimization was changed."]}
    (output / "driver-build.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({"status": "passed", "binary": str(binary), "build_evidence": str(output / "driver-build.json")}))


if __name__ == "__main__":
    main()

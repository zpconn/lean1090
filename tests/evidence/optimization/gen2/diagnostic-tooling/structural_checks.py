#!/usr/bin/env python3
"""Exercise only diagnostic-builder parsing/guards; never invoke its main/build."""
import ast
import hashlib
import importlib.util
import json
import shlex
import subprocess
import sys
import tempfile
from datetime import datetime, timezone
from pathlib import Path

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[4]
BUILDER = ROOT / "review/diagnostics/build_decode_costs.py"
spec = importlib.util.spec_from_file_location("diagnostic_builder", BUILDER)
builder = importlib.util.module_from_spec(spec)
spec.loader.exec_module(builder)
checks = []


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def record(name, detail=None):
    checks.append({"name": name, "status": "passed", "detail": detail})


def reject(name, operation, reason):
    try:
        operation()
    except RuntimeError as error:
        assert reason in str(error), (name, str(error), reason)
        record(name, str(error).replace(str(FIXTURE), "<fixture>"))
    else:
        raise AssertionError("accepted invalid fixture: " + name)


with tempfile.TemporaryDirectory(prefix="lean1090-diagnostic-structure-") as temp:
    FIXTURE = Path(temp) / "project with spaces"
    FIXTURE.mkdir()
    blobs = {}

    def add(module):
        source = FIXTURE / (module + ".lean")
        cpath = FIXTURE / ".lake/build/ir" / (module + ".c")
        obj = Path(str(cpath) + ".o.export")
        for path in (source, cpath, obj):
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text("non-executable structural fixture: " + path.name + "\n")
        blobs[module + ".lean"] = source.read_bytes()
        return str(obj)

    def committed(relative):
        if relative not in blobs:
            raise RuntimeError("fixture source is not committed: " + relative)
        return blobs[relative]

    def discover(response):
        return builder.discover_project_objects(FIXTURE, response, committed)

    worker = add("Bench/WholeDecoder")
    model = add("Model/Types")
    core = add("Impl")
    response = [worker, model, core, "-L", "/system/lib", "--sysroot", "/system",
                "-Wl,--start-group", "-lInit", "-lleanrt", "-Wl,--end-group",
                "-Wl,--gc-sections", "-lm", "-pthread"]
    found = discover(response)
    assert len(found["objects"]) == 3
    assert found["sources"]["Model/Types.lean"] == sha(FIXTURE / "Model/Types.lean")
    assert found["object_sources"][".lake/build/ir/Model/Types.c.o.export"] == "Model/Types.lean"
    assert found["worker_object"] == ".lake/build/ir/Bench/WholeDecoder.c.o.export"
    assert len(found["generated_c"]) == len(found["sources"]) == 3
    record("two-production-objects-and-Model-provenance")

    additions = [add(f"Impl/Module{i}") for i in range(18)]
    twenty = discover(response + additions)
    assert len(twenty["objects"]) - 1 == 20
    record("twenty-production-objects")
    twenty_one = discover(response + additions + [add("Impl/ScoreGate")])
    assert len(twenty_one["objects"]) - 1 == 21
    assert "Impl/ScoreGate.lean" in twenty_one["sources"]
    record("twenty-one-production-objects-including-ScoreGate")

    quoted = "\n".join(map(builder.response_quote, response))
    assert shlex.split(quoted) == response
    assert discover(shlex.split(quoted)) == found
    record("response-path-with-spaces-roundtrip")

    reject("missing-worker", lambda: discover(response[1:]), "exactly one worker")
    reject("duplicate-worker", lambda: discover(response + [worker]), "exactly one worker")
    reject("no-production", lambda: discover([worker]), "no reusable")
    reject("duplicate-object", lambda: discover(response + [model]), "duplicate linked")
    alias = str(Path(model).parent) + "/./" + Path(model).name
    reject("canonical-duplicate-object", lambda: discover(response + [alias]), "duplicate linked")
    reject("external-object", lambda: discover(response + [str(FIXTURE / "outside.c.o.export")]), "external project")
    reject("unknown-Spec-module", lambda: discover(response + [add("Spec/Hidden")]), "unexpected project module")
    reject("unknown-Proofs-module", lambda: discover(response + [add("Proofs/Hidden")]), "unexpected project module")
    reject("bare-object", lambda: discover(response + ["/outside.o"]), "unexpected explicit")
    reject("bare-archive", lambda: discover(response + ["/outside.a"]), "unexpected explicit")
    reject("bare-shared-library", lambda: discover(response + ["/outside.so"]), "unexpected explicit")
    reject("nested-response", lambda: discover(response + ["@nested.rsp"]), "nested linker")
    reject("nested-linker-response", lambda: discover(response + ["-Wl,@nested.rsp"]), "nested linker")
    reject("nested-combined-linker-response", lambda: discover(response + ["-Wl,--start-group,@nested.rsp,--end-group"]), "nested linker")
    reject("nested-response-after-L", lambda: discover(response + ["-L", "@nested.rsp"]), "nested linker")
    reject("nested-response-after-sysroot", lambda: discover(response + ["--sysroot", "@nested.rsp"]), "nested linker")
    reject("embedded-object", lambda: discover(response + ["-Wl,--start-group,/outside.o,--end-group"]), "hidden in linker")
    reject("embedded-archive", lambda: discover(response + ["-Wl,/outside.a"]), "hidden in linker")
    reject("embedded-project-object", lambda: discover(response + ["-Wl," + model]), "hidden in linker")
    reject("missing-library-path", lambda: discover(response + ["-L"]), "missing path")
    reject("option-instead-of-library-path", lambda: discover(response + ["-L", "-lm"]), "missing path")
    reject("missing-sysroot", lambda: discover(response + ["--sysroot"]), "missing path")

    for kind, path in (("object", Path(model)),
                       ("generated-C", FIXTURE / ".lake/build/ir/Model/Types.c"),
                       ("source", FIXTURE / "Model/Types.lean")):
        saved = path.read_bytes()
        path.unlink()
        reject("missing-" + kind, lambda: discover(response), "missing or symlinked")
        path.write_bytes(saved)
        target = path.with_name(path.name + ".fixture-target")
        path.rename(target)
        path.symlink_to(target.name)
        reject("symlinked-" + kind, lambda: discover(response), "missing or symlinked")
        path.unlink()
        target.rename(path)

    source = FIXTURE / "Model/Types.lean"
    source.write_bytes(blobs["Model/Types.lean"] + b"-- changed\n")
    reject("dirty-linked-source", lambda: discover(response), "differs from committed HEAD")
    source.write_bytes(blobs["Model/Types.lean"])
    saved_blob = blobs.pop("Model/Types.lean")
    reject("uncommitted-linked-source", lambda: discover(response), "not committed")
    blobs["Model/Types.lean"] = saved_blob

    argv = ["clang", "-c", "-O3", "-ffp-contract=off", "-o", "old.o", "old.c", "-O3"]
    replaced = builder.replace_exact_paths(argv, {"old.o": "new.o", "old.c": "new.c"})
    assert replaced == ["clang", "-c", "-O3", "-ffp-contract=off", "-o", "new.o", "new.c", "-O3"]
    assert argv[-2] == "old.c"
    record("artifact-only-substitution-preserves-order-and-duplicate-flags")
    reject("missing-substitution-path", lambda: builder.replace_exact_paths(argv, {"absent": "new"}), "exactly one")
    reject("duplicate-substitution-path", lambda: builder.replace_exact_paths(argv + ["old.o"], {"old.o": "new.o"}), "exactly one")

    trace = FIXTURE / "trace.json"
    trace.write_text(json.dumps({"log": [{"message": ".> " + shlex.join(argv)}]}))
    assert builder.command_from_trace(trace) == argv
    record("native-trace-tokenization")
    trace.write_text(json.dumps({"log": []}))
    reject("missing-native-command", lambda: builder.command_from_trace(trace), "exactly one command")
    trace.write_text(json.dumps({"log": [{"message": ".> clang"}, {"message": ".> clang"}]}))
    reject("duplicate-native-command", lambda: builder.command_from_trace(trace), "exactly one command")

# Read native metadata as text only. Do not discover or inspect changing live
# production artifacts, and never invoke any command obtained from these traces.
original_rsp = ROOT / ".lake/build/bin/lean1090-bench.rsp"
original_obj = ROOT / ".lake/build/ir/Bench/WholeDecoder.c.o.export"
compile_trace = Path(str(original_obj) + ".trace")
link_trace = ROOT / ".lake/build/bin/lean1090-bench.trace"
metadata_before = {str(path.relative_to(ROOT)): sha(path)
                   for path in (original_rsp, compile_trace, link_trace)}
argv_compile = builder.command_from_trace(compile_trace)
argv_link = builder.command_from_trace(link_trace)
argv_rsp = shlex.split(original_rsp.read_text())
compile_map = {str(original_obj): "/diagnostic/DecodeCosts.c.o",
               str(ROOT / ".lake/build/ir/Bench/WholeDecoder.c"): "/diagnostic/DecodeCosts.c"}
link_map = {str(ROOT / ".lake/build/bin/lean1090-bench"): "/diagnostic/decode-costs",
            "@" + str(original_rsp): "@/diagnostic/decode-costs.rsp"}
rsp_map = {str(original_obj): "/diagnostic/DecodeCosts.c.o"}
substitution_evidence = {}
for label, argv, mapping, changed in (("compile", argv_compile, compile_map, 2),
                                      ("link", argv_link, link_map, 2),
                                      ("response", argv_rsp, rsp_map, 1)):
    replaced = builder.replace_exact_paths(argv, mapping)
    differences = [i for i, (before, after) in enumerate(zip(argv, replaced)) if before != after]
    assert len(argv) == len(replaced) and len(differences) == changed
    assert [item for item in argv if item not in mapping] == [item for item in replaced if item not in mapping.values()]
    assert shlex.split("\n".join(map(builder.response_quote, replaced))) == replaced
    substitution_evidence[label] = {"original_argv": argv, "substituted_argv": replaced,
                                    "changed_indices": differences,
                                    "all_other_tokens_unchanged": True}
    record("actual-worker-" + label + "-artifact-only-substitution")
assert "-O3" in argv_compile and "-ffp-contract=off" in argv_compile
assert all(sha(ROOT / name) == digest for name, digest in metadata_before.items())
record("actual-worker-metadata-unchanged-and-required-flags-retained")

head = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
assert builder.committed_source(ROOT, head, "Model/Types.lean") == (ROOT / "Model/Types.lean").read_bytes()
record("committed-blob-reader-on-Model")
reject("committed-blob-reader-missing-source", lambda: builder.committed_source(ROOT, head, "Model/__absent_structural_fixture__.lean"), "not committed")
ast.parse(BUILDER.read_text(), filename=str(BUILDER))
ast.parse(Path(__file__).read_text(), filename=__file__)
record("Python-syntax-without-bytecode")

result = {
    "kind": "pure_structural_diagnostic_tool_checks",
    "status": "passed", "utc": datetime.now(timezone.utc).isoformat(),
    "command": "python3 -B tests/evidence/optimization/gen2/diagnostic-tooling/structural_checks.py",
    "head_read_only": head,
    "builder_sha256": sha(BUILDER), "check_source_sha256": sha(Path(__file__)),
    "checks_passed": len(checks), "checks": checks,
    "read_only_native_metadata_sha256": metadata_before,
    "native_metadata_substitutions": substitution_evidence,
    "scope": "Temporary non-executable text fixtures, read-only git blob access, and token checks only. No builder main, Lean/compiler/linker, runtime test, profile, benchmark, staging or commit ran.",
    "freshness_limit": "Checks do not establish freshness of live native artifacts; a retained fresh committed-worker build is an external prerequisite of the builder.",
}
(HERE / "structural-results.json").write_text(json.dumps(result, indent=2) + "\n")
print(json.dumps({"status": "passed", "checks": len(checks), "evidence": str(HERE / "structural-results.json")}))

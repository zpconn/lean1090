#!/usr/bin/env python3
"""Inspect the built gen3 CLI without executing it; retain all outputs and hashes."""
import hashlib
import json
from pathlib import Path
import subprocess

OUT = Path(__file__).resolve().parent
ROOT = OUT.parents[4]
assert Path.cwd() == ROOT
BINARY = Path(".lake/build/bin/lean1090")
OBJECT = Path(".lake/build/ir/Impl/Parity.c.o.export")


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def retain(path, data):
    if path.exists():
        assert path.read_bytes() == data, "changed retained evidence: " + str(path)
    else:
        path.write_bytes(data)


inputs = [Path(name) for name in (
    "Impl/Parity.lean", "Impl/Message.lean", "lakefile.toml", "spec.lock",
    ".lake/build/ir/Impl/Parity.c", str(OBJECT),
    ".lake/build/ir/Impl/Parity.c.o.export.trace", ".lake/build/ir/Impl/Parity.c.hash",
    ".lake/build/lib/lean/Impl/Parity.trace", ".lake/build/bin/lean1090.rsp",
    ".lake/build/bin/lean1090.trace", str(BINARY))]
before = {str(path): {"sha256": sha(path), "bytes": path.stat().st_size} for path in inputs}
assert (OUT / "Parity.lean").read_bytes() == Path("Impl/Parity.lean").read_bytes()
copies = {
    ".lake/build/ir/Impl/Parity.c": "Parity.c",
    ".lake/build/ir/Impl/Parity.c.o.export.trace": "Parity.object.trace",
    ".lake/build/ir/Impl/Parity.c.hash": "Parity.c.hash",
    ".lake/build/lib/lean/Impl/Parity.trace": "Parity.module.trace",
    ".lake/build/bin/lean1090.rsp": "lean1090.rsp",
    ".lake/build/bin/lean1090.trace": "lean1090.trace",
}
for source, destination in copies.items():
    retain(OUT / destination, Path(source).read_bytes())
symbols = {
    "syndrome": "lp_lean1090_Lean1090_Impl_Parity_syndrome",
    "fold": "lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0",
    "cachedBit": "lp_lean1090_Lean1090_Impl_Parity_cachedBit",
    "wordBit": "lp_lean1090_Lean1090_Impl_Parity_wordBit",
    "checksum": "lp_lean1090_Lean1090_Impl_Parity_checksum",
}
commands = []
observations = {}
for label, symbol in symbols.items():
    observations[label] = {}
    for target, prefix in ((BINARY, "binary"), (OBJECT, "object")):
        argv = ["objdump", "-d", "--no-show-raw-insn", "--disassemble=" + symbol, str(target)]
        proc = subprocess.run(argv, text=True, capture_output=True)
        dest = OUT / (prefix + "-" + label + ".asm")
        retain(dest, proc.stdout.encode())
        retain(OUT / (prefix + "-" + label + ".stderr"), proc.stderr.encode())
        assert proc.returncode == 0
        present = "<" + symbol + ">:" in proc.stdout
        assert present or (prefix == "binary" and label in ("cachedBit", "wordBit"))
        observations[label][prefix + "_symbol_present"] = present
        commands.append({"argv": argv, "returncode": proc.returncode, "output": str(dest), "sha256": sha(dest)})
argv = ["nm", "--defined-only", str(BINARY)]
proc = subprocess.run(argv, text=True, capture_output=True)
assert proc.returncode == 0
filtered = "\n".join(line for line in proc.stdout.splitlines()
                     if "Impl_Parity_" in line or "l_Nat_testBit" in line) + "\n"
retain(OUT / "symbols.txt", filtered.encode())
commands.append({"argv": argv, "returncode": proc.returncode, "retained_filter": "Impl_Parity_ or l_Nat_testBit",
                 "output": str(OUT / "symbols.txt"), "sha256": sha(OUT / "symbols.txt")})
assert all(sha(Path(path)) == row["sha256"] for path, row in before.items())
result = {"status": "passed", "binary": str(BINARY), "binary_sha256": sha(BINARY),
          "inputs": before, "retained_files": copies, "commands": commands,
          "native_symbols": observations, "input_hashes_unchanged": True, "executed_binary": False,
          "discovery_note": "An initial inspection asserted all helper symbols survived linking and stopped at cachedBit. Its partial outputs remain byte-identical. Both inline helper definitions exist in the object; the linked loop contains their code while the unused out-of-line definitions are absent from the CLI symbol table."}
retain(OUT / "inspection-inputs.json", (json.dumps(result, indent=2) + "\n").encode())
print(json.dumps({"status": "passed", "binary_sha256": sha(BINARY), "disassemblies": 10,
                  "all_inputs_unchanged": True, "native_symbols": observations}))

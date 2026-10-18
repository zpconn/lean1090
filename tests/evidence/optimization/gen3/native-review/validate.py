#!/usr/bin/env python3
"""Check the retained compiled structure and its unchanged live input hashes."""
import hashlib
import json
from pathlib import Path

out = Path(__file__).resolve().parent
c = (out / "Parity.c").read_text()


def body(name, next_name):
    # The emitted declaration precedes the definition; select the latter.
    start = c.rindex("LEAN_EXPORT lean_object* " + name + "(")
    end = c.rindex("LEAN_EXPORT lean_object* " + next_name + "(")
    assert start < end and "){\n_start:" in c[start:end]
    return c[start:end]


fold_name = "lp_lean1090_List_foldl___at___00Lean1090_Impl_Parity_syndrome_spec__0"
setup_name = "lp_lean1090_Lean1090_Impl_Parity_syndrome"
fold = body(fold_name, fold_name + "___boxed")
setup = body(setup_name, setup_name + "___boxed")
fa = (out / "binary-fold.asm").read_text()
sa = (out / "binary-syndrome.asm").read_text()
rsp = (out / "lean1090.rsp").read_text()
checks = {
    "setup_two_word_conversions": setup.count("lean_uint64_of_nat(") == 2,
    "setup_one_nat_word_shift": setup.count("lean_nat_shiftr(") == 1,
    "setup_precedes_fold_call": setup.index("v_high_113_ = lean_uint64_of_nat") < setup.index("v___x_116_ = lp_lean1090_List_foldl"),
    "fold_two_direct_uint64_shifts": fold.count("lean_uint64_shift_right(") == 2,
    "fold_two_direct_masks": fold.count("lean_uint64_land(") == 2,
    "fold_original_nat_fallback": fold.count("l_Nat_testBit(") == 1,
    "fold_no_nat_word_shiftr": "lean_nat_shiftr" not in fold,
    "native_fold_machine_bit_test": "\tbt     %rax,%rcx" in fa and "\tsetb   %sil" in fa,
    "native_fold_original_nat_fallback": fa.count("<l_Nat_testBit>") == 2,
    "native_fold_no_big_word_shift": "lean_nat_big_shiftr" not in fa,
    "native_setup_big_shift": sa.count("<lean_nat_big_shiftr>") == 1,
    "link_section_gc": "--gc-sections" in rsp,
}
assert all(checks.values()), checks
inspection = json.loads((out / "inspection-inputs.json").read_text())
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
assert all(sha(Path(path)) == row["sha256"] for path, row in inspection["inputs"].items())
result = {
    "status": "passed", "checks": checks, "input_hashes_still_match": True,
    "files": {str(path.relative_to(out)): {"sha256": sha(path), "bytes": path.stat().st_size}
              for path in sorted(out.iterdir()) if path.is_file() and path.name != "review.json"},
    "scope": "Static generated-C/native inspection; no runtime execution, proof claim, profile or benchmark.",
    "checker_development_note": "The initial scratch slice matched a C prototype and raised ValueError before producing a result. This checker selects the definition and asserts its opening body marker; no source or expectation was changed.",
}
(out / "review.json").write_text(json.dumps(result, indent=2) + "\n")
print(json.dumps({"status": "passed", "checks": checks, "report_sha256": sha(out / "README.md"),
                  "review_sha256": sha(out / "review.json")}))

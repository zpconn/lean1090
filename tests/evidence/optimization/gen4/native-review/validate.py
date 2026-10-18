#!/usr/bin/env python3
"""Validate the retained gen4 compiled structure without executing a decoder."""
import difflib
import hashlib
import json
from pathlib import Path
import re
import subprocess

OUT = Path(__file__).resolve().parent
sha = lambda path: hashlib.sha256(Path(path).read_bytes()).hexdigest()
build = json.loads((OUT / "targeted-build-02.json").read_text())
assert build["exit_code"] == 0
assert sha(OUT / "targeted-build-02.log") == build["log_sha256"]
inspection = json.loads((OUT / "inspection-inputs.json").read_text())
inspection["build_exit_code"] = build["exit_code"]
inspection["build_log_sha256"] = build["log_sha256"]
(OUT / "inspection-inputs.json").write_text(json.dumps(inspection, indent=2) + "\n")

c = (OUT / "PayloadBits.c").read_text()
start = c.rindex("LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadBits(")
end = c.rindex("LEAN_EXPORT lean_object* lp_lean1090_Lean1090_Impl_payloadBits___boxed(")
body = c[start:end]
_, branches = body.split("if (v___x_26_ == 0)\n{", 1)
fallback, fast = branches.split("\nelse\n{", 1)
checks = {
    "integrated_build_passed": True,
    "width_guard_64": "lean_unsigned_to_nat(64u)" in body and "lean_nat_dec_lt(v_width_19_, v___x_25_)" in body,
    "fallback_two_nat_powers": fallback.count("lean_nat_pow(") == 2,
    "fallback_nat_div_mod": fallback.count("lean_nat_div(") == fallback.count("lean_nat_mod(") == 1,
    "fast_has_no_nat_pow_div_mod": not any(name in fast for name in ("lean_nat_pow", "lean_nat_div", "lean_nat_mod")),
    "fast_machine_shifts_and_mask": all(name in fast for name in ("lean_uint64_shift_right", "lean_uint64_shift_left", "lean_uint64_land", "lean_uint64_to_nat")),
    "inline_helper_not_called_from_payloadBits": "lp_lean1090_Lean1090_Impl_payloadWordBits(" not in body,
    "new_theorem_names_erased_from_C": not any(name in c for name in ("payloadWordMask_toNat", "payloadBits_lt")),
}
assembly = (OUT / "binary-payloadBits.asm").read_text()
checks["native_shifts_mask_and_nat_tag"] = all(text in assembly for text in (
    "shr    %cl,%r14", "shl    %cl,%rax", "not    %rax", "and    %rax,%r14", "lea    0x1(,%r14,2),%rax"))
checks["native_two_pow_calls_and_big_fallback"] = assembly.count("<lean_nat_pow>") == 2 and all(
    name in assembly for name in ("<lean_nat_big_div>", "<lean_nat_big_mod>"))

old_source = subprocess.check_output(["git", "show", "HEAD:Impl/CommB.lean"], text=True)
new_source = (OUT / "CommB.lean").read_text()
replacements = [
    ("(standardThreatRange ⟨payloadBits word 44 7, Nat.mod_lt _ (by decide)⟩)",
     "(standardThreatRange ⟨payloadBits word 44 7, payloadBits_lt word 44 7⟩)"),
    ("(standardThreatBearing ⟨payloadBits word 51 6, Nat.mod_lt _ (by decide)⟩)",
     "(standardThreatBearing ⟨payloadBits word 51 6, payloadBits_lt word 51 6⟩)"),
    ("exact Nat.mod_lt _ (Nat.two_pow_pos width)", "exact payloadBits_lt word start width"),
]
expected = old_source
for old, new in replacements:
    assert expected.count(old) == 1
    expected = expected.replace(old, new)
checks["CommB_source_exactly_three_proof_substitutions"] = expected == new_source

old_c_path = Path("tests/evidence/diagnostics/gen3/generated-c/Impl/CommB.c")
old_c, new_c = old_c_path.read_text(), (OUT / "CommB.c").read_text()
(OUT / "CommB.gen3.c").write_text(old_c)
(OUT / "CommB.generated.diff").write_text("".join(difflib.unified_diff(
    old_c.splitlines(keepends=True), new_c.splitlines(keepends=True),
    fromfile="gen3/CommB.c", tofile="gen4/CommB.c")))
renamed = re.sub(r"\bv___y_1479_\b|\bv___y_1480_\b",
                 lambda m: "v___y_1480_" if m[0] == "v___y_1479_" else "v___y_1479_", old_c)


def normalize_declaration_order(text):
    lines = []
    count = 0
    for line in text.splitlines(keepends=True):
        if "lean_object* v___y_1479_;" in line and "lean_object* v___y_1480_;" in line:
            declarations = [part.strip() for part in line.split(";") if part.strip()]
            assert all(re.fullmatch(r"(?:lean_object\*|uint8_t) v_\w+", part) for part in declarations)
            line = "; ".join(sorted(declarations)) + ";\n"
            count += 1
        lines.append(line)
    assert count == 1
    return "".join(lines)


# These are side-effect-free copies into distinct local variables; neither
# right-hand side references either destination. Their order is immaterial.
pair_before = "v___y_1480_ = v_val_1493_;\nv___y_1479_ = v___y_1487_;\n"
pair_after = "v___y_1479_ = v___y_1487_;\nv___y_1480_ = v_val_1493_;\n"
assert renamed.count(pair_before) == 2
normalized_old = normalize_declaration_order(renamed.replace(pair_before, pair_after))
normalized_new = normalize_declaration_order(new_c)
checks["CommB_C_equal_after_exact_local_rename_and_independent_copy_reordering"] = normalized_old == normalized_new
(OUT / "CommB.gen3.normalized.c").write_text(normalized_old)
(OUT / "CommB.gen4.normalized.c").write_text(normalized_new)
old_native = next(row for row in json.loads((OUT / "fresh-native-inputs.json").read_text())
                  if row["source"] == "Impl/CommB.lean")
commb_object = ".lake/build/ir/Impl/CommB.c.o.export"
commb_object_same = sha(commb_object) == old_native["artifacts"][commb_object]["sha256"]
for name in ("TRUSTED.md", "lakefile.toml", "spec.lock"):
    old = subprocess.check_output(["git", "show", "HEAD:" + name])
    checks[name + "_unchanged_from_HEAD"] = old == Path(name).read_bytes()
checks["no_new_ffi_override_annotations_in_runtime_diff"] = not any(
    token in (OUT / "PayloadBits.source.diff").read_text() + (OUT / "CommB.source.diff").read_text()
    for token in ("@[extern", "@[implemented_by"))
assert all(checks.values()), checks
assert all(sha(path) == row["sha256"] for path, row in inspection["inputs"].items())
result = {
    "status": "passed", "checks": checks, "all_captured_inputs_unchanged": True,
    "CommB_generated_C_byte_identical_to_gen3": old_c == new_c,
    "CommB_object_byte_identical_to_gen3": commb_object_same,
    "CommB_normalization": "Swap local names 1479/1480, reorder their two pure declarations, and commute two pairs of independent pointer-value assignments; all other C bytes match.",
    "scope": "Compiled-structure inspection only; no decoder execution, timing, profile or additional build.",
    "files": {str(path.relative_to(OUT)): {"sha256": sha(path), "bytes": path.stat().st_size}
              for path in sorted(OUT.iterdir()) if path.is_file() and path.name != "review.json"},
}
(OUT / "review.json").write_text(json.dumps(result, indent=2) + "\n")
print(json.dumps({"status": "passed", "checks": checks, "CommB_object_unchanged": commb_object_same,
                  "review_sha256": sha(OUT / "review.json")}))

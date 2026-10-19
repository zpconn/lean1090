#!/usr/bin/env python3
"""Read-only comparison of fresh campaign preparation; never imports its helpers."""
import sys
sys.dont_write_bytecode = True
import ast, datetime, hashlib, json
from pathlib import Path
P = Path("tests/evidence/optimization/gen19")
OLD = Path("tests/evidence/optimization/gen18/fresh")
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
prep = json.loads((P / "preparation.json").read_text())
bindings = {str(P / "preparation.json"): sha(P / "preparation.json")}
checks = []
for name, row in prep["helpers"].items():
    new = Path(name)
    old = Path(row["reused_from"])
    assert sha(new) == row["sha256"] and sha(old) == row["prior_sha256"]
    text = old.read_text().replace("gen18/fresh", "gen19").replace("gen18", "gen19").replace("115", "117")
    if new.name == "fresh-orchestrate.py":
        text = text.replace("p.parent/'integration/", "p/'integration/")
    if new.name == "fresh-run-campaign.py":
        text = text.replace("gen17/fresh-message-run.json", "gen18/fresh/fresh-message-run.json")
    assert text == new.read_text(), name
    ast.parse(new.read_text())
    bindings[str(new)] = sha(new)
    bindings[str(old)] = sha(old)
    checks.append(new.name + ": exact path/source-count-only adaptation")
preparer = P / "prepare_preflight.py"
assert sha(preparer) == prep["preflight_preparer_sha256"]
ast.parse(preparer.read_text())
bindings[str(preparer)] = sha(preparer)
controller = ast.parse((P / "fresh-orchestrate.py").read_text())
membership = next(ast.literal_eval(n.value) for n in controller.body if isinstance(n, ast.Assign) and any(isinstance(x, ast.Name) and x.id == "EXPECTED_RETENTION" for x in n.targets))
assert len(membership) == len(set(membership)) == 33
assert all(".." not in Path(x).parts and not Path(x).is_absolute() for x in membership)
assert prep["expected_fresh_source_count"] == 117 and prep["expected_gate_input_count"] == 192 and prep["expected_binaries"] == 3
for name, h in prep["history_bindings"].items():
    assert sha(name) == h
    bindings[name] = h
assert sha(prep["source_inventory_prior"]["path"]) == prep["source_inventory_prior"]["sha256"]
bindings[prep["source_inventory_prior"]["path"]] = prep["source_inventory_prior"]["sha256"]
for name in ["fresh-seeds.json", "fresh-preflight.json", "fresh-execution.json", "fresh-message-run.json"]:
    assert not (P / name).exists(), name
assert not list((P / "fresh-message").glob("*"))
checks += [
    "Exact 33 success members and three diagnostic-stream EOF/hash/cardinality checks unchanged.",
    "Preflight requires explicit release text, independent preparation review, passed combined build, exact 192 build/gate hashes and matching three binary hashes before sampling seeds.",
    "Preflight derives the complete 117-source inventory and binds frozen generator hashes through the retained seed history; new seeds reject prior and mutual collisions.",
    "Shared cache may contain fixed-gate outputs, but both selected fresh fixture paths must be absent before generation; no overwrite or directory-wide deletion.",
    "Current conventional path is covered by the unchanged root ignore rule; preflight executes git check-ignore before seeding.",
    "Orchestrator retains all existing raw compression/decompression checks and rechecks current sources/binaries after comparison and retention.",
    "No seed, build, fixture, decoder, comparison, campaign or cleanup execution by this review."
]
result = dict(status="passed_read_only_preparation_review", recorded_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(), checker_sha256=sha(__file__), bindings=bindings, checks=checks, exact_retention_members=len(membership), expected_source_count=117, expected_gate_input_count=192, expected_binary_count=3, seeds_sampled=False, findings=[])
out=P / "independent-review/preparation-review.json"
assert not out.exists()
out.write_text(json.dumps(result, indent=2) + "\n")
print(json.dumps(dict(status=result["status"], checks=len(checks), sha256=sha(out))))

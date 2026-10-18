#!/usr/bin/env python3
"""Retain and apply the independent review's profile-boundary wording fix."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


root = Path(__file__).resolve().parents[4]
assert Path.cwd() == root
evidence = Path("tests/evidence/diagnostics/gen2")
revision = evidence / "report-revision"
assert not revision.exists(), "revision already retained"
revision.mkdir()
report = Path("docs/GEN2-COST-BREAKDOWN.md")
tool = Path("review/diagnostics/write_cost_report.py")
validation = evidence / "validation.json"
before = report.read_text()
before_tool = tool.read_text()
old = "Not observed as a native symbol"
new = "Not observed in collected call contexts"
assert before.count(old) == 6 and before_tool.count(old) == 1
(revision / "before.md").write_bytes(report.read_bytes())
(revision / "before-tool.py").write_bytes(tool.read_bytes())
(revision / "before-validation.json").write_bytes(validation.read_bytes())
tool.write_text(before_tool.replace(old, new))
commands = json.loads((evidence / "finalization-commands.json").read_text())
argv = next(row["argv"] for row in commands if row["label"] == "report")
assert argv[-2:] == ["--output", str(report)]
argv[-1] = str(revision / "rendered.md")
proc = subprocess.run(argv, capture_output=True, text=True)
(revision / "render.stdout").write_text(proc.stdout)
(revision / "render.stderr").write_text(proc.stderr)
assert proc.returncode == 0, proc.stderr
after = (revision / "rendered.md").read_text()
assert after == before.replace(old, new), "unexpected report change"
report.write_text(after)
(revision / "after-tool.py").write_bytes(tool.read_bytes())
result = json.loads(validation.read_text())
assert result["report_sha256"] == sha(revision / "before.md")
result["report_sha256"] = sha(report)
result["review_wording_revision"] = str(revision / "revision.json")
validation.write_text(json.dumps(result, indent=2) + "\n")
manifest = json.loads((evidence / "archive-manifest.json").read_text())
assert all(sha(evidence / name) == row["stored_sha256"] for name, row in manifest["files"].items())
campaign = json.loads((evidence / "campaign.json").read_text())
assert all(sha(Path(name)) == digest for name, digest in campaign["protected_inputs"].items())
metadata = {
    "kind": "independent-review-wording-only-revision", "status": "passed",
    "reason": "Distinguish absence from collected call contexts from absence of a native binary symbol.",
    "old_phrase": old, "new_phrase": new, "report_replacements": before.count(old),
    "argv": argv, "returncode": proc.returncode, "numerical_tables_unchanged": True,
    "primary_archive_unchanged": True, "protected_inputs_unchanged": True,
    "report_before_sha256": sha(revision / "before.md"), "report_after_sha256": sha(report),
    "tool_before_sha256": sha(revision / "before-tool.py"), "tool_after_sha256": sha(tool),
    "revision_script_sha256": sha(Path(__file__)),
    "files": {str(path.relative_to(revision)): {"sha256": sha(path), "bytes": path.stat().st_size}
              for path in sorted(revision.iterdir()) if path.is_file()},
}
(revision / "revision.json").write_text(json.dumps(metadata, indent=2) + "\n")
print(json.dumps(metadata))

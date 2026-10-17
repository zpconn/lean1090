#!/usr/bin/env python3
"""Copy exact source spans for the review dependency graph, never frozen files.

Run `lake env lean scripts/review_dependencies.lean` first. Lean's elaborated
environment supplies dependency edges and declaration source positions. This
script does not infer dependencies from the source spelling.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "docs/REVIEW-DEFS.lean"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="verify exact regeneration")
    args = parser.parse_args()
    graph = json.loads((ROOT / ".cache/review-dependencies.json").read_text())
    entries = {d["name"]: d for d in graph["declarations"]}
    local = {n: d for n, d in entries.items() if d["projectLocal"]}
    lean_prefix = Path(subprocess.check_output(["lean", "--print-prefix"], cwd=ROOT, text=True).strip())

    def source_path(d: dict) -> Path:
        relative = Path(*d["module"].split(".")).with_suffix(".lean")
        if d["projectLocal"]:
            return ROOT / relative
        if d["module"].startswith("Mathlib."):
            return ROOT / ".lake/packages/mathlib" / relative
        return lean_prefix / "src/lean" / relative

    def display_path(path: Path) -> str:
        try:
            return str(path.relative_to(ROOT))
        except ValueError:
            return str(path)

    def span(d: dict) -> tuple[int, int, int, int]:
        r = d["range"]
        return r["line"], r["column"], r["endLine"], r["endColumn"]

    def contains(outer: dict, inner: dict) -> bool:
        if outer["module"] != inner["module"]:
            return False
        a, b, c, e = span(outer)
        f, g, h, i = span(inner)
        return (a, b) <= (f, g) and (h, i) <= (c, e)

    # Constructors, projections, derived instances, and compiler-generated
    # match/recursion/proof auxiliaries are represented by their actual parent
    # source command. They have no separately authored source declaration.
    ranged = [d for d in local.values() if d["range"]]
    ranged += [d["sourceParent"] for d in local.values() if d["sourceParent"]]
    owners = {}
    for name, d in local.items():
        candidate = d if d["range"] else d["sourceParent"]
        containers = [x for x in ranged if contains(x, candidate)]
        # The containing source command (e.g. full inductive declaration) is
        # more useful than a constructor or `deriving DecidableEq` token.
        owner = min(containers, key=lambda x: (span(x)[:2], tuple(-k for k in span(x)[2:]), x["name"]))
        owners[name] = owner

    unique = {}
    for owner in owners.values():
        unique[(owner["module"], span(owner))] = owner
    blocks = []
    used = set()
    for name in graph["roots"]:
        owner = owners[name]
        key = owner["module"], span(owner)
        if key not in used:
            blocks.append(("REQUESTED", owner))
            used.add(key)
    for key, owner in sorted(unique.items()):
        if key not in used:
            blocks.append(("DEPENDENCY", owner))
            used.add(key)
    project_block_count = len(blocks)
    for name in graph["libraryRoots"]:
        d = entries[name]
        if not d["range"]:
            raise RuntimeError(f"No library source for {name}")
        blocks.append(("LIBRARY SEMANTICS", d))

    texts: dict[Path, list[str]] = {}

    def file_lines(path: Path) -> list[str]:
        if path not in texts:
            texts[path] = path.read_text().splitlines(keepends=True)
        return texts[path]

    def source(d: dict) -> str:
        lines = file_lines(source_path(d))
        a, b, c, e = span(d)
        if a == c:
            return lines[a - 1][b:e]
        return lines[a - 1][b:] + "".join(lines[a:c - 1]) + lines[c - 1][:e]

    def definition_line(d: dict) -> int:
        a, _, _, _ = span(d)
        for offset, line in enumerate(source(d).splitlines()):
            if re.match(r"\s*(?:(?:noncomputable|private|protected|opaque|unsafe)\s+)*(?:def|abbrev|structure|inductive|class|theorem|lemma|instance)\b", line):
                return a + offset
        return a

    def context(d: dict) -> str:
        # Source context is informational; exact snippets remain unmodified.
        before = file_lines(source_path(d))[:span(d)[0] - 1]
        imports = [line.strip() for line in before if re.match(r"(?:public )?import ", line)]
        opened = [line.strip() for line in before if re.match(r"open |open scoped ", line)]
        scopes = []
        for line in before:
            match = re.match(r"^(namespace|section)\b\s*(\S*)", line)
            if match:
                scopes.append((match[1], match[2]))
            elif re.match(r"^end(?:\s|$)", line) and scopes:
                scopes.pop()
        namespace = ".".join(name for kind, name in scopes if kind == "namespace")
        return "\n".join([f"namespace {namespace or '<root>'}"] + imports + list(dict.fromkeys(opened)))

    roots_text = "\n".join(f"  {n}: {display_path(source_path(owners[n]))}:{definition_line(owners[n])}" for n in graph["roots"])
    output = [f"""/-!
REVIEW ONLY — NOT FROZEN; no executable declarations in this file.

The source below is copied verbatim from the pinned checkout. Every block names
the fully qualified declaration, original file/definition line, and exact source
span (one-based lines, zero-based columns, exclusive end). Original docstrings
are preserved. These are excerpts in original namespace/file context, enclosed
in comments to avoid redefining or importing the frozen specification.

Requested definitions ({len(graph['roots'])}):
{roots_text}

Completeness method:
  lake env lean scripts/review_dependencies.lean
  python3 scripts/write_review_defs.py
  python3 scripts/write_review_defs.py --check

The exporter follows every constant in elaborated declaration TYPES and BODIES,
including opaque bodies, recursively through all Spec/ and Model/ modules.
It found {len(local)} project-local constants. All are mapped in the appendix to
{project_block_count} exact authored source commands. Plain field accessors occur
inside their containing structures and need no separate snippet. Generated
constructors, recursors, pattern-match helpers, derived instances and proof
auxiliaries are mapped to the source command that generates them. No semantic
project-local helper is omitted. The raw graph is .cache/review-dependencies.json.

Library boundary: generic Lean/Std/Mathlib declarations are not recursively
expanded into the entire theorem-prover implementation. All {len([d for d in entries.values() if not d['projectLocal'] and d['name'] not in set(graph['libraryRoots'])]) + len(set(graph['libraryRoots']) & set(n for n in entries if not entries[n]['projectLocal']))} encountered/supplemented
library constants are listed by module and source location in the appendix;
{len(graph['libraryRoots'])} relevant mathematical primitives (including actual
polynomial division, real inverse trig and rational floor) are copied as well.
Their own library dependencies remain at this explicit library boundary.

This file records current definitions, not a proof that their hypotheses are
realistic, their capstones proved, or their formulas faithful to the standard.
-/
"""]
    block_ids = {}
    for index, (kind, d) in enumerate(blocks, 1):
        key = d["module"], span(d)
        block_ids[key] = index
        a, b, c, e = span(d)
        path = display_path(source_path(d))
        raw = source(d)
        # Nested Lean comments preserve the source byte-for-byte as a substring.
        output.append(f"\n/- REVIEW BLOCK {index:03d} — {kind}\nDeclaration: {d['name']}\nSource: {path}:{definition_line(d)}\nSource span: {a}:{b}–{c}:{e}\nOriginal module: {d['module']}\nOriginal imports/opens:\n{context(d)}\nBEGIN EXACT SOURCE\n{raw}\nEND EXACT SOURCE\n-/\n")

    output.append("\n/- PROJECT DEPENDENCY COVERAGE\nEvery elaborated project constant, including generated constants, appears here.\n")
    for name, d in sorted(local.items()):
        owner = owners[name]
        index = block_ids[(owner["module"], span(owner))]
        tag = " [plain field accessor]" if d["projection"] else ""
        if not d["range"]:
            tag += " [compiler-generated; parent source]"
        path = display_path(source_path(owner))
        line = d["range"]["line"] if d["range"] else definition_line(owner)
        output.append(f"{name} -> block {index:03d}; {path}:{line}{tag}\n")
    output.append("-/\n\n/- LIBRARY BOUNDARY\n")
    for name, d in sorted(entries.items()):
        if d["projectLocal"]:
            continue
        path = display_path(source_path(d))
        location = f"{path}:{d['range']['line']}" if d["range"] else f"{path} (generated declaration)"
        tag = " [plain field accessor]" if d["projection"] else ""
        output.append(f"{name}: {location}{tag}\n")
    output.append("-/\n\n/- SOURCE FILE SHA-256\n")
    for path in sorted(texts, key=display_path):
        output.append(f"{hashlib.sha256(path.read_bytes()).hexdigest()}  {display_path(path)}\n")
    output.append("-/\n")
    result = "".join(output)
    if args.check:
        if OUTPUT.read_text() != result:
            raise SystemExit("Review source verification FAILED: artifact differs from exact regeneration")
        print(f"Review source verification: {len(graph['roots'])} requested roots, {len(local)} project constants, {project_block_count} source blocks, {len(graph['libraryRoots'])} library excerpts; all copied spans match.")
    else:
        OUTPUT.write_text(result)
        print(f"Wrote {OUTPUT.relative_to(ROOT)}: {len(result.splitlines())} lines, {project_block_count} project source blocks and {len(graph['libraryRoots'])} library excerpts.")


if __name__ == "__main__":
    main()

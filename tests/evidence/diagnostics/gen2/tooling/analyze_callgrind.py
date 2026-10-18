#!/usr/bin/env python3
"""Attribute *diagnostic* Callgrind events from the unchanged native decoder.

This does not estimate elapsed time or produce a benchmark result. Every event
is counted exactly once using function self costs, never by summing inclusive
subtrees. Runtime/Rat/GMP costs inherit the stage of their callers. Contexts
merged across stages by Callgrind remain explicitly ambiguous. Register score
probes are supplemental and overlap the whole-decoder costs; they are not added
to them. No cost is distributed in proportion to message or call counts.

Example:
  python3 review/diagnostics/analyze_callgrind.py \
    --profile adsb=path/to/adsb.callgrind \
    --profile commb=path/to/commb.callgrind \
    --profile other=path/to/other.callgrind \
    --score 50=path/to/score50.callgrind --output path/to/analysis
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict, deque
from dataclasses import dataclass, field
import gzip
import hashlib
import json
from pathlib import Path
import re
import sys
import tempfile


PREFIX = "lp_lean1090_Lean1090_Impl_"
DECODE = PREFIX + "decode"
SCORE = PREFIX + "cbScorePasses"
CANDIDATE = PREFIX + "commBCoreEligible"
OPTIONAL_SCORE_ANCHORS = {
    PREFIX + name for name in (
        "cbDensityTermsFast", "cbDensityTableGet", "cbDensityTerms",
        "ScoreGate_mass", "ScoreGate_center", "ScoreGate_envelope", "ScoreGate_choose")
}
STAGES = (
    "frame_crc",
    "adsb_fields",
    "commb_inference",
    "semantic_oracle_values",
    "output_model_control",
)
DESCRIPTIONS = {
    "frame_crc": "Wire frame parsing, parity/CRC, address recovery and frame acceptance control",
    "adsb_fields": "ADS-B layout/field decoding and ADS-B hard-validity checks",
    "commb_inference": "Comm-B candidates, hard checks, score gates and accepted raw-field records",
    "semantic_oracle_values": "Standard/oracle quantities, labels and numeric-expression construction",
    "output_model_control": "Message/report construction and residual decoder control/reference management",
}


@dataclass
class Node:
    name: str
    objects: set[str] = field(default_factory=set)
    files: set[str] = field(default_factory=set)
    own: Counter = field(default_factory=Counter)
    calls: Counter = field(default_factory=Counter)
    edges: dict[str, Counter] = field(default_factory=lambda: defaultdict(Counter))


@dataclass
class Profile:
    path: Path
    events: list[str]
    nodes: dict[str, Node]
    summary: Counter
    metadata: dict


def parse(path: Path) -> Profile:
    """Read Callgrind cost records, including compressed names and positions.

    Function names already include Callgrind's context suffix when
    --separate-callers is enabled. IDs compress names; they are not node IDs.
    Inline-file changes remain attached to the same function/context. Object
    collisions with nonempty costs fail rather than silently merge libraries.
    Position values are not needed for event aggregation; their field count is.
    """
    symbols = {kind: {} for kind in ("fn", "fl", "ob")}
    events: list[str] = []
    positions = ["line"]
    nodes: dict[str, Node] = {}
    metadata: dict = {}
    summary: Counter = Counter()
    totals: Counter | None = None
    current: str | None = None
    current_object = "???"
    current_file = "???"
    called: str | None = None
    called_object: str | None = None
    called_file: str | None = None
    pending_calls: int | None = None

    def expand(kind: str, value: str) -> str:
        match = re.fullmatch(r"\((\d+)\)(?: (.*))?", value)
        if not match:
            return value
        ident, spelling = match.groups()
        if spelling is not None:
            previous = symbols[kind].setdefault(ident, spelling)
            if previous != spelling:
                raise ValueError(f"compressed {kind} ID {ident} changed spelling")
        if ident not in symbols[kind]:
            raise ValueError(f"undefined compressed {kind} ID {ident}")
        return symbols[kind][ident]

    def node(name: str, obj: str, filename: str) -> Node:
        result = nodes.setdefault(name, Node(name))
        result.objects.add(obj)
        result.files.add(filename)
        return result

    def costs(tokens: list[str]) -> Counter:
        if not events or len(tokens) > len(events):
            raise ValueError("cost record does not match events header")
        if any(not re.fullmatch(r"\d+", token) for token in tokens):
            raise ValueError("non-integer event count")
        return Counter(dict(zip(events, map(int, tokens))))

    source_file = gzip.open(path, "rt", encoding="utf-8") if path.suffix == ".gz" else path.open(encoding="utf-8")
    with source_file as source:
        for line_number, raw in enumerate(source, 1):
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            try:
                if line.startswith("events:"):
                    if events:
                        raise ValueError("multiple events headers/parts are unsupported")
                    events = line.split(":", 1)[1].split()
                elif line.startswith("positions:"):
                    positions = line.split(":", 1)[1].split()
                elif line.startswith("summary:"):
                    summary = costs(line.split(":", 1)[1].split())
                elif line.startswith("totals:"):
                    totals = costs(line.split(":", 1)[1].split())
                elif re.match(r"^(?:version|creator|pid|cmd|part|thread|desc|event):", line):
                    key, value = line.split(":", 1)
                    metadata.setdefault(key, []).append(value.strip())
                elif re.match(r"^(?:ob|fl|fi|fe|fn|cob|cfi|cfl|cfn|jfi|jfn)=", line):
                    key, value = line.split("=", 1)
                    category = "fn" if key in ("fn", "cfn", "jfn") else (
                        "ob" if key in ("ob", "cob") else "fl")
                    value = expand(category, value)
                    if key == "ob":
                        current_object = value
                    elif key in ("fl", "fi", "fe"):
                        current_file = value
                        if key in ("fi", "fe") and current is not None:
                            nodes[current].files.add(value)
                    elif key == "fn":
                        if pending_calls is not None:
                            raise ValueError("call association lacks a cost record")
                        current = value
                        node(current, current_object, current_file)
                    elif key == "cob":
                        called_object = value
                    elif key in ("cfi", "cfl"):
                        called_file = value
                    elif key == "cfn":
                        called = value
                        node(called, called_object or current_object,
                             called_file or current_file)
                        called_file = None
                        called_object = None
                elif line.startswith("calls="):
                    if pending_calls is not None or called is None or current is None:
                        raise ValueError("invalid call association")
                    pending_calls = int(line.split("=", 1)[1].split()[0])
                elif line.startswith(("jump=", "jcnd=")):
                    pass  # Branch annotations do not contain self/call event costs.
                elif re.match(r"^(?:[+-]?\d|0x|\*)", line):
                    tokens = line.split()
                    if current is None or len(tokens) < len(positions) + 1:
                        raise ValueError("cost record lacks a function or positions")
                    value = costs(tokens[len(positions):])
                    if pending_calls is not None:
                        assert called is not None
                        nodes[current].calls[called] += pending_calls
                        nodes[current].edges[called].update(value)
                        pending_calls = None
                    else:
                        nodes[current].own.update(value)
                else:
                    raise ValueError("unrecognized Callgrind record")
            except (ValueError, AssertionError) as exc:
                raise ValueError(f"{path}:{line_number}: {exc}: {line}") from exc
    if pending_calls is not None:
        raise ValueError(f"{path}: unterminated call association")
    if not events:
        raise ValueError(f"{path}: no events")
    own = Counter()
    for item in nodes.values():
        own.update(item.own)
        # A symbol name/context must identify a single object. Unknown-object
        # call references do not assert a conflicting known library identity.
        known = item.objects - {"???", ""}
        if len(known) > 1 and any(item.own.values()):
            raise ValueError(f"{path}: symbol/object collision: {item.name}: {sorted(known)}")
    expected = totals if totals is not None else summary
    if own != expected:
        raise ValueError(f"{path}: sum(self) {dict(own)} != reported total {dict(expected)}")
    if summary and totals is not None and summary != totals:
        raise ValueError(f"{path}: summary differs from totals")
    return Profile(path, events, nodes, own, metadata)


def base_name(symbol: str) -> str:
    # Callgrind 3.22 appends apostrophe-separated *caller names* with
    # --separate-callers, not just a numeric context suffix. The live Lean
    # symbols used as anchors have no apostrophes in their own spelling.
    return re.split(r"'| \[clone ", symbol, maxsplit=1)[0]


def stage_for(symbol: str, inherited: str) -> str:
    """Operational stage boundaries from Impl/Message.lean and generated C.

    Helpers below an inference or semantic root stay with that root, even when
    shared with ADS-B/altitude decoding. This is a partition by *calling use*,
    not by the module that happens to define a helper.
    """
    symbol = base_name(symbol)
    if "Lean1090_Impl_Semantics_" in symbol or "Lean1090_Impl_Presentation_" in symbol:
        return "semantic_oracle_values"
    if inherited in ("commb_inference", "semantic_oracle_values"):
        return inherited
    local = symbol.removeprefix(PREFIX)
    if local in ("frameCommB", "inferCommB", "commBEligible", "commBCoreEligible"):
        return "commb_inference"
    if local in ("frameADSB", "decodeADSB", "adsbHardValid"):
        return "adsb_fields"
    if local in ("frameAltitude", "frameOracleAltitude", "frameIdentity"):
        return "semantic_oracle_values"
    if local in ("decodeFrame", "frameSyndrome", "frameAddress", "frameAccepted") or (
            symbol.startswith(PREFIX + "Parity_")):
        return "frame_crc"
    # report's map specialization allocates the semantic list; its called
    # Semantics.commB bodies transition explicitly, leaving list bookkeeping
    # with output-model construction.
    return inherited


def analyze(profile: Profile, root: str, initial: str, extra_anchors=()) -> dict:
    roots = [name for name in profile.nodes if base_name(name) == root]
    if not roots:
        # Empty corpus strata are legitimate, but no counted work may be hidden.
        if any(profile.summary.values()):
            raise ValueError(f"{profile.path}: root {root} absent from a nonempty profile")
        roots = []
    labels: dict[str, set[str]] = defaultdict(set)
    queue: deque[tuple[str, str]] = deque((name, initial) for name in roots)
    while queue:
        name, inherited = queue.popleft()
        stage = stage_for(name, inherited)
        if stage in labels[name]:
            continue
        labels[name].add(stage)
        for callee, edge in profile.nodes[name].edges.items():
            # Zero-cost edges may have run entirely while collection was off.
            # They cannot account for any collected callee execution here.
            if any(edge.values()):
                queue.append((callee, stage))
    buckets: dict[str, Counter] = defaultdict(Counter)
    ambiguous = []
    functions = []
    for name, node in profile.nodes.items():
        stages = sorted(labels[name])
        bucket = stages[0] if len(stages) == 1 else (
            "shared_ambiguous" if stages else "outside_root")
        buckets[bucket].update(node.own)
        if any(node.own.values()):
            row = {"symbol": name, "stages": stages, "bucket": bucket,
                   "self_events": dict(node.own), "files": sorted(node.files),
                   "objects": sorted(node.objects)}
            functions.append(row)
            if len(stages) > 1:
                ambiguous.append(row)
    reconstructed = Counter()
    for counts in buckets.values():
        reconstructed.update(counts)
    assert reconstructed == profile.summary
    # With root toggling, counted execution must be reachable from that root.
    # An attribution bug, unsupported tail-edge case or collection leak fails.
    if any(buckets["outside_root"].values()):
        leaked = [row["symbol"] for row in functions if row["bucket"] == "outside_root"]
        raise ValueError(f"{profile.path}: nonzero events outside collected root: {leaked[:12]}")
    functions.sort(key=lambda row: row["self_events"].get("Ir", 0), reverse=True)
    root_calls = sum(node.calls[name] for node in profile.nodes.values() for name in roots)
    anchor_names = {
        PREFIX + name for name in (
            "decode", "decodeFrame", "frameAccepted", "frameSyndrome", "frameAddress",
            "Parity_checksum", "Parity_syndrome", "Parity_step", "frameADSB",
            "decodeADSB", "adsbHardValid", "frameCommB", "inferCommB",
            "commBCoreEligible", "bdsWireValid", "cbScorePasses", "cbCombinedScore",
            "cbDensity", "cbPenalty", "Semantics_adsb", "Semantics_commB",
            "frameAltitude", "frameIdentity", "report")
    }
    optional_anchors = OPTIONAL_SCORE_ANCHORS | set(extra_anchors)
    anchor_names |= optional_anchors
    anchors = {}
    for anchor in sorted(anchor_names):
        contexts = {name for name in profile.nodes if base_name(name) == anchor}
        if not contexts:
            continue
        calls = 0
        inclusive: Counter = Counter()
        own: Counter = Counter()
        for name in contexts:
            own.update(profile.nodes[name].own)
        for node in profile.nodes.values():
            for target in contexts:
                calls += node.calls[target]
                inclusive.update(node.edges.get(target, {}))
        anchors[anchor] = {"contexts": len(contexts), "native_entries": calls,
                           "self_events": dict(own),
                           "incoming_inclusive_events_non_additive": dict(inclusive)}
    crc_nested = {}
    for anchor in (PREFIX + "Parity_step", PREFIX + "Parity_syndrome",
                   "l_BitVec_ofNat", "l_Nat_testBit", "lean_nat_pow",
                   "lean_nat_big_shiftr", "lean_nat_div", "lean_nat_mod"):
        contexts = {name for name in profile.nodes
                    if base_name(name) == anchor and labels[name] == {"frame_crc"}}
        excluded_ambiguous = {name for name in profile.nodes
                              if base_name(name) == anchor and "frame_crc" in labels[name]
                              and labels[name] != {"frame_crc"}}
        own: Counter = Counter()
        inclusive: Counter = Counter()
        calls = 0
        for name in contexts:
            own.update(profile.nodes[name].own)
        for node in profile.nodes.values():
            for target in contexts:
                calls += node.calls[target]
                inclusive.update(node.edges.get(target, {}))
        crc_nested[anchor] = {
            "crc_only_contexts": len(contexts),
            "ambiguous_contexts_excluded": len(excluded_ambiguous),
            "native_entries": calls, "self_events": dict(own),
            "incoming_inclusive_events_non_additive": dict(inclusive),
        }
    return {
        "path": str(profile.path),
        "sha256": hashlib.sha256(gzip.decompress(profile.path.read_bytes())
                                  if profile.path.suffix == ".gz" else profile.path.read_bytes()).hexdigest(),
        "container_sha256": hashlib.sha256(profile.path.read_bytes()).hexdigest(),
        "gzip_container": profile.path.suffix == ".gz",
        "events": profile.events, "metadata": profile.metadata,
        "root": root, "root_contexts": len(roots),
        "root_incoming_calls": root_calls,
        "total_events": {event: profile.summary[event] for event in profile.events},
        "exclusive_stage_events": {key: dict(value) for key, value in sorted(buckets.items())},
        "stage_attribution_complete": not any(buckets["shared_ambiguous"].values()),
        "ambiguous_context_count": len(ambiguous),
        "ambiguous_contexts": ambiguous,
        "top_self_cost_functions": functions[:100],
        "native_anchor_counts_and_non_additive_inclusive_events": anchors,
        "unobserved_optional_anchor_symbols": sorted(optional_anchors - anchors.keys()),
        "crc_nested_events_non_additive": crc_nested,
        "self_event_sum_matches_summary": True,
        "nonzero_outside_root": False,
    }


def fixture_checks() -> None:
    """Check accounting errors that would materially mislead this diagnostic."""
    text = f"""# callgrind format
version: 1
positions: instr line
events: Ir Dr
summary: 38 8
ob=(1) decoder
fl=(1) test.c
fn=(1) {DECODE}
0x100 1 2 0
cfn=(2) {PREFIX}decodeFrame
calls=1 0x110 2
* +1 17 4
cfn=(3) {PREFIX}Semantics_adsb
calls=1 0x120 3
* +1 19 4
fn=(2)
0x110 2 3 1
cfn=(4) allocation_helper
calls=1 0x130 4
* +1 14 3
fn=(3)
0x120 3 5 1
cfn=(4)
calls=1 0x130 4
* +1 14 3
fn=(4)
0x130 4 28 6
totals: 38 8
"""
    with tempfile.TemporaryDirectory(prefix="lean1090-callgrind-parser-") as tmp:
        path = Path(tmp) / "fixture.callgrind"
        path.write_text(text)
        result = analyze(parse(path), DECODE, "output_model_control")
        assert result["total_events"] == {"Ir": 38, "Dr": 8}
        assert result["exclusive_stage_events"]["frame_crc"] == {"Ir": 3, "Dr": 1}
        assert result["exclusive_stage_events"]["semantic_oracle_values"] == {"Ir": 5, "Dr": 1}
        assert result["exclusive_stage_events"]["shared_ambiguous"] == {"Ir": 28, "Dr": 6}
        assert not result["stage_attribution_complete"]
        compressed = path.with_suffix(".callgrind.gz")
        compressed.write_bytes(gzip.compress(text.encode(), mtime=0))
        compressed_result = analyze(parse(compressed), DECODE, "output_model_control")
        assert compressed_result["total_events"] == result["total_events"]
        assert compressed_result["sha256"] == result["sha256"]
        assert compressed_result["container_sha256"] != result["container_sha256"]
        # Context separation must preserve exact self costs and disambiguate.
        separated = text.replace(
            "fn=(4)\n0x130 4 28 6", "fn=(4)\n0x130 4 14 3\nfn=(5) allocation_helper'2\n0x140 4 14 3")
        separated = separated.replace("cfn=(4)\ncalls=1", "cfn=(5) allocation_helper'2\ncalls=1")
        path.write_text(separated)
        result = analyze(parse(path), DECODE, "output_model_control")
        assert result["stage_attribution_complete"]
        assert result["exclusive_stage_events"]["frame_crc"] == {"Ir": 17, "Dr": 4}
        assert result["exclusive_stage_events"]["semantic_oracle_values"] == {"Ir": 19, "Dr": 4}
        # Real separate-callers names contain complete caller spellings.
        path.write_text(separated.replace("fn=(1) " + DECODE + "\n",
                                          "fn=(1) " + DECODE + "'diagnostic_driver\n")
                        .replace(PREFIX + "decodeFrame", PREFIX + "decodeFrame'caller")
                        .replace(PREFIX + "Semantics_adsb", PREFIX + "Semantics_adsb'caller"))
        result = analyze(parse(path), DECODE, "output_model_control")
        assert result["stage_attribution_complete"]
        assert result["exclusive_stage_events"]["frame_crc"]["Ir"] == 17
        # Damaged totals and unexpected costs outside the toggled root fail.
        path.write_text(text.replace("totals: 38 8", "totals: 39 8"))
        try:
            parse(path)
        except ValueError:
            pass
        else:
            raise AssertionError("bad accounting total accepted")
        path.write_text(text.replace("totals: 38 8", "fn=(9) outside\n0x150 9 1 0\ntotals: 39 8")
                        .replace("summary: 38 8", "summary: 39 8"))
        try:
            analyze(parse(path), DECODE, "output_model_control")
        except ValueError:
            pass
        else:
            raise AssertionError("collection leakage accepted")
        path.write_text("positions: line\nevents: Ir\nsummary: 0\ntotals: 0\n")
        empty = analyze(parse(path), SCORE, "commb_inference")
        assert empty["total_events"] == {"Ir": 0}
        assert empty["root_contexts"] == empty["root_incoming_calls"] == 0
    print("PASS: self/inclusive separation, compressed positions/names, merged-context honesty, context separation, damaged totals and collection-leak rejection")


def labeled_paths(values: list[str]) -> list[tuple[str, Path]]:
    result = []
    seen = set()
    for value in values:
        label, separator, spelling = value.partition("=")
        if not separator or not label or label in seen:
            raise ValueError("profiles require distinct LABEL=PATH arguments")
        seen.add(label)
        result.append((label, Path(spelling)))
    return result


def write_outputs(output: Path, payloads: dict[str, str]) -> None:
    for name, body in payloads.items():
        path = output / name
        if path.exists() and path.read_text() != body:
            raise ValueError(f"refusing to overwrite prior analysis: {path}")
    output.mkdir(parents=True, exist_ok=True)
    for name, body in payloads.items():
        path = output / name
        if not path.exists():
            path.write_text(body)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--profile", action="append", default=[], metavar="FAMILY=PATH")
    parser.add_argument("--score", action="append", default=[], metavar="REGISTER=PATH")
    parser.add_argument("--candidate", action="append", default=[], metavar="REGISTER=PATH")
    parser.add_argument("--output", type=Path)
    parser.add_argument("--title")
    parser.add_argument("--generation", type=int)
    parser.add_argument("--extra-anchor", action="append", default=[], metavar="EXACT_NATIVE_SYMBOL",
                        help="additional optional inclusive anchor; never an additive stage")
    parser.add_argument("--self-test", action="store_true")
    args = parser.parse_args()
    if args.generation is not None and args.generation < 0:
        parser.error("generation must be nonnegative")
    if args.title is None:
        args.title = (f"Generation {args.generation}" if args.generation is not None else "Decoder") + " diagnostic instruction counts"
    if args.self_test:
        fixture_checks()
        if not args.profile and not args.score and not args.candidate:
            return
    if args.output is None or not (args.profile or args.score or args.candidate):
        parser.error("provide --output and at least one --profile, --score or --candidate")
    families = {label: analyze(parse(path), DECODE, "output_model_control", args.extra_anchor)
                for label, path in labeled_paths(args.profile)}
    scores = {label: analyze(parse(path), SCORE, "commb_inference", args.extra_anchor)
              for label, path in labeled_paths(args.score)}
    candidates = {label: analyze(parse(path), CANDIDATE, "commb_inference", args.extra_anchor)
                  for label, path in labeled_paths(args.candidate)}
    document = {
        "kind": "untimed_diagnostic_instruction_counts_not_benchmark",
        "analyzer_source": "review/diagnostics/analyze_callgrind.py",
        "analyzer_sha256": hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        "generation": args.generation,
        "optional_inclusive_anchor_symbols": sorted(OPTIONAL_SCORE_ANCHORS | set(args.extra_anchor)),
        "stage_definitions": DESCRIPTIONS,
        "method": "Exclusive self events, ancestor stage attribution, no inclusive double-counting or proportional distribution",
        "limitations": [
            "Ir counts instrumented guest instructions, not elapsed time, cycles, cache misses or throughput.",
            "Stage attribution includes each stage's allocation and runtime helpers; construction is not a global allocation-only category.",
            "Output-model/control contains final report/message/list assembly plus residual control; instruction-level allocation/control separation is unavailable.",
            "Generic register arguments are absent from the call graph. Separate score probes overlap Comm-B inference and must not be added to whole-decoder counts.",
            "Callgrind context merges, if present, remain explicitly shared/ambiguous.",
            "Register probes are standalone executions of actual reached score gates; allocator/context state may differ from the whole decoder.",
            "Native entry counts describe retained symbols; inlining/tail-call elimination can remove entries without removing the computation. Census predictions are reported separately.",
            "Optional ScoreGate/table/fallback anchors retain caller-stage attribution and overlapping inclusive counts only. An unobserved symbol is not evidence of zero logical work or zero fallback decisions.",
            "These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the three-warmup benchmark; no unmeasured correction is applied.",
        ],
        "families": families, "non_additive_register_score_probes": scores,
        "non_additive_register_candidate_probes": candidates,
    }
    lines = ["# " + args.title, "", "**Diagnostic, not a benchmark result.** No throughput is inferred from these counts.", "",
             "| Profile | Guest instructions (Ir) | Complete stage attribution |", "|---|---:|---|"]
    for label, result in families.items():
        lines.append(f"| {label} | {result['total_events'].get('Ir', 0):,} | {result['stage_attribution_complete']} |")
    for label, result in families.items():
        total = result["total_events"].get("Ir", 0)
        lines += ["", f"## {label}", "", "| Exclusive stage | Ir | Share |", "|---|---:|---:|"]
        for stage, counts in sorted(result["exclusive_stage_events"].items(),
                                    key=lambda item: item[1].get("Ir", 0), reverse=True):
            count = counts.get("Ir", 0)
            if count:
                share = 100 * count / total if total else 0
                lines.append(f"| {stage} | {count:,} | {share:.4f}% |")
    if scores:
        lines += ["", "## Supplemental register score probes", "", "These overlap the Comm-B stage and are **not additive**. Generic register arguments cannot be recovered from Callgrind symbol names.", "",
                  "| Register | Live score-gate Ir |", "|---|---:|"]
        for label, result in scores.items():
            lines.append(f"| {label} | {result['total_events'].get('Ir', 0):,} |")
    if candidates:
        lines += ["", "## Supplemental complete candidate-predicate probes", "",
                  "These run live commBCoreEligible on every nonempty DF20/21 MB word. They include hard checks and any reached score gate, but exclude the common DF/nonempty guards, inference-list traversal, decodeBDS recheck and output construction. They overlap both the Comm-B stage and the score probes and are **not additive**.", "",
                  "| Register | Live candidate-predicate Ir |", "|---|---:|"]
        for label, result in candidates.items():
            lines.append(f"| {label} | {result['total_events'].get('Ir', 0):,} |")
    lines += ["", "## Attribution limits", ""] + [f"- {item}" for item in document["limitations"]]
    write_outputs(args.output, {"analysis.json": json.dumps(document, indent=2) + "\n",
                                "ANALYSIS.md": "\n".join(lines) + "\n"})
    print(json.dumps({"analysis": str(args.output / "analysis.json"),
                      "families": {key: value["total_events"] for key, value in families.items()},
                      "register_probes": {key: value["total_events"] for key, value in scores.items()},
                      "candidate_probes": {key: value["total_events"] for key, value in candidates.items()}}))


if __name__ == "__main__":
    try:
        main()
    except (ValueError, OSError) as error:
        print(f"ERROR: {error}", file=sys.stderr)
        sys.exit(1)

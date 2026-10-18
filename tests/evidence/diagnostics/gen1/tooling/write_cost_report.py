#!/usr/bin/env python3
"""Render a generation diagnostic from completed, inspectable observations."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path


P = "lp_lean1090_Lean1090_Impl_"
FAMILIES = {"adsb": {17, 18}, "commb": {20, 21},
            "other": set(range(32)) - {17, 18, 20, 21}}
STAGES = {
    "frame_crc": "Frame / CRC",
    "adsb_fields": "ADS-B fields / checks",
    "commb_inference": "Comm-B candidate inference / raw records",
    "semantic_oracle_values": "Semantic / oracle value construction",
    "output_model_control": "Output-model construction / residual control",
    "shared_ambiguous": "Shared context, attribution unresolved",
}


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def link(path):
    path = Path(path)
    return f"[{path}](../{path})"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--analysis", required=True, type=Path)
    parser.add_argument("--census", required=True, type=Path)
    parser.add_argument("--native-df", required=True, type=Path)
    parser.add_argument("--perf", required=True, type=Path)
    parser.add_argument("--build", required=True, type=Path)
    parser.add_argument("--output", type=Path)
    parser.add_argument("--generation", type=int, choices=(0, 1), default=0)
    parser.add_argument("--previous-analysis", type=Path)
    parser.add_argument("--campaign", type=Path)
    parser.add_argument("--benchmark", type=Path)
    parser.add_argument("--evidence-root", type=Path, default=Path("tests/evidence/diagnostics/gen0"))
    args = parser.parse_args()
    if args.output is None:
        args.output = Path(f"docs/GEN{args.generation}-COST-BREAKDOWN.md")
    if args.generation:
        assert args.output.resolve() != Path("docs/GEN0-COST-BREAKDOWN.md").resolve(), "preserve the gen0 report"
    analysis = read(args.analysis)
    native = read(args.native_df)
    perf = read(args.perf)
    build = read(args.build)
    if args.generation:
        assert args.previous_analysis and args.campaign and args.benchmark
        campaign = read(args.campaign)
        benchmark = read(args.benchmark)
        assert campaign["status"] == "passed" and campaign["protected_inputs_unchanged"]
        assert campaign["full_output_digest_and_census_match_gen0"]
        assert campaign["commit"] == benchmark["commit"] == build["commit"]
        assert len(campaign["profiles"]) == 13
        assert all(row["status"] == "passed" and row["native_output_matches"] for row in campaign["profiles"])
        assert campaign["protected_inputs"][".lake/build/bin/lean1090-bench"] == benchmark["binary_sha256"]
        assert campaign["build_manifest_sha256"] == sha(args.build)
        assert build["artifacts"][campaign["driver_binary"]] == campaign["driver_binary_sha256"]
        for inventory in (build["production_sources"], build["reused_production_objects"]):
            assert all(campaign["protected_inputs"][name] == digest for name, digest in inventory.items())
        assert native["binary_sha256"] == campaign["driver_binary_sha256"]
        assert native["corpus_sha256"] == campaign["corpus_sha256"]
        assert native["build_manifest_sha256"] == sha(args.build)
        assert native["census_sha256"] == sha(args.census)
        assert native["binary_and_production_objects_unchanged"]
        perf_capture = read(args.perf.parent / "capture.json")
        assert perf_capture["all_input_hashes_unchanged"]
        assert perf_capture["before_hashes"][".lake/build/bin/lean1090-bench"] == benchmark["binary_sha256"]
        measured = {row["mode"]: row["lean_over_rust"] for row in benchmark["results"]}
    census_rows = [json.loads(line) for line in args.census.read_text().splitlines() if line.strip()]
    census = next(row for row in census_rows if row.get("kind") == "post_decode_shadow_census")
    per_df = {row["df"]: row for row in census["per_df"]}
    native_df = {row["df"]: row for row in native["per_df"]}
    assert set(per_df) == set(native_df) == set(range(32))
    assert sum(row["count"] for row in per_df.values()) == 172432
    profiles = {name: analysis["families"][name] for name in FAMILIES}
    counts = {name: sum(per_df[df]["count"] for df in dfs) for name, dfs in FAMILIES.items()}
    for name, dfs in FAMILIES.items():
        profile = profiles[name]
        anchors = profile["native_anchor_counts_and_non_additive_inclusive_events"]
        assert profile["root_incoming_calls"] == counts[name], (name, "decode entry count")
        crc = sum(per_df[df]["crc_call_predictions"] for df in dfs)
        steps = sum(per_df[df]["crc_call_predictions"] * (56 if df < 16 else 112) for df in dfs)
        assert anchors[P + "Parity_checksum"]["native_entries"] == crc, (name, "CRC entry count")
        assert anchors[P + "Parity_step"]["native_entries"] == steps, (name, "CRC step count")
    totals = {name: result["total_events"]["Ir"] for name, result in profiles.items()}
    total = sum(totals.values())
    stages = Counter()
    for result in profiles.values():
        assert result["self_event_sum_matches_summary"] and not result["nonzero_outside_root"]
        stages.update({stage: events.get("Ir", 0)
                       for stage, events in result["exclusive_stage_events"].items()})
    assert sum(stages.values()) == total
    required = {"40", "44", "45", "50", "60"}
    assert set(analysis["non_additive_register_score_probes"]) == required
    assert set(analysis["non_additive_register_candidate_probes"]) == required
    register_counts = {}
    for register in sorted(required):
        code = int(register, 16)
        rows = [row for df in (20, 21) for row in per_df[df]["commb"]
                if row["register_decimal"] == code]
        register_counts[register] = {key: sum(row[key] for row in rows) for key in (
            "nonempty", "hard_attempt_predictions", "hard_pass", "score_attempt_predictions",
            "score_pass", "accepted", "decodeBDS_recheck_predictions")}
    for register, values in register_counts.items():
        assert values["hard_pass"] == values["score_attempt_predictions"]
        score = analysis["non_additive_register_score_probes"][register]
        candidate = analysis["non_additive_register_candidate_probes"][register]
        assert score["root_incoming_calls"] == values["score_attempt_predictions"]
        assert candidate["root_incoming_calls"] == values["nonempty"]
    assert all(register_counts[register]["score_attempt_predictions"] == 0 for register in ("44", "45"))
    if args.generation:
        profile_results = {**profiles,
                           **{"candidate" + name: value for name, value in analysis["non_additive_register_candidate_probes"].items()},
                           **{"score" + name: value for name, value in analysis["non_additive_register_score_probes"].items()}}
        assert {row["mode"] for row in campaign["profiles"]} == set(profile_results)
        for row in campaign["profiles"]:
            observed = read(args.evidence_root / "callgrind" / row["mode"] / "run.json")
            parsed = profile_results[row["mode"]]
            assert observed["hashes"]["binary"] == campaign["driver_binary_sha256"]
            assert observed["hashes"]["corpus"] == campaign["corpus_sha256"]
            assert observed["hashes"]["lock"] == build["lock_sha256"]
            assert observed["root"] == parsed["root"]
            assert observed["primary_ir"] == row["primary_ir"] == parsed["total_events"].get("Ir", 0)
            assert observed["profile_files"][observed["primary_profile"]] == parsed["sha256"]
            assert observed["result"]["digest"] == row["digest"]
    largest = max(stages, key=stages.get)
    all_complete = all(profile["stage_attribution_complete"] for profile in profiles.values())
    lines = [
        f"# Generation {args.generation}: untimed decoder cost breakdown", "",
        f"**Diagnostic, not a benchmark.** This profiles the unchanged `Impl.decode` from `{build['commit']}` over all 172,432 corpus messages before the next optimization. The largest attributed instruction category is **{STAGES[largest]}**, with {stages[largest]:,} of {total:,} collected guest instructions ({100*stages[largest]/total:.2f}%). These are instruction counts; they are not elapsed time, CPU cycles or predicted throughput gains.", "",
        (f"The separately completed generation-{args.generation} benchmark is decode **{measured['decode']:.5f}×** and CPR **{measured['cpr']:.5f}×**; see {link(args.benchmark)}. This diagnostic does not revise either benchmark." if args.generation else
         "The accepted generation-0 benchmark remains decode **0.1663×** and CPR **0.1562×**. This diagnostic does not revise either benchmark."), "",
        "## Corpus families and exclusive stages", "",
        "Each family runs the live decoder once per selected row, preserving within-family corpus order. The three families are disjoint and cover every corpus row. Their instruction totals are added with their actual populations, not by averaging family percentages. Each function/context's self cost is counted once; nested inclusive call costs are never added to this partition.", "",
        "The family and supplemental Callgrind jobs overlapped on this machine. They count instrumented guest instructions and make no timing or throughput claim. The native perf capture completed before these family/probe jobs. Every build, test, profiler and agent task must stop before any subsequent frozen generation benchmark.", "",
        "The controller prepares input with instrumentation off, enables it before the native root loop, explicitly dumps counters after complete outputs are retained, and disables instrumentation before representation/digest consumption. Collection is toggled only within the live root. The primary evidence is the explicit `callgrind.out.1` dump, whose self costs, summary and totals agree. The subsequent termination dumps are also retained; after instrumentation reset, some contain a wrapped summary with zero totals and are not the measured counter set. Control commands and state acknowledgments are recorded in each `run.json`.", "",
        "| DF family | Messages | Guest instructions (Ir) | Ir/message | Share of aggregate Ir |",
        "|---|---:|---:|---:|---:|",
    ]
    for name in FAMILIES:
        lines.append(f"| {name} | {counts[name]:,} | {totals[name]:,} | {totals[name]/counts[name]:,.1f} | {100*totals[name]/total:.2f}% |")
    lines += [f"| Total | 172,432 | {total:,} | {total/172432:,.1f} | 100% |", "",
              "ADS-B means DF17/18; Comm-B means DF20/21; other means every remaining DF. Separate processes have separate allocator state, so the aggregate is an operational cost census of the corpus strata, not a single-pass elapsed-time measurement.", "",
              "| Exclusive stage | ADS-B Ir | Comm-B Ir | Other Ir | Total Ir | Aggregate share |",
              "|---|---:|---:|---:|---:|---:|"]
    for stage in sorted(STAGES, key=lambda key: stages[key], reverse=True):
        if not stages[stage] and stage == "shared_ambiguous":
            continue
        values = [profiles[name]["exclusive_stage_events"].get(stage, {}).get("Ir", 0) for name in FAMILIES]
        lines.append(f"| {STAGES[stage]} | " + " | ".join(f"{value:,}" for value in values) +
                     f" | {stages[stage]:,} | {100*stages[stage]/total:.2f}% |")
    lines += ["", f"All stage contexts resolved uniquely: **{all_complete}**. All self-event sums match Callgrind's reported totals, and there are no counted events outside the collection root.", "",
              "The stage owns its runtime, Rat/GMP and allocation helpers. This is an operational partition: allocations inside inference stay with inference; semantic payload allocations stay with semantic construction. Final Message/Report/list assembly and residual decoder control are the output-model category. Compiler inlining can leave some dispatch/control work in its caller. A DF with no ADS-B payload can still incur the small `frameADSB` dispatch cost.", "",
    ]
    if args.previous_analysis:
        previous = read(args.previous_analysis)
        previous_stages = Counter()
        for result in previous["families"].values():
            previous_stages.update({stage: events.get("Ir", 0) for stage, events in result["exclusive_stage_events"].items()})
        previous_total = sum(previous_stages.values())
        assert set(previous["families"]) == set(profiles)
        assert all(previous["families"][name]["root_incoming_calls"] == counts[name] for name in profiles)
        lines += ["## Comparison with generation 0", "",
                  "Both diagnostics use the same corpus populations, complete output digests, control-flow census and retained stage boundaries. Gen1 changes the final 24-bit reduction in `Parity.step`; it preserves the live decode/checksum/step and semantic/inference symbols used for attribution. Absolute counts and instruction counts per message are compared below; changing shares alone would hide denominator changes.", "",
                  "| Exclusive stage | Gen0 Ir | Gen1 Ir | Difference (gen1 − gen0) | Gen1/gen0 | Gen0 Ir/message | Gen1 Ir/message |",
                  "|---|---:|---:|---:|---:|---:|---:|"]
        for stage in sorted(STAGES, key=lambda key: stages[key], reverse=True):
            old, new = previous_stages[stage], stages[stage]
            if not (old or new):
                continue
            ratio = f"{new/old:.5f}" if old else "n/a"
            lines.append(f"| {STAGES[stage]} | {old:,} | {new:,} | {new-old:+,} | {ratio} | {old/172432:,.2f} | {new/172432:,.2f} |")
        lines += [f"| Total | {previous_total:,} | {total:,} | {total-previous_total:+,} | {total/previous_total:.5f} | {previous_total/172432:,.2f} | {total/172432:,.2f} |", "",
                  "These are differences in observed instruction counts, not a timing decomposition or a predicted speedup. Separate process allocation/cold-constant context can contribute small changes in unchanged stages. Nested helper and candidate/score costs are excluded from this additive comparison because they overlap.", ""]
    lines += [
              "## Each scored Comm-B register", "",
              "Every candidate probe runs live `commBCoreEligible` on every nonempty DF20/21 MB word. It includes that candidate's hard checks and any reached software-binary64 score gate, but excludes common DF/nonempty guards, inference-list traversal and accepted-record `decodeBDS` recheck/construction. Those costs remain in the whole-decoder inference stage. Each score-only probe runs live `cbScorePasses` only on the corpus values that passed the same hard checks. Root-entry counts are checked against the independently validated control-flow census.", "",
              "These probes overlap each other and the whole-decoder inference stage: **do not add them to the exclusive stage totals**. They are separate executions with their own allocator state, not exact subdivisions of a generic function argument that Callgrind cannot observe.", "",
              "| Register | Candidate attempts | Hard pass / score calls | Score pass | Candidate Ir | Score-only Ir |",
              "|---|---:|---:|---:|---:|---:|"]
    for register, values in register_counts.items():
        candidate_ir = analysis["non_additive_register_candidate_probes"][register]["total_events"].get("Ir", 0)
        score_ir = analysis["non_additive_register_score_probes"][register]["total_events"].get("Ir", 0)
        lines.append(f"| BDS{register} | {values['nonempty']:,} | {values['score_attempt_predictions']:,} | {values['score_pass']:,} | {candidate_ir:,} | {score_ir:,} |")
    lines += ["", "BDS44 and BDS45 have **zero reached score gates in this corpus**. Their hard-check costs are observed; their score-path performance is not measured by this workload. No synthetic replacement is reported as a corpus observation. All 14 register attempt/eligibility/accepted counts are retained in the census.", "",
              "## Native allocation counts and output checks by DF", "",
              "`IO.getNumHeartbeats` counts Lean small allocations in the native decode-plus-array-append loop. These are not allocated bytes, peak live memory or all GMP/libc allocations. Each nonempty DF run consumes every output field afterward using its complete representation; count, representation byte count and FNV checksum agree with that DF's retained records from the complete corpus run. FNV is an observability checksum, not an equivalence proof.", "",
              "| DF | Messages | Native loop small allocations | Allocations/message | Complete output digest agrees |",
              "|---|---:|---:|---:|---|"]
    for df, row in native_df.items():
        if row["messages"]:
            assert row["matches_full_corpus_df_digest"]
            lines.append(f"| {df} | {row['messages']:,} | {row['loop_small_allocations']:,} | {row['loop_small_allocations']/row['messages']:.2f} | Yes |")
    absent = ", ".join(str(df) for df, row in native_df.items() if not row["messages"])
    lines += ["", f"Absent corpus DFs: {absent}. These are zero-coverage strata, not failed decodes.", "",
              f"The complete corpus loop records {native['complete_corpus_loop_small_allocations']:,} small allocations. The sum of separate DF loops is {native['sum_separate_df_loop_small_allocations']:,}, a difference of {native['sum_separate_df_loop_small_allocations'] - native['complete_corpus_loop_small_allocations']:,}. The runs have separate loop/array/context state; this difference is retained rather than assumed to be zero or assigned to a particular cause. No allocation count is converted into throughput.", "",
              "## Nested live calls (non-additive)", "",
              "Inclusive costs below overlap the exclusive stages and each other. Native entry counts describe actual retained symbols; an absent/inlined symbol does not mean the underlying computation did not run.", "",
              "| Live function | Native entries across families | Inclusive Ir across families |",
              "|---|---:|---:|"]
    for anchor in ("decodeFrame", "frameSyndrome", "Parity_checksum", "Parity_step", "cbDensity", "cbPenalty",
                   "Semantics_adsb", "Semantics_commB"):
        records = [profile["native_anchor_counts_and_non_additive_inclusive_events"].get(P + anchor, {})
                   for profile in profiles.values()]
        entries = sum(record.get("native_entries", 0) for record in records)
        events = sum(record.get("incoming_inclusive_events_non_additive", {}).get("Ir", 0) for record in records)
        lines.append(f"| `{anchor}` | {entries:,} | {events:,} |")
    lines += ["", "CRC-only contexts further separate fixed-width remainder work from extraction of bits from the complete word. The following inclusive costs overlap: a high-level parity helper can call the Nat/GMP helpers below it. They must not be added, subtracted as if disjoint, or extrapolated to predicted speedups. Non-CRC uses of the same helpers are excluded by their observed caller context. A zero native-symbol count does not imply that all semantically related work disappeared.", "",
              "| CRC-only helper | Native entries | Inclusive Ir | Share of frame/CRC Ir (overlapping) |",
              "|---|---:|---:|---:|"]
    for anchor in (P + "Parity_step", "l_BitVec_ofNat", "l_Nat_testBit", "lean_nat_pow", "lean_nat_big_shiftr"):
        records = [profile["crc_nested_events_non_additive"][anchor] for profile in profiles.values()]
        assert not any(record["ambiguous_contexts_excluded"] for record in records)
        entries = sum(record["native_entries"] for record in records)
        events = sum(record["incoming_inclusive_events_non_additive"].get("Ir", 0) for record in records)
        lines.append(f"| `{anchor.removeprefix(P)}` | {entries:,} | {events:,} | {100*events/stages['frame_crc']:.2f}% |")
    if not args.generation:
        lines += ["", "The DF11 calibration separately observed exactly 38,456 decode/frame/CRC entries and 2,153,536 parity steps (56 per message), matching the shadow census. It is not added again to the three-family totals.", ""]
    lines += ["", (
              f"The retained generation-{args.generation} generated C makes the changed path concrete: {link(args.evidence_root / 'generated-c/Impl/Parity.c')} line 72 calls `lean_nat_mod` with constant 16,777,216 inside `Parity.step`. Its per-bit generic `BitVec.ofNat` call is gone. `Nat.testBit` remains at line 126; other `BitVec.ofNat` calls remain at lines 153, 220 and 222, and line 161 retains the lazy syndrome constant. The reduction did not remove every CRC use of generic bit-vector/Nat helpers." if args.generation else
              "The retained generation-0 generated C makes the cost boundaries concrete: [Impl/Parity.c](../tests/evidence/diagnostics/gen0/generated-c/Impl/Parity.c) lines 78 and 88 call generic `l_BitVec_ofNat` with width 24 on every step; lines 121 and 123 call `l_Nat_testBit` and `Parity.step` for each bit. Line 156 uses `lean_obj_once` for the syndrome's zero constant. Source-level repetition is therefore checked against the actual generated program, not inferred only from function names."), "",
              "## Native sampling cross-check", "",
              f"A separate `perf` software CPU-clock capture of the generation-{args.generation} benchmark binary retained {perf['total_samples']:,} samples; {perf['decode_descendant_samples']:,} had a visible live `Impl.decode` ancestor. Within those visible stacks, report parity/address had {perf['disjoint_detail_stages']['report parity/address']} samples and Comm-B inference/raw fields had {perf['disjoint_detail_stages']['Comm-B inference and raw payload']}. Missing/truncated ancestry prevents an unbiased whole-decoder timing allocation. The complete exclusion counts and raw stacks are retained. Sampling does not supply the exact instruction partition above. " + ("The diagnostic driver compilation finished before this capture, and native driver/Callgrind runs began after it. Other agents performed read-only review; host-wide isolation is not claimed. This is still a diagnostic, not a frozen benchmark." if args.generation else "That capture allowed a possible small concurrent diagnostic-driver compilation; strict isolation is not claimed for it either."), "",
              "## Consequences for the next optimization", "",
              f"Start with the measured **{STAGES[largest]}** cost, then rerun this diagnostic after the change. The generated C and live source show repeated Nat/GMP operations in parity and exact Rat/software-binary64 arithmetic in Comm-B scoring. Which part is improved must be justified by the measured cost and the unchanged refinement theorem, then evaluated with the frozen benchmark protocol.", "",
              "For Comm-B, the approved direction remains immutable per-field-code tables of exact density terms, proved integer/rational gate decisions and a full-model fallback within a proved rounding interval around −3. No hardware Float trusted primitive, corpus-keyed table, message cache or frozen change is introduced by this diagnostic.", "",
              "These are single-pass diagnostic executions. Lazy constants and allocator state can differ from the accepted benchmark after its three warmup pairs. This diagnostic does not measure the size of that difference or correct instruction counts into an estimated warm throughput. Any performance conclusion requires the unchanged frozen ABAB benchmark.", "",
              "## Reproduction and evidence", "",
              f"The diagnostic driver reused the unchanged native production objects from commit `{build['commit']}`; its build and campaign provenance record object/source/generated-C SHA-256 hashes and compiler/link commands. The benchmark binary was not replaced by the driver. Source/configuration and raw collection commands are retained with the evidence. The current frozen lock hash is `{build['lock_sha256']}`.", "",
              f"- Exclusive cost analysis: {link(args.analysis)}.",
              f"- Independently checked control-flow census: {link(args.census)}.",
              f"- Per-DF native commands, digests, allocation counts and binary/object checks: {link(args.native_df)}.",
              f"- Original native sampling and its limits: {link(args.perf)}.",
              f"- Diagnostic build provenance: {link(args.build)}.",
              f"- Collection outputs, control commands and compressed raw Callgrind event files are retained under `{args.evidence_root / ('callgrind' if args.generation else 'callgrind-v3')}/`.",
              "- Analyzer/parser fixtures cover compressed names/positions, exact self accounting, inclusive-cost double counting, full caller context names, explicit ambiguity, corrupted totals and collection leakage.", "",
              "Input hashes used to render this document:", "",
              "| Input | SHA-256 |", "|---|---|"]
    for path in (args.analysis, args.census, args.native_df, args.perf, args.build, args.previous_analysis, args.campaign, args.benchmark):
        if path is None:
            continue
        lines.append(f"| `{path}` | `{sha(path)}` |")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("\n".join(lines) + "\n")
    print(json.dumps({"document": str(args.output), "sha256": sha(args.output),
                      "total_instructions": total, "largest_stage": largest,
                      "stage_attribution_complete": all_complete}))


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Reproduce FC003's pinned-source audit of wide deku reads.

This is a lexical inventory plus a reviewed disposition, not a Rust type checker
or a proof about future rs1090 versions. The pinned commit and exact unmatched
site set are assertions so that a source change cannot inherit this conclusion.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
VENDOR = ROOT / "vendor/rs1090"
SOURCE = VENDOR / "crates/rs1090/src/decode"
PIN = "685dfaa34c5ab186c691bca3cfe2a22e12517d30"
DISPOSITIONS = {
    ("bds/bds09.rs", 238): ("ReservedVelocityData.reserved_data", "observable-mode-s", "FC002"),
    ("bds/bds10.rs", 279): ("DataLinkCapability.dte", "observable-mode-s", "FC003"),
    ("bds/bds30.rs", 206): ("ThreatType::NoIdentity.unused", "serde-skipped-and-not-validated", None),
    ("bds/bds30.rs", 219): ("ThreatType::NotAssigned.unused", "serde-skipped-and-not-validated", None),
    ("mod.rs", 590): ("IcaoParity.0", "read-value-discarded-by-map", None),
    ("cat48.rs", 1130): ("CalculatedDopplerSpeed.speed_ms", "out-of-scope-asterix-cat48", None),
}


def run(*args: str) -> str:
    return subprocess.check_output(args, cwd=ROOT, text=True).strip()


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, default=ROOT / "tests/evidence/deku-endian-scan")
    args = parser.parse_args()
    assert run("git", "-C", str(VENDOR), "rev-parse", "HEAD") == PIN
    assert not run("git", "-C", str(VENDOR), "diff", "--", "crates/rs1090/src/decode")
    assert not run("git", "-C", str(VENDOR), "diff", "--cached", "--", "crates/rs1090/src/decode")

    attributes, wide_calls, raw_reads, hashes = [], [], [], {}
    missing = set()
    for path in sorted(SOURCE.rglob("*.rs")):
        text = path.read_text()
        relative = str(path.relative_to(SOURCE))
        hashes[relative] = hashlib.sha256(path.read_bytes()).hexdigest()
        for match in re.finditer(r"#\[deku\((.*?)\)\]", text, re.S):
            bit = re.search(r'\bbits\s*=\s*"?(\d+)"?(?=\s*[,)]|\s*$)', match[1])
            # The pinned source uses numeric widths only. Fail on an unparsed width.
            if re.search(r"\bbits\s*=", match[1]):
                assert bit is not None, (relative, match[0])
            if bit is None or int(bit[1]) <= 8:
                continue
            line = text.count("\n", 0, match.start()) + 1
            endian = re.search(r'\bendian\s*=\s*"([^\"]+)"', match[1])
            item = {"file": relative, "line": line, "bits": int(bit[1]),
                    "endian_attribute": endian[1] if endian else None,
                    "attribute": match[0], "following_source": text[match.end():match.end()+180]}
            if endian is None:
                key = (relative, line)
                missing.add(key)
                assert key in DISPOSITIONS, f"Unreviewed native-endian site: {key}"
                item["field"], item["disposition"], item["correction"] = DISPOSITIONS[key]
            attributes.append(item)
        # Includes whole-width primitive reads without BitSize (FLARM's u32s).
        primitive_starts = list(re.finditer(r"\b(?:u|i)(?:16|32|64|128|size)::from_reader_with_ctx\(", text))
        calls = list(re.finditer(r"\b(?:u|i)(?:16|32|64|128|size)::from_reader_with_ctx\((.*?)\)\?", text, re.S))
        assert len(calls) == len(primitive_starts), relative
        for match in calls:
            bit = re.search(r"BitSize\((\d+)\)", match[1])
            width = int(bit[1]) if bit else int(re.match(r"[ui](\d+)", match[0])[1])
            if width <= 8:
                continue
            endian = re.search(r"Endian::(Big|Little)", match[1])
            assert endian, (relative, match[0])
            wide_calls.append({"file": relative, "line": text.count("\n", 0, match.start())+1,
                               "bits": width, "endian": endian[1], "source": match[0]})
        for match in re.finditer(r"reader\.read_bits\((.*?)\)\?", text, re.S):
            assert "Order::Msb0" in match[1], (relative, match[0])
            raw_reads.append({"file": relative, "line": text.count("\n", 0, match.start())+1,
                              "source": match[0], "disposition": "raw-bits-explicit-Msb0"})
    assert missing == set(DISPOSITIONS), (missing, set(DISPOSITIONS))
    assert len(hashes) == 30
    assert len(attributes) == 25
    assert len(wide_calls) == 26
    assert len(raw_reads) == 4
    assert sum(x["endian"] == "Big" for x in wide_calls) == 21
    assert sum(x["endian"] == "Little" for x in wide_calls) == 5

    summary = {
        "pinned_rs1090": PIN, "source_files": len(hashes),
        "wide_deku_attributes": len(attributes), "explicit_endian_attributes": 19,
        "missing_endian_attributes": 6, "mode_s_missing_endian_attributes": 5,
        "mode_s_observable_sites": 2, "mode_s_skipped_or_discarded_sites": 3,
        "out_of_scope_missing_endian_attributes": 1,
        "explicit_endian_wide_primitive_calls": len(wide_calls), "raw_Msb0_reads": len(raw_reads),
        "scope": "Message::from_bytes Mode S output and acceptance; excludes ASTERIX CAT48 and FLARM",
        "limitation": "Pinned lexical inventory with manual context/use review; not a general Rust program proof",
    }
    args.output.mkdir(parents=True, exist_ok=True)
    for name, value in [("summary.json", summary), ("wide-attributes.json", attributes),
                        ("primitive-calls.json", wide_calls), ("raw-reads.json", raw_reads),
                        ("source-sha256.json", hashes)]:
        (args.output / name).write_text(json.dumps(value, indent=2) + "\n")
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()

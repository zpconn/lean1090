#!/usr/bin/env python3
"""Complete, accumulating whole-message differential campaign.

Every invocation runs fresh pinned Rust readers and actual compiled Lean code.
Diagnostic mode retains every disagreement and exits unsuccessfully only after
all corpus/generated/structured-message and direct-register cases are compared.
The JSON projection is tested separately from the proved exact message model.
"""
import argparse
from collections import Counter, defaultdict
import csv
import gzip
import hashlib
import itertools
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PIN = "685dfaa34c5ab186c691bca3cfe2a22e12517d30"
REGISTERS = (5,16,23,24,25,32,33,48,64,68,69,80,96,101)
SCOPED_DFS = (0,4,5,11,16,17,18,19,20,21,24,25,26,27,28,29,30,31)
LOG = []


def run(command, **kwargs):
    label = "+ " + " ".join(map(str, command))
    print(label, flush=True)
    result = subprocess.run(command, cwd=ROOT, stdout=kwargs.pop("stdout", subprocess.PIPE),
                            stderr=subprocess.PIPE, **kwargs)
    entries = [label]
    for stream in (result.stdout, result.stderr):
        if stream:
            text = stream.decode()
            print(text, end="" if text.endswith("\n") else "\n", flush=True)
            entries.append(text.rstrip())
    entries.append(f"exit_code={result.returncode}")
    LOG.append("\n".join(entries))
    result.check_returncode()
    return result


def digest(path):
    h = hashlib.sha256()
    with Path(path).open("rb") as source:
        for block in iter(lambda: source.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def retain(path, output):
    target = output / (path.name + ".gz")
    with path.open("rb") as source, target.open("wb") as compressed:
        with gzip.GzipFile(filename="", mode="wb", fileobj=compressed, mtime=0) as dest:
            shutil.copyfileobj(source, dest)
    return {"sha256": digest(path), "bytes": path.stat().st_size,
            "compressed_sha256": digest(target)}


def differences(a, b, path=""):
    """Exact parsed binary64/numerical values; no non-position tolerance."""
    if isinstance(a, dict) and isinstance(b, dict):
        result = []
        for key in sorted(a.keys() | b.keys()):
            child = path + "/" + key
            if key not in a or key not in b:
                result.append(child)
            else:
                result.extend(differences(a[key], b[key], child))
        return result
    if isinstance(a, list) and isinstance(b, list):
        if len(a) != len(b):
            return [path + "/length"]
        return list(itertools.chain.from_iterable(
            differences(x, y, path + f"/{i}") for i, (x, y) in enumerate(zip(a, b))))
    # Do not let Python conflate boolean flags with numeric fields.
    if isinstance(a, bool) != isinstance(b, bool) or a != b:
        return [path or "/"]
    return []


def adsb_branch(word):
    tc = word >> 51
    st = (word >> (49 if tc == 29 else 48)) & (3 if tc == 29 else 7)
    if tc == 31 and st < 2:
        return f"TC31.{st}.v{(word >> 13) & 7}"
    if tc in (19, 28, 29, 31):
        return f"TC{tc}.{st}"
    return f"TC{tc}"


def required_adsb():
    branches = []
    for tc in range(32):
        if tc in (19, 28):
            branches += [f"TC{tc}.{st}" for st in range(8)]
        elif tc == 29:
            branches += [f"TC29.{st}" for st in range(4)]
        elif tc == 31:
            branches += [f"TC31.{st}.v{v}" for st in range(2) for v in range(8)]
            branches += [f"TC31.{st}" for st in range(2, 8)]
        else:
            branches.append(f"TC{tc}")
    assert len(branches) == len(set(branches)) == 70
    return branches


def parity_overlay(information, size, address=0x112233):
    # Independent test-harness polynomial long division, not the decoder.
    word = information << 24
    remainder = word
    for bit in range(size * 8 - 1, 23, -1):
        if remainder & (1 << bit):
            remainder ^= 0x1FFF409 << (bit - 24)
    return (word | (remainder ^ address)).to_bytes(size, "big").hex()


def structured_frame(word, context):
    ac12 = (word >> 36) & 4095
    # AC12->AC13 inserts the absent M bit; this also preserves missing codes.
    ac13 = ((ac12 >> 6) << 7) | (ac12 & 63)
    df = 21 if context == "df21" else 20
    altitude = ac13 if context == "df20_matching_altitude" else 0
    return parity_overlay((df << 83) | (altitude << 56) | word, 14)


def load_boundaries(path):
    with path.open(newline="") as source:
        rows = list(csv.DictReader(source))
    if not rows:
        raise ValueError("empty structured Comm-B stratum")
    seen = Counter(int(r["register"]) for r in rows)
    if set(seen) != set(REGISTERS):
        raise ValueError(f"Comm-B register inventory changed: {seen}")
    random_rows = sum(r["tag"].startswith("random_") for r in rows)
    if random_rows < 100000:
        raise ValueError(f"need at least 100000 structured random assignments, got {random_rows}")
    for row in rows:
        word = int(row["word"])
        if not 0 <= word < 2**56:
            raise ValueError("structured payload exceeds 56 bits")
    return rows


def materialize(args, cache):
    inputs, metadata = cache / "input.hex", cache / "metadata.jsonl"
    counts = Counter()
    boundaries = load_boundaries(args.commb_boundaries)
    with inputs.open("w") as dest, metadata.open("w") as meta:
        def emit(wire, source, **details):
            wire = wire.lower()
            bytes.fromhex(wire)
            if len(wire) not in (14, 28):
                raise ValueError("stratum contains a non-7/14-byte frame")
            record = {"index": sum(counts.values()), "stratum": source, "hex": wire, **details}
            dest.write(wire + "\n")
            meta.write(json.dumps(record, separators=(",", ":")) + "\n")
            counts[source] += 1
        if args.corpus:
            path = ROOT / "vendor/rs1090/crates/rs1090/data/long_flight.csv"
            with path.open(newline="") as source:
                for rownum, row in enumerate(csv.reader(source), 1):
                    emit(row[1][18:], "corpus", corpus_row=rownum)
            if counts["corpus"] != 172432:
                raise ValueError(f"corpus cardinality changed: {counts['corpus']}")
        generated = cache / "generated.tsv"
        run([str(ROOT / ".lake/build/bin/messageGenerator"), str(generated),
             str(args.generated), str(args.seed)])
        with generated.open(newline="") as source:
            for index, row in enumerate(csv.DictReader(source, delimiter="\t")):
                if int(row["index"]) != index:
                    raise ValueError("generated index missing or duplicated")
                emit(row["hex"], "generated:" + row["stratum"], generated_index=index,
                     family=int(row["family"]), layout=int(row["layout"]))
        if sum(v for k, v in counts.items() if k.startswith("generated:")) != args.generated:
            raise ValueError("generated-message cardinality mismatch")
        for rownum, row in enumerate(boundaries):
            for context in ("df20_matching_altitude", "df20_none", "df21"):
                emit(structured_frame(int(row["word"]), context), "structured_commb:" + context,
                     commb_row=rownum, target_register=f"{int(row['register']):02x}",
                     tag=row["tag"], hard_valid=row["hard_valid"] == "true",
                     score_pass=row["score_pass"] == "true",
                     target_expected=row["eligible_" + context] == "true")
        if sum(v for k, v in counts.items() if k.startswith("structured_commb:")) != 3 * len(boundaries):
            raise ValueError("structured context cardinality mismatch")
    direct_inputs = cache / "direct-input.txt"
    direct_inputs.write_text("".join(f"{r['register']} {r['word']}\n" for r in boundaries))
    return inputs, metadata, direct_inputs, boundaries, counts


def known_commd(wire, lean, oracle):
    # D001 is only the exact standard 112-bit Comm-D vs oracle rejection.
    data = bytes.fromhex(wire)
    if len(data) != 14 or data[0] >> 3 < 24 or oracle is not None or lean is None:
        return False
    word = int.from_bytes(data, "big")
    syndrome = word
    for bit in range(111, 23, -1):
        if syndrome & (1 << bit):
            syndrome ^= 0x1FFF409 << (bit - 24)
    report = {"df": "CommDExtended", "spare": (word >> 109) & 1,
              "nd": (word >> 104) & 15, "md": list(data[1:11]),
              "parity": wire[-6:], "icao24": f"{syndrome:06x}"}
    return lean == {"consumed": 14, "remainder": "", "crc": syndrome,
                    "oracle": report, "standard": report}


def compare_messages(metadata, lean_path, oracle_path, output, expected):
    counts = Counter()
    df_counts = {str(df): Counter() for df in range(32)}
    adsb_counts = {key: Counter() for key in required_adsb()}
    commb_counts = {f"{reg:02x}": Counter() for reg in REGISTERS}
    fields = Counter()
    first_by_field = {}
    with metadata.open() as meta, lean_path.open() as lean_stream, oracle_path.open() as oracle_stream, \
         gzip.open(output / "mismatches.jsonl.gz", "wt") as mismatch_out, \
         gzip.open(output / "standard-differences.jsonl.gz", "wt") as standard_out:
        for index, triple in enumerate(itertools.zip_longest(meta, lean_stream, oracle_stream)):
            if any(line is None for line in triple):
                raise ValueError(f"message output cardinality mismatch at row {index}")
            record, lean, oracle = map(json.loads, triple)
            if record["index"] != index:
                raise ValueError("message metadata index mismatch")
            wire = record["hex"]
            df = int(wire[:2], 16) >> 3
            views = df_counts[str(df)]
            views["inputs"] += 1
            views["lean_accepted" if lean is not None else "lean_rejected"] += 1
            views["oracle_accepted" if oracle is not None else "oracle_rejected"] += 1
            branch = None
            if df in (17, 18) and len(wire) == 28:
                branch = adsb_branch(int(wire[8:22], 16))
                branch_counts = adsb_counts[branch]
                branch_counts["inputs"] += 1
                branch_counts["lean_accepted" if lean is not None else "lean_rejected"] += 1
                branch_counts["oracle_accepted" if oracle is not None else "oracle_rejected"] += 1
                if record["stratum"] == "generated:encoded_fields":
                    branch_counts["uncorrupted_generated"] += 1
            if df in (20, 21):
                for reg, cov in commb_counts.items():
                    cov["message_candidate_checks"] += 1
                    if lean is not None and "bds" + reg in lean["oracle"]:
                        cov["lean_inferred"] += 1
                    if oracle is not None and "bds" + reg in oracle["oracle"]:
                        cov["oracle_inferred"] += 1
                if "target_register" in record:
                    cov = commb_counts[record["target_register"]]
                    cov["targeted_messages"] += 1
                    expected_candidate = record["target_expected"]
                    actual_candidate = lean is not None and "bds" + record["target_register"] in lean["oracle"]
                    if expected_candidate != actual_candidate:
                        counts["fixture_candidate_mismatches"] += 1
                        mismatch_out.write(json.dumps({**record, "classification": "fixture_candidate_mismatch",
                            "expected_candidate": expected_candidate, "lean": lean, "oracle": oracle}) + "\n")
            projected = None if lean is None else {k: v for k, v in lean.items() if k != "standard"}
            paths = differences(projected, oracle)
            if paths:
                classification = "D001" if known_commd(wire, lean, oracle) else "unclassified"
                counts[classification] += 1
                views[classification] += 1
                if branch:
                    adsb_counts[branch][classification] += 1
                failure = {**record, "classification": classification, "paths": paths,
                           "lean": lean, "oracle": oracle}
                mismatch_out.write(json.dumps(failure, separators=(",", ":")) + "\n")
                if classification == "unclassified":
                    for path in paths:
                        fields[path] += 1
                        first_by_field.setdefault(path, {"index": index, "hex": wire, "branch": branch})
            else:
                counts["exact_matches"] += 1
            if lean is not None and lean["standard"] != lean["oracle"]:
                counts["standard_view_differences"] += 1
                standard_out.write(json.dumps({**record, "paths": differences(lean["standard"], lean["oracle"]),
                                              "standard": lean["standard"], "oracle_view": lean["oracle"]},
                                             separators=(",", ":")) + "\n")
            counts["messages"] += 1
    if counts["messages"] != expected:
        raise ValueError("compared-message cardinality mismatch")
    coverage_errors = []
    for df in SCOPED_DFS:
        if not df_counts[str(df)]["inputs"]:
            coverage_errors.append(f"missing DF{df}")
        if not df_counts[str(df)]["lean_accepted"]:
            coverage_errors.append(f"no accepted Lean DF{df} input")
        if df < 24 and not df_counts[str(df)]["oracle_accepted"]:
            coverage_errors.append(f"no accepted oracle DF{df} input")
    for branch, values in adsb_counts.items():
        if not values["inputs"] or not values["uncorrupted_generated"]:
            coverage_errors.append(f"missing ADS-B uncorrupted branch {branch}")
        if not values["lean_accepted"] or not values["oracle_accepted"]:
            coverage_errors.append(f"no accepted decoder input for ADS-B branch {branch}")
    for reg, values in commb_counts.items():
        if not values["targeted_messages"]:
            coverage_errors.append(f"missing targeted Comm-B register {reg}")
    return {"counts": dict(counts), "df": df_counts, "adsb": adsb_counts,
            "commb": commb_counts, "mismatch_fields": dict(fields),
            "first_mismatch_by_field": first_by_field, "coverage_errors": coverage_errors}


def compare_direct(boundaries, lean_path, oracle_path, output, coverage):
    counts, fields = Counter(), Counter()
    with lean_path.open() as lean_stream, oracle_path.open() as oracle_stream, \
         gzip.open(output / "direct-mismatches.jsonl.gz", "wt") as mismatch_out:
        for index, triple in enumerate(itertools.zip_longest(boundaries, lean_stream, oracle_stream)):
            if any(x is None for x in triple):
                raise ValueError(f"direct-register cardinality mismatch at row {index}")
            row, lean, oracle = triple
            diagnostic, oracle = json.loads(lean), json.loads(oracle)
            lean = diagnostic["oracle"]
            register = f"{int(row['register']):02x}"
            cov = coverage[register]
            cov["direct_inputs"] += 1
            cov["direct_lean_accepted" if lean is not None else "direct_lean_rejected"] += 1
            cov["direct_oracle_accepted" if oracle is not None else "direct_oracle_rejected"] += 1
            expected_accepted = row["hard_valid"] == "true"
            paths = differences(lean, oracle)
            if not diagnostic["decoder_refines"]:
                paths.append("/decoder_refines")
            if not diagnostic["meaning_refines"]:
                paths.append("/meaning_refines")
            if expected_accepted != (lean is not None):
                paths.append("/fixture_hard_valid")
            if paths:
                counts["unclassified"] += 1
                cov["direct_mismatches"] += 1
                mismatch_out.write(json.dumps({"index": index, "register": register, "input": row,
                    "paths": paths, "lean": diagnostic, "oracle": oracle}, separators=(",", ":")) + "\n")
                for path in paths:
                    fields[f"{register}:{path}"] += 1
            else:
                counts["exact_matches"] += 1
            counts["cases"] += 1
    if counts["cases"] != len(boundaries):
        raise ValueError("direct-register count mismatch")
    return {"counts": dict(counts), "mismatch_fields": dict(fields)}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--corpus", action="store_true", required=True)
    parser.add_argument("--generated", type=int, default=100000)
    parser.add_argument("--commb-boundaries", type=Path, required=True)
    parser.add_argument("--seed", type=int, default=1085632)
    parser.add_argument("--diagnostic", action="store_true",
                        help="collect all findings before returning failure (also the normal behavior)")
    parser.add_argument("--output", type=Path, default=ROOT / "tests/evidence/message-differential")
    args = parser.parse_args()
    if args.generated < 100000:
        parser.error("complete message campaign needs at least 100000 generated messages")
    args.commb_boundaries = args.commb_boundaries.resolve()
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)
    run(["python3", "scripts/check_lock.py"])
    actual_pin = subprocess.check_output(["git", "-C", "vendor/rs1090", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
    if actual_pin != PIN:
        raise SystemExit(f"unexpected oracle commit {actual_pin}")
    run(["git", "-C", "vendor/rs1090", "diff", "--exit-code", "HEAD", "--", "crates/rs1090", "Cargo.toml", "Cargo.lock"])
    run(["python3", "scripts/check_commb_fuzz.py", str(args.commb_boundaries)])
    run(["lake", "build", "lean1090", "messageGenerator", "commbDifferential"])
    env = {**os.environ, "CARGO_HOME": str(ROOT / ".cache/cargo"), "CARGO_TARGET_DIR": str(ROOT / ".cache/rs1090-target")}
    run(["cargo", "build", "--locked", "--offline", "--manifest-path", "differential/message-oracle/Cargo.toml",
         "--profile", "dist", "--bin", "lean1090-message-oracle", "--bin", "commb-oracle"], env=env)
    cache = Path(tempfile.mkdtemp(prefix="message-differential-", dir=ROOT / ".cache"))
    inputs, metadata, direct_inputs, boundaries, strata = materialize(args, cache)
    paths = {name: cache / name for name in ("lean.jsonl", "oracle.jsonl", "direct-lean.jsonl", "direct-oracle.jsonl")}
    commands = [([str(ROOT / ".lake/build/bin/lean1090"), "--diagnostic"], inputs, paths["lean.jsonl"]),
                ([str(ROOT / ".cache/rs1090-target/dist/lean1090-message-oracle")], inputs, paths["oracle.jsonl"]),
                ([str(ROOT / ".lake/build/bin/commbDifferential")], direct_inputs, paths["direct-lean.jsonl"]),
                ([str(ROOT / ".cache/rs1090-target/dist/commb-oracle")], direct_inputs, paths["direct-oracle.jsonl"])]
    for command, source, target in commands:
        with source.open() as input_file, target.open("w") as dest:
            run(command, stdin=input_file, stdout=dest)
    message = compare_messages(metadata, paths["lean.jsonl"], paths["oracle.jsonl"], output, sum(strata.values()))
    direct = compare_direct(boundaries, paths["direct-lean.jsonl"], paths["direct-oracle.jsonl"], output, message["commb"])
    for register, values in message["commb"].items():
        if not values["direct_inputs"] or not values["direct_lean_accepted"] or not values["direct_oracle_accepted"]:
            message["coverage_errors"].append(f"missing accepted direct Comm-B register {register}")
    artifacts = {p.name: retain(p, output) for p in [inputs, metadata, direct_inputs, cache / "generated.tsv", *paths.values(), args.commb_boundaries]}
    source_paths = ["spec.lock", "lean-toolchain", "lakefile.toml", "lake-manifest.json", "scripts/check_message_differential.py",
                    "scripts/check_commb_fuzz.py", "scripts/FuzzCommB.lean", "Tests/MessageGenerator.lean", "Tests/CommBDifferential.lean",
                    "differential/message-oracle/Cargo.toml", "differential/message-oracle/Cargo.lock",
                    "differential/message-oracle/src/main.rs", "differential/message-oracle/src/commb.rs", "DISCREPANCIES.md"]
    source_paths += [str(p.relative_to(ROOT)) for folder in ("Spec", "Model", "Impl") for p in sorted((ROOT / folder).rglob("*.lean"))]
    failures = message["counts"].get("unclassified", 0) + message["counts"].get("fixture_candidate_mismatches", 0) + direct["counts"].get("unclassified", 0) + len(message["coverage_errors"])
    summary = {"status": "FAIL" if failures else "PASS", "diagnostic": args.diagnostic,
               "oracle_pin": PIN, "seed": args.seed, "generated_messages": args.generated,
               "strata": dict(strata), "message": message, "direct_registers": direct,
               "artifacts": artifacts, "source_sha256": {p: digest(ROOT / p) for p in source_paths},
               "known_exception": "D001 only: exact standard 112-bit Comm-D frame vs oracle rejection; every instance retained",
               "coverage_note": "All 70 actual ADS-B branches require uncorrupted generated inputs. All 14 Comm-B layouts have targeted three-context messages and direct named-register comparisons. BDS65 has zero whole-message inferred candidates by the pinned API's offset policy; direct decoder coverage is separately reported. Standard/oracle-view differences are retained separately, never used to waive oracle-view failures."}
    (output / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    (output / "commands.log").write_text("\n\n".join(LOG) + "\n")
    print(json.dumps({k: v for k, v in summary.items() if k not in ("artifacts", "source_sha256")}, indent=2, sort_keys=True))
    print(f"Every mismatch is retained in {output}/mismatches.jsonl.gz and direct-mismatches.jsonl.gz.")
    if failures:
        raise SystemExit("Whole-message campaign completed with findings; see exhaustive retained records.")


if __name__ == "__main__":
    main()

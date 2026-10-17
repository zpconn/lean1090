#!/usr/bin/env python3
"""Exhaust the decoder's bounded numerical presentation domains against libm.

The oracle calls pinned rs1090's actual Rust libm dependency, never system
hypot/atan2. These runtime tests do not assert Lean proof semantics for Float.
"""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
PIN = "685dfaa34c5ab186c691bca3cfe2a22e12517d30"
COUNT = 4093**2 + 2045**2 + 512*2 + 1024 + 1


def main():
    os.chdir(ROOT)
    subprocess.run(["python3", "scripts/check_lock.py"], check=True)
    pin = subprocess.check_output(["git", "-C", "vendor/rs1090", "rev-parse", "HEAD"], text=True).strip()
    if pin != PIN:
        raise SystemExit("wrong rs1090 pin")
    subprocess.run(["git", "-C", "vendor/rs1090", "diff", "--exit-code", "HEAD", "--",
                    "crates/rs1090", "Cargo.toml", "Cargo.lock"], check=True)
    out = ROOT / "tests/evidence/numeric-libm"
    out.mkdir(parents=True, exist_ok=True)
    cache = ROOT / ".cache"
    cache.mkdir(exist_ok=True)
    env = {**os.environ, "CARGO_HOME": str(cache / "cargo"),
           "CARGO_TARGET_DIR": str(cache / "rs1090-target")}
    commands = []
    with (out / "commands.log").open("w") as log:
        def run(command):
            commands.append(command)
            print("+ " + " ".join(map(str, command)), flush=True)
            log.write("+ " + " ".join(map(str, command)) + "\n")
            log.flush()
            subprocess.run(command, check=True, env=env, stdout=log, stderr=subprocess.STDOUT)
            log.flush()
        run(["lake", "build", "numericTests"])
        run(["cargo", "build", "--locked", "--offline", "--manifest-path",
             "differential/message-oracle/Cargo.toml", "--profile", "dist", "--bin", "numeric-oracle"])
        with tempfile.TemporaryDirectory(prefix="numeric-libm-", dir=cache) as temp:
            reference = Path(temp) / "reference.bin"
            run([str(cache / "rs1090-target/dist/numeric-oracle"), str(reference)])
            if reference.stat().st_size != COUNT*8:
                raise SystemExit("numeric oracle cardinality changed")
            digest = hashlib.sha256(reference.read_bytes()).hexdigest()
            run([str(ROOT / ".lake/build/bin/numericTests"), str(reference)])
    sources = ["spec.lock", "lean-toolchain", "lakefile.toml", "Impl/Libm.lean",
               "Impl/Numeric.lean", "Impl/Presentation.lean", "Tests/Numeric.lean",
               "scripts/check_numeric.py", "tests/numeric_oracle.rs",
               "differential/message-oracle/Cargo.toml", "differential/message-oracle/Cargo.lock"]
    summary = {"status": "PASS", "oracle_pin": PIN, "libm_version": "0.2.16",
               "exact_comparisons": COUNT, "oracle_bytes": COUNT*8,
               "oracle_sha256": digest, "commands": commands,
               "source_sha256": {p: hashlib.sha256((ROOT/p).read_bytes()).hexdigest() for p in sources},
               "scope": "Exhaustive bounded presentation-domain runtime checks, not Float theorems or the full message differential suite."}
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True)+"\n")
    print(f"Numerical presentation: {COUNT:,} exact pinned-libm comparisons passed.")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Untimed Callgrind collection with preparation/consumption uninstrumented.

All child/control processes share this process's PID namespace. The diagnostic
driver's prepared/run/decoded/consume handshake brackets instrumentation; the
production root's entry/return brackets collection. No decoder or frozen source
is changed, and Ir is never represented as elapsed time or throughput.
"""
import argparse
import hashlib
import json
import selectors
import subprocess
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode")
    parser.add_argument("--binary", default=".cache/gen1-planning/driver-v3/decode-costs")
    parser.add_argument("--output", required=True)
    parser.add_argument("--callers", type=int, default=40)
    parser.add_argument("--phase-timeout", type=int, default=7200)
    args = parser.parse_args()
    output = (ROOT / args.output).resolve()
    output.relative_to(ROOT)
    output.mkdir(parents=True, exist_ok=True)
    if any(output.iterdir()):
        raise RuntimeError("profile output directory must be empty; preserve previous attempts")
    binary = (ROOT / args.binary).resolve()
    corpus = ROOT / "vendor/rs1090/crates/rs1090/data/long_flight.csv"
    valgrind = ROOT / ".cache/profiling-tools/bin/valgrind"
    toolbin = ROOT / ".cache/profiling-tools/root/usr/bin"
    control = toolbin / "callgrind_control"
    vgdb = toolbin / "vgdb"
    root = "lp_lean1090_Lean1090_Impl_" + (
        "cbScorePasses" if args.mode.startswith("score") else
        "commBCoreEligible" if args.mode.startswith("candidate") else "decode")
    prefix = str(output / "vgdb")
    argv = [str(valgrind), "--tool=callgrind", "--instr-atstart=no",
            "--collect-atstart=no", "--toggle-collect=" + root,
            f"--separate-callers={args.callers}", "--vgdb-prefix=" + prefix,
            "--callgrind-out-file=" + str(output / "callgrind.out"),
            "--log-file=" + str(output / "callgrind.log"),
            str(binary), args.mode, str(corpus), "--wait"]
    hashes = {"binary": sha(binary), "corpus": sha(corpus),
              "lock": sha(ROOT / "spec.lock"), "orchestrator": sha(Path(__file__))}
    manifest = {"kind": "untimed_instruction_profile", "status": "running",
                "mode": args.mode, "root": root, "argv": argv,
                "hashes": hashes, "control": [], "events": "Ir",
                "interpretation": "Executed instructions, not elapsed time or throughput.",
                "notes": ["Preparation and output consumption run with instrumentation disabled.",
                          "Only production root calls and their descendants are collected.",
                          "Caller append and heartbeat reads are outside the collection root."]}
    evidence = output / "run.json"

    def save():
        evidence.write_text(json.dumps(manifest, indent=2) + "\n")

    save()
    with (output / "stderr.log").open("w") as stderr, (output / "stdout.jsonl").open("w") as stdout:
        process = subprocess.Popen(argv, cwd=ROOT, stdin=subprocess.PIPE,
                                   stdout=subprocess.PIPE, stderr=stderr, text=True, bufsize=1)
        manifest["pid"] = process.pid
        save()

        def phase(expected):
            with selectors.DefaultSelector() as selector:
                selector.register(process.stdout, selectors.EVENT_READ)
                if not selector.select(args.phase_timeout):
                    raise RuntimeError(f"timed out waiting for {expected} marker")
            line = process.stdout.readline()
            if not line:
                raise RuntimeError(f"driver ended before {expected}; status {process.poll()}")
            stdout.write(line)
            stdout.flush()
            record = json.loads(line)
            if record.get("phase") != expected or record.get("mode") != args.mode:
                raise RuntimeError(f"unexpected driver marker {record}")
            return record

        def monitor(command, label):
            # The driver is blocked on its phase handshake. Sending a harmless
            # poll makes it run Valgrind's normal basic-block checks, avoiding
            # a forced debugger entry into a blocked read via ptrace.
            with (output / (label + ".stdout")).open("w+") as out, (output / (label + ".stderr")).open("w+") as err:
                child = subprocess.Popen(command, cwd=ROOT, text=True, stdout=out, stderr=err)
                polls = 0
                for _ in range(600):
                    if child.poll() is not None:
                        break
                    process.stdin.write("poll\n")
                    process.stdin.flush()
                    polls += 1
                    time.sleep(0.05)
                else:
                    child.kill()
                    child.wait()
                    raise RuntimeError(f"monitor command {label} did not acknowledge")
                out.seek(0)
                err.seek(0)
                result = subprocess.CompletedProcess(command, child.returncode, out.read(), err.read())
            manifest["control"].append({"label": label, "argv": command,
                                        "returncode": result.returncode, "poll_wakeups": polls})
            save()
            return result

        def control_command(arguments, label):
            command = [str(vgdb), "--max-invoke-ms=0", "--vgdb-prefix=" + prefix,
                       "--pid=" + str(process.pid), *arguments]
            result = monitor(command, label)
            if result.returncode:
                raise RuntimeError(f"control command {label} failed")

        def check_state(expected, label):
            command = [str(vgdb), "--max-invoke-ms=0", "--vgdb-prefix=" + prefix,
                       "--pid=" + str(process.pid), "status", "internal"]
            result = monitor(command, label)
            if result.returncode or f"instrumentation: {expected}" not in result.stdout:
                raise RuntimeError(f"could not confirm instrumentation {expected}")

        try:
            prepared = phase("prepared")
            manifest["prepared"] = prepared
            check_state("off", "initial-state")
            control_command(["instrumentation", "on"], "instrument-on")
            check_state("on", "enabled-state")
            process.stdin.write("run\n")
            process.stdin.flush()
            decoded = phase("decoded")
            manifest["decoded"] = decoded
            if decoded["retained"] != prepared["selected"]:
                raise RuntimeError("prepared/retained cardinality mismatch")
            control_command(["dump", "production-root-complete"], "dump")
            control_command(["instrumentation", "off"], "instrument-off")
            check_state("off", "disabled-state")
            process.stdin.write("consume\n")
            process.stdin.flush()
            result = phase("result")
            manifest["result"] = result
            if result["digest"]["count"] != prepared["selected"]:
                raise RuntimeError("retained/result cardinality mismatch")
            trailing, _ = process.communicate(timeout=args.phase_timeout)
            if trailing:
                stdout.write(trailing)
                raise RuntimeError("unexpected trailing driver output")
            if process.returncode:
                raise RuntimeError(f"driver exited {process.returncode}")
            if sha(binary) != hashes["binary"] or sha(ROOT / "spec.lock") != hashes["lock"]:
                raise RuntimeError("binary or lock changed during profile")
            manifest["returncode"] = process.returncode
            manifest["profile_files"] = {p.name: sha(p) for p in sorted(output.glob("callgrind.out*"))}
            if not manifest["profile_files"]:
                raise RuntimeError("no Callgrind output retained")
            manifest["status"] = "passed"
            save()
        except BaseException as error:
            manifest["status"] = "failed"
            manifest["error"] = repr(error)
            if process.poll() is None:
                process.terminate()
                try:
                    process.wait(timeout=15)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait()
            manifest["returncode"] = process.returncode
            save()
            raise
    print(json.dumps({"status": "passed", "mode": args.mode,
                      "selected": manifest["prepared"]["selected"], "evidence": str(evidence)}))


if __name__ == "__main__":
    main()

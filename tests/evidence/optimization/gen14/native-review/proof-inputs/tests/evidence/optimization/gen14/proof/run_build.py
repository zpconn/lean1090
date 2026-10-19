import sys
sys.dont_write_bytecode = True
import datetime, hashlib, json, pathlib, subprocess, sys, time
root = pathlib.Path(__file__).resolve().parents[5]
base = pathlib.Path(__file__).resolve().parent
attempt = sys.argv[1]
folder = base / attempt
folder.mkdir(exist_ok=False)
sources = ['Impl/CommB.lean', 'Proofs/CommBRatio.lean']
def digest(path): return hashlib.sha256(path.read_bytes()).hexdigest()
def utc(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
before = {s: digest(root / s) for s in sources}
for s in sources: (folder / s.replace('/', '-')).write_bytes((root / s).read_bytes())
record = {'command': ['lake', 'build', 'Proofs.CommBRatio'], 'utc_start': utc(), 'monotonic_start': time.monotonic(), 'sources_before': before, 'runner_sha256': digest(pathlib.Path(__file__))}
record_path = base / (attempt + '.json')
assert not record_path.exists()
record_path.write_text(json.dumps(record, indent=2) + '\n')
log = base / (attempt + '.log')
with log.open('x') as output:
    result = subprocess.run(record['command'], cwd=root, stdout=output, stderr=subprocess.STDOUT)
record.update({'exit_code': result.returncode, 'utc_end': utc(), 'monotonic_end': time.monotonic(), 'sources_after': {s: digest(root / s) for s in sources}, 'log_sha256': digest(log)})
record['sources_unchanged'] = record['sources_before'] == record['sources_after']
record_path.write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2), flush=True)
sys.exit(result.returncode)

"""Recover an ignored historical Python cache exactly; never execute its code.

The retained first validator attempt produces the old cache's exact payload
length. Search only the timestamp header within two hours before that saved
attempt, accepting a candidate only if its complete bytes match the already
recorded historical SHA-256. Preserve both changed and restored bytes.
"""
from pathlib import Path
from datetime import datetime, timezone
import hashlib, importlib.util, json, marshal, struct

HERE = Path(__file__).resolve().parent
ROOT = Path.cwd()
TARGET = ROOT/'tests/evidence/optimization/gen12/native-review/__pycache__/validate.cpython-312.pyc'
SOURCE = ROOT/'tests/evidence/optimization/gen12/native-review/attempt-01/validate.py'
MANIFEST = ROOT/'tests/evidence/diagnostics/gen12/historical-inputs.json'
sha = lambda b: hashlib.sha256(b).hexdigest()
expected = json.loads(MANIFEST.read_text())['files'][str(TARGET.relative_to(ROOT))]
observed = (HERE/'observed-validate.cpython-312.pyc').read_bytes()
assert TARGET.read_bytes() == observed
source = SOURCE.read_bytes()
filename = str(SOURCE.parent.parent/'validate.py')
# compile creates a code object only; neither the original validator nor its
# imports/top-level code are evaluated.
code = compile(source, filename, 'exec', dont_inherit=True)
payload = marshal.dumps(code)
assert len(payload)+16 == expected['bytes'] == 35542
upper = int(SOURCE.stat().st_mtime)
lower = upper - 7200
found = []
for stamp in range(lower, upper+1):
    candidate = importlib.util.MAGIC_NUMBER + struct.pack('<III', 0, stamp, len(source)) + payload
    if sha(candidate) == expected['sha256']:
        found.append((stamp,candidate))
assert len(found) == 1, {'matches':len(found),'lower':lower,'upper':upper}
stamp, original = found[0]
assert sha(original) == expected['sha256'] and len(original) == expected['bytes']
backup = HERE/'recovered-original.cpython-312.pyc'
assert not backup.exists()
backup.write_bytes(original)
result = {
    'status':'exact_original_bytes_recovered',
    'recorded_utc':datetime.now(timezone.utc).isoformat(),
    'target':str(TARGET.relative_to(ROOT)),
    'historical_manifest_sha256':sha(MANIFEST.read_bytes()),
    'retained_source':str(SOURCE.relative_to(ROOT)),
    'retained_source_sha256':sha(source),
    'compile_filename':filename,
    'source_bytes':len(source), 'code_payload_bytes':len(payload),
    'searched_timestamp_seconds_inclusive':[lower,upper],
    'matching_timestamp_header':stamp,
    'matching_timestamp_header_utc':datetime.fromtimestamp(stamp,timezone.utc).isoformat(),
    'original_sha256':sha(original), 'original_bytes':len(original),
    'changed_sha256':sha(observed), 'changed_bytes':len(observed),
    'recovery_script_sha256':sha(Path(__file__).read_bytes()),
    'execution':'No validator/import/decoder executed; only Python compilation to an inert code object and hashing.',
    'authorization':'Parent explicitly authorized restoring ignored cache only when exact original bytes match the historical hash; no historical records may change.',
    'interpretation':'The matched source-timestamp header is cache metadata, not an inferred execution time.'}
# The only historical-path write restores precisely the pre-existing expected
# bytes, after retaining the changed bytes and a second original-byte copy.
TARGET.write_bytes(original)
assert TARGET.read_bytes() == original
result['status'] = 'exact_original_bytes_restored'
(HERE/'recovery.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))

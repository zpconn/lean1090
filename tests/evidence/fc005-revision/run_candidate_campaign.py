#!/usr/bin/env python3
"""Run the exact proposed runner body without changing the live frozen runner.
Bash receives the live runner path only as $0, so its original cd resolves the
repository. No source rewrite, mocks or component substitution occurs.
"""
from pathlib import Path
import datetime, hashlib, json, subprocess
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
candidate=ROOT/'.cache/fc005-proposal/scripts/run_differential.sh'
args=['--diagnostic','--corpus','--generated','100000','--commb-boundaries','.cache/gate/commb.csv']
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
lock_before=sha(ROOT/'spec.lock')
record=dict(started_at_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
 method='Exact candidate runner body via bash -c; $0 points to repository/scripts/run_differential.sh solely for unchanged directory resolution; live frozen runner and lock untouched.',
 candidate_path=str(candidate.relative_to(ROOT)),candidate_sha256=sha(candidate),
 arguments=args,live_lock_before=lock_before)
(OUT/'campaign-execution.json').write_text(json.dumps(record,indent=2)+'\n')
with (OUT/'campaign.log').open('w') as log:
 result=subprocess.run(['bash','-c',candidate.read_text(),str(ROOT/'scripts/run_differential.sh'),*args],cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
record.update(exit_code=result.returncode,finished_at_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),live_lock_after=sha(ROOT/'spec.lock'),components=(ROOT/'tests/evidence/differential-campaign/components.tsv').read_text())
assert record['live_lock_after']==lock_before
(OUT/'campaign-execution.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(record,indent=2))
raise SystemExit(result.returncode)

#!/usr/bin/env python3
"""Fail-closed source/site/vector coverage and deterministic fixture assembly."""
import collections, json,re,subprocess,sys
sys.dont_write_bytecode=True
from pathlib import Path
from inventory import ROOT,VENDOR,GENERATED,scan
from port import expr,lit,sub,get,check

def annotate(e):
 for c in e.get('args',[]):annotate(c)
 nullable=e['op'] in ['null','present'] or (e['op'] in ['eq','ne'] and any(c==lit(None)for c in e['args']))
 if nullable:
  for c in e.get('args',[]):
   if c['op']=='get':c['allow_missing']=True
 return e

def main():
 subprocess.run(['git','-C',str(VENDOR),'diff','--exit-code','HEAD','--','crates/rs1090','python/tests','crates/rs1090-wasm/tests','Cargo.toml','Cargo.lock'],check=True)
 pin=subprocess.check_output(['git','-C',str(VENDOR),'rev-parse','HEAD'],text=True).strip()
 assert pin=='685dfaa34c5ab186c691bca3cfe2a22e12517d30'
 rows=scan();assert len(rows)==153
 fixtures=[]
 for filename in ['automatic.jsonl','rust-automatic.jsonl','manual.jsonl']:
  fixtures.extend(json.loads(l)for l in (GENERATED/filename).read_text().splitlines())
 byid={f['id']:f for f in fixtures};assert len(byid)==len(fixtures)
 excluded=json.loads((GENERATED/'exclusions.json').read_text());exc={r['id']:r for r in excluded}
 registration=next(r for r in rows if r['id'].endswith('bds21.rs::test_validate_registration'))
 exc[registration['id']]={'id':registration['id'],'reason':'Optional country/aircraft-database registration sanitizer is outside frozen SCOPE; not Message::from_bytes decoding.', 'assertions':registration['assertions']}
 corpusid='python/tests/test_full.py::test_full'
 rejects=['test_fail_crc','fail crc with message','test_invalid_crc','test_altitude_all_zeros']
 report=[];errors=[]
 for row in rows:
  id=row['id'];f=byid.get(id)
  if id in exc:
   report.append(dict(id=id,status='out_of_scope',reason=exc[id]['reason'],sites=len(row['assertions'])));continue
  if id==corpusid:
   report.append(dict(id=id,status='corpus_runner',sites=len(row['assertions']),runner='Tests/UpstreamCorpus.lean'));continue
  if f is None:errors.append('missing function '+id);continue
  source_lines={a['line']for a in row['assertions']}
  mapped={a['line']for a in f['assertions']}|{a['line']for a in f['exclusions']}
  missing=source_lines-mapped
  if missing:errors.append(f'{id}: unmapped assertion sites {sorted(missing)}')
  # Every active Rust hex literal must occur as an observation (including nested tracks).
  body=re.sub(r'(?m)^\s*//[^\n]*','',row['body'])
  hexes=re.findall(r'hex!\("([0-9A-Fa-f]+)"\)',body)if row['file'].endswith('.rs')else []
  observed=json.dumps(f['observations']).lower()
  for h in hexes:
   if h.lower()not in observed:errors.append(f'{id}: unported hex {h}')
  # Direct CPR source tests first unwrap Message::from_bytes. Preserve that
  # requirement as well as calling the low-level live numerical decoder.
  extra=[]
  for o in f['observations']:
   if o['op'] in ['local','global']:
    extra.append({'op':'frame','hex':o['hex']})
    if o['op']=='global':extra.append({'op':'frame','hex':o['other']})
  f['observations'].extend(extra)
  # Success of each source parser unwrap/pattern branch is explicit, including
  # invalid named-register tests whose enclosing frame must still decode.
  for i,o in enumerate(f['observations']):
   if o['op']=='frame' and not any(id.endswith('::'+s)for s in rejects):
    check(f,row['line'],expr('present',get(i)))
    df=int(o['hex'][:2],16)>>3
    check(f,row['line'],expr('eq',sub(get(i),'df'),lit(str(df))))
    if df in [17,18]:
     tc=int(o['hex'][8:10],16)>>3
     tag='08'if 1<=tc<=4 else '06'if 5<=tc<=8 else '05'if 9<=tc<=18 or 20<=tc<=22 else {19:'09',28:'61',29:'62',31:'65'}.get(tc)
     if tag:check(f,row['line'],expr('eq',sub(get(i),'bds'),lit(tag)))
  for a in f['assertions']:annotate(a['expression'])
  report.append(dict(id=id,status='ported' if row['assertions']or f['assertions']else 'upstream_empty',sites=len(row['assertions']),checks=len(f['assertions']),exclusions=f['exclusions']))
 assert not errors,'\n'.join(errors)
 path=ROOT/'tests/evidence/upstream-unit-tests';path.mkdir(exist_ok=True,parents=True)
 result=dict(pin=pin,source_tests=len(rows),source_assertion_sites=sum(len(r['assertions'])for r in rows),ported_fixture_tests=len(fixtures),expanded_checks=sum(len(f['assertions'])for f in fixtures),status_counts=dict(collections.Counter(r['status']for r in report)),tests=report)
 (path/'coverage.json').write_text(json.dumps(result,indent=2)+'\n')
 (GENERATED/'fixtures.jsonl').write_text(''.join(json.dumps(f,sort_keys=True)+'\n'for f in fixtures))
 print({k:v for k,v in result.items()if k!='tests'})
if __name__=='__main__':main()

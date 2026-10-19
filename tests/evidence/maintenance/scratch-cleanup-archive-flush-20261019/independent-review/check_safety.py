#!/usr/bin/env python3
"""Independent isolated deletion-boundary checks; never runs live cleanup."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
import argparse, contextlib, gzip, hashlib, io, json, os, tempfile
from unittest.mock import patch
ROOT = Path(__file__).resolve().parents[5]
sys.path.insert(0, str(ROOT / 'review/diagnostics'))
import cleanup_verified_scratch as clean
import finish_generation_gate as wrapper
OUT = Path(__file__).parent
sha = lambda b: hashlib.sha256(b).hexdigest()
checks = []

def write(p, b):
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_bytes(b)

class Fixture:
    def __init__(self, root):
        self.root = root
        self.scratch = root / '.cache/message-differential-abcd1234'
        self.archive = root / '.cache/gen2-gate/fixed-message-archive'
        self.receipt = root / 'tests/evidence/new/nested/receipt'
        self.seal = root / 'tests/evidence/optimization/gen2/gate-archive.json'
        self.raw = {'a.txt': b'aaa\n', 'b.txt': b'bbb\n'}
        for name, value in self.raw.items():
            write(self.scratch / name, value)
            write(self.archive / (name + '.gz'), gzip.compress(value, mtime=0))
        self.reseal()
    def reseal(self):
        write(self.archive / 'summary.json', json.dumps({'artifacts': {
            n: {'bytes': len(b), 'sha256': sha(b)} for n,b in self.raw.items()}}).encode())
        rows = {p.name: {'path': str(p.relative_to(self.root)), 'sha256':sha(p.read_bytes()),
                         'bytes':p.stat().st_size} for p in self.archive.iterdir()}
        write(self.seal, json.dumps({'status':'passed','generation':2,
              'components':{'message':{'retained_files':rows}}}).encode())
    def run(self, apply=True, quiet=True, protected=None):
        return clean.cleanup([self.scratch], [self.archive], protected or [], self.receipt, apply, quiet)
    def untouched(self):
        assert {p.name:p.read_bytes() for p in self.scratch.iterdir()} == self.raw
    def refuses(self):
        try:
            value=self.run()
        except (ValueError, OSError):
            pass
        else:
            assert value['results'][0]['status'] in ('retained','retained_or_interrupted')
        for n,b in self.raw.items(): assert (self.scratch/n).read_bytes()==b

def case(name, action):
    with tempfile.TemporaryDirectory(prefix='lean1090-independent-cleanup-') as tmp:
        f=Fixture(Path(tmp))
        with patch.object(clean,'ROOT',f.root): action(f)
    checks.append({'name':name,'status':'passed'})

def dry(f):
    archive={p.name:p.read_bytes() for p in f.archive.iterdir()}
    assert f.run(False)['results'][0]['status']=='would_delete'
    f.untouched();assert archive=={p.name:p.read_bytes() for p in f.archive.iterdir()}
case('default dry run retains exact source and archive bytes',dry)

def actual(f):
    archive={p.name:p.read_bytes() for p in f.archive.iterdir()}; syncs=[]; unlinks=[]
    real_sync=clean.sync_dir;real_unlink=Path.unlink
    def sync(p):syncs.append(p);real_sync(p)
    def unlink(p,*a,**kw):
        doc=json.loads((f.receipt/(f.scratch.name+'.verified.json')).read_text())
        assert len(doc['files'])==2 and all(x['gzip_eof_verified'] for x in doc['files'])
        for parent in [f.root/'tests/evidence',f.root/'tests/evidence/new',f.receipt.parent,f.receipt]: assert parent in syncs
        unlinks.append(p);return real_unlink(p,*a,**kw)
    with patch.object(clean,'sync_dir',sync),patch.object(Path,'unlink',unlink):result=f.run()
    assert result['results'][0]['status']=='deleted' and len(unlinks)==2 and not f.scratch.exists()
    assert archive=={p.name:p.read_bytes() for p in f.archive.iterdir()}
case('apply fsyncs all receipt directory links and records both files before first unlink',actual)

def unknown(f):write(f.scratch/'unknown',b'unique');f.refuses();assert (f.scratch/'unknown').read_bytes()==b'unique'
case('unarchived extra file preserves the complete set',unknown)

def nested(f):(f.scratch/'nested').mkdir();f.refuses()
case('nested scratch directory is refused',nested)

def malformed_archive(f):write(f.archive/'unexpected',b'unbound');f.refuses()
case('unsealed archive member is refused',malformed_archive)

def symlink_archive(f):
    p=f.archive/'a.txt.gz';target=f.root/'outside-gzip';p.rename(target);p.symlink_to(target);f.refuses()
case('symlinked archive file is refused',symlink_archive)

def symlink_source(f):
    p=f.scratch/'a.txt';target=f.root/'outside-raw';p.rename(target);p.symlink_to(target);f.refuses();assert target.read_bytes()==f.raw['a.txt']
case('symlinked raw file is refused and target preserved',symlink_source)

def hardlink(f):os.link(f.scratch/'a.txt',f.root/'outside-raw');f.refuses()
case('hard-linked raw file is refused',hardlink)

def forged_gzip(f):write(f.archive/'a.txt.gz',gzip.compress(b'xxx\n',mtime=0));f.reseal();f.refuses()
case('matching compressed seal with wrong decoded bytes is refused',forged_gzip)

def corrupt_eof(f):p=f.archive/'a.txt.gz';write(p,p.read_bytes()[:-1]);f.reseal();f.refuses()
case('matching compressed seal with truncated gzip trailer is refused',corrupt_eof)

def changes_after_receipt(f,what):
    real=clean.durable
    def record(p,data):
        real(p,data)
        if p.name.endswith('.verified.json'):
            if what=='raw':write(f.scratch/'a.txt',b'xxx\n')
            if what=='unknown':write(f.scratch/'new',b'unrecorded')
            if what=='seal':write(f.seal,f.seal.read_bytes()+b' ')
            if what=='summary':write(f.archive/'summary.json',(f.archive/'summary.json').read_bytes()+b' ')
            if what=='archive':write(f.archive/'a.txt.gz',gzip.compress(b'xxx\n',mtime=0))
    with patch.object(clean,'durable',record):r=f.run()
    assert r['results'][0]['status']=='retained_or_interrupted' and all((f.scratch/n).exists() for n in f.raw)
for what in ['raw','unknown','seal','summary','archive']:
    case('post-verification '+what+' mutation prevents every unlink',lambda f,w=what:changes_after_receipt(f,w))

def protect(f,pick):
    p={'self':f.scratch,'ancestor':f.scratch.parent,'child':f.scratch/'a.txt'}[pick]
    assert f.run(protected=[p])['results'][0]['status']=='retained';f.untouched()
for p in ['self','ancestor','child']:case('explicit protection '+p+' preserves set',lambda f,p=p:protect(f,p))

def noquiet(f):
    try:f.run(quiet=False)
    except ValueError:pass
    else:raise AssertionError('apply accepted missing quiescence')
    f.untouched()
case('apply requires explicit caller quiescence',noquiet)

def source_mismatch(f):
    p=f.scratch/'a.txt';write(p,b'xxx\n');before=p.read_bytes();r=f.run();assert r['results'][0]['status']=='retained_or_interrupted' and p.read_bytes()==before and (f.scratch/'b.txt').exists()
case('equal-length raw SHA mismatch preserves every source',source_mismatch)

def invalid_selection(f):
    for candidate in [f.root/'.cache',f.scratch/'child',f.root/'.cache/message-differential-too-long']:
        try:clean.cleanup([candidate],[f.archive],[],f.receipt,True,True)
        except ValueError:pass
        else:raise AssertionError('unsafe scratch scope accepted')
    f.untouched()
case('broad nested and malformed scratch selections refused',invalid_selection)

def existing_receipt(f):
    f.run(False)
    before={p.name:p.read_bytes() for p in f.receipt.iterdir()}
    try:f.run()
    except ValueError:pass
    else:raise AssertionError('existing receipt accepted')
    assert before=={p.name:p.read_bytes() for p in f.receipt.iterdir()};f.untouched()
case('existing receipt is never overwritten',existing_receipt)

def protected_cli(f):
    parser=argparse.ArgumentParser();clean.arguments(parser)
    with contextlib.redirect_stderr(io.StringIO()):
        try:parser.parse_args(['--scratch','x','--archive-root','y','--receipt','z'])
        except SystemExit as e:assert e.code==2
        else:raise AssertionError('omitted protect decision accepted')
case('CLI requires explicit protect or no-protected decision',protected_cli)

def changed_helper(f):
    helper=f.root/'review/diagnostics/archive_generation_gate.py';write(helper,b'# fixture\n')
    args=['finish_generation_gate.py','--generation','2','--gate-evidence','gate.json','--gate-log','gate.log','--scratch',str(f.scratch),'--archive-root',str(f.archive),'--no-protected-scratch','--receipt',str(f.receipt),'--quiescent','--apply']
    def run(*a,**kw):write(helper,b'# changed\n');return type('Result',(),{'returncode':0})()
    with patch.object(sys,'argv',args),patch.object(wrapper.subprocess,'run',run):
        try:wrapper.main()
        except ValueError:pass
        else:raise AssertionError('changed archiver accepted')
    f.untouched();assert not (f.receipt/'cleanup').exists()
case('wrapper refuses helper mutation even after exit zero',changed_helper)

result={'status':'passed','independent_cases':len(checks),'checks':checks,'scope':'All destructive operations use disposable /tmp fixtures only. No live gate, decoder, build or cleanup run.'}
(OUT/'independent-cases.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({'status':result['status'],'independent_cases':len(checks)}))

#!/usr/bin/env python3
"""Read-only cross-review of the two preserved decode finalizer corrections."""
import sys
sys.dont_write_bytecode = True
import ast
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

E = Path('tests/evidence/diagnostics/gen21')
OUT = E / 'independent-review/producer-tooling-correction-review.json'
bindings = {}
checks = []

def sha(path):
    path = Path(path)
    digest = hashlib.sha256(path.read_bytes()).hexdigest()
    bindings[str(path)] = digest
    return digest

def read(path):
    sha(path)
    return json.loads(Path(path).read_text())

def check(condition, label):
    assert condition, label
    checks.append(label)

def tree(name):
    path = E / name
    sha(path)
    return ast.parse(path.read_text())

def main_body(module):
    return next(n.body for n in module.body if isinstance(n, ast.FunctionDef) and n.name == 'main')

def normalized_render_tail(module):
    body = main_body(module)
    start = next(i for i, n in enumerate(body) if isinstance(n, ast.Assign)
                 and isinstance(n.targets[0], ast.Name) and n.targets[0].id == 'perf')
    tail = body[start:]
    # The two extra prose disclosures and their validation hashes are the only
    # permitted changes to already-reviewed report/count/held-input behavior.
    tail = [n for n in tail if not (isinstance(n, ast.Expr)
            and isinstance(n.value, ast.Call)
            and any(isinstance(c, ast.Constant) and isinstance(c.value, str)
                    and ('The initial finalizer completed archival' in c.value
                         or 'The first resume completed every comparison extractor' in c.value)
                    for c in ast.walk(n)))]
    for node in tail:
        for obj in ast.walk(node):
            if isinstance(obj, ast.Dict):
                pairs = [(k, v) for k, v in zip(obj.keys, obj.values)
                         if not (isinstance(k, ast.Constant) and k.value in
                                 ('finalizer_correction_sha256', 'resume_correction_sha256'))]
                obj.keys = [k for k, _ in pairs]
                obj.values = [v for _, v in pairs]
    return ast.dump(ast.Module(body=tail, type_ignores=[]), include_attributes=False)

def main():
    check(not OUT.exists(), 'New supplemental review does not overwrite the earlier source receipt')
    old_review = read(E / 'independent-review/producer-tooling-review.json')
    check(sha(E / 'independent-review/producer-tooling-review.json') ==
          '8b2edd8d35c28a1e1b243aeee61cd880bb0a6c26b97f87d5ad77abf4a7505941',
          'Original pre-correction source review retained byte-identically')
    for name, expected in old_review['bindings'].items():
        check(sha(name) == expected, 'Original source binding unchanged: ' + name)
    c1 = read(E / 'finalizer-correction.json')
    c2 = read(E / 'finalizer-correction-02.json')
    for number, record in enumerate((c1, c2), 1):
        for name, expected in record['preserved_bindings'].items():
            check(sha(name) == expected, f'Correction {number} preserved binding: ' + name)
    for name, expected in c1['corrected_bindings'].items():
        check(sha(name) == expected, 'First correction new source binding: ' + name)
    check(sha(E / 'resume_finalize_02.py') == c2['corrected_script_sha256'],
          'Second resume source matches its pre-execution receipt')
    original = (E / 'extract_ratio_contexts.py').read_text()
    corrected = (E / 'extract_ratio_contexts_corrected.py').read_text()
    check(original.count('[(19, previous_analysis), (20, analysis)]') == 1,
          'Exactly one stale ratio generation-pair occurrence')
    check(corrected == original.replace('[(19, previous_analysis), (20, analysis)]',
                                        '[(20, previous_analysis), (21, analysis)]'),
          'Ratio correction changes only raw generation selection; reconciliation unchanged')
    modules = [tree(n) for n in ('finalize.py', 'resume_finalize.py', 'resume_finalize_02.py')]
    for name in ('sha', 'read', 'save', 'run', 'history', 'grouped'):
        funcs = [ast.dump(next(n for n in m.body if isinstance(n, ast.FunctionDef) and n.name == name),
                          include_attributes=False) for m in modules]
        check(len(set(funcs)) == 1, 'Unchanged helper implementation: ' + name)
    check(len({normalized_render_tail(m) for m in modules}) == 1,
          'Final report tables, renderer command, input recheck and numeric validation unchanged except disclosed correction metadata')
    # Parse anew because normalization above intentionally edits its local AST.
    final = tree('resume_finalize_02.py')
    run_calls = [n for n in ast.walk(next(n for n in final.body if isinstance(n, ast.FunctionDef)
                                        and n.name == 'main'))
                 if isinstance(n, ast.Call) and isinstance(n.func, ast.Name) and n.func.id == 'run']
    check(len(run_calls) == 1 and ast.literal_eval(run_calls[0].args[1]) == 'report',
          'Second resume runs only renderer; no raw collection/archive/analysis/extractor rerun')
    final_text = (E / 'resume_finalize_02.py').read_text()
    check("wind_rows = read(E / 'wind-native-counts.json')['rows']" in final_text,
          'Missing local restored from hash-bound completed wind-count artifact')
    check('NameError' in (E / 'resume-finalize.stderr').read_text()
          and 'wind_rows' in (E / 'resume-finalize.stderr').read_text(),
          'First resume failure retained with exact missing-local diagnosis')
    check('AssertionError' in (E / 'ratio-contexts.stderr').read_text(),
          'Initial mismatched-generation reconciliation failure retained')
    for label in ('ratio-contexts-02', 'constant-contexts', 'pack-contexts', 'power-contexts',
                  'priority-contexts', 'bit-contexts', 'crc-contexts', 'affine-contexts',
                  'report', 'resume-finalize-02'):
        sha(E / (label + '.stdout'))
        check(sha(E / (label + '.stderr')) == hashlib.sha256(b'').hexdigest(),
              'Completed resumed stage has empty stderr: ' + label)
    validation = read(E / 'validation.json')
    check(validation['status'] == 'passed' and validation['profiles'] == 13,
          'Final validation passed all thirteen unchanged profiles')
    check(validation['finalizer_correction_sha256'] == sha(E / 'finalizer-correction.json')
          and validation['resume_correction_sha256'] == sha(E / 'finalizer-correction-02.json'),
          'Final validation binds both preserved correction records')
    check(validation['analysis_sha256'] == sha(E / 'analysis/analysis.json')
          and validation['archive_manifest_sha256'] == sha(E / 'archive-manifest.json'),
          'Final report binds original immutable completed archive and analysis')
    report = Path(validation['report'])
    check(validation['report_sha256'] == sha(report), 'Current report hash matches final validation')
    check('finalizer-correction.json' in report.read_text()
          and 'finalizer-correction-02.json' in report.read_text(),
          'Report explicitly discloses both producer finalization failures')
    check(json.loads((E / 'resume-finalize-02.stdout').read_text()) == validation,
          'Completed second resume output equals sealed final validation')
    sha(__file__)
    record = {'status': 'passed_read_only_correction_review', 'reviewer': 'payload_roundtrips',
              'completed_utc': datetime.now(timezone.utc).isoformat(), 'findings': [],
              'check_count': len(checks), 'checks': checks, 'bindings': bindings,
              'scope': 'Supplement to the preserved pre-correction source review; source, hash, AST and completed-log checks only. FC independently recounts raw accounting and exact full membership.',
              'retained_failures': ['Initial finalizer generation-pair mismatch stopped at exact raw reconciliation.',
                                    'First resume completed extractors then stopped on missing wind_rows before report write.'],
              'limits': ['No producer source changed or executed by this review.',
                         'No decoder/profile/build rerun; no new measurement or runtime/proof change.']}
    OUT.write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({'status': record['status'], 'checks': len(checks),
                      'review': str(OUT), 'sha256': sha(OUT)}))

if __name__ == '__main__':
    main()

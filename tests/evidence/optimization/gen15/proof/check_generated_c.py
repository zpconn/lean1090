import sys
sys.dont_write_bytecode = True
from pathlib import Path
import hashlib, json, re
base = Path(__file__).resolve().parent
root = base.parents[4]
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
source = root / '.lake/build/ir/Impl/CommB.c'
current = source.read_text()
before = (base / 'before-CommB.c').read_text()
def body(text, name):
    m = re.search(r'(?m)^(?:LEAN_EXPORT|static) [^\n]* ' + re.escape(name) + r'\([^;\n]*\)\{', text)
    assert m, name
    opening = text.index('{', m.start()); depth = 1; position = opening + 1
    while depth:
        depth += (text[position] == '{') - (text[position] == '}'); position += 1
    return text[m.start():position]
name = 'lp_lean1090_Lean1090_Impl_commBPayloadLimit'
old_body = body(before, 'lp_lean1090_Lean1090_Impl_bdsWireValid')
new_body = body(current, 'lp_lean1090_Lean1090_Impl_bdsWireValid')
initializer = body(current, '_init_' + name)
assert old_body.count('lean_cstr_to_nat("72057594037927936")') == 1
assert 'lean_cstr_to_nat' not in new_body
assert 'lean_nat_pow' not in new_body
assert name + ';' in new_body
assert initializer.count('lean_cstr_to_nat("72057594037927936")') == 1
assert name + ' = _init_' + name + '();' in current
assert 'lean_mark_persistent(' + name + ');' in current
snapshot = base / 'after-CommB.c'
assert not snapshot.exists(); snapshot.write_bytes(source.read_bytes())
report = {'status': 'passed', 'source': str(source.relative_to(root)), 'source_sha256': sha(source), 'checker_sha256': sha(__file__), 'before_sha256': sha(base / 'before-CommB.c'), 'snapshot_sha256': sha(snapshot), 'old_guard_parses': 1, 'new_guard_parses': 0, 'initializer_parses': 1, 'global_load_in_guard': True, 'persistent_module_initialization': True, 'scope': 'Generated C inspection only; actual rebuilt native binary is reviewed after root integration.'}
(base / 'generated-c-check.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps(report, indent=2))

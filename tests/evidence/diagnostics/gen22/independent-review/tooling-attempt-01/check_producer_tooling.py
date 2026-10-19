#!/usr/bin/env python3
"""Independent source/AST review only; never execute producer controllers."""
import sys
sys.dont_write_bytecode = True
import ast
import hashlib
import json
import subprocess
from datetime import datetime, timezone
from pathlib import Path

E = Path('tests/evidence/diagnostics/gen22')
OUT = E / 'independent-review/producer-tooling-review.json'
bindings = {}
checks = []

def sha(p):
    p = Path(p)
    result = hashlib.sha256(p.read_bytes()).hexdigest()
    bindings[str(p)] = result
    return result

def read(p):
    sha(p)
    return json.loads(Path(p).read_text())

def check(value, name):
    assert value, name
    checks.append(name)

def normalize(text):
    return text.replace('gen21', 'NEXT_CURRENT').replace('gen20', 'gen21').replace('NEXT_CURRENT', 'gen22')

def function(text, name):
    node = next(n for n in ast.parse(text).body if isinstance(n, ast.FunctionDef) and n.name == name)
    return ast.dump(node, include_attributes=False)

check(not OUT.exists(), 'New review destination preserves prior receipts')
tooling = read(E / 'producer-tooling.json')
preparation = read(E / 'producer-preparation.json')
check(tooling['preparation_sha256'] == sha(E / 'producer-preparation.json'), 'Preparation record association')
check(preparation['diff_sha256'] == sha(E / 'producer-preparation.diff'), 'Exact retained preparation diff')
sources = {}
for name, digest in tooling['files'].items():
    check(sha(name) == digest == preparation['files'][name]['sha256'], 'Current source hash: ' + name)
    prior = preparation['files'][name]
    check(sha(prior['from']) == prior['prior_sha256'], 'Prior immutable source hash: ' + name)
    text = Path(name).read_text()
    ast.parse(text, filename=name)
    sources[Path(name).name] = text
    checks.append('Source syntax only, no import: ' + name)
check(len(tooling['files']) == 12, 'All twelve declared producer scripts reviewed')
old_final = normalize(Path('tests/evidence/diagnostics/gen21/finalize.py').read_text())
final = sources['finalize.py']
for name in ['sha', 'read', 'save', 'run', 'history', 'grouped']:
    check(function(final, name) == function(old_final, name), 'Unchanged full-finalizer helper: ' + name)
check("wind_rows = []" in final and "save(E / 'wind-native-counts.json'" in final,
      'Full finalizer retains wind locals instead of incomplete historical resume state')
check("len(campaign['profiles']) == 13" in final and "assert history() == count" in final,
      'All thirteen profiles and compact historical recheck retained')
check("for name, digest in campaign['protected_inputs'].items():" in final
      and "assert sha(name) == digest" in final, 'All protected campaign inputs rechecked')
check("assert not profile['nonzero_outside_root']" in final
      and "profile['self_event_sum_matches_summary']" in final
      and "profile['stage_attribution_complete']" in final, 'Exact self-event/unique-stage coverage retained')
check("source['pack_fields_fold_anchor'] is None" in final
      and "source['raw_word_syndrome_live_path_verified']" in final
      and "source['decode_frame_with_word_anchor'] == P + 'decodeFrameWithWord'" in final,
      'Absent current pack anchor is accepted only alongside verified direct raw-word path')
check("parsed_wire_word_checked_after_collection" in final
      and "standalone_frame_syndrome_checked_after_collection" in final,
      'Separate raw-word and standalone frame-syndrome checks retained in validation')

crc = sources['extract_crc_contexts.py']
old_crc = normalize(Path('tests/evidence/diagnostics/gen21/extract_crc_contexts.py').read_text())
check(function(crc, 'collect') == function(old_crc, 'collect'),
      'CRC exact stage propagation/self/native/inclusive group reconciliation unchanged')
check("for g in (21, 22)" in crc and "for generation in (21, 22)" in crc,
      'CRC profiles and source records select actual prior/current generations')
for phrase in ["assert observed['parity_byte_wrapper_anchor'] == observed['parity_byte_fold_anchor'] == expected",
               "assert observed['parity_bit_wrapper_anchor'] == observed['parity_bit_fold_anchor'] == 0",
               'assert parser_entries == syndrome_entries == expected',
               'assert not any(reconstruction.values())',
               "'predicted_byte_iterations_not_native_entries': bit_updates // 8",
               "'predicted_bit_updates_not_native_entries': bit_updates"]:
    check(phrase in crc, 'CRC checked observation/prediction distinction: ' + phrase)
check("for kind in ('candidate', 'score')" in crc and "families.get(name, ())" in crc,
      'All three disjoint families and ten overlapping probes are checked separately')
check('Missing standalone boundaries do not imply absent work' in crc
      and 'No wall-clock explanation or performance projection' in crc,
      'CRC interpretation retains native/inlining/overlap/timing limits')

pack = sources['extract_pack_fields.py']
for phrase in ["source['raw_word_syndrome_live_path_verified'] and source['pack_fields_fold_anchor'] is None",
               "gen21/independent-review/source-review.json')['pack_fields_fold_anchor']",
               "assert own+sum(row['inclusive_ir'] for row in direct)==incoming_ir",
               "native['digest']['count'] if generation == 21 else 0",
               "assert total['entry_calls']==(172432 if generation == 21 else 0)",
               "root/'generated-c/Impl/Bits.c'",
               'absence alone is not a zero-inlined-work proof']:
    check(phrase in pack, 'Packing old/live/source reconciliation: ' + phrase)
priority = sources['extract_priority_contexts.py']
check("'decodeFrameWithWord', 'decodeFrame'" in priority and 'selected.discard(None)' in priority,
      'Priority selection adds paired parser without inventing absent packing anchor')
check('assert observed == expected' in priority, 'Priority groups reconcile to all analyzed selected contexts')
ratio = sources['extract_ratio_contexts.py']
check(preparation['files'][str(E / 'extract_ratio_contexts.py')]['from'].endswith('extract_ratio_contexts_corrected.py'),
      'Ratio extractor begins from retained corrected prior implementation')
check('[(21, previous_analysis), (22, analysis)]' in ratio and 'generation in (21,22)' in ratio,
      'Ratio generation/analysis and actual anchor cross-check pairs both advanced together')
for name in ['extract_bit_contexts.py', 'extract_affine_contexts.py']:
    old = normalize(Path('tests/evidence/diagnostics/gen21', name).read_text())
    check(function(sources[name], 'collect') == function(old, 'collect'),
          'Exact existing context accounting retained: ' + name)
check(sources['cleanup_cache.py'] == Path('tests/evidence/diagnostics/gen21/cleanup_cache.py').read_text().replace('gen21', 'gen22'),
      'Reviewed bounded cleanup exactly generation-only; raw perf and unbound files protected')

summary = read('bench/runs/gen22/summary.json')
for name in ['review/diagnostics/analyze_callgrind.py', 'review/diagnostics/write_cost_report.py',
             'review/diagnostics/DecodeCosts.lean']:
    committed = subprocess.check_output(['git', 'show', summary['commit'] + ':' + name])
    check(hashlib.sha256(committed).hexdigest() == sha(name), 'Updated helper matches measured-source committed blob: ' + name)
check(read('tests/evidence/optimization/gen22/diagnostic-tooling/validation.json')['status'] == 'passed',
      'Committed paired-parser tooling has retained passing focused validation')

note = read(E / 'perf-display-note.json')
for name, digest in note['bindings'].items():
    check(sha(name) == digest, 'Preserved executed display-note binding: ' + name)
old_perf = normalize(Path('tests/evidence/diagnostics/gen21/perf/analyze_perf_gen21.py').read_text())
new_perf = sources['analyze_perf_gen22.py']
check(new_perf == old_perf.replace('allleaf.most_common(20)', 'allleaf.most_common(21)'),
      'Only non-path sampling delta is display list limit20→21; classification/records unchanged')
sample = read(E / 'perf/analysis.json')
check(len(sample['all_samples_leaf_top20']) == note['actual_retained_display_rows'] == 21,
      'Actual retained display mismatch explicitly disclosed; source/output not overwritten')
sha(__file__)
record = {'status': 'passed', 'reviewer': 'payload_roundtrips',
          'completed_utc': datetime.now(timezone.utc).isoformat(), 'check_count': len(checks),
          'checks': checks, 'bindings': bindings, 'findings': [],
          'disclosed_nonblocking_findings': [{'kind': 'display_list_label_mismatch',
              'detail': 'The executed all_samples_leaf_top20 list retains21 entries. Complete sample classification/counts/records are unchanged. The producer preserves all executed bytes and the explicit note instead of rerunning.',
              'receipt': str(E / 'perf-display-note.json'), 'sha256': sha(E / 'perf-display-note.json')}],
          'assessment': 'Source/AST and exact identity review of current producer only. Historical generic pack code and current direct raw-word path are distinguished; parser/syndrome counts bind checked postcollection populations, all self costs and selected native/edge contexts remain reconciled, and cleanup remains narrow and durable. No profile timing gain or absent-work inference accepted.',
          'limits': ['No producer source edited/imported/executed.',
                     'No native, build, profile, cleanup or raw-parser rerun.',
                     'FC owns independent actual raw recount and final membership/report checks.']}
with OUT.open('x') as f:
    json.dump(record, f, indent=2); f.write('\n')
print(json.dumps({'status': 'passed', 'checks': len(checks), 'sha256': sha(OUT)}))

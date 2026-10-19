#!/usr/bin/env python3
"""Check current documentation contracts, claims and local links.

Historical reports/evidence copies are deliberately excluded: their original
relative paths and wording are immutable records, not current navigation.
This checker builds nothing. --check-cli runs just the README's one-message
example using an already-built executable.
"""
import argparse
import sys
sys.dont_write_bytecode = True
import csv
from decimal import Decimal
import hashlib
import json
from pathlib import Path
import re
import subprocess
from urllib.parse import unquote, urlsplit

ROOT = Path(__file__).resolve().parents[5]
DOCUMENTS = ['README.md', 'THEOREMS.md', 'SCOPE.md', 'TRUSTED.md',
             'DISCREPANCIES.md', 'THIRD_PARTY_NOTICES.md', 'docs/README.md',
             'docs/OPTIMIZATION.md', 'docs/EVIDENCE.md', 'docs/DEVELOPING.md']
MESSAGE = '8D4840D6202CC371C32CE0576098'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def without_fences(text):
    return re.sub(r'(?ms)^```[^\n]*\n.*?^```\s*$', '', text)


def anchors(text):
    counts, result = {}, set()
    for heading in re.findall(r'(?m)^#{1,6}\s+(.+?)\s*#*$', without_fences(text)):
        base = re.sub(r'[^\w\- ]', '', heading.lower()).replace(' ', '-')
        index = counts.get(base, 0)
        counts[base] = index + 1
        result.add(base if not index else base + '-' + str(index))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, default=ROOT / '.cache/presentation-check.json')
    parser.add_argument('--check-cli', action='store_true')
    parser.add_argument('--generation', type=int, default=17)
    args = parser.parse_args()
    generation = args.generation
    assert generation >= 0
    inputs = set(DOCUMENTS + ['Capstones.lean', 'scripts/Final.lean', 'bench/results.csv',
        f'bench/runs/gen{generation}/summary.json', f'bench/runs/gen{generation}/results-review.json',
        f'tests/evidence/optimization/gen{generation}/fixed-message/summary.json',
        f'tests/evidence/optimization/gen{generation}/fresh-message/summary.json',
        f'tests/evidence/optimization/gen{generation}/gate-full.log',
        'docs/images/throughput-data.json', 'docs/licenses/rust-libm-0.2.16.txt'])
    before = {p: sha(ROOT / p) for p in sorted(inputs)}
    readme = (ROOT / 'README.md').read_text()
    checks, findings = {}, []

    def check(name, condition):
        checks[name] = bool(condition)
        if not condition:
            findings.append(name)

    source_defs = re.findall(r'(?ms)^def \w+.*?(?=\n\n/--|\n\nend Lean1090.Capstones)',
                             (ROOT / 'Capstones.lean').read_text())
    section = readme.split('<!-- CAPSTONES:BEGIN -->', 1)[1].split('<!-- CAPSTONES:END -->', 1)[0]
    printed = re.findall(r'```lean\n(.*?)\n```', section, re.S)
    check('exactly_23_capstone_definitions_verbatim', len(source_defs) == 23 and printed == ['\n\n'.join(source_defs)])
    names = [re.match(r'def (\w+)', d)[1] for d in source_defs]
    final_names = re.findall(r'(?m)^theorem (\w+) :', (ROOT / 'scripts/Final.lean').read_text())
    check('final_manifest_binds_exactly_the_same_23_names', names == final_names)
    theorem_blocks = re.findall(r'```lean\n(.*?)\n```', (ROOT / 'THEOREMS.md').read_text(), re.S)
    check('theorem_guide_contains_all_exact_definitions', all(d in theorem_blocks for d in source_defs))
    check('README_discloses_numerical_and_physical_model_limits', all(x in readme for x in
        ('tested, not proved equal to real arithmetic', 'unmodeled physical receiver', 'every byte input',
         'they do not establish performance on other hosts or inputs')))
    check('README_preserves_matched_measurement_scope', all(x in readme for x in
        ('recorded single-core workload', 'including construction of its complete result',
         '172,432', 'three warmup pairs', '21 interleaved AB', 'medians')))
    check('README_bootstrap_executes_preparation', 'python3 review/packaging/bootstrap.py --prepare' in readme)
    developing = (ROOT / 'docs/DEVELOPING.md').read_text()
    check('strict_reproduction_uses_current_publication_gate_bindings',
          '--gate-evidence tests/evidence/publication/gate-evidence.json' in developing
          and '--gate-log tests/evidence/publication/gate-full.log' in developing
          and '--gate-evidence bench/runs/gen10/gate-evidence.json' not in developing)
    check('README_headline_section_is_concise', len(readme.split('## Try it', 1)[0].split()) < 150)
    check('README_has_no_trailing_spaces_or_tabs', not re.search(r'(?m)[ \t]+$', readme) and '\t' not in readme)
    check('README_coverage_claim_is_scoped', 'complete branch coverage' not in readme)
    with (ROOT / 'bench/results.csv').open(newline='') as stream:
        rows = list(csv.DictReader(stream))
    current = {r['mode']: r for r in rows if int(r['generation']) == generation}
    check('latest_generation_has_exactly_both_modes', set(current) == {'decode', 'cpr'}
          and len(rows) == 2 * (generation + 1))
    summary = json.loads((ROOT / f'bench/runs/gen{generation}/summary.json').read_text())
    check('README_timed_commit_is_current_recorded_generation', summary['commit'] in readme and all(r['commit'] == summary['commit'] for r in current.values()))
    measurements = {}
    for mode in ('decode', 'cpr'):
        row = current[mode]
        ratio = Decimal(row['lean1090_msg_s']) / Decimal(row['rs1090_msg_s'])
        measurements[mode] = {'lean_msg_s': row['lean1090_msg_s'], 'rs1090_msg_s': row['rs1090_msg_s'], 'ratio_recomputed': str(ratio)}
        check(mode + '_README_rounded_values_match_CSV', all(x in readme for x in
            (f"{Decimal(row['lean1090_msg_s']):,.0f} msg/s", f"{Decimal(row['rs1090_msg_s']):,.0f} msg/s", f'{ratio:.5f}×')))
        recorded = next(r for r in summary['results'] if r['mode'] == mode)
        check(mode + '_CSV_agrees_with_native_sample_summary', abs(ratio - Decimal(str(recorded['lean_over_rust']))) < Decimal('1e-14'))
    headline = readme.split('## Try it', 1)[0]
    check('headline_ratios_match_latest_generation', f'generation {generation}' in headline and all(
        f"{Decimal(measurements[mode]['ratio_recomputed']):.5f}×" in headline for mode in ('decode', 'cpr')))
    reached = {}
    for mode in ('decode', 'cpr'):
        medians = next(r for r in summary['results'] if r['mode'] == mode)['medians_nanoseconds']
        assert all(type(medians[name]) is int and medians[name] > 0 for name in ('rs1090', 'lean1090'))
        reached[mode] = medians['rs1090'] >= 2 * medians['lean1090']
    status_text = ('both targets are reached.' if all(reached.values()) else
                   'decode has reached its target; CPR remains below target.' if reached['decode'] else
                   'CPR has reached its target; decode remains below target.' if reached['cpr'] else
                   'neither target is reached.')
    check('both_targets_explicit_and_status_matches_exact_medians', '2.00× in both modes' in headline
          and status_text in headline)
    review = json.loads((ROOT / f'bench/runs/gen{generation}/results-review.json').read_text())
    check('independent_current_result_review_passed', review['status'] in
          ('passed', 'passed_with_documented_clock_and_host_limitations') and not review['findings']
          and review['generation'] == generation and review['commit'] == summary['commit']
          and review['binary_sha256'] == summary['binary_sha256'])
    check('target_decisions_match_independent_result_review', all(
        review[mode + '_target_ratio'] == {'numerator': 2, 'denominator': 1}
        and review[mode + '_threshold_reached'] is reached[mode] for mode in ('decode', 'cpr'))
        and review['all_mode_thresholds_reached'] is all(reached.values()))
    campaign_counts = {}
    for kind in ('fixed', 'fresh'):
        campaign = json.loads((ROOT / f'tests/evidence/optimization/gen{generation}/{kind}-message/summary.json').read_text())
        count = campaign['message']['counts']
        campaign_counts[kind] = count
        check(kind + '_whole_message_claim_and_scope_match', campaign['status'] == 'PASS' and count['messages'] == 10476164
              and count['exact_matches'] + count['D001'] == count['messages']
              and len(campaign['message']['df']) == 32 and len(campaign['message']['adsb']) == 70
              and len(campaign['message']['commb']) == 14 and not campaign['message']['coverage_errors']
              and not campaign['message']['mismatch_fields'])
    log = (ROOT / f'tests/evidence/optimization/gen{generation}/gate-full.log').read_text()
    check('unit_and_witness_claims_are_in_full_gate_evidence',
          '  "assertions": 1011,' in log and '  "expanded_checks": 1011,' in log
          and 'Witness axiom audit: 152 proofs; only the three permitted axioms (or fewer).' in log)
    check('all_capstone_types_and_axioms_passed_the_full_gate',
          'Final manifest: 23 exact theorem types and permitted axioms.' in log)
    graph = json.loads((ROOT / 'docs/images/throughput-data.json').read_text())
    check('graph_binds_current_CSV_and_all_generations', graph['source_sha256'] == sha(ROOT / 'bench/results.csv')
          and graph['generations'] == list(range(generation + 1)) and graph['frame_count'] == generation + 1
          and Decimal(graph['target_ratio']) == Decimal('2.00')
          and [{k: v for k, v in r.items() if k != 'ratio_recomputed'} for r in graph['rows']] == rows)
    check('graph_artifact_hashes_match', all(sha(ROOT / 'docs/images' / name) == row['sha256'] for name, row in graph['outputs'].items()))
    links = []
    for name in DOCUMENTS:
        document = ROOT / name
        text = without_fences(document.read_text())
        for target in re.findall(r'\]\(([^\s)]+)(?:\s+"[^"]*")?\)', text):
            url = urlsplit(target.strip('<>'))
            if url.scheme or url.netloc:
                continue
            resolved = (document.parent / unquote(url.path)).resolve() if url.path else document
            valid = resolved.exists()
            if valid and url.fragment and resolved.suffix == '.md':
                valid = unquote(url.fragment) in anchors(resolved.read_text())
            links.append({'document': name, 'target': target, 'valid': valid})
    check('all_current_document_local_links_and_anchors_resolve', all(r['valid'] for r in links))
    notices = (ROOT / 'THIRD_PARTY_NOTICES.md').read_text()
    check('Rust_libm_notice_file_hash_matches_document', sha(ROOT / 'docs/licenses/rust-libm-0.2.16.txt') in notices)
    upstream_license = ROOT / 'vendor/rs1090/license.md'
    if upstream_license.exists():
        quoted = notices.split('> MIT License', 1)[1].split('\n## Rust libm', 1)[0]
        notice = 'MIT License' + '\n'.join(re.sub(r'^> ?', '', line) for line in quoted.splitlines())
        check('rs1090_license_notice_matches_acquired_original', notice.strip() == upstream_license.read_text().strip()
              and sha(upstream_license) in notices)
    cli = {'executed': False}
    if args.check_cli:
        executable = ROOT / '.lake/build/bin/lean1090'
        binary_before = sha(executable)
        result = subprocess.run([str(executable), MESSAGE], capture_output=True, text=True, timeout=60)
        expected = json.loads(re.search(r'```json\n(.*?)\n```', readme, re.S)[1])
        cli = {'executed': True, 'argv': ['.lake/build/bin/lean1090', MESSAGE],
               'binary_sha256': binary_before, 'exit_code': result.returncode,
               'stdout': result.stdout, 'stderr': result.stderr}
        check('README_example_matches_actual_already_built_CLI', result.returncode == 0 and not result.stderr
              and json.loads(result.stdout) == expected and sha(executable) == binary_before)
    check('all_reviewed_input_bytes_unchanged_during_check', all(sha(ROOT / p) == digest for p, digest in before.items()))
    output = {'status': 'passed' if not findings else 'failed', 'generation': generation,
              'checks': checks, 'findings': findings,
              'inputs': before, 'capstones': names, 'measurements': measurements, 'campaign_counts': campaign_counts,
              'local_links': links, 'cli_example': cli, 'checker_sha256': sha(__file__),
              'scope': 'Current documentation only. Historical reports and evidence snapshots intentionally excluded; no build, test campaign, native profile or benchmark execution.'}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(output, indent=2, ensure_ascii=False) + '\n')
    print(json.dumps({'status': output['status'], 'checks': len(checks), 'local_links': len(links),
                      'findings': findings, 'output': str(args.output)}, indent=2))
    if findings:
        raise SystemExit(1)


if __name__ == '__main__':
    main()

#!/usr/bin/env python3
"""Check emitted boundary coverage; do not claim an oracle differential result."""
import csv
import hashlib
import json
import sys
from collections import defaultdict
from fractions import Fraction
from pathlib import Path

source = Path(sys.argv[1] if len(sys.argv) > 1 else '.cache/commb-generated.csv')
required = {
    5: ['ac12_50000ft_q', 'ac12_50000ft_gillham', 'position_tc_inference'],
    16: ['capability_header', 'capability_reserved'],
    23: ['required_identification', 'required_zero_suffix'],
    33: ['airline_status', 'airline_placeholder1', 'airline_placeholder2', 'registration_unknown_count'],
    32: ['identification_header'], 48: ['ra_header'],
    64: ['mcp_rounded50000', 'fms_rounded50000', 'pressure_800_1200'],
    68: ['figure_of_merit_1_2', 'wind_250', 'temperature_m80_60_wrap'],
    69: ['temperature_m80_60', 'missing_temperature_sign'],
    80: ['roll_45', 'groundspeed_700', 'tas_80_600', 'rate_sentinel',
         'opposite_turn_penalty', 'exact_minus3_inclusive'],
    96: ['ias_500', 'mach_1', 'inertial_rate_6000_sentinels', 'barometric_rate_sentinels',
         'ias_mach_ratio_250_800'],
    101: ['operational_status_tc'],
}
registers = {5,16,23,24,25,32,33,48,64,68,69,80,96,101}
scored = {64,68,69,80,96}
counts = defaultdict(lambda: dict(rows=0, hard_pass=0, eligible_df20=0,
                                score_below=0, score_equal=0, score_above=0))
tags = set()
brackets = defaultdict(set)
exact = []
selected_edges = defaultdict(dict)
random_count = 0
initial_seed = None
with source.open() as stream:
    for row in csv.DictReader(stream):
        reg = int(row['register'])
        word = int(row['word'])
        tag = row['tag']
        initial_seed = initial_seed if initial_seed is not None else int(row['seed'])
        if not 0 <= word < 2**56:
            raise SystemExit(f'Out-of-width encoded payload: {reg}:{tag}')
        score = Fraction(int(row['score_num']), int(row['score_den']))
        hard = row['hard_valid'] == 'true'
        passes = row['score_pass'] == 'true'
        if passes != (score >= -3):
            raise SystemExit(f'Incorrect inclusive threshold fixture: {reg}:{tag}')
        if tag == 'random_structured' and reg != 5 and not hard:
            raise SystemExit(f'Structured inside-envelope assignment rejected: {reg}:{word}')
        if tag.startswith('random_'):
            random_count += 1
        c = counts[reg]
        c['rows'] += 1
        c['hard_pass'] += hard
        c['eligible_df20'] += row['eligible_df20_matching_altitude'] == 'true'
        c['score_below'] += score < -3
        c['score_equal'] += score == -3
        c['score_above'] += score > -3
        tags.add((reg, tag))
        if tag.startswith('score_nearest_below:'):
            if not hard or score >= -3:
                raise SystemExit(f'Bad hard-valid score lower bracket: {reg}:{tag}')
            brackets[reg].add('below')
        if tag.startswith('score_nearest_at_or_above:'):
            if not hard or score < -3:
                raise SystemExit(f'Bad hard-valid score upper bracket: {reg}:{tag}')
            brackets[reg].add('above')
        if tag == 'bound:exact_minus3_inclusive':
            exact.append({k: row[k] for k in ('word','hard_valid','score_num','score_den','score_pass')})
        if reg == 64 and tag in {'bound:mcp_rounded50000','bound:fms_rounded50000'}:
            field = 'selected_mcp' if 'mcp' in tag else 'selected_fms'
            fields = dict(item.split(':', 1) for item in row['named_fields'].split(';'))
            selected_edges[field][int(fields[field])] = hard
if set(counts) != registers:
    raise SystemExit(f'Missing registers: {registers - set(counts)}')
for reg, names in required.items():
    for name in names:
        if (reg, 'bound:' + name) not in tags:
            raise SystemExit(f'Missing mandatory boundary family: {reg}:{name}')
for reg, start, stop in [(24, 1, 57), (25, 57, 113)]:
    for code in range(start, stop):
        if (reg, f'field_extrema:bds{code:02x}') not in tags:
            raise SystemExit(f'Missing support-bitmap flag coverage: {reg}:{code}')
status_fields = {
    64: ['selected_mcp','selected_fms','barometric_setting'],
    68: ['wind_speed','wind_direction','pressure','turbulence','humidity'],
    69: ['turbulence','wind_shear','microburst','icing','wake_vortex',
         'static_temperature','static_pressure','radio_height'],
    80: ['roll','track','groundspeed','track_rate','TAS'],
    96: ['heading','IAS','Mach','vrate_barometric','vrate_inertial'],
}
for reg, names in status_fields.items():
    for name in names:
        for state in ['zero', 'nonzero']:
            if (reg, f'status_absent_{state}:{name}') not in tags:
                raise SystemExit(f'Missing status/value consistency coverage: {reg}:{name}:{state}')
for reg in scored:
    if brackets[reg] != {'below', 'above'}:
        raise SystemExit(f'Missing hard-valid -3 score brackets for register {reg}')
for field in ['selected_mcp', 'selected_fms']:
    if any(selected_edges[field].get(code) is not True for code in range(3125, 3131)):
        raise SystemExit(f'Rounded50000ft plateau lost: {field}')
    if selected_edges[field].get(3131) is not False:
        raise SystemExit(f'Above-rounded50000ft boundary not rejected: {field}')
if not any(int(r['word']) == 40532396648603648 and int(r['score_num']) == -3 and
           int(r['score_den']) == 1 and r['hard_valid'] == r['score_pass'] == 'true' for r in exact):
    raise SystemExit('Missing exact -3 BDS50 inclusive fixture')
summary = dict(
    command=f'lake env lean --run scripts/FuzzCommB.lean {source} {random_count} {initial_seed}',
    seed=initial_seed, random_assignments=random_count,
    total_rows=sum(c['rows'] for c in counts.values()),
    sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
    register_counts=counts, exact_threshold_fixture=exact,
    status='Reference-fixture generation and coverage only; not full-register differential agreement.')
if len(sys.argv) > 2:
    Path(sys.argv[2]).write_text(json.dumps(summary, indent=2) + '\n')
print(f"Comm-B coverage: {summary['total_rows']} rows, {random_count} random assignments, "
      f"14 registers, {sum(map(len, required.values()))} mandatory bound families, "
      'all five -3 brackets, one exact -3 payload.')

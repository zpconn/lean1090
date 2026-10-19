#!/usr/bin/env python3
"""Render only this completed diagnostic's retained numeric observations."""
import sys
sys.dont_write_bytecode = True
from pathlib import Path
import gzip, json

ROOT = Path.cwd()
B = ROOT / 'tests/evidence/diagnostics/gen21-cpr'
load = lambda p: json.loads(p.read_text())
gz = lambda p: json.loads(gzip.decompress(p.read_bytes()))
a = gz(B/'analysis/analysis.json.gz')
d = gz(B/'decoder-stages.json.gz')
n = gz(B/'numeric-contexts.json.gz')
v = load(B/'retained/validation/summary.json')
archive = load(B/'archive-manifest.json')
perf = load(B/'perf/completion.json')
run = load(B/'retained/callgrind/run.json')
source = load(B/'independent-review/source-review.json')
tc = load(B/'table-contexts-summary.json')
remaining = load(B/'remaining-conversion-contexts.json')
assert remaining['status'] == 'passed' and remaining['raw_profile_sha256'] == a['raw_sha256']
assert a['total_Ir'] == run['primary_ir'] and v['status'] == archive['status'] == 'passed'
total = a['total_Ir']
labels = {'numeric_geography':'Numeric geography and conversion','motion_policy':'Motion policy, excluding numeric geography',
          'airborne_pairing_policy':'Airborne pairing policy, excluding motion/geography',
          'surface_reference_policy':'Surface reference policy, excluding geography',
          'state_tracking_control':'Remaining state/tracking control','tracking_projection':'Tracking projection',
          'loop_output_control':'Loop/output/retained-return control'}
stages = [(labels[k],x) for k,x in a['exclusive_stages'].items() if k in labels]
dl = {'frame_crc':'frame/CRC','commb_inference':'Comm-B inference','semantic_oracle_values':'semantic/oracle values',
      'adsb_fields':'ADS-B fields','output_model_control':'output/model control'}
stages += [('Decoder: '+dl[k],x) for k,x in d['exclusive_decoder_stages'].items()]
assert sum(x for _,x in stages) == total
largest_label,largest_value=max(stages,key=lambda x:x[1])
table_counts='\n'.join(f"| {r['stage']} | {r['lookup_entries']:,} | {r['direct_formula_fallback_calls']:,} | {r['table_lookup_calls_from_verified_branch_partition']:,} |" for r in tc['by_stage'])
table = '\n'.join(f'| {label} | {value:,} | {100*value/total:.4f}% |' for label,value in sorted(stages,key=lambda x:-x[1]))
helpers = a['helper_observations_non_additive']
anchors = a['native_anchor_counts_and_non_additive_inclusive']
selected = []
for name in ['streamStep','toFloat','haversineFloat','stepAirborne','stepSurface','validMotion','nearestAirport','decodeGlobalFloat','decodeLocalFloat']:
    row = anchors['lp_lean1090_Lean1090_Impl_CPR_Policy_'+name]
    selected.append((name,row['native_entries'],row['inclusive_Ir_non_additive']))
for name in ['round','exponent','powerTwo','fromBits']:
    rows=[r for r in helpers if r['stage'] in {'numeric_geography','motion_policy','airborne_pairing_policy'}
          and r['symbol']=='lp_lean1090_Lean1090_Impl_Binary64_'+name]
    for row in rows:
        selected.append((row['stage']+' Binary64.'+name,row['native_entries'],row['inclusive_Ir_non_additive']))
fallback_rows = [r for r in helpers if r['stage'] == 'numeric_geography'
                 and r['symbol'] == 'lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback']
for row in fallback_rows:
    selected.append(('Numeric-geography toFloatFallback',row['native_entries'],row['inclusive_Ir_non_additive']))
helper_table='\n'.join(f'| `{label}` | {calls:,} | {cost:,} |' for label,calls,cost in sorted(selected,key=lambda x:-x[2]))
edges=[r for r in n['grouped_direct_edges'] if r['stage']=='numeric_geography']
edge_table='\n'.join(f"| `{r['direct_caller']}` → `{r['target']}` | {r['calls']:,} | {r['inclusive_Ir_non_additive']:,} |" for r in edges[:15])
conversion_targets = {'lp_lean1090_Lean1090_Impl_CPR_Policy_toFloat',
                      'lp_lean1090_Lean1090_Impl_CPR_Policy_toFloatFallback'}
conversion_edges = [r for r in n['grouped_direct_edges'] if r['target'] in conversion_targets]
conversion_table = '\n'.join(f"| {r['stage']} | `{r['direct_caller']}` → `{r['target']}` | {r['calls']:,} | {r['inclusive_Ir_non_additive']:,} |" for r in conversion_edges)
r=v['result']; recoveries=a['explicit_chain_recoveries']; count=sum(x['self_Ir'] for x in recoveries)
text=f'''# Generation 21: live decode-plus-CPR instruction diagnostic

The full corpus loop executed **{total:,} collected instructions**. {largest_label} is the largest individual
category at {100*largest_value/total:.2f}% after separating the decoder's stages.
The combined decoder contributes {100*a['exclusive_stages']['decoder']/total:.2f}%. These are untimed instruction
observations, not throughput estimates or predictions of an optimization's gain.

The timed source is `{source['timed_commit']}`; the diagnostic
checkout is the source-equivalent artifact commit
`{source['commit']}`. Actual worker SHA-256:
`{source['worker_sha256']}`.
The unchanged diagnostic driver reuses 21 production/model objects from all
22 freshly timed native sets, replacing only the worker object. The
[source/native review](../tests/evidence/diagnostics/gen21-cpr/independent-review/source-review.json)
checks the live generated C and linked functions. No production code, proofs,
frozen files or build configuration changed during diagnosis.

The collected path mirrors the frozen benchmark: immediate `Impl.decode`,
tracking projection, `Impl.CPR.Policy.streamStep`, then array append. Its timed
loop does not call the batch `Impl.decodePositions` API. Preallocation and the
empty state are outside the collection root. Full decoded output and final
state remain live through its return; the loop/output category includes that
diagnostic return packaging. Timestamp/airport loading, output consumption,
and batch validation are outside collection. Eager module initialization is
outside; first-use lazy constants reached by the root remain included.

All 172,432 timestamp/input rows and 6,903 airport coordinates match the
frozen worker byte-for-byte. Empty state, absent reference and the always-false
reference-update callback are unchanged. Every per-message tracking row and
the final worker state projection match exactly: 172,432 bit-identical rows,
including 11,347 positions. The differential tolerance remains 1e-9 degrees;
bit identity is reported for these particular rows. Complete final
`StreamState` and every routed position also equal the actual batch API after
collection. The final state has 29 aircraft, two with positions, and no global
reference; this corpus alone does not cover worldwide tracking policies.

The complete message digest equals the same-generation decode diagnostic:
{r['digest']['count']:,} messages, {r['digest']['repr_bytes']:,} representation bytes,
FNV-1a-64 `{r['digest']['fnv1a64_decimal']}`. The complete state has
{r['full_state_repr_bytes']:,} representation bytes, digest
`{r['full_state_fnv1a64_decimal']}`. Routed reports include {r['airborne']:,}
airborne, {r['surface']:,} surface and {r['other']:,} other messages.
[Full validation](../tests/evidence/diagnostics/gen21-cpr/retained/validation/summary.json)
retains commands, complete row/state checks and unchanged input hashes.

The following rows form one **exclusive self-cost partition**. The five
decoder rows replace its combined subtotal of {a['exclusive_stages']['decoder']:,};
they must not be added to that subtotal again. Runtime, allocator, rational
and GMP descendants inherit their actual calling stage.

| Stage | Collected Ir | Share |
|---|---:|---:|
{table}
| **Total** | **{total:,}** | **100%** |

There are no ambiguous merged contexts or unexplained outside-root events.
Exactly {len(recoveries)} libm/PLT contexts totaling {count} self instructions lack a positive
path from the collection root but retain explicit caller chains containing
that exact root. The previously reviewed algorithm applies the same stage
transitions along those chains. Incoming edges from other unreachable nodes
do not establish root reachability. Foreign chains and remaining outside-root
events still fail. All eight attribution fixtures pass. The same previously reviewed
attribution algorithm is used unchanged. [Complete compressed analysis](../tests/evidence/diagnostics/gen21-cpr/analysis/analysis.json.gz),
[decoder subpartition](../tests/evidence/diagnostics/gen21-cpr/decoder-stages-summary.json).

These helper observations are **overlapping inclusive costs**. They nest
inside the exclusive rows and each other; do not sum them into another total.

| Live helper | Native entries | Inclusive Ir |
|---|---:|---:|
{helper_table}

The current `toFloat` returns positive zero for zero and uses integer bit
assembly for nonzero values with numerator magnitude below 2^53, denominator
exactly 2^k and k at most 1074. Every other value calls `toFloatFallback`, which
retains the original rational rounding, exponent and bit-pattern construction.
Both paths use `Float.ofBits`. Haversine converts four coordinates;
geographic outputs return to exact rationals through `Binary64.fromBits`.
The two airport lookups scan the pinned list. These observations retain the
distinction between proved policy and tested Float geography. They add no
new correctness claim. Sources: [CPRFloat](../Impl/CPRFloat.lean),
[CPRPolicy](../Impl/CPRPolicy.lean), [Binary64](../Impl/Binary64.lean).

The following actual direct edges keep wrapper and fallback calls separate.
Their inclusive costs overlap and are already contained in the exclusive
partition above. No accepted-dyadic population is inferred from these costs:
wrapper entries that do not call fallback include zero as well as admitted
dyadics. Inlined packing has no separately callable native boundary. The
current source/native review checks both guarded packing and the original
fallback; first-use scalar constants remain part of collection when reached.

| Stage | Direct conversion edge | Calls | Inclusive Ir |
|---|---|---:|---:|
{conversion_table}

The retained profile has {remaining['actual_fallback_calls_inside_root']:,} actual incoming calls to the source-verified
callable `toFloatFallback` boundary. This is an observation for this corpus;
the fallback remains required for arbitrary rational inputs. The separate
[remaining-conversion contexts](../tests/evidence/diagnostics/gen21-cpr/remaining-conversion-contexts.json)
reconcile `fromBits`, rounding and exponent calls against the complete helper
groups, preserving the caller chains that distinguish policy arithmetic from
conversion fallback. Their costs overlap and do not imply a timing gain.

The largest direct conversion/normalization edges within numeric geography
are below. Each callee-inclusive row is from an actual edge; parent calls,
rational normalization and nested GCD/power costs overlap. All {len(n['grouped_direct_edges'])}
grouped edges across stages, and their full contexts, are retained in the
[numeric supplement](../tests/evidence/diagnostics/gen21-cpr/numeric-contexts.json.gz).
The [power-only extraction](../tests/evidence/diagnostics/gen21-cpr/power-contexts.json)
is retained separately. Those inclusive costs do not measure exponent frequency or table-hit coverage.
The separate direct-edge census below observes the lookup/fallback branch
populations. Rounding and rational normalization remain present.

| Direct caller → callee, numeric geography | Calls | Inclusive Ir |
|---|---:|---:|
{edge_table}

The existing immutable table contains every exponent from −1074 through 1023.
The independent native review follows actual module initialization into its
2,098-entry constructor before the worker loop. Each entry calls the original
formula directly; lookup does not recursively construct the table.
Inside this collected loop, actual lookup entries and direct calls to the
retained formula are:

| Calling stage | Lookup entries | Formula fallback calls | Table branch calls |
|---|---:|---:|---:|
{table_counts}
| **Total** | **{tc['total']['lookup_entries']:,}** | **{tc['total']['direct_formula_fallback_calls']:,}** | **{tc['total']['table_lookup_calls_from_verified_branch_partition']:,}** |

The linked lookup has two mutually exclusive fallback sites and at most one
formula call per lookup. Subtracting the observed direct fallback calls from
lookup entries therefore identifies table-branch calls for this corpus; it
is not inferred from cost. There are {tc['table_constructor_entries_inside_root']} observed table-entry constructor calls
inside collection. Construction occurs eagerly before the root, and its
startup work is not claimed to be zero. No claim is made about all possible
exponents. [Exact contexts and source binding](../tests/evidence/diagnostics/gen21-cpr/table-contexts.json.gz).

The actual frozen worker was sampled separately before diagnostic native or
profile workers. Decode then CPR ran sequentially on CPU 0 using `cpu-clock:u`,
199 Hz and 16,384-byte DWARF stacks. All {perf['captured_input_hash_count']} protected inputs stayed unchanged.
CPR recorded {perf['samples']} samples: {perf['included_cpr_loop_stacks']} have a visible CPR-loop ancestor and
{perf['excluded_samples']} are excluded. Unknown frames occur in {perf['unknown_frame_stacks']} stacks, with
{perf['unknown_cpr_leaf_samples']} unknown included leaves. Both report headers explicitly state zero lost
samples. Missing/erased ancestors make these conditional observations unsuitable
for whole-workload timing shares. One-pass durations are not benchmark results.
[Capture and exclusions](../tests/evidence/diagnostics/gen21-cpr/perf/completion.json).

Callgrind uses `--instr-atstart=no`, `--collect-atstart=no` and
`--separate-callers=40`. Its prepared/run/decoded/consume handshake and every
control acknowledgement are retained. The primary raw dump SHA-256 is
`{a['raw_sha256']}`. Instruction profiling may overlap other instruction
diagnostics; none is a timing measurement.

The [archive](../tests/evidence/diagnostics/gen21-cpr/archive-manifest.json)
retains {archive['file_count']} original/tooling files in {archive['stored_bytes']:,} bytes,
with deterministic compressed and decompressed hashes. Large analysis outputs
are [separately compressed](../tests/evidence/diagnostics/gen21-cpr/analysis-retention.json).
Rebuildable binaries stay outside Git with exact hashes and build provenance.
No old artifacts are recopied or replaced. The previously reviewed archive helper is reused unchanged with an explicit
`perf-gen21-cpr` directory. [Producer validation](../tests/evidence/diagnostics/gen21-cpr/validation.json)
binds this report and all inputs. Independent raw-accounting review remains
the condition for selecting the next optimization.
'''
target=ROOT/'docs/GEN21-CPR-COST-BREAKDOWN.md'
assert not target.exists()
target.write_text(text)
print(json.dumps({'status':'passed','report':str(target.relative_to(ROOT)),
                  'total_Ir':total,'exclusive_rows':len(stages)}))

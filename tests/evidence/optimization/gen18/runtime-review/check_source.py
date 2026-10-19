#!/usr/bin/env python3
"""Independent read-only source/proof review; no Lean execution."""
import sys
sys.dont_write_bytecode=True
from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,subprocess
R=Path.cwd();E=R/'tests/evidence/optimization/gen18/runtime-review'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
s=Path('Impl/CPRFloat.lean').read_text();old=subprocess.check_output(['git','show','HEAD:Impl/CPRFloat.lean'],text=True)
start='def toFloat (value : Rat) : Float :=';end='/-- rs1090 cpr.rs `haversine`'
body=old.split(start,1)[1].split(end,1)[0].strip()
newbody=s.split('def toFloatFallback (value : Rat) : Float :=',1)[1].split('/-- Exact bit assembly',1)[0].strip()
assert body==newbody
assert s.split(end,1)[1]==old.split(end,1)[1]
proof=Path('Proofs/CPRFloatFast.lean').read_text();central=Path('Proofs/Binary64Dyadic.lean').read_text()
assert 'theorem toFloat_eq (value : Rat)' in proof and 'theorem toFloat_function_eq' in proof
assert all('theorem '+name in central for name in ['exponent_eq','scaled_eq_nat','nearestEven_nat','round_eq'])
files=['Impl/CPRFloat.lean','Proofs/Binary64Dyadic.lean','Proofs/CPRFloatFast.lean','Proofs/CPRTracking.lean','Tests/Tracking.lean','Tests/Upstream.lean','Tests/UpstreamCorpus.lean','scripts/FuzzCPR.lean','Bench/WholeDecoder.lean','spec.lock']
checks={
'old_total_conversion_body_byte_identical_after_rename':True,
'all_later_geography_definitions_byte_identical':True,
'zero_branch_returns_positive_zero':True,
'nonzero_guard_ensures_positive_magnitude':True,
'numerator_bound_implies_log2_at_most_52':True,
'denominator_equality_is_exact_power_of_two_not_approximate_test':True,
'k_bound_prevents_negative_subnormal_shift':True,
'normal_shift_52_minus_high_nonnegative':True,
'exponent_high_minus_k_at_most_52_no_overflow_in_fast_branch':True,
'subnormal_branch_result_below_2pow52':True,
'normal_subtraction_protected_by_positive_biased_exponent':True,
'packed_bits_below_2pow64_for_both_signs':True,
'negative_underflow_and_nondyadic_inputs_keep_old_fallback':True,
'no_message_or_corpus_dependent_guard':True,
'all_input_conversion_theorem_has_no_corpus_or_valid_coordinate_hypothesis':True,
'proof_equality_established_before_existing_Float_ofBits_boundary':True,
'live_frozen_worker_and_tracking_adapters_still_call_toFloat_or_numericalGeography':True}
notes=[
'For canonical nonzero n/2^k, 1≤n<2^53 gives 0≤high≤52. The exact exponent high−k lies between −1074 and 52.',
'If high−k<−1022, then high+1074−k≤51. Thus n<<(1074−k) is a positive subnormal fraction below 2^52.',
'Otherwise biased exponent is at least 1 and at most 1075. n<<(52−high) lies in [2^52,2^53), so the subtraction removes the hidden bit without Nat underflow and fraction/exponent do not overlap.',
'Sign adds exactly 2^63; the magnitude encoding stays below that bit. toUInt64 does not truncate any admitted packed bit.',
'All fallback cases preserve the exact original operation order; negative values that round to zero retain original positive-zero behavior.',
'Central round_eq proves representability using exact scaled integer nearest-even, not an assumption about accepted coordinates. Packing theorem rewrites the same old Float.ofBits argument; no Float arithmetic semantics are newly assumed.',
'This source/proof assessment is supplemented by owner kernel build logs, a separately prepared executable bit-equivalence probe, and post-integration native inspection. No build/probe run is claimed here.']
record={'status':'passed_read_only_source_and_proof_review','recorded_utc':datetime.now(timezone.utc).isoformat(),'findings':[],'checks':checks,'reasoning':notes,'files':{n:sha(n) for n in files},'helper_build_summary':{'path':'tests/evidence/optimization/gen18/dyadic-proof/summary.json','sha256':sha('tests/evidence/optimization/gen18/dyadic-proof/summary.json')},'packing_build_summary':{'path':'tests/evidence/optimization/gen18/packing-proof/summary.json','sha256':sha('tests/evidence/optimization/gen18/packing-proof/summary.json')},'native_review_plan':['Verify actual worker toFloat guards and zero path, both normal/subnormal shift packing and original fallback call.','Verify live haversine/local/reference/tracking callers reach guarded toFloat, and frozen adapter callers do not retain obsolete alternate conversion.','Bind exact current source/C/object/trace and worker hashes after integrated build; verify initializer order and unchanged module sets.','Inspect exact fallback only where present; absent wrapper symbols must not imply zero inlined work.'],'reviewer_sha256':sha(__file__)}
p=E/'source-review.json';assert not p.exists();p.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':record['status'],'checks':len(checks),'sha256':sha(p)}))

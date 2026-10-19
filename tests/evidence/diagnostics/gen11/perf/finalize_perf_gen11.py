from pathlib import Path
from datetime import datetime,timezone
import hashlib,json,re
out=Path('tests/evidence/diagnostics/gen11/perf')
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
capture=json.loads((out/'capture.json').read_text());analysis=json.loads((out/'analysis.json').read_text())
assert capture['record_exit_code']==0 and capture['all_input_hashes_unchanged']
assert capture['before_hashes']==capture['after_hashes']
for name,digest in capture['before_hashes'].items():assert sha(name)==digest,name
assert sha(capture['raw_data']['path'])==capture['raw_data']['sha256']
assert sha(out/'run_perf_gen11.py')==capture['helper_source_sha256']
records=[json.loads(line) for line in (out/'decode-samples.jsonl').read_text().splitlines()]
assert len(records)==analysis['decode_descendant_samples']
assert sum(analysis['disjoint_top_stages'].values())==sum(analysis['disjoint_detail_stages'].values())==len(records)
assert sum(analysis['excluded_by_visible_context'].values())+len(records)==analysis['total_samples']
lost=[]
for name in ['report-self.txt','report-children.txt']:
 for line_number,line in enumerate((out/name).read_text().splitlines(),1):
  if 'Total Lost Samples:' in line:lost.append({'file':name,'line':line_number,'text':line})
unknown_leaf=sum(record['leaf']=='[unknown]' for record in records)
completion={'status':'passed','reviewed_at_utc':datetime.now(timezone.utc).isoformat(),'capture_exit_code':capture['record_exit_code'],'analysis_command':['python3',str(out/'analyze_perf_gen11.py')],'analysis_exit_code':0,'capture_helper_sha256':sha(out/'run_perf_gen11.py'),'analysis_helper_sha256':sha(out/'analyze_perf_gen11.py'),'captured_input_hash_count':len(capture['before_hashes']),'all_input_hashes_still_match':True,'gen11_fresh_native_binding':capture['fresh_gen11_binding'],'samples':analysis['total_samples'],'included_decode_stacks':analysis['decode_descendant_samples'],'excluded_samples':analysis['excluded_samples'],'lost_sample_report_lines':lost,'unknown_frame_stacks':analysis['all_samples_with_unknown_frame'],'unknown_decode_leaf_samples':unknown_leaf,'no_throughput_claim':True}
(out/'completion.json').write_text(json.dumps(completion,indent=2)+'\n')
loss='; '.join(f"{item['file']} line {item['line']}: `{item['text']}`" for item in lost) or 'No explicit lost-sample counter appeared; no zero-loss claim is made.'
readme=f"""# Gen11 native sampling evidence

This is one native `perf record -e cpu-clock:u -F 199 --call-graph dwarf,16384` pass over the complete corpus through the frozen headline worker, pinned to guest logical CPU 0. It is diagnostic sampling, not an ABAB benchmark or a throughput measurement. The worker's raw response shows protocol completion; its instrumented duration is not a performance result.

The capture runs the actual gen11 timed binary, SHA-256 `{capture['fresh_gen11_binding']['binary_sha256']}`, from commit `{capture['git_head']}`. The helper verifies all 22 linked source/C/object/trace sets against `bench/runs/gen11/fresh-native-inputs.json`, every linked source against its committed blob, and all native hashes against `binary-built.json`. All {len(capture['before_hashes'])} captured source/native/provenance hashes match before and after, including the held proof sources. The diagnostic driver build finished before this pass; root readiness and its exact driver-build hash are bound in `capture.json`. Native diagnostic and Callgrind jobs were held until capture completion. Other agents could read evidence or prepare orchestration; this does not establish Windows host-wide isolation.

`run_perf_gen11.py` and `analyze_perf_gen11.py` adapt the retained gen9/gen10 helpers, retaining exact current-commit checks because this timed commit already uses the current attribution. The capture command, inputs, affinity, preserved binary path and raw-data hash are in `capture.json`. The preserved binary copy is for later symbol lookup and was not executed. Raw perf data remains `{capture['raw_data']['path']}`; the campaign archiver retains it via its explicit `--perf-data` option. The helper does not rebuild production code or alter its native image. The shared syndrome computation introduced in gen6 remains directly beneath `Impl.decode`; the analyzer labels that visible path separately instead of charging it to report construction.

All {analysis['total_samples']} recorded samples parse. Explicit loss counters: {loss}. Exactly {analysis['decode_descendant_samples']} samples have the live `Impl.decode` frame; {analysis['excluded_samples']} others are excluded and separately classified. Unknown frames occur in {analysis['all_samples_with_unknown_frame']} recorded stacks and {unknown_leaf} included leaf positions. Missing, inlined or tail-called frames may bias the visible subset; absence of the decoder frame does not prove a sample is preparation. The unresolved report substage remains explicit. Disjoint tables sum to {analysis['decode_descendant_samples']}; nested Rat/GMP/Parity/software-binary64/enclosure categories overlap and must not be added together. Absence of an inlined lookup helper frame does not establish zero lookup cost.

The runtime eagerly initializes its 13 immutable field-density tables , 1,024-entry Mach-value table and 4,096-entry QNH-value table during module startup before `main`. These initialization costs are outside the decode-visible subset when their actual stacks lack `Impl.decode`; they are not assigned to a decoder stage by assumption. The recording also contains input preparation, result consumption/destruction, runtime startup and possible unwind failures. Conditional shares among visible decoder stacks are not whole-decoder timing shares or proof of causal speedup. The current generated C uses a `uint32_t` accumulator in the tail-loop compiled from `Nat.fold`, with the existing cached-bit/fallback logic. Its inlined step can disappear from stacks, so missing step frames do not imply zero CRC work. The benchmark and exhaustive Callgrind accounting are separate evidence.
"""
(out/'README.md').write_text(readme)
manifest={'files':{str(p.relative_to(out)):sha(p) for p in sorted(out.rglob('*')) if p.is_file() and p.name!='artifact-hashes.json'},'raw_perf_data':capture['raw_data'],'note':'Raw data retained separately by diagnostic campaign archiver; no binary or object copies committed here.'}
(out/'artifact-hashes.json').write_text(json.dumps(manifest,indent=2)+'\n')
print(json.dumps(completion,indent=2))

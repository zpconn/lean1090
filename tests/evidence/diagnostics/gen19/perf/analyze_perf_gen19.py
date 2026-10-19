import sys
sys.dont_write_bytecode = True
from pathlib import Path
from collections import Counter
import json,re,hashlib
out=Path('tests/evidence/diagnostics/gen19/perf');text=(out/'script.txt').read_text();blocks=[x for x in text.split('\n\n') if x.strip()]
decode='lp_lean1090_Lean1090_Impl_decode';pre='lp_lean1090_Lean1090_Impl_'
rootstages=Counter();detail=Counter();leaf=Counter();allleaf=Counter();nested=Counter();records=[];excluded=Counter();unknown=0;periodtotal=0;periodincluded=0
for number,block in enumerate(blocks):
 lines=block.splitlines();period=re.search(r':\s+(\d+) cpu-clock:u:',lines[0]);assert period,lines[0];period=int(period.group(1));periodtotal+=period
 frames=[]
 for line in lines[1:]:
  m=re.match(r'^\s*([0-9a-f]+)\s+(.*?)\s+\((.*?)\)\s*$',line)
  if m:frames.append({'ip':m[1],'symbol':re.sub(r'\+0x[0-9a-f]+$','',m[2]),'dso':m[3]})
 symbols=[x['symbol'] for x in frames];allleaf[symbols[0] if symbols else 'no_frames']+=1
 unknown+=int(any(x=='[unknown]' for x in symbols))
 if decode not in symbols:
  if any('runDecodeOnce' in x for x in symbols):excluded['worker decode-loop stack, no decode frame']+=1
  elif any('runDecodeOnce' not in x and 'WholeDecoder' in x for x in symbols):excluded['worker other phase, no decode frame']+=1
  else:excluded['no decode or worker frame; may include unwind failures']+=1
  continue
 periodincluded+=period;ancestor=symbols[:symbols.index(decode)]
 has=lambda x:any(x in name for name in ancestor)
 if has(pre+'decodeFrame'): stage='frame extraction';part=stage
 elif has(pre+'frameAccepted'):stage='acceptance';part=stage
 elif has(pre+'report') or has('Impl_report_spec') or has('Impl_reportWithSyndrome_spec'):
  stage='report/projection'
  if has(pre+'Semantics_commB') or has('Impl_report_spec') or has('Impl_reportWithSyndrome_spec'):part='Comm-B semantic projection'
  elif has(pre+'frameCommB') or has(pre+'inferCommB') or has(pre+'commB') or has(pre+'decodeBDS'):part='Comm-B inference and raw payload'
  elif has(pre+'Semantics_adsb'):part='ADS-B semantic projection'
  elif has(pre+'frameADSB') or has(pre+'decodeADSB'):part='ADS-B raw payload'
  elif has(pre+'frameSyndrome') or has(pre+'frameAddress') or has(pre+'Parity_'):part='report parity/address'
  elif has(pre+'frameAltitude') or has(pre+'Altitude_'):part='altitude'
  elif has(pre+'frameIdentity'):part='identity'
  else:part='report other/self/unresolved substage'
 elif has(pre+'frameSyndrome') or has(pre+'Parity_'):stage='shared frame syndrome';part=stage
 else:stage='decode self/other';part=stage
 rootstages[stage]+=1;detail[part]+=1;leaf[symbols[0]]+=1
 if has(pre+'ScoreGate_'):nested['exact score enclosure (inclusive overlap)']+=1
 if has(pre+'cbRatioOutside250800'):nested['exact rounded-ratio enclosure (inclusive overlap)']+=1
 if has(pre+'cbDensityTermsFast'):nested['density table lookup path (inclusive overlap)']+=1
 if has(pre+'Binary64_'):nested['software Binary64 (inclusive overlap)']+=1
 if has(pre+'Parity_'):nested['Parity (inclusive overlap)']+=1
 if any(x.startswith('l_Rat_') for x in ancestor):nested['Rat (inclusive overlap)']+=1
 if any('gmp' in x or 'lean::mpz' in x or '_ZN4lean3mpz' in x for x in ancestor):nested['GMP/mpz (inclusive overlap)']+=1
 records.append({'sample_index':number,'period':period,'stage':stage,'substage':part,'leaf':symbols[0],'stack':frames})
summary={'classification':'one-pass diagnostic cpu-clock stack attribution; no throughput claim','total_samples':len(blocks),'decode_descendant_samples':len(records),'excluded_samples':len(blocks)-len(records),'excluded_by_visible_context':dict(excluded),'all_samples_with_unknown_frame':unknown,'total_period':periodtotal,'decode_descendant_period':periodincluded,'disjoint_top_stages':dict(rootstages),'disjoint_detail_stages':dict(detail),'nested_overlapping_categories':dict(nested),'decode_leaf_top30':leaf.most_common(30),'all_samples_leaf_top20':allleaf.most_common(20),'limitations':['Only samples with the exact live Impl.decode frame are included. Missing/unwound/truncated ancestors can exclude real decoder samples; excluded samples are not assumed to be preparation.','Substages use visible symbol names; inlining and tail calls can erase stage frames. report-other remains explicit rather than guessed. The gen12 byte path inlines bounded UInt64 byte folds into bytesValue; the prefix helper is live, and the original Nat fold remains for inputs longer than sixteen bytes. Changed ownership/tail-call conventions can change visible ancestors without proving a change in semantic-stage cost.','Percentages within decoded stacks are conditional on successful stack attribution and may be biased; see whole-process leaf samples and excluded count.','Software cpu-clock samples are statistical CPU-time evidence, not hardware instructions/cycles or a benchmark.','Inclusive nested categories overlap; only disjoint stage tables sum to included samples.','The live BDS60 ratio gate uses exact integer enclosure arithmetic and a software-rounding fallback; it still receives an eagerly normalized exact ratio. Inlining/tail-call visibility prevents attributing that division by assumption. This generation eagerly initializes 13 immutable density tables, the 1024-entry Mach table, the 4096-entry QNH table the 2047-entry BDS50 wind-penalty table and the 2098-entry format-exponent power table during module startup before main; such costs are excluded from decode-root samples when their actual stacks are outside Impl.decode, never charged to the steady-state decision by assumption.','The worker runs through Lean runtime worker-thread startup; parent/child hardware/thread attribution was checked by visible decode stacks.','Compilation completed and Callgrind/native diagnostics were held during capture; other agents could read evidence or prepare orchestration. No benchmark or comparative timing claim.']}
assert sum(rootstages.values())==len(records)==sum(detail.values());assert len(records)+sum(excluded.values())==len(blocks)
assert not (out/'analysis.json').exists() and not (out/'decode-samples.jsonl').exists()
(out/'analysis.json').write_text(json.dumps(summary,indent=2)+'\n');(out/'decode-samples.jsonl').write_text(''.join(json.dumps(record)+'\n' for record in records))
print(json.dumps({k:summary[k] for k in ('total_samples','decode_descendant_samples','excluded_samples','excluded_by_visible_context','all_samples_with_unknown_frame','disjoint_top_stages','disjoint_detail_stages','nested_overlapping_categories','decode_leaf_top30')},indent=2))

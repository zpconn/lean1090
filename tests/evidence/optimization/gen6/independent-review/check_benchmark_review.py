from pathlib import Path
from datetime import datetime,timezone
import csv,hashlib,json,re,shlex,statistics,subprocess
B=Path('bench/runs/gen6');R=Path.cwd();checks=0
load=lambda p:json.loads(Path(p).read_text())
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
def ck(v,reason):
 global checks
 checks+=1
 if not v:raise AssertionError(reason)
def blob(p):return subprocess.check_output(['git','cat-file','blob',commit+':'+str(p)])
def dt(s):return datetime.fromisoformat(s)
summary=load(B/'summary.json');commit=summary['commit'];archive=load(B/'archive-verification.json');binary=load(B/'binary-built.json')
ck(commit=='cd4df90b6821ed8d375cb26e0e5baed6f6e9fecf','commit')
ck(summary['status']=='complete' and summary['generation']==6,'completed generation')
ck(summary['binary_sha256']=='930b6d6f3c5f274c1ea05cd232919281f8a86e316636bedb8a885ecb90defdec','binary')
ck(len(archive['files'])==48 and archive['status']=='passed','archive')
for name,item in archive['files'].items():
 p=B/name;q=Path(archive['source'])/name
 ck(p.read_bytes()==q.read_bytes(),'archive bytes '+name)
 ck(p.stat().st_size==item['bytes'] and sha(p)==item['sha256'],'archive hash '+name)
ck(set(x.relative_to(Path(archive['source'])).as_posix() for x in Path(archive['source']).rglob('*') if x.is_file())==set(archive['files']),'source archive membership')
results=[];powers=[];backsteps=[];mode_windows=[]
for expected in summary['results']:
 mode=expected['mode'];p=B/mode;meta=load(p/'metadata.json');rows=list(csv.DictReader((p/'samples.csv').open()))
 ck(len(rows)==48 and meta['status']=='complete' and meta['mode']==mode,'complete mode')
 ck(sha(p/'samples.csv')==expected['samples_sha256'] and sha(p/'metadata.json')==expected['metadata_sha256'],'mode hashes')
 ck(meta['messages']==172432 and meta['corpus_sha256']==sha(meta['corpus']),'corpus')
 ck(meta['affinity']==[0] and meta['cpu']==0,'affinity')
 ck(meta['ordering']=='ABAB; A=rs1090, B=lean1090; 3 warmup pairs then 21 measured pairs','order')
 for side in ['lean','oracle']:
  ck(meta[side+'_binary_sha256']==sha(meta[side+'_binary']),'actual '+side+' binary')
 ck(meta['lean_binary_sha256']==summary['binary_sha256'] and meta['oracle_binary_sha256']==summary['oracle_binary_sha256'],'bound timed binaries')
 ck(meta['oracle_commit']=='685dfaa34c5ab186c691bca3cfe2a22e12517d30','pinned oracle')
 last=None;mode_back=[]
 for i,row in enumerate(rows):
  ck(int(row['order'])==i+1 and row['implementation']==['rs1090','lean1090'][i%2],'ABAB row')
  ck(row['phase']==('warmup' if i<6 else 'measured'),'phase')
  ck(int(row['pair'])==(i//2+1 if i<6 else (i-6)//2+1),'pair')
  ck(int(row['messages'])==172432 and int(row['positions'])==(11347 if mode=='cpr' else 0),'cardinality')
  ns=int(row['nanoseconds']);ck(ns>0 and float(row['messages_per_second'])==172432*1e9/ns,'row arithmetic')
  stamp=dt(row['recorded_at']);ck(stamp.tzinfo is not None,'aware time')
  if last is not None and stamp<last:mode_back.append({'mode':mode,'order':i+1,'previous':rows[i-1]['recorded_at'],'current':row['recorded_at']})
  last=stamp
 med={};rates={};extremes={}
 for side in ['rs1090','lean1090']:
  values=[int(r['nanoseconds']) for r in rows if r['phase']=='measured' and r['implementation']==side]
  ck(len(values)==21,'21 measured');med[side]=statistics.median(values);rates[side]=172432*1e9/med[side];extremes[side]=[min(values),max(values)]
  ck(meta['resolved_positions'][side]==(11347 if mode=='cpr' else 0),'position metadata')
 ck(med==meta['medians_nanoseconds']==expected['medians_nanoseconds'],'medians')
 ck(rates==meta['messages_per_second']==expected['messages_per_second'],'median rates')
 ratio=med['rs1090']/med['lean1090'];ck(ratio==meta['lean_over_rust']==expected['lean_over_rust'],'ratio')
 ck(mode_back==expected['utc_sample_backsteps'],'backstep preservation');backsteps.extend(mode_back)
 for when in ['before','after']:
  plan=meta['windows_power_plan_'+when]
  ck(plan['status']=='queried' and plan['scheme_guid']=='b96ff06e-8688-42eb-9c00-7c9f42465d2a','power plan')
  ck(plan['command']==['/mnt/c/Windows/system32/powercfg.exe','/getactivescheme'] and 'Ultimate Performance' in plan['output'],'power query')
  powers.append({'mode':mode,'when':when,**plan})
 consumer='consumed messages=172432 '+('aircraft=29 checksum=596195717' if mode=='cpr' else 'checksum=596195688')
 ck((p/'lean1090.stderr.log').read_text().splitlines()==[consumer]*24,'all outputs consumed')
 ck((p/'rs1090.stderr.log').read_bytes()==b'','oracle stderr')
 results.append({'mode':mode,'rows':48,'warmup_rows':6,'measured_rows':42,'median_nanoseconds':med,'messages_per_second':rates,'lean_over_rust':ratio,'positions_each_run':11347 if mode=='cpr' else 0,'postclock_consumer':consumer,'measured_duration_min_max_ns':extremes})

# Complete gate and fresh-source provenance bind the exact committed program.
gate=load(B/'gate-evidence.json');inputs=load(B/'correctness-inputs.json');gateverify=load(B/'gate-verification.json')
ck(gate['status']=='passed' and gate['exit_code']==0 and gate['command']==['scripts/check_all.sh','--full'],'full gate')
ck(gate['generated_messages']==10000000 and len(inputs)==177,'full 10M inputs')
ck(gate['input_hashes_before']==gate['input_hashes_after']==inputs,'unchanged gate inputs')
ck(gate['gate_log_sha256']==sha(B/'gate-full.log')==gateverify['log_sha256'],'gate log')
ck(gateverify['commit_to_measure']==commit and gateverify['evidence_sha256']==sha(B/'gate-evidence.json'),'gate-to-commit')
for p,digest in inputs.items():ck(hashlib.sha256(blob(p)).hexdigest()==digest==sha(p),'committed gate input '+p)
lock_blob=blob('spec.lock');ck(hashlib.sha256(lock_blob).hexdigest()==summary['spec_lock_sha256'],'lock blob')
locks=0
for line in lock_blob.decode().splitlines():
 digest,p=line.split('  ',1);ck(hashlib.sha256(blob(p)).hexdigest()==digest==sha(p),'locked blob '+p);locks+=1
ck(locks==104,'lock members')
fresh=load('tests/evidence/optimization/gen6/fresh-message-run.json');fresh_final=load('tests/evidence/optimization/gen6/fresh-final-verification.json')
ck(fresh['status']=='passed' and fresh['exit_code']==0 and fresh_final['status']=='passed','fresh campaign')
ck(fresh['source_sha256_before']==fresh['source_sha256_after'] and len(fresh['source_sha256_before'])==102,'fresh sources')
for p,digest in fresh['source_sha256_before'].items():ck(hashlib.sha256(blob(p)).hexdigest()==digest,'committed fresh input '+p)
components=list(csv.DictReader(Path('tests/evidence/optimization/gen6/components.tsv').open(),delimiter='\t'));ck(len(components)==7 and all(r['exit_code']=='0' for r in components),'seven components')

# Native objects freshly regenerated after removal; current files remain bound.
native=load(B/'fresh-native-inputs.json');removals=load(B/'fresh-build-removals.json');removed={x['path'] for x in removals};buildlog=(B/'lean-fresh-build.log').read_text()
ck(binary['commit']==commit and binary['sha256']==summary['binary_sha256']==sha(binary['path']),'fresh binary')
ck(binary['project_c_objects_regenerated']==len(native)==22,'fresh object count')
ck(binary['build_command']['argv']==['lake','--no-cache','--rehash','-v','build','lean1090-bench'] and binary['build_command']['exit_code']==0,'fresh build command')
ck(binary['object_membership_added']==binary['object_membership_removed']==[],'native membership')
objects=set()
for row in native:
 p=row['source'];ck(hashlib.sha256(blob(p)).hexdigest()==row['source_sha256']==sha(p),'committed native source')
 for path,item in row['artifacts'].items():
  ck(path in removed and sha(path)==item['sha256']==binary['native_hashes'][path],'regenerated artifact '+path)
  if path.endswith('.c.o.export'):objects.add(path)
  if path.endswith('.c'):ck(str(R/path) in buildlog,'generated C build invocation')
for p,digest in binary['native_hashes'].items():ck(sha(p)==digest,'current native hash')
rsp=Path('.lake/build/bin/lean1090-bench.rsp');rsp_objects={str(Path(x).resolve().relative_to(R)) for x in shlex.split(rsp.read_text()) if x.endswith('.c.o.export')}
ck(rsp_objects==objects,'actual linked objects')
envs=[load(B/f'{when}-environment/environment.json') for when in ['before','after']]
ck({k:v for k,v in envs[0].items() if k!='captured_at'}=={k:v for k,v in envs[1].items() if k!='captured_at'},'before/after effective environment')
for env in envs:
 ck(env['worker_binary_sha256']==summary['binary_sha256'] and env['spec_lock_sha256']==summary['spec_lock_sha256'],'environment binding')
 ck(all(v is None for v in env['build_environment'].values()),'selected compile env')
 ck(env['worker_link_response_sha256']==sha(rsp),'link response binding')
 ck(len(env['compiled_c_traces'])==22,'compile trace count')
 for path,item in env['compiled_c_traces'].items():
  ck(sha(path)==item['sha256'],'compile trace hash')
  ck(len(item['commands'])==1,'one actual compiler command')
  cmd=item['commands'][0];argv=shlex.split(cmd.removeprefix('.> '))
  ck('-O3' in argv and '-ffp-contract=off' in argv and not any(x.startswith(('-march=','-mcpu=','-mtune=')) for x in argv),'generic compiler flags')
  ck(cmd in buildlog,'actual rebuild compiler command')
  ck(sha(argv[0])==env['c_compiler_sha256'],'C compiler binary')
driver=[load(B/f'{when}-effective-clang-drivers.json') for when in ['before','after']]
ck(driver[0]==driver[1] and len(driver[0])==23,'effective driver captures')
for snapshot in driver:
 for row in snapshot:
  ck(row['normal_stdout']==row['no_default_config_stdout'] and row['normal_stderr']==row['no_default_config_stderr'],'no hidden compiler config')
  if '-c' in row['argv']:
   ck('"-O3"' in row['normal_stderr'] and '"-ffp-contract=off"' in row['normal_stderr'] and '"-target-cpu" "x86-64"' in row['normal_stderr'] and '"-tune-cpu" "generic"' in row['normal_stderr'],'effective generic optimization flags')

# Recorded isolation checks and sequential commands; no host-wide claim.
for checkpoint in ['before-build','before-decode','after-decode','before-cpr','after-cpr','after-timing']:
 x=load(B/(checkpoint+'-git.json'));ck(x['commit']==commit and x['clean'] and x['stdout']=='' and x['oracle_tracked_status']=='','clean tracked and untracked tree')
 ck(x['command']==['git','status','--porcelain=v1','--untracked-files=all'],'complete git status')
 ck((B/(checkpoint+'-lock.log')).read_text().strip()=='Lock audit: 104 frozen files match SHA-256.','lock guard pass')
commands=load(B/'commands.json');clock=load(B/'clock-events.json');outer=[]
for i,c in enumerate(commands):
 ck(c['exit_code']==0 and c['finish']['monotonic_ns']>=c['start']['monotonic_ns'],'successful ordered command')
 if i:ck(commands[i-1]['finish']['monotonic_ns']<=c['start']['monotonic_ns'],'commands do not overlap')
 if 'bench/interleave.py' in c['argv']:
  mode=c['argv'][c['argv'].index('--mode')+1];mono=(c['finish']['monotonic_ns']-c['start']['monotonic_ns'])/1e9;utc=(dt(c['finish']['utc'])-dt(c['start']['utc'])).total_seconds()
  ck(c['argv'][c['argv'].index('--cpu')+1]=='0','exact interleaver affinity')
  outer.append({'mode':mode,'outer_monotonic_seconds':mono,'outer_utc_seconds':utc,'utc_minus_monotonic_seconds':utc-mono})
ck(len(outer)==2,'exactly two interleavers')
wrapper=[]
for i,event in enumerate(clock):
 if i:
  ck(event['monotonic_ns']>=clock[i-1]['monotonic_ns'],'monotonic event order')
  backwards=dt(event['utc'])<dt(clock[i-1]['utc']);ck(event.get('utc_backstep',False)==backwards,'raw UTC backstep flag')
  if backwards:wrapper.append(event)
ck(wrapper==summary['utc_backsteps_retained'],'summary wrapper backsteps')
hosts={}
for when in ['before','after']:
 host=load(B/(when+'-host.json'));cores=host['cpu_activity_sample']['cores']
 for core,row in cores.items():
  delta={k:row['after_ticks'][k]-v for k,v in row['before_ticks'].items()};ck(delta==row['delta_ticks'],'host delta ticks')
  total=sum(v for k,v in delta.items() if k not in ['guest','guest_nice']);idle=delta['idle']+delta['iowait'];busy=(total-idle)*100/total
  ck(total==row['total_ticks_excluding_guest_double_count'] and abs(busy-row['busy_percent_idle_includes_iowait'])<1e-12,'host busy arithmetic')
 ck(all(v is None for v in host['compilation_environment'].values()),'host selected compile env flags')
 ck(all(x['status']=='unavailable' for x in host['cargo_config_candidates']),'Cargo config observation')
 for row in host['dist_oracle_fingerprints']['records']:
  ck(row['fields']['rustflags']==[] and sha(row['path'])==row['sha256'],'oracle fingerprint flags/hash')
 profile=host['dist_oracle_fingerprints']['manifest']['compilation_settings']['profile'];ck(profile['dist']['lto'] is True and profile['release']['overflow-checks'] is True,'shipped dist settings')
 hosts[when]={'cpu0_one_second_busy_percent':cores['cpu0']['busy_percent_idle_includes_iowait'],'all_cpu_one_second_busy_percent':cores['cpu']['busy_percent_idle_includes_iowait'],'capture_start_utc':host['capture_start_utc'],'capture_end_utc':host['capture_end_utc'],'sample_monotonic_seconds':host['cpu_activity_sample']['elapsed_seconds'],'sample_utc_seconds':(dt(host['cpu_activity_sample']['end_utc'])-dt(host['cpu_activity_sample']['start_utc'])).total_seconds(),**{k:host['host'][k] for k in ['cpufreq','thermal','hwmon']}}

prefix=blob('bench/results.csv');current=Path('bench/results.csv').read_bytes();ck(current.startswith(prefix),'committed results byte prefix')
ck(prefix==Path('tests/evidence/optimization/gen6/independent-review/results-prefix-before-gen6.csv').read_bytes(),'prior twelve rows exact')
allrows=list(csv.DictReader(Path('bench/results.csv').open()));ck(len(allrows)==14,'two appended rows')
for row,result in zip(allrows[-2:],results):
 ck(row['commit']==commit and row['generation']=='6' and row['mode']==result['mode'],'result row identity')
 ck(float(row['lean1090_msg_s'])==result['messages_per_second']['lean1090'] and float(row['rs1090_msg_s'])==result['messages_per_second']['rs1090'] and float(row['lean_over_rs1090'])==result['lean_over_rust'],'result row arithmetic')
previous=load('bench/runs/gen5/summary.json')
for result,old in zip(results,previous['results']):result['lean_throughput_change_over_gen5_percent']=(result['messages_per_second']['lean1090']/old['messages_per_second']['lean1090']-1)*100
out={'schema':1,'status':'passed_with_documented_clock_and_host_limitations','reviewed_at_utc':datetime.now(timezone.utc).isoformat(),'reviewer':'independent payload_roundtrips agent','timed_commit':commit,'binary_sha256':summary['binary_sha256'],'oracle_binary_sha256':summary['oracle_binary_sha256'],'spec_lock_sha256':summary['spec_lock_sha256'],'archive_files_rehashed_and_byte_compared':48,'gate':{'correctness_inputs_verified_against_timed_git_blobs':177,'fresh_inputs_verified_against_timed_git_blobs':102,'locked_git_blobs_verified':104,'full_gate_exit_code':0,'generated_messages':10000000,'all_seven_components_zero':True},'native_build':{'project_source_C_object_trace_sets':len(native),'removed_paths_recorded':len(removals),'actual_native_hashes_rechecked':len(binary['native_hashes']),'linked_objects_exact':True,'source_matches_timed_commit':True,'before_after_environment_matches':True,'effective_driver_config_comparisons':46},'protocol':{'samples_reviewed':96,'warmups_per_side_per_mode':3,'measurements_per_side_per_mode':21,'order':'ABAB, A=rs1090 B=lean1090','cpu':0,'six_clean_tree_and_lock_checkpoints':True},'results':results,'power_plan_queries':powers,'utc_sample_backsteps':backsteps,'wrapper_utc_backsteps':wrapper,'outer_interleave_clock_comparisons':outer,'host_observations':hosts,'historical_result_prefix_bytes':len(prefix),'historical_result_prefix_sha256':hashlib.sha256(prefix).hexdigest(),'clock_interpretation':'Frozen workers use IO.monoNanosNow and Rust Instant; UTC labels do not calculate sample durations. Outer UTC/monotonic differences are retained, with no samples discarded.','limitations':['WSL2 does not expose physical temperatures, frequency/governor state or physical-core scheduling; guest affinity and one-second snapshots cannot prove Windows host-wide isolation.','Process CPU percentages are lifetime averages. Bracketing guest observations cannot establish continuous absence of competing work.','Commands are sequential in recorded orchestration; oracle prebuild/checking occurs before worker samples. This review performs no native decoder, test or profile execution.','Build freshness follows explicit artifact invalidation and observed rebuild commands, not mtimes that can be affected by UTC corrections.','Cargo profile/config fingerprint hashes are opaque; configuration observations are not a complete Cargo precedence interpreter. Pinned manifests and recorded flags provide the inspectable settings.','Monotonic sample durations remain distinct from UTC labels; unobserved host clock/frequency changes are outside this evidence.'],'findings':[],'checks_passed':checks,'no_build_tests_profilers_or_benchmarks_run_by_review':True,'review_script_sha256':sha(__file__)}
p=B/'results-review.json';ck(not p.exists(),'no overwrite');p.write_text(json.dumps(out,indent=2)+'\n');print(sha(p));print(json.dumps({'results':results,'outer':outer,'host':hosts,'checks':checks},indent=2))

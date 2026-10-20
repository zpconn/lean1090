from pathlib import Path
import ast,difflib,hashlib,json
old=Path('tests/evidence/optimization/gen24/presentation/check_independent.py');new=Path('tests/evidence/optimization/gen25/presentation/check_independent.py');assert not new.exists()
before=old.read_text();s=before.replace('gen24','__CUR__').replace('gen23','gen24').replace('__CUR__','gen25').replace('GEN24','GEN25')
def rep(a,b):
 global s
 assert a in s,a;s=s.replace(a,b)
rep("review['generation'] == 24","review['generation'] == 25")
rep("# checker or its Decimal display strings. Decode alone reaches its target.","# checker or its Decimal display strings. The outcome remains unknown until timing.")
a=s.index("require('decode alone reaches its exact 2/1 target'");z=s.index('\ncsv_bytes =',a)
s=s[:a]+'''expected_status = ('both targets are reached.' if all(reached.values()) else
    'decode has reached its target; CPR remains below target.' if reached['decode'] else
    'CPR has reached its target; decode remains below target.' if reached['cpr'] else
    'neither target is reached.')
require('target wording follows exact integer medians in both modes',
        review['all_mode_thresholds_reached'] is all(reached.values())
        and execution['exact_target_status']['all_modes_reached'] is all(reached.values())
        and execution['exact_target_status']['README_status_text'] == expected_status)
''' + s[z:]
rep('all 48 prior CSV rows','all 50 prior CSV rows');rep('50 unique rows over 25 generations','52 unique rows over 26 generations');rep('len(rows) == 50','len(rows) == 52')
rep('range(25)','range(26)');rep('all 25 frames','all 26 frames');rep("len(manifest['frames']) == 25","len(manifest['frames']) == 26");rep('== 1300','== 1404');rep("verification['source_rows'] == 50 and verification['frames'] == 25","verification['source_rows'] == 52 and verification['frames'] == 26")
rep('exactly 25 full-size','exactly 26 full-size');rep('gif.n_frames == 25','gif.n_frames == 26');rep('len(set(decoded_frames)) == 25','len(set(decoded_frames)) == 26')
rep("'GENERATION 24' in svg","'GENERATION 25' in svg")
rep("and 'Decode  2.72×' in svg and 'Decode + CPR  1.99×' in svg)","and all(f\"{label}  {Decimal(str(next(r for r in summary['results'] if r['mode']==mode)['lean_over_rust'])):.2f}×\" in svg\n            for mode,label in [('decode','Decode'),('cpr','Decode + CPR')]))")
rep("row['generation'] == '24'","row['generation'] == '25'");rep("r['generation'] == '24'","r['generation'] == '25'") if "r['generation'] == '24'" in s else None
rep("require('README explicitly states decode-only success and measurement limits',\n        'generation 24' in readme and summary['commit'] in readme\n        and '2.00× in both modes' in readme and 'decode has reached its target; CPR remains below target' in readme\n        and Decimal(measurements['decode']) >= 2 and Decimal(measurements['cpr']) < 2", "require('README explicitly states exact measured target status and limits',\n        'generation 25' in readme and summary['commit'] in readme\n        and '2.00× in both modes' in readme and expected_status in readme\n        and all((Decimal(measurements[mode]) >= 2) == reached[mode] for mode in reached)")
rep('all 20 prior structured generations','all 25 prior structured generations');rep("history['generations'][:20]","history['generations'][:25]");rep('len(prior_display) == 20','len(prior_display) == 25');rep('current_display[:20]','current_display[:25]');rep('len(current_display) == 25','len(current_display) == 26');rep('range(20,25)','range(25,26)');rep("extension['new_raw_samples_checked'] == 480","extension['new_raw_samples_checked'] == 96");rep("extension['new_medians_recomputed'] == 20","extension['new_medians_recomputed'] == 4")
rep("'status': 'passed', 'generation': 24","'status': 'passed', 'generation': 25");rep("'csv_rows': 50, 'gif_frames': 25","'csv_rows': 52, 'gif_frames': 26");rep("'retained_artist_values_verified': 1300","'retained_artist_values_verified': 1404");rep("'target': '2.00 in both modes; decode reached, CPR unmet'","'target': '2.00 in both modes; ' + expected_status")
rep("'Static and final GIF show 2.72× decode / 1.99× CPR; decode is above and CPR below the visible 2.00× target.',","'Static and final GIF endpoints agree with the exact current median ratios and visible 2.00× target: ' + expected_status,")
rep("'Units, titles, legends, both series and the final 598.8k/220.2k endpoints are readable.'","'Units, titles, legends, both series and the current endpoint labels are readable.'")
rep('generations 0, 12 and 24','generations 0, 13 and 25');rep('all 1300 plotted values','all 1404 plotted values')
ast.parse(s);new.write_text(s);d=new.parent/'independent-checker.diff';d.write_text(''.join(difflib.unified_diff(before.splitlines(True),s.splitlines(True),fromfile=str(old),tofile=str(new))));print(hashlib.sha256(new.read_bytes()).hexdigest())

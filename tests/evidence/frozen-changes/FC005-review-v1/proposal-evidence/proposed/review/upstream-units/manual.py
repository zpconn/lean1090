#!/usr/bin/env python3
from rust_port import *
ROWS={r['id']:r for r in scan()};out=[]
def start(suffix):
 row=next(r for k,r in ROWS.items()if k.endswith(suffix));f=fixture(row);out.append(f);return f,row

def eq(f,line,a,b):check(f,line,expr('eq',a,lit(b)))
def lines(r):return [r['line']+r['body'].count('\n',0,o)for o,_,_ in macros(r['body'])]
def approx(f,l,a,b,rel=1e-3,absolute=2.220446049250313e-16):check(f,l,expr('approx',a,lit(b),relative=rel,absolute=absolute,symmetric=True))
# Invalid-CRC source test has no assertion macro, but its successful branch is rejection.
f,r=start('decode/mod.rs::test_invalid_crc');a=addobs(f,'frame','8d4ca251204994b1c36e60a5343d');check(f,r['line'],expr('null',a));c=addobs(f,'crc','8d4ca251204994b1c36e60a5343d');eq(f,r['line'],c,16)
f,r=start('decode/mod.rs::test_df18');ls=lines(r);a=addobs(f,'frame','95c639eefbffffedd5fefbff4f6f');eq(f,ls[0],sub(a,'icao24'),'c639ee');eq(f,ls[1],sub(a,'tisb'),'TISB_ADSB_RELAY');eq(f,r['line'],sub(a,'df'),'18');eq(f,r['line'],sub(a,'bds'),'65');check(f,r['line'],expr('ge',sub(sub(a,'_raw'),'subtype'),lit(2)))
# Q-code helpers: actual live altitude decoder, plus the source's Q/n assertions.
f,r=start('bds05.rs::test_altitude_decoding_formula');ls=lines(r)
for c,alt in [(0x03a,-350),(0x03b,-325),(0x03e,-250),(0x050,-200),(0x058,0),(0x070,200),(0x0b0,1000),(0x1f0,5000)]:
 a=addobs(f,'altitude-details',code=c);eq(f,ls[0],sub(a,'q_bit'),1);eq(f,ls[1],sub(a,'ac12'),alt)
f,r=start('bds05.rs::test_altitude_minus_1000_valid');ls=lines(r);a=addobs(f,'altitude-details',code=0x10)
for l,k,v in zip(ls,['q_bit','n','ac12'],[1,0,-1000]):eq(f,l,sub(a,k),v)
f,r=start('bds05.rs::test_altitude_all_zeros');a=addobs(f,'frame','8d1234564800000000000000000000');check(f,lines(r)[0],expr('or',expr('null',a),expr('eq',sub(a,'altitude'),lit(None))));a=addobs(f,'ac12',code=0);eq(f,lines(r)[0],a,None)
# Upstream M-bit closure: repeat both closure assertions for every invocation.
f,r=start('decode/mod.rs::test_mbit_altitude_precision');ls=lines(r)
for i,(m,feet)in enumerate([(100,328),(500,1640),(1000,3280),(2000,6561),(1234,4048),(2047,6715),(1357,4452)]):
 c=((m&0x7c0)<<2)|0x40|(m&0x3f);a=addobs(f,'altitude-details',code=c)
 eq(f,ls[0],sub(a,'m_bit'),1);eq(f,ls[1],sub(a,'metres'),m)
 eq(f,ls[2+i if i<6 else 9],sub(a,'formula_feet'),feet)
 if i==6:eq(f,ls[8],sub(a,'formula_feet'),feet)
 eq(f,r['line'],sub(a,'feet'),None if c&0x10 else feet)
# Original density and penalty helper expectations use the shipped proof-visible arithmetic.
for name,terms,op in [
 ('cruise_bds50_passes',[('laplace',-2,0,10),('laplace',0,0,.70),('gauss',460,413,120),('gauss',470,418,129)],'gt'),
 ('slow_bds60_fails',[('gauss',50,272,55),('gauss',.05,.69,.21)],'lt')]:
 f,r=start('density.rs::'+name);a=addobs(f,'density',terms=[dict(kind=k,value=v,center=c,scale=s)for k,v,c,s in terms]);check(f,lines(r)[0],expr(op,a,lit(-3)))
f,r=start('density.rs::density_at_centre_is_zero')
for l,(k,v,c,s)in zip(lines(r),[('gauss',1,1,2),('laplace',1013.2,1013.2,5.4),('laplace',1,0,0)]):
 a=addobs(f,'density',terms=[dict(kind=k,value=v,center=c,scale=s)]);eq(f,l,a,0)
for name,h,reg,op,value in [('cruise_bds50_small_penalty','A0001838CA3E51B250C38D000000',0x50,'gt',-1),('empty_decoded_bds_no_penalty','30000000000000',0x30,'eq',0)]:
 f,r=start('penalty.rs::'+name);a=addobs(f,'penalty',h,register=reg);check(f,lines(r)[0],expr(op,a,lit(value)));b=addobs(f,'register',h,register=reg);eq(f,r['line'],b,None) if reg==0x50 else check(f,r['line'],expr('present',b))
 if reg==0x50:f['conditional_note']='The upstream if-let register guard is false for this fixture; its assertion is vacuous. We retain rejection and additionally check the unconditional live penalty value.'
# BDS65 real decoded vector: field values plus semantic version interpretation.
f,r=start('bds65.rs::test_bds65_version2_surface');a=addobs(f,'frame','903a33fff90200040049001ea8e2');ls=lines(r)
for l,key,value in zip(ls,['version','NICa','NACp','SIL','SILs','TAH','HRD','version'],[2,0,9,0,0,0,0,2]):eq(f,l,sub(a,key),value)
for l,key,value in zip(ls[8:],['version','NICa','NACp'],[2,0,9]):
 eq(f,l,sub(a,key),value);f['exclusions'].append(dict(line=l,reason='Rust Display wording excluded; corresponding decoded version/integrity field checked.'))
def operation(version,fields):
 w=31<<51|version<<13
 for key,start,width in [('NICs',44,1),('NICa',44,1),('NACp',45,4),('BAQ',49,2),('GVA',49,2),('SIL',51,2),('BAI',53,1),('HRD',54,1),('SILs',55,1)]:
  if key in fields:w|=fields[key]<<(57-start-width)
 return f'{w:014x}'
f,r=start('bds65.rs::test_version_number_method');ls=lines(r)
for version in range(8):
 a=addobs(f,'adsb-word',operation(version,{}));eq(f,ls[min(version,3)],sub(a,'version'),version)
f,r=start('bds65.rs::test_adsb_version_display_airborne');ls=lines(r)
versions=[(0,{}),(1,dict(NICs=1,NACp=9,BAQ=1,SIL=2,BAI=1,HRD=0)),(2,dict(NICa=0,NACp=9,GVA=2,SIL=3,BAI=1,HRD=0,SILs=0)),(5,{})]
# Source display substrings and version helpers retain every field value.
index=0
for v,fields in versions:
 a=addobs(f,'adsb-word',operation(v,fields));values=[('version',v)]+list(fields.items())+[('version',v)]
 for key,value in values:
  l=ls[index];index+=1;eq(f,l,sub(a,key),value)
  if 'assert!('in (VENDOR/r['file']).read_text().splitlines()[l-1]:f['exclusions'].append(dict(line=l,reason='Display substring API excluded; exact represented field value checked.'))
assert index==len(ls),(index,len(ls))
# Full-message Display snapshots: all represented decoding fields are independently anchored;
# exact Rust spacing/units text is an excluded presentation API.
for suffix,expected,rounded in [
 ('bds06.rs::test_format',dict(df='17',icao24='484175',bds='06',groundspeed=17,track=92.8125,parity='odd',lat_cpr=39195,lon_cpr=110320),{}),
 ('bds08.rs::test_format',dict(df='17',icao24='406b90',bds='08',callsign='EZY85MH',wake_vortex='n/a'),{}),
 ('bds09.rs::test_format_groundspeed',dict(df='17',icao24='485020',bds='09',vertical_rate=-832,vrate_src='barometric',NACv=0,geo_minus_baro=550),dict(track=(183,.5),groundspeed=(159,.5))),
 ('bds09.rs::test_format_airspeed',dict(df='17',icao24='a05f21',bds='09',TAS=375,vertical_rate=-2304,vrate_src='GNSS',NACv=0),dict(heading=(244,.5))),
 ('bds62.rs::test_format_groundspeed',dict(df='17',icao24='a05629',bds='62',selected_altitude=17000,source='MCP/FCU',autopilot=True,vnav_mode=True,lnav_mode=True,tcas_operational=True),dict(selected_heading=(66.8,.05),barometric_setting=(1012.8,.05)))]:
 f,r=start(suffix);l=lines(r)[0];h=re.search(r'hex!\("([0-9a-fA-F]+)"\)',r['body'])[1];a=addobs(f,'frame',h)
 for k,v in expected.items():eq(f,l,sub(a,k),v)
 for k,(v,tol)in rounded.items():approx(f,l,sub(a,k),v,rel=0,absolute=tol)
 f['exclusions'].append(dict(line=l,reason='Rust Display exact text/spacing not an in-scope output API. All substantive decoded snapshot values ported, including source rounding precision.'))
 # Air/Ground capability and other snapshot policy status still have raw anchors.
 eq(f,l,sub(a,'_capability'),4 if suffix.startswith('bds06') else 5)
 if suffix.startswith('bds62'):
  eq(f,l,sub(a,'alt_hold'),False);eq(f,l,sub(a,'approach_mode'),False)
 f['snapshot_text']=re.search(r'r#"([\s\S]*?)"#',r['body'])[1]
# Direct CPR examples, including order and the exact numerical challenge reference.
for name,cases in [
 ('decode_airporne_position',[('8D40058B58C901375147EFD09357','8D40058B58C904A87F402D3B8C59',49.81755,6.08442),('8d4d224f58bf07c2d41a9a353d70','8d4d224f58bf003b221b34aa5b8d',42.346,.4347)]),
 ('decode_airporne_position_with_reference',[('8D40058B58C901375147EFD09357',(49,6),49.82410,6.06785),('8D40058B58C904A87F402D3B8C59',(49,6),49.81755,6.08442)]),
 ('decode_airborne_position_with_reference_numerical_challenge',[('8d06a15358bf17ff7d4a84b47b95',(30.508474576271183,7.2*5+3e-15),30.50540,33.44787)]),
 ('decode_surface_position_with_reference',[('8c4841753aab238733c8cd4020b1',(51.99,4.375),52.32061,4.73473)])]:
 f,r=start('cpr.rs::'+name);ls=lines(r)
 for i,(h,other,lat,lon)in enumerate(cases):
  a=addobs(f,'global',h,other=other)if isinstance(other,str)else addobs(f,'local',h,reference=dict(latitude=other[0],longitude=other[1]),surface='surface'in name)
  approx(f,ls[2*i],sub(a,'latitude'),lat);approx(f,ls[2*i+1],sub(a,'longitude'),lon)
# Tracking source regression lists/timestamps are extracted verbatim, retaining arrival order.
for name,split in [('test_regression_50km_threshold_check',4),('test_regression_position_oscillations_filtered',2),('test_regression_position_decode_after_large_gap',3)]:
 f,r=start('cpr.rs::'+name);messages=[dict(hex=h,timestamp=float(t))for h,t in re.findall(r'\(hex!\("([0-9a-fA-F]+)"\),\s*([0-9.]+)\)',r['body'])]
 a=addobs(f,'stream',messages=messages,split=split);ls=lines(r)
 eq(f,r['line'],sub(a,'decoded_count'),len(messages))
 if name.endswith('50km_threshold_check'):
  check(f,ls[0],expr('or',expr('null',sub(a,'final')),expr('and',expr('gt',sub(sub(a,'final'),'latitude'),lit(30)),expr('lt',sub(sub(a,'final'),'latitude'),lit(90)))))
 elif name.endswith('oscillations_filtered'):
  check(f,r['line'],expr('present',sub(a,'before')));check(f,ls[0],expr('or',expr('null',sub(a,'final')),expr('lt',sub(a,'distance'),lit(200))))
 else:
  check(f,ls[0],expr('ge',sub(a,'before_count'),lit(1)));check(f,ls[1],expr('ge',sub(a,'after_count'),lit(2)));check(f,ls[2],expr('gt',sub(a,'longitude_change'),lit(20)))
  for l,k,lo,hi in [(ls[3],'latitude',43,44),(ls[4],'longitude',26,27)]:check(f,l,expr('and',expr('gt',sub(sub(a,'final'),k),lit(lo)),expr('lt',sub(sub(a,'final'),k),lit(hi))))
# The three state-position expect() calls also require non-null values at their source lines.
for f in out:
 if '/cpr.rs::'in f['id']:
  r=ROWS[f['id']]
  for a in r['assertions']:
   if '.expect(' in a['text']:
    target='final' if 'pos_after' in a['text'] or 'after gap' in a['text'] else 'before'
    check(f,a['line'],expr('present',sub(get(0),target)))
Path('review/upstream-units/manual.jsonl').write_text(''.join(json.dumps(x)+'\n'for x in out))
print(len(out),'manual functions',sum(len(f['assertions'])for f in out),'expanded assertions')

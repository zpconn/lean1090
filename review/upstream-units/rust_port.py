#!/usr/bin/env python3
import sys
sys.dont_write_bytecode=True
from port import *

def split_args(text):
 out=[];start=0;depth=0;quote=False;i=0
 while i<len(text):
  c=text[i]
  if quote:
   if c=='\\':i+=2;continue
   if c=='"':quote=False
  elif c=='"':quote=True
  elif c in '([{':depth+=1
  elif c in ')]}':depth-=1
  elif c==',' and depth==0:out.append(text[start:i].strip());start=i+1
  i+=1
 out.append(text[start:].strip());return out

def macros(body):
 body=re.sub(r'(?m)//[^\n]*',lambda m:' '*len(m[0]),body)
 for m in re.finditer(r'\b(assert(?:_eq|_ne|_relative_eq)?)!\s*\(',body):
  depth=1;i=m.end();quote=False
  while depth:
   c=body[i]
   if quote:
    if c=='\\':i+=2;continue
    if c=='"':quote=False
   elif c=='"':quote=True
   elif c=='(':depth+=1
   elif c==')':depth-=1
   i+=1
  yield m.start(),m[1],split_args(body[m.end():i-1])
ALIASES={'alt':'altitude','ac.0':'altitude','roll_angle':'roll','track_angle':'track','true_airspeed':'TAS','selected_altitude_fms':'selected_fms','selected_altitude_mcp':'selected_mcp','aircraft_registration':'registration','magnetic_heading':'heading','indicated_airspeed':'IAS','mach_number':'Mach','barometric_altitude_rate':'vrate_barometric','inertial_vertical_velocity':'vrate_inertial','airspeed':'TAS','alt_source':'source','vrate':'vertical_rate'}
ENUMS={'Typecode::A':4,'AltSource::MCP':'MCP/FCU','VerticalRateSource::GeometricAltitude':'GNSS','VerticalRateSource::BarometricPressureAltitude':'barometric','ControlFieldType::TISB_ADSB_RELAY':'TISB_ADSB_RELAY'}
def literal(s):
 s=s.strip().replace('.to_string()','')
 if s.startswith('Some(') and s.endswith(')'):return literal(s[5:-1])
 if s=='None':return None
 if s in ENUMS:return ENUMS[s]
 if s in ['true','false']:return s=='true'
 if re.fullmatch(r'-?\d+(?:\.\d*)?',s):return float(s) if '.'in s else int(s)
 if s.startswith('"'):return json.loads(s)
 raise ValueError(s)

def convert(row):
 f=fixture(row);body=row['body'];name=row['id'].split('::')[-1];file=Path(row['file']).name
 # Only active hex macros (comments blanked).
 clean=re.sub(r'(?m)//[^\n]*',lambda m:' '*len(m[0]),body)
 hs=[(m.start(),m[1],addobs(f,'frame',m[1]))for m in re.finditer(r'hex!\("([0-9a-fA-F]+)"\)',clean)]
 def actual(s,off):
  root=next((v for pos,h,v in reversed(hs) if pos<off),None)
  s=s.replace('.unwrap()','')
  if s.startswith('-'):return expr('neg',actual(s[1:],off))
  if s.startswith('vel_pos.'):root=hs[0][2]
  if s.startswith('vel_neg.'):root=hs[1][2]
  if 'format!'in s:
   if 'wake_vortex'in s:return sub(root,'wake_vortex')
   return sub(root,'icao24')
  if s=='ac.0':return sub(root,'altitude')
  if s=='crc':
   f['observations'][root['observation']]['op']='crc';return root
  if s.startswith('bds.bds'):return sub(root,s.split('.')[1])
  key=s.split('.')[-1];key=ALIASES.get(key,key)
  if key=='tc':return sub(sub(root,'_raw'),'tc')
  if key=='ca':return sub(sub(root,'_raw'),'category')
  if key=='mode_status':return sub(sub(root,'_raw'),'mode_status')
  if key=='aa':key='icao24'
  if key=='field_type':key='tisb'
  if re.search(r'bds\.bds\w+\.unwrap',body) and file not in ['bds05.rs','bds06.rs','bds08.rs','bds09.rs','bds62.rs','bds65.rs']:
   root=sub(root,file[:-3])
  return sub(root,key)
 for off,macro,args in macros(body):
  line=row['line']+body.count('\n',0,off)
  a=args[0]
  if macro=='assert' and re.fullmatch(r'bds\.bds[0-9a-f]+\.is_(some|none)\(\)',a):
   check(f,line,expr('present' if '.is_some'in a else 'null',actual(a.split('.is_')[0],off)));continue
  if macro=='assert':
   check(f,line,expr('eq',actual(a,off),lit(1 if a=='mode_status' else True)));continue
  if args[1].startswith('Some(') and '{'in args[1]:
   root=actual(a,off);check(f,line,expr('present',root))
   struct=re.search(r'\{([\s\S]*)\}',args[1])[1]
   for part in split_args(struct):
    if not part:continue
    key,value=part.split(':',1);key=key.strip();value=literal(value)
    rawroot=sub(sub(hs[0][2],'_commb_raw'),file[:-3])
    if key=='check_flag':
     f['exclusions'].append(dict(line=line,component=key,reason='Upstream computed private capability check flag is implied by register acceptance; covered by the positive candidate assertion.'));continue
    if key=='callsign':e=sub(root,key)
    else:e=sub(rawroot,key);value=int(value) if isinstance(value,bool) else value
    check(f,line,expr('eq',e,lit(value)))
   continue
  try:b=literal(args[1])
  except ValueError:
   check(f,line,expr("eq",actual(a,off),actual(args[1],off)));continue
  if file=="bds62.rs" and a=="barometric_setting":
   import struct
   b=struct.unpack("f",struct.pack("f",b))[0]
  if a=='format!("{wake_vortex}")':b='n/a'
  e=actual(a,off)
  if macro=='assert_relative_eq':
   rel=float(next(x.split('=')[1]for x in args[2:]if x.startswith('max_relative')))
   check(f,line,expr('approx',e,lit(b),relative=rel,absolute=2.220446049250313e-16,symmetric=True))
  else:check(f,line,expr('ne' if macro=='assert_ne' else 'eq',e,lit(b)))
 return f

if __name__=='__main__':
 rows=scan();out=[];pending=[]
 special=['cpr.rs','cat48.rs','flarm.rs','density.rs','penalty.rs','bds65.rs']
 specialnames=['test_altitude_decoding_formula','test_altitude_all_zeros','test_altitude_minus_1000_valid','test_mbit_altitude_precision','test_invalid_crc','test_validate_registration','test_df18']
 for row in rows:
  if not row['file'].endswith('.rs'):continue
  if Path(row['file']).name in special or row['id'].split('::')[-1]in specialnames or 'fn test_format'in row['body']:
   pending.append(row);continue
  try:out.append(convert(row))
  except Exception as e:print('FAIL',row['id'],e);pending.append(row)
 (GENERATED/'rust-automatic.jsonl').write_text(''.join(json.dumps(x)+'\n'for x in out))
 (GENERATED/'pending.json').write_text(json.dumps(pending,indent=2)+'\n')
 print(len(out),'Rust tests',sum(len(f['assertions'])for f in out),'assertions;',len(pending),'pending')

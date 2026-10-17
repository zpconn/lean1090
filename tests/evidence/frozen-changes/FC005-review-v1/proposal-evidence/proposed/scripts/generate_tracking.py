#!/usr/bin/env python3
"""Independent exact CPR encoder and deterministic multiaircraft stream strata.
CPR equations: Sun, second edition (2021), ch. 5; pinned Spec NL table is read
as test data. Frames have freshly calculated polynomial CRC, never copied outputs.
"""
import argparse, json, math, random, re, struct
from fractions import Fraction as Q
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def bits(x): return struct.unpack('>Q',struct.pack('>d',float(x)))[0]
def pos(p):return None if p is None else list(map(bits,p))
text=(ROOT/'Spec/CPR.lean').read_text()
TRANS=[Q(int(n),100000000) for n in re.findall(r'\d+',re.search(r'def transitions : List Nat :=\s*\[([^]]+)\]',text)[1])]
def nl(lat): return 2 if abs(lat)==87 else 59-sum(t<=abs(lat) for t in TRANS)
def encode(p,odd,surface=False):
 width=90 if surface else 360; dl=Q(width,60-odd); lat,lon=map(Q,p)
 y=math.floor(lat/dl*131072+Q(1,2))%131072
 rounded=math.floor(lat/dl*131072+Q(1,2))*dl/131072
 dx=Q(width,max(nl(rounded)-odd,1)); x=math.floor(lon/dx*131072+Q(1,2))%131072
 return y,x

def crc(word):
 for shift in range(111,23,-1):
  if word>>shift&1:word^=0x1fff409<<(shift-24)
 return word

def frame(p=(52.308609,4.763889),odd=0,address=0xabc001,surface=False,df=17,tc=None,alt=500,**kw):
 tc=tc if tc is not None else (5 if surface else 11)
 y,x=encode(p,odd,surface)
 n=(alt+1000)//25; ac=((n>>4)<<5)|(n&15)|16
 payload=(tc<<51)|((0 if surface else ac)<<36)|(int(kw.get('sync',False))<<35)|(odd<<34)|(y<<17)|x
 word=(df<<107)|(5<<104)|(address<<80)|(payload<<24)
 return f'{word|crc(word):028x}'

def nonpos(address,tc=1,df=17):
 payload=tc<<51;word=(df<<107)|(5<<104)|(address<<80)|(payload<<24)
 return f'{word|crc(word):028x}'

def generate(corpus=True,random_tracks=200,seed=109005):
 streams=[];a=0xabc001;b=0xabc002;c=0xabc003;P=(52.308609,4.763889);F=(43.628101,1.367263)
 def add(name,events,reference=None,update=0):streams.append(dict(name=name,events=events,reference=reference,update=update))
 def msg(t,p=P,odd=0,address=a,**kw):return(t,frame(p,odd,address,**kw))
 def seedpair(p=P,address=a):return[msg(0,p,0,address),msg(1,p,1,address)]
 for df in (17,18):
  for odd in (0,1):
   for gap,label in ((math.nextafter(30.,0.),'inside'),(30.,'exact'),(math.nextafter(30.,math.inf),'outside')):
    add(f'pair_df{df}_first{odd}_{label}',[msg(0,odd=odd,df=df),msg(gap,odd=1-odd,df=df)])
 for age,label in ((math.nextafter(180.,0.),'inside'),(180.,'exact'),(math.nextafter(180.,math.inf),'outside')):
  add('local_age_'+label,seedpair()+[msg(1+age,odd=1)])
 add('cross_and_same_parity_order',[msg(0),msg(10,odd=1),msg(5),msg(7,odd=1),msg(8),msg(6,odd=1),msg(9,odd=1)])
 add('nonposition_initializes_clock',[(100.,nonpos(a)),msg(99),msg(101),msg(102,odd=1)])
 add('same_aircraft_df17_df18',[msg(0,df=17),msg(1,odd=1,df=18),msg(2,df=17)])
 add('non_adsb_and_invalid',[(0.,'00000000000000'),(0.,'8d00000000000000000000000000'),(0.,'1234'),(1.,nonpos(a)),msg(2),msg(3,odd=1)])
 for dt,label in ((1799.,'inside'),(1800.,'exact'),(1801.,'outside')):
  add('speed_gap_'+label,seedpair()+[msg(dt,F,0),msg(1+dt,F,1)])
 # Nearby wrong pair gives failed global and usable local reference; broad random
 # stream stratum additionally exercises NL failures at worldwide latitudes.
 add('global_bad_pair_local_fallback',seedpair()+[msg(2,(P[0]+1.,P[1]),0),msg(3,P,1)])
 add('zero_dt_large_global_jump',seedpair()+[msg(1,F,0),msg(1,F,1),msg(2,P,0),msg(3,P,1)])
 for ref,label in ((None,'none'),(P,'near_airport'),((0.,-140.),'ocean')):
  p=P if label!='ocean' else (0.,-140.)
  add('surface_first_'+label,[msg(0,p,0,surface=True),msg(1,p,1,surface=True)],reference=ref)
 for offset in (.0001,.02):
  for ref,label in ((None,'no_shared'),(P,'shared')):
   add(f'surface_own_{offset}_{label}',seedpair()+[msg(2,(P[0]+offset,P[1]),surface=True),msg(-10,(P[0]+offset,P[1]),odd=1,surface=True),msg(99999,(P[0]+offset,P[1]),surface=True)],reference=ref)
 add('surface_own_precedes_contradictory_shared',seedpair()+[msg(2,(P[0]+.0001,P[1]),surface=True)],reference=F)
 # Surface references do not enforce motion speed or airport proximity after init.
 add('surface_existing_remote_shared',seedpair()+[msg(2,(0.,-140.),surface=True)],reference=(0.,-140.))
 add('surface_bad_shared_latitude',[msg(0,surface=True)],reference=(100.,4.7))
 for step in (-2,-1,0,1,2):
  p=(P[0]+10/111.19492664455873+step*90/(60*131072),P[1])
  add('airport_10km_boundary_'+str(step),[msg(0,p,surface=True)],reference=p)
 for mode in (0,1,2,3):
  add('reference_callback_'+str(mode),[msg(0,alt=500,tc=20,sync=True),msg(1,odd=1,alt=500,tc=20,sync=True),msg(2,address=b,surface=True),msg(3,(P[0]+.0001,P[1]),0,alt=1500,tc=20,sync=True),msg(4,(P[0]+.0001,P[1]),1,alt=1500,tc=20,sync=True),msg(5,address=c,surface=True)],update=mode)
 add('interleaved_distinct_aircraft',[msg(0,address=a),msg(.1,F,address=b),msg(1,odd=1,address=a),msg(1.1,F,odd=1,address=b),msg(2,address=c,surface=True),msg(3,P,0,a),msg(4,F,0,b)],update=1)
 # Broad distance/time strata include both sides of the jump and speed gates.
 for distance_km in (.1,1.,10.,499.9,500.,500.1,501.):
  q=(P[0]+distance_km/111.19492664455873,P[1])
  for dt in (0.,1.,29.999,30.,30.001,1799.,1800.):
   add(f'motion_{distance_km}_{dt}',seedpair()+[msg(1+dt,q,0),msg(1+dt,q,1)])
 # Latitude-out-of-domain candidate rejects local and own surface reconstruction.
 add('local_latitude_decode_rejected',seedpair((89.999,0.))+[msg(179,(90.1,0.),odd=1)])
 add('surface_own_decode_rejected',seedpair((89.999,0.))+[msg(2,(90.1,0.),surface=True)],reference=(0.,0.))
 # Isolate speed threshold on a first even update from exact (0,0): the
 # previous odd coordinate is zero; current even latitude is this exact CPR code.
 p0=(0.,0.);q=(.01,0.);y,_=encode(q,0);latitude=6*(y/131072)
 h=math.sin(math.radians(latitude)/2)**2;distance=6371*2*math.atan2(math.sqrt(h),math.sqrt(1-h))
 center=1.+distance/1200.*3600.
 for i,delta in enumerate((-1e-8,-1e-10,0.,1e-10,1e-8)):
  add('speed_1200_bracket_'+str(i),seedpair(p0)+[msg(center+delta,q,0)])
 # Other ADS-B variants must still create/update their per-aircraft evidence.
 add('nonposition_evidence',[(0.,nonpos(a,tc)) for tc in (1,19,28,29,31)]+[msg(1),msg(2,odd=1)])
 for i,t in enumerate(TRANS):
  for sign in (-1,1):
   p=(float(sign*t)-.0001,12.);q=(float(sign*t)+.0001,12.)
   add(f'zone_crossing_{i}_{sign}',seedpair(p)+[msg(2,q,0),msg(3,q,1),msg(4,p,0)])
 rng=random.Random(seed)
 for k in range(random_tracks):
  p=(rng.uniform(-86.8,86.8),rng.uniform(-179,179));q=(rng.uniform(-86.8,86.8),rng.uniform(-179,179))
  events=[]
  for i in range(12):
   for j,point in enumerate((p,q)):
    t=i*5.+j*.1
    moved=(point[0]+i*.0001,point[1]+i*.0001)
    events.append(msg(t,moved,i%2,a+j,df=17+(i%3==0)))
  add(f'random_interleaved_{k}',events,update=k%4)
 if corpus:
  rows=[]
  for line in (ROOT/'vendor/rs1090/crates/rs1090/data/long_flight.csv').read_text().splitlines():
   t,h=line.split(',');rows.append((float(t),h[18:]))
  assert len(rows)==172432;streams.insert(0,dict(name='full_corpus',events=rows,reference=None,update=0))
 return streams

def write(out,corpus=True,random_tracks=200,seed=109005):
 out=Path(out);out.mkdir(parents=True,exist_ok=True);streams=generate(corpus,random_tracks,seed)
 with (out/'input.jsonl').open('w') as f:
  for s in streams:
   f.write(json.dumps(dict(kind='header',stream=s['name'],reference=pos(s['reference']),update=s['update']))+'\n')
   for i,(t,h) in enumerate(s['events']):f.write(json.dumps(dict(kind='message',id=i,timestamp_bits=bits(t),hex=h))+'\n')
 airports=json.loads((ROOT/'vendor/rs1090/crates/rs1090/data/airports.json').read_text())
 with (out/'airports.jsonl').open('w') as f:
  for a in airports:f.write(json.dumps(dict(icao=a['icao'],position=pos((a['lat'],a['lon']))))+'\n')
 meta=dict(seed=seed,random_tracks=random_tracks,streams=len(streams),messages=sum(len(s['events']) for s in streams),corpus=172432 if corpus else 0,airports=len(airports),strata={s['name']:len(s['events']) for s in streams})
 (out/'generation.json').write_text(json.dumps(meta,indent=2)+'\n');return meta
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--output',required=True);p.add_argument('--no-corpus',action='store_true');p.add_argument('--random-tracks',type=int,default=200);p.add_argument('--seed',type=int,default=109005);a=p.parse_args();print(json.dumps(write(a.output,not a.no_corpus,a.random_tracks,a.seed),indent=2))

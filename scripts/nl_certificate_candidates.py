#!/usr/bin/env python3
"""Generate *unproved* rational enclosure candidates from ICAO CPR §2.6.2(f).
Pure Decimal arithmetic; these numbers are data for future Lean proofs,
not a substitute for a kernel-checked transcendental certificate.
"""
from decimal import Decimal as D, localcontext, ROUND_FLOOR
from fractions import Fraction as F
import json


def atan_series(x):
    term = x
    total = term
    for n in range(1, 200):
        term *= -x*x
        total += term / (2*n+1)
    return total


def cos_series(x):
    total = term = D(1)
    for n in range(1, 100):
        term *= -x*x / ((2*n-1)*(2*n))
        total += term
    return total


def candidates():
    with localcontext() as ctx:
        ctx.prec = 80
        pi = 16*atan_series(D(1)/5)-4*atan_series(D(1)/239)
        result=[]
        for zone in range(59,2,-1):
            target=((1-cos_series(pi/30))/(1-cos_series(2*pi/zone))).sqrt()
            lo, hi=D(0),pi/2
            for _ in range(280):
                mid=(lo+hi)/2
                if cos_series(mid)>target: lo=mid
                else: hi=mid
            angle=(lo+hi)/2*180/pi
            floor12=int((angle*10**12).to_integral_value(rounding=ROUND_FLOOR))
            table8=int((angle*10**8).to_integral_value())
            lower=min(floor12,table8*10**4)
            upper=max(floor12+1,table8*10**4)
            row={'zone':zone,'table8':table8,'lower12':lower,'upper12':upper}
            # Grid exclusion is an exact rational numerical check, not the Lean proof.
            for span in (90,360):
                for odd in (0,1):
                    step=F(span,(60-odd)*131072)
                    low,high=F(lower,10**12)/step,F(upper,10**12)/step
                    if -(-low.numerator//low.denominator)<=high.numerator//high.denominator:
                        raise ValueError(('candidate interval intersects grid',row,span,odd))
            result.append(row)
        return result


if __name__=='__main__':
    print(json.dumps(candidates(),indent=2))

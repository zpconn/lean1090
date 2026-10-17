import Spec.Presentation
open Lean1090.Spec
open Lean1090.Spec.Presentation

-- 8d1122339a000300800801cb9966: payload43347159306733569
#eval standardVelocityComponents 43347159306733569
#eval adsbOracleVelocityComponents 43347159306733569
#eval standardVerticalSource 43347159306733569
#eval oracleVerticalSource 43347159306733569
#eval standardGeoMinusBaro 43347159306733569
#eval adsbGeoMinusBaro 43347159306733569
-- 8d1122339900000010007f1027d0: payload43065671437779071
#eval standardVelocityComponents 43065671437779071
#eval adsbOracleVelocityComponents 43065671437779071
#eval standardVerticalSource 43065671437779071
#eval oracleVerticalSource 43065671437779071
#eval standardGeoMinusBaro 43065671437779071
#eval adsbGeoMinusBaro 43065671437779071
-- 8d112233a0010000000000b2fb95: payload45037095785332736
#eval standardGNSSHeightMetres 45037095785332736
#eval adsbAltitude 45037095785332736
-- Comm-D standard wire interpretation
#eval decodeFrame [192,0,0,0,0,0,0,0,0,0,0,0,0,0]

-- 8d11223348fff000000000509bc4: representable altitude beyond heuristic ceiling
#eval Altitude.decodeAC12 4095
#eval adsbAltitude 20547604580401152
#eval decodeADSB 20547604580401152

import Init

/-!
Pure Lean translation of the binary64 hypot/atan/atan2 algorithms in the
pinned Rust libm 0.2.16 crate (src/math/{hypot,atan,atan2}.rs). This is the
tested numerical presentation boundary, not a mathematical Float proof or an
inference primitive. Preserve operation order and compile without contraction.
Original license and notices: docs/licenses/rust-libm-0.2.16.txt.

atan and atan2 originate in FreeBSD msun s_atan.c/e_atan2.c:
Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
Developed at SunPro/SunSoft, Sun Microsystems, Inc. businesses.
Permission to use, copy, modify, and distribute this software is freely
 granted, provided that this notice is preserved.
-/

namespace Lean1090.Impl.Libm

private def squareParts (x : Float) : Float × Float :=
  let xc := x * 134217729
  let xh := x - xc + xc
  let xl := x - xh
  let hi := x * x
  let lo := xh * xh - hi + 2 * xh * xl + xl * xl
  (hi, lo)

/-- Pinned libm norm: split products preserve the argument's low-order terms. -/
def hypot (x y : Float) : Float :=
  let ux := x.toBits &&& 0x7fffffffffffffff
  let uy := y.toBits &&& 0x7fffffffffffffff
  let (ux, uy) := if ux < uy then (uy, ux) else (ux, uy)
  let ex := ux >>> 52
  let ey := uy >>> 52
  let x := Float.ofBits ux
  let y := Float.ofBits uy
  if ey == 0x7ff then y
  else if ex == 0x7ff || uy == 0 then x
  else if ex - ey > 64 then x + y
  else
    let (x, y, z) := if ex > 0x3ff + 510 then
      (x * Float.ofBits 0x1430000000000000,
       y * Float.ofBits 0x1430000000000000, Float.ofBits 0x6bb0000000000000)
    else if ey < 0x3ff - 450 then
      (x * Float.ofBits 0x6bb0000000000000,
       y * Float.ofBits 0x6bb0000000000000, Float.ofBits 0x1430000000000000)
    else (x, y, 1)
    let (hx, lx) := squareParts x
    let (hy, ly) := squareParts y
    z * (ly + lx + hy + hx).sqrt

/-- Pinned libm arctangent, including exactly encoded polynomial constants. -/
def atan (input : Float) : Float :=
  let ix := (input.toBits >>> 32).toUInt32 &&& 0x7fffffff
  let negative := input.toBits >>> 63 != 0
  if ix ≥ 0x44100000 then
    if input.isNaN then input else
    let z := Float.ofBits 0x3ff921fb54442d18 + Float.ofBits 0x03800000
    if negative then -z else z
  else if ix < 0x3e400000 then input
  else
    let (x, adjustment) : Float × Option (Float × Float) :=
      if ix < 0x3fdc0000 then (input, none)
      else
        let x := input.abs
        if ix < 0x3ff30000 then
          if ix < 0x3fe60000 then
            ((2 * x - 1) / (2 + x),
             some (Float.ofBits 0x3fddac670561bb4f, Float.ofBits 0x3c7a2b7f222f65e2))
          else
            ((x - 1) / (x + 1),
             some (Float.ofBits 0x3fe921fb54442d18, Float.ofBits 0x3c81a62633145c07))
        else if ix < 0x40038000 then
          ((x - 1.5) / (1 + 1.5 * x),
           some (Float.ofBits 0x3fef730bd281f69b, Float.ofBits 0x3c7007887af0cbbd))
        else
          (-1 / x, some (Float.ofBits 0x3ff921fb54442d18, Float.ofBits 0x3c91a62633145c07))
    let z := x * x
    let w := z * z
    let s1 := z * (Float.ofBits 0x3fd555555555550d + w *
      (Float.ofBits 0x3fc24924920083ff + w *
      (Float.ofBits 0x3fb745cdc54c206e + w *
      (Float.ofBits 0x3fb10d66a0d03d51 + w *
      (Float.ofBits 0x3fa97b4b24760deb + w * Float.ofBits 0x3f90ad3ae322da11)))))
    let s2 := w * (Float.ofBits 0xbfc999999998ebc4 + w *
      (Float.ofBits 0xbfbc71c6fe231671 + w *
      (Float.ofBits 0xbfb3b0f2af749a6d + w *
      (Float.ofBits 0xbfadde2d52defd9a + w * Float.ofBits 0xbfa2b4442c6a6c2f))))
    match adjustment with
    | none => x - x * (s1 + s2)
    | some (hi, lo) =>
        let result := hi - (x * (s1 + s2) - lo - x)
        if negative then -result else result

/-- Pinned libm atan2, retaining signed zeros, quadrants and low-part correction. -/
def atan2 (y x : Float) : Float :=
  let pi := Float.ofBits 0x400921fb54442d18
  let piLow := Float.ofBits 0x3ca1a62633145c07
  if x.isNaN || y.isNaN then x + y
  else
    let ix := (x.toBits >>> 32).toUInt32
    let lx := x.toBits.toUInt32
    let iy := (y.toBits >>> 32).toUInt32
    let ly := y.toBits.toUInt32
    if (ix - 0x3ff00000) ||| lx == 0 then atan y
    else
      let m : UInt32 := ((iy >>> 31) &&& (1 : UInt32)) ||| ((ix >>> 30) &&& (2 : UInt32))
      let ix := ix &&& 0x7fffffff
      let iy := iy &&& 0x7fffffff
      if iy ||| ly == 0 then
        if m < 2 then y else if m == 2 then pi else -pi
      else if ix ||| lx == 0 then
        if m &&& 1 != 0 then -pi / 2 else pi / 2
      else if ix == 0x7ff00000 then
        if iy == 0x7ff00000 then
          if m == 0 then pi / 4 else if m == 1 then -pi / 4
          else if m == 2 then 3 * pi / 4 else -3 * pi / 4
        else
          if m == 0 then 0 else if m == 1 then Float.ofBits 0x8000000000000000
          else if m == 2 then pi else -pi
      else if ix + ((64 : UInt32) <<< 20) < iy || iy == 0x7ff00000 then
        if m &&& 1 != 0 then -pi / 2 else pi / 2
      else
        let z := if m &&& 2 != 0 && iy + ((64 : UInt32) <<< 20) < ix then 0
          else atan (y / x).abs
        if m == 0 then z else if m == 1 then -z
        else if m == 2 then pi - (z - piLow) else (z - piLow) - pi

end Lean1090.Impl.Libm

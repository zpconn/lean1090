//! Test-only reference for the presentation primitives used by pinned rs1090.
//! Hypot/atan2 use pinned libm 0.2.16; f32 arithmetic uses Rust operations.
use std::io::{self, BufWriter, Write};

fn main() -> io::Result<()> {
    let path = std::env::args().nth(1).expect("output path");
    let mut out = BufWriter::new(std::fs::File::create(path)?);
    let mut emit = |value: f64| out.write_all(&value.to_bits().to_le_bytes());
    for x in 0..=4092 {
        for y in 0..=4092 {
            emit(libm::hypot(x as f64, y as f64))?;
        }
    }
    for x in -1022..=1022 {
        for y in -1022..=1022 {
            let mut track = libm::atan2(x as f64, y as f64)
                * (360.0 / (2.0 * std::f64::consts::PI));
            if track < 0.0 { track += 360.0; }
            emit(track)?;
        }
    }
    for n in 0..512 {
        emit((800.0f32 + n as f32 * 0.8f32) as f64)?;
        emit((n as f32 * 180.0f32 / 256.0f32) as f64)?;
    }
    for n in 0..1024 {
        emit((n as f32 * 360.0f32 / 1024.0f32) as f64)?;
    }
    // A midpoint whose tiny positive offset disappears in binary64. Direct
    // rational -> binary32 must round up, unlike binary64 -> binary32.
    emit(f32::from_bits(0x3f800001) as f64)?;
    out.flush()
}

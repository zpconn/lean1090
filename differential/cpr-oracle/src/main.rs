//! Differential test adapter, calling the actual pinned public CPR functions.
use rs1090::decode::bds::bds05::{AirbornePosition, Source, SurveillanceStatus};
use rs1090::decode::bds::bds06::SurfacePosition;
use rs1090::decode::cpr::{
    airborne_position, airborne_position_with_reference, surface_position_with_reference,
    CPRFormat, Position,
};
use std::error::Error;
use std::io::{BufRead, BufReader, BufWriter, Write};

fn airborne(odd: bool, latitude: u32, longitude: u32) -> AirbornePosition {
    AirbornePosition {
        nuc_p: 9,
        ss: SurveillanceStatus::NoCondition,
        saf_or_nicb: Some(0),
        alt: Some(10000),
        source: Source::Barometric,
        time_sync: false,
        parity: if odd { CPRFormat::Odd } else { CPRFormat::Even },
        lat_cpr: latitude,
        lon_cpr: longitude,
        latitude: None,
        longitude: None,
    }
}

fn surface(odd: bool, latitude: u32, longitude: u32) -> SurfacePosition {
    SurfacePosition {
        nuc_p: 9,
        groundspeed: None,
        track_status: false,
        track: None,
        t: false,
        parity: if odd { CPRFormat::Odd } else { CPRFormat::Even },
        lat_cpr: latitude,
        lon_cpr: longitude,
        latitude: None,
        longitude: None,
    }
}

fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<String> = std::env::args().skip(1).collect();
    if args.len() != 2 {
        return Err("usage: lean1090-synthetic-cpr-oracle LEAN.csv ORACLE.csv".into());
    }
    let reader = BufReader::new(std::fs::File::open(&args[0])?);
    let mut writer = BufWriter::new(std::fs::File::create(&args[1])?);
    writeln!(writer, "id,accepted,lat_bits,lon_bits")?;
    for line in reader.lines().skip(1) {
        let line = line?;
        let values = line
            .split(',')
            .map(str::parse::<u64>)
            .collect::<Result<Vec<_>, _>>()?;
        if values.len() != 25 {
            return Err("expected 25 columns from frozen-reference adapter".into());
        }
        let id = values[0];
        let kind = values[1];
        let surface_mode = values[2] == 1;
        let odd = values[3] == 1;
        let latest_odd = values[4] == 1;
        let a = (u32::try_from(values[5])?, u32::try_from(values[6])?);
        let b = (u32::try_from(values[7])?, u32::try_from(values[8])?);
        if [a.0, a.1, b.0, b.1].iter().any(|&n| n >= 131072) {
            return Err("encoder produced an out-of-range code".into());
        }
        let reference = (f64::from_bits(values[9]), f64::from_bits(values[10]));
        if !reference.0.is_finite() || !reference.1.is_finite() {
            return Err("non-finite reference".into());
        }
        let answer: Option<Position> = if kind == 0 {
            if surface_mode {
                surface_position_with_reference(&surface(odd, a.0, a.1), reference.0, reference.1)
            } else {
                airborne_position_with_reference(&airborne(odd, a.0, a.1), reference.0, reference.1)
            }
        } else {
            if surface_mode || kind > 2 {
                return Err("unsupported global selector".into());
            }
            let even = airborne(false, a.0, a.1);
            let other = airborne(kind != 2, b.0, b.1);
            if latest_odd {
                airborne_position(&even, &other)
            } else {
                airborne_position(&other, &even)
            }
        };
        match answer {
            None => writeln!(writer, "{id},0,0,0")?,
            Some(position) => writeln!(
                writer,
                "{id},1,{},{}",
                position.latitude.to_bits(),
                position.longitude.to_bits()
            )?,
        }
    }
    Ok(())
}

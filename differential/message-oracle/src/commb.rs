//! Direct named-register readers, before the inference score gate. Every call
//! invokes the pinned library's actual decoder; no fields are reimplemented.
use deku::{ctx::Order, prelude::*};
use rs1090::decode::bds::{
    bds05::AirbornePosition, bds10::DataLinkCapability,
    bds17::CommonUsageGICBCapabilityReport, bds18::GICBCapabilityReportPart1,
    bds19::GICBCapabilityReportPart2, bds20::AircraftIdentification,
    bds21::AircraftAndAirlineRegistrationMarkings, bds30::ACASResolutionAdvisory,
    bds40::SelectedVerticalIntention, bds44::MeteorologicalRoutineAirReport,
    bds45::MeteorologicalHazardReport, bds50::TrackAndTurnReport,
    bds60::HeadingAndSpeedReport, bds65::AircraftOperationStatus,
};
use serde_json::Value;
use std::io::{self, BufRead, BufWriter, Write};

macro_rules! decode {
    ($ty:ty, $data:expr, $offset:expr) => {
        <$ty>::from_bytes(($data, $offset)).ok()
            .map(|(_, value)| serde_json::to_value(value).expect("serializable register"))
    };
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let input = io::stdin();
    let mut output = BufWriter::new(io::stdout().lock());
    for line in input.lock().lines() {
        let line = line?;
        let columns: Vec<_> = line.split_whitespace().collect();
        if columns.is_empty() { continue; }
        if columns.len() != 2 { return Err("expected register and payload".into()); }
        let register: u8 = columns[0].parse()?;
        let word: u64 = columns[1].parse()?;
        if word >= (1u64 << 56) { return Err("payload exceeds 56 bits".into()); }
        let data = word.to_be_bytes();
        let data = &data[1..];
        let tc = data[0] >> 3;
        let value = match register {
            0x05 if (9..=18).contains(&tc) || (20..=22).contains(&tc) => {
                let mut cursor = io::Cursor::new(data);
                let mut reader = Reader::new(&mut cursor);
                reader.skip_bits(5, Order::Msb0)?;
                AirbornePosition::from_reader_with_ctx(&mut reader, tc).ok()
                    .map(serde_json::to_value).transpose()?
            }
            0x05 => None,
            0x10 => decode!(DataLinkCapability, data, 0),
            0x17 => decode!(CommonUsageGICBCapabilityReport, data, 0),
            0x18 => decode!(GICBCapabilityReportPart1, data, 0),
            0x19 => decode!(GICBCapabilityReportPart2, data, 0),
            0x20 => decode!(AircraftIdentification, data, 0),
            0x21 => decode!(AircraftAndAirlineRegistrationMarkings, data, 0),
            0x30 => decode!(ACASResolutionAdvisory, data, 0),
            0x40 => decode!(SelectedVerticalIntention, data, 0),
            0x44 => decode!(MeteorologicalRoutineAirReport, data, 0),
            0x45 => decode!(MeteorologicalHazardReport, data, 0),
            0x50 => decode!(TrackAndTurnReport, data, 0),
            0x60 => decode!(HeadingAndSpeedReport, data, 0),
            0x65 if tc == 31 && data[0] & 7 < 2 => decode!(AircraftOperationStatus, data, 5),
            0x65 => None,
            _ => return Err("unsupported register".into()),
        }.unwrap_or(Value::Null);
        serde_json::to_writer(&mut output, &value)?;
        writeln!(&mut output)?;
    }
    output.flush()?;
    Ok(())
}

//! Frozen checkpoint-1 rs1090 benchmark side. See ../BENCHMARK.md.
use rs1090::decode::cpr::{airborne_position, decode_position, AircraftState, Position, UpdateIf};
use rs1090::decode::DF;
use rs1090::prelude::*;
use std::collections::BTreeMap;
use std::error::Error;
use std::hint::black_box;
use std::io::{self, BufRead, Write};
use std::time::{Duration, Instant};

const EXPECTED_MESSAGES: usize = 172_432;

struct Input {
    timestamp: f64,
    bytes: Vec<u8>,
}

fn hex_digit(c: u8) -> Result<u8, Box<dyn Error>> {
    match c {
        b'0'..=b'9' => Ok(c - b'0'),
        b'a'..=b'f' => Ok(c - b'a' + 10),
        b'A'..=b'F' => Ok(c - b'A' + 10),
        _ => Err("invalid hexadecimal digit".into()),
    }
}

fn read_inputs(path: &str) -> Result<Vec<Input>, Box<dyn Error>> {
    let text = std::fs::read_to_string(path)?;
    let mut inputs = Vec::with_capacity(EXPECTED_MESSAGES);
    for (line_number, line) in text.lines().enumerate() {
        let (time, beast) = line.split_once(',').ok_or("expected timestamp,frame")?;
        let hex = beast.get(18..).ok_or("missing 18-character Beast prefix")?;
        if hex.len() != 14 && hex.len() != 28 {
            return Err(format!("line {}: expected 7 or 14 message bytes", line_number + 1).into());
        }
        let mut bytes = Vec::with_capacity(hex.len() / 2);
        for pair in hex.as_bytes().chunks_exact(2) {
            bytes.push(hex_digit(pair[0])? * 16 + hex_digit(pair[1])?);
        }
        let timestamp = time.parse::<f64>()?;
        if !timestamp.is_finite() {
            return Err("non-finite timestamp".into());
        }
        inputs.push(Input { timestamp, bytes });
    }
    if inputs.len() != EXPECTED_MESSAGES {
        return Err(format!(
            "expected {EXPECTED_MESSAGES} messages, found {}",
            inputs.len()
        )
        .into());
    }
    Ok(inputs)
}

fn run_once(inputs: &[Input], cpr: bool) -> Result<(Duration, usize), Box<dyn Error>> {
    // Output capacity and empty state are prepared before the clock starts.
    let mut output = Vec::with_capacity(inputs.len());
    let mut aircraft: BTreeMap<ICAO, AircraftState> = BTreeMap::new();
    let mut reference: Option<Position> = None;
    let update_reference: UpdateIf = None;
    let start = Instant::now();
    for input in inputs {
        let (_, mut message) = Message::from_bytes((black_box(input.bytes.as_slice()), 0))?;
        if cpr {
            match &mut message.df {
                DF::ExtendedSquitterADSB(adsb) => decode_position(
                    &mut adsb.message,
                    input.timestamp,
                    &adsb.icao24,
                    &mut aircraft,
                    &mut reference,
                    &update_reference,
                ),
                DF::ExtendedSquitterTisB { cf, .. } => decode_position(
                    &mut cf.me,
                    input.timestamp,
                    &cf.aa,
                    &mut aircraft,
                    &mut reference,
                    &update_reference,
                ),
                _ => {}
            }
        }
        output.push(message);
    }
    let elapsed = start.elapsed();
    black_box(&output);
    black_box(&aircraft);
    // Inspection and destruction are outside the timed interval on both sides.
    let positions = output
        .iter()
        .filter(|message| {
            let me = match &message.df {
                DF::ExtendedSquitterADSB(adsb) => Some(&adsb.message),
                DF::ExtendedSquitterTisB { cf, .. } => Some(&cf.me),
                _ => None,
            };
            match me {
                Some(ME::BDS05 { inner, .. }) => inner.latitude.is_some(),
                Some(ME::BDS06 { inner, .. }) => inner.latitude.is_some(),
                _ => false,
            }
        })
        .count();
    Ok((elapsed, positions))
}

fn probe_formats() {
    for df in [
        0u8, 4, 5, 11, 16, 17, 18, 19, 20, 21, 24, 25, 26, 27, 28, 29, 30, 31,
    ] {
        let mut bytes = vec![0; if df < 16 { 7 } else { 14 }];
        bytes[0] = df << 3;
        let hex: String = bytes.iter().map(|b| format!("{b:02x}")).collect();
        match Message::from_bytes((&bytes, 0)) {
            Ok((tail, message)) => println!("{hex}: remainder={tail:?} {message:?}"),
            Err(error) => println!("{hex}: ERROR {error:?}"),
        }
    }
}

fn probe_cpr() -> Result<(), Box<dyn Error>> {
    // Valid DF17 frames encoding the same latitude87°, longitude0°.
    // The odd quantized latitude lies just below87°, while the even is exactly87°.
    let even_bytes = [141, 17, 34, 51, 72, 1, 2, 0, 0, 0, 0, 248, 26, 71];
    let odd_bytes = [141, 17, 34, 51, 72, 1, 5, 8, 136, 0, 0, 213, 150, 25];
    let (_, even_message) = Message::from_bytes((&even_bytes, 0))?;
    let (_, odd_message) = Message::from_bytes((&odd_bytes, 0))?;
    println!("even=8d11223348010200000000f81a47 crc={}", even_message.crc);
    println!("odd=8d11223348010508880000d59619 crc={}", odd_message.crc);
    match (&even_message.df, &odd_message.df) {
        (DF::ExtendedSquitterADSB(even), DF::ExtendedSquitterADSB(odd)) => {
            match (&even.message, &odd.message) {
                (ME::BDS05 { inner: even, .. }, ME::BDS05 { inner: odd, .. }) => {
                    println!("even CPR=({}, {})", even.lat_cpr, even.lon_cpr);
                    println!("odd CPR=({}, {})", odd.lat_cpr, odd.lon_cpr);
                    println!(
                        "airborne_position(odd, even)={:?}",
                        airborne_position(odd, even)
                    );
                    Ok(())
                }
                _ => Err("CPR fixture did not decode as airborne position".into()),
            }
        }
        _ => Err("CPR fixture did not decode as DF17".into()),
    }
}

// Persistent workers preload the corpus before announcing readiness. Each run
// allocates fresh output/state and calls the identical timed run_once workload.
// The parent controls ABAB ordering; workers never start an unrequested run.
fn worker(inputs: &[Input], cpr: bool) -> Result<(), Box<dyn Error>> {
    let stdin = io::stdin();
    let mut stdout = io::stdout().lock();
    writeln!(stdout, "ready {}", inputs.len())?;
    stdout.flush()?;
    for line in stdin.lock().lines() {
        match line?.trim() {
            "run" => {
                let (elapsed, positions) = run_once(inputs, cpr)?;
                writeln!(stdout, "{} {positions}", elapsed.as_nanos())?;
                stdout.flush()?;
            }
            "quit" => return Ok(()),
            other => return Err(format!("unknown worker command: {other:?}").into()),
        }
    }
    Ok(())
}

fn main() -> Result<(), Box<dyn Error>> {
    let arguments: Vec<_> = std::env::args().skip(1).collect();
    if arguments.as_slice() == ["--probe-cpr"] {
        return probe_cpr();
    }
    if arguments.len() == 2 && arguments[0] == "--probe-hex" {
        let hex = arguments[1].as_bytes();
        if hex.len() != 14 && hex.len() != 28 {
            return Err("expected 7 or 14 bytes".into());
        }
        let mut bytes = Vec::with_capacity(hex.len() / 2);
        for pair in hex.chunks_exact(2) {
            bytes.push(hex_digit(pair[0])? * 16 + hex_digit(pair[1])?);
        }
        println!("{}: {:?}", arguments[1], Message::from_bytes((&bytes, 0)));
        return Ok(());
    }
    if arguments.as_slice() == ["--probe-formats"] {
        probe_formats();
        return Ok(());
    }
    if arguments.len() != 2
        || !["--check", "--worker-decode", "--worker-cpr"].contains(&arguments[0].as_str())
    {
        return Err("usage: lean1090-oracle-bench --check|--worker-decode|--worker-cpr CORPUS.csv; or --probe-formats; or --probe-cpr; or --probe-hex HEX; comparative timing is controlled by bench/interleave.py".into());
    }
    let inputs = read_inputs(&arguments[1])?;
    if arguments[0] == "--check" {
        for cpr in [false, true] {
            let (_, positions) = run_once(&inputs, cpr)?;
            println!(
                "check mode={} messages={} positions={positions} ok",
                if cpr { "cpr" } else { "decode" },
                inputs.len()
            );
        }
        return Ok(());
    }
    worker(&inputs, arguments[0] == "--worker-cpr")
}

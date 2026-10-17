use deku::DekuContainerRead;
use rs1090::decode::bds::{bds50::TrackAndTurnReport, density, penalty, DecodedBds};
use std::error::Error;
use std::hint::black_box;
use std::io::{self, BufRead, Write};
use std::time::Instant;

// Exactly the BDS50 branch used by Comm-B inference: no other register's work.
// The MB-empty shortcut is outside the named-register decoder in rs1090.
fn decode(payload: &[u8; 7]) -> Option<(DecodedBds, f64)> {
    if payload.iter().all(|&x| x == 0) { return None; }
    let (_, report) = TrackAndTurnReport::from_bytes((payload, 0)).ok()?;
    let candidate = DecodedBds::Bds50(report);
    let score = density::density_score(&candidate).unwrap_or(0.0) + penalty::penalty(&candidate);
    if score < density::DENSITY_THRESHOLD { None } else { Some((candidate, score)) }
}

fn show(value: Option<f64>) -> String {
    value.map(|x| x.to_bits().to_string()).unwrap_or_else(|| "none".into())
}

fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<_> = std::env::args().skip(1).collect();
    if args.len() != 2 { return Err("usage: pilot --worker|--dump|--audit WORDS.txt".into()); }
    let text = std::fs::read_to_string(&args[1])?;
    let mut inputs = Vec::new();
    for line in text.lines() {
        let value: u64 = line.parse()?;
        if value >= (1u64 << 56) { return Err("word wider than 56 bits".into()); }
        let full = value.to_be_bytes();
        inputs.push(<[u8; 7]>::try_from(&full[1..])?);
    }
    if args[0] == "--audit" {
        for input in &inputs {
            if input.iter().all(|&x| x == 0) { println!("hard-reject"); continue; }
            match TrackAndTurnReport::from_bytes((input, 0)) {
                Err(_) => println!("hard-reject"),
                Ok((_, x)) => {
                    let candidate = DecodedBds::Bds50(x.clone());
                    let score = density::density_score(&candidate).unwrap_or(0.0) + penalty::penalty(&candidate);
                    let flag = if score < density::DENSITY_THRESHOLD { "score-reject" } else { "accepted" };
                    println!("{} {} {} {} {} {} {}", flag,
                        show(x.roll_angle), show(x.track_angle), show(x.groundspeed.map(f64::from)),
                        show(x.track_rate), show(x.true_airspeed.map(f64::from)), show(Some(score)));
                }
            }
        }
        return Ok(());
    }
    if args[0] == "--dump" {
        for input in &inputs {
            match decode(input) {
                None => println!("none"),
                Some((DecodedBds::Bds50(x), score)) => println!("{} {} {} {} {} {}",
                    show(x.roll_angle), show(x.track_angle), show(x.groundspeed.map(f64::from)),
                    show(x.track_rate), show(x.true_airspeed.map(f64::from)), show(Some(score))),
                _ => return Err("unexpected register".into()),
            }
        }
        return Ok(());
    }
    if args[0] != "--worker" { return Err("unknown mode".into()); }
    println!("ready {}", inputs.len()); io::stdout().flush()?;
    for line in io::stdin().lock().lines() {
        if line? == "quit" { break; }
        let mut output = Vec::with_capacity(inputs.len());
        let start = Instant::now();
        for input in &inputs { output.push(decode(black_box(input))); }
        let nanos = start.elapsed().as_nanos();
        black_box(&output);
        let accepted = output.iter().filter(|x| x.is_some()).count();
        println!("{nanos} {accepted}"); io::stdout().flush()?;
    }
    Ok(())
}

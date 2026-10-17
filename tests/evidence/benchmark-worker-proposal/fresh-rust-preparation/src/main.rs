use std::error::Error;
fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<_> = std::env::args().collect();
    match args.get(1).map(String::as_str) {
        Some("airports") => {
            for a in rs1090::data::airports::AIRPORTS.iter() {
                println!("{} {} {}", a.icao, a.lat.to_bits(), a.lon.to_bits());
            }
        }
        Some("timestamps") => {
            for line in std::fs::read_to_string("vendor/rs1090/crates/rs1090/data/long_flight.csv")?.lines() {
                let (time, _) = line.split_once(',').ok_or("missing comma")?;
                println!("{}", time.parse::<f64>()?.to_bits());
            }
        }
        _ => return Err("airports or timestamps required".into())
    }
    Ok(())
}

//! Review-only observation of the pinned oracle. No decoder or spec is modified.
use rs1090::decode::cpr::{
    airborne_position, airborne_position_with_reference, decode_position, decode_positions,
    surface_position_with_reference, AircraftState, CPRFormat, Position, UpdateIf,
};
use rs1090::decode::{TimedMessage, DF};
use rs1090::prelude::*;
use serde_json::{json, Value};
use std::collections::BTreeMap;
use std::error::Error;
use std::io::{BufWriter, Write};

#[derive(Clone)]
struct Cached {
    row: usize,
    timestamp: f64,
    message: AirbornePosition,
    position: Option<Position>,
}

struct ObservedState {
    timestamp: f64,
    position: Option<Position>,
    position_row: Option<usize>,
    even_ts: f64,
    odd_ts: f64,
    even: Option<Cached>,
    odd: Option<Cached>,
}

fn position_json(position: Option<Position>) -> Value {
    position.map_or(
        Value::Null,
        |p| json!({"lat_bits": p.latitude.to_bits(), "lon_bits": p.longitude.to_bits()}),
    )
}

fn cached_json(cached: Option<&Cached>) -> Value {
    cached.map_or(Value::Null, |c| {
        json!({"row": c.row, "timestamp_bits": c.timestamp.to_bits(),
            "odd": c.message.parity == CPRFormat::Odd,
            "lat_cpr": c.message.lat_cpr, "lon_cpr": c.message.lon_cpr,
            "position": position_json(c.position)})
    })
}

fn same_position(a: Option<Position>, b: Option<Position>) -> bool {
    match (a, b) {
        (None, None) => true,
        (Some(a), Some(b)) => {
            a.latitude.to_bits() == b.latitude.to_bits()
                && a.longitude.to_bits() == b.longitude.to_bits()
        }
        _ => false,
    }
}

fn me_position(me: &ME) -> Option<Position> {
    let (lat, lon) = match me {
        ME::BDS05 { inner, .. } => (inner.latitude, inner.longitude),
        ME::BDS06 { inner, .. } => (inner.latitude, inner.longitude),
        _ => return None,
    };
    match (lat, lon) {
        (Some(latitude), Some(longitude)) => Some(Position {
            latitude,
            longitude,
        }),
        (None, None) => None,
        _ => panic!("oracle returned only one coordinate"),
    }
}

fn message_position(message: &Message) -> Option<Position> {
    match &message.df {
        DF::ExtendedSquitterADSB(adsb) => me_position(&adsb.message),
        DF::ExtendedSquitterTisB { cf, .. } => me_position(&cf.me),
        _ => None,
    }
}

fn read_inputs(path: &str) -> Result<Vec<TimedMessage>, Box<dyn Error>> {
    let text = std::fs::read_to_string(path)?;
    let mut out = Vec::with_capacity(172_432);
    for (row, line) in text.lines().enumerate() {
        let (time, beast) = line.split_once(',').ok_or("expected timestamp,frame")?;
        let hex = beast.get(18..).ok_or("missing Beast prefix")?;
        if ![14, 28].contains(&hex.len()) {
            return Err(format!("invalid frame length at row {}", row + 1).into());
        }
        let frame: Vec<u8> = hex
            .as_bytes()
            .chunks_exact(2)
            .map(|b| {
                let s = std::str::from_utf8(b)?;
                Ok(u8::from_str_radix(s, 16)?)
            })
            .collect::<Result<_, Box<dyn Error>>>()?;
        let timestamp: f64 = time.parse()?;
        if !timestamp.is_finite() {
            return Err("non-finite timestamp".into());
        }
        let (_, message) = Message::from_bytes((&frame, 0))?;
        out.push(TimedMessage {
            timestamp,
            frame,
            message: Some(message),
            metadata: Vec::new(),
            decode_time: None,
        });
    }
    if out.len() != 172_432 {
        return Err("unexpected corpus size".into());
    }
    Ok(out)
}

fn increment(counts: &mut BTreeMap<String, usize>, label: &str) {
    *counts.entry(label.to_owned()).or_default() += 1;
}

fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<String> = std::env::args().skip(1).collect();
    if args.len() != 2 {
        return Err("usage: lean1090-review-cpr-oracle CORPUS.csv TRACE.jsonl".into());
    }
    let mut baseline = read_inputs(&args[0])?;
    let update_reference: UpdateIf = None;
    decode_positions(&mut baseline, None, &update_reference);
    let expected: Vec<Option<Position>> = baseline
        .iter()
        .map(|tm| tm.message.as_ref().and_then(message_position))
        .collect();
    drop(baseline);

    let mut inputs = read_inputs(&args[0])?;
    let mut aircraft = BTreeMap::<ICAO, AircraftState>::new();
    let mut observed = BTreeMap::<ICAO, ObservedState>::new();
    let mut reference = None;
    let mut writer = BufWriter::new(std::fs::File::create(&args[1])?);
    let mut counts = BTreeMap::<String, usize>::new();

    for (index, timed) in inputs.iter_mut().enumerate() {
        let row = index + 1;
        let timestamp = timed.timestamp;
        let message = timed.message.as_mut().ok_or("message missing")?;
        let (icao, me) = match &mut message.df {
            DF::ExtendedSquitterADSB(adsb) => (adsb.icao24, &mut adsb.message),
            DF::ExtendedSquitterTisB { cf, .. } => (cf.aa, &mut cf.me),
            _ => {
                assert!(expected[index].is_none());
                continue;
            }
        };
        let state = observed.entry(icao).or_insert(ObservedState {
            timestamp,
            position: None,
            position_row: None,
            even_ts: timestamp,
            odd_ts: timestamp,
            even: None,
            odd: None,
        });
        let previous_ref = state.position.map_or(Value::Null, |p| {
            json!({"row": state.position_row, "timestamp_bits": state.timestamp.to_bits(), "position": position_json(Some(p))})
        });
        let mut trace: Option<Value> = None;
        let mut cached_airborne: Option<AirbornePosition> = None;
        let mut negative_time = false;
        let mut global_candidate = None;
        let mut local_candidate = None;
        let mut route_if_accepted = "none";
        match me {
            ME::BDS05 { inner, .. } => {
                increment(&mut counts, "airborne_frames");
                let odd = inner.parity == CPRFormat::Odd;
                let opposite = if odd {
                    state.even.as_ref()
                } else {
                    state.odd.as_ref()
                };
                let opposite_ts = if odd { state.even_ts } else { state.odd_ts };
                negative_time = timestamp - opposite_ts < 0.0;
                let global_attempt =
                    !negative_time && (timestamp - opposite_ts).abs() < 30.0 && opposite.is_some();
                let mut mate_backfill = None;
                if global_attempt {
                    increment(&mut counts, "global_attempts");
                    if let Some(other) = opposite {
                        global_candidate = airborne_position(&other.message, inner);
                        mate_backfill = airborne_position(inner, &other.message);
                    }
                }
                let local_eligible = !negative_time
                    && global_candidate.is_none()
                    && timestamp - state.timestamp < 180.0;
                if local_eligible {
                    if let Some(p) = state.position {
                        local_candidate =
                            airborne_position_with_reference(inner, p.latitude, p.longitude);
                    }
                }
                route_if_accepted = if global_candidate.is_some() {
                    "global"
                } else {
                    "local"
                };
                trace = Some(
                    json!({"row": row, "timestamp_bits": timestamp.to_bits(), "icao": icao.to_string(),
                    "mode": "airborne", "odd": odd, "lat_cpr": inner.lat_cpr, "lon_cpr": inner.lon_cpr,
                    "previous_ref": previous_ref, "opposite": cached_json(opposite),
                    "global_attempt": global_attempt, "global_candidate": position_json(global_candidate),
                    "mate_backfill": position_json(mate_backfill), "local_candidate": position_json(local_candidate),
                    "negative_time": negative_time}),
                );
                cached_airborne = Some(*inner);
            }
            ME::BDS06 { inner, .. } => {
                increment(&mut counts, "surface_frames");
                if let Some(p) = state.position {
                    local_candidate =
                        surface_position_with_reference(inner, p.latitude, p.longitude);
                }
                route_if_accepted = "surface_local";
                trace = Some(
                    json!({"row": row, "timestamp_bits": timestamp.to_bits(), "icao": icao.to_string(),
                    "mode": "surface", "odd": inner.parity == CPRFormat::Odd,
                    "lat_cpr": inner.lat_cpr, "lon_cpr": inner.lon_cpr,
                    "previous_ref": previous_ref, "opposite": Value::Null,
                    "global_attempt": false, "global_candidate": Value::Null, "mate_backfill": Value::Null,
                    "local_candidate": position_json(local_candidate), "negative_time": false}),
                );
            }
            _ => {}
        }

        decode_position(
            me,
            timestamp,
            &icao,
            &mut aircraft,
            &mut reference,
            &update_reference,
        );
        let actual = me_position(me);
        assert!(
            same_position(actual, expected[index]),
            "decode_positions mismatch at row {row}"
        );
        assert!(
            reference.is_none(),
            "benchmark starts without external reference and disables updates"
        );
        if let Some(position) = actual {
            increment(&mut counts, "resolved_positions");
            let predicted = if route_if_accepted == "global" {
                global_candidate
            } else {
                local_candidate
            };
            assert!(
                same_position(Some(position), predicted),
                "route classification mismatch at row {row}"
            );
            increment(&mut counts, &format!("accepted_{route_if_accepted}"));
            if state.position.is_some() {
                increment(&mut counts, "resolved_with_previous_ref");
            }
            if let Some(trace) = trace.as_ref() {
                if route_if_accepted == "global" {
                    if trace["opposite"]["position"].is_null() {
                        increment(&mut counts, "accepted_global_unresolved_mate");
                    } else {
                        increment(&mut counts, "accepted_global_resolved_mate");
                    }
                }
            }
            state.position = Some(position);
            state.position_row = Some(row);
            state.timestamp = timestamp;
        }
        assert!(
            same_position(
                state.position,
                aircraft.get(&icao).and_then(|s| s.last_position())
            ),
            "state position mismatch at row {row}"
        );
        if let Some(before) = cached_airborne {
            if !negative_time {
                let after = match me {
                    ME::BDS05 { inner, .. } => *inner,
                    _ => before,
                };
                let cache = Cached {
                    row,
                    timestamp,
                    message: after,
                    position: actual,
                };
                if after.parity == CPRFormat::Odd {
                    state.odd_ts = timestamp;
                    state.odd = Some(cache);
                } else {
                    state.even_ts = timestamp;
                    state.even = Some(cache);
                }
            } else {
                increment(&mut counts, "negative_time_frames");
            }
        }
        if let Some(mut trace) = trace {
            trace["position"] = position_json(actual);
            trace["route"] = json!(if actual.is_some() {
                route_if_accepted
            } else {
                "none"
            });
            serde_json::to_writer(&mut writer, &trace)?;
            writer.write_all(b"\n")?;
        }
    }
    writer.flush()?;
    counts.insert("corpus_messages".to_owned(), inputs.len());
    counts.insert(
        "decode_positions_bitwise_crosschecks".to_owned(),
        inputs.len(),
    );
    println!("{}", serde_json::to_string_pretty(&counts)?);
    Ok(())
}

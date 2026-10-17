//! Diagnostic stream checker: expected positions come from actual decode_positions.
//! Branch labels are observations around a separate actual decode_position replay;
//! every replay output must be bit-identical to the batch output before it is used.
use rs1090::decode::cpr::{
    airborne_position, airborne_position_with_reference, decode_position, decode_positions,
    surface_position_with_reference, AircraftState, CPRFormat, Position, UpdateIf,
};
use rs1090::decode::{TimedMessage, DF};
use rs1090::prelude::*;
use serde_json::{json, Value};
use std::collections::{BTreeMap, BTreeSet};
use std::error::Error;
use std::io::{self, BufRead, Write};
#[derive(Clone)]
struct Row {
    id: u64,
    timestamp: f64,
    frame: Vec<u8>,
}
#[derive(Clone)]
struct Observed {
    ts: f64,
    even_ts: f64,
    odd_ts: f64,
    even: Option<AirbornePosition>,
    odd: Option<AirbornePosition>,
}
fn pos_json(p: Option<Position>) -> Value {
    p.map_or(Value::Null, |p| {
        json!([p.latitude.to_bits(), p.longitude.to_bits()])
    })
}
fn me_pos(me: &ME) -> Option<Position> {
    let (a, b) = match me {
        ME::BDS05 { inner, .. } => (inner.latitude, inner.longitude),
        ME::BDS06 { inner, .. } => (inner.latitude, inner.longitude),
        _ => return None,
    };
    match (a, b) {
        (Some(latitude), Some(longitude)) => Some(Position {
            latitude,
            longitude,
        }),
        (None, None) => None,
        _ => panic!("partial coordinate"),
    }
}
fn msg_pos(m: &Message) -> Option<Position> {
    match &m.df {
        DF::ExtendedSquitterADSB(a) => me_pos(&a.message),
        DF::ExtendedSquitterTisB { cf, .. } => me_pos(&cf.me),
        _ => None,
    }
}
fn distance(a: Position, b: Position) -> f64 {
    let dlat = (b.latitude - a.latitude).to_radians();
    let dlon = (b.longitude - a.longitude).to_radians();
    let h = (dlat / 2.).sin() * (dlat / 2.).sin()
        + a.latitude.to_radians().cos()
            * b.latitude.to_radians().cos()
            * (dlon / 2.).sin()
            * (dlon / 2.).sin();
    let c = 2. * h.sqrt().atan2((1. - h).sqrt());
    6371. * c
}
// The public state is checked after every real call, not merely at stream end.
fn nearest_airport(p: Position) -> Option<String> {
    rs1090::data::airports::AIRPORTS
        .iter()
        .filter_map(|a| {
            let d = distance(
                p,
                Position {
                    latitude: a.lat,
                    longitude: a.lon,
                },
            );
            (d < 10.).then_some((d, a.icao.clone()))
        })
        .min_by(|a, b| a.0.partial_cmp(&b.0).unwrap())
        .map(|(_, airport)| airport)
}
fn callback(mode: u64) -> UpdateIf {
    match mode {
        0 => None,
        1 => Some(Box::new(|_| true)),
        2 => Some(Box::new(|p| p.alt.is_some_and(|a| a < 1000))),
        3 => Some(Box::new(|p| {
            p.time_sync && matches!(p.source, rs1090::decode::bds::bds05::Source::Gnss)
        })),
        _ => panic!("bad update mode"),
    }
}
fn timed(r: &Row) -> TimedMessage {
    TimedMessage {
        timestamp: r.timestamp,
        frame: r.frame.clone(),
        message: Message::from_bytes((&r.frame, 0)).ok().map(|(_, m)| m),
        metadata: vec![],
        decode_time: None,
    }
}
fn run(
    name: &str,
    reference: Option<Position>,
    mode: u64,
    rows: &[Row],
) -> Result<(), Box<dyn Error>> {
    let mut batch: Vec<_> = rows.iter().map(timed).collect();
    decode_positions(&mut batch, reference, &callback(mode));
    let mut states = BTreeMap::<ICAO, AircraftState>::new();
    let mut obs = BTreeMap::<ICAO, Observed>::new();
    let mut shared = reference;
    let mut out = io::BufWriter::new(io::stdout().lock());
    for (r, expected) in rows.iter().zip(batch.iter()) {
        let expected_pos = expected.message.as_ref().and_then(msg_pos);
        let mut original = timed(r);
        let mut labels = vec![];
        let mut routed = false;
        let mut candidate = None;
        let mut early = false;
        let mut motion_pass = true;
        let mut metrics = serde_json::Map::new();
        let mut integrity = Value::Null;
        if let Some(message) = &mut original.message {
            let pair = match &mut message.df {
                DF::ExtendedSquitterADSB(a) => Some((a.icao24, &mut a.message, "df17")),
                DF::ExtendedSquitterTisB { cf, .. } => Some((cf.aa, &mut cf.me, "df18")),
                _ => None,
            };
            if let Some((address, me, df)) = pair {
                routed = true;
                labels.push(df.to_owned());
                let old_pos = states.get(&address).and_then(|s| s.last_position());
                let old_shared = shared;
                let old_altitude = states.get(&address).and_then(|s| s.last_altitude());
                let old_airport = states.get(&address).and_then(|s| s.airport.clone());
                let mut expected_seen: BTreeSet<u8> = states
                    .get(&address)
                    .map(|s| s.seen_bds().clone())
                    .unwrap_or_default();
                let mut expected_altitude = old_altitude;
                let mut expected_airport = old_airport.clone();
                let mut expected_shared = old_shared;
                let mut airborne = false;
                let o = obs.entry(address).or_insert(Observed {
                    ts: r.timestamp,
                    even_ts: r.timestamp,
                    odd_ts: r.timestamp,
                    even: None,
                    odd: None,
                });
                let mut cached = None;
                let mut surface = false;
                match me {
                    ME::BDS05 { inner, .. } => {
                        airborne = true;
                        labels.push("airborne".into());
                        let odd = inner.parity == CPRFormat::Odd;
                        labels.push(if odd { "airborne_odd" } else { "airborne_even" }.into());
                        let opposite_ts = if odd { o.even_ts } else { o.odd_ts };
                        let previous = if odd { o.even } else { o.odd };
                        let gap = r.timestamp - opposite_ts;
                        early = gap < 0.;
                        if early {
                            labels.push("cross_parity_out_of_order".into());
                        } else {
                            labels.push(
                                if gap < 30. {
                                    "pair_gap_inside"
                                } else if gap == 30. {
                                    "pair_gap_exact"
                                } else {
                                    "pair_gap_outside"
                                }
                                .into(),
                            );
                            if gap.abs() < 30. {
                                if let Some(previous) = previous {
                                    labels.push(
                                        if odd {
                                            "pair_even_then_odd"
                                        } else {
                                            "pair_odd_then_even"
                                        }
                                        .into(),
                                    );
                                    candidate = airborne_position(&previous, inner);
                                    labels.push(
                                        if candidate.is_some() {
                                            "global_success"
                                        } else {
                                            "global_rejected"
                                        }
                                        .into(),
                                    );
                                } else {
                                    labels.push("opposite_slot_empty".into());
                                }
                            }
                            if candidate.is_none() {
                                let age = r.timestamp - o.ts;
                                metrics.insert("signed_local_age_seconds".into(), json!(age));
                                labels.push(
                                    if age < 180. {
                                        "local_age_inside"
                                    } else if age == 180. {
                                        "local_age_exact"
                                    } else {
                                        "local_age_outside"
                                    }
                                    .into(),
                                );
                                if age < 180. {
                                    if let Some(p) = old_pos {
                                        labels.push("local_attempt".into());
                                        candidate = airborne_position_with_reference(
                                            inner,
                                            p.latitude,
                                            p.longitude,
                                        );
                                        labels.push(
                                            if candidate.is_some() {
                                                "local_success"
                                            } else {
                                                "local_rejected"
                                            }
                                            .into(),
                                        );
                                    } else {
                                        labels.push("local_no_previous_position".into());
                                    }
                                }
                            }
                            if let (Some(p), Some(old)) = (candidate, old_pos) {
                                let signed_dt = r.timestamp - o.ts;
                                let dt = signed_dt.abs();
                                let d = distance(p, old);
                                let hours = dt / 3600.;
                                metrics.insert("motion_signed_dt_seconds".into(), json!(signed_dt));
                                metrics.insert("motion_dt_seconds".into(), json!(dt));
                                metrics.insert("motion_distance_km".into(), json!(d));
                                if hours > 0. {
                                    metrics.insert("speed_kmh".into(), json!(d / hours));
                                }
                                if signed_dt < 0. && d > 0. {
                                    labels.push("airborne_backward_motion".into());
                                    if labels.iter().any(|s| s == "local_attempt") {
                                        labels.push("signed_local_age_backward_motion".into());
                                    }
                                    if dt < 1800. {
                                        labels.push(
                                            if d / hours <= 1200. {
                                                "backward_speed_below_threshold"
                                            } else {
                                                "backward_speed_above_threshold"
                                            }
                                            .into(),
                                        );
                                    }
                                }
                                labels.push(
                                    if dt < 1800. {
                                        "speed_gap_inside"
                                    } else if dt == 1800. {
                                        "speed_gap_exact"
                                    } else {
                                        "speed_gap_outside"
                                    }
                                    .into(),
                                );
                                if dt == 0. {
                                    labels.push("speed_zero_dt".into());
                                } else if dt < 1800. {
                                    let speed = d / hours;
                                    labels.push(
                                        if speed < 1200. {
                                            "speed_below_threshold"
                                        } else if speed == 1200. {
                                            "speed_exact_threshold"
                                        } else {
                                            "speed_above_threshold"
                                        }
                                        .into(),
                                    );
                                }
                                if dt < 1800. && hours > 0. && d / hours > 1200. {
                                    motion_pass = false;
                                    labels.push("speed_rejection".into());
                                } else if d > 500. && dt < 30. {
                                    motion_pass = false;
                                    labels.push("jump_rejection".into());
                                } else {
                                    labels.push("motion_pass".into());
                                }
                                labels.push(
                                    if d < 500. {
                                        "distance_below_500"
                                    } else if d == 500. {
                                        "distance_exact_500"
                                    } else {
                                        "distance_above_500"
                                    }
                                    .into(),
                                );
                            }
                            if r.timestamp < if odd { o.odd_ts } else { o.even_ts } {
                                labels.push("same_parity_out_of_order_replacement".into());
                            }
                            cached = Some(*inner);
                        }
                    }
                    ME::BDS06 { inner, .. } => {
                        surface = true;
                        labels.push("surface".into());
                        labels.push(
                            if inner.parity == CPRFormat::Odd {
                                "surface_odd"
                            } else {
                                "surface_even"
                            }
                            .into(),
                        );
                        if let Some(old) = old_pos {
                            labels.push("surface_has_previous".into());
                            let p =
                                surface_position_with_reference(inner, old.latitude, old.longitude);
                            if let Some(p) = p {
                                let own_distance = distance(old, p);
                                metrics.insert(
                                    "own_reference_distance_km".into(),
                                    json!(own_distance),
                                );
                                // A 2m band brackets adjacent latitude codes for both parities.
                                if own_distance < 1. && own_distance >= 0.998 {
                                    labels.push("surface_own_1km_just_inside".into());
                                } else if own_distance >= 1. && own_distance <= 1.002 {
                                    labels.push("surface_own_1km_just_outside".into());
                                }
                                if own_distance < 1. {
                                    candidate = Some(p);
                                    labels.push("surface_own_within_1km".into());
                                } else {
                                    labels.push("surface_own_outside_1km".into());
                                }
                            } else {
                                labels.push("surface_own_decode_rejected".into());
                            }
                        }
                        if candidate.is_none() {
                            if let Some(reference) = shared {
                                labels.push("surface_shared_attempt".into());
                                let p = surface_position_with_reference(
                                    inner,
                                    reference.latitude,
                                    reference.longitude,
                                );
                                if let Some(p) = p {
                                    if old_pos.is_some() {
                                        candidate = Some(p);
                                        labels.push("surface_existing_bypasses_airport".into());
                                    } else {
                                        let near =
                                            rs1090::data::airports::AIRPORTS.iter().any(|a| {
                                                distance(
                                                    p,
                                                    Position {
                                                        latitude: a.lat,
                                                        longitude: a.lon,
                                                    },
                                                ) < 10.
                                            });
                                        labels.push(
                                            if near {
                                                "surface_first_near_airport"
                                            } else {
                                                "surface_first_far_from_airport"
                                            }
                                            .into(),
                                        );
                                        if near {
                                            candidate = Some(p);
                                        }
                                    }
                                } else {
                                    labels.push("surface_shared_decode_rejected".into());
                                }
                            } else {
                                labels.push("surface_no_shared_reference".into());
                            }
                        }
                        if old_pos.is_some() {
                            labels.push(
                                if r.timestamp < o.ts {
                                    "surface_out_of_order"
                                } else if r.timestamp - o.ts >= 180. {
                                    "surface_stale_previous"
                                } else {
                                    "surface_recent_previous"
                                }
                                .into(),
                            );
                        }
                    }
                    _ => {
                        labels.push("other_adsb".into());
                    }
                }
                let expected = if airborne && !motion_pass {
                    None
                } else {
                    candidate
                };
                if let Some(p) = expected {
                    if let ME::BDS05 { inner, .. } = me {
                        expected_altitude = inner.alt;
                        expected_airport = None;
                        expected_seen.insert(0x05);
                        if old_airport.is_some() {
                            labels.push("transition_surface_to_airborne_airport_cleared".into());
                        }
                        match callback(mode) {
                            None => labels.push("callback_absent".into()),
                            Some(f) => {
                                if f(inner) {
                                    labels.push("callback_true".into());
                                    expected_shared = Some(p);
                                } else {
                                    labels.push("callback_false".into());
                                }
                            }
                        }
                    } else if surface {
                        expected_altitude = None;
                        expected_seen.insert(0x06);
                        if old_altitude.is_some() {
                            labels.push("transition_airborne_to_surface_altitude_reset".into());
                        }
                        if old_airport.is_none() {
                            labels.push("surface_airport_lookup_none".into());
                            expected_airport = nearest_airport(p);
                            labels.push(
                                if expected_airport.is_some() {
                                    "surface_airport_lookup_found"
                                } else {
                                    "surface_airport_lookup_missing"
                                }
                                .into(),
                            );
                        } else {
                            labels.push("surface_airport_preserved_existing".into());
                            let nearest = nearest_airport(p);
                            if nearest != old_airport {
                                labels.push("surface_airport_preserved_despite_new_nearest".into());
                            }
                        }
                    }
                } else if !airborne && !surface {
                    let code = match me {
                        ME::BDS08 { .. } => Some(0x08),
                        ME::BDS09(_) => Some(0x09),
                        ME::BDS61(_) => Some(0x61),
                        ME::BDS62(_) => Some(0x62),
                        ME::BDS65(_) => Some(0x65),
                        _ => None,
                    };
                    if let Some(code) = code {
                        expected_seen.insert(code);
                    }
                }
                decode_position(
                    me,
                    r.timestamp,
                    &address,
                    &mut states,
                    &mut shared,
                    &callback(mode),
                );
                let got = me_pos(me);
                // Every shadow label set must predict the actual result, including
                // unresolved results. Surface has no motion gate. Candidate plus
                // no previous position passes the airborne motion gate vacuously.
                assert_eq!(
                    pos_json(got),
                    pos_json(expected),
                    "shadow/real position disagreement {name}/{} labels={labels:?}",
                    r.id
                );
                let actual_state = states.get(&address).expect("routed state exists");
                assert_eq!(
                    pos_json(actual_state.last_position()),
                    pos_json(expected.or(old_pos)),
                    "shadow/real state position disagreement {name}/{}",
                    r.id
                );
                assert_eq!(
                    actual_state.last_altitude(),
                    expected_altitude,
                    "shadow/real altitude disagreement {name}/{}",
                    r.id
                );
                assert_eq!(
                    actual_state.airport, expected_airport,
                    "shadow/real airport disagreement {name}/{}",
                    r.id
                );
                assert_eq!(
                    *actual_state.seen_bds(),
                    expected_seen,
                    "shadow/real evidence disagreement {name}/{}",
                    r.id
                );
                assert_eq!(
                    pos_json(shared),
                    pos_json(expected_shared),
                    "shadow/real reference disagreement {name}/{}",
                    r.id
                );
                integrity = json!({"candidate":pos_json(candidate), "motion_pass":motion_pass,
                    "predicted_position":pos_json(expected), "actual_position":pos_json(got),
                    "position_asserted":true, "public_state_asserted":true,
                    "before_airport":old_airport,"after_airport":actual_state.airport,
                    "before_altitude":old_altitude,"after_altitude":actual_state.last_altitude()});
                if let ME::BDS05 { inner, .. } = me {
                    if got.is_some() {
                        labels.push(
                            if callback(mode).as_ref().is_some_and(|f| f(inner)) {
                                "accepted_callback_true"
                            } else {
                                "accepted_callback_false"
                            }
                            .into(),
                        );
                    }
                }
                assert_eq!(
                    pos_json(got),
                    pos_json(expected_pos),
                    "batch/replay mismatch {name}/{}",
                    r.id
                );
                if got.is_some() {
                    o.ts = r.timestamp;
                    labels.push("resolved".into());
                } else {
                    labels.push("unresolved".into());
                }
                if let Some(c) = cached {
                    if c.parity == CPRFormat::Odd {
                        o.odd = Some(c);
                        o.odd_ts = r.timestamp;
                    } else {
                        o.even = Some(c);
                        o.even_ts = r.timestamp;
                    }
                    labels.push(
                        if got.is_some() {
                            "cache_replace_accepted"
                        } else {
                            "cache_replace_failed"
                        }
                        .into(),
                    );
                }
                if early {
                    labels.push("cache_unchanged_early_return".into());
                }
                if pos_json(shared) != pos_json(old_shared) {
                    labels.push(
                        if old_shared.is_none() {
                            "reference_initialized"
                        } else {
                            "reference_updated"
                        }
                        .into(),
                    );
                } else {
                    labels.push("reference_unchanged".into());
                }
            } else {
                labels.push("non_adsb".into());
            }
        } else {
            labels.push("decode_rejected".into());
        }
        if !routed {
            assert!(expected_pos.is_none(), "unrouted position {name}/{}", r.id);
            integrity = json!({"position_asserted":true,"public_state_asserted":true});
        }
        // These generated strata are promises about decoded distances/times, not
        // merely encoder inputs. Fail if CPR quantization moves a promised case.
        if name.starts_with("surface_own_1km_") && r.id == 2 {
            let d = metrics["own_reference_distance_km"].as_f64().unwrap();
            assert!(
                (d - 1.).abs() < 0.002,
                "1km stratum not adjacent: {name} {d}"
            );
            assert_eq!(d < 1., name.starts_with("surface_own_1km_inside"));
        }
        if name.starts_with("backward_speed_1200_") && r.id == 3 {
            assert!(metrics["motion_signed_dt_seconds"].as_f64().unwrap() < 0.);
            assert!(metrics["motion_distance_km"].as_f64().unwrap() > 0.);
            let speed = metrics["speed_kmh"].as_f64().unwrap();
            assert!(
                (speed - 1200.).abs() < 0.001,
                "speed stratum too distant: {name} {speed}"
            );
            assert_eq!(speed < 1200., name.starts_with("backward_speed_1200_below"));
        }
        if name.starts_with("signed_local_age_motion_") && r.id == 3 {
            assert!(metrics["signed_local_age_seconds"].as_f64().unwrap() < 0.);
            assert!(metrics["motion_distance_km"].as_f64().unwrap() > 0.);
            assert!(labels.iter().any(|l| l == "local_success"));
            assert!(expected_pos.is_some());
        }
        writeln!(
            out,
            "{}",
            json!({"stream":name,"id":r.id,"position":pos_json(expected_pos),"routed":routed,
                "branches":labels,"metrics":metrics,"label_integrity":integrity})
        )?;
    }
    let aircraft:Vec<_>=states.iter().map(|(a,s)|json!({"address":u32::from_str_radix(&a.to_string(),16).unwrap(),"position":pos_json(s.last_position()),"altitude":s.last_altitude(),"airport":s.airport,"seen":s.seen_bds()})).collect();
    writeln!(
        out,
        "{}",
        json!({"stream":name,"final":true,"reference":pos_json(shared),"aircraft":aircraft})
    )?;
    Ok(())
}
fn parse_position(v: &Value) -> Option<Position> {
    if v.is_null() {
        None
    } else {
        Some(Position {
            latitude: f64::from_bits(v[0].as_u64().unwrap()),
            longitude: f64::from_bits(v[1].as_u64().unwrap()),
        })
    }
}
fn main() -> Result<(), Box<dyn Error>> {
    let mut name = String::new();
    let mut reference = None;
    let mut mode = 0;
    let mut rows = vec![];
    for line in io::stdin().lock().lines() {
        let j: Value = serde_json::from_str(&line?)?;
        if j["kind"] == "header" {
            if !name.is_empty() {
                run(&name, reference, mode, &rows)?;
            }
            name = j["stream"].as_str().unwrap().into();
            reference = parse_position(&j["reference"]);
            mode = j["update"].as_u64().unwrap();
            rows.clear();
        } else {
            let hex = j["hex"].as_str().unwrap();
            let frame = (0..hex.len())
                .step_by(2)
                .map(|i| u8::from_str_radix(&hex[i..i + 2], 16))
                .collect::<Result<Vec<_>, _>>()?;
            rows.push(Row {
                id: j["id"].as_u64().unwrap(),
                timestamp: f64::from_bits(j["timestamp_bits"].as_u64().unwrap()),
                frame,
            });
        }
    }
    if !name.is_empty() {
        run(&name, reference, mode, &rows)?;
    }
    Ok(())
}

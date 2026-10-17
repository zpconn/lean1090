use rs1090::prelude::*;
use serde_json::{json, Value};
use std::io::{self, BufRead, BufWriter, Write};

fn bytes(text: &str) -> Option<Vec<u8>> {
    if text.len() % 2 != 0 || !text.is_ascii() { return None; }
    text.as_bytes().chunks_exact(2).map(|pair| {
        let hi = (pair[0] as char).to_digit(16)?;
        let lo = (pair[1] as char).to_digit(16)?;
        Some((16 * hi + lo) as u8)
    }).collect()
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let input = io::stdin();
    let mut output = BufWriter::new(io::stdout().lock());
    for line in input.lock().lines() {
        let line = line?;
        let text = line.trim();
        if text.is_empty() { continue; }
        let data = bytes(text).ok_or("invalid hexadecimal input")?;
        let result = match Message::from_bytes((&data, 0)) {
            Ok(((rest, offset), message)) => {
                assert_eq!(offset, 0, "whole-frame entrypoint must finish on a byte");
                let remainder = rest.iter().map(|b| format!("{b:02x}")).collect::<String>();
                json!({"oracle": message, "crc": message.crc,
                    "consumed": data.len() - rest.len(), "remainder": remainder})
            }
            Err(_) => Value::Null,
        };
        serde_json::to_writer(&mut output, &result)?;
        writeln!(&mut output)?;
    }
    output.flush()?;
    Ok(())
}

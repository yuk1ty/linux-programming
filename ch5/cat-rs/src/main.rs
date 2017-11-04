use std::env;
use std::io;
use std::io::prelude::*;
use std::fs::File;

fn main() {
    let mut args = env::args();
    if let Some(file) = args.nth(1) {
        println!("{}", read_file(&file).unwrap());
    }
}

fn read_file(filename: &String) -> Result<String, io::Error> {
    let mut file = File::open(filename)?;
    let mut content = String::new();
    file.read_to_string(&mut content)?;
    Ok(content)
}

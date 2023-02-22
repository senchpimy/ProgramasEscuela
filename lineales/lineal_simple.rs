use std::io::{stdin};
use rand::Rng;
fn main() {
    let mut rng=rand::thread_rng();
    let incognita:i32= rng.gen_range(2..15);
    let valor_extra:i32=rng.gen_range(2..20);
    let multiplicacion:i32=rng.gen_range(2..20);
    let mut s=String::new();
    let mut total:i32=(multiplicacion*incognita)+valor_extra;

    println!("{}x + {} = {}",multiplicacion,valor_extra,total);

    stdin().read_line(&mut s);
    println!("{}", incognita);
}

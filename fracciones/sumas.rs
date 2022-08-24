use std::io::{stdin};
use rand::Rng;
fn main() {
    let mut total:i32=0;
    let mut ra:i32;
    let mut s=String::new();
    let mut rng=rand::thread_rng();
    let fin:i32= rng.gen_range(5..9);
    for _ in 0..fin{
        ra=rng.gen_range(-25..25);
        println!("{} ",ra);
        total=total+ra;
    }
    stdin().read_line(&mut s);
    println!("{}", total);
}

use std::io::{stdin};
use rand::Rng;
fn main() {
    let mut total:i32=0;
    let mut ra:i32;
      let mut s=String::new();
    let mut rng=rand::thread_rng();
    for _ in 0..4{
        ra=rng.gen_range(100000..999999);
        println!("{}",ra);
        total=total+ra;
    }
    stdin().read_line(&mut s);
    println!("{}", total);
}

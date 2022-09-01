use std::io::{stdin};
use rand::Rng;
fn main() {

    let total:i32;
    let num1:i32;
    let num2:i32;
    let mut rng=rand::thread_rng();
    let mut s=String::new();

    num1=rng.gen_range(10000..999999);
    num2=rng.gen_range(11..99);

    println!("{}", num1);
    println!("{}", num2);
    total=num1/num2;
    stdin().read_line(&mut s);
    println!("{}", total);
}

use std::io::{stdin};
use rand::Rng;
fn main() {
    let mut rng=rand::thread_rng();
    let incognita = [rng.gen_range(2..15),rng.gen_range(2..15)];
    let valor_extra=[rng.gen_range(2..20),rng.gen_range(2..20)];
    let multiplicacion=[rng.gen_range(2..20),rng.gen_range(2..20)];
    let mut s=String::new();
    let total = ((multiplicacion[0]*incognita[0])+valor_extra[0]) + ((multiplicacion[1]*incognita[1])+valor_extra[1]);

    println!("{}x + {} + {}y + {}= {}",multiplicacion[0],valor_extra[0],multiplicacion[1],valor_extra[1],total);

    stdin().read_line(&mut s);
    println!("x= {}     y= {}", incognita[0], incognita[1]);
}

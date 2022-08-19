use std::io::{stdin};
use rand::Rng;
fn main() {
    let total:i32;
    let num1:i32;
    let num2:i32;
    let mut s=String::new();
    let mut rng=rand::thread_rng();
    num1=rng.gen_range(100000..999999);
    num2=rng.gen_range(100000..999999);
    if num1>num2{
        println!("{}",num1);
        println!("{}",num2);
        total=num1-num2;
    }else{
        println!("{}",num2);
        println!("{}",num1);
        total=num2-num1;
    }
    stdin().read_line(&mut s);
    println!("{}", total);
}

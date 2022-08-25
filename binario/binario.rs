//use std::io::{stdin};
use rand::Rng;
fn main() {
    let mut total:i32=0;
    let mut ran:i32;
    let pote:i32;
    let mut ubicacion:u32=0;
    let mut valor:i32;
    let mut rng=rand::thread_rng();
    ran=rng.gen_range(0..99999);
    pote=rng.gen_range(2..20);
    println!("{} elevado a {}", ran,pote);
    while ran!=0{
        valor=(ran%10)*pote.pow(ubicacion);
        ran=ran/10;
        total=total+valor;
        ubicacion=ubicacion+1
    }
    println!("{}",total)
}

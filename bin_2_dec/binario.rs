fn main() {
    let mut total:i32=0;
    let mut ran:i32=1001101;
    let mut ubicacion:u32=0;
    let mut valor:i32;
    println!("{} elevado a decimal", ran);
    while ran!=0{
        valor=(ran%10)*2_i32.pow(ubicacion);
        ran=ran/10;
        total=total+valor;
        ubicacion=ubicacion+1
    }
    println!("{}",total)
}

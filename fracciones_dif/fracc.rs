use std::io::{stdin};
use rand::Rng;
fn main() {
    let mut ra:i32;
    let mut s=String::new();
    let mut bases=Vec::new();
    let mut dividendo=Vec::new();
    let mut rng=rand::thread_rng();
    ra=rng.gen_range(0..35);
    for i in 0..6{
        if i==3{
        ra=rng.gen_range(0..35)
        }
        dividendo.push(rng.gen_range(-99..99));
        bases.push(ra);
        println!("{}", &dividendo[i]);
        println!("--");
        println!("{}", &bases[i]);
        println!("          ");
    }
    let mut total=(1,1);
    for j in 0..6{
total=suma(dividendo[j],total.0,bases[j],total.1);
    }
    stdin().read_line(&mut s);
        println!("{}", total.0);
        println!("--");
        println!("{}", total.1);

}

fn suma(dividendo1:i32,dividendo2:i32,base1:i32,base2:i32) -> (i32, i32){
    let  x:i32;
    let  y:i32;
if base1==base2{
x=base1;
}else{
    x=base1*base2;
}
y=dividendo1*base2+dividendo2*base1;
(y,x)
}

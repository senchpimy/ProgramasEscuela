use rand::Rng;
use std::time::SystemTime;

fn main() {

    let mut lista:Vec<i32>;
    let mut lista2:Vec<i32>;
    let mut comparaciones:i32=0;
    timeit_m(|| create_list(), "Crear la lista");

    lista=create_list();
    lista2=create_list();
    timeit(||bubble_sort(&mut lista,&mut comparaciones),"Ordenar la lista");
    println!("Se hicieron {} comparaciones",comparaciones);
    let mut comparaciones_op:i32=0;
    timeit(||bubble_sort_optimized(&mut lista2, &mut comparaciones_op),"Ordenar la lista (optimizado)");
    println!("Se hicieron {} comparaciones en el algo op",comparaciones_op);
}

fn bubble_sort(lista:&mut Vec<i32>,comparaciones:&mut i32){
    let len = lista.len();
   for _ in 0..len {
    let mut bandera=true;
    for i in 0..len-1 {
        if lista[i]>lista[i+1]{
        bandera=false;
        *comparaciones+=1;
        lista.swap(i,i+1);
        }
    } 
    if bandera{break;}
   } 
}

pub fn bubble_sort_optimized(arr: &mut [i32],comparaciones:&mut i32) {
    let mut new_len: usize;
    let mut len = arr.len();
    loop {
        new_len = 0;
        for i in 1..len {
            if arr[i - 1] > arr[i] {
                arr.swap(i - 1, i);
                new_len = i;
                *comparaciones+=1;
            }
        }
        if new_len == 0 {
            break;
        }
        len = new_len;
    }
}


fn create_list()->Vec<i32>{
    let mut rng=rand::thread_rng();
    (0..10_001).map(|_| rng.gen_range(0..10_000)).collect()
}

fn timeit<F: FnMut() -> T, T>(mut f: F, desc:&str) -> T {
  let start = SystemTime::now();
  let result = f();
  let end = SystemTime::now();
  let duration = end.duration_since(start).unwrap();
  println!("{} {} milisegundos",desc, duration.as_millis());
  result
}

fn timeit_m<F: FnMut() -> T, T>(mut f: F, desc:&str) -> T {
  let start = SystemTime::now();
  let result = f();
  let end = SystemTime::now();
  let duration = end.duration_since(start).unwrap();
  println!("{} {} microsegundos",desc, duration.as_micros());
  result
}


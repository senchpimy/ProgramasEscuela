use rand::Rng;
use std::time::SystemTime;

fn main() {

    let mut lista:Vec<i32>;
    let mut comparaciones:i32=0;
    timeit(|| create_list());

    lista=create_list();
    timeit(||bubble_sort(&mut lista,&mut comparaciones));
    println!("{}",comparaciones);
}

fn bubble_sort(lista:&mut Vec<i32>,comparaciones:&mut i32){
   for j in 0..lista.len() {
    for i in 0..lista.len()-1 {
        if lista[i]>lista[i+1]{
        *comparaciones+=1;
        lista.swap(i,i+1);
        }
     
    } 
   } 
}

pub fn bubble_sort_optimized(arr: &mut [i32]) {
    let mut new_len: usize;
    let mut len = arr.len();
    loop {
        new_len = 0;
        for i in 1..len {
            if arr[i - 1] > arr[i] {
                arr.swap(i - 1, i);
                new_len = i;
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

fn timeit<F: FnMut() -> T, T>(mut f: F) -> T {
  let start = SystemTime::now();
  let result = f();
  let end = SystemTime::now();
  let duration = end.duration_since(start).unwrap();
  println!("Crear la lista tomo: {} nanosegundos", duration.as_nanos());
  println!("Crear la lista tomo: {} microsegundos", duration.as_micros());
  println!("Crear la lista tomo: {} milisegundos", duration.as_millis());
  result
}


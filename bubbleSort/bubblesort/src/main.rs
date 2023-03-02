use rand::Rng;
use std::time::SystemTime;

fn test(crear:&mut i32, ordenar:&mut i32, comp:&mut i32, bal:&mut i32,ordenar_op:&mut i32,comparaciones_op_rec:&mut i32,mome:&mut i32) {
    let mut lista:Vec<i32>;
    let mut lista2:Vec<i32>;
    let mut comparaciones:i32=0;
    timeit_m(|| create_list(), "Crear la lista",crear);

    lista=create_list();
    lista2=create_list();
    timeit(||bubble_sort(&mut lista,&mut comparaciones, bal),"Ordenar la lista",ordenar);
    println!("Se hicieron {} comparaciones",comparaciones);
    *comp+=comparaciones;
    let mut comparaciones_op:i32=0;
    timeit(||bubble_sort_optimized(&mut lista2, &mut comparaciones_op,mome),"Ordenar la lista (optimizado)",ordenar_op);
    println!("Se hicieron {} comparaciones en el algo op",comparaciones_op);
    *comparaciones_op_rec+=comparaciones_op;
    for i in 0..100{
        print!("{} ",lista[i]);
    }
    println!();
}

fn bubble_sort(lista:&mut Vec<i32>,comparaciones:&mut i32,bal:&mut i32){
    let len = lista.len();
    for j in 0..len {
        let mut bandera=true;
        for i in 0..len-1 {
           if lista[i]>lista[i+1]{
           bandera=false;
           *comparaciones+=1;
           lista.swap(i,i+1);
           }
        } 
    if bandera{*bal+=j as i32;break;}
    } 
}

pub fn bubble_sort_optimized(arr: &mut [i32],comparaciones:&mut i32,mome:&mut i32) {
    let mut new_len: usize;
    let mut len = arr.len();
    let mut i=0;
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
            *mome+=i;
            break;
        }
        len = new_len;
        i+=1;
    }
}


fn create_list()->Vec<i32>{
    let mut rng=rand::thread_rng();
    (0..10_001).map(|_| rng.gen_range(0..10_000)).collect()
}

fn timeit<F: FnMut() -> T, T>(mut f: F, desc:&str,tiempo:&mut i32) -> T {
  let start = SystemTime::now();
  let result = f();
  let end = SystemTime::now();
  let duration = end.duration_since(start).unwrap();
  println!("{} {} milisegundos",desc, duration.as_millis());
  *tiempo += duration.as_millis() as i32;
  result
}

fn timeit_m<F: FnMut() -> T, T>(mut f: F, desc:&str,tiempo:&mut i32) -> T {
  let start = SystemTime::now();
  let result = f();
  let end = SystemTime::now();
  let duration = end.duration_since(start).unwrap();
  println!("{} {} microsegundos",desc, duration.as_micros());
  *tiempo+=duration.as_micros() as i32;
  result
}

fn main() {
    let mut crear=0;
    let mut ordenar=0;
    let mut ordenar_op=0;
    let mut comparaciones_op=0;
    let mut bal_op=0;
    let mut comp=0;
    let mut bal=0;
    for _ in 0..5{
        test(&mut crear,&mut ordenar,&mut comp,&mut bal,&mut ordenar_op,&mut comparaciones_op,&mut bal_op)
    }
    println!();
    println!("Se tardo {:.2} microsegundos en crear la lista",crear as f32 /5.0);
    println!("Se hicieron {:.2} comparaciones",comp as f32 /5.0);
    println!("Se tardo {:.2} milisegundos en ordenar la lista",ordenar as f32 /5.0);
    println!("La lista se ordeno en el momento {:.2} en promedio",bal as f32 /5.0);
    println!();
    println!("Se tardo {:.2} milisegundos en ordenar la lista con el algoritmo optimizado",ordenar_op as f32 /5.0);
    println!("Se hicieron {:.2} comparaciones en el agoritmo optimizado",comparaciones_op as f32 /5.0);
    println!("La lista se ordeno en el momento {:.2} en promedio",bal_op as f32 /5.0);
}

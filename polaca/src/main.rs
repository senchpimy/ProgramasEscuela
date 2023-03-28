struct EstrucutraPosfija{
    op_i:char,
    operacion:char,
    op_d:char
}

fn main() {
    let cadena = "x=(6+2)/(3-1)*(5/1)";
    let mut operandos:Vec<char> = vec![];
    let mut operadores:Vec<char> = vec![];
    let mut n_operadores=0;
    for i in cadena.chars(){
        match i{
            '='|'+'|'/'|'-'|'*'=>{n_operadores+=1;operadores.push(i)},
            '('|')'=>continue,
            _=>operandos.push(i)
        };
        
    }
    let mut posfija = String::from(format!("{}{}{}{}",operandos[0],operandos[1],operandos[2],operadores[1]));
    for i in 0..n_operadores-2{
        println!("{}",i);
        posfija=format!("{}{}",posfija,"papu");
    }
    posfija=format!("{}{}",posfija,operadores[0]);
    println!("{:?}",operandos);
    println!("{:?}",operadores);
    println!("{}",posfija);
}

#include <stdio.h>

//int main()
//{
//  int var = 5;
//  var=operaciones(var);
//  printf("%i",var);
//  return 0;
//}

int main(){
    int var;
    scanf("%d",&var);
    var = operaciones(var);
    printf("%d",var);
}


int operaciones(int valor){
    int resultado=valor+19;
    resultado=resultado*5;
    resultado=resultado/20;
    resultado=resultado+(34*2);
    return resultado;
}

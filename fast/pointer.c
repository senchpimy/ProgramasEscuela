#include <stdio.h>

int main(){
    int var;
    scanf("%d",&var);
    operaciones(&var);
    printf("%d\n",var);
}

void operaciones(int* valor){
        int var=*valor;
        var=var+19;
        var=var*5;
        var=var/20;
        var=var+(34*2);
        *valor= var;
}

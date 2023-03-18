#include <stdio.h>

int agregar_valor(int lista[], int valor,int size){
	int i;
	int nueva_lista[size+1];

	for (i=0;i<size;i++){
		if (valor<lista[i]){
			break;
		}
			nueva_lista[i]=lista[i];
	}
	nueva_lista[i]=valor;
	for (int j=size+1;j>i;j--){
			nueva_lista[j]=lista[j-1];
	}
	/*Imprimir Lista*/
	for(int i=0; i<size+1; i++) { printf("%i:", nueva_lista[i]); }
	printf("\n");
	/*Terminado de Imprimir Lista*/
	return 0;
}


int main(int argc, char *argv[])
{
	int lista_original[]={2,12,23,25,56,78,98,100};
	/*Imprimir Lista*/
	for(int i=0; i<8; i++) { printf("%i:", lista_original[i]); }
	printf("\n");
	/*Terminado de Imprimir Lista*/
	int valor_nuevo=40;
	size_t size = sizeof(lista_original) / sizeof(lista_original[0]);
	agregar_valor(lista_original,valor_nuevo,size);
	return 0;
}

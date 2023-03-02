#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int numero_de_elementos=10000;

void bubblesort(int lista[],int* comp,int* momen){
	for (int j=0; j<numero_de_elementos;j++){
		bool bandera = true;
		for (int i=0; i<numero_de_elementos;i++){
			if (lista[i]>lista[i+1]){
				*comp = *comp+1;
				int tmp;
				tmp = lista[i+1];
				lista[i+1]=lista[i];
				lista[i]=tmp;
				bandera=false;
			}
		}
		if (bandera){*momen=j;break;}
	}
}

int test(double* crear,double* ordenar, int* operaciones, int* momen)
{
	int lista[numero_de_elementos];
	int comparaciones=0;
	int pre_momen=0;
	srand(clock());
	clock_t start, end;

	start = clock();
	for (int i = 0;i<numero_de_elementos;i++)
		lista[i]=rand()%numero_de_elementos;
	end = clock()-start;

	double crear_lista = ((double)end)/CLOCKS_PER_SEC; // in seconds
	printf("Tomo %f segundos para crear la lista\n",crear_lista);
	*crear+=crear_lista;

	start = clock();
	bubblesort(lista,&comparaciones,&pre_momen);
	end = clock()-start;
	double ordenar_lista = ((double)end)/CLOCKS_PER_SEC; // in seconds
	printf("Tomo %f segundos en ordenar la lista\n",ordenar_lista);
	printf("La lista se ordeno en la iteracion %d\n",pre_momen);
	*ordenar+=ordenar_lista;
	*momen+=pre_momen;

	printf("Se hicieron %d comparaciones\n",comparaciones);
	*operaciones+=comparaciones;

	for (int i = 0; i < 100; i++)
            printf("%i ", lista[i]);


	return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
	double c=0;
	double o=0;
	int op=0;
	int ord=0;
	for (int i = 0 ; i<5;i++){
		test(&c, &o, &op, &ord);
		sleep(1);
	}
	double test=5;
	double op_fin=(double)op/(double)test;	
	double c_fin = (double)c/test;
	double o_fin = (double)o/test;
	double ord_fin = (double)ord/test;
	printf("\n Se hicieron %f comparaciones en total\n",op_fin);
	printf("\n El tiempo promedio fue de %f para crear la lista\n",c_fin);
	printf("\n El tiempo promedio fue de %f para ordenar la lista\n",o_fin);
	printf("\n Se hizo un promedio de %f comparaciones para ordenar la lista\n",ord_fin);
	return EXIT_SUCCESS;
}

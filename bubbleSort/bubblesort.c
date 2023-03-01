#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

	const int numero_de_elementos=10000;

void bubblesort(int lista[],int* comp){
	for (int j=0; j<numero_de_elementos;j++){
		bool bandera = true;
		for (int i=0; i<numero_de_elementos;i++){
			if (lista[i]>lista[i+1]){
				*comp = *comp+1;
				int tmp;
				tmp = lista[i+1];
				lista[i+1]=lista[i];
				lista[i]=tmp;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int lista[numero_de_elementos];
	int comparaciones=0;
	srand(12);
	clock_t start, end;

	start = clock();
	for (int i = 0;i<numero_de_elementos;i++)
		lista[i]=rand()%numero_de_elementos;
	end = clock()-start;

	double crear_lista = ((double)end)/CLOCKS_PER_SEC; // in seconds
	printf("Tomo %f segundos para crear la lista\n",crear_lista);

	start = clock();
	bubblesort(lista,&comparaciones);
	end = clock()-start;
	double ordenar_lista = ((double)end)/CLOCKS_PER_SEC; // in seconds
	printf("Tomo %f segundos en ordenar la lista\n",ordenar_lista);

	printf("Se hicieron %d comparaciones\n",comparaciones);

	for (int i = 0; i < 100; i++)
            printf("%i ", lista[i]);

	return EXIT_SUCCESS;
}


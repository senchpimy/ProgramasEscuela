#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int numero_de_elementos=10000;
	srand(12);
	int lista[numero_de_elementos];
	clock_t start, end;

	start = clock();
	for (int i = 0;i<numero_de_elementos;i++)
		lista[i]=random();

	end = clock()-start;
	double crear_lista = ((double)end)/CLOCKS_PER_SEC; // in seconds
	printf("Tomo %f segundos para crear la lista\n",crear_lista);

	start = clock();
	for (int j=0; j<numero_de_elementos;j++){
		for (int i=0; i<numero_de_elementos;i++){
			if (lista[i]>lista[i+1]){
				int tmp;
				tmp = lista[i+1];
				lista[i+1]=lista[i];
				lista[i]=tmp;
			}
		}
	}
	end = clock()-start;
	double ordenar_lista = ((double)end)/CLOCKS_PER_SEC; // in seconds
	printf("Tomo %f segundos en ordenar la lista\n",ordenar_lista);

	for (int i = 0; i < 100; i++)
            printf("%i ", lista[i]);

	return EXIT_SUCCESS;
}

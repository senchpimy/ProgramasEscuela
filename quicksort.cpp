#include<iostream>
#include<cstdlib>
#include <chrono>
using namespace std::chrono;
using namespace std;
const int elementos=10000;

void crear_lista(int *lista){
	for (int i=0; i<elementos; i++){
		lista[i]=rand()%5000;
	}
}

int dividir(int *array, int inicio, int fin,int* comparaciones, int* cambios)
{
  int izq;
  int der;
  int pibote;
  int temp;

  pibote = array[inicio];
  izq = inicio;
  der = fin;

  while (izq < der){
    while (array[der] > pibote){
	  der--;
    }

	while ((izq < der) && (array[izq] <= pibote)){
      izq++;
    }

	if(izq < der){
      temp= array[izq];
      array[izq] = array[der];
      array[der] = temp;
      *comparaciones=*comparaciones+1;
      *cambios=*cambios+1;
    }
  }

  temp = array[der];
  array[der] = array[inicio];
  array[inicio] = temp;
  *cambios=*cambios+1;

  return der;
}

void quicksort(int *array, int inicio, int fin,int* comparaciones,int* cambios)
{
  int pivote;
  if(inicio < fin)
  {
    pivote = dividir(array, inicio, fin ,comparaciones, cambios);
    quicksort( array, inicio, pivote - 1,comparaciones,cambios);
    quicksort( array, pivote + 1, fin,comparaciones, cambios );
  }
}

void main_pre(int *comparaciones_prom,int *cambios_prom, int *crear_lista_prom,int *ordenar_lista_prom)
{
	int lista[elementos];
	srand((unsigned) time(NULL));
	auto start = high_resolution_clock::now();
	crear_lista(lista);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	for (int i=0; i<100; i++) {
	cout<<lista[i]<<" ";
	}
	cout<<"\n";
	cout << duration.count() << " microsegundos para crear la lista \n";
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||\n";

	auto start2 = high_resolution_clock::now();
	int comparaciones=0;
	int cambios=0;
	quicksort(lista,0,elementos-1,&comparaciones,&cambios);
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout<<"Se hicieron " << comparaciones <<" comparaciones\n";
	cout<<"Se hicieron " << cambios <<" cambios\n";
	for (int i=0; i<100; i++) {
	cout<<lista[i]<<" ";
	}
	cout<<"\n";
	cout<<lista[elementos/2];
	cout<<"\n";
	cout << duration2.count() << " microsegundos para ordenar la lista\n";
	*cambios_prom=*cambios_prom+cambios;
	*comparaciones_prom=*comparaciones_prom+comparaciones;
	*crear_lista_prom=*crear_lista_prom+duration.count();
	*ordenar_lista_prom=*ordenar_lista_prom+duration2.count();
}

int main (int argc, char *argv[])
{
	int comparaciones_prom =0;
	int cambios_prom =0;
	auto crear_lista_prom=0;
	auto ordenar_lista_prom=0;
	for(int i=0; i<5;i++){
	main_pre(&comparaciones_prom,&cambios_prom,&crear_lista_prom,&ordenar_lista_prom);
	}
	cout << "\n\n\n\n\n\n";
	cout << "Promedio comparaciones: "<<  comparaciones_prom;
	cout << "\n";
	cout << "Promedio cambios: "<< cambios_prom/5;
	cout << "\n";
	cout << "Promedio crear_lista : "<<  crear_lista_prom;
	cout << "\n";
	cout << "Promedio ordenar: "<< ordenar_lista_prom/5;
	cout << "\n";

	return 0;
}

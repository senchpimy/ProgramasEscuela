#include<iostream>
#include<cstdlib>
#include <chrono>
using namespace std::chrono;
using namespace std;
const int elementos=10000;

void crear_lista(int *lista){
	for (int i=0; i<elementos; i++){
		//lista[i]=rand()%5000;
		lista[i]=rand()%50;
	}
}

int dividir(int *array, int inicio, int fin){
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
    }
  }

  temp = array[der];
  array[der] = array[inicio];
  array[inicio] = temp;

  return der;
}


void quicksort(int *array, int inicio, int fin){
  int pivote;
  if(inicio < fin)
  {
    pivote = dividir(array, inicio, fin );
    quicksort( array, inicio, pivote - 1 );
    quicksort( array, pivote + 1, fin );
  }
}

int main (int argc, char *argv[])
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
	quicksort(lista,0,elementos-1);
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout<<"Se hicieron " << comparaciones <<" comparaciones\n";
	cout<<"Se hicieron " << cambios <<" cambios\n";
	for (int i=0; i<100; i++) {
	cout<<lista[i]<<" ";
	}
	cout<<"\n";
	cout << duration2.count() << " microsegundos para ordenar la lista\n";
	return 0;
}

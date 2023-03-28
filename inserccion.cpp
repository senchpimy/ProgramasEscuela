#include<iostream>
#include<cstdlib>
#include <chrono>
using namespace std::chrono;
using namespace std;
const int elementos=10000;
int lista[elementos];

void crear_lista(){
	for (int i=0; i<elementos; i++){
		lista[i]=rand()%5000;
	}
}

void insercion(){
	for (int i = 0; i<elementos; i++) {
		int mayor=0;
		for (int j = i; j>0; j--) {
			if (lista[j]<lista[j-1]){
				int tmp = lista[j];
				int tmp2=lista[j-1];
				lista[j]=tmp2;
				lista[j-1]=tmp;
			}
		}
	}
}

int main (int argc, char *argv[])
{
	srand((unsigned) time(NULL));
	auto start = high_resolution_clock::now();
	crear_lista();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	for (int i=0; i<100; i++) {
	cout<<lista[i]<<" ";
	}
	cout<<"\n";
	cout << duration.count() << " microsegundos para crear la lista \n";

	auto start2 = high_resolution_clock::now();
	insercion();
	insercion();
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop - start);
	for (int i=0; i<100; i++) {
	cout<<lista[i]<<" ";
	}
	cout<<"\n";
	cout << duration.count() << " microsegundos para ordenar la lista";
	return 0;
}

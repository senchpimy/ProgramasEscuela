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

void insercion(int &comparaciones,int &cambios){
	for (int i = 0; i<elementos; i++) {
		int mayor=0;
		for (int j = i; j>0; j--) {
			comparaciones++;
			if (lista[j]<lista[j-1]){
				cambios++;
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
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||\n";

	auto start2 = high_resolution_clock::now();
	int comparaciones=0;
	int cambios=0;
	insercion(comparaciones,cambios);
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

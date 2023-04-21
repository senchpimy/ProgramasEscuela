#include <cstddef>
#include<iostream>
#include <string>
#include<cstdlib>
using namespace std;


class Nodo {
public:
    int val;
    Nodo* sig;
};

Nodo* penultimo;
Nodo* penultimo_pre;
Nodo* ultimo;
Nodo* primero_g;
Nodo* disponible;

void printList(Nodo* n){
    while (n != NULL) {
        cout << n->val << " ";
        n = n->sig;
    }
    cout<<"\n";
}

void eliminarVal(){
	if (penultimo != primero_g){
		penultimo=primero_g;
		penultimo_pre=primero_g->sig;
		while (penultimo_pre!=ultimo){
			penultimo = penultimo_pre;
			penultimo_pre=penultimo->sig;
		}
		ultimo->sig=disponible;
		disponible=ultimo;
		disponible->val=0;
		ultimo=penultimo;
		ultimo->sig=NULL;
	}else{
		primero_g->sig=disponible;
		primero_g->val=0;
		cout<<"Lista principal vacia\n";
	}
}

int main (int argc, char *argv[])
{
	Nodo* primero = NULL;
	Nodo* segundo = NULL;
	Nodo* tercero = NULL;
	Nodo* cuarto = NULL;
	/// Disponibles
	Nodo* quinto = NULL;
	Nodo* sexto = NULL;
	Nodo* septimo = NULL;
	Nodo* octavo = NULL;
	Nodo* noveno = NULL;
	Nodo* decimo = NULL;

	primero = new Nodo();
	segundo = new Nodo();
	tercero = new Nodo();
	cuarto  = new Nodo();
	/// Disponibles
	quinto  = new Nodo();
	sexto   = new Nodo();
	septimo = new Nodo();
	octavo  = new Nodo();
	noveno  = new Nodo();
	decimo  = new Nodo();

	primero->val = 1;
	primero->sig = segundo;
	segundo->val = 2;
	segundo->sig = tercero;
	tercero->val = 3;
	/// ultimo
	primero_g=primero;
	ultimo=tercero;
	disponible=cuarto;
	/// Disponibles
	cuarto->sig  = quinto;
	quinto->sig  = sexto;
	sexto->sig   = septimo;
	septimo->sig = octavo;
	octavo->sig  = noveno;
	noveno->sig  = decimo;
	
	std::string line;
	while (true){
		line ="";
		cout<< "Quiere agregar un valor? [y/n]";
		std::getline(std::cin, line);
		if (line == "y"){
			eliminarVal();
		}
		cout<< "Lista principal:";
		printList(primero);
		cout<< "Lista disponible:";
		printList(disponible);
	}
	return 0;
}



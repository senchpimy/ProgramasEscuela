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

Nodo* ultimo;
Nodo* disponible;

void printList(Nodo* n){
    while (n != NULL) {
        cout << n->val << " ";
        n = n->sig;
    }
    cout<<"\n";
}

void agrVal(){
	if (disponible->sig != NULL){
		ultimo->sig=disponible;
		disponible->val=rand()%50;
		ultimo=disponible;
		disponible=disponible->sig;
		ultimo->sig=NULL;
	}else{
		cout<<" Lista disponible llena\n";
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
			agrVal();
		}
		cout<< "Lista principal:";
		printList(primero);
		cout<< "Lista disponible:";
		printList(disponible);
	}
	return 0;
}



#include<iostream>
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

void addVal(){
	if (disponible->val == 0){
		ultimo->sig=disponible;
		disponible->val=5555;
		ultimo=disponible;
		disponible=disponible->sig;
		ultimo->sig=NULL;
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

	printList(primero);
	printList(segundo);
	printList(quinto);
	addVal();
	printList(primero);
	printList(segundo);
	printList(quinto);
	addVal();
	printList(primero);
	printList(segundo);
	printList(quinto);
	return 0;
}



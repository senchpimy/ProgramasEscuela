#include <stdio.h>
#include <string.h>

int pila[15]={9,2,3,4,0, 
	      6,56,0,0,0,
	      78,12,0,0,0};
int tamaño_total = 15;
int comienzo_a=0;
int final_a=3;

int comienzo_b=5;
int final_b=6;

int comienzo_c=10;
int final_c=11;

void recorrerDerecha(int inicio, int final){
	for (int i=final+1; i >inicio; i--){
		pila[i]=pila[i-1];
	}
}

void recorrerIzquierda(int inicio , int final){
	int tmp = pila[final];
	for (int i=inicio; i < final; i++){
		pila[i-1]=pila[i];
	}
	pila[final-1]=tmp;
}

void printPila(int acc, char pila_char){
	char estado[15];
	int indice_ed=tamaño_total+1;
	if (pila_char=='a') {
		indice_ed=final_a;
	}else if (pila_char=='b') {
		indice_ed=final_b;
	}else if (pila_char=='c'){ 
		indice_ed=final_c;
	}

	if (acc==0){
		strcpy(estado,"%d:");
	}else if (acc==1){//agreagar
		strcpy(estado,"\033[92;5m%d:\033[0m");
	}else if (acc==2){//eliminar
		strcpy(estado,"\033[91m%d:\033[0m");
	}

	for (int i=0;i<tamaño_total;i++){
		if (i == comienzo_a ||i == comienzo_b ||i == comienzo_c ||i == final_a +1 ||i == final_b +1 ||i == final_c+1){
			printf(" █ ");
		}
		if (i==indice_ed){
			printf(estado,pila[i]);
		}else if (i>final_a && i < comienzo_b || i>final_b && i < comienzo_c || i > final_c ) {
			printf("\033[94m%d:\033[0m",pila[i]);
		
		}else{
			printf("%d:",pila[i]);
		}
	}
	printf("\n");
}

void agregar(int valor,char pila_char){
	if (pila_char=='a') {
		if (final_a+1<comienzo_b){
			final_a++;
			pila[final_a]=valor;
			printPila(1,pila_char);
			return;
		}else{
			if (final_b+1<comienzo_c){
				recorrerDerecha(comienzo_b, final_b);
				final_a++;
				pila[final_a]=valor;
				final_b++;
				comienzo_b++;
			}else if (final_c+1 < tamaño_total){
				recorrerDerecha(comienzo_c, final_c);
				recorrerDerecha(comienzo_b, final_b);
				final_b++;
				pila[final_a]=valor;
				final_b++;
				comienzo_b++;
				final_c++;
				comienzo_c++;
			}
			printPila(1,pila_char);
		}
	}else if (pila_char=='b') {
		if (final_b+1<comienzo_c){
			final_b++;
			pila[final_b]=valor;
			printPila(1,pila_char);
			return;
		}else{
			if (final_c+1<tamaño_total){
				recorrerDerecha(comienzo_c, final_c);
				final_b++;
				pila[final_b]=valor;
				final_c++;
				comienzo_c++;
			}else if (final_c+1 < tamaño_total){
				recorrerDerecha(comienzo_c, final_c);
				final_b++;
				pila[final_b]=valor;
				final_c++;
				comienzo_c++;
			}else if (comienzo_b-1 > final_a){
				recorrerIzquierda(comienzo_b, final_b);
				comienzo_b--;
				pila[final_b]=valor;
			}
		}
		printPila(1,pila_char);
	}else{ // pila_char == 'c'
		if (final_c+1<tamaño_total){
			final_c++;
			pila[final_c]=valor;
			printPila(1,pila_char);
			return;
		}else if (comienzo_c-1>final_b) {
			recorrerIzquierda(comienzo_c, final_c);
			comienzo_c--;
			pila[final_c]=valor;
		
		}else if (comienzo_b-1>final_a) {
			recorrerIzquierda(comienzo_b, final_b);
			recorrerIzquierda(comienzo_c, final_c);
			//final_c--;
			pila[final_c]=valor;
			final_b--;
			comienzo_b--;
			comienzo_c--;
		}
		printPila(1,pila_char);
	}
}

void eliminar(char pila_char){
	if (pila_char=='a') {
			pila[final_a]=0;
			if (final_a!=0){
				final_a--;
			}
	}else if (pila_char =='b'){
			pila[final_b]=0;
			if (comienzo_b < final_b){
				final_b--;
			}
	} else if (pila_char=='c'){
			pila[final_c]=0;
			if (comienzo_c < final_c){
				final_c--;
			}
	}
	printPila(2,pila_char);
}

int main(int argc, char *argv[])
{	
	int c;
	int try;
	int valor;
	char basura[1];
	char pila_char;
	printPila(0,pila_char);
		printf("Escriba A para añadir, E para eliminar o e para estado: ");
	while (1) {
		c = getchar();
		if (c=='E'){
			printf("A que pila? (a,b,c): ");
			scanf(" %c",&pila_char);
			eliminar(pila_char);
		}
		if (c=='A'){
			if (final_a+1 == comienzo_b && final_b == comienzo_c && final_c == tamaño_total -1){
				printf("Pila LLena\n");
				continue;
			}
			printf("A que pila? (a,b,c): ");
			scanf(" %c",&pila_char);
			agregar( rand()%50, pila_char);
		}
		if (c=='e'){
			printPila(0,pila_char);
		}
		getchar();
		printf("Escriba A para añadir, E para eliminar o e para estado: ");
	}
    return 0;
}




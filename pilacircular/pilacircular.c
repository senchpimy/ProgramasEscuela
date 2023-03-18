#include <stdio.h>

//int pila[10];
int pila[10]={9,2,3,4,5,6,0,0,0,0};
int comienzo=0;
int final=5;

void printPila(int val,int acc){
	if (val==0&&acc==0){
		for (int i=0;i<10;i++){
			printf("%d:",pila[i]);
		}
		printf("\n");
	}else if (acc==1){
		for (int i=0;i<10;i++){
			if (i==final){
				printf("\033[92;5m%d:\033[0m",pila[i]);
			}else{
				printf("%d:",pila[i]);
			}
		}
		printf("\n");
	}else if (acc==2){
		for (int i=0;i<10;i++){
			if (i==comienzo-1){
				printf("\033[91m%d:\033[0m",pila[i]);
			}else{
				printf("%d:",pila[i]);
			}
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{	
	int c;
	int try;
	int valor;
	char basura[1];
	printPila(0,0);
	while (1) {
		do {
			printf("Escriba A para añadir, E para eliminar o e para estad o e para estado: ");
			c = getchar();
			try=getchar();
			if (try !='\n'){
				scanf("%s",basura);
			}
		} while (try != '\n');
		if (c=='E'){
			eliminar();
		}
		if (c=='A'){
			agregar(rand()%50);
		}
		if (c=='e'){
			printPila(0, 0);
		}

	}
    return 0;
}

void agregar(int valor){
	int tmp = final;
	final++;
	if (final == 10){
		final=0;
	}
	if (final==comienzo){
		printf("pila LLena\n");
		final=tmp;
		return;
	}
	pila[final]=valor;
	printPila(valor,1);
}

void eliminar(){
	pila[comienzo]=0;
	int tmp = comienzo;
	comienzo++;
	printPila(0,2);
	if (comienzo==10){
		comienzo=0;
	}
	if (comienzo==final+1){
		comienzo=tmp;
	}
}

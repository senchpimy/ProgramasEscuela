#include <stdio.h>

//int pila[10];
int pila[10]={9,2,3,4,5,6,0,0,0,0};
int comienzo=0;
int final=6;

void printPila(int val,int acc){
	if (val==0&&acc==0){
		for (int i=0;i<10;i++){
			printf("%d:",pila[i]);
		}
		printf("\n");
	}else if (acc==1){
		for (int i=0;i<10;i++){
			if (i==final-1){
				printf("\033[92;5m%d:\033[0m",pila[i]);
			}else{
				printf("%d:",pila[i]);
			}
		}
		printf("\n");
	}else if (acc==2){
		for (int i=0;i<10;i++){
			if (i==comienzo-1){
				printf("\033[93m%d:\033[0m",pila[i]);
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
			printf("Escriba A para añadir o E para eliminar: ");
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
	}
    return 0;
}

void agregar(int valor){
	if (final==comienzo){
		printf("pila LLena\n");
		printf("Comienzo : %d Final: %d\n",comienzo,final);
		return;
	}
	if (final == 10 && comienzo == 0){
		printf("pila LLena\n");
		return;
	}
	if (final == 10){
		final=0;
	}
	pila[final]=valor;
	final++;
	printPila(valor,1);
}

void eliminar(){
	pila[comienzo]=0;
	comienzo++;
	if (comienzo==10){
		comienzo=0;
	}
	printPila(0,2);
}

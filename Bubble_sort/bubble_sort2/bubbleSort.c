#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 6

int main() {

	//VARIAVEIS
	int x[TAM], aux;

	srand(time(NULL)); //GERADOR DE NUMERO PSEUDO-ALEATORIO SIMPLES SEMENTE

	//PREENCHE O VETOR
	for (int i = 0; i < TAM; i++) {
		x[i] = (rand() % 15) + (-5);  //GERADOR DE NUMERO PSEUDO-ALEATORIO
	}

	printf("Ordem atual dos elementos do vetor:\n");
	for (int i = 0; i < TAM; i++) {
		printf("%4d", x[i]);
	}

	//BUBBLE SORT CRESCENTE
	//LACO EXTERNO DO TAMANHO DO VETOR
	for (int i = 1; i < TAM; i++) {
		//LACO INTERNO 1 ATE PENULTIMA POSICAO
		for (int j = 0; j < TAM - 1; j++) {
			//TROCA (SWAP)
			if (x[j] > x[j + 1]) {
				aux = x[j];
				x[j] = x[j + 1];
				x[j + 1] = aux;
			}
		}
	}
	
	//IMPRIME O VETOR ORDERNADO DE FORMA CRESCENTE
	printf("\n\nElementos do vetor em ordem crescente:\n");
	for (int i = 0; i < TAM; i++) {
		printf("%4d", x[i]);
	}

	printf("\n\n");
	system("pause");
	return 0;
}
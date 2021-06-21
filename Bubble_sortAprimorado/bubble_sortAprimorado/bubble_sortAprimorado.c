#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main() {

	//VARIAVEIS
	int x[TAM], aux, i;
	_Bool troca;

	srand(time(NULL)); //GERADOR DE NUMERO PSEUDO-ALEATORIO SIMPLES SEMENTE

	//PREENCHE O VETOR
	for (int i = 0; i < TAM; i++) {
		x[i] = (rand() % 15) + (-6);  //GERADOR DE NUMERO PSEUDO-ALEATORIO
	}

	//IMPRIME O VETOR ATUAL
	printf("Ordem atual dos elementos do vetor:\n");
	for (int i = 0; i < TAM; i++) {
		printf("%4d", x[i]);
	}

	//BUBBLE SORT CRESCENTE
	i = 1, troca = 1;
	//LACO EXTERNO DO TAMANHO DO VETOR
	while ((i <= TAM) && (troca == 1))
	{
		troca = 0;
		//LACO INTERNO 1 ATE PENULTIMA POSICAO
		for (int j = 0; j < TAM - 2; j++) {
			//TROCA (SWAP)
			if (x[j] > x[j + 1]) {
				troca = 1;
				aux = x[j];
				x[j] = x[j + 1];
				x[j + 1] = aux;
			}
		}
		i++;
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
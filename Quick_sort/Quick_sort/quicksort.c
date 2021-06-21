#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void quicksort(int X[], int inicio, int fim);
int particao(int X[], int inicio, int fim);
void troca(int X[], int i, int j);

int main() 
{
	int X[TAM];
	srand(time(NULL));//GERADOR DE NUMERO PSEUDO-ALEATORIO SIMPLES SEMENTE

	//PREENCHE O VETOR
	for (int i = 0; i <= TAM - 1; i++)
	{
		/*printf("Digite um valor para o indice %d do vetor: ", i);
		scanf_s("%d", &X[i]);*/
		X[i] = (rand() % 100) + (-45); //GERADOR DE NUMERO PSEUDO-ALEATORIO
	}

	// IMPRIME O VETOR
	printf("\n\nOrdem atual dos elementos do vetor:\n");
	for (int i = 0; i < TAM; i++)
		printf("%4d", X[i]);

	// QUICK SORT CRESCENTE
	quicksort(X, 0, TAM - 1); // CHAMA A FUNCAO DE ORDENACAO

	// IMPRIME O VETOR ORDENADO DE FORMA CRESCENTE
	printf("\n\nElementos do vetor em ordem crescente:\n");
	for (int i = 0; i < TAM; i++)
		printf("%4d", X[i]);

	printf("\n\n");
	system("pause");
	return 0;
}

void quicksort(int X[], int inicio, int fim)
{
	int div;

	if (inicio < fim)
	{
		div = particao(X, inicio, fim); // RETORNA O PONTO DE PARADA
		quicksort(X, inicio, div); // CONTINUA DIVIDINDO A PARTIR 1º PARTE
		quicksort(X, div + 1, fim); // CONTINUA DIVIDINDO A PARTIR 2º PARTE
	}
}

int particao(int X[], int inicio, int fim)
{
	int posicao_pivo, i, j;
	posicao_pivo = X[(inicio + fim) / 2]; // ENCONTRO O PIVO
	i = inicio - 1;
	j = fim + 1;

	while (i < j)
	{
		do // PROCURA POR VALOR INCOERENTE A DIREITA DO PIVO
		{
			j--;
		} while (X[j] > posicao_pivo); // DE FORMA CRECENTE

		do // PROCURA POR VALOR INCOERENTE A ESQUERDA DO PIVO
		{
			i++;
		} while (X[i] < posicao_pivo); // DE FORMA CRECENTE

		// TROCA UM VALOR INCOERENTE A ESQUERDA
		// COM UM VALOR A DIREITA DO PIVO
		if (i < j)
			troca(X, i, j);
	}
	// RETORNA ONDE O LADO DIREITO PAROU
	// ESTE VALOR SERA USADO COMO NOVO MEIO
	return j;
}


void troca(int X[], int i, int j)
{
	int aux; // TROCA (SWAP) COM VARIAVEL AUXILIAR
	aux = X[i];
	X[i] = X[j];
	X[j] = aux;
}

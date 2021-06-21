#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOVETOR 10

void quickSort(int vet[], int inicio, int fim);
int particao(int vet[], int inicio, int fim);
void troca(int vet[], int i, int j);

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	srand(time(NULL)); // GERA A SEMENTE ALEATORIA

	// INSERCAO DOS DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 10; // GERA OS VALORES ALETORIOS


	printf("VETOR NAO ORDERNADO\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%4d", vet[i]);

	quickSort(vet, 0, TAMANHOVETOR - 1);

	printf("\n\nVETOR ORDERNADO DE FORMA CRESCENTE\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%4d", vet[i]);

	printf("\n\n");
	system("pause");
	return 0;
}

void quickSort(int vet[], int inicio, int fim)
{
	int div = 0;

	if (inicio < fim)
	{
		div = particao(vet, inicio, fim);
		quickSort(vet, inicio, div); // ESQUERDO
		quickSort(vet, div + 1, fim); // DIREITO
	}
}

int particao(int vet[], int inicio, int fim)
{
	int pivo, pivo_pos, i, j;
	pivo_pos = (inicio + fim) / 2;
	pivo = vet[pivo_pos];

	i = inicio - 1;
	j = fim + 1;

	while (i < j)
	{
		do // TESTA O LADO DIREITO
		{
			j--;
		} while (vet[j] > pivo); // DE FORMA CRECENTE

		do // TESTA O LADO ESQUERDO
		{
			i++;
		} while (vet[i] < pivo); // DE FORMA CRECENTE

		if (i < j)
			troca(vet, i, j);	
	}

	return j;
}

void troca(int vet[], int i, int j)
{
	int aux; // TROCA (SWAP) COM VARIAVEL AUXILIAR
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}
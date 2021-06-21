#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOVETOR 10

void bubbleSort_Crescente(int vet[]);
void bubbleSort_Decrescente(int vet[]);

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	srand(time(NULL)); // GERA A SEMENTE ALEATORIA

	// INSERCAO DOS DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 100; // GERA OS VALORES ALETORIOS


	printf("VETOR NAO ORDERNADO\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%4d", vet[i]);

	bubbleSort_Crescente(vet);
	
	printf("\n\nVETOR ORDERNADO DE FORMA CRESCENTE\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%4d", vet[i]);

	bubbleSort_Decrescente(vet);

	printf("\n\nVETOR ORDERNADO DE FORMA DECRESCENTE\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%4d", vet[i]);


	printf("\n\n");
	system("pause");
	return 0;
}

void bubbleSort_Crescente(int vet[])
{
	int aux;

	for (int i = 1; i < TAMANHOVETOR; i++)
	{
		for (int j = 0; j < TAMANHOVETOR - 1; j++)
		{
			if (vet[j] > vet[j + 1]) // CRESCENTE
			{
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}
	}
}

void bubbleSort_Decrescente(int vet[])
{
	int aux;

	for (int i = 1; i < TAMANHOVETOR; i++)
	{
		for (int j = 0; j < TAMANHOVETOR - 1; j++)
		{
			if (vet[j] < vet[j + 1]) // DECRESCENTE
			{
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}
	}
}
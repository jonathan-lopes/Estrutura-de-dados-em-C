#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void merge(int X[], int inicio, int fim);
void intercala(int X[], int inicio, int fim, int meio);

int main()
{
	int X[TAM];
	srand(time(NULL));//GERADOR DE NUMERO PSEUDO-ALEATORIO SIMPLES SEMENTE

	// CARREGANDO OS NUMEROS NO VETOR
	for (int i = 0; i <= TAM - 1; i++)
	{
		/*printf("Digite um valor para o indice %d do vetor: ", i);
		scanf_s("%d", &X[i]);*/
		X[i] = (rand() % 100) + (-45); //GERADOR DE NUMERO PSEUDO-ALEATORIO
	}

	printf("Ordem atual dos elementos do vetor:\n");
	for (int i = 0; i < TAM; i++)
		printf("%4d", X[i]);

	// MERGE SORT CRESENTE
	merge(X, 0, TAM - 1);

	// MOSTRANDO O VETOR ORDERNADO DE FORMA CRESENTE
	printf("\n\nElementos do vetor em ordem crescente:\n");
	for (int i = 0; i < TAM; i++)
	{
		printf("%4d", X[i]);
	}

	printf("\n\n");
	system("pause");
	return 0;
}

void merge(int X[], int inicio, int fim)
{
	int meio;

	if (inicio < fim)
	{
		meio = (inicio + fim) / 2; // DIVIDE AO MEIO
		merge(X, inicio, meio); // CONTINUA DIVIDINDO APARTIR DA 1º METADE OU SEJA O LADO ESQUERDO
		merge(X, meio + 1, fim); // CONTINUA DIVIDINDO APARTIR DA 2º METADE OU SEJA O LADO DIREITO
		intercala(X, inicio, fim, meio); // AGREGA DE VOLTA 2 VETORES ORDERNADOS
	}
}

void intercala(int X[], int inicio, int fim, int meio)
{
	int poslivre, inicio_vetor1, inicio_vetor2, aux[TAM] = { 0 };
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1;
	poslivre = inicio;

	while (inicio_vetor1 <= meio && inicio_vetor2 <= fim)
	{
		if (X[inicio_vetor1] <= X[inicio_vetor2])
		{
			aux[poslivre] = X[inicio_vetor1];
			inicio_vetor1++;
		}
		else
		{
			aux[poslivre] = X[inicio_vetor2];
			inicio_vetor2++;
		}
		poslivre++;
	}

	// SE AINDA EXISTIR NUMEROS NO PRIMEIRO VETOR
	// QUE NAO FORAM INTERCALADOS
	for (int i = inicio_vetor1; i <= meio; i++)
	{
		aux[poslivre] = X[i];
		poslivre++;
	}

	// SE AINDA EXISTIR NUMEROS NO SEGUNDO VETOR
	// QUE NAO FORAM INTERCALADOS
	for (int i = inicio_vetor2; i <= fim; i++)
	{
		aux[poslivre] = X[i];
		poslivre++;
	}

	// RETORNA OS VALORES DO VETOR AUX PARA O VETOR X
	for (int i = inicio; i <= fim; i++)
		X[i] = aux[i];
}
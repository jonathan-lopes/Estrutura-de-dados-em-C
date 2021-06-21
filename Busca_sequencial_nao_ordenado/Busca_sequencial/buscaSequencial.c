#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 6

int main()
{
	int vet[TAM], buscado, achou = 0, i = 0;
	srand(time(NULL));

	//PREENCHE O VETOR
	for (int i = 0; i < TAM; i++)
	{
		vet[i] = rand() % 11;
	}

	// LE O VALOR BUSCADO
	printf("Digite o valor buscado: ");
	scanf_s("%d", &buscado);

	// BUSCA SEQUENCIAL
	while ((i <= TAM) && (achou == 0))
	{
		if (vet[i] == buscado)
			achou = 1;
		else
			i++;
	}

	if (achou == 0) {
		printf("\n\nValor nao encontrado\n\n");
		for (int i = 0; i < TAM; i++)
		{
			printf("%4d", vet[i]);
		}
		printf("\n\n");
	}
		
	else
		printf("\n\nValor encontrado na posicao : %d\n\n", i);

	system("pause");
	return 0;
}
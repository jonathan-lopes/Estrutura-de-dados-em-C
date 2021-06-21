#include <stdio.h>
#include <stdlib.h>

#define TAMANHOVETOR 10

int buscaSequencial(int vet[], int buscado);

int main()
{
	int vet[TAMANHOVETOR] = { 0 }, buscado, achou;
	srand(time(NULL)); // GERA A SEMENTE ALEATORIA

	// INSERCAO DOS DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 1000; // GERA OS VALORES ALETORIOS

	printf("VETOR NAO ORDERNADO\n");
	for (int i = 0; i < TAMANHOVETOR; i++)
		printf("%4d", vet[i]);

	printf("\n\nSelecione um valor buscado: ");
	scanf_s("%d", &buscado);

	achou = buscaSequencial(vet, buscado);

	if (achou == -1)
		printf("\nValor nao encontrado");
	else
		printf("\nValor encontrado na posicao %d.\n", achou);

	printf("\n\n");
	system("pause");
	return 0;
}

int buscaSequencial(int vet[], int buscado)
{
	int achou = 0, i = 0;

	while ((i <= TAMANHOVETOR) && (achou == 0))
	{
		if (vet[i] == buscado)
			achou = 1;
		else
			i++;
	}

	if (achou == 0)
		return -1;
	else
		return i;
}
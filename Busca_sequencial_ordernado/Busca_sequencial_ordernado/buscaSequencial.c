#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
	int buscado, i = 0, achou = 0, X[TAM] = { 1,2,3,4,5 };

	// LE O VALOR BUSCADO
	printf("Digite o valor buscado: ");
	scanf_s("%d", &buscado);

	// BUSCA SEQUENCIAL
	while ((i <= TAM) && (achou == 0) && (buscado >= X[i]))
	{
		if (X[i] == buscado)
			achou = 1;
		else
			i++;
	}

	if (achou == 0) 
		printf("\n\nValor nao encontrado\n\n");
	else
		printf("\n\nValor encontrado na posicao : %d\n\n", i);

	system("pause");
	return 0;
}
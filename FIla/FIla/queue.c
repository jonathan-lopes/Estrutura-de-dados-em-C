#include <stdio.h>
#include <stdlib.h>

// Cria uma fila usando lista
typedef struct fila
{
	int dado;
	struct fila* prox;
}FILA;
FILA* head;

void queue(int num);
void dequeueing();

int main()
{
	int op = 0, num;

	while (1)
	{
		printf("======= Menu =======");
		printf("\n0 - Inseri na fila");
		printf("\n1 - Remove da fila");
		printf("\n2 - Sair");
		printf("\nResposta: ");
		scanf_s("%d", &op);

		switch (op)
		{
		case 0:
			printf("\n\nDigite o numero para inserir na fila: ");
			scanf_s("%d", &num);
			queue(num);
			break;

		case 1:
			dequeueing();
			break;

		case 2:
			exit(1);
			break;

		default:
			printf("\nEntrada Invalida\n");
			system("pause>nul");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

void queue(int num)
{
	FILA* no = (FILA*)malloc(sizeof(FILA));
	if (no == NULL) return 0;
	// Insere o valor no novo elemento que sera inserido na fila
	no->dado = num;

	// Verifica se existe algo na fila
	if (head == NULL)
	{
		// Se a fila esta vazia, o novo elemento sera a fila
		head = no;
	}
	else
	{
		// Se a fila ja tem algo, novo elemento entra no final
		FILA* noVarredura = head;

		// Varre um elemento por vez procurando o ponterio nulo
		while (noVarredura->prox != NULL)
			noVarredura = noVarredura->prox;

		// Apos encontrar o ponteiro nulo
		// Faz o ultimo n� da fila apontar para o novo n�
		noVarredura->prox = no;
	}
	// Novo n� agora tera o ponterio nulo (final da fila)
	no->prox = NULL;
}

void dequeueing()
{
	FILA* noRemove;

	// Verifica se existe algo na fila
	if (head != NULL)
	{
		// Existe algo para remove entao
		// Salava temporariamente o head atual
		noRemove = head;

		// Incrementa o head (passa para o proximo n�)
		head = head->prox;

		//Limpa da memoria o head antigo
		free(noRemove);
	}
}
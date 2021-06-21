#include <stdio.h>
#include <stdlib.h>

// Definido o registro que representara cada elemento
//cada elemento da pilha
typedef struct pilha
{
	int num;
	struct pilha* prox;
}PILHA;

// A pilha esta vazia, logo, o ponteiro
// topo tem o valor NULL
// as operacaoes de insercao e remocao
// acontecem no topo
PILHA* topo = NULL;

void push();
void printStack();
void removeStack();
void emptyStack();

int main()
{
	int op = 0;

	// apresentando o menu de opcoes
	do
	{
		printf("\n==== Menu de Opcoes ====\n");
		printf("\n1 - Inserir na pilha");
		printf("\n2 - Consultar toda a pilha");
		printf("\n3 - Remove da pilha");
		printf("\n4 - Esvaziar a pilha");
		printf("\n5 - Sair");
		printf("\nDigite sua opcao: ");
		scanf_s("%d", &op);

		switch (op)
		{

		case 1:
			push();
			break;

		case 2:
			printStack();
			break;

		case 3:
			removeStack();
			break;

		case 4:
			emptyStack();
			break;

		case 5:
			exit(1);
			break;

		default:
			printf("\nEntrada Invalida!\n");
			system("pause>nul");
			system("cls");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}

void push()
{
	int num; 

	printf("\nDigite o numero a ser inserido na pilha: ");
	scanf_s("%d", &num);

	PILHA* no = (PILHA*)malloc(sizeof(PILHA));
	if (no == NULL) return 0;

	no->num = num;
	no->prox = topo;
	topo = no;
	printf("\nNumero Inserido na pilha!\n\n");
	system("pause>nul");
	system("cls");
}

void printStack()
{
	if (topo == NULL)
	{
		// A pilha esta vazia
		printf("\nPilha vazia!\n\n");
	}
	else
	{
		// A pilha contem elementos e
		// estes serao mostrados
		// do ultimo inserido ao primeiro
		printf("\n==== Consultando toda a pilha ====\n");

		// O ponterio aux e um ponteiro auxiliar
		PILHA* aux = topo;

		while (aux != NULL)
		{
			printf("%2d\n", aux->num);
			aux = aux->prox;
		}
		printf("\n=============== Fim ==============\n");
	}
	system("pause>nul");
	system("cls");
}

void removeStack()
{
	if (topo == NULL) 
	{
		// A pilha esta vazia
		printf("\nPilha Vazia!\n\n");
	}
	else
	{
		// A pilha contem elementos
		// e o ultimo elemento inserido
		// sera removido

		// O ponterio aux e um ponteiro auxiliar
		PILHA* aux = topo;
		printf("\nNumero %d removido\n\n", topo->num);
		topo = topo->prox;
		free(aux);
	}
	system("pause>nul");
	system("cls");
}

void emptyStack()
{
	if (topo == NULL)
	{
		// A pilha esta vazia
		printf("\nPilha Vazia!\n\n");
	}
	else
	{
		// A pilha sera esvaziada
		// O ponterio aux e um ponteiro auxiliar
		PILHA* aux = topo;

		while (aux != NULL)
		{
			topo = topo->prox;
			free(aux);
			aux = topo;
		}
		printf("\nPilha esvaziada\n\n");
	}
	system("pause>nul");
	system("cls");
}
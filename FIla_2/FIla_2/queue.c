#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
	int num;
	struct fila* prox;
}Fila;

// A fila esta vazia, logo,
// o ponterio inicio tem o valor null
// a operaracao de remocao acontece no INICIO
// e a operacao de insercao acontece no FIM

Fila* inicio = NULL;
Fila* fim = NULL;

void inseri_fila();
void cosultar_fila();
void remove_fila();
void esvaziar_fila();

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
			inseri_fila();
			break;

		case 2:
			cosultar_fila();
			break;

		case 3:
			remove_fila();
			break;

		case 4:
			esvaziar_fila();
			break;

		case 5:
			exit(1);
			break;

		default:
			printf("\nOpcao Invalida!\n");
			system("pause>nul");
			system("cls");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}

void inseri_fila()
{
	Fila* no = (Fila*)malloc(sizeof(Fila));
	if (no == NULL) return 0;

	printf("\n\nDigite o numero a ser inserido na fila: ");
	scanf_s("%d", &no->num);

	no->prox = NULL;

	if (inicio == NULL)
	{
		// A fila esta vazia e o numero inserido
		// sera o primeiro e o ultimo
		inicio = no;
		fim = inicio;
	}
	else
	{
		fim->prox = no;
		fim = no;
		
	}
	printf("\nNumero Inserido na pilha!\n\n");
	system("pause>nul");
	system("cls");
}

void cosultar_fila()
{
	if (inicio == NULL)
	{
		// A fila esta vazia
		printf("\nPilha vazia!\n\n");
	}
	else
	{
		// A fila contem elementos e
		// estes serao mostrados
		// do primeiro inserido ao ultimo
		printf("\n==== Consultando toda a fila ====\n");

		// O ponterio aux e um ponteiro auxiliar
		Fila* aux = inicio;

		while (aux != NULL)
		{
			printf("%4d", aux->num);
			aux = aux->prox;
		}
		printf("\n=============== Fim ==============\n");
	}
	system("pause>nul");
	system("cls");
}

void remove_fila()
{
	if (inicio == NULL)
	{
		// a fila esta vazia
		printf("\nFila vazia!!\n\n");
	}
	else
	{
		// A fila comtem elementos
		// e o primeiro elemento inserido
		// sera removido

		// O ponterio aux e um ponteiro auxiliar
		Fila* aux = inicio;

		printf("Numero %d removido", inicio->num);
		inicio = inicio->prox;
		free(aux);
	}
}

void esvaziar_fila()
{
	if (inicio == NULL)
	{
		// A fila esta vazia
		printf("\nFila Vazia!!\n\n");
	}
	else
	{
		// A fila sera esvazia
		Fila* aux = inicio;
		while (aux->prox != NULL)
		{
			inicio = inicio->prox;
			free(aux);
			aux = inicio;
		}
		printf("\nPilha esvaziada\n\n");
	}
	system("pause>nul");
	system("cls");
}
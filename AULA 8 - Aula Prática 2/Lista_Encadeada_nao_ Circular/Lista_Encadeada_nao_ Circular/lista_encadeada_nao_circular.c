#include <stdio.h>
#include <stdlib.h>

int menu();
void buffer();
void inserirInicio(int num);
void listar();
void inserirFim(int num);
void inserirMeio(int num, int posicao);

typedef struct ElemnetoDaLista_Simples
{
	int dado;
	struct ElemnetoDaLista_Simples* prox;
}Lista;

Lista* Head;

int main()
{
	int op, num, posicao;
	while (1)
	{
		op = menu();
		switch (op)
		{
		case 1: // INSERIR NO INICIO DA LISTA
			printf("Digite um numero desejado: ");
			scanf_s("%d", &num);

			inserirInicio(num);
			break;

		case 2: // INSERIR NO FIM DA LISTA
			printf("Digite um numero desejado: ");
			scanf_s("%d", &num);

			inserirFim(num);
			break;

		case 3: // INSERIR NO MEIO DA LISTA
			printf("Digite um numero desejado: ");
			scanf_s("%d", &num);
			buffer();

			printf("Digite a posicao: ");
			scanf_s("%d", &posicao);
			buffer();
			inserirMeio(num, posicao);
			break;

		case 4: // REMOVER DA LISTA
			break;

		case 5: // MOSTRAR TODA A LISTA
			listar();
			break;

		case 6:
			return 0;
		default:
			printf("Invalido\n");
			break;
		}
	}
	system("pause");
	return 0;
}

int menu()
{
	int op;
	system("cls");

	printf("1.Inserir no inicio da lista encadeda simples\n");
	printf("2.Inserir no fim da lista encadeda simples\n");
	printf("3.Inserir no meio da lista encadeda simples\n");
	printf("4.Remover da lista encadeda simples\n");
	printf("5.Listar toda a lista encadeda simples\n");
	printf("6.Sair\n");
	printf("Digite sua escolha: ");
	scanf_s("%d", &op);
	buffer();

	system("cls");
	return op;
}

void buffer()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void inserirInicio(int num)
{
	Lista* novoElemento;
	// ALOCA O ELEMENTO NA MEMORIA
	novoElemento = (Lista*)malloc(sizeof(Lista));
	novoElemento->dado = num;

	if (Head == NULL)
	{
		Head = novoElemento; // HEAD VIROU MEU NOVO ELEMENTO
		Head->prox = NULL;
	}
	else
	{
		novoElemento->prox = Head;
		Head = novoElemento;
	}
}

void listar()
{
	Lista* elementoVarredura;
	elementoVarredura = (Lista*)malloc(sizeof(Lista));

	elementoVarredura = Head;
	if (elementoVarredura == NULL)
		return 0;
	
	while (elementoVarredura != NULL)
	{
		printf("%d ", elementoVarredura->dado);
		elementoVarredura = elementoVarredura->prox;
	}
	printf("\n");

	system("pause");
}

void inserirFim(int num)
{
	Lista* novoElemento, *elementoVarredura;

	novoElemento = (Lista*)malloc(sizeof(Lista));
	elementoVarredura = (Lista*)malloc(sizeof(Lista));

	novoElemento->dado = num;

	if (Head == NULL)
	{
		Head = novoElemento;
		Head->prox = NULL;
	}
	else
	{
		elementoVarredura = Head;

		while (elementoVarredura->prox != NULL)
			elementoVarredura = elementoVarredura->prox; // passando elemento por elemento
		
		elementoVarredura->prox = novoElemento; // ponterio nulo agora apontar para meu novo elemento
		novoElemento->prox = NULL;
	}
}

void inserirMeio(int numero, int posicao)
{
	Lista* novoElemento, *elementoVarredura, *elementoAuxliar;

	novoElemento = (Lista*)malloc(sizeof(Lista));
	elementoVarredura = (Lista*)malloc(sizeof(Lista));
	elementoAuxliar = (Lista*)malloc(sizeof(Lista));

	novoElemento->dado = numero;

	if (posicao == 0)
	{
		Head = novoElemento;
		Head->prox = NULL;
	}
	else
	{
		elementoVarredura = Head;

		for (int i = 0; i < posicao - 1; i++)
			elementoVarredura = elementoVarredura->prox;

		elementoAuxliar = elementoVarredura->prox;
		elementoVarredura->prox = novoElemento;
		novoElemento->prox = elementoAuxliar;
	}
}

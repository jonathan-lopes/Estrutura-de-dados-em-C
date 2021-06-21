#include <stdio.h>
#include <stdlib.h>

// Criar uma arvore
typedef struct elementoDaArvoreBinaria
{
	int dado;
	struct elementoDaArvoreBinaria* esquerda;
	struct elementoDaArvoreBinaria* direita;
}Tree;

//Declara o root como sendo do tipo tree
Tree* root;

void inserirNaArvore(Tree** elementoVarredura, int num);
Tree* buscarNaArvore(Tree** elementoVarredura, int num);
void visualizarArvore_Ordem(Tree* elementoVarredura);
void visualizarArvore_PreOrdem(Tree* elementoVarredura);
void visulizarArvore_PosOrdem(Tree* elementoVarredura);

int main(int argc, char const* argv[])
{
	int op = 0, num;
	Tree* valorBuscado;
	do
	{
		printf("===== Menu Arvore Binaria =====\n");
		printf("0 - Inserir na arvore\n");
		printf("1 - Buscar na arvore\n");
		printf("2 - Visualizar arvore em ordem\n");
		printf("3 - Visualizar arvore em pre-ordem\n");
		printf("4 - Visualizar arvore em pos-ordem\n");
		printf("5 - Sair\n");
		printf("Digite sua opcao: ");
		scanf_s("%d", &op);

		switch (op)
		{
		case 0:
			printf("\n\nDigite um valor para inserir na arvore: ");
			scanf_s("%d", &num);
			inserirNaArvore(&root, num);
			system("cls");
			break;

		case 1:
			printf("\n\nDigite um valor para busca na arvore: ");
			scanf_s("%d", &num);
			valorBuscado = buscarNaArvore(&root, num);
			if (valorBuscado != NULL)
				printf("\nValor encontrado");
			else
				printf("\nValor nao encontrado");
			system("pause>nul");
			system("cls");
			break;

		case 2:
			visualizarArvore_Ordem(root);
			system("pause>nul");
			system("cls");
			break;

		case 3:
			visualizarArvore_PreOrdem(root);
			system("pause>nul");
			system("cls");
			break;

		case 4:
			visulizarArvore_PosOrdem(root);
			system("pause>nul");
			system("cls");
			break;

		case 5:
			exit(1);
			break;

		default:
			printf("\nEntrada Invalida\n");
			break;
		}

	} while (1);

	system("pause");
	return 0;
}

// Cria um procedimento que recebe como parametro o dado
// a ser inserido da arvore e o endereco do nó atualmente
// a ser testado, iniciando pela raiz
void inserirNaArvore(Tree** elementoVarredura, int num)
{
	// Declara um novo nó do tipo tree
	Tree* no = NULL;
	no = (Tree*)malloc(sizeof(Tree));

	// Inicializa novo nó fora da lista
	no->dado = num;

	// Verifica se o elemento recebido esta vazio
	if ((*elementoVarredura) == NULL)
	{
		// Se o elemento esta vazio, coloca na arvore
		no->esquerda = NULL;
		no->direita = NULL;

		// Faz o elemento atual (vazio) da arvore receber
		// o novo elemento 
		*elementoVarredura = no;
		return;
	}
	else
	{
		// Verifica-se RECURSIVAMENTE se a arvore deve
		// seguir para o ramo esquerdo ou direito
		if (num < (*elementoVarredura)->dado)
		{
			// Segue para a esquerda recursivamente
			inserirNaArvore(&((*elementoVarredura))->esquerda, num);
		}
		else
		{
			// Segue para a direita recursivamente
			inserirNaArvore(&((*elementoVarredura))->direita, num);
		}
	}
}

// Cria um procedimento que recebe como parametro o dado
// E o enderecodo nó a ser testado, iniciando pela raiz
Tree* buscarNaArvore(Tree** elementoVarredura, int num)
{	
	// Verifica se o elemento esta vazio
	if (elementoVarredura != NULL)
	{
		// Verifica RECURSIVAMENTE se a arvore deve
		// seguir parao ramo esquerdo ou direito
		if (num < (*elementoVarredura)->dado)
		{
			// Segue para a esquerda recursivavamente
			buscarNaArvore(&((*elementoVarredura)->esquerda), num);
		}
		else
		{
			if (num > (*elementoVarredura)->dado)
			{
				// Segue para a direita recursivavamente
				buscarNaArvore(&((*elementoVarredura)->direita), num);
			}
			else
			{
				if (num == (*elementoVarredura)->dado)
				{
					// Valor encontrado
					return *elementoVarredura;
				}
			}
		}
	}
	return NULL;
}

void visualizarArvore_Ordem(Tree* elementoVarredura)
{
	if (elementoVarredura != NULL)
	{
		// Segue para a esquerda
		visualizarArvore_Ordem(elementoVarredura->esquerda);
	
		// Imprime o elemento atual
		printf("\n\n%4d", elementoVarredura->dado);

		// Segue para a direita
		visualizarArvore_Ordem(elementoVarredura->direita);
	}
}

void visualizarArvore_PreOrdem(Tree* elementoVarredura)
{
	if (elementoVarredura != NULL)
	{
		// Imprime elemento atual
		printf("\n\n%4d", elementoVarredura->dado);

		// Segue para a esquerda
		visualizarArvore_Ordem(elementoVarredura->esquerda);

		// Segue para a direita
		visualizarArvore_Ordem(elementoVarredura->direita);
	}
}

void visulizarArvore_PosOrdem(Tree* elementoVarredura)
{
	// Segue para a esquerda
	visualizarArvore_Ordem(elementoVarredura->esquerda);

	// Segue para a direita
	visualizarArvore_Ordem(elementoVarredura->direita);

	// Imprime elemento atual
	printf("\n\n%4d", elementoVarredura->dado);
}
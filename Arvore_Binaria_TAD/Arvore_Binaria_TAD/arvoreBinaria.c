#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

typedef struct NO
{
	int info;
	struct NO* esq;
	struct NO* dir;
}NO;

ArvBin* cria_ArvBin()
{
	ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
	if (raiz != NULL)
		*raiz = NULL;
	return raiz;
}

void libera_NO(NO* no)
{
	if (no == NULL)
		return;
	libera_NO(no->esq);
	libera_NO(no->dir);
	free(no);
	no = NULL;
}

void libera_ArvBin(ArvBin* raiz)
{
	if (raiz == NULL)
		return;
	libera_NO(*raiz); // Libera cada nó da arvore
	free(raiz);	// Libera a raiz
}

_Bool estaVazia_ArvBin(ArvBin* raiz)
{
	return (raiz == NULL || *raiz == NULL) ? 1 : 0;
}

int altura_ArvBin(ArvBin* raiz)
{
	if (raiz == NULL)
		return 0;
	if (*raiz == NULL)
		return 0;

	int alt_esq = altura_ArvBin(&((*raiz)->esq));
	int alt_dir = altura_ArvBin(&((*raiz)->dir));
	if (alt_esq > alt_dir)
		return (alt_esq + 1);
	else
		return (alt_dir + 1);
}

int totalNo_ArvBin(ArvBin* raiz)
{
	if (raiz == NULL)
		return 0;
	if (*raiz == NULL)
		return 0;

	int alt_esq = totalNo_ArvBin(&((*raiz)->esq));
	int alt_dir = totalNo_ArvBin(&((*raiz)->dir));
	return (alt_esq + alt_dir + 1);
}

void preOrdem_ArvBin(ArvBin* raiz)
{
	if (raiz == NULL)
		return;
	if (*raiz != NULL)
	{
		printf("%4d", (*raiz)->info);
		preOrdem_ArvBin(&((*raiz)->esq));
		preOrdem_ArvBin(&((*raiz)->dir));
	}
}

void emOrdem_ArvBin(ArvBin* raiz)
{
	if (raiz == NULL)
		return 0;
	if (*raiz != NULL)
	{
		emOrdem_ArvBin(&((*raiz)->esq));
		printf("%4d", (*raiz)->info);
		emOrdem_ArvBin(&((*raiz)->dir));
	}
}

void posOrdem_arvBin(ArvBin* raiz)
{
	if (raiz == NULL)
		return 0;
	if (*raiz != NULL)
	{
		posOrdem_arvBin(&((*raiz)->esq));
		posOrdem_arvBin(&((*raiz)->dir));
		printf("%4d", (*raiz)->info);
	}
}

int insere_ArvBin(ArvBin* raiz, int valor)
{
	if (raiz == NULL)
		return 0;
	
	NO* novo = (NO*)malloc(sizeof(NO));

	if (novo = NULL)
		return 0;
	
	novo->info = valor;
	novo->esq = NULL;
	novo->dir = NULL;

	//Procurar onde inserir
	if (*raiz == NULL)
		*raiz = novo;
	else
	{
		NO* atual = *raiz;
		NO* ant = NULL;

		// Navegar nos nós da arvore ate chega em um no nulo
		while (atual != NULL) 
		{
			ant = atual;
			if (valor == atual->info)
			{
				free(novo);
				return 0; // Elemento ja existe
			}

			if (valor > atual->info)
				atual = atual->dir;
			else
				atual = atual->esq;
		}

		// Insere como filho desse no folha
		if (valor > ant->info)
			ant->dir = novo;
		else
			ant->esq = novo;
	}
	return 1;
}
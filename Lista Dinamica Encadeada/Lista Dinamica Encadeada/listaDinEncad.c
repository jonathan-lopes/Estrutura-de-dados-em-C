#include <stdlib.h>
#include "listaDinEncad.h"

struct elemento
{
	struct aluno dados;
	struct elemento* prox;
};

typedef struct elemento Elem;

Lista* cria_lista()
{
	Lista* li = (Lista*)malloc(sizeof(Lista)); // ALOCAR A MEMORIA
	if (li != NULL)
		*li = NULL;
	return li;
}

void libera_lista(Lista* li)
{
	if (li != NULL)
	{
		Elem* no;
		while ((*li) != NULL)
		{
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}

int tamanho_lista(Lista* li)
{
	if (li == NULL) return 0;
	int cont = 0;
	Elem* no = *li;

	while (no != NULL)
	{
		cont++;
		no = no->prox;
	}
	return cont;
}

_Bool lista_cheia(Lista* li)
{
	return 0;
}

_Bool lista_vazia(Lista* li)
{
	if (li == NULL)
		return 1;
	if (*li == NULL)
		return 1;
	return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al)
{
	if (li == NULL) return 0;
	Elem* no = (Elem*)malloc(sizeof(Elem));
	if (no == NULL) return 0;

	no->dados = al;
	no->prox = (*li);
	*li = no;
	return 1;
}

int insere_lista_final(Lista* li, struct aluno al)
{
	if (li == NULL) return 0;
	Elem* no = (Elem*)malloc(sizeof(Elem));
	if (no == NULL) return 0;

	no->dados = al;
	no->prox = NULL;
	if ((*li) == NULL)
		insere_lista_inicio(li, al);
	else
	{
		Elem* aux = *li;
		while (aux->prox != NULL)
			aux = aux->prox;
		aux->prox = no;
	}
	return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al)
{
	if (li == NULL) return 0;
	Elem* no = (Elem*)malloc(sizeof(Elem));
	if (no == NULL) return 0;
	no->dados = al;
	if (lista_vazia(li)) // INSERE NO INICIO
	{ 	no->prox = (*li);
		*li = no;
		return 1;
	}
	else
	{
		Elem* ant= NULL, * atual = *li;

		while (atual != NULL && atual->dados.matricula < al.matricula)
		{
			ant = atual;
			atual = atual->prox;
		}
		if (atual == *li) // INSERE NO INICIO 
		{ 
			no->prox = (*li);
			*li = no;
		}
		else
		{
			no->prox = ant->prox;
			ant->prox = no;
		}
		return 1;
	}
}

int remove_lista_inicio(Lista* li)
{
	if (li == NULL)
		return 0;
	if ((*li) == NULL) //LISTA VAZIA
		return 0;

	Elem* no = *li;
	*li = no->prox;
	free(no);
	return 1;
}

int remove_lista_final(Lista* li)
{
	if (li == NULL) return 0;
	if ((*li) == NULL) return 0;

	Elem* ant = 0, *no = *li;

	while (no->prox != NULL)
	{
		ant = no;
		no = no->prox;
	}

	if (no == (*li)) // REMOVER O PRIMEIRO?
		*li = no->prox;
	else
		ant->prox = no->prox;
	free(no);
	return 1;
}

int remove_lista(Lista* li, int mat)
{
	if (li == NULL) return 0;

	Elem* ant = 0, * no = *li;

	while (no != NULL && no->dados.matricula != mat)
	{
		ant = no;
		no = no->prox;
	}

	if (no == NULL) return 0; // NAO ENCONTRADO

	if (no == *li) // REMOVER O PRIMEIRO
		*li = no->prox;
	else
		ant->prox = no->prox;
	free(no);
	return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno* al)
{
	if (li == NULL || pos <= 0) return 0;
	Elem* no = *li;
	int i = 1;
	while (no != NULL && i < pos)
	{
		no = no->prox;
		i++;
	}

	if (no == NULL) return 0;
	else
	{
		*al = no->dados;
		return 1;
	}
}

int consulta_lista_mat(Lista* li, int mat, struct aluno* al)
{
	if (li == NULL) return 0;

	Elem* no = *li;
	while (no != NULL && no->dados.matricula != mat)
		no = no->prox;
	
	if (no == NULL)
		return 0;
	else 
	{
		*al = no->dados;
		return 1;
	}
}

void imprime_lista(Lista* li) 
{
	if (li == NULL)
		return;

	Elem* no = *li;
	while (no != NULL) 
	{
		printf("Matricula: %d \n", no->dados.matricula);
		printf("Nome: %s \n", no->dados.nome);
		printf("Notas: %.1f %.1f %.1f \n", no->dados.n1, no->dados.n2, no->dados.n3);
		printf("------------------------------- \n");

		no = no->prox;
	}
}

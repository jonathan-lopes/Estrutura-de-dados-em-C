#include "pilhaDin.h"
#include <stdlib.h>

struct elemento
{
	Dados dados;
	struct elemento* prox;
};
typedef struct elemento Elem;

PILHA* cria_pilha()
{
	PILHA* pi = (PILHA*)malloc(sizeof(PILHA));
	if (pi != NULL)
		*pi = NULL;
	return pi;
}

void libera_pilha(PILHA* pi)
{
	if (pi != NULL)
	{
		Elem* no;
		while ((*pi) != NULL)
		{
			no = *pi;
			*pi = (*pi)->prox;
			free(no);
		}
		free(pi);
	}
}

int tamanho_pilha(PILHA* pi)
{
	if (pi == NULL) return 0;
	int cont = 0;
	Elem* no = *pi;
	while (no != NULL)
	{
		cont++;
		no = no->prox;
	}
	return cont;
}

_Bool pilha_cheia(PILHA* pi)
{
	return 0;
}

_Bool pilha_vazia(PILHA* pi)
{
	if (pi == NULL)
		return 1;
	if (*pi == NULL)
		return 1;
	return 0;
}

int insere_pilha(PILHA* pi, Dados al)
{
	if (pi == NULL) return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if (no == NULL) return 0;

	no->dados = al;
	no->prox = (*pi);
	*pi = no;
	return 1;
}

int remove_pilha(PILHA* pi)
{
	if (pi == NULL) return 0;
	if ((*pi) == NULL) return 0;

	Elem* no = *pi;
	*pi = no->prox;
	free(no);
	return 1;
}

int consulta_topo_pilha(PILHA* pi, Dados* al)
{
	if (pi == NULL) return 0;
	if ((*pi) == NULL) return 0;

	*al = (*pi)->dados;
	return 1;
}

void imprime_pilha(PILHA* pi) {
	if (pi == NULL)
		return;
	Elem* no = *pi;
	while (no != NULL) {
		printf("Matricula: %d\n", no->dados.matricula);
		printf("Nome: %s\n", no->dados.nome);
		printf("Notas: %f %f %f\n", no->dados.n1,
			no->dados.n2,
			no->dados.n3);
		printf("-------------------------------\n");
		no = no->prox;
	}
}

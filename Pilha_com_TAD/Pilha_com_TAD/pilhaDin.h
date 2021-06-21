#pragma once
typedef struct aluno
{
	int matricula;
	char nome[30];
	float n1, n2, n3;
}Dados;

typedef struct elemento* PILHA;

PILHA* cria_pilha();
void libera_pilha(PILHA* pi);
int tamanho_pilha(PILHA* pi);
_Bool pilha_cheia(PILHA* pi);
_Bool pilha_vazia(PILHA* pi);
int insere_pilha(PILHA* pi, Dados al);
int remove_pilha(PILHA* pi);
int consulta_topo_pilha(PILHA* pi, Dados* al);
void imprime_pilha(PILHA* pi);
#pragma once
struct aluno
{
	int matricula;
	char nome[30];
	float n1, n2, n3;
};
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* head);
int tamanho_lista(Lista* head);
_Bool lista_cheia(Lista* head);
_Bool lista_vazia(Lista* head);
int insere_lista_inicio(Lista* head, struct aluno al);
int insere_lista_final(Lista* head, struct aluno al);
int insere_lista_ordernada(Lista* head, struct aluno al);
int remove_lista_inicio(Lista* head);
int remove_lista_final(Lista* head);
int remove_lista(Lista* head, int mat);
int consulta_lista_pos(Lista* head, int pos, struct aluno* al);
int consulta_lista_mat(Lista* head, int mat, struct aluno* al);
void imprime_lista(Lista* head);
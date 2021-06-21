#include "filadin.h" //inclui os Prototipos
#include <stdlib.h>
#include <stdio.h>

//Definicao do tipo Fila
struct fila
{
	struct elemento* inicio;
	struct elemento* final;
};

//Definicao do Nó Descritor da Fila
struct elemento
{
	struct aluno dados;
	struct elemento* prox;
};
typedef struct elemento Elem;

Fila* cria_Fila()
{
	Fila* fi = (Fila*)malloc(sizeof(Fila));
	if (fi != NULL)
	{
		fi->final = NULL;
		fi->inicio = NULL;
	}
	return fi;
}

void libera_Fila(Fila* fi)
{
	if (fi != NULL)
	{
		Elem* no; // nó auxiliar
		while (fi->inicio != NULL)
		{
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}

int tamanho_Fila(Fila* fi)
{
	if (fi == NULL) return 0;
	int cont = 0;
	Elem* no = fi->inicio; // nó auxiliar
	while (no != NULL)
	{
		cont++;
		no = no->prox;
	}
	return cont;
}

_Bool Fila_cheia(Fila* fi)
{
	return 0;
}

_Bool Fila_vazia(Fila* fi)
{
	if (fi == NULL) 
		return 1;
	if (fi->inicio == NULL) 
		return 1;
	return 0;
}

int insere_Fila(Fila* fi, struct aluno al)
{
	if (fi == NULL)
		return 0;
	
	Elem* no = (Elem*)malloc(sizeof(Elem));
	if (no == NULL)
		return 0;
	no->dados = al;
	no->prox = NULL;

	// Fila Vazia
	if (fi->inicio == NULL)
		fi->inicio = no;
	else
		fi->final->prox = no;

	fi->final = no;
	return 1;
}

int remove_Fila(Fila* fi)
{
	if (fi == NULL)
		return 0;
	if (fi->inicio == NULL) // Fila vazia
		return 0;
	Elem* no = fi->inicio; // Nó auxiliar

	fi->inicio = fi->inicio->prox;

	if (fi->inicio == NULL) // Fila ficou vazia
		fi->final = NULL;

	free(no);
	return 1;
}

int consulta_Fila(Fila* fi, struct aluno* al)
{
	if (fi == NULL)
		return 0;
	if (fi->inicio == NULL) // Fila vazia
		return 0;

	*al = fi->inicio->dados;
	return 1;
}

void imprime_Fila(Fila* fi)
{
	if (fi == NULL) return;

	Elem* no = fi->inicio;

	while (no != NULL)
	{
		printf("Matricula: %d\n", no->dados.matricula);
		printf("Nome: %s\n", no->dados.nome);
		printf("Notas: %.3f %.3f %.3f\n", no->dados.n1, no->dados.n2, no->dados.n3);
		printf("-------------------------------\n");
		no = no->prox;
	}
}
#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadCirc.h" //inclui os Protótipos

//Defini��o do tipo lista
struct elemento
{
	struct aluno dados;
	struct elemento* prox;
};
typedef struct elemento Elem;

Lista* cria_lista()
{
	Lista* head = (Lista*)malloc(sizeof(Lista));
	if (head != NULL)
		*head = NULL;
	return head;
}

void libera_lista(Lista* head)
{
	if (head != NULL && *head != NULL)
	{
		Elem* aux, *no = *head;

		while ((*head) != no->prox)
		{
			aux = no;
			no = no->prox;
			free(aux);
		}
		free(no);
		free(head);
	}
}

int tamanho_lista(Lista* head)
{
	if (head == NULL || *head == NULL)
		return 0;

	int cont = 0;
	Elem* aux = *head;
	do
	{
		cont++;
		aux = aux->prox;
	} while (aux != (*head));
	return cont;
}

_Bool lista_cheia(Lista* head)
{
	return 0;
}

_Bool lista_vazia(Lista* head)
{
	return (head == NULL || *head == NULL) ? 1 : 0;
}

int insere_lista_inicio(Lista* head, struct aluno al)
{
	if (head == NULL)
		return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if (no == NULL)
		return 0;

	no->dados = al;

	if ((*head) == NULL) // Lista vazia: insere no inicio
	{
		*head = no;
		no->prox = no;
	}
	else
	{
		Elem* aux = *head;
		while (aux->prox != (*head))
			aux = aux->prox;

		aux->prox = no;	  // o ultimo elemento aponta para o novo nó
		no->prox = *head; // o novo nó aponta para o inicio da lista
		*head = no;		  // o novo nó vira o inicio
	}
	return 1;
}

int insere_lista_final(Lista* head, struct aluno al)
{
	if (head == NULL)
		return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if (no == NULL)
		return 0;

	no->dados = al;
	if ((*head) == NULL) // Lista vazia: insere no inicio
	{
		*head = no;
		no->prox = no;
	}
	else // Procuro o ultimo elemento e insere no final
	{
		Elem* aux = *head;
		while (aux->prox != (*head))
			aux = aux->prox;

		aux->prox = no;	  // O ultimo nó aponta para o novo nó
		no->prox = *head; // Novo nó aponta para o inicio da lista
	}
	return 1;
}

int insere_lista_ordenada(Lista* head, struct aluno al)
{
	if (head == NULL)
		return 0;

	Elem* no = (Elem*)malloc(sizeof(Elem));
	if (no == NULL)
		return 0;

	no->dados = al;
	if ((*head) == NULL) // Lista vazia: insere no inicio
	{
		*head = no;
		no->prox = no;
		return 1;
	}
	else
	{
		if ((*head)->dados.matricula > al.matricula) // Insere no inicio
		{
			Elem* atual = *head;
			while (atual->prox != (*head)) // Procura o ultimo
				atual = atual->prox;

			no->prox = *head;
			atual->prox = no;
			*head = no;
			return 1;
		}

		Elem* ant = *head, * atual = (*head)->prox;
		while (atual != (*head) && atual->dados.matricula < atual->dados.matricula)
		{
			ant = atual;
			atual = atual->prox;
		}
		ant->prox = 0;
		no->prox = atual;
		return 1;
	}
}

int remove_lista_inicio(Lista* head)
{
	if (head == NULL || (*head) == NULL)
		return 0;

	if ((*head) == (*head)->prox) //Lista fica vazia
	{
		free(*head);
		*head = NULL;
		return 1;
	}

	Elem* atual = *head;
	while (atual->prox != (*head)->prox) //Procura o ultimo
		atual = atual->prox;

	Elem* no = *head;		// Crio um no auxiliar para amazerna o incio da lista
	atual->prox = no->prox; // faco o nó atual receber o nó subsequente ao head
	*head = no->prox;		// O nó subsequente ao head vira o head
	free(no);
	return 1;
}

int remove_lista_final(Lista* head)
{
	if (head == NULL || (*head) == NULL)
		return 0;
	if ((*head) == (*head)->prox) // Lista fica vazia
	{
		free(*head);
		*head = NULL;
		return 1;
	}

	Elem* ant = 0, * no = *head;
	while (no->prox != (*head)) // Procura o ultimo
	{
		ant = no;
		no = no->prox;
	}
	ant->prox = no->prox; // ant receber o nó apontando pelo proximo ou seja o incio da lista
	free(no);
	return 1;
}

int remove_lista(Lista* head, int mat)
{
	if (head == NULL || (*head) == NULL)
		return 0;

	Elem* no = *head;
	if (no->dados.matricula == mat) // remove do inicio
	{
		if (no == no->prox) //lista fica vaza
		{
			free(no);
			*head = NULL;
			return 1;
		}
		else
		{
			Elem* ult = *head;
			while (ult->prox != (*head)) //procura o último
				ult = ult->prox;
			ult->prox = (*head)->prox;
			*head = (*head)->prox;
			free(no);
			return 1;
		}
	}

	Elem* ant = no;
	no = no->prox;
	while (no != (*head) && no->dados.matricula != mat)
	{
		ant = no;
		no = no->prox;
	}
	if (no == *head) // Valor nao encontrado
		return 0;
	ant->prox = no->prox;
	free(no);
	return 1;
}

int consulta_lista_pos(Lista* head, int pos, struct aluno* al)
{
	if (head == NULL || (*head) == NULL || pos <= 0)
		return 0;
	Elem* no = *head;
	int i = 1;
	while (no->prox != (*head) && i < pos)
	{
		no = no->prox;
		i++;
	}
	if (i != pos) return 0; // valor nao encontrado
	else
	{
		*al = no->dados;
		return 1;
	}
}

int consulta_lista_mat(Lista* head, int mat, struct aluno* al)
{
	if (head == NULL || (*head) == NULL) return 0;
	Elem* no = *head;
	while (no->prox != (*head) && no->dados.matricula != mat)
		no = no->prox;
	if (no->dados.matricula != mat)
		return 0; // Valor nao encontrado
	else
	{
		*al = no->dados;
		return 1;
	}
}

void imprime_lista(Lista* head) 
{
	if (head == NULL || (*head) == NULL)
		return;
	Elem* no = *head;
	do 
	{
		printf("Matricula: %d\n", no->dados.matricula);
		printf("Nome: %s\n", no->dados.nome);
		printf("Notas: %.3f %.3f %.3f\n", no->dados.n1, no->dados.n2, no->dados.n3);
		printf("-------------------------------\n");
		no = no->prox;
	} while (no != (*head));
}

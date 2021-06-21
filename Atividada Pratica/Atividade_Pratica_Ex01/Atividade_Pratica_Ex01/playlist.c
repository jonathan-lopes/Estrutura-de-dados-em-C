#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "playlist.h" // Incluindo prototipos

typedef struct node
{
	Playlist data;
	struct node* next;
}Node;

// Limpar o buffer do teclado
void buffer() 
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

// Verifica se a lista esta vazia
_Bool isEmpty(List* head)
{
	return (head == NULL || (*head) == NULL) ? 1 : 0;
}

// Retonar uma lista apontando pra NULL
List* createList()
{
	List* head = (List*)malloc(sizeof(List));
	if (head != NULL)
		*head = NULL;
	return head;
}

// Libera todos os nós da lista
void freeList(List* head)
{
	if (isEmpty(head) == 1)
	{
		printf("Erro: A lista é nula ou está vazia");
		return;
	}

	Node* aux, *node = *head;
	while (node->next != (*head)) // Pecorrendo a lista enquanto meu nó for diferente do inicio da lista
	{
		aux = node;
		node = node->next;
		free(aux);
	}
	free(node);
	free(head);
	head = NULL; //dangling pointer
	node = NULL;
	aux = NULL;
}

// Conta o numero de nós na lista
int sizeList(List* head)
{
	if (isEmpty(head) == 1)
	{
		printf("\n\nErro: A lista é nula ou está vazia\n");
		system("pause>nul");
		return 0;
	}

	int cont = 0;
	Node* aux = *head;

	do
	{
		cont++;
		aux = aux->next;
	} while (aux != (*head));

	return cont;
}

// Insere no inicio da lista
int insertFist(List* head, Playlist music)
{
	if (head == NULL) return 0; // Verificando se a lista e nula

	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) return 0; // Verifico se houve algum problema na alocacao do novo nó

	node->data = music; 

	if ((*head) == NULL) // Lista vazia: insere no inicio
	{
		*head = node;
		node->next = node;
	}
	else
	{
		Node* aux = *head;
		while (aux->next != (*head))
			aux = aux->next;

		aux->next = node; // O ultimo elemento aponta para o novo nó
		node->next = *head; // O novo nó aponta para o inicio da lista
		*head = node;  // O novo nó vira o inicio da lista
	}
	return 1;
}

// Insere no final da lista
int insertFinal(List* head, Playlist music)
{
	if (head == NULL) return 0; // Verificando se a lista e nula
	
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) return 0; // Verifico se houve algum problema na alocacao do novo nó

	node->data = music;
	if ((*head) == NULL) // Lista vazia: insere no inicio
	{
		*head = node;
		node->next = node;
	}
	else // Procuro o ultimo elemento e insere no final
	{
		Node* aux = *head;
		while (aux->next != (*head))
			aux = aux->next;

		aux->next = node;  // O ultimo nó aponta para o novo nó
		node->next = *head;  // Novo nó aponta para o inicio da lista
	}
	return 1;
}

// Insere no meio da lista
int insertMiddle(List* head, Playlist music, int pos)
{
	if (head == NULL || pos < 0 || pos > sizeList(head))
	{
		printf("\n\nErro: Lista vazia ou a posição passada é invalida\n");
		system("pause>nul");

		return 0;
	}

	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) return 0; // Verifico se houve algum problema na alocacao do novo nó

	node->data = music;
	if ((*head) == NULL) // Lista vazia: insere no inicio
	{
		*head = node;
		node->next = node;
		return 1;
	}
	else
	{
		if (pos == 0) // Insere no inicio
		{
			*head = node;
			node->next = node;
			return 1;
		}
		
		Node* nodeScan = *head;

		int i = 0;
		while (nodeScan->next != (*head) && i < pos - 1)
		{
			nodeScan = nodeScan->next;
			i++;
		}

		Node* aux = nodeScan->next;
		nodeScan->next = node;
		node->next = aux;
		return 1;
	}
}

// Remove a musica passada como parametro
int removeList(List* head, char music[])
{
	if (isEmpty(head) == 1) return 0;

	if ((*head) == (*head)->next) //Lista fica vazia
	{
		printf("\n\nMusica da banda %s foi removida\n", (*head)->data.nameBand);
		free(*head);
		*head = NULL;
		return 1;
	}

	Node* current = *head, *previous = 0;

	do
	{
		if (strcmp(current->data.nameMusic, music) == 0) // Verifico se as strings sao iguais
		{
			printf("\n\nMusica da banda %s foi removida\n", current->data.nameBand);
			previous->next = current->next;
			free(current);
			return 1;
		}
		previous = current;
		current = current->next;
	} while (current != (*head));

	printf("\nErro: Musica não existe\n\n");
	return 0;
}

void printList(List* head)
{
	if (head == NULL) return; // Lista nula
	
	if ((*head) == NULL)
		printf("\n\nLista Vazia!\n\n");
	else
	{
		Node* aux = *head;
		printf("\n\n========== Sua Playlist ========== \n");

		do
		{
			printf("Nome da banda/artista: %s\n", aux->data.nameBand);
			printf("Nome da musica: %s\n", aux->data.nameMusic);
			printf("Duração: %s\n", aux->data.duration);
			printf("\n\n\n");
			aux = aux->next;
		} while (aux != (*head));
	}
}

// Verifica se o arquivo exixte
int fileExists(const char* cpfileName)
{
	struct stat stStat;
	int errcode = stat(cpfileName, &stStat);
	if (errcode == ENOENT)
		return 0; /* nao existe */
	return 1; /* existe */
}

// Salva a playlist criada
void saveFile(List* head)
{
	FILE* arq;
	errno_t err;
	int result;

	if (fileExists(PATH) == 0) // Verifico se o arquivo nao existe
	{
		err = fopen_s(&arq, PATH, "w");
		if (arq == NULL) 
		{
			perror("O seguinte erro ocorreu");
			system("pause");
			exit(1);
		}

		Node* aux = *head;
		do
		{
			result = fprintf(arq, "Nome da banda/artista: %s\n", aux->data.nameBand);
			if (result < 0)
				printf("Erro na escrita do nome da banda/artista\n");

			result = fprintf(arq, "Nome da musica: %s\n", aux->data.nameMusic);
			if (result < 0)
				printf("Erro na escrita no nome da musica\n");

			result = fprintf(arq, "Duração: %s\n", aux->data.duration);
			if (result < 0)
				printf("Erro na escrita na duração da musica\n");

			fprintf(arq, "\n\n\n");
			aux = aux->next;
		} while (aux->next != (*head));  // Grava os dados no arquivo
	
		printf("\n\nPlaylist salva no caminho %s", PATH);

		fflush(arq); // Forcando a escrita dos dados do buffer
		fclose(arq);
		return;
	}

	if (fileExists(PATH) == 1) // Verifico se o arquivo ja existe
	{
		err = fopen_s(&arq, PATH, "a");
		if (arq == NULL)
		{
			perror("O seguinte erro ocorreu");
			system("pause");
			exit(1);
		}

		Node* aux = *head;
		do
		{
			result = fprintf(arq, "Nome da banda/artista: %s\n", aux->data.nameBand);
			if (result < 0)
				printf("Erro na escrita do nome da banda/artista\n");

			result = fprintf(arq, "Nome da musica: %s\n", aux->data.nameMusic);
			if (result < 0)
				printf("Erro na escrita no nome da musica\n");

			result = fprintf(arq, "Duração: %s\n", aux->data.duration);
			if (result < 0)
				printf("Erro na escrita na duração da musica\n");

			fprintf(arq, "\n\n\n");
			aux = aux->next;
		} while (aux->next != (*head));  // Grava os dados no arquivo
		printf("\n\nPlaylist salva no caminho %s", PATH);

		fflush(arq); // Forcando a escrita dos dados do buffer
		fclose(arq);
		return;
	}
}

// Deleto o arquivo
void removeFile()
{
	int status;

	status = remove(PATH);

	if (status != 0)
	{
		perror("\n\nO seguinte erro ocorreu");
		exit(1);
	}
	else
		printf("\n\nArquivo removido com sucesso\n");
}

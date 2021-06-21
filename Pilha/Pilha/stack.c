#include <stdio.h>
#include <stdlib.h>

// Cria uma pilha usando lista
typedef struct stack
{
    int data;
    struct stack* prox;
} Stack;
Stack* top;

void push(int num);
void pop();

int main()
{
    int op, num;

    do
    {
        system("cls");
        printf("\n============ MENU ==============\n");
        printf("0 - Inserir na pilha\n");
        printf("1 - Remove da pilha\n");
        printf("2 - sair\n");
        printf("Reposta: ");
        scanf_s("%d", &op);

        switch (op)
        {
        case 0:
            printf("Digite o valor para inserir na pilha: ");
            scanf_s("%d", &num);
            push(num);
            break;

        case 1:
            pop();
            break;

        case 2:
            exit(1);
            break;
        default:
            printf("\nEntrada Invalida\n");
            system("pause>nul");
            break;
        }
    } while (1);

    return 0;
}

void push(int num)
{
    // Aloca memoria para o novo no
    Stack* no = (Stack*)malloc(sizeof(Stack));

    // Insere o valor no novo elemento que sera inserido na pilha
    no->data = num;

    // Verifica se existe algo na pilha
    if (top == NULL)
    {
        // Se a pilha esta vazia, o novo elemento sera a pilha
        // e apontara para nulo
        no->prox = NULL;
    }
    else
    {
        // Se a pilha ja tem algo, o novo elemento aponta para o novo
        no->prox = top;
    }

    // o Novo elemento vira o topo, pois a insercao e sempre no topo
    top = no;
}

/* Nao passa nenhum valor como parametro,
pois a remocao e sempre do valor do tempo*/
void pop()
{
    Stack* remove;

    // Verifica que existe algo na pilha
    if (top != NULL)
    {
        //Existe algo para remover entao
        //Salva temporariamente o topo atual
        remove = top;

        //Incrementa o top (passa para o proximo no)
        top = top->prox;

        //Limpa da memoria o topo antigo
        free(remove);
    }
}
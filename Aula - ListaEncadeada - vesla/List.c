#include <stdio.h>
#include <stdlib.h>

// DEFINCAO DA ESTRUTURA
typedef struct dataNode {
    int id;
}DataNode;

typedef struct node {
    DataNode data;
    struct node *next;
}Node;

typedef struct list {
    int size;
    Node *head;
}List;

List* createList();
void push(List* list, DataNode data);
void printList(List* list);
void pop(List* list);
_Bool isEmpty(List* list);
Node* atPos(List* list, int index);
int indexOf(List* list, Node* node);
void erase(List* list, int index);
void insert(List* list, DataNode data, int index);
void xchgNodes(List* list, Node* nodeA, Node* nodeB);
Node* minimum(List* list, int index);
Node* maximum(List* list, int index);
void incSort(List* list);
void decSort(List* list);

int main() {
    int index;
    List* lista = createList();
    
    DataNode data;
    data.id = 5;
    push(lista, data);

    data.id = 88;
    push(lista, data);


    data.id = 45;
    push(lista, data);

    
    data.id = 12;
    push(lista, data);

    printf("\nDigite um valor um valor para inseri na lista: ");
    scanf("%d", &data.id);
    printf("Digite um indice para inserir na lista: ");
    scanf("%d", &index);

    insert(lista, data, index);
    printf("\nLista: ");
    printList(lista);

    printf("\nNos trocados: ");
    xchgNodes(lista, lista->head->next->next, lista->head->next);
    printList(lista);

    printf("\nNumero minimo da lista: %d", minimum(lista, 2)->data.id);

    printf("\nNumero maximo da lista: %d", maximum(lista, 2)->data.id);

    incSort(lista);
    printf("\nLista Ordenada em ordem crescente: ");
    printList(lista);

    decSort(lista);
    printf("Lista Ordenada em ordem descrecente: ");
    printList(lista);

    return 0;
}

//RETORNA UMA REFERENCIA PARA A LISTA
List* createList() {
    List* list = (List*)malloc(sizeof(List)); // CRIA UM PONTEIRO PARA A LISTA

    list->size = 0; // INICIALIZA O TAMANHO DA LISTA COM ZERO
    list->head = NULL; // INICIALIZA o HEAD COM NULL

    return list;
}

// INSERE NO INICIO DA LISTA
void push(List* list, DataNode data) {
    Node* node = (Node*)malloc(sizeof(Node)); //ALOCAR NA MEMORIA

    node->data = data; // NODE RECEBER O VALOR DE DATA
    node->next = list->head; // O PROXIMO NÓ SE TORNAR O HEAD
    list->head = node; // O NÓ SE TORNAR A PRIMEIRA
    list->size++;
}

// IMPRIME A LISTA
void printList(List* list) {    
    if (isEmpty(list)) {
        printf("Lista Vazia\n");
        return;
    }
        
    Node* pointer = list->head; // NÓ VARREDURA
    // PERCORRER TODA A LISTA
    while(pointer != NULL) { 
        printf("%d ", pointer->data.id);
        pointer = pointer->next;
    }
    printf("\n");
}

// REMOVE O PRIMEIRO NÓ
void pop(List* list) {
    if (!isEmpty(list)) {
       Node* pointer = list->head; // NÓ AUXILIAR
       list->head = pointer->next; // HEAD APONTAR PARA O PROXIMO NÓ
       free(pointer);
       list->size--;
    }
}

// VERIFICA SE A LISTA ESTA VAZIA E RETONAR UM BOLEANO
_Bool isEmpty(List* list) {
    return (list->size == 0);
}

// DEVOLVE UM NÓ PARA O INDICE PASSADO
Node* atPos(List* list, int index) {
    if(index >= 0 && index < list->size) {
        Node* node = list->head; // NÓ AUXILIAR

        for (int i = 0; i < index; i++)
            node = node->next; // NODE RECEBE O PROXIMO NODE
        return node;
    }
    printf("\nIndice invalido\n");
    return NULL;
}

// RETONAR O INDICE DO NÓ
int indexOf(List* list, Node* node) {
    if(node != NULL) {
        Node* pointer = list->head; // NÓ AUXILIAR
        int index = 0; // VARIAVEL CONTADORA

        while(pointer != node && pointer != NULL) {
            pointer = pointer->next;
            index++;
        }
        if (pointer != NULL) 
            return index;
    }
    printf("\n\nNo nao pertencente a lista\n");
    return -1;
}

// EXCLUIR O NÓ NO INDICE PASSADO
void erase(List* list, int index) {
    if (index == 0)
        pop(list);
    else {
        Node* current = atPos(list, index); // NÓ ATUAL
        
        if(current != NULL) {
            Node* previous = atPos(list, index - 1); // NÓ ANTERIOR
            previous->next = current->next;
            free(current);
            list->size--;
        }
    }
}

// INSERE UM NÓ NA POSICAO DESEJADA
void insert(List* list, DataNode data, int index) {
    if(index == 0)
        push(list, data);
    else {
        Node* current = atPos(list, index); // NÓ ATUAL
        
        if (current != NULL) {
            Node* previous = atPos(list, index - 1); // NÓ ANTERIOR

            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = data;

            previous->next = newNode;
            newNode->next =current;
            list->size++;
        } 
    }
}

// MUDAR OS NÓS DE POSICAO
void xchgNodes(List* list, Node* nodeA, Node* nodeB) {
    if(nodeA == nodeB) // SE OS NÓS ESTAO NO MESMO ENDERECO RETORNA E NADA EXECUTA 
        return;
   
    int indexA = indexOf(list, nodeA); // INDICE DO NÓ A
    int indexB = indexOf(list, nodeB); // INDICE DO NÓ B

    if(indexA == -1 || indexB == -1)
        return;

    if(indexA > indexB) {
        nodeA = nodeB;
        nodeB = atPos(list, indexA);

        indexA = indexB;
        indexB = indexOf(list, nodeB);
    }
    Node* pb = atPos(list, indexB - 1);
    if(nodeA == list->head)
        list->head = nodeB;
    else {
        Node* pa = atPos(list, indexA - 1);
        pa->next = nodeB;
    }
    pb->next = nodeA;
    Node* pointer = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = pointer;
}

// RETORNA O MENOR ELEMNETO DA NOSSA LISTA
Node* minimum(List* list, int index) {
    Node* pointer = atPos(list, index);

    if(pointer != NULL) {
        Node* minNode = pointer;

        while(pointer != NULL) {
            if(pointer->data.id < minNode->data.id)
                minNode = pointer;
            pointer = pointer->next;
        }
        return minNode;
    }
    return NULL;
}

// RETORNA O MAIOR ELEMNETO DA NOSSA LISTA
Node* maximum(List* list, int index) {
    Node* pointer = atPos(list, index);

    if(pointer != NULL) {
        Node* maxNode = pointer;

        while(pointer != NULL) {
            if(pointer->data.id > maxNode->data.id)
                maxNode = pointer;
            pointer = pointer->next;
        }
        return maxNode;
    }
    return NULL;
}

// ORDERNA A LISTA EM ORDEM CRESCENTE
void incSort(List* list) {
    for (int  i = 0; i < list->size - 1; i++)
       xchgNodes(list, atPos(list, i), minimum(list, i));
}

// ORDERNA A LISTA EM ORDEM DECRESCENTE
void decSort(List *list) {
    for (int  i = 0; i < list->size - 1; i++)
       xchgNodes(list, atPos(list, i), maximum(list, i));
}
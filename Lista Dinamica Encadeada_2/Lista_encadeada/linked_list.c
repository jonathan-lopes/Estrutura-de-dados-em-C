#include <stdio.h>
#include <stdlib.h>

// CRIA UMA LISTA SIMPLES ENCADEADA
typedef struct ElementoDaLista_simples
{
	int dado;
	struct ElementoDaLista_simples* prox;
} lista;

// DECLARA O HEAD COMO SENDO DO TIPO DA LISTA
lista* head;

void inserirInicio(int numero);
void inserirFim(int numero);
void inserirMeio(int numero, int posicao);

int main()
{	
	int op = 0, numero, posicao;

	do
	{
		printf("\n\nDigite um valor inteiro para inserir na lista: ");
		scanf_s("%d", &numero); // LE UM VALOR PARA INSERIR E A OPERACAO DESEJADA

		printf("\n\n");

		printf("Operacao desejada: \n");
		printf("0 - para inserir no inicio da lista\n");
		printf("1 - para inserir no fim da lista\n");
		printf("2 - inserir no meio da lista\n");
		printf("Resposta: ");
		scanf_s("%d", &op);
		// ESCOLHE O QUE E A OPERACAO
		switch (op)
		{
		case 0:
			inserirInicio(numero);
			break;

		case 1:
			inserirFim(numero);
			break;

		case 2:
			printf("Digite a posicao: ");
			scanf_s("%d", &posicao);
			inserirMeio(numero, posicao);
			break;

		default:
			printf("Entrada invalida\n");
		}

	} while (op <= 2 && op >= 0);
	system("pause");
	return 0;
}

//FUNCAO QUE RECEBER COMO PARAMETRO O DADO A SER INSERIDO NO INICIO
void inserirInicio(int numero)
{
	// DECLARA UM NOVO NO DO TIPO REGISTRO
	lista* novoNo = (lista*)malloc(sizeof(lista));
		
	novoNo->dado = numero;

	if (head == NULL)
	{
		//SE HEAD ESTA VAZIO, A LISTA ESTA VAZIA
		//PORTANTO, NOVO ELEMNETO SERA O HEAD
		head = novoNo;
		head->prox = NULL;
	}
	else
	{
		// SE HEAD NAO ESTA VAZIO, EXISTEM DADOS NA LSITA
		// PORTANTO, O NOVO ELEMENTO APONTA PARA O HEAD
		novoNo->prox = head;
		// NOVO ELEMENTO VIARA O HEAD DA LISTA
		head = novoNo;
	}
}

// FUNCAO QUE RECEBE COMO PARAMETRO O DADO PARA SER INSERIDO NO FINAL
void inserirFim(int numero) 
{
	// DECLARA UM NOVO NO DO TIPO REGISTRO
	lista* novoNo = (lista*)malloc(sizeof(lista));

	// DECLARA UM NO PARA FAZER A VERREDURA DA ATE LOCALIZAR O FINAL
	lista* elementoVarredura;

	// INSERE NO NOVO (NO) O DADO RECEBIDO COMO PARAMETRO
	novoNo->dado = numero;

	// VERIFICA SE O HEAD ESTA VAZIO
	if (head == NULL)
	{
		// SE O HEAD ESTA VAZIO, A LISTA ESTA VAZIA
		// POTANTO, NOVO ELEMENTO SERA O HEAD
		head = novoNo;
		head->prox = NULL;
	}
	else
	{
		// SE O HEAD NAO ESTA VAZIO, EXISTEM ELEMENTOS NA LISTA
		// PORTANTO, PRECISAMOS ACHAR O FINAL DA LISTA (PONTEIRO NULO)
		elementoVarredura = head;

		// VARRE UM ELEMENTO POR VEZ PROCURANDO O PONTERIO NULO
		while (elementoVarredura->prox != NULL)
			elementoVarredura = elementoVarredura->prox;
		
		// APOS ENCONTRA O PONTERIO
		// FAZ O ULTIMO ELEMENTO DA LISTA APONTAR PARA O NOVO NO
		elementoVarredura->prox = novoNo;

		// NOVO NO AGORA TERA O PONTEIRO NULO (FINAL DA LISTA)
		novoNo->prox = NULL;
	}
}

// FUNCAO QUE RECEBE COMO PARAMETROO DADO A SER INSERIDO 
// E A POSICAO DA LISTA QUE ELE SERA INSERIDA
void inserirMeio(int numero, int posicao)
{
	// DECLARA UM NOVO NO DO TIPO REGISTRO
	lista* novoNo = (lista*)malloc(sizeof(lista));

	// DECLARA UM NOVO NO PARA FAZER A VARREDURA DA LISTA ATE LOCALIZAR O FINAL
	lista* elementoVarredura;

	// DECLARA UM NO AUXILIAR PARA AJUDAR NO ARMAZENAMENTO TEMPORARIO
	lista* elementoAuxiliar;

	// INSERE NOVO NO O DADO RECEBIDO COMO PARAMETRO
	novoNo->dado = numero;

	// VERIFICA SE O HEAD ESTA VAZIO
	if (posicao == 0)
	{
		// HEAD E A POSICAO 0, INSERE NELE
		head = novoNo;
		head->prox = NULL;
	}
	else
	{
		// QUALQUER OUTRA POSICAO, INSERE APOS HEAD
		elementoVarredura = head;

		// VARRE UM ELEMNETO POR FEZ ATE CHEGAR NO ELEMENTO DA POSICAO DESEJADA
		for (int i = 0; i < posicao; i++)
			elementoVarredura = elementoVarredura->prox;

		// APOS ENCONTRAR A POSICAO DESEJADA
		// FAZ UMA TROCA USANDO UM (NO) AUXILIAR
		elementoAuxiliar = elementoVarredura->prox;
		elementoVarredura->prox = novoNo;
		novoNo->prox = elementoAuxiliar;

		// NOVO NO AGORA TERA O PONTERIO NULO (FINAL DA LISTA)
		novoNo->prox = NULL;
	}
}
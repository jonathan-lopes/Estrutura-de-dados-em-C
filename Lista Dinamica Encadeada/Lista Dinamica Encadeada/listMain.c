#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncad.h"

int main()
{
    struct aluno a[4] = { {2,"Andre",9.5,7.8,8.5}, 
                          {4,"Ricardo",7.5,8.7,6.8}, 
                          {1,"Bianca",9.7,6.7,8.4}, 
                          {3,"Ana",5.7,6.1,7.4} };
    
    /*  "*li" é um ponteito para "elemento de estrutura *Lista"
        Logo "*li" é um ponteiro para ponteiro **
        **p consegue guardar outros ponteiro(como uma lista de ponteiro)
    */
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n", tamanho_lista(li));
   
    for (int i = 0; i < 4; i++)
        insere_lista_ordenada(li, a[i]);

    imprime_lista(li);
    printf("\n Tamanho: %d\n", tamanho_lista(li));
    printf("\n\n\n");

    for (int i = 0; i < 4; i++) {
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n", tamanho_lista(li));
    }

    for (int i = 0; i < 4; i++)
        insere_lista_ordenada(li, a[i]);
    imprime_lista(li);

    libera_lista(li);
    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadCirc.h" 

int main() {
    struct aluno a[4] = { {2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4} };
    Lista* head = cria_lista();
    printf("Tamanho: %d\n\n\n\n", tamanho_lista(head));

 
    for (int i = 0; i < 4; i++)
        insere_lista_inicio(head, a[i]);

    imprime_lista(head);
    printf("\n\n\n\n Tamanho: %d\n", tamanho_lista(head));

    for (int i = -1; i < 5; i++) {
        //remove_lista(li,i+1);
        if (!remove_lista(head, i + 1))
            printf("Erro!\n");
        imprime_lista(head);
        printf("\n\n======================\n\n");
    }
    for (int i = 0; i < 4; i++)
        insere_lista_ordenada(head, a[i]);

    imprime_lista(head);
    libera_lista(head);
    system("pause");
    return 0;
}



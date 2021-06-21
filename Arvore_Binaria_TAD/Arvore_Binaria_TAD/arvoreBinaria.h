typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_NO(NO* no);
void libera_ArvBin(ArvBin* raiz);
_Bool estaVazia_ArvBin(ArvBin* raiz);
int altura_ArvBin(ArvBin* raiz);
int totalNo_ArvBin(ArvBin* raiz);
void preOrdem_ArvBin(ArvBin* raiz);
void emOrdem_ArvBin(ArvBin* raiz);
void posOrdem_arvBin(ArvBin* raiz);
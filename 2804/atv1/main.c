#include "fila.h"


int main() {
    Fila *fi = cria_fila();

    if (fi == NULL) {
        printf("Erro de alocacao!");
        return 1;
    }

    insere_elemento(fi);
    insere_elemento(fi);
    insere_elemento(fi);
    
    remove_elemento_fila(fi);
    
    consulta_fila(fi);

    return 0;
}
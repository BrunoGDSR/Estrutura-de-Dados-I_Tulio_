#include "fila.h"

Fila* cria_fila() {
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void insere_elemento(Fila *fi) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL) return;

    printf("\nDigite o numero a ser inserido na fila: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;

    if (fi->inicio == NULL) {
        fi->inicio = novo;
        fi->fim = novo;
    } else {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    printf("\nNumero inserido na fila!");
    getch();
}

void consulta_fila(Fila *fi) {
    if (fi->inicio == NULL) {
        printf("\nFila Vazia!!");
    } else {
        Elemento *aux = fi->inicio; 
        while (aux != NULL) {
            printf("\n %d ", aux->num);
            aux = aux->prox;
        }
    }
    getch();
}

void remove_elemento_fila(Fila *fi) {
    if (fi->inicio == NULL) {
        printf("\nFila Vazia!!");
    } else {
        Elemento *aux = fi->inicio;
        printf("\n%d removido!", fi->inicio->num);
        fi->inicio = fi->inicio->prox;
        
        // Se a fila esvaziou, o fim também deve ser NULL
        if (fi->inicio == NULL) {
            fi->fim = NULL;
        }
        free(aux);
    }
    getch();
}
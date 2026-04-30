#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

void inicializarFila(Fila* f) {
    f->frente = NULL;
    f->tras = NULL;
}

void inserirCliente(Fila* f, int id, int tempo) {
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    if (novo == NULL) return;
    
    novo->id = id;
    novo->tempo = tempo;
    novo->proximo = NULL;
    
    if (f->tras == NULL) {
        f->frente = novo;
        f->tras = novo;
    } else {
        f->tras->proximo = novo;
        f->tras = novo;
    }
    printf("Cliente %d inserido.\n", id);
}

void atenderCliente(Fila* f, int* tempoTotal) {
    if (f->frente == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    
    Cliente* temp = f->frente;
    *tempoTotal += temp->tempo;
    
    printf("Atendendo cliente %d (%d min)\n", temp->id, temp->tempo);
    
    f->frente = f->frente->proximo;
    if (f->frente == NULL) {
        f->tras = NULL;
    }
    
    free(temp);
}

void exibirFila(Fila* f) {
    if (f->frente == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    
    Cliente* atual = f->frente;
    printf("Fila: ");
    while (atual != NULL) {
        printf("[%d|%dmin] ", atual->id, atual->tempo);
        atual = atual->proximo;
    }
    printf("\n");
}

void liberarFila(Fila* f) {
    Cliente* atual = f->frente;
    while (atual != NULL) {
        Cliente* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    f->frente = f->tras = NULL;
}
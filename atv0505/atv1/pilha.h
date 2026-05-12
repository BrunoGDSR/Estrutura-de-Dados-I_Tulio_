#ifndef PILHA_H
#define PILHA_H

typedef struct Elemento
{
    int num;
    struct Elemento *prox;
} Elemento;

typedef struct Pilha
{
    Elemento *topo;
} Pilha;

Pilha *cria_pilha();

void insere_elemento(Pilha *pi);

void consulta_pilha(Pilha *pi);

void remove_elemento_pilha(Pilha *pi);

void esvazia_pilha(Pilha *pi);

#endif
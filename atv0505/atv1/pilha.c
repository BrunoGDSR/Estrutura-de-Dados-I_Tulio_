#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Elemento *aux;

Pilha *cria_pilha()
{
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

    if (pi != NULL)
    {
        pi->topo = NULL;
    }

    return pi;
}

void insere_elemento(Pilha *pi)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));

    printf("\nDigite o numero: ");
    scanf("%d", &novo->num);

    novo->prox = pi->topo;

    pi->topo = novo;

    printf("\nNumero inserido!\n");
}

void consulta_pilha(Pilha *pi)
{
    if (pi->topo == NULL)
    {
        printf("\nPilha vazia!\n");
    }
    else
    {
        aux = pi->topo;

        while (aux != NULL)
        {
            printf("%d\n", aux->num);

            aux = aux->prox;
        }
    }
}

void remove_elemento_pilha(Pilha *pi)
{
    if (pi->topo == NULL)
    {
        printf("\nPilha vazia!\n");
    }
    else
    {
        aux = pi->topo;

        printf("\n%d removido!\n", aux->num);

        pi->topo = pi->topo->prox;

        free(aux);
    }
}

void esvazia_pilha(Pilha *pi)
{
    while (pi->topo != NULL)
    {
        aux = pi->topo;

        pi->topo = pi->topo->prox;

        free(aux);
    }

    printf("\nPilha esvaziada!\n");
}
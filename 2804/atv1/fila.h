#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Necessária para o getch()

/* Registro que representará cada elemento da fila */
struct Elemento {
    int num;
    struct Elemento *prox;
};
typedef struct Elemento Elemento;

/* Registro para controle da fila */
struct Fila {
    struct Elemento *inicio; 
    struct Elemento *fim;    
};
typedef struct Fila Fila;

/* Protótipos das funções */
Fila* cria_fila();
void insere_elemento(Fila *fi);
void consulta_fila(Fila *fi);
void remove_elemento_fila(Fila *fi);

#endif
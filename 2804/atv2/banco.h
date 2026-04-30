#ifndef BANCO_H
#define BANCO_H

typedef struct Cliente {
    int id;
    int tempo;
    struct Cliente* proximo;
} Cliente;

typedef struct {
    Cliente* frente;
    Cliente* tras;
} Fila;

void inicializarFila(Fila* f);
void inserirCliente(Fila* f, int id, int tempo);
void atenderCliente(Fila* f, int* tempoTotal);
void exibirFila(Fila* f);
void liberarFila(Fila* f);

#endif
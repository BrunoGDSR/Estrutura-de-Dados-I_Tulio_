#include <stdio.h>
#include <stdlib.h>

// Nó da lista
typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

// Estrutura da fila
typedef struct {
    Node* inicio;
    Node* fim;
    int tamanho;
} Fila;

// Criar fila
Fila* criarFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

// Verificar se está vazia
int estaVazia(Fila* f) {
    return f->inicio == NULL;
}

// Inserir com prioridade (ordem crescente)
void enqueuePrioridade(Fila* f, int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->valor = valor;
    novo->proximo = NULL;

    if (estaVazia(f) || valor < f->inicio->valor) {
        novo->proximo = f->inicio;
        f->inicio = novo;
        if (f->fim == NULL) f->fim = novo;
    } else {
        Node* atual = f->inicio;
        while (atual->proximo && atual->proximo->valor <= valor) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
        if (novo->proximo == NULL) f->fim = novo;
    }
    f->tamanho++;
}

// Remover (dequeue)
int dequeue(Fila* f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    Node* temp = f->inicio;
    int valor = temp->valor;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) f->fim = NULL;
    free(temp);
    f->tamanho--;
    return valor;
}

// Exibir elementos
void exibir(Fila* f) {
    Node* atual = f->inicio;
    printf("Fila: ");
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Inverter fila (recursivo)
void inverterFila(Fila* f) {
    if (estaVazia(f)) return;
    int valor = dequeue(f);
    inverterFila(f);
    enqueuePrioridade(f, valor); // mantém ordem de inserção
}

// Copiar fila
Fila* copiarFila(Fila* f) {
    Fila* copia = criarFila();
    Node* atual = f->inicio;
    while (atual) {
        enqueuePrioridade(copia, atual->valor);
        atual = atual->proximo;
    }
    return copia;
}

// Concatenar filas
Fila* concatenarFilas(Fila* f1, Fila* f2) {
    Fila* resultado = copiarFila(f1);
    Node* atual = f2->inicio;
    while (atual) {
        enqueuePrioridade(resultado, atual->valor);
        atual = atual->proximo;
    }
    return resultado;
}

// Teste da Atividade 2
int main() {
    Fila* fp = criarFila();
    enqueuePrioridade(fp, 50);
    enqueuePrioridade(fp, 10);
    enqueuePrioridade(fp, 30);
    exibir(fp);

    inverterFila(fp);
    exibir(fp);

    Fila* copia = copiarFila(fp);
    exibir(copia);

    Fila* f3 = concatenarFilas(fp, copia);
    exibir(f3);

    return 0;
}

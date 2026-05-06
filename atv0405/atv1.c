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

// Inserir (enqueue)
void enqueue(Fila* f, int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->valor = valor;
    novo->proximo = NULL;
    if (estaVazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
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

// Consultar primeiro elemento
int primeiro(Fila* f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->inicio->valor;
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

// Contar elementos
int contar(Fila* f) {
    return f->tamanho;
}

// Teste da Atividade 1
int main() {
    Fila* f = criarFila();
    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);
    exibir(f);

    printf("Primeiro: %d\n", primeiro(f));
    printf("Removido: %d\n", dequeue(f));
    exibir(f);
    printf("Quantidade: %d\n", contar(f));

    return 0;
}

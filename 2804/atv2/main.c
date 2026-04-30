#include <stdio.h>
#include "banco.h"

int main() {
    Fila banco;
    inicializarFila(&banco);
    int opcao, id, tempo, tempoAcumulado = 0;

    do {
        printf("\n1. Novo Cliente\n2. Atender\n3. Listar\n4. Tempo Total\n0. Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("ID: ");
                scanf("%d", &id);
                printf("Tempo: ");
                scanf("%d", &tempo);
                inserirCliente(&banco, id, tempo);
                break;
            case 2:
                atenderCliente(&banco, &tempoAcumulado);
                break;
            case 3:
                exibirFila(&banco);
                break;
            case 4:
                printf("Tempo total: %d min\n", tempoAcumulado);
                break;
        }
    } while (opcao != 0);

    liberarFila(&banco);
    return 0;
}
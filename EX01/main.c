#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "professor.h"
#include "produto.h"
#include "livro.h"
#include "cliente.h"
#include "funcionario.h"
#include "carro.h"
#include "conta.h"
#include "endereco.h"
#include "filme.h"
#include "aluno.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ler_string(char *buffer, int tamanho) {
    fgets(buffer, tamanho, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

void exercicio1() {
    Professor p;
    printf("\n--- Exercicio 1: Professor ---\n");
    printf("Digite o ID: ");
    scanf("%d", &p.id);
    limpar_buffer();
    printf("Digite o Nome: ");
    ler_string(p.nome, 100);
    printf("Digite o Salario: ");
    scanf("%f", &p.salario);

    printf("\nDados do Professor:\n");
    printf("ID: %d\n", p.id);
    printf("Nome: %s\n", p.nome);
    printf("Salario: %.2f\n", p.salario);
}

void exercicio2() {
    Produto p;
    printf("\n--- Exercicio 2: Produto ---\n");
    printf("Digite o Codigo: ");
    scanf("%d", &p.codigo);
    limpar_buffer();
    printf("Digite o Nome: ");
    ler_string(p.nome, 100);
    printf("Digite o Preco: ");
    scanf("%f", &p.preco);

    printf("\nDados do Produto:\n");
    printf("Codigo: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Preco: %.2f\n", p.preco);
}

void exercicio3() {
    Livro l;
    printf("\n--- Exercicio 3: Livro ---\n");
    limpar_buffer();
    printf("Digite o ISBN: ");
    ler_string(l.isbn, 20);
    printf("Digite o Titulo: ");
    ler_string(l.titulo, 100);
    printf("Digite o Autor: ");
    ler_string(l.autor, 100);

    printf("\nDados do Livro:\n");
    printf("ISBN: %s\n", l.isbn);
    printf("Titulo: %s\n", l.titulo);
    printf("Autor: %s\n", l.autor);
}

void exercicio4() {
    Cliente c;
    printf("\n--- Exercicio 4: Cliente ---\n");
    printf("Digite o ID: ");
    scanf("%d", &c.id);
    limpar_buffer();
    printf("Digite o Nome: ");
    ler_string(c.nome, 100);
    printf("Digite o Telefone: ");
    ler_string(c.telefone, 20);

    printf("\nDados do Cliente:\n");
    printf("ID: %d\n", c.id);
    printf("Nome: %s\n", c.nome);
    printf("Telefone: %s\n", c.telefone);
}

void exercicio5() {
    Funcionario f;
    printf("\n--- Exercicio 5: Funcionario ---\n");
    printf("Digite a Matricula: ");
    scanf("%d", &f.matricula);
    limpar_buffer();
    printf("Digite o Nome: ");
    ler_string(f.nome, 100);
    printf("Digite o Salario: ");
    scanf("%f", &f.salario);

    printf("\nDados do Funcionario:\n");
    printf("Matricula: %d\n", f.matricula);
    printf("Nome: %s\n", f.nome);
    printf("Salario: %.2f\n", f.salario);
}

void exercicio6() {
    Carro c;
    printf("\n--- Exercicio 6: Carro ---\n");
    limpar_buffer();
    printf("Digite a Placa: ");
    ler_string(c.placa, 10);
    printf("Digite o Modelo: ");
    ler_string(c.modelo, 50);
    printf("Digite o Ano: ");
    scanf("%d", &c.ano);

    printf("\nDados do Carro:\n");
    printf("Placa: %s\n", c.placa);
    printf("Modelo: %s\n", c.modelo);
    printf("Ano: %d\n", c.ano);
}

void exercicio7() {
    Conta c;
    printf("\n--- Exercicio 7: Conta Bancaria ---\n");
    printf("Digite o Numero: ");
    scanf("%d", &c.numero);
    limpar_buffer();
    printf("Digite o Titular: ");
    ler_string(c.titular, 100);
    printf("Digite o Saldo: ");
    scanf("%f", &c.saldo);

    printf("\nDados da Conta:\n");
    printf("Numero: %d\n", c.numero);
    printf("Titular: %s\n", c.titular);
    printf("Saldo: %.2f\n", c.saldo);
}

void exercicio8() {
    Endereco e;
    printf("\n--- Exercicio 8: Endereco ---\n");
    limpar_buffer();
    printf("Digite a Rua: ");
    ler_string(e.rua, 100);
    printf("Digite o Numero: ");
    scanf("%d", &e.numero);
    limpar_buffer();
    printf("Digite a Cidade: ");
    ler_string(e.cidade, 50);

    printf("\nDados do Endereco:\n");
    printf("Rua: %s\n", e.rua);
    printf("Numero: %d\n", e.numero);
    printf("Cidade: %s\n", e.cidade);
}

void exercicio9() {
    Filme f;
    printf("\n--- Exercicio 9: Filme ---\n");
    limpar_buffer();
    printf("Digite o Titulo: ");
    ler_string(f.titulo, 100);
    printf("Digite o Genero: ");
    ler_string(f.genero, 50);
    printf("Digite a Duracao (min): ");
    scanf("%d", &f.duracao);

    printf("\nDados do Filme:\n");
    printf("Titulo: %s\n", f.titulo);
    printf("Genero: %s\n", f.genero);
    printf("Duracao: %d min\n", f.duracao);
}

void exercicio10() {
    Aluno a;
    printf("\n--- Exercicio 10: Aluno ---\n");
    printf("Digite o ID: ");
    scanf("%d", &a.id);
    limpar_buffer();
    printf("Digite o Nome: ");
    ler_string(a.nome, 100);
    printf("Digite a Nota 1: ");
    scanf("%f", &a.nota1);
    printf("Digite a Nota 2: ");
    scanf("%f", &a.nota2);

    float media = (a.nota1 + a.nota2) / 2.0;

    printf("\nDados do Aluno:\n");
    printf("ID: %d\n", a.id);
    printf("Nome: %s\n", a.nome);
    printf("Media: %.2f\n", media);
}

int main() {
    int opcao;

    do {
        printf("\n===================================\n");
        printf("       MENU DE EXERCICIOS\n");
        printf("===================================\n");
        printf(" 1 - Professor\n");
        printf(" 2 - Produto\n");
        printf(" 3 - Livro\n");
        printf(" 4 - Cliente\n");
        printf(" 5 - Funcionario\n");
        printf(" 6 - Carro\n");
        printf(" 7 - Conta Bancaria\n");
        printf(" 8 - Endereco\n");
        printf(" 9 - Filme\n");
        printf("10 - Aluno (Media)\n");
        printf(" 0 - Sair\n");
        printf("===================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: exercicio1(); break;
            case 2: exercicio2(); break;
            case 3: exercicio3(); break;
            case 4: exercicio4(); break;
            case 5: exercicio5(); break;
            case 6: exercicio6(); break;
            case 7: exercicio7(); break;
            case 8: exercicio8(); break;
            case 9: exercicio9(); break;
            case 10: exercicio10(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

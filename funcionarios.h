#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[150];
    int clientesAtendidos;
    int tempoDeAtendimento;
} Funcionario;

typedef struct noFuncionario {
    Funcionario *funcionario;
    struct noFuncionario *prox;
} NoFuncionario;

typedef struct listaFuncionario {
    NoFuncionario *inicio;
    int contador;
} ListaFuncionario;

NoFuncionario *insereFuncionario(NoFuncionario *lista, Funcionario *funcionario);
void imprimeFuncionarios(ListaFuncionario *lista);
void liberaFuncionarios(ListaFuncionario *lista);
Funcionario *buscaFuncionario(ListaFuncionario *lista, int codigo);
Funcionario *leFuncionario(FILE *arquivo);
ListaFuncionario *leFuncionarios(char *nome_arquivo);

#endif
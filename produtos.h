#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[150];
    float preco;
    float tcompra;
    float tcaixa;
} Produto;

typedef struct noProduto {
    Produto *produto;
    struct noProduto *prox;
} NoProduto;

typedef struct listaProduto {
    NoProduto *inicio;
    int contador;
} ListaProduto;

NoProduto *insereProduto(NoProduto *lista, Produto *produto);
void imprimeProdutos(ListaProduto *lista);
void liberaProdutos(ListaProduto *lista);
Produto *buscaProduto(ListaProduto *lista, int codigo);
Produto *leProduto(FILE *arquivo);
ListaProduto *leProdutos(char *nome_arquivo);
ListaProduto *criarListaProdutos();

#endif
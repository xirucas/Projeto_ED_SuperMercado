#ifndef CLIENTES_H
#define CLIENTES_H

#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct cliente
{
    int codigo;
    char nome[150];
    int qtde_compras;
    int totalTempoCompra;
    int totalTempoCaixa;
    ListaProduto *lista_compras;
} Cliente;

typedef struct noCliente
{
    Cliente *cliente;
    struct noCliente *prox;
} NoCliente;

typedef struct ListaCliente
{
    NoCliente *inicio;
    int contador;
} ListaCliente;

NoCliente *insereCliente(NoCliente *lista, Cliente *cliente);
void imprimeClientes(ListaCliente *lista);
void liberaClientes(ListaCliente *lista);
Cliente *buscaCliente(ListaCliente *lista, int codigo);
Cliente *leCliente(FILE *arquivo, ListaProduto *listaProduto);
ListaCliente *leClientes(char *nome_arquivo, ListaProduto *listaProduto);
void realizaCompra(Cliente *cliente, NoProduto *produto);
Cliente *produtosAComprar(Cliente *cliente, ListaProduto *listaProduto);
int gerarCodigoProdutoRand();


#endif
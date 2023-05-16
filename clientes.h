#ifndef CLIENTES_H
#define CLIENTES_H

#define MIN_PRODUTOS 1
#define MAX_PRODUTOS 10

#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct cliente
{
    int codigo;
    char nome[150];
    int qtde_compras;
    float totalTempoCompra;
    float totalTempoCaixa;
    ListaProduto *lista_compras;
    int codigoCaixa;
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

Cliente *produtosAComprar(Cliente *cliente, ListaProduto *listaProduto);
int gerarCodigoProdutoRand();

ListaCliente *criarListaClientes();
Cliente *removerClientesDaFila(ListaCliente *fila);
void adicionarClienteFila(ListaCliente *fila, Cliente *cliente);
void removerClienteDaFila(ListaCliente *fila, Cliente *cliente);
void removerClienteFilaInicio(ListaCliente *fila);
bool isFilaVazia(ListaCliente *fila);

#endif
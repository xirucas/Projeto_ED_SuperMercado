#ifndef CAIXA_H
#define CAIXA_H 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "clientes.h"
#include "funcionarios.h"


typedef struct caixa{
    int codigoCaixa;
    Funcionario *funcionario;
    ListaCliente *filaClientes;
    float tempoNaCaixa;
    int clientesAtendidos;
    float tempoSemClientes;
    bool aberta;
}Caixa;

typedef struct noCaixa
{
    Caixa *caixa;
    struct noCaixa *prox;
}NoCaixa;

typedef struct listaCaixa
{
    NoCaixa *inicio;
    int contador;
}ListaCaixa;


Caixa *criaCaixa(int codigoCaixa, Funcionario *funcionario);
ListaCaixa *criarCaixas(int numCaixas, ListaFuncionario *listaFuncionario);
NoCaixa *adicionaCaixaLista(NoCaixa *lista,  Caixa *caixa);
void abrirCaixa(Caixa *caixa);
void fecharCaixa(Caixa *caixa, ListaCaixa *caixas, int numCaixas);
void mudarDeCaixa(Cliente *cliente, ListaCaixa *caixas, ListaCliente *filaAnterior);
void adicionaClienteNaCaixa(Caixa *caixa, Cliente *cliente);
void removerClienteFilaCaixaInicio(Caixa *caixa);
ListaCaixa *criarListaCaixas();
Caixa *buscaCaixa(ListaCaixa *listaCaixas,int codigoCaixa);
void imprimeCaixas(ListaCaixa *listaCaixas);
void liberarCaixas(ListaCaixa *listaCaixas);





#endif
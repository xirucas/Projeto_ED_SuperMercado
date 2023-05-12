#include <stdio.h>
#include <stdlib.h>
#include "produtos.c"
#include "clientes.c"
#include "funcionarios.c"
#include "caixas.c"
#include <time.h>

#define FICH_PRODUTOS "produtos.txt"
#define FICH_CLIENTES "clientes.txt"
#define FICH_FUNCIONARIOS "funcionarios.txt"
#define NUM_CAIXAS 10

void simulacao(ListaProduto *listaProdutos, ListaCliente *listaClientes, ListaFuncionario *listaFuncionarios, ListaCaixa *listaCaixas){

}

int main(void)
{
    srand(time(NULL));
    ListaProduto *listaProdutos = leProdutos(FICH_PRODUTOS);
    ListaCliente *listaClientes = leClientes(FICH_CLIENTES,listaProdutos);
    ListaFuncionario *listaFuncionarios = leFuncionarios(FICH_FUNCIONARIOS);
    ListaCaixa *listaCaixas = criarCaixas(NUM_CAIXAS,listaFuncionarios);
    printf("%d\n", listaCaixas->contador);
    Caixa* caixa = buscaCaixa(listaCaixas,4);
    imprimeFuncionarios(listaFuncionarios);
    printf("%i\n", caixa->codigoCaixa);
    printf("%s\n",caixa->funcionario->nome);
    imprimeCaixas(listaCaixas);


    
    liberaClientes(listaClientes);
    liberaProdutos(listaProdutos);
    liberaFuncionarios(listaFuncionarios);
    liberarCaixas(listaCaixa);
    printf("acabouu");

    return 0;
}

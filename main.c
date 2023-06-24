#include <stdio.h>
#include <stdlib.h>
#include "produtos.c"
#include "clientes.c"
#include "funcionarios.c"
#include "caixas.c"
#include "utils.c"
#include <time.h>

#define FICH_PRODUTOS "produtos.txt"
#define FICH_CLIENTES "clientes.txt"
#define FICH_FUNCIONARIOS "funcionarios.txt"
#define NUM_CAIXAS 10
#define HORA_ABERTURA "9:00:00"


int main(void)
{
    Relogio rolex;
    srand(time(NULL));
    ListaProduto *listaProdutos = leProdutos(FICH_PRODUTOS);
    ListaCliente *listaClientes = leClientes(FICH_CLIENTES,listaProdutos);
    ListaFuncionario *listaFuncionarios = leFuncionarios(FICH_FUNCIONARIOS);
    ListaCaixa *listaCaixas = criarCaixas(NUM_CAIXAS,listaFuncionarios);
    StartRelogio(&rolex,100,HORA_ABERTURA);
    time_t hora= VerTimeRelogio(&rolex);
    while (true)
    {   
       
    }
    


    
    liberaClientes(listaClientes);
    liberaProdutos(listaProdutos);
    liberaFuncionarios(listaFuncionarios);
    liberarCaixas(listaCaixas);
    printf("acabouu");

    return 0;
}

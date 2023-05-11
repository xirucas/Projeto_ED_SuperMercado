#include <stdio.h>
#include <stdlib.h>
#include "produtos.c"
#include "clientes.c"
#include <time.h>

void printClient(Cliente *cliente)
{
    printf("Cliente %d: %s", cliente->codigo, cliente->nome);
}

int main(void)
{
    srand(time(NULL));
    ListaProduto *listaProdutos = leProdutos("produtos.txt");
    Produto *sla = buscaProduto(listaProdutos, 51000);
    printf("%s\n", sla->nome);
    printf("%d", listaProdutos->contador);

    // teste de clientes
    printf("\n");
    ListaCliente *listaClientes = leClientes("clientes.txt", listaProdutos);

    // mostrar produtos que todos os clientes vao comprar
    printf("\n");
    NoCliente *atual = listaClientes->inicio;
    while (atual != NULL)
    {
        printClient(atual->cliente);
        printf("\n");
        imprimeProdutos(atual->cliente->lista_compras);
        printf("\n");
        atual = atual->prox;
    }


    liberaClientes(listaClientes);
    liberaProdutos(listaProdutos);

    return 0;
}

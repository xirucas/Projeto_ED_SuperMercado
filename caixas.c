#include "caixas.h"

Caixa *criarCaixa(int codigoCaixa, Funcionario *funcionario)
{
    Caixa *caixa = (Caixa *)malloc(sizeof(Caixa));
    if (caixa == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    caixa->codigoCaixa = codigoCaixa;
    caixa->funcionario = funcionario;
    caixa->filaClientes = criarListaClientes();
    caixa->tempoNaCaixa = 0;
    caixa->clientesAtendidos=0;
    caixa->aberta = false;
    return caixa;
}

ListaCaixa *criarCaixas(int numCaixas, ListaFuncionario *listaFuncionario)
{
    bool exist=false;
    ListaCaixa *listaCaixas = criarListaCaixas();
    for (int i = 1; i <= numCaixas; i++)
    {
        
        Funcionario *funcionario;
        while (exist==false)
        {
            funcionario = buscaFuncionario(listaFuncionario, gerarCodigoFuncionarioRand());
            if(funcionario!=NULL){
                exist=true;
            }
        }
        exist=false;
        Caixa *caixa = criarCaixa(i, funcionario);
        listaCaixas->inicio = adicionaCaixaLista(listaCaixas->inicio, caixa);
        listaCaixas->contador++;
    }

    return listaCaixas;
}

NoCaixa *adicionaCaixaLista(NoCaixa *lista, Caixa *caixa)
{
    NoCaixa *novoNo = (NoCaixa *)malloc(sizeof(NoCaixa));
    if (novoNo == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->caixa = caixa;
    novoNo->prox = NULL;
    if (lista == NULL)
    { // Caso a lista esteja vazia, o novo nó é o primeiro
        return novoNo;
    }
    else
    { // Caso contrário, percorremos a lista até encontrar o último nó
        NoCaixa *atual = lista;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novoNo; // Atribuímos o novo nó ao último nó encontrado
        return lista;
    }
}

void abrirCaixa(Caixa *caixa)
{
    caixa->aberta = true;
}

void fecharCaixa(Caixa *caixa, ListaCaixa *caixas, int numCaixas)
{
    if (!isFilaVazia(caixa->filaClientes))
    {
        while (!isFilaVazia(caixa->filaClientes))
        {
            Cliente *cliente = removerClientesDaFila(caixa->filaClientes);
            printf("Cliente %d saiu da fila do caixa %d\n", cliente->codigo, caixa->codigoCaixa);
            for (int i = 1; i <= numCaixas; i++)
            {
                NoCaixa *noCaixa;
                while (noCaixa!=NULL)
                {
                    if (noCaixa->caixa->aberta)
                    {
                        adicionaClienteNaCaixa(noCaixa->caixa, cliente);
                        printf("Cliente %d entrou na fila da caixa %d\n", cliente->codigo, noCaixa->caixa->codigoCaixa);
                        break;
                    }
                    noCaixa = noCaixa->prox;
                }
            }
        }
    }
    caixa->aberta = false;
}


void adicionaClienteNaCaixa(Caixa *caixa, Cliente *cliente)
{
    adicionarClienteFila(caixa->filaClientes, cliente);
}

void removerClienteFilaCaixaInicio(Caixa *caixa)
{
    removerClienteFilaInicio(caixa->filaClientes);
}


ListaCaixa *criarListaCaixas()
{
    ListaCaixa *lista = (ListaCaixa *)malloc(sizeof(ListaCaixa));
    if (lista == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    lista->inicio = NULL;
    lista->contador = 0;
    return lista;
}

Caixa *buscaCaixa(ListaCaixa *listaCaixas,int codigoCaixa){
    NoCaixa *noCaixa = listaCaixas->inicio;
    while (noCaixa != NULL)
    {
        if (noCaixa->caixa->codigoCaixa == codigoCaixa)
        {
            return noCaixa->caixa;
        }
        noCaixa = noCaixa->prox;
    }
    return NULL;
}

void imprimeCaixas(ListaCaixa *listaCaixas)
{
    NoCaixa *noCaixa = listaCaixas->inicio;
    while (noCaixa != NULL)
    {
        printf("Caixa %d\n", noCaixa->caixa->codigoCaixa);
        printf("Funcionario %d\n", noCaixa->caixa->funcionario->codigo);
        printf("Fila de clientes: ");
        imprimeClientes(noCaixa->caixa->filaClientes);
        printf("\n");
        noCaixa = noCaixa->prox;
    }
}

void liberarCaixas(ListaCaixa *listaCaixa){
    NoCaixa *atual = listaCaixa->inicio;
    while(atual!=NULL){
        NoCaixa *prox = atual->prox;
        liberaClientes(atual->caixa->filaClientes);
        free(atual);
        atual = prox;
    }
}


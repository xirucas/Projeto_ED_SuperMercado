#include "clientes.h"
#define MIN_PRODUTOS 1
#define MAX_PRODUTOS 10

NoCliente *insereCliente(NoCliente *lista, Cliente *cliente)
{
    NoCliente *novoNo = (NoCliente *) malloc(sizeof(NoCliente));
    if (novoNo == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->cliente = cliente;
    novoNo->prox = NULL;

    if (lista == NULL)
    { // Caso a lista esteja vazia, o novo nó é o primeiro
        return novoNo;
    }
    else
    { // Caso contrário, percorremos a lista até encontrar o último nó
        NoCliente *atual = lista;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novoNo; // Atribuímos o novo nó ao último nó encontrado

        return lista;
    }
}
void imprimeClientes(ListaCliente *lista)
{
    NoCliente *atual = lista->inicio;
    while (atual != NULL)
    {
        Cliente *cliente = atual->cliente;

        printf("Codigo: %d\tNome: %s\tQtde Compras: %d\n",
               atual->cliente->codigo, atual->cliente->nome, atual->cliente->qtde_compras);

        atual = atual->prox;
    }
}
void liberaClientes(ListaCliente *lista)
{
    NoCliente *atual = lista->inicio;
    while (atual != NULL)
    {
        NoCliente *prox = atual->prox;
        free(atual->cliente->lista_compras);
        free(atual->cliente);
        free(atual);
        atual = prox;
    }
    free(lista);
}
Cliente *buscaCliente(ListaCliente *lista, int codigo)
{
    NoCliente *atual = lista->inicio;
    while (atual != NULL)
    {
        if (atual->cliente->codigo == codigo)
        {
            return atual->cliente;
        }
        atual = atual->prox;
    }
    return NULL;
}


Cliente *produtosAComprar(Cliente *cliente, ListaProduto *listaProduto)
{

    cliente->qtde_compras = MIN_PRODUTOS + rand() % (MAX_PRODUTOS - MIN_PRODUTOS + 1);
    cliente->lista_compras = criarListaProdutos();

    int i;
    for (i = 0; i < cliente->qtde_compras; i++)
    {
        char exist = 'f';
        while (exist == 'f')
        {
            int codigo_produto = gerarCodigoProdutoRand();
            Produto *produto = buscaProduto(listaProduto, codigo_produto);
            if (produto != NULL)
            {
                cliente->lista_compras->inicio = insereProduto(cliente->lista_compras->inicio, produto);
                cliente->lista_compras->contador++;
                exist = 't';
            }
        }
    }
    return cliente;
}

Cliente *leCliente(FILE *arquivo, ListaProduto *listaProduto)
{
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    char ch = '\0';
    char aux[50] = {'\0'}; 

    int i = 0;
    while (ch != '\t' && ch != '\n' && ch != EOF && i < 50) 
    {
        ch = fgetc(arquivo);
        if (ch != '\t' && ch != '\n' && ch != EOF) 
        {
            aux[i] = ch;
            i++;
        }
    }
    cliente->codigo = atoi(aux);

    ch = '\0';
    i = 0;
    while (ch != '\t' && ch != EOF && ch != '\n' && i < 50) 
    {
        ch = fgetc(arquivo);
        if (ch != '\t' && ch != '\n' && ch != EOF) 
        {
            aux[i] = ch;
            i++;
        }
    }
    strcpy(cliente->nome, aux);
    cliente->qtde_compras=0;
    cliente->totalTempoCaixa=0;
    cliente->totalTempoCompra=0;
    cliente->lista_compras = NULL;
    
    cliente = produtosAComprar(cliente, listaProduto);
    
    return cliente;
}
ListaCliente *leClientes(char *nome_arquivo, ListaProduto *listaProduto)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro: nao foi possivel abrir o arquivo %s.\n", nome_arquivo);
        exit(EXIT_FAILURE);
    }

    ListaCliente *lista = (ListaCliente *)malloc(sizeof(ListaCliente));
    if (lista == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    lista->inicio = NULL;
    lista->contador = 0;
    while (!feof(arquivo))
    {
        Cliente *cliente = leCliente(arquivo, listaProduto);
        lista->inicio = insereCliente(lista->inicio, cliente);
        lista->contador++;
    }

    fclose(arquivo);
    return lista;
}

int gerarCodigoProdutoRand()
{
    int intervalos[][2] = {
        {10001, 14352},
        {20001, 22239},
        {30002, 32757},
        {40001, 41404},
        {50001, 51094}};
    int num_intervalos = sizeof(intervalos) / sizeof(intervalos[0]);
    int i, num_aleatorio;
    
    i = rand() % num_intervalos;
    num_aleatorio = rand() % (intervalos[i][1] - intervalos[i][0] + 1) + intervalos[i][0];
    return num_aleatorio;
}




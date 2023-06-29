#include "produtos.h"

NoProduto *insereProduto(NoProduto *lista, Produto *produto)
{
    NoProduto *novoNo = (NoProduto *)malloc(sizeof(NoProduto));
    if (novoNo == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->produto = produto;
    novoNo->prox = NULL;

    if (lista == NULL)
    { // Caso a lista esteja vazia, o novo nó é o primeiro
        return novoNo;
    }
    else
    { // Caso contrário, percorremos a lista até encontrar o último nó
        NoProduto *atual = lista;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novoNo; // Atribuímos o novo nó ao último nó encontrado
        return lista;
    }
}



void imprimeProdutos(ListaProduto *lista)
{
    NoProduto *atual = lista->inicio;
    while (atual != NULL)
    {
        Produto *produto = atual->produto;

        printf("Codigo: %d\tNome: %s\tPreco: %.2f\tTempo Compra: %.2f\tTempo Caixa: %.2f\n",
               atual->produto->codigo, atual->produto->nome, atual->produto->preco,
               atual->produto->tcompra, atual->produto->tcaixa);

        atual = atual->prox;
    }
}

void liberaProdutos(ListaProduto *lista)
{
    NoProduto *atual = lista->inicio;
    while (atual != NULL)
    {
        NoProduto *prox = atual->prox;
        free(atual->produto);
        free(atual);
        atual = prox;
    }
    free(lista);
}

Produto *buscaProduto(ListaProduto *lista, int codigo)
{
    NoProduto *atual = lista->inicio;
    while (atual != NULL)
    {
        Produto *produto = atual->produto;

        if (atual->produto->codigo == codigo)
        {
            return atual->produto;
        }
        atual = atual->prox;
    }
    return NULL;
}

Produto *leProduto(FILE *arquivo)
{
    Produto *produto = (Produto *)malloc(sizeof(Produto));
    if (produto == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(arquivo, "%d\t%[^\t]\t%f\t%f\t%f\n", &produto->codigo, produto->nome,
           &produto->preco, &produto->tcompra, &produto->tcaixa);
    return produto;
}

ListaProduto *leProdutos(char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro: nao foi possivel abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    Produto *produto;
    ListaProduto *lista = criarListaProdutos();

    while (!feof(arquivo))
    {
        produto = leProduto(arquivo);
        lista->inicio = insereProduto(lista->inicio, produto);
        lista->contador++;
    }

    fclose(arquivo);
    return lista;
}


ListaProduto *criarListaProdutos(){
    ListaProduto *lista = (ListaProduto *)malloc(sizeof(ListaProduto));
    if (lista == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    lista->inicio = NULL;
    lista->contador = 0;
    return lista;
}



NoProduto *copiaListaProdutos(NoProduto *lista)
{
    NoProduto *novaLista = NULL;
    NoProduto *ultimo = NULL;

    NoProduto *atual = lista;
    while (atual != NULL)
    {
        // Cria um novo nó e copia os valores do nó atual
        NoProduto *novoNo = (NoProduto *)malloc(sizeof(NoProduto));
        novoNo->produto = (Produto *)malloc(sizeof(Produto));
        novoNo->produto->codigo = atual->produto->codigo;
        strcpy(novoNo->produto->nome, atual->produto->nome);
        novoNo->produto->preco = atual->produto->preco;
        novoNo->produto->tcompra = atual->produto->tcompra;
        novoNo->produto->tcaixa = atual->produto->tcaixa;

        // Copie os outros campos do produto, se houver

        novoNo->prox = NULL;

        if (novaLista == NULL)
        {
            novaLista = novoNo;
            ultimo = novoNo;
        }
        else
        {
            ultimo->prox = novoNo;
            ultimo = novoNo;
        }

        atual = atual->prox;
    }

    return novaLista;
}

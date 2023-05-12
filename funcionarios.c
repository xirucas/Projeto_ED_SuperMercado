#include "funcionarios.h"

NoFuncionario *insereFuncionario(NoFuncionario *lista, Funcionario *funcionario){
    NoFuncionario *novoNo = (NoFuncionario*) malloc(sizeof(NoFuncionario));
    if(novoNo == NULL){
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->funcionario = funcionario;
    novoNo->prox = NULL;

    if (lista == NULL)
    { // Caso a lista esteja vazia, o novo nó é o primeiro
        return novoNo;
    }
    else
    { // Caso contrário, percorremos a lista até encontrar o último nó
        NoFuncionario *atual = lista;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novoNo; // Atribuímos o novo nó ao último nó encontrado
        return lista;
    }
}
void imprimeFuncionarios(ListaFuncionario *lista){
    NoFuncionario *atual = lista->inicio;
    while (atual != NULL)
    {
        Funcionario *funcionario = atual->funcionario;

        printf("Codigo: %d\tNome: %s\n",
               atual->funcionario->codigo, atual->funcionario->nome);

        atual = atual->prox;
    }
}
void liberaFuncionarios(ListaFuncionario *lista){
    NoFuncionario *atual = lista->inicio;
    while (atual != NULL)
    {
        NoFuncionario *prox = atual->prox;
        free(atual->funcionario);
        free(atual);
        atual = prox;
    }
    free(lista);
}
Funcionario *buscaFuncionario(ListaFuncionario *lista, int codigo){
    NoFuncionario *atual = lista->inicio;
    while (atual != NULL)
    {
        if (atual->funcionario->codigo == codigo)
        {
            return atual->funcionario;
        }
        atual = atual->prox;
    }
    return NULL;
}
Funcionario *leFuncionario(FILE *arquivo){
    Funcionario *funcionario = (Funcionario *) malloc(sizeof(Funcionario));
    if (funcionario == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(arquivo, "%d\n", &funcionario->codigo);
    fgets(funcionario->nome, 150, arquivo);
    funcionario->clientesAtendidos=0;
    funcionario->tempoDeAtendimento=0;
    return funcionario;
}
ListaFuncionario *leFuncionarios(char *nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro: nao foi possivel abrir o arquivo %s.\n", nome_arquivo);
        exit(EXIT_FAILURE);
    }
    ListaFuncionario *lista = (ListaFuncionario *) malloc(sizeof(ListaFuncionario));
    if (lista == NULL)
    {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    lista->inicio = NULL;
    lista->contador=0;
    while (!feof(arquivo))
    {
        Funcionario *funcionario = leFuncionario(arquivo);
        lista->inicio = insereFuncionario(lista->inicio, funcionario);
        lista->contador++;
    }
    fclose(arquivo);
    return lista;
}

int gerarCodigoFuncionarioRand(){
    return 1000 + rand() % (9999 - 1000 + 1);
}
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
void adicionarFuncionario(Funcionario **listaFuncionarios) {
    // Aloca memória para um novo funcionário
    Funcionario *novoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    // Solicita o código do funcionário
    printf("Insira o código do funcionário: ");
    scanf("%d", &(novoFuncionario->codigo));

    // Solicita o nome do funcionário
    printf("Insira o nome do funcionário: ");
    scanf("%s", novoFuncionario->nome);

    // Define valores iniciais para os demais campos
    novoFuncionario->clientesAtendidos = 0;
    novoFuncionario->tempoDeAtendimento = 0;
    novoFuncionario->aTrabalhar = false;
    

    adicionarFuncionarioFila(listaFuncionarios,novoFuncionario);

    printf("Funcionário adicionado com sucesso!\n");

    // Libera a memória alocada para o novo funcionário
    free(novoFuncionario);
}
void imprimeFuncionario(Funcionario* funcionario) {
    printf("Código: %d\n", funcionario->codigo);
    printf("Nome: %s\n", funcionario->nome);
    printf("Clientes atendidos: %d\n", funcionario->clientesAtendidos);
    printf("Tempo de atendimento: %s\n", funcionario->tempoDeAtendimento);
    printf("A Trabalhar: %d\n", funcionario->aTrabalhar);
}

    Funcionario* criarFuncionario(int codigo, const char* nome, int clientesAtendidos, int tempoDeAtendimento, bool aTrabalhar) {
    Funcionario* funcionario = malloc(sizeof(Funcionario));
    if (funcionario != NULL) {
        funcionario->codigo = codigo;
        strcpy(funcionario->nome, nome);
        funcionario->clientesAtendidos = clientesAtendidos;
        funcionario->tempoDeAtendimento = tempoDeAtendimento;
        funcionario->aTrabalhar = aTrabalhar;
    }
    return funcionario;
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
Funcionario* buscaFuncionarioPorNome(ListaFuncionario* lista, char* nome) {
    NoFuncionario* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->funcionario->nome, nome) == 0) {
            return atual->funcionario;
        }
        atual = atual->prox;
    }
    return NULL;
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
    funcionario->aTrabalhar = false;
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
void adicionarFuncionarioFila(ListaFuncionario *fila, Funcionario *Funcionario)
{
    fila->inicio = insereFuncionario(fila->inicio, Funcionario);
    fila->contador++;
}
void removerFuncionarioLista(Funcionario **lista, int codigo)
{
    Funcionario *atual = *lista;
    Funcionario *anterior = NULL;

    // Procurar o funcionário na lista
    while (atual != NULL && atual->codigo != codigo)
    {
        anterior = atual;
        atual = atual->prox;
    }

    // Verificar se o funcionário foi encontrado
    if (atual == NULL)
    {
        printf("Funcionário não encontrado.\n");
        return;
    }

    // Remover o funcionário da lista
    if (anterior == NULL)
    {
        // O funcionário a ser removido é o primeiro da lista
        *lista = atual->prox;
    }
    else
    {
        // O funcionário a ser removido não é o primeiro da lista
        anterior->prox = atual->prox;
    }

    // Liberar a memória alocada para o funcionário removido
    free(atual);
}
#include <stdio.h>
#include <stdlib.h>
#include "produtos.c"
#include "clientes.c"
#include "funcionarios.c"
#include "caixas.c"
#include <time.h>
#include <conio.h>
#include "utils.c"

#define FICH_PRODUTOS "produtos.txt"
#define FICH_CLIENTES "clientes.txt"
#define FICH_FUNCIONARIOS "funcionarios.txt"
#define FICH_CSV "historico.csv"
#define NUM_CAIXAS 10
#define TEMPO_MAX_SEM_CLIENTES 360 // 6 MINUTOS
#define CLIENTES_MAX_POR_CAIXA 8
#define HORA_ABERTURA "9:00:00"
#define HORA_DE_FECHO "22:00:00"

void Funcionarios(ListaFuncionario *listaFuncionarios)
{

    int menu_funcionarios;
    int id;
    char *funcionario;
    do
    {
        printf("----------Funcionarios----------\n");
        printf("2.......... Pesquisar por ID\n");
        printf("3.......... Mostrar Funcionarios\n");
        printf("4......... Adicionar Funcionarios\n");
        printf("5........... Remover Funcionarios\n");
        printf("6............ Voltar ao Menu\n");
        printf("------Escolha uma opção:----\n");
        scanf("%d", &menu_funcionarios);

        switch (menu_funcionarios)
        {
        case 1:
         printf("Você escolheu Pesquisar por ID de Funcionarios.\n");

            Funcionario *funcionarioencontradoid = buscaFuncionario(listaFuncionarios, id);

            if (funcionarioencontradoid != NULL)
            {
                printf("O Funcionario encontrado foi:\n");
                imprimeFuncionario(funcionarioencontradoid);
            }
            else
            {
                printf("Funcionario não encontrado.\n");
            }
            break;
        case 2:
            printf("Você escolheu Mostrar Funcionarios.\n");
            imprimeFuncionarios(listaFuncionarios);
            break;
        case 3:
            printf("Você escolheu Adicionar Funcionarios.\n");
            adicionarFuncionario(listaFuncionarios);
            break;
        case 4:
            printf("Você escolheu Remover Funcionarios.\n");
            printf("------Insira um id para remover o funcionario :----\n");
            scanf("%d", &id);
            removerFuncionarioLista(listaFuncionarios,id);
            break;
        case 5:
            printf("Voltando ao Menu Principal.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (menu_funcionarios != 5);
}
void Produtos(ListaProduto *listaProdutos)
{
    int menu_produtos;
    int id;
    char Produto;
    do
    {

        printf("----------Produtos----------\n");
        printf("1.......... Pesquisar por ID\n");
        printf("2.......... Mostrar Produtos\n");
        printf("3......... Adicionar Produtos\n");
        printf("4........... Remover Produtos\n");
        printf("5............ Voltar ao Menu\n");
        printf("------Escolha uma opção:----\n");
        scanf("%d", &menu_produtos);

        switch (menu_produtos)
        {
        case 1:
            break;
        case 2:
            printf("Você escolheu Mostrar Produtos.\n");
            imprimeProdutos(listaProdutos);
            break;
        case 3:
            printf("Você escolheu Adicionar Produtos.\n");
            // insereProduto();
            break;
        case 4:
            printf("Você escolheu Remover Produtos.\n");
            break;
        case 5:
            printf("Voltando ao Menu Principal.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (menu_produtos != 5);
}
void Clientes(ListaCliente *listaClientes)
{

    int menu_cliente;
    int id,codigo;
    char C;
    char nome;
    Cliente *cliente, *clienteEncontrado;

    do
    {
        printf("----------CLIENTES----------\n");
        printf("1.......... Pesquisar por ID\n");
        printf("2.......... Mostrar Clientes\n");
        printf("3......... Adicionar Cliente\n");
        printf("4........... Remover Cliente\n");
        printf("5............ Voltar ao Menu\n");
        printf("------Escolha uma opção:----\n");
        scanf("%d", &menu_cliente);

        switch (menu_cliente)
        {
        case 1:
            printf("Você escolheu Pesquisar por ID.\n");
            printf("------Insira um id:----\n");
            scanf("%d", &id);

            clienteEncontrado = buscaCliente(listaClientes, id);

            if (clienteEncontrado != NULL)
            {
                printf("O Cliente encontrado foi:\n");
                imprimeCliente(clienteEncontrado);
            }
            else
            {
                printf("Cliente não encontrado.\n");
            }
            break;
        case 2:
            printf("Você escolheu Mostrar Clientes.\n");
            imprimeClientes(listaClientes);
            break;
        case 3:
            printf("Você escolheu Adicionar Cliente.\n");
            char *novonome[150];
            printf("--Insira o nome do Cliente--\n");
            scanf("%s", &novonome);
            codigo = gerarCodigoClienteRand();
            cliente = criarCliente(codigo,novonome);
            adicionarClienteFila(listaClientes,cliente);
            printf("--O cliente foi adicionado --\n");
            break;
        case 4:
            printf("Você escolheu Remover Cliente.\n");
            printf("-Insira o id do cliente que quer remover:-\n");
            scanf("%d", &id);

            clienteEncontrado = buscaCliente(listaClientes, id);

            removerClienteDaFila(listaClientes,clienteEncontrado);
            printf("-Ocliente foi removido:-\n");
            break;
        case 5:
            printf("Voltando ao Menu Principal.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (menu_cliente != 5);
}

// caga nesta cena de simulaçao sou so testes ahah
void simulacao(ListaCliente *listaClientes, ListaCaixa *listaCaixas, ListaProduto *listaProdutos)
{
    Relogio rolex;
    ListaCliente *clientesEmLoja = criarListaClientes();
    char texto[100];
    int random;
    int clientesAtendidos = 0;
    float tempoMedioEspera = 0.0;
    int caixasAbertas = 0;
    char tecla;
    StartRelogio(&rolex, 120, HORA_ABERTURA);
    while (true)
    {
        if (kbhit())
        {
            tecla = getch();
            while (tecla != 'q' || tecla != 'Q')
            {
                StopRelogio(&rolex);
                tecla = '\0';
                menuSimulacao(rolex);
                while (tecla != 'q' && tecla != 'Q' && tecla != 'm' && tecla != 'M' && tecla != '1' && tecla != '2' && tecla != '3' && tecla != '4' && tecla != '0')
                {
                    if (kbhit)
                    {
                        tecla = getch();
                        if (tecla != 'q' && tecla != 'Q' && tecla != 'm' && tecla != 'M' && tecla != '1' && tecla != '2' && tecla != '3' && tecla != '4' && tecla != '0')
                        {
                            printf("\nOpção inválida.\nPrima M para voltar à simulação.");
                        }
                    }
                }
                if (tecla == '0')
                {
                    printf("Simulação terminada");
                    break;
                }
                else if (tecla == 'm' || tecla == 'M')
                {
                    ResumeRelogio(&rolex);
                    break;
                }
            }
        }

        time_t simulacao = VerTimeRelogio(&rolex);
        struct tm *tempo = localtime(&simulacao);

        random = rand() % 100;

        if (tempo->tm_hour > 19 && tempo->tm_min >= 30)
        {
            printf("A loja irá fechar mais nenhum cliente entra");
            random = 0;
        }

        if (tempo->tm_hour >= 21 && tempo->tm_min >= 00)
        {
            printf("Simulação terminada\n");
            break;
        }

        // abrir caixa se nao houver nenhuma aberta
        if (caixasAbertas == 0)
        {
            printf("Não há caixas abertas\n");
            Caixa *caixa = NULL;
            while (caixa == NULL)
            {

                // gerar codigo entre 1 e o numero maximo de caixas
                int codigoCaixa = rand() % (NUM_CAIXAS - 1 + 1) + 1;
                caixa = buscaCaixa(listaCaixas, codigoCaixa);
            }
            caixa->aberta = true;
            caixasAbertas++;
            printf("Caixa %d abriu\n", caixa->codigoCaixa);
            sprintf(texto, "Caixa %d abriu\n", caixa->codigoCaixa);
            escreverFicheiroCSV(FICH_CSV, texto);
        }

        // atualiza tempos de espera nas caixas sem clientes
        if (caixasAbertas < 1)
        {
            NoCaixa *noCaixa = listaCaixas->inicio;
            while (noCaixa != NULL)
            {
                Caixa *caixa = (Caixa *)noCaixa->caixa;
                if (caixa->aberta == true && caixa->filaClientes->contador <= 0)
                {
                    caixa->tempoSemClientes = caixa->tempoSemClientes + 120;
                }
                noCaixa = noCaixa->prox;
            }
        }

        printf("%d", random);

        // entrada de cliente na loja
        if (random < 65)
        {
            Cliente *cliente = NULL;
            while (cliente == NULL)
            {
                // alterar gerador do codigo
                int codigoCliente = gerarCodigoClienteRand();
                cliente = buscaCliente(listaClientes, codigoCliente);
                if (cliente != NULL)
                {
                    cliente = produtosAComprar(cliente, listaProdutos);
                }
            }

            clientesEmLoja->inicio = insereCliente(clientesEmLoja->inicio, cliente);
            clientesEmLoja->contador++;
            printf("Entrou na loja o cliente %d\n", cliente->codigo);
            sprintf(texto, "Entrou na loja o cliente %d\n", cliente->codigo);
            escreverFicheiroCSV(FICH_CSV, texto);
        }
        printf("eu\n");
        // verifica se ja passou o tempo do cliente comprar e adiciona o cliente em uma caixa
        if (clientesEmLoja->contador >= 1)
        {
            NoCliente *noCliente = clientesEmLoja->inicio;
            while (noCliente != NULL)
            {
                Cliente *cliente = noCliente->cliente;
                if (cliente->codigoCaixa == 0)
                {
                    if (cliente->tempoCompraRestante > 0)
                    {
                        cliente->tempoCompraRestante = -120;
                    }
                    else if (cliente->tempoCompraRestante <= 0)
                    {
                        Caixa *caixa = NULL;
                        while (caixa == NULL)
                        {
                            int codigoCaixa = rand() % (NUM_CAIXAS - 1 + 1) + 1;
                            caixa = buscaCaixa(listaCaixas, codigoCaixa);
                            if (caixa->aberta == true)
                            {
                                adicionaClienteNaCaixa(caixa, cliente);
                                printf("Cliente %d foi para a caixa %d\n", cliente->codigo, caixa->codigoCaixa);
                                sprintf(texto, "Cliente %d foi para a caixa %d\n", cliente->codigo, caixa->codigoCaixa);
                                escreverFicheiroCSV(FICH_CSV, texto);
                            }
                        }
                    }
                }
                noCliente = noCliente->prox;
            }
        }
        printf("tu\n");
        // verificar se alguma caixa fecha por falta de clientes
        if (caixasAbertas > 2)
        {
            NoCaixa *noCaixa = listaCaixas->inicio;
            while (noCaixa != NULL)
            {
                Caixa *caixa = noCaixa->caixa;
                if (caixa->aberta == true && caixa->filaClientes->inicio != NULL)
                {
                    caixa->tempoSemClientes = caixa->tempoSemClientes + 120;
                    if (caixa->tempoSemClientes >= TEMPO_MAX_SEM_CLIENTES)
                    {
                        caixa->aberta = false;
                        caixasAbertas--;
                        printf("Caixa %d fechou\n", caixa->codigoCaixa);
                        sprintf(texto, "Caixa %d fechou\n", caixa->codigoCaixa);
                        escreverFicheiroCSV(FICH_CSV, texto);
                    }
                }
                noCaixa = noCaixa->prox;
            }
        }
        printf("nois\n");
        // fazer atendimento dos clientes em cada caixa
        if (clientesEmLoja->contador >= 1)
        {
            NoCaixa *noCaixa = listaCaixas->inicio;
            while (noCaixa != NULL)
            {
                Caixa *caixa = noCaixa->caixa;
                if (caixa->aberta == true && caixa->filaClientes->inicio != NULL)
                {
                    Cliente *cliente = caixa->filaClientes->inicio->cliente;
                    if (cliente->tempoCaixaRestante > 0)
                    {
                        printf("Cliente %d a ser atendido na caixa %d\n", cliente->codigo, caixa->codigoCaixa);
                        sprintf(texto, "Cliente %d a ser atendido na caixa %d\n", cliente->codigo, caixa->codigoCaixa);
                        escreverFicheiroCSV(FICH_CSV, texto);
                        cliente->tempoCaixaRestante = -120;
                    }
                    else if (cliente->tempoCaixaRestante <= 0)
                    {
                        removerClienteFilaCaixaInicio(caixa);
                        printf("Cliente %d saiu da caixa %d\n", cliente->codigo, caixa->codigoCaixa);
                        sprintf(texto, "Cliente %d saiu da caixa %d\n", cliente->codigo, caixa->codigoCaixa);
                        escreverFicheiroCSV(FICH_CSV, texto);
                    }
                }
                noCaixa = noCaixa->prox;
            }
        }
        printf("bota\n");
        // verifica se é preciso abrir uma caixa
        if (caixasAbertas < NUM_CAIXAS)
        {
            NoCaixa *noCaixa = listaCaixas->inicio;
            while (noCaixa != NULL)
            {
                Caixa *caixa = noCaixa->caixa;
                if (caixa->aberta == true && caixa->filaClientes->contador >= CLIENTES_MAX_POR_CAIXA)
                {
                    Caixa *caixa2 = NULL;
                    while (caixa2 == NULL)
                    {
                        int codigoCaixa = rand() % (NUM_CAIXAS - 1 + 1) + 1;
                        caixa2 = buscaCaixa(listaCaixas, codigoCaixa);
                        if (caixa2->aberta == false)
                        {
                            caixa2->aberta = true;
                            caixasAbertas++;
                            printf("Caixa %d abriu\n", caixa2->codigoCaixa);
                            sprintf(texto, "Caixa %d abriu\n", caixa2->codigoCaixa);
                            escreverFicheiroCSV(FICH_CSV, texto);
                            break;
                        }
                        else
                        {
                            caixa2 = NULL;
                        }
                    }
                }
                noCaixa = noCaixa->prox;
            }
        }
        printf("nela\n");

        WaitSegundos(500);
    }
    liberaClientes(clientesEmLoja);
}
// e nisto tbm
void menuSimulacao(Relogio rolex)
{
    time_t hora = VerTimeRelogio(&rolex);
    printf("----------Menu:-------------\n");
    printf("HORA: %s\n", asctime(localtime(&hora)));
    printf("1 - Consultar cliente (Ainda não está implementado)");
    printf("\n2 - Consultar caixas (Ainda não está implementado)");
    printf("\n3 - Consultar estatísticas (Ainda não está implementado)");
    printf("\n0 - Sair da simulação");
    printf("\n\nPrima M para voltar à simulação.");
}

int main(void)
{
    srand(time(NULL));
    ListaProduto *listaProdutos = leProdutos(FICH_PRODUTOS);
    ListaCliente *listaClientes = leClientes(FICH_CLIENTES);
    ListaFuncionario *listaFuncionarios = leFuncionarios(FICH_FUNCIONARIOS);
    ListaCaixa *listaCaixas = criarCaixas(NUM_CAIXAS, listaFuncionarios);
    int menu;
    do
    {
        printf("----------Menu:-------------\n");
        printf("1.................. Produtos\n");
        printf("2.................. Clientes\n");
        printf("3.............. Funcionarios\n");
        printf("4.................... Caixas\n");
        printf("5......... Iniciar Simulacao\n");
        printf("6...................... Sair\n");
        printf("------Escolha uma opção:----\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Você escolheu a Produtos.\n");
            Produtos(listaProdutos);
            // Faça alguma coisa para a opção 1
            break;
        case 2:
            printf("Você escolheu a Clientes.\n");
            Clientes(listaClientes);
            break;
        case 3:
            printf("Você escolheu a Funcionarios.\n");
            Funcionarios(listaFuncionarios);
            break;
        case 4:
            printf("Você escolheu a Caixas.\n");
            printf("%d\n", listaCaixas->contador);
            Caixa *caixa = buscaCaixa(listaCaixas, 4);
            printf("%i\n", caixa->codigoCaixa);
            printf("%s\n", caixa->funcionario->nome);
            imprimeCaixas(listaCaixas);
            break;
        case 5:
            printf("Você escolheu a Iniciar Simulacao.\n");
            simulacao(listaClientes, listaCaixas, listaProdutos);
            break;
        case 6:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (menu != 6);

    liberaClientes(listaClientes);
    liberaProdutos(listaProdutos);
    liberaFuncionarios(listaFuncionarios);
    liberarCaixas(listaCaixas);
    printf("acabouu");

    return 0;
}

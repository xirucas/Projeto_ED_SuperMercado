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
#define NUM_CAIXAS 10
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
        printf("1........ Pesquisar por Nome\n");
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
            printf("Você escolheu Pesquisar por Nome de Funcionarios.\n");
            printf("------Insira o Nome do Funcionario:----\n");
            scanf("%s", &funcionario);
            Funcionario *funcionarioEncontrado = buscaFuncionarioPorNome(listaFuncionarios, funcionario);

            if (funcionarioEncontrado != NULL)
            {
                printf("Funcionário encontrado!\n");
                imprimeFuncionario(funcionarioEncontrado);
                // Faça algo com o funcionário encontrado
            }
            else
            {
                printf("Funcionário não encontrado.\n");
            }
            break;
        case 2:
            printf("Você escolheu Pesquisar por ID de Funcionarios.\n");
            printf("------Insira um id:----\n");
            scanf("%d", &id);

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
        case 3:
            printf("Você escolheu Mostrar Funcionarios.\n");
            imprimeFuncionarios(listaFuncionarios);
            break;
        case 4:
            printf("Você escolheu Adicionar Funcionarios.\n");
            printf("------Insira o Nome do Funcionario:----\n");
            scanf("%s", &funcionario);
            break;
        case 5:
            printf("Você escolheu Remover Funcionarios.\n");
            break;
        case 6:
            printf("Voltando ao Menu Principal.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (menu_funcionarios != 6);
}
void Produtos(ListaProduto *listaProdutos)
{
    int menu_produtos;
    int id;
    char Produto;
    do
    {

        printf("----------Produtos----------\n");
        printf("1........ Pesquisar por Nome\n");
        printf("2.......... Pesquisar por ID\n");
        printf("3.......... Mostrar Produtos\n");
        printf("4......... Adicionar Produtos\n");
        printf("5........... Remover Produtos\n");
        printf("6............ Voltar ao Menu\n");
        printf("------Escolha uma opção:----\n");
        scanf("%d", &menu_produtos);

        switch (menu_produtos)
        {
        case 1:
            printf("Você escolheu Pesquisar por Nome de Produto.\n");
            //   printf("------Insira o Nome do Produto:----\n");
            //   scanf("%d", &Produto);
            //
            //   Produto* ProdutoEncontrado = buscaProdutoNome(listaProdutos, Produto);
            //
            //   if (ProdutoEncontrado != NULL) {
            //       printf("O Produto encontrado foi:\n");
            //       imprimeProdutos(ProdutoEncontrado);
            //   } else {
            //       printf("Produto não encontrado.\n");
            //   }
            break;
        case 2:
            printf("Você escolheu Pesquisar por ID de Produto.\n");
            break;
        case 3:
            printf("Você escolheu Mostrar Produtos.\n");
            imprimeProdutos(listaProdutos);
            break;
        case 4:
            printf("Você escolheu Adicionar Produtos.\n");
            // insereProduto();
            break;
        case 5:
            printf("Você escolheu Remover Produtos.\n");
            break;
        case 6:
            printf("Voltando ao Menu Principal.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (menu_produtos != 6);
}
void Clientes(ListaCliente *listaClientes)
{

    int menu_cliente;
    int id;
    char C;
    char nome;

    do
    {
        printf("----------CLIENTES----------\n");
        printf("1........ Pesquisar por Nome\n");
        printf("2.......... Pesquisar por ID\n");
        printf("3.......... Mostrar Clientes\n");
        printf("4......... Adicionar Cliente\n");
        printf("5........... Remover Cliente\n");
        printf("6............ Voltar ao Menu\n");
        printf("------Escolha uma opção:----\n");
        scanf("%d", &menu_cliente);

        switch (menu_cliente)
        {
        case 1:
            printf("Você escolheu Pesquisar por Nome.\n");
            // Faça alguma coisa para a opção 1
            break;
        case 2:
            printf("Você escolheu Pesquisar por ID.\n");
            printf("------Insira um id:----\n");
            scanf("%d", &id);

            Cliente *clienteEncontrado = buscaCliente(listaClientes, id);

            if (clienteEncontrado != NULL)
            {
                printf("O Cliente encontrado foi:\n");
                imprimeCliente(clienteEncontrado);
            }
            else
            {
                printf("Cliente não encontrado.\n");
            }
            // Faça alguma coisa para a opção 2
            break;
        case 3:
            printf("Você escolheu Mostrar Clientes.\n");
            imprimeClientes(listaClientes);
            break;
        case 4:
            printf("Você escolheu Adicionar Cliente.\n");
            break;
        case 5:
            printf("Você escolheu Remover Cliente.\n");
            // Faça alguma coisa para a opção 3
            break;
        case 6:
            printf("Voltando ao Menu Principal.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (menu_cliente != 6);
}

//caga nesta cena de simulaçao sou so testes ahah
void simulacao(ListaCliente listaClientes, ListaCaixa listaCaixas, ListaFuncionario listaFuncionarios)
{
    Relogio rolex;
    char tecla;
    StartRelogio(&rolex,500,HORA_ABERTURA);
    while (true)
    {
        if (kbhit())
        {
            tecla = getch();
            while (tecla == 'q' || tecla == 'Q')
            {
                ch = '\0';
                menuSimulacao();
                while (ch != 'q' && ch != 'Q' && ch != 'm' && ch != 'M' && ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '0')
                {
                    if (kbhit)
                    {
                        ch = getch();
                        if (ch != 'q' && ch != 'Q' && ch != 'm' && ch != 'M' && ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '0')
                        {
                            printf("\nOpção inválida.\nPrima M para apresentar o menu.");
                        }
                    }
                }
                if (tecla == '0')
                {
                    printf("Simulação terminada");
                    break;
                }
                else if (ch == 'q' || ch == 'Q')
                {
                    printf("Vontando para a simulação");
                    break;
                }
                else if (ch == 'm' || ch == 'M')
                {
                    menuSimulacao();
                }
            }

            /*else if (tecla == 'c')
            {
                printf("Cliente entrou na loja\n");
                Cliente *cliente = criaClienteAleatorio(listaClientes);
                printf("Cliente %d entrou na loja\n", cliente->id);
                printf("Cliente %d está na fila\n", cliente->id);
                insereClienteFila(listaCaixas, cliente);
            }
            else if (tecla == 'f')
            {
                printf("Cliente saiu da loja\n");
                Cliente *cliente = removeClienteFila(listaCaixas);
                printf("Cliente %d saiu da loja\n", cliente->id);
                printf("Cliente %d está na fila\n", cliente->id);
            }
            else if (tecla == 'p')
            {
                printf("Cliente está a pagar\n");
                Cliente *cliente = removeClienteFila(listaCaixas);
                printf("Cliente %d está a pagar\n", cliente->id);
                printf("Cliente %d está na fila\n", cliente->id);
            }
            else if (tecla == 'a')
            {
                printf("Cliente está a ser atendido\n");
                Cliente *cliente = removeClienteFila(listaCaixas);
                printf("Cliente %d está a ser atendido\n", cliente->id);
                printf("Cliente %d está na fila\n", cliente->id);
            }
            else if (tecla == 't')
            {
                printf("Cliente está a terminar de ser atendido\n");
                Cliente *cliente = removeClienteFila(listaCaixas);
                printf("Cliente %d está a terminar de ser atendido\n", cliente->id);
                printf("Cliente %d está na fila\n", cliente->id);
            }
            else if (tecla == 's')
            {
                printf("Cliente saiu da loja\n");
                Cliente *cliente = removeClienteFila(listaCaixas);
                printf("Cliente %d saiu da loja\n", cliente->id);
                printf("Cliente %d está na fila\n", cliente->id);
            }
            else if (tecla == 'n')
            {
                printf("Cliente não entrou na loja\n");
                Cliente *cliente = removeClienteFila(listaCaixas);
                printf
        }*/
        }
    }
}
//e nisto tbm
void menuSimulacao()
{
}

int main(void)
{
    srand(time(NULL));
    ListaProduto *listaProdutos = leProdutos(FICH_PRODUTOS);
    ListaCliente *listaClientes = leClientes(FICH_CLIENTES, listaProdutos);
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
            printf("Você escolheu a Caixas.\n");
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
            // Faça alguma coisa para a opção 3
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

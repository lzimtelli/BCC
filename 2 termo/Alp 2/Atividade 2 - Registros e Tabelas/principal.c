#include <stdio.h>
#include <string.h>
#include "tabelaProdutos.h"
#include "tabelaVendas.h"

#define tamVetores 100 // escolhe quantas leituras vai fazer, coloquei 5 só para testar vetor cheio

int chamarMenu()
{
    int escolha;

    printf("\n");
    puts("Inclusao de produto..................[1]");
    puts("Alteracao de dados de um produto.....[2]");
    puts("Exclusao de produto(nao vendido).....[3]");
    puts("Pesquisa de produto pelo codigo......[4]");
    puts("Comprar produtos.....................[5]");
    puts("Apresentar todos os dados............[6]");
    puts("Apresentar balancete do estoque......[7]");
    puts("Apresentar estoque baixo.............[8]");
    puts("Inclusao de vendas...................[9]");
    puts("Apresentar vendas de um produto......[10]");
    puts("Apresentar vendas de uma data........[11]");
    puts("Totalizar vendas de um produto.......[12]");
    puts("Total arrecadado no mes..............[13]");
    puts("Sair.................................[14]");

    scanf("%d", &escolha);

    return escolha;
}

int main()
{
    int escolha, sair = 0, tlP = 0, tlV = 0, aux;
    Produtos listaProdutos[tamVetores];
    Datas listaDatas[tamVetores];

    while (sair != 1)
    {
        escolha = chamarMenu();

        switch (escolha)
        {

        case 1:
            if (tlP < tamVetores)
            {
                listaProdutos[tlP] = produtos_lerProduto(tlP);
                tlP++;
            }
            else
            {
                printf("\nTamanho maximo excedido");
            }
            break;

        case 2:
            produtos_alterarDados(listaProdutos, tlP);
            break;

        case 3:
            aux = 0;
            vendas_verificarVendas(listaDatas, tlV, listaProdutos, tlP, aux);
            vendas_excluirNaoVendidos(listaProdutos, tlP, aux);
            break;

        case 4:
            produtos_pesquisarCodigo(listaProdutos, tlP);
            break;

        case 5:
            produtos_comprarProdutos(listaProdutos, tlP);
            break;

        case 6:
            produtos_apresentarDados(listaProdutos, tlP);
            break;

        case 7:
            produtos_balancete(listaProdutos, tlP);
            break;

        case 8:
            produtos_estoqueBaixo(listaProdutos, tlP);
            break;

        case 9:
            if (tlV < tamVetores)
            {
                listaDatas[tlV] = vendas_inclusaoVendas(listaProdutos, tlV);
                tlV++;
            }
            else
            {
                printf("\nTamanho maximo excedido");
            }
            break;

        case 10:
            vendas_apresentarCodigo(listaDatas, listaProdutos, tlV, tlP);
            break;

        case 11:
            vendas_apresentarData(listaDatas, tlV);
            break;

        case 12:
            vendas_totalizarProdutos(listaDatas, tlV, listaProdutos, tlP);
            break;

        case 13:
            vendar_totalizarMes(listaDatas, tlV);
            break;

        case 14:
            puts("Voce escolheu sair!");
            sair = 1;
            break;

        default:
            printf("\nDigite uma opcao valida!");
            printf("\n");
            break;
        }
    }
}
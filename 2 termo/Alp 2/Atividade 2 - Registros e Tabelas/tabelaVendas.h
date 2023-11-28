#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
    int codigoProduto;
    int qntVendida;
    float valorVenda;
} Datas;

Datas vendas_inclusaoVendas(Produtos listaProdutos[], int tl2) // 9
{
    Datas d;
    int j = -1, concluidoCod = 0, concluidoQnt = 0, tempEstoque;

    printf("\nDigite o Dia: ");
    scanf("%d", &d.dia);

    printf("\nDigite o Mes: ");
    scanf("%d", &d.mes);

    printf("\nDigite o Ano: ");
    scanf("%d", &d.ano);

    do // valida codigo
    {

        printf("\nDigite o Codigo do Produto a ser vendido: ");
        scanf("%d", &d.codigoProduto);

        for (int i = 0; i < tl2 + 1; i++) // procura no vetor o codigo
        {
            if (d.codigoProduto == listaProdutos[i].codigo) // se achar, salva
            {
                d.codigoProduto = listaProdutos[i].codigo;
                j = i;
            }
        }

        if (j != -1) // se achou o codigo, mostra
        {
            printf("\n------------------");
            printf("\nNome: %s", listaProdutos[j].nome);
            printf("\nRS %.2f", listaProdutos[j].preco);
            printf("\nQnt: %d", listaProdutos[j].estoque);
            printf("\n------------------");
            printf("\n");

            do // valida quantidade
            {
                printf("\nDigite a quantidade a ser vendida: ");
                scanf(" %d", &d.qntVendida);

                if (d.qntVendida == 0)
                {
                    printf("\nImpossivel venda de 0 produtos!\n");
                }
                else if (d.qntVendida > listaProdutos[j].estoque)
                {
                    printf("\nQuantidade em estoque insuficiente para esta venda!\n");
                }
                else
                {
                    tempEstoque = listaProdutos[j].estoque;
                    listaProdutos[j].estoque -= d.qntVendida;
                    d.valorVenda = d.qntVendida * listaProdutos[j].preco;
                    concluidoQnt = 1;
                }

            } while (concluidoQnt != 1);
        }

        if (j != -1) // tabela visual
        {
            printf("\n------------------");
            printf("\nData: %02d/%02d/%04d\n", d.dia, d.mes, d.ano);
            printf("\nCodigo: %d", d.codigoProduto);
            printf("\nQuantidade Vendida: %d", d.qntVendida);
            printf("\nValor da venda: RS %.2f", d.valorVenda);
            printf("\n------------------");
            printf("\n");

            printf("\n------------------");
            printf("\nAnterior");
            printf("\nNome: %s", listaProdutos[j].nome);
            printf("\nRS %.2f", listaProdutos[j].preco);
            printf("\nQnt: %d", tempEstoque);
            printf("\n------------------");
            printf("\n");

            printf("\n------------------");
            printf("\nAtual");
            printf("\nNome: %s", listaProdutos[j].nome);
            printf("\nRS %.2f", listaProdutos[j].preco);
            printf("\nQnt: %d", listaProdutos[j].estoque);
            printf("\n------------------");
            printf("\n");
            concluidoCod = 1;
        }

        else
        {
            printf("\nCodigo de produto nao encontrado!\n");
        }

    } while (concluidoCod != 1);
    return d;
}

void vendas_apresentarData(Datas listaVendas[], int tlV) // 11
{
    Datas d;
    float soma = 0;

    printf("\nDigite o Dia: ");
    scanf("%d", &d.dia);

    printf("\nDigite o Mes: ");
    scanf("%d", &d.mes);

    printf("\nDigite o Ano: ");
    scanf("%d", &d.ano);

    for (int i = 0; i < tlV; i++)
    {
        if (d.dia == listaVendas[i].dia && d.mes == listaVendas[i].mes && d.ano == listaVendas[i].ano)
        {
            printf("\n------------------");
            printf("\nData: %02d/%02d/%04d\n", listaVendas[i].dia, listaVendas[i].mes, listaVendas[i].ano);
            printf("\nCodigo: %d", listaVendas[i].codigoProduto);
            printf("\nQuantidade Vendida: %d", listaVendas[i].qntVendida);
            printf("\nValor venda: RS %.2f", listaVendas[i].valorVenda);
            printf("\n------------------");
            printf("\n");
            soma = soma + listaVendas[i].valorVenda;
        }
        else
        {
            printf("\nDigite uma data valida!");
        }
    }
    printf("\nTotal: RS %.2f\n", soma);
}

void vendas_apresentarCodigo(Datas listaVendas[], Produtos listaProdutos[], int tlV, int tlP) // 10
{
    int j = -1, busca, cod = -1;
    float soma = 0;

    printf("\nDigite o codigo a ser pesquisado: ");
    scanf("%d", &busca);

    for (int i = 0; i < tlP; i++)
    {
        if (busca == listaProdutos[i].codigo)
        {
            cod = i;

            if (cod != -1)
            {
                printf("\n------------------");
                printf("\nNome: %s", listaProdutos[cod].nome);
                printf("\nRS %.2f", listaProdutos[cod].preco);
                printf("\nQnt: %d", listaProdutos[cod].estoque);
                printf("\n------------------");
                printf("\n");
            }
        }
    }

    if (cod == -1)
    {
        printf("\nDigite um codigo valido");
    }

    for (int i = 0; i < tlV + 1; i++)
    {
        if (busca == listaVendas[i].codigoProduto)
        {
            j = i;

            printf("\n------------------");
            printf("\nData: %02d/%02d/%04d\n", listaVendas[j].dia, listaVendas[j].mes, listaVendas[j].ano);
            printf("\nQuantidade Vendida: %d", listaVendas[j].qntVendida);
            printf("\nValor da Venda: RS %.2f", listaVendas[j].valorVenda);
            printf("\n------------------");
            printf("\n");
            soma += listaVendas[j].valorVenda;
        }
    }

    printf("\nTotal: RS %.2f\n", soma);
}

void vendas_totalizarProdutos(Datas listaVendas[], int tlV, Produtos listaProdutos[], int tlP)
{
    for (int i = 0; i < tlP; i++)
    {
        int codigoProduto = listaProdutos[i].codigo;
        int totalVendido = 0;

        for (int j = 0; j < tlV + 1; j++)
        {
            if (codigoProduto == listaVendas[j].codigoProduto)
            {
                totalVendido += listaVendas[j].qntVendida;
            }
        }

        printf("\n------------------");
        printf("\nNome: %s", listaProdutos[i].nome);
        printf("\nCodigo: %d", codigoProduto);
        printf("\nQuantidade Vendida: %d", totalVendido);
        printf("\n------------------");
        printf("\n");
    }
}

void vendar_totalizarMes(Datas listaVendas[], int tlV)
{ // 13
    int mes;
    float total = 0;

    printf("\nDigite o mes: ");
    scanf("%d", &mes);

    for (int i = 0; i < tlV + 1; i++)
    {
        if (mes == listaVendas[i].mes)
        {
            total = total + listaVendas[i].valorVenda;
            printf("\n------------------");
            printf("\nData: %02d/%02d/%04d\n", listaVendas[i].dia, listaVendas[i].mes, listaVendas[i].ano);
            printf("\nCodigo: %d", listaVendas[i].codigoProduto);
            printf("\nQuantidade Vendida: %d", listaVendas[i].qntVendida);
            printf("\nValor venda: RS %.2f", listaVendas[i].valorVenda);
            printf("\n------------------");
            printf("\n");
        }
    }
    printf("\nTotal arrecadado no mes: RS %.2f\n", total);
}

void vendas_verificarVendas(Datas listaVendas[], int tlV, Produtos listaProdutos[], int tlP, int aux)
{
    int buscaCodigo = -1, j = -1;

    printf("\nDigite o codigo a ser buscado: ");
    scanf("%d", &buscaCodigo);

    for (int i = 0; i < tlP; i++)
    {
        if (buscaCodigo == listaProdutos[i].codigo)
        {
            j = listaProdutos[i].codigo;
        }
    }

    if (j == -1)
    {
        printf("\nCodigo nao encontrado!");
    } 
    else
    {
        for(int i = 0; i < tlV + 1; i++){
            if(j == listaVendas[i].codigoProduto){
                if(listaVendas[i].qntVendida != 0){
                    aux = i;
                    printf("\nIncapaz de excluir um produto ja vendido!\n");
                }
            }
        }
    }
}

void vendas_excluirNaoVendidos(Produtos listaProdutos[], int tlP, int aux)
{
    for(int i = aux; aux < tlP - 1; i++){
        listaProdutos[i] = listaProdutos[i+1];
    }
}
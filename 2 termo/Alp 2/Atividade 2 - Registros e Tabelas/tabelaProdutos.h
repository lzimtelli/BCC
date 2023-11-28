#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[100];
    float preco;
    int estoque;
} Produtos;

Produtos produtos_lerProduto() //1
{
    Produtos p;

    printf("\nDigite o Codigo: ");
    scanf(" %d", &p.codigo);

    printf("\nDigite o nome do item: ");
    fflush(stdin);
    fgets(p.nome, 99, stdin);
    p.nome[strlen(p.nome) - 1] = '\0';

    printf("\nDigite o preco: ");
    scanf(" %f", &p.preco);

    printf("\nDigite a Quantidade: ");
    scanf(" %d", &p.estoque);

    printf("\nProduto registrado!\n");

    return p;
}

void produtos_alterarDados(Produtos listaProdutos[], int tl) //2
{
    int busca, j = -1, sair = 0, escolha;
    char tempNome[100];
    float tempPreco;
    int tempEstoque;
    printf("\nDigite o codigo a ser buscado: ");
    scanf("%d", &busca);

    for (int i = 0; i < tl; i++) //TROCAR MENOR IGUAL
    {
        if (busca == listaProdutos[i].codigo)
        {
            j = i;
        }
    }

    if (j != -1)
    {
        printf("\n------------------");
        printf("\nNome: %s", listaProdutos[j].nome);
        printf("\nRS %.2f", listaProdutos[j].preco);
        printf("\nQnt: %d", listaProdutos[j].estoque);
        printf("\n------------------");
        printf("\n");

        while (sair != 1)
        {
            printf("\nEscolha o dado a ser alterado: ");
            printf("\n");
            puts("Nome do produto...........[1]");
            puts("Preco do produto..........[2]");
            puts("Quantidade do produto.....[3]");
            puts("Nao alterar...............[4]");
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1: // alterar nome
                strcpy(tempNome, listaProdutos[j].nome);
                printf("\nDigite o novo nome: ");
                fflush(stdin);
                fgets(listaProdutos[j].nome, 99, stdin);
                listaProdutos[j].nome[strlen(listaProdutos[j].nome) - 1] = '\0';

                printf("\n------------------");
                printf("\nAnterior");
                printf("\nNome: %s", tempNome);
                printf("\nRS %.2f", listaProdutos[j].preco);
                printf("\nQnt: %d", listaProdutos[j].estoque);
                printf("\n------------------");
                printf("\n");

                printf("\n------------------");
                printf("\nAtual");
                printf("\nNome: %s", listaProdutos[j].nome);
                printf("\nRS %.2f", listaProdutos[j].preco);
                printf("\nQnt: %d", listaProdutos[j].estoque);
                printf("\n------------------");
                printf("\n");
                break;

            case 2: // alterar preco
                tempPreco = listaProdutos[j].preco;
                printf("\nDigite o novo preco: ");
                scanf("%f", &listaProdutos[j].preco);

                printf("\n------------------");
                printf("\nAnterior");
                printf("\nNome: %s", listaProdutos[j].nome);
                printf("\nRS %.2f", tempPreco);
                printf("\nQnt: %d", listaProdutos[j].estoque);
                printf("\n------------------");
                printf("\n");

                printf("\n------------------");
                printf("\nAtual");
                printf("\nNome: %s", listaProdutos[j].nome);
                printf("\nRS %.2f", listaProdutos[j].preco);
                printf("\nQnt: %d", listaProdutos[j].estoque);
                printf("\n------------------");
                printf("\n");
                break;

            case 3: // alterar quantidade
                tempEstoque = listaProdutos[j].estoque;
                printf("\nDigite a nova quantidade: ");
                scanf("%d", &listaProdutos[j].estoque);

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
                break;

            case 4:
                sair = 1;
                printf("\n------------------");
                printf("\nNome: %s", listaProdutos[j].nome);
                printf("\nRS %.2f", listaProdutos[j].preco);
                printf("\nQnt: %d", listaProdutos[j].estoque);
                printf("\n------------------");
                printf("\n");

                j = 0;
                break;

            default:
                printf("\nDigite uma opcao valida!");
                break;
            }
        }
    }
    else
    {
        printf("\nCodigo nao encontrado\n");
    }
}

void produtos_pesquisarCodigo(Produtos listaProdutos[], int tl) //4
{
    int busca, j = -1;
    printf("\nDigite o codigo a ser buscado: ");
    scanf("%d", &busca);

    for (int i = 0; i < tl; i++)
    {
        if (busca == listaProdutos[i].codigo)
        {
            j = i;
        }
    }

    if (j != -1)
    {
        printf("\n------------------");
        printf("\nNome: %s", listaProdutos[j].nome);
        printf("\nRS %.2f", listaProdutos[j].preco);
        printf("\nQnt: %d", listaProdutos[j].estoque);
        printf("\n------------------");
        printf("\n");
    }
    else
    {
        printf("\nCodigo nao encontrado\n");
    }
}

void produtos_comprarProdutos(Produtos listaProdutos[], int tl) //5
{
    int busca, j = -1, compra, tempEstoque;

    printf("\nDigite o codigo a ser buscado: ");
    scanf("%d", &busca);

    for (int i = 0; i < tl; i++)
    {
        if (busca == listaProdutos[i].codigo)
        {
            j = i;
        }
    }

    if (j != -1)
    {
        printf("\n------------------");
        printf("\nNome: %s", listaProdutos[j].nome);
        printf("\nRS %.2f", listaProdutos[j].preco);
        printf("\nQnt: %d", listaProdutos[j].estoque);
        printf("\n------------------");
        printf("\n");
    }

    if (j != -1)
    {
        tempEstoque = listaProdutos[j].estoque;

        printf("\nDigite a quantidade a ser comprada: ");
        scanf("%d", &compra);

        listaProdutos[j].estoque = listaProdutos[j].estoque + compra;

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
    }
    else
    {
        printf("\nCodigo nao encontrado\n");
    }
}

void produtos_estoqueBaixo(Produtos listaProdutos[], int tl) //8
{
    for (int j = 0; j < tl; j++)
    {
        if (listaProdutos[j].estoque < 5)
        {
            printf("\n------------------");
            printf("\nCodigo: %d", listaProdutos[j].codigo);
            printf("\nNome: %s", listaProdutos[j].nome);
            printf("\nRS %.2f", listaProdutos[j].preco);
            printf("\nQnt: %d", listaProdutos[j].estoque);
            printf("\n------------------");
            printf("\n");
        }
    }
}

void produtos_apresentarDados(Produtos listaProdutos[], int tl) //6
{
    for (int j = 0; j < tl; j++)
    {
        printf("\n------------------");
        printf("\nCodigo: %d", listaProdutos[j].codigo);
        printf("\nNome: %s", listaProdutos[j].nome);
        printf("\nRS %.2f", listaProdutos[j].preco);
        printf("\nQnt: %d", listaProdutos[j].estoque);
        printf("\n------------------");
        printf("\n");
    }
}

void produtos_balancete(Produtos listaProdutos[], int tl) //7
{
    int j = 0;
    float aux = 0;

    for (j = 0; j < tl; j++)
    {
        float balancete = 0;
        balancete = listaProdutos[j].estoque * listaProdutos[j].preco;
        printf("\n------------------");
        printf("\nCodigo: %d", listaProdutos[j].codigo);
        printf("\nNome: %s", listaProdutos[j].nome);
        printf("\nRS %.2f", listaProdutos[j].preco);
        printf("\nQnt: %d", listaProdutos[j].estoque);
        printf("\nBalancete: RS %.2f", balancete);
        printf("\n------------------");
        printf("\n");
        aux = aux + balancete;
    }
    printf("\nTotal do estoque: RS %.2f\n", aux);
}
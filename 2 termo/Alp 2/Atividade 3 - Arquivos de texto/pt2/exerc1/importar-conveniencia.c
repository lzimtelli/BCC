#include <stdio.h>
#include <string.h>

typedef struct
{
    int CodigoProduto;
    char NomeProduto[50];
    int EstoqueProduto;
    float PrecoProduto;
} Produtos;

int lerQuantidade(FILE *s)
{
    int QntProdutos;
    fscanf(s, "%d\n", &QntProdutos);

    return (QntProdutos);
}

Produtos lerProdutos(FILE *s)
{
    Produtos p;

    fscanf(s, "%d\n", &p.CodigoProduto);
    fgets(p.NomeProduto, 50, s);
    if (p.NomeProduto[strlen(p.NomeProduto) - 1] == '\n')
    {
        p.NomeProduto[strlen(p.NomeProduto) - 1] = '\0';
    }
    fscanf(s, "%d %f\n", &p.EstoqueProduto, &p.PrecoProduto);

    return(p);
}

void apresentarImportacao(int tl, Produtos VetorProdutos[]){
    printf("\n==================================================\n"); // 50
        for (int i = 0; i < tl; i++)
        {
            printf("\nCodigo do produto: %d", VetorProdutos[i].CodigoProduto);
            printf("\nNome do produto: %s", VetorProdutos[i].NomeProduto);
            printf("\nEstoque do produto: %d", VetorProdutos[i].EstoqueProduto);
            printf("\nValor do produto: RS: %.2f", VetorProdutos[i].PrecoProduto);
            printf("\n");
        }
        printf("\n==================================================\n"); // 50
}

int main()
{
    FILE *s;
    int QntProdutos, tl = 0;
    Produtos VetorProdutos[100];

    s = fopen("..\\produtos-exerc1.txt", "r");

    if (s == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
    }
    else
    {
        QntProdutos = lerQuantidade(s);

        for (int i = 0; i < QntProdutos; i++)
        {
            VetorProdutos[i] = lerProdutos(s);
            tl++;
        }

        apresentarImportacao(tl, VetorProdutos);

        fclose(s);
    }
}
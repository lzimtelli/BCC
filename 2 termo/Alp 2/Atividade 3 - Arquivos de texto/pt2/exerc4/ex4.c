#include <stdio.h>
#define TAM 50

typedef struct
{
    char NomeProduto[50];
    int QuantidadeProduto;
    float PrecoProduto;
} Produtos;

typedef struct
{
    int NumeroFiscal;
    char NomeCliente[50];
    char CpfCliente[50];
    int QuantidadeItens;
} NotaFiscal;

NotaFiscal LerDadosCliente(FILE *origem)
{
    NotaFiscal nf;
    fscanf(origem, "%d\n", &nf.NumeroFiscal);
    fscanf(origem, "%s %[^\n]", nf.CpfCliente, nf.NomeCliente);
    fscanf(origem, "%d\n", &nf.QuantidadeItens);

    return nf;
}

void CriarDestino(NotaFiscal nf, Produtos VetorProdutos[], int tl, int totalvendidos, float precototal, FILE *destino)
{
    fprintf(destino, "Nota fiscal de Venda - nr.: %d", nf.NumeroFiscal);
    fprintf(destino, "\n================================================================");
    fprintf(destino, "\nCliente: %s", nf.NomeCliente);
    fprintf(destino, "\nCPF: %s", nf.CpfCliente);
    fprintf(destino, "\n================================================================");
    fprintf(destino, "\nProdutos:");
    fprintf(destino, "\nSeq Nome                                   Qte    Preço    Total");
    fprintf(destino, "\n----------------------------------------------------------------");
    for (int i = 0; i < tl; i++)
    {
        fprintf(destino, "\n%03d %-40s %-5d %-7.2f %.2f", i + 1, VetorProdutos[i].NomeProduto, VetorProdutos[i].QuantidadeProduto, VetorProdutos[i].PrecoProduto, VetorProdutos[i].QuantidadeProduto * VetorProdutos[i].PrecoProduto);
    }
    fprintf(destino, "\n================================================================");
    fprintf(destino, "\nQuantidade de itens vendidos ...: %d", tl);
    fprintf(destino, "\nQuantidade total de produtos ...: %d", totalvendidos);
    fprintf(destino, "\nValor total da venda............: R$ %.2f", precototal);
    fprintf(destino, "\n================================================================");

    printf("\n Arquivo criado!\n");
}

Produtos LerProdutos(FILE *origem, int *TotalVendidos, float *PrecoTotal){
    Produtos p;

    fscanf(origem, "%[^\n]", p.NomeProduto);
    fscanf(origem, "%d %f\n", &p.QuantidadeProduto, &p.PrecoProduto);
    *TotalVendidos = *TotalVendidos + p.QuantidadeProduto;
    *PrecoTotal = *PrecoTotal + (p.PrecoProduto * p.QuantidadeProduto);

    return(p);
}

int main()
{
    FILE *origem, *destino;
    NotaFiscal nf;
    Produtos VetorProdutos[TAM];

    int tl = 0, TotalVendidos = 0, erro = 0;
    float PrecoTotal = 0;

    origem = fopen("..\\notafiscal-origem.txt", "r");

    if (origem == NULL)
    {
        printf("\n Erro ao abrir o arquivo!\n");
        erro = 1;
    }
    else
    {
        nf = LerDadosCliente(origem);

        for (int i = 0; i < nf.QuantidadeItens; i++)
        {
            VetorProdutos[i] = LerProdutos(origem, &TotalVendidos, &PrecoTotal);
            tl++;
        }
    }

    fclose(origem);

    destino = fopen("..\\notafiscal-destino.txt", "w");

    if (destino == NULL || erro == 1)
    {
        printf("\n Erro ao criar arquivo!");
    }
    else
    {
        CriarDestino(nf, VetorProdutos, tl, TotalVendidos, PrecoTotal, destino);
    }
}
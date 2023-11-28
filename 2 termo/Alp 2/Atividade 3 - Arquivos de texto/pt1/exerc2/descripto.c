#include <stdio.h>
#include <string.h>

int lerTexto(FILE *entrada, char texto[])
{
    int i = 0;
    while (!feof(entrada))
    {
        texto[i] = fgetc(entrada);
        i++;
    }
    return(i);
}

void subtrairASCI(int tamanhoTexto, char texto[], FILE *saida)
{
    int j = 0;
    while (j < tamanhoTexto - 1)
    {
        fputc(texto[j] - 1, saida);
        j++;
    }
}

int main()
{
    FILE *entrada, *saida;
    int tamanhoTexto = 0;
    char texto[100];

    entrada = fopen("..\\texto_saida.txt", "r");

    if (entrada == NULL)
    {
        printf("\nErro ao abrir o arquivo 1!");
    }
    else
    {
        tamanhoTexto = lerTexto(entrada, texto);
    }

    fclose(entrada);

    saida = fopen("..\\texto_saida.txt", "w");

    if (saida == NULL)
    {
        printf("\n\n Erro ao abrir o arquivo 2!\n");
    }
    else
    {
        subtrairASCI(tamanhoTexto, texto, saida);

        printf("\n Arquivo descriptografado\n");
    }

    fclose(saida);
}
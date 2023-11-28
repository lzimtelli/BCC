#include <stdio.h>
#include <stdlib.h>

void apresentar(char classe[], FILE *destino, int n)
{
    if (n > 0)
    {
        fprintf(destino, "%s\n", classe);
    }
}

void extrairClasses(FILE *arquivo, FILE *destino)
{
    char classe[50];
    char c;
    int n = 0;

    while ((c = fgetc(arquivo)) != EOF)
    {
        if (c == '<')
        {
            n = 0;
            while ((c = fgetc(arquivo)) != '>' && c != EOF && c != ' ')
            {
                if (c != ' ')
                {
                    classe[n++] = c;
                }
            }
            classe[n] = '\0';
            apresentar(classe, destino, n);
        }
    }
}

void verificarArquivo(FILE *arquivo_html)
{
    FILE *destino;
    if (arquivo_html == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    else
    {
        destino = fopen("..\\Saida.txt", "w");
        extrairClasses(arquivo_html, destino);
        fclose(arquivo_html);
        fclose(destino);
        printf("\n Arquivo Criado! \n");
    }
}

int main()
{
    FILE *arquivo_html;

    arquivo_html = fopen("..\\teste.html", "r");
    verificarArquivo(arquivo_html);

    return 0;
}

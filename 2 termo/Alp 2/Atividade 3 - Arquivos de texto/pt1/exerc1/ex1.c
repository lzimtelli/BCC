#include<stdio.h>
#include<string.h>
#include<ctype.h>

void lercaracteres(FILE *texto, int *linha, int *espaco, int *letras_num, int *caracteres) 
{
    char caractere;
    while((caractere = fgetc(texto)) != EOF) 
    {
        (*caracteres)++;

        if (caractere == '\n') 
        {
            (*linha)++;
        } 
        else if (caractere == ' ') 
        {
            (*espaco)++;
        } 
        else if (isalnum(caractere)) 
        {
            (*letras_num)++;
        }
    }
}

void quantidades(int linha, int espaco, int letras_num, int caracteres)
{
    printf("Quantidade de linhas...: %d\n", linha);
    printf("Quantidade de espacos em branco...: %d\n", espaco);
    printf("Quantidade de letras e numeros...: %d\n", letras_num);
    printf("Quantidade total de caracteres...: %d\n", caracteres);

}

int main() 
{
    FILE *texto;
    int linha = 1, espaco = 0, letras_num = 0, caracteres = 0;
    texto = fopen("..\\Arquivo.txt", "r");

    if(texto == NULL) 
    {
        printf("Nenhum arquivo encontrado!!\n");
        return 1;
    }
    else
    {
    lercaracteres(texto, &linha, &espaco, &letras_num, &caracteres);
    }
    fclose(texto);
    quantidades(linha, espaco, letras_num, caracteres);

    return 0;
}

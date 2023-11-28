#include<stdio.h>
#include<string.h>

void Definir(FILE *destino, int y)
{
    switch (y)
            {
                case 1:
                    fputs(" (elemento)\n", destino);
                    break;
                case 2:
                    fputs(" (classe)\n", destino);
                    break;
                case 3:
                    fputs(" (ID)\n", destino);
                    break;        
                    
                default:
                    break;
            }
}

void ler(FILE *origem, FILE *destino,char caracter)
{
    int t = 0, y = 1;
    while(caracter != EOF)
    {
        if(caracter == '{')
        {
            t = 1;

            Definir(destino, y);
        }
        else if(caracter == '}')
        {
            t = 0;
        }
        else if(t == 0 && caracter != '\n' && caracter != ' ')
        {
            if(caracter == '.')
            {
                y = 2;
            }
            else if(caracter == '#')
            {
                y = 3;
            }
            fputc(caracter, destino);
        }
        caracter = fgetc(origem);
    }

}

void verificarDestino(FILE *origem, FILE *destino)
{
    char caracter;
    if(destino == NULL)
    {
        printf("Arquivo nao encontrado!!\n");
    }
    else
    {
        caracter = fgetc(origem);
        ler(origem, destino, caracter);
        printf("Arquivo Criado!");
    }
}    

void verificarOrigiem(FILE *origem, FILE *destino){
    if(origem == NULL)
    {
        printf("Arquivo nao encontrado!!\n");
    }
    else
    {
        destino = fopen("..\\Saida.txt", "w");
        verificarDestino(origem, destino);
        fclose(destino);
    }
}

void main()
{
    FILE *origem, *destino;

    origem = fopen("..\\css.css", "r");
    verificarOrigiem(origem, destino);
    
    fclose(origem);
}
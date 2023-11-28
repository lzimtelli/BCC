#include <stdio.h>

int main()
{
    int positivos, negativos, cache, saida = 1;

    do
    {
        printf("\n Digite um numero(ou 0 para sair): ");
        scanf("%d", &cache);

        if (cache > 0)
            positivos++;
        else if (cache < 0)
            negativos++;
        else if(cache == 0)
            saida = 0;

    } while (saida != 0);
    
    printf("\n Quantidade de numeros positivos: %d", positivos);
    printf("\n Quantidade de numeros negativos: %d\n", negativos);
}
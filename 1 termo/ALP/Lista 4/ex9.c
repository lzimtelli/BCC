#include <stdio.h>

int main(){
    /*fibonacci = 1, 1, 2, 3, 5, 8, 13, 21, 34*/

    int i, n, n1 = 0, n2 = 1, saida;

    printf(" Tamanho da repeticao de fibonnachi: ");
    scanf("%d", &n);

    n = n - 1; //subtrai um numero na repeticao do for por conta do primeiro 1 de fibonnachi

    for(i = 0; i < n; i++){
        if(i==0)
            printf("1 "); //primeiro numero da sequencia
        saida = n1 + n2;
        n1 = n2;
        n2 = saida;

        printf("%d ", saida);
    }
}
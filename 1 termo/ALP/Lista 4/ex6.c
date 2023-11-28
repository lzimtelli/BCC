#include <stdio.h>

int main(){
    int i, mult=1;

    printf(" Digite um numero para calcular o seu fatorial: ");
    scanf("%d", &i);

    for(i>0;i>0;i--){
        mult = mult * i;
    }
    printf(" Resultado do fatorial: %d\n", mult);
}
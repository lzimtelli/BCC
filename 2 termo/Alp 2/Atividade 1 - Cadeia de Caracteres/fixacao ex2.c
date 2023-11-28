#include <stdio.h>

void lerProdutos(float valores[]){
    for(int i = 0; i < 5; i++){
        printf("\n Digite o valor do item: ");
        scanf("%f", &valores[i]);
    }
    printf("\n");
}

void apresentarCupom(float valores[]){
    printf("\n Cupom da compra:");
    for (int i = 0; i < 5; i++){
        printf("\n Item %d - Valor: RS %.2f", i+1, valores[i]);
    }
}

float valorCompra(float valores[]){
    float total = 0;
    for (int i = 0; i < 5; i++){
        total = total + valores[i];
    }
    return(total);
}

float maiorValor(float valores[]){
    float maior = 0;
    for (int i = 0; i < 5; i++){
        if(valores[i] > maior){
            maior = valores[i];
        }
    }
    return(maior);
}

int menorValor(float valores[]){
    float menor = valores[0];
    int tl = 0;
    for(int i = 1; i < 5; i++){
        if(valores[i] < menor){
            menor = valores[i];
            tl = i+1;
        }
    }
    return(tl);
}


int main(){
    float valores[5];
    lerProdutos(valores);
    printf("--------------------------------------------------------------------");
    apresentarCupom(valores);
    printf("\n--------------------------------------------------------------------");
    printf("\n Valor total da compra: RS %.2f", valorCompra(valores));
    printf("\n Valor do produto mais caro: RS %.2f", maiorValor(valores));
    printf("\n Codigo do produto mais barato: %d", menorValor(valores));
    printf("\n--------------------------------------------------------------------\n");
}
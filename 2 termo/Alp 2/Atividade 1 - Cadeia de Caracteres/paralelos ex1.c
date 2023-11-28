#include <stdio.h>
#define tam 5

void lerCompras(float valores[], int quantidade[]){
    int item = 1;
    for (int i = 0; i < tam; i++){
        printf("\n Digite o valor do item %d: ", item);
        scanf("%f", &valores[i]);
        printf("\n Digite a quantidade a comprar: ");
        scanf("%d", &quantidade[i]);
        item++;
    }
}

void apresentarCupom(float valores[], int quantidade[]){
    float total = 0;
    int itens = 0;
    printf("\n-----------------------------------------------------------------------------------");
    for (int i = 0; i < tam; i++){
        float valor = 0;
        valor = quantidade[i] * valores[i];
        printf("\n Codigo do Produto: %d - Valor Unitario: RS %.2f - Quantidade de itens: %d - Total: RS %.2f", i+1, valores[i], quantidade[i], valor);
        total = total + valor;
        itens = itens + quantidade[i];
    }
    printf("\n Valor total: RS %.2f - Quantidade de Itens: %d", total, itens);
    printf("\n-----------------------------------------------------------------------------------\n");
}
void buscarValor(float valores[], int quantidade[]){
    float busca;
    printf("\n Digite o valor para a busca: RS ");
    scanf("%f", &busca);
    for (int i = 0; i < tam; i++){
        if(valores[i] > busca){
            printf("\n Codigo do Produto: %d - Valor Unitario: RS %.2f - Quantidade de itens: %d", i+1, valores[i], quantidade[i]);
        }
    }
    printf("\n");
}

void buscarCodigo(float valores[], int quantidade[]){
    int busca;
    printf("\n Digite o codigo para a busca: ");
    scanf("%d", &busca);
    printf("\n Codigo do Produto: %d - Valor Unitario: RS %.2f - Quantidade de itens: %d - Total: %.2f\n", busca, valores[busca-1], quantidade[busca-1], valores[busca-1]*quantidade[busca-1]);
}

int main(){
    float valores[tam];
    int quantidade[tam], opcao, saida = 0;
    lerCompras(valores, quantidade);
    do{
        printf("\n Digite a opcao:\n 1 - Apresentar Cupom\n 2 - Procurar Valores superiores a\n 3 - Procurar Codigo\n 4 - Saida\n ");
        scanf("%d", &opcao);
        switch (opcao)
        {

        case 1:
            apresentarCupom(valores, quantidade);
            break;

        case 2:
            buscarValor(valores, quantidade);
            break;

        case 3:
            buscarCodigo(valores, quantidade);
            break;

        case 4:
            printf("\n Voce optou por sair\n");
            saida = 1;
            break;
        
        default:
            break;
        }
    } while(saida == 0);
}
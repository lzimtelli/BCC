#include <stdio.h>
#include <ctype.h>

int main(){
    int pessoas, i, contagem = 0, mulher;
    float altura, maior = 0, menor = 10, x, media = 0, mediaF = 0, percentual;
    char sexo;

    printf(" Digite a quantidade de pessoas: ");
    scanf("%d", &pessoas);
    
    for(i = 1; i <= pessoas; i++){
        printf("\n Digite o sexo da pessoa %d(M ou F): ", i);
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = toupper(sexo);
        printf(" Digite a altura da pessoa %d: ", i);
        scanf("%f", &altura);

        x = altura;

        if(x>maior)
            maior = x;
        if(x<menor)
            menor = x;
        
        if(sexo == 'M'){
            contagem++;
        }
        else if(sexo == 'F'){
            mediaF = mediaF + altura;
            mulher++;
        }
        
        media = media + altura;
    }

    media = (float) media/pessoas;
    mediaF = mediaF / mulher;
    percentual = (float) contagem/pessoas * 100;

    printf("\n Maior altura = %.2f\n", maior);
    printf(" Menor menor = %.2f\n", menor);
    printf(" Media de altura = %.2f\n", media);
    printf(" Media de altura das mulheres = %.2f\n", mediaF);
    printf(" Percentual de homens = %.2f\n", percentual);
}
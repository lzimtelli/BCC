#include <stdio.h>

void LerAlunos(int alunos[]){
    int disciplina = 1;
    for(int i = 0; i <8; i++){
        printf("\n Digite a quantidade de alunos inscritos na disciplina %d: ", disciplina);
        scanf("%d", &alunos[i]);
        if(alunos[i] >= 40)
            printf(" Lotada\n");
        else
            printf(" Ha Vagas\n");
        disciplina++;
    }
}

int calcularMedia(int alunos[]){
    float media;
    for(int i = 0; i < 8; i++){
       media = media + alunos[i];
    }
    return media/8;
}

int somarMatriculas(int alunos[]){
    int soma = 0;
    for(int i = 0; i < 8; i++){
        soma = soma + alunos[i];
    }
    return(soma);
}

int main(){
    int alunos[8];
    LerAlunos(alunos);
    printf("\n Media das matriculas nas disciplinas: %d", calcularMedia(alunos));
    printf("\n Total de matriculas: %d\n", somarMatriculas(alunos));
}
#include <stdio.h>
#define tam 50

int lerEmail(char email[]){
    printf("Digite seu email: ");
    fgets(email, 50, stdin);

    int i = 0;

    while(email[i] != '\0'){
        i++;
    }
    i--;
    return(i);
}

int apresentarNome(char email[]){
    int i = 0, cont = 0;
    printf("Nome: ");
    while(email[i] != '@'){
        printf("%c", email[i]);
        i++;
        cont++;
    }
    return(cont);
}

void apresentarServidor(char email[]){
    int t = 0;
    for (int j = 0; j < tam; j++){
        if(email[j] == '@'){
            t = j;
        }
    }

    printf("Servidor: ");
    while (email[t] != '\0'){
        printf("%c", email[t+1]);
        t++;
    } 
}

void verificar(char email[]){
    int arroba = 0, ponto = 0, i = 0, espaco = 0;
    while(email[i] != '\0'){
        if(email[i] == '@')
            arroba = 1;
        else if(email[i] == '.')
            ponto = 1;
        else if(email[i] == ' ')
            espaco = 1;
        i++;
    }
    if(arroba == 1 && ponto == 1 && espaco == 0)
        printf("Email validado");
    else
        printf("Email incorreto");
}

void separarEmail(char email[], char nome[], char servidor[]){
    int i = 0;
    while(email[i] != '@'){
        nome[i] = email[i];
        i++;
    }

    int t = 0, k = 0;
    for (int j = 0; j < tam; j++){
        if(email[j] == '@'){
            t = j;
        }
    }

    while (email[t] != '\0'){
        servidor[k] = email[t+1];
        t++;
        k++;
    }
}

void verificarBr(char email[], int tamanhoEmail){
    if(email[tamanhoEmail-1] == 'r' && email[tamanhoEmail-2] == 'b')
        printf("Dominio Brasileiro");
    else
        printf("Email nao e brasileiro");
}

int main(){
    char email[tam];
    int tamanhoNome, tamanhoEmail;

    tamanhoEmail = lerEmail(email);
    printf("\n");
    tamanhoNome = apresentarNome(email);
    printf("\n");
    printf("\n");
    apresentarServidor(email);

    char nome[tamanhoNome], servidor[tam];

    separarEmail(email, nome, servidor);
    printf("\n");
    verificar(email);
    printf("\n");
    printf("\n");
    verificarBr(email, tamanhoEmail);
    printf("\n");
}
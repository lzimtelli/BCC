#include <stdio.h>
#include <ctype.h>
#define tam 100

void lerNome(char nome[]){
    printf("Digite seu nome: ");
    fgets(nome, 100, stdin);
}

int contarLetras(char nome[]){
    int contagem = 0, i = 0;

    while (nome[i] != '\n'){
        if(nome[i] != ' '){
            contagem++;
        }
        i++;
    }
    
    return(contagem);
}

void apresentarNome(char nome[], int quantidade){
    for (int i = 0; i < quantidade; i++){
        while (nome[i] != '\n'){
            if(nome[i] == ' '){
                printf("\n");
            } else if(nome[i] != ' '){
                printf("%c", nome[i]);
            }
            i++;
        }
        printf("\n");
    }
}

int contarPalavras(char nome[], int quantidade){
    int contagem = 0;
    for (int i = 0; i < quantidade; i++){
        while (nome[i] != '\n'){
            if(nome[i] == ' ')
                contagem++;
            i++;
        }
    }
    contagem++; //palavra inicial
    return(contagem);
}

void criarVetorNovo(char nome[], int quantidade, char vetorNovo[]){
    for(int i = 0; i <= quantidade; i++){ //limpar lixo de memoria
        vetorNovo[i] = '\0';
    }
 
    int cont = 0;

    for(int i = 0; i <= quantidade; i++){
        if(nome[i] == ' '){
            cont++;
        } else {
            vetorNovo[i-cont] = nome[i];
        }
    } 
}

int inicial(char nome[], int quantidade) {
    int maiuscula_anterior = 1; // a primeira letra e maiuscula
    for (int i = 0; i < quantidade; i++) {
        if (nome[i] == ' ') {
            maiuscula_anterior = 1; // letra maiuscula dps do espaco
        } else if (maiuscula_anterior == 1 && !isupper(nome[i])) {
            return(0);
        }
        maiuscula_anterior = 0; //nao e maiuscula
    }
    return(1);
}

int main(){
    char nome[tam] = {};
    int quantidade;

    lerNome(nome);
    quantidade = contarLetras(nome);
    printf("\nQuantidade de Palavras que formam esse nome: %d\n", contarPalavras(nome, quantidade));
    printf("\nQuantidade de Letras que formam esse nome: %d\n", quantidade);
    printf("\nApresentar nome em diferentes linhas: \n");
    apresentarNome(nome, quantidade);

    char vetorNovo[quantidade+1];
    
    criarVetorNovo(nome, quantidade+2, vetorNovo);
    
    printf("\nTranspor para um novo vetor sem espacos: ");
    for (int i = 0; i < quantidade+1; i++){
        printf("%c", vetorNovo[i]);
    }

    int retorno = inicial(nome, quantidade);

    if(retorno == 1){
        printf("\nTodas as iniciais sao maiusculas\n");
    } else {
        printf("\nTodas as iniciais sao minusculas\n");
    }
}
#include <stdio.h>
#include <string.h>
typedef struct {
    char Disciplina[50];
    char Sigla[5];
    float nota1;
    float nota2;
    float frequencia;
} Produtos;
void escrever(char Aluno[], char Curso[], int QuantidadeDisciplina, int QntAlunos, Produtos VetorProduto[], int tl) 
{
    printf("\n==================================================\n");
    printf("Quantidade de Alunos: %d\n", QntAlunos);
    printf("Nome do Aluno: %s\n", Aluno);
    printf("Curso: %s\n", Curso);
    printf("Quantidade de Disciplinas: %d\n", QuantidadeDisciplina);
    for (int i = 0; i < tl; i++) 
    {
        printf("\n%s", VetorProduto[i].Disciplina);
        printf("\n%s %.2f %.2f %.1f\n", VetorProduto[i].Sigla, VetorProduto[i].nota1, VetorProduto[i].nota2, VetorProduto[i].frequencia);
    }
    printf("\n==================================================\n");
}
void ler(FILE *s)
{
    Produtos VetorProduto[100];
    char Aluno[50];
    char Curso[50];
    int QuantidadeDisciplina;
    int QntAlunos, tl = 0;
    fscanf(s, "%d\n", &QntAlunos);
    for(int j = 0; j < QntAlunos; j++)
    {
        fscanf(s, "%[^\n]\n", Aluno);  
        fscanf(s, "%[^\n]\n", Curso);  
        fscanf(s, "%d\n", &QuantidadeDisciplina);
        for (int i = 0; i < QuantidadeDisciplina; i++) 
        {
            fscanf(s, "%[^\n]\n", VetorProduto[i].Disciplina);
            fscanf(s, "%s %f %f %f\n", VetorProduto[i].Sigla, &VetorProduto[i].nota1, &VetorProduto[i].nota2, &VetorProduto[i].frequencia);
            tl++;
        }
        if(j == 1)
        {
        fscanf(s, "%d\n", &QntAlunos);
        fscanf(s, "%[^\n]\n", Aluno);  
        fscanf(s, "%[^\n]\n", Curso);  
        fscanf(s, "%d\n", &QuantidadeDisciplina);
        }

        escrever(Aluno, Curso, QuantidadeDisciplina, QntAlunos, VetorProduto, tl);
        tl = 0;
    }


}
void verificarArquivo(FILE *s)
{
    if (s == NULL) 
    {
        printf("\nErro ao abrir o arquivo!\n");
    } 
    else 
    {
        ler(s);
        fclose(s);
    }

}

int main() {
    FILE *s;

    s = fopen("..\\disciplinas-exerc1.txt", "r");
    verificarArquivo(s);

    return 0;
}

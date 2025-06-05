#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[50];
    float nota;

};

int main(){
    int qtdAluno;
    float media = 0;

    printf("Quantos alunos?");
    scanf("%d", &qtdAluno);

    getchar();

    struct aluno aluno [100];

    for(int i = 0; i < qtdAluno; i++){
        printf("Nome: ");
        scanf("%49[^\n]", aluno[i].nome);

        getchar();

        printf("Nota: ");
        scanf("%f", &aluno[i].nota);

        getchar();
    }

    printf("\n");
    
    for(int i = 0; i < qtdAluno; i++){
        printf("Lista de alunos:");
        printf("Nome: %s\n", aluno[i].nome);
        printf("Nota: %2.f\n\n", &aluno[i].nota);

    }

    for(int i = 0; i < qtdAluno; i++){
        media = (media + aluno[i].nota) / qtdAluno;
    }

    printf("Media: %.2f", media);

    return 0;
}
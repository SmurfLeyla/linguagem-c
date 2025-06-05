#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[50];
    int idade;
};

int main(){

    struct pessoa pessoa;

    printf("Nome: ");
    scanf("%49[^\n]", pessoa.nome);

    printf("Idade: ");
    scanf("%d", &pessoa.idade);

    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);


    return 0;
}
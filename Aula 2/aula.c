#include <stdio.h>

int main() {
    int idade;
    float altura;
    char genero;
    char nome[15];

    printf("Qual sua idade?");
    scanf("%d", &idade);

    printf("Qual sua altura?");
    scanf("%f", &altura);

    printf("Qual seu genero?");
    scanf(" %c", &genero);

    printf("Qual seu nome?");
    scanf("%s", nome);

    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);
    printf("Genero: %c\n", genero);
    printf("Nome: %s\n", nome);

    return 0;
}

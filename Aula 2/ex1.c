#include <stdio.h>

int main(){
    int idade;
    float altura;
    char genero;
    char nome[20];

    printf("Bem vindo!\n");

    printf("Qual o seu nome ? ");
    scanf("%s", nome);

    printf("Qual a sua idade ? ");
    scanf("%d", &idade);

    printf("Qual a sua altura ? ");
    scanf("%f", &altura);

    printf("Qual o seu genero ? ");
    scanf(" %c", &genero);

    printf("Bem vindo, %s!\n", nome);

    printf("Seu Perfil:\n");

    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);
    printf("Genero: %c\n", genero);

    return 0;

}
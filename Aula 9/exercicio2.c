#include <stdio.h>
#include <string.h>

int main(){

    char nome[50];
    char palavra[50];

    printf("Digite sua 1 palavra: \n");
    fgets(nome, 50, stdin);
    printf("Digite sua 2 palavra: \n");
    fgets(palavra, 50, stdin);

    printf("Palavra: %s\n", nome);
    printf("Palavra: %s\n", palavra);

    nome[strcspn(nome, "\n")] = '\0';
    palavra[strcspn(palavra, "\n")] = '\0';

    strcmp(nome, palavra);

    if (strcmp == 0){
        printf("As palavras sao iguais");
    }
    else{
        printf("As palavras são diferentes");
    }


    return 0;
}
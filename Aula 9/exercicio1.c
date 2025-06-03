#include <stdio.h>
#include <string.h>

int main(){

    char nome[50];
    int tamanho;

    printf("Digite sua palavra: \n");
    fgets(nome, 50, stdin);
    printf("Palavra: %s\n", nome);

    nome[strcspn(nome, "\n")] = '\0';

    tamanho = strlen(nome);

    if (tamanho > 15){
        printf("Palavra longa");
    }
    if (tamanho >= 8){
        printf("Palavra media");
    }
    else{
        printf("Palavra pequena");
    }

    return 0;
}
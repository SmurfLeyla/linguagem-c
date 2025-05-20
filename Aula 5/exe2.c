#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mensagem(char nome[], int idade){
    printf("Ola, %s, voce tem %d anos. Seja bem-vindo(a)!", nome, idade);
}
int main(){
    char nome[20];
    int idade;

    printf("Qual o seu nome? ");
    scanf("%s", nome);
    printf("Qual a sua idade? ");
    scanf("%d", &idade);

    mensagem(nome,idade);
    
    return 0;
}

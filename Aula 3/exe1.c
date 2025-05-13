#include <stdio.h>

int main(){
    int anoAtual;
    int anoNascimento;
    int idade;

    printf("Qual ano você nasceu?");
    scanf("%d", &anoNascimento);

    printf("Qual o no atual?");
    scanf("%d", &anoAtual);

    idade = anoAtual - anoNascimento;

    if (idade >= 18) {
        printf("Você tem %d anos em %d e poderá tirar a habilitação.", idade, anoAtual);
    }
    else {
        printf("Você tem %d anos em %d e NÃO poderá tirar a habilitação.", idade, anoAtual);
    }

    return 0; 

}
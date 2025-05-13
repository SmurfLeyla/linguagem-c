#include <stdio.h>

int main(){
    int idade;

    printf("Qual a sua idade?");
    scanf("%d", &idade);

    if (idade >= 65) {
        printf("Você é idoso(a)");
    }
    else if (idade >= 18) {
        printf("Você é adulto(a)");
    }
    else if (idade >= 13){
        printf("Você é um adolescente");
    }
    else {
        printf("Você é criança");
    }

    return 0;
}



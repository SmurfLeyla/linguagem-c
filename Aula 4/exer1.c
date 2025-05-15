#include <stdio.h>

int main (){
    int valorInicial;
    int valorFinal;

    printf("Digite o seu numero inicial: ");
    scanf("%d", &valorInicial);

    printf("Digite o seu numero final: ");
    scanf("%d", &valorFinal);

    for (int contador = valorInicial; contador <= valorFinal; contador++) {
        printf("%d ", contador);

    }

    return 0;
}
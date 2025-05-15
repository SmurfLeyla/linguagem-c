#include <stdio.h>

int main (){
    int numeroN, soma = 0;

    printf("Digite o seu numero: ");
    scanf("%d", &numeroN);

    for (int contador = 1; contador <= numeroN; contador++){

        if (contador % 2 == 0){
            soma = soma + contador;
        }

    }

    printf("A soma dos pares de seu numeroN: %d", soma);

    return 0;
}
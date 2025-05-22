#include <stdio.h>
void decrescer(int contador){
    if (contador == 1){
        printf("%d\n", contador);
    }
    else{
        printf("%d\n", contador);
        decrescer(contador - 1);
    }
}

int main() {
    int decrescente;

    printf("Insira seu numero: ");
    scanf("%d", &decrescente);

    decrescer(decrescente);

    return 0;
}
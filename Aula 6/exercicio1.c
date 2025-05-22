#include <stdio.h>

void crescer(int contador){
    if (contador == 1){
        printf("%d\n", contador);
    }
    else{
        crescer(contador - 1);
        printf("%d\n", contador);
    }
}

int main() {
    int crescente;

    printf("Insira seu numero: ");
    scanf("%d", &crescente);

    crescer(crescente);

    return 0;
}
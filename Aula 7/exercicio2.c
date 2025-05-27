#include <stdio.h>

int main(){
    int numeros[10];

    for(int i = 0; i < 10; i++){
        int numero;

        printf("Digite um numero: ");
        scanf("%d", &numero);

        numeros[i] = numero;
    }

    for(int i = 9; i >= 0; i--){
        printf("[%d] = %d\n", i, numeros[i]);
    }

    return 0; 
}
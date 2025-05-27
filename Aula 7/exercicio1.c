#include <stdio.h>

int main(){
    int numeros[10], soma = 0;

    for(int i = 0; i < 10; i++){
        int numero;

        printf("Digite um numero: ");
        scanf("%d", &numero);

        numeros[i] = numero;
    }

    for(int i = 0; i < 10; i++){
        printf("[%d] = %d\n", i, numeros[i]);
    }

    for(int i = 0; i < 10; i++){
      
        soma = soma + numeros[i];
    }

    printf("Soma = %d", soma);

    return 0; 
}
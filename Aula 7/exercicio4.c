#include <stdio.h>

int main(){
    float numeros[10], soma = 0, media;

    for(int i = 0; i < 10; i++){
        float numero;

        printf("Digite um numero: ");
        scanf("%f", &numero);

        numeros[i] = numero;
    }
    for(int i = 0; i < 10; i++){
      
        soma = soma + numeros[i];
    }
    media = soma / 10;

    printf("Media das notas: %.2f\n", &media);

    for(int i = 0; i < 10; i++){
        float nota;
        int qtdAzul;

        numeros[i] = nota;

        if (nota > media){
            qtdAzul = qtdAzul + 1;
        }
        printf("Quantidade de notas acima da media: %f\n", &qtdAzul);
    }
    printf("Notas acima da média:\n");

    for(int i = 0; i < 10; i++){
        float nota;

        numeros[i] = nota;

        if (nota > media){
            printf("%.2f\n", &nota);
        }
    }
    
    return 0; 
}
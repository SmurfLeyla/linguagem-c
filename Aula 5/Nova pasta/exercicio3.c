#include <stdio.h>

float calcularMedia (float ab1, float ab2){
    return (ab1+ab2)/2;
}

void exibirInformacoes(float media, float ab1, float ab2){
    printf("Nota da primeira avaliacao: %.2f\n", ab1);
    printf("Nota da segunda avaliacao: %.2f\n", ab2);
    printf("Media final: %.2f\n", media);
} 

int main(){
    float ab1, ab2;

    printf("Primeira avaliacao: \n");
    scanf("%f", &ab1);
    printf("Segunda avaliacao: \n");
    scanf("%f", &ab2);

    float media = calcularMedia(ab1,ab2);

    exibirInformacoes(media,ab1,ab2);

    return 0;
}
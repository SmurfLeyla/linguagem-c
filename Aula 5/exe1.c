
#include <stdio.h>

int areaRetangulo(float n1, float n2);

int main(){
    float base;
    float altura;

    printf("Digite a base do retangulo: ");
    scanf("%f", &base);
    printf("Digite a altura do retangulo: ");
    scanf("%f", &altura);
    
    float area = areaRetangulo(base,altura);
    printf("Area: %.2f\n", area);

    return 0;
}

int areaRetangulo(float base, float altura){
    return base * altura;
}
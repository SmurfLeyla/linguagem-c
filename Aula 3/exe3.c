#include <stdio.h>

int main(){
    float n1;
    float n2;
    int operacao;
    float resultado;

    printf("Informe o primeiro numero: ");
    scanf("%f", &n1);

    printf("Informe o segundo numero: ");
    scanf("%f", &n2);

    printf("Escolha a sua operacao:\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisao\n");
    scanf("%f", &operacao);

    switch (operacao)
    {
    case 1:
        resultado = n1 + n2;
        printf("%f\n", resultado);
        break;
    
    case 2:
        resultado = n1 - n2;
        printf("%f\n", resultado);
        break;
    
    case 3:
        resultado = n1 * n2;
        printf("%f\n", resultado);

    case 4:
        resultado = n1 / n2;
        
        if (n2 == 0){
            printf("Operacao invalida!");
        }
        else{
            printf("%f\n", resultado);
        }
        break;
    
    default :
        printf("Opcao invalida!");
        break;
    }
    return 0;
}
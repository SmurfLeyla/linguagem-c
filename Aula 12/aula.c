#include <stdio.h>
#include <string.h>

int main(){
    int numero;
    printf("Digite o valor original: \n");
    scanf("%d", &numero);
    
    printf("Valor original: %d\n", numero);

    int *ponteiro;
    ponteiro = &numero;

    printf("Digite o novo valor: \n");
    scanf("%d", ponteiro);

    printf("Novo valor: %d\n", *ponteiro);

    return 0;
}
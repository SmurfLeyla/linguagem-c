#include <stdio.h>
#include <string.h>

int main(){

    char palavra1[50];
    char palavra2[50];
    char palavra3[50];

    printf("Digite sua 1 palavra: \n");
    fgets(palavra1, 50, stdin);
    printf("Digite sua 2 palavra: \n");
    fgets(palavra2, 50, stdin);
    printf("Digite sua 3 palavra: \n");
    fgets(palavra3, 50, stdin);

    palavra1[strcspn(palavra1, "\n")] = '\0';
    palavra2[strcspn(palavra2, "\n")] = '\0';
    palavra3[strcspn(palavra3, "\n")] = '\0';

    
    printf("palavra 3: %s\n", palavra3);
    printf("palavra 2: %s\n", palavra2);
    printf("palavra 1: %s\n", palavra1);


    return 0;
}
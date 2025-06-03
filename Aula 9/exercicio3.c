#include <stdio.h>
#include <string.h>

int main(){

    char frase1[50];
    char frase2[50];
    char fraseCompleta[102] = "";

    printf("Digite a primeira frase: \n");
    fgets(frase1, 50, stdin);
    frase1[strcspn(frase1, "\n")] = '\0';

    printf("Digite a segunda frase: \n");
    fgets(frase2, 50, stdin);
    frase2[strcspn(frase2, "\n")] = '\0';

    strcat(fraseCompleta, frase1);
    strcat(fraseCompleta, " ");
    strcat(fraseCompleta, frase2);

    printf("Palavra: %s\n", frase1);
    printf("Palavra: %s\n", frase2);
    printf("%s", fraseCompleta);


    return 0;
}
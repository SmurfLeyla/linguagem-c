#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcao;

    do {
        printf("===== SISTEMA BANCÁRIO =====\n");
        printf("0 - Sair\n");
        printf("1 - Criar Conta\n");
        printf("2 - Exibir Contas\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Buscar Conta\n");
        printf("===========================\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo do sistema...\n");
                break;
            case 1:
                printf("Opção Criar Conta selecionada.\n");
                break;
            case 2:
                printf("Opção Exibir Contas selecionada.\n");
                break;
            case 3:
                printf("Opção Depositar selecionada.\n");
                break;
            case 4:
                printf("Opção Sacar selecionada.\n");
                break;
            case 5:
                printf("Opção Buscar Conta selecionada.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        sleep(3); 
        printf("\n");
    } while (opcao != 0);

    return 0;
}
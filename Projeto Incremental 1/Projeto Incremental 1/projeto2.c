#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int mostrarMenu(){
    int escolha;
    printf("===== SISTEMA BANCÁRIO =====\n");
        printf("0 - Sair\n");
        printf("1 - Criar Conta\n");
        printf("2 - Exibir Contas\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Buscar Conta\n");
        printf("===========================\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", escolha);
}
void criarConta(){
    printf("Opção Criar Conta selecionada.");
}
void exibirContas(){
    printf("Opção Exibir Conta selecionada.");
}
void depositar(){
    printf("Opção Deposito selecionada.");
}
void sacar(){
    printf("Opção saque selecionada.");
}
void buscarContas(){
    printf("Opção buscar Conta selecionada.");
}

int main() {
    int opcao;

    do {
        opcao = mostrarMenu();

        switch (opcao) {
            case 0:
                printf("Saindo do sistema...\n");
                break;
            case 1:
                criarConta();
                break;
            case 2:
                exibirContas();
                break;
            case 3:
                depositar();
                break;
            case 4:
                sacar();
                break;
            case 5:
                buscarContas();
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        Sleep(3000); 
        printf("\n");
    } while (opcao != 0);

    return 0;
}

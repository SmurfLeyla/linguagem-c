#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#define MAX_CONTAS 100

int ids = 1001;
int totalContas = 0;

typedef struct {
    int numero;
    char nome[200];
    float saldo;
}Conta;


int mostrarMenu(){
    int escolha;
    printf("===== SISTEMA BANCÁRIO =====\n");
        printf("0 - Sair\n");
        printf("1 - Criar Conta\n");
        printf("2 - Exibir Contas\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Buscar Conta\n");
        printf("6 - ");
        printf("7 - ");
        printf("===========================\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", escolha);
}

int contaExiste(Conta contas[], int numero){
    if(totalContas == 0){
        printf("ERROR! NENHUMA CONTA CADASTRADA");
        return -2;
    }

    for(int i = 0; i < totalContas; i++){
        if(contas[i].numero == numero){
            return 1;
        }
    }
    return -1;
}
void criarConta(Conta contas[]){
    printf("Opção Criar Conta selecionada.");

    if(totalContas >= MAX_CONTAS){
        printf("Limite de contas atingido");
        return;
    }
    int i = totalContas;
    printf("------CADASTRO-------\n");
    printf("Digite o seu nome:");
    fgets(contas[i].nome, MAX_CONTAS, stdin);
    contas[i].nome[strcspn(contas[i].nome, "\n")] = 0;
    contas[i].numero = ids;
    contas[i].saldo = 0.0;

    printf("Olá, %s! Conta criada com sucesso.\n", contas[i].nome);

    printf("----------DADOS--------");
    printf("Numero: %d\n", contas[i].numero);
    prinff("Nome: %s\n", contas[i].nome);
    printf("Saldo: %f", contas[i].saldo);

    ids++;
    totalContas++;
}
void exibirContas(Conta contas[]){
    printf("Opção Exibir Conta selecionada.");

    if(totalContas = 0){
        printf("Nenhuma conta cadastrada");
        return;
    }

    for(int i = 0; i < totalContas; i++){
        printf("\n--------- CONTA %d ---------\n");
        printf("Numero: %d\n", contas[i].numero);
        prinff("Nome: %s\n", contas[i].nome);
        printf("Saldo: %f", contas[i].saldo);

    }
}
void depositar(Conta contas[]){
    printf("Opção Deposito selecionada.");

    int numero;
    printf("Digite o nmero da conta: ");
    scanf("%d", &numero);

    int i = contaExiste(contas, numero);

    if (i == -1){
        printf("Conta não encontrada.\n");
        return;
    }
    if (i >= 0){
        float valorDeposito;
        printf("Informe o valor do seu deposito: ");
        scanf("%f", &valorDeposito);

        if (valorDeposito <= 0){
            printf("Valor Invalido.\n");
        }
        else {
            contas[i].saldo += valorDeposito;

            printf("\n----- DADOS ATUALIZADOS -------\n");
            printf("Numero: %d\n", contas[i].numero);
            prinff("Nome: %s\n", contas[i].nome);
            printf("Saldo: %f", contas[i].saldo);
        }
    }
}
void sacar(Conta contas){
    printf("Opção saque selecionada.");

     int numero;
    printf("Digite o nmero da conta: ");
    scanf("%d", &numero);

    int i = contaExiste(contas, numero);

    printf("Buscando conta.");


    if(i == -1){
        printf("Conta não encontrada");
        return;
    }
    if(i >= 0){
        float valorSaque;
        printf("\n Informe o valor do seu saque: \n");
        scanf("%f", &valorSaque);

        if(valorSaque <= 0){
            printf("Valor saque invalido");
        }
        else{
            if(valorSaque > contas[i].saldo){
            printf("Valor de saque insuficiente");
             }
            else{
            contas[i].saldo -= valorSaque;

            printf("\n----- DADOS ATUALIZADOS -------\n");
            printf("Numero: %d\n", contas[i].numero);
            prinff("Nome: %s\n", contas[i].nome);
            printf("Saldo: %f", contas[i].saldo);
            }
    }

}
}
void buscarContas(Conta contas[]){
    printf("Opção buscar Conta selecionada.");

    int numero;
    printf("Informe o numero da conta");
    scanf("%d", &numero);

    int indice = contaExiste(contas, numero);

    printf("Buscando");

    if(indice == -1){
        printf("Conta não encontrada");
    }
    if(indice >= 0){

    }
}

void transferir(Conta contas[]){
    int numeroOrigem;
    printf("Conta origem:");
    scanf("%d", &numeroOrigem);

    int numeroDestino;
    printf("Conta destino:");
    scanf("%d", &numeroDestino);

    int indiceOrigem = contaExiste(contas, numeroOrigem);
    int indiceDestino = contaExiste(contas, numeroDestino);

    if(indiceOrigem == -1 && indiceDestino == -1){
        prinf("Contas não encontradas");
        return;
    }
    if (indiceOrigem == -1){
        printf("Conta origem não encontrada");
        return;
    }
    if (indiceDestino == -1){
        printf("Conta destino não encontrada");
        return;
    }
    if(indiceOrigem >= 0 && indiceDestino >= 0){
        float valorTransfer;
        printf("\n Informe o valor do seu transfer: \n");
        scanf("%f", &valorTransfer);

        if(valorTransfer <= 0){
            printf("Valor invalido");
        }
        else{
            if(valorTransfer > contas[indiceOrigem].saldo){
            printf("Valor de saque insuficiente");
             }
            else{
            contas[indiceOrigem].saldo -= valorTransfer;
            contas[indiceDestino].saldo += valorTransfer;
            }
    }
}

void deletar(Conta contas[]){
   int numero;
   printf("Conta:");
   scanf("%d", &numero);

   int indice = contaExiste(contas, numero);

   if(i == -1){
    printf("Conta não encontrada");
    return:
   }
   if (i >= 0){
    for(int i = indice; i < totalContas -1; i++){
        strcpy(contas[i].nome, contas[i+1].nome);
        contas[i].numero = contas[i+1].numero;
        contas[i].saldo = contas[i+1]. saldo;
    }

    strcpy(contas[totalContas - 1].nome, "");
    contas[totalContas - 1].numero, "";
    contas[totalContas -1].saldo,"";

    totalContas--;
   }
}

void carregando(){
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
}

int main() {
    setlocale(LC_ALL, "portuguese");

    Conta contas[MAX_CONTAS];
    int opcao;

    do {
        opcao = mostrarMenu();

        switch (opcao) {
            case 0:
                printf("Saindo do sistema...\n");
                break;
            case 1:
                criarConta(contas);
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
            case 6:
                transferir();
                break;  
            case 7:
                deletar();
                break;  
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        Sleep(5000); 
        printf("\n");
    } while (opcao != 0);

    return 0;
}
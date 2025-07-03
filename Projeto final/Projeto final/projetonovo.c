#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

typedef struct {
    int matricula;
    char nome[100];
    float nota1, nota2;
    float media;
} Aluno;

void carregarDados(Aluno **alunos, int *totalAlunos, int *idAtual);
void salvarDados(Aluno *alunos, int totalAlunos);

// Funções Utilitárias
int mostrarMenu();
int alunoExiste(Aluno *alunos, int totalAlunos, int numero);
void carregando();
float calcularMedia(float nota1, float nota2);

// Funções do Sistema
void cadastrarAluno(Aluno **alunos, int *totalAlunos, int *ids);
void cadastrarNota(Aluno *alunos, int totalAlunos);
void exibirAlunos(Aluno *alunos, int totalAlunos);
void buscarAluno(Aluno *alunos, int totalAlunos);
void atualizarDados(Aluno *alunos, int totalAlunos);
void excluirAluno(Aluno **alunos, int *totalAlunos);
void taxaAprovacao(Aluno *alunos, int totalAlunos);

int main(){
    setlocale(LC_ALL, "portuguese");

    Aluno *alunos = NULL;
    int totalAlunos = 0;
    int idAtual = 1001;

    carregarDados(&alunos, &totalAlunos, &idAtual);

    int opcao;

    do {
        opcao = mostrarMenu();

        switch (opcao) {
            case 1:
                cadastrarAluno(&alunos, &totalAlunos, &idAtual);
                carregando();
                break;
            case 2:
                exibirAlunos(alunos, totalAlunos);
                carregando();
                break;
            case 3:
                buscarAluno(alunos, totalAlunos);
                carregando();
                break;
            case 4:
                atualizarDados(alunos, totalAlunos);
                carregando();
                break;
            case 5:
                excluirAluno(&alunos, &totalAlunos);
                carregando();
                break;
            case 6:
                cadastrarNota(alunos, totalAlunos);
                carregando();
                break;
            case 7:
                taxaAprovacao(alunos, totalAlunos);
                carregando();
                break;
            case 0:
                salvarDados(alunos, totalAlunos);
                printf("Saindo do sistema");
                carregando();
                break;
            default:
                printf("Opção inválida. Tente novamente.");
                break;
        }
            Sleep(5000);
            system("cls");

    } while (opcao != 0);

    return 0;
}


int mostrarMenu() {
    int opcao;
    printf("\n===== SISTEMA G.A =====\n");
    printf("1 - Cadastrar novo aluno\n");
    printf("2 - Exibir todos os alunos\n");
    printf("3 - Buscar por matricula\n");
    printf("4 - Atualizar dados do aluno\n");
    printf("5 - Excluir aluno\n");
    printf("6 - Cadastrar nota de aluno\n");
    printf("7 - Exibir relatorio de aprovação\n");
    printf("0 - Salvar e sair\n");
    printf("============================\n\n");
    
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}


void carregando() {
    Sleep(500); printf(".");
    Sleep(500); printf(".");
    Sleep(500); printf(".");
    printf("\n");
}

int alunoExiste(Aluno *alunos, int totalAlunos, int matricula) {
    if (totalAlunos == 0) {
        return -2;
    }

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }

    return -1;
}

void cadastrarAluno(Aluno **alunos, int *totalAlunos, int *ids) {
    printf("\n--- Cadastrar Novo Aluno ---\n");

    Aluno *ptemp = realloc(*alunos, (*totalAlunos + 1) * sizeof(Aluno));

    if (ptemp == NULL) {
        printf("ERRO: Falha ao alocar memória!\n");
        return;
    }

    *alunos = ptemp;
    int novoIndice = *totalAlunos;

    (*alunos)[novoIndice].matricula = *ids;

    printf("Matricula gerada para o novo aluno: %d\n", (*alunos)[novoIndice].matricula);
    printf("Digite o nome completo do aluno: ");
    scanf(" %[^\n]", (*alunos)[novoIndice].nome);

    (*alunos)[novoIndice].nota1 = 0.00f;
    (*alunos)[novoIndice].nota2 = 0.00f;
    (*alunos)[novoIndice].media = 0.00f;
    (*totalAlunos)++;
    (*ids)++;

    printf("\nAluno '%s' cadastrado com sucesso!\n", (*alunos)[novoIndice].nome);
}

void exibirAlunos(Aluno *alunos, int totalAlunos) {
    printf("\n--- Alunos Cadastrados ---\n");

    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado no sistema.\n");
        return;
    }

    for (int i = 0; i < totalAlunos; i++) {
        printf("--------------------------\n");
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Nota 1: %.2f\n", alunos[i].nota1);
        printf("Nota 2: %.2f\n", alunos[i].nota2);
        printf("Media Final: %.2f\n", alunos[i].media);
    }

    printf("--------------------------\n");
    printf("\nTotal de alunos: %d\n", totalAlunos);
}

void buscarAluno(Aluno *alunos, int totalAlunos) {
    int matricula;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);

    int indiceEncontrado = alunoExiste(alunos, totalAlunos, matricula);

    if (indiceEncontrado >= 0) {
        printf("\n=== Aluno Encontrado! ===\n");
        printf("----------------------\n");
        printf("Matricula: %d\n", alunos[indiceEncontrado].matricula);
        printf("Nome: %s\n", alunos[indiceEncontrado].nome);
        printf("Nota 1: %.2f\n", alunos[indiceEncontrado].nota1);
        printf("Nota 2: %.2f\n", alunos[indiceEncontrado].nota2);
        printf("Media Final: %.2f\n", alunos[indiceEncontrado].media);
        printf("----------------------\n");
    } 
    else {
        printf("\nMatricula %d nao encontrada no sistema.\n", matricula);
    }
}

void atualizarDados(Aluno *alunos, int totalAlunos) {
    int matricula;

    printf("Digite a matricula do aluno que deseja atualizar: ");
    scanf("%d", &matricula);

    int indiceEncontrado = alunoExiste(alunos, totalAlunos, matricula);

    if (indiceEncontrado < 0) {
        printf("\nMatricula %d nao encontrada no sistema.\n", matricula);
        return;
    }

    int opcao;

    do {
        printf("\n--- Editando Aluno: %s ---\n", alunos[indiceEncontrado].nome);
        printf("    Matricula: %d\n", alunos[indiceEncontrado].matricula);
        printf("    [Nota 1: %.2f]  [Nota 2: %.2f]  [Media: %.2f]\n", alunos[indiceEncontrado].nota1, alunos[indiceEncontrado].nota2, alunos[indiceEncontrado].media);
        printf("--------------------------------------------------\n");
        printf("O que voce deseja alterar?\n");
        printf("1 - Alterar Nome\n");
        printf("2 - Inserir/Alterar Nota 1\n");
        printf("3 - Inserir/Alterar Nota 2\n");
        printf("0 - Concluir Alteracoes\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o novo nome: ");
                scanf(" %[^\n]", alunos[indiceEncontrado].nome);
                printf("=> Nome atualizado com sucesso!\n");
                break;
            case 2:
                printf("Digite a nova Nota 1: ");
                scanf("%f", &alunos[indiceEncontrado].nota1);
                printf("=> Nota 1 atualizada com sucesso!\n");
                break;
            case 3:
                printf("Digite a nova Nota 2: ");
                scanf("%f", &alunos[indiceEncontrado].nota2);
                printf("=> Nota 2 atualizada com sucesso!\n");
                break;
            case 0:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opção invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    alunos[indiceEncontrado].media = calcularMedia(alunos[indiceEncontrado].nota1, alunos[indiceEncontrado].nota2);

    printf("\n=> Media do aluno %s recalculada para: %.2f\n", alunos[indiceEncontrado].nome, alunos[indiceEncontrado].media);
}

void cadastrarNota(Aluno *alunos, int totalAlunos) {
    printf("\n--- Lançamento de Notas ---\n");

    int matricula;

    printf("Digite a matricula do aluno para lançar as notas: ");
    scanf("%d", &matricula);

    int indiceEncontrado = alunoExiste(alunos, totalAlunos, matricula);

    if (indiceEncontrado < 0) {
        printf("\nMatricula %d nao encontrada no sistema.\n", matricula);
        return;
    }

    printf("\nLancando notas para o aluno: %s\n", alunos[indiceEncontrado].nome);
    printf("Digite a Nota 1: ");
    scanf("%f", &alunos[indiceEncontrado].nota1);

    printf("Digite a Nota 2: ");
    scanf("%f", &alunos[indiceEncontrado].nota2);

    alunos[indiceEncontrado].media = calcularMedia(alunos[indiceEncontrado].nota1, alunos[indiceEncontrado].nota2);

    printf("\n=> Notas lancadas com sucesso!\n");
    printf("=> Nova media calculada: %.2f\n", alunos[indiceEncontrado].media);
}

void excluirAluno(Aluno **alunos, int *totalAlunos) {
    printf("\n--- Excluir Aluno do Sistema ---\n");

    int matricula;

    printf("Digite a matricula do aluno que deseja excluir: ");
    scanf("%d", &matricula);

    int indice = alunoExiste(*alunos, *totalAlunos, matricula);

    if (indice < 0) {
        printf("\nMatricula %d nao encontrada no sistema.\n", matricula);
        return;
    }

    char confirmacao;

    printf("\nAluno encontrado: %s\n", (*alunos)[indice].nome);
    printf("Tem certeza que deseja excluir este aluno? (S -> Sim/N -> Nao): ");
    scanf(" %c", &confirmacao);

    if (confirmacao != 'S' && confirmacao != 's') {
        printf("Operação cancelada\n");
        return;
    }
    
    for (int i = indice; i < (*totalAlunos - 1); i++) {
        (*alunos)[i] = (*alunos)[i + 1];
    }

    (*totalAlunos)--;

    if (*totalAlunos == 0) {
        free(*alunos);
        *alunos = NULL;
    } 
    else {
        Aluno *temp = realloc(*alunos, (*totalAlunos) * sizeof(Aluno));
        if (temp == NULL) {
            printf("ERRO: Falha ao realocar memoria!\n");
            exit(1);
        }
        *alunos = temp;
    }

    printf("\n=> Aluno excluido com sucesso!\n");
}

float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2.00f;
}

void taxaAprovacao(Aluno *alunos, int totalAlunos) {
    printf("\n--- Relatorio de Aprovacao da Turma ---\n");

    if (totalAlunos == 0) {
        printf("Nao ha alunos para gerar relatorio.\n");
        return;
    }
    
    float mediaAprovacao = 7.00;
    int contadorAprovados = 0;
    int contadorReprovados = 0;

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].media >= mediaAprovacao) {
            contadorAprovados++;
        } 
        else {
            contadorReprovados++;
        }
    }

    float taxaAprovados = ((float)contadorAprovados / totalAlunos) * 100.0;
    float taxaReprovados = ((float)contadorReprovados / totalAlunos) * 100.0;

    printf("Total de Alunos na Turma: %d\n", totalAlunos);
    printf("Nota de Corte para Aprovacao: %.1f\n", mediaAprovacao);
    printf("----------------------------------------\n");
    printf("Alunos Aprovados:  %d\n", contadorAprovados);
    printf("Alunos Reprovados: %d\n", contadorReprovados);
    printf("----------------------------------------\n");
    printf("Taxa de Aprovacao:  %.2f%%\n", taxaAprovados);
    printf("Taxa de Reprovacao: %.2f%%\n", taxaReprovados);
    printf("========================================\n");
}

void carregarDados(Aluno **alunos, int *totalAlunos, int *idAtual) {
    FILE *arquivo = fopen("alunos.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de dados nao encontrado. Iniciando sistema vazio.\n");
        *idAtual = 1;
        return;
    }

    Aluno alunoTemp;
    int maiorMatricula = 0;

    while (fscanf(arquivo, "%d,%99[^,],%f,%f,%f\n", &alunoTemp.matricula, alunoTemp.nome, &alunoTemp.nota1, &alunoTemp.nota2, &alunoTemp.media) == 5) {
        
        Aluno *temp = realloc(*alunos, (*totalAlunos + 1) * sizeof(Aluno));

        if (temp == NULL) {
            printf("ERRO: Falha ao alocar memoria.\n");
            fclose(arquivo);
            exit(1);
        }

        *alunos = temp;
        (*alunos)[*totalAlunos] = alunoTemp;
        (*totalAlunos)++;

        if (alunoTemp.matricula > maiorMatricula) {
            maiorMatricula = alunoTemp.matricula;
        }
    }
    
    *idAtual = maiorMatricula + 1;

    fclose(arquivo);

    printf("=> %d alunos carregados do arquivo com sucesso.\n", *totalAlunos);
}

void salvarDados(Aluno *alunos, int totalAlunos) {
    FILE *arquivo = fopen("alunos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar os dados!\n");
        return;
    }

    for (int i = 0; i < totalAlunos; i++) {
        fprintf(arquivo, "%d,%s,%.2f,%.2f,%.2f\n", alunos[i].matricula, alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
    }

    fclose(arquivo);

    printf("\n=> Dados de %d alunos salvos com sucesso!\n", totalAlunos);
}

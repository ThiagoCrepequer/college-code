/**
 * @file SistemaAtendimento.c
 * @brief Implementação de um sistema de atendimento.
 * 
 * Este arquivo contém um simples algoritmo feito em C para implementar um sistema de atendimento.
 * 
 * @date 2021-10-01
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Atendimento {
    char nome[100];
    char cpf[15];
    char tipoAtendimento[100];
};

struct Atendimento atendimentos[100];
int totalAtendimentos = 0;

void solicitarAtendimento();
void listarAtendimentosRegistrados();
void listarAtendimentoPorSetor();
const char* pegarTipoAtendimento(int opcao);

int main() {
    int opcao;

    do {
        printf("Bem-vindo ao sistema de atendimento\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                solicitarAtendimento();
                break;
            case 2:
                listarAtendimentosRegistrados();
                break;
            case 3:
                listarAtendimentoPorSetor();
                break;
            case 4:
                printf("Saindo do sistema. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void solicitarAtendimento() {
    printf("Cadastro de Atendimento\n");
    
    printf("Digite seu nome: ");
    scanf("%s", atendimentos[totalAtendimentos].nome);
    
    printf("Digite seu CPF: ");
    scanf("%s", atendimentos[totalAtendimentos].cpf);
    
    int opcao;

    printf("Setores disponíveis:\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    printf("Escolha o setor de atendimento (1 a 4): ");
    scanf("%d", &opcao);
    
    strcpy(atendimentos[totalAtendimentos].tipoAtendimento, pegarTipoAtendimento(opcao));

    totalAtendimentos++;
    
    printf("Atendimento registrado com sucesso!\n\n");
}

void listarAtendimentosRegistrados() {
    printf("Lista de Atendimentos Registrados\n");
    
    for (int i = 0; i < totalAtendimentos; i++) {
        printf("===============================\n");
        printf("Nome: %s\n", atendimentos[i].nome);
        printf("CPF: %s\n", atendimentos[i].cpf);
        printf("Tipo Atendimento - %s\n", atendimentos[i].tipoAtendimento);
        printf("===============================\n");
    }
    printf("\n");
}

void listarAtendimentoPorSetor() {
    int setor;
    
    printf("Listar Atendimento por Setor\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    printf("Escolha o setor de atendimento (1 a 4): ");
    scanf("%d", &setor);
    
    printf("Atendimentos do setor %d\n", setor);
    
    for (int i = 0; i < totalAtendimentos; i++) {
        if (strcmp(atendimentos[i].tipoAtendimento, pegarTipoAtendimento(setor)) == 0) {
            printf("===============================\n");
            printf("Nome: %s\n", atendimentos[i].nome);
            printf("CPF: %s\n", atendimentos[i].cpf);
            printf("Tipo Atendimento - %s\n", atendimentos[i].tipoAtendimento);
            printf("===============================\n");
        }
    }
    printf("\n");
}

const char* pegarTipoAtendimento(int opcao) {
    switch (opcao) {
        case 1:
            return "1 - Abertura de Conta";
        case 2:
            return "2 - Caixa";
        case 3:
            return "3 - Gerente Pessoa Física";
        case 4:
            return "4 - Gerente Pessoa Jurídica";
        default:
            printf("Opção inválida. Tente novamente.\n");
            return "Opção inválida";
    }
}

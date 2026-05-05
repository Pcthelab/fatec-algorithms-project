#include "Aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Turma* criar_turma() {
    //Aloca memoria para a estrutura principal
    Turma* turma = (Turma*) malloc(sizeof(Turma));
    if (turma == NULL) {
        perror("Erro ao alocar memoria\n");
        return NULL;
    }
    turma->total_alunos = 0;
    for (int i=0; i<MAX_ALUNOS; i++) {
        turma->alunos[i] = NULL;
    }
    return turma;
}

void liberar_turma(Turma* turma) {
    if (turma == NULL) {
        return;
    }
    for (int i=0; i<turma->total_alunos; i++) {
        if (turma->alunos[i] != NULL) {
            free(turma->alunos[i]);
        }
    }
    free(turma);
}

void cadastrar_aluno(Turma* turma) {
    if (turma == NULL) {
        printf("\n[!] Erro: Turma nao inicializada.\n");
        return;
    }

    if (turma->total_alunos == MAX_ALUNOS) {
        printf("\n[!] Erro: Turma cheia!\n");
        return;
    }

    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));

    printf("\n--- Cadastrar Novo Aluno ---\n");

    int matricula_temp;
    while (1) {
        printf("Digite a matricula:");
        if (scanf("%d", &matricula_temp) != 1) {
            printf("Entrada invalida! Use apenas numeros.\n");
            while (getchar() != '\n');
            continue;
        }

        if (buscar_aluno(turma, matricula_temp) == NULL) {
            novo_aluno->matricula = matricula_temp;
            break;
        } else {
            printf("[!] Erro: Matricula %d ja existe. Tente outra.\n", matricula_temp);
        }
    }

    while (getchar() != '\n');

    printf("Digite o nome:");
    fgets(novo_aluno->nome, 50, stdin);
    novo_aluno->nome[strcspn(novo_aluno->nome, "\n")] = 0;

    printf("Digite o curso:");
    fgets(novo_aluno->curso, 50, stdin);
    novo_aluno->curso[strcspn(novo_aluno->curso, "\n")] = 0;

    printf("Digite a idade:");
    scanf("%d", &novo_aluno->idade);

    turma->alunos[turma->total_alunos] = novo_aluno;
    turma->total_alunos++;

    printf("\n>>> Aluno '%s' cadastrado com sucesso! <<<\n", novo_aluno->nome);
}

Aluno* buscar_aluno(Turma* turma, int matricula) {
    if (turma == NULL) {
        return NULL;
    }
    for (int i=0; i<turma->total_alunos; i++) {
        if (matricula == turma->alunos[i]->matricula) {
            return turma->alunos[i];
        }
    }
    return NULL;
}

void alterar_dados_aluno(Aluno* aluno) {
    if (aluno == NULL) {
        printf("Erro: Aluno nao encontrado no sistema.\n");
        return;
    }

    // Informativo inicial
    printf("\n--- Editando Aluno: %s ---\n", aluno->nome);
    printf("[Aviso: O campo MATRICULA (%d) e fixo e nao pode ser editado]\n", aluno->matricula);

    printf("Digite o NOVO nome: ");
    fflush(stdin);
    // fgets e mais seguro: (variavel, tamanho, entrada_padrao)
    fgets(aluno->nome, 50, stdin);
    // O fgets pega o 'Enter', esse comando remove ele:
    aluno->nome[strcspn(aluno->nome, "\n")] = 0;

    printf("Digite o NOVO curso: ");
    fflush(stdin);
    fgets(aluno->curso, 50, stdin);
    aluno->curso[strcspn(aluno->curso, "\n")] = 0;

    printf("Digite a NOVA idade: ");
    fflush(stdin);
    scanf("%d", &aluno->idade);

    printf("\n--- Dados atualizados com sucesso! ---\n");
}

void exibir_aluno(const Aluno* aluno) {
    if (aluno == NULL) {
        printf("Aluno nao encontrado ou nulo\n");
        return;
    }
    printf("========================================\n");
    printf("Matricula: %d \n", aluno->matricula);
    printf("Nome: %s \n", aluno->nome);
    printf("Curso: %s \n", aluno->curso);
    printf("Idade: %d \n", aluno->idade);
    printf("========================================\n");
}

void exibir_lista_alunos(const Turma* turma) {
    if (turma == NULL || turma->total_alunos == 0) {
        printf("\n[!] Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n>>> LISTA DE ALUNOS CADASTRADOS (%d) <<<\n", turma->total_alunos);


    printf("------------------------------------------------------------------\n");
    printf("%-5s | %-20s | %-15s | %-5s\n", "ID", "NOME", "CURSO", "IDADE");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < turma->total_alunos; i++) {
        printf("%-5d | %-20s | %-15s | %-5d\n",
               turma->alunos[i]->matricula,
               turma->alunos[i]->nome,
               turma->alunos[i]->curso,
               turma->alunos[i]->idade);
    }

    printf("------------------------------------------------------------------\n");
}
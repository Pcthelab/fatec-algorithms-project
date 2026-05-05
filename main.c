#include <stdio.h>
#include "Aluno.h"

int exibir_menu() {
    int opcao;
    printf("--- MENU PRINCIPAL ----\n");
    printf("1. Cadatrar Aluno \n");
    printf("2. Alterar Dados de Aluno \n");
    printf("3. Procurar Aluno (por matricula) \n");
    printf("4. Exibir Dados de um Aluno \n");
    printf("5. Exibir lista de Alunos \n");
    printf("9. SAIR \n");
    printf("-----------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);
    return opcao;
}

void executar_alterar_aluno(Turma* turma) {
    printf("\n----Alterar dados ---\n");
    int matricula;
    printf("Digite a matricula do aluno a alterar: ");
    scanf("%d", &matricula);
    Aluno *aluno_encontrado = buscar_aluno(turma, matricula);
    if (aluno_encontrado == NULL) {
        printf("Aluno nao encontrado. Nao ha o que alterar\n");
        return;
    }
    alterar_dados_aluno(aluno_encontrado);
}

void executar_procurar_aluno(Turma* turma) {
    printf("\n----Procurar Aluno ---\n");
    printf("Digite a matricula do aluno a procurar: ");
    int matricula;
    scanf("%d", &matricula);
    fflush(stdin);
    Aluno *aluno_encontrado = buscar_aluno(turma, matricula);
    if (aluno_encontrado == NULL) {
        printf("Aluno nao encontrado \n");
        return;
    }
    printf("Aluno encontrado: \n");
    exibir_aluno(aluno_encontrado); //Rotina elegante
}

void executar_exibir_aluno(Turma* turma) {
    printf("\n----Exibir Aluno ---\n");
    printf("Digite a matricula do aluno a exibir: ");
    int matricula;
    scanf("%d", &matricula);
    fflush(stdin);
    Aluno* aluno_encontrado = buscar_aluno(turma, matricula);
    if (aluno_encontrado != NULL) {
        exibir_aluno(aluno_encontrado);
    }else {
        printf("Aluno nao encontrado \n");
    }
}
int main(void) {
    //Inicializar o TAD
    Turma * m_turma = criar_turma();
    if (m_turma == NULL) {
        printf("Falha Critica ao inicializa o sistema. Encerrando\n");
        return 1;
    }
    while (1) {
        int opcao = exibir_menu();
        switch (opcao) {
            case 1: //Cadastrar
                cadastrar_aluno(m_turma);
                break;
            case 2: //Alterar
                executar_alterar_aluno(m_turma);
                break;
            case 3: //Procurar
                executar_procurar_aluno(m_turma);
                break;
            case 4: //Exibir aluno
                executar_exibir_aluno(m_turma);
                break;
            case 5: //Exibir lista
                exibir_lista_alunos(m_turma);
                break;
            case 9:
                printf("Encerrando o sistema\n");
                liberar_turma(m_turma);
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }
}

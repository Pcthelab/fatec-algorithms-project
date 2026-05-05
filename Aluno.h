#ifndef ALUNO_H
#define ALUNO_H

/**
 * @struct Aluno
 * @brief Estrutura que representa um aluno.
 *
 * Contém informações básicas como matrícula, nome, curso e idade.
 */
typedef struct {
    int matricula;     /**< Número de matrícula do aluno */
    char nome[100];    /**< Nome completo do aluno */
    char curso[50];    /**< Curso em que o aluno está matriculado */
    int idade;         /**< Idade do aluno */
} Aluno;

#define MAX_ALUNOS 100 /**< Número máximo de alunos permitidos em uma turma */

/**
 * @struct Turma
 * @brief Estrutura que representa uma turma de alunos.
 *
 * Contém um vetor de ponteiros para alunos e o total de alunos cadastrados.
 */
typedef struct {
    Aluno* alunos[MAX_ALUNOS]; /**< Vetor de ponteiros para alunos */
    int total_alunos;          /**< Quantidade atual de alunos na turma */
} Turma;

/**
 * @brief Cria e inicializa uma nova turma.
 *
 * Aloca memória para a estrutura Turma e inicializa o total de alunos como zero.
 *
 * @return Ponteiro para a nova turma criada.
 */
Turma* criar_turma();

/**
 * @brief Libera a memória associada a uma turma.
 *
 * Percorre todos os alunos cadastrados, libera suas memórias e, em seguida,
 * libera a memória da própria turma.
 *
 * @param turma Ponteiro para a turma a ser liberada.
 */
void liberar_turma(Turma* turma);

/**
 * @brief Cadastra um novo aluno na turma.
 *
 * Solicita os dados do aluno e adiciona ao vetor da turma, caso haja espaço disponível.
 *
 * @param turma Ponteiro para a turma onde o aluno será cadastrado.
 */
void cadastrar_aluno(Turma* turma);

/**
 * @brief Busca um aluno pela matrícula.
 *
 * Percorre a lista de alunos da turma procurando pela matrícula informada.
 *
 * @param turma Ponteiro para a turma onde será realizada a busca.
 * @param matricula Número de matrícula do aluno a ser encontrado.
 * @return Ponteiro para o aluno encontrado ou NULL caso não exista.
 */
Aluno* buscar_aluno(Turma* turma, int matricula);

/**
 * @brief Altera os dados de um aluno.
 *
 * Permite modificar informações como nome, curso e idade.
 *
 * @param aluno Ponteiro para o aluno cujos dados serão alterados.
 */
void alterar_dados_aluno(Aluno* aluno);

/**
 * @brief Exibe os dados de um aluno.
 *
 * Mostra na saída padrão as informações do aluno.
 *
 * @param aluno Ponteiro para o aluno a ser exibido.
 */
void exibir_aluno(const Aluno* aluno);

/**
 * @brief Exibe a lista de todos os alunos da turma.
 *
 * Percorre todos os alunos cadastrados e exibe suas informações.
 *
 * @param turma Ponteiro para a turma.
 */
void exibir_lista_alunos(const Turma* turma);

#endif
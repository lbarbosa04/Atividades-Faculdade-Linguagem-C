#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

// Constantes do sistema.
#define MAX_NOME 50
#define MAX_INFO 20
#define MAX_CADASTRO_ALUNOS 1000
#define MAX_NOTAS 4
#define NUM_DISCIPLINAS 4
#define MEDIA_APROVADO 6.0
#define MEDIA_RECUPERACAO 4.0

// Struct que armazena as notas das disciplinas.
typedef struct {
    float notaMatematica[MAX_NOTAS];
    float notaPortugues[MAX_NOTAS];
    float notaHistoria[MAX_NOTAS];
    float notaCiencia[MAX_NOTAS];
} materia;

// Struct com os dados do aluno.
typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char turma[MAX_INFO];
} aluno;

// Struct que agrupa os dados do aluno e suas notas.
typedef struct {
    materia materias;
    aluno alunos;
} cadastro;


// Le somente numeros inteiros.
int lerInteiro(void) {
    char entrada[100];
    char *fim;
    long valor;

    while(1) {
        if(scanf("%99s", entrada) != 1) {
            return 0;
        }

        errno = 0;
        valor = strtol(entrada, &fim, 10);

        if(fim == entrada || *fim != '\0' || errno == ERANGE ||
           valor < INT_MIN || valor > INT_MAX) {
            printf("Entrada invalida! Digite um numero inteiro: ");
        }
        else {
            return (int)valor;
        }
    }
}


// Le notas numericas entre 0 e 10.
float lerNota(void) {
    char entrada[100];
    char *fim;
    float valor;

    while(1) {
        if(scanf("%99s", entrada) != 1) {
            return -1;
        }

        errno = 0;
        valor = strtof(entrada, &fim);

        if(fim == entrada || *fim != '\0' || errno == ERANGE ||
           !(valor >= 0 && valor <= 10)) {
            printf("Entrada invalida! Digite uma nota numerica entre 0 e 10: ");
        }
        else {
            return valor;
        }
    }
}


// Pausa a tela.
void PAUSE() {
    printf("\nPRESSIONE ENTER PARA CONTINUAR...");
    getchar();
    getchar();
}


// Calcula a media de uma disciplina.
float calcularMediaDisciplina(float notas[MAX_NOTAS]) {
    float soma = 0;

    for(int x = 0; x < MAX_NOTAS; x++) {
        soma += notas[x];
    }

    return soma / MAX_NOTAS;
}


// Calcula a media geral do aluno.
float calcularMediaGeral(cadastro c) {
    float soma = 0;

    soma += calcularMediaDisciplina(c.materias.notaMatematica);
    soma += calcularMediaDisciplina(c.materias.notaPortugues);
    soma += calcularMediaDisciplina(c.materias.notaHistoria);
    soma += calcularMediaDisciplina(c.materias.notaCiencia);

    return soma / NUM_DISCIPLINAS;
}


// Retorna: 1 = aprovado, 2 = recuperacao, 3 = reprovado.
int situacao(float media) {
    if(media >= MEDIA_APROVADO) {
        return 1;
    }
    else if(media >= MEDIA_RECUPERACAO) {
        return 2;
    }
    else {
        return 3;
    }
}


// Exibe o menu principal.
void exibirMenu(void) {
    printf("\n===== SISTEMA DE ALUNOS =====\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Listar alunos\n");
    printf("3 - Buscar aluno\n");
    printf("4 - Lancar/alterar notas\n");
    printf("5 - Remover aluno\n");
    printf("6 - Emitir boletim\n");
    printf("7 - Relatorio da turma\n");
    printf("8 - Sair\n");
    printf("\nEscolha uma opcao: ");
}


// Exibe as notas, a media e a situacao de uma disciplina.
void imprimirLinhaBoletim(char disciplina[], float notas[MAX_NOTAS]) {
    float media = calcularMediaDisciplina(notas);

    printf("%-10s", disciplina);

    for(int x = 0; x < MAX_NOTAS; x++) {
        printf(" %4.1f", notas[x]);
    }

    printf(" %6.2f  ", media);

    if(situacao(media) == 1) {
        printf("Aprovado\n");
    }
    else if(situacao(media) == 2) {
        printf("Recuperacao\n");
    }
    else {
        printf("Reprovado\n");
    }
}


// Procura a matricula e retorna o indice ou -1 se nao encontrar.
int buscarIndice(cadastro cadastroAluno[], int totalAlunos, int matricula) {
    for(int x = 0; x < totalAlunos; x++) {
        if(cadastroAluno[x].alunos.matricula == matricula) {
            return x;
        }
    }

    return -1;
}


// CASE 1 - Cadastro de alunos.
int cadastroAlunos(cadastro cadastroAluno[], int totalAlunos) {

    int opcaoFinalizarSistema;
    int matricula;

    do {

        if(totalAlunos >= MAX_CADASTRO_ALUNOS) {
            printf("Limite de cadastros atingido!\n");
            return totalAlunos;
        }

        // A proxima posicao livre do vetor.
        int i = totalAlunos;

        printf("\n===== Cadastro do aluno =====\n");

        // Valida o intervalo e impede matriculas duplicadas.
        do {
            printf("Matricula (001 a 999): ");
            matricula = lerInteiro();

            if(matricula < 1 || matricula > 999) {
                printf("ERRO! Matricula deve estar entre 001 e 999.\n");
            }
            else if(buscarIndice(cadastroAluno, totalAlunos, matricula) != -1) {
                printf("ERRO! Matricula ja cadastrada.\n");
            }

        } while(matricula < 1 || matricula > 999 ||
                buscarIndice(cadastroAluno, totalAlunos, matricula) != -1);

        cadastroAluno[i].alunos.matricula = matricula;

        // Nome.
        printf("Nome do aluno: ");
        scanf(" %49[^\n]", cadastroAluno[i].alunos.nome);

        // Turma.
        printf("Turma do aluno (ex.: ADS 1): ");
        scanf(" %19[^\n]", cadastroAluno[i].alunos.turma);

        printf("===== Cadastro das notas =====\n");

        // Notas de Matematica.
        for(int x = 0; x < MAX_NOTAS; x++) {
            printf("Nota %d de Matematica (0 a 10): ", x + 1);
            cadastroAluno[i].materias.notaMatematica[x] = lerNota();
        }

        // Notas de Portugues.
        for(int x = 0; x < MAX_NOTAS; x++) {
            printf("Nota %d de Portugues (0 a 10): ", x + 1);
            cadastroAluno[i].materias.notaPortugues[x] = lerNota();
        }

        // Notas de Historia.
        for(int x = 0; x < MAX_NOTAS; x++) {
            printf("Nota %d de Historia (0 a 10): ", x + 1);
            cadastroAluno[i].materias.notaHistoria[x] = lerNota();
        }

        // Notas de Ciencias.
        for(int x = 0; x < MAX_NOTAS; x++) {
            printf("Nota %d de Ciencias (0 a 10): ", x + 1);
            cadastroAluno[i].materias.notaCiencia[x] = lerNota();
        }

        // Atualiza a quantidade de alunos.
        totalAlunos++;

        printf("\nCadastro finalizado!\n");
        PAUSE();

        do {
            printf("\nContinuar cadastro:\n1 - Sim\n2 - Nao\n");
            opcaoFinalizarSistema = lerInteiro();

            if(opcaoFinalizarSistema != 1 && opcaoFinalizarSistema != 2) {
                printf("ERRO! Escolha 1 ou 2.\n");
            }

        } while(opcaoFinalizarSistema != 1 && opcaoFinalizarSistema != 2);

    } while(opcaoFinalizarSistema != 2);

    return totalAlunos;
}


// CASE 2 - Lista todos os alunos cadastrados.
void listarAlunos(cadastro cadastroAluno[], int totalAlunos) {

    // Impede a listagem quando nao ha alunos.
    if(totalAlunos == 0) {
        printf("\nNao existem alunos cadastrados no sistema.\n");
        PAUSE();
        return;
    }

    printf("\n==== Listagem de alunos =====\n");
    printf("Quantidade cadastrada no sistema: %d\n", totalAlunos);

    for(int x = 0; x < totalAlunos; x++) {
        printf("\nMatricula: %03d | Nome: %s | Turma: %s",
               cadastroAluno[x].alunos.matricula,
               cadastroAluno[x].alunos.nome,
               cadastroAluno[x].alunos.turma);
    }

    PAUSE();
}


// CASE 3 - Busca um aluno pela matricula.
void buscarAlunos(cadastro cadastroAluno[], int totalAlunos) {

    int matricula;
    int indice;

    // Impede a busca quando nao ha alunos.
    if(totalAlunos == 0) {
        printf("\nNao existem alunos cadastrados para buscar.\n");
        PAUSE();
        return;
    }

    printf("\n===== Busca aluno =====\n");

    do {
        printf("\nDigite a matricula (001 a 999): ");
        matricula = lerInteiro();

        if(matricula < 1 || matricula > 999) {
            printf("ERRO! Matricula invalida.\n");
        }

    } while(matricula < 1 || matricula > 999);

    indice = buscarIndice(cadastroAluno, totalAlunos, matricula);

    if(indice == -1) {
        printf("Aluno nao encontrado.\n");
    }
    else {
        printf("\nAluno encontrado!");
        printf("\nMatricula: %03d", cadastroAluno[indice].alunos.matricula);
        printf("\nNome: %s", cadastroAluno[indice].alunos.nome);
        printf("\nTurma: %s\n", cadastroAluno[indice].alunos.turma);
    }

    PAUSE();
}


// CASE 4 - Lancar ou alterar notas de um aluno.
void lancarAlterarNotas(cadastro cadastroAluno[], int totalAlunos) {

    int matricula;
    int indice;
    int materiaEscolhida;
    int numNota;
    float novaNota;
    int opcaoContinuar;

    // Impede a alteracao quando nao ha alunos.
    if(totalAlunos == 0) {
        printf("\nNao existem alunos cadastrados para alterar notas.\n");
        PAUSE();
        return;
    }

    printf("\n===== Lancar/alterar notas =====\n");

    do {
        printf("Matricula do aluno (001 a 999): ");
        matricula = lerInteiro();

        if(matricula < 1 || matricula > 999) {
            printf("ERRO! Matricula invalida.\n");
        }

    } while(matricula < 1 || matricula > 999);

    indice = buscarIndice(cadastroAluno, totalAlunos, matricula);

    if(indice == -1) {
        printf("Aluno nao encontrado.\n");
        PAUSE();
        return;
    }

    printf("\nAluno: %s\n", cadastroAluno[indice].alunos.nome);

    do {

        // Escolher materia.
        do {
            printf("\nMateria:\n");
            printf("1 - Matematica\n");
            printf("2 - Portugues\n");
            printf("3 - Historia\n");
            printf("4 - Ciencias\n");
            printf("Escolha a materia: ");
            materiaEscolhida = lerInteiro();

            if(materiaEscolhida < 1 || materiaEscolhida > NUM_DISCIPLINAS) {
                printf("ERRO! Escolha uma materia entre 1 e 4.\n");
            }

        } while(materiaEscolhida < 1 || materiaEscolhida > NUM_DISCIPLINAS);


        // Mostrar notas atuais.
        printf("\nNotas atuais: ");

        for(int x = 0; x < MAX_NOTAS; x++) {

            if(materiaEscolhida == 1) {
                printf("[%d]=%.1f ", x + 1, cadastroAluno[indice].materias.notaMatematica[x]);
            }
            else if(materiaEscolhida == 2) {
                printf("[%d]=%.1f ", x + 1, cadastroAluno[indice].materias.notaPortugues[x]);
            }
            else if(materiaEscolhida == 3) {
                printf("[%d]=%.1f ", x + 1, cadastroAluno[indice].materias.notaHistoria[x]);
            }
            else {
                printf("[%d]=%.1f ", x + 1, cadastroAluno[indice].materias.notaCiencia[x]);
            }
        }

        printf("\n");

        // Escolher a nota que sera alterada.
        do {
            printf("Qual nota deseja alterar (1 a %d)? ", MAX_NOTAS);
            numNota = lerInteiro();

            if(numNota < 1 || numNota > MAX_NOTAS) {
                printf("ERRO! Escolha uma nota entre 1 e 4.\n");
            }

        } while(numNota < 1 || numNota > MAX_NOTAS);

        numNota--;

        // Digitar a nova nota.
        printf("Nova nota (0 a 10): ");
        novaNota = lerNota();

        // Atualiza somente a nota escolhida.
        if(materiaEscolhida == 1) {
            cadastroAluno[indice].materias.notaMatematica[numNota] = novaNota;
        }
        else if(materiaEscolhida == 2) {
            cadastroAluno[indice].materias.notaPortugues[numNota] = novaNota;
        }
        else if(materiaEscolhida == 3) {
            cadastroAluno[indice].materias.notaHistoria[numNota] = novaNota;
        }
        else {
            cadastroAluno[indice].materias.notaCiencia[numNota] = novaNota;
        }

        printf("\nNota atualizada com sucesso!\n");

        do {
            printf("\nAlterar outra nota deste aluno:\n1 - Sim\n2 - Nao\n");
            opcaoContinuar = lerInteiro();

            if(opcaoContinuar != 1 && opcaoContinuar != 2) {
                printf("ERRO! Escolha 1 ou 2.\n");
            }

        } while(opcaoContinuar != 1 && opcaoContinuar != 2);

    } while(opcaoContinuar != 2);

    PAUSE();
}


// CASE 5 - Remove um aluno do vetor.
int removerAluno(cadastro cadastroAluno[], int totalAlunos) {

    int matricula;
    int indice;
    int confirmar;

    // Impede a remocao quando nao ha alunos.
    if(totalAlunos == 0) {
        printf("\nNao existem alunos cadastrados para remover.\n");
        PAUSE();
        return totalAlunos;
    }

    printf("\n===== Remover aluno =====\n");

    do {
        printf("Matricula do aluno (001 a 999): ");
        matricula = lerInteiro();

        if(matricula < 1 || matricula > 999) {
            printf("ERRO! Matricula invalida.\n");
        }

    } while(matricula < 1 || matricula > 999);

    indice = buscarIndice(cadastroAluno, totalAlunos, matricula);

    if(indice == -1) {
        printf("Aluno nao encontrado.\n");
        PAUSE();
        return totalAlunos;
    }

    printf("\nAluno: %s\n", cadastroAluno[indice].alunos.nome);
    printf("Turma: %s\n", cadastroAluno[indice].alunos.turma);

    do {
        printf("\nConfirmar remocao:\n1 - Sim\n2 - Nao\n");
        confirmar = lerInteiro();

        if(confirmar != 1 && confirmar != 2) {
            printf("ERRO! Escolha 1 ou 2.\n");
        }

    } while(confirmar != 1 && confirmar != 2);

    if(confirmar == 1) {

        // Desloca os registros seguintes para fechar o espaco.
        for(int x = indice; x < totalAlunos - 1; x++) {
            cadastroAluno[x] = cadastroAluno[x + 1];
        }

        totalAlunos--;

        printf("\nAluno removido com sucesso!\n");
    }
    else {
        printf("\nRemocao cancelada.\n");
    }

    PAUSE();

    return totalAlunos;
}


// CASE 6 - Emite o boletim de um aluno.
void emitirBoletim(cadastro cadastroAluno[], int totalAlunos) {

    int matricula;
    int indice;

    // Impede a emissao quando nao ha alunos.
    if(totalAlunos == 0) {
        printf("\nNao existem alunos cadastrados para emitir boletins.\n");
        PAUSE();
        return;
    }

    printf("\n===== Emitir boletim =====\n");

    do {
        printf("Matricula do aluno (001 a 999): ");
        matricula = lerInteiro();

        if(matricula < 1 || matricula > 999) {
            printf("ERRO! Matricula invalida.\n");
        }

    } while(matricula < 1 || matricula > 999);

    indice = buscarIndice(cadastroAluno, totalAlunos, matricula);

    if(indice == -1) {
        printf("Aluno nao encontrado.\n");
        PAUSE();
        return;
    }

    printf("\n========== BOLETIM ESCOLAR ==========\n");

    printf("Aluno: %s   Matricula: %03d   Turma: %s\n",
           cadastroAluno[indice].alunos.nome,
           cadastroAluno[indice].alunos.matricula,
           cadastroAluno[indice].alunos.turma);

    printf("-------------------------------------\n");
    printf("Disciplina   B1   B2   B3   B4  Media  Situacao\n");

    imprimirLinhaBoletim("Portugues", cadastroAluno[indice].materias.notaPortugues);
    imprimirLinhaBoletim("Matematica", cadastroAluno[indice].materias.notaMatematica);
    imprimirLinhaBoletim("Ciencias", cadastroAluno[indice].materias.notaCiencia);
    imprimirLinhaBoletim("Historia", cadastroAluno[indice].materias.notaHistoria);

    printf("-------------------------------------\n");
    printf("Media geral: %.2f\n", calcularMediaGeral(cadastroAluno[indice]));
    printf("=====================================\n");

    PAUSE();
}


// CASE 7 - Gera um relatorio de uma turma.
void relatorioTurma(cadastro cadastroAluno[], int totalAlunos) {

    char turma[MAX_INFO];
    int qtd = 0;
    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;
    int indiceMaior = -1;
    float mediaAluno;
    float maiorMedia = -1;
    float somaTurma = 0;

    // Impede o relatorio quando nao ha alunos.
    if(totalAlunos == 0) {
        printf("\nNao existem alunos cadastrados para gerar relatorios.\n");
        PAUSE();
        return;
    }

    printf("\n===== Relatorio da turma =====\n");

    printf("Turma (ex.: ADS 1): ");
    scanf(" %19[^\n]", turma);

    for(int x = 0; x < totalAlunos; x++) {

        // Ignora alunos que nao pertencem a turma informada.
        if(strcmp(cadastroAluno[x].alunos.turma, turma) != 0) {
            continue;
        }

        qtd++;

        mediaAluno = calcularMediaGeral(cadastroAluno[x]);
        somaTurma += mediaAluno;

        if(situacao(mediaAluno) == 1) {
            aprovados++;
        }
        else if(situacao(mediaAluno) == 2) {
            recuperacao++;
        }
        else {
            reprovados++;
        }

        // Guarda o aluno com a maior media encontrada.
        if(mediaAluno > maiorMedia) {
            maiorMedia = mediaAluno;
            indiceMaior = x;
        }
    }

    if(qtd == 0) {
        printf("\nNenhum aluno encontrado nessa turma.\n");
    }
    else {
        printf("\n========== RELATORIO DA TURMA %s ==========\n", turma);
        printf("Total de alunos: %d\n", qtd);
        printf("Media geral da turma: %.2f\n", somaTurma / qtd);
        printf("Maior media: %s (%.2f)\n",
               cadastroAluno[indiceMaior].alunos.nome,
               maiorMedia);

        printf("\nAprovados: %d\n", aprovados);
        printf("Recuperacao: %d\n", recuperacao);
        printf("Reprovados: %d\n", reprovados);
    }

    PAUSE();
}


// Funcao principal: controla o vetor, o contador e o menu.
int main() {

    // Vetor que armazena os registros dos alunos.
    cadastro cadastroAluno[MAX_CADASTRO_ALUNOS];

    // Comeca em zero porque nenhum aluno foi cadastrado.
    int totalAlunos = 0;
    int opcao;

    do {
        exibirMenu();
        opcao = lerInteiro();

        // Direciona para a funcao correspondente.
        switch(opcao) {

            case 1:
                totalAlunos = cadastroAlunos(cadastroAluno, totalAlunos);
                break;

            case 2:
                listarAlunos(cadastroAluno, totalAlunos);
                break;

            case 3:
                buscarAlunos(cadastroAluno, totalAlunos);
                break;

            case 4:
                lancarAlterarNotas(cadastroAluno, totalAlunos);
                break;

            case 5:
                totalAlunos = removerAluno(cadastroAluno, totalAlunos);
                break;

            case 6:
                emitirBoletim(cadastroAluno, totalAlunos);
                break;

            case 7:
                relatorioTurma(cadastroAluno, totalAlunos);
                break;

            case 8:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while(opcao != 8);

    return 0;
}
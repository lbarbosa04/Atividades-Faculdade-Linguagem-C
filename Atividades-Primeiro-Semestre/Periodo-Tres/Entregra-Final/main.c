#include <stdio.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_INFO 20
#define MAX_CADASTRO_ALUNOS 1000
#define MAX_NOTAS 4
#define NUM_DISCIPLINAS 4
#define MEDIA_APROVADO 6.0
#define MEDIA_RECUPERACAO 4.0

typedef struct { // informações das notas
    float notaMatematica[MAX_NOTAS];
    float notaPortugues[MAX_NOTAS];
    float notaHistoria[MAX_NOTAS];
    float notaCiencia[MAX_NOTAS];
} materia;

typedef struct { // cadastro do aluno
    int matricula;
    char nome[MAX_NOME];
    char turma[MAX_INFO];
} aluno;

typedef struct { // Vai ser utilizado na main
    materia materias;
    aluno alunos;
} cadastro;


void PAUSE(){ //PAUSE serve para sempre que eu chamar ele o programar pausar e continuar ao dar o comando
    printf("\nPRESSIONE ENTER PARA CONTINUAR...");
    getchar();
    getchar();
}

//Funções de cálculo
float calcularMediaDisciplina(float notas[MAX_NOTAS]){
    float soma = 0;

    for(int x = 0; x < MAX_NOTAS; x ++){
        soma += notas[x];
    }
    return soma / MAX_NOTAS;
}

float calcularMediaGeral(cadastro c){
    float soma = 0;

    soma += calcularMediaDisciplina(c.materias.notaMatematica);
    soma += calcularMediaDisciplina(c.materias.notaPortugues);
    soma += calcularMediaDisciplina(c.materias.notaHistoria);
    soma += calcularMediaDisciplina(c.materias.notaCiencia);

    return soma / NUM_DISCIPLINAS;
}

// 1 = Aprovado, 2 = Recuperacao, 3 = Reprovado
int situacao(float media){
    if(media >= MEDIA_APROVADO){
        return 1;
    } else if(media >= MEDIA_RECUPERACAO){
        return 2;
    } else {
        return 3;
    }
}

//Funções de exibição
void exibirMenu(void) //menu
{
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

void imprimirLinhaBoletim(char disciplina[], float notas[MAX_NOTAS]){
    float media = calcularMediaDisciplina(notas);

    printf("%-10s", disciplina);
    for(int x = 0; x < MAX_NOTAS; x ++){
        printf(" %4.1f", notas[x]);
    }
    printf(" %6.2f  ", media);

    if(situacao(media) == 1){
        printf("Aprovado\n");
    } else if(situacao(media) == 2){
        printf("Recuperacao\n");
    } else {
        printf("Reprovado\n");
    }
}

// Procura o aluno pela matricula (retorna a posição ou -1 se não achar)
int buscarIndice(cadastro cadastroAluno[], int totalAlunos, int matricula){
    for(int x = 0; x < totalAlunos; x ++){
        if(cadastroAluno[x].alunos.matricula == matricula){
            return x;
        }
    }
    return -1;
}

//Case 1 (devolve a nova quantidade de alunos)
int cadastroAlunos(cadastro cadastroAluno[], int totalAlunos){

    int opcaoFinalizarSistema;
    int matricula;

    do {
        if(totalAlunos >= MAX_CADASTRO_ALUNOS){
            printf("Limite de cadastros atingidos!\n");
            return totalAlunos;
        }

        int i = totalAlunos;

        printf("\n===== Cadastro do aluno =====\n");

        do {
            printf("Matricula: ");
            scanf("%d", &matricula);

            if(buscarIndice(cadastroAluno, totalAlunos, matricula) != -1){
                printf("Matricula ja cadastrada!\n");
            }
        } while(buscarIndice(cadastroAluno, totalAlunos, matricula) != -1);

        cadastroAluno[i].alunos.matricula = matricula;

        printf("Nome do aluno: ");
        scanf(" %49[^\n]", cadastroAluno[i].alunos.nome);

        printf("Turma do aluno: (ex.: 2A)\n");
        scanf("%s", cadastroAluno[i].alunos.turma);

        printf("===== Cadstro notas do aluno =====\n");
        for(int x = 0; x < MAX_NOTAS; x ++){
            do {
                printf("Nota %d de Matematica (0 a 10)\n", x + 1);
                scanf("%f", &cadastroAluno[i].materias.notaMatematica[x]);
            } while(cadastroAluno[i].materias.notaMatematica[x] < 0 || cadastroAluno[i].materias.notaMatematica[x] > 10);
        }
        for(int x = 0; x < MAX_NOTAS; x ++){
            do {
                printf("Nota %d de Portugues (0 a 10)\n", x + 1);
                scanf("%f", &cadastroAluno[i].materias.notaPortugues[x]);
            } while(cadastroAluno[i].materias.notaPortugues[x] < 0 || cadastroAluno[i].materias.notaPortugues[x] > 10);
        }
        for(int x = 0; x < MAX_NOTAS; x ++){
            do {
                printf("Nota %d de Historia (0 a 10)\n", x + 1);
                scanf("%f", &cadastroAluno[i].materias.notaHistoria[x]);
            } while(cadastroAluno[i].materias.notaHistoria[x] < 0 || cadastroAluno[i].materias.notaHistoria[x] > 10);
        }
        for(int x = 0; x < MAX_NOTAS; x ++){
            do {
                printf("Nota %d de ciências (0 a 10)\n", x + 1);
                scanf("%f", &cadastroAluno[i].materias.notaCiencia[x]);
            } while(cadastroAluno[i].materias.notaCiencia[x] < 0 || cadastroAluno[i].materias.notaCiencia[x] > 10);
        }

        totalAlunos ++;

        printf("\nCadastro Finalizado...\n");
        PAUSE();

        printf("\nContinuar cadastro:\n 1 - Sim\n 2 - Não\n");
        scanf("%d", &opcaoFinalizarSistema);

    } while (opcaoFinalizarSistema != 2);

    return totalAlunos;
}

//case 2
void listarAlunos(cadastro cadastroAluno[], int totalAlunos){
    printf("\n==== Listagem de alunos =====\n");
    printf("Quantidade cadastrado no sistema: %d\n", totalAlunos);

    for(int x = 0; x < totalAlunos; x ++){
        printf("\nMatricula: %d | Nome: %s | Turma: %s",
               cadastroAluno[x].alunos.matricula,
               cadastroAluno[x].alunos.nome,
               cadastroAluno[x].alunos.turma);
    }
    PAUSE();
}

//case 3
void buscarAlunos(cadastro cadastroAluno[], int totalAlunos){

    int matricula;
    int indice;

    printf("\n===== Busca aluno =====\n");

    printf("\nDigite a matricula: ");
    scanf("%d", &matricula);

    indice = buscarIndice(cadastroAluno, totalAlunos, matricula);

    if(indice == -1) {
        printf("Aluno nao encontrado.\n");
    } else {
        printf("\nAluno encontrado!");
        printf("\nMatricula: %d", cadastroAluno[indice].alunos.matricula);
        printf("\nNome: %s", cadastroAluno[indice].alunos.nome);
        printf("\nTurma: %s\n", cadastroAluno[indice].alunos.turma);
    }

    PAUSE();
}

//Case 4
void lancarAlterarNotas(cadastro cadastroAluno[], int totalAlunos){

    int matricula;
    int indice;
    int materiaEscolhida;
    int numNota;
    float novaNota;
    int opcaoContinuar;

    printf("\n===== Lancar/alterar notas =====\n");

    printf("Matricula do aluno: ");
    scanf("%d", &matricula);

    indice = buscarIndice(cadastroAluno, totalAlunos, matricula);

    if(indice == -1){
        printf("Aluno nao encontrado.\n");
        PAUSE();
        return;
    }

    printf("\nAluno: %s\n", cadastroAluno[indice].alunos.nome);

    do {
        // escolher a materia
        do {
            printf("\nMateria:\n");
            printf(" 1 - Matematica\n");
            printf(" 2 - Portugues\n");
            printf(" 3 - Historia\n");
            printf(" 4 - Ciencias\n");
            printf("Escolha a materia: ");
            scanf("%d", &materiaEscolhida);
        } while(materiaEscolhida < 1 || materiaEscolhida > NUM_DISCIPLINAS);

        // mostrar as notas atuais da materia escolhida
        printf("\nNotas atuais: ");
        for(int x = 0; x < MAX_NOTAS; x ++){
            if(materiaEscolhida == 1){
                printf("[%d]=%.1f ", x + 1, cadastroAluno[indice].materias.notaMatematica[x]);
            } else if(materiaEscolhida == 2){
                printf("[%d]=%.1f ", x + 1, cadastroAluno[indice].materias.notaPortugues[x]);
            } else if(materiaEscolhida == 3){
                printf("[%d]=%.1f ", x + 1, cadastroAluno[indice].materias.notaHistoria[x]);
            } else {
                printf("[%d]=%.1f ", x + 1, cadastroAluno[indice].materias.notaCiencia[x]);
            }
        }
        printf("\n");

        // escolher qual nota alterar
        do {
            printf("Qual nota deseja alterar (1 a %d)? ", MAX_NOTAS);
            scanf("%d", &numNota);
        } while(numNota < 1 || numNota > MAX_NOTAS);
        numNota --; // vira posicao do vetor

        // digitar a nova nota
        do {
            printf("Nova nota (0 a 10): ");
            scanf("%f", &novaNota);
        } while(novaNota < 0 || novaNota > 10);

        // guardar a nova nota na materia escolhida
        if(materiaEscolhida == 1){
            cadastroAluno[indice].materias.notaMatematica[numNota] = novaNota;
        } else if(materiaEscolhida == 2){
            cadastroAluno[indice].materias.notaPortugues[numNota] = novaNota;
        } else if(materiaEscolhida == 3){
            cadastroAluno[indice].materias.notaHistoria[numNota] = novaNota;
        } else {
            cadastroAluno[indice].materias.notaCiencia[numNota] = novaNota;
        }

        printf("\nNota atualizada com sucesso!\n");

        printf("\nAlterar outra nota deste aluno:\n 1 - Sim\n 2 - Não\n");
        scanf("%d", &opcaoContinuar);

    } while(opcaoContinuar != 2);

    PAUSE();
}

//Case 5
int removerAluno(cadastro cadastroAluno[], int totalAlunos){

    int matricula;
    int indice;
    int confirmar;

    printf("\n===== Remover aluno =====\n");

    printf("Matricula do aluno: ");
    scanf("%d", &matricula);

    indice = buscarIndice(cadastroAluno, totalAlunos, matricula);

    if(indice == -1){
        printf("Aluno nao encontrado.\n");
        PAUSE();
        return totalAlunos;
    }

    printf("\nAluno: %s\n", cadastroAluno[indice].alunos.nome);
    printf("Turma: %s\n", cadastroAluno[indice].alunos.turma);

    do {
        printf("\nConfirmar remocao:\n 1 - Sim\n 2 - Não\n");
        scanf("%d", &confirmar);
    } while(confirmar != 1 && confirmar != 2);

    if(confirmar == 1){
        // puxa os alunos seguintes uma posicao para tras
        for(int x = indice; x < totalAlunos - 1; x ++){
            cadastroAluno[x] = cadastroAluno[x + 1];
        }
        totalAlunos --;
        printf("\nAluno removido com sucesso!\n");
    } else {
        printf("\nRemocao cancelada.\n");
    }

    PAUSE();
    return totalAlunos;
}

//Case 6
void emitirBoletim(cadastro cadastroAluno[], int totalAlunos){

    int matricula;
    int indice;

    printf("\n===== Emitir boletim =====\n");

    printf("Matricula do aluno: ");
    scanf("%d", &matricula);

    indice = buscarIndice(cadastroAluno, totalAlunos, matricula);

    if(indice == -1){
        printf("Aluno nao encontrado.\n");
        PAUSE();
        return;
    }

    printf("\n========== BOLETIM ESCOLAR ==========\n");
    printf("Aluno: %s   Matricula: %d   Turma: %s\n",
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

//Case 7
void relatorioTurma(cadastro cadastroAluno[], int totalAlunos){

    char turma[MAX_INFO];
    int qtd = 0;
    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;
    int indiceMaior = -1;
    float mediaAluno;
    float maiorMedia = -1;
    float somaTurma = 0;

    printf("\n===== Relatorio da turma =====\n");

    printf("Turma (ex.: 2A): ");
    scanf("%s", turma);

    for(int x = 0; x < totalAlunos; x ++){

        // pula os alunos de outras turmas
        if(strcmp(cadastroAluno[x].alunos.turma, turma) != 0){
            continue;
        }

        qtd ++;
        mediaAluno = calcularMediaGeral(cadastroAluno[x]);
        somaTurma += mediaAluno;

        if(situacao(mediaAluno) == 1){
            aprovados ++;
        } else if(situacao(mediaAluno) == 2){
            recuperacao ++;
        } else {
            reprovados ++;
        }

        if(mediaAluno > maiorMedia){
            maiorMedia = mediaAluno;
            indiceMaior = x;
        }
    }

    if(qtd == 0){
        printf("\nNenhum aluno encontrado nessa turma.\n");
    } else {
        printf("\n========== RELATORIO DA TURMA %s ==========\n", turma);
        printf("Total de alunos: %d\n", qtd);
        printf("Media geral da turma: %.2f\n", somaTurma / qtd);
        printf("Maior media: %s (%.2f)\n", cadastroAluno[indiceMaior].alunos.nome, maiorMedia);
        printf("\nAprovados: %d\n", aprovados);
        printf("Recuperacao: %d\n", recuperacao);
        printf("Reprovados: %d\n", reprovados);
    }

    PAUSE();
}


int main()
{
    cadastro cadastroAluno[MAX_CADASTRO_ALUNOS]; // vetor de alunos
    int totalAlunos = 0;                         // contador de alunos cadastrados
    int opcao;

    do{
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao){
            case 1: totalAlunos = cadastroAlunos(cadastroAluno, totalAlunos); break;
            case 2: listarAlunos(cadastroAluno, totalAlunos); break;
            case 3: buscarAlunos(cadastroAluno, totalAlunos); break;
            case 4: lancarAlterarNotas(cadastroAluno, totalAlunos); break;
            case 5: totalAlunos = removerAluno(cadastroAluno, totalAlunos); break;
            case 6: emitirBoletim(cadastroAluno, totalAlunos); break;
            case 7: relatorioTurma(cadastroAluno, totalAlunos); break;
            case 8: printf("\nEncerrando o sistema...\n"); break;
            default: printf("\nOpcao invalida! Tente novamente.\n"); break;
        }

    } while (opcao != 8);

    return 0;
}
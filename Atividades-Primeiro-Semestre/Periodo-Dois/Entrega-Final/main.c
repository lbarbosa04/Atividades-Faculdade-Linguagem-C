#include <stdio.h>
#include <string.h>

#define maxAlunos 100   //Nessa variavel global eu declaros valores que não serão alterados.
#define tamanhoNome 50
#define mediaAprovacao 7
#define mediaRecuperacao 5

void PAUSE(){ //PAUSE serve para sempre que eu chamar ele o programar pausar e continuar ao dar o comando
    printf("\nPRESSIONE ENTER PARA VOLTAR AO MENU...");
    getchar();
    getchar();
}

void menu(){
    printf("\n==========================================\n");
    printf("   GERENCIAMENTO PARA ALUNOS E NOTAS\n");
    printf("==========================================\n");
    printf("1 - Registrar aluno e nota\n");
    printf("2 - Exibir relatorio geral (media, maior e menor nota)\n");
    printf("3 - Listar aprovados, recuperacao e reprovados\n");
    printf("4 - Procurar aluno por nome\n");
    printf("5 - Sair do programa\n");
    printf("==========================================\n");
    printf("Escolha uma opcao: ");
}

// Case 1
void cadastroAluno(char nomeAluno[][tamanhoNome], float notaAluno[], int *totalAlunos){//Paramestros
    int quantidade = 0;

    printf("\nDigite o total de alunos que serao cadastrados: ");
    scanf("%d", &quantidade);

    //Logica para sempre ser somado o que está cadastrado com os novos
    if (quantidade <= 0 || *totalAlunos + quantidade > maxAlunos)  {                                                   
        printf("\nQuantidade invalida! Vagas restantes: %d\n", maxAlunos - *totalAlunos);
        PAUSE();
        return;
    }

    for (int x = 0; x < quantidade; x += 1){
        int pos = *totalAlunos; //pos = posição do aluno, 1, 2, 3 etc

        printf("\nDigite o nome do %d° aluno: ", pos + 1);
        scanf(" %49[^\n]", nomeAluno[pos]);

        printf("Nota do aluno: ");
        scanf("%f", &notaAluno[pos]);

        *totalAlunos += 1;
    }

    printf("\nCadastros concluidos!\n");
    PAUSE();
}

// Case 2
void exibirRelatorioGeral(float notaAluno[], int totalAlunos){
    if (totalAlunos == 0){
        printf("\nNenhum aluno cadastrado!\n");
        PAUSE();
        return;
    }

    float somaNotas = 0;
    float maiorNota = notaAluno[0];
    float menorNota = notaAluno[0];

    for (int x = 0; x < totalAlunos; x += 1){
        somaNotas += notaAluno[x];

        if (notaAluno[x] > maiorNota){
            maiorNota = notaAluno[x];
        }

        if (notaAluno[x] < menorNota){
            menorNota = notaAluno[x];
        }
    }

    float media = somaNotas / totalAlunos;

    printf("\n==========================================\n");
    printf("      RELATORIO GERAL DAS NOTAS\n");
    printf("==========================================\n");
    printf("Quantidade de alunos: %d\n", totalAlunos);
    printf("Media de notas: %.2f\n", media);
    printf("Maior nota: %.2f\n", maiorNota);
    printf("Menor nota: %.2f\n", menorNota);
    printf("------------------------------------------\n");
    PAUSE();
}

// Case 3
void listarAprovadosRecuperacaoReprovados(char nomeAluno[][tamanhoNome], float notaAluno[], int totalAlunos){
    if (totalAlunos == 0){
        printf("\nNenhum aluno cadastrado!\n");
        PAUSE();
        return;
    }

    printf("\n==========================================\n");
    printf("                APROVADOS\n");
    printf("==========================================\n");

    for (int x = 0; x < totalAlunos; x += 1){
        if (notaAluno[x] >= mediaAprovacao){
            printf("%s - Nota: %.2f\n", nomeAluno[x], notaAluno[x]);
        }
    }

    printf("\n==========================================\n");
    printf("               RECUPERACAO\n");
    printf("==========================================\n");
    for (int x = 0; x < totalAlunos; x += 1){
        if (notaAluno[x] >= mediaRecuperacao && notaAluno[x] < mediaAprovacao){
            printf("%s - Nota: %.2f\n", nomeAluno[x], notaAluno[x]);
        }
    }

    printf("\n==========================================\n");
    printf("               REPROVADOS\n");
    printf("==========================================\n");
    for (int x = 0; x < totalAlunos; x += 1){
        if (notaAluno[x] < mediaRecuperacao){
            printf("%s - Nota: %.2f\n", nomeAluno[x], notaAluno[x]);
        }
    }

    PAUSE();
}

// Case 4
void buscarAluno(char nomeAluno[][tamanhoNome], float notaAluno[], int totalAlunos){
    char buscaAluno[tamanhoNome];
    int achou = 0;

    if (totalAlunos == 0){
        printf("\nNenhum aluno cadastrado!\n");
        PAUSE();
        return;
    }

    printf("\nNome do aluno: ");
    scanf(" %49[^\n]", buscaAluno);

    for (int x = 0; x < totalAlunos; x += 1){
        if (strcmp(buscaAluno, nomeAluno[x]) == 0){
            printf("\nAluno encontrado!\n");
            printf("Nome: %s\n", nomeAluno[x]);
            printf("Nota: %.2f\n", notaAluno[x]);
            achou = 1;
        }
    }

    if (!achou){
        printf("\nAluno nao encontrado!\n");
    }
    PAUSE();
}

int main(){
    int opcaoMenu;
    int totalAlunos = 0;
    float notasAlunos[maxAlunos];
    char nomeAlunos[maxAlunos][tamanhoNome];

    do{
        menu();
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
        case 1:
            cadastroAluno(nomeAlunos, notasAlunos, &totalAlunos);
            break;
        case 2:
            exibirRelatorioGeral(notasAlunos, totalAlunos);
            break;
        case 3:
            listarAprovadosRecuperacaoReprovados(nomeAlunos, notasAlunos, totalAlunos);
            break;
        case 4:
            buscarAluno(nomeAlunos, notasAlunos, totalAlunos);
            break;
        case 5:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
            PAUSE();
            break;
        }

    } while (opcaoMenu != 5);

    return 0;
}
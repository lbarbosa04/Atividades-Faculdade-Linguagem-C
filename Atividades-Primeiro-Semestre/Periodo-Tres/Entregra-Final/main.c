#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 50
#define MAX_INFO 20
#define MAX_CADASTRO_ALUNOS 1000
#define MAX_NOTAS 4


void PAUSE(){ //PAUSE serve para sempre que eu chamar ele o programar pausar e continuar ao dar o comando
    printf("\nPRESSIONE ENTER PARA CONTINUAR...");
    getchar();
    getchar();
}

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

cadastro cadastroAluno[MAX_CADASTRO_ALUNOS]; // variavel global
int totalAlunos = 0;
int quantidadeCadastrado = 1; // Serve para 


//Funções do sistema
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

//Case 1
void cadastroAlunos(){
    
    int quantidade = quantidadeCadastrado;
    int notaNum = 1; 
    int opcaoFinalizarSistema;
    
    if(totalAlunos >= MAX_CADASTRO_ALUNOS){
        printf("Limite de cadastros atingidos!");
    return;
    }
    
    do {
        int i = totalAlunos; 
        
        printf("\n===== Cadastro do aluno =====\n");
        printf("Cadastro n %d\n", quantidadeCadastrado);
        
        printf("Nome do aluno: ");
        scanf(" %49[^\n]", &cadastroAluno[i].alunos.nome);
        
        printf("Turma do aluno: (A, B, C ou D)\n");
        scanf("%s", cadastroAluno[i].alunos.turma);
        
        printf("===== Cadstro notas do aluno =====\n");
        for(int x = 0; x < MAX_NOTAS; x ++){
            printf("Nota %d de Matematica\n", notaNum);
            scanf("%f", &cadastroAluno[i].materias.notaMatematica[x]);
            notaNum ++;
        }
        notaNum = 1;
        for(int x = 0; x < MAX_NOTAS; x ++){
            printf("Nota %d de Portugues\n", notaNum);
            scanf("%f", &cadastroAluno[i].materias.notaPortugues[x]);
            notaNum ++;
        }
        notaNum = 1;
        for(int x = 0; x < MAX_NOTAS; x ++){
            printf("Nota %d de Historia\n", notaNum);
            scanf("%f", &cadastroAluno[i].materias.notaHistoria[x]);
            notaNum ++;
        }
        notaNum = 1;
        for(int x = 0; x < MAX_NOTAS; x ++){
            printf("Nota %d de ciências\n", notaNum);
            scanf("%f", &cadastroAluno[i].materias.notaCiencia[x]);
            notaNum ++;
        }
        notaNum = 1;
        
        cadastroAluno[i].alunos.matricula = quantidadeCadastrado;
        
        quantidadeCadastrado ++;
        totalAlunos ++;
        
        printf("\nCadastro Finalizado...\n");
        PAUSE();
        
        printf("\nContinuar cadastro:\n 1 - Sim\n 2 - Não\n");
        scanf("%d", &opcaoFinalizarSistema);
        
    } while (opcaoFinalizarSistema != 2);
}

//case 2
void listarAlunos(){
    printf("\n==== Listagem de alunos =====\n");
    printf("Quantidade cadastrado no sistema: %d\n", totalAlunos);
    
    for(int x = 0; x < totalAlunos; x ++){
        printf("\nNome: %s", cadastroAluno[x].alunos.nome);
    }
    PAUSE();
}

//case 3
void buscarAlunos(){
    
    char buscaAluno[MAX_NOME];
    int achou = 0;
    
    printf("\n===== Busca aluno =====\n");
    
    printf("\nDigite o nome: ");
    scanf(" %49[^\n]", buscaAluno);
    
    for(int x = 0; x < totalAlunos; x ++){
        if(strcmp(buscaAluno, cadastroAluno[x].alunos.nome) == 0){
            printf("\nAluno encontrado!");
            printf("\nNome: %s", cadastroAluno[x].alunos.nome);
            achou = 1;
        }
    }
    
    if(achou == 0) {
        printf("Aluno nao encontrado.\n");
    }
    
    PAUSE();
}

//Case 4
void lancarAlterarNotas(){
    
    int matricula;
    int indice = -1;
    int materiaEscolhida;
    int numNota;
    float novaNota;
    int opcaoContinuar;
    
    printf("\n===== Lancar/alterar notas =====\n");
    
    printf("Matricula do aluno: ");
    scanf("%d", &matricula);
    
    // procura o aluno pela matricula
    for(int x = 0; x < totalAlunos; x ++){
        if(cadastroAluno[x].alunos.matricula == matricula){
            indice = x;
        }
    }
    
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
        } while(materiaEscolhida < 1 || materiaEscolhida > 4);
        
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
        numNota --; // vira posicao do vetor (0 a 3)
        
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
void removerAluno(){
    
    int matricula;
    int indice = -1;
    int confirmar;
    
    printf("\n===== Remover aluno =====\n");
    
    printf("Matricula do aluno: ");
    scanf("%d", &matricula);
    
    // procura o aluno pela matricula
    for(int x = 0; x < totalAlunos; x ++){
        if(cadastroAluno[x].alunos.matricula == matricula){
            indice = x;
        }
    }
    
    if(indice == -1){
        printf("Aluno nao encontrado.\n");
        PAUSE();
        return;
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
}

//case 6
void emitirBoletim(){
    
    int matricula;
    int indice = -1;
    float soma;
    float mediaMatematica, mediaPortugues, mediaHistoria, mediaCiencia;
    float mediaGeral;
    
    printf("\n===== Emitir boletim =====\n");
    
    printf("Matricula do aluno: ");
    scanf("%d", &matricula);
    
    // procura o aluno pela matricula
    for(int x = 0; x < totalAlunos; x ++){
        if(cadastroAluno[x].alunos.matricula == matricula){
            indice = x;
        }
    }
    
    if(indice == -1){
        printf("Aluno nao encontrado.\n");
        PAUSE();
        return;
    }
    
    // calcula a media de cada materia
    soma = 0;
    for(int x = 0; x < MAX_NOTAS; x ++){
        soma += cadastroAluno[indice].materias.notaMatematica[x];
    }
    mediaMatematica = soma / MAX_NOTAS;
    
    soma = 0;
    for(int x = 0; x < MAX_NOTAS; x ++){
        soma += cadastroAluno[indice].materias.notaPortugues[x];
    }
    mediaPortugues = soma / MAX_NOTAS;
    
    soma = 0;
    for(int x = 0; x < MAX_NOTAS; x ++){
        soma += cadastroAluno[indice].materias.notaHistoria[x];
    }
    mediaHistoria = soma / MAX_NOTAS;
    
    soma = 0;
    for(int x = 0; x < MAX_NOTAS; x ++){
        soma += cadastroAluno[indice].materias.notaCiencia[x];
    }
    mediaCiencia = soma / MAX_NOTAS;
    
    // media geral = media das 4 materias
    mediaGeral = (mediaMatematica + mediaPortugues + mediaHistoria + mediaCiencia) / 4;
    
    // mostra o boletim
    printf("\n========== BOLETIM ==========\n");
    printf("Matricula: %d\n", cadastroAluno[indice].alunos.matricula);
    printf("Nome: %s\n", cadastroAluno[indice].alunos.nome);
    printf("Turma: %s\n\n", cadastroAluno[indice].alunos.turma);
    
    printf("%-12s", "Matematica");
    for(int x = 0; x < MAX_NOTAS; x ++){
        printf(" %5.1f", cadastroAluno[indice].materias.notaMatematica[x]);
    }
    printf("  | Media: %.2f\n", mediaMatematica);
    
    printf("%-12s", "Portugues");
    for(int x = 0; x < MAX_NOTAS; x ++){
        printf(" %5.1f", cadastroAluno[indice].materias.notaPortugues[x]);
    }
    printf("  | Media: %.2f\n", mediaPortugues);
    
    printf("%-12s", "Historia");
    for(int x = 0; x < MAX_NOTAS; x ++){
        printf(" %5.1f", cadastroAluno[indice].materias.notaHistoria[x]);
    }
    printf("  | Media: %.2f\n", mediaHistoria);
    
    printf("%-12s", "Ciencias");
    for(int x = 0; x < MAX_NOTAS; x ++){
        printf(" %5.1f", cadastroAluno[indice].materias.notaCiencia[x]);
    }
    printf("  | Media: %.2f\n", mediaCiencia);
    
    printf("\nMedia geral: %.2f\n", mediaGeral);
    
    if(mediaGeral >= 7){
        printf("Situacao: APROVADO\n");
    } else if(mediaGeral >= 5){
        printf("Situacao: RECUPERACAO\n");
    } else {
        printf("Situacao: REPROVADO\n");
    }
    
    PAUSE();
}

//case 7
void relatorioTurma(){
    
    char turma;
    int qtd = 0;
    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;
    float soma;
    float mediaMatematica, mediaPortugues, mediaHistoria, mediaCiencia;
    float mediaGeral;
    float somaTurmaMatematica = 0, somaTurmaPortugues = 0;
    float somaTurmaHistoria = 0, somaTurmaCiencia = 0;
    float somaTurmaGeral = 0;
    float maiorMedia = -1;
    float menorMedia = 11;
    char nomeMaior[MAX_NOME];
    char nomeMenor[MAX_NOME];
    
    printf("\n===== Relatorio da turma =====\n");
    
    do {
        printf("Turma (A, B, C, D ou T para todas): ");
        scanf(" %c", &turma);
        turma = toupper(turma);
    } while((turma < 'A' || turma > 'D') && turma != 'T');
    
    for(int x = 0; x < totalAlunos; x ++){
        
        // pula os alunos de outras turmas
        if(turma != 'T' && toupper(cadastroAluno[x].alunos.turma[0]) != turma){
            continue;
        }
        
        qtd ++;
        
        // media de cada materia do aluno
        soma = 0;
        for(int n = 0; n < MAX_NOTAS; n ++){
            soma += cadastroAluno[x].materias.notaMatematica[n];
        }
        mediaMatematica = soma / MAX_NOTAS;
        
        soma = 0;
        for(int n = 0; n < MAX_NOTAS; n ++){
            soma += cadastroAluno[x].materias.notaPortugues[n];
        }
        mediaPortugues = soma / MAX_NOTAS;
        
        soma = 0;
        for(int n = 0; n < MAX_NOTAS; n ++){
            soma += cadastroAluno[x].materias.notaHistoria[n];
        }
        mediaHistoria = soma / MAX_NOTAS;
        
        soma = 0;
        for(int n = 0; n < MAX_NOTAS; n ++){
            soma += cadastroAluno[x].materias.notaCiencia[n];
        }
        mediaCiencia = soma / MAX_NOTAS;
        
        mediaGeral = (mediaMatematica + mediaPortugues + mediaHistoria + mediaCiencia) / 4;
        
        // acumula para calcular a media da turma
        somaTurmaMatematica += mediaMatematica;
        somaTurmaPortugues += mediaPortugues;
        somaTurmaHistoria += mediaHistoria;
        somaTurmaCiencia += mediaCiencia;
        somaTurmaGeral += mediaGeral;
        
        // situacao do aluno
        if(mediaGeral >= 7){
            aprovados ++;
        } else if(mediaGeral >= 5){
            recuperacao ++;
        } else {
            reprovados ++;
        }
        
        // maior e menor media
        if(mediaGeral > maiorMedia){
            maiorMedia = mediaGeral;
            strcpy(nomeMaior, cadastroAluno[x].alunos.nome);
        }
        if(mediaGeral < menorMedia){
            menorMedia = mediaGeral;
            strcpy(nomeMenor, cadastroAluno[x].alunos.nome);
        }
    }
    
    if(qtd == 0){
        printf("\nNenhum aluno encontrado.\n");
    } else {
        printf("\n========== RELATORIO ==========\n");
        if(turma == 'T'){
            printf("Turma: todas\n");
        } else {
            printf("Turma: %c\n", turma);
        }
        printf("Total de alunos: %d\n\n", qtd);
        
        printf("Media de Matematica: %.2f\n", somaTurmaMatematica / qtd);
        printf("Media de Portugues: %.2f\n", somaTurmaPortugues / qtd);
        printf("Media de Historia: %.2f\n", somaTurmaHistoria / qtd);
        printf("Media de Ciencias: %.2f\n", somaTurmaCiencia / qtd);
        printf("\nMedia geral da turma: %.2f\n", somaTurmaGeral / qtd);
        
        printf("\nAprovados: %d\n", aprovados);
        printf("Recuperacao: %d\n", recuperacao);
        printf("Reprovados: %d\n", reprovados);
        
        printf("\nMaior media: %s (%.2f)\n", nomeMaior, maiorMedia);
        printf("Menor media: %s (%.2f)\n", nomeMenor, menorMedia);
    }
    
    PAUSE();
}


int main()
{
    int opcao;
    
    do{
        exibirMenu();
        scanf("%d", &opcao);
         
        switch (opcao){
            case 1: cadastroAlunos(); break;
            case 2: listarAlunos(); break;
            case 3: buscarAlunos(); break;
            case 4: lancarAlterarNotas(); break;
            case 5: removerAluno(); break;
            case 6: emitirBoletim(); break;
            case 7: relatorioTurma(); break;
            case 8: printf("\nEncerrando o sistema...\n"); break;
        }
        
    } while (opcao != 8);
    
    return 0;
}